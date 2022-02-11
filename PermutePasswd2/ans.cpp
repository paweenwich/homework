#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <random>
using namespace std;
#include <unordered_map>

bool login(string pwd){
    static hash<string> hasher;
    size_t h = hasher(pwd);
    //printf("%08X\n",h);
    switch(pwd.size()){
        case 3: return (0x70A6F543 == (unsigned long)h);
        case 4: return (0xAE346D6B == (unsigned long)h);
        case 5: return (0x46494396 == (unsigned long)h);
        case 6: return (0xDF7402C0 == (unsigned long)h);
        case 7: return (0xA7FB70E2 == (unsigned long)h);
        case 8: return (0xC7CE89F6 == (unsigned long)h);
    }
    return false;
}
char allChars[] = "23456789abcdefghkmnpqrstuvwxyzABCDEFGHKMNPQRSTUVWXYZ";
int numChars = 0;

void crack(int n,int start,string prev){
    for(int i=0;i<numChars;i++){
        if(start + 1 < n){
            string current = prev;
            current += allChars[i];
            //printf("%s\n",current.c_str());
            crack(n,start+1,current);
        }else{
            string out = prev;
            out += allChars[i];
            if(login(out)){
                printf("%s\n",out.c_str());
            }
        }
    }
}

int main(int argc,char * argv[])
{
    int m,k;
    cin >> m;
    numChars = strlen(allChars);
    string prev = "";
    crack(m,0,prev);
    return 0;
}