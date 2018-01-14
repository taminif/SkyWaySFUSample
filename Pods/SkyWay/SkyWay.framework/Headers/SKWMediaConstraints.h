////////////////////////////////////////////////////////////////////////
// SKWMediaConstraints.h
// SkyWay SDK
////////////////////////////////////////////////////////////////////////
#import <Foundation/Foundation.h>
#import "SKWCommon.h"

/**
 * \file SKWMediaConstraints.h
 */

//! \~japanese カメラ位置
//! \~english Device camera position
//! \~
typedef NS_ENUM(NSUInteger, SKWCameraPositionEnum)
{
    //! \~japanese 指定なし
    //! \~english Unspecified
    //! \~
    SKW_CAMERA_POSITION_UNSPECIFIED = 0,
    //! \~japanese 背面カメラ
    //! \~english Back camera
    //! \~
    SKW_CAMERA_POSITION_BACK = 1,
    //! \~japanese 前面カメラ
    //! \~english Front camera
    //! \~
    SKW_CAMERA_POSITION_FRONT = 2,
};

//! \~japanese カメラモード
//! \~english Device camera mode
//! \~
typedef NS_ENUM(NSUInteger, SKWCameraModeEnum)
{
    //! \~japanese
    //! \~english Camera Switchable
    //! \~
    SKW_CAMERA_MODE_SWITCHABLE = 0,
    //! \~japanese
    //! \~english Width/Height Adjustable
    //! \~
    SKW_CAMERA_MODE_ADJUSTABLE = 1,
} SKYWAY_API_DEPRECATED;

//! \~japanese SKWNavigator の getUserMedia 実行時のオプション設定クラスです。
//! \~english Media constraints class
//! \~
@interface SKWMediaConstraints : NSObject < NSCopying >

//! \~japanese 映像使用を設定します。デフォルトは \c YES になります。
//! `videoFlag` | 状態
//! ----------- | ----
//! \c YES      | 映像を有効
//! \c NO       | 映像を無効
//! \~english Using video track. Default value is YES.
//! \~
@property (nonatomic) BOOL videoFlag;

//! \~japanese 音声使用を設定します。デフォルトは \c YES になります。
//! `audioFlag` | 状態
//! ----------- | ----
//! \c YES      | 音声を有効
//! \c NO       | 音声を無効
//! \~english Using audio track. Default value is YES.
//! \~
@property (nonatomic) BOOL audioFlag;

//! \~japanese 使用するカメラの位置を設定します。デフォルトは SKW_CAMERA_POSITION_FRONT になります。
//! \~english Using camera position. Default value is SKW_CAMERA_POSITION_FRONT.
//! \~
@property (nonatomic) SKWCameraPositionEnum cameraPosition;

//! \~japanese カメラモードを設定します。デフォルトは SKW_CAMERA_MODE_SWITCHABLE になります。
//! \~english Using camera mode. Default value is SKW_CAMERA_MODE_SWITCHABLE.
//! \~
//! @deprecated
@property (nonatomic) SKWCameraModeEnum cameraMode SKYWAY_API_DEPRECATED;

// Mandatory

//! \~japanese 横ピクセル上限を設定します。
//! \~english Maximum width pixel. 0 is Engine default. Default value is 640.
//! \~
@property (nonatomic) NSUInteger maxWidth;

//! \~japanese 横ピクセル下限を設定します。
//! \~english Minimum width pixel. 0 is Engine default. Default value is 192.
//! \~
@property (nonatomic) NSUInteger minWidth;

//! \~japanese 縦ピクセル上限を設定します。
//! \~english Maximum height pixel. 0 is Engine default. Default value is 640.
//! \~
@property (nonatomic) NSUInteger maxHeight;

//! \~japanese 縦ピクセルの下限を設定します。
//! \~english Minimum height pixel. 0 is Engine default. Default value is 144.
//! \~
@property (nonatomic) NSUInteger minHeight;

//! \~japanese フレームレート上限を設定します。2 〜 30 を指定することができます。デフォルトは 10 となります。
//! \~english Maximum frame rate. 0 is Engine default. Default value is 10.
//! \~
@property (nonatomic) NSUInteger maxFrameRate;

//! \~japanese フレームレートの下限を設定します。2 〜 30 を指定することができます。デフォルトは 2 となります。
//! \~english Minimum frame rate. 0 is Engine default. Default value is 2.
//! \~
@property (nonatomic) NSUInteger minFrameRate;

// Optional

@end
