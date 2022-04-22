#include "kernel.h"
#include "starlib.h"
#include "stdbool.h"
#include "../drivers/monitor_mode_txt.h"
#include "../drivers/interrupts.h"
#include "../drivers/pic.h"
#include "../drivers/pit.h"
#include "../drivers/kbd.h"
#include "../prog/main.h"

static INPUT_HNDLR input_f = default_input;

void k_main()
{
	// initiate interrupt descriptor table and drivers
	idt_init(IDT);				// set id table
	pic_initialize();			// intialize the pic
	set_interval_size(1000);	// count every 1000 ticks
	pit_initialize(1000);		// start timer ticking every ms
	kbd_initialize();			// enable keyboard
	__asm__("sti"); 			// enable interrupts
	clear_screen();
	hide_cursor();

	run_program();				// start the built in program
	
	// system loop
	while (true)
		halt();					// halts until interrupted
}

void kbd_dispatch(int kbd_scan_code)
{
	/* called by the kbd_irq, dispatches the keyboard
	 * input to the function pointed to by input_f */
	 input_f(kbd_scan_code);
}

void set_input_function(INPUT_HNDLR proc_input)
{
	/* with this you can set a custom function
	 * dealing with keyboard input */
	input_f = proc_input;
}

void default_input(int code)
{
	/* default input function does nothing */
	return;
}