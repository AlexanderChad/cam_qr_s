void QRScaner_init(
    std::string CamPath,
    void (*QRS_callback)(std::string qr_code));
//инициализация сканера. CamPath - путь к камере,
//QRS_callback - обратный вызов при нахождении нового QR-кода.
void QRScaner_Start(); //Запуск
void QRScaner_Stop();  //Остановка