QUESTIONS: 5 8a 8b 9 10 13a 13b

all: $(QUESTIONS)

5: 5.c
	cc 5.c -Wall -o 5

8a: 8a.c
	cc 8a.c -Wall -o 8a

8b: 8b.c
	cc 8b.c -Wall -o 8b

9: 9.c
	gcc 9.c -Wall -o 9 -lpthread

10: 10.c
	gcc 10.c -Wall -o 10 -lpthread

13a: 13a.c
	gcc 13a.c -Wall -o 13a

13b: 13b.c
	gcc 13b.c -Wall -o 13b

.PHONY: clean

clean:
	rm -f 5 8a 8b 9 10 13a 13b