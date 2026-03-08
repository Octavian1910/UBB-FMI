#include <stdio.h>

int main()
{
    int n = 0, s = 0;
    printf("Cate numere vrei sa citesti?");
    scanf("%d", &n);
    for (int i = 0 ; i < n ; ++i)
    {
        printf("\n%d = ",i + 1);
        int x = 0;
        scanf("%d", &x);
        s += x;
    }
    printf("%d",s);
    return 0;
}