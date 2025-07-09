class Solution {
public:
    vector<int> findPse(vector<int> &arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> pse(n, -1);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {  // Fixed: >= instead of >
                st.pop();
            }
            if (!st.empty()) {
                pse[i] = st.top();
            }
            st.push(i);
        }
        return pse;
    }
    
    vector<int> findNse(vector<int> &arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> nse(n, n);  // Fixed: Initialize with n instead of -1
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nse[i] = st.top();
            }
            st.push(i);
        }
        return nse;
    }
    
    int sumSubMins(vector<int>& arr) {  // Fixed: parameter should be reference
        vector<int> nextSmaller = findNse(arr);
        vector<int> prevSmaller = findPse(arr);
        long long total = 0;
        int mod = 1e9 + 7;
        int n = arr.size();
        
        for (int i = 0; i < n; i++) {
            int left = i - prevSmaller[i];
            int right = nextSmaller[i] - i;
            long long currSize = (long long)left * right % mod;
            long long val = (arr[i] * currSize) % mod;
            total = (total + val) % mod;
        }
        return total;
    }
};