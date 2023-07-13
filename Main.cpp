#include <iostream>
#include <fstream>
using namespace std;

int len = 10;

struct books
{
string name,author;
int price,year;
};

struct person
{
string first_name,last_name,address,book_name,author_name;
int bill,year,price;
person *next;

person()
    {
     this->next = NULL;
    }
};

//@User Functions

void welcome_user()
    {
    cout<<"========================================================================================"<<endl; 
    cout<<"\n\t\t\t\t      ---|HELLO!!!|---\n      \t\t\t---|Welcome to Reader to Leader Bookstore|---\n"<<endl;  
    cout<<"---|Press 1 if you are a User|---\n\t\n\t---|Press 2 if you want Admin Access|---\n\n\t\t---|Press 0 to Exit|---"<<endl; 
    cout<<"========================================================================================"<<endl; 
    // cout<<"=========================================================="<<endl; 
    }

void create_books(books stock[])  
    {
    stock[0].name = "Rich Dad Poor Dad";
     stock[0].author = "Robert T.Kiyosaki";
     stock[0].price = 300;
     stock[0].year = 1997;
    
    stock[1].name = "Forty rules of Love";
     stock[1].author = "Elif Shafak";
     stock[1].price = 350;
     stock[1].year = 2009;

    stock[2].name = "Silent Patient";
     stock[2].author = "Alex Michaelides";
     stock[2].price = 250;
     stock[2].year = 2009;

    stock[3].name = "Alchemist";
     stock[3].author = "Paulo Coelho";
     stock[3].price = 300;
     stock[3].year = 1988;
    
    stock[4].name = "Romi's Daughter";
     stock[4].author = "Muriel Maufroy";
     stock[4].price = 250;
     stock[4].year = 2004;
    
    stock[5].name = "Honor";
     stock[5].author = "Elif Shafak";
     stock[5].price = 250;
     stock[5].year = 2011;

    stock[6].name = "80 Minute MBA";
     stock[6].author = "John Knell";
     stock[6].price = 200;
     stock[6].year = 2009;

    stock[7].name = "Sapiens";
     stock[7].author = "Yuval Noah Harari";
     stock[7].price = 300;
     stock[7].year = 2014;

    stock[8].name = "Homo Deus";
     stock[8].author = "Yuval Noah";
     stock[8].price = 250;
     stock[8].year = 2018;

    stock[9].name = "Why Nations Fail";
     stock[9].author = "Daron Acemoglu";
     stock[9].price = 350;
     stock[9].year = 2012;

    }

int show_books(books stock[] , int len) 
    {
    int i;
    for(i=0 ; i<len ; i+=2)
        {
        cout<<"\n\t---|Book "<<i+1<<"|---\t\t\t\t\t---|Book "<<i+2<<"|---\n"<<endl;
        cout<<"Book Name : "<<stock[i].name<<"\t\t\tBook Name : "<<stock[i+1].name<<endl;
        cout<<"Author Name : "<<stock[i].author<<"\t\t\tAuthor Name : "<<stock[i+1].author<<endl;
        cout<<"Price : "<<stock[i].price<<"\t\t\t\t\tPrice : "<<stock[i+1].price<<endl;
        cout<<"Year of Publication : "<<stock[i].year<<"\t\t\tYear of Publication : "<<stock[i+1].year<<endl;
        }
    re:
    cout<<"\n\n\tPress 0 if you want to return to Menu\n\n\t\t\tOR\n\n   Enter the Book  Number you want to choose : ";
     cin >> i;
        if(i <0 || i>len)
            {
             cout<<"\n\tPlease Enter the Right Choice : "<<endl;
             goto re;
            }
    return (i-1);
    }

void show_bill(person *head)
    {
    ofstream order("Orders.csv" , ios::app);
    system ("cls");
    person *temp = new person;
     temp = head;
    cout<<"========================================================================================"<<endl; 
     cout<<"\n\tYour Bill is shown as Below\n"<<endl;
     cout<<"Name : "<<temp->first_name<<" "<<temp->last_name<<endl;
     cout<<"Adress : "<<temp->address<<endl;
     cout<<"Book Name : "<<temp->book_name<<endl;
     cout<<"Author Name : "<<temp->author_name<<endl;
     cout<<"Year of Publication : "<<temp->year<<endl;
     cout<<"Price : "<<temp->price<<endl;
     cout<<"Grand Total  :"<<temp->bill<<endl;
    cout<<"========================================================================================"<<endl; 
    order<<temp->first_name<<" "<<temp->last_name<<","<<temp->address<<","<<temp->book_name<<","<<temp->author_name<<","<<temp->price<<","<<temp->bill<<endl;
 
    cout<<"\n\tYour Package will be deliverd to you in next 3 Days!"<<endl;
     cout<<"\n\tThanks for choosing Reader to Leader \n\n"<<endl;
    }

