class Solution {
public:

    map<vector<int>,bool> mp;
    void f(int indx, vector<vector<int>> &ans, vector<int> &a,vector<int> &v,int &t,int len,int sum){

        if(sum==t){
            if(!mp[a]){
                ans.push_back(a);
                mp[a]=true;
                return;
            }
        }
        if(sum>t || indx==len) return;

        for(int x=indx; x<len; x++){
            if(x>indx && v[x]==v[x-1]) continue;
            a.push_back(v[x]);
            sum+=v[x];
        
            f(x+1,ans,a,v,t,len,sum);
            a.pop_back();
            sum-=v[x];
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& v, int t) {
        vector<vector<int>> ans;
        vector<int> a;
        int len = v.size();
        int sum=0;
        sort(v.begin(),v.end());

        f(0,ans,a,v,t,len,0);
        return ans;
    }
};