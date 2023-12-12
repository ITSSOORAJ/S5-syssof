#include<stdio.h>
int prevche(int p,int m,int n)
	{
	 int flag=0;
	  if(m==p)
		{
		 flag=1;
		}
       //printf("FLAG IS %d",flag);
        return flag;
	}
void main()
{
int p,b[90],c[10][10],sb[10],f,i,j,t,q[90],n;
int m[90],flag,flag1=0,s[90];
printf("ENTER THE NO OF FILES\n");
scanf("%d",&n);
for(i=0;i<n;i++)
	{
		printf("enter the index block of file%d\t\t",i+1);
		scanf("%d",&sb[i]);
		t=sb[i];
		q[i]=sb[i];
		s[i]=sb[i];
		p=sb[i-1];
		//printf("\n\n\t\t%d and %d",p,t);
		flag=prevche(p,t,n);
        for(j=0;j<b[i-1];j++)
		{
		 if(sb[i]==m[j])
			{
			 flag1=1;
			 //break;
			}
		}
		//printf("\n%d ",flag1);
		if(flag==0&& flag1==0)
                        {
                printf("enter the no of blocks of file%d\t\t",i+1);
                scanf("%d",&b[i]);
		 printf("ENTER THE BLOCKS\n");
                for(j=0;j<b[i];j++)
                        {
                         scanf("%d",&c[i][j]);
			  m[j]=c[i][j];
                        }
                        }
               else
                        {
                         printf("BLOCK ALREADY ALLOCATED\n");
			 b[i]=0;
                        }
        }

printf("FILE\t\tINDEX BLOCK\t\tSIZE OF BLOCK\n");
 for(i=0;i<n;i++)
	{
	 printf("File%d\t\t%d\t\t%d\n",i+1,q[i],b[i]);
	}
printf("enter the file name\n FILE:");
scanf("%d",&f);
printf("FILE:%d\t\t\t",f);
printf("INDEX BLOCK:%d\t\t\t",q[f-1]);
printf("ALLOCATED BLOCKS:");
for(i=0;i<b[f-1];i++)
{
	printf("%d->",c[f-1][i]);
}
printf("\n");

}
