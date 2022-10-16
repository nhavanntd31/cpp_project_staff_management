#include <bits/stdc++.h>
#include <vector>
using namespace std;
// Ma Khoa Hoc
class Staff
{
private:
        string FullName;
        string StaffID;
        string PhoneNumber;
        string YearStart;
        int BasicSalary;
public:
    Staff(){
        FullName = "";
        StaffID = "";
        PhoneNumber = "";
        YearStart = "";
        BasicSalary= 0;
    }
    virtual void getInformation();
    virtual void printInformation();
    virtual int FinalSalary(){};
    virtual void editInformation();
    friend class Programmer;
    friend class Tester;
    friend class Menu;
}; 
//the method to enter the information of staff
void Staff :: getInformation(){       
    fflush(stdin);                                                             
    cout << "Full name: ";
    getline(cin , FullName);                                                    
    cout << "Staff ID: ";
    cin >> StaffID;
    cout << "Phone number: ";
    cin >> PhoneNumber;
    cout << "Year start working: "; 
    cin >> YearStart;
    cout << "Basic salary: " ;
    cin >> BasicSalary;
}
//method that prints on the screen the information of staff
void Staff :: printInformation(){ 
    cout << "Full name: " << FullName << endl;
    cout << "Staff Id: " << StaffID<< endl;
    cout << "Phone number: " << PhoneNumber << endl;
    cout << "Year start working: "<<YearStart << endl;
    cout << "Basic salary: " << BasicSalary << endl;
}
//the method to choose the information that need editing
void Staff :: editInformation(){ 
        system("cls");
        cout << "What do you want to edit? " << endl; 
        cout << "0. Exit. " << endl;
        cout << "1. Full name. " <<endl;
        cout << "2. Staff ID. " << endl;
        cout << "3. Phone number. " << endl;
        cout << "4. Year start working. " << endl;
        cout << "5. Basic salary. " << endl;
}
// Nguyen Duc Phuc Hoang 
class Programmer : public Staff   //inheritance attributes and method from Staff class in public type
{
private:
    int OvertimeHour;
public : 
    Programmer(){
        OvertimeHour=0;
    }
    void getInformation();
    void printInformation();
    int FinalSalary();
    void editInformation();
};  
    //the method to enter the information of programmer
    void Programmer :: getInformation(){  // ham nhap vao cac thong tin cua programmer
        cout << "Programmer" << endl;
        Staff :: getInformation();     
        cout << "Overtime hours: "; 
        cin >> OvertimeHour;
    }
    //method that prints on the screen the information of programmer
    void Programmer :: printInformation(){
        cout << "-----Programmer-----" << endl;
        Staff :: printInformation();   
        cout << "Overtime hours: " << OvertimeHour << endl;
        cout << "Final Salary: " << FinalSalary() << endl;
    }
    //the method calculates the salary of programmer in the month
    int Programmer :: FinalSalary(){ 
        int FinalSalaryPro;
        FinalSalaryPro = BasicSalary + OvertimeHour * 200000; 
        return FinalSalaryPro;
    }
    //the method to edit the information of programmer
    void Programmer :: editInformation(){
        int editchoice; 
        do
        {  fflush(stdin);
            Staff :: editInformation();
            cout << "6. Overtime hours. " << endl;
            cin >> editchoice;
            switch (editchoice)
            {
            case 1:
                fflush(stdin);
                cout << "New name : ";
                getline(cin,FullName);
                break;
            case 2:
                cout << "New Staff ID : ";
                cin >> StaffID;
                break;
            case 3:
                cout << "New phone number : " ;
                cin >> PhoneNumber;
                break;
            case 4:
                cout << "New starting year : ";
                cin >> YearStart;
                break;
            case 5:
                cout << "New basic salary : ";
                cin >> BasicSalary;
                break;
            case 6:
                cout << "New overtime hour : ";
                cin >> OvertimeHour;
                break; 
            case 0:
                break;
            default:
            cout << "Wrong choice, again !";
            system("pause");    
            }
        } while (editchoice != 0);
    }
