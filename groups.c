#include "groups.h"

void list_all_groups(struct group *group_head, struct user *logged_user)
{
    char line = 9;
    struct group *aux = group_head -> next_group;
    struct friend *aux2;
    gotoxy(5,29); printf(CYN"4. List all groups"WHT);
    if(aux == NULL)
    {
        gotoxy(37, 6); printf(YEL"*"WHT" The group list is empty!");
        gotoxy(37,46); printf("<press anything to continue>");
        pause_screen();
        gotoxy(5,29); printf(YEL"4."WHT" List all groups");
        clean_area(30,1,37,6);
        clean_area(31,1,37,46);
        return;
    }
    gotoxy(37,6); printf(YEL"*"WHT" Existing groups");
    gotoxy(37,7); printf(YEL"*"CYN0" Groups you belong"WHT);
    while (aux != NULL)
    {
        aux2 = aux -> next_group_member;
        while (aux2 != NULL)
        {
            if (!strcmp(logged_user -> username, aux2 -> username))
            {
                break;
            }
            aux2 = aux2 -> next_friend;
        }
        if(logged_user == aux -> leader || aux2 != NULL)
        {
            gotoxy(37, line); printf(YEL"*"WHT" "CYN0"%s"WHT, aux -> name);
            line++;
            aux = aux -> next_group;
            continue;
        }
        
        gotoxy(37, line); printf(YEL"*"WHT" %s", aux -> name);
        line++;
        aux = aux -> next_group;
    }
    gotoxy(37,46); printf("<press anything to continue>");
    pause_screen();
    gotoxy(5,29); printf(YEL"4."WHT" List all groups");
    clean_area(31,1,37,46);
    clean_area(92,line-6,37,6);
}

void print_group_feed(struct group *found_group)
{
    short line = 13, i;
    struct group_feed *print_this_post = found_group -> next_group_feed;

    if (print_this_post == NULL)
    {
        gotoxy(37, line); printf(YEL"*"WHT" This group has no posts yet");
        return;
    }
    
    gotoxy(37, line); printf(YEL"Group's feed sorted by newer to older: "WHT);
    line += 2;
    while (print_this_post != NULL)
    {
        gotoxy(37,line);
        printf(YEL"*"WHT" User: %s", print_this_post -> username);
        gotoxy(37,++line);
        for(i = 0; i < strlen(print_this_post -> post); i++){
            printf("%c", print_this_post -> post[i]);
            if (i == 91)
            {
                gotoxy(37, ++line);
            }
        }
        print_this_post = print_this_post -> next_struct_feed;
        line += 2;
        gotoxy(37, line);
    }
}

void show_group_data(struct group *found_group)
{
    gotoxy(37,5); printf(YEL"*"WHT " Group name: %s", found_group -> name);
    gotoxy(37,6); printf(YEL"*"WHT " Group leader: %s", found_group -> leader -> username);
    gotoxy(37,7); printf(YEL"*"WHT " Group description:");
    gotoxy(37,9); printf("%s", found_group -> description);
    gotoxy(36,12); for(int i = 0; i < 94; printf("-"), i++);
}

void join_group(struct group *found_group, struct user *logged_user)
{
    struct friend *aux =  found_group -> next_group_member;

    while (aux != NULL)
    {
        if(!strcmp(aux -> username, logged_user -> username))
        {
            break;
        }
        aux = aux -> next_friend;
    }
    
    if (aux != NULL || found_group -> leader == logged_user)
    {
        gotoxy(37,46); printf(RED"You are a member of this group already! <press anything to continue>"WHT);
        pause_screen();
        clean_area(80,1,37,46);
        return;
    }

    aux = (struct friend*)malloc(sizeof(struct friend));
    aux -> next_friend = found_group -> next_group_member;
    strcpy(aux -> username, logged_user -> username);
    found_group -> next_group_member = aux;

    gotoxy(37,46); printf(GRN"You have joined the group! <press anything to continue>"WHT);
    pause_screen();
    clean_area(80,1,37,46);
}

void create_group_post(struct group *found_group, struct user *logged_user) 
{
    struct friend *members = found_group -> next_group_member;
    char type_post[181];
    gotoxy(61,11); printf(CYN"2. Create a post"WHT);

    while (members != NULL)
    {
        if(!strcmp(members -> username, logged_user -> username))
        {
            break;
        }
        members = members -> next_friend;
    }
    
    if(members == NULL && found_group -> leader != logged_user)
    {
        gotoxy(37,46); printf(RED"You are not a member of this group! <press anything to continue>"WHT);
        pause_screen();
        clean_area(80,1,37,46);
        gotoxy(61,11); printf(YEL"2."WHT" Create a post");
        return;
    }

    clean_area(92,33,37,13);
    gotoxy(37,13); printf(YEL"*"WHT" Create a post within 180 characters:");
    gotoxy(37,45); printf("Press 'Esc' to cancel data input and go back without saving");
    if(type_feed(type_post,15))
    {
        clean_area(92,4,37,13);
        clean_area(61,1,37,45);
        gotoxy(61,11); printf(YEL"2."WHT" Create a post");
        return;
    }

    struct group_feed *new_feed = (struct group_feed*)malloc(sizeof(struct group_feed));
    strcpy(new_feed -> post, type_post);
    strcpy(new_feed -> username, logged_user -> username);
    new_feed -> next_struct_feed = found_group -> next_group_feed;
    found_group -> next_group_feed = new_feed;

    gotoxy(37,46); printf(GRN"Post created successfully! <Press anything to continue>"WHT);
    pause_screen();
    gotoxy(61,11); printf(YEL"2."WHT" Create a post");
    clean_area(92,4,37,13);
    clean_area(61,1,37,45);
    clean_area(70,1,37,46);
}   

