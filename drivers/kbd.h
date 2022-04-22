// constants
#define KBD_IRQ			0x21 // kbr irq address in IDT (33 dec)

// ports and codes
#define KBD_ENC_INPUT	0x60
#define KBD_ENC_CMD		0x60
#define KBD_CTRL_STAT	0x64
#define KBD_CTRL_CMD 	0x64

#define KBD_CTRL_WRITE_OUT_PORT 0xD1

#define KBD_OUTPUT_FULL	0x01
#define KBD_INPUT_FULL	0x02

// functions
void kbd_initialize(void);
void kbd_irq(void);
