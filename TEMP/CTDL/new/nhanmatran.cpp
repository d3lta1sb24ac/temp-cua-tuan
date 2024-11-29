#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, a, b) for(int i = a; i <= b; i++)

const int Z=2;
const ll Mod=1e9+7;
struct mtrx{ ll m[Z][Z]; };
mtrx mul(mtrx a,mtrx b){
    mtrx ans;
    FOR(i,0,Z-1)
    {
        FOR(j,0,Z-1){
            FOR(k,0,Z-1){ans.m[i][j]=0,(ans.m[i][j]+=(a.m[i][k] % Mod) * (b.m[k][j] % Mod))%=Mod;}
        }
    }
    return ans;
}
mtrx mpw(mtrx base,ll exp){
    mtrx ans;
    FOR(i,0,Z-1){
        FOR(j,0,Z-1){ans.m[i][j] = (i == j);}   
    }              
    while (exp) {      
        if (exp & 1)                   
        ans = mul(ans, base);                                
        base = mul(base, base);                           
        exp>>= 1;                                               
    }
    return ans;
}
int main(){
    return 0;
}