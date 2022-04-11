/* utility functions - printing, pseudo random number generator,
 * memory copy, sleep, etc. */

// includes
#include "util.h"
#include "stdbool.h"
#include "keyboard_map.h"
#include "../drivers/monitor_mode_txt.h"
#include "../drivers/pit.h"

// translation table for number printing
const char TBL[] = "0123456789ABCDEF";
static unsigned int next = 1;	// used for PRN generation

#define ENTER_KEY 28

//1MB keyboard buffer
char* key_buffer[1024*1024];

// code
void mem_cpy(char * src, char * dest, int num_of_bytes)
{
	/* copy num_of_bytes from src to dest */
	
	int i;
	
	for (i = 0; i < num_of_bytes; ++i)
		*(dest + i) = *(src + i);
}

int strlen(const char * str)
{
	/* the string length function */
	
	int i = 0;
	
	while (str[i] != '\0')
		++i;
		
	return i;
}

void print_n(int num)
{
	/* wrapper for printing an int in dec */
	
	print_number(num, 10);
}

void print_number(int num, int base)
{
	/* prepares num for base_convert */
	
	if (num < 0)	// handle negative numbers
	{
		// print a '-'
		print_c('-');
		// negate
		__asm__ ("neg %%eax" : "=a"(num) : "a"(num));
	}
	else if (0 == num)
	{
		// print a single zero
		print_c('0');
		return;
	}
	
	// convert and print
	base_convert(num, base);
}

void base_convert(int num, int base)
{
	/* prints a positive number, recursive */
	
	if (num <= 0)
		return;
	
	base_convert(num / base, base);
	
	print_c(TBL[num % base]);
}

void print(char* str) 
{
	/* wrapper for printing a string */
	
	print_at(str, -1 , -1);
}

void print_c(char ch)
{
	/* wrapper for printing a single char */
	
	print_char(ch, -1, -1);
}

int rand(void)
{
	/* classic pseudo random generator */
	
	next = next * 1103515245 + 12345;
	
	return (next>>16) & RAND_MAX;
}

void srand(unsigned int seed)
{
	/* seed for the generator */
	
	next = seed;
}

void sleep(unsigned int ms)
{
	/* do nothing for ms milliseconds */
	
	int i, j;
	
	j = 0;
	
	while (true)
	{
		// get current number of ticks
		i = get_ticks();	
		
		__asm__("hlt");	// halt until next interrupt
		
		// check here if the interrupt was from the timer
		if (i != get_ticks())
			++j;
		
		// ready?
		if (j >= ms)
			break;
	}
}

void halt(void)
{
	/* makes the processor halt */
	__asm__("hlt");
}

void append(char* s, char c) {
        int len = strlen(s);
        s[len] = c;
        s[len+1] = '\0';
}

int sc = 0;
char* input_text[1024*1024];

char* str_end = "\0";

char* read(void) {
	set_input_function(get_key);
	key_buffer[0] = str_end;
	input_text[0] = str_end;
	while (sc != ENTER_KEY) {
		//Hold until enter key is pressed
	}
	sc = 0;

	int input_length = strlen(key_buffer);

	for (int i = 0; i < input_length; i++) {
		append(input_text, (char)key_buffer[i]);
	}

	return input_text;
}

void get_key(int scancode) {
	sc = scancode;
	char* key = get_key_from_code(sc);
	append(key_buffer, sc);
	print(key);
}