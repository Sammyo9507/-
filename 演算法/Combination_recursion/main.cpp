#include <iostream>
using namespace std;
void comb(int,int);
int step[100],num[100],t=0;
int n,m;
int main(){
    cout<<"請輸入comb(n,m)"<<endl;
   cin>>n>>m;
    for(int i=0;i<n;i++){
       num[i]=i+1;
    }
  comb(0,0);
  cout<<"有"<<t<<"種組合"<<endl;
  return 0;
}
void comb(int curStep,int start){
  int j;
  if (curStep == m){
        cout<<"{ ";
    for(int i=0;i<m;i++){
      cout << num[step[i]] << " ";
    }
    cout<<"}";
    t++;
    cout << endl;
  }else{
    for(j=start;j<n;j++){
      step[curStep]=j;
      comb(curStep+1,j+1);
    }
  }
}
