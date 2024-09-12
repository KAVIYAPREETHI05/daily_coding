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
### 503. Next Greater Element II
```java
class Solution {
    public int[] nextGreaterElements(int[] nums) {
        int n=nums.length;
        int[] res=new int[n];
        Arrays.fill(res,-1);
       Stack <Integer> s=new Stack<>();
       for(int i=0;i<2*n;i++){
        if(!s.isEmpty() && nums[s.peek()]<nums[i%n]){
            res[s.pop()]=nums[i%n];
        }
        if(i<n){
            s.push(i);
        }
       }
       return res;
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
### move zeros
```java
class Solution {
    void swap(int[] nums,int i,int start){
        int temp=nums[i];
        nums[i]=nums[start];
        nums[start]=temp;
    }
    public void moveZeroes(int[] nums) {
        int n=nums.length;
        int start=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                swap(nums,i,start);
                 start++;

            }
           
        }
     
    }
}
```
### valid parenthesis
```java
class Solution {
    public boolean checkValidString(String s) {
        int low = 0; 
        int high = 0; 

        for (char c : s.toCharArray()) {
            if (c == '(') {
                low++;
                high++;
            } else if (c == ')') {
                low = Math.max(low - 1, 0); 
                high--;
            } else if (c == '*') {
                // '*' can be '(', ')' or empty
                low = Math.max(low - 1, 0); // Treat '*' as ')' or empty
                high++; // Treat '*' as '('
            }

            if (high < 0) {
                return false;
            }
        }

        return low == 0;
    }
}

```
### 482. license key formatting
```java
class Solution {
    public String licenseKeyFormatting(String s, int k) {
        StringBuilder cleaned = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (c != '-') {
                cleaned.append(Character.toUpperCase(c));
            }
        }
        
        if (cleaned.length() == 0) {
            return "";
        }

        StringBuilder result = new StringBuilder();
        int length = cleaned.length();
        
        int firstGroupLength = length % k == 0 ? k : length % k;
        result.append(cleaned.substring(0, firstGroupLength));
        
        for (int i = firstGroupLength; i < length; i += k) {
            result.append("-").append(cleaned.substring(i, Math.min(i + k, length)));
        }
        
        return result.toString();
    }
}
```
