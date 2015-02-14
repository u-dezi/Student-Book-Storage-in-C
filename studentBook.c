#include<string.h>
#include<stdio.h>
#include<windows.h>

// Structure of books and students, all its variables
struct book
{
    char bname[15];
    int b_id;
    //struct book ;/*pointer to the book*/
}; struct book bk[100],temp_b; // variable for book // 2nd to be a structure for copying, only for book type

struct student
{
    char sname[20];
    int s_id;
    int slevel;
}; struct student sk[100],temp_s; // variable for student //// 2nd to be a structure for copying, only for student type




//Variables for selection
int choice1;// For Main menu
int choice2;// For Sub Menus
int choice3;// Fpr Bub sub Menu
int option;
int id;     // For testing in delete
int choose; // For testing in delete
int x;      // For testing in delete true or false test using integers

//Variables for Creating and keeping count of the number of books and students
int b_create = 0;           // counter for the book create function, used to increment for next call
int s_create = 0;           // counter for the book create function, used to increment for next call
int flag_book_no = -1;       // Used to show the number of books entered
int flag_student_no = -1;    // used to show the number of students entered
void clr()
{
    system("cls");
}
slp()
{
   Sleep(2000);
}
void main_menu();

int create();
    int create_book();
    int create_student();
    int create_options();

int display();
    int display_book();
       // int display_book_id();
       // int display_book_name();
    int display_student();
       // int display_student_id();
       // int display_student_name();

int del();
    int del_book();
        int del_book_id();
            int del_book_id_act(int);
        int del_book_name();
            // int del_book_name_act(char[]); //defined
    int del_student();
        int del_student_id();
            int del_student_id_act(int);
        int del_student_name();
            // int del_student_name_act(char[]); //defined

int look();
    int look_book();
        int look_book_id();
        int look_book_name();
    int look_student();
        int look_student_id();
        int look_student_name();

int close();

