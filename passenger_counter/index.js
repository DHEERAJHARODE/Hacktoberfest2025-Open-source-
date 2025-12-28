//document.getElementById("count-el").innerText = 5;

let count=0;
function increment()
{
count++
document.getElementById("count-el").innerText=count
}
let saveEl= document.getElementById("save-el");
function save()
{
let countStr = count + " - "
saveEl.textContent += countStr  //.textcontent replaced innerText; innerHTML still not seen
count=0
document.getElementById("count-el").innerText=count
}


