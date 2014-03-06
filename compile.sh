#!/bin/sh
#Run this to compile the client
gcc -o client main.c client.c packet.c packet.h types/ack.c types/data_packet.c types/error_packet.c types/error_packet.h types/request_packet.c types/request_packet.h