#ifndef BOOK_H
#define BOOK_H


class Book {//abstract 

protected:
	char* bookName;
	char* author;
	char* ISBN;
	int publicationYear;
	int copiesAvailable;
	char* genre;

public:
	Book(); // Default constructor
	Book(const char* bookName, const char* author, const char* ISBN, int publicationYear, int copiesAvailable, const char* genre);
	Book(const Book& other);
	Book(Book&& other) noexcept;
	const Book& operator=(const Book& other);
	virtual ~Book();

	// Getters
	const char* getBookName() const;
	const char* getAuthor() const;
	const char* getISBN() const;
	int getPublicationYear() const;
	int getCopiesAvailable() const;
	const char* getGenre() const;

	// Setters
	bool setBookName(const char* newBookName);
	bool setCopiesAvailable(int newCopiesAvailable);
	bool setGenre(const char* newGenre);

	virtual void printBook() const = 0;
	virtual Book* clone() const = 0;
	static Book* findBookByName(Book* books, int count, const char* name);

};

#endif // BOOK_H