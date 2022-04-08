#include<bits/stdc++.h>
using namespace std ; 

class Library {
    public : 
    void initialise() ; 
    void display() ; 
    void student_login() ;
    void student_dashboard() ; 
    void prof_login() ; 
    void prof_dashboard() ; 
    void librarian_login() ;  
    void librarian_dashboard() ; 
    void logout() ;   
};

class User { 
    public : 
    string Name ; 
    int ID ; 
    string password ; 
};

class Professor : public User
{
public:
    int Fine_amount;
    vector<int> List_of_Books; // code - 1
    void Calculate_fine();
    void Clear_fine_amount();
    void Display_Issued_books();
    void Issue_book();
};
class Student : public User
{
public:
    int Fine_amount; // code - 0
    vector<int> List_of_Books;
    void Calculate_fine();
    void Clear_fine_amount();
    void Display_Issued_books();
    void Issue_book();
};
class Librarian : public User
{
public:
    void Search_user_for_book();
    void List_down_all_books_for_user();
    void List_down_all_books_for_Student();
    void List_down_all_books_for_Professor();
};


class Book
{
public:
    string Title;
    string Author;
    string ISBN;
    string Publication;
    string issued_person_identity;
    bool issued_or_not;
    int date_of_issue;
};

class User_database
{
public:
    vector<Student> List_of_Students;
    vector<Professor> List_of_Professors;
    Librarian librarian;
    void Display_all_Users();
    void Add();
    void Update();
    void Delete();
    void Search();
};


class Book_database
{
public:
    vector<Book> List_of_Books;
    void Add();
    void Display_all_Books();
    void Update();
    void Delete();
    void Search();
};
int current_login_number = -1 ;
Library library ; 
User_database library_userdatabase ; 
Book_database library_bookdatabase ; 

void Library :: initialise(){
library_userdatabase.librarian.Name = "test" ; 
library_userdatabase.librarian.ID   =  12345 ; 
library_userdatabase.librarian.password = "test" ; 
}



int current_date()
{
    time_t time_ptr;
    time_ptr = time(NULL);
    tm *tm_local = localtime(&time_ptr);
    int k = tm_local->tm_hour * 3600 + tm_local->tm_min * 60 + tm_local->tm_sec;
    return k;
}

void Library :: display(){
    initialise();
    int val  =  0  ;
    cout<<"HELLO ! Welcome to our Library Managmenet Project!!"<<endl;
    cout<<"The Librarian details are : "<<endl;
    cout<<"Name : "<<library_userdatabase.librarian.Name<<endl;
    cout<<"ID : "<<library_userdatabase.librarian.ID<<endl;
    cout<<"Contact the above mentioned Librarian if facing any issue related to Library"<<endl;
    cout<<"Write 1  if you are student"<<endl;
    cout<<"Write 2  if you are professor"<<endl;
    cout<<"Write 3  if you are librarian"<<endl;
    cout<<"Write 4  if you want to Exit"<<endl;
    cin >> val ; 
    if(val==3){
        librarian_login(); 
    }
    
    else if(val==1){
        student_login(); 
    }

    
    else if(val==2){
        prof_login() ; 
    }
    
    else if(val==4){
       exit(0) ;
    }
}

void Library :: librarian_login(){
    cout<<"Welcome Back !"<<endl;
    int id ; 
    string password ; 
    cout<<endl ; 
    cout<<"Enter your ID : " ; 
    cin>>id; 
    cout<<endl;
    cout<<"Enter your Password : ";
    cin>>password;
   if(id == library_userdatabase.librarian.ID && password == library_userdatabase.librarian.password ) {
      librarian_dashboard() ; 
   }
   else{
       cout<<"WRONG DETAILS!"<<endl;
       display() ; 
   }
}

void User_database :: Display_all_Users(){
  cout<<"The total Students's Database : "<<endl ; 
  for(auto it : List_of_Students){
      cout<<"Name : "<<it.Name<<" "<<"ID : "<<it.ID<<" "<<"password : "<<it.password<<endl;
  }
  cout<<"The total Professors's Database : "<<endl ; 
  for(auto it : List_of_Professors){
       cout<<"Name : "<<it.Name<<" "<<"ID : "<<it.ID<<" "<<"password : "<<it.password<<endl;
  }
  cout<<"The Librarian's Detail"<<endl;
  cout<<"Name : test"<<" "<<"ID : "<<12345<<" "<<"password : test"<<endl;
  cout<<"Write 1 to go to the Dashboard"<<endl;
  int one ; 
  cin >> one ; 
  if(one==1)library.librarian_dashboard() ; 
}

