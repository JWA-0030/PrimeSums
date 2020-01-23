#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//setting the limit of our primes to any high number
#define LIMIT 105000

int main()
{
//variable declaration
    int i, j, x = 0, y = 0, primeSums = 0, input = 0, allNums = 0;
// here I am Dynamically Allocating an array for all of the primes up to the Limit
    int *primes = malloc(LIMIT*sizeof(int));
//I am filling the aray so all numbers up to limit are 1 or prime
    for(i = 0; i < LIMIT; i++)
    {
         primes[i] = 1;
    }
//i set the 0 and 1 place as not prime
    primes[0] = 0;
    primes[1] = 0;
// here i start at 2 and lop through all multiples of all numbers under the  square root of my limit and multiply by all numbers of i
// all multiples are immediately set to 0

    for(i = 2; i < sqrt(LIMIT); i++)
    {
        for (j=i;i*j<LIMIT;j++)
                  primes[i*j]=0;
    }
//scanf from the input file to find number of inputs to be read
    scanf("%d", &allNums);
//scanf for each input value
    scanf("%d", &input);

    for(i = 0; i < LIMIT; i++)
    {
// brings only prime numbers out and run if the input is not 0
        if(primes[i] == 1 && input > 0)
        {
            if(x == allNums)
//if the max number of inputs is found it returns
                break;
            else if(y < input)
            {
//as long as under input the sum of the primes is iterated and y iterates until input is reached
                primeSums += i;
                y++;
            }
//when y = input it prints, then retruns all but x iterated numbers to zero, scans again and x is iterated until all nums is reached
            else if(y == input)
            {
                printf("%d\n", primeSums);
                primeSums = 0;
                y = 0;
                i = 0;
                x++;
                scanf("%d", &input);
            }
        }
    }

    free(primes);
    return 0;
}

