#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <cstring>

#include "Book.h"


// Default constructor
Book::Book() : bookName(nullptr), author(nullptr), ISBN(nullptr), publicationYear(0), copiesAvailable(0), genre(nullptr) {}

// Parameterized constructor
Book::Book(const char* bookName, const char* author, const char* ISBN, int publicationYear, int copiesAvailable, const char* genre)
{
    this->bookName = new char[strlen(bookName) + 1];
    strcpy(this->bookName, bookName);

    this->author = new char[strlen(author) + 1];
    strcpy(this->author, author);

    this->ISBN = new char[strlen(ISBN) + 1];
    strcpy(this->ISBN, ISBN);

    this->publicationYear = publicationYear;
    this->copiesAvailable = copiesAvailable;

    this->genre = new char[strlen(genre) + 1];
    strcpy(this->genre, genre);
}

// Copy constructor
Book::Book(const Book& other)
{
    bookName = new char[strlen(other.bookName) + 1];
    strcpy(bookName, other.bookName);

    author = new char[strlen(other.author) + 1];
    strcpy(author, other.author);

    ISBN = new char[strlen(other.ISBN) + 1];
    strcpy(ISBN, other.ISBN);

    publicationYear = other.publicationYear;
    copiesAvailable = other.copiesAvailable;

    genre = new char[strlen(other.genre) + 1];
    strcpy(genre, other.genre);
}

// Move constructor
Book::Book(Book&& other) noexcept
{
    bookName = other.bookName;
    author = other.author;
    ISBN = other.ISBN;
    publicationYear = other.publicationYear;
    copiesAvailable = other.copiesAvailable;
    genre = other.genre;

    other.bookName = nullptr;
    other.author = nullptr;
    other.ISBN = nullptr;
    other.genre = nullptr;
}

// assignment operator
const Book& Book::operator=(const Book& other)
{
    if (this != &other) {
        delete[] bookName;
        delete[] author;
        delete[] ISBN;
        delete[] genre;

        bookName = new char[strlen(other.bookName) + 1];
        strcpy(bookName, other.bookName);

        author = new char[strlen(other.author) + 1];
        strcpy(author, other.author);

        ISBN = new char[strlen(other.ISBN) + 1];
        strcpy(ISBN, other.ISBN);

        publicationYear = other.publicationYear;
        copiesAvailable = other.copiesAvailable;

        genre = new char[strlen(other.genre) + 1];
        strcpy(genre, other.genre);
    }
    return *this;
}

// Destructor
Book::~Book() {
    delete[] bookName;
    delete[] author;
    delete[] ISBN;
    delete[] genre;
}

// Getters
const char* Book::getBookName() const
{
    return bookName;
}
const char* Book::getAuthor() const
{
    return author;
}
const char* Book::getISBN() const
{
    return ISBN;
}
int Book::getPublicationYear() const
{
    return publicationYear;
}
int Book::getCopiesAvailable() const
{
    return copiesAvailable;
}
const char* Book::getGenre() const
{
    return genre;
}

// Setters
bool Book::setBookName(const char* newBookName)
{
    if (newBookName)
    {
        delete[] bookName;
        bookName = new char[strlen(newBookName) + 1];
        strcpy(bookName, newBookName);
        return true;
    }
    return false;
}
bool Book::setCopiesAvailable(int newCopiesAvailable)
{
    if (newCopiesAvailable >= 0)
    {
        copiesAvailable = newCopiesAvailable;
        return true;
    }
    return false;
}
bool Book::setGenre(const char* newGenre)
{
    if (newGenre)
    {
        delete[] genre;
        genre = new char[strlen(newGenre) + 1];
        strcpy(genre, newGenre);
        return true;
    }
    return false;
}

void Book::printBook() const
{
    std::cout << "Name: " << bookName << "\n" <<
        "Author: " << author << "\n" <<
        "ISBN: " << ISBN << "\n" <<
        "Year of publication: " << publicationYear << "\n" <<
        "Copies: " << copiesAvailable << "\n" <<
        "Genre: " << genre << std::endl;
}

Book* Book::findBookByName(Book* books, int count, const char* name)
{
    for (int i = 0; i < count; ++i)
    {
        if (strcmp(books[i].getBookName(), name) == 0)
        {
            return books[i].clone(); // Return a clone to avoid object slicing
        }
    }
    return nullptr;
}

