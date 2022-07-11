#include <iostream>
using namespace std;
template<typename T>
void insertion_sort(T arr[], int len){
        int i,j,key;
        for (i=1;i<len;++i){
                key = arr[i];
                j=i-1;
                while((j>=0) && (arr[j]>key)) {
                        arr[j+1] = arr[j];
                        j--;
                }
                arr[j+1] = key;
        }
}
template<typename T>
int minpos(T arr[],T arr2[],int len){
for(int i=0; i<len ;i++){
 if(arr[i]==arr2[0]){
    return i;
    break;
 }
}
}
int main()
{	int arr[] = { 1, 5, 4, 2, 0, 8, 7, 3, 9, 10 };
	int len = (int) sizeof(arr) / sizeof(*arr);
	int arr2[len];
    for (int i = 0; i < len; i++)
    {cout << arr[i] << ' ';
    arr2[i]=arr[i];}
	cout << endl;
	insertion_sort(arr, len);
    int minpos1=minpos(arr2,arr,len);
	for (int i = 0; i < len; i++)
		cout << arr[i] << ' ';
	cout << endl;
		cout<<"³Ì¤p­È¦ì¸m: "<<minpos1<<endl;
	return 0;
}
