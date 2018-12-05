all:
	gcc main.c dsh_builtins.c -I apue.3e/include/ -L apue.3e/lib/ -lapue -o shell
