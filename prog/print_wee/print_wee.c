#include <starlib.h>
#include <kernel.h>
#include <monitor_mode_txt.h>

#include "print_wee.h"

void print_wee() {
	int indent = 0;
	bool falling = false;

	while (true) {
		for (int i = 0; i <= 15; i++) {
			set_foreground_colour(i);
			for (int j = 0; j <= indent; j++) {
				print(" ");
			}
			
			print("00000000000000000000\n");
			
			if (falling) {
				indent--;
				if (indent == 0) falling = false;
			} else {
				indent++;
				if (indent == 4) falling = true;
			}

			sleep(10);
		}
	}	
}

void do_the_printing() {
	print("What is your name you buffoon: ");
	char* name = read();
	print("\nWow what a smelly name, ");
	print(name);
	sleep(2000);
	print_wee();
}