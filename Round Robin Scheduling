#include <stdio.h>
#include <string.h>
struct process
{
	char name[20];
	int status, at, bt, wt, tt, left;
} p[20], temp;
struct done {
	char name[20];
	int st, ct;
} d[20];
void enq(int);
int deq();
int q[100], front=-1, rear=0;
void main() 
{
	int i, j, k, n, t, ls, idle=0, num=0;
	float avgwt,avgtt,tt=0,wt=0;	
	printf("\nEnter the number of processes: ");
	scanf("%d", &n);
	printf("\nEnter the time quantum: ");
	scanf("%d", &t);
	for(i=0; i<n; ++i)
	{ 
		printf("\nProcess: %d \n",i+1);
		printf("Enter the process name: ");
		scanf("%s", &p[i].name);
		printf("Enter the process arrival time: ");
		scanf("%d", &p[i].at);
		printf("Enter the process burst time: ");
		scanf("%d", &p[i].bt);
		p[i].status=0;
		p[i].left=p[i].bt;
	}
	i=0;
	for(ls=0; ls<30; ++ls)
	{
		for(j=0; j<n; ++j)
		{
			if(p[j].status==0 && p[j].at<=i)
			{
				enq(j);
				p[j].status=1;
			}
		}
		if(idle==0 && front==-1)
		{
			strcpy(d[num].name, "idle");
			d[num].st = i;
			i++;
			idle = 1;
		}
		if(front!=-1)
		{
			if(idle==1)
			{
				d[num].ct = i;
				num++;
				idle=0;
			}
			k=deq();
			strcpy(d[num].name, p[k].name);
			d[num].st=i;
			if(p[k].left<=t)
			{
				d[num].ct = i + p[k].left;
				p[k].tt = d[num].ct - p[k].at;
				p[k].wt = p[k].tt - p[k].bt;
				i = d[num].ct;
				p[k].status=2;
				num++;
			}		
			else
			{
				d[num].ct = i + t;
				i = d[num].ct;
				p[k].left = p[k].left - t;
				num++;
				for(j=0; j<n; ++j)
				{
					if(p[j].status==0 && p[j].at<=i)
					{
						enq(j);
						p[j].status=1;
					}
				}
				enq(k);
			}
		}
		else
		{
			i++;
		}
	}	
//Printing Process table
	printf("PROCESS:\n\n");
	printf("Process\tAT\tBT\tWT\tTT\n");
	for(i=0;i<n;i++)
	{	
		printf("%s\t%d\t%d\t%d\t%d\n",p[i].name,p[i].at,p[i].bt,p[i].wt,p[i].tt);
	}

	//Prinitng Done table
	printf("\nDONE:\n\n");
	printf("Process\tST\tCT\n");
	for(i=0;i<num;i++)
		printf("%s\t%d\t%d\n",d[i].name,d[i].st,d[i].ct);

	//Printing Gauntt Chart		
	printf("\n\nGauntt Chart:\n");
	printf("\n\t");
	
	for(i=0;i<num-2;i++)
		printf("----------");
	printf("\n");
	printf("\t|");

	for(i=0;i<num;i++)
		printf("%s\t|",d[i].name);
	printf("\n\t");

	for(i=0;i<num-2;i++)
		printf("----------");
	printf("\n");	

	for(i=0;i<num;i++)
		printf("\t%d",d[i].st);
	printf("\t%d\n",d[i-1].ct);
	
	for(i=0;i<n;i++)
		tt=tt+p[i].tt;
	avgtt=(tt/n);
	printf("\nAverage Turnaround time= %.2fms \n",avgtt);
	
	for(i=0;i<n;i++)
		wt=wt+p[i].wt;
	avgwt=wt/n;
	printf("\nAverage Waiting time= %.2fms \n",avgwt);	
		

}

void enq(int j)
{
	int i;
	if(front==-1)
	{
		front++;
		q[rear] = j;
	}
	else
	{
		rear++;
		q[rear] = j;
	}
}
int deq()
{
	int j;
	j = q[front];
	if(front==rear)
	{
		front=-1;
		rear=0;
	}
	else if(front < rear)
	{
		front++;
	}
	return j;
}
		



