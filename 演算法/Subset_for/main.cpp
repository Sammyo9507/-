#include<iostream>
#include<algorithm>
#include<iomanip>
#include <cmath>
using namespace std;
int n,num[100],step[100],t=0;
void subset(int [],int);
int main(){
    cout<<"�п�Jn"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
      num[i]=i+1;
    }
   subset(num,n);
   cout<<"��"<<t<<"�ؤl��"<<endl;
}
void subset(int arr[],int n){
   int count = pow(2, n);
    for (int i = 0; i < count; i++) {
        cout<<"{ ";
        for (int j = 0; j < n; j++) {
            if ((i & (1 << j)))//�Q��2�i��Ӥ����i����j�쬰1��
                cout << arr[j] << " ";
        }
        cout<<"} "<<endl;
    }
   t=count;
}
