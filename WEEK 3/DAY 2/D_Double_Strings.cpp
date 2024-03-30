#include <bits/stdc++.h>
#define ll long long
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define endl "\n"
using namespace std;

void solve(){
    ll len; cin >> len;

    multiset<string> ms;
    vector<string> s;
    map<string,int> mp;
    for(int x=0; x<len; x++){
        string tk; cin >> tk;
        s.push_back(tk);
        mp[tk]++;
        ms.insert(tk);
    }




    // for(auto val: ms) cout << val << endl;

    string ans="";


    int i=0,j=0;
    for(int x=0; x<len; x++){
        string get="";
        ll s_len=s[x].size();
        bool f=false;
 
        for(int y=0; y<s_len; y++){
            get+=s[x][y];


            // if(mp[get]!=0 && y==s_len-1){
            //     f=false;
            // }
            if(mp[get]!=0 && y!=s_len-1){
                // hlf_f=true;
                string lst="";
                lst+=s[x].substr(y+1,s_len);

                // cout << lst << endl;
                if(mp[lst]!=0){
                    f=true;
                    break;
                }
            }

        }
        if(f){
            ans+="1";
        }
        else{
            ans+="0";
        }
        
    }

    cout << ans << endl;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; cin >> t;
    while(t--) solve();
    return 0;
}