void User_database :: Add(){
string name; int id ; string password ; int proff;
cout<<"Enter 1 if it's proff adding details otherwise 0 for the student "<<endl;
cin >> proff ; 
cout<<"Enter the Name : "<<endl;
cin >> name ; 
cout<<endl;
cout<<"Enter the ID : "<<endl ; 
cin >> id ; 
cout<<"Enter the Password : "<<endl;
cin >> password  ; 
cout<<endl;
if(proff == 0){
    Student student ;
    student.Name = name , student.ID = id , student.password = password ; 
    library_userdatabase.List_of_Students.push_back(student) ;
    cout<<"Added to the Database"<<endl ; 
 cout<<"Write 1 to go to the Dashboard"<<endl;
   int one ;
  cin >> one ; 
  if(one==1)library.librarian_dashboard() ; 
    return ;
}
Professor professor ; 
 professor.Name = name , professor.ID = id , professor.password = password ; 
 library_userdatabase.List_of_Professors.push_back(professor) ;
 cout<<"Added to the Database"<<endl ; 
 cout<<"Write 1 to go to the Dashboard"<<endl;
   int one ;
  cin >> one ; 
  if(one==1)library.librarian_dashboard() ; 
}


void User_database :: Update(){
string name; int id ; string password ; int proff;
cout<<"Enter 1 if it's proff adding details otherwise 0 for the student "<<endl;
cin >> proff ; 
cout<<"Enter the Name : "<<endl;
cin >> name ; 
cout<<endl;
cout<<"Enter the OLD ID : "<<endl ; 
cin >> id ; 
cout<<"Enter the OLD Password : "<<endl;
cin >> password  ; 
cout<<endl;
int new_id ; 
string new_password ; 
bool p = false ; 
if(proff== 0){
      for(int i=0;i<List_of_Students.size();i++){
         if(List_of_Students[i].Name == name && List_of_Students[i].ID == id && List_of_Students[i].password == password){
cout<<"ENTER THE NEW ID : "<<endl;
cin >> new_id ; 
cout<<"Enter the new passoword : "<<endl;
cin >> new_password ;
cout<<endl;
             List_of_Students[i].Name  = name  ; 
            List_of_Students[i].ID = new_id  ; 
            List_of_Students[i].password = new_password ;  
             p = true ; 
         }
     }
     if(p==true)
 cout<<"Details are Updated Now!!"<<endl ; 
 else 
 cout<<"Wrong details!!"<<endl;
cout<<"Write 1 to go to the Dashboard"<<endl;
  int one ;
  cin >> one ; 
  if(one==1)library.librarian_dashboard() ; 
     return ; 
}
      for(int i=0;i<List_of_Professors.size();i++){
         if(List_of_Professors[i].Name == name && List_of_Professors[i].ID == id && List_of_Professors[i].password == password){
cout<<"ENTER THE NEW ID : "<<endl;
cin >> new_id ; 
cout<<"Enter the new passoword : "<<endl;
cin >> new_password ;
cout<<endl;
             List_of_Professors[i].Name = name  ; 
             List_of_Professors[i].ID = new_id  ; 
             List_of_Professors[i].password = new_password ; 
             p = true ; 
         }
     }
if(p==true)cout<<"Details are Updated Now!!"<<endl ; 
else cout<<"Wrong Details!!"<<endl;
cout<<"Write 1 to go to the Dashboard"<<endl;
  int one ;

  cin >> one ; 
  if(one==1)library.librarian_dashboard() ; 

}

