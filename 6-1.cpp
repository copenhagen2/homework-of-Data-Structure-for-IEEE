/**
 * @Author: George Lu
 * @Date:   2021-11-26 16:54:08
 * @Last Modified by:   George Lu
 * @Last Modified time: 2021-12-24 02:24:37
 */
#include <iostream>
using namespace std;

struct node {
    int val;
    node *next = nullptr;
    node *pre = nullptr;
};

class linkList {
private:
    node *root;
    node *rear;
public:
    linkList() {
        root = new node;
        rear = root;
    }

    void add(int x) {
        node *tmp = new node;
        tmp->val = x;
        rear->next = tmp;
        tmp->pre = rear;
        rear = tmp;
    }

    // 查找元素并把查到的元素放在表头
    int find(int x) {
        int count = 0;
        int flag = 0;
        node *p = root->next;
        while (p) {
            count++;
            if (p->val == x) {
                flag = 1;
                break;
            }
            p = p->next;
        }
        if (flag) {
            p->pre->next = p->next;
            if (p->next) p->next->pre = p->pre;
            p->next = root->next;
            root->next->pre = p;
            root->next = p;
            p->pre = root;
        }
        return count;
    }
    ~linkList() {
        node *tmp = root;
        while (tmp->next) {
            node *p = tmp->next;
            delete tmp;
            tmp = p;
        }
        delete tmp;
    }
};

int main() {
    int n, m, res = 0;
    linkList list;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        list.add(x);
        //cout << "add one elem." << endl;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        res += list.find(x);
    }
    cout << res;
    return 0;
}