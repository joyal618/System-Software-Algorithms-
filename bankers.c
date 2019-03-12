#include<stdio.h>

struct process{
	int alloc[10],max[10],need[10],flag;
}p[10];



void main()
{
	int i,j,k,b,pno,rno,g,cnt,f1,id,new,r,seq[10],avail[10],req[10],opt,flg;
	char y,n;
	printf("\nEnter the number of processes: ");
	scanf("%d",&pno);
	printf("Enter the number of resources: ");
	scanf("%d",&rno);
	for(i=0;i<pno;i++)
	{
		printf("\nEnter Allocation of Process %d: \n\n",i);
		for(j=0;j<rno;j++)
		{
			printf("Enter Allocation of resourcse %d: ",j+1);
			scanf("%d",&p[i].alloc[j]);
		}
		printf("\nEnter Maximum demand of Process %d: \n\n",i);
		for(j=0;j<rno;j++)
		{
			printf("Enter Max demand of resourcse %d: ",j+1);
			scanf("%d",&p[i].max[j]);
		}
		p[i].flag=0;
	}
	printf("\nEnter available resources:\n\n");
	for(j=0;j<rno;j++)
	{
		printf("Enter available of resourcse %d: ",j+1);
		scanf("%d",&avail[j]);
	}
	printf("\nDo you want to enter a new request to any process(y/n): ");
	scanf("%s",&opt);
	if(opt=='y')
	{
		printf("Enter process number for entering new details:");
		scanf("%d",&n);
		flg=0;
		for(j=0;j<rno;j++)
		{
			printf("Enter new request details of resource %d: ",j+1);
			scanf("%d",&req[j]);
			if(req[j]>avail[j])
			{
				printf("Not possible\n");
				break;
				flg=1;
			}

		}
		if(flg==0)
		{
			for(i=0;i<rno;i++)
				p[n].alloc[i]=p[n].alloc[i]+req[i];
			for(i=0;i<rno;i++)
				avail[i]=avail[i]-req[i];
		}
	}	
	
	for(i=0;i<pno;i++)
	{
		for(j=0;j<rno;j++)
			p[i].need[j] = ( p[i].max[j] - p[i].alloc[j] );
			if(p[i].need[j]<0)
				p[i].need[j]=0;
	}

	f1=0;
	
	for(cnt=0;cnt<pno;)
	{
		g=0;
		for(j=0;j<pno;j++)
		{
			if(p[j].flag==0)
			{
				b=0;
				for(k=0;k<rno;k++)
				{
					if(avail[k]>=p[j].need[k])
						b=b+1;
					else
						b=b-1;
				}
				if(b==rno)
				{
					seq[f1++]=j;
					p[j].flag=1;
					for(k=0;k<rno;k++)
						avail[k]=avail[k]+p[j].alloc[k];
					g=1;
					cnt++;
				}
			}
		}
		if(g==0)
		{
			printf("\nSystem is in unsafe state.\n");
			break;
		}
	}
	if(g==1)
	{
		printf("\nSystem is in safe state.\nSequence:\t");
		for(i=0;i<pno;i++)
			printf("P%d\t",seq[i]);
		printf("\n\n");
	}
	printf("Process\tAlloc\t\t\tMax\t\t\tNeed\n");  
	for(i=0;i<pno;i++)
	{
		printf("P%d\t",i,p[i].max,p[i].alloc,p[i].need);
		for(j=0;j<rno;j++)
			printf("%d\t",p[i].alloc[j]);
		for(j=0;j<rno;j++)
			printf("%d\t",p[i].max[j]);
		for(j=0;j<rno;j++)
			printf("%d\t",p[i].need[j]);
		printf("\n");
	}
}		
	
	