void User_database :: Delete(){
string name; int id ; string password ; int proff;
cout<<"Enter 1 if it's proff adding details otherwise 0 for the student "<<endl;
cin >> proff ; 
cout<<"Enter the Name : "<<endl;
cin >> name ; 
cout<<endl;
cout<<"Enter the ID : "<<endl ; 
cin >> id ; 
cout<<"Enter the Password : "<<endl;
cin >> password  ; 
cout<<endl;
bool p = false;  
if(proff == 0 ){
    for(int i=0;i<List_of_Students.size();i++){
         if(List_of_Students[i].Name == name && List_of_Students[i].ID == id && List_of_Students[i].password == password){

            List_of_Students.erase(List_of_Students.begin() + i) ;
            cout<<"Student is deleted from the database!"<<endl;
            p = true ; 
            break ; 
         }
    }
 cout<<"Write 1 to go to the Dashboard"<<endl;
   int one ;
  cin >> one ; 
  if(one==1)library.librarian_dashboard() ; 
            return ; 
    }
   for(int i=0;i<List_of_Professors.size();i++){
         if(List_of_Professors[i].Name == name && List_of_Professors[i].ID == id && List_of_Professors[i].password == password){

            List_of_Professors.erase(List_of_Professors.begin() +  i) ;
            cout<<"Professor is deleted from the database!"<<endl;
         }
   }
    int one ;
  cin >> one ; 
  if(one==1)library.librarian_dashboard() ; 
            return ; 
}

void User_database :: Search(){
string name; int id ; string password ; int proff;
cout<<"Enter 1 if it's proff adding details otherwise 0 for the student "<<endl;
cin >> proff ; 
cout<<"Enter the Name : "<<endl;
cin >> name ; 
cout<<endl;
cout<<"Enter the ID : "<<endl ; 
cin >> id ; 
cout<<"Enter the Password : "<<endl;
cin >> password  ; 
cout<<endl;
if(proff == 0 ){
    for(auto it : List_of_Students){
         if(it.Name == name && it.ID == id && it.password == password){
 cout<<"YES! The Student is present !!"<<endl;
 cout<<"Write 1 to go to the Dashboard"<<endl;
   int one ;

  cin >> one ; 
  if(one==1)library.librarian_dashboard() ; 
          return ; 
         }
    }
     cout<<"NO! The student is not present!!"<<endl ;
  cout<<"Write 1 to go to the Dashboard"<<endl;
    int one ;

  cin >> one ; 

  if(one==1)library.librarian_dashboard() ;  
    return ;
}
  for(auto it : List_of_Professors){
         if(it.Name == name && it.ID == id && it.password == password){
          cout<<"YES! The Prof is present !!"<<endl;
  cout<<"Write 1 to go to the Dashboard"<<endl;
  int one ; 
  cin >> one ; 
  if(one==1)library.librarian_dashboard() ; 
          return ;
         }
    }
     cout<<"NO! The Professor is not present!!"<<endl ; 
  cout<<"Write 1 to go to the Dashboard"<<endl;
  int one ;
  cin >> one ; 
  if(one==1)library.librarian_dashboard() ; 
}

void Book_database :: Add(){
    Book book ; 
    string title , author , isbn , Publication ;
    cout<<"Enter the Book title : "<<endl ; 
    cin >> title ; 
    cout<<endl ; 
   cout<<"Enter the Book author : "<<endl ; 
   cin >> author ; 
   cout<<endl ; 
   cout<<"Enter the Book isbn : "<<endl ; 
   cin >> isbn ;
   cout<<endl ; 
    cout<<"Enter the Book Publication : "<<endl ; 
    cin >> Publication ; 
    cout<<endl ;
    book.Title = title , book.Author = author ;
    book.ISBN = isbn ; 
    book.Publication  = Publication  ;
    book.issued_or_not = false ; 
    library_bookdatabase.List_of_Books.push_back(book) ; 
    cout<<"Book has been added now to the Database"<<endl;
    cout<<"Write 1 to go to the Dashboard"<<endl;
  int one ;
  cin >> one ; 
  if(one==1)library.librarian_dashboard() ; 
}

