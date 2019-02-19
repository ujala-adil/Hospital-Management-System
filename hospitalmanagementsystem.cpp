#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
void adminlogin(void);
void admin(void);
void insert(void);
void viewall(void);
void search(void);
void delrec(void);
void update(void);
//void user(void);
void aboutp(void); 

FILE *ft;
char another,choice;

struct crec{

		char email[30] , name[30] , bg[3] , dis[30] , add[30] , docname[30] , pnum[30] , symptom[30];
		int age;

	}detail;

       int i=0;
       int main()

{
           
          // system("COLOR F1");
             
	    printf ("\n\t\t\t\t\t\t================================================================");
		printf ("\n\n\t\t\t\t\t\t||\t\tHOSPITAL MANAGEMENT RECORD-BASED SYSTEM\t      ||\n\n");
		printf ("\t\t\t\t\t\t================================================================");
	    printf ("\n\n\n\n\t\t\t\t\t\t\t\tWelcome to \"NEDUET Hospital\" ");
	    printf ("\n\n\t\t\t\t\t\t\t\t\"Where you can hope again...\"\n\n\n");

	int opt;
    printf("\n\n\n\n\t\t\t\t\t\t\t\t\t1-Administration\n\n\n");
	//printf ("\t\t2-User\n\n");
	printf ("\t\t\t\t\t\t\t2-About Program");
	printf ("\t\t\t  0-Exit");
	printf ("\n\n\n\n\t\t\t\t\t\t\t\t\tEnter your choice:  ");
	scanf ("%d",&opt);

	system("cls");

	switch(opt)

	{

		case 1:
		  printf ("\n\t\t\t\t\t\t****************************************************\n\n");
		  printf ("\t\t\t\t\t\t\t*** WELCOME TO ADMINISTRATOR BLOCK ***\n\n");
		  printf ("\t\t\t\t\t\t****************************************************\n\n");
		  adminlogin();
		  break;
	
	/*
		case 2:
		    printf ("\n\t\t\t\t\t\t\t**********************************************\n\n");
            printf("\t\t\t\t\t\t\t\t*** WELCOME TO USER PORTAL ***\n\n");
            printf ("\t\t\t\t\t\t\t**********************************************\n\n");
		  //  user();
			break;
	
	*/
	
		case 2:
			printf ("\n\t\t\t\t\t\t\t*******************************\n\n");
			printf ("\t\t\t\t\t\t\t\t*** ABOUT PROGRAM **\n\n");
			printf ("\t\t\t\t\t\t\t*******************************\n\n");
			aboutp();
			break;
	
		case 0:
			exit(0);
			break;
			
		default:
		    ("Invalid choice:");

	}
}

   

void adminlogin(void)

{
	
     char a[30];
     
    fflush(stdin);

					puts("ENTER YOUR NAME: ");
					printf ("\n");
					gets(a);
					printf ("\n\n");
					puts("ENTER YOUR PASSWORD: ");
					printf ("\n");
						char ch1,ch2,ch3,ch4,ch5,ch6;
							ch1=getch(); printf("*");
							ch2=getch(); printf("*");
							ch3=getch(); printf("*");
							ch4=getch(); printf("*");
							ch5=getch(); printf("*");
							ch6=getch(); printf("*\n\n");
			
					
							
							
if((ch1=='N' || ch1=='n') && (ch2=='E' || ch2=='e') && (ch3=='D' || ch3=='d') && (ch4=='U' || ch4=='u') && (ch5=='E' || ch5=='e') && (ch6=='T' || ch6=='t'))
  
  {
    system("cls");
  	admin();
 
  }
 
 else
    
	{
    
	 printf ("WRONG PASSWORD!!!\nTRY AGAIN\n\n");
	 printf ("( Password Hint:  UNIVERSITY )\n\n");
	 adminlogin();
    
	}
  
}



void insert()

