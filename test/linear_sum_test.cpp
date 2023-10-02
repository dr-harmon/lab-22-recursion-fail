#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark_all.hpp>

#include "linear_sum.h"

using namespace std;

TEST_CASE("Linear sum can be found iteratively")
{
    vector<int> A = {1, 2, 3, 4, 5, 6};
    REQUIRE(iterativeLinearSum(A, 6) == 21);
    REQUIRE(iterativeLinearSum(A, 1) == 1);
}

TEST_CASE("Linear sum can be found recursively")
{
    vector<int> A = {1, 2, 3, 4, 5, 6};
    REQUIRE(recursiveLinearSum(A, 6) == 21);
    REQUIRE(recursiveLinearSum(A, 1) == 1);
}
