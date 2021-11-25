#include <string>
#include <thread>
#include "QRScaner.h"

void *ReadCam(void *param);
pthread_t thread_QRS;
static std::string ScanCommand;
static void (*in_main_QRS_callback)(std::string qr_code);

void QRScaner_init(std::string CamPath, void (*QRS_callback)(std::string qr_code))
{
    ScanCommand = "zbarcam --raw --prescale=1280x960 --nodisplay --oneshot -Sdisable -Sqrcode.enable " + CamPath;
    in_main_QRS_callback = QRS_callback;
}
void *ReadCam(void *param)
{
    char buf[7168];
    std::string qr_data;
    std::string qr_data_old;
    std::string prog(ScanCommand);
    while (1)
    {
        FILE *fp = popen(prog.c_str(), "r");
        fread(buf, 7168, 1, fp);
        pclose(fp);
        qr_data = buf;
        if (qr_data != qr_data_old)
        {
            in_main_QRS_callback(qr_data);
            qr_data_old = qr_data;
        }
    }
    pthread_exit(0);
}
void QRScaner_Start()
{
    pthread_create(&thread_QRS, NULL, ReadCam, NULL);
}
void QRScaner_Stop()
{
    pthread_cancel(thread_QRS);
}