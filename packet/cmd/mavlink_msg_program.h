#pragma once
// MESSAGE Program PACKING

#define MAVLINK_MSG_ID_Program 4


typedef struct __mavlink_program_t {
 uint32_t ack; /*<  acknowledge or not*/
} mavlink_program_t;

#define MAVLINK_MSG_ID_Program_LEN 4
#define MAVLINK_MSG_ID_Program_MIN_LEN 4
#define MAVLINK_MSG_ID_4_LEN 4
#define MAVLINK_MSG_ID_4_MIN_LEN 4

#define MAVLINK_MSG_ID_Program_CRC 88
#define MAVLINK_MSG_ID_4_CRC 88



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_Program { \
    4, \
    "Program", \
    1, \
    {  { "ack", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_program_t, ack) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_Program { \
    "Program", \
    1, \
    {  { "ack", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_program_t, ack) }, \
         } \
}
#endif

/**
 * @brief Pack a program message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param ack  acknowledge or not
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_program_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t ack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_Program_LEN];
    _mav_put_uint32_t(buf, 0, ack);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_Program_LEN);
#else
    mavlink_program_t packet;
    packet.ack = ack;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_Program_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_Program;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_Program_MIN_LEN, MAVLINK_MSG_ID_Program_LEN, MAVLINK_MSG_ID_Program_CRC);
}

/**
 * @brief Pack a program message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ack  acknowledge or not
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_program_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t ack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_Program_LEN];
    _mav_put_uint32_t(buf, 0, ack);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_Program_LEN);
#else
    mavlink_program_t packet;
    packet.ack = ack;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_Program_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_Program;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_Program_MIN_LEN, MAVLINK_MSG_ID_Program_LEN, MAVLINK_MSG_ID_Program_CRC);
}

/**
 * @brief Encode a program struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param program C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_program_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_program_t* program)
{
    return mavlink_msg_program_pack(system_id, component_id, msg, program->ack);
}

/**
 * @brief Encode a program struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param program C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_program_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_program_t* program)
{
    return mavlink_msg_program_pack_chan(system_id, component_id, chan, msg, program->ack);
}

/**
 * @brief Send a program message
 * @param chan MAVLink channel to send the message
 *
 * @param ack  acknowledge or not
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_program_send(mavlink_channel_t chan, uint32_t ack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_Program_LEN];
    _mav_put_uint32_t(buf, 0, ack);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Program, buf, MAVLINK_MSG_ID_Program_MIN_LEN, MAVLINK_MSG_ID_Program_LEN, MAVLINK_MSG_ID_Program_CRC);
#else
    mavlink_program_t packet;
    packet.ack = ack;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Program, (const char *)&packet, MAVLINK_MSG_ID_Program_MIN_LEN, MAVLINK_MSG_ID_Program_LEN, MAVLINK_MSG_ID_Program_CRC);
#endif
}

/**
 * @brief Send a program message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_program_send_struct(mavlink_channel_t chan, const mavlink_program_t* program)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_program_send(chan, program->ack);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Program, (const char *)program, MAVLINK_MSG_ID_Program_MIN_LEN, MAVLINK_MSG_ID_Program_LEN, MAVLINK_MSG_ID_Program_CRC);
#endif
}

#if MAVLINK_MSG_ID_Program_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_program_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t ack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, ack);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Program, buf, MAVLINK_MSG_ID_Program_MIN_LEN, MAVLINK_MSG_ID_Program_LEN, MAVLINK_MSG_ID_Program_CRC);
#else
    mavlink_program_t *packet = (mavlink_program_t *)msgbuf;
    packet->ack = ack;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Program, (const char *)packet, MAVLINK_MSG_ID_Program_MIN_LEN, MAVLINK_MSG_ID_Program_LEN, MAVLINK_MSG_ID_Program_CRC);
#endif
}
#endif

#endif

// MESSAGE Program UNPACKING


/**
 * @brief Get field ack from program message
 *
 * @return  acknowledge or not
 */
static inline uint32_t mavlink_msg_program_get_ack(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Decode a program message into a struct
 *
 * @param msg The message to decode
 * @param program C-struct to decode the message contents into
 */
static inline void mavlink_msg_program_decode(const mavlink_message_t* msg, mavlink_program_t* program)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    program->ack = mavlink_msg_program_get_ack(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_Program_LEN? msg->len : MAVLINK_MSG_ID_Program_LEN;
        memset(program, 0, MAVLINK_MSG_ID_Program_LEN);
    memcpy(program, _MAV_PAYLOAD(msg), len);
#endif
}
