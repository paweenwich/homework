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
    // skip data
    while(true){
        string s;
        infile >> s;
        if(s == "#output"){
            break;
        }
    }
    int count = 0;
    while(!cin.eof() && !infile.eof()){
        int a,b;
        cin >> a;
        infile >> b;
        if(a!=b){
            printf("FAIL AT %d %d -> %d\n",count,a,b);
            return(-1);
        }
        count++;
    }
    printf("PASS\n");
    return(0);
}