call "D:\vs_assembly\VC\Auxiliary\Build\vcvars32.bat"


nasm modul1.asm  -fwin32 -o modul1.obj
nasm modul2.asm  -fwin32 -o modul2.obj
cl main.c /link modul1.obj modul2.obj 

main.exe

pause   