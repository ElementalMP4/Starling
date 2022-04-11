#include "print_keyboard_keys.h"
#include "../kernel/util.h"
#include "../kernel/stdbool.h"
#include "../drivers/monitor_mode_txt.h"

#include "../kernel/keyboard_map.h"

void do_the_printing() {
	while (true) {
		for (int i = 0; i < 15; i++) {
			set_background_colour(i);
			for (int j = 0; j < 15; j++) {
				set_foreground_colour(j);
				print("WEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE\n");
				sleep(10);
			}
		}
	}
}