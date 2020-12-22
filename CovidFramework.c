#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>


//Function Declaration
void WelcomeScreen(void);
void Title(void);
void Password(void);
void ActorMenu(void);
void UserMenu(void);
void Register(void);
void TestReport(void);
void BedAdmit(void);
void Count(void);
void BedCount(void);
void PatientHistory(void);
void DoctorMenu(void);
void CareTaker();
void PatientMenu(void);
void Charges(void);
void PlasmaDonor(void);
void Display(void);
void Search(void);
void PlasmaIDList(void);
void ex_it(void);

char password[10]={"123456789"};

struct patient
{
	char FirstName[30];
	char LastName[30];
	int Age;
	char Gender;
	char Contact_No[10];
	int Weight;
	char BloodGroup[3];
	int PatientID;
	char CovidReport[9];
	char Symp[200];
};

struct patient p;
FILE *fr;
FILE *fpc;
FILE *fnc;
FILE *fhc;
FILE *fob;
FILE *fvb;
FILE *fgb;
FILE *fpd;
FILE *fct;
int Docch=0;
int BC=0;
int C=0;
int D=0;
int ct=0;
int ID;
char lname[25];
char fname[25];

int main(void)
{
	WelcomeScreen();
	Title();
	Password();
}

void WelcomeScreen(void)
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t**************************************************");
	printf("\n\t\t\t\t\t\t*\t            WELCOME TO              \t *");
	printf("\n\t\t\t\t\t\t*          COVID TEST CARE FRAMEWORK             *");
	printf("\n\t\t\t\t\t\t**************************************************");
	printf("\n\n\n\n Press any key to continue...   ");
	getch();
	system("cls");
}

void Title(void)
{
	printf("\n\n\t\t-------------------------------------------------------------------------------------------------------------------------------");
	printf("\n\t\t\t\t                                  COVID TEST CARE FRAMEWORK                ");
	printf("\n\t\t-------------------------------------------------------------------------------------------------------------------------------");
}

void ex_it(void)
{
	system("cls");
	Title();
	printf("\n\n\n\n\t\t\t\t\tThank You for visiting!!!");
	getch();
}
void Password(void)
{
	char login[25]=("\n\n\t\t\t\tPASSWORD:");
        char Username[25];
        char Original_Username[25]="Allen";
	char ch,pass[10];
	int count=0;
	do{
        	printf("\n\n\t\t\t\tUSERNAME:") ;
        	scanf ("%s",&Username) ;
		printf("%s",login);
		int i=0,j;
		ch=0;
		while(ch!=13)
		{
			ch=getch();
			if(ch!=13 && ch!=9)
			{
				putch('*');
				pass[i]=ch;
				i++;
			}
		}
		pass[i]='\0';
		if(strcmp(pass,password)==0 && strcmp(Username, Original_Username)==0) 
		{
			printf("\n\n\n\n\t\t\tNow you are logged in.....");
			getch();
			ActorMenu();
			break;
		}
		else
		{
			printf("\n\n\n\t\t\t\tIncorrect Password or Username! Try again");
			count++;
			getch();
		}
	}while(count<=2);
	if(count>2)
	{
		printf("\n\n\n\t\t\t\tToo many attempts!You cannot login :(");
		getch();
		ex_it();
	}
             system ("cls") ;
}

