"use strict";define("bundles/programming/stores/submissionSummariesStore",["require","exports","module","underscore","js/vendor/EventEmitter","bundles/programming/promises/submissionSummaries"],function(require,exports,module){function onLoadSuccess(r){e.submissionSummaries=r,e.emit("update",r)}function onLoadError(r){e.error=r,e.emit("updateError",r)}function SubmissionSummariesStore(){this.submissionSummaries=null}var _=require("underscore"),r=require("js/vendor/EventEmitter"),s=require("bundles/programming/promises/submissionSummaries");SubmissionSummariesStore.prototype=_.extend({},r.prototype,{load:function load(e){s(e).then(onLoadSuccess,onLoadError).done()}});var e=new SubmissionSummariesStore;module.exports=e});