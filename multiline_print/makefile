multiline.out: sample.o multiline.o
	gcc -o multiline.out sample.o multiline.o

sample.o: sample.c .FORCE
	gcc -c sample.c

multiline.o: multiline.c .FORCE
	gcc -c multiline.c

.FORCE:
