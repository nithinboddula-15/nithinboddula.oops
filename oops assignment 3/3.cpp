#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> arr = {900,940,950,1100};
    vector<int> dep = {910,1200,1120,1130};

    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int i=0, j=0, plat=0, ans=0;

    while(i < arr.size()){
        if(arr[i] <= dep[j]) plat++, i++;
        else plat--, j++;

        ans = max(ans, plat);
    }

    cout << ans;
}
