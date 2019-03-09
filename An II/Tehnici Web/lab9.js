window.onload = function() {
	var i = 0;
	//var b = document.querySelector("input:nth-of-type(1)");
	/*b.onclick = function() {alert(i);}
	i = 1;*/
	/*var i2 = 0;
	{
		let il = i2;
		b.onclick = function() {alert(il);}
	}*/
	/*i2 = 1;
	{
		let bl = b;
		b.onclick = function() {alert(bl.value);}
	}
	b.value = "nou";*/
	/*var i3 = 0
	setTimeout(function(){alert(i);}, 100);
	i = 1;*/
	/*var i4 = 0
	{
		let il = i4;
		setTimeout(function(){alert(il);}, 100);
	}
	i4 = 1;*/
	/*var i5 = 0;
	setTimeout(function(p){alert(p);}, 100, i5);
	i5 = 1;*/
	/*var i6 = 0;
	{
		let il = i6;
		b.onclick = function(){setTimeout(function(){alert(il);}, 100);}
	}
	i6 = 1;*/
	var v = document.querySelectorAll("div input");
	for ( let i = 0; i < v.length; i++) {
	v[i].xnou = 100;
	v[i].style.left = (i + 1) * 25 + "px";
	v[i].onclick = function(){
		v[i].t = setInterval(function (){v[i].xnou += 5; v[i].style.left = v[i].xnou + "px";}, 100);
		v[i].onclick = function(){clearInterval(v[i].t);}
		}
	}
	var CeasulVietii = document.querySelector("section input");
	CeasulVietii.onclick = function(){
		setInterval(function() {let d = new Date(); CeasulVietii.value = d.getHours() + " " + d.getMinutes() + " " + d.getSeconds()}, 1000)
		}
}