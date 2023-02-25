    ///HEADER FILES
#include<iostream>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<windows.h>
#include<time.h>
using namespace std;

    ///FUNCTIONS DECLARATIONS
int ctn(char);
void delay(int );
void Wrong_Choice_Entered();

    ///CLASS DECLARATIONS
class subject;
class teacher;
class student;
class batch;
class admin;

    ///GLOBAL VARIABLES
int n_all_students = 0;
int n_all_teachers = 0;
int n_all_batches = 0;

    ///CLASS DEFINITIONS
class subject{
protected:
    string subject_name;
    float marks = -1;
    string grade = "-1";
public:
    void get_subject(string str)
    {
        subject_name = str;
    }

    void get_marks(float x)
    {
        marks = x;
    }

    void get_grade(string x)
    {
        grade = x;
    }

    string return_subject()
    {
        return subject_name;
    }

    float return_marks()
    {
        return marks;
    }

    string return_grade()
    {
        return grade;
    }
};

class teacher{
protected:
    char salary_paid;
    string faculy_abbreviation;
    double salary;
    string teacher_name, email_id, position, mobile_no;
    string subject;
    batch *B;
public:
    void getdata()
    {
        fflush(stdin);
        cout <<"Name : ";
        getline(cin, teacher_name);

        fflush(stdin);
        cout <<"Faculty Abbreviation (in UpperCase) : ";
        getline(cin, faculy_abbreviation);

        fflush(stdin);
        cout <<"Position of the Teacher : ";
        getline(cin, position);

        fflush(stdin);
        cout <<"Subject (SDF/Math/Physics) : ";
        getline(cin, subject);

        while((subject != "SDF") && (subject != "Math") && (subject != "Physics"))
        {
            fflush(stdin);
            cerr <<"WRONG Subject Entered !!!" <<endl
                 <<"Re-enter Subject : ";
            getline(cin, subject);
        }

        fflush(stdin);
        cout <<"Mobile Number : ";
        getline(cin, mobile_no);

        fflush(stdin);
        cout <<"Email Address : ";
        getline(cin, email_id);

        fflush(stdin);
        cout <<"Is the salary paid ? (Y/N) ";
        salary_paid = getche();
        cout <<endl;

        while((salary_paid != 'y') && (salary_paid != 'Y') && (salary_paid != 'n') && (salary_paid != 'N'))
        {
            fflush(stdin);
            cerr <<"INVALID INPUT !!!" <<endl
                 <<"Re-enter the response : ";
            salary_paid = getche();
            cout <<endl;
        }

        fflush(stdin);
        cout <<"Salary : ";
        cin >>salary;
    }

    void putdata()
    {
        cout <<"The details of the teacher " <<teacher_name <<" are : " <<endl
             <<"Faculty Abbreviation : " <<faculy_abbreviation <<endl
             <<"Position : " <<position <<endl
             <<"Mobile Number : " <<mobile_no <<endl
             <<"Email ID : " <<email_id <<endl <<endl;
    }

    void salary_details()
    {
        cout <<"The salary is " <<salary <<endl;
        if((salary_paid == 'y') || (salary_paid == 'Y'))
            cout <<"The salary is Paid";
        else
            cout <<"The Salary is Not Paid";
    }

    void get_batch(batch *b);

    void show_students();

    void enter_marks();

    void enter_grades();

    string return_name()
    {
        return teacher_name;
    }

    string return_faculy_abbreviation()
    {
        return faculy_abbreviation;
    }

    string return_subject()
    {
        return subject;
    }

    void get_faculy_abbreviation(string str)
    {
        faculy_abbreviation = str;
    }
}all_teacher_list[100];

