#include "src/wasm/wasm-objects-inl.h"

#include "torque-generated/class-verifiers.h"
#include "src/objects/instance-type-inl.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=102&c=1
bool IsWasmFuncRef_NonInline(Tagged<HeapObject> o) {
  return IsWasmFuncRef(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedWasmFuncRef<WasmFuncRef, HeapObject>::WasmFuncRefVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::WasmFuncRefVerify(Cast<WasmFuncRef>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=310&c=1
bool IsWasmNull_NonInline(Tagged<HeapObject> o) {
  return IsWasmNull(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedWasmNull<WasmNull, HeapObject>::WasmNullVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::WasmNullVerify(Cast<WasmNull>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=42&c=1
bool IsWasmImportData_NonInline(Tagged<HeapObject> o) {
  return IsWasmImportData(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedWasmImportData<WasmImportData, TrustedObject>::WasmImportDataVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::WasmImportDataVerify(Cast<WasmImportData>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=32&c=1
bool IsWasmInstanceObject_NonInline(Tagged<HeapObject> o) {
  return IsWasmInstanceObject(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedWasmInstanceObject<WasmInstanceObject, JSObject>::WasmInstanceObjectVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::WasmInstanceObjectVerify(Cast<WasmInstanceObject>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=73&c=1
bool IsWasmInternalFunction_NonInline(Tagged<HeapObject> o) {
  return IsWasmInternalFunction(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedWasmInternalFunction<WasmInternalFunction, ExposedTrustedObject>::WasmInternalFunctionVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::WasmInternalFunctionVerify(Cast<WasmInternalFunction>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=111&c=1
bool IsWasmFunctionData_NonInline(Tagged<HeapObject> o) {
  return IsWasmFunctionData(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedWasmFunctionData<WasmFunctionData, ExposedTrustedObject>::WasmFunctionDataVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::WasmFunctionDataVerify(Cast<WasmFunctionData>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=127&c=1
bool IsWasmExportedFunctionData_NonInline(Tagged<HeapObject> o) {
  return IsWasmExportedFunctionData(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedWasmExportedFunctionData<WasmExportedFunctionData, WasmFunctionData>::WasmExportedFunctionDataVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::WasmExportedFunctionDataVerify(Cast<WasmExportedFunctionData>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=150&c=1
bool IsWasmJSFunctionData_NonInline(Tagged<HeapObject> o) {
  return IsWasmJSFunctionData(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedWasmJSFunctionData<WasmJSFunctionData, WasmFunctionData>::WasmJSFunctionDataVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::WasmJSFunctionDataVerify(Cast<WasmJSFunctionData>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=156&c=1
bool IsWasmCapiFunctionData_NonInline(Tagged<HeapObject> o) {
  return IsWasmCapiFunctionData(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedWasmCapiFunctionData<WasmCapiFunctionData, WasmFunctionData>::WasmCapiFunctionDataVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::WasmCapiFunctionDataVerify(Cast<WasmCapiFunctionData>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=163&c=1
bool IsWasmResumeData_NonInline(Tagged<HeapObject> o) {
  return IsWasmResumeData(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedWasmResumeData<WasmResumeData, HeapObject>::WasmResumeDataVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::WasmResumeDataVerify(Cast<WasmResumeData>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=168&c=1
bool IsWasmContinuationObject_NonInline(Tagged<HeapObject> o) {
  return IsWasmContinuationObject(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedWasmContinuationObject<WasmContinuationObject, HeapObject>::WasmContinuationObjectVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::WasmContinuationObjectVerify(Cast<WasmContinuationObject>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=174&c=1
bool IsWasmSuspenderObject_NonInline(Tagged<HeapObject> o) {
  return IsWasmSuspenderObject(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedWasmSuspenderObject<WasmSuspenderObject, HeapObject>::WasmSuspenderObjectVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::WasmSuspenderObjectVerify(Cast<WasmSuspenderObject>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=183&c=1
bool IsWasmExceptionTag_NonInline(Tagged<HeapObject> o) {
  return IsWasmExceptionTag(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedWasmExceptionTag<WasmExceptionTag, Struct>::WasmExceptionTagVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::WasmExceptionTagVerify(Cast<WasmExceptionTag>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=192&c=1
bool IsWasmModuleObject_NonInline(Tagged<HeapObject> o) {
  return IsWasmModuleObject(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedWasmModuleObject<WasmModuleObject, JSObject>::WasmModuleObjectVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::WasmModuleObjectVerify(Cast<WasmModuleObject>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=199&c=1
bool IsWasmTableObject_NonInline(Tagged<HeapObject> o) {
  return IsWasmTableObject(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedWasmTableObject<WasmTableObject, JSObject>::WasmTableObjectVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::WasmTableObjectVerify(Cast<WasmTableObject>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=232&c=1
bool IsWasmMemoryObject_NonInline(Tagged<HeapObject> o) {
  return IsWasmMemoryObject(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedWasmMemoryObject<WasmMemoryObject, JSObject>::WasmMemoryObjectVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::WasmMemoryObjectVerify(Cast<WasmMemoryObject>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=243&c=1
bool IsWasmMemoryMapDescriptor_NonInline(Tagged<HeapObject> o) {
  return IsWasmMemoryMapDescriptor(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedWasmMemoryMapDescriptor<WasmMemoryMapDescriptor, JSObject>::WasmMemoryMapDescriptorVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::WasmMemoryMapDescriptorVerify(Cast<WasmMemoryMapDescriptor>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=252&c=1
bool IsWasmGlobalObject_NonInline(Tagged<HeapObject> o) {
  return IsWasmGlobalObject(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedWasmGlobalObject<WasmGlobalObject, JSObject>::WasmGlobalObjectVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::WasmGlobalObjectVerify(Cast<WasmGlobalObject>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=266&c=1
bool IsWasmTagObject_NonInline(Tagged<HeapObject> o) {
  return IsWasmTagObject(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedWasmTagObject<WasmTagObject, JSObject>::WasmTagObjectVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::WasmTagObjectVerify(Cast<WasmTagObject>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=275&c=1
bool IsAsmWasmData_NonInline(Tagged<HeapObject> o) {
  return IsAsmWasmData(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedAsmWasmData<AsmWasmData, Struct>::AsmWasmDataVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::AsmWasmDataVerify(Cast<AsmWasmData>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=280&c=1
bool IsWasmTypeInfo_NonInline(Tagged<HeapObject> o) {
  return IsWasmTypeInfo(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedWasmTypeInfo<WasmTypeInfo, HeapObject>::WasmTypeInfoVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::WasmTypeInfoVerify(Cast<WasmTypeInfo>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=288&c=1
bool IsWasmObject_NonInline(Tagged<HeapObject> o) {
  return IsWasmObject(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedWasmObject<WasmObject, JSReceiver>::WasmObjectVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::WasmObjectVerify(Cast<WasmObject>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=291&c=1
bool IsWasmStruct_NonInline(Tagged<HeapObject> o) {
  return IsWasmStruct(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedWasmStruct<WasmStruct, WasmObject>::WasmStructVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::WasmStructVerify(Cast<WasmStruct>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=294&c=1
bool IsWasmArray_NonInline(Tagged<HeapObject> o) {
  return IsWasmArray(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedWasmArray<WasmArray, WasmObject>::WasmArrayVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::WasmArrayVerify(Cast<WasmArray>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=315&c=1
bool IsWasmSuspendingObject_NonInline(Tagged<HeapObject> o) {
  return IsWasmSuspendingObject(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedWasmSuspendingObject<WasmSuspendingObject, JSObject>::WasmSuspendingObjectVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::WasmSuspendingObjectVerify(Cast<WasmSuspendingObject>(*this), isolate);
}


#endif  // VERIFY_HEAP
} // namespace internal
} // namespace v8
