function nume() {
var x = document.getElementById("2");
x.style.width = "20%";
x.style.border = "dotted lightblue 3px";
x.style.borderRadius = "500px";
x.onclick = iara;
}

function iara() {
var x = document.getElementById("2");
x.style.width = "50%";
x.style.border = "none";
}

window.onload = function() {
		  var x = document.getElementById("2");
		  x.onclick = nume;
		}
