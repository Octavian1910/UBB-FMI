call "D:\vs_assembly\VC\Auxiliary\Build\vcvars32.bat"


nasm modul.asm  -fwin32 -o modul.obj
nasm modul2.asm  -fwin32 -o modul2.obj
cl main.c /link modul.obj modul2.obj

main.exe

pause   