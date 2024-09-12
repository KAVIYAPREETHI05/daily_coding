## 1. Dutch National Flag
- `0` → Red
- `1` → White
- `2` → Blue
### Sort 0s, 1s and 2s 
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
//reversing image section
```
### reverse array in groups
```java
class Solution {

    void reverseInGroups(ArrayList<Long> arr, int k) {
        int n=arr.size();
            for (int i = 0; i < n; i += k) {
            int start = i;
            int end = Math.min(i + k - 1, n - 1);
            Collections.reverse(arr.subList(start, end + 1));
        }
    }
}

```
```java
class Solution {
    private void reverseRange(ArrayList<Long>arr,int start,int end){
        while(start<end){
            Long temp=arr.get(start);
            arr.set(start,arr.get(end));
            arr.set(end,temp);
            start++;
            end--;
        }
    }

    void reverseInGroups(ArrayList<Long> arr, int k) {
        int n=arr.size();
            for (int i = 0; i < n; i += k) {
            int start = i;
            int end = Math.min(i + k - 1, n - 1);
            reverseRange(arr,start,end);
        }
    }
}
//encryption
```

