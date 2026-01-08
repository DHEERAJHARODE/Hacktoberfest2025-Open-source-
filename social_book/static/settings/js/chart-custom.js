! function(e) {
	"use strict";

	function t(t) {
		t ? e(".right-sidebar-mini").addClass("right-sidebar") : e(".right-sidebar-mini").removeClass("right-sidebar")
		t ? e("body").addClass("right-sidebar-close") : e("body").removeClass("right-sidebar-close")
	}
	e(document).ready(function() {
		var a = !1;
		t(a), e(document).on("click", ".right-sidebar-toggle", function() {
			t(a = !a)
		})
	})
}(jQuery);
var options = {
	chart: {
		height: 80,
		type: "area",
		sparkline: {
			enabled: !0
		},
		group: "sparklines"
	},
	dataLabels: {
		enabled: !1
	},
	stroke: {
		width: 3,
		curve: "smooth"
	},
	fill: {
		type: "gradient",
		gradient: {
			shadeIntensity: 1,
			opacityFrom: .5,
			opacityTo: 0
		}
	},
	series: [{
		name: "series1",
		data: [60, 15, 50, 30, 70]
	}],
	colors: ["#827af3"],
	xaxis: {
		type: "datetime",
		categories: ["2018-08-19T00:00:00", "2018-09-19T01:30:00", "2018-10-19T02:30:00", "2018-11-19T01:30:00", "2018-12-19T01:30:00"]
	},
	tooltip: {
		x: {
			format: "dd/MM/yy HH:mm"
		}
	}
};
jQuery("#chart-1").length && (chart = new ApexCharts(document.querySelector("#chart-1"), options)).render();
options = {
	chart: {
		height: 80,
		type: "area",
		sparkline: {
			enabled: !0
		},
		group: "sparklines"
	},
	dataLabels: {
		enabled: !1
	},
	stroke: {
		width: 3,
		curve: "smooth"
	},
	fill: {
		type: "gradient",
		gradient: {
			shadeIntensity: 1,
			opacityFrom: .5,
			opacityTo: 0
		}
	},
	series: [{
		name: "series1",
		data: [70, 40, 60, 30, 60]
	}],
	colors: ["#b47af3"],
	xaxis: {
		type: "datetime",
		categories: ["2018-08-19T00:00:00", "2018-09-19T01:30:00", "2018-10-19T02:30:00", "2018-11-19T01:30:00", "2018-12-19T01:30:00"]
	},
	tooltip: {
		x: {
			format: "dd/MM/yy HH:mm"
		}
	}
};
jQuery("#chart-2").length && (chart = new ApexCharts(document.querySelector("#chart-2"), options)).render();
options = {
	chart: {
		height: 80,
		type: "area",
		sparkline: {
			enabled: !0
		},
		group: "sparklines"
	},
	dataLabels: {
		enabled: !1
	},
	stroke: {
		width: 3,
		curve: "smooth"
	},
	fill: {
		type: "gradient",
		gradient: {
			shadeIntensity: 1,
			opacityFrom: .5,
			opacityTo: 0
		}
	},
	series: [{
		name: "series1",
		data: [60, 40, 60, 40, 70]
	}],
	colors: ["#fbc647"],
	xaxis: {
		type: "datetime",
		categories: ["2018-08-19T00:00:00", "2018-09-19T01:30:00", "2018-10-19T02:30:00", "2018-11-19T01:30:00", "2018-12-19T01:30:00"]
	},
	tooltip: {
		x: {
			format: "dd/MM/yy HH:mm"
		}
	}
};
jQuery("#chart-3").length && (chart = new ApexCharts(document.querySelector("#chart-3"), options)).render();
options = {
	chart: {
		height: 80,
		type: "area",
		sparkline: {
			enabled: !0
		},
		group: "sparklines"
	},
	dataLabels: {
		enabled: !1
	},
	stroke: {
		width: 3,
		curve: "smooth"
	},
	fill: {
		type: "gradient",
		gradient: {
			shadeIntensity: 1,
			opacityFrom: .5,
			opacityTo: 0
		}
	},
	series: [{
		name: "series1",
		data: [75, 30, 60, 35, 60]
	}],
	colors: ["#27b345"],
	xaxis: {
		type: "datetime",
		categories: ["2018-08-19T00:00:00", "2018-09-19T01:30:00", "2018-10-19T02:30:00", "2018-11-19T01:30:00", "2018-12-19T01:30:00"]
	},
	tooltip: {
		x: {
			format: "dd/MM/yy HH:mm"
		}
	}
};
jQuery("#chart-4").length && (chart = new ApexCharts(document.querySelector("#chart-4"), options)).render();
options = {
	chart: {
		height: 200,
		type: "line",
		sparkline: {
			enabled: !0
		},
		stacked: !1
	},
	stroke: {
		width: [2, 3],
		curve: "smooth",
		dashArray: [0, 5]
	},
	plotOptions: {
		bar: {
			columnWidth: "50%"
		}
	},
	colors: ["#827af3", "#827af3"],
	series: [{
		name: "Vine",
		type: "area",
		data: [44, 55, 41, 67, 22, 43, 21, 41, 56, 27, 43]
	}, {
		name: "Dribbble",
		type: "line",
		data: [30, 25, 36, 30, 45, 35, 64, 52, 59, 36, 39]
	}],
	fill: {
		opacity: [.2, 1],
		gradient: {
			inverseColors: !1,
			shade: "light",
			type: "vertical",
			opacityFrom: 1,
			opacityTo: 1,
			stops: [0, 100, 100, 100]
		}
	},
	labels: ["01/01/2003", "02/01/2003", "03/01/2003", "04/01/2003", "05/01/2003", "06/01/2003", "07/01/2003", "08/01/2003", "09/01/2003", "10/01/2003", "11/01/2003"],
	markers: {
		size: 0
	},
	xaxis: {
		type: "datetime"
	},
	yaxis: {
		min: 0
	},
	tooltip: {
		shared: !0,
		intersect: !1,
		y: {
			formatter: function(e) {
				return void 0 !== e ? e.toFixed(0) + " views" : e
			}
		}
	},
	legend: {
		labels: {
			useSeriesColors: !0
		},
		markers: {
			customHTML: [function() {
				return ""
			}, function() {
				return ""
			}, function() {
				return ""
			}]
		}
	}
};
jQuery("#chart-5").length && (chart = new ApexCharts(document.querySelector("#chart-5"), options)).render();
options = {
	chart: {
		height: 400,
		type: "bar",
		sparkline: {
			show: !1
		},
		toolbar: {
			show: !1
		}
	},
	colors: ["#827af3", "#fbc647"],
	plotOptions: {
		bar: {
			horizontal: !1,
			columnWidth: "30%",
			endingShape: "rounded"
		}
	},
	dataLabels: {
		enabled: !1
	},
	stroke: {
		show: !1,
		width: 5,
		colors: ["#ffffff"]
	},
	series: [{
		name: "Mobile",
		enabled: "true",
		data: [44, 90, 90, 60, 115]
	}, {
		name: "Desktop",
		data: [35, 80, 100, 70, 95]
	}],
	fill: {
		opacity: 1
	},
	tooltip: {
		y: {
			formatter: function(e) {
				return "$ " + e + " thousands"
			}
		}
	}
};
jQuery("#bar-chart-6").length && (chart = new ApexCharts(document.querySelector("#bar-chart-6"), options)).render();
jQuery("#chart-6").length && (chart = new ApexCharts(document.querySelector("#chart-6"), options)).render();
var lastDate = 0,
	data = [],
	TICKINTERVAL = 864e5;
let XAXISRANGE = 7776e5;

function getDayWiseTimeSeries(e, t, a) {
	for (var n = 0; n < t;) {
		var o = e,
			r = Math.floor(Math.random() * (a.max - a.min + 1)) + a.min;
		data.push({
			x: o,
			y: r
		}), lastDate = e, e += TICKINTERVAL, n++
	}
}

function getNewSeries(e, t) {
	var a = e + TICKINTERVAL;
	lastDate = a;
	for (var n = 0; n < data.length - 10; n++) data[n].x = a - XAXISRANGE - TICKINTERVAL, data[n].y = 0;
	data.push({
		x: a,
		y: Math.floor(Math.random() * (t.max - t.min + 1)) + t.min
	})
}

function resetData() {
	data = data.slice(data.length - 10, data.length)
}
getDayWiseTimeSeries(new Date("11 Feb 2017 GMT").getTime(), 10, {
	min: 10,
	max: 90
});
options = {
	chart: {
		height: 150,
		type: "area",
		animations: {
			enabled: !0,
			easing: "linear",
			dynamicAnimation: {
				speed: 1e3
			}
		},
		toolbar: {
			show: !1
		},
		sparkline: {
			enabled: !0
		},
		group: "sparklines"
	},
	dataLabels: {
		enabled: !1
	},
	stroke: {
		curve: "straight",
		width: 3
	},
	series: [{
		data: data
	}],
	markers: {
		size: 4
	},
	xaxis: {
		type: "datetime",
		range: XAXISRANGE
	},
	yaxis: {
		max: 100
	},
	fill: {
		type: "gradient",
		gradient: {
			shadeIntensity: 1,
			inverseColors: !1,
			opacityFrom: .5,
			opacityTo: 0,
			stops: [0, 90, 100]
		}
	},
	legend: {
		show: !1
	},
	colors: ["#827af3"]
};
if (jQuery("#wave-chart-7").length) {
	options.markers.size = 0, options.chart.type = "area", options.stroke.curve = "smooth", options.chart.height = 70;
	var wave_chart_7 = new ApexCharts(document.querySelector("#wave-chart-7"), options);
	wave_chart_7.render()
}
if (jQuery("#chart-7").length) {
	var chart_7 = new ApexCharts(document.querySelector("#chart-7"), options);
	chart_7.render()
}
if (options.colors = ["#827af3"], jQuery("#wave-chart-8").length) {
	options.markers.size = 0, options.chart.height = 70, options.stroke.curve = "smooth", options.chart.type = "area";
	var wave_chart_8 = new ApexCharts(document.querySelector("#wave-chart-8"), options);
	wave_chart_8.render()
}
if (jQuery("#chart-8").length) {
	var chart_8 = new ApexCharts(document.querySelector("#chart-8"), options);
	chart_8.render()
}(jQuery("#wave-chart-7").length || jQuery("#wave-chart-8").length) && window.setInterval(function() {
	getNewSeries(lastDate, {
		min: 10,
		max: 90
	}), jQuery("#wave-chart-7").length && wave_chart_7.updateSeries([{
		data: data
	}]), jQuery("#wave-chart-8").length && wave_chart_8.updateSeries([{
		data: data
	}])
}, 1e3);
options = {
	chart: {
		height: 112,
		type: "area",
		animations: {
			enabled: !0,
			easing: "linear",
			dynamicAnimation: {
				speed: 1e3
			}
		},
		toolbar: {
			show: !1
		},
		sparkline: {
			enabled: !0
		},
		group: "sparklines"
	},
	dataLabels: {
		enabled: !1
	},
	stroke: {
		curve: "smooth",
		width: 3
	},
	fill: {
		type: "gradient",
		gradient: {
			shadeIntensity: 1,
			opacityFrom: .5,
			opacityTo: 0
		}
	},
	series: [{
		data: data
	}],
	markers: {
		size: 0
	},
	xaxis: {
		type: "datetime",
		range: XAXISRANGE
	},
	yaxis: {
		max: 100
	},
	legend: {
		show: !1
	},
	colors: ["#827af3"]
};
if (jQuery("#chart-9").length) {
	var chart9 = new ApexCharts(document.querySelector("#chart-9"), options);
	chart9.render(), window.setInterval(function() {
		getNewSeries(lastDate, {
			min: 10,
			max: 90
		}), jQuery("#chart-9").length && chart9.updateSeries([{
			data: data
		}])
	}, 1e3)
}

