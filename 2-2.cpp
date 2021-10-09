#include <iostream>

using namespace std;

int main(void) {
    int T;
    cin >> T;
    int res[T];
    for (int i = 0; i < T; i++) {
        int n, top = 0;
        int flag = 1;
        cin >> n;
        int data[n];
        int record[n];
        for (int j = 0; j < n; j++) record[j] = 0;
        for (int j = 0; j < n; j++) cin >> data[j];
        for (int j = 0; j < n; j++) {
            record[data[j]-1] = 1;
            if (data[j] >= top) {
                int k = data[j] - 1;
                while (k) {
                    if (record[k-1] == 0) break;
                    else k--;
                }
                top = k;
            }
            else if (data[j] < top) {
                //cout << "No" << endl;
                flag = 0;
                break;
            }
        }
        res[i] = flag;
        //if (flag) cout << "Yes" << endl;
    }
    for (int i = 0; i < T; i++) {
        if (res[i]) cout << "Yes";
        else cout << "No";
        if (i < T - 1) cout << endl;
    }
    return 0;
}
