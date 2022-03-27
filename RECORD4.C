/*This Program will retrieve individual record from the disk */

#include <stdio.h>
#include <conio.h>
#include <string.h>
typedef struct{
			 char  No[12];
			 char  Name[25];
			 char  Crsyr[10];
			 float Grade[5];
		  }Student_Record;
int main()
{
  FILE  *STUDFILE;
  Student_Record   STUDENT;
  int j,Found=0;
  float TGrade;
  char Temp,FName[15],StudNo[12];
  clrscr();
  printf("\n\nEnter Filename where record will be retrieved => ");
  gets(FName);
  printf("\nEnter Student No. of Record to be retrieved => ");
  gets(StudNo);
  printf("\nRetrieving record from %s...",FName);

  STUDFILE=fopen(FName,"r");
  fread(&STUDENT,sizeof(STUDENT),1,STUDFILE);
  while(!feof(STUDFILE)&&Found==0)
	  {
		if (strcmp(StudNo,STUDENT.No)==0)
			Found=1;
		else
			fread(&STUDENT,sizeof(STUDENT),1,STUDFILE);
	  }
  fclose(STUDFILE);

  if (Found==0)
	 printf("Record Not Existing!!!\n\n");
  else
	{
	 printf("Retrieval of Record Successful!!!");

	 printf("\n\nPress Any Key To Continue...\n\n");
	 getch();

	 printf("<@@ STUDENT's INFORMATION @@>\n\n");
	 printf("Student No.    : %s\n",STUDENT.No);
	 printf("Student Name   : %s\n",STUDENT.Name);
	 printf("Course and Year: %s\n",STUDENT.Crsyr);
	 printf("List of grades:\n");
	 for(j=0;j<5;j++)
		printf("\tGrade No. %d => %0.2f\n",j+1,STUDENT.Grade[j]);
	}
  printf("\n\nPress Any Key To Exit...\n\n");
  getch();
  return (0);


}