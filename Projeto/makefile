all: prog.exe

prog.exe: lerPGM.o fc.o main.o
	gcc -o $@ $^

lerPGM.o: lerPGM.c
	gcc -o $@ -c $<

fc.o: fc.c
	gcc -o $@ -c $<

main.o: main.c 
	gcc -o $@ -c $<

clean:
	rm -f prog.exe lerPGM.o fc.o main.o
