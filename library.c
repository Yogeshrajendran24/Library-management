#include <stdio.h>
#include <string.h>
void Admin();
void Add_book();
void View_book();
void Report();
void Student();
void Take_book();
void Return_book();
int tot=0;
struct book
{
    char bn[100],an[100];
    int bid,f,a[100];
}b[100];

int main()
{
    int n;
    printf("\t\t\t\t*Welcome to Library*\t\t\t");
    while(1)
    {
        printf("\n1.Admin \n2.Student \n3.Exit\n");
        scanf("%d",&n);
        if(n==1)
            Admin();
        else if(n==2)
            Student();
        else if(n==3)
        {
            printf("Exit");
            printf("\nThank you for using");
            break;
        }
        else
        printf("\nInvalid Details");
    }
    return 0;
}
void Admin()
{
    int n,m,id;
    char pass[20];
    printf("\nEnter Your Id:");
    scanf("%d",&id);
    printf("\nEnter password: ");
    scanf("%s",pass);
    if(id==112&&strcmp(pass,"ad112")==0)
    {
		printf("\nYou have loggined as Admin succesfully\n");
        while(1)
        {
            printf("\n1.Books\n2.Report\n3.Exit\n");
            scanf("%d",&n);
            if(n==1)
            {
                while(1)
                {
                    printf("\n1.Add book\n2.View book\n3.Exit\n");
                    scanf("%d",&m);
                    if(m==1)
                        Add_book();
                    else if(m==2)
                        View_book();
                    else if(m==3)
                    {
                    printf("\nExit");
                    break;
                    }
                    else
                    printf("\nInvalid details");
                   
                }
            }
            
            else if(n==2)
                Report();
            else if(n==3)
            {
                printf("\nExit\n");
                break;
			}
            
        }
    }
    else
    {
        printf("\nInvalid details\n");
    }
}
void Add_book()
{
    int n,i,f=1;
    printf("\nEnter the no.of.books to be added: ");
    scanf("%d",&n);
    for(i=tot;i<tot+n;i++)
    {
        printf("\nBook name: ");
        scanf("%s",b[i].bn);
        printf("\nAuthor name: ");
        scanf("%s",b[i].an);
        printf("\nBook id: ");
        scanf("%d",&b[i].bid);
        b[i].f = 1;
        printf("\nBook has been added successfully\n");
    }
    tot+=n;
}
void View_book()
{
	printf("\n list of Books in library\n ");
    int i;
    for(i=0;i<tot;i++)
    printf("%s %s %d %s\n",b[i].bn,b[i].an,b[i].bid,(b[i].f?"Available":"Not available"));
}

void Student()
{
	int sid,n;
	char spass[100];
	printf("\nEnter student Id:");
	scanf("%d",&sid);
	printf("\Enter student password:");
	scanf("%s",spass);
	if(sid==111&&strcmp(spass,"std111")==0)
	{
		printf("\n You have loggined as Student Successfully\n");
		while(1)
		{
			printf("\n1.Take book \n2.Return book \n3.View book \n4.Exit\n");
			scanf("%d",&n);
			if(n==1)
				Take_book();
			else if(n==2)
				Return_book();
		    else if(n==3)
				View_book();
			else if(n==4)
			{
				printf("\n Exit\n");
				break;
			}
		}
	}
	else
	{
		printf("\n Invalid details\n");
	}
}
void Take_book()
{
	  char y[50];
    int i,n,f=1,x;
    printf("\nBook id: \n");
    scanf("%d",&x);
    printf("\nBook name: \n");
    scanf("%s",y);
    for(i=0;i<tot;i++)
    {
        if(b[i].bid==x&&!strcmp(b[i].bn,y)&&b[i].f==1)
        {
            printf("\nBook has been Taken\n");
            f=0;
            b[i].f = 0;
            break;
        }
    }
    if(f)
        printf("\nInvalid Details\n");
}
void Return_book()
{
	char y[50];
    int i,n,f=1,x;
    printf("Book id: \n");
    scanf("%d",&x);
    printf("Book name: \n");
    scanf("%s",y);
    for(i=0;i<tot;i++)
    {
        if(b[i].f==0&&x==b[i].bid&&!strcmp(b[i].bn,y))
        {
            f=0;
            b[i].f=1;   
        }
    }
    if(f==1)
        printf("\nBook not returned\n");
    else
    printf("\nBook returned\n");
 }
 void Report()
{
	printf("\n For report check the report.txt file in documents\n");
	FILE *f;
	char ar[100];
    int a,i,n;
    f=fopen("report.txt","w");
    for(i=0;i<tot;i++)
    fprintf(f,"%s %s %d %s\n",b[i].bn,b[i].an,b[i].bid,(b[i].f?"Available":"Not available"));
    fclose(f);
}

