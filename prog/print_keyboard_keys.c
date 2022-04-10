#include "print_keyboard_keys.h"
#include "../kernel/kernel.h"
#include "../kernel/util.h"

void do_the_printing() {
	set_input_function(get_key);
}

void get_key(int scancode) {
	print_n(scancode);
	print("\n");
}