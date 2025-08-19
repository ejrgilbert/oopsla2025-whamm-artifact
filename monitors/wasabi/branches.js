{
    const taken = {};

    Wasabi.analysis = {
        if_(loc, cond) {
            taken[loc.func] = (taken[loc.func] || {});
            taken[loc.func][loc.instr] = (taken[loc.func][loc.instr] || [0, 0]);
            taken[loc.func][loc.instr][cond ? 1 : 0]++;
         },
        br_if(loc, target, cond) {
            taken[loc.func] = (taken[loc.func] || {});
            taken[loc.func][loc.instr] = (taken[loc.func][loc.instr] || [0, 0]);
            taken[loc.func][loc.instr][cond ? 1 : 0]++;
        },
        br_table(loc, tbl, df, idx) {
            taken[loc.func] = (taken[loc.func] || {});
            taken[loc.func][loc.instr] = (taken[loc.func][loc.instr] || Array(tbl.length+1).fill(0));
            taken[loc.func][loc.instr][idx]++;
        },
    };

    Wasabi.analysisResult = function() {
        for (let func in taken) {
            for (let instr in taken[func] ){
                console.log(`func: ${func} instr: ${instr} taken: [${taken[func][instr].toString()}]`)
            }
        }
    };
}