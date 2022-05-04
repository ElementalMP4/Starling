#include <starlib.h>
#include <stdint.h>
#include <display.h>
#include "main.h"

void print_white_screen() {
	for (int i = 0; i < MAX_ROWS; i++) {
		for (int j = 0; j < MAX_COLS; j++) {
			set_background_colour(15);
			print(" ");
		}
	}
}

void change_random_byte() {
	int column = rand_range(0, MAX_COLS - 1);
	int row = rand_range(0, MAX_ROWS - 1);
	int colour = rand_range(0, 14);
	char byte = create_attribute_byte(0, colour);
	set_attribute_byte_at(byte, row, column);
}

int run_program(void)
{
	print_white_screen();
	while(true) {
		change_random_byte();
		sleep(5);
	}
}