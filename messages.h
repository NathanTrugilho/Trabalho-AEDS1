#ifndef MESSAGES_H
#define MESSAGES_H

#include "shared.h"
/**
 * @brief Função que envia uma mensagem para o usuário desejado.
 * 
 * @param found_user Ponteiro para o usuário que receberá a mensagem.
 * @param logged_user Ponteiro para o usuário que enviou a mensagem (usuário logado).
 */
void send_message(struct user *found_user, struct user *logged_user);

/**
 * @brief Função que gerencia as mensagens recebidas.
 * 
 * @param logged_user Ponteiro para o usuário logado no momento.
 */
void manage_messages(struct user *logged_user);

#endif