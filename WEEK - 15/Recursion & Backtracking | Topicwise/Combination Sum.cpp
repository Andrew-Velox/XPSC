class Solution {
public:

    map<vector<int>,bool> mp;

    void f(int indx, vector<vector<int>> &ans, vector<int> &a,vector<int> &v,int &t,int len,int sum){
        
        if(sum>t || indx==len){
            return;
        }
        if(sum==t){
            if(!mp[a]){
                ans.push_back(a);
                mp[a]=true;
                return;
            }
        }
        for(int x=indx; x<len; x++){
            a.push_back(v[x]);
            sum+=v[x];
            f(x+1,ans,a,v,t,len,sum);
            a.pop_back();
            sum-=v[x];
            a.push_back(v[x]);
            sum+=v[x];
            f(x,ans,a,v,t,len,sum);
            a.pop_back();
            sum-=v[x];


        }
    }


    vector<vector<int>> combinationSum(vector<int>& v, int t) {
        vector<vector<int>> ans;
        vector<int> a;
        int len = v.size();
        int sum=0;
        sort(v.begin(),v.end());
        f(0,ans,a,v,t,len,0);

        return ans;
    }
};