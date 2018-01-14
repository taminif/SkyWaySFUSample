////////////////////////////////////////////////////////////////////////
// SKWVideo.h
// SkyWay SDK
////////////////////////////////////////////////////////////////////////
#import <Foundation/Foundation.h>
#if TARGET_OS_IPHONE
#import <UIKit/UIKit.h>
#define ViewRoot UIView
#elif TARGET_OS_MAC
#import <AppKit/AppKit.h>
#define ViewRoot NSView
#else
#define ViewRoot NSObject
#endif
#import "SKWCommon.h"

/**
 * \file SKWVideo.h
 */

@class SKWMediaStream;

//! \~japanese 映像を表示するレンダラービューオブジェクトです。
//! \~english Video view
//! \~
//!
//! \code{.m}
//! CGRect rect = CGRectMake(32.0f, 32.0f, 256.0f, 256.0f);
//! SKWVideo* video = [[SKWVideo alloc] initWithFrame:rect];
//! [self.view addSubview:video];
//! \endcode
@interface SKWVideo : ViewRoot

//! \~japanese メディアソースとして指定のメディアストリームトラック番号を追加します。
//! \~english Add media stream.
//! \~
//!
//! \~japanese
//! このメソッドは非推奨となりました。代わりに [SKWMediaStream -addVideoRenderer:track:] を使用してください。
//! \~english
//! \~
//!
//! \code{.m}
//! SKWMediaStream* stream;
//! SKWVideo* video = (SKWVideo *)[self.view viewWithTag:100];
//! [video addSrc:stream track:0];
//! \endcode
//!
//! @param stream
//! \~japanese 追加するメディアストリーム
//! \~english Media stream.
//! \~
//! @param trackNo
//! \~japanese 追加するビデオトラック番号 (0 始まり)
//! \~english Media track number.
//! \~
//! @return
//! \~japanese 実行結果
//! \~english Result code.
//! \~
//! @deprecated
- (BOOL)addSrc:(SKWMediaStream* __nonnull)stream track:(NSUInteger)trackNo SKYWAY_API_DEPRECATED;

//! \~japanese メディアソースとして使用していたメディアストリームトラック番号を削除します。
//! \~english Remove video stream.
//! \~
//!
//! \~japanese
//! このメソッドは非推奨となりました。代わりに [SKWMediaStream -removeVideoRenderer:track:] を使用してください。
//! \~english
//! \~
//!
//! \code{.m}
//! SKWMediaStream* stream;
//! SKWVideo* video = (SKWVideo *)[self.view viewWithTag:100];
//! [video removeSrc:stream track:0];
//! \endcode
//!
//! @param stream
//! \~japanese 削除するメディアストリーム
//! \~english Media stream.
//! \~
//! @param trackNo
//! \~japanese 削除するメディアストリーム
//! \~english Media track number.
//! \~
//! @return
//! \~japanese 実行結果
//! \~english Result code.
//! \~
- (BOOL)removeSrc:(SKWMediaStream* __nonnull)stream track:(NSUInteger)trackNo SKYWAY_API_DEPRECATED;

//! \~japanese 映像サイズが変更された場合に、呼ばれるコールバックを設定します。
//! \~english Set change video size callback.
//! \~
//!
//! \code{.m}
//! SKWVideo* video = (SKWVideo *)[self.view viewWithTag:100];
//! [video setDidChangeVideoSizeCallback:^(CGSize size) {
//!     //
//! }];
//! \endcode
//!
//! @param callback
//! \~japanese 呼び出されるコールバックブロック
//! \~english Callback block.
//! \~
- (void)setDidChangeVideoSizeCallback:(void (^ __nonnull)(CGSize))callback;

//! \~japanese 左右反転を行います
//! \~english Set mirror viewing
//! \~
//!
//! @param mirror
//! \~japanese 鏡と同じかどうか
//! \~english Mirror viewing.
//! \~
- (void)setMirrorViewing:(BOOL)mirror;

@end
