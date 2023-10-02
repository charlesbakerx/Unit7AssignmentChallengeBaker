/*
Charles Baker, Programming Fundamentals I: COSC-1436-57001
IDE: Replit
Summary: A program that declares a GreenTea and Student class as well as functions using instantiated objects to demonstrate OOP principles.
Note: Original code by Dr. Tyson McMillan
*/

/*
3-28-2018, 10-24-2019 Dr. Tyson McMillan
Working with class (object) Data Type and functions
private attributes (variables)
setter and getter MVC method
*/

#include <iostream>
#include <string>
using namespace std;

class GreenTea {
  private:
    bool delicious;
    string nameTea;
  public:
    void setDelicious(bool);
    bool getDelicious();
    void setNameTea(string);
    string getNameTea();
};

void GreenTea::setDelicious(bool d) {
  delicious = d;
}

bool GreenTea::getDelicious() {
  return delicious;
}

void GreenTea::setNameTea(string nt) {
  nameTea = nt;
}

string GreenTea::getNameTea() {
  return nameTea;
}

class Student {
  private:
    string name;
    int id;
    char letterGrade;
    GreenTea preference;
  public:
    void setName(string);
    void setId(int);
    void setLetterGrade(char);
    void setPreference(GreenTea);
    string getName();
    int getId();
    char getLetterGrade();
    GreenTea getPreference();
    void printTranscript();
};

void Student::setName(string n) {
  name = n;
}

void Student::setId(int i) {
  id = i;
}

void Student::setLetterGrade(char lg) {
  letterGrade = lg;
}

void Student::setPreference(GreenTea p) {
  preference = p;
}

string Student::getName() {
  return name;
}

int Student::getId() {
  return id;
}

char Student::getLetterGrade() {
  return letterGrade;
}

GreenTea Student::getPreference() {
  return preference;
}

void Student::printTranscript() {
  cout << "\nName: " << name;
  cout << "\nID: " << id;
  cout << "\nGrade: " << letterGrade;
  cout << "\nTea Name: " << preference.getNameTea();

  if (preference.getDelicious() == true) {
    cout << "\nWell said, McMillanite, " << preference.getNameTea() << ", green tea is great!!!" << endl;
  } else {
    cout << "\n :'(" << endl;
  }
}

void populateStudentWithDefaultData(Student &s) {
  GreenTea ut;
  ut.setNameTea("Matcha Green Tea - China");
  ut.setDelicious(true);

  s.setName("Charles Baker");
  s.setId(123456);
  s.setLetterGrade('F');
  s.setPreference(ut);

  // cout << "Start Data: ";
  // s.printTranscript();
}

void fnClass(Student student) {
  cout << "\nA pass by value object process (least effective):";
  char newGrade = '\0';
  // a function to pass a class by value
  cout << "\nINSIDE fnClass()" << endl;
  cout << "\t" << student.getId() << " : " << student.getName() << " earned a(n): " << student.getLetterGrade();
  // one can also change values in the function
  cout << "\nWhat would you like the new grade to be: ";
  cin >> newGrade;
  student.setLetterGrade(newGrade);
  cout << "\n\t" << student.getId() << " : " << student.getName() << " earned a(n): " << student.getLetterGrade();
  cout << "\nUPDATE TRANSCRIPT *** pass by value ***" << endl;
  student.printTranscript();
}

void fnClassRef(Student &student) {
  cout << "\nA pass by REFRENCE object process (Best method):";
  char newGrade = '\0';
  // a function to pass a class by reference
  cout << "\nINSIDE fnClassRef()" << endl;
  cout << "\t" << student.getId() << " : " << student.getName() << " earned a(n): " << student.getLetterGrade();
  // one can also change values in the function
  cout << "\nWhat would you like the new grade to be: ";
  cin >> newGrade;
  student.setLetterGrade(newGrade);
  cout << "\n\t" << student.getId() << " : " << student.getName() << " earned a(n): " << student.getLetterGrade();
  cout << "\nUPDATE TRANSCRIPT *** pass by references (&) ***" << endl;
  student.printTranscript();
}

void fnClassPtr(Student* student) {
  cout << "\nA pass by pointer * object process (Alternative method):";
  char newGrade = '\0';
  // a function to pass a class by pointer
  cout << "\nINSIDE fnClassPtr()" << endl;
  cout << "\t" << student->getId() << " : " << student->getName() << " earned a(n): " << student->getLetterGrade();
  // one can also change values in the function
  cout << "\nWhat would you like the new grade to be: ";
  cin >> newGrade;
  student->setLetterGrade(newGrade);
  cout << "\n\t" << student->getId() << " : " << student->getName() << " earned a(n): " << student->getLetterGrade();
  cout << "\nUPDATE TRANSCRIPT *** pass by pointer (*) ***" << endl;
  student->printTranscript();
}

