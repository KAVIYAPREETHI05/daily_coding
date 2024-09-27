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
### 21.merge two sorted linked list
```java
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
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode dummy=new ListNode(-1);
        ListNode current=dummy;
        if(l1==null) return l2;
        if(l2==null) return l1;
        while(l1!=null && l2!=null){
            if(l1.val<=l2.val){
                current.next=l1;
                l1=l1.next;
            }
            else{
                current.next=l2;
                l2=l2.next;
            }
            current=current.next;
        }
        if(l1!=null){
            current.next=l1;
        }
        else{
            current.next=l2;
        }
        return dummy.next;
    }
}
```
### 160. Intersection of Two Linked Lists

```java
set approach
time complexity=O(m+n)
space complexity=O(n)
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode A, ListNode B) {
        Set<ListNode>s=new HashSet<>();
        ListNode l1=A;
        ListNode l2=B;
        while(l1!=null){
            s.add(l1);
            l1=l1.next;
            
        }
        while(l2!=null){
            if(s.contains(l2)==true){
                return l2;
            }
            s.add(l2);
            l2=l2.next;
            
        }
        return null;
    }
}
```
```java
//time complexity=O(m+n)
//space complexity=O(1)
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    private int getLength(ListNode head){
        int length=0;
        while(head!=null){
            length++;
            head=head.next;
        }
        return length;
    }
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        int l1=getLength(headA);
        int l2=getLength(headB);
        while(l1>l2){
            headA=headA.next;
            l1--;
        }
        while(l2>l1){
            headB=headB.next;
            l2--;
        }
        while(headA!=headB){
            headA=headA.next;
             headB=headB.next;
            
        }
        return headA;
        
    }
}
```
```java
time complexity=O(m+n)
space complexity=O(1)
public class Solution {
    public ListNode getIntersectionNode(ListNode A, ListNode B) {
      ListNode l1=A;ListNode l2=B;
      while(l1!=l2){
        l1=l1==null?B:l1.next;
        l2=l2==null?A:l2.next;
      }
      return l1;
    }
}
```
### 19. Remove Nth Node From End of List

```java
lass Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
     
        if (head == null) {
            return null;
        }

        ListNode dummy = new ListNode(0);
        dummy.next = head;

        ListNode temp = head;
        int count = 0;
        while (temp != null) {
            count++;
            temp = temp.next;
        }

        int index = count - n;
        temp = dummy; 

        for (int i = 0; i < index; i++) {
            temp = temp.next;
        }

        temp.next = temp.next.next;

        return dummy.next;
    }
}

```
```java
 
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if(head==null){
            return null;
        }
        
        
        ListNode temp=head;
        int count=0;
        while(temp!=null){
            count++;
            temp=temp.next;
        }
        if(count==n){
            return head.next;
        }
        int index=count-n-1;
        temp=head;

        for(int i=0;i<index;i++){
            temp=temp.next;
        }
      
         temp.next=temp.next.next;;
       
     return head;   
    }
}
```
### Middle of a Linked List
```java
class Solution {
    int getMiddle(Node head) {
        // Your code here.
        if(head==null){
            return -1;
        }
        Node current=head;
        int count=0;
        
        while(current!=null){
            count++;
            current=current.next;
           
        }
        int middle=count/2;
        current=head;
        int index=0;
        while(current!=null){
            if(index==middle){
                return current.data;
            }
            index++;
            current=current.next;
            
        }
        return -1;
    }
}
```
### reverse linked list
```java
class Solution {
    Node reverseList(Node head) {
        Node curr=head;
        Node temp=null;
        while(curr!=null){
            curr=head.next;
            head.next=temp;
            temp=head;
            head=curr;
        }
        return temp;
    }
}
```
### 