void main_menu()/*function*/
{
    printf("\t\t**********Productions**************\n\n");
    printf("\tMAIN MENU \n");
    printf("1.\tCreate book or Student\n");
    printf("2.\tDisplay book or Student\n");
    printf("3.\tDelete book or Student\n");
    printf("4.\tSearch book or Student\n");
    printf("5.\tExit\n\n");

    printf("/Enter a number from the menu :/\n");
    scanf("%d",&choice1);
    if(choice1 == 1)
    {
        create();
    }
    else if(choice1 == 2)
    {
        display();
    }
    else if(choice1 == 3)
    {
        del();
    }
    else if(choice1 == 4)
    {
        look();
    }
    else if(choice1 == 5)
    {
        close();
    }
    else
    {
        clr();
        printf("The number you entered doesn't exist try again \n\n");
        slp();
        main_menu();

    }

}
int create()/*function*/
{
    clr();
	printf("\tCREATE \n");
	printf("1. Create Book    \n");
	printf("2. Create Student \n");
	printf("3. Main Menu ");
	printf("\n\n/Enter a number from the menu :/");
	scanf("%d",&choice2);
    if(choice2 == 1)//THis goes to create _book
    {
        create_book();

    }
    else if(choice2 == 2)
    {
        create_student();

    }
    else if(choice2 == 3)
    {
        clr();
        main_menu();

    }
    else
    {

        printf("The number you entered doesn't exist try again \n\n");
        slp();
        clr();
        create();
    }
}
create_book()/*function*/
{
    clr();

     printf("Enter Book Name: \n");
        scanf("%s",bk[b_create].bname);
    printf("Enter Book ID: \n");
        scanf("%d",&bk[b_create].b_id);
    b_create++;
    flag_book_no++;

    printf("\nBook Created\n");
    slp();
    create_options();

}
create_student()/*function*/
{
    clr();

    printf("Enter Student Name: \n");
        scanf("%s",sk[s_create].sname);
    printf("Student Id Number: \n");
        scanf("%d",&sk[s_create].s_id);
    printf("Enter Student Level: \n");
        scanf("%d",&sk[s_create].slevel);
    s_create++;
    flag_student_no++;

    printf(" Student Created \n");
    slp();
    create_options();
}
create_options()/*function*/
{
    clr();
    printf("\n1.Create another Book\n");
    printf("2.Create another Student\n");
    printf("3.Go to Create Menu\n");
    printf("4.Go to Main Menu\n");

    printf("/Enter a number from the menu :/\n");
    scanf("%d",&option);

    if(option == 1)
    {
        create_book();
    }
    else if(option == 2)
    {
        create_student();
    }
    else if(option == 3)
    {
        create();
    }
    else if(option == 4)
    {
        clr();
        main_menu();
    }
    else
    {
        clr();
        printf("The number you entered doesn't exist try again \n\n");
        slp();
        create_options();

    }

}
int display()/*function*/
{
    clr();
	printf("\tDISPLAY \n");
	printf("1. Display Book    \n");
	printf("2. Display Student \n");
	printf("3. Main Menu ");
	printf("\n\n/Enter a number from the menu :/");
	scanf("%d",&choice2);
    if(choice2 == 1)//THis goes to create _book
    {
        display_book();

    }
    else if(choice2 == 2)
    {
        display_student();

    }
    else if(choice2 == 3)
    {
        clr();
        main_menu();

    }
    else
    {

        printf("The number you entered doesn't exist try again \n\n");
        slp();
        display();
    }
}
display_book()/*function*/
{
    clr();

   printf("\t \tLIST OF BOOKS \n\n");
    printf("\tName \t\t Id \n\n");
    int i = 0;
    while(i <= flag_book_no)
    {
    printf("\4   %10s %15d\n",bk[i].bname,bk[i].b_id );
    i++;
    }

    slp();
    display_options();

}
display_student()/*function*/
{
    clr();

   printf("\t \tLIST OF STUDENTS \n\n");
     printf("\tName \t\t Id \t\tLevel \n\n");
    int i = 0;// used to increment for printing the values
    while(i <= flag_student_no)
    {
    printf("\4   %10s %15d  %13d \n",sk[i].sname,sk[i].s_id, sk[i].slevel);
    i++;
    }

    slp();
    display_options();
}
display_options()/*function*/
{

    printf("\n1.Display  Book \n");
    printf("2.Display  Student\n");
    printf("3.Go to Main Menu\n");

    printf("/Enter a number from the menu :/\n");
    scanf("%d",&option);
    clr();
    if(option == 1)
    {
        display_book();
    }
    else if(option == 2)
    {
        display_student();
    }
    else if(option == 3)
    {
        clr();
        main_menu();
    }
    else
    {
        clr();
        printf("The number you entered doesn't exist try again \n\n");
        slp();
        display_options();

    }

}


 del()/*function*/
{
    clr();
	printf("\tDELETE \n");
	printf("1. Delete Book    \n");
	printf("2. Delete Student \n");
	printf("3. Main Menu ");
	printf("\n\n/Enter a number from the menu :/");
	scanf("%d",&choice2);
    if(choice2 == 1)//THis goes to create _book
    {
        del_book();

    }
    else if(choice2 == 2)
    {
        del_student();

    }
    else if(choice2 == 3)
    {
        clr();
        main_menu();

    }
    else
    {

        printf("The number you entered doesn't exist try again \n\n");
        slp();
        clr();
        del();
    }
}
del_book()/*function*/
{
    clr();
    printf("\tDELETE BOOK MENU \n");
	printf("1. Delete by ID \"Book\"  \n");
	printf("2. Delete by NAME \"Book\" \n");
	printf("3. Delete Menu\n");
	printf("4. Main Menu ");
	printf("\n\n/Enter a number from the menu :/");
	scanf("%d",&choice3);

	 if(choice3 == 1)//THis goes to create _book
    {
        del_book_id();

    }
    else if(choice3 == 2)
    {
        del_book_name();
    }
    else if(choice3 == 3)
    {
        clr();
        del();

    }
    else if(choice3 ==4)
    {
        clr();
        main_menu();
    }
    else
    {

        printf("The number you entered doesn't exist try again \n\n");
        slp();
        clr();
        del();
    }

}
del_student()/*function*/
{
    clr();
    printf("\t DELETE STUDENT MENU \n");
	printf("1. Delete by ID \"Student\"  \n");
	printf("2. Delete by NAME \"Student\" \n");
	printf("3. Delete Menu \n");
	printf("4. Main Menu ");
	printf("\n\n/Enter a number from the menu :/");
	scanf("%d",&choice3);

	 if(choice3 == 1)//THis goes to create _book
    {
        del_student_id();
    }
    else if(choice3 == 2)
    {
        del_student_name();
    }
    else if(choice3 == 3)
    {
        clr();
        del();

    }
    else if(choice3 ==4)
    {
        clr();
        main_menu();
    }
    else
    {

        printf("The number you entered doesn't exist try again \n\n");
        slp();
        clr();
        del();
    }
}

