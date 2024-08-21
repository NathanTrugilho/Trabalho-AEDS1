#ifndef USER_PROFILES_H
#define USER_PROFILES_H

#include "shared.h"
#include "user_authentication.h"
#include "friends_list.h"
#include "messages.h"

/**
 * @brief Função que faz a busca de outros usuários cadastrados na rede social.
 * 
 * @param logged_user Ponteiro para o usuário que está logado no momento. (É necessário para adicionar como amigo e outras funcionalidades)
 */
void search_users(struct user *head, struct user *logged_user);

/**
 * @brief Função que altera o nome completo do usuário logado.
 * 
 * @param logged_user Ponteiro para o usuário que está logado no momento.
 */
void change_full_name(struct user *logged_user);

/**
 * @brief Função que altera a ocupação social do usuário logado.
 * 
 * @param logged_user Ponteiro para o usuário que está logado no momento.
 */
void change_social_engagement(struct user *logged_user);

/**
 * @brief Função que altera o endereço do usuário que está logado.
 * 
 * @param logged_user Ponteiro para o usuário que está logado no momento.
 */
void change_address(struct user *logged_user);

/**
 * @brief Função que altera a senha do usuário que está logado.
 * 
 * @param logged_user Ponteiro para o usuário que está logado no momento.
 */
void change_password(struct user *logged_user);

/**
 * @brief Função que altera a biografia do usuário que está logado.
 * 
 * @param logged_user Ponteiro para o usuário que está logado no momento.
 */
void change_biography(struct user *logged_user);

/**
 * @brief Função que imprime na tela os dados do usuário que foi encontrado.
 * 
 * @param username Ponteiro para o usuário que terá seus dados impressos.
 */
void show_user_data(struct user *user);

/**
 * @brief Função que dará ao usuário a escolha de qual informação este deseja alterar.
 * 
 * @param logged_user Ponteiro para o usuário que está logado no momento.
 */
void edit_profile(struct user *logged_user);

/**
 * @brief Função que mostra os dados do usuário logado e o possibilita a troca dos mesmos.
 * 
 * @param logged_user Ponteiro para o usuário que está logado no momento.
 */
void manage_profile(struct user *logged_user);

/**
 * @brief Função que permite o usuário logado navegar pelo perfil de outro usuário. É nela que o usuário pode escolher enviar mensagens, adicionar como amigo, etc.
 * 
 * @param logged_user Ponteiro para o usuário que está logado no momento.
 * @param found_user Ponteiro para o usuário que sofrerá a navegação.
 */
void full_profile_actions(struct user *logged_user, struct user *found_user);

#endif