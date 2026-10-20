// const prompt = require('prompt-sync')();
console.log();
console.log("Starting the app");
function ageTeller(age) {
    // const answer = prompt('Enter your age');
    const newAge = age + 20;
    return newAge
}

const newAge = ageTeller(21);

console.log(`your age in 2046 will be = ${newAge}`); 
console.log("hello");

console.log("hello world");
try {
    console.log("hello from try block")
}
catch {
    console.log("you got some errors mate");
}