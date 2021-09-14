#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <random>
using namespace std;

void makeAnswer(vector<int> &data)
{
    int maxvalue = 0;
    int index = 0;
    for(int i=0;i<(int)data.size()-1;i++){
        int diff = data[i+1] - data[i];
        if(diff > maxvalue){
            index = i;
            maxvalue = diff;
        }
    }
    cout << data[index] << " " << data[index+1] << endl;
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
    std::uniform_int_distribution<long long unsigned> dpoint(0,r);  // inclusive random
    for(int i=0;i< m;i++){
        int index = dpoint(generator);
        cout << index << " ";
        data.push_back(index);
    }
    cout << endl;
    cout << "#output" << endl;
    makeAnswer(data);
}