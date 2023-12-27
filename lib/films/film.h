struct Film{
    unsigned long id;
    char title[255];
    unsigned long category_id;
    unsigned long show_time;
};
typedef struct Film film;

struct NodeFilm{
	film data;
	struct NodeFilm *next;
};
typedef struct NodeFilm* nodeFilm;
