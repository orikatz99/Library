#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <cstring>

#include "PhysicalBook.h"

// Parameterized constructor
PhysicalBook::PhysicalBook(const char* bookName, const char* author, const char* ISBN, int publicationYear, int copiesAvailable, const char* genre, const char* place)
    : Book(bookName, author, ISBN, publicationYear, copiesAvailable, genre)
{
    this->place = new char[strlen(place) + 1];
    strcpy(this->place, place);
}

// Copy constructor
PhysicalBook::PhysicalBook(const PhysicalBook& other) : Book(other)
{
    place = new char[strlen(other.place) + 1];
    strcpy(place, other.place);
}

// Move constructor
PhysicalBook::PhysicalBook(PhysicalBook&& other) noexcept : Book(std::move(other))
{
    place = other.place;
    other.place = nullptr;
}

// assignment operator
const PhysicalBook& PhysicalBook::operator=(const PhysicalBook& other)
{
    if (this != &other)
    {
        Book::operator=(other);

        delete[] place;
        place = new char[strlen(other.place) + 1];
        strcpy(place, other.place);
    }
    return *this;
}

// Destructor
PhysicalBook::~PhysicalBook()
{
    delete[] place;
}

// Getters
const char* PhysicalBook::getPlace() const
{
    return place;
}

// Setters
bool PhysicalBook::setPlace(const char* newPlace)
{
    if (newPlace)
    {
        delete[] place;
        place = new char[strlen(newPlace) + 1];
        strcpy(place, newPlace);
        return true;
    }
    return false;
}


// Implement the pure virtual function from Book
void PhysicalBook::printBook() const
{
    Book::printBook();
    std::cout << "Book location: " << place << std::endl;
}

PhysicalBook* PhysicalBook::clone() const
{
    return new PhysicalBook(*this);
}