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
