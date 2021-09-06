#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <random>
using namespace std;
int range = 1000;

bool isOverlap(pair<int,int> &p1,pair<int,int> &p2){
    if((p1.first >= p2.first) && (p1.first <= p2.second)){
        return true;
    }
    if((p1.second >= p2.first) && (p1.second <= p2.second)){
        return true;
    }    
    if((p2.first >= p1.first) && (p2.first <= p1.second)){
        return true;
    }
    if((p2.second >= p1.first) && (p2.second <= p1.second)){
        return true;
    }
    return false;
}

int main(int argc,char * argv[])
{
    int m,n;
    cin >> m >> n;
    vector<pair<int,int>> data[2];
    data[0].reserve(m);
    //data[1].reserve(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        data[0].push_back({a,b});
    }
    std::sort(data[0].begin(),data[0].end());
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        bool flgOverlap = false;
        for(auto s:data[0]){
            pair<int,int> p(a,b);
            if(isOverlap(p,s)){
                flgOverlap = true;
                break;
            }
        }
        if(flgOverlap){
            cout << "1 ";
        }else{
            cout << "0 ";
        }
    }
}