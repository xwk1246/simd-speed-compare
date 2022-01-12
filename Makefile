all:
	gcc hw7.c -o hw7.exe
	gcc dataGen.c -o dataGen.exe
	gcc hw7simd.c -mavx -o hw7simd.exe

clean:
	rm -f *.exe *.out