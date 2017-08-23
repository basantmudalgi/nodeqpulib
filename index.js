try {
	
	var core = require('./build/Release/qpulib');
	var kernels = require('./build/Release/kernels');
	module.exports = {
		core: core,
		kernels: kernels
	};
} catch (err) {
	var core = require('./build/Debug/qpulib');
	var kernels = require('./build/Debug/kernels');
	module.exports =  {
		core: core,
		kernels: kernels
	};
}
