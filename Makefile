NAME   = Connect_Four.o
SRCS   = main.c put.c judg.c r_rotation.c l_rotation.c draw.c putDisplay.c
OBJS   = $(SRCS:.c=.o)
CC     = hgcc
CFLAGS =

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

.c.o:
		$(CC) $(CFLAGS) -c $<
clean:
		rm -f $(OBJS) $(NAME)

# Path: main.c
#include "connect_four.h"
