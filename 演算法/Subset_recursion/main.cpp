#include<iostream>
#include<algorithm>
using namespace std;
int n,num[100],step[100],t=0;
void subset(int,int,int);
int main(){
    cout<<"�п�Jn"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
      num[i]=i+1;
    }
 for(int i=n;i>0;i--){
   subset(0,0,i);}
   cout<<"{ }"<<endl;
   cout<<"��"<<t+1<<"�ؤl��"<<endl;
}
//�l�� subset(k)=subset(k-1)+{subset(k-1)���X+k} for(k=0.1.2...n)
void subset(int curStep,int start,int g){//curStep����X��,start num�_�l,g subset(s)+g
    int j;
  if (curStep==g){
    cout<<"{ ";
    for(int i=0;i<g;i++){
      cout <<num[step[i]]<<" ";
    }
    cout<<" }"<< endl;
    t++;
  }
 else
 {for(j=start;j<n;j++){
      step[curStep]=j;
      subset(curStep+1,j+1,g--);
    }
}
}
