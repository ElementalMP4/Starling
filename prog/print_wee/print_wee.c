#include "../../kernel/starlib.h"
#include "../../kernel/stdbool.h"
#include "../../drivers/monitor_mode_txt.h"
#include "../../kernel/kernel.h"

#include "print_wee.h"

void do_the_printing() {
	//print("What is your name you bastard: ");
	//char* name = read();
	//print("\nWow what a smelly name, ");
	//print(name);
	show_cursor();
	sleep(5000);
	hide_cursor();
	sleep(5000);
	show_cursor();
}