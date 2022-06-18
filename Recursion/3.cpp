//STATIC AND GLOBAL VARIABLE

#include <bits/stdc++.h>
using namespace std;
int fun(int n)
{                        
    static int x = 0;   //IT WILL BE DECLARED ONLY ONCE AND IF NOT INITIALISED THEN ASSIGNED 0 AUTO MATICALLY IT WILL BE SAME FOR EVERY
                        //BE SAME FOR EVERY FUNCTION CALL  AND IT IS CREATED IN CODE SECTION OF MAIN MEMORY
                        //GLOBAL VARIABLE ARE SAME ONLY DECLARED OUTSIDE THE SCOPE AND ACCESSIBLE FOR EVERY FUNC
    if (n > 0)
    {
        x++;
        return fun(n - 1) + x;
    }
    return 0;
}
int main()
{
    int r;
    r = fun(5);
    cout<<r<<endl;

    r = fun(5);
    cout<<r<<endl;

    return 0;
}