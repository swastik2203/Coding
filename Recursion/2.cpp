// HEAD RECURSION HERE THE RECURSIVE CALL IS THE 1ST LINE AFTER THAT STATEMENTS ARE THERE ALSO TO EXECUTE

#include <bits/stdc++.h>

using namespace std;

void fun(int n)
{
    if (n > 0)
    {
        fun(n - 1);
        cout << n;
    }
}
int main()
{
    int x = 3;

    fun(x);
    return 0;
}
