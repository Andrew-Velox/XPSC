class Solution {
public:

    map<vector<int>, bool> mp;
    void f(int ind, vector<vector<int>> &ans, vector<int> &a,vector<int> &v, int len){
        

        if(!mp[a]){
            ans.push_back(a);
            mp[a]=true;
        }

        if(ind>=len){
            return;
        }

        for(int x=ind; x<len; x++){
            a.push_back(v[x]);
            f(x+1,ans,a,v,len);
            a.pop_back();
        }

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> a;
        int len=nums.size();
        sort(nums.begin(),nums.end());

        f(0,ans,a,nums,len);
        return ans;
    }
};