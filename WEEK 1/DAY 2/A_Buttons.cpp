#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

void solve(){
    int a,b; cin >> a >> b;
    if(a==b) cout << a*2 << endl;
    else{
        if(a>b){
            ll opt1=(a*2)-1;
            ll opt2=(a-1)-(b-1);

            cout << max(opt1,opt2) << endl;
        }

        else{
            ll opt1=(b*2)-1;
            ll opt2=(a-1)-(b-1);

            cout << max(opt1,opt2) << endl;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t=1;// cin >> t;
    while(t--) solve();
    return 0;
}