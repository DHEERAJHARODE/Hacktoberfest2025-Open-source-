//google map
if ($("#map-canvas").length) {
jQuery(document).ready(function($) {
	
	"use strict";

		var map;
		function initialize() {
		  var mapOptions = {
		    zoom: 12,
		    center: new google.maps.LatLng(37.048437, -100.921268)
		  };
		  map = new google.maps.Map(document.getElementById('map-canvas'),
		      mapOptions);
		      var marker = new google.maps.Marker({
		        map: map,
		        icon: "images/map-marker.png",
		        title: "Mi marcador",
		        position: map.getCenter()
		      });
		      var marker2 = new google.maps.Marker({
		        map: map,
		        icon: "images/map-marker2.png",
		        title: "Otro marker",
		        position: new google.maps.LatLng(37.071450, -100.900326)
		      });
		      var marker3 = new google.maps.Marker({
		        map: map,
		        icon: "images/map-marker3.png",
		        title: "Otro marker mas",
		        position: new google.maps.LatLng(37.020208, -100.917492)
		      });



		      var infowindow = new google.maps.InfoWindow();
		      infowindow.setContent('<b>Mi marcador</b><br>Tel: 46546545');

		      var infowindow2 = new google.maps.InfoWindow();
		      infowindow2.setContent('<b>Otro marker</b><br>Tel: 46546545');

		      var infowindow3 = new google.maps.InfoWindow();
		      infowindow3.setContent('<b>Otro marker mas</b><br>Tel: 46546545');

		      infowindow.open(map, marker);


		      google.maps.event.addListener(marker, 'click', function() {
		        infowindow.open(map, marker);
		      });
		      google.maps.event.addListener(marker2, 'click', function() {
		        infowindow2.open(map, marker2);
		      });
		      google.maps.event.addListener(marker3, 'click', function() {
		        infowindow3.open(map, marker3);
		      });
		}

		google.maps.event.addDomListener(window, 'load', initialize);
});
}