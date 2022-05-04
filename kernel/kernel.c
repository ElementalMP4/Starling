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
    set_foreground_colour(11);
   print("                        .*(#(*.\n");
   print("                 .*(%@@@@@@@@@@@@@@@%\n");
   print("             */(##%%&@@@@@@@@@@@@@@@@@@@%\n");
   print("                         .@@@@@@@@@@@@@@@@@@\n");
   print("                              %@@@@@@@@@@@@@@@@@@\n");
   print("                               @@@@@@@@@@@@@@@@@@@@@.\n");
   print("                               @@@@@@@@@@@@@@@@@@@@@@@@,\n");
   print("                               @@@@@@@@@@@@@@@@@@@@@@@@@@(\n");
   print("                               .@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
   print("                                 %@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
   print(" _____ _             _ _            &@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
   print("/  ___| |           | (_)            .@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
   print("\\ `--.| |_ __ _ _ __| |_ _ __   __ _   (@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
   print(" `--. \\ __/ _` | '__| | | '_ \\ / _` |    *@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
   print("/\\__/ / || (_| | |  | | | | | | (_| |       *@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
   print("\\____/ \\__\\__,_|_|  |_|_|_| |_|\\__, |        *@@@@@@@@@@@@@@@@@@@@@@@@&\n");
   print("                                __/ |             @@@@#    &@@@/  .,(&@@@@@@@\n");
   print("                               |___/              @@@     ,@#          .,&@@#\n");
   print("                                               ,@@(     *@#                .@@/\n");
   print("                                           &@@      (@%                      @@\n");
   print("                                        ,@@@ @      @#\n");
   print("                                 .@@@&#,@%       @*@\n");
   print("                               @          @    @   @@");

    jack();
    //sleep(500);
    //clear_screen();
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