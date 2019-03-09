window.onload = function() {
	var l1 = document.querySelector("section li");
	var ul = l1.parentElement;
	ul.className = "";
	l1.onclick = function() {
		
		l1.innerHTML += "<span>HOT</span>";
		ul.innerHTML += "<li>Curcubeitura</li>";
		ul.appendChild(l1);
		alert(l1.firstChild.nodeValue);
		ul.className = "a b";
		console.log(ul.innerHTML);
		console.log(ul.childNodes.length +" "+ ul.children.length);
		for (var i = 0; i < ul.childNodes.length; i++)
			console.log(ul.childNodes[i]);
	}
}
