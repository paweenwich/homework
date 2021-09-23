#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <random>
using namespace std;

void makeAnswer(vector<pair<int,int>> &data)
{
    sort(data.begin(),data.end());
    int finish = data[0].second;
    cout << data[0].first << " " << data[0].second << "\n";
    for(int i=1;i<data.size();i++){
        if(data[i].first <= finish) continue;
        cout << data[i].first << " " << data[i].second << "\n";
        finish = data[i].second;
    }
}




int main(int argc,char * argv[])
{
    //std::random_device rd;
    //std::time_t result = std::time(nullptr);
    std::default_random_engine generator(0);
    if(argc != 4){
        printf("USAGE %s m r d\n",argv[0]);
        return -1;
    }

    int m,r,d;
    m = atoi(argv[1]);
    r = atoi(argv[2]);
    d = atoi(argv[3]);
    cout << m << endl;
    vector<pair<int,int>> data;
    std::uniform_int_distribution<long long unsigned> dpoint(0,r);  // inclusive random
    std::uniform_int_distribution<long long unsigned> delta(1,d);  // inclusive random
    for(int i=0;i< m;i++){
        int d1 = dpoint(generator);
        int d2 = delta(generator);
        cout << d1 << " " << d1 +d2 << "\n";
        data.push_back({d1,d1 + d2});
    }
    cout << endl;
    cout << "#output" << endl;
    makeAnswer(data);
}