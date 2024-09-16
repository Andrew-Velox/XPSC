#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'


void solve(){
    
    
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll len; cin >> len;
    ll hv; cin >> hv;

    vector<ll> v(len);
    for(int x=0; x<len; x++) cin >> v[x];

    sort(v.begin(),v.end());

    auto ok = [&](ll mid){
        ll cnt=0;
        for(ll x=len/2; x<len; x++){
            if(mid>v[x]) cnt+=mid-v[x];
            if(cnt>hv) return false;
        }
        
        return cnt<=hv;
    };

    ll l=0,r=2e9;
    ll ans=0;
    while(l<=r){
        ll mid = l+(r-l)/2;

        if(ok(mid)){
            ans = mid;
            l=mid+1;
        }
        else r = mid-1;
    }


    cout << ans << endl;

    return 0;
}