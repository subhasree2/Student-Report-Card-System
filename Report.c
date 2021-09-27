#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct student
{
  int rollno;
  char name[50];
  int marks[5];
  float percentage;
  char grade;
  int std;
  char sec;
  int Total;
} st;

void
min_perc (void)
{
  FILE *fptr;
  fptr = fopen ("student.dat", "r");
  int flag = 0;
  printf ("\nTell us the minimum percentage :");
  float pass;
  scanf ("%f", &pass);
  while ((fscanf
	  (fptr, "%s %d %d %c %d %d %d %d %d %d %f %c", st.name, &st.rollno,
	   &st.std, &st.sec, &st.marks[0], &st.marks[1], &st.marks[2],
	   &st.marks[3], &st.marks[4], &st.Total, &st.percentage,
	   &st.grade) > 0))
    {
      if (st.percentage < pass)
	{
	  printf
	    ("\nName of the student(s) who got below minimum percentage :");
	  printf ("%s %f\n", st.name, st.percentage);
	  flag = 1;
	}
    }
  if (flag == 0 && st.percentage > pass)
    {
      printf ("\n***All Students are above minimum percentage***\n");
    }
  fclose (fptr);
}

void
Fail (void)
{
  FILE *fptr;
  fptr = fopen ("student.dat", "r");
  int flag = 0;
  while ((fscanf
	  (fptr, "%s %d %d %c %d %d %d %d %d %d %f %c", st.name, &st.rollno,
	   &st.std, &st.sec, &st.marks[0], &st.marks[1], &st.marks[2],
	   &st.marks[3], &st.marks[4], &st.Total, &st.percentage,
	   &st.grade) > 0))
    {
      if (st.grade == 'F')
	{
	  printf ("\nName of the student(s) who failed :");
	  printf ("%s %f\n", st.name, st.percentage);
	  flag = 1;
	}
    }
  if (flag == 0)
    {
      printf ("\n***All Students passed***\n");
    }
  fclose (fptr);
}

void
write_student ()
{
  FILE *fptr;
  fptr = fopen ("student.dat", "a");
  printf ("How many records you want to create :");
  int rec,i ; 
  char name[101];
  scanf ("%d", &rec);
  for (int i = 0; i < rec; i++)
    {
      printf ("\nPlease Enter The Details :\n");
      printf ("\nEnter The roll number of student :");
      scanf ("%d", &st.rollno);
      printf ("\nEnter The Name of student :");
      scanf("%s", st.name);
      printf ("\nEnter the standard and section of student :");
      scanf ("%d %c", &st.std, &st.sec);
      fprintf (fptr, "%s\t\t\t%d\t\t\t%d%c\t\t", st.name, st.rollno, st.std,
	       st.sec);
      for (int i = 1; i <= 5; i++)
	{
	  printf ("\nEnter the marks of Subject %d :", i);
	  scanf ("%d", &st.marks[i]);
	  fprintf (fptr, "%d       ", st.marks[i]);
	}
      st.Total = st.marks[1] + st.marks[2] + st.marks[3] + st.marks[4] +
	st.marks[5];
      st.percentage = st.Total / 5.0;
      if (st.percentage >= 90)
	st.grade = 'A';
      else if (st.percentage >= 70 && st.percentage < 90)
	st.grade = 'B';
      else if (st.percentage >= 40 && st.percentage < 70)
	st.grade = 'C';
      else
	st.grade = 'F';
      fprintf (fptr, "%d   %.2f         %c\n", st.Total, st.percentage,
	       st.grade);
    }
  fclose (fptr);
  printf ("\n\n          ***Student Record Has Been Created***\n\n");
}

