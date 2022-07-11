#include <iostream>
#include <iomanip>
using namespace std;
template<typename T>
class Node1{
 private:
 T e;
 Node1<T>* next;
 public:
 Node1(){
 e = T();
 next = NULL;
 }
 Node1(const T& data);
 T& getData();
 void setData(const T& data);
 Node1* getNext();
 void setNext(Node1* p);
};
template<typename T>
Node1<T>::Node1(const T&data){
 e = data;
}
template<typename T>
T& Node1<T>::getData(){
 return e;
}
template<typename T>
void Node1<T>::setData(const T& data){
 e = data;
 return;
}

template<typename T>
Node1<T>* Node1<T>::getNext(){
 return next;
}

template<typename T>
void Node1<T>::setNext(Node1* p){
 next = p;
 return;
}

template<typename T>
class SLL{
 private:
 Node1<T> *first,*last;
 int sz;
 public:
  SLL(){
 first = last = NULL;
 sz = 0;
 }
 void push_back(const T& data);
 void pop_back();
 int size(){
 return sz;
 }
 T& getLast(){
 return last->getData();
 }
 //ex.
 void push_front(const T data);
 void pop_front() ;
 T& getFirst() {
 return first->getData();
 }

 void show();
};

template<typename T>
void SLL<T>::push_back(const T& data){
 Node1<T>* tmp = new Node1<T>(data);
 if(sz == 0)
 {
  first = last = tmp;
  sz = 1;
  return;
 }
 last->setNext(tmp);
 last = tmp;
 sz++;
}
template<typename T>
void SLL<T>::pop_back(){
 if( sz==0 )
 {
 return;
 }
 if(sz==1){
   delete last;
 first = last = NULL;
 sz = 0;
 return;
 }

 Node1<T>* newLast;
 for( newLast=first; newLast->getNext()!=last;){
 newLast = newLast->getNext();
 }
 delete last;
 newLast->setNext(NULL);
 last = newLast;
 sz--;
}

template<typename T>
void SLL<T>::show(){
 cout<<"(first, last, sz)=("<<getFirst()<<","
          <<getLast()<<","<<sz<<")"<<endl;
 cout<<"[";
 for(Node1<T>* p=first; p!=last->getNext();p=p->getNext()){
 cout<<p->getData();
 if( p!=last ){
  cout<<",";
 }
 }
 cout<<"]"<<endl;
}
template<typename T>
void SLL<T>::push_front(const T data){
 Node1<T>* newNode = new Node1<T>(data);
 newNode->setNext(first);
 first=newNode;
 sz++;
}
template<typename T>
void SLL<T>::pop_front(){
 if(sz==0)
 {
 return;
 }
 if(sz==1){
 delete first;
 first=last=NULL;
 sz=0;
 return;
 }

 Node1<T>* newFirst;
 newFirst=first->getNext();
 delete first;
 first=newFirst;
 sz--;
}

template<typename T>
class MyStackSLL{
 private:
 SLL<T> buf;
 public:
 MyStackSLL(){
  buf = SLL<T>();
 }
 void push(const T& data){
  buf.push_back(data);
 }
 void pop(){
  buf.pop_back();
 }
 T& top(){
  return buf.getLast();
 }
 void show(){
  buf.show();
 }
  void front(const T data){
  buf.push_front(data);
 }
 void ppopfront(){
  buf.pop_front();
 }
};

template<typename T>
class MyStackSLL1{
 private:
 SLL<T> buf;
 public:
 MyStackSLL1(){
  buf = SLL<T>();
 }
 void push(const T& data){
 buf.push_front(data);
 }
 void pop(){
 buf.pop_front();
 }
 T& top(){
 return buf.getFirst();
 }
 void show(){
 buf.show();
 }
};
int main(){
 MyStackSLL<int> stk;
 stk.push(22);
 stk.show();
 stk.push(13);
 stk.show();
 stk.push(46);
 stk.front(11);
 stk.show();
 stk.front(18);
 stk.show();
 stk.ppopfront();
 stk.show();
 stk.front(99);
 stk.show();
 return 0;
}
