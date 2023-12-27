struct Room{
    unsigned long id;
    char name[255];
    unsigned long quantity_seats;
    unsigned long cinema_id;
    unsigned long status;
};
typedef struct Room room;

struct NodeRoom{
	room data;
	struct NodeRoom *next;
};
typedef struct NodeRoom* nodeRoom;