void ActorMenu(void)
{
	system("cls");
	int choose;
	Title();
	printf("\n\n\n\n\n\t\t\t1. User/Receptionist");
	printf("\n\n\t\t\t2. Doctor");
	printf("\n\n\t\t\t3. Patient");
	printf("\n\n\t\t\t4. Exit");
	printf("\n\n\n\n\t\t\tEnter your choice:");
	scanf("%d",&choose);
	switch(choose)
	{
		case 1:
			UserMenu();
			break;
		case 2:
			DoctorMenu();
			break;
		case 3:
			PatientMenu();
			break;
		case 4:
			ex_it();
			break;
		default:
			printf("\n\n\t\t\tInvalid Entry :! Please enter the right option");
			getch();
		        ActorMenu();
	}
	system("cls");
}
void UserMenu()
{
	system("cls");
	int choose;
	Title();
	printf("\n\n\n\t\t\t1. Registering the patient");
	printf("\n\n\t\t\t2. Count of Cases");
	printf("\n\n\t\t\t3. Bed Count");
	printf("\n\n\t\t\t4. patient History");
	printf("\n\n\t\t\t5. Display Details");
	printf("\n\n\t\t\t6. Go Back");
	printf("\n\n\t\t\t7. Exit");
	printf("\n\n\t\t\tEnter your choice between 1-7: ");
	scanf("%d",&choose);
	switch(choose)
	{
		case 1:
			Register();
			break;
		case 2:
			C=1;
			Count();
			break;
		case 3:
			BC=1;
			BedCount();
			break;
		case 4:
			PatientHistory();
			break;
		case 5:
			D=1;
			Display();
			break;
		case 6:
			ActorMenu();
			break;
		case 7:
			ex_it();
			break;
		default:
			printf("\n\n\t\t\t Invalid choice :( Please enter the right choice ");
			getch();
			UserMenu();
			break;
	}
	system("cls");
}

void Display()
{
	system("cls");
	Title();
	int choose;
	char ch=' ';
	printf("\n\n\t\t\t1. Patient Details");
	printf("\n\n\t\t\t2. Positive Patients");
	printf("\n\n\t\t\t3.  Negative Patients");
	printf("\n\n\t\t\t4. PlasmaDonors ID's");
	printf("\n\n\t\t\t5. CareTakers Alloted");
	printf("\n\n\t\t\tEnter your choice:");
	scanf("%d",&choose);
	Title();
	switch(choose)
	{
		case 1:
			fr=fopen("Register.txt","r");
			char ch=' ';
			printf("\n");
			while((ch=getc(fr))!=EOF)
			{
				if(ch=='\n')
					printf("\n");
				else
					printf("%c",ch);
			}
			fclose(fr);
			getch();
			break;
		case 2:
			fpc=fopen("PositiveCount.dat","r");
			printf("\n\t\t\t");
			while((ch=getc(fpc))!=EOF)
			{
				if(ch=='\n')
					printf("\n\t\t\t");
				else
					printf("%c",ch);
			}
			fclose(fpc);
			getch();
			break;
		case 3:
			fnc=fopen("NegativeCount.dat","r");
			printf("\n\t\t\t");
			while((ch=getc(fnc))!=EOF)
			{
				if(ch=='\n')
					printf("\n\t\t\t");
				else
					printf("%c",ch);
			}
			fclose(fnc);
			getch();
			break;
		case 4:
			PlasmaIDList();
			break;
		case 5:
			fct=fopen("CareTakers.txt","r");
			printf("\n\t\t\t");
			while((ch=getc(fct))!=EOF)
			{
				if(ch=='\n')
					printf("\n\t\t\t");
				else
					printf("%c",ch);
			}
			fclose(fct);
			getch();
			break;
		default:
			printf("\n\n\t\t\tInvalid Choice.Plese Enter again");
			getch();
			Display();
			break;
	}
	DIS:
	printf("\n\n\t\t\t1.Continue\n\t\t\t2.Go Back\n\t\t\tEnter your choice:");
	int choice;
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			Display();
			break;
		case 2:
			if(D==1)
			{	
				D=0;
				UserMenu();
			}
			else if(D==0)
				DoctorMenu();
			break;
		default:
			printf("\n\n\t\t\tInvalid choice.Please enter again");
			goto DIS;
			break;
	}
}

void PlasmaIDList()
{
	system("cls");
	Title();
	printf("\n\n\n\t\t\tThe ID's of PlasmaDonor Patients:");
	printf("\n\n\t\t\t");
	int num;
	fpd=fopen("PlasmaDonor.txt","r");
	while((num=getw(fpd))!=EOF)
	{
		printf("%d,",num);
	}
	fclose(fpd);
	getch();
}

