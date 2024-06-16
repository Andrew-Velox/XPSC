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
#define gcd(x,y) __gcd(x,y)
#define lcm(x,y) ((x/gcd(x,y))*y)
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define endl '\n'
#define fx(x) fixed<<setprecision(x)

void error_txt(){
    #ifdef velox
    freopen("error.txt","w",stderr);
    #endif
}


bool isPrime(ll val){
    if(val==1) return true;

    for(int x=2; x*x<=val; x++){
        if(val%x==0)return false;     
    }

    return true;
}


void solve(){
    ll n; cin >> n;

    if(n==2) cout << 1 << endl;
    else if(n%2==0) cout << 2 << endl;
    else if(isPrime(n)) cout << 1 << endl;
    else if(n%2==1){
        if(isPrime(n-2)) cout << 2 << endl;
        else cout << 3 << endl;
    }
    
}

int main(){
    // error_txt();
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll t=1; //cin >> t;
    while(t--) solve();
    return 0;
}