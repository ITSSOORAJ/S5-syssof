#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
FILE *fp;
int i,j,staddress;
char rdr[40],name[40],staddrrss[40];
fp=fopen("objp.txt","r");
fscanf(fp,"%s",rdr);
for(i=2,j=0;rdr[i]!='^';i++,j++)
	{
		name[j]=rdr[i];
	}
name[j]='\0';
printf("NAME OF THE PROGRAM IS :: %s :: AS PER OBJECT PROGRAM\n",name);
while(!feof(fp))
{
//printf("GGG");
fscanf(fp,"%s",rdr);
while(rdr[0]=='T')
	{
	  for(i=2,j=0;rdr[i]!='^';i++,j++)
		{
		 staddrrss[j]=rdr[i];
		}
	staddrrss[j]='\0';
   	staddress=atoi(staddrrss);
	i=12;
	while(rdr[i]!='$')
		{
		  if(rdr[i]!='^')
			{
			printf("00%d\t%c%c\n",staddress,rdr[i],rdr[i+1]);
			staddress++;
			i=i+2;
			}
		   else
			{
			 i++;
			}
		   }
                //free(staddrrss);
		fscanf(fp,"%s",rdr);
		}
	 if(rdr[0]=='E')
		{
		 //fclose(fp);
		  printf("LOADING SUCCESFULLY INITIATED\n");
	          exit(0);
		}
}
//printf("HI");
}
