#include<iostream>
#define size 4
using namespace std;
int is_safe(int (*a)[size],int col,int row,int i)
{
	if(col<0)
		return 1;
	if(a[row][col])
		return 0;
	if((a[row-i][col]) && (row-i>=0))
		return 0;
	if((a[row+i][col]) && (row+i<size))
		return 0;
	return is_safe(a,col-1,row,i+1);
}
bool queen(int arr[size][size],int col)
{
	int i;
	if(col>=size)
		return 1;
	for(i=0;i<size;i++)
	{
				arr[i][col]=1;
		if(is_safe(arr,col-1,i,1))
				{
				if(queen(arr,col+1))
				return 1;
				}
				arr[i][col]=0;
	}

return 0;
}

void solve()
{
	int arr[size][size];
	int i,j;
	for(i=0;i<size;i++)
		for(j=0;j<size;j++)
			arr[i][j]=0;
	int res=queen(arr,0);
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
			cout<<arr[i][j]<<" ";

		cout<<endl;
	}
}
int main()
{
	solve();
	return 0;
}
