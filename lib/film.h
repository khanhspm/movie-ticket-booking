struct Film{
    int id;
    char title[255];
    char category[255];
    char show_time[255];
};
typedef struct Film film;

struct Node{
	film data;
	struct Node *next;
};
typedef struct Node* node;

/**
 * @function checkEmptyList: checking list of nodes is NULL
 * 
 * @param list: list of nodes to check
 * 
 * @return: empty list
*/
int checkEmptyList(node list){
	return list == NULL;
}

/**
 * @function addNewNode: add a new node to the list when list is empty
 * 
 * @param head: head of list
 * @param x: node to add
*/
void addNewNode(node* head, film x){
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    p->data = x;
    p->next = NULL;
    if(checkEmptyList(*head)){
        *head = p;
    }
}

/**
 * @function addNode: add a node to the list
 * 
 * @param head: head of list
 * @param x: node to add
*/
void addNode(node* head, film x){
    if(checkEmptyList(*head)){
        addNewNode(head, x);
    }else{
        struct Node* a = *head;
        while(a->next != NULL){
            a = a->next;
        }
        struct Node* p = (struct Node*)malloc(sizeof(struct Node));
        p->data = x;
        p->next = NULL;
        a->next = p;
    }
}

/**
 * @function Title: search the film has title
 * 
 * @param head : node head of list
 * @param title : the title needed to search
 */
void searchTitle(node head, char title[]){
    int a = 0;
    if(Empty(head)){
        printf("No data!\n");
        return;
    }else{
        struct Node* p = head;
        while(p != NULL){
            if(strcmp(title, p->data.title) == 0){
                a++;
                printf("%d. %s %s %s\n", a, p->data.title, p->data.category, p->data.show_time);
            }
            p = p->next;
        }
    }
    if(a == 0) printf("The film you need search is not exist!\n");
}