// Menu Function
void printMenu() {
  cout << "0: Print this menu." << endl;
  cout << "1: Print undergraduate transcript" << endl;
  cout << "2: Print graduate transcript" << endl;
  cout << "3: Change undergraduate grade" << endl;
  cout << "4: Change graduate grade" << endl;
  cout << "5: Change undergraduate preference" << endl;
  cout << "6: Change graduate preference" << endl;
}

int main() {
  Student undergraduate;
  populateStudentWithDefaultData(undergraduate);
  GreenTea gt;
  gt.setNameTea("Sencha");
  gt.setDelicious(false);

  Student graduate;
  graduate.setId(1587);
  graduate.setName("Cool Dude");
  graduate.setLetterGrade('C');
  graduate.setPreference(gt);
  
  bool quit = false;
  int choice;
  char grade;
  string name;
  char delicious;
  printMenu();
  while(!quit) {
    cout << "Enter a choice: ";
    cin >> choice;
    switch (choice) {        
      case 0:
        printMenu();
        break;
      // Print undergraduate transcript
      case 1:
        undergraduate.printTranscript();
        break;
      // Print graduate transcript
      case 2:
        graduate.printTranscript();
        break;
      // Change undergraduate grade
      case 3:
        cout << "Enter the new letter grade: ";
        cin >> grade;
        undergraduate.setLetterGrade(toupper(grade));
        break;
      // Change graduate grade
      case 4:
        cout << "Enter the new letter grade: ";
        cin >> grade;
        graduate.setLetterGrade(toupper(grade));
        break;
      // Change undergraduate preference
      case 5:
        cout << "Enter the name of the green tea: ";
        /*
         This had me scratching my head for a while.
         Had to do some googling to figure out that cin >> var only reads until whitespace.
         The result was an infinite loop that took a little bit to figure out.
        */
        // We clear the input buffer
        cin.ignore();
        // We take the whole line and store it in name
        getline(cin, name);
        gt.setNameTea(name);
        while(true) {
          cout << "Is it delicious (y/n)? ";
          cin >> delicious;
          // If the answer isn't y/Y or n/N we repeat
          if (delicious != 'y' && delicious != 'Y' && delicious != 'n' && delicious != 'N') {
            cout << "Incorrect value, please enter y for yes or n for no!" << endl;
            continue;
          }
          // We got here because it was y/Y or n/N so we break out
          break;
        }
        // If delicious is y/Y we setDelicious to true else false
        gt.setDelicious(delicious == 'y' || delicious == 'Y' ? true : false);
        undergraduate.setPreference(gt);
        break;
      // Change graduate prefereance
      case 6:
        cout << "Enter the name of the green tea: ";
        // We clear the input buffer
        cin.ignore();
        // We take the whole line and store it in name
        getline(cin, name);
        gt.setNameTea(name);
        while(true) {
          cout << "Is it delicious (y/n)? ";
          cin >> delicious;
          // If the answer isn't y/Y or n/N we repeat
          if (delicious != 'y' && delicious != 'Y' && delicious != 'n' && delicious != 'N') {
            cout << "Incorrect value, please enter y for yes or n for no!" << endl;
            continue;
          }
          // We got here because it was y/Y or n/N so we break out
          break;
        }
        // If delicious is y/Y we setDelicious to true else false
        gt.setDelicious(delicious == 'y' || delicious == 'Y' ? true : false);
        graduate.setPreference(gt);
        break;
      default:
        cout << "Not a valid choice!" << endl;
        printMenu();
    }
  }
/* Testing code from main assignment
    
  cout << "\nPrint Undergraduate Student" << endl;
  // instances of the Student class
  Student undergraduate;
  // using a function to put initial data into the undergraduate object
  populateStudentWithDefaultData(undergraduate);

  // Populate graduate student with default Data in int main()
  GreenTea gt;
  gt.setNameTea("Sencha");
  gt.setDelicious(false);

  Student graduate;
  graduate.setId(1587);
  graduate.setName("Cool Dude");
  graduate.setLetterGrade('C');
  graduate.setPreference(gt);

  cout << "\nPrint Graduate Student" << endl;
  cout << "Start Data: ";
  graduate.printTranscript(); // call the print transcript function

  // ***************** Triple .dot notation accessing an object within an object *******************
  cout << "\nI say again..." << endl;
  if (graduate.getPreference().getDelicious()) {
    cout << "\nWell said, McMillanite, " << graduate.getPreference().getNameTea() << ", green tea is great!!!" << endl;
  } else {
    cout << "\n :'(" << endl;
  }

  // Passing object to functions, and using functions to print values in the object
  fnClass(undergraduate);
  fnClass(graduate);
  fnClassRef(undergraduate);
  fnClassRef(graduate);
  fnClassPtr(&undergraduate);
  fnClassPtr(&graduate);
*/
}