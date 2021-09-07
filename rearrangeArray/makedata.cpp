#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <random>
using namespace std;

void makeAnswer(vector<int> &data)
{
    std::sort(data.begin(),data.end());
    for(auto i=2;i<(int)data.size();i+=2){
        std::swap(data[i],data[i-1]);
    }
}

int main(int argc,char * argv[])
{
    //std::random_device rd;
    std::default_random_engine generator(0);
    if(argc != 3){
        printf("USAGE %s m r\n",argv[0]);
        return -1;
    }

    int m,r1;
    m = atoi(argv[1]);
    r1 = atoi(argv[2]);
    //cout << m << endl;
    vector<int> data;
    std::uniform_int_distribution<long long unsigned> dpoint(0,r1);    
    for(int i=0;i<m;i++){
        int x = dpoint(generator);
        if(find(data.begin(),data.end(),x)==data.end()){
            //cout << x << " " ;
            data.push_back(x);
        }
    }
    cout << data.size() << endl;
    for(auto x: data) cout << x << " ";
    cout << endl;
    cout << "#output" << endl;
    makeAnswer(data);
    for(auto x: data) cout << x << " ";
    cout << endl;
}