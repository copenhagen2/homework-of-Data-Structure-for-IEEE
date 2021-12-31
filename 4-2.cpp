/**
 * @Author: George Lu
 * @Date:   2021-11-05 16:04:13
 * @Last Modified by:   George Lu
 * @Last Modified time: 2021-12-24 02:24:29
 */
#include <iostream>
#include <climits>
using namespace std;

template <class Type>
class hfTree{
private:
    struct Node {
        Type data; //结点值
        int weight; //结点的权值
        int parent, left, right;
    };
    Node *elem;
    int length;
public:
    struct hfCode {
        Type data;
        string code;
    };
    hfTree(const Type *x, const int *w, int size);
    void getCode(hfCode result[ ]);
    ~hfTree() {delete [ ] elem;}
};

template <class Type>
hfTree<Type>::hfTree(const Type *v, const int *w, int size)
{ const int MAX_INT = INT_MAX;
    int min1, min2; //最小树、次最小树的权值
    int x, y; //最小树、次最小树的下标
//置初值
    length = 2 * size;
    elem = new Node[length];
    for (int i = size; i < length; ++i) {
        elem[i].weight = w[i - size];
        elem[i].data = v[i - size];
        elem[i].parent = elem[i].left = elem[i].right = 0;
    }
    // 构造新的二叉树
    for (int i = size - 1; i > 0; --i) {
        min1 = min2 = MAX_INT; x = y = 0;
        for (int j = i + 1; j < length; ++j)
            if (elem[j].parent == 0)
                if (elem[j].weight < min1) {
                    min2 = min1; min1 = elem[j].weight;
                    x = y; y = j; }
                else if (elem[j].weight < min2)
                { min2 = elem[j].weight; x = j; }
        elem[i].weight = min1 + min2;
        elem[i].left = x; elem[i].right = y; elem[i].parent = 0;
        elem[x].parent = i; elem[y].parent = i;
    }
}

template <class Type>
void hfTree<Type>::getCode(hfCode result[])
{ int size = length / 2;
    int p, s;
    for (int i = size; i < length; ++i) {
        result[i - size].data = elem[i].data;
        result[i - size].code = "";
        p = elem[i].parent; s = i;
        while (p) {
            if (elem[p].left == s)
                result[i - size].code = '0' + result[i - size].code;
            else result[i - size].code = '1' + result[i - size].code;
            s = p; p = elem[p].parent;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int w[n];
    for (int i = 0; i < n; i++) cin >> w[i];
    char ch[n+1];
    for (int i = 0; i < n; i++) ch[i] = 'a';
    ch[n] = 0;
    hfTree<char> tree(ch, w, n);
    hfTree<char>::hfCode result[n];
    tree.getCode(result);
    long long int res = 0;
    for (int i = 0; i < n; ++i) {
        res += (w[i] * (int)result[i].code.size());
    }
    cout << res;
    return 0;
}