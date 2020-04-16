#include "primes.h"
//#include <time.h>

#define BUFFER_LENGTH 1024*128

int main(int argc, char *argv[]){
  //  clock_t begin = clock();

    FILE* input = fopen(argv[1], "r");
    int i = 0;

    int result_index = 0;
    char result[BUFFER_LENGTH+1];
    // Stupid trick to make output faster!
    memset(result, '\n', BUFFER_LENGTH);

    while (!feof(input))
    {
        fscanf (input, "%d", &i);
        result[result_index] = isprime(i);
        result_index += 2;
        if(result_index == BUFFER_LENGTH){
            // print result
            print_result(result, result_index);
            result_index = 0;
        }
    }
    // Print last chunk of result
    if(result_index > 0){
        print_result(result, result_index);
    }

    fclose (input);
   // printf("Total time %f\n", (double)(clock() - begin)/ CLOCKS_PER_SEC);
    return 0;
}

char isprime(int num){
    // Test if number is divisible by 2
    // This must catch half of the numbers (statistically! depends on input distribution)
    if(!(num & 1)){
        return num == 2 ? '1':'0';
    }
    
    int search_up_to = (int)sqrt(num);
    int search_index = 1;
    int c_prime_number = 3;

    while(c_prime_number <= search_up_to && c_prime_number != num){
        if(num % primes[search_index] == 0){
            return '0';
        }
        search_index++;
        c_prime_number = primes[search_index];
    }

    return '1';
}

void print_result(char *buffer, int length){
    buffer[length] = '\0';
    printf("%s", buffer);
}

