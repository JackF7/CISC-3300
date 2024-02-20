/* Homework Responses:

1). JavaScript is a lightweight programming language. It is generally used by web developers to add dynamic interactions to their web pages, applications, servers, and games.
JavaScript is an interpeted programming language, which meanns it is interpreted without having been compiled into machine language. The target machine does not execute the instruction,
but rather an interpreter reads and executes them instead. A compiled programming langugae is converted into machine language by a compiler; this machine code is undecipherable by humans.

2). var, let, and const are three ways to declare a variable in JS. var is redeclarable, older, and global/function scoped.
let is block scoped and also redeclarable. const is block scoped but not declarable.

3). An anonymous function is a function without a name; they are often short. Higher-order functons return a function or take other functions as arguments.

4). In JS, an object is a collection of properties. A property is an association between a name (or key) and a value, which can be a function (method).
Objects are createdusing object literals, constructors, or classes. JS uses prototypal inheritance, meaning objects can inherit directly from other objects. 
Traditional OOP languages use class-based inheritance. JS object can be modified at runtime. 

5). See code

*/

const cats = [
    {
        name: 'Charlie', adoptionStatus: 'available' },
    {
        name: 'Lily', adoptionStatus: 'not-available' },
    {
        name: 'Coco', adoptionStatus: 'available' },
    {
        name: 'Oreo', adoptionStatus: 'not-available' },
    {
        name: 'Luna', doptionStatus: 'available' },
    {
        //My cat's name!
        name: 'Milo', adoptionStatus: 'available' },
    {
        name: 'Lola', adoptionStatus: 'not-available' },
    {
        name: 'Leo', adoptionStatus: 'available' },
    {
        name: 'Willow', adoptionStatus: 'available' },
    {
        name: 'Bella', adoptionStatus: 'not-available' },
    {
        name: 'Max', adoptionStatus: 'available' },
    {
        name: 'Cleo', adoptionStatus: 'available' },
    {
        name: 'Lucy', adoptionStatus: 'not-available' },
    {
        name: 'Daisy', adoptionStatus: 'available' },
]

catsResult = []

for (var i = 0; i < cats.length; i++) {
    if (cats[i].adoptionStatus == 'available') {
        catsResult.push(cats[i].name);
    }
}

var adoptedCatsString = 'The following cats are available: ';

for (var i = 0; i < catsResult.length; i++) {
    if (i === catsResult.length - 1) {
        adoptedCatsString += 'and ' + catsResult[i] + '.\n';
    } else {
        adoptedCatsString += catsResult[i] + ', ';
    }
}

console.log(adoptedCatsString);
