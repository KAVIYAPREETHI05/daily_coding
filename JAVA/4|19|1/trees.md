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