void set_data(books stock[] , int chosen , person *head)
    {
    person *temp = new person; 
    person *move = new person;
     move = head;

    cout<<"\n\tPlease Enter your credentials "<<endl;
     cout<<"Enter your First Name : ";
     cin>>temp->first_name;
     cout<<"Enter your Second Name : ";
     cin>>temp->last_name;
     cout<<"Enter your Adress : ";
     cin>>temp->address;

    temp->book_name = stock[chosen].name;
     temp->author_name = stock[chosen].author;
     temp->price = stock[chosen].price;
     temp->year = stock[chosen].year;
     temp->bill = stock[chosen].price + 250;

        while(move->next != NULL)
            {
             move = move->next;           
            }
    move->next = temp;
    show_bill(temp);
    }

person* create_node(person *head)
    {
    if(head->next == NULL)
        {
         return head;
        }
    person *move = new person;
     move = head;
        while(move->next != NULL)
            {
             move = move->next;
            }
     
    }

void user_update(books stock[] ,person *head)
    {
    int choice;
    person *move = new person;
     move = head;
        while(move->next != NULL)
            {
             move = move->next;
            }
    
    choice = show_books(stock,len);

    cout<<"\n\tPlease Enter your credentials "<<endl;
    cout<<"Enter your First Name : ";
     cin>>move->first_name;
     cout<<"Enter your Second Name : ";
     cin>>move->last_name;
     cout<<"Enter your Adress : ";
     cin>>move->address;

    move->book_name = stock[choice].name;
     move->author_name = stock[choice].author;
     move->price = stock[choice].price;
     move->year = stock[choice].year;
     move->bill = stock[choice].price + 250;
    
    show_bill(move);
    }

void peek(person *move)
    {
    cout<<"\n\n\t\tUser Found!!\n\n"<<endl;
     cout<<"Name : "<<move->first_name<<" "<<move->last_name<<endl;
     cout<<"Adress : "<<move->address<<endl;
     cout<<"Book Name : "<<move->book_name<<endl;
     cout<<"Author Name : "<<move->author_name<<endl;
     cout<<"Year : "<<move->year<<endl;
     cout<<"Price : "<<move->price<<endl;
     cout<<"Total : "<<move->bill<<endl;
    }

//@Admin Functions

void welcome_admin()
    {
    cout<<"========================================================================================"<<endl; 
     cout<<"\n\t\t\t\t      ---|HELLO!!!|---\n      \t\t\t---|Welcome to Reader to Leader Bookstore|---\n"<<endl;  
     cout<<"\n\n\t\t\t\t::::::||Welcome Admin||::::::\n\n"<<endl; 
     cout<<"========================================================================================"<<endl; 
    }

void traverse(person *head)
    {
    int count = 0;
    int bill = 0;
     person *move = new person;
      move = head->next;
            while(move != NULL)
                {
                cout<<"\n\n\t---|User No."<<count+1<<"|---\n"<<endl;
                count++;
                bill = bill + move->bill;

                 cout<<"Name : "<<move->first_name<<" "<<move->last_name<<endl;
                 cout<<"Adress : "<<move->address<<endl;
                 cout<<"Book Name : "<<move->book_name<<endl;
                 cout<<"Author Name : "<<move->author_name<<endl;
                 cout<<"Year : "<<move->year<<endl;
                 cout<<"Price : "<<move->price<<endl;
                 cout<<"Total : "<<move->bill<<endl;
                 move = move->next;
                }
    
    cout<<"\n\nTotal Enteries are : "<<count<<endl;
     cout<<"Total Revenue Generated Today is : "<<bill<<endl;
    }

void report(person *head)
    {
    system("cls");
     cout<<"\n\n\t***********||REPORT||***********"<<endl;
     traverse(head);
    }

void add_books(books stock[])
    {
    //  len
     cout<<"\n\n\t\tEnter New Book !!!\n\n"<<endl;
     cout<<"Enter Name of the Book : ";
     cin>>stock[len].name;
     cout<<"Enter Name of the Author : ";
     cin>>stock[len].author;
     cout<<"Enter Year of Publication : ";
     cin>>stock[len].year;
     cout<<"Enter Price of the Book : ";
     cin>>stock[len].price;
     len++;
    }