class student{
protected:
    char fees_sumbited;
    int enroll_no;
    string student_name, email_id, mobile_no;
    subject sub[3];
    batch *B;

public:
    void getdata()
    {
        fflush(stdin);
        cout <<"Name : ";
        getline(cin, student_name);

        fflush(stdin);
        cout <<"Enrollment Number : ";
        cin >>enroll_no;

        fflush(stdin);
        cout <<"Mobile Number : ";
        getline(cin, mobile_no);

        fflush(stdin);
        cout <<"Email Address : ";
        getline(cin, email_id);

        fflush(stdin);
        cout <<"Is if the fees is submitted (Y/N): ";
        fees_sumbited = getche();
        cout <<endl;

        while((fees_sumbited != 'Y') && (fees_sumbited != 'y') && (fees_sumbited != 'N') && (fees_sumbited != 'n'))
        {
            fflush(stdin);
            cerr <<"INVALID INPUT !!!" <<endl
                 <<"Re-enter the response : ";
            fees_sumbited = getche();
            cout <<endl;
        }

        sub[0].get_subject("SDF");
        sub[1].get_subject("Math");
        sub[2].get_subject("Physics");
    }

    void putdata()
    {
        cout <<"The details of " <<student_name <<" is : " <<endl
             <<"Enrollment Number : " <<enroll_no <<endl
             <<"Mobile Number : " <<mobile_no <<endl
             <<"Email Address : " <<email_id <<endl <<endl;
    }

    void get_batch(batch *b);

    void show_teacher();

    string return_name()
    {
        return student_name;
    }

    char return_fees_submitted()
    {
        return fees_sumbited;
    }

    int return_enrollno()
    {
        return enroll_no;
    }

    void get_enrollno(int a)
    {
        enroll_no = a;
    }

    void get_marks(float x, string str)
    {
        if(str == "SDF")
            sub[0].get_marks(x);
        else if(str == "Math")
            sub[1].get_marks(x);
        else if(str == "Physics")
            sub[2].get_marks(x);
    }

    void get_grades(string ch, string str)
    {
        if(str == "SDF")
            sub[0].get_grade(ch);
        else if(str == "Math")
            sub[1].get_grade(ch);
        else if(str == "Physics")
            sub[2].get_grade(ch);
    }

    void show_marks()
    {
        cout <<"The marks are : " <<endl;
        for(int i=0 ; i < 3 ; ++i)
        {
            cout <<sub[i].return_subject() <<" : " ;
            if(sub[i].return_marks() == -1)
                cout <<"Not Entered" <<endl;
            else
                cout <<sub[i].return_marks() <<endl;
        }
        cout <<endl;
    }

    void show_grades()
    {
        cout <<"The grades are : " <<endl;
        for(int i=0 ; i < 3 ; ++i)
        {
            cout <<sub[i].return_subject() <<" : ";
            if(sub[i].return_grade() == "-1")
                cout <<"Not Entered" <<endl;
            else
                cout <<sub[i].return_grade() <<endl;
        }
        cout <<endl;
    }

}all_student_list[100];

class batch{
protected:
    int n_student, n_teacher;
    string batch_name;
public:
    student student_list[100];
    teacher teacher_list[10];

    void getdata()
    {
        fflush(stdin);
        cout <<"Enter the batch name : ";
        getline(cin, batch_name);

        fflush(stdin);
        cout <<"Enter the number of student : ";
        cin >>n_student;

        fflush(stdin);
        cout <<"Enter the number of teacher : ";
        cin >>n_teacher;

        cout <<"Enter the details of the Students : " <<endl;
        for(int i=0 ; i < n_student ; ++i)
        {
            cout <<"For Student " <<i+1 <<endl;
            student_list[i].getdata();
            cout <<endl;

            all_student_list[n_all_students + i] = student_list[i];
        }
        cout <<endl;
        n_all_students += n_student;

        cout <<"Enter the details of the Teachers : " <<endl;
        for(int i=0 ; i < n_teacher ; ++i)
        {
            cout <<"For Teacher " <<i+1 <<endl;
            teacher_list[i].getdata();
            cout <<endl;

            all_teacher_list[n_all_teachers + i] = teacher_list[i];
        }
        cout <<endl;
        n_all_teachers += n_teacher;

    }

