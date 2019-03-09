window.onload = function() {
	var intervalul = setInterval(CreateFulgi, 1000);
}

function CreateFulgi() {
	var div = document.querySelector("div");
	var fulg = document.createElement("img");
	fulg.xnou = 0;
	fulg.src = "bibi.jpg"
	fulg.style.position = "absolute";
	fulg.style.left = Math.floor((Math.random() * 1000) + 1) + "px";
	fulg.style.width = Math.floor((Math.random() * 300) + 1) + "px";
	fulg.style.height = fulg.style.width;
	fulg.proprietate = parseInt(fulg.style.width);
	div.appendChild(fulg);
	fulg.t = setInterval(function() {
		fulg.xnou += 5; 
		fulg.style.top = fulg.xnou + "px"; 
		fulg.proprietate -= 2; 
		fulg.style.width = fulg.proprietate + "px";
		fulg.style.height = fulg.proprietate + "px";
		if (fulg.proprietate <= 0)	{
			div.removeChild(fulg);
			clearInterval(fulg.t);
		}
		},100);
		
	fulg.onclick = function(e) {clearInterval(fulg.t); div.removeChild(fulg); e.stopPropagation();}
	var body = document.querySelector("body");
	body.onclick = function() {body.style.backgroundColor = "lightblue";}
}