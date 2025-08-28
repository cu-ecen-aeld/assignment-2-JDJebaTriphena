CC = $(CROSS_COMPILER)gcc
CFLAGS = -Wall -Wextra -g
SRC = writer.c
OBJ = $(SRC:.c=.o)
TARGET = writer

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
