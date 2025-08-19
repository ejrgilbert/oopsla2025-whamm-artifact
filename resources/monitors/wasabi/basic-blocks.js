{
	const counts = [];

	Wasabi.analysis.begin = function ({func, instr}, type) {
		counts[func] = counts[func] || [];
		counts[func][instr] = counts[func][instr] || { count: 0, type };
		counts[func][instr].count++;
	};

	Wasabi.analysisResult = function () {
		for (const func in counts) {
			for (const instr in counts[func]) {
				console.log(`${func}:${instr} --> ${counts[func][instr].count}`);
			}
		}
    };
}