let x=10;
const y=20;
let p;
{
    var t=50;
    let x=100;
    console.table([x,y,t,p]);
}
//Never use the var 
//It does not afftect with the block scope 
console.table([x,y,t,p]);