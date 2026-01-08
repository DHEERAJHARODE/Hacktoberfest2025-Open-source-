(function($){
	"use strict";
	$.fn.userincr=function(options) {
	options=$.extend({},$.fn.userincr.defaults,options ||{});
	// ??? optins is shared between all invocations of a function?
	return this.each(function(){
	var edit=$(this);
	var oldvalue=edit.val();
	var op=OPS.add;
	var delta=1;
	edit.attr('title',(options.title) || edit.attr('title') || 'Enter "+x" or "+x%" or "*x" \nto change increment');
	edit.on('change',function(e){
	// console.log('change-handler-enter');
	var v=edit.val();
	if(0) {
	} else if( '%'==v.substr(-1) ) {
	v=parseFloat(v.substr(0,v.length-1))
	if(v>0) newdelta(OPS.mul,1+v/100,'inc');
	else newdelta(OPS.mul,1/(1+v/100),'dec');
	} else if( '-'===v.substr(0,1) && edit.data('min')>=0  ) {
	newdelta(OPS.add,-parseFloat(v),'dec');
	} else if( '+'==v.substr(0,1) ) {
	v=parseFloat(v.substr(1));
	if( v<0 ) newdelta(OPS.add,-v,'dec');
	else newdelta(OPS.add,v,'inc');
	} else if( '*'==v.substr(0,1) ) {
	v=parseFloat(v.substr(1));
	if( v>1 ) newdelta(OPS.mul, v,'inc');
	else      newdelta(OPS.mul, 1/v,'dec');
	} else if( '/'==v.substr(0,1) ) {
	v=parseFloat(v.substr(1));
	if(v>1) newdelta(OPS.mul,v,'dec');
	else    newdelta(OPS.mul,1/v,'inc');
	} else {
	btn[1].focus();
	}
	limit_val();
	oldvalue=edit.val();
	// console.log('change-handler-exit');
	});
	var limit_val=function(){
	var t=edit.data('min')
	if( parseFloat(edit.val())<t ) edit.val(t);
	t=edit.data('max')
	if( parseFloat(edit.val())>t ) edit.val(t);
	}
	var newdelta=function(newop,newdelta,spinop){
	op=newop;
	delta=newdelta;
	update_tooltip();
	spin(spinop);
	}
	var spin=function(spinop) {
	edit.val(op[spinop](parseFloat(oldvalue),delta));
	limit_val();
	btn[spinop==='dec'?0:1].focus();
	oldvalue=edit.val();
	// console.log('trigger-spin');
	edit.trigger('spin');
	};

	var btn=$.map(['dec','inc'],function(id){
	return $("<input>",{type:"button",value:options.buttonlabels[id],"class":'userincr-btn-'+id})
	.on('click',function(){spin(id)});
	});
	var update_tooltip=function(){
	btn[1].attr({title:op.incfmt(delta)});
	btn[0].attr({title:op.decfmt(delta)});
	};
	update_tooltip();
	if( 1!=edit.parent().children().length ) edit.wrap('<span class="userincr-container">');
	edit.parent().append(btn);
	});
	};
	var OPS={
	add:{
	inc:function(x,delta){return x+delta},
	dec:function(x,delta){return x-delta},
	incfmt:function(delta){return "+"+delta},
	decfmt:function(delta){return "âˆ’"+delta}
	},
	mul:{
	inc:function(x,delta){return x*delta},
	dec:function(x,delta){return x/delta},
	incfmt:function(delta){return "Ã—"+delta},
	decfmt:function(delta){return "Ã·"+delta}
	}
	};
	$.fn.userincr.defaults={
	buttonlabels:{ dec:'â–¼',inc:'â–²'} //â— â–· â—€ â–¶ â–½ â–³ â–¼ â–²
	};
	}(jQuery));