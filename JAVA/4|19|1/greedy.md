### fractional knapsack
```java
class compPWratio implements Comparator<Item>{
    public int compare(Item i1,Item i2){
        double r1=(double)i1.value/(double)i1.weight;
        double r2=(double)i2.value/(double)i2.weight;
        if(r1<r2)
        return 1;
        else
        return -1;
    }
}

class Solution {
    double fractionalKnapsack(int w, Item arr[], int n) {
        Arrays.sort(arr,new compPWratio());
        double maxprofit=0.0;
        for(Item i:arr){
            if(i.weight<=w){
                w=w-i.weight;
                maxprofit+=i.value;
            }
            else{
                maxprofit=maxprofit+w*(double)i.value/i.weight;
                break;
            }
        }
       return maxprofit;
    }
}
```
### 435. Non-overlapping Intervals
```java
class compINT implements Comparator<int[]>{
    public int compare(int a[],int b[]){
        return a[1]-b[1];
    }
}
class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
       
        Arrays.sort(intervals,new compINT());
        int n=intervals.length;
        int cet=Integer.MIN_VALUE;
        int removeCount=0;
        for(int i=0;i<n;i++){
            if(intervals[i][0]>=cet){
                cet=intervals[i][1];
            }
            else{
                removeCount++;

            }
        }
        return removeCount;
    }
}
```
### 56. Merge Intervals
```java
class compInt implements Comparator<int[]>{
    public int compare(int a[],int b[]){
        return a[0]-b[0];
    }
}
class Solution {
    public int[][] merge(int[][] intervals) {
       Arrays.sort(intervals,new compInt());
       LinkedList<int[]>temp=new LinkedList<>();
       int n=intervals.length;
       for(int i=0;i<n;i++){
        if(temp.isEmpty() || intervals[i][0]>temp.getLast()[1]){
            temp.add(intervals[i]);
        }
        else{
            temp.getLast()[1]=Math.max(intervals[i][1],temp.getLast()[1]);
        }

       }
       return temp.toArray(new int[temp.size()][]);
    }
}

```
### job sequencing
```java
class Solution
{
    class compInt implements Comparator<Job>{
        public int compare(Job a,Job b){
            return b.profit-a.profit;
        }
    }
    int[] JobScheduling(Job arr[], int n)
    {
        
        Arrays.sort(arr,new compInt());
        int maxdeadline=0;
        for(Job i:arr){
            maxdeadline=Math.max(maxdeadline,i.deadline);
        }
        int []temp=new int[maxdeadline];
        int total=0;int count=0;
        for(int i=0;i<n;i++){
            int j=Math.min(maxdeadline,arr[i].deadline)-1;
            while(j>=0){
                if(temp[j]==0){
                    temp[j]=arr[i].profit;
                    total+=arr[i].profit;
                    count++;
                    break;
                }
                j--;
            }
        }
        int []result=new int[2];
        result[0]=count;
        result[1]=total;
        return result;
    }
}

/*
class Job {
    int id, profit, deadline;
    Job(int x, int y, int z){
        this.id = x;
        this.deadline = y;
        this.profit = z; 
    }
}
*/
```
### minimum platforms
```java
class Solution {
    
    static int findPlatform(int arr[], int dep[]) {
        int n=arr.length;
        Arrays.sort(arr);
        Arrays.sort(dep);
        int platform=1,maxplat=1, i=1,j =0;
        while(i<n && j<n){
            if(arr[i]<=dep[j]){
                platform++;
                i++;
            }
            else{
                    platform--;
                    j++;
                }
                maxplat=Math.max(maxplat,platform);
            
        }
        return maxplat;
    }
}

```
### activity selection
```java
class Solution
{
    //greedy about end
    public static int activitySelection(int start[], int end[], int n)
    {
        int[][] temp=new int[n][2];
        for(int i=0;i<n;i++){
            temp[i][0]=start[i];
            temp[i][1]=end[i];
        }
        
        Arrays.sort(temp,new Comparator<int[]>(){
            public int compare(int[]a,int[]b){
                return Integer.compare(a[1], b[1]);
            }
        });
        int count=1; int endnum=temp[0][1];
        for(int i=1;i<n;i++){
            if(temp[i][0]>endnum){
                endnum=temp[i][1];
                count++;
            }
        }
        return count;
    }
}
```
### N meetings in one room
```java
class Solution {
    // greedy about end time
    public int maxMeetings(int n, int start[], int end[]) {
        int[][] temp=new int[n][2];
        for(int i=0;i<n;i++){
            temp[i][0]=start[i];
            temp[i][1]=end[i];
        }
        
        Arrays.sort(temp,new Comparator<int[]>(){
            public int compare(int[]a,int[]b){
                return Integer.compare(a[1],b[1]);
            }
        });
        int count=1;
        int endTime=temp[0][1];
        for(int i=1;i<n;i++){
            if(temp[i][0]>endTime){
                endTime=temp[i][1];
                count++;
            }
        }
        return count;
    }
}
```
### Maximize Toys
```java
class Solution{
    static int toyCount(int n, int k, int arr[])
    {
        Arrays.sort(arr);
        long sum=0;int count=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum<=k){
                count++;
            }
        }
        return count;
    }
}
```
### Page Faults in LRU
```java
class Solution{
    static int pageFaults(int n, int c, int pages[]){
        // code here
        ArrayList<Integer>temp=new ArrayList<>();
        //Set <Integer> pageSet=new HashSet<>();
        int pageFaults=0;
        for(int i=0;i<n;i++){
            if(!temp.contains(pages[i])){
                if(temp.size()==c){
                   temp.remove(0);
                   // pageSet.remove(lru);
                    
                }
                temp.add(pages[i]);
               // pageSet.add(pages[i]);
                pageFaults++;
            }
            else{
                temp.remove((Integer)pages[i]);
                temp.add(pages[i]);
            }
            
            
        }
        return pageFaults;
    }
}
```
### Largest number possible

