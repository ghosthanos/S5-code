#include<stdio.h>
#include<string.h>


void main()
{
    FILE *fp;
    int i,j,staddr1;
    char line[50],name1[50],staddr[200];
    
    fp=fopen("absloader_objprogram.txt","r");
    fscanf(fp,"%s",line);
    
    for(i=2,j=2;line[i]!='^';i++,j++)
    {
        name1[j]=line[i];
    }
    name1[j]='\0';
    printf("name of obj prgm%s", name1);
    
while(!feof(fp))
{
    fscanf(fp,"%s",line);
}
while(line[0]=='T')
{
    for(i=2,j=0;line[i]!='^';i++,j++)
    {
        staddr[j]=line[i];
    }
    staddr[j]='\0';
    staddr1=atoi(staddr);
    i=12;
    
while(line[i]!='$')
{
    if(line[i]!='^')
    {
        printf("00%d\t %c\t%c\t",staddr1,line[i],line[i+1]);
        staddr1++;
        i=i+2;
    }
    else
    {
        i++;
    }
}
if(line[i]=='E')
{
    fclose(fp);
}
}
}