#include "user_profiles.h"

void search_users(struct user *head, struct user *logged_user)
{
    char username_verification[USERNAME_MAX_LENGTH];
    struct user *user_search;
    gotoxy(2,8); printf(""CYN"1. Search users"WHT);
    gotoxy(STARTING_DEFAUT_X_POSITION,2); printf(YEL"*"WHT" Type the username of the person you are looking for: ");
    gotoxy(STARTING_DEFAUT_X_POSITION,45); printf("Press 'Esc' to cancel data input and go back without saving");

    do
    {
        clean_area(21,1,92,2);
        gotoxy(92,2); 
        if(type_username(username_verification))
        { 
            clean_area(92,1,STARTING_DEFAUT_X_POSITION,2);
            gotoxy(2,8); printf(YEL"1."WHT" Search users");
            clean_area(94,42,36,5);
            return;
        }        
        user_search = chained_authentication_search(head, username_verification);
        if(user_search == NULL)
        {
            gotoxy(STARTING_DEFAUT_X_POSITION,46); printf(RED"Username not found! Press anything to continue"WHT);
            pause_screen();
            clean_area(60,1,STARTING_DEFAUT_X_POSITION,46);
            clean_area(21,1,92,2);
            continue;
        };       
        full_profile_actions(logged_user, user_search);
    } while (1);
}

void change_full_name(struct user *logged_user)
{
    char verification_string[41];
    gotoxy(STARTING_DEFAUT_X_POSITION,17); printf(CYN"1. Change full name"WHT);
    gotoxy(STARTING_DEFAUT_X_POSITION,24); printf("Type your full name (maximum of 40 characters):");
    gotoxy(STARTING_DEFAUT_X_POSITION,45); printf("Press 'Esc' to cancel data input and go back without saving");
    do
    {
        gotoxy(85,24);
        if(type_info(verification_string, 40, 0))
        {
            clean_area(70,1,STARTING_DEFAUT_X_POSITION,24);
            gotoxy(STARTING_DEFAUT_X_POSITION,17); printf(YEL"1."WHT" Change full name");
            clean_area(61,1,STARTING_DEFAUT_X_POSITION,45);
            return;
        }
        if(!strcmp(verification_string, logged_user -> full_name))
        {
            gotoxy(STARTING_DEFAUT_X_POSITION,46); printf(RED"Your new full name cannot be the same as before!"WHT);
            pause_screen();
            clean_area(41,1,85,24);
            clean_area(55,1,STARTING_DEFAUT_X_POSITION,46);
            continue;
        }
        break;
    }while(1);

    strcpy(logged_user -> full_name, verification_string);
    gotoxy(STARTING_DEFAUT_X_POSITION,46); printf(GRN"Your full name has been changed successfully!"WHT);
    pause_screen();
    clean_area(40,1,58,7);
    gotoxy(58,7); printf("%s", logged_user -> full_name);
    clean_area(90,1,STARTING_DEFAUT_X_POSITION,24);
    clean_area(61,1,STARTING_DEFAUT_X_POSITION,45);
    clean_area(55,1,STARTING_DEFAUT_X_POSITION,46);
    gotoxy(STARTING_DEFAUT_X_POSITION,17); printf(YEL"1."WHT" Change full name");
}

void change_social_engagement(struct user *logged_user)
{
    char verification_string[17];
    gotoxy(STARTING_DEFAUT_X_POSITION,18); printf(CYN"2. Change social engagement"WHT);
    gotoxy(STARTING_DEFAUT_X_POSITION,24); printf("Type your social engagement (maximum of 16 characters):");
    gotoxy(STARTING_DEFAUT_X_POSITION,45); printf("Press 'Esc' to cancel data input and go back without saving");
    do
    {
        gotoxy(93,24);
        if(type_info(verification_string, 16, 0))
        {
            clean_area(72,1,STARTING_DEFAUT_X_POSITION,24);
            gotoxy(STARTING_DEFAUT_X_POSITION,18); printf(YEL"2."WHT" Change social engagement");
            clean_area(61,1,STARTING_DEFAUT_X_POSITION,45);
            return;
        }
        if(!strcmp(verification_string, logged_user -> social_engagement))
        {
            gotoxy(STARTING_DEFAUT_X_POSITION,46); printf(RED"Your new social engagement cannot be the same as before!"WHT);
            pause_screen();
            clean_area(17,1,93,24);
            clean_area(55,1,STARTING_DEFAUT_X_POSITION,46);
            continue;
        }
        break;
    }while(1);

    strcpy(logged_user -> social_engagement, verification_string);
    gotoxy(STARTING_DEFAUT_X_POSITION,46); printf(GRN"Your social engagement name has been changed successfully!"WHT);
    pause_screen();
    clean_area(17,1,65,8);
    gotoxy(65,8); printf("%s", logged_user -> social_engagement);
    clean_area(72,1,STARTING_DEFAUT_X_POSITION,24);
    clean_area(61,1,STARTING_DEFAUT_X_POSITION,45);
    clean_area(65,1,STARTING_DEFAUT_X_POSITION,46);
    gotoxy(STARTING_DEFAUT_X_POSITION,18); printf(YEL"2."WHT" Change social engagement");
}

