/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.78
        Device            :  PIC12F1571
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    uint16_t    readWord;
    uint16_t    flashAddr = 0x01C0;
    uint16_t    Buf[ERASE_FLASH_BLOCKSIZE];

              IO_RA0_SetHigh();
              IO_RA1_SetHigh();
              IO_RA2_SetHigh();
              IO_RA4_SetHigh();
              IO_RA5_SetHigh();
              
    readWord = FLASH_ReadWord(flashAddr);
    if((readWord > 0x0000) && (readWord < 0x0005))
    {
        readWord = readWord + 0x0001;
        FLASH_WriteWord(flashAddr, Buf, readWord);
    }
    else
    {
        readWord = 0x0001;
        FLASH_WriteWord(flashAddr, Buf, readWord); 
    }
    while (1)
    {

    switch ( readWord )    
    {
        case 0x0000:
            ;
            uint8_t i = 0;
            while (i <= 20)
            {
                __delay_ms(100);

                IO_RA0_SetLow();
                IO_RA1_SetLow();
                IO_RA2_SetLow();
                IO_RA4_SetLow();
                IO_RA5_SetLow();

                __delay_ms(5);

                
              IO_RA0_SetHigh();
              IO_RA1_SetHigh();
              IO_RA2_SetHigh();
              IO_RA4_SetHigh();
              IO_RA5_SetHigh();
                i++;
            }
//              IO_RA0_SetHigh();
//              IO_RA1_SetHigh();
//              IO_RA2_SetHigh();
//              IO_RA4_SetHigh();
//              IO_RA5_SetHigh();
            SLEEP();
          break;
        case 1:
          IO_RA0_SetLow();
          IO_RA1_SetHigh();
          IO_RA2_SetHigh();
          IO_RA4_SetHigh();
          IO_RA5_SetHigh();
          break;
        case 2:
            IO_RA0_SetLow();
            IO_RA1_SetLow();
            IO_RA2_SetHigh();
            IO_RA4_SetHigh();
            IO_RA5_SetHigh();
          break;
        case 3:
          IO_RA0_SetLow();
          IO_RA1_SetLow();
          IO_RA2_SetHigh();
          IO_RA4_SetLow();
          IO_RA5_SetHigh();
          break;
        case 4:
          IO_RA0_SetLow();
          IO_RA1_SetLow();
          IO_RA2_SetHigh();
          IO_RA4_SetLow();
          IO_RA5_SetLow();
          break;
        case 5:
          IO_RA0_SetLow();
          IO_RA1_SetLow();
          IO_RA2_SetLow();
          IO_RA4_SetLow();
          IO_RA5_SetLow();
          break;
        default:
          break;
    }

    __delay_ms(500);
        IO_RA0_SetHigh();
        IO_RA1_SetHigh();
        IO_RA2_SetHigh();
        IO_RA4_SetHigh();
        IO_RA5_SetHigh();
    __delay_ms(55500);
    if(readWord >= 0x0001)
        {
            readWord = readWord - 1;
            FLASH_WriteWord(flashAddr, Buf, readWord);
        }
   }
}
/**
 End of File
*/