
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
    bool empty(){
    if(size()==0){return true;}
    return false;
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
