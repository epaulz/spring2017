/*
 * Eric Paulz
 * CPSC 1021-004
 * Lab #12
 * TA: Nick Glyder
 */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>

void print_vector(std::vector<int> vec);
void quickSort(std::vector<int>& vec, int start, int end);
int partition(std::vector<int>& vec, int start, int end);
int binarySearch(std::vector<int> vec, int first, int last, int value);

#endif