void DoctorMenu()
{
	system("cls");
	int choose;
	Title();
	printf("\n\n\n\t\t\t1. Patient Details");
	printf("\n\n\t\t\t2. Count of cases");
	printf("\n\n\t\t\t3. Bed Count");
	printf("\n\n\t\t\t4. DisplayDetails");
	printf("\n\n\t\t\t5. Go Back");
	printf("\n\n\t\t\t6. Exit");
	printf("\n\n\n\t\t\tEnter your choice between 1-6:");
	scanf("%d",&choose);
	switch(choose)
	{
		case 1:
			Docch=1;
			PatientHistory();
			break;
		case 2:
			Count();
			break;
		case 3:
			BedCount();
			break;
		case 4:
			Display();
			break;
		case 5:
			ActorMenu();
			break;
		case 6:
			ex_it();
			break;
		default:
			printf("\n\n\t\t\tInvalid Choice :( Please enter the right choice again..");
			getch();
			DoctorMenu();
			break;
	}
	system("cls");
}

void CareTaker()
{
	system("cls");
	Title();
	printf("\n\n\t\t\t1. Sunitha\t\tPhoneNo:7412369852");
	printf("\n\n\t\t\t2. Laxmi\t\tPhoneNo:7539518246");
	printf("\n\n\t\t\t3. Adithya\t\tPhoneNo:9512367482");
	printf("\n\n\t\t\t4. Sujatha\t\tPhoneNo:8426593175");
	printf("\n\n\t\t\t5. Ramesh\t\tPhoneNo:9874123652");
	printf("\n\n\n\t\t\tAllot a Care taker:");
	int choose;
	scanf("%d",&choose);
	switch(choose)
	{
		case 1:
			fct=fopen("CareTakers.txt","a");
			if(ct==1)
			fprintf(fct,"%d Sunitha PhoneNo:7412369852\n",ID);
			if(ct==2)
			fprintf(fct,"%s%s Sunitha PhoneNo:7412369852\n",fname,lname);
			fclose(fct);
			break;
		case 2:
			fct=fopen("CareTakers.txt","a");
			if(ct==1)
			fprintf(fct,"%d Laxmi PhoneNo:7539518246\n",ID);
			if(ct==2)
			fprintf(fct,"%s%s Laxmi PhoneNo:7539518246\n",fname,lname);
			fclose(fct);
			break;
		case 3:
			fct=fopen("CareTakers.txt","a");
			if(ct==1)
			fprintf(fct,"%d Adithya PhoneNo:9512367482\n",ID);
			if(ct==2)
			fprintf(fct,"%s%s Adithya PhoneNo:9512367482\n",fname,lname);
			fclose(fct);
			break;
		case 4:
			fct=fopen("CareTakers.txt","a");
			if(ct==1)
			fprintf(fct,"%d Sujatha PhoneNo:8426593175\n",ID);
			if(ct==2)
			fprintf(fct,"%s%s Sujatha PhoneNo:8426593175\n",fname,lname);
			fclose(fct);
			break;
		case 5:
			fct=fopen("CareTakers.txt","a");
			if(ct==1)
			fprintf(fct,"%d Ramesh PhoneNo:9874123652\n",ID);
			if(ct==2)
			fprintf(fct,"%s%s Ramesh PhoneNo:9874123652\n",fname,lname);
			fclose(fct);
			break;
		default:
			printf("Invalid input:( Please enter the right choice");
			CareTaker();
			break;
	}
	printf("\n\n\t\t\t Thank you! We will track your details");
	getch();
	DoctorMenu();
}
void PatientMenu()
{
	system("cls");
	Title();
	int choice;
	printf("\n\n\n\n\n\t\t\t1. Hospital Charges");
	printf("\n\n\n\t\t\t2. Plasma Donor");
	printf("\n\n\n\t\t\t3. Go back");
	printf("\n\n\n\t\t\t4. Exit");
	printf("\n\n\n\t\t\tEnter your choice: ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			Charges();
			break;
		case 2:
			PlasmaDonor();
			break;
		case 3:
			ActorMenu();
			break;
		case 4:
			ex_it();
			break;
		default:
			printf("\n\n\t\t\tInvalid Choice :( Please enter again");
			getch();
			PatientMenu();
			break;
	}
	getch();
}

