"use strict";define("bundles/ondemand/components/programming/ProgrammingDeadline",["require","exports","module","moment","react-with-addons","bundles/ondemand/appContextSingleton","bundles/ondemand/stores/CourseScheduleStore","bundles/ondemand/stores/SessionStore","bundles/ondemand/utils/penaltiesExperiment","i18n!nls/programming","pages/open-course/common/models/itemMetadata"],function(require,exports,module){var t=require("moment"),e=require("react-with-addons"),s=require("bundles/ondemand/appContextSingleton"),a=require("bundles/ondemand/stores/CourseScheduleStore"),o=require("bundles/ondemand/stores/SessionStore"),l=require("bundles/ondemand/utils/penaltiesExperiment"),n=require("i18n!nls/programming"),r=require("pages/open-course/common/models/itemMetadata"),d=e.createClass({displayName:"ProgrammingDeadline",propTypes:{itemMetadata:e.PropTypes.instanceOf(r).isRequired},render:function render(){if(o.isEnrolled()){var r=null,u=this.props.itemMetadata.get("lesson.module.id"),c=s.getComponentContext().getStore("CourseScheduleStore"),d=c.getDeadlineForModuleId(u),i=a.getFormattedDeadline(d);if(t().isAfter(d)){var m=null;m=n(l()?"You can still pass this assignment before the course ends, but a 20% penalty will be applied.":"You can still pass this assignment before the course ends."),r=e.createElement("td",null,e.createElement("div",null,n("The assignment was due on")," ",i),e.createElement("div",{className:"caption-text color-text-secondary"},m))}else r=e.createElement("td",null,e.createElement("div",null,n("Pass this assignment by")," ",i));return e.createElement("table",{className:"c-deadline-information"},e.createElement("tr",null,e.createElement("td",null,e.createElement("strong",null,n("Deadline"))),r))}return null}});module.exports=d});