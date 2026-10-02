#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>arr;
        arr.push_back(2);
        int a = 0, b = 0;
        for(int i = 2; i <= n; i++){
            arr.push_back(pow(2,i));
        }
        if(arr.size() > 2){
            if(n % 3 == 0 ||n % 5 == 0){

        for(int i = 0; i < (n/2)-1; i++){
            if(i % 2 == 0 || i == 0){
                a += (arr[i] + arr[n - i - 1]);
            } else {
                b += (arr[i] + arr[n - i - 1]);
            }
        }
        a += arr[(n/2)-1];
        b += arr[n/2];
    } else {
        for(int i = 0; i < n/2; i++){
            if(i % 2 == 0 || i == 0){
                a += (arr[i] + arr[n - i - 1]);
            } else {
                b += (arr[i] + arr[n - i - 1]);
            }
        }
    }
    } else {
        a = arr[0], b= arr[1];
    }
        cout << abs(a - b) << endl;
        
    }
}