function generateData(e, t, a) {
	for (var n = 0, o = []; n < t;) {
		var r = Math.floor(750 * Math.random()) + 1,
			i = Math.floor(Math.random() * (a.max - a.min + 1)) + a.min,
			c = Math.floor(61 * Math.random()) + 15;
		o.push([r, i, c]), 864e5, n++
	}
	return o
}
options = {
	chart: {
		height: 440,
		type: "bubble",
		stacked: !1,
		toolbar: {
			show: !1
		},
		animations: {
			enabled: !0,
			easing: "linear",
			dynamicAnimation: {
				speed: 1e3
			}
		},
		sparkline: {
			enabled: !0
		},
		group: "sparklines"
	},
	dataLabels: {
		enabled: !1
	},
	series: [{
		name: "Bubble1",
		data: generateData(new Date("11 Feb 2017 GMT").getTime(), 10, {
			min: 10,
			max: 60
		})
	}, {
		name: "Bubble2",
		data: generateData(new Date("11 Feb 2017 GMT").getTime(), 10, {
			min: 10,
			max: 60
		})
	}, {
		name: "Bubble3",
		data: generateData(new Date("11 Feb 2017 GMT").getTime(), 10, {
			min: 10,
			max: 60
		})
	}, {
		name: "Bubble4",
		data: generateData(new Date("11 Feb 2017 GMT").getTime(), 10, {
			min: 10,
			max: 60
		})
	}],
	fill: {
		opacity: .8
	},
	title: {
		show: !1
	},
	xaxis: {
		tickAmount: 8,
		type: "category",
		labels: {
			show: !1
		}
	},
	yaxis: {
		max: 70,
		labels: {
			show: !1
		}
	},
	legend: {
		show: !1
	}
};
if (jQuery("#chart-10").length) {
	var chart_2 = new ApexCharts(document.querySelector("#chart-10"), options);
	chart_2.render()
}
var chart11 = {
	chart: {
		height: 407,
		type: "line",
		zoom: {
			enabled: !1
		},
		toolbar: {
			show: !1
		}
	},
	dataLabels: {
		enabled: !1
	},
	stroke: {
		width: [5, 7, 5],
		curve: "straight",
		dashArray: [0, 8, 5]
	},
	series: [{
		name: "Session Duration",
		data: [45, 52, 38, 24, 33, 26, 21, 20, 6, 8, 15, 10]
	}, {
		name: "Page Views",
		data: [35, 41, 62, 42, 13, 18, 29, 37, 36, 51, 32, 35]
	}, {
		name: "Total Visits",
		data: [87, 57, 74, 99, 75, 38, 62, 47, 82, 56, 45, 47]
	}],
	colors: ["#827af3", "#27b345", "#b47af3"],
	legend: {
		show: !1
	},
	markers: {
		size: 0,
		hover: {
			sizeOffset: 6
		}
	},
	xaxis: {
		categories: ["01 Jan", "02 Jan", "03 Jan", "04 Jan", "05 Jan", "06 Jan", "07 Jan", "08 Jan", "09 Jan", "10 Jan", "11 Jan", "12 Jan"]
	},
	yaxis: {
		labels: {
			show: !1
		}
	},
	tooltip: {
		y: [{
			title: {
				formatter: function(e) {
					return e + " (mins)"
				}
			}
		}, {
			title: {
				formatter: function(e) {
					return e + " per session"
				}
			}
		}, {
			title: {
				formatter: function(e) {
					return e
				}
			}
		}]
	},
	grid: {
		borderColor: "#f1f1f1"
	}
};
if (jQuery("#chart-11").length) {
	var chart_3 = new ApexCharts(document.querySelector("#chart-11"), chart11);
	chart_3.render()
}
var options12 = {
	chart: {
		height: 140,
		type: "area",
		sparkline: {
			enabled: !0
		},
		group: "sparklines"
	},
	dataLabels: {
		enabled: !1
	},
	stroke: {
		width: 5,
		curve: "smooth"
	},
	fill: {
		type: "gradient",
		gradient: {
			shadeIntensity: 1,
			opacityFrom: .5,
			opacityTo: 0
		}
	},
	series: [{
		name: "series1",
		data: [70, 40, 60, 30, 60]
	}],
	colors: ["#ffd400"],
	xaxis: {
		type: "datetime",
		categories: ["2018-08-19T00:00:00", "2018-09-19T01:30:00", "2018-10-19T02:30:00", "2018-11-19T01:30:00", "2018-12-19T01:30:00"]
	},
	tooltip: {
		x: {
			format: "dd/MM/yy HH:mm"
		}
	}
};
jQuery("#chart-12").length && (chart12 = new ApexCharts(document.querySelector("#chart-12"), options12)).render();
var chart12, barOptions12 = {
	chart: {
		height: 150,
		type: "bar",
		sparkline: {
			enabled: !0
		},
		group: "sparklines"
	},
	dataLabels: {
		enabled: !1
	},
	stroke: {
		curve: "smooth",
		width: 15
	},
	series: [{
		name: "series1",
		data: [70, 40, 60, 30, 60]
	}],
	colors: ["#6ce6f4"],
	xaxis: {
		type: "datetime",
		categories: ["2019-08-19T00:00:00", "2019-09-19T00:00:00", "2019-10-19T00:00:00", "2019-11-19T00:00:00"]
	},
	tooltip: {
		x: {
			format: "dd/MM/yy HH:mm"
		}
	}
};
jQuery("#bar-chart-12").length && ((chart12 = new ApexCharts(document.querySelector("#bar-chart-12"), barOptions12)).render(), window.setInterval(function() {
	getNewSeries(lastDate, {
		min: 10,
		max: 90
	}), jQuery("#bar-chart-12").length && chart12.updateSeries([{
		data: data
	}])
}, 1e3));
var option13 = {
	chart: {
		height: 420,
		type: "radialBar",
		stroke: {
			show: !0,
			curve: "smooth",
			lineCap: "butt",
			colors: void 0,
			width: 3,
			dashArray: 0
		}
	},
	plotOptions: {
		radialBar: {
			hollow: {
				margin: 10,
				size: "30%",
				background: "transparent",
				image: void 0,
				imageWidth: 64,
				imageHeight: 64
			},
			dataLabels: {
				name: {
					fontSize: "22px"
				},
				value: {
					fontSize: "16px"
				},
				total: {
					show: !0,
					label: "Total",
					formatter: function(e) {
						return 249
					}
				}
			}
		}
	},
	fill: {
		type: "gradient"
	},
	colors: ["#827af3", "#b47af3", "#27b345"],
	series: [44, 55, 67],
	stroke: {
		lineCap: "round"
	},
	labels: [" Mobile", "Desktop", "Tablet", "Watch"]
};
if (jQuery("#chart-13").length) {
	var chart13 = new ApexCharts(document.querySelector("#chart-13"), option13);
	chart13.render()
}
var option14 = {
	chart: {
		height: 350,
		type: "radialBar"
	},
	plotOptions: {
		hollow: {
			margin: 10,
			size: "30%",
			background: "transparent",
			image: void 0,
			imageWidth: 64,
			imageHeight: 64
		},
		radialBar: {
			startAngle: -135,
			endAngle: 135,
			dataLabels: {
				name: {
					fontSize: "16px",
					color: void 0,
					offsetY: 120
				},
				value: {
					offsetY: 76,
					fontSize: "22px",
					color: void 0,
					formatter: function(e) {
						return e + "%"
					}
				}
			}
		}
	},
	fill: {},
	stroke: {
		dashArray: 5
	},
	series: [67],
	labels: ["User traffic"],
	colors: ["#827af3"]
};
if (jQuery("#chart-14").length) {
	var chart14 = new ApexCharts(document.querySelector("#chart-14"), option14);
	chart14.render()
}
var option15 = {
	chart: {
		height: 310,
		type: "line",
		stacked: !1,
		toolbar: {
			show: !1
		}
	},
	dataLabels: {
		enabled: !1
	},
	colors: ["#827af3", "#27b345", "#b47af3"],
	series: [{
		name: "Income",
		type: "column",
		data: [14, 2, 25, 15, 25, 28, 38, 46]
	}, {
		name: "Cashflow",
		type: "column",
		data: [11, 3, 31, 4, 41, 49, 65, 85]
	}, {
		name: "Revenue",
		type: "line",
		data: [20, 29, 37, 36, 44, 45, 50, 58]
	}],
	stroke: {
		width: [1, 1, 4]
	},
	xaxis: {
		categories: [2009, 2010, 2011, 2012, 2013, 2014, 2015, 2016],
		labels: {
			show: !1
		}
	},
	yaxis: {
		show: !1
	},
	tooltip: {
		theme: "dark",
		fixed: {
			enabled: !0,
			position: "topLeft",
			offsetY: 30,
			offsetX: 60
		}
	},
	legend: {
		show: !1
	}
};
if (jQuery("#chart-15").length) {
	var chart15 = new ApexCharts(document.querySelector("#chart-15"), option15);
	chart15.render()
}
var option16 = {
	chart: {
		height: 350,
		type: "area",
		sparkline: {
			enabled: !0
		},
		group: "sparklines"
	},
	dataLabels: {
		enabled: !1
	},
	stroke: {
		curve: "smooth"
	},
	series: [{
		name: "series1",
		data: [3, 30, 15, 25, 35]
	}],
	colors: ["#6f32ff"],
	xaxis: {
		type: "datetime",
		categories: ["2018-08-19T00:00:00", "2018-09-19T01:30:00", "2018-10-19T02:30:00", "2018-11-19T01:30:00", "2018-12-19T01:30:00"]
	},
	tooltip: {
		x: {
			format: "dd/MM/yy HH:mm"
		}
	}
};
if (jQuery("#chart-16").length) {
	var chart16 = new ApexCharts(document.querySelector("#chart-16"), option16);
	chart16.render()
}
var option17 = {
	chart: {
		height: 268,
		type: "area",
		zoom: {
			enabled: !1
		},
		toolbar: {
			show: !1
		},
		sparkline: {
			enabled: !0
		},
		group: "sparklines"
	},
	colors: ["#827af3", "#b47af3", "#27b345"],
	dataLabels: {
		enabled: !1
	},
	stroke: {
		width: [3, 2, 3],
		curve: "straight"
	},
	series: [{
		name: "Session Duration",
		data: [45, 52, 38, 24, 33, 26, 21, 20, 6, 8, 15, 10]
	}, {
		name: "Page Views",
		data: [35, 41, 62, 42, 13, 18, 29, 37, 36, 51, 32, 35]
	}, {
		name: "Total Visits",
		data: [87, 57, 74, 30, 75, 38, 62, 47, 82, 56, 45, 47]
	}],
	legend: {
		show: !1
	},
	markers: {
		size: 0,
		hover: {
			sizeOffset: 6
		}
	},
	xaxis: {
		categories: ["01 Jan", "02 Jan", "03 Jan", "04 Jan", "05 Jan", "06 Jan", "07 Jan", "08 Jan", "09 Jan", "10 Jan", "11 Jan", "12 Jan"],
		labels: {
			show: !1
		}
	},
	yaxis: {
		labels: {
			show: !1
		}
	},
	tooltip: {
		y: [{
			title: {
				formatter: function(e) {
					return e + " (mins)"
				}
			}
		}, {
			title: {
				formatter: function(e) {
					return e + " per session"
				}
			}
		}, {
			title: {
				formatter: function(e) {
					return e
				}
			}
		}]
	},
	grid: {
		borderColor: "#f1f1f1"
	}
};
if (jQuery("#Dash1MultiBarChart").length) {
	var chart17 = new ApexCharts(document.querySelector("#Dash1MultiBarChart"), option17);
	chart17.render()
}
var option18 = {
	chart: {
		height: 235,
		type: "donut"
	},
	plotOptions: {
		pie: {
			donut: {
				size: "55%"
			}
		}
	},
	series: [44, 55, 41],
	colors: ["#827af3", "#b47af3", "#27b345"],
	labels: ["Server1", "Server2", "Server3"],
	legend: {
		position: "bottom"
	}
};
if (jQuery("#Dash1DonetChart").length) {
	var chart18 = new ApexCharts(document.querySelector("#Dash1DonetChart"), option18);
	chart18.render()
}
var option19 = {
	chart: {
		height: 308,
		type: "line",
		toolbar: {
			show: !1
		}
	},
	series: [{
		name: "Website Blog",
		type: "column",
		data: [440, 505, 414, 671, 227, 413, 201, 352, 752, 320, 257, 160]
	}, {
		name: "Social Media",
		type: "line",
		data: [23, 42, 35, 27, 43, 22, 17, 31, 22, 22, 12, 16]
	}],
	stroke: {
		width: [0, 4]
	},
	title: {
		show: !1
	},
	legend: {
		show: !1
	},
	labels: ["01 Jan 2001", "02 Jan 2001", "03 Jan 2001", "04 Jan 2001", "05 Jan 2001", "06 Jan 2001", "07 Jan 2001", "08 Jan 2001", "09 Jan 2001", "10 Jan 2001", "11 Jan 2001", "12 Jan 2001"],
	colors: ["#827af3", "#b47af3"],
	xaxis: {
		labels: {
			show: !1
		},
		type: "datetime"
	},
	yaxis: [{
		labels: {
			show: !1
		}
	}, {
		labels: {
			show: !1
		}
	}]
};
if (jQuery("#chart-19").length) {
	var chart19 = new ApexCharts(document.querySelector("#chart-19"), option19);
	chart19.render()
}
var option20 = {
	chart: {
		height: 387,
		type: "line",
		stacked: !1,
		toolbar: {
			show: !1
		},
		sparkline: {
			enabled: !0
		},
		group: "sparklines"
	},
	stroke: {
		width: [2, 3],
		curve: "smooth"
	},
	plotOptions: {
		bar: {
			columnWidth: "20%"
		}
	},
	colors: ["#827af3", "#fbc647"],
	series: [{
		name: "Vine",
		type: "area",
		data: [44, 55, 41, 67, 22, 43, 21, 41, 56, 27, 43]
	}, {
		name: "Dribbble",
		type: "line",
		data: [30, 25, 36, 30, 45, 35, 64, 52, 59, 36, 39]
	}],
	fill: {
		opacity: [.25, 1],
		gradient: {
			inverseColors: !1,
			shade: "light",
			type: "vertical",
			opacityFrom: .85,
			opacityTo: .55,
			stops: [0, 100, 100, 100]
		}
	},
	labels: ["01/01/2003", "02/01/2003", "03/01/2003", "04/01/2003", "05/01/2003", "06/01/2003", "07/01/2003", "08/01/2003", "09/01/2003", "10/01/2003", "11/01/2003"],
	xaxis: {
		type: "datetime",
		labels: {
			show: !1
		}
	},
	yaxis: {
		min: 0,
		labels: {
			show: !1
		}
	},
	tooltip: {
		shared: !0,
		intersect: !1,
		y: {
			formatter: function(e) {
				return void 0 !== e ? e.toFixed(0) + " views" : e
			}
		}
	},
	legend: {
		show: !1
	}
};
if (jQuery("#chart-20").length) {
	var chart20 = new ApexCharts(document.querySelector("#chart-20"), option20);
	chart20.render()
}
if (jQuery("#amChartWorldMap").length) {
	am4core.useTheme(am4themes_animated), (chart = am4core.create("amChartWorldMap", am4maps.MapChart)).geodata = am4geodata_worldLow, chart.projection = new am4maps.projections.Miller;
	var worldSeries = chart.series.push(new am4maps.MapPolygonSeries);
	worldSeries.exclude = ["AQ"], worldSeries.useGeodata = !0;
	var polygonTemplate = worldSeries.mapPolygons.template;
	polygonTemplate.tooltipText = "{name}", polygonTemplate.fill = chart.colors.getIndex(0), polygonTemplate.nonScalingStroke = !0, (hs = polygonTemplate.states.create("hover")).properties.fill = am4core.color("#367B25");
	var usaSeries = chart.series.push(new am4maps.MapPolygonSeries);
	usaSeries.geodata = am4geodata_usaLow;
	var hs, usPolygonTemplate = usaSeries.mapPolygons.template;
	usPolygonTemplate.tooltipText = "{name}", usPolygonTemplate.fill = chart.colors.getIndex(1), usPolygonTemplate.nonScalingStroke = !0, (hs = usPolygonTemplate.states.create("hover")).properties.fill = am4core.color("#367B25")
}
if (jQuery("#chartdiv").length && jQuery(document).ready(function() {
		am4core.ready(function() {
			am4core.useTheme(am4themes_animated);
			var e = {
					AD: {
						country: "Andorra",
						continent_code: "EU",
						continent: "Europe",
						maps: ["andorraLow", "andorraHigh"]
					},
					AE: {
						country: "United Arab Emirates",
						continent_code: "AS",
						continent: "Asia",
						maps: ["uaeLow", "uaeHigh"]
					},
					AF: {
						country: "Afghanistan",
						continent_code: "AS",
						continent: "Asia",
						maps: []
					},
					AG: {
						country: "Antigua and Barbuda",
						continent_code: "NA",
						continent: "North America",
						maps: ["antiguaBarbudaLow", "antiguaBarbudaHigh"]
					},
					AI: {
						country: "Anguilla",
						continent_code: "NA",
						continent: "North America",
						maps: ["anguillaLow", "anguillaHigh"]
					},
					AL: {
						country: "Albania",
						continent_code: "EU",
						continent: "Europe",
						maps: ["albaniaLow", "albaniaHigh"]
					},
					AM: {
						country: "Armenia",
						continent_code: "EU",
						continent: "Europe",
						maps: ["armeniaLow", "armeniaHigh"]
					},
					AO: {
						country: "Angola",
						continent_code: "AF",
						continent: "Africa",
						maps: ["angolaLow", "angolaHigh"]
					},
					AQ: {
						country: "Antarctica",
						continent_code: "AN",
						continent: "Antarctica",
						maps: []
					},
					AR: {
						country: "Argentina",
						continent_code: "SA",
						continent: "South America",
						maps: ["argentinaLow", "argentinaHigh"]
					},
					AS: {
						country: "American Samoa",
						continent_code: "OC",
						continent: "Oceania",
						maps: ["americanSamoaLow", "americanSamoaHigh"]
					},
					AT: {
						country: "Austria",
						continent_code: "EU",
						continent: "Europe",
						maps: ["austriaLow", "austriaHigh"]
					},
					AU: {
						country: "Australia",
						continent_code: "OC",
						continent: "Oceania",
						maps: ["australiaLow", "australiaHigh"]
					},
					AW: {
						country: "Aruba",
						continent_code: "NA",
						continent: "North America",
						maps: ["arubaLow", "arubaHigh"]
					},
					AX: {
						country: "Aland Islands",
						continent_code: "EU",
						continent: "Europe",
						maps: []
					},
					AZ: {
						country: "Azerbaijan",
						continent_code: "EU",
						continent: "Europe",
						maps: ["azerbaijanLow", "azerbaijanHigh"]
					},
					BA: {
						country: "Bosnia and Herzegovina",
						continent_code: "EU",
						continent: "Europe",
						maps: ["bosniaHerzegovinaLow", "bosniaHerzegovinaHigh", "bosniaHerzegovinaCantonsLow", "bosniaHerzegovinaCantonsHigh"]
					},
					BB: {
						country: "Barbados",
						continent_code: "NA",
						continent: "North America",
						maps: ["barbadosLow", "barbadosHigh"]
					},
					BD: {
						country: "Bangladesh",
						continent_code: "AS",
						continent: "Asia",
						maps: ["bangladeshLow", "bangladeshHigh"]
					},
					BE: {
						country: "Belgium",
						continent_code: "EU",
						continent: "Europe",
						maps: ["belgiumLow", "belgiumHigh"]
					},
					BF: {
						country: "Burkina Faso",
						continent_code: "AF",
						continent: "Africa",
						maps: ["burkinaFasoLow", "burkinaFasoHigh"]
					},
					BG: {
						country: "Bulgaria",
						continent_code: "EU",
						continent: "Europe",
						maps: ["bulgariaLow", "bulgariaHigh"]
					},
					BH: {
						country: "Bahrain",
						continent_code: "AS",
						continent: "Asia",
						maps: ["bahrainLow", "bahrainHigh"]
					},
					BI: {
						country: "Burundi",
						continent_code: "AF",
						continent: "Africa",
						maps: ["burundiLow", "burundiHigh"]
					},
					BJ: {
						country: "Benin",
						continent_code: "AF",
						continent: "Africa",
						maps: ["beninLow", "beninHigh"]
					},
					BL: {
						country: "Saint Barthelemy",
						continent_code: "NA",
						continent: "North America",
						maps: []
					},
					BM: {
						country: "Bermuda",
						continent_code: "NA",
						continent: "North America",
						maps: ["bermudaLow", "bermudaHigh"]
					},
					BN: {
						country: "Brunei Darussalam",
						continent_code: "AS",
						continent: "Asia",
						maps: ["bruneiDarussalamLow", "bruneiDarussalamHigh"]
					},
					BO: {
						country: "Bolivia, Plurinational State of",
						continent_code: "SA",
						continent: "South America",
						maps: ["boliviaLow", "boliviaHigh"]
					},
					BQ: {
						country: "Bonaire, Sint Eustatius and Saba",
						continent_code: "NA",
						continent: "North America",
						maps: ["bonaireSintEustatiusSabaLow", "bonaireSintEustatiusSabaHigh"]
					},
					BR: {
						country: "Brazil",
						continent_code: "SA",
						continent: "South America",
						maps: ["brazilLow", "brazilHigh"]
					},
					BS: {
						country: "Bahamas",
						continent_code: "NA",
						continent: "North America",
						maps: []
					},
					BT: {
						country: "Bhutan",
						continent_code: "AS",
						continent: "Asia",
						maps: ["bhutanLow", "bhutanHigh"]
					},
					BV: {
						country: "Bouvet Island",
						continent_code: "AN",
						continent: "Antarctica",
						maps: []
					},
					BW: {
						country: "Botswana",
						continent_code: "AF",
						continent: "Africa",
						maps: ["botswanaLow", "botswanaHigh"]
					},
					BY: {
						country: "Belarus",
						continent_code: "EU",
						continent: "Europe",
						maps: ["belarusLow", "belarusHigh"]
					},
					BZ: {
						country: "Belize",
						continent_code: "NA",
						continent: "North America",
						maps: ["belizeLow", "belizeHigh"]
					},
					CA: {
						country: "Canada",
						continent_code: "NA",
						continent: "North America",
						maps: ["canadaLow", "canadaHigh"]
					},
					CC: {
						country: "Cocos (Keeling) Islands",
						continent_code: "AS",
						continent: "Asia",
						maps: []
					},
					CD: {
						country: "Congo, the Democratic Republic of the",
						continent_code: "AF",
						continent: "Africa",
						maps: ["congoDRLow", "congoDRHigh"]
					},
					CF: {
						country: "Central African Republic",
						continent_code: "AF",
						continent: "Africa",
						maps: ["centralAfricanRepublicLow", "centralAfricanRepublicHigh"]
					},
					CG: {
						country: "Congo",
						continent_code: "AF",
						continent: "Africa",
						maps: ["congoLow", "congoHigh"]
					},
					CH: {
						country: "Switzerland",
						continent_code: "EU",
						continent: "Europe",
						maps: ["switzerlandLow", "switzerlandHigh"]
					},
					CI: {
						country: "Cote d'Ivoire",
						continent_code: "AF",
						continent: "Africa",
						maps: []
					},
					CK: {
						country: "Cook Islands",
						continent_code: "OC",
						continent: "Oceania",
						maps: []
					},
					CL: {
						country: "Chile",
						continent_code: "SA",
						continent: "South America",
						maps: ["chileLow", "chileHigh"]
					},
					CM: {
						country: "Cameroon",
						continent_code: "AF",
						continent: "Africa",
						maps: ["cameroonLow", "cameroonHigh"]
					},
					CN: {
						country: "China",
						continent_code: "AS",
						continent: "Asia",
						maps: ["chinaLow", "chinaHigh"]
					},
					CO: {
						country: "Colombia",
						continent_code: "SA",
						continent: "South America",
						maps: ["colombiaLow", "colombiaHigh", "colombiaMuniLow", "colombiaMuniHigh"]
					},
					CR: {
						country: "Costa Rica",
						continent_code: "NA",
						continent: "North America",
						maps: ["costaRicaLow", "costaRicaHigh"]
					},
					CU: {
						country: "Cuba",
						continent_code: "NA",
						continent: "North America",
						maps: []
					},
					CV: {
						country: "Cape Verde",
						continent_code: "AF",
						continent: "Africa",
						maps: ["capeVerdeLow", "capeVerdeHigh"]
					},
					CW: {
						country: "Curacao",
						continent_code: "NA",
						continent: "North America",
						maps: ["curacaoLow", "curacaoHigh"]
					},
					CX: {
						country: "Christmas Island",
						continent_code: "AS",
						continent: "Asia",
						maps: []
					},
					CY: {
						country: "Cyprus",
						continent_code: "EU",
						continent: "Europe",
						maps: ["cyprusLow", "cyprusHigh", "cyprusNorthCyprusLow", "cyprusNorthCyprusHigh"]
					},
					CZ: {
						country: "Czech Republic",
						continent_code: "EU",
						continent: "Europe",
						maps: ["czechiaLow", "czechiaHigh"]
					},
					DE: {
						country: "Germany",
						continent_code: "EU",
						continent: "Europe",
						maps: ["germanyLow", "germanyHigh"]
					},
					DJ: {
						country: "Djibouti",
						continent_code: "AF",
						continent: "Africa",
						maps: ["djiboutiLow", "djiboutiHigh"]
					},
					DK: {
						country: "Denmark",
						continent_code: "EU",
						continent: "Europe",
						maps: ["denmarkLow", "denmarkHigh"]
					},
					DM: {
						country: "Dominica",
						continent_code: "NA",
						continent: "North America",
						maps: ["dominicaLow", "dominicaHigh"]
					},
					DO: {
						country: "Dominican Republic",
						continent_code: "NA",
						continent: "North America",
						maps: ["dominicanRepublicLow", "dominicanRepublicHigh", "dominicanRepublicMuniLow", "dominicanRepublicMuniHigh"]
					},
					DZ: {
						country: "Algeria",
						continent_code: "AF",
						continent: "Africa",
						maps: ["algeriaLow", "algeriaHigh"]
					},
					EC: {
						country: "Ecuador",
						continent_code: "SA",
						continent: "South America",
						maps: ["ecuadorLow", "ecuadorHigh"]
					},
					EE: {
						country: "Estonia",
						continent_code: "EU",
						continent: "Europe",
						maps: ["estoniaLow", "estoniaHigh"]
					},
					EG: {
						country: "Egypt",
						continent_code: "AF",
						continent: "Africa",
						maps: ["egyptLow", "egyptHigh"]
					},
					EH: {
						country: "Western Sahara",
						continent_code: "AF",
						continent: "Africa",
						maps: []
					},
					ER: {
						country: "Eritrea",
						continent_code: "AF",
						continent: "Africa",
						maps: []
					},
					ES: {
						country: "Spain",
						continent_code: "EU",
						continent: "Europe",
						maps: ["spainLow", "spainHigh", "spainProvincesLow", "spainProvincesHigh"]
					},
					ET: {
						country: "Ethiopia",
						continent_code: "AF",
						continent: "Africa",
						maps: []
					},
					FI: {
						country: "Finland",
						continent_code: "EU",
						continent: "Europe",
						maps: ["finlandLow", "finlandHigh"]
					},
					FJ: {
						country: "Fiji",
						continent_code: "OC",
						continent: "Oceania",
						maps: ["fijiEastLow", "fijiEastHigh", "fijiWestLow", "fijiWestHigh"]
					},
					FK: {
						country: "Falkland Islands (Malvinas)",
						continent_code: "SA",
						continent: "South America",
						maps: []
					},
					FM: {
						country: "Micronesia, Federated States of",
						continent_code: "OC",
						continent: "Oceania",
						maps: []
					},
					FO: {
						country: "Faroe Islands",
						continent_code: "EU",
						continent: "Europe",
						maps: ["faroeIslandsLow", "faroeIslandsHigh"]
					},
					FR: {
						country: "France",
						continent_code: "EU",
						continent: "Europe",
						maps: ["franceLow", "franceHigh", "franceDepartmentsLow", "franceDepartmentsHigh"]
					},
					GA: {
						country: "Gabon",
						continent_code: "AF",
						continent: "Africa",
						maps: ["gabonLow", "gabonHigh"]
					},
					GB: {
						country: "United Kingdom",
						continent_code: "EU",
						continent: "Europe",
						maps: ["ukLow", "ukHigh", "ukCountiesLow", "ukCountiesHigh"]
					},
					"GB-CHA": {
						country: "Channel Islands",
						continent_code: "EU",
						continent: "Europe",
						maps: ["channelIslandsLow", "channelIslandsHigh"]
					},
					GD: {
						country: "Grenada",
						continent_code: "NA",
						continent: "North America",
						maps: []
					},
					GE: {
						country: "Georgia",
						continent_code: "EU",
						continent: "Europe",
						maps: ["georgiaLow", "georgiaHigh", "georgiaSouthOssetiaLow", "georgiaSouthOssetiaHigh"]
					},
					GF: {
						country: "French Guiana",
						continent_code: "SA",
						continent: "South America",
						maps: ["frenchGuianaLow", "frenchGuianaHigh"]
					},
					GG: {
						country: "Guernsey",
						continent_code: "EU",
						continent: "Europe",
						maps: []
					},
					GH: {
						country: "Ghana",
						continent_code: "AF",
						continent: "Africa",
						maps: []
					},
					GI: {
						country: "Gibraltar",
						continent_code: "EU",
						continent: "Europe",
						maps: []
					},
					GL: {
						country: "Greenland",
						continent_code: "NA",
						continent: "North America",
						maps: ["greenlandLow", "greenlandHigh"]
					},
					GM: {
						country: "Gambia",
						continent_code: "AF",
						continent: "Africa",
						maps: []
					},
					GN: {
						country: "Guinea",
						continent_code: "AF",
						continent: "Africa",
						maps: ["guineaLow", "guineaHigh"]
					},
					GP: {
						country: "Guadeloupe",
						continent_code: "NA",
						continent: "North America",
						maps: []
					},
					GQ: {
						country: "Equatorial Guinea",
						continent_code: "AF",
						continent: "Africa",
						maps: ["equatorialGuineaLow", "equatorialGuineaHigh"]
					},
					GR: {
						country: "Greece",
						continent_code: "EU",
						continent: "Europe",
						maps: ["greeceLow", "greeceHigh"]
					},
					GS: {
						country: "South Georgia and the South Sandwich Islands",
						continent_code: "AN",
						continent: "Antarctica",
						maps: []
					},
					GT: {
						country: "Guatemala",
						continent_code: "NA",
						continent: "North America",
						maps: []
					},
					GU: {
						country: "Guam",
						continent_code: "OC",
						continent: "Oceania",
						maps: []
					},
					GW: {
						country: "Guinea-Bissau",
						continent_code: "AF",
						continent: "Africa",
						maps: []
					},
					GY: {
						country: "Guyana",
						continent_code: "SA",
						continent: "South America",
						maps: []
					},
					HK: {
						country: "Hong Kong",
						continent_code: "AS",
						continent: "Asia",
						maps: ["hongKongLow", "hongKongHigh"]
					},
					HM: {
						country: "Heard Island and McDonald Islands",
						continent_code: "AN",
						continent: "Antarctica",
						maps: []
					},
					HN: {
						country: "Honduras",
						continent_code: "NA",
						continent: "North America",
						maps: ["hondurasLow", "hondurasHigh"]
					},
					HR: {
						country: "Croatia",
						continent_code: "EU",
						continent: "Europe",
						maps: ["croatiaLow", "croatiaHigh"]
					},
					HT: {
						country: "Haiti",
						continent_code: "NA",
						continent: "North America",
						maps: []
					},
					HU: {
						country: "Hungary",
						continent_code: "EU",
						continent: "Europe",
						maps: ["hungaryLow", "hungaryHigh"]
					},
					ID: {
						country: "Indonesia",
						continent_code: "AS",
						continent: "Asia",
						maps: ["indonesiaLow", "indonesiaHigh"]
					},
					IE: {
						country: "Ireland",
						continent_code: "EU",
						continent: "Europe",
						maps: ["irelandLow", "irelandHigh"]
					},
					IL: {
						country: "Israel",
						continent_code: "AS",
						continent: "Asia",
						maps: ["israelLow", "israelHigh", "israelPalestineLow", "israelPalestineHigh"]
					},
					IM: {
						country: "Isle of Man",
						continent_code: "EU",
						continent: "Europe",
						maps: []
					},
					IN: {
						country: "India",
						continent_code: "AS",
						continent: "Asia",
						maps: ["indiaLow", "indiaHigh"]
					},
					IO: {
						country: "British Indian Ocean Territory",
						continent_code: "AS",
						continent: "Asia",
						maps: []
					},
					IQ: {
						country: "Iraq",
						continent_code: "AS",
						continent: "Asia",
						maps: []
					},
					IR: {
						country: "Iran, Islamic Republic of",
						continent_code: "AS",
						continent: "Asia",
						maps: []
					},
					IS: {
						country: "Iceland",
						continent_code: "EU",
						continent: "Europe",
						maps: ["icelandLow", "icelandHigh"]
					},
					IT: {
						country: "Italy",
						continent_code: "EU",
						continent: "Europe",
						maps: ["italyLow", "italyHigh"]
					},
					JE: {
						country: "Jersey",
						continent_code: "EU",
						continent: "Europe",
						maps: []
					},
					JM: {
						country: "Jamaica",
						continent_code: "NA",
						continent: "North America",
						maps: []
					},
					JO: {
						country: "Jordan",
						continent_code: "AS",
						continent: "Asia",
						maps: []
					},
					JP: {
						country: "Japan",
						continent_code: "AS",
						continent: "Asia",
						maps: ["japanLow", "japanHigh"]
					},
					KE: {
						country: "Kenya",
						continent_code: "AF",
						continent: "Africa",
						maps: ["kenyaLow", "kenyaHigh"]
					},
					KG: {
						country: "Kyrgyzstan",
						continent_code: "AS",
						continent: "Asia",
						maps: ["kyrgyzstanLow", "kyrgyzstanHigh"]
					},
					KH: {
						country: "Cambodia",
						continent_code: "AS",
						continent: "Asia",
						maps: ["cambodiaLow", "cambodiaHigh"]
					},
					KI: {
						country: "Kiribati",
						continent_code: "OC",
						continent: "Oceania",
						maps: []
					},
					KM: {
						country: "Comoros",
						continent_code: "AF",
						continent: "Africa",
						maps: []
					},
					KN: {
						country: "Saint Kitts and Nevis",
						continent_code: "NA",
						continent: "North America",
						maps: []
					},
					KP: {
						country: "Korea, Democratic People's Republic of",
						continent_code: "AS",
						continent: "Asia",
						maps: ["northKoreaLow", "northKoreaHigh"]
					},
					KR: {
						country: "Korea, Republic of",
						continent_code: "AS",
						continent: "Asia",
						maps: ["southKoreaLow", "southKoreaHigh"]
					},
					KT: {
						country: "Saint Kitts and Nevis",
						continent_code: "AS",
						continent: "Asia",
						maps: ["stKittsNevisLow", "stKittsNevisHigh"]
					},
					KW: {
						country: "Kuwait",
						continent_code: "AS",
						continent: "Asia",
						maps: []
					},
					KY: {
						country: "Cayman Islands",
						continent_code: "NA",
						continent: "North America",
						maps: []
					},
					KZ: {
						country: "Kazakhstan",
						continent_code: "EU",
						continent: "Europe",
						maps: ["kazakhstanLow", "kazakhstanHigh"]
					},
					LA: {
						country: "Lao People's Democratic Republic",
						continent_code: "AS",
						continent: "Asia",
						maps: []
					},
					LB: {
						country: "Lebanon",
						continent_code: "AS",
						continent: "Asia",
						maps: []
					},
					LC: {
						country: "Saint Lucia",
						continent_code: "NA",
						continent: "North America",
						maps: ["saintLuciaLow", "saintLuciaHigh"]
					},
					LI: {
						country: "Liechtenstein",
						continent_code: "EU",
						continent: "Europe",
						maps: ["liechtensteinLow", "liechtensteinHigh"]
					},
					LK: {
						country: "Sri Lanka",
						continent_code: "AS",
						continent: "Asia",
						maps: ["sriLankaLow", "sriLankaHigh"]
					},
					LR: {
						country: "Liberia",
						continent_code: "AF",
						continent: "Africa",
						maps: []
					},
					LS: {
						country: "Lesotho",
						continent_code: "AF",
						continent: "Africa",
						maps: []
					},
					LT: {
						country: "Lithuania",
						continent_code: "EU",
						continent: "Europe",
						maps: ["lithuaniaLow", "lithuaniaHigh"]
					},
					LU: {
						country: "Luxembourg",
						continent_code: "EU",
						continent: "Europe",
						maps: []
					},
					LV: {
						country: "Latvia",
						continent_code: "EU",
						continent: "Europe",
						maps: ["latviaLow", "latviaHigh"]
					},
					LY: {
						country: "Libya",
						continent_code: "AF",
						continent: "Africa",
						maps: []
					},
					MA: {
						country: "Morocco",
						continent_code: "AF",
						continent: "Africa",
						maps: ["moroccoLow", "moroccoHigh"]
					},
					MC: {
						country: "Monaco",
						continent_code: "EU",
						continent: "Europe",
						maps: []
					},
					MD: {
						country: "Moldova, Republic of",
						continent_code: "EU",
						continent: "Europe",
						maps: ["moldovaLow", "moldovaHigh"]
					},
					ME: {
						country: "Montenegro",
						continent_code: "EU",
						continent: "Europe",
						maps: []
					},
					MF: {
						country: "Saint Martin (French Part)",
						continent_code: "NA",
						continent: "North America",
						maps: []
					},
					MG: {
						country: "Madagascar",
						continent_code: "AF",
						continent: "Africa",
						maps: []
					},
					MH: {
						country: "Marshall Islands",
						continent_code: "OC",
						continent: "Oceania",
						maps: []
					},
					MK: {
						country: "North Macedonia",
						continent_code: "EU",
						continent: "Europe",
						maps: []
					},
					ML: {
						country: "Mali",
						continent_code: "AF",
						continent: "Africa",
						maps: ["maliLow", "maliHigh"]
					},
					MM: {
						country: "Myanmar",
						continent_code: "AS",
						continent: "Asia",
						maps: []
					},
					MN: {
						country: "Mongolia",
						continent_code: "AS",
						continent: "Asia",
						maps: ["mongoliaLow", "mongoliaHigh"]
					},
					MO: {
						country: "Macao",
						continent_code: "AS",
						continent: "Asia",
						maps: []
					},
					MP: {
						country: "Northern Mariana Islands",
						continent_code: "OC",
						continent: "Oceania",
						maps: []
					},
					MQ: {
						country: "Martinique",
						continent_code: "NA",
						continent: "North America",
						maps: []
					},
					MR: {
						country: "Mauritania",
						continent_code: "AF",
						continent: "Africa",
						maps: []
					},
					MS: {
						country: "Montserrat",
						continent_code: "NA",
						continent: "North America",
						maps: []
					},
					MT: {
						country: "Malta",
						continent_code: "EU",
						continent: "Europe",
						maps: ["maltaLow", "maltaHigh"]
					},
					MU: {
						country: "Mauritius",
						continent_code: "AF",
						continent: "Africa",
						maps: []
					},
					MV: {
						country: "Maldives",
						continent_code: "AS",
						continent: "Asia",
						maps: ["maldivesLow", "maldivesHigh", "maldivesIslandsLow", "maldivesIslandsHigh"]
					},
					MW: {
						country: "Malawi",
						continent_code: "AF",
						continent: "Africa",
						maps: []
					},
					MX: {
						country: "Mexico",
						continent_code: "NA",
						continent: "North America",
						maps: ["mexicoLow", "mexicoHigh"]
					},
					MY: {
						country: "Malaysia",
						continent_code: "AS",
						continent: "Asia",
						maps: ["malaysiaLow", "malaysiaHigh"]
					},
					MZ: {
						country: "Mozambique",
						continent_code: "AF",
						continent: "Africa",
						maps: []
					},
					NA: {
						country: "Namibia",
						continent_code: "AF",
						continent: "Africa",
						maps: ["namibiaLow", "namibiaHigh"]
					},
					NC: {
						country: "New Caledonia",
						continent_code: "OC",
						continent: "Oceania",
						maps: []
					},
					NE: {
						country: "Niger",
						continent_code: "AF",
						continent: "Africa",
						maps: []
					},
					NF: {
						country: "Norfolk Island",
						continent_code: "OC",
						continent: "Oceania",
						maps: []
					},
					NG: {
						country: "Nigeria",
						continent_code: "AF",
						continent: "Africa",
						maps: ["nigeriaLow", "nigeriaHigh"]
					},
					NI: {
						country: "Nicaragua",
						continent_code: "NA",
						continent: "North America",
						maps: ["nicaraguaLow", "nicaraguaHigh"]
					},
					NL: {
						country: "Netherlands",
						continent_code: "EU",
						continent: "Europe",
						maps: ["netherlandsLow", "netherlandsHigh"]
					},
					NO: {
						country: "Norway",
						continent_code: "EU",
						continent: "Europe",
						maps: ["norwayLow", "norwayHigh"]
					},
					NP: {
						country: "Nepal",
						continent_code: "AS",
						continent: "Asia",
						maps: ["nepalLow", "nepalHigh"]
					},
					NR: {
						country: "Nauru",
						continent_code: "OC",
						continent: "Oceania",
						maps: []
					},
					NU: {
						country: "Niue",
						continent_code: "OC",
						continent: "Oceania",
						maps: []
					},
					NZ: {
						country: "New Zealand",
						continent_code: "OC",
						continent: "Oceania",
						maps: ["newZealandLow", "newZealandHigh"]
					},
					OM: {
						country: "Oman",
						continent_code: "AS",
						continent: "Asia",
						maps: ["omanLow", "omanHigh"]
					},
					PA: {
						country: "Panama",
						continent_code: "NA",
						continent: "North America",
						maps: ["panamaLow", "panamaHigh"]
					},
					PE: {
						country: "Peru",
						continent_code: "SA",
						continent: "South America",
						maps: ["peruLow", "peruHigh"]
					},
					PF: {
						country: "French Polynesia",
						continent_code: "OC",
						continent: "Oceania",
						maps: []
					},
					PG: {
						country: "Papua New Guinea",
						continent_code: "OC",
						continent: "Oceania",
						maps: []
					},
					PH: {
						country: "Philippines",
						continent_code: "AS",
						continent: "Asia",
						maps: ["philippinesLow", "philippinesHigh"]
					},
					PK: {
						country: "Pakistan",
						continent_code: "AS",
						continent: "Asia",
						maps: ["pakistanLow", "pakistanHigh"]
					},
					PL: {
						country: "Poland",
						continent_code: "EU",
						continent: "Europe",
						maps: ["polandLow", "polandHigh"]
					},
					PM: {
						country: "Saint Pierre and Miquelon",
						continent_code: "NA",
						continent: "North America",
						maps: ["stPierreMiquelonLow", "stPierreMiquelonHigh"]
					},
					PN: {
						country: "Pitcairn",
						continent_code: "OC",
						continent: "Oceania",
						maps: []
					},
					PR: {
						country: "Puerto Rico",
						continent_code: "NA",
						continent: "North America",
						maps: ["puertoRicoLow", "puertoRicoHigh"]
					},
					PS: {
						country: "Palestinian, State of",
						continent_code: "AS",
						continent: "Asia",
						maps: ["palestineLow", "palestineHigh"]
					},
					PT: {
						country: "Portugal",
						continent_code: "EU",
						continent: "Europe",
						maps: ["portugalLow", "portugalHigh", "portugalRegionsLow", "portugalRegionsHigh"]
					},
					PW: {
						country: "Palau",
						continent_code: "OC",
						continent: "Oceania",
						maps: []
					},
					PY: {
						country: "Paraguay",
						continent_code: "SA",
						continent: "South America",
						maps: ["paraguayLow", "paraguayHigh"]
					},
					QA: {
						country: "Qatar",
						continent_code: "AS",
						continent: "Asia",
						maps: ["qatarLow", "qatarHigh"]
					},
					RE: {
						country: "Reunion",
						continent_code: "AF",
						continent: "Africa",
						maps: []
					},
					RO: {
						country: "Romania",
						continent_code: "EU",
						continent: "Europe",
						maps: ["romaniaLow", "romaniaHigh"]
					},
					RS: {
						country: "Serbia",
						continent_code: "EU",
						continent: "Europe",
						maps: ["serbiaLow", "serbiaHigh", "serbiaNoKosovoLow", "serbiaNoKosovoHigh"]
					},
					RU: {
						country: "Russian Federation",
						continent_code: "EU",
						continent: "Europe",
						maps: ["russiaLow", "russiaHigh", "russiaCrimeaLow", "russiaCrimeaHigh"]
					},
					RW: {
						country: "Rwanda",
						continent_code: "AF",
						continent: "Africa",
						maps: []
					},
					SA: {
						country: "Saudi Arabia",
						continent_code: "AS",
						continent: "Asia",
						maps: ["saudiArabiaLow", "saudiArabiaHigh"]
					},
					SB: {
						country: "Solomon Islands",
						continent_code: "OC",
						continent: "Oceania",
						maps: ["solomonIslandsLow", "solomonIslandsHigh"]
					},
					SC: {
						country: "Seychelles",
						continent_code: "AF",
						continent: "Africa",
						maps: ["seychellesLow", "seychellesHigh"]
					},
					SD: {
						country: "Sudan",
						continent_code: "AF",
						continent: "Africa",
						maps: ["sudanLow", "sudanHigh"]
					},
					SE: {
						country: "Sweden",
						continent_code: "EU",
						continent: "Europe",
						maps: ["swedenLow", "swedenHigh"]
					},
					SG: {
						country: "Singapore",
						continent_code: "AS",
						continent: "Asia",
						maps: ["singaporeLow", "singaporeHigh"]
					},
					SH: {
						country: "Saint Helena, Ascension and Tristan da Cunha",
						continent_code: "AF",
						continent: "Africa",
						maps: ["saintHelenaLow", "saintHelenaHigh"]
					},
					SI: {
						country: "Slovenia",
						continent_code: "EU",
						continent: "Europe",
						maps: ["sloveniaLow", "sloveniaHigh", "sloveniaRegionsLow", "sloveniaRegionsHigh"]
					},
					SJ: {
						country: "Svalbard and Jan Mayen",
						continent_code: "EU",
						continent: "Europe",
						maps: ["svalbardLow", "svalbardHigh"]
					},
					SK: {
						country: "Slovakia",
						continent_code: "EU",
						continent: "Europe",
						maps: ["slovakiaLow", "slovakiaHigh"]
					},
					SL: {
						country: "Sierra Leone",
						continent_code: "AF",
						continent: "Africa",
						maps: []
					},
					SM: {
						country: "San Marino",
						continent_code: "EU",
						continent: "Europe",
						maps: ["sanMarinoLow", "sanMarinoHigh"]
					},
					SN: {
						country: "Senegal",
						continent_code: "AF",
						continent: "Africa",
						maps: ["senegalLow", "senegalHigh"]
					},
					SO: {
						country: "Somalia",
						continent_code: "AF",
						continent: "Africa",
						maps: ["somaliaLow", "somaliaHigh"]
					},
					SR: {
						country: "Suriname",
						continent_code: "SA",
						continent: "South America",
						maps: []
					},
					SS: {
						country: "South Sudan",
						continent_code: "AF",
						continent: "Africa",
						maps: []
					},
					ST: {
						country: "Sao Tome and Principe",
						continent_code: "AF",
						continent: "Africa",
						maps: ["saoTomePrincipeLow", "saoTomePrincipeHigh"]
					},
					SV: {
						country: "El Salvador",
						continent_code: "NA",
						continent: "North America",
						maps: ["elSalvadorLow", "elSalvadorHigh"]
					},
					SX: {
						country: "Sint Maarten (Dutch Part)",
						continent_code: "NA",
						continent: "North America",
						maps: []
					},
					SY: {
						country: "Syrian Arab Republic",
						continent_code: "AS",
						continent: "Asia",
						maps: ["syriaLow", "syriaHigh"]
					},
					SZ: {
						country: "Swaziland",
						continent_code: "AF",
						continent: "Africa",
						maps: ["eswatiniLow", "eswatiniHigh"]
					},
					TC: {
						country: "Turks and Caicos Islands",
						continent_code: "NA",
						continent: "North America",
						maps: []
					},
					TD: {
						country: "Chad",
						continent_code: "AF",
						continent: "Africa",
						maps: ["chadLow", "chadHigh"]
					},
					TF: {
						country: "French Southern Territories",
						continent_code: "AN",
						continent: "Antarctica",
						maps: []
					},
					TG: {
						country: "Togo",
						continent_code: "AF",
						continent: "Africa",
						maps: []
					},
					TH: {
						country: "Thailand",
						continent_code: "AS",
						continent: "Asia",
						maps: ["thailandLow", "thailandHigh"]
					},
					TJ: {
						country: "Tajikistan",
						continent_code: "AS",
						continent: "Asia",
						maps: ["tajikistanLow", "tajikistanHigh"]
					},
					TK: {
						country: "Tokelau",
						continent_code: "OC",
						continent: "Oceania",
						maps: []
					},
					TL: {
						country: "Timor-Leste",
						continent_code: "AS",
						continent: "Asia",
						maps: []
					},
					TM: {
						country: "Turkmenistan",
						continent_code: "AS",
						continent: "Asia",
						maps: []
					},
					TN: {
						country: "Tunisia",
						continent_code: "AF",
						continent: "Africa",
						maps: ["tunisiaLow", "tunisiaHigh"]
					},
					TO: {
						country: "Tonga",
						continent_code: "OC",
						continent: "Oceania",
						maps: []
					},
					TR: {
						country: "Turkey",
						continent_code: "EU",
						continent: "Europe",
						maps: ["turkeyLow", "turkeyHigh"]
					},
					TT: {
						country: "Trinidad and Tobago",
						continent_code: "NA",
						continent: "North America",
						maps: []
					},
					TV: {
						country: "Tuvalu",
						continent_code: "OC",
						continent: "Oceania",
						maps: []
					},
					TW: {
						country: "Taiwan, Province of China",
						continent_code: "AS",
						continent: "Asia",
						maps: []
					},
					TZ: {
						country: "Tanzania, United Republic of",
						continent_code: "AF",
						continent: "Africa",
						maps: ["tanzaniaLow", "tanzaniaHigh"]
					},
					UA: {
						country: "Ukraine",
						continent_code: "EU",
						continent: "Europe",
						maps: ["ukraineLow", "ukraineHigh"]
					},
					UG: {
						country: "Uganda",
						continent_code: "AF",
						continent: "Africa",
						maps: []
					},
					UM: {
						country: "United States Minor Outlying Islands",
						continent_code: "OC",
						continent: "Oceania",
						maps: []
					},
					US: {
						country: "United States",
						continent_code: "NA",
						continent: "North America",
						maps: ["usaLow", "usaHigh", "usaTerritoriesLow", "usaTerritoriesHigh", "usaTerritories2Low", "usaTerritories2High"]
					},
					UY: {
						country: "Uruguay",
						continent_code: "SA",
						continent: "South America",
						maps: []
					},
					UZ: {
						country: "Uzbekistan",
						continent_code: "AS",
						continent: "Asia",
						maps: ["uzbekinstanLow", "uzbekinstanHigh"]
					},
					VA: {
						country: "Holy See (Vatican City State)",
						continent_code: "EU",
						continent: "Europe",
						maps: ["vaticanLow", "vaticanHigh"]
					},
					VC: {
						country: "Saint Vincent and the Grenadines",
						continent_code: "NA",
						continent: "North America",
						maps: ["saintVincentLow", "saintVincentHigh"]
					},
					VE: {
						country: "Venezuela, Bolivarian Republic of",
						continent_code: "SA",
						continent: "South America",
						maps: ["venezuelaLow", "venezuelaHigh"]
					},
					VG: {
						country: "Virgin Islands, British",
						continent_code: "NA",
						continent: "North America",
						maps: []
					},
					VI: {
						country: "Virgin Islands, U.S.",
						continent_code: "NA",
						continent: "North America",
						maps: []
					},
					VN: {
						country: "Viet Nam",
						continent_code: "AS",
						continent: "Asia",
						maps: ["vietnamLow", "vietnamHigh"]
					},
					VU: {
						country: "Vanuatu",
						continent_code: "OC",
						continent: "Oceania",
						maps: []
					},
					WF: {
						country: "Wallis and Futuna",
						continent_code: "OC",
						continent: "Oceania",
						maps: []
					},
					WS: {
						country: "Samoa",
						continent_code: "OC",
						continent: "Oceania",
						maps: ["samoaLow", "samoaHigh"]
					},
					YE: {
						country: "Yemen",
						continent_code: "AS",
						continent: "Asia",
						maps: ["yemenLow", "yemenHigh"]
					},
					YT: {
						country: "Mayotte",
						continent_code: "AF",
						continent: "Africa",
						maps: []
					},
					ZA: {
						country: "South Africa",
						continent_code: "AF",
						continent: "Africa",
						maps: ["southAfricaLow", "southAfricaHigh"]
					},
					ZM: {
						country: "Zambia",
						continent_code: "AF",
						continent: "Africa",
						maps: ["zambiaLow", "zambiaHigh"]
					},
					ZW: {
						country: "Zimbabwe",
						continent_code: "AF",
						continent: "Africa",
						maps: ["zimbabweLow", "zimbabweHigh"]
					},
					XK: {
						country: "Kosovo",
						continent_code: "EU",
						continent: "Europe",
						maps: ["kosovoLow", "kosovoHigh"]
					}
				},
				t = {
					AF: 0,
					AN: 1,
					AS: 2,
					EU: 3,
					NA: 4,
					OC: 5,
					SA: 6
				},
				a = am4core.create("chartdiv", am4maps.MapChart);
			a.projection = new am4maps.projections.Miller;
			var n = a.series.push(new am4maps.MapPolygonSeries);
			n.useGeodata = !0, n.geodata = am4geodata_worldLow, n.exclude = ["AQ"];
			var o = n.mapPolygons.template;
			o.tooltipText = "{name}", o.nonScalingStroke = !0, o.strokeOpacity = .5, o.fill = am4core.color("#eee"), o.propertyFields.fill = "color", o.states.create("hover").properties.fill = a.colors.getIndex(9);
			var r = a.series.push(new am4maps.MapPolygonSeries);
			r.useGeodata = !0, r.hide(), r.geodataSource.events.on("done", function(e) {
				n.hide(), r.show()
			});
			var i = r.mapPolygons.template;
			i.tooltipText = "{name}", i.nonScalingStroke = !0, i.strokeOpacity = .5, i.fill = am4core.color("#eee"), i.states.create("hover").properties.fill = a.colors.getIndex(9), o.events.on("hit", function(e) {
				e.target.series.chart.zoomToMapObject(e.target);
				var t = e.target.dataItem.dataContext.map;
				t && (e.target.isHover = !1, r.geodataSource.url = "https://www.amcharts.com/lib/4/geodata/json/" + t + ".json", r.geodataSource.load())
			});
			var c = [];
			for (var s in e)
				if (e.hasOwnProperty(s)) {
					var l = e[s];
					l.maps.length && c.push({
						id: s,
						color: a.colors.getIndex(t[l.continent_code]),
						map: l.maps[0]
					})
				}
			n.data = c, a.zoomControl = new am4maps.ZoomControl;
			var d = new am4core.Button;
			d.events.on("hit", function() {
				n.show(), r.hide(), a.goHome()
			}), d.icon = new am4core.Sprite, d.padding(7, 5, 7, 5), d.width = 30, d.icon.path = "M16,8 L14,8 L14,16 L10,16 L10,10 L6,10 L6,16 L2,16 L2,8 L0,8 L8,0 L16,8 Z M16,8", d.marginBottom = 10, d.parent = a.zoomControl, d.insertBefore(a.zoomControl.plusButton)
		})
	}), jQuery("#calendar").length && document.addEventListener("DOMContentLoaded", function() {
		var e = document.getElementById("calendar");
		new FullCalendar.Calendar(e, {
			plugins: ["dayGrid"]
		}).render()
	}), jQuery("#calendar1").length && document.addEventListener("DOMContentLoaded", function() {
		var e = document.getElementById("calendar1");
		new FullCalendar.Calendar(e, {
			plugins: ["timeGrid", "dayGrid", "list"],
			timeZone: "UTC",
			defaultView: "dayGridMonth",
			header: {
				left: "prev,next today",
				center: "title",
				right: "dayGridMonth,timeGridWeek,timeGridDay,listWeek"
			},
			events: [{
				title: "All Day Event",
				start: "2020-03-01",
				color: "#fc9919"
			}, {
				title: "Long Event",
				start: "2020-03-07",
				end: "2020-03-10",
				color: "#ffc107"
			}, {
				groupId: "999",
				title: "Repeating Event",
				start: "2020-03-09T16:00:00",
				color: "#17a2b8"
			}, {
				groupId: "999",
				title: "Repeating Event",
				start: "2020-03-16T16:00:00",
				color: "#17a2b8"
			}, {
				title: "Conference",
				start: "2020-03-11",
				end: "2020-03-13",
				color: "#27e3f4"
			}, {
				title: "Meeting",
				start: "2020-03-12T10:30:00",
				end: "2020-03-12T12:30:00",
				color: "#827af3"
			}, {
				title: "Lunch",
				start: "2020-03-12T12:00:00",
				color: "#777D74"
			}, {
				title: "Meeting",
				start: "2020-03-12T14:30:00",
				color: "#827af3"
			}, {
				title: "Birthday Party",
				start: "2020-03-28T07:00:00",
				color: "#28a745"
			}, {
				title: "Meeting",
				start: "2020-01-12T14:30:00",
				color: "#827af3"
			}, {
				title: "Birthday Party",
				start: "2020-01-02T07:00:00",
				color: "#28a745"
			}, {
				title: "Click for Google",
				url: "http://google.com/",
				start: "2020-01-25"
			}, {
				title: "Birthday Party",
				start: "2020-01-13T07:00:00",
				color: "#28a745"
			}, {
				title: "Click for Google",
				url: "http://google.com/",
				start: "2020-03-28"
			}, {
				title: "Meeting",
				start: "2020-01-12T14:30:00",
				color: "#827af3"
			}, {
				title: "Birthday Party",
				start: "2020-01-13T07:00:00",
				color: "#28a745"
			}, {
				title: "Click for Google",
				url: "http://google.com/",
				start: "2020-01-28"
			}, {
				title: "All Day Event",
				start: "2020-02-01",
				color: "#fc9919"
			}, {
				title: "Long Event",
				start: "2020-02-07",
				end: "2020-02-10",
				color: "#ffc107"
			}, {
				groupId: "999",
				title: "Repeating Event",
				start: "2020-02-09T16:00:00",
				color: "#17a2b8"
			}, {
				groupId: "999",
				title: "Repeating Event",
				start: "2020-02-16T16:00:00",
				color: "#17a2b8"
			}]
		}).render()
	}), jQuery("#apex-basic").length) {
	options = {
		chart: {
			height: 350,
			type: "line",
			zoom: {
				enabled: !1
			}
		},
		colors: ["#827af3"],
		series: [{
			name: "Desktops",
			data: [10, 41, 35, 51, 49, 62, 69, 91, 148]
		}],
		dataLabels: {
			enabled: !1
		},
		stroke: {
			curve: "straight"
		},
		title: {
			text: "Product Trends by Month",
			align: "left"
		},
		grid: {
			row: {
				colors: ["#f3f3f3", "transparent"],
				opacity: .5
			}
		},
		xaxis: {
			categories: ["Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep"]
		}
	};
	(chart = new ApexCharts(document.querySelector("#apex-basic"), options)).render()
}
if (jQuery("#apex-line-area").length) {
	options = {
		chart: {
			height: 350,
			type: "area"
		},
		dataLabels: {
			enabled: !1
		},
		stroke: {
			curve: "smooth"
		},
		colors: ["#827af3", "#fbc647"],
		series: [{
			name: "series1",
			data: [31, 40, 28, 51, 42, 109, 100]
		}, {
			name: "series2",
			data: [11, 32, 45, 32, 34, 52, 41]
		}],
		xaxis: {
			type: "datetime",
			categories: ["2018-09-19T00:00:00", "2018-09-19T01:30:00", "2018-09-19T02:30:00", "2018-09-19T03:30:00", "2018-09-19T04:30:00", "2018-09-19T05:30:00", "2018-09-19T06:30:00"]
		},
		tooltip: {
			x: {
				format: "dd/MM/yy HH:mm"
			}
		}
	};
	(chart = new ApexCharts(document.querySelector("#apex-line-area"), options)).render()
}
if (jQuery("#apex-bar").length) {
	options = {
		chart: {
			height: 350,
			type: "bar"
		},
		plotOptions: {
			bar: {
				horizontal: !0
			}
		},
		dataLabels: {
			enabled: !1
		},
		colors: ["#827af3"],
		series: [{
			data: [470, 540, 580, 690, 1100, 1200, 1380]
		}],
		xaxis: {
			categories: ["Netherlands", "Italy", "France", "Japan", "United States", "China", "Germany"]
		}
	};
	(chart = new ApexCharts(document.querySelector("#apex-bar"), options)).render()
}
if (jQuery("#apex-column").length) {
	options = {
		chart: {
			height: 350,
			type: "bar"
		},
		plotOptions: {
			bar: {
				horizontal: !1,
				columnWidth: "55%",
				endingShape: "rounded"
			}
		},
		dataLabels: {
			enabled: !1
		},
		stroke: {
			show: !0,
			width: 2,
			colors: ["transparent"]
		},
		colors: ["#827af3", "#27b345", "#b47af3"],
		series: [{
			name: "Net Profit",
			data: [44, 55, 57, 56, 61, 58]
		}, {
			name: "Revenue",
			data: [76, 85, 101, 98, 87, 105]
		}, {
			name: "Free Cash Flow",
			data: [35, 41, 36, 26, 45, 48]
		}],
		xaxis: {
			categories: ["Feb", "Mar", "Apr", "May", "Jun", "Jul"]
		},
		yaxis: {
			title: {
				text: "$ (thousands)"
			}
		},
		fill: {
			opacity: 1
		},
		tooltip: {
			y: {
				formatter: function(e) {
					return "$ " + e + " thousands"
				}
			}
		}
	};
	(chart = new ApexCharts(document.querySelector("#apex-column"), options)).render()
}
if (jQuery("#apex-mixed-chart").length) {
	options = {
		chart: {
			height: 350,
			type: "line",
			stacked: !1
		},
		stroke: {
			width: [0, 2, 5],
			curve: "smooth"
		},
		plotOptions: {
			bar: {
				columnWidth: "50%"
			}
		},
		colors: ["#27b345", "#fbc647", "#827af3"],
		series: [{
			name: "Facebook",
			type: "column",
			data: [23, 11, 22, 27, 13, 22, 37, 21, 44, 22, 30]
		}, {
			name: "Vine",
			type: "area",
			data: [44, 55, 41, 67, 22, 43, 21, 41, 56, 27, 43]
		}, {
			name: "Dribbble",
			type: "line",
			data: [30, 25, 36, 30, 45, 35, 64, 52, 59, 36, 39]
		}],
		fill: {
			opacity: [.85, .25, 1],
			gradient: {
				inverseColors: !1,
				shade: "light",
				type: "vertical",
				opacityFrom: .85,
				opacityTo: .55,
				stops: [0, 100, 100, 100]
			}
		},
		labels: ["01/01/2003", "02/01/2003", "03/01/2003", "04/01/2003", "05/01/2003", "06/01/2003", "07/01/2003", "08/01/2003", "09/01/2003", "10/01/2003", "11/01/2003"],
		markers: {
			size: 0
		},
		xaxis: {
			type: "datetime"
		},
		yaxis: {
			min: 0
		},
		tooltip: {
			shared: !0,
			intersect: !1,
			y: {
				formatter: function(e) {
					return void 0 !== e ? e.toFixed(0) + " views" : e
				}
			}
		},
		legend: {
			labels: {
				useSeriesColors: !0
			},
			markers: {
				customHTML: [function() {
					return ""
				}, function() {
					return ""
				}, function() {
					return ""
				}]
			}
		}
	};
	(chart = new ApexCharts(document.querySelector("#apex-mixed-chart"), options)).render()
}
if (jQuery("#apex-candlestick-chart").length) {
	options = {
		chart: {
			height: 350,
			type: "candlestick"
		},
		colors: ["#827af3", "#27b345", "#b47af3"],
		series: [{
			data: [{
				x: new Date(15387786e5),
				y: [6629.81, 6650.5, 6623.04, 6633.33]
			}, {
				x: new Date(15387804e5),
				y: [6632.01, 6643.59, 6620, 6630.11]
			}, {
				x: new Date(15387822e5),
				y: [6630.71, 6648.95, 6623.34, 6635.65]
			}, {
				x: new Date(1538784e6),
				y: [6635.65, 6651, 6629.67, 6638.24]
			}, {
				x: new Date(15387858e5),
				y: [6638.24, 6640, 6620, 6624.47]
			}, {
				x: new Date(15387876e5),
				y: [6624.53, 6636.03, 6621.68, 6624.31]
			}, {
				x: new Date(15387894e5),
				y: [6624.61, 6632.2, 6617, 6626.02]
			}, {
				x: new Date(15387912e5),
				y: [6627, 6627.62, 6584.22, 6603.02]
			}, {
				x: new Date(1538793e6),
				y: [6605, 6608.03, 6598.95, 6604.01]
			}, {
				x: new Date(15387948e5),
				y: [6604.5, 6614.4, 6602.26, 6608.02]
			}, {
				x: new Date(15387966e5),
				y: [6608.02, 6610.68, 6601.99, 6608.91]
			}, {
				x: new Date(15387984e5),
				y: [6608.91, 6618.99, 6608.01, 6612]
			}, {
				x: new Date(15388002e5),
				y: [6612, 6615.13, 6605.09, 6612]
			}, {
				x: new Date(1538802e6),
				y: [6612, 6624.12, 6608.43, 6622.95]
			}, {
				x: new Date(15388038e5),
				y: [6623.91, 6623.91, 6615, 6615.67]
			}, {
				x: new Date(15388056e5),
				y: [6618.69, 6618.74, 6610, 6610.4]
			}, {
				x: new Date(15388074e5),
				y: [6611, 6622.78, 6610.4, 6614.9]
			}, {
				x: new Date(15388092e5),
				y: [6614.9, 6626.2, 6613.33, 6623.45]
			}, {
				x: new Date(1538811e6),
				y: [6623.48, 6627, 6618.38, 6620.35]
			}, {
				x: new Date(15388128e5),
				y: [6619.43, 6620.35, 6610.05, 6615.53]
			}, {
				x: new Date(15388146e5),
				y: [6615.53, 6617.93, 6610, 6615.19]
			}, {
				x: new Date(15388164e5),
				y: [6615.19, 6621.6, 6608.2, 6620]
			}, {
				x: new Date(15388182e5),
				y: [6619.54, 6625.17, 6614.15, 6620]
			}, {
				x: new Date(153882e7),
				y: [6620.33, 6634.15, 6617.24, 6624.61]
			}, {
				x: new Date(15388218e5),
				y: [6625.95, 6626, 6611.66, 6617.58]
			}, {
				x: new Date(15388236e5),
				y: [6619, 6625.97, 6595.27, 6598.86]
			}, {
				x: new Date(15388254e5),
				y: [6598.86, 6598.88, 6570, 6587.16]
			}, {
				x: new Date(15388272e5),
				y: [6588.86, 6600, 6580, 6593.4]
			}, {
				x: new Date(1538829e6),
				y: [6593.99, 6598.89, 6585, 6587.81]
			}, {
				x: new Date(15388308e5),
				y: [6587.81, 6592.73, 6567.14, 6578]
			}, {
				x: new Date(15388326e5),
				y: [6578.35, 6581.72, 6567.39, 6579]
			}, {
				x: new Date(15388344e5),
				y: [6579.38, 6580.92, 6566.77, 6575.96]
			}, {
				x: new Date(15388362e5),
				y: [6575.96, 6589, 6571.77, 6588.92]
			}, {
				x: new Date(1538838e6),
				y: [6588.92, 6594, 6577.55, 6589.22]
			}, {
				x: new Date(15388398e5),
				y: [6589.3, 6598.89, 6589.1, 6596.08]
			}, {
				x: new Date(15388416e5),
				y: [6597.5, 6600, 6588.39, 6596.25]
			}, {
				x: new Date(15388434e5),
				y: [6598.03, 6600, 6588.73, 6595.97]
			}, {
				x: new Date(15388452e5),
				y: [6595.97, 6602.01, 6588.17, 6602]
			}, {
				x: new Date(1538847e6),
				y: [6602, 6607, 6596.51, 6599.95]
			}, {
				x: new Date(15388488e5),
				y: [6600.63, 6601.21, 6590.39, 6591.02]
			}, {
				x: new Date(15388506e5),
				y: [6591.02, 6603.08, 6591, 6591]
			}, {
				x: new Date(15388524e5),
				y: [6591, 6601.32, 6585, 6592]
			}, {
				x: new Date(15388542e5),
				y: [6593.13, 6596.01, 6590, 6593.34]
			}, {
				x: new Date(1538856e6),
				y: [6593.34, 6604.76, 6582.63, 6593.86]
			}, {
				x: new Date(15388578e5),
				y: [6593.86, 6604.28, 6586.57, 6600.01]
			}, {
				x: new Date(15388596e5),
				y: [6601.81, 6603.21, 6592.78, 6596.25]
			}, {
				x: new Date(15388614e5),
				y: [6596.25, 6604.2, 6590, 6602.99]
			}, {
				x: new Date(15388632e5),
				y: [6602.99, 6606, 6584.99, 6587.81]
			}, {
				x: new Date(1538865e6),
				y: [6587.81, 6595, 6583.27, 6591.96]
			}, {
				x: new Date(15388668e5),
				y: [6591.97, 6596.07, 6585, 6588.39]
			}, {
				x: new Date(15388686e5),
				y: [6587.6, 6598.21, 6587.6, 6594.27]
			}, {
				x: new Date(15388704e5),
				y: [6596.44, 6601, 6590, 6596.55]
			}, {
				x: new Date(15388722e5),
				y: [6598.91, 6605, 6596.61, 6600.02]
			}, {
				x: new Date(1538874e6),
				y: [6600.55, 6605, 6589.14, 6593.01]
			}, {
				x: new Date(15388758e5),
				y: [6593.15, 6605, 6592, 6603.06]
			}]
		}],
		title: {
			text: "CandleStick Chart",
			align: "left"
		},
		xaxis: {
			type: "datetime"
		},
		yaxis: {
			tooltip: {
				enabled: !0
			}
		}
	};
	(chart = new ApexCharts(document.querySelector("#apex-candlestick-chart"), options)).render()
}
if (jQuery("#apex-bubble-chart").length) {
	function generateData(e, t, a) {
		for (var n = 0, o = []; n < t;) {
			var r = Math.floor(Math.random() * (a.max - a.min + 1)) + a.min,
				i = Math.floor(61 * Math.random()) + 15;
			o.push([e, r, i]), e += 864e5, n++
		}
		return o
	}
	options = {
		chart: {
			height: 350,
			type: "bubble"
		},
		dataLabels: {
			enabled: !1
		},
		series: [{
			name: "Product1",
			data: generateData(new Date("11 Feb 2017 GMT").getTime(), 20, {
				min: 10,
				max: 40
			})
		}, {
			name: "Product2",
			data: generateData(new Date("11 Feb 2017 GMT").getTime(), 20, {
				min: 10,
				max: 40
			})
		}, {
			name: "Product3",
			data: generateData(new Date("11 Feb 2017 GMT").getTime(), 20, {
				min: 10,
				max: 40
			})
		}],
		fill: {
			type: "gradient"
		},
		colors: ["#827af3", "#27b345", "#b47af3"],
		title: {
			text: "3D Bubble Chart"
		},
		xaxis: {
			tickAmount: 12,
			type: "datetime",
			labels: {
				rotate: 0
			}
		},
		yaxis: {
			max: 40
		},
		theme: {
			palette: "palette2"
		}
	};
	(chart = new ApexCharts(document.querySelector("#apex-bubble-chart"), options)).render()
}
if (jQuery("#apex-scatter-chart").length) {
	options = {
		chart: {
			height: 350,
			type: "scatter",
			zoom: {
				enabled: !0,
				type: "xy"
			}
		},
		colors: ["#827af3", "#b47af3", "#27b345"],
		series: [{
			name: "SAMPLE A",
			data: [
				[16.4, 5.4],
				[21.7, 2],
				[10.9, 0],
				[10.9, 8.2],
				[16.4, 0],
				[16.4, 1.8],
				[13.6, .3],
				[13.6, 0],
				[29.9, 0],
				[27.1, 2.3],
				[16.4, 0],
				[13.6, 3.7],
				[10.9, 5.2],
				[16.4, 6.5],
				[10.9, 0],
				[24.5, 7.1],
				[10.9, 0],
				[8.1, 4.7]
			]
		}, {
			name: "SAMPLE B",
			data: [
				[36.4, 13.4],
				[1.7, 11],
				[1.9, 9],
				[1.9, 13.2],
				[1.4, 7],
				[6.4, 8.8],
				[3.6, 4.3],
				[1.6, 10],
				[9.9, 2],
				[7.1, 15],
				[1.4, 0],
				[3.6, 13.7],
				[1.9, 15.2],
				[6.4, 16.5],
				[.9, 10],
				[4.5, 17.1],
				[10.9, 10],
				[.1, 14.7]
			]
		}, {
			name: "SAMPLE C",
			data: [
				[21.7, 3],
				[23.6, 3.5],
				[28, 4],
				[27.1, .3],
				[16.4, 4],
				[13.6, 0],
				[19, 5],
				[22.4, 3],
				[24.5, 3],
				[32.6, 3],
				[27.1, 4],
				[29.6, 6],
				[31.6, 8],
				[21.6, 5],
				[20.9, 4],
				[22.4, 0],
				[32.6, 10.3],
				[29.7, 20.8]
			]
		}],
		xaxis: {
			tickAmount: 5,
			labels: {
				formatter: function(e) {
					return parseFloat(e).toFixed(1)
				}
			}
		},
		yaxis: {
			tickAmount: 5
		}
	};
	(chart = new ApexCharts(document.querySelector("#apex-scatter-chart"), options)).render()
}
if (jQuery("#apex-radialbar-chart").length) {
	options = {
		chart: {
			height: 350,
			type: "radialBar"
		},
		plotOptions: {
			radialBar: {
				dataLabels: {
					name: {
						fontSize: "22px"
					},
					value: {
						fontSize: "16px"
					},
					total: {
						show: !0,
						label: "Total",
						formatter: function(e) {
							return 249
						}
					}
				}
			}
		},
		series: [44, 55, 67, 83],
		labels: ["Apples", "Oranges", "Bananas", "Berries"],
		colors: ["#827af3", "#b47af3", "#6ce6f4", "#27b345"]
	};
	(chart = new ApexCharts(document.querySelector("#apex-radialbar-chart"), options)).render()
}
if (jQuery("#apex-pie-chart").length) {
	options = {
		chart: {
			width: 380,
			type: "pie"
		},
		labels: ["Team A", "Team B", "Team C", "Team D", "Team E"],
		series: [44, 55, 13, 43, 22],
		colors: ["#827af3", "#b47af3", "#6ce6f4", "#27b345", "#c8c8c8"],
		responsive: [{
			breakpoint: 480,
			options: {
				chart: {
					width: 200
				},
				legend: {
					position: "bottom"
				}
			}
		}]
	};
	(chart = new ApexCharts(document.querySelector("#apex-pie-chart"), options)).render()
}
if (jQuery("#apex-area-01").length) {
	options = {
		series: [{
			name: "series1",
			data: [31, 40, 28, 51, 42, 109, 100]
		}],
		colors: ["#827af3"],
		chart: {
			height: 350,
			type: "area"
		},
		dataLabels: {
			enabled: !1
		},
		stroke: {
			curve: "smooth"
		},
		xaxis: {
			type: "datetime",
			categories: ["2018-09-19T00:00:00.000Z", "2018-09-19T01:30:00.000Z", "2018-09-19T02:30:00.000Z", "2018-09-19T03:30:00.000Z", "2018-09-19T04:30:00.000Z", "2018-09-19T05:30:00.000Z", "2018-09-19T06:30:00.000Z"]
		},
		tooltip: {
			x: {
				format: "dd/MM/yy HH:mm"
			}
		}
	};
	(chart = new ApexCharts(document.querySelector("#apex-area-01"), options)).render()
}
if (jQuery("#apex-area-02").length) {
	options = {
		series: [{
			name: "Series 1",
			data: [80, 50, 30, 40, 100, 20]
		}, {
			name: "Series 2",
			data: [20, 30, 40, 80, 20, 80]
		}, {
			name: "Series 3",
			data: [44, 76, 78, 13, 43, 10]
		}],
		colors: ["#827af3", "#b47af3", "#6ce6f4"],
		chart: {
			height: 350,
			type: "radar",
			dropShadow: {
				enabled: !0,
				blur: 1,
				left: 1,
				top: 1
			}
		},
		title: {
			text: "Radar Chart - Multi Series"
		},
		stroke: {
			width: 0
		},
		fill: {
			opacity: .4
		},
		markers: {
			size: 0
		},
		xaxis: {
			categories: ["2011", "2012", "2013", "2014", "2015", "2016"]
		}
	};
	(chart = new ApexCharts(document.querySelector("#apex-area-02"), options)).render()
}
if (jQuery("#apex-area-03").length) {
	options = {
		series: [{
			data: [34, 44, 54, 21, 12, 43, 33, 23, 66, 66, 58]
		}],
		colors: ["#827af3"],
		chart: {
			type: "line",
			height: 350
		},
		stroke: {
			curve: "stepline"
		},
		dataLabels: {
			enabled: !1
		},
		title: {
			text: "Stepline Chart",
			align: "left"
		},
		markers: {
			hover: {
				sizeOffset: 4
			}
		}
	};
	(chart = new ApexCharts(document.querySelector("#apex-area-03"), options)).render()
}
if (jQuery("#am-simple-chart").length && am4core.ready(function() {
		am4core.useTheme(am4themes_animated);
		var e = am4core.create("am-simple-chart", am4charts.XYChart);
		e.colors.list = [am4core.color("#827af3")], e.data = [{
			country: "USA",
			visits: 2025
		}, {
			country: "China",
			visits: 1882
		}, {
			country: "Japan",
			visits: 1809
		}, {
			country: "UK",
			visits: 1122
		}, {
			country: "France",
			visits: 1114
		}];
		var t = e.xAxes.push(new am4charts.CategoryAxis);
		t.dataFields.category = "country", t.renderer.grid.template.location = 0, t.renderer.minGridDistance = 30, t.renderer.labels.template.adapter.add("dy", function(e, t) {
			return t.dataItem && !0 & t.dataItem.index ? e + 25 : e
		});
		e.yAxes.push(new am4charts.ValueAxis);
		var a = e.series.push(new am4charts.ColumnSeries);
		a.dataFields.valueY = "visits", a.dataFields.categoryX = "country", a.name = "Visits", a.columns.template.tooltipText = "{categoryX}: [bold]{valueY}[/]", a.columns.template.fillOpacity = .8;
		var n = a.columns.template;
		n.strokeWidth = 2, n.strokeOpacity = 1
	}), jQuery("#am-columnlinr-chart").length && am4core.ready(function() {
		am4core.useTheme(am4themes_animated);
		var e = am4core.create("am-columnlinr-chart", am4charts.XYChart);
		e.colors.list = [am4core.color("#827af3")], e.exporting.menu = new am4core.ExportMenu;
		var t = e.xAxes.push(new am4charts.CategoryAxis);
		t.dataFields.category = "year", t.renderer.minGridDistance = 30;
		e.yAxes.push(new am4charts.ValueAxis);
		var a = e.series.push(new am4charts.ColumnSeries);
		a.name = "Income", a.dataFields.valueY = "income", a.dataFields.categoryX = "year", a.columns.template.tooltipText = "[#fff font-size: 15px]{name} in {categoryX}:\n[/][#fff font-size: 20px]{valueY}[/] [#fff]{additional}[/]", a.columns.template.propertyFields.fillOpacity = "fillOpacity", a.columns.template.propertyFields.stroke = "stroke", a.columns.template.propertyFields.strokeWidth = "strokeWidth", a.columns.template.propertyFields.strokeDasharray = "columnDash", a.tooltip.label.textAlign = "middle";
		var n = e.series.push(new am4charts.LineSeries);
		n.name = "Expenses", n.dataFields.valueY = "expenses", n.dataFields.categoryX = "year", n.stroke = am4core.color("#827af3"), n.strokeWidth = 3, n.propertyFields.strokeDasharray = "lineDash", n.tooltip.label.textAlign = "middle";
		var o = n.bullets.push(new am4charts.Bullet);
		o.fill = am4core.color("#fdd400"), o.tooltipText = "[#fff font-size: 15px]{name} in {categoryX}:\n[/][#fff font-size: 20px]{valueY}[/] [#fff]{additional}[/]";
		var r = o.createChild(am4core.Circle);
		r.radius = 4, r.fill = am4core.color("#fff"), r.strokeWidth = 3, e.data = [{
			year: "2009",
			income: 23.5,
			expenses: 21.1
		}, {
			year: "2010",
			income: 26.2,
			expenses: 30.5
		}, {
			year: "2011",
			income: 30.1,
			expenses: 34.9
		}, {
			year: "2012",
			income: 29.5,
			expenses: 31.1
		}, {
			year: "2013",
			income: 30.6,
			expenses: 28.2,
			lineDash: "5,5"
		}, {
			year: "2014",
			income: 34.1,
			expenses: 32.9,
			strokeWidth: 1,
			columnDash: "5,5",
			fillOpacity: .2,
			additional: "(projection)"
		}]
	}), jQuery("#am-stackedcolumn-chart").length && am4core.ready(function() {
		am4core.useTheme(am4themes_animated);
		var e = am4core.create("am-stackedcolumn-chart", am4charts.XYChart);
		e.colors.list = [am4core.color("#827af3"), am4core.color("#b47af3"), am4core.color("#27b345")], e.data = [{
			year: "2016",
			europe: 2.5,
			namerica: 2.5,
			asia: 2.1,
			lamerica: .3,
			meast: .2
		}, {
			year: "2018",
			europe: 2.8,
			namerica: 2.9,
			asia: 2.4,
			lamerica: .3,
			meast: .3
		}];
		var t = e.xAxes.push(new am4charts.CategoryAxis);
		t.dataFields.category = "year", t.renderer.grid.template.location = 0;
		var a = e.yAxes.push(new am4charts.ValueAxis);

		function n(t, a) {
			var n = e.series.push(new am4charts.ColumnSeries);
			n.name = a, n.dataFields.valueY = t, n.dataFields.categoryX = "year", n.sequencedInterpolation = !0, n.stacked = !0, n.columns.template.width = am4core.percent(60), n.columns.template.tooltipText = "[bold]{name}[/]\n[font-size:14px]{categoryX}: {valueY}";
			var o = n.bullets.push(new am4charts.LabelBullet);
			return o.label.text = "{valueY}", o.locationY = .5, n
		}
		a.renderer.inside = !0, a.renderer.labels.template.disabled = !0, a.min = 0, n("europe", "Europe"), n("namerica", "North America"), n("asia", "Asia-Pacific"), e.legend = new am4charts.Legend
	}), jQuery("#am-barline-chart").length && am4core.ready(function() {
		am4core.useTheme(am4themes_animated);
		var e = am4core.create("am-barline-chart", am4charts.XYChart);
		e.colors.list = [am4core.color("#827af3"), am4core.color("#827af3")], e.data = [{
			year: "2005",
			income: 23.5,
			expenses: 18.1
		}, {
			year: "2006",
			income: 26.2,
			expenses: 22.8
		}, {
			year: "2007",
			income: 30.1,
			expenses: 23.9
		}, {
			year: "2008",
			income: 29.5,
			expenses: 25.1
		}, {
			year: "2009",
			income: 24.6,
			expenses: 25
		}];
		var t = e.yAxes.push(new am4charts.CategoryAxis);
		t.dataFields.category = "year", t.renderer.inversed = !0, t.renderer.grid.template.location = 0, e.xAxes.push(new am4charts.ValueAxis).renderer.opposite = !0;
		var a = e.series.push(new am4charts.ColumnSeries);
		a.dataFields.categoryY = "year", a.dataFields.valueX = "income", a.name = "Income", a.columns.template.fillOpacity = .5, a.columns.template.strokeOpacity = 0, a.tooltipText = "Income in {categoryY}: {valueX.value}";
		var n = e.series.push(new am4charts.LineSeries);
		n.dataFields.categoryY = "year", n.dataFields.valueX = "expenses", n.name = "Expenses", n.strokeWidth = 3, n.tooltipText = "Expenses in {categoryY}: {valueX.value}";
		var o = n.bullets.push(new am4charts.CircleBullet);
		o.circle.fill = am4core.color("#fff"), o.circle.strokeWidth = 2, e.cursor = new am4charts.XYCursor, e.cursor.behavior = "zoomY", e.legend = new am4charts.Legend
	}), jQuery("#am-datedata-chart").length && am4core.ready(function() {
		am4core.useTheme(am4themes_animated);
		var e = am4core.create("am-datedata-chart", am4charts.XYChart);
		e.colors.list = [am4core.color("#827af3")], e.data = [{
			date: "2012-07-27",
			value: 13
		}, {
			date: "2012-07-28",
			value: 11
		}, {
			date: "2012-07-29",
			value: 15
		}, {
			date: "2012-07-30",
			value: 16
		}, {
			date: "2012-07-31",
			value: 18
		}, {
			date: "2012-08-01",
			value: 13
		}, {
			date: "2012-08-02",
			value: 22
		}, {
			date: "2012-08-03",
			value: 23
		}, {
			date: "2012-08-04",
			value: 20
		}, {
			date: "2012-08-05",
			value: 17
		}, {
			date: "2012-08-06",
			value: 16
		}, {
			date: "2012-08-07",
			value: 18
		}, {
			date: "2012-08-08",
			value: 21
		}, {
			date: "2012-08-09",
			value: 26
		}, {
			date: "2012-08-10",
			value: 24
		}, {
			date: "2012-08-11",
			value: 29
		}, {
			date: "2012-08-12",
			value: 32
		}, {
			date: "2012-08-13",
			value: 18
		}, {
			date: "2012-08-14",
			value: 24
		}, {
			date: "2012-08-15",
			value: 22
		}, {
			date: "2012-08-16",
			value: 18
		}, {
			date: "2012-08-17",
			value: 19
		}, {
			date: "2012-08-18",
			value: 14
		}, {
			date: "2012-08-19",
			value: 15
		}, {
			date: "2012-08-20",
			value: 12
		}, {
			date: "2012-08-21",
			value: 8
		}, {
			date: "2012-08-22",
			value: 9
		}, {
			date: "2012-08-23",
			value: 8
		}, {
			date: "2012-08-24",
			value: 7
		}, {
			date: "2012-08-25",
			value: 5
		}, {
			date: "2012-08-26",
			value: 11
		}, {
			date: "2012-08-27",
			value: 13
		}, {
			date: "2012-08-28",
			value: 18
		}, {
			date: "2012-08-29",
			value: 20
		}, {
			date: "2012-08-30",
			value: 29
		}, {
			date: "2012-08-31",
			value: 33
		}, {
			date: "2012-09-01",
			value: 42
		}, {
			date: "2012-09-02",
			value: 35
		}, {
			date: "2012-09-03",
			value: 31
		}, {
			date: "2012-09-04",
			value: 47
		}, {
			date: "2012-09-05",
			value: 52
		}, {
			date: "2012-09-06",
			value: 46
		}, {
			date: "2012-09-07",
			value: 41
		}, {
			date: "2012-09-08",
			value: 43
		}, {
			date: "2012-09-09",
			value: 40
		}, {
			date: "2012-09-10",
			value: 39
		}, {
			date: "2012-09-11",
			value: 34
		}, {
			date: "2012-09-12",
			value: 29
		}, {
			date: "2012-09-13",
			value: 34
		}, {
			date: "2012-09-14",
			value: 37
		}, {
			date: "2012-09-15",
			value: 42
		}, {
			date: "2012-09-16",
			value: 49
		}, {
			date: "2012-09-17",
			value: 46
		}, {
			date: "2012-09-18",
			value: 47
		}, {
			date: "2012-09-19",
			value: 55
		}, {
			date: "2012-09-20",
			value: 59
		}, {
			date: "2012-09-21",
			value: 58
		}, {
			date: "2012-09-22",
			value: 57
		}, {
			date: "2012-09-23",
			value: 61
		}, {
			date: "2012-09-24",
			value: 59
		}, {
			date: "2012-09-25",
			value: 67
		}, {
			date: "2012-09-26",
			value: 65
		}, {
			date: "2012-09-27",
			value: 61
		}, {
			date: "2012-09-28",
			value: 66
		}, {
			date: "2012-09-29",
			value: 69
		}, {
			date: "2012-09-30",
			value: 71
		}, {
			date: "2012-10-01",
			value: 67
		}, {
			date: "2012-10-02",
			value: 63
		}, {
			date: "2012-10-03",
			value: 46
		}, {
			date: "2012-10-04",
			value: 32
		}, {
			date: "2012-10-05",
			value: 21
		}, {
			date: "2012-10-06",
			value: 18
		}, {
			date: "2012-10-07",
			value: 21
		}, {
			date: "2012-10-08",
			value: 28
		}, {
			date: "2012-10-09",
			value: 27
		}, {
			date: "2012-10-10",
			value: 36
		}, {
			date: "2012-10-11",
			value: 33
		}, {
			date: "2012-10-12",
			value: 31
		}, {
			date: "2012-10-13",
			value: 30
		}, {
			date: "2012-10-14",
			value: 34
		}, {
			date: "2012-10-15",
			value: 38
		}, {
			date: "2012-10-16",
			value: 37
		}, {
			date: "2012-10-17",
			value: 44
		}, {
			date: "2012-10-18",
			value: 49
		}, {
			date: "2012-10-19",
			value: 53
		}, {
			date: "2012-10-20",
			value: 57
		}, {
			date: "2012-10-21",
			value: 60
		}, {
			date: "2012-10-22",
			value: 61
		}, {
			date: "2012-10-23",
			value: 69
		}, {
			date: "2012-10-24",
			value: 67
		}, {
			date: "2012-10-25",
			value: 72
		}, {
			date: "2012-10-26",
			value: 77
		}, {
			date: "2012-10-27",
			value: 75
		}, {
			date: "2012-10-28",
			value: 70
		}, {
			date: "2012-10-29",
			value: 72
		}, {
			date: "2012-10-30",
			value: 70
		}, {
			date: "2012-10-31",
			value: 72
		}, {
			date: "2012-11-01",
			value: 73
		}, {
			date: "2012-11-02",
			value: 67
		}, {
			date: "2012-11-03",
			value: 68
		}, {
			date: "2012-11-04",
			value: 65
		}, {
			date: "2012-11-05",
			value: 71
		}, {
			date: "2012-11-06",
			value: 75
		}, {
			date: "2012-11-07",
			value: 74
		}, {
			date: "2012-11-08",
			value: 71
		}, {
			date: "2012-11-09",
			value: 76
		}, {
			date: "2012-11-10",
			value: 77
		}, {
			date: "2012-11-11",
			value: 81
		}, {
			date: "2012-11-12",
			value: 83
		}, {
			date: "2012-11-13",
			value: 80
		}, {
			date: "2012-11-14",
			value: 81
		}, {
			date: "2012-11-15",
			value: 87
		}, {
			date: "2012-11-16",
			value: 82
		}, {
			date: "2012-11-17",
			value: 86
		}, {
			date: "2012-11-18",
			value: 80
		}, {
			date: "2012-11-19",
			value: 87
		}, {
			date: "2012-11-20",
			value: 83
		}, {
			date: "2012-11-21",
			value: 85
		}, {
			date: "2012-11-22",
			value: 84
		}, {
			date: "2012-11-23",
			value: 82
		}, {
			date: "2012-11-24",
			value: 73
		}, {
			date: "2012-11-25",
			value: 71
		}, {
			date: "2012-11-26",
			value: 75
		}, {
			date: "2012-11-27",
			value: 79
		}, {
			date: "2012-11-28",
			value: 70
		}, {
			date: "2012-11-29",
			value: 73
		}, {
			date: "2012-11-30",
			value: 61
		}, {
			date: "2012-12-01",
			value: 62
		}, {
			date: "2012-12-02",
			value: 66
		}, {
			date: "2012-12-03",
			value: 65
		}, {
			date: "2012-12-04",
			value: 73
		}, {
			date: "2012-12-05",
			value: 79
		}, {
			date: "2012-12-06",
			value: 78
		}, {
			date: "2012-12-07",
			value: 78
		}, {
			date: "2012-12-08",
			value: 78
		}, {
			date: "2012-12-09",
			value: 74
		}, {
			date: "2012-12-10",
			value: 73
		}, {
			date: "2012-12-11",
			value: 75
		}, {
			date: "2012-12-12",
			value: 70
		}, {
			date: "2012-12-13",
			value: 77
		}, {
			date: "2012-12-14",
			value: 67
		}, {
			date: "2012-12-15",
			value: 62
		}, {
			date: "2012-12-16",
			value: 64
		}, {
			date: "2012-12-17",
			value: 61
		}, {
			date: "2012-12-18",
			value: 59
		}, {
			date: "2012-12-19",
			value: 53
		}, {
			date: "2012-12-20",
			value: 54
		}, {
			date: "2012-12-21",
			value: 56
		}, {
			date: "2012-12-22",
			value: 59
		}, {
			date: "2012-12-23",
			value: 58
		}, {
			date: "2012-12-24",
			value: 55
		}, {
			date: "2012-12-25",
			value: 52
		}, {
			date: "2012-12-26",
			value: 54
		}, {
			date: "2012-12-27",
			value: 50
		}, {
			date: "2012-12-28",
			value: 50
		}, {
			date: "2012-12-29",
			value: 51
		}, {
			date: "2012-12-30",
			value: 52
		}, {
			date: "2012-12-31",
			value: 58
		}, {
			date: "2013-01-01",
			value: 60
		}, {
			date: "2013-01-02",
			value: 67
		}, {
			date: "2013-01-03",
			value: 64
		}, {
			date: "2013-01-04",
			value: 66
		}, {
			date: "2013-01-05",
			value: 60
		}, {
			date: "2013-01-06",
			value: 63
		}, {
			date: "2013-01-07",
			value: 61
		}, {
			date: "2013-01-08",
			value: 60
		}, {
			date: "2013-01-09",
			value: 65
		}, {
			date: "2013-01-10",
			value: 75
		}, {
			date: "2013-01-11",
			value: 77
		}, {
			date: "2013-01-12",
			value: 78
		}, {
			date: "2013-01-13",
			value: 70
		}, {
			date: "2013-01-14",
			value: 70
		}, {
			date: "2013-01-15",
			value: 73
		}, {
			date: "2013-01-16",
			value: 71
		}, {
			date: "2013-01-17",
			value: 74
		}, {
			date: "2013-01-18",
			value: 78
		}, {
			date: "2013-01-19",
			value: 85
		}, {
			date: "2013-01-20",
			value: 82
		}, {
			date: "2013-01-21",
			value: 83
		}, {
			date: "2013-01-22",
			value: 88
		}, {
			date: "2013-01-23",
			value: 85
		}, {
			date: "2013-01-24",
			value: 85
		}, {
			date: "2013-01-25",
			value: 80
		}, {
			date: "2013-01-26",
			value: 87
		}, {
			date: "2013-01-27",
			value: 84
		}, {
			date: "2013-01-28",
			value: 83
		}, {
			date: "2013-01-29",
			value: 84
		}, {
			date: "2013-01-30",
			value: 81
		}], e.dateFormatter.inputDateFormat = "yyyy-MM-dd";
		var t = e.xAxes.push(new am4charts.DateAxis),
			a = (e.yAxes.push(new am4charts.ValueAxis), e.series.push(new am4charts.LineSeries));
		a.dataFields.valueY = "value", a.dataFields.dateX = "date", a.tooltipText = "{value}", a.strokeWidth = 2, a.minBulletDistance = 15, a.tooltip.background.cornerRadius = 20, a.tooltip.background.strokeOpacity = 0, a.tooltip.pointerOrientation = "vertical", a.tooltip.label.minWidth = 40, a.tooltip.label.minHeight = 40, a.tooltip.label.textAlign = "middle", a.tooltip.label.textValign = "middle";
		var n = a.bullets.push(new am4charts.CircleBullet);
		n.circle.strokeWidth = 2, n.circle.radius = 4, n.circle.fill = am4core.color("#fff"), n.states.create("hover").properties.scale = 1.3, e.cursor = new am4charts.XYCursor, e.cursor.behavior = "panXY", e.cursor.xAxis = t, e.cursor.snapToSeries = a, e.scrollbarY = new am4core.Scrollbar, e.scrollbarY.parent = e.leftAxesContainer, e.scrollbarY.toBack(), e.scrollbarX = new am4charts.XYChartScrollbar, e.scrollbarX.series.push(a), e.scrollbarX.parent = e.bottomAxesContainer, t.start = .79, t.keepSelection = !0
	}), jQuery("#am-linescrollzomm-chart").length && am4core.ready(function() {
		am4core.useTheme(am4themes_animated);
		var e = am4core.create("am-linescrollzomm-chart", am4charts.XYChart);
		e.colors.list = [am4core.color("#827af3")], e.data = function() {
			var e = [],
				t = new Date;
			t.setDate(t.getDate() - 1e3);
			for (var a = 1200, n = 0; n < 500; n++) {
				var o = new Date(t);
				o.setDate(o.getDate() + n), a += Math.round((Math.random() < .5 ? 1 : -1) * Math.random() * 10), e.push({
					date: o,
					visits: a
				})
			}
			return e
		}();
		var t = e.xAxes.push(new am4charts.DateAxis);
		t.renderer.minGridDistance = 50;
		e.yAxes.push(new am4charts.ValueAxis);
		var a = e.series.push(new am4charts.LineSeries);
		a.dataFields.valueY = "visits", a.dataFields.dateX = "date", a.strokeWidth = 2, a.minBulletDistance = 10, a.tooltipText = "{valueY}", a.tooltip.pointerOrientation = "vertical", a.tooltip.background.cornerRadius = 20, a.tooltip.background.fillOpacity = .5, a.tooltip.label.padding(12, 12, 12, 12), e.scrollbarX = new am4charts.XYChartScrollbar, e.scrollbarX.series.push(a), e.cursor = new am4charts.XYCursor, e.cursor.xAxis = t, e.cursor.snapToSeries = a
	}), jQuery("#am-zoomable-chart").length && am4core.ready(function() {
		am4core.useTheme(am4themes_animated);
		var e = am4core.create("am-zoomable-chart", am4charts.XYChart);
		e.colors.list = [am4core.color("#827af3")], e.data = [{
			date: "2012-07-27",
			value: 13
		}, {
			date: "2012-07-28",
			value: 11
		}, {
			date: "2012-07-29",
			value: 15
		}, {
			date: "2012-07-30",
			value: 16
		}, {
			date: "2012-07-31",
			value: 18
		}, {
			date: "2012-08-01",
			value: 13
		}, {
			date: "2012-08-02",
			value: 22
		}, {
			date: "2012-08-03",
			value: 23
		}, {
			date: "2012-08-04",
			value: 20
		}, {
			date: "2012-08-05",
			value: 17
		}, {
			date: "2012-08-06",
			value: 16
		}, {
			date: "2012-08-07",
			value: 18
		}, {
			date: "2012-08-08",
			value: 21
		}, {
			date: "2012-08-09",
			value: 26
		}, {
			date: "2012-08-10",
			value: 24
		}, {
			date: "2012-08-11",
			value: 29
		}, {
			date: "2012-08-12",
			value: 32
		}, {
			date: "2012-08-13",
			value: 18
		}, {
			date: "2012-08-14",
			value: 24
		}, {
			date: "2012-08-15",
			value: 22
		}, {
			date: "2012-08-16",
			value: 18
		}, {
			date: "2012-08-17",
			value: 19
		}, {
			date: "2012-08-18",
			value: 14
		}, {
			date: "2012-08-19",
			value: 15
		}, {
			date: "2012-08-20",
			value: 12
		}, {
			date: "2012-08-21",
			value: 8
		}, {
			date: "2012-08-22",
			value: 9
		}, {
			date: "2012-08-23",
			value: 8
		}, {
			date: "2012-08-24",
			value: 7
		}, {
			date: "2012-08-25",
			value: 5
		}, {
			date: "2012-08-26",
			value: 11
		}, {
			date: "2012-08-27",
			value: 13
		}, {
			date: "2012-08-28",
			value: 18
		}, {
			date: "2012-08-29",
			value: 20
		}, {
			date: "2012-08-30",
			value: 29
		}, {
			date: "2012-08-31",
			value: 33
		}, {
			date: "2012-09-01",
			value: 42
		}, {
			date: "2012-09-02",
			value: 35
		}, {
			date: "2012-09-03",
			value: 31
		}, {
			date: "2012-09-04",
			value: 47
		}, {
			date: "2012-09-05",
			value: 52
		}, {
			date: "2012-09-06",
			value: 46
		}, {
			date: "2012-09-07",
			value: 41
		}, {
			date: "2012-09-08",
			value: 43
		}, {
			date: "2012-09-09",
			value: 40
		}, {
			date: "2012-09-10",
			value: 39
		}, {
			date: "2012-09-11",
			value: 34
		}, {
			date: "2012-09-12",
			value: 29
		}, {
			date: "2012-09-13",
			value: 34
		}, {
			date: "2012-09-14",
			value: 37
		}, {
			date: "2012-09-15",
			value: 42
		}, {
			date: "2012-09-16",
			value: 49
		}, {
			date: "2012-09-17",
			value: 46
		}, {
			date: "2012-09-18",
			value: 47
		}, {
			date: "2012-09-19",
			value: 55
		}, {
			date: "2012-09-20",
			value: 59
		}, {
			date: "2012-09-21",
			value: 58
		}, {
			date: "2012-09-22",
			value: 57
		}, {
			date: "2012-09-23",
			value: 61
		}, {
			date: "2012-09-24",
			value: 59
		}, {
			date: "2012-09-25",
			value: 67
		}, {
			date: "2012-09-26",
			value: 65
		}, {
			date: "2012-09-27",
			value: 61
		}, {
			date: "2012-09-28",
			value: 66
		}, {
			date: "2012-09-29",
			value: 69
		}, {
			date: "2012-09-30",
			value: 71
		}, {
			date: "2012-10-01",
			value: 67
		}, {
			date: "2012-10-02",
			value: 63
		}, {
			date: "2012-10-03",
			value: 46
		}, {
			date: "2012-10-04",
			value: 32
		}, {
			date: "2012-10-05",
			value: 21
		}, {
			date: "2012-10-06",
			value: 18
		}, {
			date: "2012-10-07",
			value: 21
		}, {
			date: "2012-10-08",
			value: 28
		}, {
			date: "2012-10-09",
			value: 27
		}, {
			date: "2012-10-10",
			value: 36
		}, {
			date: "2012-10-11",
			value: 33
		}, {
			date: "2012-10-12",
			value: 31
		}, {
			date: "2012-10-13",
			value: 30
		}, {
			date: "2012-10-14",
			value: 34
		}, {
			date: "2012-10-15",
			value: 38
		}, {
			date: "2012-10-16",
			value: 37
		}, {
			date: "2012-10-17",
			value: 44
		}, {
			date: "2012-10-18",
			value: 49
		}, {
			date: "2012-10-19",
			value: 53
		}, {
			date: "2012-10-20",
			value: 57
		}, {
			date: "2012-10-21",
			value: 60
		}, {
			date: "2012-10-22",
			value: 61
		}, {
			date: "2012-10-23",
			value: 69
		}, {
			date: "2012-10-24",
			value: 67
		}, {
			date: "2012-10-25",
			value: 72
		}, {
			date: "2012-10-26",
			value: 77
		}, {
			date: "2012-10-27",
			value: 75
		}, {
			date: "2012-10-28",
			value: 70
		}, {
			date: "2012-10-29",
			value: 72
		}, {
			date: "2012-10-30",
			value: 70
		}, {
			date: "2012-10-31",
			value: 72
		}, {
			date: "2012-11-01",
			value: 73
		}, {
			date: "2012-11-02",
			value: 67
		}, {
			date: "2012-11-03",
			value: 68
		}, {
			date: "2012-11-04",
			value: 65
		}, {
			date: "2012-11-05",
			value: 71
		}, {
			date: "2012-11-06",
			value: 75
		}, {
			date: "2012-11-07",
			value: 74
		}, {
			date: "2012-11-08",
			value: 71
		}, {
			date: "2012-11-09",
			value: 76
		}, {
			date: "2012-11-10",
			value: 77
		}, {
			date: "2012-11-11",
			value: 81
		}, {
			date: "2012-11-12",
			value: 83
		}, {
			date: "2012-11-13",
			value: 80
		}, {
			date: "2012-11-18",
			value: 80
		}, {
			date: "2012-11-19",
			value: 87
		}, {
			date: "2012-11-20",
			value: 83
		}, {
			date: "2012-11-21",
			value: 85
		}, {
			date: "2012-11-22",
			value: 84
		}, {
			date: "2012-11-23",
			value: 82
		}, {
			date: "2012-11-24",
			value: 73
		}, {
			date: "2012-11-25",
			value: 71
		}, {
			date: "2012-11-26",
			value: 75
		}, {
			date: "2012-11-27",
			value: 79
		}, {
			date: "2012-11-28",
			value: 70
		}, {
			date: "2012-11-29",
			value: 73
		}, {
			date: "2012-11-30",
			value: 61
		}, {
			date: "2012-12-01",
			value: 62
		}, {
			date: "2012-12-02",
			value: 66
		}, {
			date: "2012-12-03",
			value: 65
		}, {
			date: "2012-12-04",
			value: 73
		}, {
			date: "2012-12-05",
			value: 79
		}, {
			date: "2012-12-06",
			value: 78
		}, {
			date: "2012-12-07",
			value: 78
		}, {
			date: "2012-12-08",
			value: 78
		}, {
			date: "2012-12-09",
			value: 74
		}, {
			date: "2012-12-10",
			value: 73
		}, {
			date: "2012-12-11",
			value: 75
		}, {
			date: "2012-12-12",
			value: 70
		}, {
			date: "2012-12-13",
			value: 77
		}, {
			date: "2012-12-14",
			value: 67
		}, {
			date: "2012-12-15",
			value: 62
		}, {
			date: "2012-12-16",
			value: 64
		}, {
			date: "2012-12-17",
			value: 61
		}, {
			date: "2012-12-18",
			value: 59
		}, {
			date: "2012-12-19",
			value: 53
		}, {
			date: "2012-12-20",
			value: 54
		}, {
			date: "2012-12-21",
			value: 56
		}, {
			date: "2012-12-22",
			value: 59
		}, {
			date: "2012-12-23",
			value: 58
		}, {
			date: "2012-12-24",
			value: 55
		}, {
			date: "2012-12-25",
			value: 52
		}, {
			date: "2012-12-26",
			value: 54
		}, {
			date: "2012-12-27",
			value: 50
		}, {
			date: "2012-12-28",
			value: 50
		}, {
			date: "2012-12-29",
			value: 51
		}, {
			date: "2012-12-30",
			value: 52
		}, {
			date: "2012-12-31",
			value: 58
		}, {
			date: "2013-01-01",
			value: 60
		}, {
			date: "2013-01-02",
			value: 67
		}, {
			date: "2013-01-03",
			value: 64
		}, {
			date: "2013-01-04",
			value: 66
		}, {
			date: "2013-01-05",
			value: 60
		}, {
			date: "2013-01-06",
			value: 63
		}, {
			date: "2013-01-07",
			value: 61
		}, {
			date: "2013-01-08",
			value: 60
		}, {
			date: "2013-01-09",
			value: 65
		}, {
			date: "2013-01-10",
			value: 75
		}, {
			date: "2013-01-11",
			value: 77
		}, {
			date: "2013-01-12",
			value: 78
		}, {
			date: "2013-01-13",
			value: 70
		}, {
			date: "2013-01-14",
			value: 70
		}, {
			date: "2013-01-15",
			value: 73
		}, {
			date: "2013-01-16",
			value: 71
		}, {
			date: "2013-01-17",
			value: 74
		}, {
			date: "2013-01-18",
			value: 78
		}, {
			date: "2013-01-19",
			value: 85
		}, {
			date: "2013-01-20",
			value: 82
		}, {
			date: "2013-01-21",
			value: 83
		}, {
			date: "2013-01-22",
			value: 88
		}, {
			date: "2013-01-23",
			value: 85
		}, {
			date: "2013-01-24",
			value: 85
		}, {
			date: "2013-01-25",
			value: 80
		}, {
			date: "2013-01-26",
			value: 87
		}, {
			date: "2013-01-27",
			value: 84
		}, {
			date: "2013-01-28",
			value: 83
		}, {
			date: "2013-01-29",
			value: 84
		}, {
			date: "2013-01-30",
			value: 81
		}];
		var t = e.xAxes.push(new am4charts.DateAxis);
		t.renderer.grid.template.location = 0, t.renderer.minGridDistance = 50;
		e.yAxes.push(new am4charts.ValueAxis);
		var a = e.series.push(new am4charts.LineSeries);
		a.dataFields.valueY = "value", a.dataFields.dateX = "date", a.strokeWidth = 3, a.fillOpacity = .5, e.scrollbarY = new am4core.Scrollbar, e.scrollbarY.marginLeft = 0, e.cursor = new am4charts.XYCursor, e.cursor.behavior = "zoomY", e.cursor.lineX.disabled = !0
	}), jQuery("#am-radar-chart").length && am4core.ready(function() {
		am4core.useTheme(am4themes_animated);
		var e = am4core.create("am-radar-chart", am4charts.RadarChart);
		e.colors.list = [am4core.color("#827af3")], e.data = [{
			country: "Lithuania",
			litres: 501
		}, {
			country: "Czechia",
			litres: 301
		}, {
			country: "Ireland",
			litres: 266
		}, {
			country: "Germany",
			litres: 165
		}, {
			country: "Australia",
			litres: 139
		}, {
			country: "Austria",
			litres: 336
		}, {
			country: "UK",
			litres: 290
		}, {
			country: "Belgium",
			litres: 325
		}, {
			country: "The Netherlands",
			litres: 40
		}], e.xAxes.push(new am4charts.CategoryAxis).dataFields.category = "country";
		var t = e.yAxes.push(new am4charts.ValueAxis);
		t.renderer.axisFills.template.fill = e.colors.getIndex(2), t.renderer.axisFills.template.fillOpacity = .05;
		var a = e.series.push(new am4charts.RadarSeries);
		a.dataFields.valueY = "litres", a.dataFields.categoryX = "country", a.name = "Sales", a.strokeWidth = 3
	}), jQuery("#am-polar-chart").length && am4core.ready(function() {
		am4core.useTheme(am4themes_animated);
		var e = am4core.create("am-polar-chart", am4charts.RadarChart);
		e.data = [{
			direction: "N",
			value: 8
		}, {
			direction: "NE",
			value: 9
		}, {
			direction: "E",
			value: 4.5
		}, {
			direction: "SE",
			value: 3.5
		}, {
			direction: "S",
			value: 9.2
		}, {
			direction: "SW",
			value: 8.4
		}, {
			direction: "W",
			value: 11.1
		}, {
			direction: "NW",
			value: 10
		}];
		var t = e.xAxes.push(new am4charts.CategoryAxis);
		t.dataFields.category = "direction";
		e.yAxes.push(new am4charts.ValueAxis);
		var a = t.axisRanges.create();
		a.category = "NW", a.endCategory = "NW", a.axisFill.fill = am4core.color("#827af3"), a.axisFill.fillOpacity = .3;
		var n = t.axisRanges.create();
		n.category = "N", n.endCategory = "N", n.axisFill.fill = am4core.color("#b47af3"), n.axisFill.fillOpacity = .3;
		var o = t.axisRanges.create();
		o.category = "SE", o.endCategory = "SW", o.axisFill.fill = am4core.color("#fbc647"), o.axisFill.fillOpacity = .3, o.locations.endCategory = 0;
		var r = e.series.push(new am4charts.RadarSeries);
		r.dataFields.valueY = "value", r.dataFields.categoryX = "direction", r.name = "Wind direction", r.strokeWidth = 3, r.fillOpacity = .2
	}), jQuery("#am-polarscatter-chart").length && am4core.ready(function() {
		am4core.useTheme(am4themes_animated);
		var e = am4core.create("am-polarscatter-chart", am4charts.RadarChart);
		e.colors.list = [am4core.color("#827af3"), am4core.color("#b47af3"), am4core.color("#27b345")], e.data = [{
			country: "Lithuania",
			litres: 501,
			units: 250
		}, {
			country: "Czech Republic",
			litres: 301,
			units: 222
		}, {
			country: "Ireland",
			litres: 266,
			units: 179
		}, {
			country: "Germany",
			litres: 165,
			units: 298
		}, {
			country: "Australia",
			litres: 139,
			units: 299
		}], e.xAxes.push(new am4charts.ValueAxis).renderer.maxLabelPosition = .99;
		var t = e.yAxes.push(new am4charts.ValueAxis);
		t.renderer.labels.template.verticalCenter = "bottom", t.renderer.labels.template.horizontalCenter = "right", t.renderer.maxLabelPosition = .99, t.renderer.labels.template.paddingBottom = 1, t.renderer.labels.template.paddingRight = 3;
		var a = e.series.push(new am4charts.RadarSeries);
		a.bullets.push(new am4charts.CircleBullet), a.strokeOpacity = 0, a.dataFields.valueX = "x", a.dataFields.valueY = "y", a.name = "Series #1", a.sequencedInterpolation = !0, a.sequencedInterpolationDelay = 10, a.data = [{
			x: 83,
			y: 5.1
		}, {
			x: 44,
			y: 5.8
		}, {
			x: 76,
			y: 9
		}, {
			x: 2,
			y: 1.4
		}, {
			x: 100,
			y: 8.3
		}, {
			x: 96,
			y: 1.7
		}, {
			x: 68,
			y: 3.9
		}, {
			x: 0,
			y: 3
		}, {
			x: 100,
			y: 4.1
		}, {
			x: 16,
			y: 5.5
		}, {
			x: 71,
			y: 6.8
		}, {
			x: 100,
			y: 7.9
		}, {
			x: 35,
			y: 8
		}, {
			x: 44,
			y: 6
		}, {
			x: 64,
			y: .7
		}, {
			x: 53,
			y: 3.3
		}, {
			x: 92,
			y: 4.1
		}, {
			x: 43,
			y: 7.3
		}, {
			x: 15,
			y: 7.5
		}, {
			x: 43,
			y: 4.3
		}, {
			x: 90,
			y: 9.9
		}];
		var n = e.series.push(new am4charts.RadarSeries);
		n.bullets.push(new am4charts.CircleBullet), n.strokeOpacity = 0, n.dataFields.valueX = "x", n.dataFields.valueY = "y", n.name = "Series #2", n.sequencedInterpolation = !0, n.sequencedInterpolationDelay = 10, n.data = [{
			x: 178,
			y: 1.3
		}, {
			x: 129,
			y: 3.4
		}, {
			x: 99,
			y: 2.4
		}, {
			x: 80,
			y: 9.9
		}, {
			x: 118,
			y: 9.4
		}, {
			x: 103,
			y: 8.7
		}, {
			x: 91,
			y: 4.2
		}, {
			x: 151,
			y: 1.2
		}, {
			x: 168,
			y: 5.2
		}, {
			x: 168,
			y: 1.6
		}, {
			x: 152,
			y: 1.2
		}, {
			x: 138,
			y: 7.7
		}, {
			x: 107,
			y: 3.9
		}, {
			x: 124,
			y: .7
		}, {
			x: 130,
			y: 2.6
		}, {
			x: 86,
			y: 9.2
		}, {
			x: 169,
			y: 7.5
		}, {
			x: 122,
			y: 9.9
		}, {
			x: 100,
			y: 3.8
		}, {
			x: 172,
			y: 4.1
		}, {
			x: 140,
			y: 7.3
		}, {
			x: 161,
			y: 2.3
		}, {
			x: 141,
			y: .9
		}];
		var o = e.series.push(new am4charts.RadarSeries);
		o.bullets.push(new am4charts.CircleBullet), o.strokeOpacity = 0, o.dataFields.valueX = "x", o.dataFields.valueY = "y", o.name = "Series #3", o.sequencedInterpolation = !0, o.sequencedInterpolationDelay = 10, o.data = [{
			x: 419,
			y: 4.9
		}, {
			x: 417,
			y: 5.5
		}, {
			x: 434,
			y: .1
		}, {
			x: 344,
			y: 2.5
		}, {
			x: 279,
			y: 7.5
		}, {
			x: 307,
			y: 8.4
		}, {
			x: 279,
			y: 9
		}, {
			x: 220,
			y: 8.4
		}, {
			x: 201,
			y: 9.7
		}, {
			x: 288,
			y: 1.2
		}, {
			x: 333,
			y: 7.4
		}, {
			x: 308,
			y: 1.9
		}, {
			x: 330,
			y: 8
		}, {
			x: 408,
			y: 1.7
		}, {
			x: 274,
			y: .8
		}, {
			x: 296,
			y: 3.1
		}, {
			x: 279,
			y: 4.3
		}, {
			x: 379,
			y: 5.6
		}, {
			x: 175,
			y: 6.8
		}], e.legend = new am4charts.Legend, e.cursor = new am4charts.RadarCursor
	}), jQuery("#am-3dpie-chart").length && am4core.ready(function() {
		am4core.useTheme(am4themes_animated);
		var e = am4core.create("am-3dpie-chart", am4charts.PieChart3D);
		e.hiddenState.properties.opacity = 0, e.legend = new am4charts.Legend, e.data = [{
			country: "Lithuania",
			litres: 501.9
		}, {
			country: "Germany",
			litres: 165.8
		}, {
			country: "Australia",
			litres: 139.9
		}, {
			country: "Austria",
			litres: 128.3
		}, {
			country: "UK",
			litres: 99
		}, {
			country: "Belgium",
			litres: 60
		}];
		var t = e.series.push(new am4charts.PieSeries3D);
		t.colors.list = [am4core.color("#827af3"), am4core.color("#fbc647"), am4core.color("#b47af3"), am4core.color("#6ce6f4"), am4core.color("#27b345"), am4core.color("#c8c8c8")], t.dataFields.value = "litres", t.dataFields.category = "country"
	}), jQuery("#am-layeredcolumn-chart").length && am4core.ready(function() {
		am4core.useTheme(am4themes_animated);
		var e = am4core.create("am-layeredcolumn-chart", am4charts.XYChart);
		e.colors.list = [am4core.color("#27b345"), am4core.color("#827af3")], e.numberFormatter.numberFormat = "#.#'%'", e.data = [{
			country: "USA",
			year2004: 3.5,
			year2005: 4.2
		}, {
			country: "UK",
			year2004: 1.7,
			year2005: 3.1
		}, {
			country: "Canada",
			year2004: 2.8,
			year2005: 2.9
		}, {
			country: "Japan",
			year2004: 2.6,
			year2005: 2.3
		}, {
			country: "France",
			year2004: 1.4,
			year2005: 2.1
		}, {
			country: "Brazil",
			year2004: 2.6,
			year2005: 4.9
		}];
		var t = e.xAxes.push(new am4charts.CategoryAxis);
		t.dataFields.category = "country", t.renderer.grid.template.location = 0, t.renderer.minGridDistance = 30;
		var a = e.yAxes.push(new am4charts.ValueAxis);
		a.title.text = "GDP growth rate", a.title.fontWeight = 800;
		var n = e.series.push(new am4charts.ColumnSeries);
		n.dataFields.valueY = "year2004", n.dataFields.categoryX = "country", n.clustered = !1, n.tooltipText = "GDP grow in {categoryX} (2004): [bold]{valueY}[/]";
		var o = e.series.push(new am4charts.ColumnSeries);
		o.dataFields.valueY = "year2005", o.dataFields.categoryX = "country", o.clustered = !1, o.columns.template.width = am4core.percent(50), o.tooltipText = "GDP grow in {categoryX} (2005): [bold]{valueY}[/]", e.cursor = new am4charts.XYCursor, e.cursor.lineX.disabled = !0, e.cursor.lineY.disabled = !0
	}), jQuery("#morris-line-chart").length && new Morris.Line({
		element: "morris-line-chart",
		data: [{
			year: "2008",
			value: 20
		}, {
			year: "2009",
			value: 10
		}, {
			year: "2010",
			value: 5
		}],
		xkey: "year",
		ykeys: ["value"],
		labels: ["Value"],
		lineColors: ["#827af3"]
	}), jQuery("#morris-bar-chart").length && Morris.Bar({
		element: "morris-bar-chart",
		data: [{
			x: "2011 Q1",
			y: 3,
			z: 2
		}, {
			x: "2011 Q2",
			y: 2,
			z: null,
			a: 1
		}, {
			x: "2011 Q3",
			y: 0,
			z: 2,
			a: 4
		}, {
			x: "2011 Q4",
			y: 2,
			z: 4
		}],
		xkey: "x",
		ykeys: ["y", "z", "a"],
		labels: ["Y", "Z", "A"],
		barColors: ["#827af3", "#27b345", "#b47af3"],
		hoverCallback: function(e, t, a, n) {
			return ""
		}
	}).on("click", function(e, t) {
		console.log(e, t)
	}), jQuery("#morris-area-chart").length) var area = new Morris.Area({
	element: "morris-area-chart",
	resize: !0,
	data: [{
		y: "2011 Q1",
		item1: 2666,
		item2: 2666
	}, {
		y: "2011 Q2",
		item1: 2778,
		item2: 2294
	}, {
		y: "2011 Q3",
		item1: 4912,
		item2: 1969
	}, {
		y: "2011 Q4",
		item1: 3767,
		item2: 3597
	}, {
		y: "2012 Q1",
		item1: 6810,
		item2: 1914
	}, {
		y: "2012 Q2",
		item1: 5670,
		item2: 4293
	}],
	xkey: "y",
	ykeys: ["item1", "item2"],
	labels: ["Item 1", "Item 2"],
	lineColors: ["#827af3", "#b47af3"],
	hoverCallback: function(e, t, a, n) {
		return ""
	}
});
if (jQuery("#morris-donut-chart").length) var donut = new Morris.Donut({
	element: "morris-donut-chart",
	resize: !0,
	colors: ["#827af3", "#b47af3", "#27b345"],
	data: [{
		label: "Download Sales",
		value: 30
	}, {
		label: "In-Store Sales",
		value: 12
	}, {
		label: "Mail-Order Sales",
		value: 20
	}],
	hideHover: "auto"
});
if (jQuery("#high-basicline-chart").length && Highcharts.chart("high-basicline-chart", {
		chart: {
			type: "spline",
			inverted: !0
		},
		title: {
			text: "Atmosphere Temperature by Altitude"
		},
		subtitle: {
			text: "According to the Standard Atmosphere Model"
		},
		xAxis: {
			reversed: !1,
			title: {
				enabled: !0,
				text: "Altitude"
			},
			labels: {
				format: "{value} km"
			},
			maxPadding: .05,
			showLastLabel: !0
		},
		yAxis: {
			title: {
				text: "Temperature"
			},
			labels: {
				format: "{value}°"
			},
			lineWidth: 2
		},
		legend: {
			enabled: !1
		},
		tooltip: {
			headerFormat: "<b>{series.name}</b><br/>",
			pointFormat: "{point.x} km: {point.y}°C"
		},
		plotOptions: {
			spline: {
				marker: {
					enable: !1
				}
			}
		},
		series: [{
			name: "Temperature",
			color: "#827af3",
			data: [
				[0, 15],
				[10, -50],
				[20, -56.5],
				[30, -46.5],
				[40, -22.1],
				[50, -2.5],
				[60, -27.7],
				[70, -55.7],
				[80, -76.5]
			]
		}]
	}), jQuery("#high-area-chart").length && Highcharts.chart("high-area-chart", {
		chart: {
			type: "areaspline"
		},
		title: {
			text: "Average fruit consumption during one week"
		},
		legend: {
			layout: "vertical",
			align: "left",
			verticalAlign: "top",
			x: 150,
			y: 100,
			floating: !0,
			borderWidth: 1,
			backgroundColor: Highcharts.defaultOptions.legend.backgroundColor || "#FFFFFF"
		},
		xAxis: {
			categories: ["Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"],
			plotBands: [{
				from: 4.5,
				to: 6.5,
				color: "rgba(68, 170, 213, .2)"
			}]
		},
		yAxis: {
			title: {
				text: "Fruit units"
			}
		},
		tooltip: {
			shared: !0,
			valueSuffix: " units"
		},
		credits: {
			enabled: !1
		},
		plotOptions: {
			areaspline: {
				fillOpacity: .5
			}
		},
		series: [{
			name: "John",
			color: "#827af3",
			data: [3, 4, 3, 5, 4, 10, 12]
		}, {
			name: "Jane",
			color: "#27b345",
			data: [1, 3, 4, 3, 3, 5, 4]
		}]
	}), jQuery("#high-columnndbar-chart").length && Highcharts.chart("high-columnndbar-chart", {
		chart: {
			type: "bar"
		},
		title: {
			text: "Stacked bar chart"
		},
		xAxis: {
			categories: ["Apples", "Oranges", "Pears", "Grapes", "Bananas"]
		},
		yAxis: {
			min: 0,
			title: {
				text: "Total fruit consumption"
			}
		},
		legend: {
			reversed: !0
		},
		plotOptions: {
			series: {
				stacking: "normal"
			}
		},
		series: [{
			name: "John",
			color: "#827af3",
			data: [5, 3, 4, 7, 2]
		}, {
			name: "Jane",
			color: "#b47af3",
			data: [2, 2, 3, 2, 1]
		}, {
			name: "Joe",
			color: "#27b345",
			data: [3, 4, 4, 2, 5]
		}]
	}), jQuery("#high-pie-chart").length && Highcharts.chart("high-pie-chart", {
		chart: {
			plotBackgroundColor: null,
			plotBorderWidth: null,
			plotShadow: !1,
			type: "pie"
		},
		colorAxis: {},
		title: {
			text: "Browser market shares in January, 2018"
		},
		tooltip: {
			pointFormat: "{series.name}: <b>{point.percentage:.1f}%</b>"
		},
		plotOptions: {
			pie: {
				allowPointSelect: !0,
				cursor: "pointer",
				dataLabels: {
					enabled: !0,
					format: "<b>{point.name}</b>: {point.percentage:.1f} %"
				}
			}
		},
		series: [{
			name: "Brands",
			colorByPoint: !0,
			data: [{
				name: "Chrome",
				y: 61.41,
				sliced: !0,
				selected: !0,
				color: "#827af3"
			}, {
				name: "Internet Explorer",
				y: 11.84,
				color: "#b47af3"
			}, {
				name: "Firefox",
				y: 10.85,
				color: "#c8c8c8"
			}, {
				name: "Edge",
				y: 4.67,
				color: "#6ce6f4"
			}, {
				name: "Other",
				y: 2.61
			}]
		}]
	}), jQuery("#high-scatterplot-chart").length && Highcharts.chart("high-scatterplot-chart", {
		chart: {
			type: "scatter",
			zoomType: "xy"
		},
		accessibility: {
			description: "A scatter plot compares the height and weight of 507 individuals by gender. Height in centimeters is plotted on the X-axis and weight in kilograms is plotted on the Y-axis. The chart is interactive, and each data point can be hovered over to expose the height and weight data for each individual. The scatter plot is fairly evenly divided by gender with females dominating the left-hand side of the chart and males dominating the right-hand side. The height data for females ranges from 147.2 to 182.9 centimeters with the greatest concentration between 160 and 165 centimeters. The weight data for females ranges from 42 to 105.2 kilograms with the greatest concentration at around 60 kilograms. The height data for males ranges from 157.2 to 198.1 centimeters with the greatest concentration between 175 and 180 centimeters. The weight data for males ranges from 53.9 to 116.4 kilograms with the greatest concentration at around 80 kilograms."
		},
		title: {
			text: "Height Versus Weight of 507 Individuals by Gender"
		},
		subtitle: {
			text: "Source: Heinz  2003"
		},
		xAxis: {
			title: {
				enabled: !0,
				text: "Height (cm)"
			},
			startOnTick: !0,
			endOnTick: !0,
			showLastLabel: !0
		},
		yAxis: {
			title: {
				text: "Weight (kg)"
			}
		},
		legend: {
			layout: "vertical",
			align: "left",
			verticalAlign: "top",
			x: 100,
			y: 70,
			floating: !0,
			backgroundColor: Highcharts.defaultOptions.chart.backgroundColor,
			borderWidth: 1
		},
		plotOptions: {
			scatter: {
				marker: {
					radius: 5,
					states: {
						hover: {
							enabled: !0,
							lineColor: "rgb(100,100,100)"
						}
					}
				},
				states: {
					hover: {
						marker: {
							enabled: !1
						}
					}
				},
				tooltip: {
					headerFormat: "<b>{series.name}</b><br>",
					pointFormat: "{point.x} cm, {point.y} kg"
				}
			}
		},
		series: [{
			name: "Female",
			color: "rgba(223, 83, 83, .5)",
			data: [
				[161.2, 51.6],
				[167.5, 59],
				[159.5, 49.2],
				[157, 63],
				[155.8, 53.6],
				[170, 59],
				[159.1, 47.6],
				[166, 69.8],
				[176.2, 66.8],
				[160.2, 75.2],
				[172.7, 62],
				[155, 49.2],
				[156.5, 67.2],
				[164, 53.8],
				[160.9, 54.4]
			],
			color: "#827af3"
		}, {
			name: "Male",
			color: "rgba(119, 152, 191, .5)",
			data: [
				[174, 65.6],
				[175.3, 71.8],
				[193.5, 80.7],
				[186.5, 72.6],
				[187.2, 78.8],
				[181.5, 74.8],
				[184, 86.4],
				[184.5, 78.4],
				[175, 62],
				[184, 81.6],
				[180.1, 93],
				[175.5, 80.9],
				[180.6, 72.7],
				[184.4, 68],
				[175.5, 70.9],
				[180.3, 83.2],
				[180.3, 83.2]
			],
			color: "#b47af3"
		}]
	}), jQuery("#high-linendcolumn-chart").length && Highcharts.chart("high-linendcolumn-chart", {
		chart: {
			zoomType: "xy"
		},
		title: {
			text: "Average Monthly Temperature and Rainfall in Tokyo"
		},
		subtitle: {
			text: "Source: WorldClimate.com"
		},
		xAxis: [{
			categories: ["Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"],
			crosshair: !0
		}],
		yAxis: [{
			labels: {
				format: "{value}°C",
				style: {
					color: Highcharts.getOptions().colors[1]
				}
			},
			title: {
				text: "Temperature",
				style: {
					color: Highcharts.getOptions().colors[1]
				}
			}
		}, {
			title: {
				text: "Rainfall",
				style: {
					color: Highcharts.getOptions().colors[0]
				}
			},
			labels: {
				format: "{value} mm",
				style: {
					color: Highcharts.getOptions().colors[0]
				}
			},
			opposite: !0
		}],
		tooltip: {
			shared: !0
		},
		legend: {
			layout: "vertical",
			align: "left",
			x: 120,
			verticalAlign: "top",
			y: 100,
			floating: !0,
			backgroundColor: Highcharts.defaultOptions.legend.backgroundColor || "rgba(255,255,255,0.25)"
		},
		series: [{
			name: "Rainfall",
			type: "column",
			yAxis: 1,
			data: [49.9, 71.5, 106.4, 129.2, 144, 176, 135.6, 148.5, 216.4, 194.1, 95.6, 54.4],
			color: "#fbc647",
			tooltip: {
				valueSuffix: " mm"
			}
		}, {
			name: "Temperature",
			type: "spline",
			data: [7, 6.9, 9.5, 14.5, 18.2, 21.5, 25.2, 26.5, 23.3, 18.3, 13.9, 9.6],
			color: "#827af3",
			tooltip: {
				valueSuffix: "°C"
			}
		}]
	}), jQuery("#high-dynamic-chart").length && Highcharts.chart("high-dynamic-chart", {
		chart: {
			type: "spline",
			animation: Highcharts.svg,
			marginRight: 10,
			events: {
				load: function() {
					var e = this.series[0];
					setInterval(function() {
						var t = (new Date).getTime(),
							a = Math.random();
						e.addPoint([t, a], !0, !0)
					}, 1e3)
				}
			}
		},
		time: {
			useUTC: !1
		},
		title: {
			text: "Live random data"
		},
		accessibility: {
			announceNewData: {
				enabled: !0,
				minAnnounceInterval: 15e3,
				announcementFormatter: function(e, t, a) {
					return !!a && "New point added. Value: " + a.y
				}
			}
		},
		xAxis: {
			type: "datetime",
			tickPixelInterval: 150
		},
		yAxis: {
			title: {
				text: "Value"
			},
			plotLines: [{
				value: 0,
				width: 1,
				color: "#808080"
			}]
		},
		tooltip: {
			headerFormat: "<b>{series.name}</b><br/>",
			pointFormat: "{point.x:%Y-%m-%d %H:%M:%S}<br/>{point.y:.2f}"
		},
		legend: {
			enabled: !1
		},
		exporting: {
			enabled: !1
		},
		series: [{
			name: "Random data",
			color: "#827af3",
			data: function() {
				var e, t = [],
					a = (new Date).getTime();
				for (e = -19; e <= 0; e += 1) t.push({
					x: a + 1e3 * e,
					y: Math.random()
				});
				return t
			}()
		}]
	}), jQuery("#high-3d-chart").length) {
	var chart = new Highcharts.Chart({
		chart: {
			renderTo: "high-3d-chart",
			type: "column",
			options3d: {
				enabled: !0,
				alpha: 15,
				beta: 15,
				depth: 50,
				viewDistance: 25
			}
		},
		title: {
			text: "Chart rotation demo"
		},
		subtitle: {
			text: "Test options by dragging the sliders below"
		},
		plotOptions: {
			column: {
				depth: 25
			}
		},
		series: [{
			data: [29.9, 71.5, 106.4, 129.2, 144, 176, 135.6, 148.5, 216.4, 194.1, 95.6, 54.4],
			color: "#827af3"
		}]
	});

	function showValues() {
		$("#alpha-value").html(chart.options.chart.options3d.alpha), $("#beta-value").html(chart.options.chart.options3d.beta), $("#depth-value").html(chart.options.chart.options3d.depth)
	}
	$("#sliders input").on("input change", function() {
		chart.options.chart.options3d[this.id] = parseFloat(this.value), showValues(), chart.redraw(!1)
	}), showValues()
}
if (jQuery("#high-gauges-chart").length && Highcharts.chart("high-gauges-chart", {
		chart: {
			type: "gauge",
			plotBackgroundColor: null,
			plotBackgroundImage: null,
			plotBorderWidth: 0,
			plotShadow: !1
		},
		title: {
			text: "Speedometer"
		},
		pane: {
			startAngle: -150,
			endAngle: 150,
			background: [{
				backgroundColor: {
					linearGradient: {
						x1: 0,
						y1: 0,
						x2: 0,
						y2: 1
					},
					stops: [
						[0, "#FFF"],
						[1, "#333"]
					]
				},
				borderWidth: 0,
				outerRadius: "109%"
			}, {
				backgroundColor: {
					linearGradient: {
						x1: 0,
						y1: 0,
						x2: 0,
						y2: 1
					},
					stops: [
						[0, "#333"],
						[1, "#FFF"]
					]
				},
				borderWidth: 1,
				outerRadius: "107%"
			}, {}, {
				backgroundColor: "#DDD",
				borderWidth: 0,
				outerRadius: "105%",
				innerRadius: "103%"
			}]
		},
		yAxis: {
			min: 0,
			max: 200,
			minorTickInterval: "auto",
			minorTickWidth: 1,
			minorTickLength: 10,
			minorTickPosition: "inside",
			minorTickColor: "#666",
			tickPixelInterval: 30,
			tickWidth: 2,
			tickPosition: "inside",
			tickLength: 10,
			tickColor: "#666",
			labels: {
				step: 2,
				rotation: "auto"
			},
			title: {
				text: "km/h"
			},
			plotBands: [{
				from: 0,
				to: 120,
				color: "#55BF3B"
			}, {
				from: 120,
				to: 160,
				color: "#DDDF0D"
			}, {
				from: 160,
				to: 200,
				color: "#DF5353"
			}]
		},
		series: [{
			name: "Speed",
			data: [80],
			tooltip: {
				valueSuffix: " km/h"
			}
		}]
	}, function(e) {
		e.renderer.forExport || setInterval(function() {
			var t, a = e.series[0].points[0],
				n = Math.round(20 * (Math.random() - .5));
			((t = a.y + n) < 0 || t > 200) && (t = a.y - n), a.update(t)
		}, 3e3)
	}), jQuery("#high-barwithnagative-chart").length) {
	var categories = ["0-4", "5-9", "10-14", "15-19", "20-24", "25-29", "30-34", "35-39", "40-44", "45-49", "50-54", "55-59", "60-64", "65-69", "70-74", "75-79", "80-84", "85-89", "90-94", "95-99", "100 + "];
	Highcharts.chart("high-barwithnagative-chart", {
		chart: {
			type: "bar"
		},
		title: {
			text: "Population pyramid for Germany, 2018"
		},
		subtitle: {
			text: 'Source: <a href="http://populationpyramid.net/germany/2018/">Population Pyramids of the World from 1950 to 2100</a>'
		},
		accessibility: {
			point: {
				descriptionFormatter: function(e) {
					return e.index + 1 + ", Age " + e.category + ", " + Math.abs(e.y) + "%. " + e.series.name + "."
				}
			}
		},
		xAxis: [{
			categories: categories,
			reversed: !1,
			labels: {
				step: 1
			},
			accessibility: {
				description: "Age (male)"
			}
		}, {
			opposite: !0,
			reversed: !1,
			categories: categories,
			linkedTo: 0,
			labels: {
				step: 1
			},
			accessibility: {
				description: "Age (female)"
			}
		}],
		yAxis: {
			title: {
				text: null
			},
			labels: {
				formatter: function() {
					return Math.abs(this.value) + "%"
				}
			},
			accessibility: {
				description: "Percentage population",
				rangeDescription: "Range: 0 to 5%"
			}
		},
		plotOptions: {
			series: {
				stacking: "normal"
			}
		},
		tooltip: {
			formatter: function() {
				return "<b>" + this.series.name + ", age " + this.point.category + "</b><br/>Population: " + Highcharts.numberFormat(Math.abs(this.point.y), 1) + "%"
			}
		},
		series: [{
			name: "Male",
			data: [-2.2, -2.1, -2.2, -2.4, -2.7, -3, -3.3, -3.2, -2.9, -3.5, -4.4, -4.1, -0],
			color: "#827af3"
		}, {
			name: "Female",
			data: [2.1, 2, 2.1, 2.3, 2.6, 2.9, 3.2, 3.1, 2.9, 3.4, 0],
			color: "#27b345"
		}]
	})
}
if (jQuery("#home-chart-01").length) {
	options = {
		series: [{
			name: "Desktops",
			data: [5, 10, 8, 15]
		}],
		chart: {
			height: 150,
			type: "line",
			zoom: {
				enabled: !1
			}
		},
		colors: ["#827af3"],
		dataLabels: {
			enabled: !1
		},
		stroke: {
			curve: "straight"
		},
		grid: {
			row: {
				colors: ["#f3f3f3", "transparent"],
				opacity: .5
			}
		},
		xaxis: {
			categories: ["Jan", "Feb", "Mar", "Apr"]
		}
	};
	(chart = new ApexCharts(document.querySelector("#home-chart-01"), options)).render()
}
if (jQuery("#home-chart-02").length) {
	options = {
		series: [{
			name: "Net Profit",
			data: [44, 55, 57, 56, 61, 58, 63, 60, 66]
		}, {
			name: "Revenue",
			data: [76, 85, 101, 98, 87, 105, 91, 114, 94]
		}],
		chart: {
			type: "bar",
			height: 350
		},
		colors: ["#827af3", "#6ce6f4"],
		plotOptions: {
			bar: {
				horizontal: !1,
				columnWidth: "55%",
				endingShape: "rounded"
			}
		},
		dataLabels: {
			enabled: !1
		},
		stroke: {
			show: !0,
			width: 2,
			colors: ["transparent"]
		},
		xaxis: {
			categories: ["Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct"]
		},
		yaxis: {},
		fill: {
			opacity: 1
		},
		tooltip: {
			y: {
				formatter: function(e) {
					return "$ " + e + " thousands"
				}
			}
		}
	};
	(chart = new ApexCharts(document.querySelector("#home-chart-02"), options)).render()
}
if (jQuery("#home-chart-03").length) {
	options = {
		series: [44, 55, 13, 33],
		chart: {
			width: 380,
			height: 180,
			type: "donut"
		},
		dataLabels: {
			enabled: !1
		},
		colors: ["#827af3", "#6ce6f4", "#a09e9e", "#fbc647"],
		responsive: [{
			breakpoint: 480,
			options: {
				chart: {
					width: 200
				},
				legend: {
					show: !1
				}
			}
		}],
		legend: {
			position: "right",
			offsetY: 0,
			height: 150
		}
	};

	function appendData() {
		var e = chart.w.globals.series.slice();
		return e.push(Math.floor(100 * Math.random()) + 1), e
	}

	function removeData() {
		var e = chart.w.globals.series.slice();
		return e.pop(), e
	}

	function randomize() {
		return chart.w.globals.series.map(function() {
			return Math.floor(100 * Math.random()) + 1
		})
	}

	function reset() {
		return options.series
	}(chart = new ApexCharts(document.querySelector("#home-chart-03"), options)).render()
}
jQuery("#home-chart-04").length && am4core.ready(function() {
	am4core.useTheme(am4themes_animated);
	var e = "M9,0C4.029,0,0,4.029,0,9s4.029,9,9,9s9-4.029,9-9S13.971,0,9,0z M9,15.93 c-3.83,0-6.93-3.1-6.93-6.93S5.17,2.07,9,2.07s6.93,3.1,6.93,6.93S12.83,15.93,9,15.93 M12.5,9c0,1.933-1.567,3.5-3.5,3.5S5.5,10.933,5.5,9S7.067,5.5,9,5.5 S12.5,7.067,12.5,9z",
		t = am4core.create("home-chart-04", am4maps.MapChart),
		a = new am4core.InterfaceColorSet;
	t.geodata = am4geodata_worldLow, t.projection = new am4maps.projections.Mercator, t.zoomControl = new am4maps.ZoomControl, t.homeZoomLevel = 2.5, t.homeGeoPoint = {
		latitude: 51,
		longitude: -23
	};
	var n = t.series.push(new am4maps.MapPolygonSeries);
	n.exclude = ["AQ"], n.useGeodata = !0, n.mapPolygons.template.nonScalingStroke = !0;
	var o = t.series.push(new am4maps.MapImageSeries),
		r = o.mapImages.template;
	r.tooltipText = "{title}", r.nonScaling = !0;
	var i = r.createChild(am4core.Sprite);
	i.path = e, i.horizontalCenter = "middle", i.verticalCenter = "middle", i.scale = .7, i.fill = a.getFor("alternativeBackground"), r.propertyFields.latitude = "latitude", r.propertyFields.longitude = "longitude", o.data = [{
		id: "london",
		svgPath: e,
		title: "London",
		latitude: 51.5002,
		longitude: -.1262,
		scale: 1
	}, {
		svgPath: e,
		title: "Brussels",
		latitude: 50.8371,
		longitude: 4.3676,
		scale: .5
	}, {
		svgPath: e,
		title: "Prague",
		latitude: 50.0878,
		longitude: 14.4205,
		scale: .5
	}, {
		svgPath: e,
		title: "Bratislava",
		latitude: 48.2116,
		longitude: 17.1547,
		scale: .5
	}, {
		svgPath: e,
		title: "Kiev",
		latitude: 50.4422,
		longitude: 30.5367,
		scale: .5
	}, {
		svgPath: e,
		title: "Paris",
		latitude: 48.8567,
		longitude: 2.351,
		scale: .5
	}, {
		svgPath: e,
		title: "New York",
		latitude: 40.43,
		longitude: -74,
		scale: .5
	}];
	var c = t.series.push(new am4maps.MapLineSeries);
	c.dataFields.multiGeoLine = "multiGeoLine";
	var s = c.mapLines.template;
	s.nonScalingStroke = !0, s.arrow.nonScaling = !0, s.arrow.width = 4, s.arrow.height = 6, s.stroke = a.getFor("alternativeBackground"), s.fill = a.getFor("alternativeBackground"), s.line.strokeOpacity = .4, c.data = [{
		multiGeoLine: [
			[{
				latitude: 51.5002,
				longitude: -.1262
			}, {
				latitude: 50.4422,
				longitude: 30.5367
			}]
		]
	}, {
		multiGeoLine: [
			[{
				latitude: 51.5002,
				longitude: -.1262
			}, {
				latitude: 40.43,
				longitude: -74
			}]
		]
	}, {
		multiGeoLine: [
			[{
				latitude: 51.5002,
				longitude: -.1262
			}, {
				latitude: 64.1353,
				longitude: -21.8952
			}]
		]
	}, {
		multiGeoLine: [
			[{
				latitude: 51.5002,
				longitude: -.1262
			}, {
				latitude: 37.9792,
				longitude: 23.7166
			}]
		]
	}, {
		multiGeoLine: [
			[{
				latitude: 51.5002,
				longitude: -.1262
			}, {
				latitude: 38.7072,
				longitude: -9.1355
			}]
		]
	}, {
		multiGeoLine: [
			[{
				latitude: 51.5002,
				longitude: -.1262
			}, {
				latitude: 55.7558,
				longitude: 37.6176
			}]
		]
	}, {
		multiGeoLine: [
			[{
				latitude: 51.5002,
				longitude: -.1262
			}, {
				latitude: 44.8048,
				longitude: 20.4781
			}]
		]
	}, {
		multiGeoLine: [
			[{
				latitude: 51.5002,
				longitude: -.1262
			}, {
				latitude: 48.2116,
				longitude: 17.1547
			}]
		]
	}, {
		multiGeoLine: [
			[{
				latitude: 51.5002,
				longitude: -.1262
			}, {
				latitude: 46.0514,
				longitude: 14.506
			}]
		]
	}, {
		multiGeoLine: [
			[{
				latitude: 51.5002,
				longitude: -.1262
			}, {
				latitude: 40.4167,
				longitude: -3.7033
			}]
		]
	}, {
		multiGeoLine: [
			[{
				latitude: 51.5002,
				longitude: -.1262
			}, {
				latitude: 59.3328,
				longitude: 18.0645
			}]
		]
	}, {
		multiGeoLine: [
			[{
				latitude: 51.5002,
				longitude: -.1262
			}, {
				latitude: 46.948,
				longitude: 7.4481
			}]
		]
	}]
}), jQuery("#home-chart-05").length && am4core.ready(function() {
	am4core.useTheme(am4themes_animated);
	var e = am4core.create("home-chart-05", am4charts.XYChart);
	e.colors.list = [am4core.color("#827af3")];
	for (var t = [], a = 120, n = ["ra", "De", "Ca", "Ja", "Ri", "An"], o = 0; o < n.length; o++) a += Math.round((Math.random() < .5 ? 1 : -1) * Math.random() * 5), t.push({
		category: n[o],
		value: a
	});
	e.data = t;
	var r = e.xAxes.push(new am4charts.CategoryAxis);
	r.renderer.grid.template.location = 0, r.dataFields.category = "category", r.renderer.minGridDistance = 15, r.renderer.grid.template.location = .5, r.renderer.grid.template.strokeDasharray = "1,3", r.renderer.labels.template.rotation = -90, r.renderer.labels.template.horizontalCenter = "left", r.renderer.labels.template.location = .5, r.renderer.labels.template.adapter.add("dx", function(e, t) {
		return -t.maxRight / 2
	});
	var i = e.yAxes.push(new am4charts.ValueAxis);
	i.tooltip.disabled = !0, i.renderer.ticks.template.disabled = !0, i.renderer.axisFills.template.disabled = !0;
	var c = e.series.push(new am4charts.ColumnSeries);
	c.dataFields.categoryX = "category", c.dataFields.valueY = "value", c.tooltipText = "{valueY.value}", c.sequencedInterpolation = !0, c.fillOpacity = 0, c.strokeOpacity = 1, c.strokeDashArray = "1,3", c.columns.template.width = .01, c.tooltip.pointerOrientation = "horizontal";
	c.bullets.create(am4charts.CircleBullet);
	e.cursor = new am4charts.XYCursor
}), jQuery("#home-chart-06").length && am4core.ready(function() {
	am4core.useTheme(am4themes_animated);
	var e = am4core.create("home-chart-06", am4charts.XYChart);
	e.colors.list = [am4core.color("#827af3"), am4core.color("#6ce6f4")];
	for (var t = [], a = 100, n = 120, o = ["Rai", "Dem", "Caro", "Jac", "Rich", "Ano", "Amd", "Idal", "Joi", "Mar", "Cur", "Shl", "Meg"], r = 0; r < o.length; r++) n = (a += Math.round((Math.random() < .5 ? 1 : -1) * Math.random() * 5)) + Math.round(10 * Math.random()) + 3, t.push({
		category: o[r],
		open: a,
		close: n
	});
	e.data = t;
	var i = e.xAxes.push(new am4charts.CategoryAxis);
	i.renderer.grid.template.location = 0, i.dataFields.category = "category", i.renderer.minGridDistance = 15, i.renderer.grid.template.location = .5, i.renderer.grid.template.strokeDasharray = "1,3", i.renderer.labels.template.rotation = -90, i.renderer.labels.template.horizontalCenter = "left", i.renderer.labels.template.location = .5, i.renderer.inside = !0, i.renderer.labels.template.adapter.add("dx", function(e, t) {
		return -t.maxRight / 2
	});
	var c = e.yAxes.push(new am4charts.ValueAxis);
	c.tooltip.disabled = !0, c.renderer.ticks.template.disabled = !0, c.renderer.axisFills.template.disabled = !0;
	var s = e.series.push(new am4charts.ColumnSeries);
	s.dataFields.categoryX = "category", s.dataFields.openValueY = "open", s.dataFields.valueY = "close", s.tooltipText = "open: {openValueY.value} close: {valueY.value}", s.sequencedInterpolation = !0, s.fillOpacity = 0, s.strokeOpacity = 1, s.columns.template.width = .01, s.tooltip.pointerOrientation = "horizontal", s.bullets.create(am4charts.CircleBullet).locationY = 1;
	var l = s.bullets.create(am4charts.CircleBullet);
	l.fill = e.colors.getIndex(4), l.stroke = l.fill, e.cursor = new am4charts.XYCursor
}), jQuery("#home-chart-07").length && am4core.ready(function() {
	am4core.useTheme(am4themes_animated);
	var e = am4core.create("home-chart-07", am4charts.PieChart);
	e.data = [{
		country: "Lithuania",
		litres: 501.9
	}, {
		country: "Czech Republic",
		litres: 301.9
	}, {
		country: "Ireland",
		litres: 201.1
	}, {
		country: "Germany",
		litres: 165.8
	}, {
		country: "Australia",
		litres: 139.9
	}, {
		country: "The Netherlands",
		litres: 50
	}];
	var t = e.series.push(new am4charts.PieSeries);
	t.dataFields.value = "litres", t.dataFields.category = "country", t.innerRadius = am4core.percent(50), t.ticks.template.disabled = !0, t.labels.template.disabled = !0;
	var a = new am4core.RadialGradientModifier;
	a.brightnesses.push(-.8, -.8, -.5, 0, -.5), t.slices.template.fillModifier = a, t.slices.template.strokeModifier = a, t.slices.template.strokeOpacity = .4, t.slices.template.strokeWidth = 0
});
var animationData = {
		v: "5.5.2",
		fr: 60,
		ip: 53,
		op: 125,
		w: 192,
		h: 192,
		nm: "Comp 1",
		ddd: 0,
		assets: [],
		layers: [{
			ddd: 0,
			ind: 1,
			ty: 4,
			nm: "Bell-ringing Outlines",
			sr: 1,
			ks: {
				o: {
					a: 0,
					k: 100,
					ix: 11
				},
				r: {
					a: 0,
					k: 0,
					ix: 10
				},
				p: {
					a: 1,
					k: [{
						i: {
							x: .667,
							y: .892
						},
						o: {
							x: .333,
							y: 0
						},
						t: 53,
						s: [96, 107, 0],
						to: [0, -.569, 0],
						ti: [0, .799, 0]
					}, {
						i: {
							x: .667,
							y: 1
						},
						o: {
							x: .311,
							y: 1
						},
						t: 59,
						s: [96, 87.729, 0],
						to: [0, -1.733, 0],
						ti: [0, -.653, 0]
					}, {
						t: 119,
						s: [96, 107, 0]
					}],
					ix: 2
				},
				a: {
					a: 0,
					k: [12, 12, 0],
					ix: 1
				},
				s: {
					a: 0,
					k: [583.333, 583.333, 100],
					ix: 6
				}
			},
			ao: 0,
			ef: [{
				ty: 5,
				nm: "CC Bend It",
				np: 7,
				mn: "CC Bend It",
				ix: 1,
				en: 1,
				ef: [{
					ty: 0,
					nm: "Bend",
					mn: "CC Bend It-0001",
					ix: 1,
					v: {
						a: 1,
						k: [{
							i: {
								x: [.667],
								y: [1]
							},
							o: {
								x: [.167],
								y: [.167]
							},
							t: 59,
							s: [0]
						}, {
							i: {
								x: [.667],
								y: [1]
							},
							o: {
								x: [.333],
								y: [0]
							},
							t: 70,
							s: [7]
						}, {
							i: {
								x: [.667],
								y: [1]
							},
							o: {
								x: [.333],
								y: [0]
							},
							t: 75,
							s: [-4]
						}, {
							i: {
								x: [.667],
								y: [1]
							},
							o: {
								x: [.333],
								y: [0]
							},
							t: 85,
							s: [2]
						}, {
							i: {
								x: [.667],
								y: [1]
							},
							o: {
								x: [.333],
								y: [0]
							},
							t: 93,
							s: [-1]
						}, {
							t: 98,
							s: [0]
						}],
						ix: 1
					}
				}, {
					ty: 3,
					nm: "Start",
					mn: "CC Bend It-0002",
					ix: 2,
					v: {
						a: 0,
						k: [95.5, -19],
						ix: 2
					}
				}, {
					ty: 3,
					nm: "End",
					mn: "CC Bend It-0003",
					ix: 3,
					v: {
						a: 0,
						k: [93, 213],
						ix: 3
					}
				}, {
					ty: 7,
					nm: "Render Prestart",
					mn: "CC Bend It-0004",
					ix: 4,
					v: {
						a: 0,
						k: 3,
						ix: 4
					}
				}, {
					ty: 7,
					nm: "Distort",
					mn: "CC Bend It-0005",
					ix: 5,
					v: {
						a: 0,
						k: 1,
						ix: 5
					}
				}]
			}],
			shapes: [{
				ty: "gr",
				it: [{
					ind: 0,
					ty: "sh",
					ix: 1,
					ks: {
						a: 0,
						k: {
							i: [
								[0, 0],
								[.956, .553],
								[.174, .302]
							],
							o: [
								[-.555, .955],
								[-.301, -.175],
								[0, 0]
							],
							v: [
								[1.73, -.64],
								[-1.004, .087],
								[-1.73, -.64]
							],
							c: !1
						},
						ix: 2
					},
					nm: "Path 1",
					mn: "ADBE Vector Shape - Group",
					hd: !1
				}, {
					ty: "st",
					c: {
						a: 0,
						k: [0, 0, 0, 1],
						ix: 3
					},
					o: {
						a: 0,
						k: 100,
						ix: 4
					},
					w: {
						a: 0,
						k: 2,
						ix: 5
					},
					lc: 2,
					lj: 2,
					bm: 0,
					nm: "Stroke 1",
					mn: "ADBE Vector Graphic - Stroke",
					hd: !1
				}, {
					ty: "tr",
					p: {
						a: 1,
						k: [{
							i: {
								x: .667,
								y: 1
							},
							o: {
								x: .333,
								y: 0
							},
							t: 59,
							s: [12, 21.64],
							to: [.25, .25],
							ti: [-.333, -.083]
						}, {
							i: {
								x: .667,
								y: .629
							},
							o: {
								x: .333,
								y: 0
							},
							t: 68,
							s: [13.5, 23.14],
							to: [.217, .054],
							ti: [-.099, .302]
						}, {
							i: {
								x: .667,
								y: 1
							},
							o: {
								x: .333,
								y: .79
							},
							t: 73,
							s: [14.42, 22.2],
							to: [.053, -.162],
							ti: [.379, .204]
						}, {
							i: {
								x: .667,
								y: .211
							},
							o: {
								x: .333,
								y: 0
							},
							t: 77,
							s: [14, 22.14],
							to: [-.558, -.301],
							ti: [2.437, .178]
						}, {
							i: {
								x: .667,
								y: 1
							},
							o: {
								x: .333,
								y: .369
							},
							t: 83,
							s: [15.844, 21.405],
							to: [-2.291, -.167],
							ti: [-.04, 0]
						}, {
							i: {
								x: .667,
								y: .579
							},
							o: {
								x: .333,
								y: 0
							},
							t: 91,
							s: [6, 21.14],
							to: [.042, 0],
							ti: [-2.606, -.221]
						}, {
							i: {
								x: .667,
								y: 1
							},
							o: {
								x: .333,
								y: .5
							},
							t: 95,
							s: [12.257, 21.552],
							to: [2.561, .217],
							ti: [-.124, -.124]
						}, {
							i: {
								x: .667,
								y: .544
							},
							o: {
								x: .333,
								y: 0
							},
							t: 99,
							s: [17.5, 21.14],
							to: [.148, .148],
							ti: [2.582, -.083]
						}, {
							i: {
								x: .667,
								y: 1
							},
							o: {
								x: .333,
								y: .691
							},
							t: 103,
							s: [12.057, 21.961],
							to: [-1.778, .057],
							ti: [.204, -.068]
						}, {
							i: {
								x: .667,
								y: 1
							},
							o: {
								x: .333,
								y: 0
							},
							t: 106,
							s: [9.5, 21.14],
							to: [-.5, .167],
							ti: [-.417, -.083]
						}, {
							i: {
								x: .667,
								y: 1
							},
							o: {
								x: .333,
								y: 0
							},
							t: 114,
							s: [13.5, 21.64],
							to: [.417, .083],
							ti: [.25, 0]
						}, {
							t: 118,
							s: [12, 21.64]
						}],
						ix: 2
					},
					a: {
						a: 0,
						k: [0, 0],
						ix: 1
					},
					s: {
						a: 0,
						k: [100, 100],
						ix: 3
					},
					r: {
						a: 1,
						k: [{
							i: {
								x: [.833],
								y: [.833]
							},
							o: {
								x: [.167],
								y: [.167]
							},
							t: 59,
							s: [0]
						}, {
							i: {
								x: [.833],
								y: [.833]
							},
							o: {
								x: [.167],
								y: [.167]
							},
							t: 69,
							s: [29]
						}, {
							i: {
								x: [.833],
								y: [.833]
							},
							o: {
								x: [.167],
								y: [.167]
							},
							t: 72,
							s: [11]
						}, {
							i: {
								x: [.833],
								y: [.833]
							},
							o: {
								x: [.167],
								y: [.167]
							},
							t: 73,
							s: [-4.575]
						}, {
							i: {
								x: [.833],
								y: [.833]
							},
							o: {
								x: [.167],
								y: [.167]
							},
							t: 77,
							s: [-24]
						}, {
							i: {
								x: [.833],
								y: [.833]
							},
							o: {
								x: [.167],
								y: [.167]
							},
							t: 83,
							s: [-4]
						}, {
							i: {
								x: [.833],
								y: [.833]
							},
							o: {
								x: [.167],
								y: [.167]
							},
							t: 86,
							s: [14]
						}, {
							i: {
								x: [.833],
								y: [.833]
							},
							o: {
								x: [.167],
								y: [.167]
							},
							t: 91,
							s: [10]
						}, {
							i: {
								x: [.833],
								y: [.833]
							},
							o: {
								x: [.167],
								y: [.167]
							},
							t: 95,
							s: [-5]
						}, {
							i: {
								x: [.833],
								y: [.833]
							},
							o: {
								x: [.167],
								y: [.167]
							},
							t: 99,
							s: [-5]
						}, {
							i: {
								x: [.833],
								y: [.833]
							},
							o: {
								x: [.167],
								y: [.167]
							},
							t: 103,
							s: [8]
						}, {
							t: 106,
							s: [2]
						}],
						ix: 6
					},
					o: {
						a: 0,
						k: 100,
						ix: 7
					},
					sk: {
						a: 0,
						k: 0,
						ix: 4
					},
					sa: {
						a: 0,
						k: 0,
						ix: 5
					},
					nm: "Transform"
				}],
				nm: "Group 1",
				np: 2,
				cix: 2,
				bm: 0,
				ix: 1,
				mn: "ADBE Vector Group",
				hd: !1
			}, {
				ty: "gr",
				it: [{
					ind: 0,
					ty: "sh",
					ix: 1,
					ks: {
						a: 0,
						k: {
							i: [
								[0, 7],
								[4.652, -2.631],
								[-.03, -1.912],
								[0, 0],
								[0, 0]
							],
							o: [
								[0, -4.399],
								[-1.665, .941],
								[.114, 7.316],
								[0, 0],
								[0, 0]
							],
							v: [
								[6, -.654],
								[-3.387, -5.715],
								[-6.003, -1.044],
								[-9, 8.346],
								[9, 8.346]
							],
							c: !0
						},
						ix: 2
					},
					nm: "Path 1",
					mn: "ADBE Vector Shape - Group",
					hd: !1
				}, {
					ty: "st",
					c: {
						a: 0,
						k: [0, 0, 0, 1],
						ix: 3
					},
					o: {
						a: 0,
						k: 100,
						ix: 4
					},
					w: {
						a: 0,
						k: 2,
						ix: 5
					},
					lc: 2,
					lj: 2,
					bm: 0,
					nm: "Stroke 1",
					mn: "ADBE Vector Graphic - Stroke",
					hd: !1
				}, {
					ty: "tr",
					p: {
						a: 0,
						k: [12, 8.654],
						ix: 2
					},
					a: {
						a: 0,
						k: [0, 0],
						ix: 1
					},
					s: {
						a: 0,
						k: [100, 100],
						ix: 3
					},
					r: {
						a: 1,
						k: [{
							i: {
								x: [.667],
								y: [.649]
							},
							o: {
								x: [.333],
								y: [0]
							},
							t: 59,
							s: [0]
						}, {
							i: {
								x: [.667],
								y: [.534]
							},
							o: {
								x: [.333],
								y: [.605]
							},
							t: 64,
							s: [16.49]
						}, {
							i: {
								x: [.71],
								y: [.694]
							},
							o: {
								x: [.302],
								y: [-.094]
							},
							t: 69,
							s: [26.049]
						}, {
							i: {
								x: [.778],
								y: [1]
							},
							o: {
								x: [.426],
								y: [1.157]
							},
							t: 74,
							s: [-16.741]
						}, {
							i: {
								x: [.667],
								y: [1]
							},
							o: {
								x: [.167],
								y: [0]
							},
							t: 78,
							s: [-30.021]
						}, {
							i: {
								x: [.667],
								y: [1]
							},
							o: {
								x: [.167],
								y: [0]
							},
							t: 88,
							s: [19.021]
						}, {
							i: {
								x: [.79],
								y: [1]
							},
							o: {
								x: [.299],
								y: [0]
							},
							t: 96,
							s: [-11]
						}, {
							i: {
								x: [.585],
								y: [.443]
							},
							o: {
								x: [.178],
								y: [0]
							},
							t: 103,
							s: [9]
						}, {
							i: {
								x: [.667],
								y: [1]
							},
							o: {
								x: [.348],
								y: [1.956]
							},
							t: 107,
							s: [-2.3]
						}, {
							i: {
								x: [.833],
								y: [1]
							},
							o: {
								x: [.167],
								y: [0]
							},
							t: 111,
							s: [-5]
						}, {
							i: {
								x: [.833],
								y: [1]
							},
							o: {
								x: [.167],
								y: [0]
							},
							t: 114,
							s: [2]
						}, {
							t: 118,
							s: [0]
						}],
						ix: 6
					},
					o: {
						a: 0,
						k: 100,
						ix: 7
					},
					sk: {
						a: 0,
						k: 0,
						ix: 4
					},
					sa: {
						a: 0,
						k: 0,
						ix: 5
					},
					nm: "Transform"
				}],
				nm: "Group 2",
				np: 2,
				cix: 2,
				bm: 0,
				ix: 2,
				mn: "ADBE Vector Group",
				hd: !1
			}, {
				ty: "gr",
				it: [{
					ty: "tr",
					p: {
						a: 0,
						k: [12, 21.64],
						ix: 2
					},
					a: {
						a: 0,
						k: [0, 0],
						ix: 1
					},
					s: {
						a: 0,
						k: [100, 100],
						ix: 3
					},
					r: {
						a: 0,
						k: 0,
						ix: 6
					},
					o: {
						a: 0,
						k: 100,
						ix: 7
					},
					sk: {
						a: 0,
						k: 0,
						ix: 4
					},
					sa: {
						a: 0,
						k: 0,
						ix: 5
					},
					nm: "Transform"
				}],
				nm: "Group 3",
				np: 0,
				cix: 2,
				bm: 0,
				ix: 3,
				mn: "ADBE Vector Group",
				hd: !1
			}],
			ip: -1,
			op: 614,
			st: -1,
			bm: 0
		}],
		markers: []
	},
	params = {
		container: document.getElementById("lottie-beil"),
		renderer: "svg",
		loop: !0,
		autoplay: !0,
		animationData: animationData
	};