{

char ch;
FILE *fptr;

if ( (fptr=fopen("patient.txt","ab+")) == NULL)

{

	printf ("Cannot open file.");  exit(1);

}



fflush(stdin);

printf("\n\nEnter the name of new patient:\n");
gets(detail.name);

printf ("\n");
fflush(stdin);
printf("Enter the age of new patient:\n");
scanf("%d",&detail.age);

printf ("\n");

fflush(stdin);

printf("Enter mobile number:\n");
gets(detail.pnum);

printf ("\n");

printf ("Enter E-mail ID:\n");
gets(detail.email);

printf ("\n");

fflush(stdin);

printf("Enter the blood group of new patient:\n");
gets(detail.bg);

printf ("\n");

printf("Enter new patient's disease\n");
gets(detail.dis);

printf ("\n");

printf ("Enter symptoms:\n");
gets(detail.symptom); 

printf ("\n");

printf("Enter address:\n");
gets(detail.add);

printf ("\n");

fflush(stdin);

printf("Enter doctor's name:\n");
gets(detail.docname);


fwrite(&detail,sizeof(detail),1,fptr);


fclose(fptr);
printf ("\nDo you want to add another record (Y/N)\n\n");
ch=getche();

if (ch=='Y' || ch=='y') {
		system("cls");
	insert();
}
else {
	system("cls");
	admin();
 
}
	

}

void viewall()

{
//	int j;
	FILE *fptr;
	if ( (fptr=fopen("patient.txt","r"))==NULL) {
		printf ("Cannot open file.");
		exit(1);
	}
	
	while ( fread(&detail,sizeof(detail),1,fptr) ) {
		printf("\n\nRecord no. %d\n\nName:   %s\nAge: %d\nBlood Group: %s\nMobile Number: %s\nE-mail: %s\nSymptoms: %s\nDisease: %s\nHome Address:  %s\nDoctor's Name: %s\n",i+1,detail.name,detail.age,detail.bg,detail.pnum,detail.email,detail.symptom,detail.dis,detail.add,detail.docname);
    i++;}

      fclose(fptr);
		printf("\n\nPress any key to back...");
 		getch();

	system("cls");
	admin();

}
  


void search(void)
{
	
	FILE *fptr;
	char phn[30];
	int flag = 0;

	printf ("\nEnter patient's phone no. to be searched:     ");
	fflush(stdin);
	gets(phn);
	
	if ( ( fptr=fopen("patient.txt","rb")) == NULL)	 {
		
		printf ("Cannot open file");
		exit(1);
		
	}
	
	
	while( fread(&detail, sizeof(detail), 1, fptr)) {
		if ( !strcmp( phn, detail.pnum) ) {
			flag = 1;
			break;
		}
	}
	
	if ( flag ) {
		printf ("\n\nName:   %s\n",detail.name);
	    printf ("Age:   %d\n",detail.age);
	    printf ("Blood Group:  %s\n",detail.bg);
	    printf ("Mobile Number:   %s\n",detail.pnum);
	    printf ("E-mail:     %s\n",detail.email);
	    printf ("Symptoms:    %s\n",detail.symptom);
	    printf ("Disease:   %s\n",detail.dis);
	    printf ("Home Address:   %s\n",detail.add);
	    printf ("Doctor's Name:   %s\n",detail.docname);
	} else {
		printf("Record not found..");
		getch();
	
	}
	
   printf("Press any key to go back to ADMIN ACCESS..");
   getch();
   admin();
    
}


void delrec(void) {
	system("cls");
	int falg = 0;
	FILE *fptr, *fptr_tmp;
	char phn[30];
	int flag = 0;

	printf ("\nEnter patient's phone no. to be searched:     ");
	fflush(stdin);
	gets(phn);
	
	fptr = fopen("patient.txt", "r");
	if ( fptr == NULL ) {
		printf("Unable to open file");
		exit(0);
	}
	fptr_tmp = fopen( "temp_file.txt", "wb");
	if ( fptr_tmp == NULL ) {
		printf("Unable to open file temp file.");
		exit(0);
	}
	
	while( fread(&detail, sizeof(detail), 1, fptr)) {
		if ( !strcmp( phn, detail.pnum) ) {
			printf("A record with requested name found and deleted.\n\n");
			flag = 1;
		} else {
			fwrite(&detail, sizeof(detail), 1, fptr_tmp);
		}
	}
	if ( !flag) {
		printf("No record(s) found with the request");
	}

	fclose(fptr);
	fclose(fptr_tmp);

	remove("patient.txt");
	rename("temp_file.txt","patient.txt");
    printf("\n\npress any key to back!");
	getch();
	system("cls");
	admin();
	}


