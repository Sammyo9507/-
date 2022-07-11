#include <iostream>
using namespace std;
void comb(int [],int);
int step[100],num[100],t=0;
int n,m;
int main(){
    cout<<"請輸入comb(n,m)"<<endl;
   cin>>n>>m;
    for(int i=0;i<n;i++){
       num[i]=i+1;
    }
  comb(num,m);
  cout<<"有"<<t<<"種組合"<<endl;
  return 0;
}
void comb(int num[],int m){
   long long int a=1,b=1;
  for(int i=m+1;i<=n;i++){
    a=a*i;
  }
  for(int i=1;i<=n-m;i++){
    b=b*i;
  }
  int count=a/b;
  for(int p=0;p<count;p++){
        cout<<"{";
    for(int i=0;i<m;i++){
        cout<<num[i]<<" ";
        if(i==m-1){
            if(num[i]<n){
            num[i]+=1;}
            else{
                int g=m-2,z=n-1;
                while(true){
                    if(num[g]<z){
                      num[g]+=1;
                      for(int k=g+1;k<m;k++){
                        num[k]=num[k-1]+1;
                      }
                     break;
                    }
                    else{g--;z--;
                    }

                }
            }

        }
    }
    cout<<"}"<<endl;
  }
  t=count;
}

