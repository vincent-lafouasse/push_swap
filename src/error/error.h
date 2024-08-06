#pragma once

#include <stdbool.h>

typedef enum e_error {
	NO_ERROR,
	OOM,
	DUPLICATES,
	NOT_A_NUMBER,
} t_error;

void die(const char* msg);
void assert(bool assertion, const char* msg);
