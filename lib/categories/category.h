struct Category{
    unsigned long id;
    char name[255];
    unsigned long quantity_seats;
    unsigned long cinema_id;
    unsigned long status;
};
typedef struct Category category;

struct NodeCategory{
	category data;
	struct NodeCategory *next;
};
typedef struct NodeCategory* nodeCategory;
