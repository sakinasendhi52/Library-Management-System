//Library Management System

//header files
#include<iostream>
#include<stdexcept>   //for exception handling
#include<cctype>      //for tolower() function
using namespace std;

class LibraryItem{     //abstract base class
    private:
        string title,author,dueDate;
    public:
        //getters and setters
        string getTitle(){
            return title;
        }
        string getAuthor(){
            return author;
        }
        string getDueDate(){
            return dueDate;
        }
        void setTitle(string t){
            title = t;
        }
        void setAuthor(string a){
            author = a;
        }
        void setDueDate(string d){
            dueDate = d;
        }

        virtual void checkOut()=0;   //pure virtual function
        virtual void returnItem()=0;   //pure virtual function
        virtual void displayDetails()=0;   //pure virtual function

        //destructor
        virtual ~LibraryItem(){}
};

//book derived class
class Book : public LibraryItem{
    private:                 //data members/attributes
        string ISBN;
    public:                //member functions
        //parameterized constructor
        Book(string t,string a,string d,string i){
            setTitle(t);
            setAuthor(a);
            setDueDate(d);
            setISBN(i);
        }
        void setISBN(string isbn){
            //exception handling
            try{
                if (isbn.length() < 5){
                    throw invalid_argument("Invalid ISBN!");
                }
                ISBN=isbn;
            }
            catch(invalid_argument &e){
                cout<<"=============  EXCEPTION : ISBN length is less than 5  ============"<<endl<<endl;
                ISBN="00000";
            }
        }
        //implement the pure virtual functions
        void checkOut() override{
            cout<<"========================  BOOK CHECKED OUT  ======================="<<endl<<endl;
        }
        void returnItem() override{
            cout<<"=========================  BOOK RETURNED  ========================="<<endl<<endl;
        }
        void displayDetails() override{
            cout<<"======================  SEARCHED BOOK DETAILS  ===================="<<endl;
            cout<<"TITLE            : "<<getTitle()<<endl;
            cout<<"AUTHOR           : "<<getAuthor()<<endl;
            cout<<"DUE DATE         : "<<getDueDate()<<endl;
            cout<<"ISBN             : "<<ISBN<<endl;
            cout<<"==================================================================="<<endl<<endl;
        }
};

//DVD derived class
class DVD : public LibraryItem{
    private:                 //data members/attributes
        int duration;
    public:                //member functions
        //parameterized constructor
        DVD(string t,string a,string d,int duration){
            setTitle(t);
            setAuthor(a);
            setDueDate(d);
            setDuration(duration);
        }
        void setDuration(int d){
            try{
                if(d<=0){
                    throw invalid_argument("Invalid duration!");
                }
                duration = d;
            }
            catch(invalid_argument &e){
                cout<<"===============  EXCEPTION : Duration is less than 0  ============="<<endl<<endl;
                duration = 1;
            }
        }      
        //implement the pure virtual functions
        void checkOut() override{
            cout<<"========================  DVD CHECKED OUT  ========================"<<endl<<endl;
        }
        void returnItem() override{
            cout<<"=========================  DVD RETURNED  =========================="<<endl<<endl;
        }
        void displayDetails() override{
            cout<<"======================  SEARCHED DVD DETAILS  ====================="<<endl;
            cout<<"TITLE            : "<<getTitle()<<endl;
            cout<<"AUTHOR           : "<<getAuthor()<<endl;
            cout<<"DUE DATE         : "<<getDueDate()<<endl;
            cout<<"DURATION         : "<<duration<<" Days"<<endl;
            cout<<"==================================================================="<<endl<<endl;
        }
};

//magazine derived class
class Magazine : public LibraryItem{
    private:                 //data members/attributes
        int issueNumber;
    public:                //member functions
        Magazine(string t,string a,string d,int issue){
            setTitle(t);
            setAuthor(a);
            setDueDate(d);
            setIssueNumber(issue);
        }
        void setIssueNumber(int i){
            try{
                if (i <= 0){
                    throw invalid_argument("Invalid issue number!");
                }
                issueNumber = i;
            }
            catch(invalid_argument &e){
                cout<<"=============  EXCEPTION : Issue Number is less than 0  ==========="<<endl<<endl;
                issueNumber=1;
            }
            
        }
        //implement the pure virtual functions
        void checkOut() override{
            cout<<"======================  MAGAZINE CHECKED OUT  ====================="<<endl<<endl;
        }
        void returnItem() override{
            cout<<"=======================  MAGAZINE RETURNED  ======================="<<endl<<endl;
        }
        void displayDetails() override{
            cout<<"====================  SEARCHED MAGAZINE DETAILS  ==================="<<endl;
            cout<<"TITLE             : "<<getTitle()<<endl;
            cout<<"AUTHOR            : "<<getAuthor()<<endl;
            cout<<"DUE DATE          : "<<getDueDate()<<endl;
            cout<<"ISSUE NUMBER      : "<<issueNumber<<endl;
            cout<<"==================================================================="<<endl<<endl;
        }
};

