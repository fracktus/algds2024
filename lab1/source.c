#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include "Func.h"

int* FinderCost(int A, int n) {
    int* b;
    int* c;
    int* cost;
    int** M;
    cost = (int*)calloc(n, sizeof(int));
    b = Read(n);
    c = Read(n);
    M = Matrix(b, c, A, n);
    if (b && c && M) {
        Finder(n, A, M, b, cost);
    }
    for (int i = 0; i <= n; ++i) {
        free(M[i]);
    }
    free(M);
    free(b);
    free(c);
    return cost;
}

int main() {
    int A;
    int n;
    int* result;
    scanf("%d %d", &A, &n);

    result = FinderCost(A, n);
    for (int i = 0; i < n; ++i) {
        printf("%d ", result[i]);
    }
    free(result);

    return 0;
}
