#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const int N=1e5;

ll st[N*4+1];
ll a[N+1];
ll merg(ll u,ll v){return u+v;}
void build(int id,int l,int r){
    if(l==r)
    {
        st[id]=a[l];
        return;
    }
    ll mid = (l + r) >> 1;
    build(id << 1,l,mid);build(id<<1|1,mid+1,r);
    st[id]=merg(st[id<<1],st[id<<1|1]);

}
void upd(int id,int l,int r,ll pos,ll val){
    if (l > pos || r < pos) return;
    if(l==r)
    {
        st[id]=val;
        return;
    }
    ll mid = (l + r) >> 1;
    upd(id << 1,l,mid,pos,val);upd(id<<1|1,mid+1,r,pos,val);
    st[id]=merg(st[id<<1],st[id<<1|1]);
}
ll get(int id,int l,int r,int u,int v){
    if(l>v||r<u)return 0;
    if(l>=u&&r<=v)return st[id];
    ll mid = (l + r) >> 1;
    return merg(get(id << 1,l,mid,u,v),get(id<<1|1,mid+1,r,u,v));
}

int main(){
    return 0;
}