gcc ../src/first.c -c -o first.o
gcc first.o ../lib/libraylibdll.a -o ../bin/first.exe
start ../bin/first.exe

pause