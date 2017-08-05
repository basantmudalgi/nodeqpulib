/*try {
	return require('./build/Release/qpulib');
} catch (err) {
	return require('./build/Debug/qpulib');
}*/
var addon = require('./build/Release/qpulib');
console.log(addon.qpulib());
console.log(addon.qpugcd());
