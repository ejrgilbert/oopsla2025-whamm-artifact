{
	const reads = new Map();
	const writes = new Map();

	function access({func, instr}, {addr, offset}, write) {
		const key = addr+offset;
		const accesses = write ? writes : reads;
		
		if (accesses.has(key)) {
			accesses.set(key, accesses.get(key) + 1);
		} else {
			accesses.set(key, 1);
		}

	};

	Wasabi.analysis = {
		load(loc, op, memarg) { access(loc, memarg, false) },
		store(loc, op, memarg) { access(loc, memarg, true) },
	};

	Wasabi.analysisResult = function () {
		console.log("Reads:");
		for (const [addr, count] of reads) {
        		console.log(addr, ":", count);
		}
		console.log("Writes:");
		for (const [addr, count] of writes) {
        		console.log(addr, ":", count);
		}
	};

}
