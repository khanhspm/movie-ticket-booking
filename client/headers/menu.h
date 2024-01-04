void viewWelcome(){
    printf("--------------Welcome to HTV-SPM------------------\n\n");
    printf("1. Login to HTV-SPM\n");
    printf("2. Register for HTV-SPM\n");
    printf("3. Exit HTV-SPM\n\n");
    printf("---------------------------------------------------\n");
}

/**
 * @function viewLogin: view the login information
 * 
 * @param username : the username to login
 * @param password : the password to login
 */
void viewLogin(char username[], char password[]){
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);
}

void viewRegister(char *name, char *username, char *password) {
    printf("Registration\n");
    printf("Full Name: ");
    memset(name, 0, 255);
    fgets(name, 255, stdin);    // lay ca dau cach
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);
}

void viewAdmin(){
    printf("--------------Welcome to HTV-SPM------------------\n\n");
    printf("1. Add new film\n");
    printf("2. Announcing film \n");
    printf("3. Edit announced film\n");
    printf("4. Logout\n\n");
    printf("---------------------------------------------------\n");
}

void viewUser(){
    printf("--------------Welcome to HTV-SPM------------------\n\n");
    printf("1. Browse film catalogs\n");
    printf("2. Search film \n");
    printf("3. Book ticket\n");
    printf("4. Logout\n\n");
    printf("5. Change Password\n")
    printf("---------------------------------------------------\n");
}

/**
 * @function addNewFilm: add new film to database
 * 
 * @param title : name of new film
 * @param category : category of new film
 * @param show_time : show time of new film
 */
void addNewFilm(char title[], char category[], char show_time[]){
    printf("Title: ");
    title[0] = '\0';
    fgets(title, 255, stdin);
    printf("Category: ");
    category[0] = '\0';
    fgets(category, 255, stdin);
    printf("Show time: ");
    show_time[0] = '\0';
    fgets(show_time, 255, stdin);    
}

void browseFilm(){
    printf("--------------Welcome to HTV-SPM------------------\n\n");
    printf("1. Browse film follow title\n");
    printf("2. Browse film follow category\n");
    printf("3. Browse film follow theater\n");
    printf("4. Browse film follow show time\n");
    printf("5. Return\n\n");
    printf("---------------------------------------------------\n");
}

void getTitleFilm(char title[]){
    printf("Title: ");
    title[0] = '\0';
    fgets(title, 255, stdin);
}
