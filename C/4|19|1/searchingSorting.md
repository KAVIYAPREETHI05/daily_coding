### binary search
```c
int search(int* nums, int n, int target) {
    int left=0;int right=n-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(nums[mid]==target){
            return mid;
        }
        else if(target<nums[mid]){
            right=mid-1;
        }
        else if(target>nums[mid]){
            left=mid+1;
        }
    }
    return -1;
    
    
}
```

### quick sort
```c
void quickSort(int arr[], int low, int high)
{
    if(low<high){
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}
    
int partition (int arr[], int low, int high)
{
   int pivot=arr[high];
   int pi=low-1;
   for(int i=low;i<high;i++){
       if(arr[i]<pivot){
           pi++;
           swap(&arr[i],&arr[pi]);
       }
   }
   swap(&arr[high],&arr[pi+1]);
   return pi+1;
}
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
```

### merge sort
```c
#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Create temporary arrays
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));
    
    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[mid + 1 + i];
    }
    
    // Merge the temporary arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    
    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k++] = L[i++];
    }
    
    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k++] = R[j++];
    }
    
    // Free the allocated memory
    free(L);
    free(R);
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        
        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Given array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    mergeSort(arr, 0, n - 1);
    
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}

```