void change_address(struct user *logged_user)
{
    char verification_string[31];
    gotoxy(STARTING_DEFAUT_X_POSITION,19); printf(CYN"3. Change address"WHT);
    gotoxy(STARTING_DEFAUT_X_POSITION,24); printf("Type your address (maximum of 30 characters):");
    gotoxy(STARTING_DEFAUT_X_POSITION,45); printf("Press 'Esc' to cancel data input and go back without saving");
    do
    {
        gotoxy(83,24);
        if(type_info(verification_string, 30, 0))
        {
            clean_area(72,1,STARTING_DEFAUT_X_POSITION,24);
            gotoxy(STARTING_DEFAUT_X_POSITION,19); printf(YEL"3."WHT" Change address");
            clean_area(61,1,STARTING_DEFAUT_X_POSITION,45);
            return;
        }
        if(!strcmp(verification_string, logged_user -> address))
        {
            gotoxy(STARTING_DEFAUT_X_POSITION,46); printf(RED"Your new address cannot be the same as before!"WHT);
            pause_screen();
            clean_area(17,1,93,24);
            clean_area(55,1,STARTING_DEFAUT_X_POSITION,46);
            continue;
        }
        break;
    }while(1);

    strcpy(logged_user -> address, verification_string);
    gotoxy(STARTING_DEFAUT_X_POSITION,46); printf(GRN"Your address has been changed successfully!"WHT);
    pause_screen();
    clean_area(31,1,55,9);
    gotoxy(55,9); printf("%s", logged_user -> address);
    clean_area(76,1,STARTING_DEFAUT_X_POSITION,24);
    clean_area(61,1,STARTING_DEFAUT_X_POSITION,45);
    clean_area(55,1,STARTING_DEFAUT_X_POSITION,46);
    gotoxy(STARTING_DEFAUT_X_POSITION,19); printf(YEL"3."WHT" Change address");

}

void change_password(struct user *logged_user)
{
    char password_verification[11];

    gotoxy(STARTING_DEFAUT_X_POSITION,21); printf(CYN"5. Change password"WHT);
    gotoxy(STARTING_DEFAUT_X_POSITION,24); printf("Type your old password in order to change: ");
    gotoxy(STARTING_DEFAUT_X_POSITION,45); printf("Press 'Esc' to cancel data input and go back without saving");
    do
    {
        gotoxy(80,24); 
        if(type_password(password_verification))
        {
            clean_area(56,1,STARTING_DEFAUT_X_POSITION,24);
            gotoxy(STARTING_DEFAUT_X_POSITION,21); printf(YEL"5."WHT" Change password");
            clean_area(61,1,STARTING_DEFAUT_X_POSITION,45);
            return;
        }

        if(!strcmp(password_verification, logged_user -> password))
        {
            gotoxy(STARTING_DEFAUT_X_POSITION,26); printf("Type your new password: ");
            do
            {
                gotoxy(61,26);
                if(type_password(password_verification))
                {
                    clean_area(56,1,STARTING_DEFAUT_X_POSITION,26);
                    gotoxy(STARTING_DEFAUT_X_POSITION,21); printf(YEL"5."WHT" Change password");
                    clean_area(61,1,STARTING_DEFAUT_X_POSITION,45);
                    clean_area(60,3,STARTING_DEFAUT_X_POSITION,24);
                    return;
                }

                if(!strcmp(password_verification, logged_user -> password))
                {
                    gotoxy(STARTING_DEFAUT_X_POSITION,46); printf(RED"Your new password cannot be the same as before!"WHT);
                    pause_screen();
                    clean_area(11,1,61,26);
                    clean_area(49,1,STARTING_DEFAUT_X_POSITION,46);
                    continue;
                }

                strcpy(logged_user -> password, password_verification);
                gotoxy(STARTING_DEFAUT_X_POSITION,46); printf(GRN"Password changed successfully!"WHT);
                pause_screen();
                clean_area(60,3,STARTING_DEFAUT_X_POSITION,24);
                clean_area(61,1,STARTING_DEFAUT_X_POSITION,45);
                clean_area(44,1,STARTING_DEFAUT_X_POSITION,46);
                gotoxy(STARTING_DEFAUT_X_POSITION,21); printf(YEL"5."WHT" Change password");
                return;
            }while(1);
        }

        gotoxy(STARTING_DEFAUT_X_POSITION,46); printf(RED"Wrong Password! Press anything to try again."WHT);
        pause_screen();
        clean_area(10,1,80,24);
        clean_area(44,1,STARTING_DEFAUT_X_POSITION,46);

    } while (1);

}

