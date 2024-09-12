### Sort 0s, 1s and 2s or Dutch National Flag
```java
class Solution {
  
    public void sort012(ArrayList<Integer> arr) {
    int n=arr.size();
    int start=0;int end=n-1;int mid=0;
    while(mid<=end){
        if(arr.get(mid)==0){
            Collections.swap(arr,start,mid);
            start++;
            mid++;
            
        }
        else if(arr.get(mid)==1){
            
            mid++;
        }
        else if(arr.get(mid)==2){
             Collections.swap(arr,end,mid);
                end--;
            
        }
    }
    }
}
```
