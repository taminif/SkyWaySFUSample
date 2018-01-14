////////////////////////////////////////////////////////////////////////
// SKWPeer.h
// SkyWay SDK
////////////////////////////////////////////////////////////////////////
#import "SKWHeaders.h"

/**
 * \file SKWPeer.h
 */

#ifndef DOXYGEN_SKIP_THIS
/// True string value
extern NSString* __nonnull const kSKWTrue;
/// False string value
extern NSString* __nonnull const kSKWFalse;

/**
 Connection types
 */
/// Connection type 'data'
extern NSString* __nonnull const kSKWConnectionTypeData;
/// Connection type 'media'
extern NSString* __nonnull const kSKWConnectionTypeMedia;

/**
 Peer data serialization types
 */
/// Binary
extern NSString* __nonnull const kSKWPeerSerializationBinary;
/// Binary (UTF-8)
extern NSString* __nonnull const kSKWPeerSerializationBinaryUtf8;
/// JSON
extern NSString* __nonnull const kSKWPeerSerializationJson;
/// None
extern NSString* __nonnull const kSKWPeerSerializationNone;
#endif // !DOXYGEN_SKIP_THIS

//! \~japanese ピアイベントタイプ
//! \~english Peer event type
//! \~
typedef NS_ENUM(NSUInteger, SKWPeerEventEnum)
{
    //! \~japanese シグナリングサーバとの接続が確立された時のイベントです
    //! \~english Emitted when a connection to the PeerServer is established.
    //! \~
    SKW_PEER_EVENT_OPEN,
    //! \~japanese リモートピアからのデータ接続が発生したときのイベントです
    //! \~english Emitted when a new data connection is established from a remote peer.
    //! \~
    SKW_PEER_EVENT_CONNECTION,
    //! \~japanese リモートピアからのメディア接続が発生した時のイベントです
    //! \~english Emitted when a remote peer attempts to call you.
    //! \~
    SKW_PEER_EVENT_CALL,
    //! \~japanese ピアが破棄された時のイベントです
    //! \~english Emitted when the peer is destroyed and can no longer accept or create any new connections
    //! \~
    SKW_PEER_EVENT_CLOSE,
    //! \~japanese ピアが切断された時のイベントです
    //! \~english Emitted when the peer is disconnected from the signalling server, either manually or because the connection to the signalling server was lost.
    //! \~
    SKW_PEER_EVENT_DISCONNECTED,
    //! \~japanese エラーが発生したときのイベントです
    //! \~english Errors on the peer are almost always fatal and will destroy the peer.
    //! \~
    SKW_PEER_EVENT_ERROR,
#ifndef DOXYGEN_SKIP_THIS
    /// Emitted when the change reachability status.
    SKW_PEER_EVENT_REACHABILITY,
#endif // !DOXYGEN_SKIP_THIS
    //! \~japanese 認証トークンの期限切れが近づくと発生するイベントです
    //! \~english
    //! \~
    SKW_PEER_EVENT_AUTH_EXPIRES_IN,
};

//! \~japanese ピアイベントコールバックシグネチャ
//! \~english Peer Event Callback signature.
//! \~
typedef void (^SKWPeerEventCallback)(NSObject* __nullable arg);

@class SKWPeerOption;
@class SKWConnection;
@class SKWPeerCredential;
@class SKWDataConnection;
@class SKWMediaConnection;
@class SKWMediaStream;
@class SKWConnectOption;
@class SKWCallOption;
@class SKWRoom;
@class SKWRoomOption;

//! \~japanese
//! ピアクラス
//! \~english
//! A peer class
//! \~
@interface SKWPeer : NSObject

//! \~japanese
//! ピア ID を表します。
//! \~english
/// The brokering ID of this peer. If no ID was specified in the constructor, this will be undefined until the open event is emitted.
//! \~
@property (nonatomic, readonly) NSString* __nullable identity;

//! \~japanese
//! コネクション接続管理オブジェクトです。リモート peer の ID が key として、peer と関連付けされるコネクション列を持つハッシュです。
//! \~english
//! A object array of all connections this peer, keyed by the remote peer's ID.
//! \~
@property (nonatomic, readonly) NSDictionary* __nullable connections;

//! \~japanese
//! 切断状態を表します。
//! `isDisconnected` | 状態
//! ---------------- | ----
//! \c YES           | サーバとは切断されています。
//! \c NO            | サーバとは接続されています。
//! \~english
//!     false if there is an active connection to the PeerServer.
//! \~
@property (nonatomic, readonly) BOOL isDisconnected;

