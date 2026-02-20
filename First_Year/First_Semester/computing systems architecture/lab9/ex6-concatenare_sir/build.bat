call "D:\vs_assembly\VC\Auxiliary\Build\vcvars32.bat"


nasm modul.asm  -fwin32 -o modul.obj
cl main.c /link modul.obj 

main.exe

pause   