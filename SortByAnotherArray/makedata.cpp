#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <random>
using namespace std;

void makeAnswer(vector<int> &data1,vector<int> &data2)
{
    vector<int> ret;
    //sort(data2.begin(),data2.end());
    map<int,int> m1;
    //set<int> s2(data2.begin(),data2.end());
    for(auto x:data1){
        m1[x]++;
    }
    for(auto x: data2){
        for(int i=0;i<m1[x];i++){
            ret.push_back(x);
        }
        m1.erase(x);
    }
    for(auto x:m1){
        for(int i=0;i<x.second;i++){
            ret.push_back(x.first);
        }
    }
    for(auto x: ret) {
        cout << x << " "; 
    }
    cout << endl;
}

int main(int argc,char * argv[])
{
    //std::random_device rd;
    //std::time_t result = std::time(nullptr);
    std::default_random_engine generator(0);
    if(argc != 4){
        printf("USAGE %s m n r\n",argv[0]);
        return -1;
    }

    int m,n,r1;
    m = atoi(argv[1]);
    n = atoi(argv[2]);
    r1 = atoi(argv[3]);
    //cout << m << endl;
    vector<int> data1;
    set<int> data2;
    std::uniform_int_distribution<long long unsigned> dpoint(0,r1);    
    for(int i=0;i< m;i++){
        data1.push_back(dpoint(generator));
    }
    for(int i=0;i< n;i++){
        data2.insert(dpoint(generator));
    }    
    //while((int)data.size()<m){
    //    data.push_back(dpoint(generator));
    //}
    //std::shuffle(data.begin(),data.end(),generator);
    cout << m << " " << data2.size() << endl;
    vector<int> d2(data2.begin(),data2.end());
    std::shuffle(d2.begin(),d2.end(),generator);
    for(auto x: data1) cout << x << " "; 
    cout << endl;
    for(auto x: d2) cout << x << " "; 
    cout << endl;
    cout << "#output" << endl;
    makeAnswer(data1,d2);
}