void change_biography(struct user *logged_user)
{
    char verification_string[91];
    gotoxy(STARTING_DEFAUT_X_POSITION,20); printf(CYN"4. Change biography"WHT);
    gotoxy(STARTING_DEFAUT_X_POSITION,24); printf("Type your biography (maximum of 90 characters):");
    gotoxy(STARTING_DEFAUT_X_POSITION,45); printf("Press 'Esc' to cancel data input and go back without saving");
    
    do
    {
        gotoxy(STARTING_DEFAUT_X_POSITION,26);
        if(type_info(verification_string, 90, 0))
        {
            clean_area(91,1,STARTING_DEFAUT_X_POSITION,26);
            gotoxy(STARTING_DEFAUT_X_POSITION,20); printf(YEL"4."WHT" Change biography");
            clean_area(50,1,STARTING_DEFAUT_X_POSITION,24);
            clean_area(61,1,STARTING_DEFAUT_X_POSITION,45);
            return;
        }
        if(!strcmp(verification_string, logged_user -> biography))
        {
            gotoxy(STARTING_DEFAUT_X_POSITION,46); printf(RED"Your new biography cannot be the same as before!"WHT);
            pause_screen();
            clean_area(91,1,STARTING_DEFAUT_X_POSITION,26);
            clean_area(55,1,STARTING_DEFAUT_X_POSITION,46);
            continue;
        }
        break;
    }while(1);

    strcpy(logged_user -> biography, verification_string);
    gotoxy(STARTING_DEFAUT_X_POSITION,46); printf(GRN"Your biography has been changed successfully!"WHT);
    pause_screen();
    clean_area(50,1,STARTING_DEFAUT_X_POSITION,24);
    clean_area(91,1,STARTING_DEFAUT_X_POSITION,12);
    gotoxy(STARTING_DEFAUT_X_POSITION,12); printf("%s", logged_user -> biography);
    clean_area(91,1,STARTING_DEFAUT_X_POSITION,26);
    clean_area(61,1,STARTING_DEFAUT_X_POSITION,45);
    clean_area(55,1,STARTING_DEFAUT_X_POSITION,46);
    gotoxy(STARTING_DEFAUT_X_POSITION,20); printf(YEL"4."WHT" Change biography");
}

void show_user_data(struct user *user)
{
    gotoxy(STARTING_DEFAUT_X_POSITION,5); printf(CYN0"%s's profile "WHT, user -> username);
    gotoxy(STARTING_DEFAUT_X_POSITION,7); printf(YEL"*"WHT" User's full name"YEL":"WHT" %s", user -> full_name);
    gotoxy(STARTING_DEFAUT_X_POSITION,8); printf(YEL"*"WHT" User's social engagement"YEL":"WHT" %s", user -> social_engagement);
    gotoxy(STARTING_DEFAUT_X_POSITION,9); printf(YEL"*"WHT" User's address"YEL":"WHT" %s", user -> address);
    gotoxy(STARTING_DEFAUT_X_POSITION,10); printf(YEL"*"WHT" User's biography"YEL":"WHT);
    gotoxy(STARTING_DEFAUT_X_POSITION,12); printf("%s", user -> biography);
    gotoxy(36,16); for(int i = 0; i < 94; printf("-"), i++);
}

