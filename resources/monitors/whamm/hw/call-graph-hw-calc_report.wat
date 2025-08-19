(module
  (import "call" "inc" (func $inc (param i32 i32)))
  (import "call" "report" (func $report))

  (global $tracking (mut i32) (i32.const 0))
  (global $caller (mut i32) (i32.const 0))

  (func (export "wasm:opcode:call(fid, imm0)") (param $fid i32) (param $imm0 i32)
    local.get $fid
    local.get $imm0
    call $inc
  )

  (func (export "wasm:opcode:return_call(fid, imm0)") (param $fid i32) (param $imm0 i32)
    local.get $fid
    local.get $imm0
    call $inc
  )

  (func (export "wasm:opcode:call_indirect(fid)") (param $fid i32)
    i32.const 1
    global.set $tracking
    local.get $fid
    global.set $caller
  )

  (func (export "wasm:opcode:return_call_indirect(fid)") (param $fid i32)
    i32.const 1
    global.set $tracking
    local.get $fid
    global.set $caller
  )

  (func (export "wasm:opcode:call_ref(fid)") (param $fid i32)
    i32.const 1
    global.set $tracking
    local.get $fid
    global.set $caller
  )

  (func (export "wasm:opcode:return_call_ref(fid)") (param $fid i32)
    i32.const 1
    global.set $tracking
    local.get $fid
    global.set $caller
  )

  (func (export "wasm:func:entry(fid)") (param $fid i32)
    global.get $tracking
    if
      global.get $caller
      local.get $fid
      call $inc

      i32.const 0
      global.set $tracking
    end
  )

  (func
    call $report
  )
)
