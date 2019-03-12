#include<stdio.h>
#include<string.h>

//Defining Structure
struct process{
	char name[20];
	int status;
	int AT,BT,WT;
	int TT;
}p[20],temp;

struct done{
	char name[20];
	int ST,CT;
}d[20];

void main()
{

	int n,i,j,k=0,flag,found,idle,x,num;
	float avgwt,avgtt,tt=0,wt=0;

	//Reading number of proccesses
	printf("Enter total number of processes: ");
	scanf("%d",&n);
	printf("\n\n");
	
	//Reading values
	for(i=0;i<n;i++)
	{
		printf("Enter process name: ");
		scanf("%s",&p[i].name);
		printf("Enter it's Arrival Time: ");
		scanf("%d",&p[i].AT);
		printf("Enter it's Burst Time: ");
		scanf("%d",&p[i].BT);
		printf("\n\n");
		p[i].status=0;
	}



	idle=0;
	i=0;
	num=0;
	
	for(x=0;x<n;)
	{
		flag=0;
		found=0;
		for(j=0;j<n;j++)
		{
			if((p[j].status==0) && (p[j].AT<=i) && found==0)
			{
				k=j;
				flag++;
				found++;
			}
			else if( p[j].status==0 && p[j].AT<=i && found>0 )
			{
				if( p[j].BT < p[k].BT )
					k=j;
			}
		}
		if( flag==0 && idle==0 )
		{
			strcpy(d[num].name,"idle");
			d[num].ST=i;
			i++;
			idle=1;
		}
		else if( flag > 0 )
		{
			if(idle==1)
			{
				d[num].CT=i;
				num++;
			}
			strcpy(d[num].name,p[k].name);
			d[num].ST=i;
			d[num].CT=i+p[k].BT;
			p[k].TT=d[num].CT-p[k].AT;
			p[k].WT=p[k].TT-p[k].BT;		
			i=d[num].CT;
			p[k].status=1;	
			k++;
			idle=0;
			num++;
			x++;
		}
		else
			i++;
	}
	
		
	//Printing Process table
	printf("PROCESS:\n\n");
	printf("Process\tAT\tBT\tWT\tTT\n");
	for(i=0;i<n;i++)
	{	
		printf("%s\t%d\t%d\t%d\t%d\n",p[i].name,p[i].AT,p[i].BT,p[i].WT,p[i].TT);
	}

	//Prinitng Done table
	printf("\nDONE:\n\n");
	printf("Process\tST\tCT\n");
	for(i=0;i<num;i++)
		printf("%s\t%d\t%d\n",d[i].name,d[i].ST,d[i].CT);

	//Printing Gauntt Chart		
	printf("\n\nGauntt Chart:\n");
	printf("\n\t------------------------------------------------------------\n");
	printf("\t|");
	for(i=0;i<num;i++)
		printf("%s\t|",d[i].name);
	printf("\n\t------------------------------------------------------------\n");	
	for(i=0;i<num;i++)
		printf("\t%d",d[i].ST);
	printf("\t%d\n",d[i-1].CT);
	
	for(i=0;i<n;i++)
		tt=tt+p[i].TT;
	avgtt=(tt/n);
	printf("\nAverage Turnaround time= %.2fms \n",avgtt);
	
	for(i=0;i<n;i++)
		wt=wt+p[i].WT;
	avgwt=wt/n;
	printf("\nAverage Waiting time= %.2fms \n",avgwt);	
		

}
	
	
