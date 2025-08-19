{
    const coverage = [];

    function addLocation({func, instr}) {
        coverage[func] = coverage[func] || [];
        // JS engine optimizes this to sparse array anyway, no need for Sets
        coverage[func][instr] = true;
    }

    // just let every callback add its location to coverage
    for (const hook of Wasabi.HOOK_NAMES) {
        Wasabi.analysis[hook] = addLocation;
    }

    Wasabi.analysisResult  = function () {
		for (const func in coverage) {
			for (const instr in coverage[func]) {
				console.log(`${func}:${instr} --> ${coverage[func][instr]}`);
			}
		}
    };
}