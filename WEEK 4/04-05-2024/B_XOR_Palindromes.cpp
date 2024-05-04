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
    string s; cin >> s;

    ll cnt=0;
    ll cnt2=0;
    ll l=0,r=len-1;
    while(l<r){
        if(s[l]==s[r]) cnt++;
        else cnt2++;
        l++;
        r--;
    }
    ll match=cnt*2;
    ll nt_match=cnt2;

    // debug(match, nt_match);
    string ans="";
    for(int x=0; x<=len; x++){
        if(x<nt_match) ans+='0';
        else{
            ll get=x-nt_match;
            if(get==1 && len%2==1 || get==0) ans+='1';
            else if(get==1 && len%2==0) ans+='0';
            else{
                if(get<=match){
                    if(get<=match && get%2==0 || get%2==1 && len%2==1) ans+='1';
                    else ans+='0';
                }
                else if(get-match==1 && len%2==1) ans+='1';
                else ans+='0';
                // debug(x,m,ans);
            }
        }
    }

    cout << ans << endl;
    
}

int main(){
    // error_txt();
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}