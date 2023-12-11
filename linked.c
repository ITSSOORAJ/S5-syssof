#include <stdio.h>
//#include <conio.h>
#include <stdlib.h>

struct file
{
    int si; // The Starting Index of the file.
    int len; // Total length of the file.
    int b[100]; // The blocks in the file.
    struct node *link; 
} f[100];

int mem[100], n;
struct node
{
    int n;
    struct node *next;
};

void main()
{
    //Marks all positions as unoccupied.
    for (int i = 0; i < 100; i++)
    {
        mem[i] = 0;
    }

    printf("\nEnter the no: of Files : ");
    scanf("%i", &n);
    for (int i = 0; i < n;)
    {
        printf("\nfile%i", i + 1);
        printf("\nEnter the Starting block : ");
        scanf("%i", &f[i].si);
        if (mem[f[i].si] == 1)
        {
            printf("\nFile%i Cannot be Allocated\n", i + 1);
            continue;
        }
        else
        {
            printf("\nEnter the no: BLOCKS : ");
            scanf("%i", &f[i].len);
            int check = 0;
 int kk;
            mem[f[i].si] = 1;
	   printf("ENTER THE BLOCKS\n");
            for (int j = 0; j < f[i].len; j++)
            {
               // for (int kk = 1; kk < 100; kk++)
                //{ 
		   x:scanf("%d",&kk);
                    if (mem[kk] == 0)
                    {
                        struct node *ll = (struct node *)malloc(sizeof(struct node));
                        ll->n = kk;
                        ll->next = NULL;
                        if (f[i].link == NULL)
                            f[i].link = ll;
                        else
                        {
                            struct node *temp = f[i].link;
                            while (temp->next != NULL)
                            {
                                temp = temp->next;
                            }
                            temp->next = ll;
                        }
                        mem[kk] = 1;
                        //break;
                    //}
                }
		else
		  {
		   printf("BLOCK ALREADY OCCUPIED ENTER ANOTHER BLOCK\n");
		    goto x;
		  }
            }
        }
        i++;
    }
  printf("FILE\tSTART\tSIZE\tBLOCKS\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d", i + 1, f[i].si,f[i].len);
        struct node *temp = f[i].link;
        while (temp != NULL)
        {
            printf("\t%i\t->", temp->n);
            temp = temp->next;
        }
	printf("\n");
    }
}
