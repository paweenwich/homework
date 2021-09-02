#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
using namespace std;
int main(int argc,char * argv[])
{
    if(argc != 2){
        printf("USAGE %s datafile\n",argv[0]);
        return -1;
    }
    //assume 2 for now
    std::ifstream infile(argv[1]);
    int m,n;
    infile >> m >> n;
    // skip data
    for(int i=0;i<m;i++){
        int a; 
        infile >> a;
    }
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a;
        infile >> b;
        if(a!=b){
            printf("FAIL AT %d %d -> %d\n",i,a,b);
            return(-1);
        }
    }
    printf("PASS\n");
    return(0);
}