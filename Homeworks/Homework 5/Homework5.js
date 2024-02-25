// Homework Responses:

// Question 1
const age = 19;
const result = age >= 18 ? 'You can vote this November' : 'You cannot vote';
console.log(result);

// Question 2
const student = {
    Name: 'Jack',
    Age: 19,
    City: 'New York',
    School: 'Fordham University',
    Major: 'Math & Computer Science',
};

for (const property in student) {
    console.log(`${property}: ${student[property]}`);
}

// Question 3
const boringNumbers = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
const funSquaredNumbers = boringNumbers.map(num => num ** 2);
console.log(funSquaredNumbers);

/* Questions 4 & 5

4). The DOM is the Document Object Model. The DOM dictates how browsers should create a model of an HTML page, as well 
as how JavaScript can access and update the contents of a web page while in the browser window. It is browser’s live rendering of an HTML page.
The DOM states what your script can ask the browser and how to tell the browser to update what is being shown to the user.

The model a browser creates upon loading a web page is called a DOM tree, which is stored in the browser's memory. It consists of four main types of nodes:
document node (topmost), element nodes, attribute nodes, and text nodes. The DOM tree is a hierarchical representation of a document's structure.


5). An XSS attack is a type of security vulnerability that allows attackers to inject malicious scripts into web pages viewed by other users. 
These scripts can be executed in the context of a user's browser, potentially allowing the attacker to steal sensitive information or manipulate the appearance and behavior of the web page.
XSS attacks typically occur when a web application does not properly validate user input and then reflects that input back to other users.
To prevent this, be very careful with HTML content. It should very rarely have the option to have come from a user at all. 
If it does, strip it of potential malicious intent by removing tags, escaping characters, etc.

*/

// Question 6

var originalText = 'Click here to change my text!';
var changedText = 'Text Changed! Click to change again.';

var changeText = document.getElementById('changeText');

changeText.addEventListener('click', function() {
  // Check the current text and toggle between original and changed text
  var currentText = this.textContent;
  this.textContent = currentText === originalText ? changedText : originalText;
});

var changeColor = document.getElementById('colorChange');

changeColor.addEventListener('click', function(event) {
    if (event.target.tagName === 'LI') {

        var fordhamItems = changeColor.getElementsByTagName('li');

        for (var i = 0; i < fordhamItems.length; i++) {
            fordhamItems[i].style.color = 'blue';
        }
        }
    });


document.getElementById('paragraphQuestion').addEventListener('click', function() {

    var newParagraph = document.createElement('p')
    newParagraph.textContent = 'Welcome to CISC 3300 - Spring 2024';
    document.body.append(newParagraph);

});