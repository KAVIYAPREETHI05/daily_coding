### print all subsequence of an array
``time complexity-O(n*2^n)``
``space complexity-O(n)``
```c
#include<stdio.h>
#include<math.h>

void subseq(int arr[],int n){
    //int no_of_subseq=pow(2,n);(instead of this use 1<<n to optimize the code)
    int no_of_subseq=1<<n;
    for(int i=0;i<no_of_subseq;i++){
        for(int j=0;j<n;j++){
        if(i&(1<<j)){
            printf("%d ",arr[j]);
        }
    }
    printf("\n");
    }
        }
int main(){
    int n=4;
    int arr[]={1,2,3,4};
    subseq(arr,n);
}
```
### Longest subsequence having equal numbers of 0 and 1
``time complexity-O(n)``
``space complexity-O(1)``
```c
#include <stdio.h>
int main()
{
    int arr[]={0,0,1,1,1,1,1,0,0};
    int n=sizeof(arr)/sizeof(arr[0]);
    int count_0=0;
    int count_1=0;
    for(int i=0;i<n;i++){
        if(arr[i]){
            count_1+=1;
        }
        else{
            count_0+=1;
        }
    }
    int sum= count_1<count_0 ? count_1 : count_0;
    printf("%d",sum*2);
    return 0;
}
```
### Powers of two and subsequences
``time complexity-O(n)``
``space complexity-O(1)``
```c
#include <stdio.h>
#include<math.h>
int ispow(int m){
    if(m==0){
        return 0;
    }
    else if(m==1){
        return 1;
    }
    else if(m&(m-1)){
        return 0;
    }
    return 1;
}
int main()
{
    int arr[]={1,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int count=0;
    for(int i=0;i<n;i++){
        if(ispow(arr[i])){
            count+=1;
        }
        
        }
    int total= pow(2,count)-1;
    printf("%d",total);
    return 0;
}
```
### Longest subsequence of even numbers in an Array
``time complexity-O(n)``
``space complexity-O(1)``
```c
#include <stdio.h>
int main()
{
    int arr[]={3,4,11,2,9,21};
    int n=sizeof(arr)/sizeof(arr[0]);
    int count=0;
    for(int i=0;i<n;i++){
        if((arr[i])%2==0){
            count+=1;
        }
        
        }
    printf("%d",count);
    return 0;
}
```
