#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N,M;
	scanf("%d %d",&N, &M);
	
	int A[N+5]= {0,};
	for(int i=0; i<N; i++)
	{
		scanf("%d",A+i);
	}
	
	int s=0, e=0, a=0;
	long long int sum = 0;
	while(1)
	{		
		if(sum >= M)
			sum -= A[s++];
		else if(e==N)
			break;
		else
			sum += A[e++];
		
			
		if(sum==M)
			a++;
	}
	
	printf("%d",a);
	
	return 0;
}
