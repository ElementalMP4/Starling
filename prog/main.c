#include <starlib.h>
#include <kbd.h>
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
int column = 0;
int row = 0;

bool box_filled[MAX_COLS][MAX_ROWS];

void reset_filled_list() {
	for (int i = 0; i < MAX_COLS; i++) {
		for (int j = 0; j < MAX_ROWS; j++) {
			box_filled[i][j] = false;
		}
	}
}

void generate_random_coordinates() {
	column = rand_range(0, MAX_COLS - 1);
	row = rand_range(0, MAX_ROWS - 1);
}

void change_random_byte() {
	generate_random_coordinates();
	while (box_filled[column][row]) {
		generate_random_coordinates();
	}
	box_filled[column][row] = true;
	char byte = create_attribute_byte(0, colour);
	set_attribute_byte_at(byte, row, column);
}

int run_program(void)
{
	print_white_screen();
	while(true) {
		for (int k = 0; k < MAX_COLS * MAX_ROWS; k++) {
			change_random_byte();
			sleep(1);
		}
		reset_filled_list();
		if (colour < 15) colour++;
		else colour = 0;
		sleep(100);
	}
}