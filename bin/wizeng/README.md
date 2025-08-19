fork: ejrgilbert/wizeng, branch: FOR_WHAMM, commit sha: e4a786735d11e156f2fe32b8ad19a2e0da6fde43

The binaries were built with the following tuning parameters (found in [`wizard-engine/src/engine/Tuning.v3`](https://github.com/titzer/wizard-engine/blob/master/src/engine/Tuning.v3)):

`wizeng.x86-64-linux_default`
- FastIntTuning:enableWhammProbeTrampoline: false
- FastIntTuning:whammProbeTrampolineNumPages: 2048
- SpcTuning:intrinsifyWhammProbe: false
- SpcTuning:inlineSmallFunc: false
- SpcTuning:compileWhammModules: false

`wizeng.x86-64-linux_rt-int`
- FastIntTuning:enableWhammProbeTrampoline: false
- FastIntTuning:whammProbeTrampolineNumPages: 2048
- SpcTuning:intrinsifyWhammProbe: false
- SpcTuning:inlineSmallFunc: false
- SpcTuning:compileWhammModules: false

`wizeng.x86-64-linux_rt-jit`
- FastIntTuning:enableWhammProbeTrampoline: false
- FastIntTuning:whammProbeTrampolineNumPages: 2048
- SpcTuning:intrinsifyWhammProbe: false
- SpcTuning:inlineSmallFunc: false
- SpcTuning:compileWhammModules: true

`wizeng.x86-64-linux_tramp-int`
- FastIntTuning:enableWhammProbeTrampoline: true
- FastIntTuning:whammProbeTrampolineNumPages: 2048
- SpcTuning:intrinsifyWhammProbe: false
- SpcTuning:inlineSmallFunc: false
- SpcTuning:compileWhammModules: false

`wizeng.x86-64-linux_tramp-jit`
- FastIntTuning:enableWhammProbeTrampoline: true
- FastIntTuning:whammProbeTrampolineNumPages: 2048
- SpcTuning:intrinsifyWhammProbe: false
- SpcTuning:inlineSmallFunc: false
- SpcTuning:compileWhammModules: true

`wizeng.x86-64-linux_wasm-int`
- FastIntTuning:enableWhammProbeTrampoline: true
- FastIntTuning:whammProbeTrampolineNumPages: 2048
- SpcTuning:intrinsifyWhammProbe: true
- SpcTuning:inlineSmallFunc: false
- SpcTuning:compileWhammModules: false

`wizeng.x86-64-linux_wasm-jit`
- FastIntTuning:enableWhammProbeTrampoline: true
- FastIntTuning:whammProbeTrampolineNumPages: 2048
- SpcTuning:intrinsifyWhammProbe: true
- SpcTuning:inlineSmallFunc: false
- SpcTuning:compileWhammModules: true

`wizeng.x86-64-linux_inline`
- FastIntTuning:enableWhammProbeTrampoline: true
- FastIntTuning:whammProbeTrampolineNumPages: 2048
- SpcTuning:intrinsifyWhammProbe: true
- SpcTuning:inlineSmallFunc: true
- SpcTuning:compileWhammModules: true

NOTE: It does not make sense to only set `inlineSmallFunc` to `true`.
