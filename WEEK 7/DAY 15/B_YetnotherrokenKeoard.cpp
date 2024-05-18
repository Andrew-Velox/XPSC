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

    ll choto_b=0,boro_b=0;
    rev(s);
    string ans="";
    for(int x=0; x<s.size(); x++){
        if(s[x]=='B') boro_b++;
        else if(s[x]=='b') choto_b++;
        else{
            if(s[x]>='a' && s[x]<='z' && choto_b>0) choto_b--;
            else if(s[x]>='a' && s[x]<='z' && choto_b==0) ans+=s[x];
            else if(s[x]>='A' && s[x]<='Z' && boro_b>0) boro_b--;
            else if(s[x]>='A' && s[x]<='Z' && boro_b==0) ans+=s[x];
        }
    }

    rev(ans);
    cout << ans << endl;
    
}

int main(){
    // error_txt();
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}