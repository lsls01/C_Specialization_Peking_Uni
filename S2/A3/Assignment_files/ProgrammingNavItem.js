"use strict";define("bundles/ondemand/components/programming/ProgrammingNavItem",["require","exports","module","classnames","react-router","react-with-addons"],function(require,exports,module){var r=require("classnames"),i=require("react-router"),s=i.Link,e=require("react-with-addons"),t=e.createClass({displayName:"ProgrammingNavItem",propTypes:{link:e.PropTypes.string.isRequired,isActive:e.PropTypes.bool.isRequired,isRight:e.PropTypes.bool.isRequired},render:function render(){var i=r("c-peer-review-navlist-item",{active:this.props.isActive,"c-peer-review-navlist-item-right":this.props.isRight});return e.createElement("li",{className:i},e.createElement(s,{className:"nostyle",to:this.props.link.path},this.props.link.title))}});module.exports=t});