
#define RRQ 1           //A write request packet
#define WRQ 2           //A read request packet
#define DATA 3           //An acknowledgement packet
#define ACK 4          //A data packet
#define ERROR 5         //An error packet    

#define BUF_SIZE 516    //Block size

typedef struct packet_struct{
    int opcode;                             //Type of the packet
    char *filename;                         //Filename -> Only if a WRQ or RRQ
    int mode;                             //mode -> Only if WRQ or RRQ
    int block_number;                       //Block number -> For ACK and DATA packets
    int error_code;                         //Error code for ERROR packets
    char *err_message;                      //Error message for ERROR packets
    char *data_buffer;             //Data buffer which contains a data    
} packet; 


/*functions*/

void init_packet(packet *);                 //Initialises a packet structure
int strip_raw_packet(char *, int, packet *);           //Takes the TFTP header + data and returns a pointer to the corresponding packet structure
char *create_raw_packet(packet * );         //Takes the packet struct pointer and returns the string    

/*Some other functions*/

int is_read_request(int);                   //is read request ?
int is_write_request(int);                  //is write request ?
int is_data_packet(int);					//is data packet ?
int is_error_packet(int);					//is error packet ?
int is_ack_packet(int);						//is acknowledgement packet ?