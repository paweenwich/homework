#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <random>
using namespace std;
int lowerBouond(vector<int> &data,int left,int right,int value){
    //cout << left << " " << right << "\n";
    while(left < right){
        int center = (left + right) /2;
        if(center==left){
            break;
        }
        if(value <= data[center]){
            return  lowerBouond(data,left,center,value);
        }else{
            return  lowerBouond(data,center,right,value);
        }
    }
    if(value <= data[left]){
        return left;
    }else{
        return right;
    }

}

int upperBouond(vector<int> &data,int left,int right,int value){
    //cout << left << " " << right << "\n";
    while(left < right){
        int center = (left + right) /2;
        if(center==left){
            break;
        }
        if(value < data[center]){
            return  upperBouond(data,left,center,value);
        }else{
            return  upperBouond(data,center,right,value);
        }
    }
    if(value < data[left]){
        return left;
    }else{
        if(value == data[right]){
            return right+1;
        }
        return right;
    }

}

void makeAnswer(vector<int> &data,int value)
{
    int lower =  lowerBouond(data,0, (int)data.size()-1,value);
    int upper =  upperBouond(data,0, (int)data.size()-1,value);
    cout << lower << " " << upper;
}

int main(int argc,char * argv[])
{
    //std::random_device rd;
    //std::time_t result = std::time(nullptr);
    std::default_random_engine generator(0);
    if(argc != 4){
        printf("USAGE %s m v r \n",argv[0]);
        return -1;
    }

    int m = atoi(argv[1]);
    int target = atoi(argv[2]);
    int r = atoi(argv[3]);
    std::uniform_int_distribution<long long unsigned> dpoint(0,r);  // inclusive random    
    cout << m << " " << target << endl;
    vector<int> data;
    
    for(int i=0;i< m;i++){
        int index = dpoint(generator);

        data.push_back(index);
    }
    sort(data.begin(),data.end());
    for(auto a: data){
        cout << a << " ";
    }
    cout << endl;
    cout << "#output" << endl;
    makeAnswer(data,target);
}