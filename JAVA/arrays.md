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
