#include <iostream>
using namespace std;
struct node{
    int val;
    node *next = nullptr;
};
int main() {
    int n;
    cin >> n;
    int arr1[n];
    for (int i = 0; i < n; i++) cin >> arr1[i];
    int m;
    cin >> m;
    int arr2[m];
    for (int i = 0; i < m; i++) cin >> arr2[i];
    int res[n+m];
    int ptr1 = 0, ptr2 = 0;
    for (int i = 0; i < m+n; i++) {
        if (ptr1 == n ) {
            res[i] = arr2[ptr2];
            ptr2++;
            continue;
        }

        if (ptr2 == m ) {
            res[i] = arr1[ptr1];
            ptr1++;
            continue;
        }

        if (arr1[ptr1] < arr2[ptr2]) {
            res[i] = arr1[ptr1];
            ptr1++;
        }
        else {
            res[i] = arr2[ptr2];
            ptr2++;
        }
    }
    for (int i = 0; i < n+m; i++) {
        cout << res[i] << ' ';
    }
    return 0;
}