//
//  DCMMainController.h
//  Common Messaging
//
//  Created by Donky Networks on 07/04/2015.
//  Copyright (c) 2015 Dynmark International Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DNServerNotification.h"
#import "DNMessage.h"
#import "DNBlockDefinitions.h"

@interface DCMMainController : NSObject

/*!
 Helper method to record the message as delivered on the network, this will go towards analytics.
 
 @param notification the notification that was received.
 
 @since 2.0.0.0
 */
+ (void)markMessageAsReceived:(DNServerNotification *)notification;

/*!
 Class method to mark more than one conversation as received at the same time.
 
 @param notifications the notifications that should be marked as received.
 
 @since 2.6.5.4
 */
+ (void)markAllMessagesAsReceived:(NSArray *)notifications;

/*!
 Helper method to mark a message as read.
 
 @param notification the notification for the message.
 
 @since 2.0.0.0
 */
+ (void)markMessageAsRead:(DNMessage *)message;

/*!
 Class method to mark more than one conversation as read at the same time.
 
 @param messages the messages that should be marked as read.
 
 @since 2.6.5.4
 */
+ (void)markAllMessagesAsRead:(NSArray *)messages;

/*!
 Class method to mark more than one conversation as read at the same time with a completion call back
 as this is performed on a background thread.

 @param messages the messages that should be marked as read.
 @param completion the completion block called when completed.

 @since 2.7.1.6
 */
+ (void)markAllMessagesAsRead:(NSArray *)messages completion:(DNCompletionBlock)completion;

/*!
 Helper method to report the fact that a rich message has been shared via the share sheet.
 
 @param message     the message that was shared.
 @param sharedUsing the name of the service used to share the message i.e. twitter
 
 @since 2.2.2.7
 */
+ (void)reportSharingOfRichMessage:(DNMessage *)message sharedUsing:(NSString *)sharedUsing;

/*!
 Helper method to report that a message(s) has been deleted.
 
 @param messages the messages that should be marked as deleted.
 
 @since 2.7.1.3
 */
+ (void)reportMessagesDeleted:(NSArray *)messages;

@end
