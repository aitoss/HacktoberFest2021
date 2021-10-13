//clockwise spiral
//***********
//          *
// ******** *
// *      * *
// * **** * *
// * * ** * *
// * *    * *
// * ****** *
// *        *
// **********



#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 11;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j > i - 2 && j < n - i && i % 2 == (n&1)) printf("*");
            else if (j < i - 1 && j < n - i && j % 2 == (n & 1)) printf("*");
            else if (j > n - i -1&& j > i && j % 2 == ((n+1) & 1)) printf("*");
            else if (j < i + 1 && j > n - i - 1 && i % 2 == ((n + 1) & 1)) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
}
