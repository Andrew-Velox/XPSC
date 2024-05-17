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
    ll len,tk; cin >> len >> tk;
    vector<ll> v(len);

    for(int x=0; x<len; x++) cin >> v[x];

    vector<ll> pos,neg;

    for(int x=0; x<len; x++){
        if(v[x]>0) pos.push_back(v[x]);
        else neg.push_back(abs(v[x]));
    }

    grtsrt(pos);
    grtsrt(neg);
    ll sp=0,sn=0;
    
    for(int x=0; x<pos.size(); x+=tk) sp+=pos[x]*2;
    for(int x=0; x<neg.size(); x+=tk) sn+=neg[x]*2;

    ll ans=sp+sn;
    if(pos.size()!=0 && neg.size()!=0) ans-=max(pos[0],neg[0]);
    else if(pos.size() > neg.size()) ans-=pos[0];
    else ans-=neg[0]; 
    

    cout << ans << endl;
    debug(sp,sn);


   
    
}

int main(){
    // error_txt();
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}