void Charges()
{
	system("cls");
	Title();
	printf("\n\n\n\t\t\tCovid Test Fee :   Rs.2200/- per person");
	printf("\n\n\t\t\tConsultation Fee: Rs.3500/- per person");
	printf("\n\n\t\t\tGeneralBed/Isolation ward : Rs.4000/- per day");
	printf("\n\n\t\t\tOxygenared Bed : Rs.7500/- per day");
	printf("\n\n\t\t\tVentilator Bed : Rs.9000/- per day");
	printf("\n\n\t\t\tOther charges depend accordingly");
	getch();
	PatientMenu();
}

void PlasmaDonor()
{
	system("cls");
	Title();
	printf("\n\n\n\t\t\tEnter the patient ID:");
	int pid;
	scanf("%d",&pid);
	printf("\n\n\t\t\tDo you want to be a plasma donor?");
	printf("\n\n\t\t\tEnter 1.Yes 2.No:");
	int choice;
	scanf("%d",&choice);
	if(choice==1)
	{
		fpd=fopen("PlasmaDonor.txt","a");
		putw(pid,fpd);
		fclose(fpd);
		printf("\n\n\t\t\t\tThankyou");
		getch();
	}
	else
	{
		printf("\n\n\t\t\tThank you for visiting");
	}
	getch();
	PatientMenu();
}

