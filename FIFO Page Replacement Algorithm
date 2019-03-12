#include<stdio.h>

void main()
{
	int victim=-1,flag=0,ref[50],frm[50],pf=0,nof,nor,i,j,k;
	printf("Enter number of frames: ");
	scanf("%d",&nof);
	printf("Enter number of pages: ");
	scanf("%d",&nor);
	for(i=0;i<nor;i++)
	{
		printf("Enter of value of page %d: ",i+1);
		scanf("%d",&ref[i]);
	}
	for(i=0;i<nor;i++)
		frm[i]=-1;
	for(i=0;i<nor;i++)
	{
		flag=0;
		for(j=0;j<nof;j++)
			if(frm[j]==ref[i])
			{
				flag=1;
				break;
			}
		if(flag==0)
		{
			pf++;
			victim++;
			victim=victim%nof;
			frm[victim]=ref[i];
			for(k=0;k<nof;k++)
				printf("%d\t",frm[k]);
			printf("\n");
		}							
	}
	printf("Number of page fault is %d.\n",pf);
}
