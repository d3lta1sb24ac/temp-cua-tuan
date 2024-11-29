#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, a, b) for(int i = a; i <= b; i++)

const int N=1e5;
int n;
ll s[N+1][18];//log2 cua 1e5 bang 17;
ll a[N+1];
ll LOG2(ll n)
{
    int res = 0;
    while ((1 << res) <= n) {res++;}
    return res - 1;
}

ll merge(ll a,ll b){return min(a,b);}
void spr(){
    FOR(i,1,n)s[i][0]=a[i];
    FOR(j,1,LOG2(n)){
        for(ll i = 1; i + (1 << j) - 1 <= n; i ++){s[i][j] = merge(s[i][j - 1], s[i + (1 << (j - 1))][j - 1]);}
    }
}
ll get(int l,int r){
    ll k = LOG2(r - l + 1);
    return merge(s[l][k], s[r - (1 << k) + 1][k]); 
}
int main(){
    return ;
}