void Book_database :: Update(){
    cout<<"Enter the Book Title to update : "<<endl;
    string title ; 
    cin >> title ; 
    cout<<endl;
    cout<<"Update the author : "<<endl;
    string author ; 
    cin >> author ; 
    cout<<endl;
    cout<<"Update the isbn : "<<endl;
    string isbn ; 
    cin >> isbn ; 
    cout<<endl; 
    cout<<"Update the publication : "<<endl;
    string publication ; 
    cin >> publication ; 
    cout<<endl; 
    cout<<"Update the Issued Person Identity : "<<endl;
    string a ; 
    cin >> a ; 
    cout<<endl; 
    cout<<"Update the Issued or not : "<<endl;
      bool b ; 
    cin >> b ; 
    cout<<endl; 
    cout<<"Update the date of issue : "<<endl;
    int c ; 
    cin >> c ; 
    cout<<endl; 

   for(int i=0;i<List_of_Books.size() ; i++){
        if(List_of_Books[i].Title==title){
         List_of_Books[i].Author = author ; 
         List_of_Books[i].ISBN  = isbn ; 
         List_of_Books[i].Publication = publication ; 
         List_of_Books[i].issued_person_identity = a ; 
         List_of_Books[i].issued_or_not = b ;
         List_of_Books[i].date_of_issue = c ; 
             cout<<"THE BOOK HAS BEEN UPDATED!!!"<<endl;

        }
    }
    cout<<"Write 1 to go to the Dashboard"<<endl;
  int one ;
  cin >> one ; 
  if(one==1)library.librarian_dashboard() ; 
}

void Book_database :: Display_all_Books(){
    if(List_of_Books.size()==0){
        cout<<"CURRENTLY there is no book available!!"<<endl;
  cout<<"Write 1 to go to the Dashboard , 2 to prof dashborad , 3 to student dashboard"<<endl;
  int one ;
  cin >> one ; 
  if(one==1)library.display() ; 
  if(one==2)library.prof_dashboard();
  if(one==3)library.student_dashboard();
        return ; 
    }
    for(int i=0;i<List_of_Books.size();i++){
        cout<<"Title : "<<        List_of_Books[i].Title<<" "<<"Author : "<<List_of_Books[i].Author<<" "<<"ISBN : "<<List_of_Books[i].ISBN <<" Publication  : "<<List_of_Books[i].Publication<<" "<<"Issued or not  : "<<List_of_Books[i].issued_or_not<<" "<<"Issued Person Identity : "<<List_of_Books[i].issued_person_identity<<" "<<"Date of Issue : "<<List_of_Books[i].date_of_issue<<endl;
    }
    cout<<"Write 1 to go to the Dashboard , 2 to prof dashborad , 3 to student dashboard"<<endl;
  int one ;
  cin >> one ; 
  if(one==1)library.display() ; 
  if(one==2)library.prof_dashboard();
  if(one==3)library.student_dashboard();
}
void Book_database :: Delete(){
    string title , author , isbn , Publication ;
    cout<<"Enter the Book title : "<<endl ; 
    cin >> title ; 
    cout<<endl ; 
   cout<<"Enter the Book author : "<<endl ; 
   cin >> author ; 
   cout<<endl ; 
   cout<<"Enter the Book isbn : "<<endl ; 
   cin >> isbn ;
   cout<<endl ; 
    cout<<"Enter the Book Publication : "<<endl ; 
    cin >> Publication ; 
    cout<<endl ;
  for(int i=0;i<List_of_Books.size();i++){
        if(List_of_Books[i].ISBN==isbn){
           List_of_Books.erase(List_of_Books.begin() + i);
            cout<<"Book is deleted from the database!"<<endl;
            break ;
        }
    }
    cout<<"Write 1 to go to the Dashboard"<<endl;
  int one ;
  cin >> one ; 
  if(one==1)library.librarian_dashboard() ; 
}
void Book_database :: Search(){
    string title , author , isbn , Publication ;
    cout<<"Enter the Book title : "<<endl ; 
    cin >> title ; 
    cout<<endl ; 
   cout<<"Enter the Book author : "<<endl ; 
   cin >> author ; 
   cout<<endl ; 
   cout<<"Enter the Book isbn : "<<endl ; 
   cin >> isbn ;
   cout<<endl ; 
    cout<<"Enter the Book Publication : "<<endl ; 
    cin >> Publication ; 
    cout<<endl ;
     for(auto it : List_of_Books){
        if(it.ISBN==isbn){
            cout<<"Book is in the database!!"<<endl;
cout<<"Write 1 to go to the Dashboard"<<endl;
  int one ;
  cin >> one ; 
  if(one==1)library.librarian_dashboard() ; 
            return ; 
        }
    }
  cout<<"Book is not in the database"<<endl ; 
  cout<<"Write 1 to go to the Dashboard"<<endl;
  int one ;
  cin >> one ; 
  if(one==1)library.librarian_dashboard() ; 
}

