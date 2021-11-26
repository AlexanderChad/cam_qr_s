# cam_qr_s  
Инструкция по установке  
1) Скачивание, сборка и установка ZBar:   
```wget https://github.com/mchehab/zbar/archive/refs/tags/0.23.92.tar.gz
tar -xzvf 0.23.92.tar.gz
cd ./zbar-0.23.92
sudo apt update
sudo apt install build-essential manpages-dev git automake autoconf autopoint gettext pkg-config libtool v4l-utils libv4l-dev imagemagick
autoreconf -vfi
./configure
make
sudo make install
```
2) Скачивание и сборка с запуском cam_qr_s:   
```
git clone https://github.com/AlexanderChad/cam_qr_s.git
cd ./cam_qr_s
make
./CB_on_T
```   
При необходимости в файле CB_on_T.cpp в строке `QRScaner_init("/dev/video0", Display_QR_code);` заменить `"/dev/video0"` на актуальную камеры и пересобрать `CB_on_T` командой `make`.
