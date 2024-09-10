### array leaders
```java

class Solution {
   
    static ArrayList<Integer> leaders(int n, int arr[]) {
        
        ArrayList<Integer>temp=new ArrayList<>();
        int last=arr[n-1];
        temp.add(arr[n-1]);
        for(int i=n-2;i>=0;i--){
            if(arr[i]>=last){
                last=arr[i];
                temp.add(arr[i]);
            }
        }
        Collections.reverse(temp);
        return temp;
    }
}
```
### Equilibrium Point
```java
class Solution {
    public static int equilibriumPoint(long arr[]) {
        int n=arr.length;
        if(n==1){
            return 1;
        }
        int total=0;
       for(int i=0;i<n;i++){
           total+=arr[i];
       }
       int leftsum=0;
       for(int i=0;i<n;i++){
           if(leftsum==total-leftsum-arr[i]){
               return i+1;
           }
           leftsum+=arr[i];
           
       }
       return -1;
    }
}
```
### 496. Next Greater Element I
```java
class Solution {
    int nextgreater(int j,int num,int []nums2,int n2){
        for(int i=j+1;i<n2;i++){
            if(nums2[i]>num){
                return nums2[i];
            }
        }
        return -1;
    }
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int n1=nums1.length;
        int n2=nums2.length;
        ArrayList<Integer>result=new ArrayList<>();
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                if(nums1[i]==nums2[j]){
                    int ans=nextgreater(j,nums2[j],nums2,n2);
                    result.add(ans);
                    break;

                    
                }
            }
        }

        return result.stream().mapToInt(i -> i).toArray();
    }
}
```
### 739. Daily Temperatures
```java
//time limit exceeded
class Solution {
    public int[] dailyTemperatures(int[] temp) {
        int n=temp.length;
        int[] ans=new int[n];
        for(int i=0;i<n-1;i++){
            int start=i+1;
            int count=1;
            if(temp[i]<temp[start]){
                ans[i]=1;

            }
            else{
                while(start<n){
                     if(temp[i]<temp[start]){
                        ans[i]=count;
                         break;           }
            start++;
            count++;
            
                }
            }
        }
return ans;
        
    }
}
```

optimized code

```java
import java.util.Stack;

class Solution {
    public int[] dailyTemperatures(int[] temp) {
        int n = temp.length;
        int[] ans = new int[n];
        Stack<Integer> stack = new Stack<>();

        for (int i = 0; i < n; i++) {
            while (!stack.isEmpty() && temp[i] > temp[stack.peek()]) {
                int index = stack.pop();
                ans[index] = i - index;  
            }
            stack.push(i);
        }


        return ans;
    }
}

```
