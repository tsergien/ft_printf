make fclean -C ../ft_pr
make -C ../ft_pr 
make clean -C ../ft_pr
rm run
gcc -Wall -Wextra -Werror main.c ../ft_pr/libftprintf.a -o run -g
echo "===================="
./run
