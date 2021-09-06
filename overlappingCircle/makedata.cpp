#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <random>
using namespace std;
int range = 1000;

class Circle {
    public:
    int x;
    int y;
    int r;
};

bool isOverlap(Circle &p1,Circle &p2){
    double dist = sqrt(pow(p1.x - p2.x,2) +pow(p1.y - p2.y,2));
    return dist <= (p1.r + p2.r);
}
void makeAnswer(vector<Circle> &data,vector<Circle> &question)
{
    //std::sort(data.begin(),data.end());
    for(auto &q: question){
        bool flgFound = false;
        for(auto &d: data){
            if(isOverlap(q,d)){
                flgFound = true;
                break;
            }
        }
        if(flgFound){
            cout << "1 ";
        }else{
            cout << "0 ";
        }
    }
}

int main(int argc,char * argv[])
{
    //std::random_device rd;
    std::default_random_engine generator(0);
    if(argc != 5){
        printf("USAGE %s m n r1 r2\n",argv[0]);
        return -1;
    }

    int m,n,r1,r2;
    m = atoi(argv[1]);
    n = atoi(argv[2]);
    r1 = atoi(argv[3]);
    r2 = atoi(argv[4]);
    cout << m << " " << m << endl;
    std::uniform_int_distribution<long long unsigned> dpoint(0,r1);    
    std::uniform_int_distribution<long long unsigned> drange(1,r2);    
    vector<Circle> data;
    vector<Circle> questions;
    for(int i=0;i<m;i++){
        int x = dpoint(generator);
        int y = dpoint(generator);
        int r = drange(generator);
        cout << x << " " << y << " " << r << endl;
        data.push_back({x,y,r});
    }
    for(int i=0;i<n;i++){
        int x = dpoint(generator);
        int y = dpoint(generator);
        int r = drange(generator);
        cout << x << " " << y << " " << r << endl;
        questions.push_back({x,y,r});
    }

    cout << "#output" << endl;
    makeAnswer(data,questions);
}