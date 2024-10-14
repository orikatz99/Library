#ifndef EBOOK_H
#define EBOOK_H

#include "Book.h"

class Ebook : public Book
{

private:
	double fileSize;
	char* format;

public:
	Ebook(const char* bookName, const char* author, const char* ISBN, int publicationYear, int copiesAvailable, const char* genre, double fileSize, const char* format);
	Ebook(const Ebook& other);
	Ebook(Ebook&& other) noexcept;
	const Ebook& operator=(const Ebook& other);
	virtual ~Ebook();

	// Getters
	double getFileSize() const;
	const char* getFormat() const;

	// Setters
	bool setFormat(const char* format);

	void printBook() const override;

	// Override clone method
	virtual Ebook* clone() const override;
};

#endif // EBOOK_H