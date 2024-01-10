// Include the libsodium header file
#include <sodium.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Check if the user provided a valid argument
    if (argc != 2)
    {
        printf("Usage: %s upper_bound\n", argv[0]);
        return 1;
    }

    // Convert the argument to an unsigned integer
    unsigned int upper_bound = (unsigned int)strtoul(argv[1], NULL, 10);

    // Initialize libsodium
    if (sodium_init() == -1)
    {
        printf("Error: libsodium initialization failed\n");
        return 1;
    }

    // Generate a random number between 1 and upper_bound using libsodium
    unsigned int random_number = randombytes_uniform(upper_bound) + 1;

    // Print the random number
    printf("The random number is %u\n", random_number);

    return 0;
}
