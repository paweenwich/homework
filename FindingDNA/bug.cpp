#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;

void preProcessData(vector<char> &data)
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
    vector<vector<char>> questions(o);
    for(int i=0;i< o;i++){
        vector<char> q(n);
        for(int j=0;j<n;j++){
            string s;
            cin >> s;
            q[j] = s.at(0);
        }
        questions.push_back(q);
    }
    for(auto x: data){
        cout << x << " ";
    }
    cout << endl;
    for(auto q: questions){
        for(auto x: q){
            cout << x << " ";
        }
        cout << endl;
    }

}