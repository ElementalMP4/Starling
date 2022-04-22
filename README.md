# Starling - A barebones OS

Starling is based on [this existing project](https://github.com/vladcc/Tetris-OS) which has been modified to run custom programs with cutting edge VGA text mode graphics and an entire 16 colours to work with.

Starling removes all the unnecessary bloat from a traditional operating system such as Linux or Windows. Starling has no ads, no networking, no filesystem and no support for the backspace key *(yet...)*. 

Starling is an opportunity to learn some C and x86 assembly. I learnt more about C whilst doing this project than I have since I first touched C in 2010.

## Building Starling

To build Starling, you will need the following prerequisites:

- Make
- GCC
- NASM
- Qemu
- A flavour of Linux

It is possible to use WSL for the linux component of this endeavour. Additionally, using an ARM-based computer *should* work, but as of yet it is not tested.

Run `make` to create the disk image.

Assuming everything works, you can now load `Starling.img` into Qemu.

## Using Starling

I have not and probably will not test this on anything other than a virtual machine. I recommend using Qemu.

To run Starling, use the following command `qemu-system-x86_64 -hda Starling.img` in the root of the project folder. 

## Creating a custom program

Check the `docs` folder for documentation
