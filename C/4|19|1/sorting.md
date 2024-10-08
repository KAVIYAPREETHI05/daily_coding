### professor and parties
```c
char* PartyType(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                return "true";  // Duplicate found
            }
        }
    }
    return "false"; // No duplicates
}
```
### anagram
```c
bool isAnagram(char* str1, char* str2) {
    int temp[26] = {0};
   int l1 = strlen(str1);
    int l2 = strlen(str2);
    if (l1 != l2) {
        return false;
    }
    for (int i = 0; i < l1; i++) {
        temp[str1[i] - 'a']++; 
    }
    for (int i = 0; i < l2; i++) {
        temp[str2[i] - 'a']--; 
    }
    for (int i = 0; i < 26; i++) {
        if (temp[i] != 0) {
            return false;
        }
    }

    return true; 
}
```
### max perimeter
```c
 int maxPerimeter(int n,int arr[]) {
int compare(const void *a,const void *b){
return (*(int*)a - *(int *)b);


}

        if(n<3){
            return -1;
        }
      qsort(arr,n,sizeof(int),compare);
       for(int i=n-1;i>=2;i--){
           int side1=arr[i];
           int side2=arr[i-1];
           int side3=arr[i-2];
           if(side1<side2+side3){
               return side1+side2+side3;
           }
           
       }
        return -1;
        
    }

```
### Maximize sum after K negations
```c
int compare(const void *a, const void *b) {
    long val1 = *(long *)a;
    long val2 = *(long *)b;
    return (val1 > val2) - (val1 < val2);  // Returns 1, 0, or -1 based on comparison
}
(or)
int compare(const void *a,const void *b){
    return (*(long *)a-*(long*)b);
}
long maximizeSum(long a[], int n, int k)
    {
        qsort(a,n,sizeof(long),compare);
        for(int i=0;i<n&& k>0;i++)  {
            if(a[i]<0 ){
                a[i]=-a[i];
                k--;
                
            }
        }
        qsort(a,n,sizeof(long),compare);
        if(k>0){
           
            if(k%2 !=0){
                a[0]=-a[0];
            }
        }
        long sum=0;
        for(int i=0;i<n;i++){
            sum+=a[i];
        }
        return sum;
    }

```
### Friendly Array
Friendliness is the sum of the absolute differences between each element and its closest friend in the array.(circular array)
```c
 int calculateFriendliness(int n,int arr[]) {
        int sum=0;
        if(n==1){
            return 0;
        }
        for(int i=0;i<n-1;i++){
            sum+=abs(arr[i]-arr[i+1]);
        }
            sum+=abs(arr[n-1]-arr[0]);
        
        return sum;
    }

```
### wave array
```c
//arr[1] >= arr[2] <= arr[3] >= arr[4] <= arr[5].....

 void swap(int *a,int *b){
        int temp=*a;
        *a=*b;
        *b=temp;
    }
void convertToWave(int n, int arr[]) {
        for(int i=0;i<n-1;i=i+2){
            if(arr[i]<arr[i+1]){
                swap(&arr[i],&arr[i+1]);
            }
            
        }
    }

```
### Chocolate Distribution Problem

```c
int compare(const void *a,const void *b){
    return (*(int *)a-*(int *)b);
}
 long findMinDiff (int a[], int n, int m)
    {
        if(m==0 || n==0 ||m>n){
            return -1;
        }
        qsort(a,n,sizeof(int),compare);
        int mindiff=INT_MAX;
        for(int i=0;i<=n-m;i++){
           int diff=a[i+m-1]-a[i];
           if(diff<mindiff){
               mindiff=diff;
           }
        }
         
        return mindiff;
    }
```
### max value permutation
```c
#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

// Comparator function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

long Maximize(int arr[], int n) {
    qsort(arr, n, sizeof(int), compare); // Sort the array
    long sum = 0; // Declare sum as long to handle large sums

    for (int i = 0; i < n; i++) {
        sum = (sum + (long)arr[i] * i) % MOD; // Calculate the sum with modulo
    }

    return sum; // Return the result as a long
}

int main() {
    int arr[] = {5, 3, 2, 4, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    long result = Maximize(arr, n);
    printf("Maximized sum: %ld\n", result); // Expected output: 40
    return 0;
}

```
### floor in sorted array
```c
int findFloor(long arr[], int n, long x) {
        int left=0;int right=n-1;int floorIndex=-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(x==arr[mid]){
                return mid;
            }
            else if(arr[mid]>x){
                right=mid-1;
            }
            else if(arr[mid]<x){
                floorIndex=mid;
                left=mid+1;
            }
        }
        return floorIndex;
        
        
    }
```
### find pair given difference
```c
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
int findPair(int n, int x, int[] arr) {
    qsort(arr, n, sizeof(int), compare);
       int left=0;int right=1;
       while(right<n){
           int diff=arr[right]-arr[left];
           if(diff==x){
               return 1;
           }
           else if(diff<x){
               right++;
           }
           else{
               left++;
           }
           if(right==left){
               right++;
           }
           
       }
       return -1;
    }
```
### Triplet Sum in Array
```c
int compare(const void *a,const void *b){
    return (*(int *)a - *(int*)b);
}

int find3Numbers(int arr[], int n, int x) {
     qsort(arr,n,sizeof(int),compare);
        for(int i=0;i<n-2;i++){
            int left=i+1;
            int right=n-1;
            while(left<right){
                if(arr[i]+arr[left]+arr[right]==x){
                    return 1;
                }
                if(arr[i]+arr[left]+arr[right]>x){
                    right--;
                }
                else{
                    left++;
                }
            }
            
        }
        return 0;
}
```












