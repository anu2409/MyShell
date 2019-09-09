CC=gcc
TARGET=oscode
 
all:
	$(CC) oscode.c -o $(TARGET)
 
clean:
	rm $(TARGET)