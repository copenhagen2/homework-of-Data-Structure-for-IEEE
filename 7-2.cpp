/**
 * @Author: George Lu
 * @Date:   2021-12-08 00:01:31
 * @Last Modified by:   George Lu
 * @Last Modified time: 2021-12-24 15:07:14
 */
#include <iostream>

using namespace std;

void reverse(int *arr, int l, int r, int &k);

int main() {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++) arr[i] = i+1;
    k--;
    reverse(arr, 0, n, k);
    if (k <= 0) for (int i = 0; i < n; i++) cout << arr[i] << ' ';
    else cout << -1;
    //for (int i = 0; i < n; i++) cout << arr[i] << ' ';
    return 0;
}

void reverse(int *arr, int l, int r, int &k) {
    if (k == 0) return;
    if (k == 1) return;
    if (k >= 2) {
        if (l < r - 1) {
            int mid = (l + r) / 2;
            int tmp = arr[mid];
            arr[mid] = arr[mid - 1];
            arr[mid - 1] = tmp;
            k -= 2;
            reverse(arr, l, mid, k);
            reverse(arr, mid, r, k);
        }
    }
}