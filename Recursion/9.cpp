// POWER FUNCTION

#include <bits/stdc++.h>
using namespace std;

int power(int m, int n)    //RECURSIVE METHOD
{
    if (n == 0)
        return 1;
    return power(m, n - 1) * m;
}
int power1(int m, int n)   //RECURSIVE METHOD WITH REDUCED TIME COMPLEXITY
{
    if (n == 0)
        return 1;

    if (n % 2 == 0)
        return power1(m * m, n / 2);

    return m * power1(m * m, (n - 1) / 2);
}
int main()
{
    int r = power1(9, 3);
    cout<<r;
    return 0;
}