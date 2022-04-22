#include "keyboard_map.h"
#include "stdbool.h"

const int key_codes[MAP_SIZE] = {
2,3,4,5,6,7,8,9,10,11,
12,13,16,17,18,19,20,21,22,23,
24,25,26,27,30,31,32,33,34,35,
36,37,38,39,40,41,43,44,45,46,
47,48,49,50,51,52,53,57
};

const char key_values[MAP_SIZE] = {
'1','2','3','4','5','6','7','8','9','0',
'-','=','q','w','e','r','t','y','u','i',
'o','p','[',']','a','s','d','f','g','h',
'j','k','l',';','\'','`','\\','z','x','c',
'v','b','n','m',',','.','/',' '
};

const int shift_key_codes[SHIFT_MAP_SIZE] = { 
2,3,4,5,6,7,8,9,10,11,
12,13,16,17,18,19,20,21,22,23,
24,25,26,27,30,31,32,33,34,35,
36,37,38,39,40,41,43,44,45,46,
47,48,49,50,51,52,53
}; 

const char shift_key_values[SHIFT_MAP_SIZE] = { 
'!','"','£','$','%','^','&','*','(',')',
'_','+','Q','W','E','R','T','Y','U','I',
'O','P','{','}','A','S','D','F','G','H',
'J','K','L',':','@','`','|','Z','X','C',
'V','B','N','M','<','>','?'
 }; 

char get_key_from_map(int code, int map_size, const int codes[], const char values[]) {
	char key;
	bool found = false;
	for (int i = 0; i < map_size; i++) {
		if (code == codes[i]) {
			key = values[i];
			found = true;
		}
	}

	if (found) return key;
	else return '\0';
}

char get_key_from_code(int code, bool shift_pressed) {
	if (shift_pressed) {
		return get_key_from_map(code, SHIFT_MAP_SIZE, shift_key_codes, shift_key_values);
	} else {
		return get_key_from_map(code, MAP_SIZE, key_codes, key_values);
	} 
}