#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> Matrix;

vector<vector<int>> Multiply_Conventional(vector<vector<int>> &m1, vector<vector<int>> &m2)
{
    int n = m1.size();
    int m = m1[0].size();
    ;
    int l = m2[0].size();

    vector<vector<int>> ans(n, vector<int>(l, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < l; k++)
            {
                ans[i][k] += m1[i][j] * m2[j][k];
            }
        }
    }
    return ans;
}

// Function to add two matrices
Matrix add(const Matrix &A, const Matrix &B, int size)
{
    Matrix result(size, vector<int>(size, 0));
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return result;
}

// Function to subtract two matrices
Matrix sub(const Matrix &A, const Matrix &B, int size)
{
    Matrix result(size, vector<int>(size, 0));
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
    return result;
}

// Strassen's Matrix Multiplication Algorithm
Matrix strassen(const Matrix &A, const Matrix &B, int size)
{
    if (size == 1)
    {
        return {{A[0][0] * B[0][0]}};
    }

    int newSize = size / 2;

    // Create submatrices
    Matrix A11(newSize, vector<int>(newSize)), A12(newSize, vector<int>(newSize));
    Matrix A21(newSize, vector<int>(newSize)), A22(newSize, vector<int>(newSize));
    Matrix B11(newSize, vector<int>(newSize)), B12(newSize, vector<int>(newSize));
    Matrix B21(newSize, vector<int>(newSize)), B22(newSize, vector<int>(newSize));

    // Splitting matrices into submatrices
    for (int i = 0; i < newSize; i++)
    {
        for (int j = 0; j < newSize; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Compute 7 intermediate matrices
    Matrix M1 = strassen(add(A11, A22, newSize), add(B11, B22, newSize), newSize);
    Matrix M2 = strassen(add(A21, A22, newSize), B11, newSize);
    Matrix M3 = strassen(A11, sub(B12, B22, newSize), newSize);
    Matrix M4 = strassen(A22, sub(B21, B11, newSize), newSize);
    Matrix M5 = strassen(add(A11, A12, newSize), B22, newSize);
    Matrix M6 = strassen(sub(A21, A11, newSize), add(B11, B12, newSize), newSize);
    Matrix M7 = strassen(sub(A12, A22, newSize), add(B21, B22, newSize), newSize);

    // Compute the result submatrices
    Matrix C11 = add(sub(add(M1, M4, newSize), M5, newSize), M7, newSize);
    Matrix C12 = add(M3, M5, newSize);
    Matrix C21 = add(M2, M4, newSize);
    Matrix C22 = add(sub(add(M1, M3, newSize), M2, newSize), M6, newSize);

    // Combine submatrices into final result
    Matrix C(size, vector<int>(size, 0));
    for (int i = 0; i < newSize; i++)
    {
        for (int j = 0; j < newSize; j++)
        {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }

    return C;
}

// Main function to test Strassen's Algorithm
int main()
{
    Matrix A = {{1, -2, 3, -11}, {-3, 4, 6, -11}, {8, -9, 10, -11}, {8, -9, 10, -11}};
    Matrix B = {{4, -5, 6, -11}, {6, 7, -8, -11}, {10, 11, -12, -11}, {8, -9, 10, -11}};

    int size = A.size();

    Matrix result = strassen(A, B, size);
    Matrix result1=Multiply_Conventional(A,B);
    cout << "Using Conventional way : Resultant Matrix:\n";
    for (auto row : result1)
    {
        for (auto ele : row)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
    cout << "Using Strassen's Method way : Resultant Matrix:\n";
    for (auto row : result)
    {
        for (auto ele : row)
        {
            cout << ele << " ";
        }
        cout << endl;
    }

}
