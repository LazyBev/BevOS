gcc -m32 -ffreestanding -fno-stack-protector -fno-builtin -c kernel.c -o kernel.o
gcc -m32 -ffreestanding -fno-stack-protector -fno-builtin -c vga.c -o vga.o
nasm -f elf boot.s -o boot.o
ld -m elf_i386 -T linker.ld -o kernel.bin boot.o kernel.o vga.o
mv kernel.bin Bev/boot/kernel
grub-mkrescue -o Bev.iso Bev/
qemu-system-i386 -cdrom Bev.iso