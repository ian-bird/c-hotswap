output: main.c first.dylib second.dylib
	gcc -o main.out main.c

first.dylib: first/lib.c
	gcc -shared -fPIC -o first.dylib first/lib.c

second.dylib: second/lib.c
	gcc -shared -fPIC -o second.dylib second/lib.c

clean:
	rm  main.out first.dylib second.dylib