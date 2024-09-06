### linkedlist length is even or odd
```java
class Solution {
    public boolean isLengthEven(Node head) {
    boolean flag=true;
    Node n=head;
    while(n!=null){
        flag=!flag;
        n=n.next;
    }
    return flag;
    }
}

```
### 206.reverse linked list

```java
class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode temp=head;
        ListNode prev=null;
        while(temp!=null){
            temp=head.next;
            head.next=prev;
            prev=head;
            head=temp;
        }
        return prev;
        
    }
}
```
### 234.Palindrome Linked List

```java
//using stack
class Solution {
    public boolean isPalindrome(ListNode head) {
        ListNode temp=head;
        Stack <Integer>s=new Stack<>();
        while(temp!=null){
            s.push(temp.val);
            temp=temp.next;
        }
        temp=head;
        while(temp!=null){
            if(temp.val!=s.pop()){
                return false;
            }
                temp=temp.next;

        }
        return true;
    }
}
```
```java
//using deque
class Solution {
    public boolean isPalindrome(ListNode head) {
        ListNode temp=head;
        Deque<Integer> s=new ArrayDeque<>();

        while(temp!=null){
            s.push(temp.val);
            temp=temp.next;
        }
        temp=head;
        while(temp!=null){
            if(temp.val!=s.pop()){
                return false;
            }
                temp=temp.next;

        }
        return true;
    }
}
```
```java
//using list

class Solution {
    public boolean isPalindrome(ListNode head) {
        ListNode temp=head;
        List<Integer>s=new ArrayList<>();


        while(temp!=null){
            s.add(temp.val);
            temp=temp.next;
        }
        temp=head;int i=s.size()-1;
        while(temp!=null){
            if(temp.val!=s.get(i)){
                return false;
            }
                temp=temp.next;
                i--;

        }
        return true;
    }
}
```
### add two numbers
leetcode-2
```java
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode t=new ListNode();
        ListNode d=t;
        int carry=0;
        while(l1!=null || l2!=null || carry!=0){
            int sum=carry;
            if(l1!=null){
                sum+=l1.val;
                l1=l1.next;
                
            }
            if(l2!=null){
                sum+=l2.val;
                l2=l2.next;
            }
            d.next=new ListNode(sum%10);
            carry=sum/10;
            d=d.next;

        }
        return t.next;
    }
}
```
### middle of linked list
##### [https://leetcode.com/problems/middle-of-the-linked-list/submissions/1193391779/]

```java
class Solution {
    public ListNode middleNode(ListNode head) {
        int count=0;
        ListNode temp=head;

        while(temp!=null){
            count++;
            temp=temp.next;
        }

        int MidIndex=count/2 + 1;
        temp=head;
        while(temp!=null){
            MidIndex--;
            if(MidIndex==0){
                break;
            }
            temp=temp.next;
        }

        return temp;
    }
}
```
```java
another approach
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode middleNode(ListNode head) {
        ListNode slow=head;
        ListNode fast=head;
        while(fast!=null){
            fast=fast.next;
            if(fast!=null){
                fast=fast.next;
                slow=slow.next;
            }

        }
        return slow;
        
    }
}
```
### 141. Linked List Cycle

```java
public class Solution {
    public boolean hasCycle(ListNode head) {
        ListNode slow=head;
        ListNode fast=head;
        while(fast!=null){
            fast=fast.next;
            if(fast!=null){
                fast=fast.next;
                slow=slow.next;

            }
            if(fast==slow){
                return true;
            }
        }
        return false;
        
    }
}
```
```
//using stack approach

public class Solution {
    public boolean hasCycle(ListNode head) {
      
        ListNode temp=head;
        Stack<ListNode> s=new Stack<>();
        while(temp!=null){
            if(s.contains(temp)==true){
                return true;
            }
            s.add(temp);
            temp=temp.next;
        }
        return false;
        
    }
}
```
### 142. Linked List Cycle II
```java
//using stack
public class Solution {
    public ListNode detectCycle(ListNode head) {
        ListNode temp=head;
        Stack<ListNode> s=new Stack<>();
        while(temp!=null){
            if(s.contains(temp)==true){
                return temp;
            }
            s.add(temp);
            temp=temp.next;
        }
        return null;
        
    }
}
```
```java

public class Solution {
    public ListNode detectCycle(ListNode head) {
        
        ListNode slow=head;
        ListNode fast=head;
        while(fast!=null){
            fast=fast.next;
            if(fast!=null){
                fast=fast.next;
                slow=slow.next;

            }
            if(fast==slow){
                break;
            }
        }
        if(fast==null) return fast;
        slow=head;
        while(slow!=fast){
            slow=slow.next;
            fast=fast.next;
            
        }
        return fast;
        
    }
}
```
### 202.happy number
```java
class Solution {
    int ishappy(int n){
        int sum=0;
        while(n>0){
            int digit=n%10;
            sum+=Math.pow(digit,2);
            n/=10;
        }
        return sum;

    }
    public boolean isHappy(int n) {
     int slow=n;
     int fast=n;
     do{
        slow=ishappy(slow);
        fast=ishappy(fast);
        fast=ishappy(fast);
     } 
     while(slow!=fast);
     if(slow==1){
        return true;
     }
     return false;
    }
}
```
### 287. Find the Duplicate Number
```java
using set approach
class Solution {
    public int findDuplicate(int[] nums) {
        Set<Integer> s=new HashSet<>();
        for(int i:nums){
            if(s.contains(i)==true){
                return i;
            }
            s.add(i);
        }
        return -1;
        
        
    }
}
```
```java
//tortoise and hare approach
class Solution {
    public int findDuplicate(int[] nums) {
        int slow=nums[0];
        int fast=nums[0];
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];

        }while(slow!=fast);
        slow=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
        
    }
}
```
