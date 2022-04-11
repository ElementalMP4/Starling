#include "print_keyboard_keys.h"
#include "../kernel/kernel.h"
#include "../kernel/util.h"
#include "../kernel/stdbool.h"

#include "../kernel/keyboard_map.h"

void do_the_printing() {
	print("What is your name? ");
	char* name = read();
	print("\nHello, ");
	print(name);
	print("\nWhat is your favourite thing? ");
	char* thing = read();
	print("\nI like ");
	print(thing);
	print(" too!");
	set_input_function(print_keys);
}

void print_keys(int code) {
	print_n(code);
	print("\n");
}