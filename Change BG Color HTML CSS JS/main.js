const button = document.querySelector('button');
const h2El = document.querySelector('h2');
const bgEl = document.querySelector('section');

let color = null;
function generateColor() {
  color = '#';
  color += Math.random().toString(16).slice(2, 8).toUpperCase();
  bgEl.style.backgroundColor = color;
  h2El.innerText = color
  return color;
}

function copy() {
  navigator.clipboard.writeText(color);
  // alert("Color Code : " + color)
  Swal.fire({
    position: 'top-center',
    icon: 'success',
    title: 'Code Copied Successfully',
    text: color,
    showConfirmButton: false,
    timer: 1500
  })
}




