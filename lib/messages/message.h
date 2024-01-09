#ifndef MESSAGE_H
#define MESSAGE_H

/**
 * @brief Get the Type Message object
 * 
 * @param message : The Message from client
 * @return char* 
 */
char* getTypeMessage(char *message);

/**
 * @brief Make LOGIN message to send to server
 * 
 * @param username : The username to login
 * @param password : The password to login
 * @param message : The message to send to server
 */
void makeLoginMessage(char *username, char *password, char *message);

/**
 * @brief break LOGIN request
 * 
 * @param username : username for login
 * @param password : password for login
 */
void getLoginMessage(char **username, char **password);

/**
 * @brief Make REGISTER message to send to server
 * 
 * @param username : username for register
 * @param password :password for register
 * @param message : the message to send to server
 */
void makeRegisterMessage(char *name,char *username, char *password, char *message);
void getRegisterMessage(char **name, char **username, char **password);

void makeChangePasswordMessage(char *username, char *oldPassword, char *newPassword, char *message);
void getChangePasswordMessage(char **username, char **oldPassword, char **newPassword);

/**
 * @brief Make LOGOUT message to send to server
 * 
 * @param message : the message to send to send
 */
void makeLogoutMessage(char *message);

void makeAddNewFilmMessage(char *title, char *category_id, char *show_time, char *description ,char *message);
void getAddNewFilmMessage(char **title, char **category_id, char **show_time, char **description);

void makeSearchFilmByTitleMessage(char *title, char *message);
void getSearchFilmByTitleMessage(char **title);

void makeShowCategoryMessage(char *message);

void makeShowCinemaMessage(char *message);

void makeBrowseFollowCategoryMessage(char *category_id, char *message);

void makeBrowseFollowCinemaMessage(char *cinema_id, char *message);

void getCategoryIDMessage(char **category_id);

void getCinemaIDMessage(char **cinema_id);

void makeShowPremieredTimeMessage(char *message);

void makeBrowseFollowPremieredTimeMessage(char *premiered_time_id, char *message);

void getPremieredTimeIDMessage(char **premiered_time_id);
#endif