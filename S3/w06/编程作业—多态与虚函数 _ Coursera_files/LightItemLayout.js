"use strict";define("bundles/ondemand/components/item/LightItemLayout",["require","exports","module","react-with-addons","classnames","bundles/phoenix/lib/waitForStores","bundles/ondemand/components/item/ItemNavigation","bundles/content-feedback/components/ItemFeedback","bundles/ondemand/utils/useItemSideNav","bundles/ondemand/components/item/ItemMenu","bundles/programming/components/Footer","css!./__styles__/LightItemLayout"],function(require,exports,module){var e=require("react-with-addons"),o=require("classnames"),n=require("bundles/phoenix/lib/waitForStores"),s=require("bundles/ondemand/components/item/ItemNavigation"),d=require("bundles/content-feedback/components/ItemFeedback"),t=require("bundles/ondemand/utils/useItemSideNav"),a=require("bundles/ondemand/components/item/ItemMenu"),r=require("bundles/programming/components/Footer");require("css!./__styles__/LightItemLayout");var i=e.createClass({displayName:"LightItemLayout",propTypes:{itemMetadata:e.PropTypes.object.isRequired,children:e.PropTypes.node.isRequired,weekNumber:e.PropTypes.number.isRequired,showFeedback:e.PropTypes.bool,subItemId:e.PropTypes.string,itemType:e.PropTypes.string,isCard:e.PropTypes.bool,feedbackFixedAtBottom:e.PropTypes.bool,wide:e.PropTypes.bool},getDefaultProps:function getDefaultProps(){return{isCard:!0,showFeedback:!0,feedbackFixedAtBottom:!1,wide:!1}},render:function render(){var n=this.props,i=n.itemMetadata,c=n.itemType,g=n.isCard,u=n.weekNumber,l=n.showFeedback,p=n.subItemId,I=n.children,m=n.feedbackFixedAtBottom,h=n.wide,y=o("rc-LightItemLayout","theme-light",{"horizontal-box":t()}),k=o("content-container",{"card-rich-interaction":g,"flex-1":t(),"feedback-not-fixed-at-bottom":!m}),b=o("content",{wide:h});return e.createElement("div",{className:y},!t()&&e.createElement(s,{weekNumber:u,lessonName:i.get("lesson.name"),lesson:i.get("lesson"),currentItemId:i.get("id")}),t()&&e.createElement(a,{weekNumber:u,currentItemId:i.get("id"),currentLesson:i.get("lesson")}),e.createElement("div",{className:k},e.createElement("div",{className:b},I),l&&!m&&e.createElement(d,{itemId:i.get("id"),itemMetadata:i,itemType:c,subItemId:p,courseId:i.get("course.id")}),l&&m&&e.createElement(r,{itemMetadata:this.props.itemMetadata,feedbackItemType:c})))}});module.exports=n(i,["CourseScheduleStore"],function(e,t){var o=e.CourseScheduleStore,n=t.itemMetadata.get("lesson.module.id");return{weekNumber:o.getSchedule().getWeekForModuleId(n)}})});