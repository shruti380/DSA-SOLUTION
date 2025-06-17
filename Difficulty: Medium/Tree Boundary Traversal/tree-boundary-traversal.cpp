/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  bool isLeaf(Node*root){
      return !root->left&&!root->right;
  }
  void addLeftNode(Node*root,vector<int>&res){
      Node*curr=root->left;
      while(curr){
          if(!isLeaf(curr)){
              res.push_back(curr->data);
          }
          if(curr->left!=NULL){
              curr=curr->left;
          }
          else{
              curr=curr->right;
          }
      }
      
  }
  void addRightNode(Node*root,vector<int>&res){
      Node*curr=root->right;
      vector<int>temp;
      while(curr){
          if(!isLeaf(curr)){
              temp.push_back(curr->data);
          }
          if(curr->right!=NULL){
              curr=curr->right;
          }
          else{
              curr=curr->left;
          }
      }
      for(int i=temp.size()-1;i>=0;i--){
          res.push_back(temp[i]);
      }
  }
  void addLeaf(Node*root,vector<int>&res){
      if(isLeaf(root)){
          res.push_back(root->data);
          return;
      }
      if(root->left){
          addLeaf(root->left,res);
      }
      if(root->right){
          addLeaf(root->right,res);
      }
      
  }
  
    vector<int> boundaryTraversal(Node *root) {
       
        vector<int>res;
        if (!root) return res;  
        if(!isLeaf(root)){
            res.push_back(root->data);
        }
        addLeftNode(root,res);
        addLeaf(root,res);
        addRightNode(root,res);
        return res;
        // code here
        
    }
};