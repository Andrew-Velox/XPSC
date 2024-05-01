#include <bits/stdc++.h>
using namespace std;

#ifdef velox
#include "debug.h"
#else
#define debug(x...)
#endif

#define ll long long
#define srt(v) sort(v.begin(),v.end())
#define grtsrt(v) sort(v.begin(),v.end(),greater<ll>())
#define unq(v) v.erase(unique(v.begin(),v.end()),v.end())
#define rev(v) reverse(v.begin(),v.end())
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define endl '\n'
#define fx(x) fixed<<setprecision(x)

void error_txt(){
    #ifdef velox
    freopen("error.txt","w",stderr);
    #endif
}



void solve(){
    ll len; cin >> len;
    vector<ll> v(len);
    for(int x=0; x<len; x++) cin >> v[x];

    map<ll,ll> mp;
    for(int x=0; x<len; x++){
        for(int y=0; y<32; y++){
            if((1<<y) & v[x]) mp[y]++;
        }
    }

    vector<ll> ans;
    for(int x=1; x<=len; x++){
        bool f=true;

        for(int y=0; y<32; y++){
            if(mp[y]%x){
                f=false;
                break;
            }
            else{
                debug(mp[y], x, y);
            }
        }
        if(f) ans.push_back(x);

    }

    for(auto val: ans) cout << val << " ";
    cout << endl;
    
}

int main(){
    // error_txt();
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}