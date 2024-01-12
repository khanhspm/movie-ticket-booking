#include <stdio.h>
#include <string.h>

char* getTypeMessage(char *message){
    return strtok(message, "\r\n");
}

/**
 * @brief Create a message for user login.
 *
 * @param username: User's username.
 * @param password: User's password.
 * @param message: Pointer to store the created message.
 */
void makeLoginMessage(char *username, char *password, char *message){
    strcpy(message, "LOGIN\r\n");
    strcat(message, username);
    strcat(message, "\r\n");
    strcat(message, password);
    strcat(message, "\r\n");
}

/**
 * @brief Extract login information from a message.
 *
 * @param username: Pointer to store the extracted username.
 * @param password: Pointer to store the extracted password.
 */
void getLoginMessage(char **username, char **password){
    *username = strtok(NULL, "\r\n");
    *password = strtok(NULL, "\r\n");
}

/**
 * @brief Create a message for user registration.
 *
 * @param name: User's name.
 * @param username: User's username.
 * @param password: User's password.
 * @param message: Pointer to store the created message.
 */
void makeRegisterMessage(char *name,char *username, char *password, char *message){
    strcpy(message, "REGISTER\r\n");
    strcat(message, name);
    strcat(message, "\r\n");
    strcat(message, username);
    strcat(message, "\r\n");
    strcat(message, password);
    strcat(message, "\r\n");
}

/**
 * @brief Extract registration information from a message.
 * @param name: Pointer to store the extracted name.
 * @param username: Pointer to store the extracted username.
 * @param password: Pointer to store the extracted password.
 */
void getRegisterMessage(char **name, char **username, char **password){
    *name = strtok(NULL, "\r\n");
    *username = strtok(NULL, "\r\n");
    *password = strtok(NULL, "\r\n");
}

/**
 * @brief Create a message for changing the password.
 *
 * @param username: User's username.
 * @param oldPassword: User's old password.
 * @param newPassword: User's new password.
 * @param message: Pointer to store the created message.
 */
void makeChangePasswordMessage(char *username, char *oldPassword, char *newPassword, char *message) {
    strcpy(message, "CHANGE_PASSWORD\r\n");
    strcat(message, username);
    strcat(message, "\r\n");
    strcat(message, oldPassword);
    strcat(message, "\r\n");
    strcat(message, newPassword);
    strcat(message, "\r\n");
}

/**
 * @brief Extract change password information from a message.
 *
 * @param username: Pointer to store the extracted username.
 * @param oldPassword: Pointer to store the extracted old password.
 * @param newPassword: Pointer to store the extracted new password.
 */
void getChangePasswordMessage(char **username, char **oldPassword, char **newPassword) {
    *username = strtok(NULL, "\r\n");
    *oldPassword = strtok(NULL, "\r\n");
    *newPassword = strtok(NULL, "\r\n");
}

/**
 * @brief Create a message for logging out.
 *
 * @param message: Pointer to store the created message.
 */
void makeLogoutMessage(char *message){
    strcpy(message, "LOGOUT\r\n");
}

/**
 * @brief Create a message for showing categories.
 *
 * @param message: Pointer to store the created message.
 */
void makeShowCategoryMessage(char *message){
    strcpy(message, "SHOW_CATEGORY\r\n");
}


/**
 * @brief Create a message for showing cinemas.
 *
 * @param message: Pointer to store the created message.
 */
void makeShowCinemaMessage(char *message){
    strcpy(message, "SHOW_CINEMA\r\n");
}

/**
 * @brief Create a message for showing premiered times.
 *
 * @param message: Pointer to store the created message.
 */
void makeShowPremieredTimeMessage(char *message){
    strcpy(message, "SHOW_PREMIERED_TIME\r\n");
}

/**
 * @brief Create a message for showing post-film information.
 *
 * @param message: Pointer to store the created message.
 */
void makeShowPostFilmMessage(char *message){
    strcpy(message, "SHOW_POST_FILM\r\n");
}

/**
 * @brief Create a message for adding a new film.
 *
 * @param title: Title of the new film.
 * @param category_id: ID of the film's category.
 * @param show_time: Show time of the film.
 * @param description: Description of the film.
 * @param message: Pointer to store the created message.
 */
