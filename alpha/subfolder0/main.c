#include <stdio.h>
#include <math.h>
#include <stdbool.h>


void fillTrue(bool *array, const int N);
void input(int* N);
void print(bool *candidates, const int N);
void sieveEratosthenes(bool *candidates, const int N);

int main(void)
{
    int N;
    input(&N);
    bool candidates[N];
    fillTrue(candidates, N);
    sieveEratosthenes(candidates, N);
    print(candidates, N);
    return 0;
}

void sieveEratosthenes(bool *candidates, const int N)
{
    int i, j, r;
    for(i = 2,  r = sqrt(N) ; i <= r ; i++)
        if(candidates[i])
            for(j = i*i ; j <= N ; j += i)
                candidates[j] = false;
}

void input(int* N)
{
    do{
        printf("Please, input a positive number\n");
        scanf("%d" , N);
    }while(*N < 0);
    (*N)++;
}

void fillTrue(bool *array, const int N)
{
    int i;
    array[0] = array[1] = false;
    for(i = 2 ; i < N ; i++)
        array[i] = true;
}

void print(bool *candidates, const int N)
{
    int i;
    for(i = 0 ; i < N ; i++)
        printf("%d is %sprime\n", i, candidates[i] ? "" : "NOT ");
}