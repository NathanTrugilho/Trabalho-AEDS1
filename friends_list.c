#include "friends_list.h"

void print_my_friends(struct user *user, short column, short line)
{
    struct friend *aux = user -> next_friend;
    if(aux == NULL)
    {
        gotoxy(column, line); printf(YEL"*"WHT" This friends list is empty!");
        return;
    }
    while (aux != NULL)
    {
        gotoxy(column, line); printf(YEL"*"WHT" %s", aux -> username);
        line++;
        aux = aux -> next_friend;
    }
}

void add_friend(struct user *logged_user, struct user *found_user)
{
    if (logged_user == found_user)
    {
        gotoxy(STARTING_DEFAUT_X_POSITION, 46);
        printf(RED"You cannot add yourself as a friend! <press anything to continue>"WHT);
        pause_screen();
        clean_area(92, 1, STARTING_DEFAUT_X_POSITION, 46);
        return;
    }
    struct friend *current = logged_user -> next_friend;
    while(current != NULL)
    {
        if(!strcmp(found_user -> username, current -> username))
        {
            gotoxy(STARTING_DEFAUT_X_POSITION, 46);
            printf(RED"This user is already your friend! <press anything to continue>"WHT);
            pause_screen();
            clean_area(92, 1, STARTING_DEFAUT_X_POSITION, 46);
            return;
        }
        current = current -> next_friend;
    }
    struct friend *new_friend = (struct friend *)malloc(sizeof(struct friend));
    strcpy(new_friend -> username, found_user -> username);
    struct friend *prev = NULL;
    current = logged_user -> next_friend;

    // Encontrar o ponto de inserção em ordem alfabética
    while (current != NULL && strcmp(current -> username, new_friend -> username) < 0)
    {
        prev = current;
        current = current -> next_friend;
    }
    if (prev == NULL)
    {
        // Inserir no início da lista
        logged_user -> next_friend = new_friend;
    }
    else
    {
        // Inserir no meio ou no final da lista
        prev -> next_friend = new_friend;
    }
    new_friend -> next_friend = current;

    clean_area(33,40,132,6);
    print_my_friends(logged_user, 132, 6);
    gotoxy(STARTING_DEFAUT_X_POSITION, 46); printf(GRN"Friend added successfully! <press anything to continue>"WHT);
    pause_screen();
    clean_area(92, 1, STARTING_DEFAUT_X_POSITION, 46);

    //Adiciona o usuario logado como amigo na conta do outro usuario
    new_friend = (struct friend *)malloc(sizeof(struct friend));
    strcpy(new_friend -> username, logged_user -> username);
    prev = NULL;
    current = found_user -> next_friend;

    // Encontrar o ponto de inserção em ordem alfabética
    while (current != NULL && strcmp(current -> username, new_friend -> username) < 0)
    {
        prev = current;
        current = current -> next_friend;
    }
    if (prev == NULL)
    {
        // Inserir no início da lista
        found_user -> next_friend = new_friend;
    }
    else
    {
        // Inserir no meio ou no final da lista
        prev -> next_friend = new_friend;
    }
    new_friend -> next_friend = current;
    return;
}