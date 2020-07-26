#include <stdio.h>
#include <sys/socket.h> //for socket(), connect(), send(), recv() functions
#include <arpa/inet.h> // different address structures are declared here
#include <stdlib.h> // atoi() which convert string to integer
#include <string.h>
#include <unistd.h> // close() function
#define BUFSIZE 32
#define PACKET_SIZE 100

enum packet_type {ACK, DATA};
struct in_addr
{
	unsigned long s_addr; /* Internet address (32 bits) */
};

struct sockaddr_in
{
	unsigned short sin_family; /* Internet protocol (AF_INET) */
	unsigned short sin_port; /* Address port (16 bits) */
	struct in_addr sin_addr; /* Internet address (32 bits) */
	char sin_zero[8]; /* Not used */
}

struct packet_struct
{
	int size;
	int seq_no;
	bool last;
	packet_type kind;
	int channel_id;
	char payload[PACKET_SIZE];
}
	