#include <starlib.h>
#include <kernel.h>
#include <monitor_mode_txt.h>

#include "print_wee.h"

void print_wee() {
	while (true) {
		for (int i = 0; i <= 15; i++) {
			set_foreground_colour(i);
			print_n(rand());
			print("\n");
			sleep(10);
		}
	}	
}

void do_the_printing() {
	print("What is your name you buffoon: ");
	char* name = read();
	print("\nWow what a smelly name, ");
	print(name);
	sleep(1000);
	clear_screen();
	print_wee();
}