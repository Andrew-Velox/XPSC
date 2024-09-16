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


const int N=1e4+5;

void solve(){
    ll n; cin >> n;
    

    bool f=false;
    for(int x=1; x<=N; x++){

        if(pow(x,3)>=n) break;


        ll l=0,r=N;
        while(l<=r){
            ll mid=l+(r-l)/2;

            if(mid*mid*mid == n-(pow(x,3))){
                f=true;
                break;
            }
            else if(mid*mid*mid > n-(pow(x,3))){
                r=mid-1;
            }
            else l=mid+1;
        }
        if(f) break;
    }
    
    if(f) YES;
    else NO;
}

int main(){
    // error_txt();
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}