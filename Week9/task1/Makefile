CC = gcc 
CFLAGS = -Wall -Wextra -Werror 

SRCS = main.c math_func.c 
OBJS = $(SRCS:.c=.o) 
TARGET = program 

all: $(TARGET) 

$(TARGET): $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

main.o: main.c math_func.h 
	$(CC) $(CFLAGS) -c main.c  

math_func.o: math_func.c math_func.h
	$(CC) $(CFLAGS) -c math_func.c 

clean: 
	rm -f $(OBJS) $(TARGET) 