void search(person *head)
    {
// cin.ignore();
        if(head->next  == NULL)
            {
             cout<<"List doesnt Exist!!!"<<endl;
             return;
            }
    person *move = new person;
    move = head;
    string str;
    cout<<"Enter the Person's First Name you want to Search : ";
    cin>>str;
            while(move != NULL)
                {
                if(move->first_name == str)
                    {
                     peek(move);
                     return;
                    }
                move = move->next;
                }
    cout<<"\n\n\t\tNo such Record Found!!!\n"<<endl;
    }
 
void delete_person(person *head)
    {
    person *move = new person;
     move = head;
        if(move->next == NULL)
            {
            cout<<"List doesn't Exist!!!!"<<endl;
             return;
            }
    
    string str;
     cout<<"Enter the First Name of the Person you want to delete : ";
     cin>>str;
    
    person *temp = new person;
    
    if(move->first_name == str)//first node
            {
            move = NULL;
             delete(move);
             cout<<"\n\n\t\tPerson Deleted Succesfully!!!\n"<<endl;
             return;
            }

        while(move != NULL) 
            { 
            // cout<<"chk1"<<endl;
            if(move->next->first_name == str && move->next == NULL)//last node
                {
                temp = move->next;
                 move->next = NULL;
                 delete(temp);
                 cout<<"\n\n\t\tPerson Deleted Succesfully!!!\n"<<endl;
                 return;
                }
            else if(move->next->first_name == str)//incentre node
                {
                temp = move->next;
                 move->next = temp->next;
                 temp->next = NULL;
                 cout<<"\n\n\t\tPerson Deleted Succesfully!!!\n"<<endl;
                 delete(temp);
                 return;
                }
            move = move->next;
            }
    
    }
  
void admin_menu(person *head,books stock[])
    {
    system ("cls");
    char opt;
    admin:
    welcome_admin();
    //  cout<<"\n\n\t\t*********Welcome Admin*********\n\n"<<endl;
     cout<<"\n\t\t:::||Enter your Choice||::: \n\nPress 1 to see the Whole Report\nPress 2 to add new book\nPress 3 to search\n";
     cout<<"Press 4 to delete a Person"<<endl;
     cout<<"Press 0 to go to Head Menu "<<endl;
     cin>>opt;
            switch(opt)
                {
                case '1':
                        report(head);
                         cin>>opt;
                         goto admin;
                         break;
                case '2':
                        add_books(stock);
                         cin>>opt;
                         goto admin;
                         break;
                case '3':
                        search(head);
                         cin>>opt;
                         goto admin;
                         break;
                case '4':
                        delete_person(head);
                         cin>>opt;
                         goto admin;
                         break;
                case '0':
                        break;

                }

    }

//main

int main()
{
system("color 02");
person *p1 = new person;
person *head = new person;
// head = NULL;
person *customer = new person;
books b1[20];
int choice;

//user_interface
create_books(b1);

do
    {
system("cls");
start:

welcome_user();
// cout<<"\n\n\t\t\t\t      HELLO!!!\n      \t\t\tWelcome to Reader to Leader Bookstore\n"<<endl;  
// cout<<"Press 1 if you are a User\n\t\nPress 2 if you want Admin Access\n\nPress 0 to Exit"<<endl; 
 cin>>choice;
        if (choice == 0)
            {
            cout<<"\n============================================================================================="<<endl;
                cout<<"\n\n\t\tThanks You for choosing Readers to Leaders!!"<<endl;
            cout<<"\n============================================================================================="<<endl;
                return 0;
            }
        else if(choice == 2)
                {
                system ("cls");
                welcome_admin();
                cout<<"\n\t---|Please Enter the Admin Pin to access Admin Menu :|--- ";
                 cin>>choice;
                    if(choice == 8521)
                        {
                        admin_menu(head,b1);
                         goto start;
                        }
                    else
                        {
                        cout<<"Wrong Pin Entered!!!!"<<endl;
                         goto start;
                        }
                }
        else
        {
        menu:
        //  cout<<"\n\n\t\t\t\t      HELLO!!!\n      \t\t\tWelcome to Reader to Leader Bookstore\n\t    \t\t\tHere is our Book list. \n\t\t\t\t     Please select"<<endl;
        // welcome_user();
         choice = show_books(b1,len);
                
        set_data(b1,choice,head);
                
        cout<<"\n\nPlease Re-Check your information Press 1 to Confirm\n\t\tOR"<<endl;
         cout<<"Press 0 to Update any Information \n"<<endl;
         cin>>choice;
            if(choice == 0)
                {
                user_update(b1,head);
                goto start;
                } 
        // cout<<"\n\n\tPress 1 if you want to place another order\n\t\tPress 0 to Exit"<<endl;
        //  cin>>choice;
        }
    }while(choice == 1);
// system("cls");
// traverse(head);

}

