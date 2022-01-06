#include <bits/stdc++.h> 
 
using namespace std;
 
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int,int>> enter(trips.size()),leave(trips.size());
        for(int i= 0 ; i < trips.size() ; i++){
            enter[i] = {trips[i][1],i};
            leave[i] = {trips[i][2],i};
        }
        int i = 0 , j = 0,n = trips.size();
        int curCap = 0;
        sort(enter.begin(),enter.end());
        sort(leave.begin(),leave.end());
        while(i < n && j < n){
            if(enter[i].first < leave[j].first){
                curCap += trips[enter[i].second][0];
                i++;
            }else{
                curCap -= trips[leave[j].second][0];
                j++;
            }
            if(curCap > capacity)
                return false;
        }
        while(j < n)
            curCap -= trips[leave[j++].second][0];
        return curCap <= capacity;
    }
};