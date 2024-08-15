#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

void solve(){
    ll a,b,k;
    cin >> a >>b >>k;

    if(k%a==0 || k%b==0) cout << "Yes" << endl;
    else{

        bool flag=false;
        for(int x=0; x*a<=k; x++){
            for(int y=0;y*b<=k;y++){
                if((x*a)+(y*b)==k){
                    flag=true;
                    break;
                }
            }
        }

        if(flag) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t=1;// cin >> t;
    while(t--) solve();
    return 0;
}