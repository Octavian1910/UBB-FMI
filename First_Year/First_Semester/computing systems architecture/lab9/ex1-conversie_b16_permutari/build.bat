call "D:\vs_assembly\VC\Auxiliary\Build\vcvars32.bat"


nasm -fwin32 modul.asm -o modul.obj
nasm -fwin32 modul2.asm -o modul2.obj
cl main.c /link modul.obj modul2.obj

main.exe

pause   