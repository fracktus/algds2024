#pragma once
#pragma warning(disable: 4996)
#include <stdlib.h> 
#include <stdio.h>

int* Read(int a); 
void Finder(int n, int A, const int** M, const int* b, int* F);
int** Matrix( const int* b, const int* c, const int A, const int n);
