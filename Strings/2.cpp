//TOGGLE CASE
#include <bits/stdc++.h>
using namespace std;

int main()
{
    char s[] = "w5lcOme";   // it adds a null character automatically at the end
    int i;
    for (i = 0; s[i] != '\0'; i++)  // scanning till we find '\0'
    {
        // if(s[i] == '5')      //even 5 has a ascii character i.e 53 
        //    s[i] += 32;       //if we add 32 to 53  =  85 this is ascii of 'U'
        if (s[i] >= 65 && s[i] <= 90)      // we are checking if capital then add 32 to make it small
           s[i] += 32;
        else if(s[i] >= 'a' && s[i] <= 122) // we are checking if small then subtract 32 to make it capital
           s[i] -= 32;  

        cout<<s[i];    
    }

    
    

    return 0;
}