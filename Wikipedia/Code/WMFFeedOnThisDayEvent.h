@import Mantle.MTLModel;
@import Mantle.MTLJSONAdapter;

@class WMFFeedArticlePreview;

NS_ASSUME_NONNULL_BEGIN

@interface WMFFeedOnThisDayEvent : MTLModel <MTLJSONSerializing>

@property (nonatomic, copy, nullable, readonly) NSString *text;

@property (nonatomic, copy, nullable, readonly) NSNumber *year;

@property (nullable, nonatomic, copy, readonly) NSArray<WMFFeedArticlePreview *> *articlePreviews;

@property (nullable, nonatomic, readonly) NSURL *siteURL;

@property (nullable, nonatomic, readonly) NSString *language;

@property (nullable, nonatomic, copy) NSNumber *imageCount;

@property (nullable, nonatomic, copy) NSNumber *index;

@end

NS_ASSUME_NONNULL_END
