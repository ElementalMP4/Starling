#include <stdint.h>
#include "../drivers/pit.h"
#include "../drivers/kbd.h"
#include "../drivers/monitor_mode_txt.h"
#include "../kernel/util.h"
#include "../kernel/kernel.h"
#include "../kernel/stdbool.h"
#include "../kernel/util.h"
#include "main.h"

int run_program(void)
{
	print("Hello World!");	
}