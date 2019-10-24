#ifndef __OPA_TYPES_H__
#define __OPA_TYPES_H__

#include "..\\include\types\Basic_types.h"

/**
  * This file contains global types for OPA.
  *
  */

/**
  * The TUserData type is used by component clients to store information
  * related to the specific instance of the component.
  *
  * The data content is defined by the client.
  */
typedef void TUserData;

/**
  * Defines a size for example number of bytes in AllocMem.
  */
typedef FUint16 TSize;

/**
  * Time type.
  */
typedef FUint32 TTime;



/**
  * This is the maximum length in characters of a MIME type string.
  */
const TUnsigned MIME_TYPE_MAX_LENGTH = 46;


/**
  * This is a null terminated ASCII-7 MIME type string.
  */
typedef TAscii TMimeType[MIME_TYPE_MAX_LENGTH + 1];

// ==========================================================================
// OPA Message Related types
// ==========================================================================


/**
  * TMsgBase is the type used for classifying a message.
  */
typedef FUint16 TMsgBase;

/**
  * TMsgId is the type used for identifying a message.
  */
typedef FUint16 TMsgId;

/**
  * TClientData is used to allow component clients to store the ClientData
  * offered in asynchronous services.
  */
typedef FUint32 TClientData;

/**
  * Type specifying a handle to a session.
  */
typedef THnd TSessionHandle;

/**
  * TMsgDescriptor is the type used for storing the complete identity of a message.
  *
  * @param MsgBase        Message Identifier specifying the class of the message.
  * @param MsgId          Message Identifier specifying the type of the message.
  */
typedef struct {
  TMsgBase MsgBase;
  TMsgId   MsgId;
} TMsgDescriptor;


/**
  * Constant that signifies a non-valid message base in a message identifier.
  */
const TMsgBase OPA_MSG_BASE_NULL = 0xffff;

/**
  * Definition of bits 0 to 7 of ExtendedInformation in messages.
  *
  * @param OPA_MSG_EXTENSION_ROUTED   Message should be routed in NAC
  */

const FUint8 OPA_MSG_EXTENSION_ROUTED = 0x01;

/**
  * Definitions for the storage of interface references in messages.
  *
  */
typedef FUint16 TinterfaceReferenceDescriptor;

/**
  * The maximum number of interface pointers that can be sent in an OPA message.
  *
  */
const FUint8 OPA_MAX_INTERFACES_IN_MSG = 4;

/**
  * TMsgHdr is the type used for defining OPA message headers.
  *
  * This shall be the first parameter in all messages defined
  * in the components, plug-ins and applications.
  *
  * @param MessageDescriptor    Complete identity of the message
  * @param ClientData           This member is free to use by the user
  * @param Sender               Sender of the message
  * @param hSession             The session related to the message.
  * @param pNext                Allows messages to be queued in a linked list.
  * @param ResponseBase         MsgBase to be used when responding the message.
  * @param Size                 Size of the message, including the header.
  * @param Ird                  Location of Interface references in message.
  * @param ReleaseSession       Flag indicating the release of the session upon message delivery.
  * @param ExtendedInformation  Flag for internal use.
  */

typedef struct
{
  TMsgDescriptor MessageDescriptor;
  TClientData ClientData;
  THnd Sender;
  TSessionHandle hSession;
  TVoid* pNext;
  TMsgBase ResponseBase;
  TSize Size;
  TinterfaceReferenceDescriptor Ird[OPA_MAX_INTERFACES_IN_MSG];
  TBool ReleaseSession;
  FUint8 ExtendedInformation;
} TMsgHdr;

/**
  * TMsg is the type used for defining OPA messages in methods. The message
  * content is specified by the components. All
  * OPA messages shall contain a TMsgHdr as the first parameter.
  *
  * @param MsgHdr The OPA Message header.
  */

typedef struct
{
  TMsgHdr MsgHdr;
}
TMsg;

/**
  * Definition of which mode the application is currently running.
  * Used by plug-in to determine which actions to take upon a
  * callback from an OPA component or plug-in it extends.
  *
  * @param FULL_MSG_MODE  Application is currently in Full Message Mode
  * @param CB_MSG_MODE    Application is currently in Callback Message Mode
  */
typedef enum
{
  FULL_MSG_MODE       = 1,
  CB_MSG_MODE         = 2
} TMsgMode;

// ==========================================================================
// OPA Error Handling Related types
// ==========================================================================
/**
  * OK return type.
  */
const TSigned OPA_OK = 0;

/**
  * A coordinate. Note that a coordinate value can be either an absolute value or a relative value, why
  * it is possible to specify negative coordinates as well.
  */
typedef TSigned TCoordinate;

/**
  * A single point in a coordinate system.
  *
  * @param X X-coordinate of the point
  * @param Y Y-coordinate of the point.
  */
typedef struct
{
  TCoordinate X;
  TCoordinate Y;
} TPoint;

/**
  * A rectangle in a coordinate system.
  *
  * @param X      X-coordinate of the upper left corner of the rectangle.
  * @param Y      Y-coordinate of the upper left corner of the rectangle.
  * @param Width  Width of the rectangle.
  * @param Height Height of the rectangle.
  */
typedef struct
{
  TCoordinate X;
  TCoordinate Y;
  TUnsigned Width;
  TUnsigned Height;
} TRectangle;

/**
  *  A line in a coordinate system.
  *
  *  @param X1 The X-coordinate of the first point
  *  @param Y1 The Y-coordinate of the first point
  *  @param X2 The X-coordinate of the second point
  *  @param Y2 The Y-coordinate of the second point
  */
typedef struct
{
  TCoordinate X1;
  TCoordinate Y1;
  TCoordinate X2;
  TCoordinate Y2;
} TLine;

/**
  * RGB values for one colour. This type is divided into 4 parts where
  * the most significant byte is the transparency. The value 0 means
  * full transparency. The value 255 means that the colour is fully opaque.
  * The next three bytes are the RGB value for red, green and blue.
  * Examples: 0xFFFF0000 is full red. 0x8000FF00 means half transparent
  * green colour.
  */
typedef FUint32 TColour;

/**
  * This is the maximum length in characters of strings defined in Bridge.
  * This constant is used for marshalling/unmarshalling purposes.
  */
const TUnsigned BRIDGE_DEFAULT_MAX_IS_VALUE = 255;

/**
  * This is the maximum time-out value in milliseconds (~6.21 days).
  */
const FUint32 OPA_MAX_TIMEOUT_VALUE = 536870911;


#endif