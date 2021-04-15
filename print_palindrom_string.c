#include<stdio.h>
#include<string.h>
#include<malloc.h>

void print(char *str,int start,int end)
{
	int i;
	for(i=start;i<=end;i++)
		printf("%c ",str[i]);
	
}

int long_palindrom(char *str)
{
	int n=strlen(str),i,j,k;

	int **table=(int **)malloc(n*sizeof(int *));
	for(i=0;i<n;i++)
		table[i]=(int *)malloc(n*sizeof(int));
//	memset(table,0,sizeof(table));
	int maxlen=1;
	for(i=0;i<n;i++)
		table[i][i]=1;
	int start=0;
	for(i=0;i<n-1;i++)
	{
		if(str[i]==str[i+1])
		{
			table[i][i+1]=1;
		start=i;
		maxlen=2;
		}
	}
	for(k=3;k<=n;++k)
	{
		for(i=0;i<n-k+1;++i)
		{
			j=i+k-1;
			if(table[i+1][j-1] && str[i]==str[j])
			{
				table[i][j]=0;
			if(k>maxlen)
			{
			start=i;
			maxlen=k;
			}
		        }
		}
	}

	printf("longest palindromic string\n");
	print(str,start,start+maxlen-1);

	return maxlen;

}


int main()
{
	char arr[]="malyamma";
	printf("\nlongest string size=%d\n",long_palindrom(arr));
}
