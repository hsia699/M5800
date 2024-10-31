// Header file for the 16*2 LCD screen display.
// Author: Jeff Zhong
// Date: 10/25/2024

#ifndef M5800_H
#define M5800_H

// Pin Definitions for LCD control
__sfr __at (0x90) lcd_data_port;   // Assigns P1 as data port (D0-D7)
__sbit __at (0xB1) LCD_RW;
__sbit __at (0xB2) LCD_RS;         // P3.2 for Register Select pin
__sbit __at (0xB4) LCD_EN;         // P3.4 for Enable pin

// Functions
void delay(unsigned int ms);
void lcd_command (unsigned char cmd);
void lcd_data(unsigned char data_byte);
void init_display();
void display_string(unsigned char *str);
void set_cursor(unsigned char row, unsigned char column);
void display_customa();
void display_customb();
#endif // M5800_H
