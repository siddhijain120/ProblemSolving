#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >>n;
    vector<int>val(n);
    for(int i = 0; i < n; i++){
        cin >> val[i];
    }
    vector<int>wt(n);
    int capacity;
    for(int i = 0; i < n; i++){
        cin >> wt[i];
    }
    cin >> capacity;
    vector<pair<double, int>>arr;
        for(int i = 0; i < val.size(); i++){
            arr.push_back({val[i]/wt[i], wt[i]});
        }
        double total;
        sort(arr.rbegin(), arr.rend());
        // for(int i =0; i < arr.size(); i++){
        //     cout << arr[i].first << " " << arr[i].second << endl;
        // }
        for(int i = 0; i < arr.size(); i++){
            int wt = arr[i].second;
            if(capacity >= wt){
                total += arr[i].first * wt;
                capacity -= wt;
            } else if(wt > capacity) {
                total += arr[i].first * capacity;
                break;
            }
        }
        cout << total << endl;
}