void full_group_actions(struct group *found_group, struct user *logged_user)
{
    char switch_case;
    show_group_data(found_group);
    gotoxy(37,45); clean_area(60,1,37,45);
    gotoxy(37,11); printf(YEL"1."WHT" Join group");
    gotoxy(61,11); printf(YEL"2."WHT" Create a post");
    gotoxy(88,11); printf(YEL"3."WHT" See group's feed");
    gotoxy(118,11); printf(YEL"4."WHT" Go back");
    
    for(;;)
    {
        switch_case = _getch();
        fflush(stdin);

        switch (switch_case)
        {
        case '1':    
            join_group(found_group, logged_user);        
            break;

        case '2':
            create_group_post(found_group, logged_user);
            break;

        case '3':
            print_group_feed(found_group);
            break;

        case '4':
            clean_area(94,42,36,5);
            gotoxy(37,45); printf("Press 'Esc' to cancel data input and go back without saving");
            clean_area(31,1,87,2);
            return;
        }
    }
}

struct group *chained_authentication_group_search(struct group *next_group, struct user *logged_user, char *group_name_verification){
    struct group *aux = next_group;
    while (aux != NULL)
    {   
        if(aux -> leader == logged_user || !strcmp(aux -> name, group_name_verification) )
        {
            return aux;
        }
        aux = aux -> next_group;
    }
    return NULL;
};

void create_group(struct user *logged_user, struct group *group_head)
{
    char group_name[31];
    char group_description[91];
    group_name[0] = '\0';
    group_description[0] = '\0';
    struct group *group_verification = NULL;
    group_verification = chained_authentication_group_search(group_head -> next_group, logged_user, group_name);

    if(group_verification != NULL)
    {
        gotoxy(37,46); printf(RED"You cannot create more than one group! <press anything to continue>!"WHT);
        pause_screen();
        clean_area(70,1,37,46);
        return;
    }

    gotoxy(5,28); printf(CYN"3. Create group"WHT);
    gotoxy(37,45); printf("Press 'Esc' to cancel data input and go back one step without saving");
    gotoxy(37,6); printf(YEL"*"WHT" Type your group name (12 to 30 characters):");
    gotoxy(37,8); printf(YEL"*"WHT" Type your group description (optional):");

    char sai = 1;
    do
    {
        gotoxy(83,6);
        if(type_info(group_name, 30, 12))
        {
            clean_area(60,1,37,6);
            gotoxy(5,28); printf(YEL"3."WHT" Create group");
            clean_area(70,1,37,45);
            clean_area(55,1,37,8);
            return;
        }

        group_verification = chained_authentication_group_search(group_head, logged_user, group_name);

        if(group_verification != NULL)
        {
            gotoxy(37,46); printf(RED"This group already exists! <press anything to continue>!"WHT);
            pause_screen();
            clean_area(31,1,83,6);
            clean_area(70,1,37,46);
            continue;
        }
        do
        {
            gotoxy(37,10);
            if(type_info(group_description, 90, 0))
            {   
                clean_area(92,1,37,10);
                clean_area(31,1,83,6);
                break;
            }
            sai = 0;
        }while(sai);

    }while(sai);

    struct group *new_group = (struct group *)malloc(sizeof(struct group));
    strcpy(new_group -> name, group_name);
    strcpy(new_group -> description, group_description);
    new_group -> next_group_feed = NULL;
    new_group -> next_group_member = NULL;
    new_group -> leader = logged_user;
    new_group -> next_group = NULL;
    struct group *prev = NULL;
    struct group *current = group_head -> next_group;

    // Encontrar o ponto de inserção em ordem alfabética
    while (current != NULL && strcmp(current -> name, new_group -> name) < 0)
    {
        prev = current;
        current = current -> next_group;
    }
    if (prev == NULL)
    {
        // Inserir no início da lista
        group_head -> next_group = new_group;
    }
    else
    {
        // Inserir no meio ou no final da lista
        prev -> next_group = new_group;
    }
    new_group -> next_group = current;

    gotoxy(37,46); printf(GRN"Group created successfully! <press anything to continue>!"WHT);
    pause_screen();
    gotoxy(5,28); printf(YEL"3."WHT" Create group");
    clean_area(92,1,37,6);
    clean_area(55,1,37,8);
    clean_area(92,1,37,10);
    clean_area(70,1,37,45);
    clean_area(70,1,37,46);
    return;
}

