#include "mbed.h"
#include "WIZnetInterface.h"
/**----------------------------------------------------------------------------
 * @target      Nucleo F411RE
 * @libraries   mbed drivers and rtos
 * @date        14-February-2015
 * @author      Hotboards
 * @brief       This is a project build with the mbed libraries ready to compile
 * using GNU ARM compiler and eclipse, it has only the driver libraries and the
 * rtx OS at the moment. Should be use as a template only copy and paste to
 * generate a new independent project, or use egit to clone from the github
 * repository. In folder Debug you will find .hex, .elf and .bin file to program,
 * your board check the readme file for more information.
 * By default printf and scanf with floating point number are disable
-----------------------------------------------------------------------------*/
int main() {
    Serial pc(USBTX, USBRX);
    pc.printf("Starte ...\r\n");
    SPI device(PA_7, PA_6, PA_5); // mosi, miso, sclk
    uint8_t mac[] = {0x22, 0x27, 0xeb, 0x98, 0x1e, 0xc4};
    DigitalOut cs(); // ssel
    WIZnetInterface win(&device, PB_6, NC);
    int stat = win.init(mac);
    if (stat==0)
    {
        pc.printf("init OK!\r\n");
    }else
    {
        pc.printf("init FAILD!\r\n");
    }
    stat=win.connect();
    if (stat==0)
    {
        pc.printf("Connect!\r\n");
    }else
    {
        pc.printf("Not Connected!\r\n");
    }
    pc.printf("IP-Adresse: %s\r\n", win.getIPAddress());
    pc.printf("MAC-Adresse: %s\r\n",win.getMACAddress());
    pc.printf("Netzwerkmaske: %s\r\n",win.getNetworkMask());
    pc.printf("Gateway: %s\r\n",win.getGateway());

}
