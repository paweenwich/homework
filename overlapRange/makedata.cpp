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
void makeAnswer(vector<pair<int,int>> &data1,vector<pair<int,int>> &data2)
{
    std::sort(data1.begin(),data1.end());
//for(auto p: data1){
    //cout << p.first << " " << p.second << ",";
//}
//cout << endl;
    for(auto p: data2){
        auto it = lower_bound(data1.begin(),data1.end(),p.first,[](pair<int,int> &p1,int value){
            return p1.second < value;
        });
        if(it==data1.end()){
            cout << "0 ";
        }else{
            //cout << it->first << " - ";
            if(isOverlap(p,*it)){
                cout << "1 ";
            }else{
                cout << "0 ";
            }
        }
    }
}

int main(int argc,char * argv[])
{
    //std::random_device rd;
    std::default_random_engine generator(0);
    if(argc != 5){
        printf("USAGE %s m n r1 r2\n",argv[0]);
        return -1;
    }

    int m,n,r1,r2;
    m = atoi(argv[1]);
    n = atoi(argv[2]);
    r1 = atoi(argv[3]);
    r2 = atoi(argv[4]);
    cout << m << " " << n << endl;
    std::uniform_int_distribution<long long unsigned> dpoint(0,r1);    
    std::uniform_int_distribution<long long unsigned> drange(1,r2);    
    vector<pair<int,int>> data[2];
    for(int j=0;j<2;j++){
        for(int i=0;i<m;i++){
            int p1 = dpoint(generator);
            int p2 = p1 + drange(generator);
            cout << p1 << " " << p2 << endl;
            data[j].push_back({p1,p2});
        }
    }
    cout << "#output" << endl;
    makeAnswer(data[0],data[1]);
}