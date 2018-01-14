////////////////////////////////////////////////////////////////////////
// SKWMediaStream.h
// SkyWay SDK
////////////////////////////////////////////////////////////////////////
#import <Foundation/Foundation.h>
#import "SKWMediaConstraints.h"
#import "SKWCommon.h"

/**
 * \file SKWMediaStream.h
 */

@class SKWVideo;

//! \~japanese メディアストリーム
//! \~english Media stream
//! \~
@interface SKWMediaStream : NSObject < NSCopying >

//! \~japanese メディアストリームのラベルです
//! \~english media stream label
//! \~
@property(nonatomic, readonly) NSString* __nullable label;

//! \~japanese リモートメディアストリームを所有しているピア ID です。ローカルストリームの場合は割り当てられません。
//! \~english remote media stream peer id
//! \~
@property(nonatomic, readonly) NSString* __nullable peerId;

//! \~japanese メディアストリームをすべて閉じます。
//! \~english Close all tracks.
//! \~
- (void)close;

//! \~japanese メディアストリームに追加されているビデオトラック数を取得します。
//! \~english Get video track count.
//! \~
//!
//! \code{.m}
//! SKWMediaStream* stream;
//! NSUInteger videos = [stream getVideoTracks];
//! \endcode
//!
//! @return
//! \~japanese ビデオトラック数
//! \~english Count of video track.
//! \~
- (NSUInteger)getVideoTracks;

//! \~japanese メディアストリームに追加済みのビデオトラック再生状態を設定します。
//! \~english Set video track enabling state.
//! \~
//!
//! \code{.m}
//! SKWMediaStream* stream;
//! [stream setEnableVideoTrack:0 enable:YES];
//! \endcode
//!
//! @param pos
//! \~japanese ビデオトラック番号 (0 始まり)
//! \~english Track number.
//! \~
//! @param enable
//! \~japanese 再生状態
//! `enable` | 再生状態
//! -------- | ----
//! \c YES   | 再生します
//! \c NO    | 停止します
//! \~english Enabling state.
//! \~
- (void)setEnableVideoTrack:(NSUInteger)pos enable:(BOOL)enable;

//! \~japanese メディアストリームに追加済みのビデオトラック再生状態を取得します。
//! \~english Get video track enabling state.
//! \~
//!
//! \code{.m}
//! SKWMediaStream* stream;
//! BOOL enable = [stream getEnableVideoTrack:0];
//! if (enable) {
//!     // playing
//! } else {
//!     // stopped
//! }
//! \endcode
//!
//! @param pos
//! \~japanese ビデオトラック番号 (0 始まり)
//! \~english Track number.
//! \~
//! @return
//! \~japanese 再生状態
//! \~english Enabling state.
//! \~
- (BOOL)getEnableVideoTrack:(NSUInteger)pos;

//! \~japanese メディアストリームに追加されているオーディオトラック数を取得します。
//! \~english Get audio track count.
//! \~
//!
//! \code{.m}
//! SKWMediaStream* stream;
//! NSUInteger audios = [stream getVideoTracks];
//! \endcode
//!
//! @return
//! \~japanese オーディオトラック数
//! \~english Count of audio track.
//! \~
- (NSUInteger)getAudioTracks;

//! \~japanese メディアストリームに追加済みのオーディオトラック再生状態を設定します。
//! \~english Set audio track enabling state.
//! \~
//!
//! \code{.m}
//! SKWMediaStream* stream;
//! [stream setEnableAudioTrack:0 enable:YES];
//! \endcode
//!
//! @param pos
//! \~japanese オーディオトラック番号 (0 始まり)
//! \~english Track number.
//! \~
//! @param enable
//! \~japanese 再生状態
//! `enable` | 再生状態
//! -------- | ----
//! \c YES   | 再生します
//! \c NO    | 停止します
//! \~english Enabling state.
//! \~
- (void)setEnableAudioTrack:(NSUInteger)pos enable:(BOOL)enable;

