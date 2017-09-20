TARGET = essai

all : essai

%.o: %.c
	$(CC) -c $*.c

clean:
	rm -f $(TARGET) 