del_student_id()/*Function*/
{
    int id;
    printf("\n Enter an ID to delete book \n");
    scanf("%d",&id);
    printf("\n\n");

    int i;
    i = 0;
    int flag_found = 0;   // This shows that the document has been found. If not found it remains 0
    int flag_found_no = 0;// used to know the total number of entries to be deleted

    printf("\tName \t\t Id \t\tLevel \n\n");
     for(i=0; i <= flag_student_no; i++)
    {
        if(id == sk[i].s_id)
        {
            flag_found = 1;
            flag_found_no++;
            printf("\4   %10s %15d  %13d \n",sk[i].sname,sk[i].s_id, sk[i].slevel);
        }
    }

    if(flag_found == 1)// delete exists
    {
        printf("\n %d record or records found",flag_found_no);
        printf("\n Do you want to delete enter 1 for y and 2 for No :   ");
        scanf("%d",&x);

        if(x == 1)
        {
            del_student_id_act(id);

            printf("\n Document Deleted \n");
            slp();
            clr();
            del_student();
        }
        else
        {
                slp();
                clr();
                del_student();
        }
    }
    else
    {
         printf("The id number you entered doesn't exist try again \n\n");
         slp();
         clr();
         del_student();
    }
}

del_student_id_act(id)
{
    int item_index = 0;     //Used to know the actual index of the record to be deleted
    int i = 0;
    for(i; i<=flag_student_no; i++)
    {
        if(id == sk[i].s_id) // to match the delete option
            {
                item_index = i;     // stores the current id to be deleted
                sk[i].s_id ='null';     // the deleting of the student id
                sk[i].slevel ='null';     // the deleting of the student level
                int t = 0;

                for(t =0;t<=14;t++)     // to delete all array spaces for student name
                {
                    sk[i].sname[t] ='\0';  // the deleting of the student name
                }
                int j;

               // j=item_index;
                for(j=item_index; j <= flag_student_no; j++) // Code to swipe and rearrange after deleting, flag
                                                                   // is ok b/c it starts at -1, so 1st record be 0
                {
                    temp_s       = sk[j];
                    sk[j]      = sk[j + 1];
                    sk[j + 1]  = temp_s;
                }
                --flag_student_no;
                s_create = flag_student_no + 1; // so that it goes to next and doesnt override
                i--; // This is so that it can repeat a delete operation for multiple records with same id, it will reinitialize i
                     // back to a previous to delete search again
            }
    }

}
del_student_name()/*Function*/
{
    char src[20];
    printf("\n Enter a name to delete student: \t");
    scanf("%s",src);
    printf("\n\n");

    int i;
    i = 0;
    int flag_found = 0;   // This shows that the document has been found. If not found it remains 0
    int flag_found_no = 0;// used to know the total number of entries to be deleted

    printf("\tName \t\t Id \t\tLevel \n\n");
     for(i=0; i <= flag_student_no; i++)
    {
        if((strcmp(src,sk[i].sname)) == 0)
        {
            flag_found = 1;
            flag_found_no++;
            printf("\4   %10s %15d  %13d \n",sk[i].sname,sk[i].s_id, sk[i].slevel);
        }
    }

    if(flag_found == 1)// delete exists
    {
        printf("\n %d record or records found",flag_found_no);
        printf("\n Do you want to delete enter 1 for y and 2 for No :   ");
        scanf("%d",&x);

        if(x == 1)
        {
            del_student_name_act(src);

            printf("\n Document Deleted \n");
            slp();
            clr();
            del_student();
        }
        else
        {
                slp();
                clr();
                del_student();
        }
    }
    else
    {
         printf("The id number you entered doesn't exist try again \n\n");
         slp();
         clr();
         del_student();
    }
}

