#pragma once

#include <stddef.h>
#include <stdbool.h>

void sort_array(int* array, size_t len);
int index_of(int value, const int* array, size_t len);
bool array_is_sorted(const int* array, size_t len);
bool array_contains_duplicates(const int* array, size_t len);
