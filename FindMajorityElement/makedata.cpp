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
    std::time_t result = std::time(nullptr);
    std::default_random_engine generator(result);
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
    int repNum = dpoint(generator);
    for(int i=0;i< m/2 + 1;i++){
        data.push_back(repNum);
    }
    while((int)data.size()<m){
        data.push_back(dpoint(generator));
    }
    std::shuffle(data.begin(),data.end(),generator);
    cout << data.size() << endl;
    for(auto x: data) cout << x << " ";
    cout << endl;
    cout << "#output" << endl;
    //makeAnswer(data);
    cout << repNum;
    cout << endl;
}