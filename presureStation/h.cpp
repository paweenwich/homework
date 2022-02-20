#include<bits/stdc++.h>
using namespace std;
int a[101000];
struct node {
    int val,last;
    node(int a,int b) : val(a),last(b) {}
    bool operator<(const node &a) const {
        return val>a.val || (val==a.val && last>a.last);
    }
};
priority_queue<node> pq;
int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    int ans=1<<30;
    for(int i=1; i<=n; i++) {
        int val;
        scanf("%d",&val);
        if(i<=k+1)
            pq.push(node(val,i));

        while(!pq.empty() && (pq.top()).last<i-k*2-1) {
            if(pq.top().last>=n-k)
                ans=min(ans,pq.top().val);
            pq.pop();
        }

        if(!pq.empty())
            pq.push(node((pq.top()).val+val,i));

    }
    while(!pq.empty()) {
        if(pq.top().last>=n-k)
            ans=min(ans,pq.top().val);
        pq.pop();
    }
    printf("%d",ans);
}
