TARGET = essai essai2 tube

all : $(TARGET)

%.o: %.c
	$(CC) -c $*.c

clean:
	rm -f $(TARGET) 
