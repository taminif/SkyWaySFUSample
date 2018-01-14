////////////////////////////////////////////////////////////////////////
// SKWMediaConnection.h
// SkyWay SDK
////////////////////////////////////////////////////////////////////////
#import "SKWConnection.h"

/**
 * \file SKWMediaConnection.h
 */

@class SKWMediaStream;
@class SKWAnswerOption;


//! \~japanese メディアコネクションイベントタイプ
//! \~english Media connection event type
//! \~
typedef NS_ENUM(NSUInteger, SKWMediaConnectionEventEnum)
{
    //! \~japanese リモートメディアストリームを追加された時のイベントです
    //! \~english Emitted when a remote peer adds a stream.
    //! \~
    SKW_MEDIACONNECTION_EVENT_STREAM,
    //! \~japanese リモートメディアストリームが削除された時のイベントです
    //! \~english Emitted when a remote peer remove a stream.
    //! \~
    SKW_MEDIACONNECTION_EVENT_REMOVE_STREAM,
    //! \~japanese メディアコネクションが閉じられた時のイベントです
    //! \~english Emitted when either you or the remote peer closes the media connection.
    //! \~
    SKW_MEDIACONNECTION_EVENT_CLOSE,
    //! \~japanese エラーが発生した時のイベントです
    //! \~english Errors on the media conenction are almost always fatal and will destroy the media connection.
    //! \~
    SKW_MEDIACONNECTION_EVENT_ERROR,
};

//! \~japanese メディアコネクションイベントコールバックシグネチャ
//! \~english Media Event Callback signature.
//! \~
typedef void (^SKWMediaConnectionEventCallback)(NSObject* __nullable arg);

//! \~japanese MediaConnection 相当のクラスです。
//! \~english Alternative class as MediaConnection
//! \~
//!
//! \~japanese
//! このオブジェクトを取得するには、SKWPeer の callWithId メソッドを使用するか、
//! SKW_PEER_EVENT_CALL イベント発生時に渡されるオブジェクトを使用してください。
//! \~english
//! \~
@interface SKWMediaConnection : SKWConnection

//! \~japanese
//! call イベントを受信した場合に、応答するためのコールバックにて与えられる
//! SKWMediaConnection にて answer を呼び出せます。
//!
//! 送信するメディアストリームは使用せず、応答します。
//! \~english
//! When receiving a call event on a peer, you can call .answer on the media connection
//! provided by the callback to accept the call.
//! \~
//!
//! \code{.m}
//! SKWPeer* peer;
//!
//! [peer on:SKW_PEER_EVENT_CALL callback:^(NSObject* obj) {
//!     [media answer];
//! }];
//! \endcode
- (void)answer;

//! \~japanese
//! call イベントを受信した場合に、応答するためのコールバックにて与えられる
//! SKWMediaConnection にて answer を呼び出せます。
//!
//! 送信するメディアストリームを指定して、応答します。
//! \~english
//! When receiving a call event on a peer, you can call .answer on the media connection
//! provided by the callback to accept the call.
//! \~
//!
//! \code{.m}
//! SKWPeer* peer;
//!
//! [SKWNavigator initialize:peer];
//!
//! SKWMediaConstraints* constraints = [[SKWMediaConstraints alloc] init];
//! SKWMediaStream* stream = [SKWNavigator getUserMedia:constraints];
//!
//! [peer on:SKW_PEER_EVENT_CALL callback:^(NSObject* obj) {
//!     SKWMediaConnection* media = (SKWMediaConnection *)obj;
//!     [media answer:stream];
//! }];
//! \endcode
//!
//! @param stream
//! \~japanese SKWNavigator の getUserMedia によって取得される SKWMediaStream を指定します。
//! \~english Video stream
//! \~
- (void)answer:(SKWMediaStream* __nullable)stream;

//! \~japanese
//! call イベントを受信した場合に、応答するためのコールバックにて与えられる
//! SKWMediaConnection にて answer をオプション付きで呼び出せます。
//!
//! 送信するメディアストリームとオプションを指定して、応答します。
//! \~english
//! When receiving a call event on a peer, you can call .answer on the media connection
//! provided by the callback to accept the call with options.
//! \~
//!
//! \code{.m}
//! SKWPeer* peer;
//!
//! [SKWNavigator initialize:peer];
//!
//! SKWMediaConstraints* constraints = [[SKWMediaConstraints alloc] init];
//! SKWMediaStream* stream = [SKWNavigator getUserMedia:constraints];
//!
//! [peer on:SKW_PEER_EVENT_CALL callback:^(NSObject* obj) {
//!     SKWMediaConnection* media = (SKWMediaConnection *)obj;
//!     SKWAnswerOption* options = [[SKWAnswerOption alloc] init];
//!     options.videoBandwidth = 768;
//!     options.audioBandwidth = 64;
//!     [media answer:stream options:options];
//! }];
//! \endcode
//!
//! @param stream
//! \~japanese SKWNavigator の getUserMedia によって取得される SKWMediaStream を指定します。
//! \~english Video stream
//! \~
//!
//! @param options
//! \~japanese 応答時のオプションを指定します。
//! \~english Answer Options
//! \~
- (void)answer:(SKWMediaStream* __nullable)stream options:(SKWAnswerOption* __nullable)options;

//! \~japanese SKWMediaConnection を閉じます。
//! \~english Closes the media connection.
//! \~
//!
//! \code{.m}
//! SKWMediaConnection* media;
//!
//! [media close];
//! media = nil;
//! \endcode
- (void)close;

//! \~japanese SKWMediaConnection のイベントコールバック Block を設定します。
//! \~english Set callbacks for media connection events. (Block Literal Syntax)
//! \~
//!
//! \code{.m}
//! SKWMediaConnection* media;
//!
//! [media on:SKW_MEDIACONNECTION_EVENT_STREAM callback:^(NSObject* obj) {
//!     SKWMediaStream *stream = (SKWMediaStream *)obj;
//! }];
//!
//! [media on:SKW_MEDIACONNECTION_EVENT_REMOVE_STREAM callback:^(NSObject* obj) {
//!     SKWMediaStream *stream = (SKWMediaStream *)obj;
//! }];
//!
//! [media on:SKW_MEDIACONNECTION_EVENT_CLOSE callback:^(NSObject* obj) {
//!     // クローズ時の処理を記述
//! }];
//!
//! [media on:SKW_MEDIACONNECTION_EVENT_ERROR callback:^(NSObject* obj) {
//!     SKWPeerError* err = (SKWPeerError*)obj;
//!     NSLog(@"%@", err);
//! }];
//! \endcode
//!
//!  @param event
//! \~japanese 設定するイベント種別を指定します。
//! \~english Event type
//! \~
//!
//! @param callback
//! \~japanese イベント発生時に実行する Block を設定します。
//! \~english Callback block literal
//! \~
- (void)on:(SKWMediaConnectionEventEnum)event callback:(SKWMediaConnectionEventCallback __nullable)callback;

//! \~japanese
//! 送信しているメディアストリームを更新します。
//! 受信のみモードから双方向に切り替えることもできます。
//! \~english
//! \~
//!
//! \code{.m}
//! SKWMediaConnection* connection;
//! SKWMediaStream* stream;
//!
//! [connection replaceStream:stream];
//!
//! \endcode
//!
//! @param newStream
//! \~japanese 対向のピアに送るメディアストリーム
//! \~english
//! \~
- (void)replaceStream:(SKWMediaStream* __nullable)newStream;

@end
