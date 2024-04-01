#include "pch.h"
#include "Func.h"

TEST(Read, NullTest) {
    int* b = Read(0);
    EXPECT_EQ((int)b, NULL);
    EXPECT_TRUE(true);
}

TEST(NullTest, Matrix_tests) {
    int b[2] = { 1,2 };
    int c[2] = { 2,1 };
    int** mas = Matrix((const int*)&b[0], (const int*)&c[0], 3, 0);
    EXPECT_EQ((int)mas, 0);
    EXPECT_TRUE(true);
}
TEST(Testcase_1, Algo_case_Matrix) {
    int b[2] = { 1,2 };
    int c[2] = { 2,1 };
    int** mas = Matrix(&b[0], &c[0], 2, 2);
    EXPECT_EQ(mas[2][2], 2);
    EXPECT_TRUE(true);
}
TEST(Big_weight, Algo_case_Matrix_tests) {
    int b[2] = { 1,2 };
    int c[2] = { 2,1 };
    int** mas = Matrix(&b[0], &c[0], 3, 2);
    EXPECT_EQ(mas[2][3], 3);
    EXPECT_TRUE(true);
}
TEST(Small_weight, Algo_case_Matrix_tests) {
    int b[2] = { 3 , 4 };
    int c[2] = { 2,1 };
    int** M = Matrix(&b[0], &c[0], 2, 2);
    EXPECT_EQ(M[2][2], 0);
    EXPECT_TRUE(true);
}
TEST(Easy_Test, Finder_tests) {
    int b[5] = { 3,4 };
    int c[5] = { 1,6 };
    int** M = Matrix(&b[0], &c[0], 3, 2);
    int F[2] = {};
    Finder(2, 3, (const int**)M, &b[0], &F[0]);
    EXPECT_EQ(F[1], 0);
    EXPECT_EQ(F[0], 1);
    EXPECT_TRUE(true);
}
TEST(Big_Wight_Test, Algo_Finder_tests) {
    int b[5] = { 1,2 };
    int c[5] = { 1,6 };
    int** M = Matrix(&b[0], &c[0], 3, 2);
    int F[2] = {};
    Finder(2, 3, (const int**)M, &b[0], &F[0]);
    EXPECT_EQ(F[0], 1);
    EXPECT_EQ(F[1], 2);
    EXPECT_TRUE(true);
}
TEST(Small_Wight_Test, Algo_Finder_tests) {
    int b[5] = { 3,4 };
    int c[5] = { 1,6 };
    int** M = Matrix(&b[0], &c[0], 2, 2);
    int F[2] = { 0 };
    Finder(2, 2, (const int**)M, &b[0], &F[0]);
    EXPECT_EQ(F[0], 0);
    EXPECT_EQ(F[1], 0);
    EXPECT_TRUE(true);
}
TEST(Small_amount_Test, Algo_Finder_tests) {
    int b[1] = { 3 };
    int c[1] = { 1 };
    int** M = Matrix(&b[0], &c[0], 4, 1);
    int F[2] = { 0 };
    Finder(1, 4, (const int**)M, &b[0], &F[0]);
    EXPECT_EQ(F[0], 1);
    EXPECT_TRUE(true);
}
