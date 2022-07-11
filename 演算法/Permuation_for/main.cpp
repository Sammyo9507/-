#include <iostream>
#include<algorithm>
using namespace std;
bool next_permutation(int* first,int* last)
{
    if(first == last)
        return false;
    int* i = first;
    ++i;
    if(i == last)
        return false;
    i = last;
    --i;
    while(true) {
        int* ii = i;
        --i;
        if(*i < *ii) {
            int* j = last;
            while(!(*i < *--j));
            iter_swap(i, j);
            reverse(ii, last);
            return true;
        }
        if(i == first) {
            reverse(first, last);
            return false;
        }
    }
}
int main() {
	int n, k;
	cout << "perm(n):" << endl;
	cin >> n ;
	int* perm = new int[n];
	for (int i = 0; i < n; i++)
		{perm[i] = i+1;}
	do{
        cout<<"{ ";
		for (int i = 0; i < n; i++){
			cout << perm[i]<<" ";
		}
		cout<<"}"<<endl;
	}
	while (next_permutation(perm,perm+n));
	delete[] perm;
	return 0;
}
