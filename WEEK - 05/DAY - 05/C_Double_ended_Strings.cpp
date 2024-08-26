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
    string a,b; cin >> a >> b;

    if(a==b){
        cout << 0 << endl;
        return;
    }

    ll sum_len=a.size()+b.size();
    ll mx_sm=0;
    if(b.size()>a.size()) swap(a,b);

    char f,l;
    for(int x=0; x<a.size(); x++){
        ll cnt=0;

        for(int y=0; y<b.size(); y++){
            ll in=x;
            ll ii=y;
            if(a[x]==b[y]){
                while(a[in]==b[ii] && in<a.size() && ii<b.size()){
                    
                    cnt++;
                    in++;
                    ii++;
                }
                // if(cnt>=mx_sm){
                //     f=a[x];
                //     l=a[in-1];
                // }
                mx_sm=max(mx_sm, cnt);
                cnt=0;
            }
        }


    }
    debug(sum_len, mx_sm);
    cout << sum_len-(mx_sm*2) << endl;

    
}

int main(){
    // error_txt();
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}