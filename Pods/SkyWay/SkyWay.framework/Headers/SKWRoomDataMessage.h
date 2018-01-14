////////////////////////////////////////////////////////////////////////
// SKWRoomDataMessage.h
// SkyWay SDK
////////////////////////////////////////////////////////////////////////
#import <Foundation/Foundation.h>

/**
 * \file SKWRoomDataMessage.h
 */

//! \~japanese  ルームで受信するデータメッセージです
//! \~english Data received from peer.
//! \~
@interface SKWRoomDataMessage : NSObject < NSCopying >

//! \~japanese  送信者のピア ID
//! \~english The peerId of the peer who sent the data.
//! \~
@property (nonatomic, readonly) NSString* src;

//! \~japanese  受信したデータ
//! \~english The data that a peer sent in the room.
//! \~
@property (nonatomic, readonly) NSObject* data;

@end
