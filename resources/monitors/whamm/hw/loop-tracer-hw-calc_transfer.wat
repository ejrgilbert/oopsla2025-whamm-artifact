(module
  (import "wizeng" "puti" (func $puti (param i32)))
  (import "wizeng" "puts" (func $puts (param i32 i32)))

  ;; imports tracer.wasm
  (import "tracer" "init_anchor" (func $init_anchor (param i32 i32) (result i32)))
  (import "tracer" "on_anchor" (func $on_anchor (param i32)))
  (import "tracer" "on_if" (func $on_if (param i32)))
  (import "tracer" "on_br_table" (func $on_br_table (param i32)))
  (import "tracer" "flush_csv" (func $flush_csv))

  (func (export "$init_anchor") (param i32 i32) (result i32)
    local.get 0
    local.get 1
    call $init_anchor
  )

  (memory (export "mem") 1 1)
  (data (i32.const 0xc00) "func=")
  (data (i32.const 0xd00) ", pc=")
  (data (i32.const 0xe00) "\n")
  
  (func (export "wasm:func:entry($init_anchor(fid, pc))") (param $anchor_id i32))

  (func (export "wasm:opcode:loop($init_anchor(fid, pc))") (param $anchor_id i32))

  (func (export "wasm:opcode:if(arg0)") (param $arg0 i32))

  (func (export "wasm:opcode:br_if(arg0)") (param $arg0 i32))

  (func (export "wasm:opcode:br_table(arg0, num_targets)") (param $arg0 i32) (param $num_targets i32))

  (func (export "wasm:exit")
    call $flush_csv
  )
)