void update() {
	
	FILE *fptr;
	char phn[30];
	int flag = 0;

	printf ("\nEnter patient's phone no. to be searched:     ");
	fflush(stdin);
	gets(phn);
	
	if ( ( fptr=fopen("patient.txt","rb+")) == NULL)	 {
		
		printf ("Cannot open file");
		exit(1);
		
	}
	
	
	while( fread(&detail, sizeof(detail), 1, fptr)) {
		if ( !strcmp( phn, detail.pnum) ) {
			flag = 1;
			break;
		}
	}
	
	if (flag) {
		
			fflush(stdin);
			
			printf("\n\nEnter the name of new patient:\n");
			gets(detail.name);
			
			printf ("\n");
			fflush(stdin);
			printf("Enter the age of new patient:\n");
			scanf("%d",&detail.age);
			
			printf ("\n");
			
			fflush(stdin);
			
			printf("Enter mobile number:\n");
			gets(detail.pnum);
			
			printf ("\n");
			
			printf ("Enter E-mail ID:\n");
			gets(detail.email);
			
			printf ("\n");
			
			fflush(stdin);
			
			printf("Enter the blood group of new patient:\n");
			gets(detail.bg);
			
			printf ("\n");
			
			printf("Enter new patient's disease\n");
			gets(detail.dis);
			
			printf ("\n");
			
			printf ("Enter symptoms:\n");
			gets(detail.symptom); 
			
			printf ("\n");
			
			printf("Enter address:\n");
			gets(detail.add);
			
			printf ("\n");
			
			fflush(stdin);
			
			printf("Enter doctor's name:\n");
			gets(detail.docname);
			
			fseek(fptr, -sizeof(detail), SEEK_CUR);
			
			fwrite(&detail,sizeof(detail),1,fptr);
			fclose(fptr);
			printf("Record Updated!!");
			
		} else {
			
			printf("Record not found!!");
			getch();
			admin();
		}
	
	printf("\n\nPress any key to go back to ADMIN ACCESS..");
	getch();
   	admin();
    
	
}

void aboutp(void)

{

	printf ("This is a user-friendly record-based program on HOSPTIAL MANAGEMENT that maanages patients records through an admin account.\n");
    printf ("This program has been developed by a partnership of:\n\n");
	printf ("\tUJALA  ADIL\n\tCT-024\n\n\tand\n\n");
	printf ("\tROMAISA LIAQUAT\n\tCT-019\n\n");
	printf ("\t\t\t\t\t\t***THANK YOU FOR VISITING!***");
	printf ("\n\nPress >>ENTER<< to continue");
	
    	if(getch()=='\r')
	     system("cls");
	      main();
	
}


void admin(void)

{
	system("cls");
            	printf ("\t\t\t\t\t\t\t==========================================\n\n");
                printf ("\t\t\t\t\t\t\t\tWELCOME TO ADMIN ACCESS!\n\n");
                printf ("\t\t\t\t\t\t\t==========================================\n\n");
                
                
                // while(1)
//	clrscr();
	
//	gotoxy(30,10);
	printf ("\n1.Add Record\n");
//	gotoxy(30,12);
	printf ("2.View Records\n");
//	gotoxy(30,14);
	printf ("3.Update Record\n");
//	gotoxy(30,16);
	printf ("4.Delete Record\n");
	printf ("5.Search Record\n");
//	gotoxy(30,18);
	printf ("0. Exit\n");
//	gotoxy(30,20);
	printf ("\nYour choice:    ");

	//fflush(stdin);

char another , choice;
 
	choice=getche();
	system("cls");

	
	switch (choice)
	
	{
	
		case '1':
			insert(); 
			break;

	    case '2':
	    	viewall();
	    	break;
	    	
	    case '3':
			update();
			break;
			
		case '4':
			delrec();
			break;
			
		case '5':
			search();
			break;
			
		case '0':
		//	FILE *fp , *ft;
		//	fclose(fp);

			exit(0);
			
		default:
			printf ("INVALID ENTRY.\n Select only available options.");

	}
}
