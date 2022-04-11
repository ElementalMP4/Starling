#include "print_keyboard_keys.h"
#include "../kernel/kernel.h"
#include "../kernel/util.h"
#include "../kernel/stdbool.h"

#include "../kernel/keyboard_map.h"

void do_the_printing() {
	print("What is your name? ");
	char* input = read();
	print("\nHello, ");
	print(input);
}