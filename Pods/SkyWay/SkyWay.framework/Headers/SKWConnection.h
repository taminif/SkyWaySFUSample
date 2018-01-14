////////////////////////////////////////////////////////////////////////
// SKWConnection.h
// SkyWay SDK
////////////////////////////////////////////////////////////////////////
#import <Foundation/Foundation.h>
#import "SKWCommon.h"

/**
 * \file SKWConnection.h
 */

@class SKWPeer;

//! \~japanese シリアライズ種別
//! \~english Serialization type
//! \~
typedef NS_ENUM(NSUInteger, SKWSerializationEnum)
{
    /// Binary
    SKW_SERIALIZATION_BINARY = 0,
    /// Binary (UTF-8)
    SKW_SERIALIZATION_BINARY_UTF8 = 1,
    /// JSON
    SKW_SERIALIZATION_JSON = 2,
    /// NONE
    SKW_SERIALIZATION_NONE = 3,
};


//! \~japanese SKWDataConnection / SKWMediaConnection の基底クラスです。
//! \~english Base class of SKWDataConnection and SKWMediaConnection.
//! \~
//!
//! \~japanese 直接このクラスは使用しません。
//! \~english
//! \~
@interface SKWConnection : NSObject

//! \~japanese コネクション ID
//! \~english Connection ID
//! \~
@property (nonatomic, readonly) NSString* __nullable connectionId;

#ifndef DOXYGEN_SKIP_THIS
//! Payload
@property (nonatomic, readonly) NSDictionary* __nullable payload SKYWAY_API_DEPRECATED;
#endif // !DOXYGEN_SKIP_THIS

//! \~japanese コネクションに関連するメタデータ文字列
//! \~english Any type of metadata associated with the connection, passed in by whoever initiated the connection.
//! \~
@property (nonatomic, readonly) NSString* __nullable metadata;

//! \~japanese コネクションの読み書き状態
//! \~english This is true if the connection is open and ready for read/write.
//! \~
@property (nonatomic, readonly) BOOL isOpen;

//! \~japanese リモートピア ID
//! \~english The ID of the peer on the other end of this connection.
//! \~
@property (nonatomic, readonly) NSString* __nullable peer;

//! \~japanese コネクション種別
//! \~english For type of connection.
//! \~
@property (nonatomic, readonly) NSString* __nullable type;

//! \~japanese コネクションラベル文字列
//! \~english The optional label passed in or assigned by PeerJS when the connection was initiated.
//! \~
@property (nonatomic, readonly) NSString* __nullable label;

//! \~japanese 送信されるデータ形式種別です。コネクション作成時に定義されます。(データ接続でのみ有効です)
//! \~english Whether the underlying data channels are reliable; defined when the connection was initiated.
//! \~
@property (nonatomic, readonly) BOOL reliable;

//! \~japanese 送信されるデータ形式種別です。 コネクション作成時に定義されます。(データ接続でのみ有効です)
//! \~english The serialization format of the data sent over the connection. Can be binary (default), binary-utf8, json, or none.
//! \~
@property (nonatomic, readonly) SKWSerializationEnum serialization;

//! \~japanese この接続を作成したピアオブジェクトです
//! \~english Provider PeerObjC object.
//! \~
@property (nonatomic, weak, readonly) SKWPeer* __nullable provider;

#ifndef DOXYGEN_SKIP_THIS
//! A reference to the RTCPeerConnection object associated with the connection.
@property (nonatomic, readonly) id __nullable peerConnection SKYWAY_API_DEPRECATED;
#endif // !DOXYGEN_SKIP_THIS

#pragma mark - Objective-C dependent

#ifndef DOXYGEN_SKIP_THIS
//! Queing to get peer connection state.
//!
//! @param bOutputDebug
//!     Output state information of debug level
//! @param callback
//!     Callback block
- (void)getPeerConnectionState:(BOOL)bOutputDebug callback:(void(^ __nullable)(NSArray* __nullable))callback SKYWAY_API_DEPRECATED;
#endif // !DOXYGEN_SKIP_THIS

@end
