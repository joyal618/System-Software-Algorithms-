#include<stdio.h>

void main()
{
	int n,i,t[50],s,sum=0,a=0;
	printf("Enter the number of tracks: ");
	scanf("%d",&n);
	printf("Enter the head position: ");
	scanf("%d",&t[0]);
	printf("Enter tracks:\n");
	for(i=1;i<n+1;i++)
	{
		printf("Enter track %d: ",i);
		scanf("%d",&t[i]);
	}
	for(i=1;i<n+1;i++)
	{
		a=t[i]-t[i-1];
		if(a<0)
			a=a*-1;
		sum=sum+a;
	}
	printf("Traversed track is: \n\t");
	for(i=0;i<n+1;i++)
		printf("%d\t",t[i]);
	printf("\nTotal head movements is %d.\n",sum);
}
