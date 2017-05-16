define("bundles/programming/components/MetaInfoArea",["require","exports","module","react-with-addons","bundles/programming/components/Status","bundles/programming/stores/submissionSummariesStore","pages/open-course/common/models/itemMetadata","pages/open-course/common/models/courseProgress","pages/open-course/common/models/itemGrade"],function(require,exports,module){"use strict";function _defaults(e,s){for(var n=Object.getOwnPropertyNames(s),t=0;t<n.length;t++){var r=n[t],o=Object.getOwnPropertyDescriptor(s,r);o&&o.configurable&&void 0===e[r]&&Object.defineProperty(e,r,o)}return e}function _classCallCheck(e,t){if(!(e instanceof t))throw new TypeError("Cannot call a class as a function")}function _inherits(t,e){if("function"!=typeof e&&null!==e)throw new TypeError("Super expression must either be null or a function, not "+typeof e);t.prototype=Object.create(e&&e.prototype,{constructor:{value:t,enumerable:!1,writable:!0,configurable:!0}}),e&&(Object.setPrototypeOf?Object.setPrototypeOf(t,e):_defaults(t,e))}var r=function(){function defineProperties(o,r){for(var t=0;t<r.length;t++){var e=r[t];e.enumerable=e.enumerable||!1,e.configurable=!0,"value"in e&&(e.writable=!0),Object.defineProperty(o,e.key,e)}}return function(e,t,r){return t&&defineProperties(e.prototype,t),r&&defineProperties(e,r),e}}(),s=function get(n,u,m){var r=!0;e:for(;r;){var t=n,i=u,a=m;r=!1,null===t&&(t=Function.prototype);var e=Object.getOwnPropertyDescriptor(t,i);if(void 0===e){var o=Object.getPrototypeOf(t);if(null===o)return void 0;n=o,u=i,m=a,r=!0,e=o=void 0;continue e}if("value"in e)return e.value;var s=e.get;if(void 0===s)return void 0;return s.call(a)}},e=require("react-with-addons"),o=require("bundles/programming/components/Status"),t=require("bundles/programming/stores/submissionSummariesStore"),n=require("pages/open-course/common/models/itemMetadata"),i=require("pages/open-course/common/models/courseProgress"),a=require("pages/open-course/common/models/itemGrade"),u=function(u){function MetaInfoArea(t,r){var e=this;_classCallCheck(this,MetaInfoArea),s(Object.getPrototypeOf(MetaInfoArea.prototype),"constructor",this).call(this,t,r),this.onProgressChange=function(){e.setState(e.getState())},this.onSubmissionSummariesUpdate=function(t){e.setState(e.getState())},this.state=this.getState()}return _inherits(MetaInfoArea,u),r(MetaInfoArea,null,[{key:"propTypes",value:{itemMetadata:e.PropTypes.instanceOf(n).isRequired,courseProgress:e.PropTypes.instanceOf(i).isRequired,itemGrade:e.PropTypes.instanceOf(a).isRequired,verificationDisplay:e.PropTypes.object.isRequired,learnerAssignment:e.PropTypes.object.isRequired},enumerable:!0}]),r(MetaInfoArea,[{key:"componentDidMount",value:function componentDidMount(){var e=this.props.courseProgress;e&&e.on("refreshed",this.onProgressChange),t.on("update",this.onSubmissionSummariesUpdate)}},{key:"componentWillUnmount",value:function componentWillUnmount(){var e=this.props.courseProgress;e&&e.off("refreshed",this.onProgressChange),t.removeListener("update",this.onSubmissionSummariesUpdate)}},{key:"getState",value:function getState(){var e=this.props,o=e.itemMetadata,r=e.courseProgress,s=e.itemGrade,n=o.get("id");return{itemGrade:s,itemProgress:r&&r.getItemProgress(n),submissionSummaries:t.submissionSummaries}}},{key:"render",value:function render(){var t=this.state,r=t.itemProgress,s=t.itemGrade,n=t.submissionSummaries;return r&&s?e.createElement(o,{itemMetadata:this.props.itemMetadata,learnerAssignment:this.props.learnerAssignment,itemProgress:r,itemGrade:s,submissionSummaries:n,verificationDisplay:this.props.verificationDisplay}):null}}]),MetaInfoArea}(e.Component);module.exports=u});