    void putdata()
    {
        cout <<"The list of members of batch " <<batch_name <<" is : " <<endl;

        cout <<"For Students : " <<endl;
        cout <<"Name " <<"\t\t" <<"Enrollment Number" <<endl;
        for(int i=0 ; i < n_student ; ++i)
            cout <<student_list[i].return_name() <<"\t\t" <<student_list[i].return_enrollno() <<endl;
        cout <<endl;

        cout <<"For Teacher : " <<endl;
        cout <<"Name " <<"\t\t" <<"Faculty Abbreviations" <<"\t\t" <<"Subject";
        for(int i=0 ; i < n_teacher ; ++i)
            cout <<teacher_list[i].return_name() <<"\t\t" <<teacher_list[i].return_faculy_abbreviation() <<"\t\t" <<teacher_list[i].return_subject() <<endl;
        cout <<endl;
    }

    void show_studentlist()
    {
        cout <<"Name " <<"\t\t" <<"Enrollment Number" <<endl;
        for(int i=0 ; i < n_student ; ++i)
            cout <<student_list[i].return_name() <<"\t\t" <<student_list[i].return_enrollno() <<endl;
        cout <<endl;
    }

    void show_teacherlist()
    {
        cout <<"Name " <<"\t\t" <<"Faculty Abbreviations" <<"\t\t" <<"Subject" <<endl;
        for(int i=0 ; i < n_teacher ; ++i)
            cout <<teacher_list[i].return_name() <<"\t\t" <<teacher_list[i].return_faculy_abbreviation() <<"\t\t\t" <<teacher_list[i].return_subject() <<endl;
        cout <<endl;
    }

    void update_student_batch(batch *b)
    {
        for(int i=0 ; i < n_student ; ++i)
        {
            student_list[i].get_batch(b);
            all_student_list[n_all_students - n_student + i].get_batch(b);
        }
    }

    void update_teacher_batch(batch *b)
    {
        for(int i=0 ; i < n_teacher ; ++i)
        {
            teacher_list[i].get_batch(b);
            all_teacher_list[n_all_teachers - n_teacher + i].get_batch(b);
        }
    }

    void update_student_marks(string str)
    {
        for(int i=0 ; i < n_student ; ++i)
        {
            float x;
            fflush(stdin);
            cout <<student_list[i].return_name() <<" : " ;
            cin >>x;
            student_list[i].get_marks(x, str);
            all_student_list[n_all_students - n_student + i].get_marks(x, str);
        }
    }

    void update_student_grades(string str)
    {
        for(int i=0 ; i < n_student ; ++i)
        {
            string ch;
            fflush(stdin);
            cout <<student_list[i].return_name() <<" : ";
            getline(cin, ch);
            student_list[i].get_grades(ch, str);
            all_student_list[n_all_students - n_student + i].get_grades(ch, str);
        }
    }

    string return_name()
    {
        return batch_name;
    }
}all_batch_list[100];

class admin{
protected:
    int n_batch;
    string admin_name;
    batch b[10];
public:
    void getdata()
    {
        fflush(stdin);
        cout <<"Name : ";
        getline(cin, admin_name);

        fflush(stdin);
        cout <<"Number of batches under the admin : ";
        cin >>n_batch;

        fflush(stdin);
        cout <<"Enter the details of batches : " <<endl;
        for(int i=0 ; i < n_batch ; ++i)
        {
            cout <<"For Batch " <<i+1 <<endl;
            b[i].getdata();
            all_batch_list[n_all_batches+i] = b[i];
            b[i].update_student_batch(&all_batch_list[n_all_batches+i]);
            b[i].update_teacher_batch(&all_batch_list[n_all_batches+i]);
            cout <<endl;
        }
        n_all_batches += n_batch;
    }

    void putdata()
    {
        cout <<"The admin " <<admin_name <<" has following batches under him/her : " <<endl;
        for(int i=0 ; i < n_batch ; ++i)
            cout <<b[i].return_name() <<endl;
        cout <<endl;
    }
};

    ///MEMBER FUCTIONS
