// Source file for the 16*2 LCD screen display.
// Author: Jeff Zhong
// Date: 10/25/2024

#include "m5800.h"
#include <8052.h>
#include <stdint.h>

void delay(unsigned int ms) {
    int i, j;
	for (i = 0; i < ms; i++) {
	    for (j = 0; j < 123; j++) {
		}
	}
}

// Send command to the LCD to control it.
void lcd_command (unsigned char cmd) {
	lcd_data_port = cmd;

	LCD_RS = 0;
	LCD_RW = 0;
	delay(1);
	
    LCD_EN = 1;
	delay(10);
	LCD_EN = 0;
	delay(1);
}

// Send data to the LCD to display information.
void lcd_data(unsigned char data_byte) {
	lcd_data_port = data_byte;
	// Data mode.
	LCD_RS = 1;
	LCD_RW = 0;
	delay(1);
	// Enable high.
	LCD_EN = 1;
	
	delay(10);
	LCD_EN = 0;
	delay(1);
}

void init_display() {
	delay(30);
	// 2-line mode, display off.
	lcd_command(0x38);
	delay(1);
	// Display on, cursor on, blink off.
	lcd_command(0x0E);
	delay(1);
	// Display clear.
	lcd_command(0x01);
	delay(2);
	// Entry mode set, increment mode(from left to right), entire shift off.
	lcd_command(0x06);
}

// Function to set the cursor position
void set_cursor(unsigned char row, unsigned char column) {
    if (row == 0) {
	    lcd_command((column & 0x0F) | 0x80);
	} else if (row == 1) {
	    lcd_command((column & 0x0F) | 0xC0);
	}
}

void display_customa() {
    lcd_command(0x40);
	
	// Define the custom character by sending 8 bytes to CGRAM
	lcd_data(0b00100);  // Row 1 of the 5x8 matrix
	lcd_data(0b01010);  // Row 2
	lcd_data(0b10001);  // Row 3
	lcd_data(0b10001);  // Row 4
	lcd_data(0b10001);  // Row 5
	lcd_data(0b10001);  // Row 6
	lcd_data(0b01010);  // Row 7
	lcd_data(0b00100);  // Row 8
}

void display_customb() {
    lcd_command(0x48);
	
	// Define the custom character by sending 8 bytes to CGRAM
	lcd_data(0b00000);  // Row 1 of the 5x8 matrix
	lcd_data(0b01010);  // Row 2
	lcd_data(0b10101);  // Row 3
	lcd_data(0b10001);  // Row 4
	lcd_data(0b10001);  // Row 5
	lcd_data(0b01010);  // Row 6
	lcd_data(0b00100);  // Row 7
	lcd_data(0b00000);  // Row 8
}