void Register()
{
	system("cls");
	Title();
	int count=0;
	char c;
	int valid,val,v,va;
	fr=fopen("Register.txt","r");
	for(c=getc(fr);c!=EOF;c=getc(fr))
	{
		if(c=='\n')
			count=count+1;
	}
	count=count+1;
	fclose(fr);
	fr=fopen("Register.txt","a");
	printf("\n\n\t\t\t|||||||||||||||||||||||||||||||Adding Patients Record|||||||||||||||||||||||||||||||||||||");
	p.PatientID=count;
	printf("\n\n\t\t\tYour UserID is: %d",p.PatientID);
	H:
	printf("\n\n\t\t\tFIRSTNAME: ");
    	scanf("%s",p.FirstName);
	if(strlen(p.FirstName)>25 || strlen(p.FirstName)<3)
	{
		printf("\n\t\t\tInvalid Name.Please Enter again");
		goto H;
	}
	for(int i=0;i<strlen(p.FirstName);i++)
	{
		if(isalpha(p.FirstName[i]))
			val=1;
		else
		{
			val=0;
			break;
		}
	}
	if(val==0)
	{
		printf("\n\t\t\tContains invalid Characters. Please Enter again");
		goto H;
	}
	p.FirstName[0]=toupper(p.FirstName[0]);
	LN:
	printf("\n\t\t\tLASTNAME: ");
    	scanf("%s",p.LastName);
	if(strlen(p.LastName)>25 || strlen(p.LastName)<3)
	{
		printf("\n\t\t\tInvalid Name.Please Enter again");
		goto LN;
	}
	for(int i=0;i<strlen(p.LastName);i++)
	{
		if(isalpha(p.LastName[i]))
			v=1;
		else
		{
			v=0;
			break;
		}
	}
	if(v==0)
	{
		printf("\n\t\t\tContains invalid Characters. Please Enter again");
		goto LN;
	}
	p.LastName[0]=toupper(p.LastName[0]);
	AE:
	printf("\n\t\t\tAGE: ");
	scanf("%d",&p.Age);
	if(p.Age<=0 || p.Age>110)
	{
		printf("\n\t\t\tInvalid Age.Please enter again");
		goto AE;
	}
	WEI:
	printf("\n\t\t\tWEIGHT: ");
	scanf("%d",&p.Weight);
	if(p.Weight<=0)
	{
		printf("\n\t\t\tInvalid weight.Please Enter again");
		goto WEI;
	}
	D:
	printf("\n\t\t\tBLODD GROUP: ");
	scanf("%s",p.BloodGroup);
	if(!(strcmp(p.BloodGroup,"O+")==0 || strcmp(p.BloodGroup,"O-")==0 || strcmp(p.BloodGroup,"B+")==0 || strcmp(p.BloodGroup,"B-")==0 || strcmp(p.BloodGroup,"AB-")==0 || strcmp(p.BloodGroup,"AB+")==0 || strcmp(p.BloodGroup,"A-")==0 || strcmp(p.BloodGroup,"A+")==0))
	{
		printf("\n\t\t\tInvalid Blood group. Please enter again");
		goto D;
	}	
	A:
	printf("\n\t\t\tGENDER[F/M]: ");
	scanf(" %c",&p.Gender);
	if(toupper(p.Gender)=='M' || toupper(p.Gender)=='F')
		valid=1;
	else
		valid=0;
	if(valid==0)
	{
		printf("\n\t\t\tInvalid Charachter :( Enter either F/M");
		goto A;
	}
	B:
	printf("\n\t\t\tCONTACT NUMBER: ");
	scanf("%s",p.Contact_No);
	if(strlen(p.Contact_No)>10 || strlen(p.Contact_No)<10)
	{
		printf("\n\t\t\tInvalid Phone number");
		goto B;
	}
	for(int i=0;i<strlen(p.Contact_No);i++)
	{
		if(!isalpha(p.Contact_No[i]))
			va=1;
		else
		{
			va=0;
			break;
		}
	}
	if(va==0)
	{
		printf("\n\t\t\tContains Invalid Characters.Please enter again");
		goto B;
	}
	printf("\n\n\n\t\t\tInformation recorded successfully :) ...");
	getch();
	system("cls");
	Title();
	int store[12];
	int i=0;
	printf("\n\n\t\t\t---------------------------------SYMPTOMS MENU--------------------------------\n");
   	printf("\n\t\t\t1 . COLD AND DRYCOUGH");
   	printf("\n\t\t\t2 . FEVER");
        printf("\n\t\t\t3 . TIREDNESS");
        printf("\n\t\t\t4 . SORE THROAT");
        printf("\n\t\t\t5 . ACHES AND PAINS");
  	printf("\n\t\t\t6 . DIARRHOEA");
   	printf("\n\t\t\t7 . CONJUCTIVITIS");
  	printf("\n\t\t\t8 . HEADACHE");
  	printf("\n\t\t\t9 . LOSS OF TASTE OR SMELL");
	printf("\n\t\t\t10 . DIFFICULTY IN BREATHING");
 	printf("\n\t\t\t11 . CHEAST PAIN");
	printf("\n\n\t\t\tEnter the symptoms that you have separated by space. Press 0 to end the list:");
	scanf("%d",&store[i]);
	while(store[i]!=0)
	{
		i++;
		scanf("%d",&store[i]);
		if(store[i]>11 || store[i]<0)
		{
			printf("\n\t\t\tInvalid Choice\t");
			i--;
		}
		
	}
	system("cls");
	Title();
	printf("\n\n\t\t\tBasicPrecautions to be taken are:\n\n");
	for(i=0;store[i]!=0;i++)
	{
		switch(store[i])
  	        {
			case 1: 
				strcat(p.Symp,"Cold,drycough,");
				printf("\n\n\t\t\t*Take OTC cough supressants(Robitussin),to suppress your cough");
				printf("\n\n\t\t\t*Adding honey to do drink to soothe irritated throat tissue");
				break;
			case 2:
				strcat(p.Symp,"Fever,");
			       	printf("\n\n\t\t\t*Paracetamol and Ibuprofen");
				break;
     	                case 3:
				strcat(p.Symp,"Tiredness,");
			       	printf("\n\n\t\t\t*See docter immediately");
				printf("\n\n\t\t\t*Modafinil drug");
				break;
     		        case 4: 
				strcat(p.Symp,"SoreThroat,");
				printf("\n\n\t\t\t*Drinking plenty of liquids");
				printf("\n\n\t\t\t*Gargling with warm water");
			        printf("\n\n\t\t\t*Take pain medication such as Ibuprofen or Paracetamol");
				break;
    		        case 5:
				strcat(p.Symp,"Aches,Pains,");
			       	printf("\n\n\t\t\t*Some good choices for pain relief are Acetaminophen,Aspirin,ibuprofen and naproxen");
				break;
     		        case 6:
				strcat(p.Symp,"Diarrhoea,");
			       	printf("\n\n\t\t\t*Replacing lost fluids with an oral rehydration solution(ORS) may help to prevent dehydration");
				break;
     		        case 7:
				strcat(p.Symp,"Conjuctivities,");
			       	printf("\n\n\t\t\t*Consult docter immediately");
				break;
      			case 8:
				strcat(p.Symp,"Headache,");
			       	printf("\n\n\t\t\t*Take drugs like Aspirin,Parcetamol");
				break;
      			case 9:
				strcpy(p.Symp,"Lossoftaste,smell,");
			       	printf("\n\n\t\t\t*Treating the underlying condition that causes your impaired sense of taste can help restore your taste");
				break;
      			case 10:
				strcat(p.Symp,"Difficultyinbreathing,");
			       	printf("\n\n\t\t\t*Consult docter immediately");
				break;
     			case 11:
			        strcpy(p.Symp,"ChestPain,");	
				printf("\n\n\t\t\t*Consult docter immediately");
				break;
		}
	}
	getch();
	fprintf(fr,"PatientID:%d FirstName:%s LastName:%s Age:%d Weight:%d BloodGroup:%s Gender:%c ContactNo:%s Symptoms:%s\n",p.PatientID,p.FirstName,p.LastName,p.Age,p.Weight,p.BloodGroup,toupper(p.Gender),p.Contact_No,p.Symp);
	fclose(fr);
	TestReport();
}

