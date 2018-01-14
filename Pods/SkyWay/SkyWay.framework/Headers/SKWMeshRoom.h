////////////////////////////////////////////////////////////////////////
// SKWMeshRoom.h
// SkyWay SDK
////////////////////////////////////////////////////////////////////////
#import "SKWRoom.h"

/**
 * \file SKWMeshRoom.h
 */

@class SKWMediaStream;

//! \~japanese メッシュ接続でのルームを提供するルームクラスです。
//! \~english Mesh room class
//! \~
//!
//! \~japanese
//! メッシュ接続でのルームを管理するクラスです。
//! \~english
//! Class that manages fullmesh type room.
//! \~
@interface SKWMeshRoom : SKWRoom

//! \~japanese ルームを退出し、ルーム内のすべてのユーザーとのコネクションをcloseします。
//! \~english Close PeerConnection and emit leave and close event.
//! \~
- (void)close;

//! \~japanese
//! 送信しているメディアストリームを更新します。
//! 受信のみモードから双方向に切り替えることもできます。
//! \~english Replace the stream being sent on all MediaConnections with a new one.
//! \~
//!
//! \code{.m}
//! SKWMeshRoom* room;
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
