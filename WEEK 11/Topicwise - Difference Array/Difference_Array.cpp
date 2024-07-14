#include <bits/stdc++.h>
#define ll long long
using namespace std;
#ifdef velox
#include "debug.h"
#else
#define debug(x...)
#endif

// adding values from l to r form multiple queries..__O(n)__

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    ll n=5,q=3;
    vector<ll> v = {0,2,5,1,8,13}; // taking input from index 1, i'm initially adding 0 at first,

    vector<ll> dif_array(n+2); // difference array size will be n+2
    // queries are...[1 3 4],[2 5 7],[1 5 2]
    while(q--){
        ll l,r,val;
        cin >> l >> r >> val;

        dif_array[l] += val; // l -> + (add)
        dif_array[r+1] -= val; // r+1 -> -(subtract)
    }

    debug(dif_array); // dif_array = {0,6,7,-4,0,-9,0}
    
    // Now make the prifix sum of dif_array
    for(int x=1; x<=n; x++){
        dif_array[x]=dif_array[x-1]+dif_array[x];
    }
    debug(dif_array); // dif_array = {0,6,13,9,9,-9,0}

    // Now make the final Answer
    for(int x=1; x<=n; x++){
        cout << v[x]+dif_array[x] << " "; // 8 18 14 17 22
    }
    cout << endl;
    
    return 0;
}