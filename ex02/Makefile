# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mriant <mriant@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 10:29:46 by mriant            #+#    #+#              #
#    Updated: 2023/01/20 10:29:48 by mriant           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mutant

SRCS = ${addprefix srcs/, \
		 main.cpp \
		 Span.cpp}

OBJS = ${SRCS:srcs/%.cpp=build/%.o}
DEPS = ${OBJS:%.o=%.d}

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g
IFLAGS = -I./includes -MMD
LFLAGS =

${NAME}: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ${NAME} ${LFLAGS}

build/%.o: srcs/%.cpp
	mkdir -p build
	${CXX} ${CXXFLAGS} -c $< -o $@ ${IFLAGS}

.PHONY: all
all: ${NAME}

.PHONY: clean
clean:
	rm -rf build

.PHONY: fclean
fclean: clean
	rm -rf ${NAME}

.PHONY: re
re: fclean
	make -C .

-include ${DEPS}