void makeAddNewFilmMessage(char *title, char *category_id, char *show_time, char *description ,char *message){
    strcpy(message, "NEW_FILM\r\n"); 
    strcat(message, title);
    strcat(message, "\r\n");
    strcat(message, category_id);
    strcat(message, "\r\n");
    strcat(message, show_time);
    strcat(message, "\r\n");
    strcat(message, description);
    strcat(message, "\r\n");
}

/**
 * @brief Create a message for announcing a film.
 *
 * @param film_id: ID of the film.
 * @param cinema_id: ID of the cinema.
 * @param premiered_time_id: ID of the premiered time.
 * @param date: Date of the film announcement.
 * @param message: Pointer to store the created message.
 */
void makeAnnounceFilmMessage(char *film_id, char *cinema_id, char *premiered_time_id, char *date, char *message){
    strcpy(message, "POST_FILM\r\n");
    strcat(message, film_id);
    strcat(message, "\r\n");
    strcat(message, cinema_id);
    strcat(message, "\r\n");
    strcat(message, premiered_time_id);
    strcat(message, "\r\n");
    strcat(message, date);
    strcat(message, "\r\n");
}

/**
 * @brief Extract information from a message for adding a new film.
 *
 * @param title: Pointer to store the extracted film title.
 * @param category_id: Pointer to store the extracted category ID.
 * @param show_time: Pointer to store the extracted show time.
 * @param description: Pointer to store the extracted description.
 */
void getAddNewFilmMessage(char **title, char **category_id, char **show_time, char **description){
    *title = strtok(NULL, "\r\n");
    *category_id = strtok(NULL, "\r\n");
    *show_time = strtok(NULL, "\r\n");
    *description = strtok(NULL, "\r\n");
}

/**
 * @brief Extract information from a message for announcing a film.
 *
 * @param film_id: Pointer to store the extracted film ID.
 * @param cinema_id: Pointer to store the extracted cinema ID.
 * @param premiered_time_id: Pointer to store the extracted premiered time ID.
 * @param date: Pointer to store the extracted date.
 */
void getAnnounceFilmMessage(char **film_id, char **cinema_id, char **premiered_time_id, char **date){
    *film_id = strtok(NULL, "\r\n");
    *cinema_id = strtok(NULL, "\r\n");
    *premiered_time_id = strtok(NULL, "\r\n");
    *date = strtok(NULL, "\r\n");
}

/**
 * @brief Create a message for searching films by title.
 *
 * @param title: Title to search for.
 * @param message: Pointer to store the created message.
 */
void makeSearchFilmByTitleMessage(char *title, char *message){
    strcpy(message, "TITLE\r\n");
    strcat(message, title);
    strcat(message, "\r\n");
}

/**
 * @brief Extract information from a message for searching films by title.
 *
 * @param title: Pointer to store the extracted film title.
 */
void getSearchFilmByTitleMessage(char **title){
    *title = strtok(NULL, "\r\n");
}

/**
 * @brief make browser film follow category message
 * 
 * @param category_id 
 * @param message 
 */
void makeBrowseFollowCategoryMessage(char *category_id, char *message){
    strcpy(message, "BROWSE_CATEGORY\r\n");
    strcat(message, category_id);
    strcat(message, "\r\n");
}

/**
 * @brief make browse film follow cinema message
 * 
 * @param cinema_id 
 * @param message 
 */
void makeBrowseFollowCinemaMessage(char *cinema_id, char *message){
    strcpy(message, "BROWSE_CINEMA\r\n");
    strcat(message, cinema_id);
    strcat(message, "\r\n");
}
/**
 * @brief make browse film follow cinema message
 * 
 * @param premiered_time_id 
 * @param message 
 */
void makeBrowseFollowPremieredTimeMessage(char *premiered_time_id, char *message){
    strcpy(message, "BROWSE_PREMIERED_TIME\r\n");
    strcat(message, premiered_time_id);
    strcat(message, "\r\n");
}

/**
 * @brief Get the Category ID Message object
 * 
 * @param category_id 
 */
void getCategoryIDMessage(char **category_id){
    *category_id = strtok(NULL, "\r\n");
}

/**
 * @brief Get the Cinema ID Message object
 * 
 * @param cinema_id 
 */
void getCinemaIDMessage(char **cinema_id){
    *cinema_id = strtok(NULL, "\r\n");
}

/**
 * @brief Get the Premiered Time ID Message object
 * 
 * @param premiered_time_id 
 */
void getPremieredTimeIDMessage(char **premiered_time_id){
    *premiered_time_id = strtok(NULL, "\r\n");
}