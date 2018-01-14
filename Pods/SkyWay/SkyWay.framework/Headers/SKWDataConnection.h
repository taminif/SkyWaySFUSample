////////////////////////////////////////////////////////////////////////
// SKWDataConnection.h
// SkyWay SDK
////////////////////////////////////////////////////////////////////////
#import "SKWConnection.h"

/**
 * \file SKWDataConnection.h
 */

@class SKWDataChannel;


//! \~japanese データコネクションイベントタイプ
//! \~english Data connection event type
//! \~
typedef NS_ENUM(NSUInteger, SKWDataConnectionEventEnum)
{
    /// Emitted when the connection is established and ready-to-use.
    SKW_DATACONNECTION_EVENT_OPEN,
    /// Emitted when data is received from the remote peer.
    SKW_DATACONNECTION_EVENT_DATA,
    /// Emitted when either you or the remote peer closes the data connection.
    SKW_DATACONNECTION_EVENT_CLOSE,
    /// Errors on the data conenction are almost always fatal and will destroy the data connection.
    SKW_DATACONNECTION_EVENT_ERROR,
};

//! \~japanese データコネクションイベントコールバックシグネチャ
//! \~english Data connection event callback signature.
//! \~
typedef void (^SKWDataConnectionEventCallback)(NSObject* __nullable arg);

//! \~japanese
//! DataConnection 相当のクラスです。
//!
//! このオブジェクトを取得するには SKWPeer の connectWithId メソッドを使用するか、
//! SKW_PEER_EVENT_CONNECTION イベント発生時に渡されるオブジェクトを使用してください。
//! \~english Alternative class as DataConnection
//! \~
@interface SKWDataConnection : SKWConnection

#ifndef DOXYGEN_SKIP_THIS
/// A reference to the SKWDataChannel object associated with the connection.
@property (nonatomic, readonly) id __nullable dataChannel;

/// The number of messages queued to be sent once the browser buffer is no longer full.
@property (nonatomic, readonly) NSUInteger bufferSize;
#endif // !DOXYGEN_SKIP_THIS

//! \~japanese 接続中のリモートピアにデータを送信します。
//!
//! プロパティ serialization の値によって送信処理が変わります。
//!
//! binary / binary-utf8 の場合、js-binarypack 相当のシリアライズを行ってバイナリ送受信処理をおこないます。
//! 送信先がブラウザーの場合に有用です。
//!
//! json の場合、送信時は NSDictionary* / NSArray* を JSON オブジェクトデータに してバイナリ送信します。
//! 受信は、バイナリデータを NSDictionary*, NSArray* として受信します。
//!
//! none の場合、NSString* はテキストとして、それ以外は NSData* で変換できたオブ ジェクトをバイナリ送受信します。
//!
//! \~english data is sent to the remote peer.
//! \~
//!
//! \code{.m}
//! SKWDataConnection* data;
//! NSString* strMsg = @"Send data.";
//!
//! BOOL bResult = [data send:strMsg];
//! if (bResult) {
//!     // success
//! }
//! else {
//!     // failure
//! }
//!
//! \endcode
//!
//! @param data
//! \~japanese
//! 送信するオブジェクトを設定します。
//! NSData*, NSString*, NSNumber*, NSDictionary*, NSArray* を設定できます。
//! \~english You can send any type of NSData object.
//! \~
//! @return
//! \~japanese 処理結果
//! \~english method result
//! \~
- (BOOL)send:(NSObject* __nonnull)data;

//! \~japanese データ通信接続の切断と解放をおこないます。
//! \~english Closes the data connection gracefully, cleaning up underlying DataChannels and PeerConnections.
//! \~
//! \code{.m}
//! SKWDataConnection* data;
//! [data close];
//! data = nil;
//! \endcode
- (void)close;

//! \~japanese SKWDataConnection のイベントコールバック Block を設定します。
//! \~english Set callbacks for data connection events. (Block Literal Syntax)
//! \~
//!
//! \code{.m}
//! SKWDataConnection* data;
//!
//! [data on:SKW_DATACONNECTION_EVENT_OPEN callback:^(NSObject* obj) {
//!     // オープンしたときの処理等を記述
//! }];
//!
//! [data on:SKW_DATACONNECTION_EVENT_DATA callback:^(NSObject* obj) {
//!     if ([obj isKindOfClass:[NSData class]]) {
//!         NSData* dat = (NSData *)obj;
//!     } else if ([obj isKindOfClass:[NSDictionary class]]) {
//!         NSDictionary* dic = (NSDictionary *)obj;
//!     }
//!     else if ([obj isKindOfClass:[NSArray class]]) {
//!         NSArray* ary = (NSArray *)obj;
//!     } else if ([obj isKindOfClass:[NSString class]]) {
//!         NSString* string = (NSString *)obj;
//!     }
//! }];
//!
//! [data on:SKW_DATACONNECTION_EVENT_CLOSE callback:^(NSObject* obj) {
//!     // コネクションが切断したときの処理を記述
//! }];
//!
//! [data on:SKW_DATACONNECTION_EVENT_ERROR callback:^(NSObject* obj) {
//!     SKWPeerError* err = (SKWPeerError *)obj;
//!     NSLog(@"%@", err);
//! }];
//! \endcode
//!
//! @param event
//! \~japanese 設定するイベント種別を指定します。
//! \~english Event type
//! \~
//!
//! @param callback
//! \~japanese イベント発生時に実行する Block を設定します。
//! \~english Callback block
//! \~
- (void)on:(SKWDataConnectionEventEnum)event callback:(__nullable SKWDataConnectionEventCallback)callback;

@end