void search_groups(struct group *group_head, struct user *logged_user)
{
    char group_verification[31];
    struct group *group_search;
    gotoxy(5,26); printf(CYN"1. Search groups"WHT);
    gotoxy(37,2); printf(YEL"*"WHT" Type the name of the group you are looking for: ");
    gotoxy(37,45); printf("Press 'Esc' to cancel data input and go back without saving");
    do
    {
        clean_area(31,1,87,2);
        gotoxy(87,2); 
        if(type_info(group_verification,30,12))
        { 
            clean_area(92,1,37,2);
            gotoxy(5,26); printf(YEL"1."WHT" Search groups");
            clean_area(94,42,36,5);
            return;
        }        
        group_search = chained_authentication_group_search(group_head -> next_group, NULL, group_verification);
        if(group_search == NULL)
        {
            gotoxy(37,46); printf(RED"Group not found! <press anything to continue>"WHT);
            pause_screen();
            clean_area(60,1,37,46);
            clean_area(21,1,92,2);
            continue;
        };       
        full_group_actions(group_search, logged_user);
    } while (1);
}

void edit_group(struct user *logged_user, struct group *group_head)
{
    struct group *aux = group_head;

    while (aux != NULL)
    {   
        if(aux -> leader == logged_user)
        {
            break;
        }
        aux = aux -> next_group;
    }
    
    if(aux == NULL)
    {
        gotoxy(37,46); printf(RED"You do not own a group! <press anything to continue>!"WHT);
        pause_screen();
        clean_area(70,1,37,46);
        return;
    }
    gotoxy(5,27); printf(CYN"2. My group"WHT);
    show_group_data(aux);
    gotoxy(37,11); printf(YEL"1. "WHT"Edit description");
    gotoxy(60,11); printf(YEL"2. "WHT"Go back");
    char case_edit_group;
    char group_description[91];

    for(;;)
    {
        case_edit_group = _getch();
        fflush(stdin);

        if(case_edit_group == '2')
        {
            gotoxy(5,27); printf(YEL"2."WHT" My group");
            clean_area(94,8,36,5);
            return;
        }
        else if(case_edit_group == '1')
        {
            gotoxy(37,11); printf(CYN"1. Edit description"WHT);
            gotoxy(37,13); printf(YEL"*"WHT" Type your group description:");
            gotoxy(37,45); printf("Press 'Esc' to cancel data input and go back one step without saving");
            gotoxy(37,15);
            if(type_info(group_description, 90, 0))
            {   
                gotoxy(37,11); printf(YEL"1. "WHT"Edit description");
                clean_area(50,1,37,13);
                clean_area(92,1,37,15);
                clean_area(70,1,37,45);
                continue;
            }

            if(!strcmp(group_description, aux -> description))
            {
                gotoxy(37,46); printf(RED"The new description cannot be the same as before! <press anything to continue>!"WHT);
                pause_screen();
                clean_area(92,1,37,46);
            }

            strcpy(aux -> description, group_description);
            gotoxy(37,46); printf(GRN"Group created successfully! <press anything to continue>!"WHT);
            pause_screen();
            gotoxy(37,11); printf(YEL"1. "WHT"Edit description");
            clean_area(92,1,37,9);
            gotoxy(37,9); printf("%s", group_description);
            clean_area(92,4,37,13);
            clean_area(70,1,37,45);
            clean_area(92,1,37,46);
        }
    }
}

void manage_groups(struct user *logged_user, struct user *head, struct group *group_head)
{
    char case_switch_groups;

    gotoxy(2,24); printf(CYN"5. Groups"WHT);
    gotoxy(5,26); printf(YEL"1."WHT" Search groups");
    gotoxy(5,27); printf(YEL"2."WHT" My group");
    gotoxy(5,28); printf(YEL"3."WHT" Create group");
    gotoxy(5,29); printf(YEL"4."WHT" List all groups");
    gotoxy(5,30); printf(YEL"5."WHT" Go back");

    for(;;)
    {   
        case_switch_groups = _getch();
        fflush(stdin);

        switch (case_switch_groups)
        {
        case '1':
            search_groups(group_head,logged_user);    
            break;

        case '2':
            edit_group(logged_user, group_head -> next_group);
            break;

        case '3':
            create_group(logged_user, group_head);
            break;

        case '4':
            list_all_groups(group_head, logged_user);
            break;

        case '5':
            clean_area(20,5,5,26);
            gotoxy(2,24); printf(YEL"5."WHT" Groups");
            return;
        }
    }
}