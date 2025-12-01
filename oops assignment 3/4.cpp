#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    vector<int> a = {1,1,1};
    int k = 2;

    unordered_map<int,int> mp;
    mp[0] = 1;

    int sum = 0, cnt = 0;

    for(int x : a){
        sum += x;
        if(mp.find(sum - k) != mp.end())
            cnt += mp[sum - k];

        mp[sum]++;
    }

    cout << cnt;
}
