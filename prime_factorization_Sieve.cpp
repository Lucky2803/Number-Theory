#include <bits/stdc++.h>
#define N 100000001
using namespace std;

// Initializes all elements in the vector to -1
vector<int> Sieve(N, -1);

// Function to build the sieve
void build()
{
    // Initialize the first element to 1
    Sieve[1] = 1;
    // Iterate through all elements in the vector
    for (int i = 2; i * i < N; i++)
    {
        // If the element is not initialized, initialize it
        if (Sieve[i] == -1)
        {
            // Iterate through all multiples of i and initialize them
            for (int j = i * i; j < N; j += i)
                Sieve[j] = i;
        }
    }
}

// Function to find the prime factorization of a number
void factorise(int n, map<int, int> &mp)
{
    // Continue until n is reduced to 1
    while (n > 1)
    {
        // If the element at index n (corresponding to n) has not been initialized, it is a prime number so set it to n(the value itself)
        if (Sieve[n] == -1)
            Sieve[n] = n;

        // Increment the count for the current prime factor and divide n by the prime factor
        mp[Sieve[n]]++;
        n /= Sieve[n];
    }

    // Return the prime factorization
    return;
}

int main()
{
    // Build the sieve
    build(); // O(NloglogN)

    // Read in the number of test cases
    int T;
    cin >> T;

    // Iterate through each test case  //O(TlogN)
    while (T--)
    {
        // Read in the number to find the prime factorization of
        int n;
        cin >> n;

        // Map to store the prime factorization
        map<int, int> mp;

        // Find the prime factorization of the number
        factorise(n, mp); //~O(logn)

        // Iterate through the map and print the prime factorization
        for (auto i : mp)
            cout << "(" << i.first << "," << i.second << ") ";

        // Print a newline after each test case
        cout << endl;
    }

    return 0;
}
