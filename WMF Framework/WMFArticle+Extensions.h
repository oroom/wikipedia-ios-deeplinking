#import "WMFArticle+CoreDataClass.h"

typedef NS_ENUM(NSUInteger, WMFGeoType) {
    WMFGeoTypeUnknown = 0,
    WMFGeoTypeCountry,
    WMFGeoTypeSatellite,
    WMFGeoTypeAdm1st,
    WMFGeoTypeAdm2nd,
    WMFGeoTypeAdm3rd,
    WMFGeoTypeCity,
    WMFGeoTypeAirport,
    WMFGeoTypeMountain,
    WMFGeoTypeIsle,
    WMFGeoTypeWaterBody,
    WMFGeoTypeForest,
    WMFGeoTypeRiver,
    WMFGeoTypeGlacier,
    WMFGeoTypeEvent,
    WMFGeoTypeEdu,
    WMFGeoTypePass,
    WMFGeoTypeRailwayStation,
    WMFGeoTypeLandmark
};

typedef NS_ENUM(NSUInteger, WMFArticleAction) {
    WMFArticleActionNone = 0,
    WMFArticleActionRead,
    WMFArticleActionSave,
    WMFArticleActionShare,
};

@interface WMFArticle (WMFExtensions)

@property (nonatomic, readonly, nullable) NSURL *URL;

@property (nonatomic, nullable) NSURL *thumbnailURL; // Deprecated. Use thumbnailURLForWidth:

- (nullable NSURL *)thumbnailURLForWidth:(NSInteger)width;

@property (nonatomic, readonly, nullable) NSArray<NSNumber *> *pageViewsSortedByDate;

@property (nonatomic, readonly) WMFGeoType geoType;

@property (nonatomic, readonly) int64_t geoDimension;

- (void)updateViewedDateWithoutTime; // call after setting viewedDate

- (void)updateWithSearchResult:(nullable MWKSearchResult *)searchResult;

- (void)updateWithMWKArticle:(nullable MWKArticle *)article;

@end

@interface NSManagedObjectContext (WMFArticle)

- (nullable WMFArticle *)fetchArticleWithURL:(nullable NSURL *)articleURL;

- (nullable WMFArticle *)fetchArticleWithKey:(nullable NSString *)key;

- (nullable WMFArticle *)fetchOrCreateArticleWithKey:(nullable NSString *)key;

- (nullable WMFArticle *)fetchOrCreateArticleWithURL:(nullable NSURL *)articleURL;

- (nullable WMFArticle *)fetchOrCreateArticleWithURL:(nullable NSURL *)articleURL updatedWithSearchResult:(nullable MWKSearchResult *)searchResult;

- (nullable WMFArticle *)fetchOrCreateArticleWithURL:(nullable NSURL *)articleURL updatedWithMWKArticle:(nullable MWKArticle *)article;

- (nullable WMFArticle *)fetchOrCreateArticleWithURL:(nullable NSURL *)articleURL updatedWithFeedPreview:(nullable WMFFeedArticlePreview *)feedPreview pageViews:(nullable NSDictionary<NSDate *, NSNumber *> *)pageViews;

@end
