#include "linear_sum.h"

int iterativeLinearSum(const std::vector<int>& A, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += A[i];
    }
    return sum;
}

int recursiveLinearSum(const std::vector<int>& A, int n)
{
    if (n == 1) {
        return A[0];
    } else {
        return recursiveLinearSum(A, n - 1) + A[n - 1];
    }
}