void TestReport()
{
	system("cls");
	Title();
	int TestCount;
	char ch;
	int num;
	printf("\n\n\n\n\t\t\tPlease Enter Your Covid Report....");
	printf("\n\n\t\t\t1. Tested COVID Positive ");
	printf("\n\n\t\t\t2. Tested COVID Negative ");
	printf("\n\n\n\n\t\t\tChoose either 1 or 2:");
	scanf("%d",&TestCount);
	if(TestCount==1)
	{
		strcpy(p.CovidReport,"Positive");
		fpc=fopen("PositiveCount.dat","a");
		fprintf(fpc,"%d %s%s %s\n",p.PatientID,p.FirstName,p.LastName,p.CovidReport);
		fclose(fpc);
	}
	else if(TestCount==2)
	{
		strcpy(p.CovidReport,"Negative");
		fnc=fopen("NegativeCount.dat","a");
		fprintf(fnc,"%d %s%s %s\n",p.PatientID,p.FirstName,p.LastName,p.CovidReport);
		fclose(fnc);
	}
	else
	{
		printf("\n\n\t\t\tInvalid Input:( Please enter the right choice..");
		getch();
		TestReport();
	}
	printf("\n\n\t\t\tYour Information is successfully stored. Your report is forwarded to doctor");
	getch();
	UserMenu();
}

void Count()
{
	system("cls");
	Title();
	int status;
	char c;
	int ch;
	int poc=0;
	int noc=0;
	int pc=0;
	printf("\n\n\n\t\t\t1. Total number of Patients");
	printf("\n\n\t\t\t2. Positive Cases Count");
	printf("\n\n\t\t\t3. Negative Cases Count");
	printf("\n\n\n\t\t\tEnter your choice you want to enter:");
	scanf("%d",&status);
	switch(status)
	{
		case 1:
			fr=fopen("Register.txt","r");
			for(c=getc(fr);c!=EOF;c=getc(fr))
			{
				if(c=='\n')
					pc=pc+1;
			}
			fclose(fr);
			printf("\n\n\n\t\t\t The Total number of patients visited are : %d",pc);
			ch=1;
			break;
		case 2:
			fpc=fopen("PositiveCount.dat","r");
			for(c=getc(fpc);c!=EOF;c=getc(fpc))
			{
				if(c=='\n')
					poc=poc+1;
			}
			fclose(fpc);
			printf("\n\n\t\t\tThe positive count is: %d ",poc);
			ch=1;
			break;

		case 3:
			fnc=fopen("NegativeCount.dat","r");
			for(c=getc(fnc);c!=EOF;c=getc(fnc))
			{
				if(c=='\n')
					noc=noc+1;
			}
			printf("\n\n\t\t\tThe negative count is: %d", noc);
			fclose(fnc);
			ch=1;
			break;
		default:
			printf("\n\n\t\t\tInvalid choice :( Please enter again");
			getch();
			Count();
	}
	if(ch==1)
{
	printf("\n\n\n\t\t\tDo you want to continue to check the count?Press\n\t\t\t1. Continue\n\t\t\t2. Go Back\n\t\t\t3.Exit");
	int choose;
	F:
	printf("\n\t\t\tEnter your choice:");
	scanf("%d",&choose);
	switch(choose)
	{
		case 1:
			Count();
			break;
		case 2:
			if(C==1)
			{
				C=0;
				UserMenu();
			}
			else if(C==0)
				DoctorMenu();
			break;
		case 3:
			ex_it();
			break;
		default:
			printf("\n\n\t\t\tInvalid choice.Please enter again");
			goto F;
	}
}			
}

