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
