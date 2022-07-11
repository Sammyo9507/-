#include<iostream>
#include<algorithm>
#include<iomanip>
#include <cmath>
using namespace std;
int n,num[100],step[100],t=0;
void subset(int [],int);
int main(){
    cout<<"請輸入n"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
      num[i]=i+1;
    }
   subset(num,n);
   cout<<"有"<<t<<"種子集"<<endl;
}
void subset(int arr[],int n){
   int count = pow(2, n);
    for (int i = 0; i < count; i++) {
        cout<<"{ ";
        for (int j = 0; j < n; j++) {
            if ((i & (1 << j)))//利用2進制來分辨當i的第j位為1時
                cout << arr[j] << " ";
        }
        cout<<"} "<<endl;
    }
   t=count;
}
