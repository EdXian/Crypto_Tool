#pragma once
// MESSAGE device_sn PACKING

#define MAVLINK_MSG_ID_device_sn 8


typedef struct __mavlink_device_sn_t {
 uint8_t sn[9]; /*<  timestamp*/
} mavlink_device_sn_t;

#define MAVLINK_MSG_ID_device_sn_LEN 9
#define MAVLINK_MSG_ID_device_sn_MIN_LEN 9
#define MAVLINK_MSG_ID_8_LEN 9
#define MAVLINK_MSG_ID_8_MIN_LEN 9

#define MAVLINK_MSG_ID_device_sn_CRC 245
#define MAVLINK_MSG_ID_8_CRC 245

#define MAVLINK_MSG_device_sn_FIELD_SN_LEN 9

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_device_sn { \
    8, \
    "device_sn", \
    1, \
    {  { "sn", NULL, MAVLINK_TYPE_UINT8_T, 9, 0, offsetof(mavlink_device_sn_t, sn) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_device_sn { \
    "device_sn", \
    1, \
    {  { "sn", NULL, MAVLINK_TYPE_UINT8_T, 9, 0, offsetof(mavlink_device_sn_t, sn) }, \
         } \
}
#endif

/**
 * @brief Pack a device_sn message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param sn  timestamp
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_device_sn_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const uint8_t *sn)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_device_sn_LEN];

    _mav_put_uint8_t_array(buf, 0, sn, 9);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_device_sn_LEN);
#else
    mavlink_device_sn_t packet;

    mav_array_memcpy(packet.sn, sn, sizeof(uint8_t)*9);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_device_sn_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_device_sn;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_device_sn_MIN_LEN, MAVLINK_MSG_ID_device_sn_LEN, MAVLINK_MSG_ID_device_sn_CRC);
}

/**
 * @brief Pack a device_sn message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param sn  timestamp
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_device_sn_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const uint8_t *sn)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_device_sn_LEN];

    _mav_put_uint8_t_array(buf, 0, sn, 9);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_device_sn_LEN);
#else
    mavlink_device_sn_t packet;

    mav_array_memcpy(packet.sn, sn, sizeof(uint8_t)*9);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_device_sn_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_device_sn;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_device_sn_MIN_LEN, MAVLINK_MSG_ID_device_sn_LEN, MAVLINK_MSG_ID_device_sn_CRC);
}

/**
 * @brief Encode a device_sn struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param device_sn C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_device_sn_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_device_sn_t* device_sn)
{
    return mavlink_msg_device_sn_pack(system_id, component_id, msg, device_sn->sn);
}

/**
 * @brief Encode a device_sn struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param device_sn C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_device_sn_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_device_sn_t* device_sn)
{
    return mavlink_msg_device_sn_pack_chan(system_id, component_id, chan, msg, device_sn->sn);
}

/**
 * @brief Send a device_sn message
 * @param chan MAVLink channel to send the message
 *
 * @param sn  timestamp
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_device_sn_send(mavlink_channel_t chan, const uint8_t *sn)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_device_sn_LEN];

    _mav_put_uint8_t_array(buf, 0, sn, 9);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_device_sn, buf, MAVLINK_MSG_ID_device_sn_MIN_LEN, MAVLINK_MSG_ID_device_sn_LEN, MAVLINK_MSG_ID_device_sn_CRC);
#else
    mavlink_device_sn_t packet;

    mav_array_memcpy(packet.sn, sn, sizeof(uint8_t)*9);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_device_sn, (const char *)&packet, MAVLINK_MSG_ID_device_sn_MIN_LEN, MAVLINK_MSG_ID_device_sn_LEN, MAVLINK_MSG_ID_device_sn_CRC);
#endif
}

/**
 * @brief Send a device_sn message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_device_sn_send_struct(mavlink_channel_t chan, const mavlink_device_sn_t* device_sn)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_device_sn_send(chan, device_sn->sn);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_device_sn, (const char *)device_sn, MAVLINK_MSG_ID_device_sn_MIN_LEN, MAVLINK_MSG_ID_device_sn_LEN, MAVLINK_MSG_ID_device_sn_CRC);
#endif
}

#if MAVLINK_MSG_ID_device_sn_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_device_sn_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const uint8_t *sn)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;

    _mav_put_uint8_t_array(buf, 0, sn, 9);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_device_sn, buf, MAVLINK_MSG_ID_device_sn_MIN_LEN, MAVLINK_MSG_ID_device_sn_LEN, MAVLINK_MSG_ID_device_sn_CRC);
#else
    mavlink_device_sn_t *packet = (mavlink_device_sn_t *)msgbuf;

    mav_array_memcpy(packet->sn, sn, sizeof(uint8_t)*9);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_device_sn, (const char *)packet, MAVLINK_MSG_ID_device_sn_MIN_LEN, MAVLINK_MSG_ID_device_sn_LEN, MAVLINK_MSG_ID_device_sn_CRC);
#endif
}
#endif

#endif

// MESSAGE device_sn UNPACKING


/**
 * @brief Get field sn from device_sn message
 *
 * @return  timestamp
 */
static inline uint16_t mavlink_msg_device_sn_get_sn(const mavlink_message_t* msg, uint8_t *sn)
{
    return _MAV_RETURN_uint8_t_array(msg, sn, 9,  0);
}

/**
 * @brief Decode a device_sn message into a struct
 *
 * @param msg The message to decode
 * @param device_sn C-struct to decode the message contents into
 */
static inline void mavlink_msg_device_sn_decode(const mavlink_message_t* msg, mavlink_device_sn_t* device_sn)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_device_sn_get_sn(msg, device_sn->sn);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_device_sn_LEN? msg->len : MAVLINK_MSG_ID_device_sn_LEN;
        memset(device_sn, 0, MAVLINK_MSG_ID_device_sn_LEN);
    memcpy(device_sn, _MAV_PAYLOAD(msg), len);
#endif
}
