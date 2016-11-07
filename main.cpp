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
#include "mbed.h"



DigitalOut myled(LED1);
Serial pc(USBTX, USBRX);

int main()
{
SPI device(PA_7, PA_6, PA_5);
pc.printf("Starte ...\r\n");

    while(1)
    {
        myled = 1; // LED is ON
        wait(0.2); // 200 ms
        myled = 0; // LED is OFF
        wait(1.0); // 1 sec
        //Thread::wait(10000);
        struct tm *actt;
                time_t actTime;
                time(&actTime);
               // pc.printf("%lld\n", (long long) actTime);

    }
}

