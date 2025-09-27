#include<iostream>
#include<algorithm>

using namespace std;

int main() {

    int n;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++) {
        cin>>nums[i];
    }

    sort(nums, nums+n);
    int ans = 0;
    for (int i=0;i<n;i+=2) {
        ans = max(ans,abs(nums[i]-nums[i + 1]));
    }
    cout<<ans<<endl;
    return 0;
}