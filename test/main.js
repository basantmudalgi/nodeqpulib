var qpulib = require('../index');
var core = qpulib.core;
var kernels = qpulib.kernels;

const gcdKern = kernels.createObject();

console.log(core.qpugcd(gcdKern));
