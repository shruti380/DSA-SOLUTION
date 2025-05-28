//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  bool Util(int ind,int target,vector<int>&arr,vector<vector<int>>&dp){
      if(target==0){
          return true;
      }
      if(ind==0){
          return (arr[0]==target);
      }
      if(dp[ind][target]!=-1){
          return dp[ind][target];
      }
      bool notTaken=Util(ind-1,target,arr,dp);
      bool taken=false;
      if(arr[ind]<=target){
          taken=Util(ind-1,target-arr[ind],arr,dp);
      }
      return dp[ind][target]=notTaken||taken;
  }
    bool isSubsetSum(vector<int>& arr, int target) {
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return Util(n-1,target,arr,dp);
       
    


        // code here
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends