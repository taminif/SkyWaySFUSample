////////////////////////////////////////////////////////////////////////
// SKWNavigator.h
// SkyWay SDK
////////////////////////////////////////////////////////////////////////
#import <Foundation/Foundation.h>

/**
 * \file SKWNavigator.h
 */

@class SKWMediaConstraints;
@class SKWMediaStream;
@class SKWPeer;

//! \~japanese Web ブラウザの navigator 相当のクラスになります。
//! \~english Alternative class as browser navigator
//! \~
@interface SKWNavigator : NSObject

//! \~japanese 初期化を行います。
//! \~english Initialize navigator
//! \~
//!
//! \code{.m}
//! SKWPeer* peer;
//! [SKWNavigator initialize:peer];
//! \endcode
//!
//! @param peer
//! \~japanese 作成・初期化済みの SKWPeer オブジェクト
//! \~english Initialized SKWPeer object.
//! \~
+ (void)initialize:(SKWPeer* __nonnull)peer;

//! \~japanese ローカルメディアストリームを取得します。
//! \~english Terminate navigator
//! \~
//! \code{.m}
//! [SKWNavigator terminate];
//! \endcode
+ (void)terminate;

//! \~japanese
//! \~english Get video stream
//! \~
//!
//! \code{.m}
//! SKWMediaConstraints* constraints = [[SKWMediaConstraints alloc] init];
//! SKWMediaStream* stream = [SKWNavigator getUserMedia:constraints];
//! \endcode
//!
//! @param constraints
//! \~japanese メディアストリームの設定
//! \~english Using media constraints.
//! \~
//! @return
//! \~japanese メディアストリームオブジェクト
//! \~english Media stream object.
//! \~
+ (SKWMediaStream* __nullable)getUserMedia:(SKWMediaConstraints* __nonnull)constraints;

@end
