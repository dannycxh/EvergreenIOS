Evergreen iOS SDK
================

Thanks for choosing Evergreen!

This package supports iOS 7+, but will degrade gracefully in older versions.

#### Other links

- [Sign up for an account](https://merchant.trialpay.com/register/?t=mb)
- [Evergreen SDK API Reference](http://help.trialpay.com/docs3/iOS/index.html)

### Changelog

#### Version 3.2 (2015500)

Maintenance build

Bugfixes and improvements for offer rotation and offer browsing
Improved responsiveness for availability

#### Version 3.2 (2015461)

The changes allow for an easier handling of event statuses. 

* Offer Browsing - Developers can now choose when offers are rotated on single-offer flows. Offer browsing has to be enabled on the dashboard.
* Moved away from polling of offer availability (isAvailable) to notifications of event status change. Enables a more efficient reaction for time-sensitive UI and generating better UX.
* Reduce memory by reusing events. The same event created multiple times will result in the same object now.

#### Version 3.1 (2015311)

Multiple fixes.

#### Version 3.1 (2015141)

iOS memory management improvements

#### Version 3.1 (2015110)

iOS App Trailers now available on portrait apps.

#### Version 3.0 (2015108)

Initial version of Evergreen iOS SDK, enjoy!

*Note*: You may not implement TrialPay's services or technology on applications that are directed at, or collect data from, children under the age of 13.

*Note*: You are required to display [TrialPay's Privacy Policy](http://www.trialpay.com/legal/privacy-policy/) and [Terms of Use](http://www.trialpay.com/legal/terms/) to all users with any TrialPay offers displayed on your site or app.

