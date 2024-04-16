// Create simple application that will do following
// Declare And assign variable
// Operators and expression in JavaScript
// Looping in JavaScript
// Declare an Array
// User defined functions in Javascript
// Built in functions in Javascript
// Dialog boxes

let a = 10;
let b = 20;
let c = 2

let sum = a + b;
let difference = b - a;
let product = a * b;
let quotient = b / a;
let power = a ** c;
let fruits = ['Apple', 'Banana', 'Cherry','Dragonfruit','Blueberries'];

document.write("<h4>Looping in JavaScript:</h4>");
for (let i = 0; i < 5; i++) {
    document.write(fruits[i] + "<br>");
}



function add(a, b) {
    return a + b;
}

let currentDate = new Date();
let pivalue = Math.PI
var str = "Apples"

alert("You check result here!!");
confirm("You want to see result?");
prompt("Enter anything and check result");

document.write("<h4>Results:</h4>");
document.write("a = " + a + "<br>" + "b = " + b + "<br>")
document.write("a + b = " + sum + "<br>");
document.write("b - a = " + difference + "<br>");
document.write("a * b = " + product + "<br>");
document.write("b / a = " + quotient + "<br>");
document.write("a ** c = " + power + "<br>");
document.write("Array : " + fruits + "<br>");
document.write("User define add function : " + add(a, b) + "<br>");
document.write("Current Date : " + currentDate + "<br>");
document.write("Value of pi : " + pivalue + "<br>")
document.write("lowercase of str : " + str.toLowerCase() + "<br>")
document.write("lowercase of str : " + str.toUpperCase() + "<br>")