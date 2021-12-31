/**
 * @Author: George Lu
 * @Date:   2021-10-15 16:08:34
 * @Last Modified by:   George Lu
 * @Last Modified time: 2021-12-24 02:24:17
 */
#include <iostream>
using namespace std;
struct node {
    int val;
    node *next = nullptr;
};
class linkList{
private:
    node *head;
    node *tail;
    int curLength = 0;
public:
    linkList() {
        head = new node;
        tail = head;
    }
    void insert(int index, int val) {
        int count = 0;
        node *p = head;
        while (count < index) {
            p = p->next;
            count++;
        }
        node *tmp = new node;
        tmp->val = val;
        tmp->next = p->next;
        p->next = tmp;
    }

    void remove(int index) {
        int count = 0;
        node *p = head;
        while (count < index-1) {
            count++;
            p = p->next;
        }
        node *tmp;
        tmp = p->next->next;
        p->next = tmp;
    }

    void add(int val) {
        node *tmp = new node;
        tmp->val = val;
        tail->next = tmp;
        tail = tmp;
        curLength++;
    }

    void traverse() {
        node *p = head->next;
        while (p) {
            cout << p->val << ' ';
            p = p->next;
        }
    }
};
int main(void) {
    int n, m;
    cin >> n >> m;
    linkList l;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        l.add(x);
    }
    for (int i = 0; i < m; i++) {
        int type_opt;
        cin >> type_opt;
        if (type_opt == 1) {
            int x, y;
            cin >> x >> y;
            l.insert(x, y);
        }
        if (type_opt == 2) {
            int x;
            cin >> x;
            l.remove(x);
        }
    }
    l.traverse();
    return 0;
}
