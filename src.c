#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 3
#define TITLE 40
#define AUTHOR 20
#define DATES 10

typedef struct
{
    char titulo[TITLE];
    char autor[AUTHOR];
    float numeroDoCatalogo;
    int anoDePublicacao;
    int numeroDaCopia;
    char dataEmprestimo[DATES];
    char dataRetorno[DATES];
} LIVRO;

void showMenu();
void initialize(LIVRO data[]);
void insertBook(LIVRO data[], LIVRO book);
void searchByTitle(LIVRO data[], char title[TITLE]);
void searchByAuthor(LIVRO data[], char author[AUTHOR]);
void updateBookTitle(LIVRO data[], char oldTitle[TITLE], char newTitle[TITLE]);
void updateBookReturnDate(LIVRO data[], char title[TITLE], char date[DATES]);
void updateBookLoanDate(LIVRO data[], char title[TITLE], char date[DATES]);
void showLib(LIVRO data[]);
void freeBook(LIVRO book);

int main()
{
    LIVRO lib[SIZE];
    LIVRO book;

    initialize(lib);

    while (1)
    {
    menu:
        printf("\n");
        freeBook(book);
        showMenu();

        __fpurge(stdin);
        int *tmp = malloc(sizeof(int));
        scanf("%ld", tmp);

        __fpurge(stdin);

        // 1 //
        if (*tmp == 1)
        {
            printf("Digite abaixo os dados para cadastro de um livro...\n");
            printf("Digite o título do livro: ");
            scanf("%s%*c", &book.titulo);
            __fpurge(stdin);
            //--//
            printf("Digite o autor do livro: ");
            scanf("%s%*c", &book.autor);
            insertBook(lib, book);
            goto menu;
        }

        // 2 //
        if (*tmp == 2)
        {
            printf("Digite um titulo para pesquisar na lista: ");
            char str[TITLE];
            scanf("%s%*c", str);
            __fpurge(stdin);
            searchByTitle(lib, str);
            goto menu;
        }

        // 3 //
        if (*tmp == 3)
        {
            printf("Digite um autor para pesquisar na lista: ");
            char str[AUTHOR];
            scanf("%s%*c", str);
            __fpurge(stdin);
            searchByAuthor(lib, str);
            goto menu;
        }

        // 4 //
        if (*tmp == 4)
        {
            printf("Digite o titulo que deseja alterar: ");
            char old[TITLE];
            scanf("%s%*c", old);
            __fpurge(stdin);
            printf("Digite o novo titulo para atualizar: ");
            char new[TITLE];
            scanf("%s%*c", new);
            __fpurge(stdin);
            updateBookTitle(lib, old, new);
            goto menu;
        }

        // 5 //
        if (*tmp == 5)
        {
            printf("Digite o titulo que deseja alterar: ");
            char title[TITLE];
            scanf("%s%*c", title);
            __fpurge(stdin);
            printf("Digite a data de empréstimo do livro para atualizar: ");
            char date[DATES];
            scanf("%s%*c", date);
            __fpurge(stdin);
            updateBookLoanDate(lib, title, date);
            goto menu;
        }

        // 6 //
        if (*tmp == 6)
        {
            printf("Digite o titulo que deseja alterar: ");
            char title[TITLE];
            scanf("%s%*c", title);
            __fpurge(stdin);
            printf("Digite a data de retorno do livro para atualizar: ");
            char date[DATES];
            scanf("%s%*c", date);
            __fpurge(stdin);
            updateBookReturnDate(lib, title, date);
            goto menu;
        }

        // 7 //
        if (*tmp == 7)
        {
            printf("Listando livros...\n");
            showLib(lib);
        }

        if (*tmp == 8)
        {
            free(tmp);
            break;
        }
    }

    return 0;
}

void showMenu()
{
    printf("BIBLIOTECA DA IES\n");
    printf("1 - Inserir novo livro\n");
    printf("2 - Procurar livro por título.\n");
    printf("3 - Procurar livro por autor.\n");
    printf("4 - Alterar nome do livro\n");
    printf("5 - Registar data de empréstimo de um livro.\n");
    printf("6 - Registar data de retorno de um livro.\n");
    printf("7 - Listar livros existentes na biblioteca.\n");
    printf("8 – Sair\n");
}

