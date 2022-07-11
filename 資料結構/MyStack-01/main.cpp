#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;
template<typename T>
class MyStack {
private:
    T* buf;
    int tp;
    int cpcty;

public:
    MyStack() {
        tp = -1;
        cpcty = 1;
        buf = new T[cpcty];
    }

    ~MyStack() {
        delete [] buf;
    }

    void push(const T& e);
    void pop();
    T top();
    int size() {
        return tp+1;
    }
    void show();
};

template<typename T>
void MyStack<T>::push(const T& e) {
    if ( tp+1>=cpcty) {
        //double strategy
        T* tmp = new T[cpcty*2];
        for (int i=0; i<=tp; ++i)
            { tmp[i] = buf[i];
            }
        delete [] buf;
        cpcty *=2;
        buf = tmp;
    }
    ++tp;
    buf[tp] = e;
}

template<typename T>
void MyStack<T>::pop() {
    if (tp<0)
        return;
    --tp;
}

template<typename T>
T MyStack<T>::top() {
    if( tp<0 )
        return T();
    return buf[tp];
}

template<typename T>
void MyStack<T>::show() {
    cout << "capacity=" << cpcty
         << "  size= " << tp+1 << endl;
    cout << "[";
    for ( int i=0; i<=tp; ++i )
        { cout << setw(4) << buf[i];
            if( i!=tp )
                cout << ",";
        }
        cout << "]" << endl;
}

int main()
{   MyStack<int> stk1;
    const int n=20;
    int data[n];
    srand( (unsigned)time(NULL) );
    for( int i=0; i<n; ++i)
        {   data[i] = rand()%100;
            cout << data[i] << ",";
            stk1.push(data[i]);
        }
    cout << endl;

    stk1.show();

    for ( int i=0; i<3; ++i )
        { cout << stk1.top() << endl;
          stk1.pop();
        }
        stk1.show();

        MyStack<string> stk2;
        stk2.push("abc");
        stk2.push("xyz");
        stk2.push("123");
        stk2.show();

        stk2.pop();
        stk2.show();
        return 0;
}
