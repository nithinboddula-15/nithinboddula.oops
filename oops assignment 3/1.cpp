#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> a = {-1,0,1,2,-1,-4};
    sort(a.begin(), a.end());

    for(int i=0;i<a.size();i++){
        int l=i+1, r=a.size()-1;
        while(l<r){
            int s=a[i]+a[l]+a[r];
            if(s==0){
                cout<<a[i]<<" "<<a[l]<<" "<<a[r]<<endl;
                l++; r--;
            }
            else if(s<0) l++;
            else r--;
        }
    }
}
