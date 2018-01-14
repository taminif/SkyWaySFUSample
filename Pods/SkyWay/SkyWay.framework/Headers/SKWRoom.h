////////////////////////////////////////////////////////////////////////
// SKWRoom.h
// SkyWay SDK
////////////////////////////////////////////////////////////////////////
#import <Foundation/Foundation.h>

/**
 * \file SKWRoom.h
 */

@class SKWMediaStream;

//! \~japanese ルームイベント
//! \~english Room events
//! \~
typedef NS_ENUM(NSUInteger, SKWRoomEventEnum)
{
    //! \~japanese 現在のルームに新しいメディアストリームが追加された時のイベントです
    //! \~english
    //! \~
    SKW_ROOM_EVENT_STREAM, // arg1 = added stream
    //! \~japanese 現在のルームから既存のメディアストリームが削除された時のイベントです
    //! \~english
    //! \~
    SKW_ROOM_EVENT_REMOVE_STREAM, // arg1 = removed stream
    //! \~japanese ルームに自分が入室した時のイベントです
    //! \~english
    //! \~
    SKW_ROOM_EVENT_OPEN, // arg1 = room name
    //! \~japanese 現在のルームから自分が退室したときのイベントです
    //! \~english
    //! \~
    SKW_ROOM_EVENT_CLOSE, // arg1 = room name
    //! \~japanese 現在のルームにリモートピアが入室した時のイベントです
    //! \~english
    //! \~
    SKW_ROOM_EVENT_PEER_JOIN, // arg1 = src
    //! \~japanese 現在のルームからリモートピアが退室した時のイベントです
    //! \~english
    //! \~
    SKW_ROOM_EVENT_PEER_LEAVE, // arg1 = src
    //! \~japanese エラーが発生した時のイベントです
    //! \~english
    //! \~
    SKW_ROOM_EVENT_ERROR,
    //! \~japanese 現在のルームにリモートピアがらデータが送信された時のイベントです
    //! \~english
    //! \~
    SKW_ROOM_EVENT_DATA, // arg1 = data
    //! \~japanese 現在のルームのログが取得できた時のイベントです
    //! \~english
    //! \~
    SKW_ROOM_EVENT_LOG, // arg1 = logs
};

//! \~japanese ルームイベントコールバックシグネチャ
//! \~english Room Event Callback signature.
//! \~
typedef void (^SKWRoomEventCallback)(NSObject* __nullable arg);

//! \~japanese SKWMeshRoom / SKWSFURoom の基底クラスです。
//! \~english Room base class.
//! \~
@interface SKWRoom : NSObject

//! \~japanese ルーム名
//! \~english Room name.
//! \~
@property (nonatomic, readonly) NSString* __nullable name;

#ifndef DOXYGEN_SKIP_THIS
- (__nullable instancetype)init __attribute__((unavailable("init is not a supported initializer for this class.")));
#endif // !DOXYGEN_SKIP_THIS

//! \~japanese 現在のルームに入室中のピアにデータを送信します。NSString* または NSData* を送信できます。
//! \~english Send data to all participants in the room with WebSocket. It emits broadcast event.
//! \~
//!
//! \code{.m}
//! SKWRoom* room;
//! [room send:@"Hello."];
//! \endcode
//!
//! @param data
//! \~japanese 送信データ
//! \~english Send data
//! \~
//! @return
//! \~japanese 呼び出し結果
//! \~english Result.
//! \~
- (BOOL)send:(NSObject* __nonnull)data;

//! \~japanese SKWRoom のイベントコールバック block を設定します。
//! \~english Set blocks for SKWRoom events.
//! \~
//!
//! \code{.m}
//! SKWRoom* room;
//!
//! [room on:SKW_ROOM_EVENT_STREAM callback:^(NSObject* arg1, NSObject* arg2) {
//!     SKWMediaStream* stream = (SKWMediaStream*)arg1;
//! }];
//!
//! [room on:SKW_ROOM_EVENT_REMOVE_STREAM callback:^(NSObject* arg1, NSObject* arg2) {
//!     SKWMediaStream* stream = (SKWMediaStream*)arg1;
//! }];
//!
//! [room on:SKW_ROOM_EVENT_OPEN callback:^(NSObject* arg1, NSObject* arg2) {
//!     NSString* roomName = (NSString*)arg1;
//! }];
//!
//! [room on:SKW_ROOM_EVENT_CLOSE callback:^(NSObject* arg1, NSObject* arg2) {
//!     NSString* roomName = (NSString*)arg1;
//! }];
//!
//! [room on:SKW_ROOM_EVENT_PEER_JOIN callback:^(NSObject* arg1, NSObject* arg2) {
//!     NSString* peerId = (NSString*)arg1;
//! }];
//!
//! [room on:SKW_ROOM_EVENT_PEER_LEAVE callback:^(NSObject* arg1, NSObject* arg2) {
//!     NSString* peerId = (NSString*)arg1;
//! }];
//!
//! [room on:SKW_ROOM_EVENT_ERROR callback:^(NSObject* arg1, NSObject* arg2) {
//!     SKWPeerError* error = (SKWPeerError*)arg1;
//! }];
//!
//! [room on:SKW_ROOM_EVENT_DATA callback:^(NSObject* arg1, NSObject* arg2) {
//!     NSString* peerId = (NSString*)arg1;
//!     if ([arg2 isKindOfClass:[NSString class]]) {
//!         NSString* data = (NSString*)arg2;
//!     }
//!     else if ([arg2 isKindOfClass:[NSData class]]) {
//!         NSData* data = (NSData*)arg2;
//!     }
//! }];
//!
//! [room on:SKW_ROOM_EVENT_LOG callback:^(NSObject* arg1, NSObject* arg2) {
//!     NSArray* logs = (NSArray*)arg1;
//! }];
//! \endcode
//!
//! @param event
//! \~japanese 設定するイベント種別を指定します。
//! \~english Event type
//! \~
//! @param callback
//! \~japanese イベント発生時に実行する Block を設定します。
//! \~english Callback block literal
//! \~
- (void)on:(SKWRoomEventEnum)event callback:(SKWRoomEventCallback __nullable)callback;

//! \~japanese SKWRoom の設定済みイベントコールバック block を解除します。
//! \~english Cancels the set event callback block of SKWRoom.
//! \~
//!
//! \code{.m}
//! SKWRoom* room;
//! [room offAll];
//! \endcode
- (void)offAll;

//! \~japanese シグナリングサーバにルームのログ取得を要求します。結果は SKW_ROOM_EVENT_LOG イベントで返されます。
//! \~english Start getting room's logs from signaling server. The result is returned in the SKW_ROOM_EVENT_LOG event.
//! \~
//!
//! \code{.m}
//! SKWRoom* room;
//!
//! [room on:SKW_ROOM_EVENT_LOG callback:^(NSObject* arg1, NSObject* arg2) {
//!     NSArray* logs = (NSArray*)arg1;
//!     [logs enumerateObjectsUsingBlock:^(id obj, NSUInteger idx, BOOL* stop) {
//!         NSString* logStr = (NSString*)obj;
//!         NSError* error = nil;
//!         id logData = [NSJSONSerialization JSONObjectWithData:[logStr dataUsingEncoding:NSUTF8StringEncoding]
//!                                                      options:0
//!                                                        error:&error];
//!         if (nil == error)
//!         {
//!             NSLog(@"SKW_ROOM_EVENT_LOG: %@", logData);
//!         }
//!     }];
//! }];
//!
//! [room getLog];
//! \endcode
- (void)getLog;

@end
