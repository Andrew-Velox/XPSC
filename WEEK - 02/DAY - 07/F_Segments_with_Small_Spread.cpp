#include <bits/stdc++.h>
#define ll long long
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define endl "\n"
using namespace std;

void solve(){
    ll len, dif;
    cin >> len >> dif;

    vector<ll> v(len);


    for(int x=0; x<len; x++) cin >> v[x];

    ll i=0,j=0,ans=0,cnt=0;
    multiset<ll> ms;

    while(j<len){
        ms.insert(v[j]);

        ll mn,mx;
        mn = *ms.begin();
        mx = *ms.rbegin();

        if(mx-mn<=dif) ans+=(j-i+1);

        else{
            while(i<j){
                mn = *ms.begin();
                mx = *ms.rbegin();

                if (mx-mn<=dif) break;
                
                auto it = ms.find(v[i]);
                ms.erase(it);
                i++;
            }


            mn = *ms.begin();
            mx = *ms.rbegin();

            if(mx - mn<=dif) ans+=(j-i+1);
            
        }
        j++;
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