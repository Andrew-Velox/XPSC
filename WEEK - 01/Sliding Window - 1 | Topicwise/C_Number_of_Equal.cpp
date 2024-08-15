#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;


void solve(){
    ll a,b; cin >> a>>b;

    vector<ll> v1(a+1),v2(b+1);
    for(ll x=0; x<a; x++) cin >> v1[x];
    for(ll x=0; x<b; x++) cin >> v2[x];

    ll l=0,r=0;

    ll ans=0;
    ll cnt1=0,cnt2=0;

    while(l<a && r<b){
        if(v1[l]==v2[r]){
            while(l<a && r< b && v1[l]==v2[r]){
                cnt1++;
                l++;
            }
            ans+=cnt1;
            r++;
            while(l>0 && v1[l-1]==v2[r] && r<b){
                ans+=cnt1;
                r++;
            }
            cnt1=0;

        }
        else{
            if(v1[l]<v2[r]) l++;
            else r++;
        }
    }

    cout << ans << endl;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t=1;// cin >> t;
    while(t--) solve();
    return 0;
}
