#include "t_error.h"

const char* error_repr(t_error err)
{
	if (err == OK)
		return "Ok";
	if (err == OOM)
		return "Out of memory";
	if (err == DUPLICATES)
		return "Duplicates in input";
	if (err == NOT_A_NUMBER)
		return "Input is not a number";
	if (err == NULL_OUT_PARAM)
		return "Out param is NULL";
	return "Unrecognised error";
}
