/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This file contains the "main" function for a project.

  Description:
    This file contains the "main" function for a project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state
    machines of all modules in the system
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes
#include "string.h"
#include "stdio.h"
#include "atca_iface.h"                // SYS function prototypes

#include "cryptoauthlib.h"
#include "host/atca_host.h"
//#include "cmd.h"
#include "mavlink.h"
// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************
void delay(){
    for(uint16_t i=0;i<1000;i++){
    for(uint16_t j=0;j<100;j++){
        asm("nop");
    }
}
}


#define CHECK_STATUS( status )\
{\
if(status != ATCA_SUCCESS)\
{\
sprintf(UartWriteBuf, "Error: Line %d in %s\r\n",__LINE__, __FILE__);\
SYS_CONSOLE_Write(consoleHandleUSB, UartWriteBuf, strlen(UartWriteBuf));\
}\
}\


SYS_TIME_HANDLE tmrHandle_USB_hello;
SYS_CONSOLE_HANDLE consoleHandleUSB;
SYS_TIME_HANDLE tmrHandle;
SYS_CONSOLE_HANDLE consoleHandle ;
char UartWriteBuf[128];
char UartReadBuf[30];



void OutputData(char* label, uint8_t *buffer, size_t len)
{
    
     sprintf(UartWriteBuf,label);
     SYS_CONSOLE_Write(consoleHandleUSB, UartWriteBuf, strlen(UartWriteBuf));
    
    for( int i=0 ; i<len ; i++ )
    {
        sprintf(UartWriteBuf, "0x%02X,  ",buffer[i]);
        SYS_CONSOLE_Write(consoleHandleUSB, UartWriteBuf, strlen(UartWriteBuf));
        if( (i+1)%16==0 )
        {
             sprintf(UartWriteBuf, "\r\n");
              SYS_CONSOLE_Write(consoleHandleUSB, UartWriteBuf, strlen(UartWriteBuf));
        }
    }
    sprintf(UartWriteBuf, "\r\n");
    SYS_CONSOLE_Write(consoleHandleUSB, UartWriteBuf, strlen(UartWriteBuf));
}



