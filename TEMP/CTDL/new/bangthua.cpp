#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, a, b) for(int i = a; i <= b; i++)

const int N=1e5;
const int Nlog=__lg(N)+1;
int n;
ll s[N+1][Nlog];
ll a[N+1];
ll merge(ll a,ll b){return min(a,b);}
void spr(){
    FOR(i,1,n)s[i][0]=a[i];
    FOR(j,1,__lg(n)){
        for(ll i = 1; i + (1 << j) - 1 <= n; i ++){s[i][j] = merge(s[i][j - 1], s[i + (1 << (j - 1))][j - 1]);}
    }
}
ll get(int l,int r){
    ll k = __lg(r - l + 1);
    return merge(s[l][k], s[r - (1 << k) + 1][k]); 
}
int main(){
    return 0;
}