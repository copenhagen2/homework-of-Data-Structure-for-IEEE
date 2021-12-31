/**
 * @Author: George Lu
 * @Date:   2021-10-26 17:28:22
 * @Last Modified by:   George Lu
 * @Last Modified time: 2021-12-24 02:24:24
 */
/**
 * @Author: George Lu
 * @Date:   2021-10-26 17:28:22
 * @Last Modified by:   George Lu
 * @Last Modified time: 2021-12-24 02:24:24
 */
#include <iostream>
using namespace std;
class que {
private:
    int *data;

public:
    int front, rear;
    int maxSize;
    que(int s = 10) {
        maxSize = 10;
        data = new int[maxSize];
        front = 0;
        rear = 0;
    }

    ~que() {
        delete []data;
    }

    bool empty() {
        return front == rear;
    }

    int getHead() {
        return data[(front+1) % maxSize];
    }

    void doubleSpace() {
        int *tmp = data;
        data = new int[2 * maxSize];
        for (int i = 1; i < maxSize; ++i)
            data[i] = tmp[(front + i) % maxSize];
        front = 0; rear = maxSize - 1;
        maxSize *= 2;
        delete tmp;
    }

    int dequeue() {
        front = (front + 1) % maxSize;
        return data[front];
    }

    void enqueue(int x) {
        if ((rear + 1) % maxSize == front) doubleSpace();
        rear = (rear + 1) % maxSize;
        data[rear] = x;
    }
};

int main() {
    int s, n;
    cin >> s >> n;
    int *res_1 = new int[n], *res_2 = new int[n];
    que q(s);
    for (int i = 0; i < n; i++) {
        int op;
        cin >> op;
        if (op == 0) {
            int x;
            cin >> x;
            q.enqueue(x);
            res_1[i] = q.rear;
            res_2[i] = (q.rear - q.front + q.maxSize) % q.maxSize;
        }
        else {
            if (!q.empty()) {
                q.dequeue();
            }
            res_1[i] = (q.front)%q.maxSize;
            res_2[i] = (q.rear - q.front + q.maxSize) % q.maxSize;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << res_1[i] << ' ' << res_2[i] << endl;
    }
    delete[]res_1;
    delete[]res_2;
    return 0;
}