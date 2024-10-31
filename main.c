#include "m5800.h"

void main() {
    init_display();
	
    display_customa();
	display_customb();

	set_cursor(0, 0);
    lcd_data(0x00);
	delay(2000);

	set_cursor(0, 1);
	lcd_data(0x01);
	delay(1000);
	
	set_cursor(0,2);
	/**
        // "H"
	lcd_data(0x48);
	delay(2000);
	// "E"
	lcd_data(0x45);
	delay(2000);
	// "L"
	lcd_data(0x4C);
	delay(2000);
	// "L"
	lcd_data(0x4C);
	delay(2000);
	// "o"
	lcd_data(0x4F);
	delay(2000);
	// " "
	lcd_data(0x12);
	delay(2000);
	// "W"
	lcd_data(0x57);
	delay(2000);
	// "o"
	lcd_data(0x4F);
	delay(2000);
	// "R"
	lcd_data(0x52);
	delay(2000);
	// "L"
	lcd_data(0x4C);
	delay(2000);
	// "D"
	lcd_data(0x44);
    delay(2000);
	// "!"
	lcd_data(0x21);
	delay(1000);
	// Set the cursor to a fixed position to stop moving.
	set_cursor(0, 12);
**/
    while (1) {
	}
}
