#pragma once
// MESSAGE verify PACKING

#define MAVLINK_MSG_ID_verify 6


typedef struct __mavlink_verify_t {
 uint32_t ack; /*<  acknowledge or not*/
} mavlink_verify_t;

#define MAVLINK_MSG_ID_verify_LEN 4
#define MAVLINK_MSG_ID_verify_MIN_LEN 4
#define MAVLINK_MSG_ID_6_LEN 4
#define MAVLINK_MSG_ID_6_MIN_LEN 4

#define MAVLINK_MSG_ID_verify_CRC 159
#define MAVLINK_MSG_ID_6_CRC 159



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_verify { \
    6, \
    "verify", \
    1, \
    {  { "ack", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_verify_t, ack) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_verify { \
    "verify", \
    1, \
    {  { "ack", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_verify_t, ack) }, \
         } \
}
#endif

/**
 * @brief Pack a verify message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param ack  acknowledge or not
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_verify_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t ack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_verify_LEN];
    _mav_put_uint32_t(buf, 0, ack);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_verify_LEN);
#else
    mavlink_verify_t packet;
    packet.ack = ack;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_verify_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_verify;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_verify_MIN_LEN, MAVLINK_MSG_ID_verify_LEN, MAVLINK_MSG_ID_verify_CRC);
}

/**
 * @brief Pack a verify message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ack  acknowledge or not
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_verify_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t ack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_verify_LEN];
    _mav_put_uint32_t(buf, 0, ack);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_verify_LEN);
#else
    mavlink_verify_t packet;
    packet.ack = ack;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_verify_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_verify;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_verify_MIN_LEN, MAVLINK_MSG_ID_verify_LEN, MAVLINK_MSG_ID_verify_CRC);
}

/**
 * @brief Encode a verify struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param verify C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_verify_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_verify_t* verify)
{
    return mavlink_msg_verify_pack(system_id, component_id, msg, verify->ack);
}

/**
 * @brief Encode a verify struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param verify C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_verify_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_verify_t* verify)
{
    return mavlink_msg_verify_pack_chan(system_id, component_id, chan, msg, verify->ack);
}

/**
 * @brief Send a verify message
 * @param chan MAVLink channel to send the message
 *
 * @param ack  acknowledge or not
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_verify_send(mavlink_channel_t chan, uint32_t ack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_verify_LEN];
    _mav_put_uint32_t(buf, 0, ack);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_verify, buf, MAVLINK_MSG_ID_verify_MIN_LEN, MAVLINK_MSG_ID_verify_LEN, MAVLINK_MSG_ID_verify_CRC);
#else
    mavlink_verify_t packet;
    packet.ack = ack;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_verify, (const char *)&packet, MAVLINK_MSG_ID_verify_MIN_LEN, MAVLINK_MSG_ID_verify_LEN, MAVLINK_MSG_ID_verify_CRC);
#endif
}

/**
 * @brief Send a verify message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_verify_send_struct(mavlink_channel_t chan, const mavlink_verify_t* verify)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_verify_send(chan, verify->ack);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_verify, (const char *)verify, MAVLINK_MSG_ID_verify_MIN_LEN, MAVLINK_MSG_ID_verify_LEN, MAVLINK_MSG_ID_verify_CRC);
#endif
}

#if MAVLINK_MSG_ID_verify_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_verify_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t ack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, ack);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_verify, buf, MAVLINK_MSG_ID_verify_MIN_LEN, MAVLINK_MSG_ID_verify_LEN, MAVLINK_MSG_ID_verify_CRC);
#else
    mavlink_verify_t *packet = (mavlink_verify_t *)msgbuf;
    packet->ack = ack;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_verify, (const char *)packet, MAVLINK_MSG_ID_verify_MIN_LEN, MAVLINK_MSG_ID_verify_LEN, MAVLINK_MSG_ID_verify_CRC);
#endif
}
#endif

#endif

// MESSAGE verify UNPACKING


/**
 * @brief Get field ack from verify message
 *
 * @return  acknowledge or not
 */
static inline uint32_t mavlink_msg_verify_get_ack(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Decode a verify message into a struct
 *
 * @param msg The message to decode
 * @param verify C-struct to decode the message contents into
 */
static inline void mavlink_msg_verify_decode(const mavlink_message_t* msg, mavlink_verify_t* verify)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    verify->ack = mavlink_msg_verify_get_ack(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_verify_LEN? msg->len : MAVLINK_MSG_ID_verify_LEN;
        memset(verify, 0, MAVLINK_MSG_ID_verify_LEN);
    memcpy(verify, _MAV_PAYLOAD(msg), len);
#endif
}