// Phung Mac Quan 
class Tester : public Staff     //inheritance attributes and method from Staff class in public type
{
private:
    int BugFixed;
public:
    Tester(){
        BugFixed =0;
    };
    void getInformation();
    void printInformation();
    int FinalSalary();
    void editInformation();
};  
    // the method to enter the information of tester
    void Tester :: getInformation(){
        cout << "Tester" << endl;
        Staff :: getInformation();
        fflush(stdin);
        cout << "Number of bug fixed: " ;
        cin >> BugFixed;
    }
    //The method that prints on the screen the information of tester
    void Tester :: printInformation(){
        cout << "-----Tester-----" << endl;
        Staff :: printInformation();
        cout << "Number of bug fixed: " << BugFixed <<endl;
        cout << "Final Salary: " << FinalSalary() << endl;
    }
    //the method calculates the salary of tester in the month
    int Tester :: FinalSalary(){
        int FinalSalaryTes;
        FinalSalaryTes = BasicSalary + BugFixed * 20000;
        return FinalSalaryTes;
    }
    //The method to edit tester's information
    void Tester :: editInformation(){
        
        int editchoice;
        do
        {
            Staff :: editInformation();
            cout << "6. Bug fixed. " << endl;
            cin >> editchoice;
            switch (editchoice)
            {
            case 1:
                fflush(stdin);
                cout << "New name : ";
                getline(cin,FullName);
                break;
            case 2:
                cout << "New Staff ID : ";
                cin >> StaffID;
                break;
            case 3:
                cout << "New phone number : " ;
                cin >> PhoneNumber;
                break;
            case 4:
                cout << "New starting year : ";
                cin >> YearStart;
                break;
            case 5:
                cout << "New basic salary : ";
                cin >> BasicSalary;
                break;
            case 6:
                cout << "New fixed bug : ";
                cin >> BugFixed; 
                break;
            case 0:
                break;
            default:
            cout << "Wrong choice, again !";
            system("pause");    
            }
        } while (editchoice != 0);    
    }
// Nguyen Tien Dat : private attributes, getStaffListSize, EnterList, PrintList, EditStaff, RemoveStaff.
// Nguyen Duc Phuc Hoang : CalculateAverageSalary, StatisticSalary. 
// Phung Mac Quan : SearchStaff. 
class Menu
{
private:
    vector<Staff*> StaffList; 
public:
    void EnterList();
    void PrintList();
    void EditStaff();
    void RemoveStaff();
    void SearchStaff();
    long CalculateAverageSalary();
    void StatisticSalary();
    int getStaffListSize();
};
    //The method to get the number of employees have been saved
    int Menu :: getStaffListSize(){
        return StaffList.size();
    }
    //The method selects the object to be entered, enters the information, and stores the information in memory
    void Menu :: EnterList(){
        Staff* stf;
        int choice;
        do
        {   
            system("cls");
            cout << "1. Programmer. " << endl;
            cout << "2. Tester. " << endl;
            cout << "0. Exit. " << endl;
            cout << "Your choice? " << endl;
            cin >> choice;
            switch (choice)
            {
            case 1:
                system("cls");
                stf = new Programmer();
                stf->getInformation();
                StaffList.push_back(stf);
                break;
            case 2:
                system("cls");
                stf = new Tester();
                stf->getInformation();
                StaffList.push_back(stf);
                break;
            case 0 :
                break;
            default:
            cout << "Wrong choice, again !";
            system("pause");    
            } 
        } while (choice != 0 );
    }
    //The method that prints the information of all employees on the screen
    void Menu :: PrintList(){
        for (int i=0;i< StaffList.size();i++)
        {
            StaffList[i] ->printInformation();
            cout << "========" << i+1 << "/" << StaffList.size() <<"========" << endl;
        }    
    }
    //The method to enter the position to edit and edit employee information 
    void Menu :: EditStaff(){     
            int editpos;
            cout << "What position of employee do you want to edit from the list ? " << endl;
            cin >> editpos;
            while (editpos > getStaffListSize())
            {
                cout << " Re-enter position: " << endl;
                cin >> editpos;
            }            
            StaffList[editpos -1]->editInformation();
    }
    //The method to enter the position to be removed and remove the employee's information in that position
    void Menu :: RemoveStaff(){
        int removepos;
        cout << "What position of employee do you want to remove from the list ? " << endl;
        cin >> removepos;
        while ( removepos > getStaffListSize())
        {
            cout << "Re-enter position: " << endl;
            cin >> removepos;
        }
        
       /* Another way 
        for (int  i = removepos-1; i < StaffList.size() ; i++)
        {
            StaffList[i] = StaffList[i+1];
        }
        StaffList.resize(StaffList.size()-1); */
        StaffList.erase(StaffList.begin() + removepos - 1);
    }
    //The method that searches and prints out all the information of the employees by using a known information
    void Menu :: SearchStaff(){
        int searchchoice;
        
        do
        {   system("cls");
            cout << "1. Search by name. " << endl;
            cout << "2. Search by staff id. " << endl;
            cout << "3. Search by phone number. " <<endl;
            cout << "4. Search by starting year. " << endl;
            cout << "0. Exit. " << endl;
            cout << "Your choice? " << endl;
            cin >> searchchoice;
            switch (searchchoice)
            {
            //search by name 
            case 1: 
            {   
                string searchname;
                fflush(stdin);
                cout << "Enter name: " ;
                getline(cin,searchname);
                int count=0;
                system("cls");
                for (int i=0; i<StaffList.size();i++)
                {
                    if ((StaffList[i]->FullName).find(searchname) != -1 )
                    {
                        StaffList[i]->printInformation();
                        cout << "Position : " << ++count << endl ;
                    }
                }
                cout <<"===============" << endl << "Total : " << count << endl;
                system("pause");
                break;
            }
            //search by id    
            case 2:
            {    
                string searchid;
                cout << "Enter ID: " ;
                cin >> searchid;
                int count=0;
                system("cls");
                for (int i=0; i<StaffList.size();i++)
                {
                    if ((StaffList[i]->StaffID).find(searchid) != -1 )
                    {
                        StaffList[i]->printInformation();
                        cout << "Position : " << ++count << endl ;
                    }
                }
                cout <<"===============" << endl << "Total : " << count << endl;
                system("pause");
                break;
            }  
            //search by phonenumber  
            case 3:
            {
                string searchphone;
                cout << "Enter phone number : " ;
                cin >> searchphone;
                int count=0;
                system("cls");
                for (int i=0; i<StaffList.size();i++)
                {
                    if ((StaffList[i]->PhoneNumber).find(searchphone) != -1 )
                    {
                        StaffList[i]->printInformation();
                        cout << "Position : " << ++count << endl ;
                    }
                }
                cout <<"===============" << endl << "Total : " << count << endl;
                system("pause");
                break;
            }    
            //search by year start working
            case 4:
            { 
                string searchyear;
                cout << "Enter year: " ;
                cin >> searchyear;
                int count=0;
                system("cls");
                for (int i=0; i<StaffList.size();i++)
                {
                    if ((StaffList[i]->YearStart).find(searchyear) != -1 )
                    {
                        StaffList[i]->printInformation();
                        cout << "Position : " << ++count << endl ;
                    }
                }
                cout <<"===============" << endl << "Total : " << count << endl;
                system("pause");
                break;
            }    
            case 0:
                break;
            default:
            cout << "Wrong choice, again !";
            system("pause");  
            }
            
        } while (searchchoice != 0);
        
    }
    //The method that calculates the average salary of all employees
    long Menu :: CalculateAverageSalary(){
        long AverageSalary=0;
        for (int i=0;i <StaffList.size();i++)
        {
            AverageSalary += StaffList[i]->FinalSalary();
        }
        AverageSalary /= StaffList.size(); 
        return AverageSalary;
    }
    //The method that prints the information of the employees whose salary is less than the average salary
    void Menu :: StatisticSalary(){
        cout << "Employees whose monthly salary is lower than the average salary of employees in the company" << endl;
        for (int i=0;i< StaffList.size();i++)
        {
            if (StaffList[i]->FinalSalary() <= CalculateAverageSalary() )
            {
                StaffList[i]->printInformation();
            }
        }
        system("pause");
    }
