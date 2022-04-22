#include "stdbool.h"

#define MAP_SIZE 48
#define SHIFT_MAP_SIZE 47

extern int key_codes[MAP_SIZE];
extern char key_values[MAP_SIZE];

extern int shift_key_codes[SHIFT_MAP_SIZE];
extern char shift_key_values[SHIFT_MAP_SIZE];

char get_key_from_code(int code, bool shiftPressed);