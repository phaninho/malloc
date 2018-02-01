# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwalle <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/20 17:39:34 by jwalle            #+#    #+#              #
#    Updated: 2018/02/01 17:34:46 by stmartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all :
	make -C ../ re
	cp ../*.so .
	gcc test0.c -o test0
	gcc test1.c -o test1 -L. -lft_malloc
	gcc test2.c -o test2 -L. -lft_malloc
	gcc test3.c -o test3 -L. -lft_malloc
	gcc test3bis.c -o test3bis -L. -lft_malloc
	gcc test4.c -o test4 -L. -lft_malloc
	gcc test5.c -o test5 -L. -lft_malloc
	#gcc test.c -o test -L. -lft_malloc

test0:
	./run.sh /usr/bin/time -l ./test0

test1:
	./run.sh /usr/bin/time -l ./test1

test2:
	./run.sh /usr/bin/time -l ./test2

test3:
	./run.sh /usr/bin/time -l ./test3

test3bis:
	./run.sh /usr/bin/time -l ./test3bis

test4:
	./run.sh /usr/bin/time -l ./test4

test5:
	./run.sh /usr/bin/time -l ./test5

clean :
	rm -rf test0 test1 test2 test3 test3bis test4 test5
	rm -rf *.so

.PHONY: all clean test0 test1 test2 test3 test3bis test4 test5
