#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <random>
using namespace std;
int range = 1000;
std::vector<vector<int>> passwd;
void perm(int n,int k,int start,vector<int> &prev){
    int sum[10];
    for(int i=0;i<10;i++){
        sum[i] = 0;
    }
    for(auto p: prev){
        sum[p]++;
    }
    for(int i=0;i<10;i++){
        if(i>k) continue;
        if(sum[i]==2) continue;
        if(start + 1 < n){
            vector<int> current = prev;
            current.push_back(i);
            perm(n,k-i,start+1,current);
        }else{
            if(i == k){
                vector<int> out = prev;
                out.push_back(i);
                passwd.push_back(out);
            }
        }
    }
}

int main(int argc,char * argv[])
{
    int m,k;
    cin >> m >> k;
    //printf("%d %d\n",m,k);
    vector<int> prev;
    perm(m,k,0,prev);
    for(auto p: passwd){
        for(auto i: p){
            printf("%d ",i);
        }
        printf("\n");
    }
    printf("%d\n",passwd.size());
    return 0;
}