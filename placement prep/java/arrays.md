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
    long factorial(int n){
        if(n<=1){
            return 1;
        }
        return n*factorial(n-1);
    }
    long smallerLetter(int index,String s){
        long count=0;
        for(int i=index+1;i<s.length();i++){
            if(s.charAt(index)>s.charAt(i)){
                count++;
            }
            
        }
        return count;
        
    }
    long findPermutation(String s){
        int n=s.length();
        long rank=1;
        for(int i=0;i<n;i++){
            long count=smallerLetter(i,s) ;
            rank+=(count* factorial(n-1-i));
        }
        return rank;
    }
    public long findRank(String S) {
        
        return findPermutation(S);
        
    }
}
```

### no of combinations

```java
import java.util.Scanner;
public class noOfCombinations {
    static int numOfCom(int[] arr,int n){
        int[]c={0,0,0};

        for(int i=0;i<n;i++){
            ++c[arr[i]%3];
           
        }

        int pair_1_2=c[1]*c[2];
        int pair_00=c[0]*(c[0]-1)/2;
        int triplet_000=c[0]*(c[0]-1)*(c[0]-2)/6;
        int triplet_111=c[1]*(c[1]-1)*(c[1]-2)/6;
        int triplet_222=c[2]*(c[2]-1)*(c[2]-2)/6;
        int triplet_012=c[0]*c[1]*c[2];

        return pair_1_2+pair_00+triplet_000+triplet_111+triplet_222+triplet_012;

    }
    public static void main(String[] args){
     
        int[] arr1 = { 1, 5, 7, 2, 9, 14 }; 
    System.out.println("Result for arr1"+numOfCom(arr1, arr1.length));

    int arr2[] = { 3, 6, 9, 12 }; 
    System.out.print("Result for arr2"+numOfCom(arr2, arr2.length));



    }
    
}


```

### wildcard matching

```java
class Solution {
    public boolean isMatch(String s, String p) {
        int sIndex=0;int pIndex=0;int starIndex=-1;int sTempIndex=-1;

        while(sIndex<s.length()){
            if(pIndex<p.length() && (p.charAt(pIndex)==s.charAt(sIndex) || p.charAt(pIndex)=='?')){
                pIndex++;
                sIndex++;
            }
            else if(pIndex<p.length() && p.charAt(pIndex)=='*'){
                starIndex=pIndex;
                sTempIndex=sIndex;
                pIndex++;
            }
            else if(starIndex==-1){
                return false;
            }
            else{
                pIndex=starIndex+1;
                sTempIndex++;
                sIndex=sTempIndex;
            }
        }

        while(pIndex<p.length() && p.charAt(pIndex)=='*'){
            pIndex++;
        }
        return pIndex==p.length();
        
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
