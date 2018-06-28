#include <stdio.h>
#include <string.h>

typedef struct Books{
  char title[50];
  char author[50];
  char subject[100];
  int book_id;
} book_t;

void printBook(struct Books *book);

int main(){
  book_t Book1;  //Declare a variable using typedef
  struct Books Book2;  //Declare a variable without typedef

  strcpy(Book1.title, "Cross Justice");
  strcpy(Book1.author, "James Patterson");
  strcpy(Book1.subject, "Mystery");
  Book1.book_id = 6495407;

  strcpy(Book2.title, "Her Last Breath");
  strcpy(Book2.author, "Linda Castillo");
  strcpy(Book2.subject, "Mystery");
  Book2.book_id = 6495700;

  printBook(&Book1);
  printBook(&Book2);

  return 0;
}

void printBook(struct Books *book){
  printf("Book title: %s\n", book->title);
  printf("Book author: %s\n", book->author);
  printf("Book subject: %s\n", book->subject);
  printf("Book ID: %d\n\n", book->book_id);
}