//function to change into lowercase
string toLower(string str)
{
    for(int i=0; i<str.length(); i++)
    {
        str[i] = tolower(str[i]);
    }
    return str;
}

//main function
int main(){
    int MAX_ITEMS=100,choice=0,i=0,count=0;               //variables
    LibraryItem* libraryItems[MAX_ITEMS];         //array of LibraryItem pointers

    //Heading
    cout<<"==================================================================="<<endl;
    cout<<"                     LIBRARY MANAGEMENT SYSTEM                     "<<endl;
    cout<<"==================================================================="<<endl<<endl;

    //Pre added values for Books
    {
        libraryItems[0] = new Book("Harry Potter","J.K. Rowling","12-4-2026","11111");
        libraryItems[1] = new Book("The Hobbit","J.R.R. Tolkien","15-4-2026","22222");
        libraryItems[2] = new Book("The Alchemist","Paulo Coelho","10-4-2026","33333");
        libraryItems[3] = new Book("Pride and Prejudice","Jane Austen","22-4-2026","44444");
        libraryItems[4] = new Book("The Lord of the Rings","J.R.R. Tolkien","26-4-2026","55555");
    }
    
    //Pre added values for DVD
    {
        libraryItems[5] = new DVD("Inception","Christopher Nolan","5-5-2026",10);
        libraryItems[6] = new DVD("Interstellar","Christopher Nolan","7-5-2026",20);
        libraryItems[7] = new DVD("Avengers Endgame","Marvel Studios","8-5-2026",15);
        libraryItems[8] = new DVD("Titanic","James Cameron","9-5-2026",10);
        libraryItems[9] = new DVD("The Lion King","Disney","14-5-2026",25);
    }

    //Pre added values for Magazines
    {
        libraryItems[10] = new Magazine("Vogue","Vogue Team","18-5-2026",104);
        libraryItems[11] = new Magazine("Time","Time Editors","15-5-2026",101);
        libraryItems[12] = new Magazine("National Geographic","NatGeo Team","16-5-2026",102);
        libraryItems[13] = new Magazine("Forbes","Forbes Editors","17-5-2026",103);
        libraryItems[14] = new Magazine("Harvard Business Review","HBR Editors","22-5-2026",108);
    }

    count=15;

    //do while loop for choice
    do{
        cout<<"=============================  MENU  =============================="<<endl;
        cout<<" 1 . Search Items"<<endl;
        cout<<" 2 . Check Out"<<endl;
        cout<<" 3 . Return Them"<<endl;
        cout<<" 4 . Exit "<<endl<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        cout<<endl;

        //switch case to match the choice
        switch(choice){
            //Search items
            case 1:{
                string searchTitle;
                int match=0;
                cout<<"Enter title to search: ";
                cin.ignore();
                getline(cin,searchTitle);

                for(int i=0; i<count; i++){
                    if(toLower(libraryItems[i]->getTitle()) == toLower(searchTitle)){
                        libraryItems[i]->displayDetails();
                        match = 1;
                     }
                }
                if(match!=1){
                    cout<<"========================  ITEM NOT FOUND  ========================="<<endl<<endl;
                }
                break;
            }

            //Check out
            case 2:{
                string searchTitle;
                int match=0;
                cout<<"Enter title to checkout: ";
                cin.ignore();
                getline(cin,searchTitle);

                for(int i=0; i<count; i++){
                    if(toLower(libraryItems[i]->getTitle()) == toLower(searchTitle)){
                        libraryItems[i]->checkOut();
                        match = 1;
                     }
                }
                if(match!=1){
                    cout<<"========================  DATA NOT FOUND  ========================="<<endl<<endl;
                }
                break;
            }

            //Return them
            case 3:{
                string searchTitle;
                int match=0;
                cout<<"Enter title to return: ";
                cin.ignore();
                getline(cin,searchTitle);

                for(int i=0; i<count; i++){
                    if(toLower(libraryItems[i]->getTitle()) == toLower(searchTitle)){
                        libraryItems[i]->returnItem();
                        match = 1;
                     }
                }
                if(match!=1){
                    cout<<"========================  DATA NOT FOUND  ========================="<<endl<<endl;
                }
                break;
            }

            //Exit case
            case 4:{
                cout<<"===========================  THANK YOU  ==========================="<<endl<<endl;
                break;
            }

            //Default case
            default:{
                cout<<"=========================  INVALID CHOICE  ========================"<<endl<<endl;
                break;
            }
        }
    }
    while(choice!=4);

    //Free Memory Space
    for(int i = 0; i<count; i++){
        delete libraryItems[i];
    }

    return 0;
}