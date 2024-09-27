### 876. Middle of the Linked List

```c
struct ListNode* middleNode(struct ListNode* head) {
    if(head==NULL){
        return head;
    }
    struct ListNode*current=head;
    int count=0;
    while(current!=NULL){
        count++;
        current=current->next;
    }
    int middle=(count/2);
    current=head;
    while(middle>0){        
        current=current->next;
        middle--;
    }

return current;
    
}
```
 ### 206. Reverse Linked List

```c
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* curr=head;
    struct ListNode* temp=NULL;
    while(curr!=NULL){
        curr=head->next;
        head->next=temp;
        temp=head;
        head=curr;
    }
    return temp;
    
}
```
### 
