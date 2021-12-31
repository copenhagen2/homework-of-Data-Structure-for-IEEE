/**
 * @Author: George Lu
 * @Date:   2021-12-07 17:00:03
 * @Last Modified by:   George Lu
 * @Last Modified time: 2021-12-24 15:07:14
 */
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long long int minValue = 0, maxValue = 0;
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(a, a+n);
    sort(b, b+n);
    for (int i = 0; i < n; i++) {
        minValue += (long long int)a[i] * (long long int)b[n-1-i];
        maxValue += (long long int)a[i] * (long long int)b[i];
    }
    cout << maxValue << ' ' << minValue;
    return 0;
}
