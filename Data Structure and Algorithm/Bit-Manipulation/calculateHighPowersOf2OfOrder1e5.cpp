#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;

#define pb emplace_back
#define mp make_pair
#define F first
#define Endl "\n"
#define S second
#define all(c) (c).begin(),(c).end()
#define int long long

string print_2_pow_n(int n)
{
    int i, j, blen = n / 32 + 1, dlen = n / 29 + 1;
    string ans;
    uint32_t bin[blen], dec[dlen];
    uint64_t num;

    for (i = 0; i < blen; i++)
        bin[i] = 0;
    bin[n / 32] = (uint32_t)1 << (n % 32);

    for (j = 0; blen > 0;)
    {
        for (num = 0, i = blen; i-- > 0;)
        {
            num = (num << 32) | bin[i];
            bin[i] = num / 1000000000;
            num = num % 1000000000;
        }
        dec[j++] = (uint32_t)num;
        while (blen > 0 && bin[blen - 1] == 0)
            blen--;
    }

    while (j-- > 0)
    {
        stringstream ss;
        ss << setw(9) << setfill('0') << dec[j];
        ans += ss.str();
    }
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i] != '0')
        {
            ans = ans.substr(i, ans.size() - i);
            break;
        }
    }
    return ans;
}


signed main()
{

#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

    srand(time(NULL));  //for stress-testing
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string ans = print_2_pow_n(n);
    cout << ans;
}
