/**
 * @Author: George Lu
 * @Date:   2021-10-22 15:54:07
 * @Last Modified by:   George Lu
 * @Last Modified time: 2021-12-24 15:07:21
 */
#include <iostream>
using namespace std;
struct node{
    int val;
    node *next = nullptr;
    node *pre = nullptr;
};
class linkList{
public:
    node *head;
    node *tail;
    linkList() {
        head = new node;
        tail = head;
    };
    void push_back(int x) {
        node *tmp = new node;
        tmp->val = x;
        tail->next = tmp;
        tmp->pre = tail;
        tail = tail->next;
    }
    void traverse() {
        node *tmp = head;
        while (tmp->next) {
            cout << tmp->next->val << ' ';
            tmp = tmp->next;
        }
    }
    ~linkList() {
        node *tmp = head;
        node *p = tmp->next;
        while (p) {
            delete tmp;
            tmp = p;
            if (p->next) p = p->next;
            else p = nullptr;
        }
    }
};
int main() {
    linkList a, b;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        b.push_back(x);
    }
    linkList res;
    node *p = a.tail;
    node *q = b.tail;
    int c = 0;
    while (c || p != a.head || q != b.head) {
        int x = c;
        if (p != a.head) {
            x += p->val;
            p = p->pre;
        }
        if (q != b.head) {
            x += q->val;
            q = q->pre;
        }
        c = x / 10;
        x %= 10;
        res.push_back(x);
    }
    p = res.tail;
    while (p != res.head) {
        cout << p->val << ' ';
        p = p->pre;
    }
    return 0;
}
