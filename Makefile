# Makefile for project

# Name of output file
OUTPUT_CLIENT = client_out
OUTPUT_SERVER = server_out

# List file .c
SRC_CLIENT = client/client.c
SRC_SERVER = server/server.c

all: $(OUTPUT_CLIENT) $(OUTPUT_SERVER)

# Compiler
CC = gcc

# Flags for compiler
CFLAGS = -I./ -lm

# Rules for compiler
$(OUTPUT_CLIENT): $(SRC_CLIENT) 
	$(CC) -pthread -o $(OUTPUT_CLIENT) $(SRC_CLIENT) $(CFLAGS) 
$(OUTPUT_SERVER): $(SRC_SERVER)
	$(CC) -pthread -o $(OUTPUT_SERVER) $(SRC_SERVER) $(CFLAGS)

# Delete files that are not in the main
clean:
	rm -f $(OUTPUT_CLIENT) $(OUTPUT_SERVER) 