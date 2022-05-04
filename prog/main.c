#include <starlib.h>
#include <stdint.h>
#include <display.h>
#include "main.h"

void print_white_screen() {
	for (int i = 0; i < MAX_COLS; i++) {
		for (int j = 0; j < MAX_ROWS; j++) {
			set_background_colour(15);
			print_at(" ", i, j);
			sleep(1);
		}
	}
}

int colour = 0;

void change_random_byte() {
	int column = rand_range(0, MAX_COLS - 1);
	int row = rand_range(0, MAX_ROWS - 1);
	char byte = create_attribute_byte(0, colour);
	set_attribute_byte_at(byte, row, column);
}

int run_program(void)
{
	print_white_screen();
	while(true) {
		for (int k = 0; k < 2000; k++) {
			change_random_byte();
			sleep(1);
		}
		if (colour < 15) colour++;
		else colour = 0;
	}
}