//! \~japanese
//! 破棄状態を表します。
//! `isDestroyed` | 状態
//! ---------------- | ----
//! \c YES           | 破棄状態です。
//! \c NO            | 有効状態です。
//! \~english
//! true if this peer and all of its connections can no longer be used.
//! \~
@property (nonatomic, readonly) BOOL isDestroyed;

#ifndef DOXYGEN_SKIP_THIS
- (nonnull instancetype)init __attribute__((unavailable("init is not a supported initializer for this class.")));
#endif // !DOXYGEN_SKIP_THIS

//! \~japanese
//! SKWPeer オブジェクトの初期化を行います。
//! \~english
//! A peer can connect to other peers and listen for connections. ID is retrieve from brokering server.
//! \~
//!
//! \code{.m}
//! SKWPeerOption* options = [[SKWPeerOption alloc] init];
//! options.key = @"{your-dev-key}";
//! options.domain = @”{your-domain}”;
//! options.debug = SKW_PEER_DEBUG_LEVEL_ALL_LOGS;
//! options.turn = YES;
//!
//! SKWPeer* peer = [[SKWPeer alloc] initWithOptions:options];
//! \endcode
//!
//! @param options
//! \~japanese 設定情報オブジェクトを指定します。
//! \~english Option seetings.
//! \~
//! @return
//! \~japanese ピアオブジェクト
//! \~english PeerObjC object
//! \~
- (instancetype __nullable)initWithOptions:(SKWPeerOption* __nullable)options;

//! \~japanese
//! SKWPeer オブジェクトの初期化を行います。
//! \~english
//! A peer can connect to other peers and listen for connections.
//! \~
//!
//! \code{.m}
//! NSString* curtomPeerId = @"my-peer-id";
//! SKWPeerOption* options = [[SKWPeerOption alloc] init];
//! options.key = @"{your-dev-key}";
//! options.domain = @”{your-domain}”;
//! options.debug = SKW_PEER_DEBUG_LEVEL_ALL_LOGS;
//! options.turn = YES;
//!
//! SKWPeer* peer = [[SKWPeer alloc] initWithId:curtomPeerId options:options];
//! \endcode
//!
//! @param peerId
//! \~japanese 接続するピア ID を指定します。\c nil を指定した場合、ピア ID をサーバから取得する処理を行います。
//! \~english Other peers can connect to this peer using the provided ID. If no ID is given, one will be generated by the brokering server.
//! \~
//!
//! @param options
//! \~japanese 設定情報オブジェクトを指定します。
//! \~english Option seetings.
//! \~
//!
//! @return
//! \~japanese ピアオブジェクト
//! \~english PeerObjC object
//! \~
- (instancetype __nullable)initWithId:(NSString* __nullable)peerId options:(SKWPeerOption* __nullable)options NS_DESIGNATED_INITIALIZER;

//! \~japanese
//! 指定されたリモートへデータ接続を行い、SKWDataConnection を返します。失敗した場合には、error イベントが呼び出されます。
//! \~english
//! Connects to the remote peer specified by id and returns a data connection. Be sure to listen on the error event in case the connection fails.
//! \~
//!
//! \code{.m}
//! SKWPeer* peer;
//!
//! SKWDataConnection* data = [peer connectWithId:destId];
//! \endcode
//!
//! @param peerId
//! \~japanese 接続先リモートの peer ブローカー ID です (リモートのピア ID です)
//! \~english The brokering ID of the remote peer (their peer.id).
//! \~
//! @return
//! \~japanese
//! データコネクションオブジェクト
//! \~english
//! Data connection object
//! \~english
//! \~
- (SKWDataConnection* __nullable)connectWithId:(NSString* __nonnull)peerId;

//! \~japanese
//! 指定されたリモートへデータ接続を行い、SKWDataConnection を返します。失敗した場合には、error イベントが呼び出されます。
//! \~english
//! Connects to the remote peer specified by id and returns a data connection. Be sure to listen on the error event in case the connection fails.
//! \~
//!
//!
//! \code{.m}
//! SKWPeer* peer;
//!
//! SKWConnectOption* options = [[SKWConnectOption alloc] init];
//! options.label = @"chat";
//! options.metadata = @"hi !!!";
//! options.serialization = SKW_SERIALIZATION_NONE;
//!
//! SKWDataConnection* data = [peer connectWithId:destId options:options];
//! \endcode
//!
//! @param peerId
//! \~japanese 接続先リモートの peer ブローカー ID です (リモートのピア ID です)
//! \~english The brokering ID of the remote peer (their peer.id).
//! \~
//!
//! @param options
//! \~japanese 設定を指定します。
//! \~english Option setting dictionary
//! \~
//!
//! @return
//! \~japanese
//! データコネクションオブジェクト
//! \~english
//! Data connection object
//! \~english
//! \~
- (SKWDataConnection* __nullable)connectWithId:(NSString* __nonnull)peerId options:(SKWConnectOption* __nullable)options;

