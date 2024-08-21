#include "user_authentication.h"
#include "groups.h"

int main()
{
    char caso_switch;
    struct group *group_head = (struct group*)malloc((sizeof(struct group)));
    group_head -> name[0] = '\0';
    group_head -> description[0] = '\0';
    group_head -> next_group_member = NULL;
    group_head -> next_group_feed = NULL;
    group_head -> next_group = NULL;
    group_head -> leader = NULL;

    struct user *head = (struct user*)malloc((sizeof(struct user)));
    head -> next_user = NULL;
    head -> username[0] = '\0';
    print_user_authentication();

    for (;;)
    {   
        caso_switch = getch();
        fflush(stdin);

        switch (caso_switch)
        {
        case '1':
            create_account(head);
            break;

        case '2':
            login(head, group_head);
            break;

        case '3':
            system("cls");
            printf(RED"\n Program aborted successfully!\n"WHT);
            return EXIT_SUCCESS;
        }
    }
}