void Librarian :: Search_user_for_book(){
    string title ; 
    cout<<"Enter Book Title : "<<endl ; 
    cin >> title ; 
    cout<<endl ; 
    for(auto it : library_bookdatabase.List_of_Books){
        if(it.Title == title ){
            if(it.issued_or_not==false){
                cout<<"This Book is Available!"<<endl;
cout<<"Write 1 to go to the Dashboard"<<endl;
  int one ;
  cin >> one ; 
  if(one==1)library.librarian_dashboard() ; 
                return ; 
            }
            else{
                cout<<"This Book is issued by"<<it.issued_person_identity<<" on"<<it.date_of_issue<<endl;
 cout<<"Write 1 to go to the Dashboard"<<endl;
  int one ;
  cin >> one ; 
  if(one==1)library.librarian_dashboard() ; 
                return ; 
            }
        }
    }
}

void Librarian :: List_down_all_books_for_user(){
    cout<<"write 1 : for the proff and 0 : for the student"<<endl ;
    int a ; 
    cin >> a ; 
    if(a==1){
        List_down_all_books_for_Professor();
    }
    else{
        List_down_all_books_for_Student();
    }
}

void Librarian :: List_down_all_books_for_Student(){
    cout<<"Enter the Student Name : "<<endl;
    string student_name ;
    cin >> student_name ;
    for(auto it : library_userdatabase.List_of_Students){
        if(it.Name==student_name){
            unordered_map<int,int>m;
            for(auto it1 : it.List_of_Books){
              m[it1] = 1 ; 
            }
            if(it.List_of_Books.size()==0){
                cout<<"Currently No Book issued "<<endl;
  cout<<"Write 1 to go to the Dashboard"<<endl;
  int one ;
  cin >> one ; 
  if(one==1)library.librarian_dashboard() ; 
        return;
            }
            for(int i=0;i<library_bookdatabase.List_of_Books.size();i++){
                if(m.find(i)!=m.end()){
                    auto it1 = library_bookdatabase.List_of_Books[i] ;
                     cout<<"Title : "<<it1.Title<<" "<<"Author : "<<it1.Author<<" ISBN : "<<it1.ISBN<<endl;
                }
        }

 cout<<"Write 1 to go to the Dashboard"<<endl;
  int one ;
  cin >> one ; 
  if(one==1)library.librarian_dashboard() ; 
        return;
    }
 }
}

void Librarian :: List_down_all_books_for_Professor(){
    cout<<"Enter the Professor Name : "<<endl;
    string professor ;
    cin >>  professor;
    for(auto it : library_userdatabase.List_of_Professors){
        if(it.Name==professor){
            unordered_map<int,int>m;
            for(auto it1 : it.List_of_Books){
              m[it1] = 1 ; 
            }
                        if(it.List_of_Books.size()==0){
                cout<<"Currently No Book issued "<<endl;
  cout<<"Write 1 to go to the Dashboard"<<endl;
  int one ;
  cin >> one ; 
  if(one==1)library.librarian_dashboard() ; 
        return;
            }
            for(int i=0;i<library_bookdatabase.List_of_Books.size();i++){
                if(m.find(i)!=m.end()){
                    auto it1 = library_bookdatabase.List_of_Books[i] ;
                     cout<<"Title : "<<it1.Title<<" "<<"Author : "<<it1.Author<<" ISBN : "<<it1.ISBN<<endl;
                }
        }
  cout<<"Write 1 to go to the Dashboard"<<endl;
  int one ;
  cin >> one ; 
  if(one==1)library.librarian_dashboard() ; 
        return;
    }
 }
}



