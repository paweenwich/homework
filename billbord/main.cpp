#include <bits/stdc++.h>
using namespace std;
void dumpVector(vector<int> v){
    for(auto i:v){
        cout << i << " ";
    }
    cout << "\n";
}
void dumpSet(set<int> v){
    for(auto i:v){
        cout << i << " ";
    }
    cout << "\n";
}

string vecToStr(vector<int> v){
    string ret;
    for(auto i:v){
        ret += to_string(i) + "_";
    }
    return ret;
}

int countProc = 0;
int ans = 0;
int targetSize;
map<int,int> cache;
vector<int> tile;
vector<int> possibleSize;
set<vector<int>> possibleTile;
void genPossibleSize(int size){
    possibleSize.clear();
    for(int i=1;i<= sqrt(size) + 1;i++){
        //cout << i*i << " " << size << "\n";
        if(i*i < size){
            possibleSize.push_back(i);
        }
    }
}


void genPossibleTile(int size,vector<int> &tiles){
    countProc++;
    if(size!=0){
        cache[size]++;
    }
    if((size == 0) && (tiles.size() == tile.size())){
        vector<int> tmp = tiles;
        sort(tmp.begin(),tmp.end());
        possibleTile.insert(tmp);
        return;
    }
    if(tiles.size() < tile.size()){
        for(int i=0;i<possibleSize.size();i++){
            if(possibleSize[i]*possibleSize[i] <= size){
                tiles.push_back(possibleSize[i]);
                genPossibleTile(size - (possibleSize[i]*possibleSize[i]),tiles);
                tiles.pop_back();
            }else{
                break;
            }
        }        
    }
}

map<int,set<vector<int>>> cache2;
set<vector<int>> genPossibleTile2(int size){
    //cout << indent << " genPossibleTile2 " << size  << "\n";
    countProc++;
    auto it = cache2.find(size);
    if(it!=cache2.end()){
        return it->second;
    }
    
    set<vector<int>> ret;
    for(int i=0;i<possibleSize.size();i++){
        if(possibleSize[i]*possibleSize[i] <= size){
            if(size - (possibleSize[i]*possibleSize[i])>0){
                set<vector<int>> tmp =  genPossibleTile2(size - (possibleSize[i]*possibleSize[i]));
                for(auto t: tmp){
                    if(t.size()+1 <= tile.size()){
                        t.push_back(possibleSize[i]);
                        sort(t.begin(),t.end());
                        ret.insert(t);
                    }
                }
            }else{
                vector<int> t;
                t.push_back(possibleSize[i]);
                ret.insert(t);
            }
        }else{
            break;
        }
    }      
    cache2[size] = ret;
    return ret;
}

pair<vector<int>,int> bestMatch(vector<int> &v1,vector<int> &v2){
    pair<vector<int>,int> ret;
    if(v1.size()==v2.size()){
        int cost =0;
        for(int i=0;i<v1.size();i++){
            cost += (v1[i] - v2[i])*(v1[i] - v2[i]);
        }
        ret.first = v2;
        ret.second = cost;
        return ret;
    }
    /*ret.second = INT_MAX;
    for(int i=0;i<v1.size();i++){
        vector<int> tmp = v1;
        tmp.erase(tmp.begin());
        auto r = bestMatch(tmp,v2);
        if(r.second < ret.second){
            ret = r;
        }
    }*/
    return ret;

}

struct node {
    int val,last;
    node(int a,int b) : val(a),last(b) {}
    bool operator<(const node &a) const {
        return val<a.val || (val==a.val && last>a.last);
    }
    void show() const {
        cout << "[" << val << "," << last << "]";
    }
};

void dumpq(priority_queue<node> temp){
    while (!temp.empty()) {
        temp.top().show();
        temp.pop();
    }
    cout << "\n";
}
vector<int> vLeft;
vector<int> vRight;
vector<int> ls;
vector<int> rs;
priority_queue<node> pql;
priority_queue<node> pqr;
int maxEf(int start,int stop,vector<int> &v)
{
    //cout << "maxEf " << start << " " << stop << "\n";
    start = max(0,start);
    stop = min(stop,(int)v.size());

    auto m = max_element(v.begin()+start,v.begin()+stop);
    //cout << "vect=";dumpVector(v);
    //for(auto a = v.begin()+start;a!=v.begin()+stop;a++){
        //cout <<  *a << " ";
    //}
    //cout << "m=" << *m << "\n";
    return *m;
}


int main(int argc,char *argv[]){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,w,k;
    cin >> n >> w >> k;
    vLeft.resize(n);
    vRight.resize(n);
    ls.resize(n);
    rs.resize(n);

    for(int i=0;i<n;i++){
        cin >> vLeft[i];
        if(i<2*w -1){
            ls[i] = vLeft[i];
            pql.push({ls[i],i});
        }
    }
    for(int i=0;i<n;i++){
        cin >> vRight[i];
        if(i<2*w -1){
            rs[i] = vRight[i];
            pqr.push({rs[i],i});
        }
    }
    for(int i=2*w;i<n;i++){
        while(!pqr.empty() && pqr.top().last <= i - 2*w){
            pqr.pop();
        }
        while(!pql.empty() && pql.top().last <= i - 2*w ){
            pql.pop();
        }

        pql.push({ls[i-(2*w)],i});
        pqr.push({rs[i-(2*w)],i});
        cout << "i=" << i << "\n",
        cout << " pql="; dumpq(pql);
        cout << " pqr=";dumpq(pqr);
        
        ls[i] = vLeft[i]  + pqr.top().val;
        rs[i] = vRight[i]  + pql.top().val;

        cout << " ls="; dumpVector(ls);
        cout << " rs="; dumpVector(rs);
        

        //cout << " pql="; dumpq(pql);
        //cout << " pqr=";dumpq(pqr);

        //pqr.push({rs[i],i});
        //pql.push({ls[i],i});

        /*

        ls[i] = vLeft[i]  + maxEf(i-3*w,i-w,rs);
        rs[i] = vRight[i] + maxEf(i-3*w,i-w,ls);
        */
    }
    cout << "Left ";dumpVector(ls);
    cout << "Right ";dumpVector(rs);
    
    int maxEff = max(maxEf(n-2*w,n,ls),maxEf(n-2*w,n,rs));
    cout << maxEff << "\n";
    return 0;
}