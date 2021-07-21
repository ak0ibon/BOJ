#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector<int> arr;
	int N,M;
	scanf("%d %d",&N, &M);
	arr.resize(N+M);
	for(int i=0;i<N+M;i++)
		scanf("%d",arr.begin()+i);
	sort(arr.begin(), arr.end());
	for(int a : arr)
		printf("%d ",a);
	return 0;
}
