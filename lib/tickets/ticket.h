struct Ticket{
    unsigned long id;
    char name[255];
    unsigned long quantity_seats;
    unsigned long cinema_id;
    unsigned long status;
};
typedef struct Ticket ticket;

struct NodeTicket{
	ticket data;
	struct NodeTicket *next;
};
typedef struct NodeTicket* nodeTicket;
