const form = document.querySelector('#form')
const num1 = document.querySelector('#first-num')
const num2 = document.querySelector('#second-num')
const addition = document.querySelector('#btn1')
const subtraction = document.querySelector('#btn2')
const multiplication = document.querySelector('#btn3')
const division = document.querySelector('#btn4')
const pResult = document.querySelector('#result')

form.addEventListener('submit', additionEvent)
addition.addEventListener('click', additionEvent)
subtraction.addEventListener('click',subtractionEvent)
multiplication.addEventListener('click',multiplicationEvent)
division.addEventListener('click', divisionEvent)

function additionEvent(event){
    event.preventDefault()
    const result = parseFloat(num1.value) + parseFloat(num2.value)
    pResult.innerText = `Result: ${result}`
}
function subtractionEvent(event){
    event.preventDefault()
    const result = parseFloat(num1.value) - parseFloat(num2.value)
    pResult.innerText = `Result: ${result}`
}
function multiplicationEvent(event){
    event.preventDefault()
    const result = parseFloat(num1.value) * parseFloat(num2.value).toFixed(3)
    pResult.innerText = `Result: ${result}`
}
function divisionEvent(event){
    event.preventDefault()
    const result = (parseFloat(num1.value) / parseFloat(num2.value)).toFixed(3)
    pResult.innerText = `Result: ${result}`
}

