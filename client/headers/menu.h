void viewWelcome(){
    printf("--------------Welcome to HTV-SPM------------------\n\n");
    printf("1. Login to HTV-SPM\n");
    printf("2. Register for HTV-SPM\n");
    printf("3. Exit HTV-SPM\n\n");
    printf("---------------------------------------------------\n");
}

void viewLogin(char username[], char password[]){
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);
}
