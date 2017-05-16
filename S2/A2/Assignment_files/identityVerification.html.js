!function(e){var t=function(e,t,i){var a=function template(c){var s=[],n={},a,i=c||{};return function(t,c,i,n){s.push('<div class="c-verification"><div data-state="keystroke-ready keystroke-wrong-phrase keystroke-authenticate-error" class="c-keystroke"><div class="c-verification-header c-font-header">'+e.escape(null==(a=t("Verify Your Identity to Start"))?"":a)+'</div><form><div data-state="keystroke-ready keystroke-wrong-phrase" class="c-verification-info-text">'+e.escape(null==(a=t("Type the phrase below. Don't worry, small typos are okay."))?"":a)+'</div><div data-js="error-messages keystrokes-match-error" style="display:none;" class="c-verification-info-text c-auth-fail c-bold">'+e.escape(null==(a=t("Sorry! We compared your typing samples but couldn't detect your unique typing pattern. Please try again."))?"":a)+'</div><div data-state="keystroke-authenticate-error" class="c-keystroke-authenticate-error"><div class="c-verification-info-text c-auth-fail c-bold"> '+e.escape(null==(a=t("Sorry! We're experiencing some technical issues."))?"":a)+"\n "+e.escape(null==(a=t("Please wait a few minutes and try submitting again."))?"":a)+'</div><div class="c-verification-info-text">'+(null==(a=t("Need help?&nbsp;"))?"":a)+'<a href="https://learner.coursera.help/hc/requests/new" target="_blank" data-js="error-contact-support">'+e.escape(null==(a=t("Contact Support"))?"":a)+'</a>.</div></div><div class="c-keystroke-auth-phrase-container"><div translate="no" class="c-keystroke-auth-phrase unselectable notranslate">'+e.escape(null==(a=t(c))?"":a)+'</div></div><textarea id="keystroke-auth-textarea" data-js="keystroke-auth-input" spellcheck="false" class="c-keystroke-auth-textarea"></textarea><div class="progress c-keystroke-auth-progress"><div data-js="keystroke-auth-bar" style="width: 0%;" class="bar c-keystroke-auth-bar"></div></div><div data-state="keystroke-wrong-phrase" class="c-verification-info-text c-auth-fail">'+e.escape(null==(a=t("Looks like you might be typing the wrong phrase. Please give it another try."))?"":a)+'</div><button type="button" data-js="submit-keystrokes" disabled="disabled" class="c-verification-button bt3-btn bt3-btn-success c-btn-wide">'+e.escape(null==(a=t("Match patterns"))?"":a)+'</button><div data-state="keystroke-authenticate-error"><button data-js="cancel-verification-confirm" class="c-verification-button bt3-btn bt3-btn-warning c-btn-wide">'+e.escape(null==(a=t("Continue without Verification"))?"":a)+'</button></div></form></div><div data-state="keystroke-submitting" class="c-keystroke"><div class="c-verification-header c-font-header">'+e.escape(null==(a=t("Verify Your Identity to Start"))?"":a)+'</div><div class="c-verification-info-text">'+e.escape(null==(a=t("Matching typing patterns..."))?"":a)+"</div><div><img"+e.attr("src",i.url.assets+"images/icons/loading.gif",!0,!1)+'/></div></div><div data-state="transitioning-to-webcam" class="c-keystroke"><div class="c-verification-header c-font-header">'+e.escape(null==(a=t("Verify Your Identity to Start"))?"":a)+'</div><div class="c-verification-info-text">'+e.escape(null==(a=t("Taking you to next step..."))?"":a)+'</div></div><div data-state="webcam-ready webcam-took-photo webcam-not-authenticated webcam-authenticate-error" class="c-webcam"><div class="c-verification-header c-font-header">'+e.escape(null==(a=t("Verify Your Identity to Start"))?"":a)+'</div><div data-state="webcam-ready" class="c-webcam-help-area"><div class="c-verification-info-text">'+e.escape(null==(a=t("Now take a picture of yourself with your webcam."))?"":a)+"\n"+e.escape(null==(a=t("This picture will be used for verification purposes only"))?"":a)+"\n"+e.escape(null==(a=t("and will not be posted publicly."))?"":a)+'</div><div data-js="html5-webcam-allow-text" style="display:none;" class="c-auth-fail c-bold"><span data-js="moz-webcam-help-text">'+e.escape(null==(a=t('To turn on your webcam, click "Share Selected Device" at the top left of your screen.'))?"":a)+'</span><span data-js="chrome-webcam-help-text">'+e.escape(null==(a=t('To turn on your webcam, click "Allow" at the top right of your screen.'))?"":a)+'</span></div><div data-js="flash-webcam-allow-text" style="display:none;" class="c-auth-fail c-bold">'+e.escape(null==(a=t('To turn on your webcam, click "Allow" and then click "Close".'))?"":a)+'</div><div data-js="expand-webcam-help" class="c-action-text">'+e.escape(null==(a=t("Camera not working?"))?"":a)+'</div><div data-js="webcam-help-instructions-html5" style="display:none;"><div class="c-verification-info-text">'+e.escape(null==(a=t("Please make sure your webcam is on and connected to your computer."))?"":a)+'</div><div class="c-verification-info-text">'+e.escape(null==(a=t("Make sure your browser is up-to-date."))?"":a)+'</div><div class="c-verification-info-text">'+(null==(a=t("Or, try&nbsp;"))?"":a)+'<span data-js="switch-webcam-driver" class="c-action-text">'+e.escape(null==(a=t("switching to Flash"))?"":a)+'</span>.</div><div class="c-verification-info-text">'+(null==(a=t("Still need help? Check our&nbsp;"))?"":a)+'<a href="https://learner.coursera.help/hc/articles/201532015" target="_blank" data-js="help-center">'+e.escape(null==(a=t("Help Center"))?"":a)+'</a>.</div></div><div data-js="webcam-help-instructions-flash" style="display:none;"><div class="c-verification-info-text">'+e.escape(null==(a=t("Please make sure the correct camera is selected: right click the screen below >"))?"":a)+"\n"+e.escape(null==(a=t('choose "Settings" > click the webcam icon > choose a camera.'))?"":a)+'</div><div class="c-verification-info-text">'+(null==(a=t("Make sure you have the latest version of&nbsp;"))?"":a)+'<a href="http://get.adobe.com/flashplayer" target="_blank">'+e.escape(null==(a=t("Adobe Flash Player"))?"":a)+'</a>.</div><div data-js="switch-to-html5-webcam-link" style="display:none;" class="c-verification-info-text">'+(null==(a=t("Try&nbsp;"))?"":a)+'<span data-js="switch-webcam-driver" class="c-action-text">'+e.escape(null==(a=t("switching to HTML5"))?"":a)+'</span>.</div><div class="c-verification-info-text">'+(null==(a=t("Or, try a different browser &mdash; we recommend Chrome."))?"":a)+'</div><div class="c-verification-info-text">'+(null==(a=t("Still need help? Check our&nbsp;"))?"":a)+'<a href="https://learner.coursera.help/hc/articles/201532015" target="_blank" data-js="help-center">'+e.escape(null==(a=t("Help Center"))?"":a)+'</a>.</div></div></div><div data-js="error-messages webcam-submit-error" style="display:none;" class="c-verification-info-text c-auth-fail c-bold">'+e.escape(null==(a=t("We couldn’t detect your face. Please make sure your full face is visible and try again."))?"":a)+'</div><div data-js="error-messages webcam-error" style="display:none;" class="c-verification-info-text c-auth-fail c-bold"></div><div data-state="webcam-not-authenticated" class="c-webcam-manual-review"><div class="c-verification-info-text">'+e.escape(null==(a=t("Sorry, we couldn't automatically recognize your photo, so it will be reviewed manually."))?"":a)+"\n"+e.escape(null==(a=t("Please check the course outline page in a few days to see if this assignment has been verified."))?"":a)+'</div><div class="c-verification-info-text">'+(null==(a=t("Need help?&nbsp;"))?"":a)+'<a href="https://learner.coursera.help/hc/requests/new" target="_blank" data-js="manual-review-contact-support">'+e.escape(null==(a=t("Contact Support"))?"":a)+'</a>.</div></div><div data-state="webcam-authenticate-error" class="c-webcam-authenticate-error"><div class="c-verification-info-text c-auth-fail c-bold"> '+e.escape(null==(a=t("Sorry! We're experiencing some technical issues."))?"":a)+"\n "+e.escape(null==(a=t("Please wait a few minutes and try submitting again."))?"":a)+'</div><div class="c-verification-info-text">'+(null==(a=t("Need help?&nbsp;"))?"":a)+'<a href="https://learner.coursera.help/hc/requests/new" target="_blank" data-js="error-contact-support">'+e.escape(null==(a=t("Contact Support"))?"":a)+'</a>.</div></div><div data-js="webcam-container" class="c-webcam-container"><div data-js="html5-webcam-help-image-container" class="c-html5-webcam-help-image-container"><div data-js="moz-webcam-help-text" class="c-html5-webcam-help-text">'+e.escape(null==(a=t("Click the camera icon in the top left of your browser window to allow webcam access."))?"":a)+'</div><img data-js="html5-webcam-help-image" alt="Instructions on how to activate your webcam" class="c-html5-webcam-help-image"/><div data-js="chrome-webcam-help-text" class="c-html5-webcam-help-chrome-text"><div class="c-html5-webcam-help-chrome-text-deny"><strong>'+e.escape(null==(a=t("Deny"))?"":a)+'</strong></div><div class="c-html5-webcam-help-chrome-text-allow"><strong>'+e.escape(null==(a=t("Allow"))?"":a)+'</strong></div></div><div data-js="chrome-webcam-help-text" class="c-html5-webcam-help-text">'+e.escape(null==(a=t('Click "Allow in the top right of your browser window to allow webcam access."'))?"":a)+'</div></div></div><div class="c-verify-status-area"><div class="c-webcam-verify-area"><button data-js="take-photo-button" data-state="webcam-ready" disabled="disabled" class="c-verification-button bt3-btn bt3-btn-success c-btn-wide">'+e.escape(null==(a=t("Take Photo"))?"":a)+'</button><button data-js="submit-photo" data-state="webcam-took-photo webcam-authenticate-error" disabled="disabled" class="c-verification-button bt3-btn bt3-btn-success c-btn-wide">'+e.escape(null==(a=t("Use Photo"))?"":a)+'</button><div data-js="retake-photo" data-state="webcam-took-photo" class="c-action-text">'+e.escape(null==(a=t("Retake photo"))?"":a)+'</div><button data-js="complete-verification" data-state="webcam-not-authenticated" class="c-verification-button bt3-btn bt3-btn-warning c-btn-wide">'+e.escape(null==(a=t("Got It, Continue"))?"":a)+'</button><div data-state="webcam-authenticate-error"><button data-js="cancel-verification-confirm" class="c-verification-button bt3-btn bt3-btn-warning c-btn-wide">'+e.escape(null==(a=t("Continue without Verification"))?"":a)+'</button></div></div></div></div><div data-state="webcam-submitting" class="c-webcam"><div class="c-verification-header c-font-header">'+e.escape(null==(a=t("Verify Your Identity to Start"))?"":a)+'</div><div class="c-verification-info-text">'+e.escape(null==(a=t("Submitting photo..."))?"":a)+"</div><div><img"+e.attr("src",i.url.assets+"images/icons/loading.gif",!0,!1)+'/></div></div><div data-state="keystroke-authenticated webcam-authenticated" class="c-setup-complete"><div class="c-verification-header c-font-header">'+e.escape(null==(a=t("Identity Verified"))?"":a)+'</div><div class="c-verification-info-text">'+e.escape(null==(a=t("It's a match! Thanks for verifying!"))?"":a)+'</div><button data-js="complete-verification" class="c-verification-button bt3-btn bt3-btn-success c-btn-wide">'+e.escape(null==(a=t("Continue"))?"":a)+"</button></div>"),n&&s.push('<br/><button data-js="skip-identity-verification" data-state="keystroke-ready keystroke-wrong-phrase webcam-ready webcam-took-photo" class="nostyle c-action-text">'+e.escape(null==(a=t("I don't want to verify."))?"":a)+'</button><div data-js="skip-verification-block" style="display:none;" class="c-skip-verification"><div class="c-verification-info-text">'+e.escape(null==(a=t("This course is offered with the option to earn a Course Certificate. If you skip verification now"))?"":a)+"\n"+(null==(a=t("but decide you want a certificate later, <b>you'll have to take the assignment again</b>, with verification."))?"":a)+'</div><div class="c-verification-info-text">'+(null==(a=t("Unable to verify? Learn about&nbsp;"))?"":a)+'<a href="https://learner.coursera.help/hc/articles/201212579" target="_blank" data-js="verification-info-link">'+e.escape(null==(a=t("Verification Settings"))?"":a)+'</a>.</div><button data-js="cancel-verification-confirm" class="c-verification-button bt3-btn bt3-btn-success c-btn-wide">'+e.escape(null==(a=t("Continue without Verification"))?"":a)+"</button></div>"),s.push('<div data-state="verifiable-id-error" class="c-verifiable-id-error"><div class="c-verification-header c-font-header">'+e.escape(null==(a=t("Verify Your Identity to Start"))?"":a)+'</div><div class="c-verification-info-text"> '+e.escape(null==(a=t("Sorry! We're experiencing some technical issues."))?"":a)+"\n "+e.escape(null==(a=t("Please wait a few minutes and try again."))?"":a)+'</div><div class="c-verification-info-text">'+(null==(a=t("Need help?&nbsp;"))?"":a)+'<a href="https://learner.coursera.help/hc/requests/new" target="_blank" data-js="error-contact-support">'+e.escape(null==(a=t("Contact Support"))?"":a)+'</a>.</div><button data-js="refetch-verifiable-id" class="c-verification-button bt3-btn bt3-btn-success c-btn-wide">'+e.escape(null==(a=t("Try Verification Again"))?"":a)+'</button><br/><button data-js="cancel-verification-confirm" class="c-verification-button bt3-btn bt3-btn-warning c-btn-wide">'+e.escape(null==(a=t("Continue without Verification"))?"":a)+"</button></div></div>")}.call(this,"_t"in i?i._t:"undefined"!=typeof t?t:void 0,"keystrokeAuthPhrase"in i?i.keystrokeAuthPhrase:"undefined"!=typeof keystrokeAuthPhrase?keystrokeAuthPhrase:void 0,"config"in i?i.config:"undefined"!=typeof config?config:void 0,"canOptOut"in i?i.canOptOut:"undefined"!=typeof canOptOut?canOptOut:void 0),s.join("")};return function(e){return e&&"_t"in e&&(t=e._t.merge(t)),a(e)}};"function"==typeof define&&define.amd?define(["js/vendor/jade","i18n!bundles/verification/views/nls/identityVerification"],function(e,a){var i;return t(e,a,i)}):e.jade.templates["bundles.verification.views.identityVerification"]=t(e.jade.helpers)}(window);