/**
 * @Author: George Lu
 * @Date:   2021-11-19 16:44:05
 * @Last Modified by:   George Lu
 * @Last Modified time: 2021-12-24 02:24:31
 */
#include <iostream>
//#include "priorityQueue.h"
//#include "priorityQueue.cpp"

using namespace std;

int gcd(int a,int b) {
    return b>0 ? gcd(b,a%b):a;
}

class fraction {
public:
    int  numerator;
    int denominator;

    friend ostream & operator<<(ostream &os, fraction &f);

    fraction(int a = 1, int b = 1) : numerator(a), denominator(b) {};

    fraction(const fraction& f) : numerator(f.numerator), denominator(f.denominator) {};

    operator double() {
        return (double)numerator / (double)denominator;
    }

    void operator=(const fraction &f) {
        numerator = f.numerator;
        denominator = f.denominator;
    }
};

ostream & operator<<(ostream &os, fraction &f) {
    os << f.numerator << '/' << f.denominator;
    return os;
}
template <class Type>
class priorityQueue {
private:
    int currentSize;
    Type *array;
    int maxSize;

    void doubleSpace();
    void buildHeap( );
    void percolateDown( int hole );
public:
    priorityQueue( int capacity = 100 ) {
        array = new Type[capacity];
        maxSize = capacity;
        currentSize = 0;
    }
    priorityQueue(const Type data[], int size );
    bool isEmpty( ) const {
        return currentSize == 0;
    }
    Type getHead() {
        return array[1];
    }
    void enQueue(Type & x );
    Type deQueue();
    ~priorityQueue() {
        delete [] array;
    }
};
template <class Type>
void priorityQueue<Type>::percolateDown( int hole ){
    int child;
    Type tmp = array[ hole ];
    for( ; hole * 2 <= currentSize; hole = child ){
        child = hole * 2;  //child为最小孩子下标
        if(child != currentSize && array[ child + 1 ] > array[ child ]) child++;
        if( array[ child ] > tmp) array[ hole ] = array[ child ];
        else break;
    }
    array[ hole ] = tmp;
}

template <class Type>
void priorityQueue<Type>::buildHeap( )
{  for ( int i = currentSize / 2  ; i > 0; i-- )
        percolateDown( i );
}

template <class Type>
priorityQueue<Type>::priorityQueue( const Type *items, int size ): maxSize(size + 10 ),  currentSize(size){
    array = new Type[maxSize];
    for( int i = 0; i < size; i++ ) array[ i + 1 ] = items[ i ];
    buildHeap();
}

template <class Type>
Type priorityQueue<Type>::deQueue()
{ Type minItem;
    minItem = array[ 1 ];
    array[ 1 ] = array[ currentSize-- ];  //先保证结构性
    percolateDown( 1 );
    return minItem;
}
template <class Type>
void priorityQueue<Type>::enQueue( Type &x ) {
    if( currentSize == maxSize - 1 )  doubleSpace();
    // 向上过滤
    int hole = ++currentSize;  //先不放x
    for( ; hole > 1 && x > array[ hole / 2 ]; hole /= 2 ) array[ hole ] = array[ hole / 2 ];
    array[ hole ] = x; // hole == 1 或者 x > array[ hole / 2 ];
}

template <class Type>
void priorityQueue<Type>::doubleSpace() {
    //maxSize = (maxSize-1)*2 + 1;
    Type *item = array;
    array = new Type [(maxSize-1)*2 + 1];
    for (int i = 1; i < maxSize; i++) {
        array[i] = item[i];
    }
    maxSize = (maxSize-1)*2 + 1;
}
int main() {
    int k, n;
    cin >> n >> k;
    fraction tmp[n-1];
    for (int i = n; i >= 2; i--) {
        fraction t(i-1,i);
        tmp[n-i] = t;
    }
    priorityQueue<fraction> que(tmp, n-1);
    while (k-1) {
        k--;
        fraction f = que.deQueue();
        int a = f.numerator-1;
        int b = f.denominator;
        while(a>0 && gcd(a,b) != 1) a--;
        if (a == 0) continue;
        fraction t(a,b);
        que.enQueue(t);
    }
    fraction res = que.getHead();
    cout << res;
    return 0;
}