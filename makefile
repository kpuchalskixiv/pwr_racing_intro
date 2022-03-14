CC = g++
CFLAGS = -std=gnu99 -Wextra -Wall #-Wno-unused-parameter -Werror

TARGET = zad1

SRCS = zad1.c zad1.h
OBJS = zad1.o 

.PHONY: all clean distclean

all = $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

clean:
	$(RM) $(OBJS) 

distclean:
	$(RM) $(OBJS) $(TARGET)
