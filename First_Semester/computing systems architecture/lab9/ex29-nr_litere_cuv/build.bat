call "D:\vs_assembly\VC\Auxiliary\Build\vcvars32.bat"


nasm modul1.asm -fwin32  -o modul1.obj

cl main.c /link modul1.obj

main.exe

pause   