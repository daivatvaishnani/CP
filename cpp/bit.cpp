#include<bits/stdc++.h>
using namespace std;
 
vector< vector<int> > v;
int flag=0;
void insert(int a,int b)
{
//	a--;b--;
	v[a].push_back(b);
	if(flag=1);
		v[b].push_back(a);
}
 
int main()
{
	v.resize(5); //node value
	flag=0;
	insert(0,1);
	insert(0,4);
	insert(1,2);
	insert(1,3);
	insert(1,4);
	insert(2,3);
	insert(3,4);
 
	for(auto i:v)
	{
		for(auto a:i)
			cout<<a<<" ";
		cout<<endl;
	}
	return 0;
}