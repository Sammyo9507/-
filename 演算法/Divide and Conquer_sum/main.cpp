#include <iostream>
using namespace std;
int mysum(int arr[],int i,int len){
    int m=0;
    for (i; i<len; i++) {
        m+=arr[i];
    }
    return m;
return mysum(arr,0,len/2)+mysum(arr,len/2,len);
}
int main()
{	int arr[]={ 1, 5, 4, 2, 6, 8, 7, 3, 9, 10 };
	int len = (int) sizeof(arr) / sizeof(*arr);
    int x=mysum(arr,0,len);
    cout<<"sum = "<<x;
    return 0;
}
