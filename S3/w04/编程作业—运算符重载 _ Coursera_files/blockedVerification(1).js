"use strict";define("bundles/verification/views/blockedVerification",["require","exports","module","bundles/phoenix/lib/view","bundles/verification/views/blockedVerification.html","css!bundles/verification/styl/index.css"],function(require,exports,module){var i=require("bundles/phoenix/lib/view"),e=require("bundles/verification/views/blockedVerification.html");require("css!bundles/verification/styl/index.css");var t=i.extend({template:e,stateModelProperty:"model",events:{'click [data-js~="skip-verification-confirm"]':"onSkipVerificationConfirm",'click [data-js~="turn-verification-on"]':"turnVerificationOn"},multitracker:{namespace:"verification.verification_blocked",baseValues:["course_id","module_id","lesson_id","item_id","state"],definitions:{course_id:function course_id(){return this.verificationViewModel.metadata.get("course.id")},module_id:function module_id(){return this.verificationViewModel.metadata.get("lesson.module.id")},lesson_id:function lesson_id(){return this.verificationViewModel.metadata.get("lesson.id")},item_id:function item_id(){return this.verificationViewModel.metadata.get("id")},state:function state(){return this.state()}},eventingVersion:2},initialize:function initialize(i){this.model=i.blockedVerificationViewModel,this.verificationViewModel=i.verificationViewModel,this.listenTo(this.model,"change:state",this.renderState),this.listenTo(this.model,"destroy",this.destroy)},postRender:function postRender(){this.track("render")},destroy:function destroy(){this.region.close()},turnVerificationOn:function turnVerificationOn(){this.verificationViewModel.get("verificationDisplay").get("verificationPreferences").optIn(),this.verificationViewModel.unblockVerification(),this.track("click.turn_verification_on")},onSkipVerificationConfirm:function onSkipVerificationConfirm(){this.$$("skip-verification-confirm").prop("disabled",!0),this.track("click.cancel_verification_confirm"),this.verificationViewModel.trigger("verificationComplete",{hasVerified:!1})}});module.exports=t});