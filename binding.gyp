{
  "variables": {
      "qpulib_root": "./QPULib-master/Lib"
  },
  "targets": [
    {
      'target_name': 'Lib/Kernel',
      'type': 'static_library',
      'sources': [
	 './QPULib-master/Lib/Kernel.cpp'
       ],
      'include_dirs': ['./QPULib-master/Lib'],  # dependents need to find the .h lib
      'link_settings': {
	'libraries': ['-lm'],
       	'cflags':[
		'-DQPU_MODE',
		'-DEBUG',
		'-Wconversion',
		'-std=c++0x'
	],
	'cflags_cc!':[
		'-DQPU_MODE',
		'-DEBUG',
		'-Wconversion',
		'-std=c++0x'
	] 
      }
    },
    {
      'target_name': 'Lib/Source',
      'type': 'static_library',
      'sources': [
	 './QPULib-master/Lib/Source/Syntax.cpp',
	 './QPULib-master/Lib/Source/Int.cpp',
	 './QPULib-master/Lib/Source/Float.cpp',
	 './QPULib-master/Lib/Source/Stmt.cpp',
	 './QPULib-master/Lib/Source/Pretty.cpp',
	 './QPULib-master/Lib/Source/Translate.cpp',
	 './QPULib-master/Lib/Source/Gen.cpp'
       ],
      'include_dirs': ['./QPULib-master/Lib'],  # dependents need to find .h lib
      'link_settings': {
      	'libraries': ['-lm'], 
      },
      'cflags':[
		'-DQPU_MODE',
		'-DEBUG',
		'-Wconversion',
		'-std=c++0x'
	],
	'cflags_cc!':[
		'-DQPU_MODE',
		'-DEBUG',
		'-Wconversion',
		'-std=c++0x'
	]
    }, 
    {
      'target_name': 'Lib/Target',
      'type': 'static_library',
      'sources': [
	 './QPULib-master/Lib/Target/Syntax.cpp',
	 './QPULib-master/Lib/Target/SmallLiteral.cpp',
	 './QPULib-master/Lib/Target/Pretty.cpp',
	 './QPULib-master/Lib/Target/RemoveLabels.cpp',
	 './QPULib-master/Lib/Target/CFG.cpp',
	 './QPULib-master/Lib/Target/Liveness.cpp',
	 './QPULib-master/Lib/Target/RegAlloc.cpp',
	 './QPULib-master/Lib/Target/ReachingDefs.cpp',
	 './QPULib-master/Lib/Target/Subst.cpp',
	 './QPULib-master/Lib/Target/LiveRangeSplit.cpp',
	 './QPULib-master/Lib/Target/Satisfy.cpp',
	 './QPULib-master/Lib/Target/LoadStore.cpp',
	 './QPULib-master/Lib/Target/Emulator.cpp',
	 './QPULib-master/Lib/Target/Encode.cpp'
       ],
      'include_dirs': ['./QPULib-master/Lib'],  # dependents need to find .h lib
      'link_settings': {
       'libraries': ['-lm'], 
      },
      'cflags':[
		'-DQPU_MODE',
		'-DEBUG',
		'-Wconversion',
		'-std=c++0x'
	],
	'cflags_cc!':[
		'-DQPU_MODE',
		'-DEBUG',
		'-Wconversion',
		'-std=c++0x'
	]
    },  
    {
      'target_name': 'Lib/VideoCore',
      'type': 'static_library',
      'sources': [
	 './QPULib-master/Lib/VideoCore/Mailbox.cpp',
	 './QPULib-master/Lib/VideoCore/Invoke.cpp',
	 './QPULib-master/Lib/VideoCore/VideoCore.cpp'
       ],
      'include_dirs': ['./QPULib-master/Lib'],  # dependents need to find .h lib
      'link_settings': {
       'libraries': ['-lm'], 
      },
      'cflags':[
		'-DQPU_MODE',
		'-DEBUG',
		'-Wconversion',
		'-std=c++0x'
	],
	'cflags_cc!':[
		'-DQPU_MODE',
		'-DEBUG',
		'-Wconversion',
		'-std=c++0x'
	]
    }, {
      'target_name': 'Lib/Source/Stmt',
      'type': 'static_library',
      'sources': [
	 './QPULib-master/Lib/Source/Stmt.cpp'
       ],
      'include_dirs': ['./QPULib-master/Lib'],  # dependents need to find .h lib
      'link_settings': {
       'libraries': ['-lm'], 
      },
      'cflags':[
		'-DQPU_MODE',
		'-DEBUG',
		'-Wconversion',
		'-std=c++0x'
	],
	'cflags_cc!':[
		'-DQPU_MODE',
		'-DEBUG',
		'-Wconversion',
		'-std=c++0x'
	]
    },
    {
      'target_name': 'qpulib',
      'dependencies': [
	'Lib/Kernel', 
	'Lib/Source',
	'Lib/Target',
	'Lib/VideoCore'
      ],
      'include_dirs': ['./QPULib-master/Lib'],  # dependents need to find .h lib
      'sources': ['qpulib.cc'],
      'cflags':[
		'-DQPU_MODE',
		'-DEBUG',
		'-Wconversion',
		'-std=c++0x'
	],
	'cflags_cc!':[
		'-DQPU_MODE',
		'-DEBUG',
		'-Wconversion',
		'-std=c++0x'
	]
    }
  ]
}
