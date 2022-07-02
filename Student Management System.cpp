#include<iostream>
#include<fstream>
#include<iomanip>
#include<stdlib.h>

using namespace std;

class Student
{
 int admno;
 char name[20];
 char gender;
 int std;
 float markss;
 double percentage;
 int year, exam, sub, k = 0, i, j = 0, marks[50][50], p;
 int physics, chemistry, mathematics, english, comscience;

 char grade;
 void calculate();
 void grd();
 public:
  void getData();
  void showData();
  int getAdmno(){return admno;}//doubt
}s;// object of class that is s

void Student::grd(){
    if(percentage>85) {
cout<<"Grade                : A grade";
}
else if(percentage<85 && percentage>=75)
{
cout<<"Grade                : B grade";
}
else if(percentage<75 && percentage>=50)
{
cout<<"Grade                : C grade";
}
else if(percentage<50 && percentage>=30)
{
cout<<"Grade                 : D grade";
}
else
{
cout<<"Fail";
}

}


void Student::calculate()
{
     markss=physics+chemistry+mathematics+english+comscience;
   percentage=(physics+chemistry+mathematics+english+comscience)/5.0;
   }
void Student::getData()
{
 cout<<"\n\nEnter Student Details......\n";
 cout<<"Enter Admission No.     : "; cin>>admno;
 cout<<"Enter Full Name         : "; cin.ignore(); cin.getline(name,20);//ignore () to used to ignore inputs upto given range
 cout<<"Enter Gender (M/F)      : "; cin>>gender;
 cout<<"\n\n --Enter Academics Details--\n\n";
 cout<<"Enter Standard          : "; cin>>std;
 cout<<"-------------Enter Marks -------------------: ";
cout<<"\nEnter student's physics grade: ";
cin>>physics;
cout<<"Enter student's chemistry grade: ";
cin>>chemistry;
cout<<"Enter student's mathematics grade: ";
cin>>mathematics;
cout<<"Enter student's english grade: ";
cin>>english;
cout<<"Enter student's computer science grade: ";
cin>>comscience;
printf("\n");


   printf("Enter the year of the student(1,2,3,4,5):");
  scanf("%d", &year);
examnum:
  printf("Enter the number of tests(including 4CAs,ETE and MTE:)");
  scanf("%d", &exam);
  if (exam > 6)
  {
    printf("Invalid entry");
    goto examnum;
  }

  printf("Enter the number of subjects:");
  scanf("%d", &sub);
  printf("\n\n\n**Marks of student(Max Marks=100)**\n");

  for (i = 0; i < year * 2; i++)
  {

    printf("\n***Enter the marks for %d semester*\n", i + 1);

    for (j = 0; j < sub; j++)
    {

      printf("\n**Marks for %d subject:**\n", j + 1);

      for (p = 0; p < exam - 2; k++, p++)
      {
        printf("Enter the Marks for %d CA : ", p+1);
        scanf("%d", &marks[i][k]);

      }
      printf("Enter the Marks for MTE:");
      scanf("%d", &marks[i][k]);

      printf("Enter the Marks for ETE:");
      scanf("%d", &marks[i][++k]);

     k++;
    }
  }





 cout<<endl;
 calculate();
system("cls");

}



void Student::showData()
{

cout<<"Admission No.        : "<<admno<<endl;
cout<<"Full Name            : "<<name<<endl;
cout<<"Gender               : "<<gender<<endl;
cout<<"Standard             : "<<std<<endl;
cout<<"* * * * * * Marks Obtained * * * * * * \n";
cout<<"Physics              : "<<physics<<endl;
cout<<"Chemistry            : "<<chemistry<<endl;
cout<<"Mathematics          : "<<mathematics<<endl;
cout<<"English              : "<<english<<endl;
cout<<"Computer Science     : "<<comscience<<endl;
cout<<"Marks (out of 500)   : "<<markss<<endl;
cout<<"Percentage           : "<<percentage<<"%"<<endl;


   printf("\n\n****** Marks of Students ******\n\n ");
 k=0;

  for (i = 0; i < year * 2; i++)
  {

    printf("\n\n\nMarks for %d semester\n\n", i + 1);

    for (j = 0; j < sub; j++)
    {

      printf("\n\nMarks for %d subject:\n ", j + 1);

      for (p = 0; p < exam - 2;  p++)
      {
        printf("Marks for %d CA:", p+1);
       printf("%d\n", marks[i][k]);

       k++;
      }
      printf("Marks for MTE:");
      printf("%d\n", marks[i][k]);


      printf("Marks for ETE:");
      printf("%d\n", marks[i][++k]);


    k++;
    }
  }

cout<<endl;
cout<<"\n----------------------------------------------------------------------------------------------------------\n";

}


