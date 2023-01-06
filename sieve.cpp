#include <bits/stdc++.h>
using namespace std;
#define N 90000001

vector<bool> Sieve(N, 1);

void build_sieve()
{

    Sieve[0] = Sieve[1] = 0;

    for (int i = 2; i * i < N; i++)
    {
        if (Sieve[i] == 1)
        {
            for (int j = i * i; j < N; j += i)
                Sieve[j] = 0;
        }
    }


}

int main()
{

    build_sieve();

    return 0;
}