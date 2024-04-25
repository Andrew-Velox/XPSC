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
    map<ll,ll> mp;


    for(int x=0; x<len; x++){
        cin >> v[x];
        mp[v[x]]=x;
    }

    bool f=false;
    ll fst,mid,lst;

    for(int x=1; x<len-1; x++){
        if(v[x-1]< v[x] && v[x+1]< v[x]){
            fst=x-1;
            mid=x;
            lst=x+1;
            f=true;
            break;
        }
        
    }
    
    if(f){
        YES;
        cout << fst+1 << " " << mid+1 << " " << lst+1 << endl;
    }
    else NO;
    
}

int main(){
    // error_txt();
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}