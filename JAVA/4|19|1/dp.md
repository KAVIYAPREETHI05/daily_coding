### 1143. Longest Common Subsequence
```java
class Solution {
   
    String s1,s2; 
    
        int m,n;
        int dp[][];
    
    int lcs(int i,int j){
        if(i>=m || j>=n){
            return 0;
        }
       if(dp[i][j]!=-1) return dp[i][j];
        if(s1.charAt(i)==s2.charAt(j)){
            return dp[i][j]=1+lcs(i+1,j+1);
        }
        else{
            return dp[i][j]=Math.max(lcs(i,j+1),lcs(i+1,j));
        }
    }
    public int longestCommonSubsequence(String text1, String text2) {
        this.s1=text1;
        this.s2=text2;
         m=s1.length();
         n=s2.length();
         dp=new int[m][n];
         for( int []i :dp){
            Arrays.fill(i,-1);
         }
        return lcs(0,0);

        
    }
}
```
### 516. Longest Palindromic Subsequence
```java
class Solution {
   
    String s1;   
        int m;
        int dp[][];
    
    int lps(int i,int j){
        if(i>j){
            return 0;
        }
       if(dp[i][j]!=-1) return dp[i][j];
       if(i==j) return 1;
        if(s1.charAt(i)==s1.charAt(j)){
            return dp[i][j]=2+lps(i+1,j-1);
        }
        else{
            return dp[i][j]=Math.max(lps(i,j-1),lps(i+1,j));
        }
    }
    public int longestPalindromeSubseq(String s) {
        this.s1=s;
        m=s1.length();
        
         dp=new int[m][m];
         for( int []i :dp){
            Arrays.fill(i,-1);
         }
        return lps(0,m-1);

        
    }
}
```
### 198. House Robber

top up approach
```java
class Solution {
    int dp[];
    private int robb(int[] nums,int i,int n){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i]=Math.max(robb(nums,i+1,n),robb(nums,i+2,n)+nums[i]);
    }
    public int rob(int[] nums) {
        
        int n=nums.length;
        dp=new int[n];
        Arrays.fill(dp,-1);
        return robb(nums,0,n);
    }
}
```
bottom down approach
```java
class Solution {
   
    public int rob(int[] nums) {
        
        int n=nums.length;
        if(n==1) return nums[0];
        int[]dp=new int[n];
        dp[0]=nums[0];
        dp[1]=Math.max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            dp[i]=Math.max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[n-1];
    }
}
```
tortoise and hare approach
```java

class Solution {
    public int rob(int[] nums) {
       int n = nums.length;
        if (n == 1) return nums[0];  
        int prev = nums[0];
        int curr = Math.max(nums[0], nums[1]);
       
        for (int i = 2; i < n; i++) {
            int next = Math.max(curr,prev+nums[i]);
            prev = curr;
            curr = next;
        }
       
        return curr;
    }
}
```
### 213. House Robber II
bottom up approach
```java
class Solution {
   
    public int rob(int[] nums) {
        
        int n=nums.length;
        if(n==1) return nums[0];
        if(n==2) return Math.max(nums[0],nums[1]);
        int[]dp=new int[n-1];
        dp[0]=nums[0];
        dp[1]=Math.max(nums[0],nums[1]);
        for(int i=2;i<n-1;i++){
            dp[i]=Math.max(dp[i-1],dp[i-2]+nums[i]);
        }
        int ans1=dp[n-2];

        int[]dp1=new int[n];
        dp1[0]=0;
        dp1[1]=nums[1];
        dp1[2]=Math.max(nums[1],nums[2]);
        for(int i=3;i<n;i++){
            dp1[i]=Math.max(dp1[i-1],dp1[i-2]+nums[i]);
        }
        int ans2= dp1[n-1];
        return Math.max(ans1,ans2);
    }
}
```
tortoise and hare approach
```java

class Solution {
    public int rob(int[] nums) {
       int n = nums.length;
        if (n == 1) return nums[0];  
        int prev = nums[0];
        int curr = Math.max(nums[0], nums[1]);
       
        for (int i = 2; i < n-1; i++) {
            int next = Math.max(curr,prev+nums[i]);
            prev = curr;
            curr = next;
        }
        int ans1=curr;   

          prev = nums[1];
        curr = (n > 2) ? Math.max(nums[1], nums[2]) : nums[1];
              
        for (int i = 3; i < n; i++) {
            int next = Math.max(curr,prev+nums[i]);
            prev = curr;
            curr = next;
        }
       int ans2=curr;
        return Math.max(ans1,ans2);
    }
}
```
### 62.Unique paths
top down approach
```java
class Solution {
    int dp[][];
    private int up(int m,int n,int i,int j){
        if(i>=m || j>=n){
            return 0;
        }
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=up(m,n,i+1,j)+ up(m,n,i,j+1);
    }
    public int uniquePaths(int m, int n) {
        dp=new int[m][n];
        for(int i[]:dp){
            Arrays.fill(i,-1);
        }
        return up(m,n,0,0);
        
    }
}
```
bottom up approach
```java
class Solution {
   
    public int uniquePaths(int m, int n) {
        int[][] dp=new int[m][n];
        for(int i[]:dp){
            Arrays.fill(i,1);
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++)
                dp[i][j]=dp[i][j-1] + dp[i-1][j];
           
        }
        return dp[m-1][n-1];
        
    }
}
```
### 63. Unique Paths II
top down approach

