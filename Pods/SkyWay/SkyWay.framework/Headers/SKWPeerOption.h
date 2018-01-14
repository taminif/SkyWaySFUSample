////////////////////////////////////////////////////////////////////////
// SKWPeerOption.h
// SkyWay SDK
////////////////////////////////////////////////////////////////////////
#import <Foundation/Foundation.h>
#import "SKWCommon.h"

/**
 * \file SKWPeerOption.h
 */

@class SKWPeerCredential;

#ifndef DOXYGEN_SKIP_THIS
/**
 Peer type
 */
typedef NS_ENUM(NSUInteger, SKWPeerTypeEnum)
{
    /// skyway.io
    SKW_PEER_TYPE_SKYWAY = 0,
    /// peerjs.com
    SKW_PEER_TYPE_PEERJS = 1,
} SKYWAY_API_DEPRECATED;
#endif // !DOXYGEN_SKIP_THIS

//! \~japanese デバッグアウトプットレベル
//! \~english Debug output level
//! \~
typedef NS_ENUM(NSUInteger, SKWDebugLevelEnum)
{
    //! \~japanese ログを出力しません
    //! \~english Prints no logs.
    //! \~
    SKW_DEBUG_LEVEL_NO_LOGS = 0,
    //! \~japanese エラーのみのログを出力します
    //! \~english Prints only errors.
    //! \~
    SKW_DEBUG_LEVEL_ONLY_ERROR = 1,
    //! \~japanese エラーと警告のログを出力します
    //! \~english errors and warnings.
    //! \~
    SKW_DEBUG_LEVEL_ERROR_AND_WARNING = 2,
    //! \~japanese 全てのログを出力します
    //! \~english Prints all logs.
    //! \~
    SKW_DEBUG_LEVEL_ALL_LOGS = 3,
};

//! \~japanese SKWPeer 初期化オプションクラス
//! \~english SKWPeer initialize option class
//! \~
@interface SKWPeerOption : NSObject < NSCopying >

//! \~japanese 接続先シグナリングサーバの種別を指定します。(現在は SkyWay のみが有効であり、指定しても無視されます。)
//! \~english Type of the PeerServer. Defaults to PEER_TYPE_SKYWAY.
//! \~
@property (nonatomic) SKWPeerTypeEnum type SKYWAY_API_DEPRECATED;

//! \~japanese SkyWay API キーを指定します
//! \~english API key for the cloud PeerServer.
//! \~
@property (nonatomic) NSString* __nullable key;

//! \~japanese  サーバのホスト名です。指定が無い場合は、SkyWay シグナリングサーバによって自動的に接続先が決定されます。
//! \~english PeerServer host. Defaults to 0.peerjs.com. Also accepts '/' to signify relative hostname
//! \~
@property (nonatomic) NSString* __nullable host;

//! \~japanese  サーバのポート番号です。指定が無い場合は、SkyWay シグナリングサーバによって自動的に接続先が決定されます。
//! \~english PeerServer port.
//! \~
@property (nonatomic) NSInteger port;

//! \~japanese  自身のシグナリングサーバが動作している場所のパスです。(現在は指定しても無視されます。)
//! \~english The path where your self-hosted PeerServer is running. Defaults to '/'.
//! \~
@property (nonatomic) NSString* __nullable path SKYWAY_API_DEPRECATED;

//! \~japanese  サーバとの SSL 接続を行うか指定します。デフォルトは YES となります。
//! \~english Set to true if you're using SSL.
//! \~
@property (nonatomic) BOOL secure;

//! \~japanese ICE/TURN サーバ設定を指定します
//! \~english This contains any custom ICE/TURN server configuration.
//! \~
@property (nonatomic) NSArray* __nullable config;

//! \~japanese ログレベルを指定します。デフォルトは \a PEER_DEBUG_LEVEL_NO_LOGS です。
//! \~english Prints log messages depending on the debug level passed in. Defaults to PEER_DEBUG_LEVEL_NO_LOGS.
//! \~
@property (nonatomic) SKWDebugLevelEnum debug;

//! \~japanese SkyWay API に関連するドメインを指定します
//! \~english Domain related to the SkyWay API Key
//! \~
@property (nonatomic) NSString* __nullable domain;

//! \~japanese SkyWay TURN サーバを使用します (TURN サーバの利用を申請する必要があります)
//! \~english Using SkyWay TURN server. (Need to request for a TURN server use to SkyWay)
//! \~
@property (nonatomic) BOOL turn;

//! \~japanese
//! H.264 ハードウェアコーデックを利用するかどうか指定します。
//! デフォルトは YES となります。
//! (現在は常に利用するようになっており、NO を指定しても無視されます。)
//! \~english Using Hardware codec H.264 (iOS 8.0 later)
//! \~
@property (nonatomic) BOOL useH264 SKYWAY_API_DEPRECATED;

@property (nonatomic) SKWPeerCredential* __nullable credential;

@end
