#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_TRUSTED_OBJECT_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_TRUSTED_OBJECT_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/trusted-object.tq?l=5&c=1
TNode<TrustedObject> Cast_TrustedObject_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/trusted-object.tq?l=9&c=1
TNode<ExposedTrustedObject> Cast_ExposedTrustedObject_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/trusted-object.tq?l=12&c=26
TNode<TrustedPointerT> LoadExposedTrustedObjectSelfIndirectPointer_0(compiler::CodeAssemblerState* state_, TNode<ExposedTrustedObject> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/trusted-object.tq?l=12&c=26
void StoreExposedTrustedObjectSelfIndirectPointer_0(compiler::CodeAssemblerState* state_, TNode<ExposedTrustedObject> p_o, TNode<TrustedPointerT> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/trusted-object.tq?l=5&c=1
TNode<TrustedObject> DownCastForTorqueClass_TrustedObject_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/trusted-object.tq?l=9&c=1
TNode<ExposedTrustedObject> DownCastForTorqueClass_ExposedTrustedObject_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_TRUSTED_OBJECT_TQ_CSA_H_
