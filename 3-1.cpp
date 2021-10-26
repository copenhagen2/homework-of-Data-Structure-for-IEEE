#include <iostream>
#include <climits>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    int *data = new int[n];
    int *res_max = new int[n - k + 1];
    int *res_min = new int[n - k + 1];
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    for (int i = 0; i < n - k + 1; i++) {
        int cur_min = INT_MAX;
        int cur_max = INT_MIN;
        for (int j = 0; j < k; j++) {
            cur_max = cur_max > data[i+j]?cur_max:data[i+j];
            cur_min = cur_min < data[i+j] ? cur_min : data[i+j];
        }
        res_max[i] = cur_max;
        res_min[i] = cur_min;
    }
    for (int i = 0; i < n - k + 1; i++) cout << res_min[i] << ' ';
    cout << endl;
    for (int i = 0; i < n - k + 1; i++) cout << res_max[i] << ' ';
    delete[]res_min;
    delete[]res_max;
    delete[]data;
    return 0;
}