////////////////////////////////////////////////////////////////////////
// SKWSFURoom.h
// SkyWay SDK
////////////////////////////////////////////////////////////////////////
#import <Foundation/Foundation.h>
#import "SKWRoom.h"

/**
 * \file SKWSFURoom.h
 */

@class SKWMediaStream;
@class SKWRoomOption;

//! \~japanese SFU ルームクラス
//! \~english SFU room class
//! \~
//!
//! \~japanese
//! SFU接続でのルームを提供するルームクラスです。
//! \~english
//! Class that manages SFU type room.
//! \~
@interface SKWSFURoom : SKWRoom

//! \~japanese ルームを退出し、ルーム内のすべてのユーザーとのコネクションをcloseします。
//! \~english Close PeerConnection and emit leave and close event.
//! \~
- (void)close;

//! \~japanese
//! 送信しているメディアストリームを更新します。
//! 受信のみモードから双方向に切り替えることもできます。
//! \~english Replace the stream being sent with a new one.
//! \~
//!
//! \code{.m}
//! SKWSFURoom* room;
//! SKWMediaStream* stream;
//!
//! [room replaceStream:stream];
//!
//! \endcode
//!
//! @param newStream
//! \~japanese 交換対象となる新しいMediaStream
//! \~english The stream to replace the old stream with.
//! \~
- (void)replaceStream:(SKWMediaStream* __nullable)newStream;

@end
