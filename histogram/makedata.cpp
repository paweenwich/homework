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
    if(argc != 3){
        printf("USAGE %s m n\n",argv[0]);
        return -1;
    }
    int m,n;
    m = atoi(argv[1]);
    n = atoi(argv[2]);
    cout << m << " " << n << endl;
    vector<int> data;
    srand(m*n);
    for(int i=0;i<m;i++){
        int d = rand()%range;
        data.push_back(d);
        cout << d << endl;
    }
    makeAnswer(data,m,n);
}