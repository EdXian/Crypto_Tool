#ifndef _CMD_H_
#define _CMD_H_


#include "stdint.h"

#pragma   pack(push) 
#pragma   pack(1) 

typedef struct sync{
    uint8_t head;
    uint8_t len;
    uint8_t id;
    uint8_t status;
    uint16_t crc;
}cmd_sync_t;


typedef struct program{

    uint8_t head;
    uint8_t len;
    uint8_t id;
    uint8_t status;
    uint16_t crc;

}cmd_program_t;


typedef struct verify{

    uint8_t head;
    uint8_t len;
    uint8_t id;
    uint8_t status;
    uint16_t crc;
    
}cmd_verify_t;


typedef struct read{
    
    uint8_t head;
    uint8_t len;
    uint8_t id;
    uint8_t status;
    uint16_t crc;

}cmd_read_t;


typedef struct ack{
    uint8_t head;
    uint8_t len;
    uint8_t id;
    uint32_t code;
    uint16_t crc;
}cmd_ack_t;


#pragma   pack(pop) 

#endif