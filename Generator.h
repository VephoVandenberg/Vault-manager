#pragma once

#include <iostream>
#include <string.h>

char* generate_password(int length,
    bool use_lowercase,
    bool use_uppercase,
    bool use_numbers,
    bool use_brackets,
    bool use_specials);