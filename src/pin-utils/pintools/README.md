These are the compiled libraries for the `intel64` target.
* `inscountN`: calculates dynamic instruction of the entire program
* `opcodemix`: calculates static and dynamic counts of opcodes
* `isampling` and `itrace`: samples or traces all IPs of executed instructions
* `pinatrace`: traces memory accesses (IP, read/write, address)
* `proccount`: traces calls to routines (number of calls, instructions)
* `dcache`: cache simulator
* `jumpmix`: profiles jumps, branches, and calls
* `catmix`: profiles static and dynamic counts of instructions by category
I disabled some of these (appended `~`) because they have magnificent overhead
and/or generate gigabytes of report files.
