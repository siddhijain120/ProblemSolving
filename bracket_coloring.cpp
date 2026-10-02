#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
    int n;
    cin >> n;
    string str;
    cin >> str;

if(n % 2 == 0) {
    int c1 = 1, c2 =2;
    int o =1, c = -1;
    int ocnt = 0, ccnt = 0;
    vector<int>prefixes(n);
    if(str[0] == '(') {
        prefixes[0] = o;
        ocnt++;
    }
    else {
        prefixes[0] = c;
        ccnt++;
    }
    for(int i = 1; i < n; i++){
        if(str[i] == '(') {
            prefixes[i] =  1 + prefixes[i-1]; 
            ocnt++;
        }
        else {
            prefixes[i] = prefixes[i-1] - 1;
            ccnt++;
        }
    }
    // bool flag = true;
    if(ocnt != ccnt){
        cout <<"-1" << endl;
        // flag = false;
        continue;
    }
    // if(flag == true){
    vector<int>ans;
    for(int i = 0; i < n; i++){
        // cout << "hello";
        if(i == 0){
            if(prefixes[i] > 0) ans.push_back(1);
            else ans.push_back(2);
        } else {
        if(prefixes[i] > 0){
            ans.push_back(1);
        } else if(prefixes[i] < 0){
            ans.push_back(2);
        } else if(prefixes[i] == 0 && prefixes[i-1] < 0){
            ans.push_back(2);
        } else {
            ans.push_back(1);
        }
    }
    }
    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
} else {
    cout << " -1" << endl;
}
}
}
