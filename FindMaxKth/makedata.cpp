#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <random>
using namespace std;

void makeAnswer(vector<int> &data,int k)
{
    //sort(data.begin(),data.end());
    //cout << data[data.size() - k];

    priority_queue<int, vector<int>,greater<int>> pq;
    for(int i=0;i<k;i++){
        pq.push(data[i]);
    }
    for(int i=k;i<data.size();i++){
        if(pq.top() < data[i]){
            pq.pop();
            pq.push(data[i]);
        }
    }
    cout << pq.top() << "\n";
}




int main(int argc,char * argv[])
{
    //std::random_device rd;
    //std::time_t result = std::time(nullptr);
    std::default_random_engine generator(0);
    if(argc != 4){
        printf("USAGE %s m k r\n",argv[0]);
        return -1;
    }

    int m,k,r;
    m = atoi(argv[1]);
    k = atoi(argv[2]);
    r = atoi(argv[3]);
    cout << m << " " << k << endl;
    vector<int> data;
    std::uniform_int_distribution<long long unsigned> dpoint(0,r);  // inclusive random
    for(int i=0;i< m;i++){
        int index = dpoint(generator);
        cout << index << " ";
        data.push_back(index);
    }
    cout << endl;
    cout << "#output" << endl;
    makeAnswer(data,k);
}