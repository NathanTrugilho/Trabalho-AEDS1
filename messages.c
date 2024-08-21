#include "messages.h"

void send_message(struct user *found_user, struct user *logged_user)
{
    if(found_user == logged_user)
    {
        gotoxy(STARTING_DEFAUT_X_POSITION, 46); printf(RED"You cannot message yourself! <press anything to continue>"WHT);
        pause_screen();
        clean_area(92, 1, STARTING_DEFAUT_X_POSITION, 46);
        return;
    }
    clean_area(92,30,STARTING_DEFAUT_X_POSITION,17);
    char verification_message[91];
    gotoxy(STARTING_DEFAUT_X_POSITION,17); printf("Type the message you would like to send to this user (maximum of 90 characters):");
    gotoxy(STARTING_DEFAUT_X_POSITION,45); printf("Press 'Esc' to cancel data input and go back without saving");
    do
    {
        gotoxy(STARTING_DEFAUT_X_POSITION,19);
        if(type_info(verification_message, 90, 0))
        {
            clean_area(92,30,STARTING_DEFAUT_X_POSITION,17);
            clean_area(92, 1, STARTING_DEFAUT_X_POSITION, 45);
            return;
        }
        break;
    }while(1);

    struct message *new_message = (struct message *)malloc(sizeof(struct message));
    strcpy(new_message -> username, logged_user -> username);
    strcpy(new_message -> message, verification_message);
    new_message -> next_message = found_user -> next_message;
    found_user -> next_message = new_message;

    gotoxy(STARTING_DEFAUT_X_POSITION, 46); printf(GRN"Message sent successfully! <press anything to continue>"WHT);
    pause_screen();
    clean_area(92, 1, STARTING_DEFAUT_X_POSITION, 17);
    clean_area(92, 1, STARTING_DEFAUT_X_POSITION, 19);
    clean_area(92, 1, STARTING_DEFAUT_X_POSITION, 45);
    clean_area(92, 1, STARTING_DEFAUT_X_POSITION, 46);
}

void manage_messages(struct user *logged_user)
{
    gotoxy(2,12); printf(CYN"2. Manage messages"WHT);
    if(logged_user -> next_message == NULL)
    {
        gotoxy(STARTING_DEFAUT_X_POSITION,5); printf(YEL"*"WHT" You have no new messages! <press anything to return>");
        pause_screen();
        clean_area(55,1,STARTING_DEFAUT_X_POSITION,5);
        gotoxy(2,12); printf(YEL"2."WHT" Manage messages");
        return;
    }
    struct message *current, *previous;
    short line = 7;
    gotoxy(22,12); printf(" ");
    gotoxy(STARTING_DEFAUT_X_POSITION,5); printf(YEL"*"WHT" Your messages(from newer to older):");
    current = logged_user -> next_message;
    logged_user -> next_message = NULL;

    while (current != NULL)
    {
        gotoxy(STARTING_DEFAUT_X_POSITION, line); printf(YEL"*"WHT" %s's message:", current -> username);
        gotoxy(STARTING_DEFAUT_X_POSITION, line + 1); printf("%s", current -> message);
        previous = current;
        current = current -> next_message;
        free(previous);
        line = line + 3;
    }
    gotoxy(STARTING_DEFAUT_X_POSITION, 46); printf("<Press anything to return>");
    pause_screen();
    clean_area(94,42,36,5);
    gotoxy(2,12); printf(YEL"2."WHT" Manage messages");
}