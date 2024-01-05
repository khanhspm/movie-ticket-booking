struct Category{
    unsigned long id;
    char name[255];
};
typedef struct Category category;

struct NodeCategory{
	category data;
	struct NodeCategory *next;
};
typedef struct NodeCategory* nodeCategory;
