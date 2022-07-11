#include<iostream>
using namespace std;
int n,m,num[100],step[100],t=0;
void perm(int,int);
int main(){
cout<<"請輸入perm(n)"<<endl;
  cin>>n;
    for(int i=0;i<n;i++){
      num[i]=i+1;
    }
    perm(0,0);
    cout<<"有"<<t<<"種排列"<<endl;
}
void perm(int curStep,int start){

  if (curStep==n){
        cout<<"{ ";
    for(int i=0;i<n;i++){
      cout <<num[step[i]]<<" ";
    }
    cout<<"}";
    t++;
    cout << endl;
  }
  for(int i=0;i<n;i++){
    bool success=true;
    for(int j=0;j<curStep;j++){
      if (step[j]==i){
        success=false;
        break;
      }
    }
    if (success) {
      step[curStep]=i;
      perm(curStep+1,start+1);
    }
  }
}
