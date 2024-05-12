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

    string s="";
    s+="1";

    bool f_fst=false;
    ll tmp=v[0];
    for(int x=1; x<len; x++){
        if(v[x] >= tmp && !f_fst){
            s+='1';
            tmp=v[x];
        } 
        else if(v[x] < v[x-1] && v[x]<=v[0] && !f_fst){
            s+='1';
            f_fst=true;
            tmp=v[x];
        }
        else if(f_fst && v[x] <= v[0] && v[x]>=tmp){
            s+='1';
            tmp=v[x];
        }
        else s+='0';
    }


    cout << s << endl;
    
}

int main(){
    // error_txt();
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}