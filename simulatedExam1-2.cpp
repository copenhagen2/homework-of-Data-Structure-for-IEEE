/**
 * @Author: George Lu
 * @Date:   2021-10-16 10:01:46
 * @Last Modified by:   George Lu
 * @Last Modified time: 2021-12-24 15:07:25
 */
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