void Library :: librarian_dashboard(){
       cout << "\n\n";
    cout << "Welcome ";
    cout << library_userdatabase.librarian.Name << endl;
    cout << "1. Add a User\n";
    cout << "2. Update a User\n";
    cout << "3. Delete a User\n";
    cout << "4. Display all Users\n";
    cout << "5. Add a Book\n";
    cout << "6. Update a Book\n";
    cout << "7. Delete a Book\n";
    cout << "8. Display all Books\n";
    cout << "9. Search a user who has a particular book\n";
    cout << "10. List down all the books issued to a user\n";
    cout << "11. Search for a User\n";
    cout << "12. Search for a Book\n";
    cout << "13. Logout\n";

    int choice;
    cin >> choice;
   
    switch (choice)
    {
    case 1:
        library_userdatabase.Add();
        break;
    case 2:
        library_userdatabase.Update();
        break;

    case 3:
        library_userdatabase.Delete();
        break;

    case 4:
        library_userdatabase.Display_all_Users();
        break;

    case 5:
        library_bookdatabase.Add();
        break;

    case 6:
         library_bookdatabase.Update();
        break;

    case 7:
        library_bookdatabase.Delete();
        break;

    case 8:
        library_bookdatabase.Display_all_Books();
        cout << "\n";
        library.librarian_dashboard();
        break;

    case 9:
        library_userdatabase.librarian.Search_user_for_book();
        break;

    case 10:
        library_userdatabase.librarian.List_down_all_books_for_user();
        break;
      case 11:
        library_userdatabase.Search();
        break;
       case 12 :
       library_bookdatabase.Search();
       break;
    case 13:
        library.logout();
        break;

    default:
        cout << "Invalid Option\n";
    }
    cout << "\n";
    library.librarian_dashboard();
}

void Library :: student_login(){
    cout<<"Welcome  !"<<endl;
    string name;  
    int id ; 
    string password ; 
    cout<<"Enter your Name : ";
    cin >> name ; 
    cout<<endl ; 
    cout<<"Enter your ID : " ; 
    cin>>id; 
    cout<<endl;
    cout<<"Enter your Password : ";
    cin>>password;
   bool p = false ;
   for(int i=0;i<library_userdatabase.List_of_Students.size();i++){
       if(library_userdatabase.List_of_Students[i].Name==name && library_userdatabase.List_of_Students[i].ID==id && library_userdatabase.List_of_Students[i].password==password){
           p = true ; 
        current_login_number = i ; 
       }
   }
   if(p==true)
   {
      student_dashboard() ; 
   }
   else{
       cout<<"WRONG DETAILS!"<<endl;
       display() ; 
   }
}


void Student :: Issue_book(){
    cout<<"Book Title : "<<endl ;
    string title ;
    cin >> title ; 
    cout<<endl ; 
    int index = -1 ; 
    if(List_of_Books.size()==5){
        cout<<"Can't Issue more books!!"<<endl;
    cout<<"Write 1 to go to the Dashboard"<<endl;
  int one ;
  cin >> one ; 
  if(one==1)library.student_dashboard() ; 
        return;
    }
    for(int i=0;i<library_bookdatabase.List_of_Books.size();i++){
        if(library_bookdatabase.List_of_Books[i].Title==title)index = i ; 
        if(library_bookdatabase.List_of_Books[i].issued_or_not==true){
            cout<<"Book is not avaiable"<<endl;
  cout<<"Write 1 to go to the Dashboard"<<endl;
  int one ;
  cin >> one ; 
  if(one==1)library.student_dashboard() ; 
        return;
        }
    }
    library_bookdatabase.List_of_Books[index].issued_or_not=true ; 
    library_bookdatabase.List_of_Books[index].issued_person_identity="Student";
    library_bookdatabase.List_of_Books[index].date_of_issue = current_date();
    List_of_Books.push_back(index);
   cout<<"Book Issued!!"<<endl; 
  cout<<"Write 1 to go to the Dashboard"<<endl;
  int one ;
  cin >> one ; 
  if(one==1)library.student_dashboard() ; 
        return;   
}

void Student :: Display_Issued_books(){
    unordered_map<int,int>m;
    for(auto it : List_of_Books){
        m[it] = 1 ; 
    }
     for(int i=0;i<library_bookdatabase.List_of_Books.size();i++){
         if(m.find(i)!=m.end()){
             auto it = library_bookdatabase.List_of_Books[i] ; 
             cout<<"Title : "<<it.Title<<" "<<"Author : "<<it.Author<<" ISBN : "<<it.ISBN<<endl;
         }
    }
        if(List_of_Books.size()==0){
        cout<<"Currently Nothing is issued yet!!"<<endl;
    }
cout<<"Write 1 to go to the Dashboard"<<endl;
  int one ;
  cin >> one ; 
  if(one==1)library.student_dashboard() ; 
        return;
}

