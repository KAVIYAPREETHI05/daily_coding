### Check Equal Arrays
```java
// time limit exceeded
class Solution {
    // Function to check if two arrays are equal or not.
    public static boolean check(int[] arr1, int[] arr2) {
        // Your code here
        int n=arr1.length;
        int m=arr2.length;
        int [] temp=new int[10000000];
        for(int i=0;i<n;i++){
            temp[arr1[i]]++;
        }
        for(int j=0;j<m;j++){
            temp[arr2[j]]--;
        }
        for(int i=0;i<10000000;i++){
            if(temp[i]!=0){
                return false;
            }
        }
        return true;
    }
}
```
```java
//using hashmap

class Solution {
    // Function to check if two arrays are equal or not.
    public static boolean check(int[] arr1, int[] arr2) {
        if(arr1.length!=arr2.length){
            return false;
        }
        HashMap<Integer,Integer>temp=new HashMap<>();
        for(int i=0;i<arr1.length;i++){
            int num=arr1[i];
            if(temp.containsKey(num)){
                temp.put(num,temp.get(num)+1);
            }
            else{
                 temp.put(num,1);
            }
        }
        for(int i=0;i<arr2.length;i++){
            int num=arr2[i];
            if(!temp.containsKey(num)){
                return false;
            }
            temp.put(num,temp.get(num)-1);
            if(temp.get(num)==0){
                temp.remove(num);
            }
        }
        return temp.isEmpty();
    }
}

```
