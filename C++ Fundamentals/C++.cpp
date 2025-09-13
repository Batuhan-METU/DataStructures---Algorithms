#include <iostream>
#include <string>

using namespace std; 
/*
int main()
{
    string ad = "Ahmet"; 
    cout << "Hello " << ad << endl; 
}
*/


/*
int main()
{
    string fruit = "apple"; 

    cout << "Length: " << fruit.length() << endl; 
    cout << "First Letter: " << fruit.at(0) << endl; 
    
    fruit.append(" juice"); 
    cout << "with append: " << fruit <<  endl; 

    return 0; 
}
*/


/*
int main()
{
    int n; 
    int sum = 0;  
    cout << "Please enter a number: "; 
    cin >> n; 
    
    int *p = new int[n]; 
    for (int i = 0; i<n; i++)
    {
        cin >> p[i]; 
    } 
    for (int i = 0; i<n; i++)
    {
        sum += p[i]; 
    }

    cout << "Sum: " << sum << endl; 
    delete []p; 
    
    return 0; 
}
*/

/*
struct Student
{
    int studentNo; 
    string name; 
    double average;     
};


int main()
{
    Student students[3]; 

    for (int i = 0; i<3; i++)
    {
        cout << i+1 << ". student no: "; 
        cin >> students[i].studentNo; 
        cin.ignore(); 

        cout << i+1 << ". student name: "; 
        getline(cin, students[i].name); 

        cout << i+1 << ". student average: "; 
        cin >> students[i].average; 
    }

    cout << "\n * Students List * *\n"; 
    for (int i = 0; i<3; i++){
        cout << students[i].studentNo << "  " << students[i].name << "  " << 
        students[i].average << endl; 
    } 
}
*/



/*
struct Student
{
    int studentNo; 
    string name; 
    double average;     
};

int main()
{
    int n; 

    cout << "How many students will registered ?"; 
    cin >> n; 
    cin.ignore(); 

    Student *students = new Student[n]; 

    for (int i = 0; i < n; i++)
    {
        cout << i+1 << ". StudentNo: "; 
        cin >> students[i].studentNo; 
        cin.ignore(); 

        cout << "Name: "; 
        getline(cin, students[i].name); 

        cout << "Average: "; 
        cin >> students[i].average; 
    }

    cout << "\nStudents Info\n"; 

    for (int i = 0; i<n; i++)
    {
        cout << students[i].studentNo << "  " << students[i].name << 
        "  " << students[i].average << endl; 
    }

    delete []students; 

    return 0; 
}
*/

/*
class Car {
    public: 
        string color; 
}; 

int main()
{
    Car car1; 
    Car car2, car3; 

    car1.color = "black"; 
    car2.color = "blue"; 
    car3.color = "yellow"; 

    cout << "car1 color: " << car1.color << endl; 
    cout << "car2 color: " << car2.color << endl; 
    cout << "car3 color: " << car3.color << endl; 

}
*/


//#include "car.cpp"
/*
int main()
{
    Car car1, car2; 
    car1.color = "Blue"; 
    car1.power = 90;
    car1.model = "Audi";

    car2.color = "Black";
    car2.power =  100; 
    car2.model = "Opel"; 

    car1.information(); 
    cout << endl << endl; 
    car2.information(); 
}
*/

/*
int main()
{
    Car car1("black", "Audi", 90,4); 
    car1.setCarColor("white"); 
    Car car2("blue", "Opel", 100,4); 

    //cout << *(car1.pDoorCount) << endl; 
    car1.information(); cout << endl; 

    Car *p; 
    p = new Car("yellow", "BMW", 125,2);


    p->information(); cout << endl; 
    cout <<"BMW Door Count: " << *(p->pDoorCount) << endl; 

    delete p; 

    return 0; 
}
*/

/*
#include "animal.hpp"
#include "cat.hpp"



int main()
{
    Cat tommy("Tommy"); 

    tommy.eat(); 
    tommy.sleep(); 
    tommy.CatchMouse(); 
    Cat john("John"); Cat mumi("Mumi"); 
    Cat *cat = new Cat("Tom"); 

    cout << "Cat Count =  " << Cat::getCatCount() << endl; 

    delete cat; 

    cout << "Cat Count =  " << Cat::getCatCount() << endl; 

    return 0; 
}
*/



/*

// BASE CLASS
class Animal {
    public: 
        virtual void makeSound() {
            cout << "Animal make sound method is called\n\n"; 
        }

        void print() {
            cout << "Base class print method is called\n"; 
        }
};

// CHILD CLASS
class Cat : public Animal {
    public: 
        void makeSound() {
            cout << "meow meow..\n"; 
        }
        void print() {
            cout << "Child class cat print method is called\n"; 
        }
};

// CHILD CLASS
class Dog : public Animal {
    public: 
        void makeSound() {
            cout << "hav hav..\n"; 
        }
        void print() {
            cout << "Child class dog print method is called\n"; 
        }
};


int main() {
    Animal *pAnimal; 
    Cat tom; 

    pAnimal = &tom; 
    //pAnimal->makeSound(); 
    //pAnimal -> print();
    
    Dog John; 
    pAnimal = &John; 
    pAnimal -> makeSound(); 
    pAnimal -> print(); 
    John.print(); 

    return 0; 
}

*/


