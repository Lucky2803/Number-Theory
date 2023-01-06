// #include <bits/stdc++.h>
// #define ll long long
// using namespace std;

// // a^n

// ll power(ll a, ll n, ll p)
// {

//     if (n == 0)
//         return 1;

//     ll temp = power(a, n / 2,p);

//     if (n % 2 == 1)
//         return (a%p * ((temp%p * temp%p)%p))%p;

//     else
//         return (temp%p * temp%p)%p;
// }

// int main()
// {

//     cout<<power(10010123,100000098631,19);
//     return 0;
// }

#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll bin_exp(ll a, ll n, ll p)
{

    ll res = 1;

    while (n > 0)
    {
        if (n % 2 == 1)
        {
            res = (res % p * a % p) % p; // res = (res*a)%p
            n--;
        }
        else
        {
            a = (a % p * a % p) % p; // a= (a*a)%p
            n /= 2;
        }
    }
    return res;
}

int main()
{
    cout << bin_exp(2,10,1000);
    return 0;
}