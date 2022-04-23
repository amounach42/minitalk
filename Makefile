# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amounach <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/22 00:10:00 by amounach          #+#    #+#              #
#    Updated: 2022/04/23 01:52:11 by amounach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = minitalk
FLAGS = -Wall -Wextra -Werror
RMV = rm -rf
HEADER = minitalk.h

COMMON = utils.c
SRC_S = server.c $(COMMON)
SRC_C = client.c $(COMMON)

SRC_S_B = server_bonus.c $(COMMON)
SRC_C_B = client_bonus.c $(COMMON)

OBJ_S_B = $(SRC_S_B:%.c=%.o)
OBJ_C_B = $(SRC_C_B:%.c=%.o)

OBJ_S = $(SRC_S:%.c=%.o)
OBJ_C = $(SRC_C:%.c=%.o)


all: server client

bonus: server_bonus client_bonus

server_bonus: $(OBJ_S_B)
	$(CC) $(FLAGS) $^ -o $@

client_bonus: $(OBJ_C_B)
	$(CC) $(FLAGS) $^ -o $@

server: $(OBJ_S)
	$(CC) $(FLAGS) $^ -o $@

client: $(OBJ_C)
	$(CC) $(FLAGS) $^ -o $@

%.o: %.c minitalk.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RMV) $(OBJ_C) $(OBJ_C_B) $(OBJ_S) $(OBJ_S_B)

fclean: clean
	$(RMV) client server client_bonus server_bonus

re : fclean all
