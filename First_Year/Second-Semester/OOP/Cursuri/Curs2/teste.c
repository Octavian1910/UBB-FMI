#include <assert.h>
#include <math.h>
int gcd(int a,int b)
{
    /*greatesst common divisor
     *Pre : a,b >= 0, a*a + b*b != 0
     *return gcd
     */
    a = abs(a);
    b = abs(b);
    if(a == 0)
    {
        return b;
    }
    if (b == 0)
    {
        return a;
    }
    while (a!=b)
    {
        if (a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }
    return a;
}

void test_gcd()
{
    assert(gcd(2,4) == 2);
    assert(gcd(3,27) == 3);
    assert(gcd(7,27) == 1);
    assert(gcd(7,-27) == 1);
}

int main()
{
    test_gcd();
    return 0;
}