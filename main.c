/* ..........................VTU SGPA and CGPA Calculator according to 2018 scheme............................... */
#include<stdio.h>
#include<string.h>
int main ()
{
    /* ..........................SGPA Calculation............................. */
  int i,product = 0,sem,n;
  char ch;
  int cc[10],gp[10],sub_marks[10];
  int credits[8]={20,20,24,24,25,24,20,18};
  int c12[10] = {4,4,3,3,3,1,1,1},c34[10] ={3,4,3,3,3,3,2,2,1},c5[10] ={3,4,4,3,3,3,2,2,1};
  int c6[10] = {4,4,4,3,3,2,2,2}, c7[10] ={3,3,3,3,3,2,2,1}, c8[10] ={3,3,8,1,3};
  float sgpa,per=0, num = 0, den = 0;
  char choose[5];
  printf("Do you want to calculate SGPA or CGPA? \n");
  printf("Enter your choice: ");
  scanf("%s",choose);
  if(strcasecmp(choose,"SGPA")==0){
      printf ("Enter semester: ");
      scanf ("%d", &sem);
      if (sem == 1 || sem == 2 || sem == 6 || sem == 7)
	{
	  n = 8;		//number of subjects in 1, 2, 6, 7
	}
      else if (sem == 3 || sem == 4 || sem == 5)
	{
	  n = 9;       //number of subjects in 3, 4, 5
	}
      else
	{
	  n = 5;      //number of subjects in 8
	}
      for (i = 0; i <= n; i++)	//to get course credits..
	{
	    if(sem==1 || sem==2)
	    {
	       cc[i]=c12[i]; 
	    }
	  else if (sem == 3 || sem == 4)
	    {
	      cc[i] = c34[i];
	    }
	  else if (sem == 5)
	    {
	      cc[i] = c5[i];
	    }
	  else if (sem == 6)
	    {
	      cc[i] = c6[i];
	    }
	  else if (sem == 7)
	    {
	      cc[i] = c7[i];
	    }
	  else
	    {
	      cc[i] = c8[i];
	    }
	}
      for (i = 0; i < n; i++)
	{
	  printf (" subject code: 18xx%d%d\n", sem, i+1);
	  printf ("Enter subject marks:");
	  scanf ("%d", &sub_marks[i]);
	}
      for (i = 0; i < n; i++)	//to get grade points...
	{
	  if (sub_marks[i]<=100 && sub_marks[i] >= 90)
	    {
	      gp[i] = 10;
	    }
	  else if (sub_marks[i] < 90 && sub_marks[i] >= 80)
	    {
	      gp[i] = 9;
	    }
	  else if (sub_marks[i] < 80 && sub_marks[i] >= 70)
	    {
	      gp[i] = 8;
	    }
	  else if (sub_marks[i] < 70 && sub_marks[i] >= 60)
	    {
	      gp[i] = 7;
	    }
	  else if (sub_marks[i] < 60 && sub_marks[i] >= 45)
	    {
	      gp[i] = 6;
	    }
	  else if (sub_marks[i] < 45 && sub_marks[i] >= 40)
	    {
	      gp[i] = 4;
	    }
	  else
	    {
	      gp[i] = 0;
	    }
	}
	 printf("subject_code:\tcourse_credits:\tMarks_gained:\tgrade_points_gained:\t\n");
      for (i = 0; i < n; i++)
	{
	  printf("18xx%d%d : \t\t%d\t %d/100\t\t\t %d/10\n",sem,i+1,cc[i],sub_marks[i],gp[i]);
	  product = cc[i] * gp[i];
	  num = num + product;
	  den = den + cc[i];
	}
	sgpa = num/den;
	printf("\t\tSGPA of sem %d: %0.2f\n",sem,sgpa);
	per=(sgpa-0.75)*10;
	printf("\t\tPercentage of sem %d: %0.2f\n",sem,per);
  }
	/*....................... CGPA Calculation............................ */
else if(strcasecmp(choose,"CGPA")==0){
	int sems;
	char choice[3];
    float s[8],cgpa=0,num1[8],den1=0,temp=0;
    printf("Enter number of semesters for which cgpa has to be calculated: ");
    scanf("%d",&sems);
    for(i=0;i<sems;i++)
    {
        printf("Enter SGPA of sem %d : ",i+1);
        scanf("%f",&s[i]);
    }
     for(i=0;i<sems;i++)
     {
         num1[i]=s[i]*credits[i];
         den1=den1+credits[i];
         temp=temp+num1[i];
     }
     cgpa=temp/den1;
     printf("CGPA obtained till sem %d: %0.2f\n",sems,cgpa);
    per = (cgpa-0.75)*10;
    printf("Percentage gained: %0.2f",per);
    }
    }






















