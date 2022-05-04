#include <kernel.h>
#include <starlib.h>
#include <display.h>
#include <interrupts.h>
#include <pic.h>
#include <pit.h>
#include <kbd.h>
#include "../prog/main.h"

static INPUT_HNDLR input_f = default_input;

void show_splash() {
	print("\fB                        .*(#(*.\n");
	print("                 .*(%@@@@@@@@@@@@@@@%\n");
	print("             */(##%%&@@@@@@@@@@@@@@@@@@@%\n");
	print("                         .@@@@@@@@@@@@@@@@@@\n");
	print("                              %@@@@@@@@@@@@@@@@@@\n");
	print("                               @@@@@@@@@@@@@@@@@@@@@.\n");
	print("                               @@@@@@@@@@@@@@@@@@@@@@@@,\n");
	print("                               @@@@@@@@@@@@@@@@@@@@@@@@@@(\n");
	print("                               .@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	print("                                 %@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	print("\fF _____ _             _ _\fB            &@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	print("\fF/  ___| |           | (_)\fB            .@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	print("\fF\\ `--.| |_ __ _ _ __| |_ _ __   __ _\fB   (@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	print("\fF `--. \\ __/ _` | '__| | | '_ \\ / _` |\fB    *@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	print("\fF/\\__/ / || (_| | |  | | | | | | (_| |\fB       *@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	print("\fF\\____/ \\__\\__,_|_|  |_|_|_| |_|\\__, |\fB        *@@@@@@@@@@@@@@@@@@@@@@@@&\n");
	print("                                \fF__/ |\fB             @@@@#    &@@@/  .,(&@@@@@@@\n");
	print("                               \fF|___/\fB              @@@     ,@#          .,&@@#\n");
	print("                                               ,@@(     *@#                .@@/\n");
	print("                                           &@@      (@%                      @@\n");
	print("                                        ,@@@ @      @#\n");
	print("                                 .@@@&#,@%       @*@\n");
	print("                               @          @    @   @@");
	sleep(750);
	clear_screen();
}

void k_main()
{
	// initiate interrupt descriptor table and drivers
	idt_init(IDT);            // set id table
	pic_initialize();         // intialize the pic
	set_interval_size(1000);   // count every 1000 ticks
	pit_initialize(1000);      // start timer ticking every ms
	kbd_initialize();         // enable keyboard
	__asm__("sti");          // enable interrupts
	clear_screen();
	hide_cursor();

	show_splash();

	run_program();            // start the built in program
	
	// system loop
	while (true)
		halt();               // halts until interrupted
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
	return;
}