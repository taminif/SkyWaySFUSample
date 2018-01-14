////////////////////////////////////////////////////////////////////////
// SKWIceConfig.h
// SkyWay SDK
////////////////////////////////////////////////////////////////////////
#import <Foundation/Foundation.h>

/**
 * \file SKWIceConfig.h
 */

//! \~japanese SKWPeer 初期化時の STUN/TURN サーバ設定情報クラスです。
//! \~english ICE server config
//! \~
@interface SKWIceConfig : NSObject < NSCopying >

//! \~japanese STUN/TURN サーバの URL を指定します。
//! \~english
//! STUN/TURN server URL string (ex. stun:stun.l.google.com:19302, turn:homeo@turn.bistri.com:80, turn:153.149.7.233:443?transport=udp, turn:153.149.7.233:443?transport=tcp)
//! \~
@property (nonatomic) NSString* url;

//! \~japanese ユーザー名が必要な場合に設定します。
//! \~english User name string
//! \~
@property (nonatomic) NSString* username;

//! \~japanese パスワードが必要な場合に設定します。
//! \~english Credential string
//! \~
@property (nonatomic) NSString* credential;

@end
