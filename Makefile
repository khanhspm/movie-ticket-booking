# Compiler
CC = gcc

# Name of output file
OUTPUT_CLIENT = client_out
OUTPUT_SERVER = server_out

# List file .c
SRC_CLIENT = client/client.c
SRC_SERVER = server/server.c
SRC_QUERYUSER = server/headers/queryUser.c
SRC_CATEGORY = lib/categories/listCategory.c
SRC_CINEMA = lib/cinemas/listCinema.c
SRC_MESSAGE = lib/messages/message.c
SRC_PREMIEREDTIME = lib/premieredTime/listPremieredTime.c
SRC_PREMIEREDTIMEFILM = lib/premieredTimeFilm/listPremieredTimeFilm.c
SRC_ROOM = lib/rooms/listRoom.c
SRC_SEAT = lib/seats/listSeat.c
SRC_SOCKET = lib/socket/socket.c
SRC_TICKET = lib/tickets/listTicket.c
SRC_USER = lib/users/listUser.c

all: $(OUTPUT_CLIENT) $(OUTPUT_SERVER)

# Compile each source file into object files
# %.o: %.c
# 	$(CC) -c $< -o $@ -I/opt/homebrew/Cellar/mysql/8.2.0_1/include -L/opt/homebrew/Cellar/mysql/8.2.0_1/lib -lmysqlclient

# Link the object files to create the final executables
$(OUTPUT_SERVER): $(SRC_SERVER) $(SRC_QUERYUSER) $(SRC_USER)
	$(CC) -pthread -o $(OUTPUT_SERVER) $(SRC_SERVER) $(SRC_QUERYUSER) $(SRC_CATEGORY) $(SRC_CINEMA) $(SRC_MESSAGE) $(SRC_PREMIEREDTIME) $(SRC_PREMIEREDTIMEFILM) $(SRC_ROOM) $(SRC_SEAT) $(SRC_SOCKET) $(SRC_TICKET) $(SRC_USER) -I/opt/homebrew/Cellar/mysql/8.2.0_1/include -L/opt/homebrew/Cellar/mysql/8.2.0_1/lib -lmysqlclient

$(OUTPUT_CLIENT): $(SRC_CLIENT)
	$(CC) -pthread -o $(OUTPUT_CLIENT) $(SRC_CLIENT) $(SRC_SOCKET) $(SRC_MESSAGE) -I/ -lm 

# Delete files that are not in the main
clean:
	rm -f *.o $(OUTPUT_CLIENT) $(OUTPUT_SERVER)
