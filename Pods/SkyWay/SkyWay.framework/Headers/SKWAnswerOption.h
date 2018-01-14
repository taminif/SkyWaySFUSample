////////////////////////////////////////////////////////////////////////
//  SKWAnswerOption.h
//  SkyWay SDK
////////////////////////////////////////////////////////////////////////
#import <Foundation/Foundation.h>

/**
 * \file SKWAnswerOption.h
 */

//! \~japanese SKWMediaConnection answer オプション
//! \~english SKWMediaConnection answer Option
//! \~
@interface SKWAnswerOption : NSObject < NSCopying >

//! \~japanese 映像の最大バンド幅を kbps で指定します。
//! \~english A max video bandwidth(kbps)
//! \~
@property (nonatomic) NSUInteger videoBandwidth;

//! \~japanese 音声の最大バンド幅を kbps で指定します。
//! \~english A max audio bandwidth(kbps)
//! \~
@property (nonatomic) NSUInteger audioBandwidth;

//! \~japanese 映像コーデックを明示的に指定します。 (例:H264)
//! \~english A video codec like 'H264'
//! \~
@property (nonatomic) NSString* __nullable videoCodec;

//! \~japanese 音声コーデックを明示的に指定します。 (例:PCMU)
//! \~english A audio codec like 'PCMU'
//! \~
@property (nonatomic) NSString* __nullable audioCodec;

@end