void
display_all ()
{
  printf ("\n\n\n\t\tDISPLAYING ALL RECORD !!!\n\n");
  FILE *fptr;
  int flag = 0;
  fptr = fopen ("student.dat", "r");
  while ((fscanf
	  (fptr, "%s %d %d %c %d %d %d %d %d %d %f %c", st.name, &st.rollno,
	   &st.std, &st.sec, &st.marks[0], &st.marks[1], &st.marks[2],
	   &st.marks[3], &st.marks[4], &st.Total, &st.percentage,
	   &st.grade) > 0))
    {
      printf ("\nName of Student : %s", st.name);
      printf ("\nRoll Number of student : %d", st.rollno);
      printf ("\nStd and Sec : %d %c", st.std, st.sec);
      printf ("\nMarks in Subject1: %d", st.marks[0]);
      printf ("\nMarks in Subject2: %d", st.marks[1]);
      printf ("\nMarks in Subject3: %d", st.marks[2]);
      printf ("\nMarks in Subject4: %d", st.marks[3]);
      printf ("\nMarks in Subject5: %d", st.marks[4]);
      printf ("\nTotal : %d/500", st.Total);
      printf ("\nPercentage : %f", st.percentage);
      printf ("\nGrade : %c\n", st.grade);
      flag = 1;
    }
  if (flag == 0)
    {
      printf ("\n***Details cannot be found***\n\n");
    }
  fclose (fptr);
}

void
display_std ()
{
  printf ("\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n");
  FILE *fptr;
  int flag = 0, class;
  char section;
  printf ("\nEnter the standard and section you want to display : ");
  scanf ("%d %c", &class, &section);
  fptr = fopen ("student.dat", "r");
  while ((fscanf
	  (fptr, "%s %d %d %c %d %d %d %d %d %d %f %c", st.name, &st.rollno,
	   &st.std, &st.sec, &st.marks[0], &st.marks[1], &st.marks[2],
	   &st.marks[3], &st.marks[4], &st.Total, &st.percentage,
	   &st.grade) > 0))
    {
      if (st.std == class && st.sec == section)
	{
	  printf ("\nName of Student : %s", st.name);
	  printf ("\nRoll Number of student : %d", st.rollno);
	  printf ("\nStd and Sec : %d %c", st.std, st.sec);
	  printf ("\nMarks in Subject1: %d", st.marks[0]);
	  printf ("\nMarks in Subject2: %d", st.marks[1]);
	  printf ("\nMarks in Subject3: %d", st.marks[2]);
	  printf ("\nMarks in Subject4: %d", st.marks[3]);
	  printf ("\nMarks in Subject5: %d", st.marks[4]);
	  printf ("\nTotal: %d/500", st.Total);
	  printf ("\nPercentage : %f", st.percentage);
	  printf ("\nGrade : %c\n", st.grade);
	  flag = 1;
	}
    }
  if (flag == 0)
    {
      printf ("\n\n***Details cannot be found***\n\n");
    }
  fclose (fptr);
}

void
display_stud (int n)
{
  int flag = 0;
  FILE *fptr;
  fptr = fopen ("student.dat", "r");
  while ((fscanf
	  (fptr, "%s %d %d %c %d %d %d %d %d %d %f %c", st.name, &st.rollno,
	   &st.std, &st.sec, &st.marks[0], &st.marks[1], &st.marks[2],
	   &st.marks[3], &st.marks[4], &st.Total, &st.percentage,
	   &st.grade) > 0))
    {
      if (st.rollno == n)
	{
	  printf ("\n\t\t\t*************REPORT CARD*******************");
	  printf ("\n\t\t\t::Name : %s", st.name);
	  printf ("\n\t\t\t::Roll number : %d", st.rollno);
	  printf ("\n\n\t\t\t::Marks in Subject1 : %d", st.marks[0]);
	  printf ("\n\t\t\t::Marks in Subject2 : %d", st.marks[1]);
	  printf ("\n\t\t\t::Marks in Subject3 : %d", st.marks[2]);
	  printf ("\n\t\t\t::Marks in Subject4 : %d", st.marks[3]);
	  printf ("\n\t\t\t::Marks in Subject5 : %d\n", st.marks[4]);
	  printf ("\n\t\t\t::Total : %d/500", st.Total);
	  printf ("\n\t\t\t::Percentage : %.2f", st.percentage);
	  printf ("\n\t\t\t::Grade : %c\n\n", st.grade);
	  printf ("\t\t\t*******************************************\n\n");
	  flag = 1;
	}
    }
  if (flag == 0)
    {
      printf ("\n***Details cannot be found***\n\n");
    }
  fclose (fptr);
}

