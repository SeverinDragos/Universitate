window.onload = function() {
	var buton = document.querySelector("body input:nth-of-type(2)");
	buton.onclick = function() {
						if (localStorage.lastOpen == undefined) {
							f = open("https://www.w3schools.com/jsref/met_win_open.asp");
							var d = new Date();
							localStorage.lastOpen = d;
							localStorage.locatie = f.URL;
							setTimeout(function() {f.close();}, 3000);
						}
						else {
							buton.value = localStorage.locatie + localStorage.lastOpen;
							f = open("https://www.w3schools.com/jsref/met_win_open.asp");
							localStorage.locatie = f.URL;
							var d = new Date();
							localStorage.lastOpen = d;
							setTimeout(function() {f.close();}, 3000);
						}
					}
	/*buton.onclick = function() {
						if (localStorage.lastOpen == undefined) {
							var textbox = document.querySelector("body input");
							f = open(textbox.value);
							localStorage.lastOpen = textbox.value;
						}
						else {
							var textbox = document.querySelector("body input");
							if (localStorage.lastOpen != textbox.value) {
								f = open(textbox.value);
								localStorage.lastOpen = textbox.value;
							}
						}
					}*/
	var buton_tragubil = document.querySelector("#butonas");
	buton_tragubil.ondragstart = function(ev) { ev.dataTransfer.setData("text", this.id);}
	var div = document.querySelector("body div");
	div.ondragover = function(ev) {
						ev.preventDefault();
					}
	div.ondrop = function(ev) {
					ev.preventDefault();
					ev.dataTransfer.getData("text");
					var buton = document.getElementById(data);
					var stil = getComputedStyle(buton, null);
					div.appendChild(buton);
					//buton_tragubil.value = buton_tragubil.style.color;
					div.style.backgroundColor = stil.color;
				}
				
				
	var butoane = document.querySelectorAll("[name = \"butoane\"]");
	for (let i = 0; i < 4; i++) {
	butoane[i].onclick = function() {
							if (this.checked == true) {
								buton_tragubil.style.color = this.value;
							}
						}
	}
}