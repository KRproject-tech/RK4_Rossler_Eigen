echo off

make clean
make
rm -R *.o
main.exe


set /P USR_INPUT_STR="Finish!!"
