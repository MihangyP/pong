NAME = pong
SRC_FILES = main.c
HEADER_FILES = pong.h
CC = cc
CFLAGS = -Wall -Wextra
RM = rm -rf
INCLUDING = -I. -I./raylib/include
LINKING = -Lraylib/lib -l:libraylib.a -lm

all: $(NAME)

$(NAME): $(SRC_FILES) $(HEADER_FILES)
	$(CC) $(CFLAGS) $(INCLUDING) $(SRC_FILES) -o $(NAME) $(LINKING)

clean:
	$(RM) $(NAME)

re: clean all

.PHONY: all clean re
