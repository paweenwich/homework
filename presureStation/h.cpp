#include<bits/stdc++.h>
using namespace std;
//int [101000];
struct node {
    int val,last;
    node(int a,int b) : val(a),last(b) {}
    bool operator<(const node &a) const {
        return val>a.val || (val==a.val && last>a.last);
    }
    void show() const {
        cout << "[" << val << "," << last << "]";
    }
};
priority_queue<node> pq;
void dumpq(priority_queue<node> temp){
    while (!temp.empty()) {
        temp.top().show();
        temp.pop();
    }
    cout << "\n";
}
int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    int ans=1<<30;
    for(int i=1; i<=n; i++) {
        int val;
        scanf("%d",&val);
        cout<< "start " << i << " val=" << val ; dumpq(pq);
        if(i<=k+1)
            pq.push(node(val,i));

        while(!pq.empty() && (pq.top()).last<i-k*2-1) {
            if(pq.top().last>=n-k){
                int oldAnds = ans;
                ans=min(ans,pq.top().val);
                cout<< " ans=" << oldAnds << "->" << ans << "\n"; 
            }
            cout << " pop "; pq.top().show(); cout << "\n";//dumpq(pq);
            pq.pop();
            
        }

        if(!pq.empty()){
            pq.push(node((pq.top()).val+val,i));
        }

        cout << "end "; dumpq(pq);

    }
    while(!pq.empty()) {
        if(pq.top().last>=n-k){
            int oldAnds = ans;
            ans=min(ans,pq.top().val);
            cout<< " "  << n-k << " ";  pq.top().show(); cout << " ans=" << oldAnds << "->" << ans << "\n"; 
        }
        pq.pop();
    }
    printf("%d",ans);
}
