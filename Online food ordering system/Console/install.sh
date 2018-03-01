ecpg ConsoleApp.pgc
gcc -I/usr/local/pgsql/include -c ConsoleApp.c
gcc -o ConsoleApp ConsoleApp.o -I/usr/include/postgresql  -lecpg
./ConsoleApp