del_student_name_act(src)
{
    int item_index = 0;     //Used to know the actual index of the record to be deleted
    int i = 0;
    for(i; i<=flag_student_no; i++)
    {
        if((strcmp(src,sk[i].sname)) == 0) // to match the delete option
            {
                item_index = i;     // stores the current id to be deleted
                sk[i].s_id ='null';     // the deleting of the student id
                sk[i].slevel ='null';     // the deleting of the student level
                int t = 0;

                for(t =0;t<=14;t++)     // to delete all array spaces for student name
                {
                    sk[i].sname[t] ='\0';  // the deleting of the student name
                }
                int j;

               // j=item_index;
                for(j=item_index; j <= flag_student_no; j++) // Code to swipe and rearrange after deleting, flag
                                                                   // is ok b/c it starts at -1, so 1st record be 0
                {
                    temp_s       = sk[j];
                    sk[j]      = sk[j + 1];
                    sk[j + 1]  = temp_s;
                }
                --flag_student_no;
                s_create = flag_student_no + 1; // so that it goes to next and doesnt override
                i--; // This is so that it can repeat a delete operation for multiple records with same id, it will reinitialize i
                     // back to a previous to delete search again
            }
    }

}
del_book_id()/*Function*/
{
    int id;
    printf("\n Enter an ID to delete book \n");
    scanf("%d",&id);
    printf("\n\n");

    int i;
    i = 0;
    int flag_found = 0;   // This shows that the document has been found. If not found it remains 0
    int flag_found_no = 0;// used to know the total number of entries to be deleted

    printf("\tName \t\t Id \n\n");
     for(i=0; i <= flag_book_no; i++)
    {
        if(id == bk[i].b_id)
        {
            flag_found = 1;
            flag_found_no++;
            printf("\4   %10s %15d\n",bk[i].bname,bk[i].b_id );
        }
    }

    if(flag_found == 1)// delete exists
    {
        printf("\n %d record or records found",flag_found_no);
        printf("\n Do you want to delete enter 1 for y and 2 for No :   ");
        scanf("%d",&x);

        if(x == 1)
        {
            del_book_id_act(id);

            printf("\n Document Deleted \n");
            slp();
            clr();
            del_book();
        }
        else
        {
                slp();
                clr();
                del_book();
        }
    }
    else
    {
         printf("The id number you entered doesn't exist try again \n\n");
         slp();
         clr();
         del_book();
    }
}

del_book_id_act(id)
{
    int item_index = 0;     //Used to know the actual index of the record to be deleted
    int i = 0;
    for(i; i<=flag_book_no; i++)
    {
        if(id == bk[i].b_id) // to match the delete option
            {
                item_index = i;     // stores the current id to be deleted
                bk[i].b_id ='null';     // the deleting of the book id
                int t = 0;

                for(t =0;t<=14;t++)     // to delete all array spaces
                {
                    bk[i].bname[t] ='\0';  // the deleting of the book name
                }
                int j;

               // j=item_index;
                for(j=item_index; j <= flag_book_no; j++) // Code to swipe and rearrange after deleting, flag
                                                                   // is ok b/c it starts at -1, so 1st record be 0
                {
                    temp_b       = bk[j];
                    bk[j]      = bk[j + 1];
                    bk[j + 1]  = temp_b;
                }
                --flag_book_no;
                b_create = flag_book_no + 1; // so that it goes to next and doesnt override
                i--; // This is so that it can repeat a delete operation for multiple records with same id, it will reinitialize i
                     // back to a previous to delete search again
            }
    }

}
del_book_name()/*Function*/
{
    char src[20];
    printf("\n Enter a name to delete book: \t");
    scanf("%s",src);
    printf("\n\n");

    int i;
    i = 0;
    int flag_found = 0;   // This shows that the document has been found. If not found it remains 0
    int flag_found_no = 0;// used to know the total number of entries to be deleted

    printf("\tName \t\t Id \n\n");
     for(i=0; i <= flag_book_no; i++)
    {
        if((strcmp(src,bk[i].bname)) == 0)
        {
            flag_found = 1;
            flag_found_no++;
            printf("\4   %10s %15d\n",bk[i].bname,bk[i].b_id );
        }
    }

    if(flag_found == 1)// delete exists
    {
        printf("\n %d record or records found",flag_found_no);
        printf("\n Do you want to delete enter 1 for y and 2 for No :   ");
        scanf("%d",&x);

        if(x == 1)
        {
            del_book_name_act(src);

            printf("\n Document Deleted \n");
            slp();
            clr();
            del_book();
        }
        else
        {
                slp();
                clr();
                del_book();
        }
    }
    else
    {
         printf("The id number you entered doesn't exist try again \n\n");
         slp();
         clr();
         del_book();
    }
}