//! \~japanese
//! 指定されたリモートへメディア接続を行い、SKWMediaConnection を返します。失敗した場合には、error イベントが発生します。
//! \~english
//! Calls the remote peer specified by id and returns a media connection. Be sure to listen on the error event in case the connection fails.
//! \~
//!
//! \code{.m}
//! SKWPeer* peer;
//! SKWMediaStream* stream;
//! NSString* destId;
//!
//! SKWMediaConnection* media = [peer callWithId:destId stream:stream];
//! \endcode
//!
//! @param peerId
//! \~japanese 接続先リモートの peer ブローカー ID です (リモートのピア ID です)
//! \~english Remote peer ID
//! \~
//!
//! @param stream
//! \~japanese 使用するローカルメディアストリームです
//! \~english Video stream
//! \~
//!
//! @return
//! \~japanese メディアコネクションオブジェクト
//! \~english Media connection object
//! \~
- (SKWMediaConnection* __nullable)callWithId:(NSString* __nonnull)peerId stream:(SKWMediaStream* __nullable)stream;

//! \~japanese
//! 指定されたリモートへメディア接続を行い、SKWMediaConnection を返します。失敗した場合には、error イベントが発生します。
//! \~english
//! Calls the remote peer specified by id and returns a media connection. Be sure to listen on the error event in case the connection fails.
//! \~
//!
//! \code{.m}
//! SKWPeer* peer;
//! SKWMediaStream* stream;
//! NSString* destId;
//! SKWCallOption* options = [[SKWCallOption alloc] init];
//! options.metadata = @"yourMetadata";
//!
//! SKWMediaConnection* media = [peer callWithId:destId stream:stream options:options];
//! \endcode
//!
//! @param peerId
//! \~japanese 接続先リモートの peer ブローカー ID です (リモートのピア ID です)
//! \~english Remote peer ID
//! \~
//!
//! @param stream
//! \~japanese 使用するローカルメディアストリームです
//! \~english Video stream
//! \~
//!
//! @param options
//! \~japanese 設定を指定します。
//! \~english Option seeting dictionary
//! \~
//!
//! @return
//! \~japanese メディアコネクションオブジェクト
//! \~english Media connection object
//! \~
- (SKWMediaConnection* __nullable)callWithId:(NSString* __nonnull)peerId stream:(SKWMediaStream* __nullable)stream options:(SKWCallOption* __nullable)options;

//! \~japanese SKWPeer のイベントコールバック Block を設定します。
//! \~english Set blocks for peer events. (Block Literal Syntax)
//! \~
//!
//! \code{.m}
//! SKWPeer* peer;
//!
//! [peer on:SKW_PEER_EVENT_OPEN callback:^(NSObject* obj) {
//!     if (YES == [obj isKindOfClass:[NSString class]]) {
//!         NSString* ownId = (NSString *)obj;
//!     }
//! }];
//!
//! [peer on:SKW_PEER_EVENT_CONNECTION callback:^(NSObject* obj) {
//!     SKWDataConnection* data = (SKWDataConnection *)obj;
//! }];
//!
//! [peer on:SKW_PEER_EVENT_CALL callback:^(NSObject* obj) {
//!     SKWMediaConnection* media = (SKWMediaConnection *)obj;
//! }];
//!
//! [peer on:SKW_PEER_EVENT_CLOSE callback:^(NSObject* obj) {
//!     // ...
//! }];
//!
//! [peer on:SKW_PEER_EVENT_DISCONNECTED callback:^(NSObject* obj) {
//!     // ...
//! }];
//!
//! [peer on:SKW_PEER_EVENT_ERROR callback:^(NSObject* obj) {
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
//! \~english Callback block literal
//! \~
- (void)on:(SKWPeerEventEnum)event callback:(SKWPeerEventCallback __nullable)callback;

