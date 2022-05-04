#include <starlib.h>

//VGA address and dimensions
#define VGA_ADDRESS 0xb8000
#define MAX_ROWS 25
#define MAX_COLS 80

//Default color attribute
#define GRAY_ON_BLACK 0x07

//Screen I/O
#define REG_SCR_CTRL 0x3d4
#define REG_SCR_DATA 0x3d5

//Cursor Control
#define HIDE_CURSOR 0x200A
#define SHOW_CURSOR 0x000A

unsigned char* get_video_memory(void);
void print_char(char character, int col, int row);
int get_scr_offset(int col, int row);
int get_cursor(void);
void set_cursor(int offset);
void print_at(char *str , int col , int row);
void clear_screen(void);
int handle_scrolling(int cursor_offset);
char get_char_at(int row, int col);
void set_attribute_byte(char attrib);
char get_attribute_byte(void);
void update_attribute_byte(void);
void hide_cursor(void);
void show_cursor(void);
void remove_last_character(void);
void set_foreground_colour(int colour);
void set_background_colour(int colour);
char create_attribute_byte(int fg_c, int bg_c);
void set_attribute_byte_at(char attribute_byte, int row, int col);