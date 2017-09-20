TARGET = essai essai2 tube tube2

all : $(TARGET)

%.o: %.c
	$(CC) -c $*.c

clean:
	rm -f $(TARGET) 
