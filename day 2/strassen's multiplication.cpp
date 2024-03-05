#include <iostream>

using namespace std;

// Function to add two matrices
void addMatrix(int **A, int **B, int **C, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to subtract two matrices
void subtractMatrix(int **A, int **B, int **C, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Function to multiply two matrices using Strassen's algorithm
void strassenMultiply(int **A, int **B, int **C, int n) {
    // Base case: If matrices are 1x1
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    // Divide matrices into submatrices
    int mid = n / 2;

    int **A11 = new int*[mid];
    int **A12 = new int*[mid];
    int **A21 = new int*[mid];
    int **A22 = new int*[mid];

    int **B11 = new int*[mid];
    int **B12 = new int*[mid];
    int **B21 = new int*[mid];
    int **B22 = new int*[mid];

    for (int i = 0; i < mid; ++i) {
        A11[i] = new int[mid];
        A12[i] = new int[mid];
        A21[i] = new int[mid];
        A22[i] = new int[mid];

        B11[i] = new int[mid];
        B12[i] = new int[mid];
        B21[i] = new int[mid];
        B22[i] = new int[mid];
    }

    // Divide matrices A and B into submatrices
    for (int i = 0; i < mid; ++i) {
        for (int j = 0; j < mid; ++j) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + mid];
            A21[i][j] = A[i + mid][j];
            A22[i][j] = A[i + mid][j + mid];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + mid];
            B21[i][j] = B[i + mid][j];
            B22[i][j] = B[i + mid][j + mid];
        }
    }

    // Recursive steps of Strassen's algorithm
    int **P1 = new int*[mid];
    int **P2 = new int*[mid];
    int **P3 = new int*[mid];
    int **P4 = new int*[mid];
    int **P5 = new int*[mid];
    int **P6 = new int*[mid];
    int **P7 = new int*[mid];

    for (int i = 0; i < mid; ++i) {
        P1[i] = new int[mid];
        P2[i] = new int[mid];
        P3[i] = new int[mid];
        P4[i] = new int[mid];
        P5[i] = new int[mid];
        P6[i] = new int[mid];
        P7[i] = new int[mid];
    }

    subtractMatrix(B12, B22, P1, mid);
    strassenMultiply(A11, P1, P1, mid);

    addMatrix(A11, A12, P2, mid);
    strassenMultiply(P2, B22, P2, mid);

    addMatrix(A21, A22, P3, mid);
    strassenMultiply(P3, B11, P3, mid);

    subtractMatrix(B21, B11, P4, mid);
    strassenMultiply(A22, P4, P4, mid);

    addMatrix(A11, A22, P5, mid);
    addMatrix(B11, B22, P6, mid);
    strassenMultiply(P5, P6, P5, mid);

    subtractMatrix(A12, A22, P6, mid);
    addMatrix(B21, B22, P7, mid);
    strassenMultiply(P6, P7, P6, mid);

    subtractMatrix(A11, A21, P7, mid);
    addMatrix(B11, B12, P7, mid);
    strassenMultiply(P7, P7, P7, mid);

    // Calculate resulting submatrices
    addMatrix(P5, P4, P5, mid);
    subtractMatrix(P5, P2, P5, mid);
    addMatrix(P5, P6, P5, mid);

    addMatrix(P1, P2, P1, mid);

    addMatrix(P3, P4, P3, mid);

    subtractMatrix(P5, P3, P3, mid);
    subtractMatrix(P1, P7, P1, mid);

    // Combine submatrices to get the resulting matrix
    for (int i = 0; i < mid; ++i) {
        for (int j = 0; j < mid; ++j) {
            C[i][j] = P5[i][j];
            C[i][j + mid] = P1[i][j];
            C[i + mid][j] = P3[i][j];
            C[i + mid][j + mid] = P7[i][j];
        }
    }

    // Free memory
    for (int i = 0; i < mid; ++i) {
        delete[] A11[i];
        delete[] A12[i];
        delete[] A21[i];
        delete[] A22[i];
        delete[] B11[i];
        delete[] B12[i];
        delete[] B21[i];
        delete[] B22[i];
        delete[] P1[i];
        delete[] P2[i];
        delete[] P3[i];
        delete[] P4[i];
        delete[] P5[i];
        delete[] P6[i];
        delete[] P7[i];
    }
    delete[] A11;
    delete[] A12;
    delete[] A21;
    delete[] A22;
    delete[] B11;
    delete[] B12;
    delete[] B21;
    delete[] B22;
    delete[] P1;
    delete[] P2;
    delete[] P3;
    delete[] P4;
    delete[] P5;
    delete[] P6;
    delete[] P7;
}

// Function to print a matrix
void printMatrix(int **matrix, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n = 2;
    int **A = new int*[n];
    int **B = new int*[n];
    int **C = new int*[n];
    for (int i = 0; i < n; ++i) {
        A[i] = new int[n];
        B[i] = new int[n];
        C[i] = new int[n];
    }

    // Populate matrices A and B
    A[0][0] = 1; A[0][1] = 2; A[1][0] = 3; A[1][1] = 4;
    B[0][0] = 5; B[0][1] = 6; B[1][0] = 7; B[1][1] = 8;

    cout << "Matrix A:" << endl;
    printMatrix(A, n);

    cout << "Matrix B:" << endl;
    printMatrix(B, n);

    strassenMultiply(A, B, C, n);

    cout << "Matrix C (Result of Strassen's multiplication):" << endl;
    printMatrix(C, n);

    // Free memory
    for (int i = 0; i < n; ++i) {
        delete[] A[i];
        delete[] B[i];
        delete[] C[i];
    }
    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}
