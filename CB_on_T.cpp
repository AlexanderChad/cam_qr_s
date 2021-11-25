#include <iostream>
#include <string>
#include "QRScaner.h"
#include <unistd.h>

void Display_QR_code(std::string qr_data)
{
    std::cout << "rezult: " << qr_data << std::endl;
}

int main()
{
    QRScaner_init("/dev/video0", Display_QR_code);
    QRScaner_Start();
    std::cout << "Scan started" << std::endl;
    for (int i_m = 0; i_m < 30; i_m++)
    {
        std::cout << "waiting..." << std::endl;
        sleep(1);
    }
    QRScaner_Stop();
    return int();
}