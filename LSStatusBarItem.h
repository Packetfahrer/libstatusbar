enum StatusBarAlignment
{
	StatusBarAlignmentLeft = 1,
	StatusBarAlignmentRight = 2,
	StatusBarAlignmentCenter = 4
};


@interface LSStatusBarItem : NSObject
{
	NSString* _identifier;
	NSMutableDictionary* _properties;
	NSMutableSet* _delegates;
	BOOL _manualUpdate;
}

+ (void) updateItems;

- (void) dealloc;
- (void) setProperties: (NSDictionary*) dict;

@end


@interface LSStatusBarItem (API)

- (id) initWithIdentifier: (NSString*) identifier alignment: (StatusBarAlignment) alignment;

// bitmasks (e.g. left or right) are not supported yet
@property (nonatomic, readonly) StatusBarAlignment alignment;

@property (nonatomic, getter=isVisible) BOOL visible;

// useful only with left/right alignment - will throw error for center alignment
@property (nonatomic, assign) NSString* imageName;

// useful only with center alignment - will throw error otherwise
// will not be visible on the lockscreen
@property (nonatomic, assign) NSString* titleString;

// set to NO and manually call update if you need to make multiple changes
@property (nonatomic, getter=isManualUpdate) BOOL manualUpdate;

// manually call if manualUpdate = YES
- (void) update;

@end




@interface LSStatusBarItem (Unimplemented)


// leave alone unless you want to limit which apps your icon shows up in
@property (nonatomic, assign) NSString* exclusiveToApp;

// convenience methods?
//@property (nonatomic, getter=isSpringBoardOnly) BOOL springBoardOnly;
//@property (getter=isCurrentAppOnly) BOOL currentAppOnly;

// delegate must respond to @selector(statusBarAction:); only valid from inside of SpringBoard
- (void) addTouchDelegate: (id) delegate;
- (void) removeTouchDelegate: (id) delegate;


@end