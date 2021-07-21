#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	string S, T;
	cin >> S >> T;
	
	vector<int> idx['Z'-'A'+1];
	
	int lenS = S.length();
	int lenT = T.length();
	
	for(int i=0; i<lenT; i++)
		idx[T[i] - 'a'].push_back(i);
	
	int ans = 1;
	
	int pS = 0, pT = 0;
	
	while(pS < lenS)
	{
		int cur = S[pS] - 'a';
		
		if(!idx[cur].size())
		{
			printf("-1");
			return 0;
		}
		
		int p = lower_bound(idx[cur].begin(), idx[cur].end(), pT) - idx[cur].begin();
		
		if(p >= idx[cur].size())
		{
			ans++;
			p=0;
		}
		
		pT = idx[cur][p] + 1;
		pS++;
	}
	
	printf("%d",ans);
	
	return 0;
}
