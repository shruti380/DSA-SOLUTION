/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
  int ans=0;
    void solve(Node* root,int& sum,int level,int& maxi){
        if(root==NULL){
            return ;
        }
        sum+=root->data;
        if(level>maxi){
            ans=sum;
            maxi=level;
        }
        else if(level==maxi){
            ans=max(ans,sum);
        }
        solve(root->left,sum,level+1,maxi);
        solve(root->right,sum,level+1,maxi);
        sum-=root->data;
    }
    int sumOfLongRootToLeafPath(Node *root) {
         int sum=0,level=0,maxi=0;
        solve(root,sum,level,maxi);
        return ans;
        
    }
};