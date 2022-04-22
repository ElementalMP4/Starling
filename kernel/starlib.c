/* utility functions - printing, pseudo random number generator,
 * memory copy, sleep, etc. */

// includes
#include "starlib.h"
#include "stdbool.h"
#include "keyboard_map.h"
#include "../drivers/monitor_mode_txt.h"
#include "../drivers/pit.h"
#include "kernel.h"

// translation table for number printing
const char TBL[] = "0123456789ABCDEF";
static unsigned int next = 1;	// used for PRN generation

#define ENTER_KEY 28

// code
void *mem_cpy(char *src, char *dest, int num_of_bytes)
{	
	int i;	
	for (i = 0; i < num_of_bytes; ++i)
		*(dest + i) = *(src + i);
}

int strlen(const char *str)
{
	int i = 0;	
	while (str[i] != '\0')
		++i;
		
	return i;
}

void print_n(int num)
{	
	print_number(num, 10);
}

void print_number(int num, int base)
{
	if (num < 0)	// handle negative numbers
	{
		print_c('-');
		__asm__ ("neg %%eax" : "=a"(num) : "a"(num));
	}
	else if (0 == num)
	{
		print_c('0');
		return;
	}
	
	base_convert(num, base);
}

void base_convert(int num, int base)
{
	if (num <= 0)
		return;
	
	base_convert(num / base, base);
	print_c(TBL[num % base]);
}

void print(char *str) 
{
	print_at(str, -1 , -1);
}

void print_c(char ch)
{
	print_char(ch, -1, -1);
}

int rand(void)
{
	next = next * 1103515245 + 12345;
	return (next>>16) & RAND_MAX;
}

void srand(unsigned int seed)
{
	next = seed;
}

void sleep(unsigned int ms)
{
	int i, j;
	j = 0;
	while (true)
	{
		i = get_ticks();	
		__asm__("hlt");	// halt until next interrupt
		if (i != get_ticks())
			++j;
		if (j >= ms)
			break;
	}
}

void halt(void)
{
	__asm__("hlt");
}

void append(char *s, char c) {
        int len = strlen(s);
        s[len] = c;
        s[len+1] = '\0';
}

int sc = 0;

bool shift_pressed = false;

//1MB keyboard buffer
char key_buffer[1024*1024];

void get_key(int scancode)
{
	sc = scancode;

	if (scancode == 14) {
		remove_last_character();
		key_buffer[strlen(key_buffer) - 1] = '\0';
	} else if (scancode == 42 | scancode == 54) shift_pressed = true;
	else if (scancode == 170 | scancode == 182) shift_pressed = false;
	else {
		char key = get_key_from_code(sc, shift_pressed);
		if (key != '\0') {
			append(key_buffer, (char)key);
			print_c(key);
		}
	}
}

char *read(void) 
{
	key_buffer[0] = '\0';
	set_input_function(get_key);
	while (sc != ENTER_KEY) {
		//Hold until enter key is pressed
	}
	sc = 0;

	append(key_buffer, '\0');

	char *out;
	int buffer_length = strlen(key_buffer);

	for (int i = 0; i < buffer_length; i++) {
		append(out, key_buffer[i]);
	}

	set_input_function(default_input);
	return key_buffer;
}
