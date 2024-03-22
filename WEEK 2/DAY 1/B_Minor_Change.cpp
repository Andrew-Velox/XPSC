#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

void solve(){
    string a,b;
    cin >> a >>b;

    ll cnt=0;
    ll sz=a.size();
    for(int x=0; x<sz;x++){
        if(a[x]!=b[x]) cnt++;
    }

    cout << cnt << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t=1;// cin >> t;
    while(t--) solve();
    return 0;
}