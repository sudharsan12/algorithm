// this algorithm used to find out the maximum sum of subarray is called kadane algorithm
//
// approches
//      take array first element is initial result
//      take sum of the element one by one if the sum is less thn zero make sum is zero
//      if sum is greater than zero and it is greater than max value to stored into max variable
//      similarly to iterate over array to reeturn value 

#include<stdio.h>
int kadane_algo(int *arr,int n)
{
	int i,sum,max=arr[0];
	sum=max;
	for(i=0;i<n;i++)
	{
		sum+=arr[i];
		if(sum<0)
			sum=0;
		if(max<sum)
			max=sum;
	}
	return max;
}
int main()
{
int arr[]={-2,-3,4,-1,-2,1,5,-3,4};
int n=sizeof(arr)/sizeof(arr[0]);
int result=kadane_algo(arr,n);

printf("the maximum sum of the sub array=%d \n",result);
}
