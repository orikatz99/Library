#include <iostream>
#include <string>
using namespace std;

#include "Library.h"
#include "Ebook.h"
#include "Notebook.h"
#include "PhysicalBook.h"
#include "MemberEmployee.h"

enum eMenuOptions
{
    eAddBook, eAddMember, eAddEmployee, ePrintBooks, ePrintMembers, ePrintEmployees, ePrintMemberEmployees, ePrintLibary,
    eSortBooks, eLoanBook, eNofOptions
};

const std::string str[eNofOptions] = { "Add Book","Add Member", "Add Employee", "Print all books", "Print all members", "Print all employees"
                                     ,"Print all Member Employees", "Print libary", "Sort books",
                                      "Loan a book" };

#define EXIT -1

int menu();
Library* initLibrary();
void addBook(Library& library);
void addMember(Library& library);
void addEmployee(Library& library);
void addLoan(Loan& memberLoan, Library& library);
void addBookForLoan(Loan& memberLoan, Library& library);

int main()
{
    Library* lib = initLibrary();
    int option;

    bool stop = false;
    do
    {
        option = menu();
        switch (option)
        {
        case eAddBook:
            addBook(*lib);
            break;

        case eAddMember:
            addMember(*lib);
            break;

        case eAddEmployee:
            addEmployee(*lib);
            break;

        case ePrintBooks:
            lib->showBooks();
            break;

        case ePrintMembers:
            lib->showMembers();
            break;

        case ePrintEmployees:
            lib->getAdmin().showEmployees();
            break;

        case ePrintMemberEmployees:
            lib->showMemberEmployees();
                break;

        case ePrintLibary:
            lib->printLibrary();
            break;

        case eSortBooks:
        {
            int sortOption;
            cout << "Choose the attribute to sort by:" << endl;
            cout << "1 - Publication Year" << endl;
            cout << "2 - Copies Available" << endl;
            cout << "3 - Book Name" << endl;
            cin >> sortOption;

            switch (sortOption)
            {
            case 1:
                lib->sortBooksByPublicationYear();
                break;
            case 2:
                lib->sortBooksByCopiesAvailable();
                break;
            case 3:
                lib->sortBooksByBookName();
                break;
            default:
                cout << "Invalid option" << endl;
                break;
            }
            break;
        }

        case eLoanBook:
        {
            if (lib->getMemberCount() < 1)
            {
                cout << "There are no members in the library in order to loan a book" << endl;
                break;
            }
            lib->showMembers();
            Member* member = nullptr;
            char* numMem = new char[5];
            bool exists;
            do {
                exists = false;
                cout << "For which member would you like to make the loan? Write the member number" << endl;
                cin.getline(numMem, 5);
                // Checking if we have a member with this number
                for (int i = 0; i < lib->getMemberCount() && !exists; ++i)
                {
                    if (strcmp(lib->getMembers()[i].getMemNumber(), numMem) == 0)
                    {
                        member = lib->findMemByNum(numMem);
                        exists = true;
                    }
                }
                if (!exists)
                    cout << "There is no member with this number." << endl;

            } while (!exists);

            addLoan(*member->getLoanMember(), *lib);

            delete[] numMem;
            break;
        }

        case EXIT:
            std::cout << "Bye bye" << std::endl;
            stop = true;
            break;

        default:
            std::cout << "Wrong option" << std::endl;
            break;
        }
    } while (!stop);

    return 0;
}

int menu()
{
    int option;
    std::cout << "\n\n";
    std::cout << "Please choose one of the following options" << std::endl;
    for (int i = 0; i < eNofOptions; i++)
        std::cout << i << " - " << str[i] << std::endl;
    std::cout << EXIT << " - Quit" << std::endl;
    std::cin >> option;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clean buffer
    return option;
}

Library* initLibrary()
{
    char* libraryName = new char[100];
    char* adminName = new char[100];
    char* adminNumber = new char[20];

    cout << "Enter the name of the library: " << endl;
    cin.getline(libraryName, 100);

    cout << "Enter the administrator's name: " << endl;
    cin.getline(adminName, 100);

    cout << "Enter the administrator's member number: " << endl;
    cin.getline(adminNumber, 20);

    Employee adminEmployee(adminName, adminNumber);

    Administrator admin(adminEmployee);

    Library* library = new Library(libraryName, admin, nullptr, 0, nullptr, 0, nullptr, 0);

    delete[] libraryName;
    delete[] adminName;
    delete[] adminNumber;

    return library;
}