//writing to binary file
void addData()
{
 ofstream fout;//to do output opertations in file write ()put() seekp()
 fout.open("Students.txt",ios::out|ios::app); //fout--object of file stream ofstream

                                              //this file open in binary mode with append mode all output operations are at end of the file
 s.getData();//taking student data

 fout.write((char*)&s,sizeof(s));//writing to binary file
 fout.close();
 cout<<"\n\nData Successfully Saved to File....\n";
}


//reading from binary file

void displayData()
{
 ifstream fin;
 fin.open("Students.txt",ios::in);
 while(fin.read((char*)&s,sizeof(s)))//data is read until the end of the file is not occured
 {
  s.showData(); //calling show data
 }
 fin.close();
 cout<<"\n\nData Reading from File Successfully Done....\n";
}

void searchData()
{
 int n, flag=0;
 ifstream fin;
 fin.open("Students.txt",ios::in);//open the file then search
 cout<<"Enter Admission Number you want to search : ";
 cin>>n;

 while(fin.read((char*)&s,sizeof(s)))
 {
  if(n==s.getAdmno())  // calling the function through object of class
  {
   cout<<"The Details of Admission No. "<<n<<" shown herewith:\n";
   s.showData();
   flag++;
  }
 }
 fin.close();
 if(flag==0)
  cout<<"The Admission No. "<<n<<" not found....\n\n";
 cout<<"\n\nData Reading from File Successfully Done....\n";
}

void deleteData()
{
 int n, flag=0;
 ifstream fin;
 ofstream fout,tout;

 fin.open("Students.txt",ios::in);
 fout.open("TempStud.txt",ios::out|ios::app);
 tout.open("TrashStud.txt",ios::out|ios::app);

 cout<<"Enter Admission Number you want to move to Trash : ";
 cin>>n;

 while(fin.read((char*)&s,sizeof(s)))
 {
  if(n==s.getAdmno()) //seraching for admission number
  {
   cout<<"The Following Admission No. "<<n<<" has been moved to Trash:\n";
   s.showData();
   tout.write((char*)&s,sizeof(s)); //(after deleteion) writing data in new trashstud.dat file if admisson number  found
   flag++;
  }
  else
  {
   fout.write((char*)&s,sizeof(s)); //(nothing changed) if admisson no not found then write same data in temporary file tempstud.dat
  }
 }
 fout.close();
 tout.close();
 fin.close();
 if(flag==0)
  cout<<"The Admission No. "<<n<<" not found....\n\n";
 remove("Students.dat");// now deleting student.dat
 rename("tempStud.dat","Students.txt");//and renaming our temorary file to student.dat(recovery file)
}
// (recycle bin ) getting deleted data from trashstud.dat file
void getTrash()
{
 ifstream fin;
 fin.open("TrashStud.dat",ios::in);
 while(fin.read((char*)&s,sizeof(s)))
 {
  s.showData();
 }
 fin.close();
 cout<<"\n\nData Reading from Trash File Successfully Done....\n";
}

//modified data must be of the same length as previous data

void modifyData()
{
 int n, flag=0, pos;
 fstream fio; //using   [fstream =ifstream+ofstream]

 fio.open("Students.txt",ios::in|ios::out); //modifying data to same file

 cout<<"Enter Admission Number you want to Modify : ";
 cin>>n;

 while(fio.read((char*)&s,sizeof(s)))
 {
  pos=fio.tellg(); //returns the current position of the get pointer
  if(n==s.getAdmno()) //searching for admisson number
  {
   cout<<"The Following Admission No. "<<n<<" will be modified with new data:\n";
   s.showData();
   cout<<"\n\nNow Enter the New Details....\n";
   s.getData(); //taking new data from user
   fio.seekg(pos-sizeof(s)); // moves the get pointer to desired location
   fio.write((char*)&s,sizeof(s));//modifying data
   flag++; //
  }
 }
 fio.close();

 if(flag==0)
  cout<<"The Admission No. "<<n<<" not found....\n\n";
}

void managerecords()
{
 int ch;
 do
 {
  system("cls");

  cout<<"=================================================================================\n\n";
  cout<<"..........................STUDENT MANAGEMENT SYSTEM............................\n\n";
  cout<<"=================================================================================\n";

  cout<<"0. Exit from Program\n";
  cout<<"1. Add NeW Record For Students\n";
  cout<<"2. Show All Records Of Students\n";
  cout<<"3. Search Record Of Students\n";
  cout<<"4. Modify Records Of Students\n";
  cout<<"5. Delete Record Of Students\n";
  cout<<"6. Show Deleted Records Of Students\n";
  cout<<"Enter your choice  : ";
  cin>>ch;
  system("cls"); //use for clear screen
  switch(ch)
  {
   case 1: addData(); break;
   case 2: displayData(); break;
   case 3: searchData(); break;
   case 4: modifyData(); break;
   case 5: deleteData(); break;
   case 6: getTrash(); break;

  }
  system("pause");
 }while(ch);
}

int main()
{
 managerecords();
}
