A simple implementation of a TFTP client. Supports both OCTET and NETASCII modes.

Requirements : Linux, gcc

### Compiling

* Run `./compile.sh` and check if the executable client is produced.
* If permissions are denied, run `sudo chmod +x compile.sh` and repeat step 1.

### How to Run ?

* Run `./client -h` to see the usage instructions. Here's how it looks
```
Usage:

client [-h] [type] [filepath] [hostname] [port]

-h	Shows this usage instructions

Type:

-ra	Requests a read in NETASCII mode
-ro	Requests a read in OCTET Mode
-wa	Requests a write in NETASCII mode
-wo	Requests a write in OCTET mode

filepath	Path to file to read or write
hostname	IP Address or hostname
port		Optional.Default is 69
```

### Source Documentation

```
1) All the source files related to different packet types are in ./types folder.

./TYPES:

error_packet.h  ----- Contains the constants for each error packet type.
error_packet.c  ----- Contains the functions for handling error packets.
request_packet.h ---- Contains the constants for request packets(Both Read and Write requests and both NETASCII and OCTET mode).
request_packet.c ---- Contains the functions for handling request packets.
ack.c           ----- Contains the constants, functions for handling acknowledgement packets.
data_packet.c   ----- Contains the constants, functions for handling data packets.

2) All the source files related to the actual client are in . folder.

.:

packet.h         --- Contains the packet structure, constants and declarations of functions for packet handling.
packet.c         --- Contains definitions of functions for packet handling.
client.c         --- Contains the actual client handling functions.
main.c           --- Contains code that checks for correct arguments and call start_client().
```