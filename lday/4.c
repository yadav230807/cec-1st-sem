#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int id;
    char title[100];
    char author[50];
    int copies;
};

void addBook() {
    struct Book b;
    FILE *f = fopen("library.txt", "a");
    printf("Book ID: "); scanf("%d", &b.id); getchar();
    printf("Title: "); fgets(b.title, 100, stdin); b.title[strcspn(b.title, "\n")] = 0;
    printf("Author: "); fgets(b.author, 50, stdin); b.author[strcspn(b.author, "\n")] = 0;
    printf("Copies: "); scanf("%d", &b.copies);
    fprintf(f, "%d | %s | %s | %d\n", b.id, b.title, b.author, b.copies);
    fclose(f);
    printf("Book added!\n");
}

void viewBooks() {
    char line[200];
    FILE *f = fopen("library.txt", "r");
    if (!f) { printf("No books!\n"); return; }
    printf("\nID | Title | Author | Copies\n");
    while(fgets(line, 200, f)) printf("%s", line);
    fclose(f);
}

void issueBook() {
    int id, found = 0;
    char line[200], temp_line[200];
    FILE *f = fopen("library.txt", "r");
    FILE *t = fopen("temp.txt", "w");
    
    printf("Book ID to issue: "); scanf("%d", &id);
    
    while(fgets(line, 200, f)) {
        strcpy(temp_line, line);
        char *token = strtok(temp_line, "|");
        int book_id = atoi(token);
        
        if(book_id == id) {
            token = strtok(NULL, "|"); // title
            char *title = token;
            token = strtok(NULL, "|"); // author  
            char *author = token;
            token = strtok(NULL, "|"); // copies
            int copies = atoi(token);
            
            if(copies > 0) {
                copies--;
                fprintf(t, "%d | %s | %s | %d\n", id, title, author, copies);
                printf("Book issued! %d copies left\n", copies);
            } else {
                fprintf(t, "%s", line);
                printf("No copies available!\n");
            }
            found = 1;
        } else {
            fprintf(t, "%s", line);
        }
    }
    
    fclose(f); fclose(t);
    remove("library.txt"); 
    rename("temp.txt", "library.txt");
    if(!found) printf("Book not found!\n");
}

int main() {
    int choice;
    while(1) {
        printf("\n1.Add 2.View 3.Issue 4.Exit\nChoice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: addBook(); break;
            case 2: viewBooks(); break;
            case 3: issueBook(); break;
            case 4: return 0;
        }
    }
}