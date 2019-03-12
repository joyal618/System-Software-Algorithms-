#include<stdio.h>

void main()
{
	int end=199,t[20],n,i,j=0,temp,s,arr[20],a,sum=0,k;

	printf("Enter the number of tracks: ");
	scanf("%d",&n);

	t[0]=0;
	t[n+2]=end;

	printf("Enter the head position: ");
	scanf("%d",&s);
	t[1]=s;

	printf("Enter tracks:\n");
	for(i=2;i<n+2;i++)
	{
		printf("Enter track %d: ",i-1);
		scanf("%d",&t[i]);
	}
	

	//Sorting
	for(i=0;i<n+3;i++)
    	{
      		for(j=0;j<n-i+1;j++)
		{
	  		if( t[j] > t[j+1] )
			{
	 			temp = t[j];
		  		t[j] = t[j+1];
				t[j+1] = temp;
			}
		}
    	}
	
	for(i=0;i<n+3;i++)
		if(t[i]==s)
		{
			k=i;
			break;
		}

	
	if( ( end - s ) > s )
	{
		for(i=k;i>0;i--)
		{
			arr[j]=t[i];
			j++;
		}		
		for(i=k+1;i<n+2;i++)
		{
			arr[j]=t[i];
			j++;
		}
	} 
	else
	{
		for(i=k;i<n+2;i++)
		{
			arr[j]=t[i];
			j++;
		}		
		for(i=k-1;i>0;i--)
		{
			arr[j]=t[i];
			j++;
		}
	} 
	printf("\n");

	for(i=0;i<j-1;i++)
	{
		a = arr[i]-arr[i+1];
		if(a<0)
			a=(a*(-1));
		sum=sum+a;
	} 
	printf("Traversed track is: \n\t");
	for(i=0;i<j;i++)
		printf("%d\t",arr[i]);
	printf("\nTotal head movements is %d.\n",sum);
}
	
