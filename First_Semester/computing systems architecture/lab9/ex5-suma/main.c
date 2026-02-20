#include <stdio.h>

int calcul(int a, int b, int c);

int main(void)
{
    int a, b, c;
    int rezultat;

    printf("a = ? b = ? c = ?");
    scanf("%d %d %d", &a, &b, &c);

    rezultat = calcul(a, b, c);

    printf("a + b - c = %d\n", rezultat);

    return 0;
}
