# $^ - all dependencies
# $< - the first dependency
# $@ - the target file

# generate list of asm sources
ASM_SOURCES = $(wildcard boot/pre32_functions/*.asm boot/gdt/*.asm boot/32pm_functions/*.asm)

# generate list of c sources
C_SOURCES = $(wildcard kernel/*.c drivers/*.c) $(shell find prog/ -name "*.c")

# generate list of headers
HEADERS = $(wildcard kernel/*.h drivers/*.h) $(shell find prog/ -name "*.h")

# include path
KERNEL = kernel/
DRIVERS = drivers/

# convert .c to .o
OBJ = ${C_SOURCES:.c=.o}

# making the disk image
images/os.img: boot/bootsec.bin kernel/kernel.bin
	mkdir -p images
	cat $^ > images/os.img
	dd if=images/os.img of=Starling.img bs=512 count=2880

kernel/kernel.bin: boot/k_entry.o ${OBJ}
	ld -m elf_i386 -o $@ -Ttext 0x1000 $^ --oformat binary

# all .c files to object files
%.o : %.c ${HEADERS}
	gcc -I ${KERNEL} -I ${DRIVERS} -m32 -ffreestanding -c $< -o $@ -fno-PIE -fno-PIC

boot/k_entry.o: boot/k_entry.asm
	nasm $< -f elf -o $@

# make the boot sector
boot/bootsec.bin: boot/bootsec.asm $(ASM_SOURCES)
	nasm $< -f bin -I 'boot/' -o $@

clean:
	sudo rm -r kernel/ boot/ images/ docs/ drivers/ prog/ -f