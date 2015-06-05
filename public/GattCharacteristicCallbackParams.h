/* mbed Microcontroller Library
 * Copyright (c) 2006-2013 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __GATT_CHARACTERISTIC_CALLBACK_PARAMS_H__
#define __GATT_CHARACTERISTIC_CALLBACK_PARAMS_H__

struct GattCharacteristicWriteCBParams {
    GattAttribute::Handle_t charHandle;
    enum Type {
        GATTS_CHAR_OP_INVALID               = 0x00,  /**< Invalid Operation. */
        GATTS_CHAR_OP_WRITE_REQ             = 0x01,  /**< Write Request. */
        GATTS_CHAR_OP_WRITE_CMD             = 0x02,  /**< Write Command. */
        GATTS_CHAR_OP_SIGN_WRITE_CMD        = 0x03,  /**< Signed Write Command. */
        GATTS_CHAR_OP_PREP_WRITE_REQ        = 0x04,  /**< Prepare Write Request. */
        GATTS_CHAR_OP_EXEC_WRITE_REQ_CANCEL = 0x05,  /**< Execute Write Request: Cancel all prepared writes. */
        GATTS_CHAR_OP_EXEC_WRITE_REQ_NOW    = 0x06,  /**< Execute Write Request: Immediately execute all prepared writes. */
    } op;                   /**< Type of write operation, */
    uint16_t       offset;  /**< Offset for the write operation. */
    uint16_t       len;
    const uint8_t *data;    /* @note: data might not persist beyond the callback; make a local copy if needed. */
};

struct GattCharacteristicReadCBParams {
    GattAttribute::Handle_t  charHandle;
    uint16_t                 offset; /**< Offset for the read operation. */
    uint16_t                 len;
    const uint8_t           *data;   /* @note: data might not persist beyond the callback; make a local copy if needed. */
};

enum GattCharacteristicAuthCBReply_t {
    AUTH_CALLBACK_REPLY_SUCCESS =                       0x00,    /**< Success. */
    AUTH_CALLBACK_REPLY_ATTERR_INVALID_HANDLE =         0x0101,  /**< ATT Error: Invalid Attribute Handle. */
    AUTH_CALLBACK_REPLY_ATTERR_READ_NOT_PERMITTED =     0x0102,  /**< ATT Error: Read not permitted. */
    AUTH_CALLBACK_REPLY_ATTERR_WRITE_NOT_PERMITTED =    0x0103,  /**< ATT Error: Write not permitted. */
    AUTH_CALLBACK_REPLY_ATTERR_INSUF_AUTHENTICATION =   0x0105,  /**< ATT Error: Authenticated link required. */
    AUTH_CALLBACK_REPLY_ATTERR_INVALID_OFFSET =         0x0107,  /**< ATT Error: Offset specified was past the end of the attribute. */
    AUTH_CALLBACK_REPLY_ATTERR_INSUF_AUTHORIZATION =    0x0108,  /**< ATT Error: Used in ATT as Insufficient Authorisation. */
    AUTH_CALLBACK_REPLY_ATTERR_PREPARE_QUEUE_FULL =     0x0109,  /**< ATT Error: Used in ATT as Prepare Queue Full. */
    AUTH_CALLBACK_REPLY_ATTERR_ATTRIBUTE_NOT_FOUND =    0x010A,  /**< ATT Error: Used in ATT as Attribute not found. */
    AUTH_CALLBACK_REPLY_ATTERR_ATTRIBUTE_NOT_LONG =     0x010B,  /**< ATT Error: Attribute cannot be read or written using read/write blob requests. */
    AUTH_CALLBACK_REPLY_ATTERR_INVALID_ATT_VAL_LENGTH = 0x010D,  /**< ATT Error: Invalid value size. */
    AUTH_CALLBACK_REPLY_ATTERR_INSUF_RESOURCES =        0x0111,  /**< ATT Error: Encrypted link required. */
};

struct GattCharacteristicWriteAuthCBParams {
    GattAttribute::Handle_t  charHandle;
    uint16_t                 offset; /**< Offset for the write operation. */
    uint16_t                 len;    /**< Length of the incoming data. */
    const uint8_t           *data;   /**< Incoming data, variable length. */
    GattCharacteristicAuthCBReply_t authorizationReply; /* This is the out parameter which needs to be set to true by the callback if the
                                                         * request is to proceed; false otherwise. */
};

struct GattCharacteristicReadAuthCBParams {
    GattAttribute::Handle_t  charHandle;
    uint16_t                 offset; /**< Offset for the read operation. */
    uint16_t                 len;    /**< Optional: new length of the outgoing data. */
    uint8_t                 *data;   /**< Optional: new outgoing data. Leave at NULL if data is unchanged. */
    GattCharacteristicAuthCBReply_t authorizationReply; /* This is the out parameter which needs to be set to true by the callback if the
                                                         * request is to proceed; false otherwise. */
};

#endif /*__GATT_CHARACTERISTIC_CALLBACK_PARAMS_H__*/
