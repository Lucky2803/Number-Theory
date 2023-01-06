#include <bits/stdc++.h>
#define ll long long
using namespace std;

// a^n

ll power(ll a, ll n)
{

    if (n == 0)
        return 1;

    ll temp = power(a, n / 2);

    if (n % 2 == 1)
        return a * temp * temp;

    else
        return temp * temp;
}



int main()
{

    cout<<power(2,10);
    return 0;
}