#include<iostream>
#include<algorithm>
using namespace std;
int n,num[100],step[100],t=0;
void subset(int,int,int);
int main(){
    cout<<"請輸入n"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
      num[i]=i+1;
    }
 for(int i=n;i>0;i--){
   subset(0,0,i);}
   cout<<"{ }"<<endl;
   cout<<"有"<<t+1<<"種子集"<<endl;
}
//子集 subset(k)=subset(k-1)+{subset(k-1)集合+k} for(k=0.1.2...n)
void subset(int curStep,int start,int g){//curStep選取幾個,start num起始,g subset(s)+g
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
