#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
	int i, symtab_flag, optab_flag, error_flag, symtab_addr, start_addr=0, length, operand_addr;
	char loc[20], label[20], opcode[20], operand[20], symtab_label[20], optab_opcode[20], optab_operand[20], program_length[20];

	FILE *input_file, *symtab_file, *obj_code_file, *optab_file, *pass1_pass2_file; 
	input_file = fopen("intermediate.txt", "r+");
	obj_code_file = fopen("object_code.txt", "w+");	
	pass1_pass2_file = fopen("length.txt", "r+");
	optab_file = fopen("optab.txt", "r+");
	symtab_file = fopen("symtab.txt", "r+");	
	fscanf(input_file, "%s %s %s %s", loc, label, opcode, operand);
	fscanf(pass1_pass2_file, "%s", program_length);
	if(strcmp(opcode, "START")==0)
	{
		start_addr = atoi(operand);
		fprintf(obj_code_file, "H^%s^00%d^00%d\n", label, start_addr, atoi(program_length));
		fprintf(obj_code_file, "T^00%d^%d", start_addr, atoi(program_length));
		fscanf(input_file, "%s %s %s %s", loc, label, opcode, operand);
	}
	while(strcmp(opcode, "END")!=0)
	{
		symtab_flag = 0;
		error_flag = 0;
                optab_flag = 0;
		if(strcmp(label, ".")!=0)
		{
			while(fscanf(optab_file, "%s %s", optab_opcode, optab_operand)!=EOF)
			{
				if(strcmp(opcode, optab_opcode)==0)
				{
					optab_flag=1;
					break;
				}
			}
			if(optab_flag==1)
			{
				if(strcmp(label, "**")!=0)
				{
					while(fscanf(symtab_file, "%s %s", symtab_label, symtab_addr)!=EOF)
					{
						if(strcmp(operand, symtab_label)==0)
						{
							symtab_flag = 1;
							break;
						}
					}
					if(symtab_flag==1)
					{	
						fprintf(obj_code_file, "0000%s^", symtab_addr);
					}
					else
					{
						error_flag = 1; 		
					}
				}
				else
				{
					fprintf(obj_code_file, "0000%s^", optab_operand);
				}
			}
			else if(strcmp(opcode, "BYTE")==0 || strcmp(opcode, "WORD")==0) 
			{
				if(strcmp(opcode, "WORD")==0)
				{
					fprintf(obj_code_file, "0000%s^", operand);
				}
				else
				{
					length = strlen(operand);
					if(operand[0]=='C')
					{ 
						for(i=2; i<length-1; ++i)
						{
							fprintf(obj_code_file, "%c", operand[i]);
						}
					}
					else if(operand[0]=='X')
					{
						for(i=2; i<length-1; ++i)
						{
							fprintf(obj_code_file, "%X", operand[i]);
						}
					}
					fprintf(obj_code_file, "^");
				}	
			}

		}
		fscanf(input_file, "%s %s %s %s\n", loc, label, opcode, operand);
		rewind(optab_file);
	}
	fprintf(obj_code_file, "\nE^00%d", start_addr);
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

object_code.txt

H^COPY^002000^0022
T^002000^22000000^00000C^000050^000054^00005^4631^
E^002000
*/
