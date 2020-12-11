#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && arr[l] > arr[largest])
        {
            largest = l;
        }
    if (r < n && arr[r] > arr[largest])
        {
            largest = r;
        }
    if (largest != i)
    {
        int s;
        s=arr[i];
        arr[i]=arr[largest];
        arr[largest]=s;
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i=n-1; i>=0; i--)
    {
        int l;
        l=arr[0];
        arr[0]=arr[i];
        arr[i]=l;
        heapify(arr, i, 0);
    }
}

 int main()
{
    srand(time(0));
    FILE *inputfile = fopen("input.txt", "r");
    int size;
    fscanf(inputfile, "%d", &size);
    int array[size];
    for (int i = 0; i < size; i++)
    {
        fscanf(inputfile, "%d", &array[i]);
    }
    fclose(inputfile);
    int n = sizeof(array)/sizeof(array[0]);
    time_t time1=time(0);
    heapSort(array, n);
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
