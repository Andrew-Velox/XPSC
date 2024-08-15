class Solution {
public:

    bool isPalindrome(string &s, int i,int j){
        while(i<=j){
            if(s[i++]!=s[j--]){
                return false;
            }
        }
        return true;
    }

    void f(int indx,vector<vector<string>> &ans,int &len, vector<string> &a, string &s){
        if(indx==len){
            ans.push_back(a);
            return;
        }

        for(int x=indx; x<len; x++){
            if(isPalindrome(s,indx,x)){
                a.push_back(s.substr(indx,x-indx+1));
                f(x+1,ans,len,a,s);
                a.pop_back();
            }
        }
    }


    vector<vector<string>> partition(string s) {
        int len=s.size();
        vector<vector<string>> ans;
        vector<string> a;

        f(0,ans,len,a,s);

        return ans;
    }
};