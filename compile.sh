make fclean -C ../$1
make -C ../$1 
make clean -C ../$1
rm output
gcc main.c ../$1/libftprintf.a -o output
echo "===================="
./output
