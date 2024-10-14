#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <cstring>

#include "Loan.h"

// Constructor
Loan::Loan() : bookArr(nullptr), numOfBook(0), date(new Date()){}

Loan::Loan(Book** bookArr, int numOfBook, Date& date)
{
    this->bookArr = new Book * [numOfBook];
    for (int i = 0; i < numOfBook; ++i) {
        this->bookArr[i] = bookArr[i]->clone();
    }

    this->numOfBook = numOfBook;
    this->date = new Date(date);
}

// Copy Constructor
Loan::Loan(const Loan& other)
{
    numOfBook = other.numOfBook;
    bookArr = new Book * [numOfBook];
    for (int i = 0; i < numOfBook; ++i) {
        this->bookArr[i] = other.bookArr[i]->clone();
    }

    date = new Date(*other.date);
}

// Move Constructor
Loan::Loan(Loan&& other) noexcept
{
    bookArr = other.bookArr;
    numOfBook = other.numOfBook;
    date = other.date;

    other.bookArr = nullptr;
    other.numOfBook = 0;
    other.date = nullptr;
}

// Destructor
Loan::~Loan()
{
    for (int i = 0; i < numOfBook; ++i)
    {
        delete bookArr[i];
    }
    delete[] bookArr;
    delete date;
}

// Assignment Operator
void Loan::operator=(const Loan& other)
{
    if (this == &other)
        return;

    for (int i = 0; i < numOfBook; ++i)
    {
        delete bookArr[i];
    }
    delete[] bookArr;
    delete date;

    numOfBook = other.numOfBook;
    bookArr = new Book * [numOfBook];
    for (int i = 0; i < numOfBook; ++i)
    {
        bookArr[i] = other.bookArr[i]->clone();
    }

    date = new Date(*other.date);
}

// Getters
Book** Loan::getBookArr() const
{
    return bookArr;
}
int Loan::getNumOfBook() const
{
    return numOfBook;
}
Date* Loan::getDate() const
{
    return date;
}

// Setters
bool Loan::setBookArr(Book** bookArr)
{
    if (bookArr == nullptr)
        return false;

    delete[] this->bookArr;
    this->bookArr = new Book * [numOfBook];
    for (int i = 0; i < numOfBook; ++i)
    {
        this->bookArr[i] = bookArr[i]->clone();
    }
    return true;
}
bool Loan::setNumOfBook(int numOfBook)
{
    if (numOfBook <= 0)
        return false;

    this->numOfBook = numOfBook;
    return true;
}
bool Loan::setDate(Date& date)
{
    this->date = &date;
    return true;
}

void Loan::printBookArr() const
{
    for (int i = 0; i < numOfBook; i++)
    {
        bookArr[i]->printBook();
        if(i+1 != numOfBook)
            cout << "\n";
    }
}
void Loan::printLoan() const
{
    cout << "The loaned books are: " << endl;
    printBookArr();
    cout << "The end date of the loan: ";
    date->printDate();
}

bool Loan::addBook(Book* newBook)
{
    if (newBook == nullptr)
        return false;

    Book** newBookArr = new Book * [numOfBook + 1];
    for (int i = 0; i < numOfBook; ++i)
    {
        newBookArr[i] = bookArr[i];
    }
    newBookArr[numOfBook] = newBook->clone();

    delete[] bookArr;
    bookArr = newBookArr;
    ++numOfBook;

    return true;
}
