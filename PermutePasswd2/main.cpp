#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <random>
#include <unordered_map>

using namespace std;
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

int main(int argc,char * argv[])
{
    return 0;
}