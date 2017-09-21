TARGET = essai essai2 tube tube2 threads thread2 philo Producteur
LDFLAGS = -lpthread -std=c99 

all : $(TARGET)

clean:
	rm -f $(TARGET) 
