#include "keyboard_map.h"
#include "stdbool.h"

char get_key_from_code(int code) {
	char key;
	bool found = false;

	for (int i = 0; i < MAP_SIZE; i++) {
		if (code == key_codes[i]) {
			key = key_values[i];
			found = true;
		}
	}

	if (found) {
		return key;
	} else {
        return '\0';
    }
}

int key_codes[MAP_SIZE] = {
2,3,4,5,6,7,8,9,10,11,12,13,16,17,18,19,20,21,22,23,24,25,26,27,30,31,32,33,34,35,36,37,38,39,40,41,43,44,45,46,47,48,49,50,51,52,53,74,78,57
};

char key_values[MAP_SIZE] = {
'1','2','3','4','5','6','7','8','9','0','-','=','Q','W','E','R','T','Y','U','I','O','P','[',']','A','S','D','F','G','H','J','K','L',';','\'','`','\\','Z','X','C','V','B','N','M',',','.','/','-','+',' '
};