anim = lottie.loadAnimation(params);
var anim;
animationData = {
	v: "5.5.2",
	fr: 120,
	ip: 0,
	op: 150,
	w: 192,
	h: 192,
	nm: "Comp 1",
	ddd: 0,
	assets: [],
	layers: [{
		ddd: 0,
		ind: 1,
		ty: 4,
		nm: "Maill Opened Outlines",
		parent: 2,
		sr: 1,
		ks: {
			o: {
				a: 0,
				k: 100,
				ix: 11
			},
			r: {
				a: 0,
				k: 0,
				ix: 10
			},
			p: {
				a: 0,
				k: [12, 9.037, 0],
				ix: 2
			},
			a: {
				a: 0,
				k: [12, 12, 0],
				ix: 1
			},
			s: {
				a: 0,
				k: [100, 100, 100],
				ix: 6
			}
		},
		ao: 0,
		shapes: [{
			ty: "gr",
			it: [{
				ind: 0,
				ty: "sh",
				ix: 1,
				ks: {
					a: 0,
					k: {
						i: [
							[0, 0],
							[0, 0],
							[0, 0]
						],
						o: [
							[0, 0],
							[0, 0],
							[0, 0]
						],
						v: [
							[8, -3.15],
							[0, 3.15],
							[-8, -3.15]
						],
						c: !1
					},
					ix: 2
				},
				nm: "Path 1",
				mn: "ADBE Vector Shape - Group",
				hd: !1
			}, {
				ty: "st",
				c: {
					a: 0,
					k: [0, 0, 0, 1],
					ix: 3
				},
				o: {
					a: 0,
					k: 100,
					ix: 4
				},
				w: {
					a: 0,
					k: 2,
					ix: 5
				},
				lc: 2,
				lj: 2,
				bm: 0,
				nm: "Stroke 1",
				mn: "ADBE Vector Graphic - Stroke",
				hd: !1
			}, {
				ty: "tr",
				p: {
					a: 0,
					k: [12, 12.75],
					ix: 2
				},
				a: {
					a: 0,
					k: [0, 0],
					ix: 1
				},
				s: {
					a: 0,
					k: [100, 100],
					ix: 3
				},
				r: {
					a: 0,
					k: 0,
					ix: 6
				},
				o: {
					a: 0,
					k: 100,
					ix: 7
				},
				sk: {
					a: 0,
					k: 0,
					ix: 4
				},
				sa: {
					a: 0,
					k: 0,
					ix: 5
				},
				nm: "Transform"
			}],
			nm: "Group 1",
			np: 2,
			cix: 2,
			bm: 0,
			ix: 1,
			mn: "ADBE Vector Group",
			hd: !1
		}, {
			ty: "gr",
			it: [{
				ind: 0,
				ty: "sh",
				ix: 1,
				ks: {
					a: 1,
					k: [{
						i: {
							x: .833,
							y: .833
						},
						o: {
							x: .333,
							y: 0
						},
						t: 30,
						s: [{
							i: [
								[0, 0],
								[0, 0],
								[0, 0],
								[0, 0]
							],
							o: [
								[0, 0],
								[0, 0],
								[0, 0],
								[0, 0]
							],
							v: [
								[.018, 8.085],
								[.031, 8.073],
								[.006, 8.073],
								[.031, 8.061]
							],
							c: !1
						}]
					}, {
						i: {
							x: .667,
							y: 1
						},
						o: {
							x: .167,
							y: .167
						},
						t: 44,
						s: [{
							i: [
								[0, 0],
								[0, 0],
								[0, 0],
								[0, 0]
							],
							o: [
								[0, 0],
								[0, 0],
								[0, 0],
								[0, 0]
							],
							v: [
								[3.929, 5.275],
								[3.859, 2.97],
								[-4.167, 2.966],
								[-4.131, 5.04]
							],
							c: !1
						}]
					}, {
						i: {
							x: .667,
							y: 1
						},
						o: {
							x: .333,
							y: 0
						},
						t: 60,
						s: [{
							i: [
								[0, 0],
								[0, 0],
								[0, 0],
								[0, 0]
							],
							o: [
								[0, 0],
								[0, 0],
								[0, 0],
								[0, 0]
							],
							v: [
								[7.012, 2.915],
								[6.928, -8.044],
								[-7.072, -8.044],
								[-6.988, 2.915]
							],
							c: !1
						}]
					}, {
						i: {
							x: .667,
							y: 1
						},
						o: {
							x: .333,
							y: 0
						},
						t: 75,
						s: [{
							i: [
								[0, 0],
								[0, 0],
								[0, 0],
								[0, 0]
							],
							o: [
								[0, 0],
								[0, 0],
								[0, 0],
								[0, 0]
							],
							v: [
								[7.012, 2.915],
								[7.049, -3.207],
								[-6.951, -3.207],
								[-6.988, 2.915]
							],
							c: !1
						}]
					}, {
						i: {
							x: .667,
							y: 1
						},
						o: {
							x: .333,
							y: 0
						},
						t: 90,
						s: [{
							i: [
								[0, 0],
								[0, 0],
								[0, 0],
								[0, 0]
							],
							o: [
								[0, 0],
								[0, 0],
								[0, 0],
								[0, 0]
							],
							v: [
								[7.027, 2.479],
								[7.027, -4.521],
								[-6.973, -4.521],
								[-6.973, 2.479]
							],
							c: !1
						}]
					}, {
						t: 105,
						s: [{
							i: [
								[0, 0],
								[0, 0],
								[0, 0],
								[0, 0]
							],
							o: [
								[0, 0],
								[0, 0],
								[0, 0],
								[0, 0]
							],
							v: [
								[7.012, 2.915],
								[7.012, -4.085],
								[-6.988, -4.085],
								[-6.988, 2.915]
							],
							c: !1
						}]
					}],
					ix: 2
				},
				nm: "Path 1",
				mn: "ADBE Vector Shape - Group",
				hd: !1
			}, {
				ty: "st",
				c: {
					a: 0,
					k: [0, 0, 0, 1],
					ix: 3
				},
				o: {
					a: 0,
					k: 100,
					ix: 4
				},
				w: {
					a: 0,
					k: 2,
					ix: 5
				},
				lc: 2,
				lj: 2,
				bm: 0,
				nm: "Stroke 1",
				mn: "ADBE Vector Graphic - Stroke",
				hd: !1
			}, {
				ty: "fl",
				c: {
					a: 0,
					k: [1, 1, 1, 1],
					ix: 4
				},
				o: {
					a: 0,
					k: 100,
					ix: 5
				},
				r: 1,
				bm: 0,
				nm: "Fill 1",
				mn: "ADBE Vector Graphic - Fill",
				hd: !1
			}, {
				ty: "tr",
				p: {
					a: 0,
					k: [12, 7.5],
					ix: 2
				},
				a: {
					a: 0,
					k: [0, 0],
					ix: 1
				},
				s: {
					a: 0,
					k: [100, 100],
					ix: 3
				},
				r: {
					a: 0,
					k: 0,
					ix: 6
				},
				o: {
					a: 0,
					k: 100,
					ix: 7
				},
				sk: {
					a: 0,
					k: 0,
					ix: 4
				},
				sa: {
					a: 0,
					k: 0,
					ix: 5
				},
				nm: "Transform"
			}],
			nm: "Group 2",
			np: 3,
			cix: 2,
			bm: 0,
			ix: 2,
			mn: "ADBE Vector Group",
			hd: !1
		}, {
			ty: "gr",
			it: [{
				ind: 0,
				ty: "sh",
				ix: 1,
				ks: {
					a: 0,
					k: {
						i: [
							[-.99, 0],
							[0, 0],
							[0, -.907],
							[0, 0],
							[.991, 0],
							[0, 0],
							[0, .908],
							[0, 0]
						],
						o: [
							[0, 0],
							[.991, 0],
							[0, 0],
							[0, .908],
							[0, 0],
							[-.99, 0],
							[0, 0],
							[0, -.907]
						],
						v: [
							[-7.2, -6.6],
							[7.2, -6.6],
							[9, -4.95],
							[9, 4.95],
							[7.2, 6.6],
							[-7.2, 6.6],
							[-9, 4.95],
							[-9, -4.95]
						],
						c: !0
					},
					ix: 2
				},
				nm: "Path 1",
				mn: "ADBE Vector Shape - Group",
				hd: !1
			}, {
				ty: "st",
				c: {
					a: 0,
					k: [0, 0, 0, 1],
					ix: 3
				},
				o: {
					a: 0,
					k: 100,
					ix: 4
				},
				w: {
					a: 0,
					k: 2,
					ix: 5
				},
				lc: 2,
				lj: 2,
				bm: 0,
				nm: "Stroke 1",
				mn: "ADBE Vector Graphic - Stroke",
				hd: !1
			}, {
				ty: "tr",
				p: {
					a: 0,
					k: [12, 15.4],
					ix: 2
				},
				a: {
					a: 0,
					k: [0, 0],
					ix: 1
				},
				s: {
					a: 0,
					k: [100, 100],
					ix: 3
				},
				r: {
					a: 0,
					k: 0,
					ix: 6
				},
				o: {
					a: 0,
					k: 100,
					ix: 7
				},
				sk: {
					a: 0,
					k: 0,
					ix: 4
				},
				sa: {
					a: 0,
					k: 0,
					ix: 5
				},
				nm: "Transform"
			}],
			nm: "Group 4",
			np: 2,
			cix: 2,
			bm: 0,
			ix: 4,
			mn: "ADBE Vector Group",
			hd: !1
		}],
		ip: 30,
		op: 150,
		st: 0,
		bm: 0
	}, {
		ddd: 0,
		ind: 2,
		ty: 4,
		nm: "Mail Outlines",
		sr: 1,
		ks: {
			o: {
				a: 0,
				k: 100,
				ix: 11
			},
			r: {
				a: 1,
				k: [{
					i: {
						x: [.667],
						y: [1]
					},
					o: {
						x: [.333],
						y: [0]
					},
					t: 14,
					s: [0]
				}, {
					i: {
						x: [.667],
						y: [1]
					},
					o: {
						x: [.333],
						y: [0]
					},
					t: 41,
					s: [-8]
				}, {
					i: {
						x: [.667],
						y: [1]
					},
					o: {
						x: [.333],
						y: [0]
					},
					t: 65,
					s: [4]
				}, {
					i: {
						x: [.667],
						y: [1]
					},
					o: {
						x: [.333],
						y: [0]
					},
					t: 90,
					s: [-2]
				}, {
					t: 120,
					s: [0]
				}],
				ix: 10
			},
			p: {
				a: 1,
				k: [{
					i: {
						x: .667,
						y: 1
					},
					o: {
						x: .333,
						y: 0
					},
					t: 0,
					s: [96, 116.25, 0],
					to: [0, -5.833, 0],
					ti: [0, -1.167, 0]
				}, {
					i: {
						x: .667,
						y: 1
					},
					o: {
						x: .333,
						y: 0
					},
					t: 30,
					s: [96, 81.25, 0],
					to: [0, 1.167, 0],
					ti: [0, -5, 0]
				}, {
					i: {
						x: .667,
						y: 1
					},
					o: {
						x: .333,
						y: 0
					},
					t: 55,
					s: [96, 123.25, 0],
					to: [0, 5, 0],
					ti: [0, 1.167, 0]
				}, {
					i: {
						x: .667,
						y: 1
					},
					o: {
						x: .333,
						y: 0
					},
					t: 81,
					s: [96, 111.25, 0],
					to: [0, -1.167, 0],
					ti: [0, -.833, 0]
				}, {
					t: 106,
					s: [96, 116.25, 0]
				}],
				ix: 2
			},
			a: {
				a: 0,
				k: [12, 12, 0],
				ix: 1
			},
			s: {
				a: 1,
				k: [{
					i: {
						x: [.667, .667, .667],
						y: [1, 1, 1]
					},
					o: {
						x: [.333, .333, .333],
						y: [0, 0, 0]
					},
					t: 0,
					s: [683.333, 683.333, 100]
				}, {
					i: {
						x: [.667, .667, .667],
						y: [1, 1, 1]
					},
					o: {
						x: [.333, .333, .333],
						y: [0, 0, 0]
					},
					t: 30,
					s: [775.333, 775.333, 100]
				}, {
					i: {
						x: [.667, .667, .667],
						y: [1, 1, 1]
					},
					o: {
						x: [.333, .333, .333],
						y: [0, 0, 0]
					},
					t: 55,
					s: [635.333, 635.333, 100]
				}, {
					i: {
						x: [.667, .667, .667],
						y: [1, 1, 1]
					},
					o: {
						x: [.333, .333, .333],
						y: [0, 0, 0]
					},
					t: 81,
					s: [690.333, 690.333, 100]
				}, {
					t: 106,
					s: [683.333, 683.333, 100]
				}],
				ix: 6
			}
		},
		ao: 0,
		shapes: [{
			ty: "gr",
			it: [{
				ind: 0,
				ty: "sh",
				ix: 1,
				ks: {
					a: 1,
					k: [{
						i: {
							x: .667,
							y: 1
						},
						o: {
							x: .333,
							y: 0
						},
						t: 30,
						s: [{
							i: [
								[0, 0],
								[0, 0],
								[0, 0]
							],
							o: [
								[0, 0],
								[0, 0],
								[0, 0]
							],
							v: [
								[8, -3.15],
								[0, 3.15],
								[-8, -3.15]
							],
							c: !1
						}]
					}, {
						t: 55,
						s: [{
							i: [
								[0, 0],
								[0, 0],
								[0, 0]
							],
							o: [
								[0, 0],
								[0, 0],
								[0, 0]
							],
							v: [
								[7.988, -3.882],
								[0, -10.24],
								[-7.988, -3.845]
							],
							c: !1
						}]
					}],
					ix: 2
				},
				nm: "Path 1",
				mn: "ADBE Vector Shape - Group",
				hd: !1
			}, {
				ty: "st",
				c: {
					a: 0,
					k: [0, 0, 0, 1],
					ix: 3
				},
				o: {
					a: 0,
					k: 100,
					ix: 4
				},
				w: {
					a: 0,
					k: 2,
					ix: 5
				},
				lc: 2,
				lj: 2,
				bm: 0,
				nm: "Stroke 1",
				mn: "ADBE Vector Graphic - Stroke",
				hd: !1
			}, {
				ty: "tr",
				p: {
					a: 0,
					k: [12, 9.75],
					ix: 2
				},
				a: {
					a: 0,
					k: [0, 0],
					ix: 1
				},
				s: {
					a: 0,
					k: [100, 100],
					ix: 3
				},
				r: {
					a: 0,
					k: 0,
					ix: 6
				},
				o: {
					a: 0,
					k: 100,
					ix: 7
				},
				sk: {
					a: 0,
					k: 0,
					ix: 4
				},
				sa: {
					a: 0,
					k: 0,
					ix: 5
				},
				nm: "Transform"
			}],
			nm: "Group 1",
			np: 2,
			cix: 2,
			bm: 0,
			ix: 1,
			mn: "ADBE Vector Group",
			hd: !1
		}, {
			ty: "gr",
			it: [{
				ind: 0,
				ty: "sh",
				ix: 1,
				ks: {
					a: 0,
					k: {
						i: [
							[-.99, 0],
							[0, 0],
							[0, -.907],
							[0, 0],
							[.991, 0],
							[0, 0],
							[0, .908],
							[0, 0]
						],
						o: [
							[0, 0],
							[.991, 0],
							[0, 0],
							[0, .908],
							[0, 0],
							[-.99, 0],
							[0, 0],
							[0, -.907]
						],
						v: [
							[-7.2, -6.6],
							[7.2, -6.6],
							[9, -4.95],
							[9, 4.95],
							[7.2, 6.6],
							[-7.2, 6.6],
							[-9, 4.95],
							[-9, -4.95]
						],
						c: !0
					},
					ix: 2
				},
				nm: "Path 1",
				mn: "ADBE Vector Shape - Group",
				hd: !1
			}, {
				ty: "tm",
				s: {
					a: 1,
					k: [{
						i: {
							x: [.667],
							y: [1]
						},
						o: {
							x: [.333],
							y: [0]
						},
						t: 30,
						s: [0]
					}, {
						t: 55,
						s: [26]
					}],
					ix: 1
				},
				e: {
					a: 1,
					k: [{
						i: {
							x: [.667],
							y: [1]
						},
						o: {
							x: [.333],
							y: [0]
						},
						t: 30,
						s: [100]
					}, {
						t: 55,
						s: [98]
					}],
					ix: 2
				},
				o: {
					a: 0,
					k: 0,
					ix: 3
				},
				m: 1,
				ix: 2,
				nm: "Trim Paths 1",
				mn: "ADBE Vector Filter - Trim",
				hd: !1
			}, {
				ty: "st",
				c: {
					a: 0,
					k: [0, 0, 0, 1],
					ix: 3
				},
				o: {
					a: 0,
					k: 100,
					ix: 4
				},
				w: {
					a: 0,
					k: 2,
					ix: 5
				},
				lc: 2,
				lj: 2,
				bm: 0,
				nm: "Stroke 1",
				mn: "ADBE Vector Graphic - Stroke",
				hd: !1
			}, {
				ty: "tr",
				p: {
					a: 0,
					k: [12, 12.4],
					ix: 2
				},
				a: {
					a: 0,
					k: [0, 0],
					ix: 1
				},
				s: {
					a: 0,
					k: [100, 100],
					ix: 3
				},
				r: {
					a: 0,
					k: 0,
					ix: 6
				},
				o: {
					a: 0,
					k: 100,
					ix: 7
				},
				sk: {
					a: 0,
					k: 0,
					ix: 4
				},
				sa: {
					a: 0,
					k: 0,
					ix: 5
				},
				nm: "Transform"
			}],
			nm: "Group 2",
			np: 3,
			cix: 2,
			bm: 0,
			ix: 2,
			mn: "ADBE Vector Group",
			hd: !1
		}],
		ip: 0,
		op: 150,
		st: 0,
		bm: 0
	}],
	markers: []
}, params = {
	container: document.getElementById("lottie-mail"),
	renderer: "svg",
	loop: !0,
	autoplay: !0,
	animationData: animationData
};
anim = lottie.loadAnimation(params);
const $tableID = $("#table"),
	$BTN = $("#export-btn"),
	$EXPORT = $("#export"),
	newTr = '\n<tr class="hide">\n  <td class="pt-3-half" contenteditable="true">Example</td>\n  <td class="pt-3-half" contenteditable="true">Example</td>\n  <td class="pt-3-half" contenteditable="true">Example</td>\n  <td class="pt-3-half" contenteditable="true">Example</td>\n  <td class="pt-3-half" contenteditable="true">Example</td>\n  <td class="pt-3-half">\n    <span class="table-up"><a href="#!" class="indigo-text"><i class="fas fa-long-arrow-alt-up" aria-hidden="true"></i></a></span>\n    <span class="table-down"><a href="#!" class="indigo-text"><i class="fas fa-long-arrow-alt-down" aria-hidden="true"></i></a></span>\n  </td>\n  <td>\n    <span class="table-remove"><button type="button" class="btn btn-danger btn-rounded btn-sm my-0 waves-effect waves-light">Remove</button></span>\n  </td>\n</tr>';