void BedCount()
{
	system("cls");
	Title();
	int a,b,c;
	printf("\n\n\t\t\tTotal number of Normal Beds=20");
	printf("\n\n\t\t\tTotal number of Oxygen Beds=20");
	printf("\n\n\t\t\tTotal number of Ventilator Beds=20");
	fhc=fopen("HomeQuarantine.txt","r");
	while((a=getw(fhc))!=EOF)
	{
		printf("\n\n\t\t\tPatients in Home Quarantine:%d",a);
	}
	fclose(fhc);
	fgb=fopen("GeneralBed.txt","r");
	while((a=getw(fgb))!=EOF)
	{
		printf("\n\n\t\t\tPatients in General beds:%d",a);
	}
	fclose(fgb);
	fob=fopen("OxygenBed.txt","r");
	while((a=getw(fob))!=EOF)
	{
		printf("\n\n\t\t\tPatients in Oxygen beds:%d",a);
	}
	fclose(fob);
	fvb=fopen("VentilatorBed.txt","r");
	while((a=getw(fvb))!=EOF)
	{
		printf("\n\n\t\t\tPatients in Ventilator beds:%d",a);
	}
	fclose(fvb);
	getch();
	if(BC==1)
	{
		BC=0;
		UserMenu();
	}
	else if(BC==0)
		DoctorMenu();
}

void PatientHistory()
{
	system("cls");
	Title();
	int temp=1;
	char ch=' ';
	char c;
	int choice,count;
	printf("\n\n\n\t\t\t1. Search by ID");
	printf("\n\n\t\t\t2. Search by Name");
	printf("\n\n\t\t\tEnter 1 or 2:");
	scanf("%d",&choice);
	if(choice==1)
	{
		printf("\n\n\n\t\t\tEnter the patient ID:");
		scanf("%d",&ID);
		ct=1;
		printf("\n\t\t\t");	
		fr=fopen("Register.txt","r");
		for(c=getc(fr);c!=EOF;c=getc(fr))
		{
			if(c=='\n')
				count=count+1;
		}
		rewind(fr);
		if(ID>count || ID<=0)
		{	
			printf("Record not found!");
			printf("\n\t\t\tPlease enter the right details ");
			getch();
			PatientHistory();
		}
		while((ch=getc(fr))!=EOF)
		{
			if(ch=='\n')
			{	
				temp++;
			}
			if(temp==ID)
			{
				if(ch==' ')
					printf("\n\n\t\t\t");
				printf("%c",ch);
			}
		}
		getch();
		fclose(fr);
	}
	else if(choice==2)
	{
		ct=2;
		Search();
	}
	else
	{
		printf("\n\t\t\tInvalid Choice Please enter again");
		getch();
		PatientHistory();
	}
	if(Docch==1)
	{
		BedAdmit();
	}
	else
	{
		g:
		printf("\n\n\t\t\tDo you want to continue? Press\n\t\t\t1. Continue\n\t\t\t2. GoBack\n\t\t\t3. Exit"); 
		int choose;
		printf("\n\t\t\tEnter your choice:");
		scanf("%d",&choose);
		switch(choose)
		{
			case 1:
				PatientHistory();
				break;
			case 2:
				UserMenu();
				break;
			case 3:
				ex_it();
				break;
			default:
				printf("\n\t\t\tInvalid choice.Please enter again");
				goto g;
		}
	}
}

