#pragma once

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

void sort_array(int32_t* array, size_t len);
int index_of(int32_t value, const int32_t* array, size_t len);
bool array_is_sorted(const int32_t* array, size_t len);
bool sorted_array_contains_duplicates(const int32_t* sorted_array, size_t len);
