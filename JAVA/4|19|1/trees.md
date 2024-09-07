### 94. Binary Tree Inorder Traversal
```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public void dfs(TreeNode root,List<Integer>res){
        if(root==null) return ;
        dfs(root.left,res);
        res.add(root.val);
        dfs(root.right,res);
    }
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> res=new ArrayList<>();
        dfs(root,res);
        return res;
        
    }
}
```
### 144. Binary Tree Preorder Traversal
```java
class Solution {
public void dfs(TreeNode root,List<Integer>res){
    if(root==null) return;
    res.add(root.val);
    dfs(root.left,res);
    dfs(root.right,res);
}

    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> res=new ArrayList<>();
        dfs(root,res);
        return res;

        
    }
}
```
### 145. Binary Tree Postorder Traversal

```java
class Solution {
public void dfs(TreeNode root,List<Integer>res){
    if(root==null) return;
    dfs(root.left,res);
    dfs(root.right,res);
    res.add(root.val);
}

    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer>res=new ArrayList<>();
        dfs(root,res);
        return res;
        
    }
}
```
### level order traversal
```java
class Solution
{
    //Function to return the level order traversal of a tree.
    static ArrayList <Integer> levelOrder(Node root) 
    {
        ArrayList<Integer>ans=new ArrayList<>();
        if(root==null) return ans;
        Deque<Node> q=new ArrayDeque<>();
        q.add(root);
        while(!q.isEmpty()){
            Node curr=q.remove();
            ans.add(curr.data);
            if(curr.left!=null) {
                q.add(curr.left);
            }
            if(curr.right!=null){
                q.add(curr.right);
            }
            
        }
        return ans;
    }
}
```
### 102. Binary Tree Level Order Traversal
```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> ans=new ArrayList<>();
        if(root==null) return ans;
        Deque<TreeNode>q=new ArrayDeque<>();
        q.add(root);
        while(!q.isEmpty()){
            List<Integer>l1=new ArrayList<>();
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode curr=q.remove();
                l1.add(curr.val);
                if(curr.left!=null) q.add(curr.left);
                if(curr.right!=null) q.add(curr.right);

            }
            ans.add(l1);
            

        }
        return ans;
        
    }
}
```
### 111. Minimum Depth of Binary Tree

```java
class Solution {
    public int minDepth(TreeNode root) {
        ArrayList<Integer> ans=new ArrayList<>();
        if(root==null) return 0;
        Deque<TreeNode>q=new ArrayDeque<>();
        q.add(root);
        int level=1;
        while(!q.isEmpty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode curr=q.remove();
                if(curr.left==null && curr.right==null) return level;
                if(curr.left!=null) q.add(curr.left);
                if(curr.right!=null) q.add(curr.right);

            }
            level++;
           

        }
        return level;
        
    }
}
```
### 103. Binary Tree Zigzag Level Order Traversal
```java
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
     List<List<Integer>> ans=new ArrayList<>();
        if(root==null) return ans;
        Deque<TreeNode>q=new ArrayDeque<>();
        q.add(root);
        boolean flag=false;
        while(!q.isEmpty()){
            List<Integer>l1=new ArrayList<>();
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode curr=q.remove();
                l1.add(curr.val);
                if(curr.left!=null) q.add(curr.left);
                if(curr.right!=null) q.add(curr.right);

            }
            if(flag){
                Collections.reverse(l1);
            }
            flag=!flag;
            ans.add(l1);
            

        }
        return ans;
        
    }
}
```
### 199. Binary Tree Right Side View
```java
class Solution {
    public List<Integer> rightSideView(TreeNode root) {
   List<Integer> ans=new ArrayList<>();
        if(root==null) return ans;
        Deque<TreeNode>q=new ArrayDeque<>();
        q.add(root);
        while(!q.isEmpty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode curr=q.remove();
                if(i==size-1){
                     ans.add(curr.val);
                }
               
                if(curr.left!=null) q.add(curr.left);
                if(curr.right!=null) q.add(curr.right);

            }
            
            

        }
        return ans;
        
    }
}
```
or
```java
class Solution {
    public List<Integer> rightSideView(TreeNode root) {
    List<Integer> ans=new ArrayList<>();
        if(root==null) return ans;
        Deque<TreeNode>q=new ArrayDeque<>();
        q.add(root);
        while(!q.isEmpty()){
            List<Integer>l1=new ArrayList<>();
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode curr=q.remove();
                l1.add(curr.val);
                if(curr.left!=null) q.add(curr.left);
                if(curr.right!=null) q.add(curr.right);

            }
            ans.add(l1.getLast());
            
            

        }
        return ans;
        
    }
}
```
or
```java
class Solution {
    public List<Integer> rightSideView(TreeNode root) {
    List<Integer> ans=new ArrayList<>();
        if(root==null) return ans;
        Deque<TreeNode>q=new ArrayDeque<>();
        q.add(root);
        while(!q.isEmpty()){
           // List<Integer>l1=new ArrayList<>();
           int temp=0;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode curr=q.remove();
                temp=curr.val;
                if(curr.left!=null) q.add(curr.left);
                if(curr.right!=null) q.add(curr.right);

            }
            ans.add(temp);   
            
        }
        return ans;
        
    }
}
```
### 129. Sum Root to Leaf Numbers

```java
class Solution {
    public int sumNumbers(TreeNode root) {
        List<Integer>l=new ArrayList<>();
        ps(root,0);
        return sum;
        
    }
    int sum=0;
    void ps(TreeNode root,int rs){
        if(root==null) return;
        if(root.left==null && root.right==null){
            sum=sum+(rs*10 +root.val);
            
        }
        ps(root.left,rs*10+root.val);
        ps(root.right,rs*10+root.val);
    }
}
```
### Count Leaves in Binary Tree
```java
class Tree
{
    int countLeaves(Node root) 
    {
         if(root==null) return 0;
         if(root.left==null && root.right==null){
             return 1;
         }
         return countLeaves(root.left)+countLeaves(root.right);
    }
}
```