```java
class Solution{
    static String findLargest(int N, int S){
       if(S==0)
       return (N==1)?"0":"-1";
       
       if(S>N*9){
           return "-1";
       }
       StringBuilder stb=new StringBuilder();
       for(int i=0;i<N;i++){
           int digit=Math.min(S,9);
           stb.append(digit);
           S-=digit;
       }
       return stb.toString();
        
        
    }
}
```
### Minimize the Heights II
```java
class Solution{
    public static int getMinDiff(int[] arr,int k) {
        int n=arr.length;
        if (n == 1) {
            return 0;
        }
        Arrays.sort(arr);
        int ans = arr[n - 1] - arr[0];

        int smallest = arr[0] + k;
        int largest = arr[n - 1] - k;

        for (int i = 0; i < n - 1; i++) {
            int minHeight = Math.min(smallest, arr[i + 1] - k);
            int maxHeight = Math.max(largest, arr[i] + k);
            if (minHeight < 0) {
                continue;
            }
            ans = Math.min(ans, maxHeight - minHeight);
        }
        return ans;
    }

   
}
```
### Minimize the sum of product

```java
class Solution {
    public long minValue(List<Integer> arr1, List<Integer> arr2) {
        int n=arr1.size();
        long sum=0;
        Collections.sort(arr1,Collections.reverseOrder());
        Collections.sort(arr2);
        for(int i=0;i<n;i++){
           int product=arr1.get(i)*arr2.get(i);
            sum+=product;
        }
        return sum;
    }
}
```
## part II
### 455. Assign Cookies
```java
class Solution {
    public int findContentChildren(int[] g, int[] s) {
        int n=g.length;
        int m=s.length;
        Arrays.sort(g);
        Arrays.sort(s);
      int j=0;int i=0;int count=0;
            while(j<m && i<n){
                if(g[i]<=s[j]){
                    count++;
                    i++;

                }
                j++;
                
            }
            return count;
        }
        
    }

```
### 121. Best Time to Buy and Sell Stock

```java
class Solution {
    public int maxProfit(int[] arr) {
       int n=arr.length;
       if(n==0){
        return 0;
       }
       int minPrice=arr[0]; int maxProfit=0;
       for(int i=1;i<n;i++){
        if(arr[i]<minPrice){
            minPrice=arr[i];
        }
        if((arr[i]-minPrice)>maxProfit){
            maxProfit=arr[i]-minPrice;
        }
       }
       return maxProfit;
    }
}
```
### gas station
```java
class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int n=gas.length;
        int gasSum=0; int costSum=0;int currentSum=0;int start=0;
        for(int i=0;i<n;i++){
            gasSum+=gas[i];
            costSum+=cost[i];
            currentSum+=gas[i]-cost[i];
            if(currentSum<0){
                start=i+1;
                currentSum=0;
            }
        }
        if(gasSum<costSum){
            return -1;
        }
return start;
        
    }
}
```
### 406. Queue Reconstruction by Height
```java
class Solution {
    public int[][] reconstructQueue(int[][] people) {
        Arrays.sort(people,(a,b)->{
            if(a[0]==b[0]){
                return a[1]-b[1];
            }
            else{
                return b[0]-a[0];
            }
        });
        List<int[]> temp=new ArrayList<>();

        for(int i=0;i<people.length;i++){
            temp.add(people[i][1],people[i]);
        }

       return temp.toArray(new int[people.length][2]) ;
    }
}
```
