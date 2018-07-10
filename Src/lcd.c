#include "lcd.h"


//Задержка на микросекунды

void LCD_delay(uint16_t delay_)
{
    for(int i=0;i<delay_;i++)
    {/*do_nothing for several seconds*/}
}
//-----------------------

void LCD_set_Data(uint8_t data)
{
    if(((data>>7)&0x01) == 1){d7_set();} else{d7_reset();}
    if(((data>>6)&0x01) == 1){d6_set();} else{d6_reset();}
    if(((data>>5)&0x01) == 1){d5_set();} else{d5_reset();}
    if(((data>>4)&0x01) == 1){d4_set();} else{d4_reset();}
    if(((data>>3)&0x01) == 1){d3_set();} else{d3_reset();}
    if(((data>>2)&0x01) == 1){d2_set();} else{d2_reset();}
    if(((data>>1)&0x01) == 1){d1_set();} else{d1_reset();}
    if(((data)&0x01) == 1)   {d0_set();} else{d0_reset();}
}

//---WOHO!!!!!


void LCD_Write_Data8(uint8_t dt)
{
   //Пишем сразу 8 бит в контроллер экрана
    rs1;
    LCD_set_Data(dt);
    e1;
    //--delay--
    LCD_delay(100);
    //--delay--
    e0;
}

void LCD_Write_Comand8(uint8_t dt)
{
   //Пишем сразу 8 бит в контроллер экрана
    rs0;
    
    LCD_set_Data(dt);
    e1;
    LCD_delay(100);
    e0;
}

void LCD_Write_Data4(uint8_t dt)
{
   //Пишем сначала первые 4 бита в контроллер экрана, потом следующие 4 бита
    rs1;
    
    //------Старшие 4 бита----------
    LCD_set_Data(dt&0xF0);
    e1;
    LCD_delay(100);
    e0;
    //------------------------------
    
    //------Младшие 4 бита----------
    LCD_set_Data((dt<<4)&0xF0);
    e1;
    LCD_delay(100);
    e0;
    //------------------------------
}

void LCD_Write_Command4(uint8_t dt)
{
   //Пишем сначала первые 4 бита в контроллер экрана, потом следующие 4 бита
    rs0;
    
    //------Старшие 4 бита----------
    LCD_set_Data(dt&0xF0);
    e1;
    LCD_delay(1000);
    e0;
    //------------------------------
    
    //------Младшие 4 бита----------
    LCD_set_Data((dt<<4)&0xF0);
    e1;
    LCD_delay(1000);
    e0;
    //------------------------------
}

//----------------------
void LCD_ini(void)
{   
    HAL_Delay(15);
    rs0;
    LCD_Write_Command4(3);
    HAL_Delay(5);
    LCD_Write_Command4(3);
    HAL_Delay(1);
    LCD_Write_Command4(3);   
    HAL_Delay(1);
    LCD_Write_Command4(2);
    HAL_Delay(1);
    LCD_Write_Command4(2);
    //HAL_Delay(1);
    LCD_Write_Command4(0xC);
    //HAL_Delay(1);
    LCD_Write_Command4(0);
    //HAL_Delay(1);
    LCD_Write_Command4(8);
    //HAL_Delay(1);
    LCD_Write_Command4(0);
    //HAL_Delay(1);
    LCD_Write_Command4(1);
    //HAL_Delay(1);
    LCD_Write_Command4(0);
    //HAL_Delay(1);
    LCD_Write_Command4(3);
}
//----------------------