void addBook(Library& library)
{
    char* bookName = new char[20];
    cout << "\nEnter the book name: " << endl;
    cin.getline(bookName, 20);

    char* author = new char[30];
    cout << "Enter the book author: " << endl;
    cin.getline(author, 30);

    char* ISBN = new char[10];
    cout << "Enter the book ISBN: " << endl;
    cin.getline(ISBN, 10);
    for (int i = 0; i < library.getBookCount(); i++)
    {
        if (strcmp(library.getBooks()[i]->getISBN(), ISBN) == 0)
        {
            cout << "This book already exsist in the library " << endl;
            return;
        }
    }

    int publicationYear;
    bool valid = true;
    do
    {
        valid = true;
        std::cout << "Enter the book publication year (between 1 and 2024): ";
        std::cin >> publicationYear;

        if (publicationYear <= 0 || publicationYear > 2024) {
            std::cout << "Invalid year ";
            valid = false;
        }

    } while (!valid);


    int copiesAvailable;
    do
    {
        valid = true;
        std::cout << "Enter the book number of copies available: ";
        std::cin >> copiesAvailable;

        if (copiesAvailable < 0) {
            std::cout << "Invalid number ";
            valid = false;
        }

    } while (!valid);

    cin.ignore(); // To ignore the newline character left in the input buffer

    char* genre = new char[20];
    cout << "Enter the book genre: " << endl;
    cin.getline(genre, 20);

    int choice;

    cout << "\nPlease check what kind of book you would like to add : ";
    cout << "\nChoose 1 for Ebook, 2 for Physical Book, 3 for Notebook: ";

    bool stop = false;
    do {
        cin >> choice;
        switch (choice)
        {
        case 1: // Ebook
        {
            double fileSize;
            char* format = new char[30];

            do
            {
                valid = true;
                cout << "Enter book file Size: ";
                cin >> fileSize;

                if (fileSize < 0) {
                    std::cout << "Invalid number ";
                    valid = false;
                }

            } while (!valid);

            cin.ignore(); // To ignore the newline character left in the input buffer

            cout << "Enter book format: ";
            cin.getline(format, 30);

            Book* newBook = new Ebook(bookName, author, ISBN, publicationYear, copiesAvailable, genre, fileSize, format);
            library.addBook(newBook);
            delete[]format;
            stop = true;
            break;
        }
        case 2: // Physical Book
        {
            char* place = new char[30];
            cin.ignore();
            cout << "Enter the book place in the library: ";
            cin.getline(place, 30);

            Book* newBook = new PhysicalBook(bookName, author, ISBN, publicationYear, copiesAvailable, genre, place);
            library.addBook(newBook);
            delete[]place;
            stop = true;
            break;
        }

        case 3: //  Notebook
        {
            char* type = new char[10];
            cin.ignore();
            cout << "Enter the book type :" << endl;
            cin.getline(type, 10);

            Book* newBook = new Notebook(bookName, author, ISBN, publicationYear, copiesAvailable, genre, type);
            library.addBook(newBook);
            delete[]type;
            stop = true;
            break;
        }
        case EXIT:
            std::cout << "Bye bye" << std::endl;
            stop = true;
            break;

        default:
            cout << "Invalid choice" << endl;
            break;
        }
    } while (!stop);
    
    delete[]bookName;
    delete[]author;
    delete[]ISBN;
    delete[]genre;

}

void addMember(Library& library)
{
    char* memberName = new char[20];
    cout << "\nEnter the member name: " << endl;
    cin.getline(memberName, 20);

    char* memberNumber = new char[10];
    bool exists;
    do {
        exists = false;
        cout << "Enter the member number: " << endl;
        cin.getline(memberNumber, 10);
        // Checking if we have a member with this number
        for (int i = 0; i < library.getMemberCount() && !exists; ++i)
        {
            if (strcmp(library.getMembers()[i].getMemNumber(), memberNumber) == 0)
            {
                exists = true;
                printf("There is already a member with this number");
            }
        }
    } while (exists);

    char* phoneNumber = new char[11];
    cout << "Enter the member phone number: " << endl;
    cin.getline(phoneNumber, 11);

    Loan* memberLoan = nullptr;
    char answer;

    do
    {
        cout << "Do you want to loan books now? (y- for Yes , n- for No)" << endl;
        cin >> answer;
        cin.ignore(); // To ignore the newline character left in the input buffer

        if (answer == 'y')
        {
            memberLoan = new Loan();
            addLoan(*memberLoan, library);
        }
        else if (answer == 'n')
        {
            memberLoan = new Loan();
        }
        else
        {
            cout << "Invalid input entered" << endl;
        }
    } while (answer != 'y' && answer != 'n');

    if (memberLoan == nullptr) {
        memberLoan = new Loan();
    }

    Member newMember(memberName, memberNumber, phoneNumber, *memberLoan);
    library.addMember(newMember);

    // check if the new member is an employee in the library
    for (int i = 0; i < library.getAdmin().getEmployeeCount(); i++)
    {
        if (strcmp(library.getAdmin().getEmployeeArr()[i].getName(), newMember.getName()) == 0)
        {
            do
            {
                cout << "There is an Employee in our library with the same name, is it the same person? (y- for Yes , n- for No)" << endl;
                cin >> answer;
                cin.ignore();

                if (answer == 'y')
                {
                    Employee* emp = library.getAdmin().findEmployeeByName(library.getAdmin().getEmployeeArr(), library.getAdmin().getEmployeeCount(), newMember.getName());
                    MemberEmployee* memberEmployee = new MemberEmployee(newMember.getName(), newMember, *emp, 1);
                    library.addMemberEmployee(*memberEmployee);
                }
                else if (answer != 'n')
                {
                    cout << "Invalid input entered" << endl;
                }

            } while (answer != 'y' && answer != 'n');
        }
    }

    // Clean up dynamically allocated memory
    delete[] memberName;
    delete[] memberNumber;
    delete[] phoneNumber;
    delete memberLoan;
}

