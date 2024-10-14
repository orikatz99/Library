#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <cstring>

#include "Ebook.h"

// Parameterized constructor
Ebook::Ebook(const char* bookName, const char* author, const char* ISBN, int publicationYear, int copiesAvailable, const char* genre, double fileSize, const char* format)
    : Book(bookName, author, ISBN, publicationYear, copiesAvailable, genre)

{
    this->fileSize = fileSize;

    this->format = new char[strlen(format) + 1];
    strcpy(this->format, format);
}

// Copy constructor
Ebook::Ebook(const Ebook& other) : Book(other)
{
    fileSize = other.fileSize;

    format = new char[strlen(other.format) + 1];
    strcpy(format, other.format);
}

// Move constructor
Ebook::Ebook(Ebook&& other) noexcept : Book(std::move(other))
{
    fileSize = other.fileSize;
    format = other.format;

    other.format = nullptr;
}

// assignment operator
const Ebook& Ebook::operator=(const Ebook& other)
{
    if (this != &other)
    {
        Book::operator=(other);
        fileSize = other.fileSize;

        delete[] format;
        format = new char[strlen(other.format) + 1];
        strcpy(format, other.format);
    }
    return *this;
}

// Destructor
Ebook::~Ebook()
{
    delete[] format;
}

// Getters
double Ebook::getFileSize() const
{
    return fileSize;
}
const char* Ebook::getFormat() const
{
    return format;
}

// Setter
bool Ebook::setFormat(const char* newFormat)
{
    if (newFormat)
    {
        delete[] format;
        format = new char[strlen(newFormat) + 1];
        strcpy(format, newFormat);
        return true;
    }
    return false;
}

// Implement the pure virtual function from Book
void Ebook::printBook() const
{

    Book::printBook();
    std::cout << "File Size: " << fileSize << "\n" << "Format: " << format << std::endl;
}

Ebook* Ebook::clone() const
{
    return new Ebook(*this);
}