```java
class Solution {
    int [][] dp;
    int up(int [][]oGrid,int i,int j,int m,int n){
        if(i>=m ||j>=n){
            return 0;
        }
        if(oGrid[i][j]==1){
            return 0;
        }
        if(i==m-1 && j==n-1){
            return 1;
        }
       
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        return dp[i][j]=up(oGrid,i+1,j,m,n) + up(oGrid,i,j+1,m,n);
    }
    public int uniquePathsWithObstacles(int[][] oGrid) {
        int m=oGrid.length;
        int n=oGrid[0].length;
        dp=new int [m][n];
        for(int[]i:dp)
        Arrays.fill(i,-1);
        return up(oGrid,0,0,m,n);
        
    }
}
```
tortoise and hare approach
```java
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        if(o[0][0] == 1)return 0;
        int n = o.size();
        int m = o[0].size();
        vector<int> prev(m);
        prev[0] = 1;
        for(int j = 1; j < m; j++){
            if(o[0][j] == 0)prev[j] = prev[j-1];
        }
        for(int i = 1; i < n; i++){
            if(o[i][0] == 1) prev[0] = 0;
            for(int j = 1; j < m; j++){
                if(o[i][j] == 1) prev[j] = 0;
                else prev[j] += prev[j-1];
            }
        }
        return prev[m-1];
    }
}
```
### 70. Climbing Stairs
```java
//time limit exceeded
class Solution {
    int[]dp =new int[46];
    public int climbStairs(int n) {
        if(n==1 || n==2) return n;
        if(dp[n]!=0){
            return dp[n];
        }
        return dp[n]=climbStairs(n-1) + climbStairs(n-2);
        
    }
}
```
```java
class Solution {
  
    public int climbStairs(int n) {
        //if(n==1 || n==2) return n;
        int[] dp=new int[46];
        //dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1] + dp[i-2];
        }
        return dp[n];
       
    }
}
```
tortoise and hare
```java
class Solution {
  
    public int climbStairs(int n) {
        if(n==1 || n==2) return n;
        int prev=0,curr=1,next=0,i=1;
        while(i<=n){
            next=prev+curr;
            prev=curr;
            curr=next;
            
            i++;
        }
        return curr;
       
    }
}
```
### 300. Longest Increasing Subsequence
```java


class Solution {
    public int lengthOfLIS(int[] nums) {
        int m = nums.length;
        if (m == 0) return 0;

        int[] dp = new int[m];  
        Arrays.fill(dp, 1);  

        int maxLength = 1;

        for (int i = 1; i < m; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {  
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }
            maxLength = Math.max(maxLength, dp[i]);  
        }

        return maxLength; 
    }
}
```
### longest decreasing subsequence
```java


class Solution {
    public int lengthOfLIS(int[] nums) {
        int m = nums.length;
        if (m == 0) return 0;

        int[] dp = new int[m];  
        Arrays.fill(dp, 1);  

        int maxLength = 1;

        for (int i = 1; i < m; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] < nums[j]) {  
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }
            maxLength = Math.max(maxLength, dp[i]);  
        }

        return maxLength; 
    }
}
```
### Edit distance
top down approach
time limit exceeded
```java
class Solution {
    String s1,s2;
    int dp[][];
    public int minDistance(String word1, String word2) {
        
        this.s1=word1;
        this.s2=word2;
        int i=s1.length();
        int j=s2.length();

        dp=new int[i+1][j+1];
        for(int []k:dp){
            Arrays.fill(k,-1);
        }
        return mD(i,j);
    }
    int mD(int i,int j){
        if(i==0) return j;
        if(j==0) return i;
        if(s1.charAt(i-1)==s2.charAt(j-1)){
            return dp[i][j]=mD(i-1,j-1);
        }
        else{
            int iop=mD(i,j-1);
            int dop=mD(i-1,j);
            int rop=mD(i-1,j-1);
            return dp[i][j]=Math.min(iop,Math.min(dop,rop))+1;
        }
    }
}
```
bottom down approach or tortoise and hare approach
```java
class Solution {
    String s1, s2;
    int[][] dp;
    
    public int minDistance(String word1, String word2) {
        s1 = word1;
        s2 = word2;
        int m = s1.length();
        int n = s2.length();
        
        dp = new int[m + 1][n + 1];
        
        // Initialize base cases
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }
        
        // Fill the dp table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    int insertOp = dp[i][j - 1];
                    int deleteOp = dp[i - 1][j];
                    int replaceOp = dp[i - 1][j - 1];
                    dp[i][j] = Math.min(insertOp, Math.min(deleteOp, replaceOp)) + 1;
                }
            }
        }
        
        return dp[m][n];
    }
}

```
