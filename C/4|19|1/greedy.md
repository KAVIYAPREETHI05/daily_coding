## part II
### 455. Assign Cookies

```c
int compare(const void * a,const void *b){
    return *(int*)a - *(int*)b;
}
int findContentChildren(int* g, int gSize, int* s, int sSize) {
    
        qsort(g,gSize,sizeof(int),compare);
        qsort(s,sSize,sizeof(int),compare);
        
      int j=0;int i=0;int count=0;
            while(j<sSize && i<gSize){
                if(g[i]<=s[j]){
                    count++;
                    i++;

                }
                j++;
                
            }
            return count;
        }

```

### 121. Best Time to Buy and Sell Stock

```c
int maxProfit(int* arr, int pricesSize) {
   
       if(pricesSize==0){
        return 0;
       }
       int minPrice=arr[0]; int maxProfit=0;
       for(int i=1;i<pricesSize;i++){
        if(arr[i]<minPrice){
            minPrice=arr[i];
        }
        if((arr[i]-minPrice)>maxProfit){
            maxProfit=arr[i]-minPrice;
        }
       }
       return maxProfit;
}
```
### gas station
```c
int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {

        int gasSum=0; int costSum=0;int currentSum=0;int start=0;
        for(int i=0;i<gasSize;i++){
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
```
### 406. Queue Reconstruction by Height

### Merge Intervals
```c
int compare(const void *a,const void*b){
    int *intervalA=*(int**)a;
    int *intervalB=*(int **)b;
    return intervalA[0]-intervalB[0];
}
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    qsort(intervals,intervalsSize,sizeof(int*),compare);

    int**mergedInterval=(int**)malloc(intervalsSize*sizeof(int*));
    *returnColumnSizes=(int*)malloc(intervalsSize*sizeof(int));
    int count=0;

    mergedInterval[count]=(int*)malloc(2*sizeof(int));
    mergedInterval[count][0]=intervals[0][0];
    mergedInterval[count][1]=intervals[0][1];
        (*returnColumnSizes)[count]=2;
        
        for(int i=1;i<intervalsSize;i++){
            if(intervals[i][0]>mergedInterval[count][1]){
                count++;
    mergedInterval[count]=(int*)malloc(2*sizeof(int));
    mergedInterval[count][0]=intervals[i][0];
    mergedInterval[count][1]=intervals[i][1];
        (*returnColumnSizes)[count]=2;
            }
            else{
                mergedInterval[count][1]=(intervals[i][1] > mergedInterval[count][1]) ? intervals[i][1] : mergedInterval[count][1];
            }
        }
        *returnSize=count+1;
        return mergedInterval; 
}
```
### non-overlapping 

```c
int compare(const void * a, const void *b){
    int *intervalA=*(int**)a;
    int *intervalB=*(int**)b;
    return intervalA[1]-intervalB[1];
}

int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {

    qsort(intervals,intervalsSize,sizeof(int*),compare);

    int cet=INT_MIN;
    int removeCount=0;

    for(int i=0;i<intervalsSize;i++){
        if(intervals[i][0]>=cet){
            cet=intervals[i][1];
        }
        else{
            removeCount++;
        }
    }
    return removeCount;
}
```
### Minimum Number of Arrows to Burst Balloons

```c
int compare(const void *a,const void *b){
    int *intervalA=*(int**)a;
    int *intervalB=*(int**)b;
    if (intervalA[1] < intervalB[1]) return -1; 
    if (intervalA[1] > intervalB[1]) return 1; 
    return 0; 
}

int findMinArrowShots(int** points, int pointsSize, int* pointsColSize) {
    if(pointsSize==0){
        return 0;
    }
    qsort(points,pointsSize,sizeof(int*),compare);
    int cet=points[0][1];
int count=1;
        for(int i=1;i<pointsSize;i++){
            if(points[i][0]>cet){
                cet=points[i][1];
                count++;
            }
        }
        return count;
    
}
```

### 1029. Two City Scheduling
```c
int compare(const void *a, const void *b){
   const int * costA=*(const int **)a;
      const int * costB=*(const int **)b;

    return (costA[0]-costA[1]) - (costB[0]-costB[1]);
}


int twoCitySchedCost(int** costs, int costsSize, int* costsColSize) {
    qsort(costs,costsSize,sizeof(int*),compare);
int n=costsSize/2;
int sum=0;
    for(int i=0;i<n;i++){
        sum+=costs[i][0];
    }
    for(int i=n;i<costsSize;i++){
        sum+=costs[i][1];
    }
    return sum;
    
}
```






