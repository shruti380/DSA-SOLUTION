class SGT{
	vector<int> sgt;
    vector<int> it;

	public:
        SGT(int n){
            sgt.resize(4*n,INT_MAX);
            it.resize(4*n, -1);
        }

        void build(int index,int low,int high,vector<int>& arr){
            if(low == high){
                sgt[index] = arr[low];
                it[index] = low;
                return ;
            }

            int mid = (low + high)/2;
            build(index*2+1,low,mid,arr);
            build(index*2+2,mid+1,high,arr);
            sgt[index] = min(sgt[index*2+1],sgt[index*2+2]);
            if(sgt[index] == sgt[index*2+1]) it[index] = it[index*2+1];
            else it[index] = it[index*2 + 2];
        }

        pair<int,int> query(int index,int low,int high,int l,int h){
            if (l > h) return {INT_MAX, -1};
            if(high<l || low>h){
                return {INT_MAX, -1};
            }
            else if(low>=l && high<=h){
                return {sgt[index], it[index]};
            }
            int mid = (low + high)/2;
            auto left = query(2*index+1,low,mid,l,h);
            auto right = query(2*index+2,mid+1,high,l,h);
            if(left.first <= right.first) return left;
            else return right;
        }

    };

class Solution {
public:
    string robotWithString(string s) {
        SGT seg(s.length()+1);
        vector<int> a(s.length());
        for(int i = 0;i<s.length();i++){
            a[i] = s[i]-'a';
        }
        seg.build(0, 0, s.length()-1, a);
        stack<int> st;

        string ans = "";
        for(int i = 0;i<s.length();i++){
            auto [c, index] = seg.query(0, 0, s.length()-1, i, s.length()-1);
            while(!st.empty() && st.top() <= c){
                ans += (st.top() + 'a');
                st.pop();
            }
            st.push(a[i]);
        }
        while(!st.empty()){
            ans += (st.top() + 'a');
            st.pop();
        }
        return ans;
    }
};