#pragma once
// MESSAGE verify_ack PACKING

#define MAVLINK_MSG_ID_verify_ack 7


typedef struct __mavlink_verify_ack_t {
 uint8_t status; /*<  timestamp*/
} mavlink_verify_ack_t;

#define MAVLINK_MSG_ID_verify_ack_LEN 1
#define MAVLINK_MSG_ID_verify_ack_MIN_LEN 1
#define MAVLINK_MSG_ID_7_LEN 1
#define MAVLINK_MSG_ID_7_MIN_LEN 1

#define MAVLINK_MSG_ID_verify_ack_CRC 5
#define MAVLINK_MSG_ID_7_CRC 5



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_verify_ack { \
    7, \
    "verify_ack", \
    1, \
    {  { "status", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_verify_ack_t, status) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_verify_ack { \
    "verify_ack", \
    1, \
    {  { "status", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_verify_ack_t, status) }, \
         } \
}
#endif

/**
 * @brief Pack a verify_ack message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param status  timestamp
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_verify_ack_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_verify_ack_LEN];
    _mav_put_uint8_t(buf, 0, status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_verify_ack_LEN);
#else
    mavlink_verify_ack_t packet;
    packet.status = status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_verify_ack_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_verify_ack;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_verify_ack_MIN_LEN, MAVLINK_MSG_ID_verify_ack_LEN, MAVLINK_MSG_ID_verify_ack_CRC);
}

/**
 * @brief Pack a verify_ack message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param status  timestamp
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_verify_ack_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_verify_ack_LEN];
    _mav_put_uint8_t(buf, 0, status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_verify_ack_LEN);
#else
    mavlink_verify_ack_t packet;
    packet.status = status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_verify_ack_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_verify_ack;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_verify_ack_MIN_LEN, MAVLINK_MSG_ID_verify_ack_LEN, MAVLINK_MSG_ID_verify_ack_CRC);
}

/**
 * @brief Encode a verify_ack struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param verify_ack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_verify_ack_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_verify_ack_t* verify_ack)
{
    return mavlink_msg_verify_ack_pack(system_id, component_id, msg, verify_ack->status);
}

/**
 * @brief Encode a verify_ack struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param verify_ack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_verify_ack_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_verify_ack_t* verify_ack)
{
    return mavlink_msg_verify_ack_pack_chan(system_id, component_id, chan, msg, verify_ack->status);
}

/**
 * @brief Send a verify_ack message
 * @param chan MAVLink channel to send the message
 *
 * @param status  timestamp
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_verify_ack_send(mavlink_channel_t chan, uint8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_verify_ack_LEN];
    _mav_put_uint8_t(buf, 0, status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_verify_ack, buf, MAVLINK_MSG_ID_verify_ack_MIN_LEN, MAVLINK_MSG_ID_verify_ack_LEN, MAVLINK_MSG_ID_verify_ack_CRC);
#else
    mavlink_verify_ack_t packet;
    packet.status = status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_verify_ack, (const char *)&packet, MAVLINK_MSG_ID_verify_ack_MIN_LEN, MAVLINK_MSG_ID_verify_ack_LEN, MAVLINK_MSG_ID_verify_ack_CRC);
#endif
}

/**
 * @brief Send a verify_ack message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_verify_ack_send_struct(mavlink_channel_t chan, const mavlink_verify_ack_t* verify_ack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_verify_ack_send(chan, verify_ack->status);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_verify_ack, (const char *)verify_ack, MAVLINK_MSG_ID_verify_ack_MIN_LEN, MAVLINK_MSG_ID_verify_ack_LEN, MAVLINK_MSG_ID_verify_ack_CRC);
#endif
}

#if MAVLINK_MSG_ID_verify_ack_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_verify_ack_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_verify_ack, buf, MAVLINK_MSG_ID_verify_ack_MIN_LEN, MAVLINK_MSG_ID_verify_ack_LEN, MAVLINK_MSG_ID_verify_ack_CRC);
#else
    mavlink_verify_ack_t *packet = (mavlink_verify_ack_t *)msgbuf;
    packet->status = status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_verify_ack, (const char *)packet, MAVLINK_MSG_ID_verify_ack_MIN_LEN, MAVLINK_MSG_ID_verify_ack_LEN, MAVLINK_MSG_ID_verify_ack_CRC);
#endif
}
#endif

#endif

// MESSAGE verify_ack UNPACKING


/**
 * @brief Get field status from verify_ack message
 *
 * @return  timestamp
 */
static inline uint8_t mavlink_msg_verify_ack_get_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Decode a verify_ack message into a struct
 *
 * @param msg The message to decode
 * @param verify_ack C-struct to decode the message contents into
 */
static inline void mavlink_msg_verify_ack_decode(const mavlink_message_t* msg, mavlink_verify_ack_t* verify_ack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    verify_ack->status = mavlink_msg_verify_ack_get_status(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_verify_ack_LEN? msg->len : MAVLINK_MSG_ID_verify_ack_LEN;
        memset(verify_ack, 0, MAVLINK_MSG_ID_verify_ack_LEN);
    memcpy(verify_ack, _MAV_PAYLOAD(msg), len);
#endif
}
