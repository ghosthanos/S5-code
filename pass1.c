#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int length,locctr,start;
    char label[20],opcode[20],operand[20],code[20],mnemonics[20];
    FILE *fp1,*fp2,*fp3,*fp4;
    fp1=fopen("input.txt","r");
    fp2=fopen("optab.txt","r");
    fp3=fopen("symtab.txt","w");
    fp4=fopen("intermediate.txt","w");

fscanf(fp1,"%s \t %s \t %s", label,opcode,operand);

if(strcmp(opcode,"START")==0)
{
    start=atoi(operand);
    locctr=start;
    fprintf(fp4,"%s \t %s \t %s", label,opcode,operand);
    fscanf(fp1,"%s \t %s \t %s", label,opcode,operand);
}
else
{
    locctr=0;
}

while(strcmp(opcode,"END")!=0)
{
    fprintf("%d", locctr);
    if(strcmp(label,"**")!=0)
    {
        fprintf(fp3,"%s \t %d", label,locctr);
    }
    else
    {
        fscanf(fp1,"%s \t %s \t %s", label,opcode,operand);
    }

while(strcmp(code,"END")!=0)
{
    if(strcmp(opcode,code)==0)
    {
        locctr=locctr+3;
        break;
    }
    else
    {
        fscanf(fp2,"%s \t %s",code,mnemonics);
    }
}
if(strcmp(opcode,"WORD")==0)
{
    locctr=locctr+3;
}
else if(strcmp(opcode,"RESW")==0)
{
    locctr=locctr+3*atoi(operand);
}
else if(strcmp(opcode,"RESB")==0)
{
    locctr=locctr+atoi(operand);
}
else if(strcmp(opcode,"BYTE")==0)
{
    locctr=locctr+1;
}
fprintf(fp4,"%s \t %s \t %s", label,opcode,operand);
fscanf(fp1,"%s \t %s \t %s", label,opcode,operand);
}
fprintf(fp4,"%s \t %s \t %s", label,opcode,operand);
length=locctr-start;
printf("length id: %d", length);
fclose(fp1);
fclose(fp2);
fclose(fp3);
fclose(fp4);
}