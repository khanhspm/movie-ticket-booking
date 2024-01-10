struct PremieredTimeFilm{
    unsigned long id;
    unsigned long film_id;
    unsigned long premiered_time_id;
    unsigned long cinema_id;
    char date[255];
};
typedef struct PremieredTimeFilm premieredTimeFilm;

struct NodePremieredTimeFilm{
	premieredTimeFilm data;
	struct NodePremieredTimeFilm *next;
};
typedef struct NodePremieredTimeFilm* nodePremieredTimeFilm;
