struct PremieredTime{
    unsigned long id;
    char start_time[255];
    char finish_time[255];
};
typedef struct PremieredTime premieredTime;

struct NodePremieredTime{
	premieredTime data;
	struct NodePremieredTime *next;
};
typedef struct NodePremieredTime* nodePremieredTime;
