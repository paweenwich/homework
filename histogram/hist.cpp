#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int range = 1000;
void makeAnswer(vector<int> &data,int m,int n)
{
    vector<int> hist(n);
    double size = (double)range/n;
    for(auto value: data){
        int index = value/size;
        hist[index]+= 1;
    }
    for(auto a: hist){
        cout << a << " ";
    }
    cout << endl;
}

int main(int argc,char * argv[])
{
    int m,n;
    cin >> m >> n;
    vector<int> data;
    for(int i=0;i<m;i++){
        int d;
        cin >> d;
        data.push_back(d);
    }
    makeAnswer(data,m,n);
}