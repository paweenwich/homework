#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <random>
using namespace std;

void makeAnswer(vector<int> &data)
{
    for(int i=0;i<(int)data.size();i++){
        long long int prod = 1;
        for(int j=0;j<(int)data.size();j++){
            if(j==i) continue;
            prod *= data[j];
        }
        cout << prod << " ";
    }
    cout << endl;
}

int main(int argc,char * argv[])
{
    //std::random_device rd;
    //std::time_t result = std::time(nullptr);
    std::default_random_engine generator(0);
    if(argc != 3){
        printf("USAGE %s m r \n",argv[0]);
        return -1;
    }

    int m,r;
    m = atoi(argv[1]);
    r = atoi(argv[2]);
    cout << m << endl;
    vector<int> data;
    std::uniform_int_distribution<long long unsigned> dpoint(1,r);  // inclusive random
    for(int i=0;i< m;i++){
        int index = dpoint(generator);
        cout << index << " ";
        data.push_back(index);
    }
    cout << endl;
    cout << "#output" << endl;
    makeAnswer(data);
}