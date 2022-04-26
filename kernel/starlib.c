// includes
#include <starlib.h>
#include <keyboard_map.h>
#include <monitor_mode_txt.h>
#include <pit.h>
#include <kernel.h>

//Translation table for number printing
const char TBL[] = "0123456789ABCDEF";
//Seed for the pseudorandom number generator
static unsigned int next = 1;

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
	if (num < 0)
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

int rand_range(int lower, int upper) {
	return (rand() % (upper - lower + 1)) + lower;
}

void sleep(unsigned int ms)
{
	int i, j;
	j = 0;
	while (true)
	{
		i = get_ticks();	
		halt();
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

//1MB keyboard buffer
char key_buffer[1024*1024];
int sc = 0;
bool shift_pressed = false;

void get_key(int scancode)
{
	sc = scancode;
	if (scancode == BACKSPACE_DOWN && strlen(key_buffer) > 0) {
			remove_last_character();
			key_buffer[strlen(key_buffer) - 1] = '\0';
	} else if (scancode == LEFT_SHIFT_DOWN | scancode == RIGHT_SHIFT_DOWN)
		shift_pressed = true;
	else if (scancode == LEFT_SHIFT_UP | scancode == RIGHT_SHIFT_UP)
		shift_pressed = false;
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
	show_cursor();
	key_buffer[0] = '\0';
	set_input_function(get_key);
	//Hold until enter is pressed
	while (sc != ENTER_DOWN) {
		halt();
	}
	//Reset scancode var and add terminator to keyboard buffer
	sc = 0;
	append(key_buffer, '\0');

	//Convert keyboard buffer to char pointer
	char *out;
	int buffer_length = strlen(key_buffer);
	for (int i = 0; i < buffer_length; i++) {
		append(out, key_buffer[i]);
	}

	//Stop input propagation and turn off cursor
	set_input_function(default_input);
	hide_cursor();
	return key_buffer;
}


//Jack.
void jack() {
	while (true) {
		halt();
	}
}