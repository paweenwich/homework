#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <random>
using namespace std;

void makeAnswer(string &data,vector<string> &q)
{

    for(auto s : q){
        string::size_type loc = data.find( s, 0 );
        if(loc == string::npos){
            cout << "-1 ";
            continue;
        }else{
            cout << loc << " ";
        }
        //while(loc!= string::npos){
        //    loc++;
        //    loc = data.find( s, loc );
        //}
    }
    cout << endl;
}

int main(int argc,char * argv[])
{
    //std::random_device rd;
    //std::time_t result = std::time(nullptr);
    std::default_random_engine generator(0);
    if(argc != 4){
        printf("USAGE %s m n o\n",argv[0]);
        return -1;
    }

    int m,n,o;
    m = atoi(argv[1]);
    n = atoi(argv[2]);
    o = atoi(argv[3]);
    cout << m << " " << n << " " << o << endl;
    string data;
    char tab[4] = {'A','T','G','C'} ;
    std::uniform_int_distribution<long long unsigned> dpoint(0,3);  // inclusive random
    for(int i=0;i< m;i++){
        int index = dpoint(generator);
        //cout << "xxx " << index << endl;
        data.push_back(tab[index]);
    }
    vector<string> question;
    for(int i=0;i< o;i++){
        string tmp;
        for(int j=0;j<n;j++){
            tmp.push_back(tab[dpoint(generator)]);
        }
        question.push_back(tmp);
    }    
    for(auto x: data) cout << x << " "; 
    cout << endl;
    for(auto s: question){
        for(auto x: s) cout << x << " "; 
        cout << endl;
    }
    //cout << endl;
    cout << "#output" << endl;
    makeAnswer(data,question);
}