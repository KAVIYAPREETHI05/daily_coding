### second largest
```c
#include <stdio.h>
int secondLargest(int n,int arr[]){
    int largest=-1;
    int second_largest=-1;
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            second_largest=largest;
            largest=arr[i];
        }
        else if(arr[i]>second_largest && arr[i]!=largest){
            second_largest=arr[i];
        }
    }
    return second_largest;
}

int main() {
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int num=secondLargest(n,arr);
    printf("%d",num);

    return 0;
}
```
