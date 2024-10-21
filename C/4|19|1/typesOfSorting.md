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
void merge(int n,int arr[n],int left,int mid,int right){
    int n1=mid - left + 1;;int n2=right-mid;
    int l[n1];int r[n2];
    for(int i=0;i<  n1;i++){
        l[i]=arr[left+i];
        
    }
    for(int i=0;i<n2;i++){
        r[i]=arr[mid+i+1];
    }
    int i=0;int j=0;
    int k=left;
    while(i<n1 && j<n2){
        if(l[i]<r[j]){
            arr[k++]=l[i];
            i++;
        }
        else{
            arr[k++]=r[j];
            j++;
        }
    }
    while(i<n1){
        arr[k++]=l[i];
        i++;
    }
    while(j<n2){
        arr[k++]=r[j];
        j++;
    }
    
}
void mergesort(int n,int arr[n],int left,int right){
   if(left<right){
       int mid=left+(right-left)/2;
       mergesort(n,arr,left,mid);
       mergesort(n,arr,mid+1,right);
      merge(n,arr,left,mid,right);
       
   }
  
}


int main(){
    int n=8;
    int arr[]={1,4,5,8,2,3,4,0};
   int low=0;int high=n-1;
    mergesort(n,arr,low,high);
     print(n,arr);
    return 0;
}
```
