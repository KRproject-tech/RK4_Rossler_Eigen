
CC = g++
CFLAGS = -O3 -I ./.


all:
	$(CC) $(CFLAGS) -fpermissive ./source/*.cpp -c
	$(CC) *.o -o main.exe

clean:
	rm -R *.o *.exe