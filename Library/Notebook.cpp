#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <cstring>

#include "Notebook.h"

// Parameterized constructor
Notebook::Notebook(const char* bookName, const char* author, const char* ISBN, int publicationYear, int copiesAvailable, const char* genre, const char* type)
    : Book(bookName, author, ISBN, publicationYear, copiesAvailable, genre)
{
    this->type = new char[strlen(type) + 1];
    strcpy(this->type, type);
}

// Copy constructor
Notebook::Notebook(const Notebook& other) : Book(other)
{
    type = new char[strlen(other.type) + 1];
    strcpy(type, other.type);
}

// Move constructor
Notebook::Notebook(Notebook&& other) noexcept : Book(std::move(other))
{
    type = other.type;
    other.type = nullptr;
}

// assignment operator
const Notebook& Notebook::operator=(const Notebook& other)
{
    if (this != &other)
    {
        Book::operator=(other);

        delete[] type;
        type = new char[strlen(other.type) + 1];
        strcpy(type, other.type);
    }
    return *this;
}

// Destructor
Notebook::~Notebook()
{
    delete[] type;
}

// Getters
const char* Notebook::getType() const
{
    return type;
}

// Setters
bool Notebook::setType(const char* newType)
{
    if (newType)
    {
        delete[] type;
        type = new char[strlen(newType) + 1];
        strcpy(type, newType);
        return true;
    }
    return false;
}

// Implement the pure virtual function from Book
void Notebook::printBook() const
{
    Book::printBook();
    std::cout << "Type: " << type << std::endl;
}

Notebook* Notebook::clone() const
{
    return new Notebook(*this);
}