// ==================
// ---- CacheSim ----
// ==================

// CacheSim: instruments memory accesses and simulates a cache attached to the memory.

use cache;

report var hits: u32;
report var misses: u32;
wasm:opcode:*load*|*store*:before {
    var eff_addr: u32 = addr + offset as u32;
    var result: i32 = cache.check_access(eff_addr as i32, data_size as i32);
    var num_hits: i32 = (result & 0xFFFF0000) >> 16;
    var num_misses: i32 = (result & 0x0000FFFF);

    hits = hits + (num_hits as u32);
    misses = misses + (num_misses as u32);
}