del_book_name_act(src)
{
    int item_index = 0;     //Used to know the actual index of the record to be deleted
    int i = 0;
    for(i; i<=flag_book_no; i++)
    {
        if((strcmp(src,bk[i].bname)) == 0) // to match the delete option
            {
                item_index = i;     // stores the current id to be deleted
                bk[i].b_id ='null';     // the deleting of the book id
                int t = 0;

                for(t =0;t<=14;t++)     // to delete all array spaces
                {
                    bk[i].bname[t] ='\0';  // the deleting of the book name
                }
                int j;

               // j=item_index;
                for(j=item_index; j <= flag_book_no; j++) // Code to swipe and rearrange after deleting, flag
                                                                   // is ok b/c it starts at -1, so 1st record be 0
                {
                    temp_b       = bk[j];
                    bk[j]      = bk[j + 1];
                    bk[j + 1]  = temp_b;
                }
                --flag_book_no;
                b_create = flag_book_no + 1; // so that it goes to next and doesnt override
                i--; // This is so that it can repeat a delete operation for multiple records with same id, it will reinitialize i
                     // back to a previous to delete search again
            }
    }

}


look()/*function*/
{
    clr();
	printf("\t SEARCH \n");
	printf("1. Search Book    \n");
	printf("2. Search Student \n");
	printf("3. Main Menu ");
	printf("\n\n/Enter a number from the menu :/");
	scanf("%d",&choice2);
    if(choice2 == 1)//THis goes to create _book
    {
        look_book();
        clr();

    }
    else if(choice2 == 2)
    {
        look_student();
        clr();

    }
    else if(choice2 == 3)
    {
        clr();
        main_menu();

    }
    else
    {

        printf("The number you entered doesn't exist try again \n\n");
        slp();
        clr();
        look();
    }
}
look_book()/*function*/
{
    clr();
    printf("\tSEARCH BOOK MENU \n");
	printf("1. Search by ID \"Book\"  \n");
	printf("2. Search by NAME \"Book\" \n");
	printf("3. Search Menu\n");
	printf("4. Main Menu ");
	printf("\n\n/Enter a number from the menu :/");
	scanf("%d",&choice3);

	 if(choice3 == 1)//THis goes to create _book
    {
        look_book_id();

    }
    else if(choice3 == 2)
    {
        look_book_name();
    }
    else if(choice3 == 3)
    {
        clr();
        look();

    }
    else if(choice3 ==4)
    {
        clr();
        main_menu();
    }
    else
    {

        printf("The number you entered doesn't exist try again \n\n");
        slp();
        clr();
        look();
    }

}
look_student()/*function*/
{
    clr();
    printf("\t SEARCH STUDENT MENU \n");
	printf("1. Search by ID \"Student\"  \n");
	printf("2. Search by NAME \"Student\" \n");
	printf("3. Search Menu \n");
	printf("4. Main Menu ");
	printf("\n\n/Enter a number from the menu :/");
	scanf("%d",&choice3);

	 if(choice3 == 1)//THis goes to create _book
    {
        look_student_id();
    }
    else if(choice3 == 2)
    {
        look_student_name();
    }
    else if(choice3 == 3)
    {
        clr();
        look();

    }
    else if(choice3 ==4)
    {
        clr();
        main_menu();
    }
    else
    {

        printf("The number you entered doesn't exist try again \n\n");
        slp();
        clr();
        look();
    }
}