$(".table-add").on("click", "i", () => {
	const e = $tableID.find("tbody tr").last().clone(!0).removeClass("hide table-line");
	0 === $tableID.find("tbody tr").length && $("tbody").append(newTr), $tableID.find("table").append(e)
}), $tableID.on("click", ".table-remove", function() {
	$(this).parents("tr").detach()
}), $tableID.on("click", ".table-up", function() {
	const e = $(this).parents("tr");
	1 !== e.index() && e.prev().before(e.get(0))
}), $tableID.on("click", ".table-down", function() {
	const e = $(this).parents("tr");
	e.next().after(e.get(0))
}), jQuery.fn.pop = [].pop, jQuery.fn.shift = [].shift, $BTN.on("click", () => {
	const e = $tableID.find("tr:not(:hidden)"),
		t = [],
		a = [];
	$(e.shift()).find("th:not(:empty)").each(function() {
		t.push($(this).text().toLowerCase())
	}), e.each(function() {
		const e = $(this).find("td"),
			n = {};
		t.forEach((t, a) => {
			n[t] = e.eq(a).text()
		}), a.push(n)
	}), $EXPORT.text(JSON.stringify(a))
}), $(document).ready(function() {
	var e, t, a, n, o = 1,
		r = $("fieldset").length;

	function i(e) {
		var t = parseFloat(100 / r) * e;
		t = t.toFixed(), $(".progress-bar").css("width", t + "%")
	}
	i(o), $(".next").click(function() {
		e = $(this).parent(), t = $(this).parent().next(), $("#top-tab-list li").eq($("fieldset").index(t)).addClass("active"), $("#top-tab-list li").eq($("fieldset").index(e)).addClass("done"), t.show(), e.animate({
			opacity: 0
		}, {
			step: function(a) {
				n = 1 - a, e.css({
					display: "none",
					position: "relative"
				}), t.css({
					opacity: n
				})
			},
			duration: 500
		}), i(++o)
	}), $(".previous").click(function() {
		e = $(this).parent(), a = $(this).parent().prev(), $("#top-tab-list li").eq($("fieldset").index(e)).removeClass("active"), $("#top-tab-list li").eq($("fieldset").index(a)).removeClass("done"), a.show(), e.animate({
			opacity: 0
		}, {
			step: function(t) {
				n = 1 - t, e.css({
					display: "none",
					position: "relative"
				}), a.css({
					opacity: n
				})
			},
			duration: 500
		}), i(--o)
	}), $(".submit").click(function() {
		return !1
	})
}), $(document).ready(function() {
	var e = $("div.setup-panel div a"),
		t = $(".setup-content"),
		a = $(".nextBtn");
	t.hide(), e.click(function(a) {
		a.preventDefault();
		var n = $($(this).attr("href")),
			o = $(this);
		o.hasClass("disabled") || (e.addClass("active"), o.parent().addClass("active"), t.hide(), n.show(), n.find("input:eq(0)").focus())
	}), a.click(function() {
		var e = $(this).closest(".setup-content"),
			t = e.attr("id"),
			a = $('div.setup-panel div a[href="#' + t + '"]').parent().next().children("a"),
			n = e.find("input[type='text'],input[type='email'],input[type='password'],input[type='url'],textarea"),
			o = !0;
		$(".form-group").removeClass("has-error");
		for (var r = 0; r < n.length; r++) n[r].validity.valid || (o = !1, $(n[r]).closest(".form-group").addClass("has-error"));
		o && a.removeAttr("disabled").trigger("click")
	}), $("div.setup-panel div a.active").trigger("click")
}), $(document).ready(function() {
	var e, t, a, n, o = 1,
		r = $("fieldset").length;

	function i(e) {
		var t = parseFloat(100 / r) * e;
		t = t.toFixed(), $(".progress-bar").css("width", t + "%")
	}
	i(o), $(".next").click(function() {
		e = $(this).parent(), t = $(this).parent().next(), $("#top-tabbar-vertical li").eq($("fieldset").index(t)).addClass("active"), t.show(), e.animate({
			opacity: 0
		}, {
			step: function(a) {
				n = 1 - a, e.css({
					display: "none",
					position: "relative"
				}), t.css({
					opacity: n
				})
			},
			duration: 500
		}), i(++o)
	}), $(".previous").click(function() {
		e = $(this).parent(), a = $(this).parent().prev(), $("#top-tabbar-vertical li").eq($("fieldset").index(e)).removeClass("active"), a.show(), e.animate({
			opacity: 0
		}, {
			step: function(t) {
				n = 1 - t, e.css({
					display: "none",
					position: "relative"
				}), a.css({
					opacity: n
				})
			},
			duration: 500
		}), i(--o)
	}), $(".submit").click(function() {
		return !1
	})
}), $(document).ready(function() {
	$(".file-upload").on("change", function() {
		! function(e) {
			if (e.files && e.files[0]) {
				var t = new FileReader;
				t.onload = function(e) {
					$(".profile-pic").attr("src", e.target.result)
				}, t.readAsDataURL(e.files[0])
			}
		}(this)
	}), $(".upload-button").on("click", function() {
		$(".file-upload").click()
	})
}), $(function() {
	function e(e) {
		return e / 100 * 360
	}
	$(".progress-round").each(function() {
		var t = $(this).attr("data-value"),
			a = $(this).find(".progress-left .progress-bar"),
			n = $(this).find(".progress-right .progress-bar");
		t > 0 && (t <= 50 ? n.css("transform", "rotate(" + e(t) + "deg)") : (n.css("transform", "rotate(180deg)"), a.css("transform", "rotate(" + e(t - 50) + "deg)")))
	})
});


