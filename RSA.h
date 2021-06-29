#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

namespace Encryptor
{  

    const unsigned long int key_range1 = 500;
    const unsigned long int key_range2 = 1000;

    struct key
    {
        long long exponent;
        long long modulus;
    };

    class RSA
    {
    public:
        void generate_keys(void)
        {

            
            long long p = generate_prime_number(key_range1, key_range2);
            long long q = generate_prime_number(key_range1 + 100, key_range2 - 100);

            long long N = p * q;

            long long T = (p - 1) * (q - 1);


            long long e; // encryption key
            do
            {
                e = rand() % T + 2;
                if (gcd(e, T) == 1 && (e < T))
                {
                    break;
                }
            } while (1);

            long long d = 2; // decryption key  
            while (1)
            {
                if ((d * e) % T == 1)
                {
                    break;
                }
                d++;
            }

            public_key.exponent = e;
            public_key.modulus = N;

            private_key.exponent = d;
            private_key.modulus = N;
        }

        long long encrypt(char character)
        {
            return rsa_modexp(character, public_key.exponent, public_key.modulus);
        }

        char decrypt(long long cypher)
        {
            return rsa_modexp(cypher, private_key.exponent, private_key.modulus);
        }

        void set_public_key(long long exponent, long long modulus)
        {
            public_key.exponent = exponent;
            public_key.modulus = modulus;
        }

        key get_public_key()
        {
            return public_key;
        }

        void set_private_key(long long exponent, long long modulus)
        {
            private_key.exponent = exponent;
            private_key.modulus = modulus;
        }

        key get_private_key()
        {
            return private_key;
        }

        void serialize(ofstream* file_name, char* target_string, bool last_record)
        {
            if (file_name->is_open())
            {
                for (int i = 0; i < strlen(target_string); i++)
                {
                    *file_name << this->encrypt(target_string[i]) << ' ';
                }
            }

            if (!last_record)
            {
                *file_name << '\n';
            }
        }

        void deserialize(ifstream *file_name, char* target_string)
        {
            if (file_name->is_open())
            {
                string temp;
                getline(*file_name, temp);

                char number[250];
                int string_pointer = 0;
                for (int i = 0, v = 0; temp[i] != '\0'; i++, v++)
                {
                    if (temp[i] == ' ')
                    {
                        number[v] = '\0';
                        long long encrypted_number = stoll(*(new string(number)));
                        target_string[string_pointer++] = this->decrypt(encrypted_number);
                        v = -1;
                    }
                    else
                    {
                        number[v] = temp[i];
                    }
                }
                target_string[string_pointer] = '\0';
            }
        }


    private:
        key public_key;
        key private_key;

        long long generate_prime_number(long long range1, long long range2)
        {
            bool prime = 0;
            long long prime_number;

            while (!prime)
            {
                prime_number = rand() % range2 + range1;

                prime = is_prime(prime_number);

            }

            return prime_number;
        }

        long long gcd(long long a, long long b)
        {
            while (a > 0)
            {
                long long temp;

                temp = a;
                a = b % a;
                b = temp;
            }

            return b;
        }

        bool is_prime(long long number)
        {
            bool prime = 0;

            for (long long i = 2; i <= number / 2; i++)
            {
                prime = 1;
                if (number % i == 0)
                {
                    prime = 0;
                    return prime;
                }
            }

            return prime;
        }

        long long modmult(long long a,
            long long b,
            long long mod)
        {
            // this is necessary since we will be dividing by a
            if (a == 0)
            {
                return 0;
            }
            register long long product = a * b;
            //if multiplication does not overflow, we can use it
            if (product / a == b)
            {
                return product % mod;
            }
            // if a % 2 == 1 i. e. a >> 1 is not a / 2
            if (a & 1)
            {
                product = modmult((a >> 1), b, mod);
                if ((product << 1) > product)
                {
                    return (((product << 1) % mod) + b) % mod;
                }
            }
            //implicit else
            product = modmult((a >> 1), b, mod);
            if ((product << 1) > product)
            {
                return (product << 1) % mod;
            }
            //implicit else: this is about 10x slower than the code above, but it will not overflow
            long long sum;
            sum = 0;
            while (b > 0)
            {
                if (b & 1)
                {
                    sum = (sum + a) % mod;
                }
                a = (2 * a) % mod;
                b >>= 1;
            }
            return sum;
        }

        long long rsa_modexp(long long b,
            long long e,
            long long m)
        {
            long long product;
            product = 1;
            if (b < 0 || e < 0 || m <= 0)
            {
                return -1;
            }
            b = b % m;
            while (e > 0)
            {
                if (e & 1)
                {
                    product = modmult(product, b, m);
                }
                b = modmult(b, b, m);
                e >>= 1;
            }
            return product;
        }

    };
};