//! \~japanese メディアストリームに追加済みのオーディオトラック再生状態を取得します。
//! \~english Get audio track enabling state.
//! \~
//!
//! \code{.m}
//! SKWMediaStream* stream;
//! BOOL enable = [stream getEnableAudioTrack:0];
//! if (enable) {
//!     // playing
//! } else {
//!     // stopped
//! }
//! \endcode
//!
//! @param pos
//! \~japanese オーディオトラック番号 (0 始まり)
//! \~english Track number.
//! \~
//! @return
//! \~japanese 再生状態
//! \~english Enabling state.
//! \~
- (BOOL)getEnableAudioTrack:(NSUInteger)pos;

//! \~japanese ローカル iOS デバイスのメディアストリームの場合、カメラ位置を設定します。
//! \~english Set camera position.
//! \~
//!
//! \code{.m}
//! SKWMediaStream* stream;
//! BOOL result = [stream setCameraPosition:SKW_CAMERA_POSITION_FRONT];
//! if (result) {
//!     // successful.
//! } else {
//!     // failure.
//! }
//! \endcode
//!
//! @param pos
//! \~japanese 列挙型カメラ位置
//! \~english Camera position.
//! \~
//! @return
//! \~japanese 呼び出し結果
//! \~english Method result.
//! \~
- (BOOL)setCameraPosition:(SKWCameraPositionEnum)pos;

//! \~japanese ローカル iOS デバイスのメディアストリームオブジェクトの場合、現在のカメラ位置を取得します。
//! \~english Get camera position.
//! \~
//!
//! \code{.m}
//! SKWMediaStream* stream;
//! SKWCameraPositionEnum pos = [stream getCameraPosition];
//! switch (pos) {
//! case SKW_CAMERA_POSITION_BACK:
//!     // front camera
//!     break;
//! case SKW_CAMERA_POSITION_FRONT:
//!     // back camera
//!     break;
//! case SKW_CAMERA_POSITION_UNSPECIFIED:
//!     // unknown
//!     break;
//! }
//! \endcode
//!
//! @return
//! \~japanese 現在のカメラ位置
//! \~english Current camera position.
//! \~
- (SKWCameraPositionEnum)getCameraPosition;

//! \~japanese ローカル iOS デバイスのメディアストリームの場合、使用カメラ位置を切り替えます。
//! \~english Switch camera.
//! \~
//!
//! \code{.m}
//! SKWMediaStream* stream;
//! BOOL result = [stream switchCamera];
//! if (result) {
//!     // successful.
//! } else {
//!     // failure.
//! }
//!
//! \endcode
//! @return
//! \~japanese 呼び出し結果
//! \~english Method result.
//! \~
- (BOOL)switchCamera;

//! \~japanese このストリームにビデオレンダラーを割り当てます
//! \~english
//! \~
//!
//! \code{.m}
//! SKWMediaStream* stream;
//! SKWVideo* video;
//!
//! [stream addVideoRenderer:video track:0];
//! \endcode
//!
//! @param renderer
//! \~japanese 割り当てるビデオレンダラー
//! \~english Video Renderer
//! \~
//! @param trackNo
//! \~japanese トラック番号 (0 始まり)
//! \~english Track number. (0-)
//! \~
- (void)addVideoRenderer:(SKWVideo* __nonnull)renderer track:(NSUInteger)trackNo;

//! \~japanese このストリームに割り当てられているビデオレンダラーを取り外します
//! \~english
//! \~
//!
//! \code{.m}
//! SKWMediaStream* stream;
//! SKWVideo* video;
//!
//! [stream removeVideoRenderer:video track:0];
//! \endcode
//!
//! @param renderer
//! \~japanese 割り当て済みのビデオレンダラー
//! \~english
//! \~
//! @param trackNo
//! \~japanese トラック番号 (0 始まり)
//! \~english Track number. (0-)
//! \~
- (void)removeVideoRenderer:(SKWVideo* __nonnull)renderer track:(NSUInteger)trackNo;

@end
