#include <bits/stdc++.h>
#define ll long long
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define endl "\n"
using namespace std;

const int N=1e5+10;


void solve(){

    ll len,dif;
    cin >> len >> dif;

    vector<ll> v(len),f_cnt;
    f_cnt.resize(N,0);


    for(int x=0; x<len; x++){
        cin >> v[x];
        // f_cnt[v[x]]++;
    }

    // for(int x=0; x<len; x++) cout << f_cnt[v[x]] << " ";

    ll i=0,j=0,ans=0,cnt=0;

    ll lj=0;
    while(j<len){
        f_cnt[v[j]]++;
        if(f_cnt[v[j]]==1) cnt++;

        if(cnt<=dif){
            ans+=j-i+1;

        }

        else if(cnt>dif){
            while(i<j && cnt>dif){
                f_cnt[v[i]]--;
                if(f_cnt[v[i]]==0) cnt--;
                i++;
            }

            if(cnt==dif) ans+=j-i+1;
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