void Student :: Calculate_fine(){
             int fine = 0 ; 
        unordered_map<int,int>m;
    for(auto it : List_of_Books){
        m[it] = 1 ; 
    }
     for(int i=0;i<library_bookdatabase.List_of_Books.size();i++){
         if(m.find(i)!=m.end()){
             auto it = library_bookdatabase.List_of_Books[i] ; 
            if(current_date() - it.date_of_issue>30){
                fine+=abs(current_date() - it.date_of_issue)*2;
            }
    }
}
// I AM TAKING 1 DAY AS 1 SEC 
               Fine_amount = fine ; 
               if(fine==0)cout<<"NO FINE!"<<endl;
               else{
                cout<<"GIVE FINE OF : "<<endl;
                cout<<Fine_amount<<endl;
               }
  cout<<"Write 1 to go to the Dashboard"<<endl;
  int one ;
  cin >> one ; 
  if(one==1)library.student_dashboard() ; 
        return;
}

void Student :: Clear_fine_amount(){
    if(Fine_amount==0){
        cout<<"YOU DON'T HAVE ANY FINE AMOUNT"<<endl;
    }
    else{
        cout<<"Your Fine Amount has been cleared!!"<<endl;
        Fine_amount = 0 ;
    }
  cout<<"Write 1 to go to the Dashboard"<<endl;
  int one ;
  cin >> one ; 
  if(one==1)library.student_dashboard() ; 
        return;
}

void Library :: student_dashboard(){
    cout << "\n\n";
    cout << "Welcome ";
    cout << library_userdatabase.List_of_Students[current_login_number].Name << endl;
    cout << "1. Display Fine Amount\n";
    cout << "2. List of Books Issued\n";
    cout << "3. Clear Fine Amount\n";
    cout << "4. Display List of Books in library\n";
    cout << "5. Issue a book\n";
    cout << "6. Logout\n";
    cout << "Enter Your Choice from 1-7\n";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        library_userdatabase.List_of_Students[current_login_number].Calculate_fine();
        break;

    case 2:
        library_userdatabase.List_of_Students[current_login_number].Display_Issued_books();
        break;

    case 3:
        library_userdatabase.List_of_Students[current_login_number].Clear_fine_amount();
        break;

    case 4:
        library_bookdatabase.Display_all_Books();
        cout << "\n";
        student_dashboard();
        break;

    case 5:
        library_userdatabase.List_of_Students[current_login_number].Issue_book();
        break;

    case 6:
        library.logout();
        break;

    default:
        cout << "Invalid Choice\n";
        break;
    }
    cout << "\n";
    student_dashboard();
}



void Library :: prof_login(){
    cout<<"Welcome  !"<<endl;
    string name;  
    int id ; 
    string password ; 
    cout<<"Enter your Name : ";
    cin >> name ; 
    cout<<endl ; 
    cout<<"Enter your ID : " ; 
    cin>>id; 
    cout<<endl;
    cout<<"Enter your Password : ";
    cin>>password;
   bool p = false ;
   for(int i=0;i<library_userdatabase.List_of_Professors.size();i++){
       if(library_userdatabase.List_of_Professors[i].Name==name && library_userdatabase.List_of_Professors[i].ID==id && library_userdatabase.List_of_Professors[i].password==password){
           p = true ; 
        current_login_number = i ; 
       }
   }
   if(p==true)
   {
      prof_dashboard() ; 
   }
   else{
       cout<<"WRONG DETAILS!"<<endl;
       display() ; 
   }
}


