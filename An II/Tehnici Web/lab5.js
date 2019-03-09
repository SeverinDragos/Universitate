window.onload = function () {
  var b = document.getElementById(2);
  b.onclick = functioara;
  
}

function functioara () {
  var t = document.getElementById(1);
  alert(t.value);
  var b = document.createElement("input");
  b.type = "button";
  k = document.getElementById(1);
  b.value = k.value;
  b.onclick = function () {
  c = document.getElementById(3);
  c.removeChild(b); 
  }
  var s = document.getElementById(3);
  s.appendChild(b);
  
  var dinamica = document.getElementsByTagName("input");
  var statica = document.querySelectorAll("input");
  var d = document.createElement("input");
  d.type = "button";
  s.appendChild(d);
  d.value = statica.length +" "+ dinamica.length;
}

