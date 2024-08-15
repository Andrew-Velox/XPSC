//User function template for C++
#define ll long long

class Solution{
  public:
    int longestKSubstr(string s, int dif) {
    // your code here
    
    ll i=0,j=0,ans=-1,cnt=0;
    ll len=s.size();
    map<char,int> mp;
    while(j<len){
        mp[s[j]]++;
        if(mp[s[j]]==1) cnt++;

        if(cnt==dif){
            ans=max(ans,j-i+1);

            // cout << ans << endl;

        }

        else if(cnt>dif){
            while(i<j && cnt>dif){
                mp[s[i]]--;
                if(mp[s[i]]==0) cnt--;
                i++;
            }

            if(cnt==dif) ans=max(ans,j-i+1);
        }

        j++;

    }

    return ans;
    
    }
};