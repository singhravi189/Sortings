#include<stdio.h>
//Merge the SubArrays into main array
void Merge(int *arr,int l,int m,int r)
{
	int n1=m-l+1;
	int n2=r-m;
	int L[n1],R[n2];
	for(int i=0;i<n1;i++)
		L[i]=arr[l+i];
	for (int j=0;j<n2;j++)
		R[j]=arr[m+1+j];
	int i=0;
	int j=0;
	int p=l;
	while(i<n1&&j<n2)
	{
		if(L[i]<=R[j])
		{
			arr[p]=L[i];
			i++;
		}
		else
		{
			arr[p]=R[j];
			j++;
		}
		p++;
	}
	while(i<n1)
	{
		arr[p]=L[i];
		i++; 
		p++;	
	}
	while(j<n2)
	{
		arr[p]=R[j];
		j++;
		p++;
	}
}
//Recursive Calls
void MergeSort(int * arr,int l,int r)
{
	if(l<r)
	{
		int m=(l+r)/2;
		MergeSort(arr,l,m);
		MergeSort(arr,m+1,r);
		Merge(arr,l,m,r);
	}
}
//Main Function
int main()
{
	int arr[]={11,8,7,9,5,6,4,3,2,1};
	int len=sizeof(arr)/sizeof(arr[0]);
	MergeSort(arr,0,len-1);
	for(int i=0;i<len;i++)
		printf("%d\n",arr[i]);
	return 0;
}
//EOF