///CLASS - TEACHER
void teacher::get_batch(batch *b)
{
    B = b;
}
void teacher::show_students()
{
    cout <<"The teacher " <<teacher_name <<" has following students with him/her : " <<endl;
    B->show_studentlist();
}
void teacher::enter_marks()
{
    cout <<"Enter the marks of " <<subject <<" : " <<endl;
    cout <<"Batch : " <<B->return_name() <<endl;
    B->update_student_marks(subject);
}
void teacher::enter_grades()
{
    cout <<"Enter the marks of " <<subject <<" : " <<endl;
    cout <<"Batch : " <<B->return_name() <<endl;
    B->update_student_grades(subject);
}

///CLASS - STUDENT
void student::get_batch(batch *b)
{
    B = b;
}
void student::show_teacher()
{
    cout <<"The student " <<student_name <<" has following teachers : " <<endl;
    B->show_teacherlist();
}

    ///MAIN
int main()
{
    char choice;
    admin A;
A:
    system("Color D6");

    system("cls");
    cout <<"------------------------WELCOME TO WEBKIOSK-------------------------------"<<endl <<endl;
    cout <<"Enter Member Type : " <<endl
         <<"1. Student  " <<endl
         <<"2. Teacher " <<endl
         <<"3. Administrator  " <<endl
         <<"4. Exit ... ";
    fflush(stdin);
    choice = getche();
    cout <<endl;

    if(choice == '1')
    {system("Color B6");
        int login_enroll_no;
        student s;
        s.get_enrollno(-1);
        system("cls");
        cout <<"Enter your Enrollment Number : ";
        cin >>login_enroll_no;

        for(int i=0 ; i < n_all_students ; ++i)
            if(login_enroll_no == all_student_list[i].return_enrollno())
                s = all_student_list[i];

        if(s.return_enrollno() == -1)
        {
            cout <<"No Such Enrollment Number is in the data !!!" <<endl
                 <<"Returning to Main Menu";
            delay(1);
            goto A;
        }

        system("cls");
        cout <<"Welcome, " <<s.return_name() <<endl <<endl;
        cout <<"Enter : " <<endl
             <<"1. Personal Details " <<endl
             <<"2. Fees Status " <<endl
             <<"3. View Marks " <<endl
             <<"4. View Grades " <<endl
             <<"5. See Teacher List " <<endl
             <<"6. Go to Main Menu " <<endl
             <<"7. Exit ... ";
        fflush(stdin);
        choice = getche();
        cout <<"\n\n";

        if(choice == '1')
            s.putdata();
        else if(choice == '2')
        {
            char ch = s.return_fees_submitted();
            if((ch == 'Y') || (ch == 'y'))
                cout <<"The Student has submitted his fees";
            else
                cout <<"The Student has NOT submitted his fees";
        }
        else if(choice == '3')
            s.show_marks();
        else if(choice == '4')
            s.show_grades();
        else if(choice == '5')
            s.show_teacher();
        else if(choice == '6')
            goto A;
        else if(choice == '7')
            return 0;
        else
        {
            Wrong_Choice_Entered();
            goto A;
        }

        cout <<"\nEnter : " <<endl
             <<"1. Go to Main Menu " <<endl
             <<"2. Exit ... ";
        fflush(stdin);
        choice = getche();

        if(choice == '1')
            goto A;
        else if(choice == '2')
            return 0;
        else
        {
            Wrong_Choice_Entered();
            goto A;
        }
    }
    else if(choice == '2')
    {system("Color B6");
        system("cls");
        teacher t;
        t.get_faculy_abbreviation("-1");
        string fa;
        fflush(stdin);
        cout <<"Enter Faculty Abbreviation : ";
        getline(cin, fa);

        for(int i=0 ; i < n_all_teachers ; ++i)
        {
            if(fa == all_teacher_list[i].return_faculy_abbreviation())
                t = all_teacher_list[i];
        }

        if(t.return_faculy_abbreviation() == "-1")
        {
            cout <<"No Such Faculty Abbreviation is in the data !!!" <<endl
                 <<"Returning to Main Menu";
            delay(1);
            goto A;
        }

        system("cls");
        cout <<"Welcome, " <<t.return_name() <<"\n\n";
        cout <<"Enter : " <<endl
             <<"1. Personal Details " <<endl
             <<"2. Salary Details " <<endl
             <<"3. Upload Marks " <<endl
             <<"4. Upload Grades " <<endl
             <<"5. Student List" <<endl
             <<"6. Go to Main Menu " <<endl
             <<"7. Exit ... ";
        fflush(stdin);
        choice = getche();
        cout <<"\n\n";

        if(choice == '1')
        {
            t.putdata();
        }
        else if(choice == '2')
        {
            t.salary_details();
        }
        else if(choice == '3')
        {
            t.enter_marks();
        }
        else if(choice == '4')
        {
            t.enter_grades();
        }
        else if(choice == '5')
        {
            t.show_students();
        }
        else if(choice == '6')
            goto A;
        else if(choice == '7')
            return 0;
        else
        {
            Wrong_Choice_Entered();
            goto A;
        }

        cout <<"\nEnter : " <<endl
             <<"1. Go to Main Menu " <<endl
             <<"2. Exit ... ";
        fflush(stdin);
        choice = getche();

        if(choice == '1')
            goto A;
        else if(choice == '2')
            return 0;
        else
        {
            Wrong_Choice_Entered();
            goto A;
        }
    }
    else if(choice == '3')
    {system("Color B6");
        system("cls");
        cout <<"Enter : " <<endl
             <<"1. To enter details of a batch : " <<endl
             <<"2. List of all Students  " <<endl
             <<"3. List of all Teachers ... ";
        fflush(stdin);
        choice = getche();
        cout <<endl <<endl;

        if(choice == '1')
        {
            cout <<"Enter the details of the Administrator : " <<endl;
            A.getdata();

            cout <<"\nThe details have been updated.";

            delay(1);

            goto A;
        }
        else if(choice == '2')
        {
            if(n_all_students == 0)
            {
                cout <<"No student data present !!!" <<endl
                     <<"Returning to Main Menu";

                delay(1);
                goto A;
            }
            for(int i=0 ; i < n_all_students ; ++i)
                all_student_list[i].putdata();

            cout <<"\nEnter : " <<endl
                 <<"1. Go to Main Menu " <<endl
                 <<"2. Exit ... ";
            fflush(stdin);
            choice = getche();

            if(choice == '1')
                goto A;
            else if(choice == '2')
                return 0;
            else
            {
                Wrong_Choice_Entered();
                goto A;
            }
        }
        else if(choice == '3')
        {
            if(n_all_teachers == 0)
            {
                cout <<"No Teacher Data present !!!" <<endl
                     <<"Returning to Main Menu";
                delay(1);
                goto A;
            }
            for(int i=0 ; i < n_all_teachers ; ++i)
                all_teacher_list[i].putdata();

            cout <<"\nEnter : " <<endl
                 <<"1. Go to Main Menu " <<endl
                 <<"2. Exit ... ";
            fflush(stdin);
            choice = getche();

            if(choice == '1')
                goto A;
            else if(choice == 2)
                return 0;
            else
            {
                Wrong_Choice_Entered();
                goto A;
            }
        }
        else
        {
            cerr <<"ERROR!!! Invalid Input" <<endl
                 <<"Returning to Main Menu";
            delay(1);
            goto A;
        }
    }
    else if(choice == '4')
    {
        return 0;
    }
    else
    {
        Wrong_Choice_Entered();
        goto A;
    }
    return 0;
}

    ///FUNTION DEFINITIONS
int ctn(char ch1)
{
int x=0;

if(ch1=='1')
    x=1;
else if(ch1=='2')
    x=2;
else if(ch1=='3')
    x=3;
else if(ch1=='4')
    x=4;
else if(ch1=='5')
    x=5;
else if(ch1=='6')
    x=6;
else if(ch1=='7')
    x=7;
else if(ch1=='8')
    x=8;
else if(ch1=='9')
    x=9;
return x;
}

void delay (int delay)
{
    int now = time(NULL);
    int later = now + delay ;
    while(now<=later)now = time(NULL);
}

void Wrong_Choice_Entered()
{
    system("cls");
    cerr <<"ERROR!!! Invalid Input" <<endl
         <<"Returning to Main Menu";
    delay(1);
}
