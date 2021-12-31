/**
 * @Author: George Lu
 * @Date:   2021-10-15 16:08:34
 * @Last Modified by:   George Lu
 * @Last Modified time: 2021-12-24 02:24:17
 */
/**
 * @Author: George Lu
 * @Date:   2021-10-15 16:08:34
 * @Last Modified by:   George Lu
 * @Last Modified time: 2021-12-24 02:24:17
 */
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    vector<int> stack;
    int num = 0;
    int a, b;
    char *str;
    str = new char [1000000];
    cin >> str;
    while (*str != '@') {
        switch (*str) {
            case '+':
                a = stack.back();
                stack.pop_back();
                b = stack.back();
                stack.pop_back();
                stack.push_back(a+b);
                break;
            case '-':
                a = stack.back();
                stack.pop_back();
                b = stack.back();
                stack.pop_back();
                stack.push_back(b-a);
                break;
            case '*':
                a = stack.back();
                stack.pop_back();
                b = stack.back();
                stack.pop_back();
                stack.push_back(a*b);
                break;
            case '/':
                a = stack.back();
                stack.pop_back();
                b = stack.back();
                stack.pop_back();
                stack.push_back(b/a);
                break;
            default:
                if (*str <= '9' && *str >= '0') {
                    num *= 10;
                    num += (*str - '0');
                }
                else {
                    stack.push_back(num);
                    num = 0;
                }
                break;
        }
        str++;
    }
    if (!stack.empty()) cout << stack[0];
    else cout << 0;
    return 0;
}