look_student_id()/*Function*/
{
   // printf("WOrking");
    int id;
    printf("\n Enter an ID to search for Student \n");
    scanf("%d",&id);
    printf("\n\t\t*****STUDENTS*****");
    printf("\n");
    printf("\tName \t\t Id \t\tLevel \n\n");

    int i;
    int flag_found = 0;

     for(i =0; i <= flag_student_no; i++)
    {
        if(sk[i].s_id == id)
        {
            flag_found = 1; // This shows that the document has been found. If not found it remains 0
            printf("\4   %10s %15d  %13d \n",sk[i].sname,sk[i].s_id, sk[i].slevel);
        }


    }

      if(flag_found == 1)// exists
        {
            printf("\n Document Found \n");
            printf("\n Enter any number and press Enter to clear and continue \n");
            scanf("%d",&x);
            if(x == 1 || x != 1)
            {
                slp();
                look_student();
            }
        }

      if(flag_found == 0)
        {
         printf("The id number you entered doesn't exist try again \n\n");
         slp();
         clr();
         look_student();
        }
}

look_student_name()
{
    int id;
    char src[20];
    printf("\n Please enter the First name to search for Student: \t");
    scanf("%s",src);
    printf("\n\t\t*****STUDENTS*****");
    printf("\n");
    printf("\tName \t\t Id \t\tLevel \n\n");

    int i;
    i = 0;
    int flag_found = 0;

     for(i =0; i <= flag_student_no; i++)
    {
        if((strcmp(src,sk[i].sname)) == 0)
        {
            flag_found = 1; // This shows that the document has been found. If not found it remains 0
            printf("\4   %10s %15d  %13d \n",sk[i].sname,sk[i].s_id, sk[i].slevel);
        }

    }

        if(flag_found == 1)// exists
        {
            printf("\n Enter any number and press Enter to clear and continue \n");
            scanf("%d",&x);
            if(x == 1 || x != 1)
            {
                slp();
                look_student();
            }
        }

    if(flag_found == 0)
    {
         printf("The name you entered doesn't exist try again \n\n");
         slp();
         clr();
         look_student();
    }
}

look_book_id()/*Function*/
{

    int id;
    printf("\n Enter an ID to search for book \n");
    scanf("%d",&id);
    printf("\n\t\t*****BOOKS*****");
    printf("\n");
    printf("\tName \t\t Id \n\n");

    int i;
    i = 0;
    int flag_found = 0;

     for(i =0; i <= flag_book_no; i++)
    {
        if(id == bk[i].b_id)
        {
            flag_found = 1; // This shows that the document has been found. If not found it remains 0
            printf("\4   %10s %15d\n",bk[i].bname,bk[i].b_id );
        }


    }

      if(flag_found == 1)// exists
        {
            printf("\n Document Found \n");
            printf("\n Enter any number and press Enter to clear and continue  \n");
            scanf("%d",&x);
            if(x == 1 || x != 1)
            {
                slp();
                look_book();
            }
        }

      if(flag_found == 0)
        {
         printf("The id number you entered doesn't exist try again \n\n");
         slp();
         clr();
         look_book();
        }
}

look_book_name()/*Function*/
{

    int id;
    char src[20];
    printf("\n Enter a name to search for book: \t");
    scanf("%s",src);
    printf("\n\t\t*****BOOKS*****");
    printf("\n");
    printf("\tName \t\t Id \n\n");

    int i;
    i = 0;
    int flag_found = 0;

     for(i =0; i <= flag_book_no; i++)
    {
        if((strcmp(src,bk[i].bname)) == 0)
        {
            flag_found = 1; // This shows that the document has been found. If not found it remains 0
            printf("\4   %10s %15d\n",bk[i].bname,bk[i].b_id );
        }

    }

    if(flag_found == 1)// exists
    {
            printf("\n Document Found \n");
            printf("\n Enter any number and press Enter to clear and continue  \n");
            scanf("%d",&x);
            if(x == 1 || x != 1)
            {
                slp();
                look_book();
            }
    }
    if(flag_found == 0)
    {
         printf("The name you entered doesn't exist try again \n\n");
         slp();
         clr();
         look_book();
    }
}
int close()
{
    return 0;
}


int main()
{
    main_menu();

}
