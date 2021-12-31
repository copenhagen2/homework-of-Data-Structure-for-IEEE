/**
 * @Author: George Lu
 * @Date:   2021-11-26 16:54:23
 * @Last Modified by:   George Lu
 * @Last Modified time: 2021-12-24 02:24:51
 */
#include <iostream>
#include <cmath>
#include <climits>
#include <vector>
using namespace std;

struct node {
    int val;
    node *left = nullptr;
    node *right = nullptr;
    node(int x = 0) : val(x) {};
};

int min(int a, int b) {
    return a > b ? b : a;
}

class BySearchTree {
private:
    node *root;

    void insert(int x, node *&point) {
        if (!point) {
            point = new node(x);
            return;
        }
        if (x < point->val) insert(x, point->left);
        else insert(x, point->right);
    }

    void remove(int x, node *&point) {
        if (!point) return;
        if (x < point->val) remove(x, point->left);
        else if (x > point->val) remove(x, point->right);
        else {
            if (point->left && point->right) {
                node *tmp = point->left;
                while (tmp->right) tmp = tmp->right;
                point->val = tmp->val;
                remove(tmp->val, point->left);
            }
            else {
                node *tmp = point;
                point = point->left ? point->left:point->right;
                delete tmp;
                return;
            }
        }
    }


public:
    BySearchTree() {
        this->root = nullptr;
    }

    void insert(int x) {
        insert(x, this->root);
    }

    void remove(int x) {
        remove(x, this->root);
    }

    int inquire(int x) {
        node *tmp = root;
        int res = INT_MAX;
        while (tmp) {
            res = min(res, abs(x - tmp->val));
            if (x == tmp->val) return 0;
            if (x < tmp->val) tmp = tmp->left;
            else tmp = tmp->right;
        }
        return res;
    }
};

int main() {
    int m;
    vector<int> res;
    cin >> m;
    BySearchTree s;
    for (int i = 0; i < m; i++) {
        int op, x;
        cin >> op >> x;
        switch (op) {
            case 0:
                res.push_back(s.inquire(x));
                break;
            case 1:
                s.insert(x);
                break;
            case 2:
                s.remove(x);
                break;
        }
    }
    int n = res.size();
    for (int i = 0; i < n; i++) {
        cout << res[i] << endl;
    }
    return 0;
}