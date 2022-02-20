//#pragma comment(linker, "/STACK:268435456")
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
void dumpVector(vector<int> &v){
    for(auto i:v){
        cout << i << " ";
    }
    cout << "\n";
}
/*int process(vector<int> &space,int start, int span,string indent){
    cout << indent << start << " " << space[start] << "\n";
    int cost = space[start];
    if(space.size() - start == 1){
        return cost;
    }
    int minCost = cost;
    for(int i=0;i<span+1 && i + start +1 < space.size();i++){
        //cout << indent << start + i << "\n";
        int r = process(space,start+i+1,span,indent + "  ");
        cout << indent << "r=" << r << "\n";
        if(r < minCost){
            minCost = r;
        }
    }
    return minCost;
}*/
vector<int> cost;
vector<int> cover;
//stack<vector<int>> scover;
int span;
void doStation(int index,int value){
    int start = max(index - span,0);
    int end = min((size_t)(index + span + 1),cover.size());
    for(int i=start;i<end;i++){
        //cover[i] += value;
        cover[i] = 1;
    }
}
int cv = 0;
bool isCoverValid(){
    cv++;
    for(auto c: cover){
        if( c== 0) return false;
    }
    return true;
}
int procCount = 0;
map<string,ll> cache;
ll  process(int index, int prevOn){
    //cout << indent << "process start=" << index << " "<< prevOn << " \n";
    //cout << indent; dumpVector(cover) ;
    procCount++;
    int left = cost.size() - index;
    if(left == 1){
        ll onCost = cost[index];
        vector<int> cov = cover;
        doStation(index,1);
        if(!isCoverValid()){
            onCost = INT_MAX;
        }
        cover = cov;//doStation(index,-1);

        ll offCost = 0;
        if(!isCoverValid()){
            offCost = INT_MAX;
        }        
        return(min(onCost,offCost));
    }
    if(index - prevOn > 2*span + 1){
        return INT_MAX;
    }
    string key = to_string(index) + "_" + to_string(prevOn);
    auto it = cache.find(key);
    if(it!=cache.end()){
        return it->second;
    }

    // try on this index
    ll minCost = INT_MAX;
    vector<int> cov = cover;
    doStation(index,1);
    ll costOn = process(index+1,index);
    cover = cov; //doStation(index,-1);
    if(costOn!=INT_MAX){
        minCost = cost[index] + costOn;
    }
    //scover.pop();
    ll costOff = process(index+1,prevOn);
    if(costOff!=INT_MAX){
        if(costOff < minCost){
            minCost = costOff;
        }
    }
    //cout << "on=" << costOn << " + " << cost[index] <<  " off="<< costOff <<" \n";
    /*auto it = cache.find(key);
    if(it!=cache.end()){
        if(it->second != minCost){
            cout << key << " " << it->second << " <> "<< minCost <<" \n";
            exit(0);
        }
    }*/
    cout << key << " " << minCost <<" \n";
    cache[key] = minCost;
    return minCost;
}

int main(int argc,char *argv[]){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int m,n;
    string output;
    cin >> m >> n;
    span = n;
    cout << "Input " << m << " "<< n <<" \n";
    //process(s1,"","","");
    for(int i=0;i<m;i++){
        int s;
        cin >> s;
        cost.push_back(s);
        cover.push_back(0);
    }
    //dumpVector(cost);
    ll minCost = process(0,-(span + 1));
    cout << minCost << " " << procCount << " " << cv << " \n";
    return 0;
}