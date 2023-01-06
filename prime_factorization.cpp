#include <bits/stdc++.h>
using namespace std;

void PrimeFactorize(int N)
{

    for (int i = 2; i * i <= N; i++)
    {

        if (N % i == 0)
        {
            int cnt = 0;
            while (N % i == 0)
            {
                cnt++;
                N /= i;
            }
            cout<<"("<<i<<","<<cnt<<")"<<endl;
        }
    }

    if(N>1)
        cout << "(" << N << "," << 1 << ")" << endl;
}

int main()
{
    PrimeFactorize(256*3*5*49*121*13);

    return 0;
}