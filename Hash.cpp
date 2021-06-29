#include "pch.h"
#include "Hash.h"

char *hash_string(char* string1)
{

	int string_len = strlen(string1) + 1;
	int ascii_sum = 0;
	int cypher;
	int i;

	char* string2 = new char[string_len];

	for (i = 0; string1[i] != '\0'; ascii_sum += string1[i], i++);

	cypher = ascii_sum % string_len;

	for (i = 0; string1[i] != '\0'; i++)
	{
		string2[i] = (string1[i] + cypher);
	}

	string2[i] = '\0';
	return string2;
}