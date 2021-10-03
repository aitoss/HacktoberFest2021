#include <bits/stdc++.h>
using namespace std;
#define int long long

inline int geek_onacci(int a, int b, int c, int n)
{
    if (n == 1)
        return a;

    if (n == 2)
        return b;

    if (n == 3)
        return c;

    return geek_onacci(a, b, c, n - 1) + geek_onacci(a, b, c, n - 2) + geek_onacci(a, b, c, n - 3);
}

// Driver code to test above functions
int32_t main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c, n;

        cin >> a >> b >> c >> n;

        cout << geek_onacci(a, b, c, n) << endl;
    }

    return 0;
}