if(jQuery('#weather-chart').length){
	am4core.ready(function() {

// Themes begin
am4core.useTheme(am4themes_animated);
// Themes end


// Create map instance
var chart = am4core.create("weather-chart", am4maps.MapChart);

// Set map definition
chart.geodata = am4geodata_worldHigh;

// Set projection
chart.projection = new am4maps.projections.Mercator();

// Center on the groups by default
chart.homeZoomLevel = 6;
chart.homeGeoPoint = { longitude: 10, latitude: 51 };

// Polygon series
var polygonSeries = chart.series.push(new am4maps.MapPolygonSeries());
polygonSeries.exclude = ["AQ"];
polygonSeries.useGeodata = true;
polygonSeries.nonScalingStroke = true;
polygonSeries.strokeOpacity = 0.5;

// Image series
var imageSeries = chart.series.push(new am4maps.MapImageSeries());
var imageTemplate = imageSeries.mapImages.template;
imageTemplate.propertyFields.longitude = "longitude";
imageTemplate.propertyFields.latitude = "latitude";
imageTemplate.nonScaling = true;

var image = imageTemplate.createChild(am4core.Image);
image.propertyFields.href = "imageURL";
image.width = 50;
image.height = 50;
image.horizontalCenter = "middle";
image.verticalCenter = "middle";

var label = imageTemplate.createChild(am4core.Label);
label.text = "{label}";
label.horizontalCenter = "middle";
label.verticalCenter = "top";
label.dy = 20;

imageSeries.data = [{
  "latitude": 40.416775,
  "longitude": -3.703790,
  "imageURL": "https://www.amcharts.com/lib/images/weather/animated/rainy-1.svg",
  "width": 32,
  "height": 32,
  "label": "Madrid: +22C"
}, {
  "latitude": 48.856614,
  "longitude": 2.352222,
  "imageURL": "https://www.amcharts.com/lib/images/weather/animated/thunder.svg",
  "width": 32,
  "height": 32,
  "label": "Paris: +18C"
}, {
  "latitude": 52.520007,
  "longitude": 13.404954,
  "imageURL": "https://www.amcharts.com/lib/images/weather/animated/cloudy-day-1.svg",
  "width": 32,
  "height": 32,
  "label": "Berlin: +13C"
}, {
  "latitude": 52.229676,
  "longitude": 21.012229,
  "imageURL": "https://www.amcharts.com/lib/images/weather/animated/day.svg",
  "width": 32,
  "height": 32,
  "label": "Warsaw: +22C"
}, {
  "latitude": 41.872389,
  "longitude": 12.480180,
  "imageURL": "https://www.amcharts.com/lib/images/weather/animated/day.svg",
  "width": 32,
  "height": 32,
  "label": "Rome: +29C"
}, {
  "latitude": 51.507351,
  "longitude": -0.127758,
  "imageURL": "https://www.amcharts.com/lib/images/weather/animated/rainy-7.svg",
  "width": 32,
  "height": 32,
  "label": "London: +10C"
}, {
  "latitude": 59.329323,
  "longitude": 18.068581,
  "imageURL": "https://www.amcharts.com/lib/images/weather/animated/rainy-1.svg",
  "width": 32,
  "height": 32,
  "label": "Stockholm: +8C"
} ];

}); 
}


