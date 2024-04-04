#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define srt(v) sort(v.begin(),v.end())
#define grtsrt(v) sort(v.begin(),v.end(),greater<ll>())
#define rev(v) reverse(v.begin(),v.end());
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define endl "\n"
#define fx(x) fixed<<setprecision(x)

#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<":- "<<x<<" "<< endl;
#define debug2(x,y) cerr<<#x<<":- "<<x<<" | "<<#y<<":- "<<y<<endl;
#define debug3(x,y,z) cerr<<#x<<":- "<<x<<" | "<<#y<<":- "<<y<<" | "<<#z<<":- "<<z<<endl;
#else
#define debug(x)
#define debug(x,y)
#define debug(x,y,z)
#endif

void error_txt(){
    #ifndef ONLINE_JUDGE
    freopen("error.txt","w",stderr);
    #endif
}
void speed(){
    cin.tie(NULL);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}



void solve(){
    
    ll len; cin >> len;

    vector<ll> v(len);
    ll sum=0;
    for(int x=0; x<len; x++){
        cin >> v[x];
        sum+=abs(v[x]);
    }

    ll ans=0,l=0,r=0;

    while(r<len){
        if(v[r]<0){
            ans++;
            while(r<len && v[r]<=0){
                r++;
            }
            l=r;
            continue;
        }
        r++;
    }


    cout << sum << " " << ans << endl;

}

int main(){
    // error_txt();
    speed();
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}