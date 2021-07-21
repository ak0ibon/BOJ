#include<bits/stdc++.h>
using namespace std;

#define lld long long

int main()
{
	int N;
	scanf("%d",&N);
	
	vector<lld> add, sub, vec;
	
	for(int i=0,t;i<N;i++)
	{
		scanf("%d",&t);
		if(t>0) add.push_back(t);
		else sub.push_back(t);
		vec.push_back(t);
	}
	
	sort(add.begin(), add.end());
	sort(sub.begin(), sub.end());
	sort(vec.begin(), vec.end());
	
	int l=0, r=N-1;
	lld cur = 2*1e9;
	pair<int, int> ans;
	while(l<r)
	{
		lld sum = vec[l] + vec[r];
		
		if(abs(sum)<cur) 
		{
			cur=abs(sum);
			ans={vec[l],vec[r]};
		}
		
		if(sum<0)
			l++; //더커지게 
		else  
			r--; //더작아지 
	}
	
	printf("%d %d",ans.first, ans.second);
	
/*	
	if(add.empty()) {
		printf("%d %d", sub[sub.size()-1], sub[sub.size()-2]);
		return 0;
	}
	else if(sub.empty()) {
		printf("%d %d", add[0], add[1]);
		return 0;
	}
	else {
		pair<int, int> ans;
		lld cur = 2e9;
		
		for(int i=0;i<N;i++)
		{
			lld x = vec[i];
			
			// abs(x+y) < cur.
			// 1. x+y<0인데 조건충족 -> x>0에 y<0이고 -x-y < cur. -x-cur < y < -x < 0
			// 						 -> x<0에 y!=0이고 -x-y < cur. -x-cur < y <-x
			// 2. x+y>0인데 조건충족 -> x>0에 y!=0 이고 x+y < cur. -x < y < cur-x
			// 						 -> x<0에 y>0 이고 x+y < cur. 0 < -x < y <  cur-x.
			  
			if(x>0)
			{
				//1-1.
				auto it = upper_bound(sub.begin(), sub.end(), -x-cur);
				if(it!=sub.end() && *it < -x)
				{
					cur=abs(x+*it);
					ans={x,*it};
				}
				
				//2-1.
				auto it2 = upper_bound(vec.begin(), vec.end(), -x);
				if(it2!=vec.end())
				{
					it2--;
					
					for(int j=0;j<2;j++)
					{
						if(vec.begin()<=it2 && it2<vec.end() && *it2!=x && *it2 < cur-x)
						{
							cur=abs(x+*it2);
							ans={x,*it2};
						}
						it2++;
					}
				}
			}
			else
			{
				//1-2.
				auto it = upper_bound(vec.begin(), vec.end(), -x-cur);
				if(it!=vec.end())
				{
					it--;
					
					for(int j=0;j<2;j++)
					{
						if(vec.begin()<=it && it<vec.end() && *it!=x && *it < -x)
						{
							cur=abs(x+*it);
							ans={x,*it};
						}
						it++;
					}
				}
				
				//2-2.
				auto it2 = upper_bound(add.begin(), add.end(), -x);
				if(it2!=add.end() && *it2 < cur-x)
				{
					cur=abs(x+*it2);
					ans={x,*it2};
				}				
			}
			
		}
		
		printf("%d %d",ans.first<ans.second?ans.first:ans.second, ans.first<ans.second?ans.second:ans.first);
	}
*/

	return 0;
}
