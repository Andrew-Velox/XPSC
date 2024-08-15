#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

void solve(){
    ll len1,len2;
    cin >> len1 >> len2;
 
    vector<int> v1(len1),v2(len2);
 
    for(int x=0; x<len1; x++) cin >> v1[x];
    for(int x=0; x<len2; x++) cin >> v2[x];
    
    int l=0,r=0;
 
    
    ll cnt=0;
    for(int x=0; x<len2; x++){
        while(v1[l]<v2[r] && l<len1){
            cnt++;
            l++;
        }
        r++;
 
        cout << cnt << " ";
    }
 
    cout << endl;
}
 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t=1;// cin >> t;
    while(t--) solve();
    return 0;
}
