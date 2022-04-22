#include "../../kernel/starlib.h"
#include "../../kernel/stdbool.h"
#include "../../drivers/monitor_mode_txt.h"
#include "../../kernel/kernel.h"

#include "print_wee.h"

void do_the_printing() {
	sleep(2000);
	print("What is your name you buffoon: ");
	char* name = read();
	print("\nWow what a smelly name, ");
	print(name);
}