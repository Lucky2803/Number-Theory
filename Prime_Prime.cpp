#include <bits/stdc++.h>
#define N 1000001
using namespace std;

// Sieve is an array of size N to store whether a number is prime or not (1 for prime, 0 for not prime)
vector<long> Sieve(N, 1);

// Prime_Prime is an array of size N to store whether a number is Prime Prime or not (1 for Prime Prime, 0 for not Prime Prime)
vector<long> Prime_Prime(N, 0);

// Function to build the Sieve and Prime_Prime arrays
void build()
{
    // Set 0 and 1 as not prime
    Sieve[0] = Sieve[1] = 0;

    // Use Sieve of Eratosthenes to populate Sieve array
    for (long i = 2; i * i < N; i++)
    {
        if (Sieve[i] == 1)
        {
            for (long j = i * i; j < N; j += i)
            {
                Sieve[j] = 0;
            }
        }
    }

    // Prefix sum the Sieve array to get the number of primes up to a given index
    for (long i = 1; i < N; i++)
    {
        Sieve[i] += Sieve[i - 1];
    }

    // Iterate through the entire array and determine if each number is Prime Prime
    for (long i = 1; i < N; i++)
    {
        // If the number of primes up to the current index is prime, mark the current number as Prime Prime
        if (Sieve[Sieve[i]] - Sieve[Sieve[i] - 1] == 1)
            Prime_Prime[i] = 1;

        // Prefix sum the Prime_Prime array
        Prime_Prime[i] += Prime_Prime[i - 1];
    }
}

int main()
{
    // Build the Sieve and Prime_Prime arrays
    build();
    long T;
    cin >> T;
    while (T--)
    {
        long L, R;
        cin >> L >> R;
        cout << Prime_Prime[R] - Prime_Prime[L - 1]<<endl;
    }

    return 0;
}
