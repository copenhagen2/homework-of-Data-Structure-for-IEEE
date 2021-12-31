#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    //int tree[100000] = {0};
    //tree[1] = 1;
//    int pos[n+1];
//    for (int i = 0; i < n+1; i++) pos[i] = 0;
//    pos[1] = 1;
    int pa[n+1];
    int h[n+1];
    h[1] = 0;
    int ch[n+1];
    for (int i = 0; i < n+1; i++) ch[i] = 0;
    int max = -1;
    for (int i = 2; i < n+1; i++) cin >> pa[i];
    for (int i = 2; i < n+1; i++) {
        pa[i]++;
        h[i] = h[pa[i]]+1;
        max = max>h[i] ? max:h[i];
        ch[pa[i]]++;
    }
    int flag = 1;
    int t = 0;
    int c = 0;
    for (int i = 1; i < n+1; i++) {
        if (ch[i] == 0 ) {
            if (pa[i] > n ) {
                cout << "true";
                return 0;
            }
            if (ch[pa[i]] == 2) c++;
            if (h[i] != max && h[i] != max-1) {
                flag = 0;
                break;
            }
        }
        if (pa[i] > n) {t = 1;
            continue;}
        if (ch[i] > ch[pa[i]]) {
            flag = 0;
            break;
        }
    }
    if (c > 1) flag = 0;
    if (flag) cout << "true";
    else cout << "false";
    return 0;
}
