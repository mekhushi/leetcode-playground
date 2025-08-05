class Solution {
    int n; vector<int> seg;
    void build(vector<int>& a,int idx,int l,int r){
        if(l==r){seg[idx]=a[l];return;}
        int m=(l+r)/2;
        build(a,idx*2+1,l,m);
        build(a,idx*2+2,m+1,r);
        seg[idx]=max(seg[idx*2+1],seg[idx*2+2]);
    }
    void update(int idx,int l,int r,int pos,int val){
        if(l==r){seg[idx]=val;return;}
        int m=(l+r)/2;
        if(pos<=m) update(idx*2+1,l,m,pos,val);
        else update(idx*2+2,m+1,r,pos,val);
        seg[idx]=max(seg[idx*2+1],seg[idx*2+2]);
    }
    int query(int idx,int l,int r,int target){
        if(seg[idx]<target) return -1;
        if(l==r){ update(0,0,n-1,l,-1); return l; }
        int m=(l+r)/2;
        if(seg[idx*2+1]>=target) return query(idx*2+1,l,m,target);
        return query(idx*2+2,m+1,r,target);
    }
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        n=baskets.size();
        seg.assign(4*n,0);
        build(baskets,0,0,n-1);
        int ans=0;
        for(int f:fruits)
            if(query(0,0,n-1,f)==-1) ans++;
        return ans;
    }
};
