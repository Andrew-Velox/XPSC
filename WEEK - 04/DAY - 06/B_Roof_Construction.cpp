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


ll msb(ll val){
    return log2(val); //----O(1)----//
}


void solve(){
    ll len; cin >> len;
    
    vector<ll> ans;
    if(len==2){
        cout << 0 << " " << 1 << endl;
        return;
    }
    ll cur=len-1;
    while(cur>1){
        ans.push_back(cur);
        if(msb(cur)!=msb(cur-1)) break;
        cur--;
    }
    for(int x=0; x<cur; x++) ans.push_back(x);


    for(auto val: ans) cout << val << " ";
    cout << endl;

    
    // --------cheking-----------
    // ll an=0;
    // ll a=ans[0];
    // ll tmp_a=0;
    // ll tmp_b=0;
    // for(int x=1; x<ans.size(); x++){
    //     if(a^ans[x]>an){
    //         an=max(an,a^ans[x]);
    //         tmp_a=a;
    //         tmp_b=ans[x];
    //     }
    //     a=ans[x];

    // }
    // debug(an,tmp_a,tmp_b);
    
}

int main(){
    // error_txt();
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}