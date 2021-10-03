/* 
 Check the if number is power of two or not
*/

#include <bits/stdc++.h>
using namespace std;
bool checkPowerOf2(int n)
{
    return (n && !(n & (n - 1)));
}

int main()
{
    int n;
    cin >> n;
    cout << checkPowerOf2(n) << endl;
}