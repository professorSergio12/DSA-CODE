#include <stdio.h>


void traversal(int arr[], int size)
{
    for (int i = 0; i < size; i++)

        printf("%d ", arr[i]);
        printf("\n");
}

void swap(int * a,int * b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void heapify(int arr[],int n,int i)
{
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left < n  && arr[left]>arr[largest])
    {
        largest=left;
    }
    if(right < n  && arr[right]>arr[largest])
    {
        largest=right;
    }

    // Swap and continue heapifying if root is not largest
    if(largest!=i)
    {
        swap(&arr[i],&arr[largest]);
    }
}

void heapSort(int arr[],int n)
{
    // Build max heap
    for (int i = n/2-1; i >=0; i--) {
        heapify(arr,n,i);
    }
    
     // Heap sort
    for (int i = n-1; i >=0; i--) {
        swap(&arr[0],&arr[i]);
        
        // Heapify root element to get highest element at root again
        heapify(arr,i,0);
    }
}

int main()
{
   int arr[] = {1, 12, 9, 5, 6, 10};
   int n = 6;
  
   heapSort(arr, n);
   printf("Sorted array is:: \n");
   traversal(arr, n);
    return 0;
}
