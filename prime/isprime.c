#include "primes.h"
//#include <time.h>

#define BUFFER_LENGTH 1024*128

int main(int argc, char *argv[]){
    //clock_t begin = clock();

    FILE* input = fopen(argv[1], "r");

    int result_index = 0;
    char result[BUFFER_LENGTH+1];
    // Stupid trick to make output faster!
    memset(result, '\n', BUFFER_LENGTH);

    // Get file size
    fseek(input, 0, SEEK_END);
    int file_size = ftell(input);
    fseek(input, 0, SEEK_SET);

    char *file_buffer = malloc(file_size);
    char *buffer_token = file_buffer;
    
    fread(file_buffer, 1, file_size, input );
    fclose (input);

    char *number_str = strtok(file_buffer,"\n");
    int line_length = 0;
    while(number_str){
        line_length = strlen(number_str)+ 1;
        file_buffer += line_length;
        result[result_index] = isprime(atoi(number_str));
        result_index += 2;
        if(result_index == BUFFER_LENGTH){
            // print result
            fwrite(result,1, result_index, stdout);
            result_index = 0;
        }
        number_str = strtok(file_buffer,"\n");
    };

    // Print last chunk of result
    if(result_index > 0){
        fwrite(result,1, result_index, stdout);
    }

    free(buffer_token);

    //printf("Total time %f\n", (double)(clock() - begin)/ CLOCKS_PER_SEC);
    return 0;
}

static inline char isprime(int num){
    // Test if number is divisible by 2
    // This must catch half of the numbers (statistically! depends on input distribution)
    if(!(num & 1)){
        return num == 2 ? '1':'0';
    }
    search_up_to = (int)sqrt(num);
    c_prime_number = primes+1;
    while(*c_prime_number <= search_up_to){
        if(num % *c_prime_number == 0){
            return *c_prime_number == num ? '1' : '0';
        }
        c_prime_number++;
    }
    return '1';
}