// Ma Khoa Hoc, Nguyen Tien Dat 
int main(){
    int choice;
    Menu menu1;
    // Choose function that you want to do. 
    do
    {
        system("cls");
        cout << " ==================== Management of  programming  company employees ====================" << endl << endl;
        cout << "1. Add staff. " <<endl;
        cout << "2. Print staff list. " << endl;
        cout << "3. Edit staff information. " <<endl;
        cout << "4. Remove staff information. " <<endl;
        cout << "5. Search staff information. " << endl;
        cout << "6. Calculate average salary. " << endl;
        cout << "7. Statistics of employees. " << endl;
        cout << "0. Exit." << endl;
        cout << "Your choice ?"<<endl ;
        cin >> choice;
        switch (choice)
        {
        case 1:
            menu1.EnterList();
            break;
        case 2:
            system("cls");          
            if (menu1.getStaffListSize() == 0 )
            {
                cout << "Need more information. " << endl;
                system("pause");
                break;
            }
            menu1.PrintList();
            system("pause");
            break;
        case 3:
            system("cls");
            if (menu1.getStaffListSize() == 0 )
            {
                cout << "Need more information. " << endl;
                system("pause");
                break;
            }
            menu1.EditStaff();
            break;
        case 4:
            system("cls");
            if (menu1.getStaffListSize() == 0 )
            {
                cout << "Need more information. " << endl;
                system("pause");
                break;
            }
            menu1.RemoveStaff();
            break;
        case 5:
            system("cls");
            if (menu1.getStaffListSize() == 0 )
            {
                cout << "Need more information. " << endl;
                system("pause");
                break;
            }
            menu1.SearchStaff();
            break;
        case 6:
            system("cls");
            if (menu1.getStaffListSize() == 0) 
            {
                cout << "Need more information. " << endl;
                system("pause");
                break;
            }
            cout << "Average salary : " << menu1.CalculateAverageSalary() << endl;
            system("pause");
            break;
        case 7:
            system("cls");
            if (menu1.getStaffListSize() == 0)
            {
                cout << "Need more information. " << endl;
                system("pause");
                break;
            }
            menu1.StatisticSalary();
            break;
        case 0: 
            break;
        default:
            cout << "Wrong choice, again !";
            system("pause");            
        }
    } while (choice != 0);
    return 0;
}
