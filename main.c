#include "packet.h"
#include "types/request_packet.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void print_help();	//prints the usage instructions

int main(int argc, char **argv){

	int mode;
	int type;

	if(argc != 4 && argc != 2 && argc != 5)
		print_error("Invalid arguments provided. Use -h for help");

	if(!strcmp( argv[1], "-ra" )){
		type = RRQ;
		mode = NETASCII;
	}
	else if(!strcmp( argv[1], "-ro" )){
		type = RRQ;
		mode = OCTET;
	}
	else if(!strcmp(argv[1], "-wa" )){
		type = WRQ;
		mode = NETASCII;
	}
	else if( !strcmp( argv[1], "-wo" ) ){
		type = WRQ;
		mode = OCTET;
	}
	else if(!strcmp( argv[1], "-h") ){
		print_help();
		return;
	}
	else{
		print_error("Invalid arguments provided. Use -h for help");
	}

	if(argc == 5){
		start_client(type,argv[2],mode,argv[3], argv[4]);
	}

    else start_client(type,argv[2],mode,argv[3], NULL);
    return 0;
	
}

/*Prints help*/
/*Triggered by -h option*/
void print_help(){
	printf("Usage:\n\nclient [-h] [type] [filepath] [hostname] [port]\n\n");
	printf("-h\tShows this usage instructions\n\n");
	printf("Type:\n\n");
	printf("-ra\tRequests a read in NETASCII mode\n");
	printf("-ro\tRequests a read in OCTET Mode\n");
	printf("-wa\tRequests a write in NETASCII mode\n");
	printf("-wo\tRequests a write in OCTET mode\n\n");
	printf("filepath\tPath to file to read or write\n");
	printf("hostname\tIP Address or hostname\n");
	printf("port\t\tOptional.Default is 69\n\n");
}