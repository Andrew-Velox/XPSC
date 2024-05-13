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

    string t=s;

    ll tmp;
    ll len=s.size();
    vector<ll> v(len);
    vector<ll> mk(len,0);

    ll cnt_1=0;
    ll cnt_0=0;
    for(int x=0; x<len; x++){
        if(s[x]=='1'){
            v[x]=1;
            cnt_1++;
            mk[x]=1;
        }
        else{
            v[x]=0;
            mk[x]=0;
            cnt_0++;
        }
    }


    for(int x=0; x<len; x++){
        if(v[x]==0 && cnt_1!=0){
            mk[x]=1;
            cnt_1--;
        }
        else if(v[x]==1 && cnt_0!=0){
            mk[x]=0;
            cnt_0--;
        }
    }

    ll ans=0,in=0;
    for(int x=0; x<len; x++){
        if(v[x]==mk[in]){
            while(v[x]==mk[in] &&  in<len){
                ans++;
                in++;
            }
        }
        in++;
        if(in>=len) break;
    }


    cout << ans << endl;


    debug(v);
    debug(mk);

    // bool f=true;
    // for(int x=0; x<len; x++){
    //     if(f){
    //         tmp=x;
    //         f=false;
    //     }
    //     if(s[tmp] != s[x]){
    //         swap(s[tmp],s[x]);
            
    //     }
    // }
    
}

int main(){
    // error_txt();
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}