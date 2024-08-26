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

const int N = 1e9;


void solve(){
    ll len; cin >> len;

    ll n=(len*(len-1))/2;
    vector<ll> v(n);
    for(int x=0; x<n; x++) cin >> v[x];


    srt(v);
    ll in=len;
    vector<ll> ans;
    for(int x=0; x<n; x+=in){
        ans.push_back(v[x]);
        debug(x, in);
        in--;
    }
    ans.push_back(N);


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