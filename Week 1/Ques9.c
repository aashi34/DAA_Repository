/* Q9. Library Book Management

• Store the book ID, title, author, total copies, and available copies
  using structures.
• Create a menu-driven program to add and search for books,
  issue and return books, and display all books currently unavailable. */

#include <stdio.h>

struct Book {
    int id;
    char title[50];
    char author[50];
    int total;
    int available;
};

int main() {
    struct Book b[100];
    int n = 0;
    int choice, id, i;

    do {

        printf("\n\n--- Library Menu ---\n");
        printf("1. Add Book\n");
        printf("2. Search Book\n");
        printf("3. Issue Book\n");
        printf("4. Return Book\n");
        printf("5. Display Unavailable Books\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice == 1) {

            printf("Enter book ID: ");
            scanf("%d", &b[n].id);

            printf("Enter title: ");
            scanf(" %[^\n]", b[n].title);

            printf("Enter author: ");
            scanf(" %[^\n]", b[n].author);

            printf("Enter total copies: ");
            scanf("%d", &b[n].total);

            b[n].available = b[n].total;

            n++;

            printf("Book added successfully.");
        }

        else if(choice == 2) {

            printf("Enter book ID: ");
            scanf("%d", &id);

            for(i = 0; i < n; i++) {

                if(b[i].id == id) {
                    printf("Title: %s\n", b[i].title);
                    printf("Author: %s\n", b[i].author);
                    printf("Available copies: %d\n", b[i].available);
                    break;
                }
            }
        }

        else if(choice == 3) {

            printf("Enter book ID: ");
            scanf("%d", &id);

            for(i = 0; i < n; i++) {

                if(b[i].id == id) {

                    if(b[i].available > 0) {
                        b[i].available--;
                        printf("Book issued successfully.");
                    }
                    else {
                        printf("Book is unavailable.");
                    }

                    break;
                }
            }
        }

        else if(choice == 4) {

            printf("Enter book ID: ");
            scanf("%d", &id);

            for(i = 0; i < n; i++) {

                if(b[i].id == id) {

                    if(b[i].available < b[i].total) {
                        b[i].available++;
                        printf("Book returned successfully.");
                    }

                    break;
                }
            }
        }

        else if(choice == 5) {

            printf("\nUnavailable books:\n");

            for(i = 0; i < n; i++) {

                if(b[i].available == 0)
                    printf("%s\n", b[i].title);
            }
        }

    } while(choice != 6);

    return 0;
}
