### SELECTION SORT
```c
#include<stdio.h>
void print(int n,int arr[n]){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void sorting(int n,int arr[n]){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                swap(&arr[i],&arr[j]);
            }
        }
    }
    print(n,arr);
    
}


int main(){
    int n=8;
    int arr[]={1,4,5,8,2,3,4,0};
    sorting(n,arr);
    return 0;
}
```

### Bubble sort
```c
#include<stdio.h>
void print(int n,int arr[n]){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void sorting(int n,int arr[n]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
    print(n,arr);
    
}


int main(){
    int n=8;
    int arr[]={1,4,5,8,2,3,4,0};
    sorting(n,arr);
    return 0;
}
```

### Insertion sort

```c
#include<stdio.h>
void print(int n,int arr[n]){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

void sorting(int n,int arr[n]){
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
    print(n,arr);
    
}


int main(){
    int n=8;
    int arr[]={1,4,5,8,2,3,4,0};
    sorting(n,arr);
    return 0;
}
```

### quick sort

```c
#include<stdio.h>
void print(int n,int arr[n]){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int n,int arr[n],int low,int high){
    int pivot=arr[high];
    int pi=low-1;
    
    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            pi++;
            swap(&arr[j],&arr[pi]);
        }
    }
    swap(&arr[high],&arr[pi+1]);
    return pi+1;
}
void quicksort(int n,int arr[n],int low,int high){
   if(low<high){
       int pi=partition(n,arr,low,high);
       quicksort(n,arr,low,pi-1);
       quicksort(n,arr,pi+1,high);
       
   }
  
}


int main(){
    int n=8;
    int arr[]={1,4,5,8,2,3,4,0};
   int low=0;int high=n-1;
    quicksort(n,arr,low,high);
     print(n,arr);
    return 0;
}
```

### merge sort
```c
#include <stdio.h>

// Function to print the array
void print(int n, int arr[n]) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n"); // Added for better formatting
}

// Function to merge two halves of the array
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; // Size of left subarray
    int n2 = right - mid;    // Size of right subarray

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = left; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Function that implements merge sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Find the middle point
        int mid = left + (right - left) / 2;

        // Recursively sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

int main() {
    int n = 8;
    int arr[] = {1, 4, 5, 8, 2, 3, 4, 0};

    printf("Original array: ");
    print(n, arr); // Print the original array

    mergeSort(arr, 0, n - 1); // Perform merge sort

    printf("Sorted array: ");
    print(n, arr); // Print the sorted array

    return 0;
}

```
