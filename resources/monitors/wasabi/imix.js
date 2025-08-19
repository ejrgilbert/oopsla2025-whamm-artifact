{
    const counts = {};

    Wasabi.analysisResult = function () {
        const keysSorted = Object.keys(counts).sort(function(a,b){return counts[b]-counts[a]});
        for (const key of keysSorted) {
            console.log(key, "\t", counts[key]);
        }
    };

    function incClass(c) {
        counts[c] = (counts[c] | 0) + 1;
    }

    Wasabi.analysis = {
        // hooks that directly correspond to one instruction
        nop(loc) { incClass("NOP") },
        unreachable(loc) { incClass("CONTROL") },
        if_(loc, cond) { incClass("CONTROL") },
        br(loc, target) { incClass("CONTROL") },
        br_if(loc, target, cond) { incClass("CONTROL") },
        br_table(loc, table, def, idx) { incClass("CONTROL") },
        drop(loc, val) { incClass("DATA") },
        select(loc, fst, snd, cond) { incClass("DATA") },
        memory_size(loc, val) { incClass("MEMORY") },
        memory_grow(loc, delta, old) { incClass("MEMORY") },

        // hooks that correspond to multiple instructions -> use op argument
        unary(loc, op, input, result) {
		if (op.startsWith("i8x16") 
			|| op.startsWith("i16x8")  
			|| op.startsWith("i32x4")  
			|| op.startsWith("i64x2")  
			|| op.startsWith("f32x4")  
			|| op.startsWith("f64x2")  
			|| op.startsWith("v128")) {
			incClass("SIMD_ARITH");
		} else if (op.startsWith("i32") || op.startsWith("i64")) {
			incClass("INT_ARITH");
		} else if (op.startsWith("f32") || op.startsWith("f64")) {
			incClass("FLOAT_ARITH");
		}
	},
        binary(loc, op, first, second, result) { 
		if (op.startsWith("i8x16") 
			|| op.startsWith("i16x8")  
			|| op.startsWith("i32x4")  
			|| op.startsWith("i64x2")  
			|| op.startsWith("f32x4")  
			|| op.startsWith("f64x2")  
			|| op.startsWith("v128")) {
			incClass("SIMD_ARITH");
		} else if (op.startsWith("i32") || op.startsWith("i64")) {
			incClass("INT_ARITH");
		} else if (op.startsWith("f32") || op.startsWith("f64")) {
			incClass("FLOAT_ARITH");
		}
	},
        load(loc, op, memarg, val) { incClass("MEMORY") },
        store(loc, op, memarg, val) { incClass("MEMORY") },
        local(loc, op, idx, val) { incClass("DATA") },
        global(loc, op, idx, val) { incClass("MEMORY") },

        // special cases
        call_pre(loc, func, args, tableIdx) {
            incClass("CALL");
        },
        const_(loc, op, val) {
            incClass("DATA");
        },
        begin(loc, type, end) {
            // if is already counted by if_ hook, function begin is implicit
            if (type !== "if" && type !== "function") incClass("NOP");
        },
        return_({func, instr}, vals) {
            // do not count implicit returns
            if (instr >= 0) incClass("CALL");
	    Wasabi.analysisResult();
        },
        end(location, type, beginLocation, ifLocation) {
	    incClass("NOP");
	}
    };
}
