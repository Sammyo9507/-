#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;
template<typename T>
class MyHeap{
private:
    int root,lastNode;
    int cpc;
    static T guard;
    T* _pool;
public:
    MyHeap(int m=8){
      cpc=m;
      _pool=new T[cpc];
      root=lastNode=-1;
    }
    ~MyHeap(){
    delete [] _pool;
    }
    void push(const T e){
    int newLastNode=lastNode+1;
    if(newLastNode>=cpc)
    {T* tmp=new T [cpc*2];
      for(int i=0;i<=lastNode;++i)
      {tmp[i]=_pool[i];
      }
    cpc*=2;
    delete [] _pool;
    _pool=tmp;
    }
     _pool[newLastNode]=e;
     lastNode=newLastNode;

     for(int s=lastNode,f=(s-1)/2 ; _pool[f]>_pool[s]&&s!=root ; s=f,f=(s-1)/2 )
      {swap(_pool[f],_pool[s]);
      }
      root=0;
    }
    T& top(){
     if(root<0)
     {
      return guard;
     }
      return _pool[0];
    }
    void pop(){
    int newLastNode=lastNode-1;
      _pool[0]=_pool[lastNode];
     int f=root,ls=f*2+1,rs=f*2+2;
     for(; ls<=lastNode;)
     {int tg=ls;
       if( rs<=lastNode )
       { tg=(_pool[ls]<_pool[rs] ? ls:rs);
       }

       if(_pool[f]<_pool[tg])
       { break;
       }
       else
       {swap(_pool[f],_pool[tg]);
       f=tg;
       ls=f*2+1;
       rs=f*2+2;
       }
     }
     lastNode =newLastNode;
    }
   int size(){
   return lastNode+1;
   }
   void show(){
   int now=0;
   bool ok=true;
   for(int level = 0;ok;++level)
    {int cntMax=pow(2,level);
       for(int cnt=0;cnt<cntMax;++cnt)
       {if(now>lastNode)
          {ok=false;
            break;
          }
           cout<<setw(4)<<_pool[now++];
       }
       cout<<endl;
    }
    cout<<endl;
   }
};

void showArray(int * a,int n){
  cout<<"[";
  for(int i=0;i<n;++i)
  {cout<<a[i];
    if(i!=n-1)
    {
        cout<<", ";
    }
  }
  cout<<"]"<<endl;
}

template<typename T>
T MyHeap<T>::guard=T();

int main()
{  srand((unsigned)time(NULL));
   const int n=20;
   int data[n];
   int result[n];
   for(int i=0;i<n;++i)
   {data[i]=rand()%100+1;
   }
   showArray(data,n);

   MyHeap<int>aHeap;
   for(int i=0;i<n;++i)
   {aHeap.push(data[i]);
   }
   aHeap.show();

   int cnt1=0;
   for(;aHeap.size();)
   {   result[cnt1++]=aHeap.top();
       aHeap.pop();
       aHeap.show();
   }
   cout<<endl;
   showArray(result,n);

  return 0;
}
