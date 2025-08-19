(module
  (import "wizeng" "puti" (func $puti (param i32)))
  (import "wizeng" "puts" (func $puts (param i32 i32)))

  (memory (export "mem") 2)   ;; no expansion checks
  (global $first_entry (mut i32) (i32.const 40))
  (global $last_entry (mut i32) (i32.const 40))

  (data (i32.const 0) "fid=")
  (data (i32.const 4) ", pc=")
  (data (i32.const 9) "\n")

  ;; check whether we should grow memory based on the needed amount
  (func $check_memsize (param $bytes_needed i32)
      (local $bytes_per_page i32)
      (local $curr_pages i32)
      (local $max_needed_addr i32)

      (local.set $bytes_per_page (i32.const 65_536))
      (local.set $curr_pages (memory.size))

      (local.set $max_needed_addr (i32.add (global.get $last_entry) (local.get $bytes_needed)))

      (if (i32.lt_u (i32.mul (local.get $bytes_per_page) (local.get $curr_pages)) (local.get $max_needed_addr))
          (then
              i32.const 1
              memory.grow
              drop
          )
      )
  )

  ;; Table entry
  ;; 0      4      8       12
  ;; | func |  pc  | count |
  (func $alloc (export "$alloc") (param $func i32) (param $pc i32) (result i32)
    (local $entry i32)

    (call $check_memsize (i32.const 12))

    global.get $last_entry
    local.set $entry

    local.get $entry
    local.get $func
    i32.store

    local.get $entry
    local.get $pc
    i32.store offset=4

    local.get $entry
    i32.const 0
    i32.store offset=8

    local.get $entry
    i32.const 12
    i32.add
    global.set $last_entry

    local.get $entry
  )

  (func $print_entries
    (local $entry i32)
    (local $options i32)

    (local.set $entry (global.get $first_entry))
    (block $end_loop
      (loop $loop_entry
        ;; check at the end of memory
        local.get $entry
        global.get $last_entry
        i32.eq
        br_if $end_loop

        (call $puts (i32.const 0) (i32.const 4))
        local.get $entry
        i32.load ;; func
        call $puti
        local.get $entry
        i32.const 4
        i32.add
        local.set $entry

        (call $puts (i32.const 4) (i32.const 5))
        local.get $entry
        i32.load ;; pc
        call $puti
        local.get $entry
        i32.const 4
        i32.add
        local.set $entry

        ;; print number of times reached
        local.get $entry
        (call $puti (i32.load))
        (call $puts (i32.const 9) (i32.const 1))

        local.get $entry
        i32.const 4
        i32.add
        local.set $entry
        br $loop_entry
      )
    )
  )

  (func (export "wasm:block:exit($alloc(fid, pc))") (param $entry i32)
    (i32.store offset=8
      (local.get $entry)
      (i32.add
        (i32.load offset=8 (local.get $entry))
        (i32.const 1)
      )
    )
  )
)
