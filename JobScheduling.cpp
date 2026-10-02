#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int>time(n);
    vector<int>price(n);
    for(int i = 0; i <  n; i++){
        cin >> time[i];
    }
    for(int i = 0; i < n; i++){
        cin >>price[i];
    }
    int max_time = 0;
    for(int i = 0; i < n; i++){
        if(time[i] > max_time){
            max_time = time[i];
        }
    }
    vector<pair<int, int>>a;
    for(int i = 0; i < n; i++){
        a.push_back({price[i], time[i]});
    }
    sort(a.rbegin(),a.rend());
    int total = 0;
    if(max_time < n){
        for(int i = 0; i < max_time; i++){
            
        }
    }
}