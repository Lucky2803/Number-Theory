#include <bits/stdc++.h>
#define mat vector<vector<ll>>
#define ll long long
#define M 1000000007

using namespace std;

mat A; // Declare a matrix A

// Function to read in a matrix
void Build(ll dim)
{
    // Clear the matrix and resize it to the specified dimensions
    A.clear();
    A.resize(dim, vector<ll>(dim));

    // Read in the values for the matrix
    for (ll i = 0; i < dim; i++)
    {
        for (ll j = 0; j < dim; j++)
            cin >> A[i][j];
    }
}

// Function to multiply two matrices
void Multiply(mat &P, mat &Q)
{
    ll dim = P.size(); // Get the dimension of the matrices

    // Create a new matrix to store the result
    mat R(dim, vector<ll>(dim));

    // Multiply the matrices and store the result in R
    for (ll i = 0; i < dim; i++)
    {
        for (ll j = 0; j < dim; j++)
        {
            R[i][j] = 0; // Initialize the element to 0

            // Multiply the matrices and store the result in R[i][j]
            for (ll k = 0; k < dim; k++)
                R[i][j] = (R[i][j] % M + (P[i][k] % M * Q[k][j] % M) % M) % M; // R[i][j] += P[i][k]*Q[k][j];        }
        }

        // Set P to be equal to the result matrix R
        P = R;
    }
}

// Function to raise a matrix to the nth power
void Power(ll n)
{
    ll dim = A.size(); // Get the dimension of the matrix

    // Create a new matrix filled with 0s
    mat res(dim, vector<ll>(dim, 0));

    // Set the diagonal elements of res to 1
    for (ll i = 0; i < dim; i++)
        res[i][i] = 1;

    // Raise the matrix A to the nth power using the exponentiation by squaring algorithm
    while (n)
    {
        if (n % 2)
        {
            Multiply(res, A); // res = res x A
            n--;
        }
        else
        {
            Multiply(A, A); // A = A x A
            n /= 2;
        }
    }

    // Set A to be equal to the result matrix res
    A = res;
}

// Function to display the matrix
void Display()
{
    // Iterate through the rows and columns of the matrix and print each element
    for (ll i = 0; i < A.size(); i++)
    {
        for (ll j = 0; j < A[0].size(); j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    ll T;
    // Read in the number of test cases
    cin >> T;
    // Iterate through each test case
    while (T--)
    {
        // Read in the dimensions and exponent of the matrix
        ll order, n;
        cin >> order >> n;

        // Read in the matrix
        Build(order);

        // Raise the matrix to the nth power
        Power(n);
        
        // Display the resulting matrix
        Display();
    }

    return 0;
}