/*try {
	return require('./build/Release/qpulib');
} catch (err) {
	return require('./build/Debug/qpulib');
}*/
var addon = require('./build/Release/qpulib');
var kernels = require('./build/Release/kernels');

const gcdKern = kernels.createObject();

console.log(addon.qpugcd(gcdKern));
