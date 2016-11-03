make: directory.c
	gcc directory.c -o directory.out
run: make
	./directory.out

clean:
	rm -rf *~
