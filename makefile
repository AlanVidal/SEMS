TARGET = essai essai2 tube tube2 threads thread2 philo

all : $(TARGET)

threads: threads.c philo
	cc threads.c -o threads -lpthread


thread2: thread2.c
	cc thread2.c -o thread2 -lpthread




%.o: %.c
	$(CC) -c $*.c

clean:
	rm -f $(TARGET) 
