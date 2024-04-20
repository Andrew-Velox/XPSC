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
    ll n; cin >> n;

    if(n==1){
        cout << 0 << " " << 1 << endl;
        return;
    }

    ll a,b;

    ll tmp=1,i=0;\
    bool f=false;
    while(tmp<=n){
        a=tmp;
        tmp=(1<<i);
        i++;
    }
    b=n^a;
    if(b<a) swap(b,a);
    cout << a << " " << b << endl;



    // n = 10
    // ll msb=__lg(n); // msb=3  
    // ll b=1<<msb; // (1<<3) = 1000 => 8
    // ll a=n^b; // a = n^b => 2
    // cout << a <<" "<< b << endl;

   
}

int main(){
    // error_txt();
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}