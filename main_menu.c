#include "main_menu.h"

void print_main_menu(struct user *logged_user){

    for(int i = 1; i < 47; i++)
    {
        gotoxy(35,i); printf("|");
    }

    gotoxy(4,2); printf(""YEL"* Big Machine Social Media *"WHT"");
    gotoxy(2,4); printf(""CYN"Logged as: %s"WHT"", logged_user -> username);
    gotoxy(139,2); printf(""YEL"* My friends list *"WHT"");
    print_my_friends(logged_user, 132, 6);

    gotoxy(36,4); for(int i = 1; i < 131; printf("-"), i++);

    for(int i = 1; i < 47; i++)
    {
        gotoxy(130,i); printf("|");
    }
    gotoxy(1,6); for(int i = 1; i < 35; printf("-"), i++);

    for(int j = 10 ; j < 11 + 4*3; j += 4)
    {
        gotoxy(1,j); for(int i = 1; i < 35; printf("-"), i++);
    }

    gotoxy(1,32); for(int i = 1; i < 35; printf("-"), i++);
    gotoxy(1,36); for(int i = 1; i < 35; printf("-"), i++);

    gotoxy(2,8); printf(YEL"1."WHT" Search users");
    gotoxy(2,12); printf(YEL"2."WHT" Manage messages");
    if (logged_user -> next_message != NULL)
    {
        gotoxy(22,12); printf(RED"*"WHT);
    }
    
    gotoxy(2,16); printf(YEL"3."WHT" My profile settings");
    gotoxy(2,20); printf(YEL"4."WHT" My feed");
    gotoxy(2,24); printf(YEL"5."WHT" Groups");
    gotoxy(2,34); printf(YEL"6."WHT" Log off");
}

void initialize_main_menu(struct user *head, struct user *logged_user, struct group *group_head)
{    
    print_main_menu(logged_user);
    char case_switch_main_menu;

    for(;;)
    {   
        case_switch_main_menu = _getch();
        fflush(stdin);

        switch (case_switch_main_menu)
        {
        case '1':  
            search_users(head, logged_user);     
            break;

        case '2':
            manage_messages(logged_user);
            break;

        case '3':
            manage_profile(logged_user);
            break;

        case '4':
            manage_feed(logged_user);
            break;

        case '5':
            manage_groups(logged_user, head, group_head);
            break;

        case '6':
            clean_area(165,46,1,1);
            print_user_authentication();
            return;
        }
    }
}