/*
class Staff {
    private: 
        string staffType; 
        double salaryScaler; 
    public: 

        Staff(string staffType = "standard", double salaryScaler = 1.0) 
            : staffType(staffType), salaryScaler(salaryScaler) 
        {
            cout << "Initiliazer list usage\n"; 
        }
        void print() {
            cout << "Staff Type: " << staffType <<" || Salary Scaler: " << salaryScaler<< endl; 
        }
}; 


int main()
{
    Staff k1;
    k1.print(); 

    Staff k2("Senior", 1.5); 
    k2.print(); 
    return 0; 
}
*/


/*
struct BankAccount
{   
    private: 
        double balance; 
    public: 
        BankAccount(double initialBalance) {
            balance = initialBalance; 
            cout << "Account created\n"; 
        }
        ~BankAccount() {
            cout << "Account closed\n"; 
        }

        double getBalance() {
            return balance; 
        }

        void deposit(double amount) {
            balance += amount; 
        }

        void withdraw(double amount) {
            balance -=amount; 
        }
};

int main() {
    BankAccount myAccount(1000); 

    cout << "Current Balance: " << myAccount.getBalance() << endl; 

    myAccount.deposit(500); 
    cout << "After deposit current balance: " << myAccount.getBalance() << endl;

    myAccount.withdraw(300); 
    cout << "After withdraw current balance: " << myAccount.getBalance() << endl;

    return 0; 
}
*/

/*
int main()
{
    auto total = [](int a, int b) {return a + b; }; 

    int x = 5; 
    int y = 3; 

    int result = total(x,y); 

    cout << "result: " << result << endl; 

    return 0; 
}
*/

/*
template <typename T> 
class Square {
    private: 
        T edge; 
    public: 
        Square(T length) {
            edge = length; 
        }

        T area() {
            return edge * edge; 
        }

        void print() {
            cout << "Edge length: " << edge << endl; 
        }
}; 

int main()
{
    Square<int> k1(5); 
    Square<double> k2(4.5); 

    k1.print(); 
    cout << "k1 area: " << k1.area() << endl; 
    cout << "k2 area: " << k2.area() << endl; 

    return 0; 
}
*/


/*
#include <list> 

void printList(list<int> l) {
    list<int>::iterator itr; 

    for (itr = l.begin(); itr != l.end(); itr++) {
        cout << *itr << "  "; 
    }
    cout << endl; 
}


int main() {

    list<int> lst;  // 5-8
    lst.push_back(5); 
    lst.push_back(8); 
    lst.push_front(3); 
    printList(lst); 

    
    lst.pop_back(); 
    printList(lst); 

    lst.pop_front(); 
    printList(lst); 
    */
/*
    list<int>::iterator it;
    it = lst.begin();
    it++; 
    it++; 
    lst.insert(it, 9); 
    printList(lst); 

    it = lst.begin();
    it++; 
    lst.insert(it ,2 ,7); 
    printList(lst); 


    it = lst.begin(); 
    it++; it++; it++;  
    lst.erase(it); 
    printList(lst); 

    return 0; 
}
*/


#include <vector> 
/*
int main() {
    vector<int> vNumbers; 
    vNumbers.push_back(10); 
    vNumbers.push_back(20); 
    vNumbers.push_back(30); 

    cout << "Vector size: " << vNumbers.size() << endl; 

    for (size_t i = 0; i< vNumbers.size(); i++) {
        cout << "Element " << i << ": " << vNumbers.at(i) << endl; 
    }

    // vNumbers[1] = 42; 
    // cout << endl << vNumbers[1] << endl; 
    
    vector <string> vCars = {"Opel", "Audi", "BMW"}; 
    vCars.push_back("Seat"); 

    for (const string& car : vCars) {
        cout << car << endl; 
    }
    return 0; 
}
*/


/*
#include <map>

int main() {
    map<int, float> mStudentGrades; 

    mStudentGrades[101] = 85.5;
    mStudentGrades[102] = 90.3;
    mStudentGrades[100] = 78.8;

    mStudentGrades.insert({104, 92.4}); 

    cout << "\nStudent No and Grades\n"; 

    for (const auto& student : mStudentGrades) {
        cout << "Student No: " << student.first << ", Grades: " << student.second << endl; 
        
    }

    int searchingNo = 107; 
    if (mStudentGrades.find(searchingNo) != mStudentGrades.end()) {
        cout << "\n" << searchingNo << " grades of the student: " << mStudentGrades[searchingNo] << endl; 
    }
    else {
        cout << "\n" << searchingNo << " couldn't find in this map.\n"; 
    }
    return 0; 
}
*/

