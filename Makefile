build:
	gcc tema2.c Task1.c Task2.c Task3.c -o tema2 -lm -g -Wall

clean:
	rm -f tema2
	rm -f Task1
	rm -f Task3
	rm -f Task2