void addLoan(Loan& memberLoan, Library& library)
{
    if (library.getBookCount() <= 0)
    {
        printf("There are currently no books in the library, you can add books to the library using the main menu");
        return;
    }
    if (library.copyAvailable())
    {
        library.showBooks();
        addBookForLoan(memberLoan, library);
        char answer;
        do
        {
            cout << "Would you like to loan another book? (y- for Yes , n- for No)" << endl;
            cin >> answer;
            cin.ignore(); // To ignore the newline character left in the input buffer
            if (library.copyAvailable())
            {
                if (answer == 'y')
                    addBookForLoan(memberLoan, library);

                else if (answer != 'n')
                    cout << "Invalid input entered" << endl;
            }
            else
            {
                cout << "There are currently no books available to borrow" << endl;
                answer = 'n';
            }
        } while (answer != 'n');

        int day, month, year;
        bool correct;
        do {
            correct = true;
            cout << "When does the member have to return the books?" << endl;
            cout << "Enter a day (an Number): ";
            cin >> day;
            cout << "Enter a month (an Number): ";
            cin >> month;
            cout << "Enter a year: ";
            cin >> year;
            if (!memberLoan.getDate()->setYear(year) || !memberLoan.getDate()->setMonth(month) || !memberLoan.getDate()->setDay(day))
            {
                cout << "The date is incorrect " << endl;
                correct = false;
            }
        } while (!correct);
    }
    else
        cout << "There are currently no books available to borrow" << endl;
}

void addBookForLoan(Loan& memberLoan, Library& library)
{
    Book* thisBook = nullptr;
    char* bookName = new char[20];
    bool exists;
    do {
        exists = false;
        cout << "Which book do you want to borrow from the books in the library?: Choose the name of the book" << endl;
        cin.getline(bookName, 20);
        // Checks if there really is a book with this name in the library
        for (int i = 0; i < library.getBookCount() && !exists; ++i)
        {
            if (strcmp(library.getBooks()[i]->getBookName(), bookName) == 0)
            {
                // We will check if a copy is available
                if (library.getBooks()[i]->getCopiesAvailable() > 0)
                {
                    thisBook = Book::findBookByName(*library.getBooks(), library.getBookCount(), bookName);
                    library.getBooks()[i]->setCopiesAvailable(library.getBooks()[i]->getCopiesAvailable() - 1);
                    exists = true;
                }
            }
        }
        if (!exists)
            cout << "The book does not exist in the library or there is no available copy." << endl;
    } while (!exists);

    memberLoan.addBook(thisBook);
    delete[] bookName;
}

void addEmployee(Library& library)
{
    char* employeeName = new char[20];
    cout << "Enter the Employee name: " << endl;
    cin.getline(employeeName, 20);

    char* employeeNumber = new char[30];
    cout << "Enter the Employee number: " << endl;
    cin.getline(employeeNumber, 30);

    Employee newEmployee(employeeName, employeeNumber);
    library.getAdmin().addEmployee(newEmployee);

    char answer;
    // check if the new employee is a member in the library
    for (int i = 0; i < library.getMemberCount(); i++)
    {
        if (strcmp(newEmployee.getName(), library.getMembers()[i].getName()) == 0)
        {
            do
            {
              
                cout << "There is a Member in our library with the same name, is it the same person? (y- for Yes , n- for No)" << endl;
                cin >> answer;
                cin.ignore();
                if (answer == 'y')
                {
                    Member* member = library.findMemByName(newEmployee.getName());
                    MemberEmployee* memberEmployee = new MemberEmployee(newEmployee.getName(), *member, newEmployee, 1);
                    library.addMemberEmployee(*memberEmployee);
                }
                else if (answer != 'n')
                {
                    cout << "Invalid input entered" << endl;
                }

            } while (answer != 'y' && answer != 'n');
        }
    }

    // Clean up dynamically allocated memory
    delete[] employeeName;
    delete[] employeeNumber;
}



