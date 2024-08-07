#pragma once

typedef enum e_error {
	NO_ERROR,
	ERROR_OOM,
	ERROR_DUPLICATES,
	ERROR_NOT_A_NUMBER,
	ERROR_NULL_OUT_PARAM,
	ERROR_ELEMENT_NOT_FOUND,
} t_error;

const char* error_repr(t_error err);