//! \~japanese
//! すべてのコネクションを切断し、シグナリングサーバとの接続を切断します。
//! \~english
//! Close the connection to the server, leaving all existing data and media connections intact.
//! peer.disconnected will be set to true and the disconnected event will fire.
//! \~
//!
//!
//! \code{.m}
//! SKWPeer* peer;
//!
//! [peer disconnect];
//! \endcode
//!
//! @return
//! \~japanese 呼び出し結果
//! \~english Processing result
//! \~
- (BOOL)disconnect;

//! \~japanese シグナリングサーバとの再接続を行います。 ピア ID は既に割当済みの ID を使用します。
//! \~english Attempt to reconnect to the server with the peer's old ID.
//! \~
//!
//! \code{.m}
//! SKWPeer* peer;
//!
//! [peer reconnect];
//! \endcode
//!
- (void)reconnect;

//! \~japanese
//! ピアオブジェクトを破棄状態にします。
//! \~english
//! Close the connection to the server and terminate all existing connections. peer.destroyed will be set to true.
//! \~
//!
//! \code{.m}
//! SKWPeer* peer;
//!
//! [peer destroy];
//! \endcode
//!
//! @return
//! \~japanese 呼び出し結果
//! \~english Processing result
//! \~
- (BOOL)destroy;

//! \~japanese
//! SkyWay シグナリングサーバから接続可能な ピア ID の一覧を取得します。
//! \~english
//! Listing peer ID.
//! \~
//!
//! \code{.m}
//! SKWPeer* peer;
//!
//! [peer listAllPeers:^(NSArray* aryPeers) {
//!    for (NSString* strPeer in aryPeers) {
//!        // something to do.
//!    }
//! }];
//! \endcode
//!
//! @param callback
//! \~japanese コールバックブロック
//! \~english Callback block
//! \~
- (void)listAllPeers:(void (^ __nullable)(NSArray * __nullable))callback;

#ifndef DOXYGEN_SKIP_THIS
- (SKWConnection* __nullable)getConnectionWithId:(NSString* __nonnull)peerId connectionId:(NSString* __nonnull)connectionId;
#endif // !DOXYGEN_SKIP_THIS

//! \~japanese
//! ルームに参加します
//! \~english
//! \~
//!
//! \~japanese フルメッシュルーム:
//! \~english Full mesh room example:
//! \~
//! \code{.m}
//! SKWPeer* peer;
//! SKWMediaStream* localStream;
//!
//! NSString* roomName = @"fullmesh_videochat_room";
//!
//! SKWRoomOption* options = [[SKWRoomOptions alloc] init];
//! option.mode = SKW_ROOM_MODE_MESH;
//! option.stream = localStream;
//!
//! SKWMeshRoom* meshRoom = (SKWMeshRoom*)[peer joinRoomWithName:roomName options:options];
//! \endcode
//!
//! \~japanese SFU ルーム:
//! \~english SFU room example:
//! \~
//! \code{.m}
//! SKWPeer* peer;
//!
//! NSString* roomName = @"sfu_textchat_room";
//!
//! SKWRoomOption* options = [[SKWRoomOptions alloc] init];
//! option.mode = SKW_ROOM_MODE_SFU;
//!
//! SKWSFURoom* sfuRoom = (SKWSFURoom*)[peer joinRoomWithName:roomName options:options];
//! \endcode
//!
//! @param roomName
//! \~japanese ルーム名
//! \~english Room name
//! \~
//! @param option
//! \~japanese ルームオプション
//! \~english Room option
//! \~
//! @return
//! \~japanese ルームに参加できた場合はルームオブジェクトが返されます。
//! \~english Room object
//! \~
- (SKWRoom* __nullable)joinRoomWithName:(NSString* __nonnull)roomName options:(SKWRoomOption* __nonnull)option;

//! \~japanese
//! 認証情報を更新します。
//! \~english
//! \~
//!
//! \code{.m}
//! SKWPeer* peer;
//!
//! SKWPeerCredential* credential = [[SKWPeerCredential alloc] init];
//! credential.timestamp = [[NSDate date] timeIntervalSince1970];
//! credential.ttl = 86400;
//! credential.authToken = @"calculated auth token";
//!
//! [peer updateCredential:credential];
//! \endcode
//!
//! @param newCredential
//! \~japanese 新しい認証情報
//! \~english new credential
//! \~
- (void)updateCredential:(SKWPeerCredential* __nonnull)newCredential;

@end
