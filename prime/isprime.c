#include <stdio.h>
#include <math.h>
#include <string.h>
//#include <time.h>

#define BUFFER_LENGTH 2048*32

char isprime(int num){
    if(num < 11){
        return (num == 2 || num == 3 || num == 5 || num == 7) ? '1' : '0';
    }

    // Test if number is divisible by 2,3,5,7
    // This must catch half of the numbers (statistically! depends on input distribution)
    if(!(num & 1) || num % 3 == 0 || num % 5 == 0 || num % 7 == 0){
        return '0';
    }
    
    int search_up_to = (int)sqrt(num)+1;
    for(int i = 11; i < search_up_to; i+=2){
        if(num % i == 0){
            return '0';
        }
    }

    return '1';
}

void print_result(char *buffer, int length){
    buffer[length] = '\0';
    printf("%s", buffer);
}


int main(int argc, char *argv[]){
    //clock_t begin = clock();

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
    //printf("Total time %f\n", (double)(clock() - begin)/ CLOCKS_PER_SEC);
    return 0;
}

