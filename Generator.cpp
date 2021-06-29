#include "pch.h"
#include "Generator.h"

enum symbols
{
    LOWERCASE_ALPHABET,
    UPPERCASE_ALPHABET,
    NUMBERS,
    BRACKETS,
    SPECIALS
};


char* lowercase_alphabet = "qwertyuiopasdfghjklzxcvbnm";
char* uppercase_alphabet = "QWERTYUIOPASDFGHJKLZXCVBNM";
char* numbers = "0123456789";
char* brackets = "[]{}()<>";
char* specials = "'\"\/|.,-=+*^&%$#@!¹~_ ";


char* codes[5] = {
    lowercase_alphabet,
    uppercase_alphabet,
    numbers,
    brackets,
    specials };


char* generate_password(int length,
    bool use_lowercase,
    bool use_uppercase,
    bool use_numbers,
    bool use_brackets,
    bool use_specials)
{
    char* final_password = new char[length];
    int code_array_size = 0;

    code_array_size += (use_lowercase ? 1 : 0);
    code_array_size += (use_uppercase ? 1 : 0);
    code_array_size += (use_numbers ? 1 : 0);
    code_array_size += (use_brackets ? 1 : 0);
    code_array_size += (use_specials ? 1 : 0);


    int* pointers_to_codes = new int[code_array_size];

    int pointer = 0;
    if (use_lowercase)
    {
        pointers_to_codes[pointer++] = LOWERCASE_ALPHABET;
    }
    if (use_uppercase)
    {
        pointers_to_codes[pointer++] = UPPERCASE_ALPHABET;
    }
    if (use_numbers)
    {
        pointers_to_codes[pointer++] = NUMBERS;
    }
    if (use_brackets)
    {
        pointers_to_codes[pointer++] = BRACKETS;
    }
    if (use_specials)
    {
        pointers_to_codes[pointer++] = SPECIALS;
    }

    int i;
    for (i = 0; i < length; i++)
    {
        int random_index_to_code_array = rand() % (code_array_size);
        int random_index_to_character = rand() % (strlen(codes[pointers_to_codes[random_index_to_code_array]]) - 1);

        final_password[i] = codes[pointers_to_codes[random_index_to_code_array]][random_index_to_character];
    }

    final_password[i] = '\0';

    delete[] pointers_to_codes;
    return final_password;
}
