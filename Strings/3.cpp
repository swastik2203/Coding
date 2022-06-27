//COUNTING VOWELS CONSONANTS AND WORDS AND SPACES

#include <bits/stdc++.h>
using namespace std;

int main()
{
    char A[] = "How are   u";
    int i, words = 0, vcount = 0, ccount = 0;

    for ( i = 0; A[i] != '\0'; i++)
    {
        if (A[i] == 'a' || A[i] == 'e' || A[i] == 'i' || A[i] == 'o' || A[i] == 'u' || 
            A[i] == 'A' || A[i] == 'E' || A[i] == 'I' || A[i] == 'O' || A[i] == 'U' )
        {
            vcount++;
        }
        else if (A[i] >= 65 && A[i] <= 90 || A[i] >= 97 && A[i] <= 122)
        {
            ccount ++;
        }
        if (A[i] == ' ' && A[i-1] != ' ')   // this logic will help us prevent multiple spaces error b4 any word
        {
            words++;
        }
    }
    cout<<"no. of vowels = "<<vcount<<endl;
    cout<<"no. of consonants = "<<ccount<<endl;
    cout<<"no. of words = "<<words+1;   
}