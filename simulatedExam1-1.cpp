#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int nums[n];
    int delta[n-1];
    int res = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) cin >> nums[i];
    for (int i = 0; i < n-1; i++) {
        delta[i] = nums[i+1] - nums[i];
    }
    for (int i = 0; i < n-1; i++) {
        sum += delta[i];
        res = res>sum?res:sum;
        if (sum < 0) sum = 0;
    }
    cout << res;
    return 0;
}