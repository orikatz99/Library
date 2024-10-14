#ifndef LOAN_H
#define LOAN_H

#include "Book.h"
#include "Date.h"

class Loan {

protected:
	Book** bookArr;//an array of the books loaned
	int numOfBook;
	Date* date;//The date the loan ends

public:
	// Constructors
	Loan(); // Default Constructor
	Loan(Book** bookArr, int numOfBook, Date& date);
	Loan(const Loan& other);        // Copy Constructor
	Loan(Loan&& other) noexcept;             // Move Constructor
	virtual ~Loan();                             // Destructor

	void operator=(const Loan& other);

	// Getters
	Book** getBookArr() const;
	int getNumOfBook() const;
	Date* getDate() const;


	// Setters
	bool setBookArr(Book** bookArr);
	bool setNumOfBook(int numOfBook);
	bool setDate(Date& date);

	bool addBook(Book* newBook);

	void printBookArr() const;
	void printLoan() const;

};

#endif // LOAN_H