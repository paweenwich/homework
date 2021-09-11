#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;

void preProcessData(vector<char> &data,int questionLength)
{
}

int findDNA(vector<char> &data, vector<char> &question)
{
    for(int i=0;i<(int)(data.size() - question.size());i++){
        if(data[i] == question[0]){
            bool found = true;
            for(int j=0;j<(int)question.size();j++){
                if(data[i+j] != question[j]){
                    found = false;
                    break;
                }
            }
            if(found){
                return i;
            }
        }
    }
    return -1;
}

int main(int argc,char * argv[])
{

    int m,n,o;
    cout << "Reading data..\n";
    cin >> m >> n >> o;
    vector<char> data(m);
    for(int i=0;i< m;i++){
        string s;
        cin >> s;
        data[i] = s.at(0);
        
    }
    vector<vector<char>> questions;
    for(int i=0;i< o;i++){
        vector<char> q(n);
        for(int j=0;j<n;j++){
            string s;
            cin >> s;
            q[j] = s.at(0);
        }
        questions.push_back(q);
    }
    cout << "preProcessData data..\n";
    preProcessData(data,n);
    cout << "Finding DNA..\n";
    vector<int> output;
    auto start = chrono::high_resolution_clock::now();
    while(true){
        for(auto s: questions){
            int ret = findDNA(data,s);
            output.push_back(ret);
        }
        auto now = chrono::high_resolution_clock::now();
        auto duration =  chrono::duration_cast<chrono::microseconds>(now - start);
        if(duration.count() > 5000000){
            break;
        }
    }
    //auto stop = chrono::high_resolution_clock::now();
    //auto duration =  chrono::duration_cast<chrono::microseconds>(stop - start);
    for(auto s: output){
        cout << s << " ";
    }
    cout << endl;
    cout << output.size() << endl;
    //cout << chrono:duration.count()/1000 << " ms" << endl;
}