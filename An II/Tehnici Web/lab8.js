window.onload = function() {
	var p1 = document.querySelector("div p");
	var p2 = document.querySelector("div:nth-of-type(2) p ");
	var div1 = document.querySelector("div:nth-of-type(1)");
	var div2 = document.querySelector("div:nth-of-type(2)");
	p1.onclick = function(e){alert("p" + e.target + e.currentTarget);}
	p2.onclick = function(e){alert("p2" + e.target + e.currentTarget);}
	div1.addEventListener("click", function(e){alert("d" + e.target + e.currentTarget);}, false);
	div2.addEventListener("click", function(e){alert("d2" + e.target + e.currentTarget);}, true);
	div2.onkeypress = function(e)  {
										var buton = document.querySelector("input");
										buton.value = buton.value + e.key;
										e.preventDefault();
									}
	div2.onclick = function(e) {
									var buton = document.querySelector("input");
									buton.style.left = e.pageX + "px";
									buton.style.top = e.pageY + "px";
									buton.focus();
								}
}