struct Cinema{
    unsigned long id;
    char name[255];
    char address[255];
};
typedef struct Cinema cinema;

struct NodeCinema{
	cinema data;
	struct NodeCinema *next;
};
typedef struct NodeCinema* nodeCinema;
