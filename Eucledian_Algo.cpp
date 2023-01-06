#include <bits/stdc++.h>
using namespace std;

// GCD of 2 numbers
// NOTE: built in function that can be used for cpp version 17 and above:  __gcd(int, int)
int GCD(int A, int B)
{

    if (B == 0)
        return A;

    return GCD(B, A % B);
}

// GCD of an array of elements in a range

int GCD_Array(vector<int> &A, int start, int end)
{

    int res = A[start];

    for (int i = start + 1; i <= end; i++)
        res = GCD(A[i], A[i - 1]);

    return res;
}

// prefix array to answer GCD queries in a range

vector<int> Prefix_GCD(vector<int> &A)
{
    int n = A.size();

    vector<int> B(n, A[0]);

    for (int i = 1; i < n; i++)
    {
        B[i] = GCD(A[i], A[i - 1]);
    }

    return B;
}

// suffix array to answer GCD queries in a range
vector<int> Prefix_GCD(vector<int> &A)
{
    int n = A.size();

    vector<int> B(n, A[n-1]);

    for (int i = n - 2; i >= 0; i--)
    {
        B[i] = GCD(A[i], A[i + 1]);
    }

    return B;
}

int main()
{

    return 0;
}