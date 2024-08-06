#pragma once

#include <stdbool.h>
#include "t_error.h"

void die(const char* msg);
void assert(bool assertion, const char* msg);
