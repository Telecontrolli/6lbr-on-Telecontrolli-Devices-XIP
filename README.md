#6lbr-on-Telecontrolli-Devices V1.2

-V1.2: This version contains the Contiki OS with the addition of the input management, adapted to X.IP4T / X.IP5 devices.
Monitoring the status of a Digital Input (sensor), simulated with a button, through CoAP protocol.

Tested with Contiki-develop-20170121

This application v1.2 enables communication for sensors reading and Devices activation through 6lowpan/CoAP protocols between a “6lbr-Slip-radio” (i.e. a router device) and a “cc26xx-web-demo” device. This Repository contains all files to operate and build the firmware for X.IP4T and X.IP5 devices.

Devices setting Procedure:

1) Download Contiki OS

2) Type, in the Raspberry terminal, the following commands to install the "6lbr": 

-sudo git clone --recursive https://github.com/cetic/6lbr -b develop-20170121

-cd 6lbr

-sudo git submodule update --init --recursive

-cd examples/6lbr

-git checkout develop-20170121

-make all #all_native for version <1.4

-sudo make plugins

-sudo make tools

-sudo make install

-sudo make plugins --install

-update -rc.d 6lbr defaults

3) Download “6lbr-on-Telecontrolli-Devices-XIP” from this repository

4) Replace the folder “cc26xx” in “home/pi/contiki/example/cc26xx” with the folder “cc26xx” you find in “6lbr-on-Telecontrolli-Devices-XIP”

5) Replace the folder “dev” in “home/pi/contiki/core/dev” with the folder “dev” you find in “6lbr-on-Telecontrolli-Devices-XIP”

6) Replace the folders “slip-radio” and “rpl-border-router” in “home/pi/contiki/examples/ipv6” with the folders “slip-radio” and “rpl-border-router” you find in “6lbr-on-Telecontrolli-Devices-XIP”

7) Replace the folder “srf06” in “home/pi/contiki/platform/srf06-cc26xx/srf06” with the folder “srf06” you find in “6lbr-on--      Telecontrolli-Devices-XIP”. This folder includes “board.h”.


  

Feel free to contact our team at: 
support@telecontrolli.com

Here you will find the tutorial:
http://bit.ly/2lB9u7n
