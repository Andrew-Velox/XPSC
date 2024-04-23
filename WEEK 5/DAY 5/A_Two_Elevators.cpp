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
    ll a,b,c; cin >> a >> b >> c;

    ll frm_a=abs(a-1);
    ll frm_b=(abs(b-c))+abs(c-1);

    debug(frm_a, frm_b);
    if(frm_a==frm_b) cout << 3 << endl;
    else if(frm_a<frm_b) cout << 1 << endl;
    else cout << 2 << endl;

}

int main(){
    // error_txt();
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}