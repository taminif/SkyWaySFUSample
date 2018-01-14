////////////////////////////////////////////////////////////////////////
// SKWPeerError.h
// SkyWay SDK
////////////////////////////////////////////////////////////////////////
#import <Foundation/Foundation.h>
#import "SKWCommon.h"

/**
 * \file SKWPeerError.h
 */

#ifndef DOXYGEN_SKIP_THIS
//! Error type
typedef NS_ENUM(NSInteger, SKWPeerErrorEnum)
{
    /// No error.
    SKW_PEER_ERR_NO_ERROR = 0,
    /// The client's browser does not support some or all WebRTC features that you are trying to use.
    SKW_PEER_ERR_BROWSER_INCOMPATIBLE = -1,
    /// You've already disconnected this peer from the server and can no longer make any new connections on it.
    SKW_PEER_ERR_DISCONNECTED = -2,
    /// The ID passed into the Peer constructor contains illegal characters.
    SKW_PEER_ERR_INVALID_ID = -3,
    /// The API key passed into the Peer constructor contains illegal characters or is not in the system (cloud server only).
    SKW_PEER_ERR_INVALID_KEY = -4,
    /// Lost or cannot establish a connection to the signalling server.
    SKW_PEER_ERR_NETWORK = -5,
    /// The peer you're trying to connect to does not exist.
    SKW_PEER_ERR_PEER_UNAVAILABLE = -6,
    /// PeerJS is being used securely, but the cloud server does not support SSL. Use a custom PeerServer.
    SKW_PEER_ERR_SSL_UNAVAILABLE = -7,
    /// Unable to reach the server.
    SKW_PEER_ERR_SERVER_ERROR = -8,
    /// An error from the underlying socket.
    SKW_PEER_ERR_SOCKET_ERROR = -9,
    /// The underlying socket closed unexpectedly.
    SKW_PEER_ERR_SOCKET_CLOSED = -10,
    /// The ID passed into the Peer constructor is already taken.
    SKW_PEER_ERR_UNAVAILABLE_ID = -11,
    /// Native WebRTC errors.
    SKW_PEER_ERR_WEBRTC = -20,
    /// Room errors.
    SKW_PEER_ERR_ROOM_ERROR = -30,
    /// Unknown error.
    SKW_PEER_ERR_UNKNOWN = - 9999,
};
#endif // !DOXYGEN_SKIP_THIS


//! \~japanese エラー情報クラス
//! \~english Error information class
//! \~
@interface SKWPeerError : NSObject < NSCopying >

//! \~japanese エラー種別文字列
//! \~english Error type string
//! \~
@property (nonatomic, readonly) NSString* typeString;

//! \~japanese エラーメッセージ
//! \~english Error message
//! \~
@property (nonatomic, readonly) NSString* message;

#ifndef DOXYGEN_SKIP_THIS
//! \~japanese
//! \~english Error type
//! \~
@property (nonatomic, readonly) SKWPeerErrorEnum type SKYWAY_API_DEPRECATED;

//! \~japanese
//! \~english NSError object
//! \~
@property (nonatomic, readonly) NSError* error SKYWAY_API_DEPRECATED;
#endif // !DOXYGEN_SKIP_THIS

@end
