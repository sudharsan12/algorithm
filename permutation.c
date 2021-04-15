#include<stdio.h>
#include<string.h>
void swap(char *a,char *b)
{
	char temp=*a;
	*a=*b;
	*b=temp;
}
int permutation(char *a,int start,int end)
{
	int i;
	if(start==end)
	{
		printf("%s \n",a);
		return 0;
	}
	else
	{
	for(i=start;i<=end;i++)
	{
	if((a[start]==a[i])&&(start!=i))
	{
		continue;
	}
	else
	{	
		swap(&a[start],&a[i]);
		permutation(a,start+1,end);
		swap(&a[start],&a[i]);
		
	}
	}
	}


}
int main()
{
	char  a[100],temp,temp_2,str[100];
	int i,j,n;
	printf("enter the string\n");
	scanf("%s",a);
	n=strlen(a);
	permutation(a,0,n-1);
}


