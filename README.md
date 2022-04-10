# Starling - A barebones OS

I wrote about 0.1% of this code. I took [this existing project](https://github.com/vladcc/Tetris-OS) and modified the make files and kernel to run custom programs.

## Building Starling

To build Starling, you will need the following prerequisites:

- Make
- GCC
- NASM
- Qemu
- A flavour of Linux

It is possible to use WSL for the linux component of this endeavour. Additionally, using an ARM-based computer *should* work, but as of yet it is not tested.

Run `make -f os.make` to create the disk images.

Assuming everything works, you can now load `Starling.img` into Qemu.

## Using Starling

I have not and probably will not test this on anything other than a virtual machine. I recommend using Qemu.

To run Starling, use the following command `qemu-system-x86_64 -fda Starling.img` in the root of the project folder. 

## Creating a custom program

The entry point for all programs is `prog/main.h` inside the `run_program` function.

The rest is a mystery. Using a combination of coffee and 0 documentation ([and the original source code](https://github.com/vladcc/Tetris-OS)) however, it is all figureoutable.

The default program says `Hello World!` and then listens for key presses, then prints out the scancode of that key press.

All C files should be housed inside the `prog` directory, unless you modify the `os.make` file to compile and link your program files.
