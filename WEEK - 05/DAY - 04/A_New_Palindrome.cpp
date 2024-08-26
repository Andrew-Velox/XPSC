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
    string s; cin >> s;

    map<char,ll> mp;
    map<char,bool> ltr;
    for(int x=0; x<s.size(); x++){
        mp[s[x]]++;
        if(ltr[s[x]]==false) ltr[s[x]]=true;
    }

    ll cnt=0;
    bool f=false;
    
    for(int x='a'; x<='z'; x++){
        if(mp[x]==1){
            f=true;
        }
        if(ltr[x]==true) cnt++;
    }

    if(cnt==1 || f && cnt==2) NO;
    else YES;


    
}

int main(){
    // error_txt();
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}