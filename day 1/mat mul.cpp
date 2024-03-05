#include <stdio.h>
#include <time.h>

#define N 3 // Size of the matrices

// Function to multiply two matrices
void multiplyMatrices(int mat1[][N], int mat2[][N], int result[][N]) {
    int i, j, k;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            result[i][j] = 0; // Initialize result cell to 0
            for (k = 0; k < N; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j]; // Multiply and accumulate
            }
        }
    }
}

int main() {
    int mat1[N][N] = {{1, 5, 3}, {4, 5, 6}, {8, 8, 9}};
    int mat2[N][N] = {{9, 8, 7}, {6, 4, 4}, {3, 2, 1}};
    int result[N][N];
    int i,j;
    clock_t start, end;
    double cpu_time_used;

    // Measure time taken to multiply matrices
    start = clock();
    multiplyMatrices(mat1, mat2, result);
    end = clock();

    // Calculate CPU time used
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Display the result matrix
    printf("Resultant Matrix:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    printf("Time taken to multiply two %dx%d matrices: %f seconds\n", N, N, cpu_time_used);

    return 0;
}