void
result ()
{
  int rno;
  printf ("\n\nEnter Roll Number Of Student : ");
  scanf ("%d", &rno);
  display_stud (rno);
}

int
edit_menu ()
{
  char str[10];
  int x, num;
  printf ("\n\tEDIT MENU");
  printf
    ("\n------------------------------------------------------------------------------------");
  printf ("\nEnter 1 -> CREATE STUDENT RECORD");
  printf ("\nEnter 2 -> DISPLAY ALL STUDENTS RECORDS");
  printf ("\nEnter 3 -> SEARCH STUDENT RECORD");
  printf ("\nEnter 4 -> STUDENTS OF MINIMUM PERCENTAGE");
  printf ("\nEnter 5 -> DISPLAY REPORT CARDS OF A CLASS");
  printf ("\nEnter 6 -> FAILED STUDENTS");
  printf ("\nEnter 7 -> BACK TO MAIN MENU");
  printf ("\nEnter 8 -> EXIT");
  printf
    ("\n-------------------------------------------------------------------------------------");
  printf ("\n\nPlease Enter Your Choice (1-8) : ");
  scanf ("%s", str);
  sscanf (str, "%d", &x);
  switch (x)
    {
    case 1:
      write_student ();
      edit_menu ();
      break;
    case 2:
      printf
	("\n***************REPORT CARD OF ALL STUDENTS*************************");
      display_all ();
      edit_menu ();
      break;
    case 3:
      printf ("\n\n\tPlease Enter The roll number : ");
      scanf ("%d", &num);
      display_stud (num);
      edit_menu ();
      break;
    case 4:
      min_perc ();
      edit_menu ();
      break;
    case 5:
      display_std ();
      edit_menu ();
      break;
    case 6:
      Fail ();
      edit_menu ();
      break;
    case 7:
      break;
    case 8:
      printf ("\nThank You!!!");
      exit (0);
    default:
      printf ("Choice is invalid!!!\nTry again\n");
      edit_menu ();
    }
}

int
main ()
{
  char str[10];
  int x;
  printf
    ("\n\t\t~~~~~~~~~~~~~~~WELCOME TO STUDENT REPORT CARD SYSTEM~~~~~~~~~~~~~~~~");
  printf ("\n\nEnter the userid and password :");
  int n = 1;
  char name[50];
  char password[50];
  while (1)
    {
    redo:
      scanf ("%s %s", name, password);
      if (strcmp (name, "admin") == 0 && strcmp (password, "admin02") == 0)
	{
	  printf ("\nLOGGED IN SUCCESSFULLY!!\n\n");
	}
      else if (n == 3)
	{
	  printf
	    ("\nThe userID and the password is incorrect!!!\nTry again later!!");
	  return 0;
	}
      else
	{
	  printf ("\nEnter the correct userid and password!!!\n");
	  n++;
	  goto redo;
	}
    again:
      printf
	("\n\t\t*********************************************************************");
      printf ("\n\t\t\t\tSTUDENT REPORT CARD SYSTEM\n");
      printf
	("\n\t\t*********************************************************************");
      printf ("\n\n\tMAIN MENU\n");
      printf
	("------------------------------------------------------------------------------------");
      printf ("\nEnter 1 -> REPORT CARD GENERATION");
      printf ("\nEnter 2 -> EDITING OPTIONS");
      printf ("\nEnter 3 -> EXIT\n");
      printf
	("------------------------------------------------------------------------------------");
      printf ("\n\nPlease Select Your Option (1-3) : ");
      scanf ("%s", str);
      sscanf (str, "%d", &x);
      switch (x)
	{
	case 1:
	  result ();
	  goto again;
	  break;
	case 2:
	  edit_menu ();
	  goto again;
	  break;
	case 3:
	  printf ("\n***Thank you!!***");
	  exit (0);
	default:
	  printf ("\nChoice is invalid!!!\nTry again!!\n");
	  goto again;
	}
    }
  return 0;
}
