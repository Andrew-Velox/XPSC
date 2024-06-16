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



void solve(){

    ll n,a,b,p,q;
    cin >> n >> a >> b >> p >> q;

    ll div_by_a= n/a;
    ll div_by_b= n/b;

    ll div_by_both = n/lcm(a,b);

    debug(div_by_a, div_by_b, div_by_both);

    if(p<q){
        div_by_a-=div_by_both;
        cout << div_by_a*p + div_by_b*q << endl;
    }
    else{
        div_by_b-=div_by_both;
        cout << div_by_a*p + div_by_b*q << endl;
    }
    

}

int main(){
    // error_txt();
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll t=1; //cin >> t;
    while(t--) solve();
    return 0;
}