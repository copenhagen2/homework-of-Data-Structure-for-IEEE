#include <iostream>

using namespace std;

void getBack(int *pre, int *mid, int *back, int size);

int main() {
    int n;
    cin >> n;

    int pre[n];
    int mid[n];
    int back[n];

    for (int i = 0; i < n; i++) cin >> pre[i];
    for (int i = 0; i < n; i++) cin >> mid[i];

    //过于懒，直接写递归
    getBack(pre, mid, back, n);

    for (int i = 0; i < n; i++) cout << back[i] << ' ';

    return 0;
}

void getBack(int *pre, int *mid, int *back, int size) {
    if (size == 0) return; //递归结束条件，当back中没有操作的空间
    *(back + size - 1) = *pre; //把当前的根节点放在当前back的最后一位
    int num = 0;
    while(*(mid + num) != *pre) num++; //找出根节点在中序第几个从而算出左子树和右子树多大
    int size_left = num; //左子树大小
    int size_right = size - 1 - num; //右子树大小
    getBack(pre + 1, mid, back, size_left); //递归实现左子树
    getBack(pre + size_left + 1, mid + num + 1, back + size_left, size_right); //递归实现右子树
}