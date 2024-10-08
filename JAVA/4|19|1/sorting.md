### professor and parties
```java

class Solution {

    public static String PartyType(int arr[]) {
        int n=arr.length;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i]==arr[j]){
                    return "true";
                }
            }
        }
        return "false";
    }
}
```
### anagram
```java

class Solution {
    public static boolean isAnagram(String str1, String str2) {
        int []temp=new int[26];
        for(int i=0;i<str1.length();i++){
            temp[str1.charAt(i)-'a']++;
        }
        for(int i=0;i<str2.length();i++){
            temp[str2.charAt(i)-'a']--;
        }
        for(int i=0;i<26;i++){
            if(temp[i]!=0){
                return false;
            }
        }
        return true;

    }
}
```
### maxPerimeter
```java
class Solution {
    public int maxPerimeter(int[] arr) {
        int n=arr.length;
        Arrays.sort(arr);
        int side1=arr[n-1];int side2=arr[n-2];int side3=arr[n-3];
        if(side1+side2>side3 && side2+side3>side1 && side1+side3>side2){
            return side1+side2+side3;
        }
        return -1;
        
    }
}
```
or
```java
class Solution {
    public int maxPerimeter(int[] arr) {
        int n=arr.length;
        if(n<3){
            return -1;
        }
        Arrays.sort(arr);
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
}
```
### Maximize sum after K negations

```java
class Solution {

    public static long maximizeSum(long a[], int n, int k)
    {
        Arrays.sort(a);
        for(int i=0;i<n&& k>0;i++)  {
            if(a[i]<0 ){
                a[i]=-a[i];
                k--;
                
            }
        }
         Arrays.sort(a);
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
}
```
### Friendly Array
Friendliness is the sum of the absolute differences between each element and its closest friend in the array.(circular array)
```java
class Solution {
    public int calculateFriendliness(int[] arr) {
        int sum=0;
        int n=arr.length;
        if(n==1){
            return 0;
        }
        for(int i=0;i<n-1;i++){
            sum+=Math.abs(arr[i]-arr[i+1]);
        }
        if(n>2){
            sum+=Math.abs(arr[n-1]-arr[0]);
        }
        return sum;
    }
}
```
### wave array
```java
//arr[1] >= arr[2] <= arr[3] >= arr[4] <= arr[5].....
class Solution {
   static void swap(int[]arr,int a,int b){
        int temp=arr[a];
        arr[a]=arr[b];
        arr[b]=temp;
    }
    public static void convertToWave(int n, int[] arr) {
        for(int i=0;i<n-1;i=i+2){
            if(arr[i]<arr[i+1]){
                swap(arr,i,i+1);
            }
            
        }
    }
}

```
### Chocolate Distribution Problem

```java
class Solution
{
    public long findMinDiff (ArrayList<Integer> a, int n, int m)
    {
        if(m==0 || n==0 ||m>n){
            return -1;
        }
        Collections.sort(a);
        int mindiff=Integer.MAX_VALUE;
        for(int i=0;i<=n-m;i++){
           int diff=a.get(i+m-1)-a.get(i);
           mindiff=Math.min(diff,mindiff);
        }
         
        return mindiff;
    }
}
```
### max value permutation
```java
class Solution {
  static final int MOD = 1000000007; 
    int Maximize(int arr[]) {
        int n=arr.length;
        Arrays.sort(arr);
        long sum=0;
        for(int i=0;i<n;i++){
            sum = (sum + (long)arr[i] * i) % MOD; // Calculate the sum with modulo
        }
        return (int)sum;
    }
}

```
### floor in sorted array
```java
class Solution {

    static int findFloor(long arr[], int n, long x) {
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
}
```
### find pair given difference
```java
class Solution {
    public int findPair(int n, int x, int[] arr) {
        Arrays.sort(arr);
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
}
```

