#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <random>
using namespace std;
#include <unordered_map>
long long loginCount = 0;

bool login(string &pwd){
    static hash<string> hasher;
    size_t h = hasher(pwd);
    loginCount++;
    //printf("%08X\n",h);
    switch(pwd.size()){
        case 3: return (0x617D4123 == (unsigned long)h);
        case 4: return (0x928A8594 == (unsigned long)h);
        //case 5: return (0x46494396 == (unsigned long)h);
        //case 6: return (0xDF7402C0 == (unsigned long)h);
        //case 7: return (0xA7FB70E2 == (unsigned long)h);
        case 8: return (0xA235D110 == (unsigned long)h);
    }
    return false;
}
//char allChars[] = "23456789abcdefghkmnpqrstuvwxyzABCDEFGHKMNPQRSTUVWXYZ";
//int numChars = 0;
int numDigit = 0;
char charCount[10];
//char state[3];
//char stateLookup['z'+1];
string prevStr = "";


void crack2(int start){
    for(int i=0;i<10;i++){
        //char ch = i;
        if(charCount[i]==0) continue;
        charCount[i]--;
        //string current = prev;
        prevStr += to_string(i);
        //current += allChars[i];
        if(start + 1 < numDigit){
            crack2(start+1);
        }else{
            //printf("[%s]\n",prevStr.c_str());
            //if((state[0] >0 ) && (state[1] >0) && (state[2] > 0)){
            //if(isValid2(prev)){
                if(login(prevStr)){
                    printf("%s\n",prevStr.c_str());
                }
            //}else{
               // printf("ERR %s %d %d %d\n",prev.c_str(),state[0],state[1],state[2]);
            //}
            //}
        }
        prevStr.pop_back();
        charCount[i]++;
    }
}


int main(int argc,char * argv[])
{
    int n,m;
    cin >> n >> m;
    //numChars = strlen(allChars);
    numDigit = n;
    for(int i=0;i<10;i++){
        charCount[i] = 0;
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        charCount[a] = b;
    }
    crack2(0);
    //printf("%lld\n",loginCount);
    //crack(m,0,prev);
    string pwd = ("99887766");
    login(pwd);
    return 0;
}