/*
Charles Baker, Programming Fundamentals I: COSC-1436-57001
IDE: Replit
Summary: 
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

  cout << "Start Data: ";
  s.printTranscript();
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

int main() {
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
}