extern ATCAIfaceCfg atecc608_0_init_data;
ATCA_STATUS status;
uint8_t serial_number[ATCA_SERIAL_NUM_SIZE];
SYS_TIME_HANDLE timer = SYS_TIME_HANDLE_INVALID;
 uint8_t config_data[ATCA_ECC_CONFIG_SIZE];
 uint8_t read_config_data[ATCA_ECC_CONFIG_SIZE];

 uint8_t config_slot_1[4] = {0x00,0x00,0x80,0x80};
 uint8_t key_slot_1[4] = {0x00,0x00,0x3e,0x00};

 
 uint8_t default_config[128]={
    0x01,  0x23,  0x94,  0xD1,  0x00,  0x00,  0x60,  0x02,  0x55,  0x12,  0xD1,  0x6E,  0xEE,  0x01,  0x51,  0x00,
    0xC0,  0x00,  0x00,  0x00,  0x83,  0x20,  0x80,  0x80,  0x8F,  0x20,  0xC4,  0x8F,  0x8F,  0x8F,  0x8F,  0x8F,
    0x9F,  0x8F,  0xAF,  0x8F,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,
    0x00,  0x00,  0xAF,  0x8F,  0x00,  0xFF,  0xFF,  0xFF,  0x00,  0x00,  0x00,  0x00,  0xFF,  0xFF,  0xFF,  0xFF,
    0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,
    0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x55,  0x00,  0xFF,  0xFF,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,
    0x33,  0x00,  0x3E,  0x00,  0x33,  0x00,  0x1C,  0x00,  0x1C,  0x00,  0x1C,  0x00,  0x1C,  0x00,  0x1C,  0x00,
    0x3C,  0x00,  0x3C,  0x00,  0x3C,  0x00,  0x3C,  0x00,  0x3C,  0x00,  0x3C,  0x00,  0x3C,  0x00,  0x1C,  0x00
 };
 
 uint8_t  pv_key[]=
 {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
0x09, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
 
 uint8_t  read_pv_key[32];
 
uint8_t atecc_provision(){
    uint8_t ret= 0;
    bool lock_flag = false;
    //config slot 1 0x16 0x17 8080
    //key slot 1   0x62 0x63 3e00
    
//    config_data[16] = 0x80;
//    config_data[17] = 0x80;
//    
//    config_data[62] = 0x3e;
//    config_data[63] = 0x00;
    atcab_is_config_locked(&lock_flag);
    if(!lock_flag){

//         sprintf(UartWriteBuf,"ecc608 config is unlocked\n");
//         SYS_CONSOLE_Write(consoleHandleUSB, UartWriteBuf, strlen(UartWriteBuf));
        
         //write  config_slot_1
        status = atcab_read_bytes_zone(ATCA_ZONE_CONFIG, 0, 0x14, config_slot_1, 4);
        //CHECK_STATUS(status);
        
        config_slot_1[2] =  0x80 ;
        config_slot_1[3] =  0x80 ;
         
        status = atcab_write_bytes_zone(ATCA_ZONE_CONFIG, 0, 0x14, config_slot_1, 4);
        //CHECK_STATUS(status);
        if(status == ATCA_SUCCESS){
            ret|=(1<<2);
        }
        // write key_slot_1
        status = atcab_read_bytes_zone(ATCA_ZONE_CONFIG, 0, 0x60, key_slot_1, 4);
        //CHECK_STATUS(status);
        
        key_slot_1[2] =  0x3e ;
        key_slot_1[3] =  0x00 ;

        status = atcab_write_bytes_zone(ATCA_ZONE_CONFIG, 0, 0x60, key_slot_1, 4);
        //CHECK_STATUS(status);
        if(status == ATCA_SUCCESS){
            ret|=(1<<3);
        }
         
        status = atcab_lock_config_zone();
        //CHECK_STATUS(status);
        
        status = atcab_write_zone(ATCA_ZONE_DATA, 1, 0, 0, pv_key, 32 );
        
        if(status == ATCA_SUCCESS){
            ret|=(1<<4);
        }
        
        status = atcab_lock_data_zone();
        
    }else{
//        status = atcab_write_zone(ATCA_ZONE_DATA, 4, 0, 0, pv_key, 32 );
//        CHECK_STATUS(status);
     
//        status = atcab_write_zone(ATCA_ZONE_DATA, 1, 0, 0, pv_key, 32 );
//        CHECK_STATUS(status);

//        status = atcab_read_zone(ATCA_ZONE_DATA, 1, 0, 0, read_pv_key, 32 );
//        CHECK_STATUS(status);
      
//        sprintf(UartWriteBuf,"ecc608 config is locked");
//        SYS_CONSOLE_Write(consoleHandleUSB, UartWriteBuf, strlen(UartWriteBuf));
    }
    
    
    atcab_is_config_locked(&lock_flag);
    if(lock_flag){
        ret|=(1<<0);
    }else{
        ret&=~(1<<0);
    }
    
    atcab_is_data_locked(&lock_flag);
    
     if(lock_flag){
        ret|=(1<<1);
    }else{
        ret&=~(1<<1);
    }
    return ret;
}



atca_nonce_in_out_t host_nonce;

 uint8_t num_in[20] = {
    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    //try to use random number to fill num_in
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 

};

uint8_t rand_out[32];
atca_temp_key_t host_tempkey;
uint8_t digest[32];
uint8_t response[32];
atca_mac_in_out_t host_mac;


uint8_t atecc_verify(){
    
    uint8_t ret = 1;
    // handl verification on pc
    status = atcab_nonce_base(NONCE_MODE_SEED_UPDATE, 0, num_in, rand_out);
    //CHECK_STATUS(status);
    OutputData("- Random number response:\r\n", rand_out, 32);

    host_nonce.mode = NONCE_MODE_SEED_UPDATE;
    host_nonce.zero = 0;
    host_nonce.num_in = num_in;
    host_nonce.rand_out = rand_out;
    host_nonce.temp_key = &host_tempkey;
    status = atcah_nonce(&host_nonce);
    //CHECK_STATUS(status);
    OutputData("- Host Tempkey:\r\n", host_tempkey.value, 32);
    
    
    status = atcab_mac(MAC_MODE_BLOCK2_TEMPKEY|MAC_MODE_INCLUDE_SN, 1, NULL, digest);
    //CHECK_STATUS(status);
    OutputData("- digest response:\r\n", digest, 32);
   
    host_mac.mode = MAC_MODE_BLOCK2_TEMPKEY|MAC_MODE_INCLUDE_SN;
    host_mac.key_id = 1;
    host_mac.challenge = NULL;
    host_mac.key = pv_key;
    host_mac.otp = NULL;
    
   host_mac.sn = serial_number;
    host_mac.response = response;
    host_mac.temp_key = &host_tempkey;
    status = atcah_mac(&host_mac);
    //CHECK_STATUS(status);
    OutputData("- Digest out (Host claculated) :\r\n", response, 32);

    //challenge the private key
    
    for(uint8_t i=0;i<32;i++){
        if(response[i]!=digest[i]){
            ret=0xff;
            return ret;
        }
    }
    ret = 0;
    return ret;
}



#ifdef __SAMD21G18A__
void test1();
#endif

#ifdef __SAMD21G15B__
void test2();
#endif


uint8_t verify_text[]="verify ok\r\n";
uint16_t readCountGet = 0;
uint16_t readBuffer[50]={0};

mavlink_message_t msg;
mavlink_status_t msg_status;
mavlink_message_t  rmsg;

uint8_t parse_state = 0;
uint8_t rdata[50];
uint8_t tdata[50];
extern SYSTEM_OBJECTS sysObj;
SYS_STATUS sysstatus;

mavlink_sync_t sync;
mavlink_program_ack_t program_ack;
mavlink_verify_ack_t  verify_ack;
mavlink_device_sn_t sn;
mavlink_message_t msg;
uint16_t msg_len;

void output_device_status(){
    
    
    mavlink_msg_program_ack_encode(0,0,&rmsg,&program_ack);
    msg_len = mavlink_msg_to_send_buffer(tdata, &rmsg);
    SYS_CONSOLE_Write(consoleHandleUSB, tdata, msg_len);
    memset(tdata,0,sizeof(tdata));
    
          SYS_TIME_DelayMS( 100, &timer );
         while(!SYS_TIME_DelayIsComplete(timer));
         
    mavlink_msg_verify_ack_encode(0,0,&rmsg,&verify_ack);
    msg_len = mavlink_msg_to_send_buffer(tdata, &rmsg);
    SYS_CONSOLE_Write(consoleHandleUSB, tdata, msg_len);
    memset(tdata,0,sizeof(tdata));
    
          SYS_TIME_DelayMS( 100, &timer );
         while(!SYS_TIME_DelayIsComplete(timer));
    
//    for(uint8_t i=0;i<8;i++){
//        sn.sn[i] = i;
//    }
    
          
    mavlink_msg_device_sn_encode(0,0,&rmsg,&sn);
    msg_len = mavlink_msg_to_send_buffer(tdata, &rmsg);
    SYS_CONSOLE_Write(consoleHandleUSB, tdata, msg_len);
    memset(tdata,0,sizeof(tdata));
    
          SYS_TIME_DelayMS( 100, &timer );
         while(!SYS_TIME_DelayIsComplete(timer));
}


static bool triggered=false;
static void EIC_User_Handler(uintptr_t context)
{
       // output_device_status();
    triggered = true;
}

int main ( void )
{
     uint8_t ret=0;
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    SYS_TIME_DelayMS(1000, &tmrHandle_USB_hello);
    
    SYS_TIME_DelayMS( 1000, &timer );
//    consleHandlePLIB = SYS_CONSOLE_HandleGet( SYS_CONSOLE_INDEX_0 );
//    sprintf(UartWriteBuf, "Hello world !(PLIB)\r\n");
//    SYS_CONSOLE_Write(consoleHandlePLIB, UartWriteBuf, strlen(UartWriteBuf));
    consoleHandleUSB = SYS_CONSOLE_HandleGet( SYS_CONSOLE_INDEX_0);
    EIC_CallbackRegister(EIC_PIN_4,EIC_User_Handler, 0);

    
    LED1_Set();
    status = atcab_init(&atecc608_0_init_data);
    //CHECK_STATUS(status);
    
    atcab_read_serial_number((uint8_t*)&serial_number);
    OutputData("\r\nSerial Number:\r\n",serial_number,ATCA_SERIAL_NUM_SIZE);
    //CHECK_STATUS(status);

    atcab_read_config_zone(read_config_data);
    //CHECK_STATUS(status);
    OutputData("\r\nConfig Zone :\r\n",read_config_data,ATCA_ECC_CONFIG_SIZE);
    
    
    
 while ( true )
    {       
    
    if( triggered )
    {
        
        LED1_Set();
        status = atcab_init(&atecc608_0_init_data);
        //CHECK_STATUS(status);
         //atecc_provision();
//        LED1_Toggle();
        atcab_read_serial_number((uint8_t*)&serial_number);
        for(uint8_t i=0;i<9;i++){
           sn.sn[i] =  serial_number[i] ;
        }
         mavlink_msg_device_sn_encode(0,0,&msg,&sn);
         msg_len = mavlink_msg_to_send_buffer(tdata, &msg);
         SYS_CONSOLE_Write(consoleHandleUSB, tdata, msg_len);
        //OutputData("\r\nSerial Number:\r\n",serial_number,ATCA_SERIAL_NUM_SIZE);
       // CHECK_STATUS(status);
        SYS_TIME_DelayMS(300, &timer );
        while(!SYS_TIME_DelayIsComplete(timer));
        triggered=false;
        
        
        ret = atecc_provision();
        
        program_ack.status=ret;
        
        mavlink_msg_program_ack_encode(0,0,&msg,&program_ack);
        msg_len = mavlink_msg_to_send_buffer(tdata, &msg);
        SYS_CONSOLE_Write(consoleHandleUSB, tdata, msg_len);
        
        
        ret = atecc_verify();
         if(ret == 0){
             verify_ack.status = 0x55;  
         }else{
             verify_ack.status = 0xcc;
         }
        
        
        mavlink_msg_verify_ack_encode(0,0,&msg,&verify_ack);
        msg_len = mavlink_msg_to_send_buffer(tdata, &msg);
        SYS_CONSOLE_Write(consoleHandleUSB, tdata, msg_len);
        
//        if(ret == 0){
//                   sprintf(UartWriteBuf,"%s",verify_text);
//                    SYS_CONSOLE_Write(consoleHandleUSB, UartWriteBuf, strlen(UartWriteBuf));
//        }else{
//                     sprintf(UartWriteBuf,"verify fail");
//                    SYS_CONSOLE_Write(consoleHandleUSB, UartWriteBuf, strlen(UartWriteBuf));
//        }

    }
        /* Maintain state machines of all polled MPLAB Harmony modules. */
//        SERCOM4_USART_Write("test\n",5);
      //delay();
      
        SYS_Tasks ( );
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*
int main ( void )
{
     uint8_t ret=0;

    SYS_Initialize ( NULL );
    EIC_CallbackRegister(EIC_PIN_4,EIC_User_Handler, 0);
    SYS_TIME_DelayMS(1000, &tmrHandle_USB_hello);
    
    SYS_TIME_DelayMS( 1000, &timer );
//    consleHandlePLIB = SYS_CONSOLE_HandleGet( SYS_CONSOLE_INDEX_0 );
//    sprintf(UartWriteBuf, "Hello world !(PLIB)\r\n");
//    SYS_CONSOLE_Write(consoleHandlePLIB, UartWriteBuf, strlen(UartWriteBuf));
    consoleHandleUSB = SYS_CONSOLE_HandleGet( SYS_CONSOLE_INDEX_0);

         status = atcab_init(&atecc608_0_init_data);
   LED1_Set();

 while ( true )
    {     
     
//     if(triggered){
//         
//         status = atcab_read_serial_number(serial_number);
////         if(status == ATCA_SUCCESS){
////                    for(uint8_t i=0;i<ATCA_SERIAL_NUM_SIZE;i++){
////                    sn.sn[i]   =0x11;
////                 }
////         }else{
////              for(uint8_t i=0;i<ATCA_SERIAL_NUM_SIZE;i++){
////                    sn.sn[i]   = 0xff;
////                 }
////         }
//
//         //ATCA_SERIAL_NUM_SIZE
//         
//         output_device_status();
//    
//         triggered =  false;
//     }
  
    if( SYS_TIME_DelayIsComplete(timer) )
    {
         //atecc_provision();
        LED1_Toggle();
        status = atcab_read_config_zone(read_config_data);
        CHECK_STATUS(status);
        OutputData("\r\nConfig Zone :\r\n",read_config_data,ATCA_ECC_CONFIG_SIZE);

        
        status = atcab_read_bytes_zone(ATCA_ZONE_DATA, 1, 0, read_pv_key,32 );
        CHECK_STATUS(status);
         OutputData("\r\nprivate key :\r\n",read_pv_key,32);
         
//         if(status== ATCA_EXECUTION_ERROR ){
           
//                sprintf(UartWriteBuf,"%d\n",status);
//                SYS_CONSOLE_Write(consoleHandleUSB, UartWriteBuf, strlen(UartWriteBuf));
//             
//            }

         ret = atecc_verify();
//         
//
        if(ret == 0){
                   sprintf(UartWriteBuf,"%s",verify_text);
                    SYS_CONSOLE_Write(consoleHandleUSB, UartWriteBuf, strlen(UartWriteBuf));
        }else{
                     sprintf(UartWriteBuf,"verify fail");
                    SYS_CONSOLE_Write(consoleHandleUSB, UartWriteBuf, strlen(UartWriteBuf));
        }
         
        SYS_TIME_DelayMS( 2000, &timer );
    }
    
        SYS_Tasks ( );
    }

    return ( EXIT_FAILURE );
}
*/