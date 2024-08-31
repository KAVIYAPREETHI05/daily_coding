### reverse linked list
leetcode-206
```java
class Solution {
    public ListNode reverseList(ListNode head) {
         ListNode dummy=null;
        
        while(head!=null){
        ListNode Next=head.next;
        head.next=dummy;
        dummy=head;
        head=Next;        
    } 
    return dummy;      
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
