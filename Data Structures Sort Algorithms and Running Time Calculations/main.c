#include <stdio.h>
#include <stdlib.h>
#include <time.h>
clock_t clock(void);
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void swap_2(int *a, int *b);
void swap_3(int* a, int* b);
void merge(int arr[], int l, int m, int r);
int partition(int array[], int low, int high);
void heapify(int arr[], int N, int i);
void Insertion_sort(int arr[],int n);
void Selection_sort(int arr[],int n);
void Bubble_sort(int arr[],int n);
void Mergesort(int arr[],int l, int r);
void Quicksort(int arr[],int low, int high);
void Heap_sort(int arr[],int n);


int main()
{
    clock_t start_t, end_t;
    int id;
    int i,arr_size,chose;
    int* arr;
    time_t t1;
    printf("Welcome, this algorithm will show you some sorting algorithms and displays their running time.\n");
    printf("Please enter a array size:\n ");
    scanf("%d",&arr_size);
    arr = (int*)malloc(sizeof(int)*arr_size);
    printf("The size you chosen is: %d\n",arr_size);
    printf("Array is: ");
    srand ( (unsigned) time (&t1));
    for (i = 0; i <arr_size; i++)
    {
        arr[i]=(rand()% 10000000)+1;
        //printf("%d ",arr[i]);
    }
    printf("\nChoose the sorting algorithm from the list below to compute the running time in seconds:\n");
    printf("1-Insertion sort\n2-Selection sort\n3-Bubble sort\n4-Mergesort\n5-Quicksort\n6-Heap sort\n");
    scanf("%d",&chose);
    do
    {
        if(chose==1)
        {
            start_t = clock();
            Insertion_sort(arr,arr_size);
        }
        if(chose==2)
        {
            start_t = clock();
            Selection_sort(arr,arr_size);
        }
        if(chose==3)
        {
            start_t = clock();
            Bubble_sort(arr,arr_size);
        }
        if(chose==4)
        {
            start_t = clock();
            Mergesort(arr,0,arr_size-1);
        }
        if(chose==5)
        {
            start_t = clock();
            Quicksort(arr,0,arr_size-1);
        }
        if(chose==6)
        {
            start_t = clock();
            Heap_sort(arr,arr_size);
        }
    }
    while(chose<0&&chose>6);

    end_t = clock();

    printf("\nstart_t degeri: %ld\n", start_t);
    printf("end_t degeri: %ld\n", end_t);
    printf("CPU sreci (saniye): %f\n", (double)(end_t - start_t) / CLOCKS_PER_SEC);
    return 0;
}
////////////////////////////////////////////////////////////////////
void Insertion_sort(int arr[],int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
////////////////////////////////////////////////////////////////////
void Selection_sort(int arr[],int n)
{
    int i, j, min_idx;
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        if(min_idx != i)
            swap(&arr[min_idx], &arr[i]);
    }
}
////////////////////////////////////////////////////////////////////
void Bubble_sort(int arr[],int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}
///////////////////////////////////////////////////////////////////
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];


    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];


    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }


    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void Mergesort(int arr[],int l,int r)
{
    if (l < r)
    {

        int m = l + (r - l) / 2;

        Mergesort(arr, l, m);
        Mergesort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}
/////////////////////////////////////////////////////////////
void swap_2(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}


int partition(int array[], int low, int high)
{


    int pivot = array[high];


    int i = (low - 1);

    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {

            i++;

            swap_2(&array[i], &array[j]);
        }
    }

    swap_2(&array[i + 1], &array[high]);

    return (i + 1);
}
void Quicksort(int array[], int low, int high)
{
    if (low < high)
    {


        int pi = partition(array, low, high);


        Quicksort(array, low, pi - 1);


        Quicksort(array, pi + 1, high);
    }
}
/////////////////////////////////////////////////////////////////////////
void swap_3(int* a, int* b)
{

    int temp = *a;

    *a = *b;

    *b = temp;
}
void heapify(int arr[], int N, int i)
{

    int largest = i;

    int left = 2 * i + 1;

    int right = 2 * i + 2;

    if (left < N && arr[left] > arr[largest])

        largest = left;

    if (right < N && arr[right] > arr[largest])

        largest = right;


    if (largest != i) {

        swap(&arr[i], &arr[largest]);

        heapify(arr, N, largest);
    }
}
void Heap_sort(int arr[],int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)

        heapify(arr, n, i);


    for (int i = n - 1; i >= 0; i--) {

        swap_3(&arr[0], &arr[i]);

        heapify(arr, i, 0);
    }
}



