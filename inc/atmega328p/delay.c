#include "delay.h"

// Currently not used
void delay_ms(unsigned int count){
    for(unsigned int i=0;i<=count;i++){
        for(unsigned int j=0;j<=65535;j++)
            asm("nop;nop;nop");
    }
}