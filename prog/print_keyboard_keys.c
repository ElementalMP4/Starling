#include "print_keyboard_keys.h"
#include "../kernel/kernel.h"
#include "../kernel/util.h"
#include "../kernel/stdbool.h"

#include "../kernel/keyboard_map.h"

void do_the_printing() {
	char* input = read();
	print(input);
	print("\n1\n");
	input = read();
	print(input);
	print("\n2\n");
	input = read();
	print(input);
	print("\n3\n");
}