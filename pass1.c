#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main()
{
	
	char label[50],opcode[50],oprand[50],op[10],val[50];
 	int s_addr,locctr,found=0,l,length,error;	

	FILE *fp1,*fp2,*fp3,*fp4,*fp5;
	fp1=fopen("input.txt","r");
 	fp2=fopen("optab.txt","r");
 	fp3=fopen("symtab.txt","w");
	fp4=fopen("intermediate.txt","w");
 	fp5=fopen("length.txt","w");
 	fscanf(fp1,"%s%s%s",&label,&opcode,&oprand);

	if (strcmp(opcode,"START")==0)
	{
	 	s_addr=atoi(oprand);
	 	locctr=s_addr;
 	 	fprintf(fp4,"%d %s %s %s\n",locctr,label,opcode,oprand);
	 	fscanf(fp1,"%s%s%s",&label,&opcode,&oprand);
	}	
 	else
	{
		locctr=0;
	}
 
 	while(strcmp(opcode,"END")!=0)
	{
	 	if(strcmp(label,"**")!=0)
		{
		 	fprintf(fp3,"%s %d\n",label,locctr);
		}
	 	fscanf(fp2,"%s%s",&op,&val);
	 	found=0;
	 	while(strcmp(op,"END")!=0)
		{
		 	if(strcmp(opcode,op)==0)
		 	{
			 	found=1;
			 	break;
			}
		 	fscanf(fp2,"%s%s",&op,&val);
		}
	 	rewind(fp2);
	 	fprintf(fp4,"%d %s %s %s\n",locctr,label,opcode,oprand);
	 	if(found==1)
			locctr=locctr+3;
 	 	else if(strcmp(opcode,"WORD")==0)
		 	locctr=locctr+3;
	 	else if(strcmp(opcode,"RESW")==0)
		 	locctr=locctr+(3*atoi(oprand));
	 	else if(strcmp(opcode,"BYTE")==0)
		{
		 	if(strcmp(opcode,"X")==0)
				locctr=locctr+1;
			else
			{
			 	l=strlen(opcode);
			 	locctr=locctr+(l-3);
			}
		}
	 	else if(found==0)
	 	 	error=1;
		fscanf(fp1,"%s%s%s",&label,&opcode,&oprand);
	}
 	fprintf(fp4,"%d %s %s %s\n",locctr,label,opcode,oprand);
 	printf("Value of location count is %d.\n",locctr);
 	length=locctr-s_addr;
 	fprintf(fp5,"%d\n",length);
	fcloseall();

}

/*


OUTPUT:


input.txt

COPY START 2000
** LDA FIVE
** STA NUM1
** LDCH NUM2
** STCH C1
NUM1 RESW 2
FIVE WORD 5
NUM2 BYTE X'F1'
C1 RESB 1
** END

optab.txt

LDA 00
STA 0C
LDCH 50
STCH 54 
END

symtab.txt

NUM1 2012
FIVE 2018
NUM2 2021
C1 2022 

intermediate.txt

2000 COPY START 2000
2000 ** LDA FIVE
2003 ** STA NUM1
2006 ** LDCH NUM2
2009 ** STCH C1
2012 NUM1 RESW 2
2018 FIVE WORD 5
2021 NUM2 BYTE X'F1'
2022 C1 RESB 1
2022 ** END 1

length.txt

22
*/


