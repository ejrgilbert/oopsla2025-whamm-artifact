(module
  (import "call" "inc" (func $inc (param i32 i32)))
  (import "call" "report" (func $report))

  (global $tracking (mut i32) (i32.const 0))
  (global $caller (mut i32) (i32.const 0))

  (func (export "wasm:opcode:call(fid, imm0)") (param $fid i32) (param $imm0 i32))

  (func (export "wasm:opcode:return_call(fid, imm0)") (param $fid i32) (param $imm0 i32))

  (func (export "wasm:opcode:call_indirect(fid)") (param $fid i32))

  (func (export "wasm:opcode:return_call_indirect(fid)") (param $fid i32))

  (func (export "wasm:opcode:call_ref(fid)") (param $fid i32))

  (func (export "wasm:opcode:return_call_ref(fid)") (param $fid i32))

  (func (export "wasm:func:entry(fid)") (param $fid i32))

  (func (export "wasm:exit")
    call $report
  )
)
