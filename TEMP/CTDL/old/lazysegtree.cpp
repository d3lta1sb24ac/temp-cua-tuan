#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N=1e5;

ll a[N+1];
struct LZst{ll lz;ll val;}ST[N*4+1];
void down(int id,ll l, ll r){

    if(ST[id].lz==0)return;
    int t=ST[id].lz;
    ST[id].lz = 0;
    ST[id<<1].lz += t;
    ST[id<<1].val += t;
    ST[id<<1|1].lz += t;
    ST[id<<1|1].val += t;
}
ll merg(ll u,ll v){return max(u,v);}
void build(int id,int l,int r){
    if(l==r)
    {
        ST[id].val=a[l];
        //ST[id].lz=0;
        return;
    }
    //down(id);
    ll mid = (l + r) >> 1;
    build(id << 1,l,mid);build(id<<1|1,mid+1,r);
    ST[id].val=merg(ST[id<<1].val,ST[id<<1|1].val);

}
void upd(int id,int l,int r,int u,int v,ll val){
    if (l > v || r < u) return;
    if(u<=l&&r<=v)
    {
        ST[id].val+=val;
        ST[id].lz+=val;
        return;
    }
    down(id,l,r);
    ll mid = (l + r) >> 1;
    upd(id << 1,l,mid,u,v,val);upd(id<<1|1,mid+1,r,u,v,val);
    ST[id].val=merg(ST[id<<1].val,ST[id<<1|1].val);
}
ll get(int id,int l,int r,int u,int v){
    if(l>v||r<u)return -1e9;
    if(l>=u&&r<=v)return ST[id].val;
    ll mid = (l + r) >> 1;
    down(id,l,r);
    return merg(get(id << 1,l,mid,u,v),get(id<<1|1,mid+1,r,u,v));
}
int main(){
    return 0;
}
