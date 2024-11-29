#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using mi = map<ll, ll>;


#define FOR(i, a, b) for(int i = a; i <= b; i++)

const int N=1e6;

ll a[N+1];
ll b[N+1];
mi c;
int n;
void nenso(){
    FOR(i,1,n)b[i]=a[i];
    sort(b+1,b+1+n);
    int cur=1;c[b[1]]=1;
    FOR(i,2,n){if(b[i]!=b[i-1])c[b[i]]=++cur;}
}
int main(){
    return 0;
}