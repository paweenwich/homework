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
int numDigit = 0;
char charCount['z'+1];
char state[3];
char stateLookup['z'+1];
string prevStr = "";

bool isValid1(string &pwd){
    static char countChar['z'+1];
    memset(countChar,0,sizeof(countChar));
    for(auto c: pwd){
        countChar[c]++;
        if(countChar[c] > 1){
            //printf("%c %s %d\n",c,pwd.c_str(),count[c]);

            return false;
        }
    }
    return true; 
}
bool isValid2(string &pwd){
    bool digit = false;
    bool cap = false;
    bool normal = false;
    for(auto c: pwd){
        if(isdigit(c)){
            digit=true;
        }else if(isalpha(c)){
            if(isupper(c)){
                cap = true;
            }else{
                normal = true;
            }
        }
    }
    return (digit && cap && normal); 
}

void crack(int n,int start,string prev){
    for(int i=0;i<numChars;i++){
        string current = prev;
        current += allChars[i];
        //printf("%s\n",current.c_str());
        if(isValid1(current)){
            if(start + 1 < n){
                crack(n,start+1,current);
            }else{
                //if(isValid2(current)){
                    if(login(current)){
                        printf("%s\n",current.c_str());
                    }
                //}
            }
        }else{
            //printf("%s\n",current.c_str());
        }
    }
}
int getStateIndex(char ch){
    if(isdigit(ch)){
        return 0;
    }
    if(isupper(ch)){
        return 1;
    }else{
        return 2;
    }
}

void crack2(int start){
    for(int i=0;i<numChars;i++){
        char ch = allChars[i];
        if(charCount[ch]>0) continue;

        //int stateIndex = getStateIndex(ch);      
        int stateIndex = stateLookup[ch];      
          
        state[stateIndex]++;
        charCount[ch]++;
        //string current = prev;
        prevStr += allChars[i];
        //current += allChars[i];
        if(start + 1 < numDigit){
            crack2(start+1);
        }else{
            if((state[0] >0 ) && (state[1] >0) && (state[2] > 0)){
            //if(isValid2(prev)){
                if(login(prevStr)){
                    printf("%s\n",prevStr.c_str());
                }
            //}else{
               // printf("ERR %s %d %d %d\n",prev.c_str(),state[0],state[1],state[2]);
            //}
            }
        }
        prevStr.pop_back();
        charCount[ch]--;
        state[stateIndex]--;
    }
}


int main(int argc,char * argv[])
{
    int m,k;
    cin >> m;
    numChars = strlen(allChars);
    numDigit = m;
    
    memset(charCount,0,sizeof(charCount));
    memset(stateLookup,0,sizeof(stateLookup));
    for(char *ptr = allChars;*ptr!=0;ptr++ ){
        stateLookup[*ptr] = getStateIndex(*ptr);
    }
    memset(state,0,sizeof(state));
    crack2(0);
    printf("%lld\n",loginCount);
    //crack(m,0,prev);
    return 0;
}