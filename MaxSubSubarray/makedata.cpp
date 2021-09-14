#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <random>
using namespace std;

void makeAnswerORG(vector<int> &data)
{
    int maxSum = 0;
    pair<int,int> best;
    for(int i=0;i<(int)data.size();i++){
        for(int j=i+1;j<(int)data.size();j++){
            int sum = accumulate(data.begin()+i,data.begin()+j+1,0);
            //cout << i << " " << j << " " << sum << endl;
            if(sum > maxSum){
                best.first = i;
                best.second = j;
                //cout << i << " " << j << " " << sum << endl;
                maxSum = sum;
            }
        }
    }
    for(int i=best.first;i<=best.second;i++){
        cout << data[i] << " ";
    }
    cout << endl;
    
}

void makeAnswer(vector<int> &data)
{
    int maxSum = 0;
    pair<int,int> best;
    for(int i=0;i<(int)data.size();i++){
        if(data[i]<0) continue;
        for(int j=i+1;j<(int)data.size();j++){
            if(data[j]<0) continue;
            int sum = accumulate(data.begin()+i,data.begin()+j+1,0);
            //cout << i << " " << j << " " << sum << endl;
            if(sum > maxSum){
                best.first = i;
                best.second = j;
                //cout << i << " " << j << " " << sum << endl;
                maxSum = sum;
            }
        }
    }
    for(int i=best.first;i<=best.second;i++){
        cout << data[i] << " ";
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
    std::uniform_int_distribution<long long unsigned> dpoint(-r,r);  // inclusive random
    for(int i=0;i< m;i++){
        int index = dpoint(generator);
        cout << index << " ";
        data.push_back(index);
    }
    cout << endl;
    cout << "#output" << endl;
    makeAnswer(data);
}