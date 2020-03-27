#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <fstream>
using namespace std;



class Human
{
protected:
    string name;
    string patronymic;
    string surname;
    string nationality; 
    string dateOfBirth;
public:
    string getName() { return name; }
    string getPatronymic() { return patronymic; }
    string getSurname() { return surname; }
    string getNationality() { return nationality; }
    string getDateOfBirth() { return dateOfBirth; }
    void setName(string name) { this->name = name; }
    void setLastName(string lastName) { this->patronymic = lastName; }
    void setSurname(string surname) { this->surname = surname; }
    void setNationality(string nationality) { this->nationality = nationality; }
    void setDateOfBitth(string dateOfBirth) { this->dateOfBirth = dateOfBirth; }
    
    friend istream& operator >> (istream& s, Human& d);
    friend ostream& operator << (ostream& s, Human& d);

    Human(string name="null", string surname = "null", string patronymic = "null",  string nationality = "null", string dateOfbirth = "null")
    {
        setName(name);
        setLastName(patronymic);
        setSurname(surname);
        setNationality(nationality);
        setDateOfBitth(dateOfbirth);
    }

    virtual void write()
    {
        ofstream ouf;
        ouf.open("test1.dat", ios::trunc | ios::binary);
        if (!ouf)
        {
            cout << "cannot open";
            return;
        }

    }

    void enter_inf()
    {
        cout << "Name: "; cin >> name;
        cout << "\nSurname: "; cin >> surname;
        cout << "\nPatronymic: "; cin >> patronymic;
        cout << "\nNationality: "; cin >> nationality;
        cout << "\nDate of birth: "; cin >> dateOfBirth;
    }

    virtual void print() 
    {
        cout <<"\nName: "<< getName() <<"\nSurname: "<< getSurname() <<"\nPatronymic: "<< getPatronymic() 
            <<"\nNationaly"<< getNationality() <<"\nDate of birth:"<< getDateOfBirth() << endl;
    }
};

istream& operator >> (istream& s, Human& d)
{
   // cout << "Name: "; 
    //cout << "Surname: "; 
   // cout << "Patronymic: "; 
    //cout << "Natyonality: "; 
   // cout << "Date of birh: "; 
    s >> d.name >> d.surname >> d.patronymic >> d.nationality >> d.dateOfBirth;
    return s;
}

ostream& operator << (ostream& s, Human& d)
{
    s << d.name << " " << d.surname  << " " << d.patronymic << " " << d.nationality << " " << d.dateOfBirth;
    return s;
}


class Citizen : public Human
{
private:
    
    int numberDocument;
    string dateOfExpiry;
public:
    Human h;
    static string typeOfDocument;
    void setNumberDocument(int numberDocument) { this->numberDocument = numberDocument; }
    void setDateOfExipiry(string dateOfExpiry) { this->dateOfExpiry = dateOfExpiry; }
    int getNumberDocument() { return numberDocument; }
    string getDateOfExpiry() { return dateOfExpiry; }
    string getTypeOfDocument() { return typeOfDocument; }

    Citizen(string name = "null",  string surname = "null",string patronymic = "null",
        string nationality = "null", string dateOfbirth = "null", int numberDocument=0,
        string dateOfExpiry = "null") :Human(name,surname,patronymic,nationality,dateOfbirth)
    {
        setNumberDocument(numberDocument);
        setDateOfExipiry(dateOfExpiry);
    }



    virtual void print() override
    {
        cout << "Name: " << getName() << "\nSurname: " << getSurname() << "\nPatronymic: " << getPatronymic()
            << "\nNationaly: " << getNationality() << "\nDate of birth: " << getDateOfBirth() << "\nType of document: " << getTypeOfDocument()
            << "\nDoucument Number: " << getNumberDocument() << "\nDate of expiry: " << getDateOfExpiry() << endl;
    }
};
string Citizen::typeOfDocument = "Паспорт";


class TemporaryCitizen : public Human
{
private:
    int numberDocument;
    static string typeOfDocument;
    string dateOfExpiry;
public:
    void setNumberDocument(int numberDocument) { this->numberDocument = numberDocument; }
    void setDateOfExipiry(string dateOfExpiry) { this->dateOfExpiry = dateOfExpiry; }
    int getNumberDocument() { return numberDocument; }
    string getDateOfExpiry() { return dateOfExpiry; }
    string getTypeOfDocument() { return typeOfDocument; }

    TemporaryCitizen(string name = "null", string surname = "null", string patronymic = "null",
        string nationality = "null", string dateOfbirth = "null", int numberDocument = 0,
        string dateOfExpiry = "null") :Human(name, surname, patronymic, nationality, dateOfbirth)
    {
        setNumberDocument(numberDocument);
        setDateOfExipiry(dateOfExpiry);
    }


    virtual void print() override
    {
        cout << "Name: " << getName() << "\nSurname: " << getSurname() << "\nPatronymic: " << getPatronymic()
            << "\nNationaly: " << getNationality() << "\nDate of birth: " << getDateOfBirth() << "\nType of document: " << getTypeOfDocument()
            << "\nDoucument Number: " << getNumberDocument() << "\nDate of expiry: " << getDateOfExpiry() << endl;
    }

};


string TemporaryCitizen::typeOfDocument = "Тимчасове громадянство";


void print_menu() {
    system("cls"); // очищаем экран
    cout << "What do you want to do?" << endl;
    cout << "1. додати громадянина" << endl;
    cout << "2. додати тимчасового громадянина" << endl;
    cout << "3. переглянути громадян" << endl;
    cout << "4. переглянути тимчасових громадян" << endl;
    cout << "5. Exit" << endl;
    cout << ">";
}
int get_variant(int count) {
    int variant;
    cin >> variant;
    if (variant > count)
    {
        cerr << "Error\n";
        return 0;
    }
    return variant;
}

int main()
{
    system("chcp 1251>nul");
    int variant;
    Citizen citizen;
    Human human;
   // Citizen citizen("Name", "LastName", "Surname", "Nationality", "DateOfBirth", 1, "DateOfExpiry");
   // TemporaryCitizen tcitizen("Name", "LastName", "Surname", "Nationality", "DateOfBirth", 1, "DateOfExpiry");
    do {
        print_menu(); // выводим меню на экран
        char ch;
        variant = get_variant(5); // получаем номер выбранного пункта меню
        ofstream ofile;
        ifstream ifile;
        Citizen c;
        switch (variant) {
        case 1:
            ofile.open("Test1.txt", ofstream::app);
            do
            {
                cin >> citizen;
                ofile.write((char*)&citizen, sizeof(Citizen));
                cout << "continue(y/n)?";
                ofile.close();
                cin >> ch;
            } while (ch != 'n');
            break;

        case 2:
           
            break;

        case 3:
            ifile.open("Test1.txt");
           
            cout << "if file:\n";
            while (true)
            {
                ifile.read((char*)&c, sizeof(Citizen));//cout << "Citizen: \n" << citizen << endl;
                c.print();
            }
            ifile.close();
            break;

        case 4:
            citizen.print();
            break;
        }

        if (variant != 5)
            system("pause"); // задерживаем выполнение, чтобы пользователь мог увидеть результат выполнения выбранного пункта
    } while (variant != 5);
    return 0;
}