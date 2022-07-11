#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <string>
#include <queue>

using namespace std;

template<typename T>
class Node {
private :
    T data;
    Node<T> *father, *lSon , *rSon;
    int state;
public :
    Node(const T& e){
    data = e;
    father = lSon = rSon = NULL;
    }
    void setData(const T& e){
    data = e;
    }
    T& getData(){
    return data;
    }
    void setFather(Node<T>* p) {
    father =p;
    }
    Node<T>* getFather(){
    return father;
    }
    void setLSon(Node<T>* p){
    lSon = p;
    }
    Node<T>* getLSon(){
    return lSon;
    }
    void setRSon(Node<T>* p){
    rSon = p;
    }
    Node<T>* getRSon() {
    return rSon;
    }
    void setState(int s){
    state =s;
    }
    int getState() {
    return state;
    }
};


template<typename T>
class MyHeapTree{
private:
     int sz;
     Node<T> *root,*lastNode;

bool isLson(Node<T> *nd){
    if(nd==NULL||nd==root) return false;
    Node<T>* ndf=nd->getFather();
    return ndf->getLSon()==nd;
}
bool isRson(Node<T> *nd){
    if(nd==NULL||nd==root) return false;
    Node<T>* ndf=nd->getFather();
    return ndf->getRSon()==nd;
}
Node<T>* getBrother(Node<T> *nd)
    {if(nd==NULL||nd==root) return NULL;
     Node<T>* tmpf=nd->getFather();
     return (isLson(nd)?  tmpf->getRSon() : tmpf->getLSon() );
    }
Node<T>* nextLastNode(const T& e) {
    Node<T>* tmp = new Node<T>(e);
    if(sz==0)
      {return tmp;
      }
    if(sz==1)
      {root->setLSon(tmp);
        tmp->setFather(root);
        return tmp;
      }

    Node<T>* now=lastNode;
    if( isLson(now) )
       { Node<T> *tmpF=now->getFather();
         tmpF->setRSon(tmp);
         tmp->setFather(tmpF);
         return tmp;
       }
    for( ; !isLson(now) && now!=root; )
      { now = now ->getFather();
      }
    if(now!=root )
      {now = now->getFather()->getRSon();
      }
    for(; now->getLSon()!=NULL; )
       { now = now->getLSon();
       }
       now->setLSon(tmp);
       tmp->setFather(now);
       return tmp;
    }
Node<T>* prevNode(Node<T>* nd)  {
   if(nd==NULL||nd==root)
    {return NULL;}
   Node<T>* now=nd;
   if(isRson(now))
   {return now->getFather()->getLSon();
   }
   for(;now!=root;now=now->getFather())
      {if(isRson(now))
         break;
      }
   if(now!=root)
   {now=now->getFather()->getLSon();
   }
   for(;now->getRSon()!=NULL;)
   {now=now->getRSon();
   }
   return now;
}
Node<T>* prevLastNode(){
return prevNode(lastNode);
}

void swapData(Node<T>* nd1,Node<T>* nd2)
 {T t= nd1->getData();
  nd1->setData(nd2->getData());
  nd2->setData(t);
 }

void delNode(Node<T>* nd)
{if(nd==root)
        {root=NULL;}
 if(isLson(nd))
        {nd->getFather()->setLSon(NULL);}
 if(isRson(nd))
        {nd->getFather()->setRSon(NULL);}
 delete nd;
 --sz;
}
public:
   MyHeapTree(){
   root=lastNode=NULL;
   sz=0;
   }
   ~MyHeapTree(){
   prevSeq();
   }
void push(const T& e){
   lastNode=nextLastNode(e);
   if(sz==0)
     {root=lastNode;
     }
    for(Node<T>* now=lastNode;now!=root;now=now->getFather())
      {if(now->getData()>=now->getFather()->getData())
           {break;}
       swapData(now,now->getFather());
      }
      ++sz;
      return;
   }

   void pop(){
    if(sz==0)return;
    if(sz==1)
       {delete root;
        root=lastNode=NULL;
        sz=0;
        return;
       }
    Node<T>* newLastNode=prevLastNode();
    root->setData(lastNode->getData());
    delNode(lastNode);
    lastNode= newLastNode;

    Node<T>* now=root;
    for(;now!=NULL;)
    {Node<T> *tmpL=now->getLSon();
     Node<T> *tmpR=now->getRSon();
     Node<T> *to;
     if(tmpL==NULL)
       {break;
       }
     if(tmpR==NULL)
       {if(now->getData()<=tmpL->getData())
                {break;
                }
          to=tmpL;
       }
     else{
        to=(tmpL->getData()<=tmpR->getData() ?tmpL:tmpR);
        if(now->getData()<= to->getData())
           {break;
           }
        }
     swapData(now,to);
     now=to;
    }
   }


T top() {
        if(sz==0)
        {return T();
        }
        return root->getData();
    }

void prevSeq(bool isShow=true) {
    Node<T> *now = lastNode, *tmp;
    for( ; now!=NULL; )
      {if(isShow)
          {cout<<now->getData()<<",";
          }
          tmp = now;
          now =lastNode =prevNode(now);
          delNode(tmp);
      }
      if(isShow)
      {cout<<endl;
      }
    }
void show(){
     int cnt=0,level=0;
     cout<<"[root,lastNode,size]=["
         <<root->getData()<<","<<lastNode->getData()<<","<<sz<<"]\n";

     Node<T> *now;
     queue<Node<T>*> q;
     q.push(root);
     while(!q.empty())
     {   now=q.front();
         q.pop();
         cout<<now->getData()<<",";
         ++cnt;
         if(cnt==pow(2,level+1)-1)
         {++level;
             cout<<endl;
         }
         if(now->getLSon()!=NULL)
         {q.push(now->getLSon());
         }
         if(now->getRSon()!=NULL)
         {q.push(now->getRSon());
         }
     }
   }
};

void showArray(int *a,int n){
  for(int i=0;i<n;++i)
  {if(i%10==0)
   {
       cout<<endl;
   }
      cout<<setw(6)<<a[i];
  }
  cout<<endl;
  cout<<"---------------------------"<<endl;
}
int main()
{  srand((unsigned)time(NULL));
   const int n=20;
   int data[n];
   for(int i=0;i<n;++i)
   {data[i]=rand()%100+1;
   }
   showArray(data,n);
   MyHeapTree<int> hp;
   for(int i=0;i<n;++i)
   {hp.push(data[i]);
   }
   hp.show();
   cout<<endl<<endl;

   for(int i=0;i<n;++i)
   {cout<<hp.top()<<",";
    hp.pop();
   }
    cout<<endl;
  return 0;
}
