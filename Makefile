all:
	aarch64-linux-gnu-gcc ./main.c -static -g
run:
	qemu-aarch64-static -g 2345 ./a.out
