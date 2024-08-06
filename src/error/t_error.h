#pragma once

typedef enum e_error {
	OK,
	OOM,
	DUPLICATES,
	NOT_A_NUMBER,
	NULL_OUT_PARAM,
} t_error;

const char* error_repr(t_error err);
