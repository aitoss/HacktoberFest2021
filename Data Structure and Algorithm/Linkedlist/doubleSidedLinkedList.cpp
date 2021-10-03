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

struct node
{
    int data;
    node* link;
} *str, *save, *newptr, *ptr, *temp;

node * create_new_node(int x)
{
    ptr = new node;
    ptr->data = x;
    ptr->link = NULL;
    return ptr;
}

void Insert_at_beg(node* np)
{
    if (str == NULL)
    {
        str = np;
        temp = np;
    }
    else
    {
        save = str;
        str = np;
        np->link = save;
    }
}

void Insert_at_end(node* np)
{
    if (str == NULL)
    {
        str = np;
        temp = np;
    }
    else
    {
        temp->link = np;
        temp = np;
    }
}
void display(node* str)
{
    while (str != NULL)
    {
        cout << str->data << " ";
        str = str->link;
    }
    cout << "\n";
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
    cout << "Entering elements at the start of the list.\n";
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        newptr = create_new_node(x);
        Insert_at_beg(newptr);
        display(str);
    }
    cout << "Now entering elements at the end.\n";
    n = 5;
    while (n--)
    {
        int x;
        cin >> x;
        newptr = create_new_node(x);
        Insert_at_end(newptr);
        display(str);
    }
}