void initialize(LIVRO data[])
{
    int i = 0;
    for (i = 0; i < SIZE; i++)
    {
        strcpy(data[i].titulo, "NULL");
        strcpy(data[i].autor, "NULL");
        data[i].numeroDoCatalogo = 9999;
        data[i].anoDePublicacao = 9999;
        data[i].numeroDaCopia = 9999;
        strcpy(data[i].dataEmprestimo, "NULL");
        strcpy(data[i].dataRetorno, "NULL");
    }
}

void insertBook(LIVRO data[], LIVRO book)
{
    int i = 0;
    for (i = 0; i < SIZE; i++)
    {
        if (strcmp("NULL", data[i].titulo) == 0)
        {
            strcpy(data[i].titulo, book.titulo);
            strcpy(data[i].autor, book.autor);
            data[i].numeroDoCatalogo = book.numeroDoCatalogo;
            data[i].anoDePublicacao = book.anoDePublicacao;
            data[i].numeroDaCopia = book.numeroDaCopia;
            strcpy(data[i].dataEmprestimo, book.dataEmprestimo);
            strcpy(data[i].dataRetorno, book.dataRetorno);
            break;
        }
    }
}

void showLib(LIVRO data[])
{
    int i = 0;
    for (i = 0; i < SIZE; i++)
    {
        if (strcmp(data[i].titulo, "NULL") != 0)
            printf("%s - %s : %s - %s \n", data[i].titulo, data[i].autor, data[i].dataEmprestimo, data[i].dataRetorno);
    }
    printf("\n");
}

void searchByTitle(LIVRO data[], char title[TITLE])
{
    int i = 0;
    for (i = 0; i < SIZE; i++)
    {
        if (strcmp(title, data[i].titulo) == 0)
        {
            printf("Titulo encontrado: %s \n", data[i].titulo);
            break;
        }
    }
}

void searchByAuthor(LIVRO data[], char author[TITLE])
{
    int i = 0;
    for (i = 0; i < SIZE; i++)
    {
        if (strcmp(author, data[i].autor) == 0)
        {
            printf("Livro encontrado: %s - %s \n", data[i].titulo, data[i].autor);
            break;
        }
    }
}

void updateBookTitle(LIVRO data[], char oldTitle[TITLE], char newTitle[TITLE])
{
    int i = 0;
    for (i = 0; i < SIZE; i++)
    {
        if (strcmp(oldTitle, data[i].titulo) == 0)
        {
            strcpy(data[i].titulo, newTitle);
            printf("Titulo do livro alterado com sucesso.\n");
            break;
        }
    }
}

void updateBookReturnDate(LIVRO data[], char title[TITLE], char date[DATES])
{
    int i = 0;
    for (i = 0; i < SIZE; i++)
    {
        if (strcmp(title, data[i].titulo) == 0)
        {
            strcpy(data[i].dataRetorno, date);
            printf("Data de retorno do livro %s atualizada com sucesso para %s.\n", title, date);
            break;
        }
    }
}

void updateBookLoanDate(LIVRO data[], char title[TITLE], char date[DATES])
{
    int i = 0;
    for (i = 0; i < SIZE; i++)
    {
        if (strcmp(title, data[i].titulo) == 0)
        {
            strcpy(data[i].dataEmprestimo, date);
            printf("Data de empréstimo do livro %s atualizada com sucesso para %s.\n", title, date);
            break;
        }
    }
}

void freeBook(LIVRO book)
{
    strcpy(book.titulo, "NULL");
    strcpy(book.autor, "NULL");
    book.numeroDoCatalogo = 9999;
    book.anoDePublicacao = 9999;
    book.numeroDaCopia = 9999;
    strcpy(book.dataEmprestimo, "NULL");
    strcpy(book.dataRetorno, "NULL");
}