#include <iostream>
using namespace std;
int main() {
    char str[10001];
    int j = 0;
    cin >> str;
    char stack[10001];
    int ptr = 0;
    int flag = 1;
    while(str[j]) {
        if (str[j] == '(') {
            stack[ptr] = str[j];
            ptr++;
        }
        else if (str[j] == ')') {
            if (ptr) {
                if (stack[ptr-1] == '(') ptr--;
                else {
                    flag = 0;
                    break;
                }
            }
            else {
                flag = 0;
                break;
            }
        }
        else if (str[j] == '[') {
            stack[ptr] = str[j];
            ptr++;
        }
        else if (str[j] == ']') {
            if (ptr) {
                if (stack[ptr-1] == '[') ptr--;
                else {
                    flag = 0;
                    break;
                }
            }
            else {
                flag = 0;
                break;
            }
        }
        else if (str[j] == '{') {
            stack[ptr] = str[j];
            ptr++;
        }
        else if (str[j] == '}') {
            if (ptr) {
                if (stack[ptr-1] == '{') ptr--;
                else {
                    flag = 0;
                    break;
                }
            }
            else {
                flag = 0;
                break;
            }
        }
        j++;
    }
    if (ptr == 0) cout << flag;
    else cout << 0;
    return 0;
}
