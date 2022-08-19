#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &stalls,int dist,int k){
    int cow_count = 1,last_pos = stalls[0];
    for(int i = 0;i < stalls.size();i++){
        if(abs(stalls[i]-last_pos) >= dist){
            cow_count++;
        
            if(cow_count == k){
                return true;
            }
            last_pos = stalls[i];
        }
    }
    return false;
}


int aggressiveCows(vector<int> &stalls, int k){
    int max_dist = stalls[0];
    sort(stalls.begin(),stalls.end());
    for(int i = 1;i < stalls.size();i++){
        max_dist = max(max_dist,stalls[i]);
    }
    int dist=0;
    for(int i = 1;i <= (max_dist);i++){
        if(isPossible(stalls,i,k)){
            dist = i;
        }
    }
    return dist;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        vector<int> arr;
        for(int i=0;i<n;i++){
            int temp;
            cin >> temp;
            arr.push_back(temp);
        }
        cout << aggressiveCows(arr, k) << endl;
    }
    return 0;
}
