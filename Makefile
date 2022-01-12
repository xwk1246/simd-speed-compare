all:
	gcc hw7.c -o hw7.exe

dataGen:
	gcc dataGen.c -o dataGen.exe

clean:
	rm -f *.exe *.out