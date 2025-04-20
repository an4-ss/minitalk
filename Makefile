CC = cc
CFLAGS = -Wall -Wextra -Werror -g
CLIENT_SRCS = client.c utils.c
SERVER_SRCS = server.c utils.c
OBJ_SERVER = $(SERVER_SRCS:.c=.o)
OBJ_CLIENT = $(CLIENT_SRCS:.c=.o)
CLIENT = client
SERVER = server

all: $(CLIENT) $(SERVER)

$(CLIENT): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) -o $@ $^

$(SERVER): $(OBJ_SERVER)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f  $(OBJ_CLIENT) $(OBJ_SERVER)

fclean: clean
	rm -f $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re bonus
