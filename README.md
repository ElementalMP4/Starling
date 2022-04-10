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