void Professor :: Issue_book(){
    cout<<"Book Title : "<<endl ;
    string title ;
    cin >> title ; 
    cout<<endl ; 
    int index = -1 ; 
    for(int i=0;i<library_bookdatabase.List_of_Books.size();i++){
        if(library_bookdatabase.List_of_Books[i].Title==title)index = i ; 
        if(library_bookdatabase.List_of_Books[i].issued_or_not==true){
            cout<<"Book is not avaiable"<<endl;
  cout<<"Write 1 to go to the Dashboard"<<endl;
  int one ;
  cin >> one ; 
  if(one==1)library.prof_dashboard() ; 
        return;
        }
    }
    library_bookdatabase.List_of_Books[index].issued_or_not=true ; 
    library_bookdatabase.List_of_Books[index].issued_person_identity="Professor";
    library_bookdatabase.List_of_Books[index].date_of_issue = current_date();
    List_of_Books.push_back(index);
   cout<<"Book Issued!!"<<endl; 
  cout<<"Write 1 to go to the Dashboard"<<endl;
  int one ;
  cin >> one ; 
  if(one==1)library.prof_dashboard() ; 
        return;   
}

void Professor :: Display_Issued_books(){
    unordered_map<int,int>m;
    for(auto it : List_of_Books){
        m[it] = 1 ; 
    }
     for(int i=0;i<library_bookdatabase.List_of_Books.size();i++){
         if(m.find(i)!=m.end()){
             auto it = library_bookdatabase.List_of_Books[i] ; 
             cout<<"Title : "<<it.Title<<" "<<"Author : "<<it.Author<<" ISBN : "<<it.ISBN<<endl;
         }
    }
    if(List_of_Books.size()==0){
        cout<<"Currently Nothing is issued yet!!"<<endl;
    }
cout<<"Write 1 to go to the Dashboard"<<endl;
  int one ;
  cin >> one ; 
  if(one==1)library.prof_dashboard() ; 
        return;
}

void Professor :: Calculate_fine(){
             int fine = 0 ; 
        unordered_map<int,int>m;
    for(auto it : List_of_Books){
        m[it] = 1 ; 
    }
     for(int i=0;i<library_bookdatabase.List_of_Books.size();i++){
         if(m.find(i)!=m.end()){
             auto it = library_bookdatabase.List_of_Books[i] ; 
            if(current_date() - it.date_of_issue>60){
                fine+=abs(current_date() - it.date_of_issue)*5;
            }
    }
}
// I AM TAKING 1 DAY AS 1 SEC 
               Fine_amount = fine ; 
               if(fine==0)cout<<"NO FINE!"<<endl;
               else{
                cout<<"GIVE FINE OF : "<<endl;
                cout<<Fine_amount<<endl;
               }
  cout<<"Write 1 to go to the Dashboard"<<endl;
  int one ;
  cin >> one ; 
  if(one==1)library.prof_dashboard() ; 
        return;
}

void Professor :: Clear_fine_amount(){
    if(Fine_amount==0){
        cout<<"YOU DON'T HAVE ANY FINE AMOUNT"<<endl;
    }
    else{
        cout<<"Your Fine Amount has been cleared!!"<<endl;
        Fine_amount = 0 ;
    }
  cout<<"Write 1 to go to the Dashboard"<<endl;
  int one ;
  cin >> one ; 
  if(one==1)library.prof_dashboard() ; 
        return;
}

void Library :: prof_dashboard(){
    cout << "\n\n";
    cout << "Welcome ";
    cout << library_userdatabase.List_of_Professors[current_login_number].Name << endl;
    cout << "1. Display Fine Amount\n";
    cout << "2. List of Books Issued\n";
    cout << "3. Clear Fine Amount\n";
    cout << "4. Display List of Books in library\n";
    cout << "5. Issue a book\n";
    cout << "6. Logout\n";
    cout << "Enter Your Choice from 1-7\n";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        library_userdatabase.List_of_Professors[current_login_number].Calculate_fine();
        break;

    case 2:
        library_userdatabase.List_of_Professors[current_login_number].Display_Issued_books();
        break;

    case 3:
        library_userdatabase.List_of_Professors[current_login_number].Clear_fine_amount();
        break;

    case 4:
        library_bookdatabase.Display_all_Books();
        cout << "\n";
        prof_dashboard();
        break;

    case 5:
        library_userdatabase.List_of_Professors[current_login_number].Issue_book();
        break;

    case 6:
        logout();
        break;

    default:
        cout << "Invalid Choice\n";
    }
    cout << "\n";
    prof_dashboard();


}
void Library :: logout(){

    cout<<"YOU HAVE SUCCESSFULLY LOGED OUT!!"<<endl;
    library.display();

}

int main(){
     library.display() ; 
}
