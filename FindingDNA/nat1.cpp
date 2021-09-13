#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;

map<string,vector<int>>m;
/*
auto m["at"] = {};auto m["ta"] = {};auto m["ag"] = {};auto m["ga"] = {};auto m["ac"] = {};auto m["ca"] = {};
auto m["tg"] = {};auto m["gt"] = {};auto m["tc"] = {};auto m["ct"] = {};auto m["gc"] = {};auto m["cg"] = {};*/
void preProcessData(vector<char> &data,int questionLength)
{
    /*
    myvec at,ag,ac,tg,tc,gc,ta,ga,ca,gt,ct,cg;
    at.name = "at";ag.name = "ag";ac.name = "ac";tg.name = "tg";tc.name = "tc";gc.name = "gc";
    ta.name = "ta";ga.name = "ga";ca.name = "ca";gt.name = "gt";ct.name = "ct";cg.name = "cg";
    vector<myvec> v;*/
    //vector<int>a,t,g,c;
    for(int i = 0;i<(int)data.size()-1;i++){
        string t ;
        t.push_back(data[i]);
        t.push_back(data[i+1]);
        m[t].push_back(i);
        /*
        for(auto x:v){
            if(x.name == t){
                x.vec.push_back(i);
            }
        }*/
        /*
        if(data[i]=='a'){
            a.push_back(i);
        }
        if(data[i]=='t'){
            a.push_back(i);
        }
        if(data[i]=='g'){
            a.push_back(i);
        }
        if(data[i]=='c'){
            a.push_back(i);
        }*/
    }
}

int findDNANAT(vector<char> &data, vector<char> &question)
{

    string q,q2;
    q.push_back(question[0]);
    q.push_back(question[1]);
    q2.push_back(question[2]);
    q2.push_back(question[3]);
    //cout<<(string)question<<" "<<q<<" "<<q2<<"\n";
    /*
    for(auto u:m[q]){
        cout<<u<<" ";
    }cout<<"\n";
    for(auto u:m[q2]){
        cout<<u<<" ";
    }cout<<"\n";*/
    vector<int> &d1 = m[q];
    vector<int> &d2 = m[q2];

    vector<int>v;
    int s1 = (int)d1.size();
    int s2 = (int)d2.size();
    for(int i = 0;i<s1;){
        for(int j = 0;j<s2;){
            if(d1[i]+2 ==d2[j]){
                v.push_back(d1[i]);
                //cout<<m[q][i]<<" "<<m[q2][j]<<endl;
                i++;
                j++;
                //cout<<m[q][i]<<" "<<m[q][j]<<endl;
                
            }
            if(d2[j] <d1[i]){
                j++;
            }
            if(d1[i]+2 < d2[j]){
                i++;
            }
            if(d1[i]+2 >(d2[j])){
                j++;
            }
            if(i < s1  &&  j  < s2){
                
                //break;
            }else{
                goto out1;
            }
        }
    }
out1:    
    /*
    for(auto x: m[q]){
        auto it = lower_bound(m[q2].begin(),m[q2].end(),x+2);
        if(it != m[q2].end()){
            if(*it == x+2){
                v.push_back(x);
            }
            
        }
    }*/

    

    for(auto x: v){
        bool found = true;
        for(int j=0;j<(int)question.size();j++){
            if(data[x+j] != question[j]){
                found = false;
                break;
            }
        }
        if(found){
            return x;
        }
    }
    return -1;

}

int findDNANAT1(vector<char> &data, vector<char> &question)
{

    string q,q2;
    q.push_back(question[0]);
    q.push_back(question[1]);

    vector<int> &v = m[q];
    for(auto x: v){
        bool found = true;
        for(int j=0;j<(int)question.size();j++){
            if(data[x+j] != question[j]){
                found = false;
                break;
            }
        }
        if(found){
            return x;
        }
    }
    return -1;

}

int findDNA(vector<char> &data, vector<char> &question)
{

    string q,q2;
    q.push_back(question[0]);
    q.push_back(question[1]);
    q2.push_back(question[2]);
    q2.push_back(question[3]);
    //cout<<(string)question<<" "<<q<<" "<<q2<<"\n";
    
    vector<int>v;
    vector<int> &d1 = m[q];
    vector<int> &d2 = m[q2];
    //cout << "START " << m[q].size() << " " << m[q2].size() << endl;
    int j=0;
    for(int i=0;i<(int)d1.size() && j<(int)d2.size();i++){
        //cout << i << "-" << j << " values " << d1[i] << " " << d2[j] << " " << endl;
        if(d1[i]  + 2 < d2[j]){
            continue;
        }
        //bool flgFound = false;
        for(;j<(int)d2.size();j++){
            //cout << i << " " << j << " values " << d1[i] << " " << d2[j] << " " << endl;
            if(d2[j]<d1[i]+2){
                continue;
            }
            if(d2[j]==d1[i]+2){
                v.push_back(d1[i]);
                //cout << "push " << d1[i] << endl;
                //flgFound = true;
            }
            break;
        }
    }

    for(auto x: v){
        bool found = true;
        for(int j=0;j<(int)question.size();j++){
            if(data[x+j] != question[j]){
                found = false;
                break;
            }
        }
        if(found){
            return x;
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
            int ret;
            if(argc > 1){
                string param = string(argv[1]);
                if(param=="0"){
                    ret = findDNANAT1(data,s);
                }else{
                    ret = findDNANAT(data,s);
                }
            }else{
                ret = findDNA(data,s);
            }
            output.push_back(ret);
        }
        auto now = chrono::high_resolution_clock::now();
        auto duration =  chrono::duration_cast<chrono::microseconds>(now - start);
        if(duration.count() > 5000000){
            break;
        }
        //break;
    }
    //auto stop = chrono::high_resolution_clock::now();
    //auto duration =  chrono::duration_cast<chrono::microseconds>(stop - start);
    for(int i=0;i<o;i++){
        cout << output[i] << " ";
    }
    cout << endl;
    cout << output.size() << endl;
    //cout << chrono:duration.count()/1000 << " ms" << endl;
}

