#!/bin/sh

make
for i in `seq 0 5`;
do
	echo "gcc test/test$i.c -o test$i -I includes/ -I libft/includes"
	gcc test/test$i.c -o test$i -I includes/ -I libft/includes
done

for i in `seq 6 12`;
do
	echo "gcc ./test/test$i.c -o test$i -I ./includes/ -I libft/includes -L. -lft_malloc"
	gcc ./test/test$i.c -o test$i -I ./includes/ -I libft/includes -L. -lft_malloc
done
