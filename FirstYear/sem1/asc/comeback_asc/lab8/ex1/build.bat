nasm -fobj main.asm
nasm -fobj permutari.asm
alink main.obj permutari.obj -oPE -subsys console -entry start
main.exe
pause