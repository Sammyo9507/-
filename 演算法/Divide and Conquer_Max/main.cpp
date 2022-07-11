#include <iostream>
using namespace std;
int mymax(int arr[],int i,int len){
    int max = arr[i];
    i=i+1;
    for (i; i<len; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
int a=mymax(arr,0,len/2);
int b=mymax(arr,len/2,len);
if(a>b)
    return a;
else
    return b;
}
int main()
{	int arr[]={ 1, 5, 4, 2, 6, 8, 7, 3, 9, 10,16,2,2,2 };
	int len = (int) sizeof(arr) / sizeof(*arr);
    int x=mymax(arr,0,len);
    cout<<"³Ì¤j­È: "<<x;
    return 0;
}