void Search(void)
{
	system("cls");
	Title();
	fr=fopen("Register.txt","r");
	printf("\n\n\t\t\tEnter the patient first name:");
	scanf("%s",fname);
	printf("\n\n\t\t\tEnter last name:");
	scanf("%s",lname);
	fflush(stdin);
	fname[0]=toupper(fname[0]);
	lname[0]=toupper(lname[0]);
	while(fscanf(fr,"PatientID:%d FirstName:%s LastName:%s Age:%d Weight:%d BloodGroup:%s Gender:%c ContactNo:%s Symptoms:%s\n",&p.PatientID,p.FirstName,p.LastName,&p.Age,&p.Weight,p.BloodGroup,&(p.Gender),p.Contact_No,p.Symp)!=EOF)
	{
		if((strcmp(p.FirstName,fname)==0) && (strcmp(p.LastName,lname)==0))
		{
			printf("\n\t\t\tPatientID: %d",p.PatientID);
			printf("\n\t\t\tFirst Name: %s",p.FirstName);
			printf("\n\t\t\tLast Name: %s",p.LastName);
			printf("\n\t\t\tAge: %d",p.Age);
			printf("\n\t\t\tWeight: %d",p.Weight);
			printf("\n\t\t\tBloodGroup: %s",p.BloodGroup);
			printf("\n\t\t\tGender: %c",p.Gender);
			printf("\n\t\t\tContact Number: %s",p.Contact_No);
			printf("\n\t\t\tSymptoms: %s",p.Symp);
			break;
		}
	}
	if(strcmp(p.FirstName,fname)!=0 && strcmp(p.LastName,lname)!=0)
	{
		printf("\n\n\t\t\tRecord not found");
		printf("\n\t\t\tPlease enter valid details");
		getch();
		PatientHistory();
	}	
	fclose(fr);
	getch();
}

void BedAdmit()
{
	printf("\n\n\t\t\tDoes the Patient need to be admitted.Press 1.HomeQuarantine and 2.Bed Admission:");
	int choose;
	scanf("%d",&choose);
	if(choose==1)
	{
		fhc=fopen("HomeQuarantine.txt","r");
		int n,a;
		while((n=getw(fhc))!=EOF)
		{
			a=n+1;	
		}
		fclose(fhc);
		fhc=fopen("HomeQuarantine.txt","w");
		putw(a,fhc);	
		fclose(fhc);
		printf("\n\n\t\t\tcare Taker will be alloted :)");
		getch();
		CareTaker();
	}
	else
	{	printf("\n\t\t\t--------------------------------------------------------------------------------------------------------");
		printf("\n\n\t\t\tChoose the type of bed need to be admitted:");
		printf("\n\n\t\t\t1. General Bed");
		printf("\n\t\t\t2. Oxygen Facililty included Bed");
		printf("\n\t\t\t3. Ventilator Facility included Bed");
		printf("\n\n\t\t\tEnter the type of bed:");
		int bedch;
		scanf("%d",&bedch);
		if(bedch==1)
		{
			fgb=fopen("GeneralBed.txt","r");
			int n,a;
			while((n=getw(fgb))!=EOF)
			{
				a=n+1;	
			}
			fclose(fgb);
			if(a>20)
				printf("\n\n\t\t\tNo Empty beds");
			else
			{
				fgb=fopen("GeneralBed.txt","w");
				putw(a,fgb);	
				fclose(fgb);
			}
			DoctorMenu();	
		}
		else if(bedch==2)
		{
			fob=fopen("OxygenBed.txt","r");
			int n,a;
			while((n=getw(fob))!=EOF)
			{
				a=n+1;	
			}
			fclose(fob);
			if(a>20)
				printf("\n\n\t\t\tNo Empty beds");
			else
			{
				fob=fopen("OxygenBed.txt","w");
				putw(a,fob);	
				fclose(fob);
			}
			DoctorMenu();	
		}
		else if(bedch==3)
		{
			fob=fopen("VentilatorBed.txt","r");
			int n,a;
			while((n=getw(fvb))!=EOF)
			{
				a=n+1;	
			}
			fclose(fvb);
			if(a>20)
				printf("\n\n\t\t\tNo Empty beds");
			else
			{
				fvb=fopen("VentilatorBed.txt","w");
				putw(a,fvb);	
				fclose(fvb);
			}
			DoctorMenu();	
		}
	}
}
