#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#include "Book.h"

class Notebook : public Book {

private:
	char* type;

public:
	Notebook(const char* bookName, const char* author, const char* ISBN, int publicationYear, int copiesAvailable, const char* genre, const char* type);
	Notebook(const Notebook& other);
	Notebook(Notebook&& other) noexcept;
	const Notebook& operator=(const Notebook& other);
	virtual ~Notebook();

	// Getters
	const char* getType()const;

	// Setters
	bool setType(const char* type);

	void printBook() const override;

	// Override clone method
	virtual Notebook* clone() const override;
};

#endif // NOTEBOOK_H