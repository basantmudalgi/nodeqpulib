var qpulib = require('../index');
var core = qpulib.core;
var kernels = qpulib.kernels;

const gcdKern = kernels.createObject();

const arraySize = 16;
var a = [];
var b = [];
var c = [];

for(var i=0; i<arraySize; i++){
a[i] = 100 + (Math.random()*100 % 100);
b[i] = 100 + (Math.random()*100 % 100);
}

core.setNumQPUs(gcdKern, 8);

console.log(core.qpugcd(gcdKern, a, b, c));
