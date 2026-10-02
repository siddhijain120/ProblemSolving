#include<bits/stdc++.h>
using namespace std;

bool comp(const pair<int,int>&a, const pair<int,int>&b){
    if(a.second == b.second){
        return a.first<b.first;
    }
    return a.second < b.second;
}

int main() {
    int n;
    cin >>n;
    vector<pair<double,int>>movies;
    int startdate;
    int enddate;
    for(int i = 0; i < n; i++){
        cin >> startdate;
        cin >> enddate;
        movies.push_back({startdate, enddate});
    }
    sort(movies.begin(), movies.end(), comp);
    int end = movies[0].second;
    int cnt = 1;
    for(int i = 1; i < movies.size(); i++){
        int start = movies[i].first;
        if(start >= end){
            cnt++;
            end = movies[i].second;
        }
    }
    cout << cnt << endl;
}