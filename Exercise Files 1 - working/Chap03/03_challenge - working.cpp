// 02_challenge.cpp by Bill Weinman [bw.org]
// updated 2020-07-12
#include <cstdio>
#include <cstdint>


struct MyStructLibraryCard
{
	const char* title;
	const char* author;
	const char* publisher;
	const char* subject;
	const char* isbn;
	const char* oclc;
	float deweyDecimal;
	uint16_t yearPublished;
	uint16_t yearAcquired;
	uint16_t quantityInStock;
};

int main()
{

	MyStructLibraryCard libreriaA[6];
	libreriaA[0] = { "title1", "author1", "publisher1", "subject1", "isbn1", "oclc1", 1.1111, 1911,1912,1 };
	libreriaA[1] = { "title2", "author2", "publisher2", "subject2", "isbn2", "oclc2", 2.1111, 1921,1922,2 };
	libreriaA[2] = { "title3", "author3", "publisher3", "subject3", "isbn3", "oclc3", 3.1111, 1931,1932,3 };
	libreriaA[3] = { "title4", "author4", "publisher4", "subject4", "isbn4", "oclc4", 4.1111, 1941,1942,4 };
	libreriaA[4] = { "title5", "author5", "publisher5", "subject5", "isbn5", "oclc5", 5.1111, 1951,1952,5 };

	libreriaA[5].title = "title5";
	libreriaA[5].author="author5";
	libreriaA[5].publisher="publisher5";
	libreriaA[5].subject="subject5";
	libreriaA[5].isbn="isbn5";
	libreriaA[5].oclc="oclc5";
	libreriaA[5].deweyDecimal= 5.1111;
	libreriaA[5].yearPublished= 1951;
	libreriaA[5].yearAcquired= 1952;
	libreriaA[5].quantityInStock= 5;

	for (int i = 0; i < 6;i++) {
		printf("*****************************************\n");
		printf("title: %s\n", libreriaA[i].title);
		printf("author: %s\n", libreriaA[i].author);
		printf("publisher: %s\n", libreriaA[i].publisher);
		printf("subject: %s\n", libreriaA[i].subject);
		printf("isbn: %s\n", libreriaA[i].isbn);
		printf("oclc: %s\n", libreriaA[i].oclc);
		printf("deweyDecimal: %f\n", libreriaA[i].deweyDecimal);
		printf("yearPublished: %d\n", libreriaA[i].yearPublished);
		printf("yearAcquired: %d\n", libreriaA[i].yearAcquired);
		printf("quantityInStock: %d\n", libreriaA[i].quantityInStock);
	}



}
