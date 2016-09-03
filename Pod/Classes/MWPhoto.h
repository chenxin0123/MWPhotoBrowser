//!
//  MWPhoto.h
//  MWPhotoBrowser
//
//  Created by Michael Waterfall on 17/10/2010.
//  Copyright 2010 d3i. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Photos/Photos.h>
#import "MWPhotoProtocol.h"

// This class models a photo/image and it's caption
// If you want to handle photos, caching, decompression
// yourself then you can simply ensure your custom data model
// conforms to MWPhotoProtocol


/**
 *    图片或者视频 视频可以是本地视频 也可以是远程视频
 */
@interface MWPhoto : NSObject <MWPhoto>

@property (nonatomic, strong) NSString *caption;///<图片标题
@property (nonatomic, strong) NSURL *videoURL;
@property (nonatomic) BOOL emptyImage;///<无图片 直接init时或者是Video时为空
@property (nonatomic) BOOL isVideo;

+ (MWPhoto *)photoWithImage:(UIImage *)image;
+ (MWPhoto *)photoWithURL:(NSURL *)url;
+ (MWPhoto *)photoWithAsset:(PHAsset *)asset targetSize:(CGSize)targetSize;
+ (MWPhoto *)videoWithURL:(NSURL *)url; // Initialise video with no poster image

- (id)init;
- (id)initWithImage:(UIImage *)image;
- (id)initWithURL:(NSURL *)url;
- (id)initWithAsset:(PHAsset *)asset targetSize:(CGSize)targetSize;
- (id)initWithVideoURL:(NSURL *)url;

@end

