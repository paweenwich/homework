#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <random>
using namespace std;

void makeAnswer(vector<vector<int>> &data)
{
    vector<int> ret;
    for(int i=0;i<data.size();i++){
        ret.insert(ret.end(),data[i].begin(),data[i].end());
        
    }
    sort(ret.begin(),ret.end());
    for(auto x: ret){
       cout << x << " ";
    }
    cout << "\n";
}




int main(int argc,char * argv[])
{
    //std::random_device rd;
    //std::time_t result = std::time(nullptr);
    std::default_random_engine generator(0);
    if(argc != 4){
        printf("USAGE %s m s r\n",argv[0]);
        return -1;
    }

    int m,s,r;
    m = atoi(argv[1]);
    s = atoi(argv[2]);
    r = atoi(argv[3]);
    cout << m << endl;
    vector<vector<int>> data(m);
    std::uniform_int_distribution<long long unsigned> dpoint(0,r);  // inclusive random
    std::uniform_int_distribution<long long unsigned> delta(s/2,s);  // inclusive random
    for(int i=0;i< m;i++){
        int size = delta(generator);
        cout << size << " ";
        data[i].resize(size);
    }
    cout << endl;
    for(int i=0;i< m;i++){
         for(int j=0;j<data[i].size();j++){
            data[i][j] = dpoint(generator);
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
    cout << "#output" << endl;
    makeAnswer(data);
}