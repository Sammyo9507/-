#include <iostream>
using namespace std;
template<typename T>
void bubble_sort(T arr[], int len) {
	int i, j;
	for (i = 0; i < len - 1; i++){
		for (j = 0; j < len - 1 - i; j++)
		{if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
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
int main() {
	int arr[] = { 1, 5, 4, 2, 6, 8, 7, 3, 9, 10 };
	int len = (int) sizeof(arr) / sizeof(*arr);
	int arr2[len] ;
    for (int i = 0; i < len; i++)
    {cout << arr[i] << ' ';
    arr2[i]=arr[i];}
    cout<<endl;
	bubble_sort(arr, len);
	int minpos1=minpos(arr2,arr,len);
	for (int i = 0; i < len; i++)
         cout << arr[i] << ' ';
	cout << endl;
	cout<<"³Ì¤p­È¦ì¸m: "<<minpos1<<endl;
	return 0;
}
