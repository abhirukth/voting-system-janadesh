#include<stdio.h>
#include<conio.h>
int main()
{
	int n,num;
	printf("\n\t----\tVOTING SYSTEM\t----\n");
	printf("\nEnter the number of parties: ");
	scanf("%d",&n);
	char name[n][1000];
	printf("\nEnter the name of the parties participating: \n");
	for(int i=1;i<=n;i++)
	{
		printf("Party %d: ",i);
		scanf("%s",name[i]);
	}
	
	int choice,x=1,m=0,vote,count[n],agree=1;
	int ar[m];
	float cnt=0;
	FILE *f;
	f=fopen("result.txt","w");
	for(int i=1;i<=n;i++)
		count[i]=0;
	do
	{
		printf("\n\n--MENU--\n");
		printf("\n1.Vote for party.");
		printf("\n2.Analyse votes.");
		printf("\n3.Exit.");
		try:
		printf("\nEnter your option: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:	do
					{
						printf("\nEnter your unique voter ID number: ");
						scanf("%d",&num);
						if(m==0)
						{
							ar[m]=num;
							m++;
							printf("\nWELCOME\n");
							for(int i=1;i<=n;i++)
								printf("\nParty %d: %s",i,name[i]);
							printf("\nPlease enter the party number as mentioned to place your vote: ");
							scanf("%d",&vote);
							cnt++;
						}
						else
						{
							for(int i=0;i<m;i++)
							{
								if(ar[i]==num)
								{
									printf("\nSorry! You have voted before.");
									goto jump;
								}
							}
							ar[m]=num;
							m++;
							printf("\nWELCOME\n");
							for(int i=1;i<=n;i++)
								printf("\nParty %d: %s",i,name[i]);
							printf("\nPlease enter the party number as mentioned to place your vote: ");
							scanf("%d",&vote);
							cnt++;
						}
						count[vote]++;
						jump:
						printf("\nContinue with next voter? (1 for yes & 0 for no): ");
						scanf("%d",&agree);
					} while (agree!=0);
					break;

			case 2:	printf("\nResults are generated in text file 'result.txt'.\n");
					fprintf(f,"\n\n\t\t----\tVOTE RESULTS\t----\n\n");
					for(int i=1;i<=n;i++)
						fprintf(f,"\nParty %d: %s :: %d vote(s) :: %f %s votes",i,name[i],count[i],count[i]/cnt,"%");
					break;

			case 3:	return 0;

			default:printf("You have entered an invalid option please try again: ");
					goto try;
		}
		printf("\nRedirect to MENU for vote or analysis? (1 for yes & 0 for no): ");
		scanf("%d",&x);
	}while(x!=0);
	fclose(f);
	return 0;
}