#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll bin_exp(ll a, ll n)
{

    ll res = 1;

    while (n > 0)
    {
        if (n % 2 == 1)
        {
            res *= a;
            n--;
        }
        else
        {
            a *= a;
            n /= 2;
        }
    }
    return res;
}

int main()
{
    cout<<bin_exp(2,10);
    return 0;
}