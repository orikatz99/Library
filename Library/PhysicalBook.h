#ifndef PHYSICALBOOK_H
#define PHYSICALBOOK_H

#include "Book.h"

class PhysicalBook : public Book {

private:
	char* place;

public:
	PhysicalBook(const char* bookName, const char* author, const char* ISBN, int publicationYear, int copiesAvailable, const char* genre, const char* place);
	PhysicalBook(const PhysicalBook& other);
	PhysicalBook(PhysicalBook&& other) noexcept;
	const PhysicalBook& operator=(const PhysicalBook& other);
	virtual ~PhysicalBook();

	// Getters
	const char* getPlace()const;

	// Setters
	bool setPlace(const char* place);

	void printBook() const override;

	// Override clone method
	virtual PhysicalBook* clone() const override;
};

#endif // PHYSICALBOOK_H

