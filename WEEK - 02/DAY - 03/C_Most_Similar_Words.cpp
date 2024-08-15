#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

void solve(){
    ll n,len;
    cin>>n>>len;

    vector<string> s(n);
    for(int x=0; x<n; x++) cin >> s[x];

    ll ans=INT_MAX;

    for(int x=0; x<n-1; x++){
        for(int y=x+1; y<n; y++){
            ll cnt=0;
            for(int z=0; z<len; z++){
                cnt+=abs((s[x][z]-'a'+1)-(s[y][z]-'a'+1));
            }

            // cout << s[x] << " " << s[y] << endl;
            // cout << cnt << " ";
            ans=min(ans,cnt);
        }
    }

    cout << ans <<endl;


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; cin >> t;
    while(t--) solve();
    return 0;
}