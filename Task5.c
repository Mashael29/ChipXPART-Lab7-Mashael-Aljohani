#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the Book structure
typedef struct {
    int bookID;
    char title[100];
    char author[50];
    int year;
    float price;
} Book;


Book books[100]; //array to store books
int N = 0; // variable to track the number of books

//function to load book data from file
void loadBookData() {
    FILE *file = fopen("books.dat", "rb");
    if (file != NULL) {
        //read existing book data into the array
        while (fread(&books[N], sizeof(Book), 1, file)) {
            N++;
        }
        fclose(file);
    }
}

//function to save book data to file
void saveBookData() {
    FILE *file = fopen("books.dat", "wb");
    if (file != NULL) {
        // Write the book data to the file
        fwrite(books, sizeof(Book), N, file);
        fclose(file);
    }
}

//function to input book data
void inputBookData() {
    //add a new book to the array
    printf("Enter book details:\n");
    printf("ID: ");
    scanf("%d", &books[N].bookID);
    getchar(); // to consume the newline character after entering ID
    printf("Title: ");
    fgets(books[N].title, sizeof(books[N].title), stdin);
    books[N].title[strcspn(books[N].title, "\n")] = 0; // remove newline character
    printf("Author: ");
    fgets(books[N].author, sizeof(books[N].author), stdin);
    books[N].author[strcspn(books[N].author, "\n")] = 0;
    printf("Year: ");
    scanf("%d", &books[N].year);
    printf("Price (SAR): ");
    scanf("%f", &books[N].price);

     //increment the number of books and save the data
    N++;
    saveBookData();
}

//to display all book data
void displayBookData() {
    if (N == 0) {
        printf("No books available.\n");
    } else {
        printf("Book Details:\n");
        for (int i = 0; i < N; i++) {
            printf("ID: %d, Title: %s, Author: %s, Year: %d, Price: %.2f SAR\n",
                   books[i].bookID, books[i].title, books[i].author, books[i].year, books[i].price);
        }
    }
}

//To find a book by ID
void findBookByID() {
    int searchID;
    printf("Enter the book ID to search: ");
    scanf("%d", &searchID);

    for (int i = 0; i < N; i++) {
        if (books[i].bookID == searchID) {
            printf("Book found: ID: %d, Title: %s, Author: %s, Year: %d, Price: %.2f SAR\n",
                   books[i].bookID, books[i].title, books[i].author, books[i].year, books[i].price);
            return;
        }
    }
    printf("Book with ID %d not found.\n", searchID);
}

//to calculate the total value of all books
void calculateTotalValue() {
    float totalValue = 0;
    for (int i = 0; i < N; i++) {
        totalValue += books[i].price;
    }
    printf("Total value of all books: %.2f SAR\n", totalValue);
}

int main() {
    loadBookData();  //load book data from file at the start

    int choice;
    while (1) {
        
        printf("\nLibrary Management System\n");
        printf("1. Add a Book\n");
        printf("2. Display All Books\n");
        printf("3. Search for Book by ID\n");
        printf("4. Calculate Total Value of Books\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // handle the user's choice 
        if (choice == 1) {
            inputBookData(); //add a book
        } else if (choice == 2) {
            displayBookData(); // display all books
        } else if (choice == 3) {
            findBookByID(); // search for book by ID
        } else if (choice == 4) {
            calculateTotalValue(); // calculate total value of all books
        } else if (choice == 5) {
            saveBookData(); // save the data to file before exiting
            printf("Saving Data to books.dat and Exiting ...\n");
            return 0;
        } else {
            printf("Invalid choice! Please enter a valid option.\n");
        }
    }
}
