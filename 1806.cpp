#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N,M;
	scanf("%d %d",&N,&M);
	
	int A[N+5]={0,};
	
	for(int i=0;i<N;i++)
		scanf("%d",A+i);
	
	long long int sum =0;
	int s=0,e=0,a=N+1;
	
	while(s<=e)
	{
		if(sum<M)
		{
			if(e<N)
				sum+=A[e++];
			else
				break;
		}
		else sum-=A[s++];
			
		if(sum>=M)
			a=min(a,e-s);
	}
	
	printf("%d",a==N+1?0:a);	
	
	return 0;
}