void edit_profile(struct user *logged_user)
{
    char case_edit;
    for(;;)
    {   
        gotoxy(STARTING_DEFAUT_X_POSITION,17); printf(YEL"1."WHT" Change full name");
        gotoxy(STARTING_DEFAUT_X_POSITION,18); printf(YEL"2."WHT" Change social engagement");
        gotoxy(STARTING_DEFAUT_X_POSITION,19); printf(YEL"3."WHT" Change address");
        gotoxy(STARTING_DEFAUT_X_POSITION,20); printf(YEL"4."WHT" Change biography");
        gotoxy(STARTING_DEFAUT_X_POSITION,21); printf(YEL"5."WHT" Change password");
        gotoxy(STARTING_DEFAUT_X_POSITION,22); printf(YEL"6."WHT" Go back");

        case_edit = _getch();
        fflush(stdin);
        switch (case_edit)
        {
            case '1':
                change_full_name(logged_user);
                break;

            case '2':
                change_social_engagement(logged_user);
                break;

            case '3':
                change_address(logged_user);
                break;

            case '4':
                change_biography(logged_user);
                break;

            case '5':
                change_password(logged_user);
                break;

            case '6':
                clean_area(30,6,STARTING_DEFAUT_X_POSITION,17);
                gotoxy(STARTING_DEFAUT_X_POSITION,15); printf(YEL"1."WHT" Edit profile");
                return;
        }
    }
}

void manage_profile(struct user *logged_user)
{
    gotoxy(2,16); printf(CYN"3. My profile settings"WHT);
    show_user_data(logged_user);
    gotoxy(STARTING_DEFAUT_X_POSITION,15); printf(YEL"1."WHT" Edit profile");
    gotoxy(56,15); printf(YEL"2."WHT" Go back");

    for(char case_manage;;)
    {
        case_manage = _getch();
        fflush(stdin);
        if(case_manage == '2')
        {
            clean_area(94,41,36,5);
            gotoxy(2,16); printf(""YEL"3."WHT" My profile settings");
            return;
        }
        else if(case_manage == '1')
        {
            gotoxy(STARTING_DEFAUT_X_POSITION,15); printf(CYN"1. Edit profile"WHT);
            edit_profile(logged_user);
        }
    }
}

void full_profile_actions(struct user *logged_user, struct user *found_user)
{
    char switch_case;
    show_user_data(found_user);
    gotoxy(STARTING_DEFAUT_X_POSITION,45); clean_area(60,1,STARTING_DEFAUT_X_POSITION,45);
    gotoxy(STARTING_DEFAUT_X_POSITION,15); printf(YEL"1."WHT" Send message");
    gotoxy(55,15); printf(YEL"2."WHT" Add as friend");
    gotoxy(74,15); printf(YEL"3."WHT" Show user's friends");
    gotoxy(99,15); printf(YEL"4."WHT" See user's feed");
    gotoxy(120,15); printf(YEL"5."WHT" Return");

    for(;;)
    {
        switch_case = _getch();
        fflush(stdin);

        switch (switch_case)
        {
        case '1':
            send_message(found_user, logged_user);
            break;
        
        case '2':
            add_friend(logged_user, found_user);
            break;

        case '3':
            clean_area(92,30,STARTING_DEFAUT_X_POSITION,17);
            gotoxy(STARTING_DEFAUT_X_POSITION,17); printf(YEL"*"WHT" "CYN0"%s"WHT"'s friends list:", found_user -> username);
            print_my_friends(found_user, 65, 17);
            break;

        case '4':
            clean_area(92,30,STARTING_DEFAUT_X_POSITION,17);
            print_feed_posts(found_user, 17);
            break;

        case '5':
            clean_area(94,42,36,5);
            gotoxy(STARTING_DEFAUT_X_POSITION,45); printf("Press 'Esc' to cancel data input and go back without saving");
            clean_area(21,1,92,2);
            return;
        }
    }
}