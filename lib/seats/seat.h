struct Seat{
    unsigned long id;
    char name[255];
    unsigned long room_id;
    unsigned long status;
};
typedef struct Seat seat;

struct NodeSeat{
	seat data;
	struct NodeSeat *next;
};
typedef struct NodeSeat* nodeSeat;
