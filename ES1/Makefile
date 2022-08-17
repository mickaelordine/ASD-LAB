OBJS	= main.o getfile.o provapuntatorevoi.o
SOURCE	= main.c getfile.c provapuntatorevoi.c
HEADER	= getfile.h provapuntatorevoi.h
OUT	= output
CC	 = gcc
FLAGS	 = -g -c
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.c
	$(CC) $(FLAGS) main.c 

getfile.o: getfile.c
	$(CC) $(FLAGS) getfile.c 

provapuntatorevoi.o: provapuntatorevoi.c
	$(CC) $(FLAGS) provapuntatorevoi.c 


clean:
	rm -f $(OBJS) $(OUT)