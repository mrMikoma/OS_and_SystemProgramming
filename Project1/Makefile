# Variables
CC = gcc  # Default compiler
CFLAGS = -Wall -g  # Flags (warnings, debugging symbols)
OBJECTS = main.o lib.o  # Replace with your source files
TARGET = reverve  # Adjust to your desired executable name

# Targets and Rules
$(TARGET): $(OBJECTS)
		$(CC) $(OBJECTS) -o $(TARGET)

main.o: main.c lib.h  # Add relevant headers if needed
		$(CC) $(CFLAGS) -c main.c 

lib.o: lib.c lib.h
		$(CC) $(CFLAGS) -c lib.c

# Cleaning up
clean:
		rm -f $(OBJECTS) $(TARGET) 
