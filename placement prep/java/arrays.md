### adding unique elements in array

```java
import java.util.Scanner;
public class addUnique {
    public static void main(String[] args){
        Scanner s=new Scanner(System.in);
        int n=s.nextInt();

        int[] arr=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=s.nextInt();
        }

        int sum=0;
        for(int i=0;i<n;i++){
            int curr=arr[i];int flag=0;

           if(curr!=0){
            for(int j=i+1;j<n;j++){
                if(arr[i]==arr[j]){
                    arr[j]=0;
                    flag=1;
                }

            }
            if(flag==0){
                sum+=curr;
            }
           }


        }
        System.out.print(sum);
    }
    
}
```

### SUM OF SMALLEST SUB ARRAY IS GREATER THAN THE GIVEN VALUE
```java
class Solution {

    public static int smallestSubWithSum(int sum, int[] arr) {
        // Your code goes here
        int n=arr.length;
        
        int i=0,j=0,curr=0;int minlen=Integer.MAX_VALUE;

        while(j<n){
            while(curr<=sum && j<n){
                curr+=arr[j];
                j++;
            }
            while(curr>sum && i<n){
                minlen=Math.min(minlen,j-i);
                curr-=arr[i];
                i++;
               

            }
           
        }
        return (minlen==Integer.MAX_VALUE?0:minlen);
    
    }
}
```

### LEXICOGRAPHICAL RANK OF A STRING

```java
class Solution {
    static long[] fact = new long[21];  // For factorials up to 20

    // Precompute factorials
    static void computeFactorials() {
        fact[0] = 1;
        for (int i = 1; i <= 20; i++) {
            fact[i] = fact[i - 1] * i;
        }
    }

    // Function to calculate the product of factorials of char frequencies
    static long calculateDenominator(int[] freq) {
        long denom = 1;
        for (int i = 0; i < 256; i++) {
            if (freq[i] > 1) {
                denom *= fact[freq[i]];
            }
        }
        return denom;
    }
    public long findRank(String s) {
        // Code here
        computeFactorials();
        int n = s.length();
        long rank = 1;

        int[] freq = new int[256];
        for (char c : s.toCharArray()) {
            freq[c]++;
        }

        for (int i = 0; i < n; i++) {
            long countSmaller = 0;

            for (int ch = 0; ch < s.charAt(i); ch++) {
                if (freq[ch] > 0) {
                    freq[ch]--;
                    long num = fact[n - i - 1];
                    long denom = calculateDenominator(freq);
                    countSmaller += num / denom;
                    freq[ch]++;
                }
            }

            rank += countSmaller;
            freq[s.charAt(i)]--;

            if (freq[s.charAt(i)] < 0) {
                return -1;  // Invalid input with repeated characters beyond frequency
            }
        }

        return rank;
        
    }
}
```

### lcm
```java
import java.util.Scanner;

public class lcm{
    static int gcd(int a,int b){
        if(b==0){
            return a;
        }
        return gcd(b,a%b);
    }
    static int findLCM(int n,int[]arr){
        int maxlcm=-1;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                maxlcm=Math.max(maxlcm,(arr[i]*arr[j])/gcd(arr[i],arr[j]));

            }
        }
        return maxlcm;

    }
    public static void main(String[] args){
        Scanner s=new Scanner(System.in);
        int n=s.nextInt();

        int arr[]=new int[n];

        for(int i=0;i<n;i++){
            arr[i]=s.nextInt();
        }

        System.out.print(findLCM(n,arr));
    }
}
```

### lucky number

```java

import java.util.Scanner;
import java.util.HashSet;

public class lucky{
    static boolean findlucky(int n){
        String str=String.valueOf(n);
        HashSet <Character>hs=new HashSet<>();

        for(int i=0;i<str.length();i++){
            char ch=str.charAt(i);
            if(hs.contains(ch)){
                return false;
            }
            hs.add(ch);
           
        }
        return true;
    }
    
    public static void main(String[] args){
        Scanner s=new Scanner(System.in);
        int n=s.nextInt();
        System.out.print(findlucky(n));
    }
}
```
