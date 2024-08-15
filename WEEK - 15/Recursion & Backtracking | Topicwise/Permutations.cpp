class Solution {
public:

    void permutation(vector<vector<int>> &ans, vector<int> &a,int len , vector<int> &v, int cnt[]){

        if(len==a.size()){
            ans.push_back(a);
            return;
        }

        for(int x=0; x<len; x++){
            if(cnt[x]==0){
                a.push_back(v[x]);
                cnt[x]=1;

                permutation(ans,a,len,v,cnt);

                a.pop_back();
                cnt[x]=0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int len=nums.size();

        vector<vector<int>> ans;
        vector<int> a;
        int cnt[len];

        for(int x=0; x<len; x++) cnt[x]=0;

        permutation(ans,a,len,nums,cnt);

        return ans;
    }
};