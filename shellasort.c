#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void shellasort(int* a, int n)
{
    for (int k = n / 2; k > 0; k /= 2) {
     for (int i = k; i < n; i++) {
       int j = i - k;
       while (j>=0 && a[j] > a[j + k]) {
         a[j] = a[j] ^ a[j + k];
         a[j + k] = a[j] ^ a[j + k];
         a[j] = a[j+k] ^ a[j];
         j -= k;
       }
     }
    }
}

int main()
{
    srand(time(0));
    FILE *inputfile = fopen("input.txt", "r");
    int n;
    fscanf(inputfile, "%d", &n);
    int size = n;
    int array[size];
    for (int i = 0; i < size; i++)
    {
        fscanf(inputfile, "%d", &array[i]);
    }
    fclose(inputfile);

    time_t time1=time(0);
    shellasort(array, size);
    time_t time2=time(0);
    FILE *outputfile = fopen("output.txt", "w");
    for (int i = 0; i < size; i++)
    {
        fprintf(outputfile, "%d ", array[i]);
    }
    fclose(outputfile);

    FILE *timefile = fopen("time.txt", "w");
    fprintf(timefile, "%ld", time2 - time1);
    fclose(timefile);
    return 0;
}
