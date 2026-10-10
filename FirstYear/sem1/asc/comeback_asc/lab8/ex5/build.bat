nasm -fobj main.asm
nasm -fobj operatie.asm
alink main.obj operatie.obj -oPE -subsys console -entry start
pause
