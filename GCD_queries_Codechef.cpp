#pragma GCC optimize("O2")
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Build(vector<int> &A, vector<int> &B, vector<int> &C)
{

    int n = A.size();
    int gcd_l = A[0];
    int gcd_r = A[n - 1];

    for (int i = 0, j = n - 1; i < n, j >= 0; i++, j--)
    {
        gcd_l = __gcd(A[i], gcd_l);
        gcd_r = __gcd(A[j], gcd_r);

        B[i] = gcd_l;
        C[j] = gcd_r;
    }
}

int Solve(vector<int> &A, vector<int> &B, vector<int> &C, int l, int h)
{

    int gcd1 = A[0], gcd2 = A[A.size() - 1];

    if (l > 0)
        gcd1 = B[l - 1];

    if (h < A.size() - 1)
        ;
    gcd2 = C[h + 1];

    if (l == 0)
        return gcd2;

    if (h == A.size() - 1)
        return gcd1;

    return __gcd(gcd1, gcd2);
}

int main()
{

    int T;
    cin >> T;
    while (T--)
    {
        int N, Q;
        cin >> N >> Q;

        vector<int> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];

        vector<int> B(N);
        vector<int> C(N);
        Build(A, B, C);

        while (Q--)
        {
            int L, R;
            cin >> L >> R;
            cout << Solve(A, B, C, L - 1, R - 1) << endl;
        }
    }

    return 0;
}
