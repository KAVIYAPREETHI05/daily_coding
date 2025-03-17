### SECOND LARGEST ELEMENT

```c
#include<stdio.h>
#include<limits.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
int first_largest=INT_MIN;
int second_largest=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>first_largest){
            second_largest=first_largest;
            first_largest=arr[i];
        }
        else if(arr[i]>second_largest && arr[i]!=first_largest){
            second_largest=arr[i];
        }
    }
    printf("%d",second_largest);
   
}
```

### MOVE ALL ZEROS TO END 

```c
#include<stdio.h>
#include<limits.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;

}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
int zero_index=-1;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            if(zero_index!=-1){
                swap(&arr[i],&arr[zero_index]);
                zero_index=i;
            }           
        }
        else if(zero_index==-1){
            zero_index=i;

        }
    }
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
   
}
```

### REVERSE ARRAY IN GROUPS

```c
#include<stdio.h>
#include<limits.h>

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;

}

void reverse(int n,int arr[n],int start,int end ){
    while(start<end){
        swap(&arr[start],&arr[end]);
        start++;
        end--;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int k=2;

    for(int i=0;i<n;i+=k){
       int start=i;
       int end=(i+k-1)<n ?i+k-1 :n-1;
       reverse(n,arr,start,end);
    }
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
   
}
```

### BEST TIME TO BUTY AND SELL STOCK

```c
#include<stdio.h>
#include<limits.h>


int main(){
    int n;
    scanf("%d",&n);
    int prices[n];
    for(int i=0;i<n;i++){
        scanf("%d",&prices[i]);
    }
        int minPrice=prices[0];
        int profit=0;

        for(int i=0;i<n;i++){
            if(prices[i]<minPrice){
                minPrice=prices[i];
            }
            int newProfit=prices[i]-minPrice;
            if(newProfit>profit){
                profit=newProfit;
            }

        }
        printf("%d",profit);
   
}
```


