#include<stdio.h>
#include<stdlib.h>
struct file
{
int size;
int start;
struct node*link;
}f[100];


struct node
{
int bn;
struct node* next;
};

void main()
{
int i,j,bl,occu[100],n;
for(i=0;i<100;i++)
	{
 	  occu[i]=0;
	}
printf("ENTER THE NO OF FILES \n");
scanf("%d",&n);
for(i=0;i<n;)
	{
	printf("FILE%d\n",i+1);
	printf("ENTER THE STARTING BLOCK \n");
	scanf("%d",&f[i].start);
	if(occu[f[i].start]==1)
		{
		 printf("CANNOT BE ALLOCATED \n");
		 continue;
		}
	 else
		{
		printf("ENTER THE NO OF BLOCKS \n");
		 scanf("%d",&f[i].size);
		 occu[f[i].start]=1;
		printf("ENTER THE BLOCKS OF FILE \n");
		     for(j=0;j<f[i].size;j++)
			{
			 x:scanf("%d",&bl);
			  if(occu[bl]==0)
				{
					struct node * ll= (struct node*)malloc(sizeof(struct node));
					   ll->bn=bl;
					   ll->next=NULL;

					if(f[i].link==NULL)
							{	
							   f[i].link=ll;//sincef[i]is an array rather -> we use . and used for distinguish between files
							}
					 else
							{
							  struct  node * temp=f[i].link;
							 	while(temp->next!=NULL)
									{
										 temp=temp->next;
									}
								 temp->next=ll;
							}
					occu[bl]=1;
				}
				else
				{
				 printf("BLOCK ALREADY ALLOCATED TRY ANOTHER \n");
				  goto x;		
				}
			}
		}
      i++;
	}
  printf("ALLOCATION DETAILS \n");
    printf("FILE\tSTART\tSIZE\tBLOCKS\n");
    for ( i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d", i + 1, f[i].start,f[i].size);
        struct node *temp = f[i].link;
        while (temp != NULL)
        {
            printf("\t%i\t->", temp->bn);
            temp = temp->next;
        }
	printf("\n");
    }
}

