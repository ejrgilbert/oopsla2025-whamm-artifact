use tracer;

// anchors
wasm:func:entry {
    unshared var anchor_id: i32 = tracer.init_anchor(fid as i32, pc as i32);
    tracer.on_anchor(anchor_id);
}
wasm:opcode:loop:before {
    unshared var anchor_id: i32 = tracer.init_anchor(fid as i32, pc as i32);
    tracer.on_anchor(anchor_id);
}

wasm:opcode:*if:before {
    tracer.on_if(arg0 as i32);
}

wasm:opcode:br_table:before {
    tracer.on_br_table(target as i32);
}

wasm:report {
    tracer.flush_csv();
}
