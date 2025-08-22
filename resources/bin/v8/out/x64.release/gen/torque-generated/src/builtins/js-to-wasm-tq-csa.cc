#include "src/ast/ast.h"
#include "src/builtins/builtins-array-gen.h"
#include "src/builtins/builtins-bigint-gen.h"
#include "src/builtins/builtins-call-gen.h"
#include "src/builtins/builtins-collections-gen.h"
#include "src/builtins/builtins-constructor-gen.h"
#include "src/builtins/builtins-data-view-gen.h"
#include "src/builtins/builtins-iterator-gen.h"
#include "src/builtins/builtins-object-gen.h"
#include "src/builtins/builtins-promise-gen.h"
#include "src/builtins/builtins-promise.h"
#include "src/builtins/builtins-proxy-gen.h"
#include "src/builtins/builtins-regexp-gen.h"
#include "src/builtins/builtins-string-gen.h"
#include "src/builtins/builtins-typed-array-gen.h"
#include "src/builtins/builtins-utils-gen.h"
#include "src/builtins/builtins-wasm-gen.h"
#include "src/builtins/builtins.h"
#include "src/codegen/code-factory.h"
#include "src/debug/debug-wasm-objects.h"
#include "src/heap/factory-inl.h"
#include "src/ic/binary-op-assembler.h"
#include "src/ic/handler-configuration-inl.h"
#include "src/objects/arguments.h"
#include "src/objects/bigint.h"
#include "src/objects/call-site-info.h"
#include "src/objects/elements-kind.h"
#include "src/objects/free-space.h"
#include "src/objects/intl-objects.h"
#include "src/objects/js-atomics-synchronization.h"
#include "src/objects/js-break-iterator.h"
#include "src/objects/js-collator.h"
#include "src/objects/js-date-time-format.h"
#include "src/objects/js-display-names.h"
#include "src/objects/js-disposable-stack.h"
#include "src/objects/js-duration-format.h"
#include "src/objects/js-function.h"
#include "src/objects/js-generator.h"
#include "src/objects/js-iterator-helpers.h"
#include "src/objects/js-list-format.h"
#include "src/objects/js-locale.h"
#include "src/objects/js-number-format.h"
#include "src/objects/js-objects.h"
#include "src/objects/js-plural-rules.h"
#include "src/objects/js-promise.h"
#include "src/objects/js-raw-json.h"
#include "src/objects/js-regexp-string-iterator.h"
#include "src/objects/js-relative-time-format.h"
#include "src/objects/js-segment-iterator-inl.h"
#include "src/objects/js-segmenter.h"
#include "src/objects/js-segments.h"
#include "src/objects/js-shadow-realm.h"
#include "src/objects/js-shared-array.h"
#include "src/objects/js-struct.h"
#include "src/objects/js-temporal-objects.h"
#include "src/objects/js-weak-refs.h"
#include "src/objects/objects.h"
#include "src/objects/ordered-hash-table.h"
#include "src/objects/property-array.h"
#include "src/objects/property-descriptor-object.h"
#include "src/objects/source-text-module.h"
#include "src/objects/swiss-hash-table-helpers.h"
#include "src/objects/swiss-name-dictionary.h"
#include "src/objects/synthetic-module.h"
#include "src/objects/template-objects.h"
#include "src/objects/torque-defined-classes.h"
#include "src/objects/turbofan-types.h"
#include "src/objects/turboshaft-types.h"
#include "src/torque/runtime-support.h"
#include "src/wasm/value-type.h"
#include "src/wasm/wasm-linkage.h"
#include "src/wasm/wasm-module.h"
#include "src/codegen/code-stub-assembler-inl.h"
// Required Builtins:
#include "torque-generated/src/builtins/js-to-wasm-tq-csa.h"
#include "torque-generated/src/builtins/array-findindex-tq-csa.h"
#include "torque-generated/src/builtins/array-flat-tq-csa.h"
#include "torque-generated/src/builtins/array-join-tq-csa.h"
#include "torque-generated/src/builtins/array-splice-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/builtins-bigint-tq-csa.h"
#include "torque-generated/src/builtins/builtins-string-tq-csa.h"
#include "torque-generated/src/builtins/cast-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/frames-tq-csa.h"
#include "torque-generated/src/builtins/frame-arguments-tq-csa.h"
#include "torque-generated/src/builtins/torque-internal-tq-csa.h"
#include "torque-generated/src/objects/contexts-tq-csa.h"
#include "torque-generated/src/objects/fixed-array-tq-csa.h"
#include "torque-generated/src/builtins/js-to-js-tq-csa.h"
#include "torque-generated/src/builtins/js-to-wasm-tq-csa.h"
#include "torque-generated/src/builtins/wasm-tq-csa.h"
#include "torque-generated/src/builtins/wasm-to-js-tq-csa.h"
#include "torque-generated/src/wasm/wasm-objects-tq-csa.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=69&c=1
TNode<Int32T> FromConstexpr_ValueKind_constexpr_kRef_0(compiler::CodeAssemblerState* state_, wasm::ValueKind p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Int32T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.Int32Constant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<Int32T>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Int32T>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=69&c=1
TNode<Int32T> FromConstexpr_ValueKind_constexpr_kRefNull_0(compiler::CodeAssemblerState* state_, wasm::ValueKind p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Int32T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.Int32Constant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<Int32T>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Int32T>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=75&c=1
TNode<Int32T> FromConstexpr_Promise_constexpr_kPromise_0(compiler::CodeAssemblerState* state_, wasm::Promise p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Int32T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.Int32Constant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<Int32T>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Int32T>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=75&c=1
TNode<Int32T> FromConstexpr_Promise_constexpr_kNoPromise_0(compiler::CodeAssemblerState* state_, wasm::Promise p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Int32T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.Int32Constant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<Int32T>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Int32T>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=75&c=1
TNode<Int32T> FromConstexpr_Promise_constexpr_kStressSwitch_0(compiler::CodeAssemblerState* state_, wasm::Promise p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Int32T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.Int32Constant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<Int32T>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Int32T>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=81&c=1
TNode<Int32T> FromConstexpr_HeapType_constexpr_kExtern_0(compiler::CodeAssemblerState* state_, wasm::HeapType::Representation p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Int32T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.Int32Constant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<Int32T>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Int32T>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=81&c=1
TNode<Int32T> FromConstexpr_HeapType_constexpr_kNoExtern_0(compiler::CodeAssemblerState* state_, wasm::HeapType::Representation p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Int32T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.Int32Constant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<Int32T>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Int32T>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=81&c=1
TNode<Int32T> FromConstexpr_HeapType_constexpr_kString_0(compiler::CodeAssemblerState* state_, wasm::HeapType::Representation p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Int32T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.Int32Constant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<Int32T>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Int32T>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=81&c=1
TNode<Int32T> FromConstexpr_HeapType_constexpr_kEq_0(compiler::CodeAssemblerState* state_, wasm::HeapType::Representation p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Int32T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.Int32Constant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<Int32T>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Int32T>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=81&c=1
TNode<Int32T> FromConstexpr_HeapType_constexpr_kI31_0(compiler::CodeAssemblerState* state_, wasm::HeapType::Representation p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Int32T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.Int32Constant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<Int32T>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Int32T>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=81&c=1
TNode<Int32T> FromConstexpr_HeapType_constexpr_kStruct_0(compiler::CodeAssemblerState* state_, wasm::HeapType::Representation p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Int32T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.Int32Constant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<Int32T>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Int32T>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=81&c=1
TNode<Int32T> FromConstexpr_HeapType_constexpr_kArray_0(compiler::CodeAssemblerState* state_, wasm::HeapType::Representation p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Int32T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.Int32Constant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<Int32T>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Int32T>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=81&c=1
TNode<Int32T> FromConstexpr_HeapType_constexpr_kAny_0(compiler::CodeAssemblerState* state_, wasm::HeapType::Representation p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Int32T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.Int32Constant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<Int32T>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Int32T>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=81&c=1
TNode<Int32T> FromConstexpr_HeapType_constexpr_kNone_0(compiler::CodeAssemblerState* state_, wasm::HeapType::Representation p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Int32T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.Int32Constant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<Int32T>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Int32T>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=81&c=1
TNode<Int32T> FromConstexpr_HeapType_constexpr_kFunc_0(compiler::CodeAssemblerState* state_, wasm::HeapType::Representation p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Int32T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.Int32Constant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<Int32T>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Int32T>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=81&c=1
TNode<Int32T> FromConstexpr_HeapType_constexpr_kNoFunc_0(compiler::CodeAssemblerState* state_, wasm::HeapType::Representation p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Int32T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.Int32Constant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<Int32T>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Int32T>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=81&c=1
TNode<Int32T> FromConstexpr_HeapType_constexpr_kExn_0(compiler::CodeAssemblerState* state_, wasm::HeapType::Representation p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Int32T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.Int32Constant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<Int32T>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Int32T>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=81&c=1
TNode<Int32T> FromConstexpr_HeapType_constexpr_kNoExn_0(compiler::CodeAssemblerState* state_, wasm::HeapType::Representation p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Int32T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.Int32Constant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<Int32T>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Int32T>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=149&c=1
TNode<Uint32T> Bitcast_WasmCodePointer_float32_0(compiler::CodeAssemblerState* state_, TNode<Float32T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Uint32T> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).BitcastFloat32ToInt32(TNode<Float32T>{p_v});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Uint32T>{tmp0};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=158&c=1
TNode<IntPtrT> TruncateBigIntToI64_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSAny> p_input) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<BigInt> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<BoolT> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).ToBigInt(TNode<Context>{p_context}, TNode<JSAny>{p_input});
    tmp1 = BigIntBuiltinsAssembler(state_).ReadBigIntLength(TNode<BigInt>{tmp0});
    tmp2 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp3 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp2});
    ca_.Branch(tmp3, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp4;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp4 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.Goto(&block1, tmp4);
  }

  TNode<IntPtrT> tmp5;
  TNode<UintPtrT> tmp6;
  TNode<Uint32T> tmp7;
  TNode<Uint32T> tmp8;
  TNode<BoolT> tmp9;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    tmp5 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp6 = CodeStubAssembler(state_).LoadBigIntDigit(TNode<BigInt>{tmp0}, TNode<IntPtrT>{tmp5});
    tmp7 = BigIntBuiltinsAssembler(state_).ReadBigIntSign(TNode<BigInt>{tmp0});
    tmp8 = kPositiveSign_0(state_);
    tmp9 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T>{tmp7}, TNode<Uint32T>{tmp8});
    ca_.Branch(tmp9, &block8, std::vector<compiler::Node*>{}, &block9, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp10;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    tmp10 = CodeStubAssembler(state_).Signed(TNode<UintPtrT>{tmp6});
    ca_.Goto(&block1, tmp10);
  }

  TNode<IntPtrT> tmp11;
  TNode<IntPtrT> tmp12;
  TNode<IntPtrT> tmp13;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    tmp11 = CodeStubAssembler(state_).Signed(TNode<UintPtrT>{tmp6});
    tmp12 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp13 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{tmp12}, TNode<IntPtrT>{tmp11});
    ca_.Goto(&block1, tmp13);
  }

  TNode<IntPtrT> phi_bb1_2;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_2);
    ca_.Goto(&block10, phi_bb1_2);
  }

  TNode<IntPtrT> phi_bb10_2;
    ca_.Bind(&block10, &phi_bb10_2);
  return TNode<IntPtrT>{phi_bb10_2};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=272&c=1
TorqueStructReturnSlotAllocator_0 NewReturnSlotAllocator_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<BoolT> tmp3;
  TNode<BoolT> tmp4;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_intptr_0(state_, arraysize(wasm::kGpReturnRegisters));
    tmp1 = FromConstexpr_intptr_constexpr_intptr_0(state_, arraysize(wasm::kFpReturnRegisters));
    tmp2 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp3 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp4 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReturnSlotAllocator_0{TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp1}, TNode<BoolT>{tmp3}, TNode<BoolT>{tmp4}, TNode<IntPtrT>{tmp2}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=405&c=1
TorqueStructLocationAllocator_0 LocationAllocatorForParams_0(compiler::CodeAssemblerState* state_, TorqueStructReference_intptr_0 p_paramBuffer, TNode<IntPtrT> p_paramBufferSize) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<IntPtrT> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).UniqueIntPtrConstant(arraysize(wasm::kGpParamRegisters) - 1);
    tmp1 = CodeStubAssembler(state_).UniqueIntPtrConstant(arraysize(wasm::kFpParamRegisters));
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp3 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp2});
    if (((CodeStubAssembler(state_).ConstexprBoolNot((CodeStubAssembler(state_).Is64()))))) {
      ca_.Goto(&block2);
    } else {
      ca_.Goto(&block3);
    }
  }

  TNode<IntPtrT> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<IntPtrT> tmp6;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp5 = CodeStubAssembler(state_).WordAnd(TNode<IntPtrT>{tmp3}, TNode<IntPtrT>{tmp4});
    tmp6 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp3}, TNode<IntPtrT>{tmp5});
    ca_.Goto(&block4, tmp6);
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.Goto(&block4, tmp3);
  }

  TNode<IntPtrT> phi_bb4_7;
  TNode<IntPtrT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<BoolT> tmp12;
  TNode<IntPtrT> tmp13;
  TNode<BoolT> tmp14;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_7);
    tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb4_7}, TNode<IntPtrT>{p_paramBuffer.offset});
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_float64_0(state_)));
    tmp9 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp8});
    tmp10 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp7}, TNode<IntPtrT>{tmp9});
    tmp11 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp12 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp13 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp14 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{p_paramBufferSize}, TNode<IntPtrT>{tmp13});
    ca_.Branch(tmp14, &block9, std::vector<compiler::Node*>{}, &block10, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp15;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    tmp15 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{p_paramBuffer.offset}, TNode<IntPtrT>{p_paramBufferSize});
    ca_.Goto(&block11, tmp15);
  }

  TNode<IntPtrT> tmp16;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    tmp16 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.Goto(&block11, tmp16);
  }

  TNode<IntPtrT> phi_bb11_10;
  if (block11.is_used()) {
    ca_.Bind(&block11, &phi_bb11_10);
    ca_.Goto(&block12);
  }

    ca_.Bind(&block12);
  return TorqueStructLocationAllocator_0{TNode<Union<HeapObject, TaggedIndex>>{p_paramBuffer.object}, TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{p_paramBuffer.offset}, TNode<IntPtrT>{tmp7}, TNode<IntPtrT>{tmp10}, TNode<IntPtrT>{tmp10}, TNode<IntPtrT>{phi_bb11_10}, TNode<IntPtrT>{tmp11}, TNode<BoolT>{tmp12}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=432&c=1
TorqueStructLocationAllocator_0 LocationAllocatorForReturns_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_gpRegs, TNode<RawPtrT> p_fpRegs, TNode<RawPtrT> p_stack) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<TaggedIndex> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<IntPtrT> tmp12;
  TNode<BoolT> tmp13;
  TNode<IntPtrT> tmp14;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = kZeroBitPattern_0(state_);
    tmp1 = FromConstexpr_intptr_constexpr_intptr_0(state_, arraysize(wasm::kGpReturnRegisters));
    tmp2 = FromConstexpr_intptr_constexpr_intptr_0(state_, arraysize(wasm::kFpReturnRegisters));
    tmp3 = Convert_intptr_RawPtr_0(state_, TNode<RawPtrT>{p_gpRegs});
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, kHeapObjectTag);
    tmp5 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp3}, TNode<IntPtrT>{tmp4});
    tmp6 = Convert_intptr_RawPtr_0(state_, TNode<RawPtrT>{p_fpRegs});
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, kHeapObjectTag);
    tmp8 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp6}, TNode<IntPtrT>{tmp7});
    tmp9 = Convert_intptr_RawPtr_0(state_, TNode<RawPtrT>{p_stack});
    tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, kHeapObjectTag);
    tmp11 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp9}, TNode<IntPtrT>{tmp10});
    tmp12 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp13 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp14 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructLocationAllocator_0{TNode<Union<HeapObject, TaggedIndex>>{tmp0}, TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp5}, TNode<IntPtrT>{tmp8}, TNode<IntPtrT>{tmp11}, TNode<IntPtrT>{tmp11}, TNode<IntPtrT>{tmp14}, TNode<IntPtrT>{tmp12}, TNode<BoolT>{tmp13}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=449&c=1
TNode<Object> JSToWasmObject_0(compiler::CodeAssemblerState* state_, TNode<NativeContext> p_context, TNode<Int32T> p_targetType, TNode<JSAny> p_value) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Int32T> tmp1;
  TNode<Int32T> tmp2;
  TNode<Int32T> tmp3;
  TNode<Int32T> tmp4;
  TNode<Int32T> tmp5;
  TNode<Int32T> tmp6;
  TNode<BoolT> tmp7;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::ValueType::kKindBits);
    tmp1 = CodeStubAssembler(state_).Word32Sar(TNode<Int32T>{p_targetType}, TNode<Int32T>{tmp0});
    tmp2 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmHeapTypeBitsMask);
    tmp3 = CodeStubAssembler(state_).Word32And(TNode<Int32T>{tmp1}, TNode<Int32T>{tmp2});
    tmp4 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmValueKindBitsMask);
    tmp5 = CodeStubAssembler(state_).Word32And(TNode<Int32T>{p_targetType}, TNode<Int32T>{tmp4});
    tmp6 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::HeapType::Representation::kExtern);
    tmp7 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp3}, TNode<Int32T>{tmp6});
    ca_.Branch(tmp7, &block2, std::vector<compiler::Node*>{}, &block3, std::vector<compiler::Node*>{});
  }

  TNode<Int32T> tmp8;
  TNode<BoolT> tmp9;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp8 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::ValueKind::kRef);
    tmp9 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp5}, TNode<Int32T>{tmp8});
    ca_.Branch(tmp9, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<Null> tmp10;
  TNode<BoolT> tmp11;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp10 = Null_0(state_);
    tmp11 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{p_value}, TNode<Union<Context, FixedArrayBase, FunctionTemplateInfo, Hole, JSReceiver, Map, Oddball, String, Symbol, WasmFuncRef, WasmNull, WeakCell>>{tmp10});
    ca_.Goto(&block8, tmp11);
  }

  TNode<BoolT> tmp12;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    tmp12 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block8, tmp12);
  }

  TNode<BoolT> phi_bb8_6;
  if (block8.is_used()) {
    ca_.Bind(&block8, &phi_bb8_6);
    ca_.Branch(phi_bb8_6, &block4, std::vector<compiler::Node*>{}, &block5, std::vector<compiler::Node*>{});
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{p_context}, MessageTemplate::kWasmTrapJSTypeError);
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.Goto(&block1, p_value);
  }

  TNode<Int32T> tmp13;
  TNode<BoolT> tmp14;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp13 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::HeapType::Representation::kString);
    tmp14 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp3}, TNode<Int32T>{tmp13});
    ca_.Branch(tmp14, &block9, std::vector<compiler::Node*>{}, &block10, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp15;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    tmp15 = CodeStubAssembler(state_).TaggedIsSmi(TNode<Object>{p_value});
    ca_.Branch(tmp15, &block11, std::vector<compiler::Node*>{}, &block12, std::vector<compiler::Node*>{});
  }

  if (block11.is_used()) {
    ca_.Bind(&block11);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{p_context}, MessageTemplate::kWasmTrapJSTypeError);
  }

  TNode<HeapObject> tmp16;
  TNode<BoolT> tmp17;
  if (block12.is_used()) {
    ca_.Bind(&block12);
    tmp16 = UnsafeCast_HeapObject_0(state_, TNode<Context>{p_context}, TNode<Object>{p_value});
    tmp17 = CodeStubAssembler(state_).IsString(TNode<HeapObject>{tmp16});
    ca_.Branch(tmp17, &block13, std::vector<compiler::Node*>{}, &block14, std::vector<compiler::Node*>{});
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.Goto(&block1, p_value);
  }

  TNode<Null> tmp18;
  TNode<BoolT> tmp19;
  if (block14.is_used()) {
    ca_.Bind(&block14);
    tmp18 = Null_0(state_);
    tmp19 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{p_value}, TNode<Union<Context, FixedArrayBase, FunctionTemplateInfo, Hole, JSReceiver, Map, Oddball, String, Symbol, WasmFuncRef, WasmNull, WeakCell>>{tmp18});
    ca_.Branch(tmp19, &block15, std::vector<compiler::Node*>{}, &block16, std::vector<compiler::Node*>{});
  }

  TNode<Int32T> tmp20;
  TNode<BoolT> tmp21;
  if (block15.is_used()) {
    ca_.Bind(&block15);
    tmp20 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::ValueKind::kRef);
    tmp21 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp5}, TNode<Int32T>{tmp20});
    ca_.Branch(tmp21, &block17, std::vector<compiler::Node*>{}, &block18, std::vector<compiler::Node*>{});
  }

  if (block17.is_used()) {
    ca_.Bind(&block17);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{p_context}, MessageTemplate::kWasmTrapJSTypeError);
  }

  TNode<Int32T> tmp22;
  TNode<BoolT> tmp23;
  if (block18.is_used()) {
    ca_.Bind(&block18);
    tmp22 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::ValueKind::kRefNull);
    tmp23 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp5}, TNode<Int32T>{tmp22});
    ca_.Branch(tmp23, &block20, std::vector<compiler::Node*>{}, &block21, std::vector<compiler::Node*>{});
  }

  if (block21.is_used()) {
    ca_.Bind(&block21);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/js-to-wasm.tq", 470});
      CodeStubAssembler(state_).FailAssert("Torque assert 'kind == ValueKind::kRefNull' failed", pos_stack);
    }
  }

  TNode<WasmNull> tmp24;
  if (block20.is_used()) {
    ca_.Bind(&block20);
    tmp24 = kWasmNull_0(state_);
    ca_.Goto(&block1, tmp24);
  }

  if (block16.is_used()) {
    ca_.Bind(&block16);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{p_context}, MessageTemplate::kWasmTrapJSTypeError);
  }

  TNode<Smi> tmp25;
  TNode<JSAny> tmp26;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    tmp25 = Convert_Smi_int32_0(state_, TNode<Int32T>{p_targetType});
    tmp26 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kWasmGenericJSToWasmObject, p_context, p_value, tmp25)); 
    ca_.Goto(&block1, tmp26);
  }

  TNode<Object> phi_bb1_3;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_3);
    ca_.Goto(&block22, phi_bb1_3);
  }

  TNode<Object> phi_bb22_3;
    ca_.Bind(&block22, &phi_bb22_3);
  return TNode<Object>{phi_bb22_3};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=482&c=1
void HandleF32Params_0(compiler::CodeAssemblerState* state_, TNode<NativeContext> p_context, TorqueStructLocationAllocator_0 p_locationAllocator, TorqueStructReference_intptr_0 p_toRef, TNode<JSAny> p_param) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    if ((wasm::kIsFpAlwaysDouble)) {
      ca_.Goto(&block2);
    } else {
      ca_.Goto(&block3);
    }
  }

  TNode<IntPtrT> tmp0;
  TNode<BoolT> tmp1;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp0 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp1 = CodeStubAssembler(state_).IntPtrGreaterThanOrEqual(TNode<IntPtrT>{p_locationAllocator.remainingFPRegs}, TNode<IntPtrT>{tmp0});
    ca_.Branch(tmp1, &block5, std::vector<compiler::Node*>{}, &block6, std::vector<compiler::Node*>{});
  }

  TNode<Union<HeapObject, TaggedIndex>> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<Float32T> tmp4;
  TNode<Float64T> tmp5;
  TNode<Float64T> tmp6;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    std::tie(tmp2, tmp3) = RefCast_float64_0(state_, TorqueStructReference_intptr_0{TNode<Union<HeapObject, TaggedIndex>>{p_toRef.object}, TNode<IntPtrT>{p_toRef.offset}, TorqueStructUnsafe_0{}}).Flatten();
    tmp4 = ca_.CallBuiltin<Float32T>(Builtin::kWasmTaggedToFloat32, p_context, p_param);
    tmp5 = CodeStubAssembler(state_).ChangeFloat32ToFloat64(TNode<Float32T>{tmp4});
    tmp6 = CodeStubAssembler(state_).Float64SilenceNaN(TNode<Float64T>{tmp5});
    CodeStubAssembler(state_).StoreReference<Float64T>(CodeStubAssembler::Reference{tmp2, tmp3}, tmp6);
    ca_.Goto(&block8);
  }

  TNode<Union<HeapObject, TaggedIndex>> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<Float32T> tmp9;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    std::tie(tmp7, tmp8) = RefCast_float32_0(state_, TorqueStructReference_intptr_0{TNode<Union<HeapObject, TaggedIndex>>{p_toRef.object}, TNode<IntPtrT>{p_toRef.offset}, TorqueStructUnsafe_0{}}).Flatten();
    tmp9 = ca_.CallBuiltin<Float32T>(Builtin::kWasmTaggedToFloat32, p_context, p_param);
    CodeStubAssembler(state_).StoreReference<Float32T>(CodeStubAssembler::Reference{tmp7, tmp8}, tmp9);
    ca_.Goto(&block8);
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.Goto(&block4);
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    if ((wasm::kIsBigEndian)) {
      ca_.Goto(&block9);
    } else {
      ca_.Goto(&block10);
    }
  }

  TNode<Float32T> tmp10;
  TNode<Uint32T> tmp11;
  TNode<IntPtrT> tmp12;
  TNode<IntPtrT> tmp13;
  TNode<IntPtrT> tmp14;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    tmp10 = ca_.CallBuiltin<Float32T>(Builtin::kWasmTaggedToFloat32, p_context, p_param);
    tmp11 = Bitcast_WasmCodePointer_float32_0(state_, TNode<Float32T>{tmp10});
    tmp12 = Convert_intptr_WasmCodePointer_0(state_, TNode<Uint32T>{tmp11});
    tmp13 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x20ull));
    tmp14 = CodeStubAssembler(state_).WordShl(TNode<IntPtrT>{tmp12}, TNode<IntPtrT>{tmp13});
    CodeStubAssembler(state_).StoreReference<IntPtrT>(CodeStubAssembler::Reference{p_toRef.object, p_toRef.offset}, tmp14);
    ca_.Goto(&block11);
  }

  if (block10.is_used()) {
    ca_.Bind(&block10);
    if ((wasm::kIsBigEndianOnSim)) {
      ca_.Goto(&block12);
    } else {
      ca_.Goto(&block13);
    }
  }

  TNode<IntPtrT> tmp15;
  TNode<BoolT> tmp16;
  if (block12.is_used()) {
    ca_.Bind(&block12);
    tmp15 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp16 = CodeStubAssembler(state_).IntPtrGreaterThanOrEqual(TNode<IntPtrT>{p_locationAllocator.remainingFPRegs}, TNode<IntPtrT>{tmp15});
    ca_.Branch(tmp16, &block15, std::vector<compiler::Node*>{}, &block16, std::vector<compiler::Node*>{});
  }

  TNode<Float32T> tmp17;
  TNode<Uint32T> tmp18;
  TNode<IntPtrT> tmp19;
  TNode<IntPtrT> tmp20;
  TNode<IntPtrT> tmp21;
  if (block15.is_used()) {
    ca_.Bind(&block15);
    tmp17 = ca_.CallBuiltin<Float32T>(Builtin::kWasmTaggedToFloat32, p_context, p_param);
    tmp18 = Bitcast_WasmCodePointer_float32_0(state_, TNode<Float32T>{tmp17});
    tmp19 = Convert_intptr_WasmCodePointer_0(state_, TNode<Uint32T>{tmp18});
    tmp20 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x20ull));
    tmp21 = CodeStubAssembler(state_).WordShl(TNode<IntPtrT>{tmp19}, TNode<IntPtrT>{tmp20});
    CodeStubAssembler(state_).StoreReference<IntPtrT>(CodeStubAssembler::Reference{p_toRef.object, p_toRef.offset}, tmp21);
    ca_.Goto(&block18);
  }

  TNode<Float32T> tmp22;
  TNode<Uint32T> tmp23;
  TNode<IntPtrT> tmp24;
  if (block16.is_used()) {
    ca_.Bind(&block16);
    tmp22 = ca_.CallBuiltin<Float32T>(Builtin::kWasmTaggedToFloat32, p_context, p_param);
    tmp23 = Bitcast_WasmCodePointer_float32_0(state_, TNode<Float32T>{tmp22});
    tmp24 = Convert_intptr_WasmCodePointer_0(state_, TNode<Uint32T>{tmp23});
    CodeStubAssembler(state_).StoreReference<IntPtrT>(CodeStubAssembler::Reference{p_toRef.object, p_toRef.offset}, tmp24);
    ca_.Goto(&block18);
  }

  if (block18.is_used()) {
    ca_.Bind(&block18);
    ca_.Goto(&block14);
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.Goto(&block14);
  }

  if (block14.is_used()) {
    ca_.Bind(&block14);
    ca_.Goto(&block11);
  }

  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.Goto(&block4);
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.Goto(&block19);
  }

    ca_.Bind(&block19);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=504&c=1
TNode<JSAny> JSToWasmWrapperHelper_0(compiler::CodeAssemblerState* state_, TNode<NativeContext> p_context, TNode<JSAny> p__receiver, TNode<JSFunction> p_target, TorqueStructArguments p_arguments, wasm::Promise p_promise) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT, IntPtrT> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT, IntPtrT> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block42(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block43(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block45(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block46(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block48(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block49(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block50(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block47(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block41(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block51(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block55(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block56(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block58(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block59(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block61(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block62(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block63(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block60(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block54(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block52(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block53(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block64(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block68(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block69(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block71(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block72(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block74(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block75(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block76(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block73(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block67(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block65(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block77(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block81(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block82(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block83(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block84(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block85(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block80(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block78(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block88(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block89(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT, BoolT> block90(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block87(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block86(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block79(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block66(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block40(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT, IntPtrT> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT, IntPtrT> block91(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT, IntPtrT> block94(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT, IntPtrT> block95(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT, IntPtrT> block99(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT, IntPtrT> block97(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block110(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block111(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT, BoolT> block112(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block108(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block114(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block115(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block117(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block118(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block120(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block121(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block122(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block119(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block113(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block109(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT, IntPtrT> block98(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT, IntPtrT, IntPtrT> block92(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT, IntPtrT, IntPtrT> block124(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT, IntPtrT, IntPtrT> block125(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block123(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT> block130(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT> block129(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT> block131(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT> block132(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, Union<HeapObject, TaggedIndex>, IntPtrT, IntPtrT> block133(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT> block144(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT> block145(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT> block146(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT> block147(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT> block148(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Int32T> block151(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Int32T, Int32T> block153(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Int32T> block149(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Int32T, Int32T> block154(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Int32T> block155(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Int32T, Int32T, Int32T> block156(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Int32T, Int32T> block157(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Int32T> block158(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block162(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block163(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block160(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block166(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block167(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block169(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block170(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block172(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block173(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Union<HeapObject, TaggedIndex>, IntPtrT> block168(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Union<HeapObject, TaggedIndex>, IntPtrT> block165(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Union<HeapObject, TaggedIndex>, IntPtrT> block178(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Union<HeapObject, TaggedIndex>, IntPtrT> block177(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Union<HeapObject, TaggedIndex>, IntPtrT> block176(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Union<HeapObject, TaggedIndex>, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT> block179(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Union<HeapObject, TaggedIndex>, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT> block180(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Union<HeapObject, TaggedIndex>, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT> block181(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Union<HeapObject, TaggedIndex>, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT> block182(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Union<HeapObject, TaggedIndex>, IntPtrT> block174(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block161(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block185(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block186(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block183(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block189(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block190(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block192(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block193(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block195(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block196(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Union<HeapObject, TaggedIndex>, IntPtrT> block191(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Union<HeapObject, TaggedIndex>, IntPtrT> block188(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Union<HeapObject, TaggedIndex>, IntPtrT> block197(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Union<HeapObject, TaggedIndex>, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, Union<HeapObject, TaggedIndex>, IntPtrT> block200(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Union<HeapObject, TaggedIndex>, IntPtrT> block198(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Union<HeapObject, TaggedIndex>, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT> block201(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Union<HeapObject, TaggedIndex>, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT> block202(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Union<HeapObject, TaggedIndex>, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT> block203(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Union<HeapObject, TaggedIndex>, IntPtrT> block199(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block184(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block206(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block207(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block204(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block210(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block211(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block212(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block216(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block217(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block219(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block220(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Union<HeapObject, TaggedIndex>, IntPtrT> block215(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block213(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Union<HeapObject, TaggedIndex>, IntPtrT> block209(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Union<HeapObject, TaggedIndex>, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT> block221(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Union<HeapObject, TaggedIndex>, IntPtrT> block222(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Union<HeapObject, TaggedIndex>, IntPtrT> block223(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block205(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block226(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block227(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block224(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block229(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block233(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block234(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block236(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block237(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block239(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block240(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Union<HeapObject, TaggedIndex>, IntPtrT> block235(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Union<HeapObject, TaggedIndex>, IntPtrT> block232(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Union<HeapObject, TaggedIndex>, IntPtrT> block241(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block230(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block243(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block244(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block246(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block247(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block249(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block250(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Union<HeapObject, TaggedIndex>, IntPtrT> block245(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Union<HeapObject, TaggedIndex>, IntPtrT> block242(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Union<HeapObject, TaggedIndex>, IntPtrT> block252(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Union<HeapObject, TaggedIndex>, IntPtrT> block253(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Union<HeapObject, TaggedIndex>, IntPtrT> block255(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Union<HeapObject, TaggedIndex>, IntPtrT> block256(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Union<HeapObject, TaggedIndex>, IntPtrT> block258(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Union<HeapObject, TaggedIndex>, IntPtrT> block259(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Union<HeapObject, TaggedIndex>, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT> block254(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Union<HeapObject, TaggedIndex>, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT> block251(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Union<HeapObject, TaggedIndex>, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT> block260(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Union<HeapObject, TaggedIndex>, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT> block261(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Union<HeapObject, TaggedIndex>, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT> block262(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Union<HeapObject, TaggedIndex>, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT> block263(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block231(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block225(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block264(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block265(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block268(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block269(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block270(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block273(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block271(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block274(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block275(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, BoolT> block272(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block267(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block266(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block276(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, Union<FixedArray, Smi>, Int32T, Union<FixedArray, Smi>> block279(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, Union<FixedArray, Smi>, Int32T> block277(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, Union<FixedArray, Smi>, Int32T> block280(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, Union<FixedArray, Smi>, Int32T> block281(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, Union<FixedArray, Smi>, Int32T> block278(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, Int32T> block282(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, Int32T> block283(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, Int32T, Int32T> block284(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, Int32T> block289(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, Int32T> block290(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, Int32T> block293(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block228(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block208(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block187(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block164(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Int32T, Int32T> block294(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Int32T> block295(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Int32T> block150(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block296(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block299(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block302(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block300(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block303(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block304(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block301(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block297(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, JSAny> block298(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block305(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block307(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block308(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block310(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block311(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Int32T, Int32T> block314(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Int32T, Int32T, Int32T> block315(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Int32T, Int32T> block312(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Int32T, Int32T, Int32T> block316(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Int32T, Int32T> block318(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Int32T, Int32T> block319(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Int32T, Int32T> block322(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Int32T, Int32T> block323(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Int32T, Int32T> block324(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Int32T, Int32T> block327(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Int32T, Int32T> block328(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Int32T, Int32T> block325(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Int32T, Int32T> block329(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Int32T, Int32T, BoolT> block326(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Int32T, Int32T> block320(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Int32T, Int32T, Int32T, Int32T> block330(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Int32T, Int32T, Int32T> block331(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Int32T, Int32T, Int32T> block332(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Int32T, Int32T> block333(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Int32T, Int32T> block321(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Int32T, Int32T, Union<FixedArray, Smi>> block334(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Int32T, Int32T> block335(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Int32T, Int32T, Int32T, Int32T> block336(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Int32T, Int32T, Int32T> block337(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Int32T, Int32T> block338(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Int32T> block343(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Int32T> block344(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Int32T> block348(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Int32T> block349(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Int32T> block351(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Int32T> block352(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Int32T> block354(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Int32T> block355(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Int32T, Union<HeapObject, TaggedIndex>, IntPtrT> block350(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Int32T, Union<HeapObject, TaggedIndex>, IntPtrT> block347(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Int32T, Union<HeapObject, TaggedIndex>, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT> block356(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Int32T, Union<HeapObject, TaggedIndex>, IntPtrT, Int32T, Int32T> block357(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Int32T, Union<HeapObject, TaggedIndex>, IntPtrT, Int32T> block358(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, Int32T, Int32T> block313(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block306(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, IntPtrT> block361(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, IntPtrT> block362(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block366(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block367(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, BoolT> block368(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block365(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block364(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block369(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block370(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block371(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block372(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block373(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block374(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block375(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block376(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block377(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block378(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block379(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block380(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block381(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block382(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block383(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block384(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block385(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block386(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, JSAny> block389(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block387(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block392(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block390(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, JSAny> block394(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block391(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block397(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block395(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, JSAny> block399(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T> block396(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, JSAny> block393(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, JSAny> block388(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, JSAny> block402(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, JSAny> block403(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, JSAny> block400(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, JSAny> block405(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Union<FixedArray, Smi>, Int32T, JSAny> block401(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT, JSAny, Union<Hole, JSMessageObject>> block143(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT> block406(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny, IntPtrT, BoolT> block407(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny> block409(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<SharedFunctionInfo> tmp1;
  TNode<WasmExportedFunctionData> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    tmp1 = CodeStubAssembler(state_).LoadReference<SharedFunctionInfo>(CodeStubAssembler::Reference{p_target, tmp0});
    tmp2 = CodeStubAssembler(state_).LoadSharedFunctionInfoWasmExportedFunctionData(TNode<SharedFunctionInfo>{tmp1});
    if (((CodeStubAssembler(state_).ConstexprBoolNot(((CodeStubAssembler(state_).ConstexprInt32Equal(p_promise, wasm::Promise::kPromise)) || (CodeStubAssembler(state_).ConstexprInt32Equal(p_promise, wasm::Promise::kStressSwitch))))))) {
      ca_.Goto(&block2);
    } else {
      ca_.Goto(&block3);
    }
  }

  TNode<IntPtrT> tmp3;
  TNode<Cell> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<Object> tmp6;
  TNode<Smi> tmp7;
  TNode<Smi> tmp8;
  TNode<Smi> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<Cell> tmp11;
  TNode<IntPtrT> tmp12;
  TNode<Smi> tmp13;
  TNode<BoolT> tmp14;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 32);
    tmp4 = CodeStubAssembler(state_).LoadReference<Cell>(CodeStubAssembler::Reference{tmp2, tmp3});
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp6 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp4, tmp5});
    tmp7 = UnsafeCast_Smi_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp6});
    tmp8 = SmiConstant_0(state_, IntegerLiteral(false, 0x1ull));
    tmp9 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{tmp7}, TNode<Smi>{tmp8});
    tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, 32);
    tmp11 = CodeStubAssembler(state_).LoadReference<Cell>(CodeStubAssembler::Reference{tmp2, tmp10});
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp11, tmp12}, tmp9);
    tmp13 = SmiConstant_0(state_, IntegerLiteral(false, 0x0ull));
    tmp14 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp9}, TNode<Smi>{tmp13});
    ca_.Branch(tmp14, &block5, std::vector<compiler::Node*>{}, &block6, std::vector<compiler::Node*>{});
  }

  TNode<Smi> tmp15;
  TNode<JSAny> tmp16;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp15 = kNoContext_0(state_);
    tmp16 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kTierUpJSToWasmWrapper, tmp15, tmp2)); 
    ca_.Goto(&block6);
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.Goto(&block4);
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.Goto(&block4);
  }

  TNode<IntPtrT> tmp17;
  TNode<RawPtrT> tmp18;
  TNode<WasmInternalFunction> tmp19;
  TNode<Union<WasmImportData, WasmTrustedInstanceData>> tmp20;
  TNode<IntPtrT> tmp21;
  TNode<Union<HeapObject, TaggedIndex>> tmp22;
  TNode<IntPtrT> tmp23;
  TNode<IntPtrT> tmp24;
  TNode<Int32T> tmp25;
  TNode<IntPtrT> tmp26;
  TNode<Union<HeapObject, TaggedIndex>> tmp27;
  TNode<IntPtrT> tmp28;
  TNode<IntPtrT> tmp29;
  TNode<Int32T> tmp30;
  TNode<IntPtrT> tmp31;
  TNode<Union<HeapObject, TaggedIndex>> tmp32;
  TNode<IntPtrT> tmp33;
  TNode<RawPtrT> tmp34;
  TNode<RawPtrT> tmp35;
  TNode<Int32T> tmp36;
  TNode<IntPtrT> tmp37;
  TNode<Union<HeapObject, TaggedIndex>> tmp38;
  TNode<IntPtrT> tmp39;
  TNode<IntPtrT> tmp40;
  TNode<Undefined> tmp41;
  TNode<IntPtrT> tmp42;
  TNode<BoolT> tmp43;
  TNode<Int32T> tmp44;
  TNode<BoolT> tmp45;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp17 = FromConstexpr_intptr_constexpr_int31_0(state_, 48);
    tmp18 = CodeStubAssembler(state_).LoadReference<RawPtrT>(CodeStubAssembler::Reference{tmp2, tmp17});
    tmp19 = CodeStubAssembler(state_).LoadWasmInternalFunctionFromFunctionData(TNode<WasmFunctionData>{tmp2});
    tmp20 = CodeStubAssembler(state_).LoadImplicitArgFromWasmInternalFunction(TNode<WasmInternalFunction>{tmp19});
    tmp21 = FromConstexpr_intptr_constexpr_intptr_0(state_, wasm::FunctionSig::kParameterCountOffset);
    std::tie(tmp22, tmp23) = GetRefAt_intptr_RawFunctionSigPtr_0(state_, TNode<RawPtrT>{tmp18}, TNode<IntPtrT>{tmp21}).Flatten();
    tmp24 = CodeStubAssembler(state_).LoadReference<IntPtrT>(CodeStubAssembler::Reference{tmp22, tmp23});
    tmp25 = CodeStubAssembler(state_).TruncateIntPtrToInt32(TNode<IntPtrT>{tmp24});
    tmp26 = FromConstexpr_intptr_constexpr_intptr_0(state_, wasm::FunctionSig::kReturnCountOffset);
    std::tie(tmp27, tmp28) = GetRefAt_intptr_RawFunctionSigPtr_0(state_, TNode<RawPtrT>{tmp18}, TNode<IntPtrT>{tmp26}).Flatten();
    tmp29 = CodeStubAssembler(state_).LoadReference<IntPtrT>(CodeStubAssembler::Reference{tmp27, tmp28});
    tmp30 = CodeStubAssembler(state_).TruncateIntPtrToInt32(TNode<IntPtrT>{tmp29});
    tmp31 = FromConstexpr_intptr_constexpr_intptr_0(state_, wasm::FunctionSig::kRepsOffset);
    std::tie(tmp32, tmp33) = GetRefAt_RawPtr_RawFunctionSigPtr_0(state_, TNode<RawPtrT>{tmp18}, TNode<IntPtrT>{tmp31}).Flatten();
    tmp34 = CodeStubAssembler(state_).LoadReference<RawPtrT>(CodeStubAssembler::Reference{tmp32, tmp33});
    tmp35 = (TNode<RawPtrT>{tmp34});
    tmp36 = CodeStubAssembler(state_).Int32Add(TNode<Int32T>{tmp25}, TNode<Int32T>{tmp30});
    tmp37 = Convert_intptr_int32_0(state_, TNode<Int32T>{tmp36});
    std::tie(tmp38, tmp39, tmp40) = NewOffHeapConstSlice_int32_0(state_, TNode<RawPtrT>{tmp35}, TNode<IntPtrT>{tmp37}).Flatten();
    tmp41 = Undefined_0(state_);
    tmp42 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp43 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp44 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp45 = CodeStubAssembler(state_).Int32GreaterThan(TNode<Int32T>{tmp30}, TNode<Int32T>{tmp44});
    ca_.Branch(tmp45, &block7, std::vector<compiler::Node*>{}, &block8, std::vector<compiler::Node*>{tmp41, tmp42, tmp43});
  }

  TNode<Smi> tmp46;
  TNode<JSArray> tmp47;
  TNode<IntPtrT> tmp48;
  TNode<IntPtrT> tmp49;
  TNode<Union<HeapObject, TaggedIndex>> tmp50;
  TNode<IntPtrT> tmp51;
  TNode<IntPtrT> tmp52;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    tmp46 = Convert_Smi_int32_0(state_, TNode<Int32T>{tmp30});
    tmp47 = ca_.CallBuiltin<JSArray>(Builtin::kWasmAllocateJSArray, p_context, tmp46);
    tmp48 = Convert_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp49 = Convert_intptr_int32_0(state_, TNode<Int32T>{tmp30});
    compiler::CodeAssemblerLabel label53(&ca_);
    std::tie(tmp50, tmp51, tmp52) = Subslice_int32_0(state_, TorqueStructSlice_int32_ConstReference_int32_0{TNode<Union<HeapObject, TaggedIndex>>{tmp38}, TNode<IntPtrT>{tmp39}, TNode<IntPtrT>{tmp40}, TorqueStructUnsafe_0{}}, TNode<IntPtrT>{tmp48}, TNode<IntPtrT>{tmp49}, &label53).Flatten();
    ca_.Goto(&block11);
    if (label53.is_used()) {
      ca_.Bind(&label53);
      ca_.Goto(&block12);
    }
  }

  if (block12.is_used()) {
    ca_.Bind(&block12);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp54;
  TNode<IntPtrT> tmp55;
  TNode<BoolT> tmp56;
  TNode<BoolT> tmp57;
  TNode<IntPtrT> tmp58;
  TNode<IntPtrT> tmp59;
  TNode<IntPtrT> tmp60;
  if (block11.is_used()) {
    ca_.Bind(&block11);
    std::tie(tmp54, tmp55, tmp56, tmp57, tmp58) = NewReturnSlotAllocator_0(state_).Flatten();
    tmp59 = TimesSizeOf_int32_0(state_, TNode<IntPtrT>{tmp52});
    tmp60 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp51}, TNode<IntPtrT>{tmp59});
    ca_.Goto(&block16, tmp43, tmp54, tmp55, tmp56, tmp57, tmp58, tmp51);
  }

  TNode<BoolT> phi_bb16_18;
  TNode<IntPtrT> phi_bb16_22;
  TNode<IntPtrT> phi_bb16_23;
  TNode<BoolT> phi_bb16_24;
  TNode<BoolT> phi_bb16_25;
  TNode<IntPtrT> phi_bb16_26;
  TNode<IntPtrT> phi_bb16_28;
  TNode<BoolT> tmp61;
  TNode<BoolT> tmp62;
  if (block16.is_used()) {
    ca_.Bind(&block16, &phi_bb16_18, &phi_bb16_22, &phi_bb16_23, &phi_bb16_24, &phi_bb16_25, &phi_bb16_26, &phi_bb16_28);
    tmp61 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{phi_bb16_28}, TNode<IntPtrT>{tmp60});
    tmp62 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp61});
    ca_.Branch(tmp62, &block14, std::vector<compiler::Node*>{phi_bb16_18, phi_bb16_22, phi_bb16_23, phi_bb16_24, phi_bb16_25, phi_bb16_26, phi_bb16_28}, &block15, std::vector<compiler::Node*>{phi_bb16_18, phi_bb16_22, phi_bb16_23, phi_bb16_24, phi_bb16_25, phi_bb16_26, phi_bb16_28});
  }

  TNode<BoolT> phi_bb14_18;
  TNode<IntPtrT> phi_bb14_22;
  TNode<IntPtrT> phi_bb14_23;
  TNode<BoolT> phi_bb14_24;
  TNode<BoolT> phi_bb14_25;
  TNode<IntPtrT> phi_bb14_26;
  TNode<IntPtrT> phi_bb14_28;
  TNode<Union<HeapObject, TaggedIndex>> tmp63;
  TNode<IntPtrT> tmp64;
  TNode<IntPtrT> tmp65;
  TNode<IntPtrT> tmp66;
  TNode<Int32T> tmp67;
  TNode<Int32T> tmp68;
  TNode<BoolT> tmp69;
  if (block14.is_used()) {
    ca_.Bind(&block14, &phi_bb14_18, &phi_bb14_22, &phi_bb14_23, &phi_bb14_24, &phi_bb14_25, &phi_bb14_26, &phi_bb14_28);
    std::tie(tmp63, tmp64) = NewReference_int32_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp50}, TNode<IntPtrT>{phi_bb14_28}).Flatten();
    tmp65 = FromConstexpr_intptr_constexpr_int31_0(state_, kInt32Size);
    tmp66 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb14_28}, TNode<IntPtrT>{tmp65});
    tmp67 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{tmp63, tmp64});
    tmp68 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmI32.raw_bit_field());
    tmp69 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp67}, TNode<Int32T>{tmp68});
    ca_.Branch(tmp69, &block25, std::vector<compiler::Node*>{phi_bb14_18, phi_bb14_22, phi_bb14_23, phi_bb14_24, phi_bb14_25, phi_bb14_26}, &block26, std::vector<compiler::Node*>{phi_bb14_18, phi_bb14_22, phi_bb14_23, phi_bb14_24, phi_bb14_25, phi_bb14_26});
  }

  TNode<BoolT> phi_bb25_18;
  TNode<IntPtrT> phi_bb25_22;
  TNode<IntPtrT> phi_bb25_23;
  TNode<BoolT> phi_bb25_24;
  TNode<BoolT> phi_bb25_25;
  TNode<IntPtrT> phi_bb25_26;
  TNode<IntPtrT> tmp70;
  TNode<BoolT> tmp71;
  if (block25.is_used()) {
    ca_.Bind(&block25, &phi_bb25_18, &phi_bb25_22, &phi_bb25_23, &phi_bb25_24, &phi_bb25_25, &phi_bb25_26);
    tmp70 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp71 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{phi_bb25_22}, TNode<IntPtrT>{tmp70});
    ca_.Branch(tmp71, &block29, std::vector<compiler::Node*>{phi_bb25_18, phi_bb25_22, phi_bb25_23, phi_bb25_24, phi_bb25_25, phi_bb25_26}, &block30, std::vector<compiler::Node*>{phi_bb25_18, phi_bb25_22, phi_bb25_23, phi_bb25_24, phi_bb25_25, phi_bb25_26});
  }

  TNode<BoolT> phi_bb29_18;
  TNode<IntPtrT> phi_bb29_22;
  TNode<IntPtrT> phi_bb29_23;
  TNode<BoolT> phi_bb29_24;
  TNode<BoolT> phi_bb29_25;
  TNode<IntPtrT> phi_bb29_26;
  TNode<IntPtrT> tmp72;
  TNode<IntPtrT> tmp73;
  if (block29.is_used()) {
    ca_.Bind(&block29, &phi_bb29_18, &phi_bb29_22, &phi_bb29_23, &phi_bb29_24, &phi_bb29_25, &phi_bb29_26);
    tmp72 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp73 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{phi_bb29_22}, TNode<IntPtrT>{tmp72});
    ca_.Goto(&block28, phi_bb29_18, tmp73, phi_bb29_23, phi_bb29_24, phi_bb29_25, phi_bb29_26);
  }

  TNode<BoolT> phi_bb30_18;
  TNode<IntPtrT> phi_bb30_22;
  TNode<IntPtrT> phi_bb30_23;
  TNode<BoolT> phi_bb30_24;
  TNode<BoolT> phi_bb30_25;
  TNode<IntPtrT> phi_bb30_26;
  if (block30.is_used()) {
    ca_.Bind(&block30, &phi_bb30_18, &phi_bb30_22, &phi_bb30_23, &phi_bb30_24, &phi_bb30_25, &phi_bb30_26);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block32, phi_bb30_18, phi_bb30_22, phi_bb30_23, phi_bb30_24, phi_bb30_25, phi_bb30_26);
    } else {
      ca_.Goto(&block33, phi_bb30_18, phi_bb30_22, phi_bb30_23, phi_bb30_24, phi_bb30_25, phi_bb30_26);
    }
  }

  TNode<BoolT> phi_bb32_18;
  TNode<IntPtrT> phi_bb32_22;
  TNode<IntPtrT> phi_bb32_23;
  TNode<BoolT> phi_bb32_24;
  TNode<BoolT> phi_bb32_25;
  TNode<IntPtrT> phi_bb32_26;
  TNode<IntPtrT> tmp74;
  TNode<IntPtrT> tmp75;
  if (block32.is_used()) {
    ca_.Bind(&block32, &phi_bb32_18, &phi_bb32_22, &phi_bb32_23, &phi_bb32_24, &phi_bb32_25, &phi_bb32_26);
    tmp74 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp75 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb32_26}, TNode<IntPtrT>{tmp74});
    ca_.Goto(&block34, phi_bb32_18, phi_bb32_22, phi_bb32_23, phi_bb32_24, phi_bb32_25, tmp75);
  }

  TNode<BoolT> phi_bb33_18;
  TNode<IntPtrT> phi_bb33_22;
  TNode<IntPtrT> phi_bb33_23;
  TNode<BoolT> phi_bb33_24;
  TNode<BoolT> phi_bb33_25;
  TNode<IntPtrT> phi_bb33_26;
  if (block33.is_used()) {
    ca_.Bind(&block33, &phi_bb33_18, &phi_bb33_22, &phi_bb33_23, &phi_bb33_24, &phi_bb33_25, &phi_bb33_26);
    ca_.Branch(phi_bb33_24, &block35, std::vector<compiler::Node*>{phi_bb33_18, phi_bb33_22, phi_bb33_23, phi_bb33_24, phi_bb33_25, phi_bb33_26}, &block36, std::vector<compiler::Node*>{phi_bb33_18, phi_bb33_22, phi_bb33_23, phi_bb33_24, phi_bb33_25, phi_bb33_26});
  }

  TNode<BoolT> phi_bb35_18;
  TNode<IntPtrT> phi_bb35_22;
  TNode<IntPtrT> phi_bb35_23;
  TNode<BoolT> phi_bb35_24;
  TNode<BoolT> phi_bb35_25;
  TNode<IntPtrT> phi_bb35_26;
  TNode<BoolT> tmp76;
  TNode<BoolT> tmp77;
  if (block35.is_used()) {
    ca_.Bind(&block35, &phi_bb35_18, &phi_bb35_22, &phi_bb35_23, &phi_bb35_24, &phi_bb35_25, &phi_bb35_26);
    tmp76 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp77 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block37, phi_bb35_18, phi_bb35_22, phi_bb35_23, tmp76, tmp77, phi_bb35_26);
  }

  TNode<BoolT> phi_bb36_18;
  TNode<IntPtrT> phi_bb36_22;
  TNode<IntPtrT> phi_bb36_23;
  TNode<BoolT> phi_bb36_24;
  TNode<BoolT> phi_bb36_25;
  TNode<IntPtrT> phi_bb36_26;
  TNode<IntPtrT> tmp78;
  TNode<IntPtrT> tmp79;
  TNode<BoolT> tmp80;
  TNode<BoolT> tmp81;
  if (block36.is_used()) {
    ca_.Bind(&block36, &phi_bb36_18, &phi_bb36_22, &phi_bb36_23, &phi_bb36_24, &phi_bb36_25, &phi_bb36_26);
    tmp78 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
    tmp79 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb36_26}, TNode<IntPtrT>{tmp78});
    tmp80 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp81 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block37, phi_bb36_18, phi_bb36_22, phi_bb36_23, tmp80, tmp81, tmp79);
  }

  TNode<BoolT> phi_bb37_18;
  TNode<IntPtrT> phi_bb37_22;
  TNode<IntPtrT> phi_bb37_23;
  TNode<BoolT> phi_bb37_24;
  TNode<BoolT> phi_bb37_25;
  TNode<IntPtrT> phi_bb37_26;
  if (block37.is_used()) {
    ca_.Bind(&block37, &phi_bb37_18, &phi_bb37_22, &phi_bb37_23, &phi_bb37_24, &phi_bb37_25, &phi_bb37_26);
    ca_.Goto(&block34, phi_bb37_18, phi_bb37_22, phi_bb37_23, phi_bb37_24, phi_bb37_25, phi_bb37_26);
  }

  TNode<BoolT> phi_bb34_18;
  TNode<IntPtrT> phi_bb34_22;
  TNode<IntPtrT> phi_bb34_23;
  TNode<BoolT> phi_bb34_24;
  TNode<BoolT> phi_bb34_25;
  TNode<IntPtrT> phi_bb34_26;
  if (block34.is_used()) {
    ca_.Bind(&block34, &phi_bb34_18, &phi_bb34_22, &phi_bb34_23, &phi_bb34_24, &phi_bb34_25, &phi_bb34_26);
    ca_.Goto(&block28, phi_bb34_18, phi_bb34_22, phi_bb34_23, phi_bb34_24, phi_bb34_25, phi_bb34_26);
  }

  TNode<BoolT> phi_bb28_18;
  TNode<IntPtrT> phi_bb28_22;
  TNode<IntPtrT> phi_bb28_23;
  TNode<BoolT> phi_bb28_24;
  TNode<BoolT> phi_bb28_25;
  TNode<IntPtrT> phi_bb28_26;
  if (block28.is_used()) {
    ca_.Bind(&block28, &phi_bb28_18, &phi_bb28_22, &phi_bb28_23, &phi_bb28_24, &phi_bb28_25, &phi_bb28_26);
    ca_.Goto(&block27, phi_bb28_18, phi_bb28_22, phi_bb28_23, phi_bb28_24, phi_bb28_25, phi_bb28_26);
  }

  TNode<BoolT> phi_bb26_18;
  TNode<IntPtrT> phi_bb26_22;
  TNode<IntPtrT> phi_bb26_23;
  TNode<BoolT> phi_bb26_24;
  TNode<BoolT> phi_bb26_25;
  TNode<IntPtrT> phi_bb26_26;
  TNode<Int32T> tmp82;
  TNode<BoolT> tmp83;
  if (block26.is_used()) {
    ca_.Bind(&block26, &phi_bb26_18, &phi_bb26_22, &phi_bb26_23, &phi_bb26_24, &phi_bb26_25, &phi_bb26_26);
    tmp82 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmI64.raw_bit_field());
    tmp83 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp67}, TNode<Int32T>{tmp82});
    ca_.Branch(tmp83, &block38, std::vector<compiler::Node*>{phi_bb26_18, phi_bb26_22, phi_bb26_23, phi_bb26_24, phi_bb26_25, phi_bb26_26}, &block39, std::vector<compiler::Node*>{phi_bb26_18, phi_bb26_22, phi_bb26_23, phi_bb26_24, phi_bb26_25, phi_bb26_26});
  }

  TNode<BoolT> phi_bb38_18;
  TNode<IntPtrT> phi_bb38_22;
  TNode<IntPtrT> phi_bb38_23;
  TNode<BoolT> phi_bb38_24;
  TNode<BoolT> phi_bb38_25;
  TNode<IntPtrT> phi_bb38_26;
  TNode<IntPtrT> tmp84;
  TNode<BoolT> tmp85;
  if (block38.is_used()) {
    ca_.Bind(&block38, &phi_bb38_18, &phi_bb38_22, &phi_bb38_23, &phi_bb38_24, &phi_bb38_25, &phi_bb38_26);
    tmp84 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp85 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{phi_bb38_22}, TNode<IntPtrT>{tmp84});
    ca_.Branch(tmp85, &block42, std::vector<compiler::Node*>{phi_bb38_18, phi_bb38_22, phi_bb38_23, phi_bb38_24, phi_bb38_25, phi_bb38_26}, &block43, std::vector<compiler::Node*>{phi_bb38_18, phi_bb38_22, phi_bb38_23, phi_bb38_24, phi_bb38_25, phi_bb38_26});
  }

  TNode<BoolT> phi_bb42_18;
  TNode<IntPtrT> phi_bb42_22;
  TNode<IntPtrT> phi_bb42_23;
  TNode<BoolT> phi_bb42_24;
  TNode<BoolT> phi_bb42_25;
  TNode<IntPtrT> phi_bb42_26;
  TNode<IntPtrT> tmp86;
  TNode<IntPtrT> tmp87;
  if (block42.is_used()) {
    ca_.Bind(&block42, &phi_bb42_18, &phi_bb42_22, &phi_bb42_23, &phi_bb42_24, &phi_bb42_25, &phi_bb42_26);
    tmp86 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp87 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{phi_bb42_22}, TNode<IntPtrT>{tmp86});
    ca_.Goto(&block41, phi_bb42_18, tmp87, phi_bb42_23, phi_bb42_24, phi_bb42_25, phi_bb42_26);
  }

  TNode<BoolT> phi_bb43_18;
  TNode<IntPtrT> phi_bb43_22;
  TNode<IntPtrT> phi_bb43_23;
  TNode<BoolT> phi_bb43_24;
  TNode<BoolT> phi_bb43_25;
  TNode<IntPtrT> phi_bb43_26;
  if (block43.is_used()) {
    ca_.Bind(&block43, &phi_bb43_18, &phi_bb43_22, &phi_bb43_23, &phi_bb43_24, &phi_bb43_25, &phi_bb43_26);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block45, phi_bb43_18, phi_bb43_22, phi_bb43_23, phi_bb43_24, phi_bb43_25, phi_bb43_26);
    } else {
      ca_.Goto(&block46, phi_bb43_18, phi_bb43_22, phi_bb43_23, phi_bb43_24, phi_bb43_25, phi_bb43_26);
    }
  }

  TNode<BoolT> phi_bb45_18;
  TNode<IntPtrT> phi_bb45_22;
  TNode<IntPtrT> phi_bb45_23;
  TNode<BoolT> phi_bb45_24;
  TNode<BoolT> phi_bb45_25;
  TNode<IntPtrT> phi_bb45_26;
  TNode<IntPtrT> tmp88;
  TNode<IntPtrT> tmp89;
  if (block45.is_used()) {
    ca_.Bind(&block45, &phi_bb45_18, &phi_bb45_22, &phi_bb45_23, &phi_bb45_24, &phi_bb45_25, &phi_bb45_26);
    tmp88 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp89 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb45_26}, TNode<IntPtrT>{tmp88});
    ca_.Goto(&block47, phi_bb45_18, phi_bb45_22, phi_bb45_23, phi_bb45_24, phi_bb45_25, tmp89);
  }

  TNode<BoolT> phi_bb46_18;
  TNode<IntPtrT> phi_bb46_22;
  TNode<IntPtrT> phi_bb46_23;
  TNode<BoolT> phi_bb46_24;
  TNode<BoolT> phi_bb46_25;
  TNode<IntPtrT> phi_bb46_26;
  if (block46.is_used()) {
    ca_.Bind(&block46, &phi_bb46_18, &phi_bb46_22, &phi_bb46_23, &phi_bb46_24, &phi_bb46_25, &phi_bb46_26);
    ca_.Branch(phi_bb46_24, &block48, std::vector<compiler::Node*>{phi_bb46_18, phi_bb46_22, phi_bb46_23, phi_bb46_24, phi_bb46_25, phi_bb46_26}, &block49, std::vector<compiler::Node*>{phi_bb46_18, phi_bb46_22, phi_bb46_23, phi_bb46_24, phi_bb46_25, phi_bb46_26});
  }

  TNode<BoolT> phi_bb48_18;
  TNode<IntPtrT> phi_bb48_22;
  TNode<IntPtrT> phi_bb48_23;
  TNode<BoolT> phi_bb48_24;
  TNode<BoolT> phi_bb48_25;
  TNode<IntPtrT> phi_bb48_26;
  TNode<BoolT> tmp90;
  TNode<BoolT> tmp91;
  if (block48.is_used()) {
    ca_.Bind(&block48, &phi_bb48_18, &phi_bb48_22, &phi_bb48_23, &phi_bb48_24, &phi_bb48_25, &phi_bb48_26);
    tmp90 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp91 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block50, phi_bb48_18, phi_bb48_22, phi_bb48_23, tmp90, tmp91, phi_bb48_26);
  }

  TNode<BoolT> phi_bb49_18;
  TNode<IntPtrT> phi_bb49_22;
  TNode<IntPtrT> phi_bb49_23;
  TNode<BoolT> phi_bb49_24;
  TNode<BoolT> phi_bb49_25;
  TNode<IntPtrT> phi_bb49_26;
  TNode<IntPtrT> tmp92;
  TNode<IntPtrT> tmp93;
  TNode<BoolT> tmp94;
  TNode<BoolT> tmp95;
  if (block49.is_used()) {
    ca_.Bind(&block49, &phi_bb49_18, &phi_bb49_22, &phi_bb49_23, &phi_bb49_24, &phi_bb49_25, &phi_bb49_26);
    tmp92 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
    tmp93 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb49_26}, TNode<IntPtrT>{tmp92});
    tmp94 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp95 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block50, phi_bb49_18, phi_bb49_22, phi_bb49_23, tmp94, tmp95, tmp93);
  }

  TNode<BoolT> phi_bb50_18;
  TNode<IntPtrT> phi_bb50_22;
  TNode<IntPtrT> phi_bb50_23;
  TNode<BoolT> phi_bb50_24;
  TNode<BoolT> phi_bb50_25;
  TNode<IntPtrT> phi_bb50_26;
  if (block50.is_used()) {
    ca_.Bind(&block50, &phi_bb50_18, &phi_bb50_22, &phi_bb50_23, &phi_bb50_24, &phi_bb50_25, &phi_bb50_26);
    ca_.Goto(&block47, phi_bb50_18, phi_bb50_22, phi_bb50_23, phi_bb50_24, phi_bb50_25, phi_bb50_26);
  }

  TNode<BoolT> phi_bb47_18;
  TNode<IntPtrT> phi_bb47_22;
  TNode<IntPtrT> phi_bb47_23;
  TNode<BoolT> phi_bb47_24;
  TNode<BoolT> phi_bb47_25;
  TNode<IntPtrT> phi_bb47_26;
  if (block47.is_used()) {
    ca_.Bind(&block47, &phi_bb47_18, &phi_bb47_22, &phi_bb47_23, &phi_bb47_24, &phi_bb47_25, &phi_bb47_26);
    ca_.Goto(&block41, phi_bb47_18, phi_bb47_22, phi_bb47_23, phi_bb47_24, phi_bb47_25, phi_bb47_26);
  }

  TNode<BoolT> phi_bb41_18;
  TNode<IntPtrT> phi_bb41_22;
  TNode<IntPtrT> phi_bb41_23;
  TNode<BoolT> phi_bb41_24;
  TNode<BoolT> phi_bb41_25;
  TNode<IntPtrT> phi_bb41_26;
  if (block41.is_used()) {
    ca_.Bind(&block41, &phi_bb41_18, &phi_bb41_22, &phi_bb41_23, &phi_bb41_24, &phi_bb41_25, &phi_bb41_26);
    if (((CodeStubAssembler(state_).ConstexprBoolNot((CodeStubAssembler(state_).Is64()))))) {
      ca_.Goto(&block51, phi_bb41_18, phi_bb41_22, phi_bb41_23, phi_bb41_24, phi_bb41_25, phi_bb41_26);
    } else {
      ca_.Goto(&block52, phi_bb41_18, phi_bb41_22, phi_bb41_23, phi_bb41_24, phi_bb41_25, phi_bb41_26);
    }
  }

  TNode<BoolT> phi_bb51_18;
  TNode<IntPtrT> phi_bb51_22;
  TNode<IntPtrT> phi_bb51_23;
  TNode<BoolT> phi_bb51_24;
  TNode<BoolT> phi_bb51_25;
  TNode<IntPtrT> phi_bb51_26;
  TNode<IntPtrT> tmp96;
  TNode<BoolT> tmp97;
  if (block51.is_used()) {
    ca_.Bind(&block51, &phi_bb51_18, &phi_bb51_22, &phi_bb51_23, &phi_bb51_24, &phi_bb51_25, &phi_bb51_26);
    tmp96 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp97 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{phi_bb51_22}, TNode<IntPtrT>{tmp96});
    ca_.Branch(tmp97, &block55, std::vector<compiler::Node*>{phi_bb51_18, phi_bb51_22, phi_bb51_23, phi_bb51_24, phi_bb51_25, phi_bb51_26}, &block56, std::vector<compiler::Node*>{phi_bb51_18, phi_bb51_22, phi_bb51_23, phi_bb51_24, phi_bb51_25, phi_bb51_26});
  }

  TNode<BoolT> phi_bb55_18;
  TNode<IntPtrT> phi_bb55_22;
  TNode<IntPtrT> phi_bb55_23;
  TNode<BoolT> phi_bb55_24;
  TNode<BoolT> phi_bb55_25;
  TNode<IntPtrT> phi_bb55_26;
  TNode<IntPtrT> tmp98;
  TNode<IntPtrT> tmp99;
  if (block55.is_used()) {
    ca_.Bind(&block55, &phi_bb55_18, &phi_bb55_22, &phi_bb55_23, &phi_bb55_24, &phi_bb55_25, &phi_bb55_26);
    tmp98 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp99 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{phi_bb55_22}, TNode<IntPtrT>{tmp98});
    ca_.Goto(&block54, phi_bb55_18, tmp99, phi_bb55_23, phi_bb55_24, phi_bb55_25, phi_bb55_26);
  }

  TNode<BoolT> phi_bb56_18;
  TNode<IntPtrT> phi_bb56_22;
  TNode<IntPtrT> phi_bb56_23;
  TNode<BoolT> phi_bb56_24;
  TNode<BoolT> phi_bb56_25;
  TNode<IntPtrT> phi_bb56_26;
  if (block56.is_used()) {
    ca_.Bind(&block56, &phi_bb56_18, &phi_bb56_22, &phi_bb56_23, &phi_bb56_24, &phi_bb56_25, &phi_bb56_26);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block58, phi_bb56_18, phi_bb56_22, phi_bb56_23, phi_bb56_24, phi_bb56_25, phi_bb56_26);
    } else {
      ca_.Goto(&block59, phi_bb56_18, phi_bb56_22, phi_bb56_23, phi_bb56_24, phi_bb56_25, phi_bb56_26);
    }
  }

  TNode<BoolT> phi_bb58_18;
  TNode<IntPtrT> phi_bb58_22;
  TNode<IntPtrT> phi_bb58_23;
  TNode<BoolT> phi_bb58_24;
  TNode<BoolT> phi_bb58_25;
  TNode<IntPtrT> phi_bb58_26;
  TNode<IntPtrT> tmp100;
  TNode<IntPtrT> tmp101;
  if (block58.is_used()) {
    ca_.Bind(&block58, &phi_bb58_18, &phi_bb58_22, &phi_bb58_23, &phi_bb58_24, &phi_bb58_25, &phi_bb58_26);
    tmp100 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp101 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb58_26}, TNode<IntPtrT>{tmp100});
    ca_.Goto(&block60, phi_bb58_18, phi_bb58_22, phi_bb58_23, phi_bb58_24, phi_bb58_25, tmp101);
  }

  TNode<BoolT> phi_bb59_18;
  TNode<IntPtrT> phi_bb59_22;
  TNode<IntPtrT> phi_bb59_23;
  TNode<BoolT> phi_bb59_24;
  TNode<BoolT> phi_bb59_25;
  TNode<IntPtrT> phi_bb59_26;
  if (block59.is_used()) {
    ca_.Bind(&block59, &phi_bb59_18, &phi_bb59_22, &phi_bb59_23, &phi_bb59_24, &phi_bb59_25, &phi_bb59_26);
    ca_.Branch(phi_bb59_24, &block61, std::vector<compiler::Node*>{phi_bb59_18, phi_bb59_22, phi_bb59_23, phi_bb59_24, phi_bb59_25, phi_bb59_26}, &block62, std::vector<compiler::Node*>{phi_bb59_18, phi_bb59_22, phi_bb59_23, phi_bb59_24, phi_bb59_25, phi_bb59_26});
  }

  TNode<BoolT> phi_bb61_18;
  TNode<IntPtrT> phi_bb61_22;
  TNode<IntPtrT> phi_bb61_23;
  TNode<BoolT> phi_bb61_24;
  TNode<BoolT> phi_bb61_25;
  TNode<IntPtrT> phi_bb61_26;
  TNode<BoolT> tmp102;
  TNode<BoolT> tmp103;
  if (block61.is_used()) {
    ca_.Bind(&block61, &phi_bb61_18, &phi_bb61_22, &phi_bb61_23, &phi_bb61_24, &phi_bb61_25, &phi_bb61_26);
    tmp102 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp103 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block63, phi_bb61_18, phi_bb61_22, phi_bb61_23, tmp102, tmp103, phi_bb61_26);
  }

  TNode<BoolT> phi_bb62_18;
  TNode<IntPtrT> phi_bb62_22;
  TNode<IntPtrT> phi_bb62_23;
  TNode<BoolT> phi_bb62_24;
  TNode<BoolT> phi_bb62_25;
  TNode<IntPtrT> phi_bb62_26;
  TNode<IntPtrT> tmp104;
  TNode<IntPtrT> tmp105;
  TNode<BoolT> tmp106;
  TNode<BoolT> tmp107;
  if (block62.is_used()) {
    ca_.Bind(&block62, &phi_bb62_18, &phi_bb62_22, &phi_bb62_23, &phi_bb62_24, &phi_bb62_25, &phi_bb62_26);
    tmp104 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
    tmp105 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb62_26}, TNode<IntPtrT>{tmp104});
    tmp106 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp107 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block63, phi_bb62_18, phi_bb62_22, phi_bb62_23, tmp106, tmp107, tmp105);
  }

  TNode<BoolT> phi_bb63_18;
  TNode<IntPtrT> phi_bb63_22;
  TNode<IntPtrT> phi_bb63_23;
  TNode<BoolT> phi_bb63_24;
  TNode<BoolT> phi_bb63_25;
  TNode<IntPtrT> phi_bb63_26;
  if (block63.is_used()) {
    ca_.Bind(&block63, &phi_bb63_18, &phi_bb63_22, &phi_bb63_23, &phi_bb63_24, &phi_bb63_25, &phi_bb63_26);
    ca_.Goto(&block60, phi_bb63_18, phi_bb63_22, phi_bb63_23, phi_bb63_24, phi_bb63_25, phi_bb63_26);
  }

  TNode<BoolT> phi_bb60_18;
  TNode<IntPtrT> phi_bb60_22;
  TNode<IntPtrT> phi_bb60_23;
  TNode<BoolT> phi_bb60_24;
  TNode<BoolT> phi_bb60_25;
  TNode<IntPtrT> phi_bb60_26;
  if (block60.is_used()) {
    ca_.Bind(&block60, &phi_bb60_18, &phi_bb60_22, &phi_bb60_23, &phi_bb60_24, &phi_bb60_25, &phi_bb60_26);
    ca_.Goto(&block54, phi_bb60_18, phi_bb60_22, phi_bb60_23, phi_bb60_24, phi_bb60_25, phi_bb60_26);
  }

  TNode<BoolT> phi_bb54_18;
  TNode<IntPtrT> phi_bb54_22;
  TNode<IntPtrT> phi_bb54_23;
  TNode<BoolT> phi_bb54_24;
  TNode<BoolT> phi_bb54_25;
  TNode<IntPtrT> phi_bb54_26;
  if (block54.is_used()) {
    ca_.Bind(&block54, &phi_bb54_18, &phi_bb54_22, &phi_bb54_23, &phi_bb54_24, &phi_bb54_25, &phi_bb54_26);
    ca_.Goto(&block53, phi_bb54_18, phi_bb54_22, phi_bb54_23, phi_bb54_24, phi_bb54_25, phi_bb54_26);
  }

  TNode<BoolT> phi_bb52_18;
  TNode<IntPtrT> phi_bb52_22;
  TNode<IntPtrT> phi_bb52_23;
  TNode<BoolT> phi_bb52_24;
  TNode<BoolT> phi_bb52_25;
  TNode<IntPtrT> phi_bb52_26;
  if (block52.is_used()) {
    ca_.Bind(&block52, &phi_bb52_18, &phi_bb52_22, &phi_bb52_23, &phi_bb52_24, &phi_bb52_25, &phi_bb52_26);
    ca_.Goto(&block53, phi_bb52_18, phi_bb52_22, phi_bb52_23, phi_bb52_24, phi_bb52_25, phi_bb52_26);
  }

  TNode<BoolT> phi_bb53_18;
  TNode<IntPtrT> phi_bb53_22;
  TNode<IntPtrT> phi_bb53_23;
  TNode<BoolT> phi_bb53_24;
  TNode<BoolT> phi_bb53_25;
  TNode<IntPtrT> phi_bb53_26;
  if (block53.is_used()) {
    ca_.Bind(&block53, &phi_bb53_18, &phi_bb53_22, &phi_bb53_23, &phi_bb53_24, &phi_bb53_25, &phi_bb53_26);
    ca_.Goto(&block40, phi_bb53_18, phi_bb53_22, phi_bb53_23, phi_bb53_24, phi_bb53_25, phi_bb53_26);
  }

  TNode<BoolT> phi_bb39_18;
  TNode<IntPtrT> phi_bb39_22;
  TNode<IntPtrT> phi_bb39_23;
  TNode<BoolT> phi_bb39_24;
  TNode<BoolT> phi_bb39_25;
  TNode<IntPtrT> phi_bb39_26;
  TNode<Int32T> tmp108;
  TNode<BoolT> tmp109;
  if (block39.is_used()) {
    ca_.Bind(&block39, &phi_bb39_18, &phi_bb39_22, &phi_bb39_23, &phi_bb39_24, &phi_bb39_25, &phi_bb39_26);
    tmp108 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmF32.raw_bit_field());
    tmp109 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp67}, TNode<Int32T>{tmp108});
    ca_.Branch(tmp109, &block64, std::vector<compiler::Node*>{phi_bb39_18, phi_bb39_22, phi_bb39_23, phi_bb39_24, phi_bb39_25, phi_bb39_26}, &block65, std::vector<compiler::Node*>{phi_bb39_18, phi_bb39_22, phi_bb39_23, phi_bb39_24, phi_bb39_25, phi_bb39_26});
  }

  TNode<BoolT> phi_bb64_18;
  TNode<IntPtrT> phi_bb64_22;
  TNode<IntPtrT> phi_bb64_23;
  TNode<BoolT> phi_bb64_24;
  TNode<BoolT> phi_bb64_25;
  TNode<IntPtrT> phi_bb64_26;
  TNode<IntPtrT> tmp110;
  TNode<BoolT> tmp111;
  if (block64.is_used()) {
    ca_.Bind(&block64, &phi_bb64_18, &phi_bb64_22, &phi_bb64_23, &phi_bb64_24, &phi_bb64_25, &phi_bb64_26);
    tmp110 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp111 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{phi_bb64_23}, TNode<IntPtrT>{tmp110});
    ca_.Branch(tmp111, &block68, std::vector<compiler::Node*>{phi_bb64_18, phi_bb64_22, phi_bb64_23, phi_bb64_24, phi_bb64_25, phi_bb64_26}, &block69, std::vector<compiler::Node*>{phi_bb64_18, phi_bb64_22, phi_bb64_23, phi_bb64_24, phi_bb64_25, phi_bb64_26});
  }

  TNode<BoolT> phi_bb68_18;
  TNode<IntPtrT> phi_bb68_22;
  TNode<IntPtrT> phi_bb68_23;
  TNode<BoolT> phi_bb68_24;
  TNode<BoolT> phi_bb68_25;
  TNode<IntPtrT> phi_bb68_26;
  TNode<IntPtrT> tmp112;
  TNode<IntPtrT> tmp113;
  if (block68.is_used()) {
    ca_.Bind(&block68, &phi_bb68_18, &phi_bb68_22, &phi_bb68_23, &phi_bb68_24, &phi_bb68_25, &phi_bb68_26);
    tmp112 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp113 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{phi_bb68_23}, TNode<IntPtrT>{tmp112});
    ca_.Goto(&block67, phi_bb68_18, phi_bb68_22, tmp113, phi_bb68_24, phi_bb68_25, phi_bb68_26);
  }

  TNode<BoolT> phi_bb69_18;
  TNode<IntPtrT> phi_bb69_22;
  TNode<IntPtrT> phi_bb69_23;
  TNode<BoolT> phi_bb69_24;
  TNode<BoolT> phi_bb69_25;
  TNode<IntPtrT> phi_bb69_26;
  if (block69.is_used()) {
    ca_.Bind(&block69, &phi_bb69_18, &phi_bb69_22, &phi_bb69_23, &phi_bb69_24, &phi_bb69_25, &phi_bb69_26);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block71, phi_bb69_18, phi_bb69_22, phi_bb69_23, phi_bb69_24, phi_bb69_25, phi_bb69_26);
    } else {
      ca_.Goto(&block72, phi_bb69_18, phi_bb69_22, phi_bb69_23, phi_bb69_24, phi_bb69_25, phi_bb69_26);
    }
  }

  TNode<BoolT> phi_bb71_18;
  TNode<IntPtrT> phi_bb71_22;
  TNode<IntPtrT> phi_bb71_23;
  TNode<BoolT> phi_bb71_24;
  TNode<BoolT> phi_bb71_25;
  TNode<IntPtrT> phi_bb71_26;
  TNode<IntPtrT> tmp114;
  TNode<IntPtrT> tmp115;
  if (block71.is_used()) {
    ca_.Bind(&block71, &phi_bb71_18, &phi_bb71_22, &phi_bb71_23, &phi_bb71_24, &phi_bb71_25, &phi_bb71_26);
    tmp114 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp115 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb71_26}, TNode<IntPtrT>{tmp114});
    ca_.Goto(&block73, phi_bb71_18, phi_bb71_22, phi_bb71_23, phi_bb71_24, phi_bb71_25, tmp115);
  }

  TNode<BoolT> phi_bb72_18;
  TNode<IntPtrT> phi_bb72_22;
  TNode<IntPtrT> phi_bb72_23;
  TNode<BoolT> phi_bb72_24;
  TNode<BoolT> phi_bb72_25;
  TNode<IntPtrT> phi_bb72_26;
  if (block72.is_used()) {
    ca_.Bind(&block72, &phi_bb72_18, &phi_bb72_22, &phi_bb72_23, &phi_bb72_24, &phi_bb72_25, &phi_bb72_26);
    ca_.Branch(phi_bb72_24, &block74, std::vector<compiler::Node*>{phi_bb72_18, phi_bb72_22, phi_bb72_23, phi_bb72_24, phi_bb72_25, phi_bb72_26}, &block75, std::vector<compiler::Node*>{phi_bb72_18, phi_bb72_22, phi_bb72_23, phi_bb72_24, phi_bb72_25, phi_bb72_26});
  }

  TNode<BoolT> phi_bb74_18;
  TNode<IntPtrT> phi_bb74_22;
  TNode<IntPtrT> phi_bb74_23;
  TNode<BoolT> phi_bb74_24;
  TNode<BoolT> phi_bb74_25;
  TNode<IntPtrT> phi_bb74_26;
  TNode<BoolT> tmp116;
  TNode<BoolT> tmp117;
  if (block74.is_used()) {
    ca_.Bind(&block74, &phi_bb74_18, &phi_bb74_22, &phi_bb74_23, &phi_bb74_24, &phi_bb74_25, &phi_bb74_26);
    tmp116 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp117 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block76, phi_bb74_18, phi_bb74_22, phi_bb74_23, tmp116, tmp117, phi_bb74_26);
  }

  TNode<BoolT> phi_bb75_18;
  TNode<IntPtrT> phi_bb75_22;
  TNode<IntPtrT> phi_bb75_23;
  TNode<BoolT> phi_bb75_24;
  TNode<BoolT> phi_bb75_25;
  TNode<IntPtrT> phi_bb75_26;
  TNode<IntPtrT> tmp118;
  TNode<IntPtrT> tmp119;
  TNode<BoolT> tmp120;
  TNode<BoolT> tmp121;
  if (block75.is_used()) {
    ca_.Bind(&block75, &phi_bb75_18, &phi_bb75_22, &phi_bb75_23, &phi_bb75_24, &phi_bb75_25, &phi_bb75_26);
    tmp118 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
    tmp119 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb75_26}, TNode<IntPtrT>{tmp118});
    tmp120 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp121 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block76, phi_bb75_18, phi_bb75_22, phi_bb75_23, tmp120, tmp121, tmp119);
  }

  TNode<BoolT> phi_bb76_18;
  TNode<IntPtrT> phi_bb76_22;
  TNode<IntPtrT> phi_bb76_23;
  TNode<BoolT> phi_bb76_24;
  TNode<BoolT> phi_bb76_25;
  TNode<IntPtrT> phi_bb76_26;
  if (block76.is_used()) {
    ca_.Bind(&block76, &phi_bb76_18, &phi_bb76_22, &phi_bb76_23, &phi_bb76_24, &phi_bb76_25, &phi_bb76_26);
    ca_.Goto(&block73, phi_bb76_18, phi_bb76_22, phi_bb76_23, phi_bb76_24, phi_bb76_25, phi_bb76_26);
  }

  TNode<BoolT> phi_bb73_18;
  TNode<IntPtrT> phi_bb73_22;
  TNode<IntPtrT> phi_bb73_23;
  TNode<BoolT> phi_bb73_24;
  TNode<BoolT> phi_bb73_25;
  TNode<IntPtrT> phi_bb73_26;
  if (block73.is_used()) {
    ca_.Bind(&block73, &phi_bb73_18, &phi_bb73_22, &phi_bb73_23, &phi_bb73_24, &phi_bb73_25, &phi_bb73_26);
    ca_.Goto(&block67, phi_bb73_18, phi_bb73_22, phi_bb73_23, phi_bb73_24, phi_bb73_25, phi_bb73_26);
  }

  TNode<BoolT> phi_bb67_18;
  TNode<IntPtrT> phi_bb67_22;
  TNode<IntPtrT> phi_bb67_23;
  TNode<BoolT> phi_bb67_24;
  TNode<BoolT> phi_bb67_25;
  TNode<IntPtrT> phi_bb67_26;
  if (block67.is_used()) {
    ca_.Bind(&block67, &phi_bb67_18, &phi_bb67_22, &phi_bb67_23, &phi_bb67_24, &phi_bb67_25, &phi_bb67_26);
    ca_.Goto(&block66, phi_bb67_18, phi_bb67_22, phi_bb67_23, phi_bb67_24, phi_bb67_25, phi_bb67_26);
  }

  TNode<BoolT> phi_bb65_18;
  TNode<IntPtrT> phi_bb65_22;
  TNode<IntPtrT> phi_bb65_23;
  TNode<BoolT> phi_bb65_24;
  TNode<BoolT> phi_bb65_25;
  TNode<IntPtrT> phi_bb65_26;
  TNode<Int32T> tmp122;
  TNode<BoolT> tmp123;
  if (block65.is_used()) {
    ca_.Bind(&block65, &phi_bb65_18, &phi_bb65_22, &phi_bb65_23, &phi_bb65_24, &phi_bb65_25, &phi_bb65_26);
    tmp122 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmF64.raw_bit_field());
    tmp123 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp67}, TNode<Int32T>{tmp122});
    ca_.Branch(tmp123, &block77, std::vector<compiler::Node*>{phi_bb65_18, phi_bb65_22, phi_bb65_23, phi_bb65_24, phi_bb65_25, phi_bb65_26}, &block78, std::vector<compiler::Node*>{phi_bb65_18, phi_bb65_22, phi_bb65_23, phi_bb65_24, phi_bb65_25, phi_bb65_26});
  }

  TNode<BoolT> phi_bb77_18;
  TNode<IntPtrT> phi_bb77_22;
  TNode<IntPtrT> phi_bb77_23;
  TNode<BoolT> phi_bb77_24;
  TNode<BoolT> phi_bb77_25;
  TNode<IntPtrT> phi_bb77_26;
  TNode<IntPtrT> tmp124;
  TNode<BoolT> tmp125;
  if (block77.is_used()) {
    ca_.Bind(&block77, &phi_bb77_18, &phi_bb77_22, &phi_bb77_23, &phi_bb77_24, &phi_bb77_25, &phi_bb77_26);
    tmp124 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp125 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{phi_bb77_23}, TNode<IntPtrT>{tmp124});
    ca_.Branch(tmp125, &block81, std::vector<compiler::Node*>{phi_bb77_18, phi_bb77_22, phi_bb77_23, phi_bb77_24, phi_bb77_25, phi_bb77_26}, &block82, std::vector<compiler::Node*>{phi_bb77_18, phi_bb77_22, phi_bb77_23, phi_bb77_24, phi_bb77_25, phi_bb77_26});
  }

  TNode<BoolT> phi_bb81_18;
  TNode<IntPtrT> phi_bb81_22;
  TNode<IntPtrT> phi_bb81_23;
  TNode<BoolT> phi_bb81_24;
  TNode<BoolT> phi_bb81_25;
  TNode<IntPtrT> phi_bb81_26;
  TNode<IntPtrT> tmp126;
  TNode<IntPtrT> tmp127;
  if (block81.is_used()) {
    ca_.Bind(&block81, &phi_bb81_18, &phi_bb81_22, &phi_bb81_23, &phi_bb81_24, &phi_bb81_25, &phi_bb81_26);
    tmp126 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp127 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{phi_bb81_23}, TNode<IntPtrT>{tmp126});
    ca_.Goto(&block80, phi_bb81_18, phi_bb81_22, tmp127, phi_bb81_24, phi_bb81_25, phi_bb81_26);
  }

  TNode<BoolT> phi_bb82_18;
  TNode<IntPtrT> phi_bb82_22;
  TNode<IntPtrT> phi_bb82_23;
  TNode<BoolT> phi_bb82_24;
  TNode<BoolT> phi_bb82_25;
  TNode<IntPtrT> phi_bb82_26;
  if (block82.is_used()) {
    ca_.Bind(&block82, &phi_bb82_18, &phi_bb82_22, &phi_bb82_23, &phi_bb82_24, &phi_bb82_25, &phi_bb82_26);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block83, phi_bb82_18, phi_bb82_22, phi_bb82_23, phi_bb82_24, phi_bb82_25, phi_bb82_26);
    } else {
      ca_.Goto(&block84, phi_bb82_18, phi_bb82_22, phi_bb82_23, phi_bb82_24, phi_bb82_25, phi_bb82_26);
    }
  }

  TNode<BoolT> phi_bb83_18;
  TNode<IntPtrT> phi_bb83_22;
  TNode<IntPtrT> phi_bb83_23;
  TNode<BoolT> phi_bb83_24;
  TNode<BoolT> phi_bb83_25;
  TNode<IntPtrT> phi_bb83_26;
  TNode<IntPtrT> tmp128;
  TNode<IntPtrT> tmp129;
  if (block83.is_used()) {
    ca_.Bind(&block83, &phi_bb83_18, &phi_bb83_22, &phi_bb83_23, &phi_bb83_24, &phi_bb83_25, &phi_bb83_26);
    tmp128 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp129 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb83_26}, TNode<IntPtrT>{tmp128});
    ca_.Goto(&block85, phi_bb83_18, phi_bb83_22, phi_bb83_23, phi_bb83_24, phi_bb83_25, tmp129);
  }

  TNode<BoolT> phi_bb84_18;
  TNode<IntPtrT> phi_bb84_22;
  TNode<IntPtrT> phi_bb84_23;
  TNode<BoolT> phi_bb84_24;
  TNode<BoolT> phi_bb84_25;
  TNode<IntPtrT> phi_bb84_26;
  TNode<IntPtrT> tmp130;
  TNode<IntPtrT> tmp131;
  TNode<BoolT> tmp132;
  if (block84.is_used()) {
    ca_.Bind(&block84, &phi_bb84_18, &phi_bb84_22, &phi_bb84_23, &phi_bb84_24, &phi_bb84_25, &phi_bb84_26);
    tmp130 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
    tmp131 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb84_26}, TNode<IntPtrT>{tmp130});
    tmp132 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block85, phi_bb84_18, phi_bb84_22, phi_bb84_23, phi_bb84_24, tmp132, tmp131);
  }

  TNode<BoolT> phi_bb85_18;
  TNode<IntPtrT> phi_bb85_22;
  TNode<IntPtrT> phi_bb85_23;
  TNode<BoolT> phi_bb85_24;
  TNode<BoolT> phi_bb85_25;
  TNode<IntPtrT> phi_bb85_26;
  if (block85.is_used()) {
    ca_.Bind(&block85, &phi_bb85_18, &phi_bb85_22, &phi_bb85_23, &phi_bb85_24, &phi_bb85_25, &phi_bb85_26);
    ca_.Goto(&block80, phi_bb85_18, phi_bb85_22, phi_bb85_23, phi_bb85_24, phi_bb85_25, phi_bb85_26);
  }

  TNode<BoolT> phi_bb80_18;
  TNode<IntPtrT> phi_bb80_22;
  TNode<IntPtrT> phi_bb80_23;
  TNode<BoolT> phi_bb80_24;
  TNode<BoolT> phi_bb80_25;
  TNode<IntPtrT> phi_bb80_26;
  if (block80.is_used()) {
    ca_.Bind(&block80, &phi_bb80_18, &phi_bb80_22, &phi_bb80_23, &phi_bb80_24, &phi_bb80_25, &phi_bb80_26);
    ca_.Goto(&block79, phi_bb80_18, phi_bb80_22, phi_bb80_23, phi_bb80_24, phi_bb80_25, phi_bb80_26);
  }

  TNode<BoolT> phi_bb78_18;
  TNode<IntPtrT> phi_bb78_22;
  TNode<IntPtrT> phi_bb78_23;
  TNode<BoolT> phi_bb78_24;
  TNode<BoolT> phi_bb78_25;
  TNode<IntPtrT> phi_bb78_26;
  TNode<Int32T> tmp133;
  TNode<Int32T> tmp134;
  TNode<Int32T> tmp135;
  TNode<BoolT> tmp136;
  if (block78.is_used()) {
    ca_.Bind(&block78, &phi_bb78_18, &phi_bb78_22, &phi_bb78_23, &phi_bb78_24, &phi_bb78_25, &phi_bb78_26);
    tmp133 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmValueKindBitsMask);
    tmp134 = CodeStubAssembler(state_).Word32And(TNode<Int32T>{tmp67}, TNode<Int32T>{tmp133});
    tmp135 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::ValueKind::kRef);
    tmp136 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp134}, TNode<Int32T>{tmp135});
    ca_.Branch(tmp136, &block88, std::vector<compiler::Node*>{phi_bb78_18, phi_bb78_22, phi_bb78_23, phi_bb78_24, phi_bb78_25, phi_bb78_26}, &block89, std::vector<compiler::Node*>{phi_bb78_18, phi_bb78_22, phi_bb78_23, phi_bb78_24, phi_bb78_25, phi_bb78_26});
  }

  TNode<BoolT> phi_bb88_18;
  TNode<IntPtrT> phi_bb88_22;
  TNode<IntPtrT> phi_bb88_23;
  TNode<BoolT> phi_bb88_24;
  TNode<BoolT> phi_bb88_25;
  TNode<IntPtrT> phi_bb88_26;
  TNode<BoolT> tmp137;
  if (block88.is_used()) {
    ca_.Bind(&block88, &phi_bb88_18, &phi_bb88_22, &phi_bb88_23, &phi_bb88_24, &phi_bb88_25, &phi_bb88_26);
    tmp137 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block90, phi_bb88_18, phi_bb88_22, phi_bb88_23, phi_bb88_24, phi_bb88_25, phi_bb88_26, tmp137);
  }

  TNode<BoolT> phi_bb89_18;
  TNode<IntPtrT> phi_bb89_22;
  TNode<IntPtrT> phi_bb89_23;
  TNode<BoolT> phi_bb89_24;
  TNode<BoolT> phi_bb89_25;
  TNode<IntPtrT> phi_bb89_26;
  TNode<Int32T> tmp138;
  TNode<BoolT> tmp139;
  if (block89.is_used()) {
    ca_.Bind(&block89, &phi_bb89_18, &phi_bb89_22, &phi_bb89_23, &phi_bb89_24, &phi_bb89_25, &phi_bb89_26);
    tmp138 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::ValueKind::kRefNull);
    tmp139 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp134}, TNode<Int32T>{tmp138});
    ca_.Goto(&block90, phi_bb89_18, phi_bb89_22, phi_bb89_23, phi_bb89_24, phi_bb89_25, phi_bb89_26, tmp139);
  }

  TNode<BoolT> phi_bb90_18;
  TNode<IntPtrT> phi_bb90_22;
  TNode<IntPtrT> phi_bb90_23;
  TNode<BoolT> phi_bb90_24;
  TNode<BoolT> phi_bb90_25;
  TNode<IntPtrT> phi_bb90_26;
  TNode<BoolT> phi_bb90_33;
  if (block90.is_used()) {
    ca_.Bind(&block90, &phi_bb90_18, &phi_bb90_22, &phi_bb90_23, &phi_bb90_24, &phi_bb90_25, &phi_bb90_26, &phi_bb90_33);
    ca_.Branch(phi_bb90_33, &block86, std::vector<compiler::Node*>{phi_bb90_18, phi_bb90_22, phi_bb90_23, phi_bb90_24, phi_bb90_25, phi_bb90_26}, &block87, std::vector<compiler::Node*>{phi_bb90_18, phi_bb90_22, phi_bb90_23, phi_bb90_24, phi_bb90_25, phi_bb90_26});
  }

  TNode<BoolT> phi_bb87_18;
  TNode<IntPtrT> phi_bb87_22;
  TNode<IntPtrT> phi_bb87_23;
  TNode<BoolT> phi_bb87_24;
  TNode<BoolT> phi_bb87_25;
  TNode<IntPtrT> phi_bb87_26;
  if (block87.is_used()) {
    ca_.Bind(&block87, &phi_bb87_18, &phi_bb87_22, &phi_bb87_23, &phi_bb87_24, &phi_bb87_25, &phi_bb87_26);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/js-to-wasm.tq", 572});
      CodeStubAssembler(state_).FailAssert("Torque assert 'retKind == ValueKind::kRef || retKind == ValueKind::kRefNull' failed", pos_stack);
    }
  }

  TNode<BoolT> phi_bb86_18;
  TNode<IntPtrT> phi_bb86_22;
  TNode<IntPtrT> phi_bb86_23;
  TNode<BoolT> phi_bb86_24;
  TNode<BoolT> phi_bb86_25;
  TNode<IntPtrT> phi_bb86_26;
  TNode<BoolT> tmp140;
  if (block86.is_used()) {
    ca_.Bind(&block86, &phi_bb86_18, &phi_bb86_22, &phi_bb86_23, &phi_bb86_24, &phi_bb86_25, &phi_bb86_26);
    tmp140 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block79, tmp140, phi_bb86_22, phi_bb86_23, phi_bb86_24, phi_bb86_25, phi_bb86_26);
  }

  TNode<BoolT> phi_bb79_18;
  TNode<IntPtrT> phi_bb79_22;
  TNode<IntPtrT> phi_bb79_23;
  TNode<BoolT> phi_bb79_24;
  TNode<BoolT> phi_bb79_25;
  TNode<IntPtrT> phi_bb79_26;
  if (block79.is_used()) {
    ca_.Bind(&block79, &phi_bb79_18, &phi_bb79_22, &phi_bb79_23, &phi_bb79_24, &phi_bb79_25, &phi_bb79_26);
    ca_.Goto(&block66, phi_bb79_18, phi_bb79_22, phi_bb79_23, phi_bb79_24, phi_bb79_25, phi_bb79_26);
  }

  TNode<BoolT> phi_bb66_18;
  TNode<IntPtrT> phi_bb66_22;
  TNode<IntPtrT> phi_bb66_23;
  TNode<BoolT> phi_bb66_24;
  TNode<BoolT> phi_bb66_25;
  TNode<IntPtrT> phi_bb66_26;
  if (block66.is_used()) {
    ca_.Bind(&block66, &phi_bb66_18, &phi_bb66_22, &phi_bb66_23, &phi_bb66_24, &phi_bb66_25, &phi_bb66_26);
    ca_.Goto(&block40, phi_bb66_18, phi_bb66_22, phi_bb66_23, phi_bb66_24, phi_bb66_25, phi_bb66_26);
  }

  TNode<BoolT> phi_bb40_18;
  TNode<IntPtrT> phi_bb40_22;
  TNode<IntPtrT> phi_bb40_23;
  TNode<BoolT> phi_bb40_24;
  TNode<BoolT> phi_bb40_25;
  TNode<IntPtrT> phi_bb40_26;
  if (block40.is_used()) {
    ca_.Bind(&block40, &phi_bb40_18, &phi_bb40_22, &phi_bb40_23, &phi_bb40_24, &phi_bb40_25, &phi_bb40_26);
    ca_.Goto(&block27, phi_bb40_18, phi_bb40_22, phi_bb40_23, phi_bb40_24, phi_bb40_25, phi_bb40_26);
  }

  TNode<BoolT> phi_bb27_18;
  TNode<IntPtrT> phi_bb27_22;
  TNode<IntPtrT> phi_bb27_23;
  TNode<BoolT> phi_bb27_24;
  TNode<BoolT> phi_bb27_25;
  TNode<IntPtrT> phi_bb27_26;
  if (block27.is_used()) {
    ca_.Bind(&block27, &phi_bb27_18, &phi_bb27_22, &phi_bb27_23, &phi_bb27_24, &phi_bb27_25, &phi_bb27_26);
    ca_.Goto(&block16, phi_bb27_18, phi_bb27_22, phi_bb27_23, phi_bb27_24, phi_bb27_25, phi_bb27_26, tmp66);
  }

  TNode<BoolT> phi_bb15_18;
  TNode<IntPtrT> phi_bb15_22;
  TNode<IntPtrT> phi_bb15_23;
  TNode<BoolT> phi_bb15_24;
  TNode<BoolT> phi_bb15_25;
  TNode<IntPtrT> phi_bb15_26;
  TNode<IntPtrT> phi_bb15_28;
  if (block15.is_used()) {
    ca_.Bind(&block15, &phi_bb15_18, &phi_bb15_22, &phi_bb15_23, &phi_bb15_24, &phi_bb15_25, &phi_bb15_26, &phi_bb15_28);
    ca_.Branch(phi_bb15_18, &block91, std::vector<compiler::Node*>{phi_bb15_18, phi_bb15_22, phi_bb15_23, phi_bb15_24, phi_bb15_25, phi_bb15_26, phi_bb15_28}, &block92, std::vector<compiler::Node*>{phi_bb15_18, phi_bb15_22, phi_bb15_23, phi_bb15_24, phi_bb15_25, phi_bb15_26, phi_bb15_28, tmp60});
  }

  TNode<BoolT> phi_bb91_18;
  TNode<IntPtrT> phi_bb91_22;
  TNode<IntPtrT> phi_bb91_23;
  TNode<BoolT> phi_bb91_24;
  TNode<BoolT> phi_bb91_25;
  TNode<IntPtrT> phi_bb91_26;
  TNode<IntPtrT> phi_bb91_28;
  TNode<BoolT> tmp141;
  if (block91.is_used()) {
    ca_.Bind(&block91, &phi_bb91_18, &phi_bb91_22, &phi_bb91_23, &phi_bb91_24, &phi_bb91_25, &phi_bb91_26, &phi_bb91_28);
    tmp141 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{phi_bb91_25});
    ca_.Branch(tmp141, &block94, std::vector<compiler::Node*>{phi_bb91_18, phi_bb91_22, phi_bb91_23, phi_bb91_24, phi_bb91_25, phi_bb91_26, phi_bb91_28}, &block95, std::vector<compiler::Node*>{phi_bb91_18, phi_bb91_22, phi_bb91_23, phi_bb91_24, phi_bb91_25, phi_bb91_26, phi_bb91_28});
  }

  TNode<BoolT> phi_bb94_18;
  TNode<IntPtrT> phi_bb94_22;
  TNode<IntPtrT> phi_bb94_23;
  TNode<BoolT> phi_bb94_24;
  TNode<BoolT> phi_bb94_25;
  TNode<IntPtrT> phi_bb94_26;
  TNode<IntPtrT> phi_bb94_28;
  TNode<BoolT> tmp142;
  if (block94.is_used()) {
    ca_.Bind(&block94, &phi_bb94_18, &phi_bb94_22, &phi_bb94_23, &phi_bb94_24, &phi_bb94_25, &phi_bb94_26, &phi_bb94_28);
    tmp142 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block95, phi_bb94_18, phi_bb94_22, phi_bb94_23, tmp142, phi_bb94_25, phi_bb94_26, phi_bb94_28);
  }

  TNode<BoolT> phi_bb95_18;
  TNode<IntPtrT> phi_bb95_22;
  TNode<IntPtrT> phi_bb95_23;
  TNode<BoolT> phi_bb95_24;
  TNode<BoolT> phi_bb95_25;
  TNode<IntPtrT> phi_bb95_26;
  TNode<IntPtrT> phi_bb95_28;
  TNode<IntPtrT> tmp143;
  TNode<IntPtrT> tmp144;
  if (block95.is_used()) {
    ca_.Bind(&block95, &phi_bb95_18, &phi_bb95_22, &phi_bb95_23, &phi_bb95_24, &phi_bb95_25, &phi_bb95_26, &phi_bb95_28);
    tmp143 = TimesSizeOf_int32_0(state_, TNode<IntPtrT>{tmp52});
    tmp144 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp51}, TNode<IntPtrT>{tmp143});
    ca_.Goto(&block99, phi_bb95_18, phi_bb95_22, phi_bb95_23, phi_bb95_24, phi_bb95_25, phi_bb95_26, tmp51);
  }

  TNode<BoolT> phi_bb99_18;
  TNode<IntPtrT> phi_bb99_22;
  TNode<IntPtrT> phi_bb99_23;
  TNode<BoolT> phi_bb99_24;
  TNode<BoolT> phi_bb99_25;
  TNode<IntPtrT> phi_bb99_26;
  TNode<IntPtrT> phi_bb99_28;
  TNode<BoolT> tmp145;
  TNode<BoolT> tmp146;
  if (block99.is_used()) {
    ca_.Bind(&block99, &phi_bb99_18, &phi_bb99_22, &phi_bb99_23, &phi_bb99_24, &phi_bb99_25, &phi_bb99_26, &phi_bb99_28);
    tmp145 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{phi_bb99_28}, TNode<IntPtrT>{tmp144});
    tmp146 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp145});
    ca_.Branch(tmp146, &block97, std::vector<compiler::Node*>{phi_bb99_18, phi_bb99_22, phi_bb99_23, phi_bb99_24, phi_bb99_25, phi_bb99_26, phi_bb99_28}, &block98, std::vector<compiler::Node*>{phi_bb99_18, phi_bb99_22, phi_bb99_23, phi_bb99_24, phi_bb99_25, phi_bb99_26, phi_bb99_28});
  }

  TNode<BoolT> phi_bb97_18;
  TNode<IntPtrT> phi_bb97_22;
  TNode<IntPtrT> phi_bb97_23;
  TNode<BoolT> phi_bb97_24;
  TNode<BoolT> phi_bb97_25;
  TNode<IntPtrT> phi_bb97_26;
  TNode<IntPtrT> phi_bb97_28;
  TNode<Union<HeapObject, TaggedIndex>> tmp147;
  TNode<IntPtrT> tmp148;
  TNode<IntPtrT> tmp149;
  TNode<IntPtrT> tmp150;
  TNode<Int32T> tmp151;
  TNode<Int32T> tmp152;
  TNode<Int32T> tmp153;
  TNode<Int32T> tmp154;
  TNode<BoolT> tmp155;
  if (block97.is_used()) {
    ca_.Bind(&block97, &phi_bb97_18, &phi_bb97_22, &phi_bb97_23, &phi_bb97_24, &phi_bb97_25, &phi_bb97_26, &phi_bb97_28);
    std::tie(tmp147, tmp148) = NewReference_int32_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp50}, TNode<IntPtrT>{phi_bb97_28}).Flatten();
    tmp149 = FromConstexpr_intptr_constexpr_int31_0(state_, kInt32Size);
    tmp150 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb97_28}, TNode<IntPtrT>{tmp149});
    tmp151 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{tmp147, tmp148});
    tmp152 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmValueKindBitsMask);
    tmp153 = CodeStubAssembler(state_).Word32And(TNode<Int32T>{tmp151}, TNode<Int32T>{tmp152});
    tmp154 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::ValueKind::kRef);
    tmp155 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp153}, TNode<Int32T>{tmp154});
    ca_.Branch(tmp155, &block110, std::vector<compiler::Node*>{phi_bb97_18, phi_bb97_22, phi_bb97_23, phi_bb97_24, phi_bb97_25, phi_bb97_26}, &block111, std::vector<compiler::Node*>{phi_bb97_18, phi_bb97_22, phi_bb97_23, phi_bb97_24, phi_bb97_25, phi_bb97_26});
  }

  TNode<BoolT> phi_bb110_18;
  TNode<IntPtrT> phi_bb110_22;
  TNode<IntPtrT> phi_bb110_23;
  TNode<BoolT> phi_bb110_24;
  TNode<BoolT> phi_bb110_25;
  TNode<IntPtrT> phi_bb110_26;
  TNode<BoolT> tmp156;
  if (block110.is_used()) {
    ca_.Bind(&block110, &phi_bb110_18, &phi_bb110_22, &phi_bb110_23, &phi_bb110_24, &phi_bb110_25, &phi_bb110_26);
    tmp156 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block112, phi_bb110_18, phi_bb110_22, phi_bb110_23, phi_bb110_24, phi_bb110_25, phi_bb110_26, tmp156);
  }

  TNode<BoolT> phi_bb111_18;
  TNode<IntPtrT> phi_bb111_22;
  TNode<IntPtrT> phi_bb111_23;
  TNode<BoolT> phi_bb111_24;
  TNode<BoolT> phi_bb111_25;
  TNode<IntPtrT> phi_bb111_26;
  TNode<Int32T> tmp157;
  TNode<BoolT> tmp158;
  if (block111.is_used()) {
    ca_.Bind(&block111, &phi_bb111_18, &phi_bb111_22, &phi_bb111_23, &phi_bb111_24, &phi_bb111_25, &phi_bb111_26);
    tmp157 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::ValueKind::kRefNull);
    tmp158 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp153}, TNode<Int32T>{tmp157});
    ca_.Goto(&block112, phi_bb111_18, phi_bb111_22, phi_bb111_23, phi_bb111_24, phi_bb111_25, phi_bb111_26, tmp158);
  }

  TNode<BoolT> phi_bb112_18;
  TNode<IntPtrT> phi_bb112_22;
  TNode<IntPtrT> phi_bb112_23;
  TNode<BoolT> phi_bb112_24;
  TNode<BoolT> phi_bb112_25;
  TNode<IntPtrT> phi_bb112_26;
  TNode<BoolT> phi_bb112_33;
  if (block112.is_used()) {
    ca_.Bind(&block112, &phi_bb112_18, &phi_bb112_22, &phi_bb112_23, &phi_bb112_24, &phi_bb112_25, &phi_bb112_26, &phi_bb112_33);
    ca_.Branch(phi_bb112_33, &block108, std::vector<compiler::Node*>{phi_bb112_18, phi_bb112_22, phi_bb112_23, phi_bb112_24, phi_bb112_25, phi_bb112_26}, &block109, std::vector<compiler::Node*>{phi_bb112_18, phi_bb112_22, phi_bb112_23, phi_bb112_24, phi_bb112_25, phi_bb112_26});
  }

  TNode<BoolT> phi_bb108_18;
  TNode<IntPtrT> phi_bb108_22;
  TNode<IntPtrT> phi_bb108_23;
  TNode<BoolT> phi_bb108_24;
  TNode<BoolT> phi_bb108_25;
  TNode<IntPtrT> phi_bb108_26;
  TNode<IntPtrT> tmp159;
  TNode<BoolT> tmp160;
  if (block108.is_used()) {
    ca_.Bind(&block108, &phi_bb108_18, &phi_bb108_22, &phi_bb108_23, &phi_bb108_24, &phi_bb108_25, &phi_bb108_26);
    tmp159 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp160 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{phi_bb108_22}, TNode<IntPtrT>{tmp159});
    ca_.Branch(tmp160, &block114, std::vector<compiler::Node*>{phi_bb108_18, phi_bb108_22, phi_bb108_23, phi_bb108_24, phi_bb108_25, phi_bb108_26}, &block115, std::vector<compiler::Node*>{phi_bb108_18, phi_bb108_22, phi_bb108_23, phi_bb108_24, phi_bb108_25, phi_bb108_26});
  }

  TNode<BoolT> phi_bb114_18;
  TNode<IntPtrT> phi_bb114_22;
  TNode<IntPtrT> phi_bb114_23;
  TNode<BoolT> phi_bb114_24;
  TNode<BoolT> phi_bb114_25;
  TNode<IntPtrT> phi_bb114_26;
  TNode<IntPtrT> tmp161;
  TNode<IntPtrT> tmp162;
  if (block114.is_used()) {
    ca_.Bind(&block114, &phi_bb114_18, &phi_bb114_22, &phi_bb114_23, &phi_bb114_24, &phi_bb114_25, &phi_bb114_26);
    tmp161 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp162 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{phi_bb114_22}, TNode<IntPtrT>{tmp161});
    ca_.Goto(&block113, phi_bb114_18, tmp162, phi_bb114_23, phi_bb114_24, phi_bb114_25, phi_bb114_26);
  }

  TNode<BoolT> phi_bb115_18;
  TNode<IntPtrT> phi_bb115_22;
  TNode<IntPtrT> phi_bb115_23;
  TNode<BoolT> phi_bb115_24;
  TNode<BoolT> phi_bb115_25;
  TNode<IntPtrT> phi_bb115_26;
  if (block115.is_used()) {
    ca_.Bind(&block115, &phi_bb115_18, &phi_bb115_22, &phi_bb115_23, &phi_bb115_24, &phi_bb115_25, &phi_bb115_26);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block117, phi_bb115_18, phi_bb115_22, phi_bb115_23, phi_bb115_24, phi_bb115_25, phi_bb115_26);
    } else {
      ca_.Goto(&block118, phi_bb115_18, phi_bb115_22, phi_bb115_23, phi_bb115_24, phi_bb115_25, phi_bb115_26);
    }
  }

  TNode<BoolT> phi_bb117_18;
  TNode<IntPtrT> phi_bb117_22;
  TNode<IntPtrT> phi_bb117_23;
  TNode<BoolT> phi_bb117_24;
  TNode<BoolT> phi_bb117_25;
  TNode<IntPtrT> phi_bb117_26;
  TNode<IntPtrT> tmp163;
  TNode<IntPtrT> tmp164;
  if (block117.is_used()) {
    ca_.Bind(&block117, &phi_bb117_18, &phi_bb117_22, &phi_bb117_23, &phi_bb117_24, &phi_bb117_25, &phi_bb117_26);
    tmp163 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp164 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb117_26}, TNode<IntPtrT>{tmp163});
    ca_.Goto(&block119, phi_bb117_18, phi_bb117_22, phi_bb117_23, phi_bb117_24, phi_bb117_25, tmp164);
  }

  TNode<BoolT> phi_bb118_18;
  TNode<IntPtrT> phi_bb118_22;
  TNode<IntPtrT> phi_bb118_23;
  TNode<BoolT> phi_bb118_24;
  TNode<BoolT> phi_bb118_25;
  TNode<IntPtrT> phi_bb118_26;
  if (block118.is_used()) {
    ca_.Bind(&block118, &phi_bb118_18, &phi_bb118_22, &phi_bb118_23, &phi_bb118_24, &phi_bb118_25, &phi_bb118_26);
    ca_.Branch(phi_bb118_24, &block120, std::vector<compiler::Node*>{phi_bb118_18, phi_bb118_22, phi_bb118_23, phi_bb118_24, phi_bb118_25, phi_bb118_26}, &block121, std::vector<compiler::Node*>{phi_bb118_18, phi_bb118_22, phi_bb118_23, phi_bb118_24, phi_bb118_25, phi_bb118_26});
  }

  TNode<BoolT> phi_bb120_18;
  TNode<IntPtrT> phi_bb120_22;
  TNode<IntPtrT> phi_bb120_23;
  TNode<BoolT> phi_bb120_24;
  TNode<BoolT> phi_bb120_25;
  TNode<IntPtrT> phi_bb120_26;
  TNode<BoolT> tmp165;
  TNode<BoolT> tmp166;
  if (block120.is_used()) {
    ca_.Bind(&block120, &phi_bb120_18, &phi_bb120_22, &phi_bb120_23, &phi_bb120_24, &phi_bb120_25, &phi_bb120_26);
    tmp165 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp166 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block122, phi_bb120_18, phi_bb120_22, phi_bb120_23, tmp165, tmp166, phi_bb120_26);
  }

  TNode<BoolT> phi_bb121_18;
  TNode<IntPtrT> phi_bb121_22;
  TNode<IntPtrT> phi_bb121_23;
  TNode<BoolT> phi_bb121_24;
  TNode<BoolT> phi_bb121_25;
  TNode<IntPtrT> phi_bb121_26;
  TNode<IntPtrT> tmp167;
  TNode<IntPtrT> tmp168;
  TNode<BoolT> tmp169;
  TNode<BoolT> tmp170;
  if (block121.is_used()) {
    ca_.Bind(&block121, &phi_bb121_18, &phi_bb121_22, &phi_bb121_23, &phi_bb121_24, &phi_bb121_25, &phi_bb121_26);
    tmp167 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
    tmp168 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb121_26}, TNode<IntPtrT>{tmp167});
    tmp169 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp170 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block122, phi_bb121_18, phi_bb121_22, phi_bb121_23, tmp169, tmp170, tmp168);
  }

  TNode<BoolT> phi_bb122_18;
  TNode<IntPtrT> phi_bb122_22;
  TNode<IntPtrT> phi_bb122_23;
  TNode<BoolT> phi_bb122_24;
  TNode<BoolT> phi_bb122_25;
  TNode<IntPtrT> phi_bb122_26;
  if (block122.is_used()) {
    ca_.Bind(&block122, &phi_bb122_18, &phi_bb122_22, &phi_bb122_23, &phi_bb122_24, &phi_bb122_25, &phi_bb122_26);
    ca_.Goto(&block119, phi_bb122_18, phi_bb122_22, phi_bb122_23, phi_bb122_24, phi_bb122_25, phi_bb122_26);
  }

  TNode<BoolT> phi_bb119_18;
  TNode<IntPtrT> phi_bb119_22;
  TNode<IntPtrT> phi_bb119_23;
  TNode<BoolT> phi_bb119_24;
  TNode<BoolT> phi_bb119_25;
  TNode<IntPtrT> phi_bb119_26;
  if (block119.is_used()) {
    ca_.Bind(&block119, &phi_bb119_18, &phi_bb119_22, &phi_bb119_23, &phi_bb119_24, &phi_bb119_25, &phi_bb119_26);
    ca_.Goto(&block113, phi_bb119_18, phi_bb119_22, phi_bb119_23, phi_bb119_24, phi_bb119_25, phi_bb119_26);
  }

  TNode<BoolT> phi_bb113_18;
  TNode<IntPtrT> phi_bb113_22;
  TNode<IntPtrT> phi_bb113_23;
  TNode<BoolT> phi_bb113_24;
  TNode<BoolT> phi_bb113_25;
  TNode<IntPtrT> phi_bb113_26;
  if (block113.is_used()) {
    ca_.Bind(&block113, &phi_bb113_18, &phi_bb113_22, &phi_bb113_23, &phi_bb113_24, &phi_bb113_25, &phi_bb113_26);
    ca_.Goto(&block109, phi_bb113_18, phi_bb113_22, phi_bb113_23, phi_bb113_24, phi_bb113_25, phi_bb113_26);
  }

  TNode<BoolT> phi_bb109_18;
  TNode<IntPtrT> phi_bb109_22;
  TNode<IntPtrT> phi_bb109_23;
  TNode<BoolT> phi_bb109_24;
  TNode<BoolT> phi_bb109_25;
  TNode<IntPtrT> phi_bb109_26;
  if (block109.is_used()) {
    ca_.Bind(&block109, &phi_bb109_18, &phi_bb109_22, &phi_bb109_23, &phi_bb109_24, &phi_bb109_25, &phi_bb109_26);
    ca_.Goto(&block99, phi_bb109_18, phi_bb109_22, phi_bb109_23, phi_bb109_24, phi_bb109_25, phi_bb109_26, tmp150);
  }

  TNode<BoolT> phi_bb98_18;
  TNode<IntPtrT> phi_bb98_22;
  TNode<IntPtrT> phi_bb98_23;
  TNode<BoolT> phi_bb98_24;
  TNode<BoolT> phi_bb98_25;
  TNode<IntPtrT> phi_bb98_26;
  TNode<IntPtrT> phi_bb98_28;
  if (block98.is_used()) {
    ca_.Bind(&block98, &phi_bb98_18, &phi_bb98_22, &phi_bb98_23, &phi_bb98_24, &phi_bb98_25, &phi_bb98_26, &phi_bb98_28);
    ca_.Goto(&block92, phi_bb98_18, phi_bb98_22, phi_bb98_23, phi_bb98_24, phi_bb98_25, phi_bb98_26, phi_bb98_28, tmp144);
  }

  TNode<BoolT> phi_bb92_18;
  TNode<IntPtrT> phi_bb92_22;
  TNode<IntPtrT> phi_bb92_23;
  TNode<BoolT> phi_bb92_24;
  TNode<BoolT> phi_bb92_25;
  TNode<IntPtrT> phi_bb92_26;
  TNode<IntPtrT> phi_bb92_28;
  TNode<IntPtrT> phi_bb92_29;
  if (block92.is_used()) {
    ca_.Bind(&block92, &phi_bb92_18, &phi_bb92_22, &phi_bb92_23, &phi_bb92_24, &phi_bb92_25, &phi_bb92_26, &phi_bb92_28, &phi_bb92_29);
    ca_.Branch(phi_bb92_25, &block124, std::vector<compiler::Node*>{phi_bb92_18, phi_bb92_22, phi_bb92_23, phi_bb92_24, phi_bb92_25, phi_bb92_26, phi_bb92_28, phi_bb92_29}, &block125, std::vector<compiler::Node*>{phi_bb92_18, phi_bb92_22, phi_bb92_23, phi_bb92_24, phi_bb92_25, phi_bb92_26, phi_bb92_28, phi_bb92_29});
  }

  TNode<BoolT> phi_bb124_18;
  TNode<IntPtrT> phi_bb124_22;
  TNode<IntPtrT> phi_bb124_23;
  TNode<BoolT> phi_bb124_24;
  TNode<BoolT> phi_bb124_25;
  TNode<IntPtrT> phi_bb124_26;
  TNode<IntPtrT> phi_bb124_28;
  TNode<IntPtrT> phi_bb124_29;
  TNode<IntPtrT> tmp171;
  TNode<IntPtrT> tmp172;
  if (block124.is_used()) {
    ca_.Bind(&block124, &phi_bb124_18, &phi_bb124_22, &phi_bb124_23, &phi_bb124_24, &phi_bb124_25, &phi_bb124_26, &phi_bb124_28, &phi_bb124_29);
    tmp171 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp172 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{phi_bb124_26}, TNode<IntPtrT>{tmp171});
    ca_.Goto(&block123, phi_bb124_18, phi_bb124_22, phi_bb124_23, phi_bb124_24, phi_bb124_25, phi_bb124_26, phi_bb124_28, phi_bb124_29, tmp172);
  }

  TNode<BoolT> phi_bb125_18;
  TNode<IntPtrT> phi_bb125_22;
  TNode<IntPtrT> phi_bb125_23;
  TNode<BoolT> phi_bb125_24;
  TNode<BoolT> phi_bb125_25;
  TNode<IntPtrT> phi_bb125_26;
  TNode<IntPtrT> phi_bb125_28;
  TNode<IntPtrT> phi_bb125_29;
  if (block125.is_used()) {
    ca_.Bind(&block125, &phi_bb125_18, &phi_bb125_22, &phi_bb125_23, &phi_bb125_24, &phi_bb125_25, &phi_bb125_26, &phi_bb125_28, &phi_bb125_29);
    ca_.Goto(&block123, phi_bb125_18, phi_bb125_22, phi_bb125_23, phi_bb125_24, phi_bb125_25, phi_bb125_26, phi_bb125_28, phi_bb125_29, phi_bb125_26);
  }

  TNode<BoolT> phi_bb123_18;
  TNode<IntPtrT> phi_bb123_22;
  TNode<IntPtrT> phi_bb123_23;
  TNode<BoolT> phi_bb123_24;
  TNode<BoolT> phi_bb123_25;
  TNode<IntPtrT> phi_bb123_26;
  TNode<IntPtrT> phi_bb123_28;
  TNode<IntPtrT> phi_bb123_29;
  TNode<IntPtrT> phi_bb123_30;
  if (block123.is_used()) {
    ca_.Bind(&block123, &phi_bb123_18, &phi_bb123_22, &phi_bb123_23, &phi_bb123_24, &phi_bb123_25, &phi_bb123_26, &phi_bb123_28, &phi_bb123_29, &phi_bb123_30);
    ca_.Goto(&block8, tmp47, phi_bb123_30, phi_bb123_18);
  }

  TNode<JSAny> phi_bb8_16;
  TNode<IntPtrT> phi_bb8_17;
  TNode<BoolT> phi_bb8_18;
  TNode<IntPtrT> tmp173;
  TNode<IntPtrT> tmp174;
  TNode<Union<HeapObject, TaggedIndex>> tmp175;
  TNode<IntPtrT> tmp176;
  TNode<IntPtrT> tmp177;
  if (block8.is_used()) {
    ca_.Bind(&block8, &phi_bb8_16, &phi_bb8_17, &phi_bb8_18);
    tmp173 = Convert_intptr_int32_0(state_, TNode<Int32T>{tmp30});
    tmp174 = Convert_intptr_int32_0(state_, TNode<Int32T>{tmp25});
    compiler::CodeAssemblerLabel label178(&ca_);
    std::tie(tmp175, tmp176, tmp177) = Subslice_int32_0(state_, TorqueStructSlice_int32_ConstReference_int32_0{TNode<Union<HeapObject, TaggedIndex>>{tmp38}, TNode<IntPtrT>{tmp39}, TNode<IntPtrT>{tmp40}, TorqueStructUnsafe_0{}}, TNode<IntPtrT>{tmp173}, TNode<IntPtrT>{tmp174}, &label178).Flatten();
    ca_.Goto(&block129, phi_bb8_16, phi_bb8_17, phi_bb8_18);
    if (label178.is_used()) {
      ca_.Bind(&label178);
      ca_.Goto(&block130, phi_bb8_16, phi_bb8_17, phi_bb8_18);
    }
  }

  TNode<JSAny> phi_bb130_16;
  TNode<IntPtrT> phi_bb130_17;
  TNode<BoolT> phi_bb130_18;
  if (block130.is_used()) {
    ca_.Bind(&block130, &phi_bb130_16, &phi_bb130_17, &phi_bb130_18);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<JSAny> phi_bb129_16;
  TNode<IntPtrT> phi_bb129_17;
  TNode<BoolT> phi_bb129_18;
  TNode<Int32T> tmp179;
  TNode<BoolT> tmp180;
  if (block129.is_used()) {
    ca_.Bind(&block129, &phi_bb129_16, &phi_bb129_17, &phi_bb129_18);
    tmp179 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0xaull));
    tmp180 = CodeStubAssembler(state_).Int32LessThanOrEqual(TNode<Int32T>{tmp25}, TNode<Int32T>{tmp179});
    ca_.Branch(tmp180, &block131, std::vector<compiler::Node*>{phi_bb129_16, phi_bb129_17, phi_bb129_18}, &block132, std::vector<compiler::Node*>{phi_bb129_16, phi_bb129_17, phi_bb129_18});
  }

  TNode<JSAny> phi_bb131_16;
  TNode<IntPtrT> phi_bb131_17;
  TNode<BoolT> phi_bb131_18;
  TNode<RawPtrT> tmp181;
  TNode<RawPtrT> tmp182;
  TNode<IntPtrT> tmp183;
  TNode<Union<HeapObject, TaggedIndex>> tmp184;
  TNode<IntPtrT> tmp185;
  if (block131.is_used()) {
    ca_.Bind(&block131, &phi_bb131_16, &phi_bb131_17, &phi_bb131_18);
    tmp181 = CodeStubAssembler(state_).StackSlotPtr((CodeStubAssembler(state_).ConstexprInt31Mul((FromConstexpr_constexpr_int31_constexpr_IntegerLiteral_0(state_, (CodeStubAssembler(state_).ConstexprIntegerLiteralAdd((CodeStubAssembler(state_).ConstexprIntegerLiteralAdd(IntegerLiteral(false, 0xaull), IntegerLiteral(false, 0x8ull))), IntegerLiteral(false, 0x2ull))))), (SizeOf_float64_0(state_)))), (SizeOf_float64_0(state_)));
    tmp182 = (TNode<RawPtrT>{tmp181});
    tmp183 = Convert_intptr_constexpr_int31_0(state_, (CodeStubAssembler(state_).ConstexprInt31Mul((FromConstexpr_constexpr_int31_constexpr_IntegerLiteral_0(state_, (CodeStubAssembler(state_).ConstexprIntegerLiteralAdd((CodeStubAssembler(state_).ConstexprIntegerLiteralAdd(IntegerLiteral(false, 0xaull), IntegerLiteral(false, 0x8ull))), IntegerLiteral(false, 0x2ull))))), (SizeOf_float64_0(state_)))));
    std::tie(tmp184, tmp185) = NewOffHeapReference_intptr_0(state_, TNode<RawPtrT>{tmp182}).Flatten();
    ca_.Goto(&block133, phi_bb131_16, phi_bb131_17, phi_bb131_18, tmp184, tmp185, tmp183);
  }

  TNode<JSAny> phi_bb132_16;
  TNode<IntPtrT> phi_bb132_17;
  TNode<BoolT> phi_bb132_18;
  TNode<IntPtrT> tmp186;
  TNode<IntPtrT> tmp187;
  TNode<IntPtrT> tmp188;
  TNode<IntPtrT> tmp189;
  TNode<IntPtrT> tmp190;
  TNode<IntPtrT> tmp191;
  TNode<IntPtrT> tmp192;
  TNode<IntPtrT> tmp193;
  TNode<RawPtrT> tmp194;
  TNode<Union<HeapObject, TaggedIndex>> tmp195;
  TNode<IntPtrT> tmp196;
  if (block132.is_used()) {
    ca_.Bind(&block132, &phi_bb132_16, &phi_bb132_17, &phi_bb132_18);
    tmp186 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_float64_0(state_)));
    tmp187 = CodeStubAssembler(state_).UniqueIntPtrConstant(arraysize(wasm::kFpParamRegisters));
    tmp188 = Convert_intptr_int32_0(state_, TNode<Int32T>{tmp25});
    tmp189 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp187}, TNode<IntPtrT>{tmp188});
    tmp190 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
    tmp191 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp189}, TNode<IntPtrT>{tmp190});
    tmp192 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp191}, TNode<IntPtrT>{tmp186});
    tmp193 = Convert_intptr_intptr_0(state_, TNode<IntPtrT>{tmp192});
    tmp194 = CodeStubAssembler(state_).AllocateBuffer(TNode<IntPtrT>{tmp193});
    std::tie(tmp195, tmp196) = NewOffHeapReference_intptr_0(state_, TNode<RawPtrT>{tmp194}).Flatten();
    ca_.Goto(&block133, phi_bb132_16, phi_bb132_17, phi_bb132_18, tmp195, tmp196, tmp193);
  }

  TNode<JSAny> phi_bb133_16;
  TNode<IntPtrT> phi_bb133_17;
  TNode<BoolT> phi_bb133_18;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb133_22;
  TNode<IntPtrT> phi_bb133_23;
  TNode<IntPtrT> phi_bb133_24;
  TNode<Union<HeapObject, TaggedIndex>> tmp197;
  TNode<IntPtrT> tmp198;
  TNode<IntPtrT> tmp199;
  TNode<IntPtrT> tmp200;
  TNode<IntPtrT> tmp201;
  TNode<IntPtrT> tmp202;
  TNode<IntPtrT> tmp203;
  TNode<IntPtrT> tmp204;
  TNode<IntPtrT> tmp205;
  TNode<BoolT> tmp206;
      TNode<JSAny> tmp208;
  TNode<BoolT> tmp209;
      TNode<JSAny> tmp211;
  TNode<Smi> tmp212;
      TNode<JSAny> tmp214;
  TNode<Int32T> tmp215;
      TNode<JSAny> tmp217;
  TNode<Int32T> tmp218;
      TNode<JSAny> tmp220;
  if (block133.is_used()) {
    ca_.Bind(&block133, &phi_bb133_16, &phi_bb133_17, &phi_bb133_18, &phi_bb133_22, &phi_bb133_23, &phi_bb133_24);
    compiler::CodeAssemblerExceptionHandlerLabel catch207__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch207__label);
    std::tie(tmp197, tmp198, tmp199, tmp200, tmp201, tmp202, tmp203, tmp204, tmp205, tmp206) = LocationAllocatorForParams_0(state_, TorqueStructReference_intptr_0{TNode<Union<HeapObject, TaggedIndex>>{phi_bb133_22}, TNode<IntPtrT>{phi_bb133_23}, TorqueStructUnsafe_0{}}, TNode<IntPtrT>{phi_bb133_24}).Flatten();
    }
    if (catch207__label.is_used()) {
      compiler::CodeAssemblerLabel catch207_skip(&ca_);
      ca_.Goto(&catch207_skip);
      ca_.Bind(&catch207__label, &tmp208);
      ca_.Goto(&block144, phi_bb133_16, phi_bb133_17, phi_bb133_18);
      ca_.Bind(&catch207_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch210__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch210__label);
    tmp209 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    }
    if (catch210__label.is_used()) {
      compiler::CodeAssemblerLabel catch210_skip(&ca_);
      ca_.Goto(&catch210_skip);
      ca_.Bind(&catch210__label, &tmp211);
      ca_.Goto(&block145, phi_bb133_16, phi_bb133_17, phi_bb133_18);
      ca_.Bind(&catch210_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch213__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch213__label);
    tmp212 = Convert_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    }
    if (catch213__label.is_used()) {
      compiler::CodeAssemblerLabel catch213_skip(&ca_);
      ca_.Goto(&catch213_skip);
      ca_.Bind(&catch213__label, &tmp214);
      ca_.Goto(&block146, phi_bb133_16, phi_bb133_17, phi_bb133_18);
      ca_.Bind(&catch213_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch216__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch216__label);
    tmp215 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    }
    if (catch216__label.is_used()) {
      compiler::CodeAssemblerLabel catch216_skip(&ca_);
      ca_.Goto(&catch216_skip);
      ca_.Bind(&catch216__label, &tmp217);
      ca_.Goto(&block147, phi_bb133_16, phi_bb133_17, phi_bb133_18);
      ca_.Bind(&catch216_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch219__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch219__label);
    tmp218 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    }
    if (catch219__label.is_used()) {
      compiler::CodeAssemblerLabel catch219_skip(&ca_);
      ca_.Goto(&catch219_skip);
      ca_.Bind(&catch219__label, &tmp220);
      ca_.Goto(&block148, phi_bb133_16, phi_bb133_17, phi_bb133_18);
      ca_.Bind(&catch219_skip);
    }
    ca_.Goto(&block151, phi_bb133_16, phi_bb133_17, phi_bb133_18, tmp198, tmp199, tmp200, tmp201, tmp202, tmp205, tmp206, tmp209, tmp212, tmp215, tmp218);
  }

  TNode<JSAny> phi_bb144_16;
  TNode<IntPtrT> phi_bb144_17;
  TNode<BoolT> phi_bb144_18;
  TNode<Union<Hole, JSMessageObject>> tmp221;
  if (block144.is_used()) {
    ca_.Bind(&block144, &phi_bb144_16, &phi_bb144_17, &phi_bb144_18);
    tmp221 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb144_16, phi_bb144_17, phi_bb144_18, tmp208, tmp221);
  }

  TNode<JSAny> phi_bb145_16;
  TNode<IntPtrT> phi_bb145_17;
  TNode<BoolT> phi_bb145_18;
  TNode<Union<Hole, JSMessageObject>> tmp222;
  if (block145.is_used()) {
    ca_.Bind(&block145, &phi_bb145_16, &phi_bb145_17, &phi_bb145_18);
    tmp222 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb145_16, phi_bb145_17, phi_bb145_18, tmp211, tmp222);
  }

  TNode<JSAny> phi_bb146_16;
  TNode<IntPtrT> phi_bb146_17;
  TNode<BoolT> phi_bb146_18;
  TNode<Union<Hole, JSMessageObject>> tmp223;
  if (block146.is_used()) {
    ca_.Bind(&block146, &phi_bb146_16, &phi_bb146_17, &phi_bb146_18);
    tmp223 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb146_16, phi_bb146_17, phi_bb146_18, tmp214, tmp223);
  }

  TNode<JSAny> phi_bb147_16;
  TNode<IntPtrT> phi_bb147_17;
  TNode<BoolT> phi_bb147_18;
  TNode<Union<Hole, JSMessageObject>> tmp224;
  if (block147.is_used()) {
    ca_.Bind(&block147, &phi_bb147_16, &phi_bb147_17, &phi_bb147_18);
    tmp224 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb147_16, phi_bb147_17, phi_bb147_18, tmp217, tmp224);
  }

  TNode<JSAny> phi_bb148_16;
  TNode<IntPtrT> phi_bb148_17;
  TNode<BoolT> phi_bb148_18;
  TNode<Union<Hole, JSMessageObject>> tmp225;
  if (block148.is_used()) {
    ca_.Bind(&block148, &phi_bb148_16, &phi_bb148_17, &phi_bb148_18);
    tmp225 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb148_16, phi_bb148_17, phi_bb148_18, tmp220, tmp225);
  }

  TNode<JSAny> phi_bb151_16;
  TNode<IntPtrT> phi_bb151_17;
  TNode<BoolT> phi_bb151_18;
  TNode<IntPtrT> phi_bb151_26;
  TNode<IntPtrT> phi_bb151_27;
  TNode<IntPtrT> phi_bb151_28;
  TNode<IntPtrT> phi_bb151_29;
  TNode<IntPtrT> phi_bb151_30;
  TNode<IntPtrT> phi_bb151_33;
  TNode<BoolT> phi_bb151_34;
  TNode<BoolT> phi_bb151_35;
  TNode<Union<FixedArray, Smi>> phi_bb151_36;
  TNode<Int32T> phi_bb151_37;
  TNode<Int32T> phi_bb151_38;
  TNode<BoolT> tmp226;
      TNode<JSAny> tmp228;
  if (block151.is_used()) {
    ca_.Bind(&block151, &phi_bb151_16, &phi_bb151_17, &phi_bb151_18, &phi_bb151_26, &phi_bb151_27, &phi_bb151_28, &phi_bb151_29, &phi_bb151_30, &phi_bb151_33, &phi_bb151_34, &phi_bb151_35, &phi_bb151_36, &phi_bb151_37, &phi_bb151_38);
    compiler::CodeAssemblerExceptionHandlerLabel catch227__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch227__label);
    tmp226 = CodeStubAssembler(state_).Int32LessThan(TNode<Int32T>{phi_bb151_37}, TNode<Int32T>{tmp25});
    }
    if (catch227__label.is_used()) {
      compiler::CodeAssemblerLabel catch227_skip(&ca_);
      ca_.Goto(&catch227_skip);
      ca_.Bind(&catch227__label, &tmp228);
      ca_.Goto(&block153, phi_bb151_16, phi_bb151_17, phi_bb151_18, phi_bb151_26, phi_bb151_27, phi_bb151_28, phi_bb151_29, phi_bb151_30, phi_bb151_33, phi_bb151_34, phi_bb151_35, phi_bb151_36, phi_bb151_37, phi_bb151_38, phi_bb151_37);
      ca_.Bind(&catch227_skip);
    }
    ca_.Branch(tmp226, &block149, std::vector<compiler::Node*>{phi_bb151_16, phi_bb151_17, phi_bb151_18, phi_bb151_26, phi_bb151_27, phi_bb151_28, phi_bb151_29, phi_bb151_30, phi_bb151_33, phi_bb151_34, phi_bb151_35, phi_bb151_36, phi_bb151_37, phi_bb151_38}, &block150, std::vector<compiler::Node*>{phi_bb151_16, phi_bb151_17, phi_bb151_18, phi_bb151_26, phi_bb151_27, phi_bb151_28, phi_bb151_29, phi_bb151_30, phi_bb151_33, phi_bb151_34, phi_bb151_35, phi_bb151_36, phi_bb151_37, phi_bb151_38});
  }

  TNode<JSAny> phi_bb153_16;
  TNode<IntPtrT> phi_bb153_17;
  TNode<BoolT> phi_bb153_18;
  TNode<IntPtrT> phi_bb153_26;
  TNode<IntPtrT> phi_bb153_27;
  TNode<IntPtrT> phi_bb153_28;
  TNode<IntPtrT> phi_bb153_29;
  TNode<IntPtrT> phi_bb153_30;
  TNode<IntPtrT> phi_bb153_33;
  TNode<BoolT> phi_bb153_34;
  TNode<BoolT> phi_bb153_35;
  TNode<Union<FixedArray, Smi>> phi_bb153_36;
  TNode<Int32T> phi_bb153_37;
  TNode<Int32T> phi_bb153_38;
  TNode<Int32T> phi_bb153_39;
  TNode<Union<Hole, JSMessageObject>> tmp229;
  if (block153.is_used()) {
    ca_.Bind(&block153, &phi_bb153_16, &phi_bb153_17, &phi_bb153_18, &phi_bb153_26, &phi_bb153_27, &phi_bb153_28, &phi_bb153_29, &phi_bb153_30, &phi_bb153_33, &phi_bb153_34, &phi_bb153_35, &phi_bb153_36, &phi_bb153_37, &phi_bb153_38, &phi_bb153_39);
    tmp229 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb153_16, phi_bb153_17, phi_bb153_18, tmp228, tmp229);
  }

  TNode<JSAny> phi_bb149_16;
  TNode<IntPtrT> phi_bb149_17;
  TNode<BoolT> phi_bb149_18;
  TNode<IntPtrT> phi_bb149_26;
  TNode<IntPtrT> phi_bb149_27;
  TNode<IntPtrT> phi_bb149_28;
  TNode<IntPtrT> phi_bb149_29;
  TNode<IntPtrT> phi_bb149_30;
  TNode<IntPtrT> phi_bb149_33;
  TNode<BoolT> phi_bb149_34;
  TNode<BoolT> phi_bb149_35;
  TNode<Union<FixedArray, Smi>> phi_bb149_36;
  TNode<Int32T> phi_bb149_37;
  TNode<Int32T> phi_bb149_38;
  TNode<IntPtrT> tmp230;
      TNode<JSAny> tmp232;
  TNode<JSAny> tmp233;
      TNode<JSAny> tmp235;
  TNode<Int32T> tmp236;
      TNode<JSAny> tmp238;
  TNode<Int32T> tmp239;
      TNode<JSAny> tmp241;
  TNode<IntPtrT> tmp242;
      TNode<JSAny> tmp244;
  TNode<IntPtrT> tmp245;
  TNode<IntPtrT> tmp246;
  TNode<Union<HeapObject, TaggedIndex>> tmp247;
  TNode<IntPtrT> tmp248;
  TNode<Int32T> tmp249;
  TNode<Int32T> tmp250;
      TNode<JSAny> tmp252;
  TNode<BoolT> tmp253;
      TNode<JSAny> tmp255;
  if (block149.is_used()) {
    ca_.Bind(&block149, &phi_bb149_16, &phi_bb149_17, &phi_bb149_18, &phi_bb149_26, &phi_bb149_27, &phi_bb149_28, &phi_bb149_29, &phi_bb149_30, &phi_bb149_33, &phi_bb149_34, &phi_bb149_35, &phi_bb149_36, &phi_bb149_37, &phi_bb149_38);
    compiler::CodeAssemblerExceptionHandlerLabel catch231__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch231__label);
    tmp230 = Convert_intptr_int32_0(state_, TNode<Int32T>{phi_bb149_38});
    }
    if (catch231__label.is_used()) {
      compiler::CodeAssemblerLabel catch231_skip(&ca_);
      ca_.Goto(&catch231_skip);
      ca_.Bind(&catch231__label, &tmp232);
      ca_.Goto(&block154, phi_bb149_16, phi_bb149_17, phi_bb149_18, phi_bb149_26, phi_bb149_27, phi_bb149_28, phi_bb149_29, phi_bb149_30, phi_bb149_33, phi_bb149_34, phi_bb149_35, phi_bb149_36, phi_bb149_37, phi_bb149_38, phi_bb149_38);
      ca_.Bind(&catch231_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch234__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch234__label);
    tmp233 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{p_arguments.frame}, TNode<RawPtrT>{p_arguments.base}, TNode<IntPtrT>{p_arguments.length}, TNode<IntPtrT>{p_arguments.actual_count}}, TNode<IntPtrT>{tmp230});
    }
    if (catch234__label.is_used()) {
      compiler::CodeAssemblerLabel catch234_skip(&ca_);
      ca_.Goto(&catch234_skip);
      ca_.Bind(&catch234__label, &tmp235);
      ca_.Goto(&block155, phi_bb149_16, phi_bb149_17, phi_bb149_18, phi_bb149_26, phi_bb149_27, phi_bb149_28, phi_bb149_29, phi_bb149_30, phi_bb149_33, phi_bb149_34, phi_bb149_35, phi_bb149_36, phi_bb149_37, phi_bb149_38);
      ca_.Bind(&catch234_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch237__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch237__label);
    tmp236 = FromConstexpr_int32_constexpr_int31_0(state_, 1);
    }
    if (catch237__label.is_used()) {
      compiler::CodeAssemblerLabel catch237_skip(&ca_);
      ca_.Goto(&catch237_skip);
      ca_.Bind(&catch237__label, &tmp238);
      ca_.Goto(&block156, phi_bb149_16, phi_bb149_17, phi_bb149_18, phi_bb149_26, phi_bb149_27, phi_bb149_28, phi_bb149_29, phi_bb149_30, phi_bb149_33, phi_bb149_34, phi_bb149_35, phi_bb149_36, phi_bb149_37, phi_bb149_38, phi_bb149_37, phi_bb149_37);
      ca_.Bind(&catch237_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch240__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch240__label);
    tmp239 = CodeStubAssembler(state_).Int32Add(TNode<Int32T>{phi_bb149_37}, TNode<Int32T>{tmp236});
    }
    if (catch240__label.is_used()) {
      compiler::CodeAssemblerLabel catch240_skip(&ca_);
      ca_.Goto(&catch240_skip);
      ca_.Bind(&catch240__label, &tmp241);
      ca_.Goto(&block157, phi_bb149_16, phi_bb149_17, phi_bb149_18, phi_bb149_26, phi_bb149_27, phi_bb149_28, phi_bb149_29, phi_bb149_30, phi_bb149_33, phi_bb149_34, phi_bb149_35, phi_bb149_36, phi_bb149_37, phi_bb149_38, phi_bb149_37);
      ca_.Bind(&catch240_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch243__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch243__label);
    tmp242 = Convert_intptr_int32_0(state_, TNode<Int32T>{phi_bb149_37});
    }
    if (catch243__label.is_used()) {
      compiler::CodeAssemblerLabel catch243_skip(&ca_);
      ca_.Goto(&catch243_skip);
      ca_.Bind(&catch243__label, &tmp244);
      ca_.Goto(&block158, phi_bb149_16, phi_bb149_17, phi_bb149_18, phi_bb149_26, phi_bb149_27, phi_bb149_28, phi_bb149_29, phi_bb149_30, phi_bb149_33, phi_bb149_34, phi_bb149_35, phi_bb149_36, phi_bb149_38, phi_bb149_37);
      ca_.Bind(&catch243_skip);
    }
    tmp245 = TimesSizeOf_int32_0(state_, TNode<IntPtrT>{tmp242});
    tmp246 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp176}, TNode<IntPtrT>{tmp245});
    std::tie(tmp247, tmp248) = NewReference_int32_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp175}, TNode<IntPtrT>{tmp246}).Flatten();
    tmp249 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{tmp247, tmp248});
    compiler::CodeAssemblerExceptionHandlerLabel catch251__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch251__label);
    tmp250 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmI32.raw_bit_field());
    }
    if (catch251__label.is_used()) {
      compiler::CodeAssemblerLabel catch251_skip(&ca_);
      ca_.Goto(&catch251_skip);
      ca_.Bind(&catch251__label, &tmp252);
      ca_.Goto(&block162, phi_bb149_16, phi_bb149_17, phi_bb149_18, phi_bb149_26, phi_bb149_27, phi_bb149_28, phi_bb149_29, phi_bb149_30, phi_bb149_33, phi_bb149_34, phi_bb149_35, phi_bb149_36, phi_bb149_38);
      ca_.Bind(&catch251_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch254__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch254__label);
    tmp253 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp249}, TNode<Int32T>{tmp250});
    }
    if (catch254__label.is_used()) {
      compiler::CodeAssemblerLabel catch254_skip(&ca_);
      ca_.Goto(&catch254_skip);
      ca_.Bind(&catch254__label, &tmp255);
      ca_.Goto(&block163, phi_bb149_16, phi_bb149_17, phi_bb149_18, phi_bb149_26, phi_bb149_27, phi_bb149_28, phi_bb149_29, phi_bb149_30, phi_bb149_33, phi_bb149_34, phi_bb149_35, phi_bb149_36, phi_bb149_38);
      ca_.Bind(&catch254_skip);
    }
    ca_.Branch(tmp253, &block160, std::vector<compiler::Node*>{phi_bb149_16, phi_bb149_17, phi_bb149_18, phi_bb149_26, phi_bb149_27, phi_bb149_28, phi_bb149_29, phi_bb149_30, phi_bb149_33, phi_bb149_34, phi_bb149_35, phi_bb149_36, phi_bb149_38}, &block161, std::vector<compiler::Node*>{phi_bb149_16, phi_bb149_17, phi_bb149_18, phi_bb149_26, phi_bb149_27, phi_bb149_28, phi_bb149_29, phi_bb149_30, phi_bb149_33, phi_bb149_34, phi_bb149_35, phi_bb149_36, phi_bb149_38});
  }

  TNode<JSAny> phi_bb154_16;
  TNode<IntPtrT> phi_bb154_17;
  TNode<BoolT> phi_bb154_18;
  TNode<IntPtrT> phi_bb154_26;
  TNode<IntPtrT> phi_bb154_27;
  TNode<IntPtrT> phi_bb154_28;
  TNode<IntPtrT> phi_bb154_29;
  TNode<IntPtrT> phi_bb154_30;
  TNode<IntPtrT> phi_bb154_33;
  TNode<BoolT> phi_bb154_34;
  TNode<BoolT> phi_bb154_35;
  TNode<Union<FixedArray, Smi>> phi_bb154_36;
  TNode<Int32T> phi_bb154_37;
  TNode<Int32T> phi_bb154_38;
  TNode<Int32T> phi_bb154_39;
  TNode<Union<Hole, JSMessageObject>> tmp256;
  if (block154.is_used()) {
    ca_.Bind(&block154, &phi_bb154_16, &phi_bb154_17, &phi_bb154_18, &phi_bb154_26, &phi_bb154_27, &phi_bb154_28, &phi_bb154_29, &phi_bb154_30, &phi_bb154_33, &phi_bb154_34, &phi_bb154_35, &phi_bb154_36, &phi_bb154_37, &phi_bb154_38, &phi_bb154_39);
    tmp256 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb154_16, phi_bb154_17, phi_bb154_18, tmp232, tmp256);
  }

  TNode<JSAny> phi_bb155_16;
  TNode<IntPtrT> phi_bb155_17;
  TNode<BoolT> phi_bb155_18;
  TNode<IntPtrT> phi_bb155_26;
  TNode<IntPtrT> phi_bb155_27;
  TNode<IntPtrT> phi_bb155_28;
  TNode<IntPtrT> phi_bb155_29;
  TNode<IntPtrT> phi_bb155_30;
  TNode<IntPtrT> phi_bb155_33;
  TNode<BoolT> phi_bb155_34;
  TNode<BoolT> phi_bb155_35;
  TNode<Union<FixedArray, Smi>> phi_bb155_36;
  TNode<Int32T> phi_bb155_37;
  TNode<Int32T> phi_bb155_38;
  TNode<Union<Hole, JSMessageObject>> tmp257;
  if (block155.is_used()) {
    ca_.Bind(&block155, &phi_bb155_16, &phi_bb155_17, &phi_bb155_18, &phi_bb155_26, &phi_bb155_27, &phi_bb155_28, &phi_bb155_29, &phi_bb155_30, &phi_bb155_33, &phi_bb155_34, &phi_bb155_35, &phi_bb155_36, &phi_bb155_37, &phi_bb155_38);
    tmp257 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb155_16, phi_bb155_17, phi_bb155_18, tmp235, tmp257);
  }

  TNode<JSAny> phi_bb156_16;
  TNode<IntPtrT> phi_bb156_17;
  TNode<BoolT> phi_bb156_18;
  TNode<IntPtrT> phi_bb156_26;
  TNode<IntPtrT> phi_bb156_27;
  TNode<IntPtrT> phi_bb156_28;
  TNode<IntPtrT> phi_bb156_29;
  TNode<IntPtrT> phi_bb156_30;
  TNode<IntPtrT> phi_bb156_33;
  TNode<BoolT> phi_bb156_34;
  TNode<BoolT> phi_bb156_35;
  TNode<Union<FixedArray, Smi>> phi_bb156_36;
  TNode<Int32T> phi_bb156_37;
  TNode<Int32T> phi_bb156_38;
  TNode<Int32T> phi_bb156_43;
  TNode<Int32T> phi_bb156_44;
  TNode<Union<Hole, JSMessageObject>> tmp258;
  if (block156.is_used()) {
    ca_.Bind(&block156, &phi_bb156_16, &phi_bb156_17, &phi_bb156_18, &phi_bb156_26, &phi_bb156_27, &phi_bb156_28, &phi_bb156_29, &phi_bb156_30, &phi_bb156_33, &phi_bb156_34, &phi_bb156_35, &phi_bb156_36, &phi_bb156_37, &phi_bb156_38, &phi_bb156_43, &phi_bb156_44);
    tmp258 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb156_16, phi_bb156_17, phi_bb156_18, tmp238, tmp258);
  }

  TNode<JSAny> phi_bb157_16;
  TNode<IntPtrT> phi_bb157_17;
  TNode<BoolT> phi_bb157_18;
  TNode<IntPtrT> phi_bb157_26;
  TNode<IntPtrT> phi_bb157_27;
  TNode<IntPtrT> phi_bb157_28;
  TNode<IntPtrT> phi_bb157_29;
  TNode<IntPtrT> phi_bb157_30;
  TNode<IntPtrT> phi_bb157_33;
  TNode<BoolT> phi_bb157_34;
  TNode<BoolT> phi_bb157_35;
  TNode<Union<FixedArray, Smi>> phi_bb157_36;
  TNode<Int32T> phi_bb157_37;
  TNode<Int32T> phi_bb157_38;
  TNode<Int32T> phi_bb157_43;
  TNode<Union<Hole, JSMessageObject>> tmp259;
  if (block157.is_used()) {
    ca_.Bind(&block157, &phi_bb157_16, &phi_bb157_17, &phi_bb157_18, &phi_bb157_26, &phi_bb157_27, &phi_bb157_28, &phi_bb157_29, &phi_bb157_30, &phi_bb157_33, &phi_bb157_34, &phi_bb157_35, &phi_bb157_36, &phi_bb157_37, &phi_bb157_38, &phi_bb157_43);
    tmp259 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb157_16, phi_bb157_17, phi_bb157_18, tmp241, tmp259);
  }

  TNode<JSAny> phi_bb158_16;
  TNode<IntPtrT> phi_bb158_17;
  TNode<BoolT> phi_bb158_18;
  TNode<IntPtrT> phi_bb158_26;
  TNode<IntPtrT> phi_bb158_27;
  TNode<IntPtrT> phi_bb158_28;
  TNode<IntPtrT> phi_bb158_29;
  TNode<IntPtrT> phi_bb158_30;
  TNode<IntPtrT> phi_bb158_33;
  TNode<BoolT> phi_bb158_34;
  TNode<BoolT> phi_bb158_35;
  TNode<Union<FixedArray, Smi>> phi_bb158_36;
  TNode<Int32T> phi_bb158_38;
  TNode<Int32T> phi_bb158_43;
  TNode<Union<Hole, JSMessageObject>> tmp260;
  if (block158.is_used()) {
    ca_.Bind(&block158, &phi_bb158_16, &phi_bb158_17, &phi_bb158_18, &phi_bb158_26, &phi_bb158_27, &phi_bb158_28, &phi_bb158_29, &phi_bb158_30, &phi_bb158_33, &phi_bb158_34, &phi_bb158_35, &phi_bb158_36, &phi_bb158_38, &phi_bb158_43);
    tmp260 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb158_16, phi_bb158_17, phi_bb158_18, tmp244, tmp260);
  }

  TNode<JSAny> phi_bb162_16;
  TNode<IntPtrT> phi_bb162_17;
  TNode<BoolT> phi_bb162_18;
  TNode<IntPtrT> phi_bb162_26;
  TNode<IntPtrT> phi_bb162_27;
  TNode<IntPtrT> phi_bb162_28;
  TNode<IntPtrT> phi_bb162_29;
  TNode<IntPtrT> phi_bb162_30;
  TNode<IntPtrT> phi_bb162_33;
  TNode<BoolT> phi_bb162_34;
  TNode<BoolT> phi_bb162_35;
  TNode<Union<FixedArray, Smi>> phi_bb162_36;
  TNode<Int32T> phi_bb162_38;
  TNode<Union<Hole, JSMessageObject>> tmp261;
  if (block162.is_used()) {
    ca_.Bind(&block162, &phi_bb162_16, &phi_bb162_17, &phi_bb162_18, &phi_bb162_26, &phi_bb162_27, &phi_bb162_28, &phi_bb162_29, &phi_bb162_30, &phi_bb162_33, &phi_bb162_34, &phi_bb162_35, &phi_bb162_36, &phi_bb162_38);
    tmp261 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb162_16, phi_bb162_17, phi_bb162_18, tmp252, tmp261);
  }

  TNode<JSAny> phi_bb163_16;
  TNode<IntPtrT> phi_bb163_17;
  TNode<BoolT> phi_bb163_18;
  TNode<IntPtrT> phi_bb163_26;
  TNode<IntPtrT> phi_bb163_27;
  TNode<IntPtrT> phi_bb163_28;
  TNode<IntPtrT> phi_bb163_29;
  TNode<IntPtrT> phi_bb163_30;
  TNode<IntPtrT> phi_bb163_33;
  TNode<BoolT> phi_bb163_34;
  TNode<BoolT> phi_bb163_35;
  TNode<Union<FixedArray, Smi>> phi_bb163_36;
  TNode<Int32T> phi_bb163_38;
  TNode<Union<Hole, JSMessageObject>> tmp262;
  if (block163.is_used()) {
    ca_.Bind(&block163, &phi_bb163_16, &phi_bb163_17, &phi_bb163_18, &phi_bb163_26, &phi_bb163_27, &phi_bb163_28, &phi_bb163_29, &phi_bb163_30, &phi_bb163_33, &phi_bb163_34, &phi_bb163_35, &phi_bb163_36, &phi_bb163_38);
    tmp262 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb163_16, phi_bb163_17, phi_bb163_18, tmp255, tmp262);
  }

  TNode<JSAny> phi_bb160_16;
  TNode<IntPtrT> phi_bb160_17;
  TNode<BoolT> phi_bb160_18;
  TNode<IntPtrT> phi_bb160_26;
  TNode<IntPtrT> phi_bb160_27;
  TNode<IntPtrT> phi_bb160_28;
  TNode<IntPtrT> phi_bb160_29;
  TNode<IntPtrT> phi_bb160_30;
  TNode<IntPtrT> phi_bb160_33;
  TNode<BoolT> phi_bb160_34;
  TNode<BoolT> phi_bb160_35;
  TNode<Union<FixedArray, Smi>> phi_bb160_36;
  TNode<Int32T> phi_bb160_38;
  TNode<IntPtrT> tmp263;
  TNode<IntPtrT> tmp264;
  TNode<IntPtrT> tmp265;
  TNode<BoolT> tmp266;
  if (block160.is_used()) {
    ca_.Bind(&block160, &phi_bb160_16, &phi_bb160_17, &phi_bb160_18, &phi_bb160_26, &phi_bb160_27, &phi_bb160_28, &phi_bb160_29, &phi_bb160_30, &phi_bb160_33, &phi_bb160_34, &phi_bb160_35, &phi_bb160_36, &phi_bb160_38);
    tmp263 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp264 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{phi_bb160_26}, TNode<IntPtrT>{tmp263});
    tmp265 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp266 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{phi_bb160_26}, TNode<IntPtrT>{tmp265});
    ca_.Branch(tmp266, &block166, std::vector<compiler::Node*>{phi_bb160_16, phi_bb160_17, phi_bb160_18, phi_bb160_27, phi_bb160_28, phi_bb160_29, phi_bb160_30, phi_bb160_33, phi_bb160_34, phi_bb160_35, phi_bb160_36, phi_bb160_38}, &block167, std::vector<compiler::Node*>{phi_bb160_16, phi_bb160_17, phi_bb160_18, phi_bb160_27, phi_bb160_28, phi_bb160_29, phi_bb160_30, phi_bb160_33, phi_bb160_34, phi_bb160_35, phi_bb160_36, phi_bb160_38});
  }

  TNode<JSAny> phi_bb166_16;
  TNode<IntPtrT> phi_bb166_17;
  TNode<BoolT> phi_bb166_18;
  TNode<IntPtrT> phi_bb166_27;
  TNode<IntPtrT> phi_bb166_28;
  TNode<IntPtrT> phi_bb166_29;
  TNode<IntPtrT> phi_bb166_30;
  TNode<IntPtrT> phi_bb166_33;
  TNode<BoolT> phi_bb166_34;
  TNode<BoolT> phi_bb166_35;
  TNode<Union<FixedArray, Smi>> phi_bb166_36;
  TNode<Int32T> phi_bb166_38;
  TNode<Union<HeapObject, TaggedIndex>> tmp267;
  TNode<IntPtrT> tmp268;
  TNode<IntPtrT> tmp269;
  TNode<IntPtrT> tmp270;
  if (block166.is_used()) {
    ca_.Bind(&block166, &phi_bb166_16, &phi_bb166_17, &phi_bb166_18, &phi_bb166_27, &phi_bb166_28, &phi_bb166_29, &phi_bb166_30, &phi_bb166_33, &phi_bb166_34, &phi_bb166_35, &phi_bb166_36, &phi_bb166_38);
    std::tie(tmp267, tmp268) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp197}, TNode<IntPtrT>{phi_bb166_28}).Flatten();
    tmp269 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp270 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb166_28}, TNode<IntPtrT>{tmp269});
    ca_.Goto(&block165, phi_bb166_16, phi_bb166_17, phi_bb166_18, phi_bb166_27, tmp270, phi_bb166_29, phi_bb166_30, phi_bb166_33, phi_bb166_34, phi_bb166_35, phi_bb166_36, phi_bb166_38, tmp267, tmp268);
  }

  TNode<JSAny> phi_bb167_16;
  TNode<IntPtrT> phi_bb167_17;
  TNode<BoolT> phi_bb167_18;
  TNode<IntPtrT> phi_bb167_27;
  TNode<IntPtrT> phi_bb167_28;
  TNode<IntPtrT> phi_bb167_29;
  TNode<IntPtrT> phi_bb167_30;
  TNode<IntPtrT> phi_bb167_33;
  TNode<BoolT> phi_bb167_34;
  TNode<BoolT> phi_bb167_35;
  TNode<Union<FixedArray, Smi>> phi_bb167_36;
  TNode<Int32T> phi_bb167_38;
  if (block167.is_used()) {
    ca_.Bind(&block167, &phi_bb167_16, &phi_bb167_17, &phi_bb167_18, &phi_bb167_27, &phi_bb167_28, &phi_bb167_29, &phi_bb167_30, &phi_bb167_33, &phi_bb167_34, &phi_bb167_35, &phi_bb167_36, &phi_bb167_38);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block169, phi_bb167_16, phi_bb167_17, phi_bb167_18, phi_bb167_27, phi_bb167_28, phi_bb167_29, phi_bb167_30, phi_bb167_33, phi_bb167_34, phi_bb167_35, phi_bb167_36, phi_bb167_38);
    } else {
      ca_.Goto(&block170, phi_bb167_16, phi_bb167_17, phi_bb167_18, phi_bb167_27, phi_bb167_28, phi_bb167_29, phi_bb167_30, phi_bb167_33, phi_bb167_34, phi_bb167_35, phi_bb167_36, phi_bb167_38);
    }
  }

  TNode<JSAny> phi_bb169_16;
  TNode<IntPtrT> phi_bb169_17;
  TNode<BoolT> phi_bb169_18;
  TNode<IntPtrT> phi_bb169_27;
  TNode<IntPtrT> phi_bb169_28;
  TNode<IntPtrT> phi_bb169_29;
  TNode<IntPtrT> phi_bb169_30;
  TNode<IntPtrT> phi_bb169_33;
  TNode<BoolT> phi_bb169_34;
  TNode<BoolT> phi_bb169_35;
  TNode<Union<FixedArray, Smi>> phi_bb169_36;
  TNode<Int32T> phi_bb169_38;
  TNode<Union<HeapObject, TaggedIndex>> tmp271;
  TNode<IntPtrT> tmp272;
  TNode<IntPtrT> tmp273;
  TNode<IntPtrT> tmp274;
  if (block169.is_used()) {
    ca_.Bind(&block169, &phi_bb169_16, &phi_bb169_17, &phi_bb169_18, &phi_bb169_27, &phi_bb169_28, &phi_bb169_29, &phi_bb169_30, &phi_bb169_33, &phi_bb169_34, &phi_bb169_35, &phi_bb169_36, &phi_bb169_38);
    std::tie(tmp271, tmp272) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp197}, TNode<IntPtrT>{phi_bb169_30}).Flatten();
    tmp273 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp274 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb169_30}, TNode<IntPtrT>{tmp273});
    ca_.Goto(&block168, phi_bb169_16, phi_bb169_17, phi_bb169_18, phi_bb169_27, phi_bb169_28, phi_bb169_29, tmp274, phi_bb169_33, phi_bb169_34, phi_bb169_35, phi_bb169_36, phi_bb169_38, tmp271, tmp272);
  }

  TNode<JSAny> phi_bb170_16;
  TNode<IntPtrT> phi_bb170_17;
  TNode<BoolT> phi_bb170_18;
  TNode<IntPtrT> phi_bb170_27;
  TNode<IntPtrT> phi_bb170_28;
  TNode<IntPtrT> phi_bb170_29;
  TNode<IntPtrT> phi_bb170_30;
  TNode<IntPtrT> phi_bb170_33;
  TNode<BoolT> phi_bb170_34;
  TNode<BoolT> phi_bb170_35;
  TNode<Union<FixedArray, Smi>> phi_bb170_36;
  TNode<Int32T> phi_bb170_38;
  TNode<IntPtrT> tmp275;
  TNode<BoolT> tmp276;
  if (block170.is_used()) {
    ca_.Bind(&block170, &phi_bb170_16, &phi_bb170_17, &phi_bb170_18, &phi_bb170_27, &phi_bb170_28, &phi_bb170_29, &phi_bb170_30, &phi_bb170_33, &phi_bb170_34, &phi_bb170_35, &phi_bb170_36, &phi_bb170_38);
    tmp275 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp276 = CodeStubAssembler(state_).WordNotEqual(TNode<IntPtrT>{phi_bb170_33}, TNode<IntPtrT>{tmp275});
    ca_.Branch(tmp276, &block172, std::vector<compiler::Node*>{phi_bb170_16, phi_bb170_17, phi_bb170_18, phi_bb170_27, phi_bb170_28, phi_bb170_29, phi_bb170_30, phi_bb170_33, phi_bb170_34, phi_bb170_35, phi_bb170_36, phi_bb170_38}, &block173, std::vector<compiler::Node*>{phi_bb170_16, phi_bb170_17, phi_bb170_18, phi_bb170_27, phi_bb170_28, phi_bb170_29, phi_bb170_30, phi_bb170_33, phi_bb170_34, phi_bb170_35, phi_bb170_36, phi_bb170_38});
  }

  TNode<JSAny> phi_bb172_16;
  TNode<IntPtrT> phi_bb172_17;
  TNode<BoolT> phi_bb172_18;
  TNode<IntPtrT> phi_bb172_27;
  TNode<IntPtrT> phi_bb172_28;
  TNode<IntPtrT> phi_bb172_29;
  TNode<IntPtrT> phi_bb172_30;
  TNode<IntPtrT> phi_bb172_33;
  TNode<BoolT> phi_bb172_34;
  TNode<BoolT> phi_bb172_35;
  TNode<Union<FixedArray, Smi>> phi_bb172_36;
  TNode<Int32T> phi_bb172_38;
  TNode<Union<HeapObject, TaggedIndex>> tmp277;
  TNode<IntPtrT> tmp278;
  TNode<IntPtrT> tmp279;
  TNode<BoolT> tmp280;
  if (block172.is_used()) {
    ca_.Bind(&block172, &phi_bb172_16, &phi_bb172_17, &phi_bb172_18, &phi_bb172_27, &phi_bb172_28, &phi_bb172_29, &phi_bb172_30, &phi_bb172_33, &phi_bb172_34, &phi_bb172_35, &phi_bb172_36, &phi_bb172_38);
    std::tie(tmp277, tmp278) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp197}, TNode<IntPtrT>{phi_bb172_33}).Flatten();
    tmp279 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp280 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block168, phi_bb172_16, phi_bb172_17, phi_bb172_18, phi_bb172_27, phi_bb172_28, phi_bb172_29, phi_bb172_30, tmp279, tmp280, phi_bb172_35, phi_bb172_36, phi_bb172_38, tmp277, tmp278);
  }

  TNode<JSAny> phi_bb173_16;
  TNode<IntPtrT> phi_bb173_17;
  TNode<BoolT> phi_bb173_18;
  TNode<IntPtrT> phi_bb173_27;
  TNode<IntPtrT> phi_bb173_28;
  TNode<IntPtrT> phi_bb173_29;
  TNode<IntPtrT> phi_bb173_30;
  TNode<IntPtrT> phi_bb173_33;
  TNode<BoolT> phi_bb173_34;
  TNode<BoolT> phi_bb173_35;
  TNode<Union<FixedArray, Smi>> phi_bb173_36;
  TNode<Int32T> phi_bb173_38;
  TNode<Union<HeapObject, TaggedIndex>> tmp281;
  TNode<IntPtrT> tmp282;
  TNode<IntPtrT> tmp283;
  TNode<IntPtrT> tmp284;
  TNode<IntPtrT> tmp285;
  TNode<IntPtrT> tmp286;
  TNode<BoolT> tmp287;
  if (block173.is_used()) {
    ca_.Bind(&block173, &phi_bb173_16, &phi_bb173_17, &phi_bb173_18, &phi_bb173_27, &phi_bb173_28, &phi_bb173_29, &phi_bb173_30, &phi_bb173_33, &phi_bb173_34, &phi_bb173_35, &phi_bb173_36, &phi_bb173_38);
    std::tie(tmp281, tmp282) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp197}, TNode<IntPtrT>{phi_bb173_30}).Flatten();
    tmp283 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp284 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb173_30}, TNode<IntPtrT>{tmp283});
    tmp285 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp286 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp284}, TNode<IntPtrT>{tmp285});
    tmp287 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block168, phi_bb173_16, phi_bb173_17, phi_bb173_18, phi_bb173_27, phi_bb173_28, phi_bb173_29, tmp286, tmp284, tmp287, phi_bb173_35, phi_bb173_36, phi_bb173_38, tmp281, tmp282);
  }

  TNode<JSAny> phi_bb168_16;
  TNode<IntPtrT> phi_bb168_17;
  TNode<BoolT> phi_bb168_18;
  TNode<IntPtrT> phi_bb168_27;
  TNode<IntPtrT> phi_bb168_28;
  TNode<IntPtrT> phi_bb168_29;
  TNode<IntPtrT> phi_bb168_30;
  TNode<IntPtrT> phi_bb168_33;
  TNode<BoolT> phi_bb168_34;
  TNode<BoolT> phi_bb168_35;
  TNode<Union<FixedArray, Smi>> phi_bb168_36;
  TNode<Int32T> phi_bb168_38;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb168_41;
  TNode<IntPtrT> phi_bb168_42;
  if (block168.is_used()) {
    ca_.Bind(&block168, &phi_bb168_16, &phi_bb168_17, &phi_bb168_18, &phi_bb168_27, &phi_bb168_28, &phi_bb168_29, &phi_bb168_30, &phi_bb168_33, &phi_bb168_34, &phi_bb168_35, &phi_bb168_36, &phi_bb168_38, &phi_bb168_41, &phi_bb168_42);
    ca_.Goto(&block165, phi_bb168_16, phi_bb168_17, phi_bb168_18, phi_bb168_27, phi_bb168_28, phi_bb168_29, phi_bb168_30, phi_bb168_33, phi_bb168_34, phi_bb168_35, phi_bb168_36, phi_bb168_38, phi_bb168_41, phi_bb168_42);
  }

  TNode<JSAny> phi_bb165_16;
  TNode<IntPtrT> phi_bb165_17;
  TNode<BoolT> phi_bb165_18;
  TNode<IntPtrT> phi_bb165_27;
  TNode<IntPtrT> phi_bb165_28;
  TNode<IntPtrT> phi_bb165_29;
  TNode<IntPtrT> phi_bb165_30;
  TNode<IntPtrT> phi_bb165_33;
  TNode<BoolT> phi_bb165_34;
  TNode<BoolT> phi_bb165_35;
  TNode<Union<FixedArray, Smi>> phi_bb165_36;
  TNode<Int32T> phi_bb165_38;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb165_41;
  TNode<IntPtrT> phi_bb165_42;
  TNode<Smi> tmp288;
      TNode<JSAny> tmp291;
  if (block165.is_used()) {
    ca_.Bind(&block165, &phi_bb165_16, &phi_bb165_17, &phi_bb165_18, &phi_bb165_27, &phi_bb165_28, &phi_bb165_29, &phi_bb165_30, &phi_bb165_33, &phi_bb165_34, &phi_bb165_35, &phi_bb165_36, &phi_bb165_38, &phi_bb165_41, &phi_bb165_42);
    compiler::CodeAssemblerLabel label289(&ca_);
    compiler::CodeAssemblerExceptionHandlerLabel catch290__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch290__label);
    tmp288 = Cast_Smi_0(state_, TNode<Object>{tmp233}, &label289);
    }
    if (catch290__label.is_used()) {
      compiler::CodeAssemblerLabel catch290_skip(&ca_);
      ca_.Goto(&catch290_skip);
      ca_.Bind(&catch290__label, &tmp291);
      ca_.Goto(&block178, phi_bb165_16, phi_bb165_17, phi_bb165_18, phi_bb165_27, phi_bb165_28, phi_bb165_29, phi_bb165_30, phi_bb165_33, phi_bb165_34, phi_bb165_35, phi_bb165_36, phi_bb165_38, phi_bb165_41, phi_bb165_42);
      ca_.Bind(&catch290_skip);
    }
    ca_.Goto(&block176, phi_bb165_16, phi_bb165_17, phi_bb165_18, phi_bb165_27, phi_bb165_28, phi_bb165_29, phi_bb165_30, phi_bb165_33, phi_bb165_34, phi_bb165_35, phi_bb165_36, phi_bb165_38, phi_bb165_41, phi_bb165_42);
    if (label289.is_used()) {
      ca_.Bind(&label289);
      ca_.Goto(&block177, phi_bb165_16, phi_bb165_17, phi_bb165_18, phi_bb165_27, phi_bb165_28, phi_bb165_29, phi_bb165_30, phi_bb165_33, phi_bb165_34, phi_bb165_35, phi_bb165_36, phi_bb165_38, phi_bb165_41, phi_bb165_42);
    }
  }

  TNode<JSAny> phi_bb178_16;
  TNode<IntPtrT> phi_bb178_17;
  TNode<BoolT> phi_bb178_18;
  TNode<IntPtrT> phi_bb178_27;
  TNode<IntPtrT> phi_bb178_28;
  TNode<IntPtrT> phi_bb178_29;
  TNode<IntPtrT> phi_bb178_30;
  TNode<IntPtrT> phi_bb178_33;
  TNode<BoolT> phi_bb178_34;
  TNode<BoolT> phi_bb178_35;
  TNode<Union<FixedArray, Smi>> phi_bb178_36;
  TNode<Int32T> phi_bb178_38;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb178_41;
  TNode<IntPtrT> phi_bb178_42;
  TNode<Union<Hole, JSMessageObject>> tmp292;
  if (block178.is_used()) {
    ca_.Bind(&block178, &phi_bb178_16, &phi_bb178_17, &phi_bb178_18, &phi_bb178_27, &phi_bb178_28, &phi_bb178_29, &phi_bb178_30, &phi_bb178_33, &phi_bb178_34, &phi_bb178_35, &phi_bb178_36, &phi_bb178_38, &phi_bb178_41, &phi_bb178_42);
    tmp292 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb178_16, phi_bb178_17, phi_bb178_18, tmp291, tmp292);
  }

  TNode<JSAny> phi_bb177_16;
  TNode<IntPtrT> phi_bb177_17;
  TNode<BoolT> phi_bb177_18;
  TNode<IntPtrT> phi_bb177_27;
  TNode<IntPtrT> phi_bb177_28;
  TNode<IntPtrT> phi_bb177_29;
  TNode<IntPtrT> phi_bb177_30;
  TNode<IntPtrT> phi_bb177_33;
  TNode<BoolT> phi_bb177_34;
  TNode<BoolT> phi_bb177_35;
  TNode<Union<FixedArray, Smi>> phi_bb177_36;
  TNode<Int32T> phi_bb177_38;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb177_41;
  TNode<IntPtrT> phi_bb177_42;
  TNode<Int32T> tmp293;
      TNode<JSAny> tmp295;
  TNode<IntPtrT> tmp296;
      TNode<JSAny> tmp298;
  if (block177.is_used()) {
    ca_.Bind(&block177, &phi_bb177_16, &phi_bb177_17, &phi_bb177_18, &phi_bb177_27, &phi_bb177_28, &phi_bb177_29, &phi_bb177_30, &phi_bb177_33, &phi_bb177_34, &phi_bb177_35, &phi_bb177_36, &phi_bb177_38, &phi_bb177_41, &phi_bb177_42);
    compiler::CodeAssemblerExceptionHandlerLabel catch294__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch294__label);
    tmp293 = ca_.CallBuiltin<Int32T>(Builtin::kWasmTaggedNonSmiToInt32, p_context, ca_.UncheckedCast<Union<BigInt, Boolean, HeapNumber, JSReceiver, Null, String, Symbol, Undefined>>(tmp233));
    }
    if (catch294__label.is_used()) {
      compiler::CodeAssemblerLabel catch294_skip(&ca_);
      ca_.Goto(&catch294_skip);
      ca_.Bind(&catch294__label, &tmp295);
      ca_.Goto(&block181, phi_bb177_16, phi_bb177_17, phi_bb177_18, phi_bb177_27, phi_bb177_28, phi_bb177_29, phi_bb177_30, phi_bb177_33, phi_bb177_34, phi_bb177_35, phi_bb177_36, phi_bb177_38, phi_bb177_41, phi_bb177_42, phi_bb177_41, phi_bb177_42);
      ca_.Bind(&catch294_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch297__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch297__label);
    tmp296 = Convert_intptr_int32_0(state_, TNode<Int32T>{tmp293});
    }
    if (catch297__label.is_used()) {
      compiler::CodeAssemblerLabel catch297_skip(&ca_);
      ca_.Goto(&catch297_skip);
      ca_.Bind(&catch297__label, &tmp298);
      ca_.Goto(&block182, phi_bb177_16, phi_bb177_17, phi_bb177_18, phi_bb177_27, phi_bb177_28, phi_bb177_29, phi_bb177_30, phi_bb177_33, phi_bb177_34, phi_bb177_35, phi_bb177_36, phi_bb177_38, phi_bb177_41, phi_bb177_42, phi_bb177_41, phi_bb177_42);
      ca_.Bind(&catch297_skip);
    }
    CodeStubAssembler(state_).StoreReference<IntPtrT>(CodeStubAssembler::Reference{phi_bb177_41, phi_bb177_42}, tmp296);
    ca_.Goto(&block174, phi_bb177_16, phi_bb177_17, phi_bb177_18, phi_bb177_27, phi_bb177_28, phi_bb177_29, phi_bb177_30, phi_bb177_33, phi_bb177_34, phi_bb177_35, phi_bb177_36, phi_bb177_38, phi_bb177_41, phi_bb177_42);
  }

  TNode<JSAny> phi_bb176_16;
  TNode<IntPtrT> phi_bb176_17;
  TNode<BoolT> phi_bb176_18;
  TNode<IntPtrT> phi_bb176_27;
  TNode<IntPtrT> phi_bb176_28;
  TNode<IntPtrT> phi_bb176_29;
  TNode<IntPtrT> phi_bb176_30;
  TNode<IntPtrT> phi_bb176_33;
  TNode<BoolT> phi_bb176_34;
  TNode<BoolT> phi_bb176_35;
  TNode<Union<FixedArray, Smi>> phi_bb176_36;
  TNode<Int32T> phi_bb176_38;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb176_41;
  TNode<IntPtrT> phi_bb176_42;
  TNode<Int32T> tmp299;
      TNode<JSAny> tmp301;
  TNode<IntPtrT> tmp302;
      TNode<JSAny> tmp304;
  if (block176.is_used()) {
    ca_.Bind(&block176, &phi_bb176_16, &phi_bb176_17, &phi_bb176_18, &phi_bb176_27, &phi_bb176_28, &phi_bb176_29, &phi_bb176_30, &phi_bb176_33, &phi_bb176_34, &phi_bb176_35, &phi_bb176_36, &phi_bb176_38, &phi_bb176_41, &phi_bb176_42);
    compiler::CodeAssemblerExceptionHandlerLabel catch300__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch300__label);
    tmp299 = CodeStubAssembler(state_).SmiToInt32(TNode<Smi>{tmp288});
    }
    if (catch300__label.is_used()) {
      compiler::CodeAssemblerLabel catch300_skip(&ca_);
      ca_.Goto(&catch300_skip);
      ca_.Bind(&catch300__label, &tmp301);
      ca_.Goto(&block179, phi_bb176_16, phi_bb176_17, phi_bb176_18, phi_bb176_27, phi_bb176_28, phi_bb176_29, phi_bb176_30, phi_bb176_33, phi_bb176_34, phi_bb176_35, phi_bb176_36, phi_bb176_38, phi_bb176_41, phi_bb176_42, phi_bb176_41, phi_bb176_42);
      ca_.Bind(&catch300_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch303__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch303__label);
    tmp302 = Convert_intptr_int32_0(state_, TNode<Int32T>{tmp299});
    }
    if (catch303__label.is_used()) {
      compiler::CodeAssemblerLabel catch303_skip(&ca_);
      ca_.Goto(&catch303_skip);
      ca_.Bind(&catch303__label, &tmp304);
      ca_.Goto(&block180, phi_bb176_16, phi_bb176_17, phi_bb176_18, phi_bb176_27, phi_bb176_28, phi_bb176_29, phi_bb176_30, phi_bb176_33, phi_bb176_34, phi_bb176_35, phi_bb176_36, phi_bb176_38, phi_bb176_41, phi_bb176_42, phi_bb176_41, phi_bb176_42);
      ca_.Bind(&catch303_skip);
    }
    CodeStubAssembler(state_).StoreReference<IntPtrT>(CodeStubAssembler::Reference{phi_bb176_41, phi_bb176_42}, tmp302);
    ca_.Goto(&block174, phi_bb176_16, phi_bb176_17, phi_bb176_18, phi_bb176_27, phi_bb176_28, phi_bb176_29, phi_bb176_30, phi_bb176_33, phi_bb176_34, phi_bb176_35, phi_bb176_36, phi_bb176_38, phi_bb176_41, phi_bb176_42);
  }

  TNode<JSAny> phi_bb179_16;
  TNode<IntPtrT> phi_bb179_17;
  TNode<BoolT> phi_bb179_18;
  TNode<IntPtrT> phi_bb179_27;
  TNode<IntPtrT> phi_bb179_28;
  TNode<IntPtrT> phi_bb179_29;
  TNode<IntPtrT> phi_bb179_30;
  TNode<IntPtrT> phi_bb179_33;
  TNode<BoolT> phi_bb179_34;
  TNode<BoolT> phi_bb179_35;
  TNode<Union<FixedArray, Smi>> phi_bb179_36;
  TNode<Int32T> phi_bb179_38;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb179_41;
  TNode<IntPtrT> phi_bb179_42;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb179_45;
  TNode<IntPtrT> phi_bb179_46;
  TNode<Union<Hole, JSMessageObject>> tmp305;
  if (block179.is_used()) {
    ca_.Bind(&block179, &phi_bb179_16, &phi_bb179_17, &phi_bb179_18, &phi_bb179_27, &phi_bb179_28, &phi_bb179_29, &phi_bb179_30, &phi_bb179_33, &phi_bb179_34, &phi_bb179_35, &phi_bb179_36, &phi_bb179_38, &phi_bb179_41, &phi_bb179_42, &phi_bb179_45, &phi_bb179_46);
    tmp305 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb179_16, phi_bb179_17, phi_bb179_18, tmp301, tmp305);
  }

  TNode<JSAny> phi_bb180_16;
  TNode<IntPtrT> phi_bb180_17;
  TNode<BoolT> phi_bb180_18;
  TNode<IntPtrT> phi_bb180_27;
  TNode<IntPtrT> phi_bb180_28;
  TNode<IntPtrT> phi_bb180_29;
  TNode<IntPtrT> phi_bb180_30;
  TNode<IntPtrT> phi_bb180_33;
  TNode<BoolT> phi_bb180_34;
  TNode<BoolT> phi_bb180_35;
  TNode<Union<FixedArray, Smi>> phi_bb180_36;
  TNode<Int32T> phi_bb180_38;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb180_41;
  TNode<IntPtrT> phi_bb180_42;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb180_45;
  TNode<IntPtrT> phi_bb180_46;
  TNode<Union<Hole, JSMessageObject>> tmp306;
  if (block180.is_used()) {
    ca_.Bind(&block180, &phi_bb180_16, &phi_bb180_17, &phi_bb180_18, &phi_bb180_27, &phi_bb180_28, &phi_bb180_29, &phi_bb180_30, &phi_bb180_33, &phi_bb180_34, &phi_bb180_35, &phi_bb180_36, &phi_bb180_38, &phi_bb180_41, &phi_bb180_42, &phi_bb180_45, &phi_bb180_46);
    tmp306 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb180_16, phi_bb180_17, phi_bb180_18, tmp304, tmp306);
  }

  TNode<JSAny> phi_bb181_16;
  TNode<IntPtrT> phi_bb181_17;
  TNode<BoolT> phi_bb181_18;
  TNode<IntPtrT> phi_bb181_27;
  TNode<IntPtrT> phi_bb181_28;
  TNode<IntPtrT> phi_bb181_29;
  TNode<IntPtrT> phi_bb181_30;
  TNode<IntPtrT> phi_bb181_33;
  TNode<BoolT> phi_bb181_34;
  TNode<BoolT> phi_bb181_35;
  TNode<Union<FixedArray, Smi>> phi_bb181_36;
  TNode<Int32T> phi_bb181_38;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb181_41;
  TNode<IntPtrT> phi_bb181_42;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb181_45;
  TNode<IntPtrT> phi_bb181_46;
  TNode<Union<Hole, JSMessageObject>> tmp307;
  if (block181.is_used()) {
    ca_.Bind(&block181, &phi_bb181_16, &phi_bb181_17, &phi_bb181_18, &phi_bb181_27, &phi_bb181_28, &phi_bb181_29, &phi_bb181_30, &phi_bb181_33, &phi_bb181_34, &phi_bb181_35, &phi_bb181_36, &phi_bb181_38, &phi_bb181_41, &phi_bb181_42, &phi_bb181_45, &phi_bb181_46);
    tmp307 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb181_16, phi_bb181_17, phi_bb181_18, tmp295, tmp307);
  }

  TNode<JSAny> phi_bb182_16;
  TNode<IntPtrT> phi_bb182_17;
  TNode<BoolT> phi_bb182_18;
  TNode<IntPtrT> phi_bb182_27;
  TNode<IntPtrT> phi_bb182_28;
  TNode<IntPtrT> phi_bb182_29;
  TNode<IntPtrT> phi_bb182_30;
  TNode<IntPtrT> phi_bb182_33;
  TNode<BoolT> phi_bb182_34;
  TNode<BoolT> phi_bb182_35;
  TNode<Union<FixedArray, Smi>> phi_bb182_36;
  TNode<Int32T> phi_bb182_38;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb182_41;
  TNode<IntPtrT> phi_bb182_42;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb182_45;
  TNode<IntPtrT> phi_bb182_46;
  TNode<Union<Hole, JSMessageObject>> tmp308;
  if (block182.is_used()) {
    ca_.Bind(&block182, &phi_bb182_16, &phi_bb182_17, &phi_bb182_18, &phi_bb182_27, &phi_bb182_28, &phi_bb182_29, &phi_bb182_30, &phi_bb182_33, &phi_bb182_34, &phi_bb182_35, &phi_bb182_36, &phi_bb182_38, &phi_bb182_41, &phi_bb182_42, &phi_bb182_45, &phi_bb182_46);
    tmp308 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb182_16, phi_bb182_17, phi_bb182_18, tmp298, tmp308);
  }

  TNode<JSAny> phi_bb174_16;
  TNode<IntPtrT> phi_bb174_17;
  TNode<BoolT> phi_bb174_18;
  TNode<IntPtrT> phi_bb174_27;
  TNode<IntPtrT> phi_bb174_28;
  TNode<IntPtrT> phi_bb174_29;
  TNode<IntPtrT> phi_bb174_30;
  TNode<IntPtrT> phi_bb174_33;
  TNode<BoolT> phi_bb174_34;
  TNode<BoolT> phi_bb174_35;
  TNode<Union<FixedArray, Smi>> phi_bb174_36;
  TNode<Int32T> phi_bb174_38;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb174_41;
  TNode<IntPtrT> phi_bb174_42;
  if (block174.is_used()) {
    ca_.Bind(&block174, &phi_bb174_16, &phi_bb174_17, &phi_bb174_18, &phi_bb174_27, &phi_bb174_28, &phi_bb174_29, &phi_bb174_30, &phi_bb174_33, &phi_bb174_34, &phi_bb174_35, &phi_bb174_36, &phi_bb174_38, &phi_bb174_41, &phi_bb174_42);
    ca_.Goto(&block164, phi_bb174_16, phi_bb174_17, phi_bb174_18, tmp264, phi_bb174_27, phi_bb174_28, phi_bb174_29, phi_bb174_30, phi_bb174_33, phi_bb174_34, phi_bb174_35, phi_bb174_36, phi_bb174_38);
  }

  TNode<JSAny> phi_bb161_16;
  TNode<IntPtrT> phi_bb161_17;
  TNode<BoolT> phi_bb161_18;
  TNode<IntPtrT> phi_bb161_26;
  TNode<IntPtrT> phi_bb161_27;
  TNode<IntPtrT> phi_bb161_28;
  TNode<IntPtrT> phi_bb161_29;
  TNode<IntPtrT> phi_bb161_30;
  TNode<IntPtrT> phi_bb161_33;
  TNode<BoolT> phi_bb161_34;
  TNode<BoolT> phi_bb161_35;
  TNode<Union<FixedArray, Smi>> phi_bb161_36;
  TNode<Int32T> phi_bb161_38;
  TNode<Int32T> tmp309;
      TNode<JSAny> tmp311;
  TNode<BoolT> tmp312;
      TNode<JSAny> tmp314;
  if (block161.is_used()) {
    ca_.Bind(&block161, &phi_bb161_16, &phi_bb161_17, &phi_bb161_18, &phi_bb161_26, &phi_bb161_27, &phi_bb161_28, &phi_bb161_29, &phi_bb161_30, &phi_bb161_33, &phi_bb161_34, &phi_bb161_35, &phi_bb161_36, &phi_bb161_38);
    compiler::CodeAssemblerExceptionHandlerLabel catch310__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch310__label);
    tmp309 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmF32.raw_bit_field());
    }
    if (catch310__label.is_used()) {
      compiler::CodeAssemblerLabel catch310_skip(&ca_);
      ca_.Goto(&catch310_skip);
      ca_.Bind(&catch310__label, &tmp311);
      ca_.Goto(&block185, phi_bb161_16, phi_bb161_17, phi_bb161_18, phi_bb161_26, phi_bb161_27, phi_bb161_28, phi_bb161_29, phi_bb161_30, phi_bb161_33, phi_bb161_34, phi_bb161_35, phi_bb161_36, phi_bb161_38);
      ca_.Bind(&catch310_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch313__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch313__label);
    tmp312 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp249}, TNode<Int32T>{tmp309});
    }
    if (catch313__label.is_used()) {
      compiler::CodeAssemblerLabel catch313_skip(&ca_);
      ca_.Goto(&catch313_skip);
      ca_.Bind(&catch313__label, &tmp314);
      ca_.Goto(&block186, phi_bb161_16, phi_bb161_17, phi_bb161_18, phi_bb161_26, phi_bb161_27, phi_bb161_28, phi_bb161_29, phi_bb161_30, phi_bb161_33, phi_bb161_34, phi_bb161_35, phi_bb161_36, phi_bb161_38);
      ca_.Bind(&catch313_skip);
    }
    ca_.Branch(tmp312, &block183, std::vector<compiler::Node*>{phi_bb161_16, phi_bb161_17, phi_bb161_18, phi_bb161_26, phi_bb161_27, phi_bb161_28, phi_bb161_29, phi_bb161_30, phi_bb161_33, phi_bb161_34, phi_bb161_35, phi_bb161_36, phi_bb161_38}, &block184, std::vector<compiler::Node*>{phi_bb161_16, phi_bb161_17, phi_bb161_18, phi_bb161_26, phi_bb161_27, phi_bb161_28, phi_bb161_29, phi_bb161_30, phi_bb161_33, phi_bb161_34, phi_bb161_35, phi_bb161_36, phi_bb161_38});
  }

  TNode<JSAny> phi_bb185_16;
  TNode<IntPtrT> phi_bb185_17;
  TNode<BoolT> phi_bb185_18;
  TNode<IntPtrT> phi_bb185_26;
  TNode<IntPtrT> phi_bb185_27;
  TNode<IntPtrT> phi_bb185_28;
  TNode<IntPtrT> phi_bb185_29;
  TNode<IntPtrT> phi_bb185_30;
  TNode<IntPtrT> phi_bb185_33;
  TNode<BoolT> phi_bb185_34;
  TNode<BoolT> phi_bb185_35;
  TNode<Union<FixedArray, Smi>> phi_bb185_36;
  TNode<Int32T> phi_bb185_38;
  TNode<Union<Hole, JSMessageObject>> tmp315;
  if (block185.is_used()) {
    ca_.Bind(&block185, &phi_bb185_16, &phi_bb185_17, &phi_bb185_18, &phi_bb185_26, &phi_bb185_27, &phi_bb185_28, &phi_bb185_29, &phi_bb185_30, &phi_bb185_33, &phi_bb185_34, &phi_bb185_35, &phi_bb185_36, &phi_bb185_38);
    tmp315 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb185_16, phi_bb185_17, phi_bb185_18, tmp311, tmp315);
  }

  TNode<JSAny> phi_bb186_16;
  TNode<IntPtrT> phi_bb186_17;
  TNode<BoolT> phi_bb186_18;
  TNode<IntPtrT> phi_bb186_26;
  TNode<IntPtrT> phi_bb186_27;
  TNode<IntPtrT> phi_bb186_28;
  TNode<IntPtrT> phi_bb186_29;
  TNode<IntPtrT> phi_bb186_30;
  TNode<IntPtrT> phi_bb186_33;
  TNode<BoolT> phi_bb186_34;
  TNode<BoolT> phi_bb186_35;
  TNode<Union<FixedArray, Smi>> phi_bb186_36;
  TNode<Int32T> phi_bb186_38;
  TNode<Union<Hole, JSMessageObject>> tmp316;
  if (block186.is_used()) {
    ca_.Bind(&block186, &phi_bb186_16, &phi_bb186_17, &phi_bb186_18, &phi_bb186_26, &phi_bb186_27, &phi_bb186_28, &phi_bb186_29, &phi_bb186_30, &phi_bb186_33, &phi_bb186_34, &phi_bb186_35, &phi_bb186_36, &phi_bb186_38);
    tmp316 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb186_16, phi_bb186_17, phi_bb186_18, tmp314, tmp316);
  }

  TNode<JSAny> phi_bb183_16;
  TNode<IntPtrT> phi_bb183_17;
  TNode<BoolT> phi_bb183_18;
  TNode<IntPtrT> phi_bb183_26;
  TNode<IntPtrT> phi_bb183_27;
  TNode<IntPtrT> phi_bb183_28;
  TNode<IntPtrT> phi_bb183_29;
  TNode<IntPtrT> phi_bb183_30;
  TNode<IntPtrT> phi_bb183_33;
  TNode<BoolT> phi_bb183_34;
  TNode<BoolT> phi_bb183_35;
  TNode<Union<FixedArray, Smi>> phi_bb183_36;
  TNode<Int32T> phi_bb183_38;
  TNode<IntPtrT> tmp317;
  TNode<IntPtrT> tmp318;
  TNode<IntPtrT> tmp319;
  TNode<BoolT> tmp320;
  if (block183.is_used()) {
    ca_.Bind(&block183, &phi_bb183_16, &phi_bb183_17, &phi_bb183_18, &phi_bb183_26, &phi_bb183_27, &phi_bb183_28, &phi_bb183_29, &phi_bb183_30, &phi_bb183_33, &phi_bb183_34, &phi_bb183_35, &phi_bb183_36, &phi_bb183_38);
    tmp317 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp318 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{phi_bb183_27}, TNode<IntPtrT>{tmp317});
    tmp319 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp320 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{phi_bb183_27}, TNode<IntPtrT>{tmp319});
    ca_.Branch(tmp320, &block189, std::vector<compiler::Node*>{phi_bb183_16, phi_bb183_17, phi_bb183_18, phi_bb183_26, phi_bb183_28, phi_bb183_29, phi_bb183_30, phi_bb183_33, phi_bb183_34, phi_bb183_35, phi_bb183_36, phi_bb183_38}, &block190, std::vector<compiler::Node*>{phi_bb183_16, phi_bb183_17, phi_bb183_18, phi_bb183_26, phi_bb183_28, phi_bb183_29, phi_bb183_30, phi_bb183_33, phi_bb183_34, phi_bb183_35, phi_bb183_36, phi_bb183_38});
  }

  TNode<JSAny> phi_bb189_16;
  TNode<IntPtrT> phi_bb189_17;
  TNode<BoolT> phi_bb189_18;
  TNode<IntPtrT> phi_bb189_26;
  TNode<IntPtrT> phi_bb189_28;
  TNode<IntPtrT> phi_bb189_29;
  TNode<IntPtrT> phi_bb189_30;
  TNode<IntPtrT> phi_bb189_33;
  TNode<BoolT> phi_bb189_34;
  TNode<BoolT> phi_bb189_35;
  TNode<Union<FixedArray, Smi>> phi_bb189_36;
  TNode<Int32T> phi_bb189_38;
  TNode<Union<HeapObject, TaggedIndex>> tmp321;
  TNode<IntPtrT> tmp322;
  TNode<IntPtrT> tmp323;
  TNode<IntPtrT> tmp324;
  if (block189.is_used()) {
    ca_.Bind(&block189, &phi_bb189_16, &phi_bb189_17, &phi_bb189_18, &phi_bb189_26, &phi_bb189_28, &phi_bb189_29, &phi_bb189_30, &phi_bb189_33, &phi_bb189_34, &phi_bb189_35, &phi_bb189_36, &phi_bb189_38);
    std::tie(tmp321, tmp322) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp197}, TNode<IntPtrT>{phi_bb189_29}).Flatten();
    tmp323 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_float64_0(state_)));
    tmp324 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb189_29}, TNode<IntPtrT>{tmp323});
    ca_.Goto(&block188, phi_bb189_16, phi_bb189_17, phi_bb189_18, phi_bb189_26, phi_bb189_28, tmp324, phi_bb189_30, phi_bb189_33, phi_bb189_34, phi_bb189_35, phi_bb189_36, phi_bb189_38, tmp321, tmp322);
  }

  TNode<JSAny> phi_bb190_16;
  TNode<IntPtrT> phi_bb190_17;
  TNode<BoolT> phi_bb190_18;
  TNode<IntPtrT> phi_bb190_26;
  TNode<IntPtrT> phi_bb190_28;
  TNode<IntPtrT> phi_bb190_29;
  TNode<IntPtrT> phi_bb190_30;
  TNode<IntPtrT> phi_bb190_33;
  TNode<BoolT> phi_bb190_34;
  TNode<BoolT> phi_bb190_35;
  TNode<Union<FixedArray, Smi>> phi_bb190_36;
  TNode<Int32T> phi_bb190_38;
  if (block190.is_used()) {
    ca_.Bind(&block190, &phi_bb190_16, &phi_bb190_17, &phi_bb190_18, &phi_bb190_26, &phi_bb190_28, &phi_bb190_29, &phi_bb190_30, &phi_bb190_33, &phi_bb190_34, &phi_bb190_35, &phi_bb190_36, &phi_bb190_38);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block192, phi_bb190_16, phi_bb190_17, phi_bb190_18, phi_bb190_26, phi_bb190_28, phi_bb190_29, phi_bb190_30, phi_bb190_33, phi_bb190_34, phi_bb190_35, phi_bb190_36, phi_bb190_38);
    } else {
      ca_.Goto(&block193, phi_bb190_16, phi_bb190_17, phi_bb190_18, phi_bb190_26, phi_bb190_28, phi_bb190_29, phi_bb190_30, phi_bb190_33, phi_bb190_34, phi_bb190_35, phi_bb190_36, phi_bb190_38);
    }
  }

  TNode<JSAny> phi_bb192_16;
  TNode<IntPtrT> phi_bb192_17;
  TNode<BoolT> phi_bb192_18;
  TNode<IntPtrT> phi_bb192_26;
  TNode<IntPtrT> phi_bb192_28;
  TNode<IntPtrT> phi_bb192_29;
  TNode<IntPtrT> phi_bb192_30;
  TNode<IntPtrT> phi_bb192_33;
  TNode<BoolT> phi_bb192_34;
  TNode<BoolT> phi_bb192_35;
  TNode<Union<FixedArray, Smi>> phi_bb192_36;
  TNode<Int32T> phi_bb192_38;
  TNode<Union<HeapObject, TaggedIndex>> tmp325;
  TNode<IntPtrT> tmp326;
  TNode<IntPtrT> tmp327;
  TNode<IntPtrT> tmp328;
  if (block192.is_used()) {
    ca_.Bind(&block192, &phi_bb192_16, &phi_bb192_17, &phi_bb192_18, &phi_bb192_26, &phi_bb192_28, &phi_bb192_29, &phi_bb192_30, &phi_bb192_33, &phi_bb192_34, &phi_bb192_35, &phi_bb192_36, &phi_bb192_38);
    std::tie(tmp325, tmp326) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp197}, TNode<IntPtrT>{phi_bb192_30}).Flatten();
    tmp327 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp328 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb192_30}, TNode<IntPtrT>{tmp327});
    ca_.Goto(&block191, phi_bb192_16, phi_bb192_17, phi_bb192_18, phi_bb192_26, phi_bb192_28, phi_bb192_29, tmp328, phi_bb192_33, phi_bb192_34, phi_bb192_35, phi_bb192_36, phi_bb192_38, tmp325, tmp326);
  }

  TNode<JSAny> phi_bb193_16;
  TNode<IntPtrT> phi_bb193_17;
  TNode<BoolT> phi_bb193_18;
  TNode<IntPtrT> phi_bb193_26;
  TNode<IntPtrT> phi_bb193_28;
  TNode<IntPtrT> phi_bb193_29;
  TNode<IntPtrT> phi_bb193_30;
  TNode<IntPtrT> phi_bb193_33;
  TNode<BoolT> phi_bb193_34;
  TNode<BoolT> phi_bb193_35;
  TNode<Union<FixedArray, Smi>> phi_bb193_36;
  TNode<Int32T> phi_bb193_38;
  TNode<IntPtrT> tmp329;
  TNode<BoolT> tmp330;
  if (block193.is_used()) {
    ca_.Bind(&block193, &phi_bb193_16, &phi_bb193_17, &phi_bb193_18, &phi_bb193_26, &phi_bb193_28, &phi_bb193_29, &phi_bb193_30, &phi_bb193_33, &phi_bb193_34, &phi_bb193_35, &phi_bb193_36, &phi_bb193_38);
    tmp329 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp330 = CodeStubAssembler(state_).WordNotEqual(TNode<IntPtrT>{phi_bb193_33}, TNode<IntPtrT>{tmp329});
    ca_.Branch(tmp330, &block195, std::vector<compiler::Node*>{phi_bb193_16, phi_bb193_17, phi_bb193_18, phi_bb193_26, phi_bb193_28, phi_bb193_29, phi_bb193_30, phi_bb193_33, phi_bb193_34, phi_bb193_35, phi_bb193_36, phi_bb193_38}, &block196, std::vector<compiler::Node*>{phi_bb193_16, phi_bb193_17, phi_bb193_18, phi_bb193_26, phi_bb193_28, phi_bb193_29, phi_bb193_30, phi_bb193_33, phi_bb193_34, phi_bb193_35, phi_bb193_36, phi_bb193_38});
  }

  TNode<JSAny> phi_bb195_16;
  TNode<IntPtrT> phi_bb195_17;
  TNode<BoolT> phi_bb195_18;
  TNode<IntPtrT> phi_bb195_26;
  TNode<IntPtrT> phi_bb195_28;
  TNode<IntPtrT> phi_bb195_29;
  TNode<IntPtrT> phi_bb195_30;
  TNode<IntPtrT> phi_bb195_33;
  TNode<BoolT> phi_bb195_34;
  TNode<BoolT> phi_bb195_35;
  TNode<Union<FixedArray, Smi>> phi_bb195_36;
  TNode<Int32T> phi_bb195_38;
  TNode<Union<HeapObject, TaggedIndex>> tmp331;
  TNode<IntPtrT> tmp332;
  TNode<IntPtrT> tmp333;
  TNode<BoolT> tmp334;
  if (block195.is_used()) {
    ca_.Bind(&block195, &phi_bb195_16, &phi_bb195_17, &phi_bb195_18, &phi_bb195_26, &phi_bb195_28, &phi_bb195_29, &phi_bb195_30, &phi_bb195_33, &phi_bb195_34, &phi_bb195_35, &phi_bb195_36, &phi_bb195_38);
    std::tie(tmp331, tmp332) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp197}, TNode<IntPtrT>{phi_bb195_33}).Flatten();
    tmp333 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp334 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block191, phi_bb195_16, phi_bb195_17, phi_bb195_18, phi_bb195_26, phi_bb195_28, phi_bb195_29, phi_bb195_30, tmp333, tmp334, phi_bb195_35, phi_bb195_36, phi_bb195_38, tmp331, tmp332);
  }

  TNode<JSAny> phi_bb196_16;
  TNode<IntPtrT> phi_bb196_17;
  TNode<BoolT> phi_bb196_18;
  TNode<IntPtrT> phi_bb196_26;
  TNode<IntPtrT> phi_bb196_28;
  TNode<IntPtrT> phi_bb196_29;
  TNode<IntPtrT> phi_bb196_30;
  TNode<IntPtrT> phi_bb196_33;
  TNode<BoolT> phi_bb196_34;
  TNode<BoolT> phi_bb196_35;
  TNode<Union<FixedArray, Smi>> phi_bb196_36;
  TNode<Int32T> phi_bb196_38;
  TNode<Union<HeapObject, TaggedIndex>> tmp335;
  TNode<IntPtrT> tmp336;
  TNode<IntPtrT> tmp337;
  TNode<IntPtrT> tmp338;
  TNode<IntPtrT> tmp339;
  TNode<IntPtrT> tmp340;
  TNode<BoolT> tmp341;
  if (block196.is_used()) {
    ca_.Bind(&block196, &phi_bb196_16, &phi_bb196_17, &phi_bb196_18, &phi_bb196_26, &phi_bb196_28, &phi_bb196_29, &phi_bb196_30, &phi_bb196_33, &phi_bb196_34, &phi_bb196_35, &phi_bb196_36, &phi_bb196_38);
    std::tie(tmp335, tmp336) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp197}, TNode<IntPtrT>{phi_bb196_30}).Flatten();
    tmp337 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp338 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb196_30}, TNode<IntPtrT>{tmp337});
    tmp339 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp340 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp338}, TNode<IntPtrT>{tmp339});
    tmp341 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block191, phi_bb196_16, phi_bb196_17, phi_bb196_18, phi_bb196_26, phi_bb196_28, phi_bb196_29, tmp340, tmp338, tmp341, phi_bb196_35, phi_bb196_36, phi_bb196_38, tmp335, tmp336);
  }

  TNode<JSAny> phi_bb191_16;
  TNode<IntPtrT> phi_bb191_17;
  TNode<BoolT> phi_bb191_18;
  TNode<IntPtrT> phi_bb191_26;
  TNode<IntPtrT> phi_bb191_28;
  TNode<IntPtrT> phi_bb191_29;
  TNode<IntPtrT> phi_bb191_30;
  TNode<IntPtrT> phi_bb191_33;
  TNode<BoolT> phi_bb191_34;
  TNode<BoolT> phi_bb191_35;
  TNode<Union<FixedArray, Smi>> phi_bb191_36;
  TNode<Int32T> phi_bb191_38;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb191_41;
  TNode<IntPtrT> phi_bb191_42;
  if (block191.is_used()) {
    ca_.Bind(&block191, &phi_bb191_16, &phi_bb191_17, &phi_bb191_18, &phi_bb191_26, &phi_bb191_28, &phi_bb191_29, &phi_bb191_30, &phi_bb191_33, &phi_bb191_34, &phi_bb191_35, &phi_bb191_36, &phi_bb191_38, &phi_bb191_41, &phi_bb191_42);
    ca_.Goto(&block188, phi_bb191_16, phi_bb191_17, phi_bb191_18, phi_bb191_26, phi_bb191_28, phi_bb191_29, phi_bb191_30, phi_bb191_33, phi_bb191_34, phi_bb191_35, phi_bb191_36, phi_bb191_38, phi_bb191_41, phi_bb191_42);
  }

  TNode<JSAny> phi_bb188_16;
  TNode<IntPtrT> phi_bb188_17;
  TNode<BoolT> phi_bb188_18;
  TNode<IntPtrT> phi_bb188_26;
  TNode<IntPtrT> phi_bb188_28;
  TNode<IntPtrT> phi_bb188_29;
  TNode<IntPtrT> phi_bb188_30;
  TNode<IntPtrT> phi_bb188_33;
  TNode<BoolT> phi_bb188_34;
  TNode<BoolT> phi_bb188_35;
  TNode<Union<FixedArray, Smi>> phi_bb188_36;
  TNode<Int32T> phi_bb188_38;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb188_41;
  TNode<IntPtrT> phi_bb188_42;
  if (block188.is_used()) {
    ca_.Bind(&block188, &phi_bb188_16, &phi_bb188_17, &phi_bb188_18, &phi_bb188_26, &phi_bb188_28, &phi_bb188_29, &phi_bb188_30, &phi_bb188_33, &phi_bb188_34, &phi_bb188_35, &phi_bb188_36, &phi_bb188_38, &phi_bb188_41, &phi_bb188_42);
    if ((((wasm::kIsFpAlwaysDouble || wasm::kIsBigEndian) || wasm::kIsBigEndianOnSim))) {
      ca_.Goto(&block197, phi_bb188_16, phi_bb188_17, phi_bb188_18, phi_bb188_26, phi_bb188_28, phi_bb188_29, phi_bb188_30, phi_bb188_33, phi_bb188_34, phi_bb188_35, phi_bb188_36, phi_bb188_38, phi_bb188_41, phi_bb188_42);
    } else {
      ca_.Goto(&block198, phi_bb188_16, phi_bb188_17, phi_bb188_18, phi_bb188_26, phi_bb188_28, phi_bb188_29, phi_bb188_30, phi_bb188_33, phi_bb188_34, phi_bb188_35, phi_bb188_36, phi_bb188_38, phi_bb188_41, phi_bb188_42);
    }
  }

  TNode<JSAny> phi_bb197_16;
  TNode<IntPtrT> phi_bb197_17;
  TNode<BoolT> phi_bb197_18;
  TNode<IntPtrT> phi_bb197_26;
  TNode<IntPtrT> phi_bb197_28;
  TNode<IntPtrT> phi_bb197_29;
  TNode<IntPtrT> phi_bb197_30;
  TNode<IntPtrT> phi_bb197_33;
  TNode<BoolT> phi_bb197_34;
  TNode<BoolT> phi_bb197_35;
  TNode<Union<FixedArray, Smi>> phi_bb197_36;
  TNode<Int32T> phi_bb197_38;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb197_41;
  TNode<IntPtrT> phi_bb197_42;
      TNode<JSAny> tmp343;
  if (block197.is_used()) {
    ca_.Bind(&block197, &phi_bb197_16, &phi_bb197_17, &phi_bb197_18, &phi_bb197_26, &phi_bb197_28, &phi_bb197_29, &phi_bb197_30, &phi_bb197_33, &phi_bb197_34, &phi_bb197_35, &phi_bb197_36, &phi_bb197_38, &phi_bb197_41, &phi_bb197_42);
    compiler::CodeAssemblerExceptionHandlerLabel catch342__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch342__label);
    HandleF32Params_0(state_, TNode<NativeContext>{p_context}, TorqueStructLocationAllocator_0{TNode<Union<HeapObject, TaggedIndex>>{tmp197}, TNode<IntPtrT>{phi_bb197_26}, TNode<IntPtrT>{tmp318}, TNode<IntPtrT>{phi_bb197_28}, TNode<IntPtrT>{phi_bb197_29}, TNode<IntPtrT>{phi_bb197_30}, TNode<IntPtrT>{tmp203}, TNode<IntPtrT>{tmp204}, TNode<IntPtrT>{phi_bb197_33}, TNode<BoolT>{phi_bb197_34}}, TorqueStructReference_intptr_0{TNode<Union<HeapObject, TaggedIndex>>{phi_bb197_41}, TNode<IntPtrT>{phi_bb197_42}, TorqueStructUnsafe_0{}}, TNode<JSAny>{tmp233});
    }
    if (catch342__label.is_used()) {
      compiler::CodeAssemblerLabel catch342_skip(&ca_);
      ca_.Goto(&catch342_skip);
      ca_.Bind(&catch342__label, &tmp343);
      ca_.Goto(&block200, phi_bb197_16, phi_bb197_17, phi_bb197_18, phi_bb197_26, phi_bb197_28, phi_bb197_29, phi_bb197_30, phi_bb197_33, phi_bb197_34, phi_bb197_35, phi_bb197_36, phi_bb197_38, phi_bb197_41, phi_bb197_42, phi_bb197_26, phi_bb197_28, phi_bb197_29, phi_bb197_30, phi_bb197_33, phi_bb197_34, phi_bb197_41, phi_bb197_42);
      ca_.Bind(&catch342_skip);
    }
    ca_.Goto(&block199, phi_bb197_16, phi_bb197_17, phi_bb197_18, phi_bb197_26, phi_bb197_28, phi_bb197_29, phi_bb197_30, phi_bb197_33, phi_bb197_34, phi_bb197_35, phi_bb197_36, phi_bb197_38, phi_bb197_41, phi_bb197_42);
  }

  TNode<JSAny> phi_bb200_16;
  TNode<IntPtrT> phi_bb200_17;
  TNode<BoolT> phi_bb200_18;
  TNode<IntPtrT> phi_bb200_26;
  TNode<IntPtrT> phi_bb200_28;
  TNode<IntPtrT> phi_bb200_29;
  TNode<IntPtrT> phi_bb200_30;
  TNode<IntPtrT> phi_bb200_33;
  TNode<BoolT> phi_bb200_34;
  TNode<BoolT> phi_bb200_35;
  TNode<Union<FixedArray, Smi>> phi_bb200_36;
  TNode<Int32T> phi_bb200_38;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb200_41;
  TNode<IntPtrT> phi_bb200_42;
  TNode<IntPtrT> phi_bb200_45;
  TNode<IntPtrT> phi_bb200_47;
  TNode<IntPtrT> phi_bb200_48;
  TNode<IntPtrT> phi_bb200_49;
  TNode<IntPtrT> phi_bb200_52;
  TNode<BoolT> phi_bb200_53;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb200_54;
  TNode<IntPtrT> phi_bb200_55;
  TNode<Union<Hole, JSMessageObject>> tmp344;
  if (block200.is_used()) {
    ca_.Bind(&block200, &phi_bb200_16, &phi_bb200_17, &phi_bb200_18, &phi_bb200_26, &phi_bb200_28, &phi_bb200_29, &phi_bb200_30, &phi_bb200_33, &phi_bb200_34, &phi_bb200_35, &phi_bb200_36, &phi_bb200_38, &phi_bb200_41, &phi_bb200_42, &phi_bb200_45, &phi_bb200_47, &phi_bb200_48, &phi_bb200_49, &phi_bb200_52, &phi_bb200_53, &phi_bb200_54, &phi_bb200_55);
    tmp344 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb200_16, phi_bb200_17, phi_bb200_18, tmp343, tmp344);
  }

  TNode<JSAny> phi_bb198_16;
  TNode<IntPtrT> phi_bb198_17;
  TNode<BoolT> phi_bb198_18;
  TNode<IntPtrT> phi_bb198_26;
  TNode<IntPtrT> phi_bb198_28;
  TNode<IntPtrT> phi_bb198_29;
  TNode<IntPtrT> phi_bb198_30;
  TNode<IntPtrT> phi_bb198_33;
  TNode<BoolT> phi_bb198_34;
  TNode<BoolT> phi_bb198_35;
  TNode<Union<FixedArray, Smi>> phi_bb198_36;
  TNode<Int32T> phi_bb198_38;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb198_41;
  TNode<IntPtrT> phi_bb198_42;
  TNode<Float32T> tmp345;
      TNode<JSAny> tmp347;
  TNode<Uint32T> tmp348;
      TNode<JSAny> tmp350;
  TNode<IntPtrT> tmp351;
      TNode<JSAny> tmp353;
  if (block198.is_used()) {
    ca_.Bind(&block198, &phi_bb198_16, &phi_bb198_17, &phi_bb198_18, &phi_bb198_26, &phi_bb198_28, &phi_bb198_29, &phi_bb198_30, &phi_bb198_33, &phi_bb198_34, &phi_bb198_35, &phi_bb198_36, &phi_bb198_38, &phi_bb198_41, &phi_bb198_42);
    compiler::CodeAssemblerExceptionHandlerLabel catch346__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch346__label);
    tmp345 = ca_.CallBuiltin<Float32T>(Builtin::kWasmTaggedToFloat32, p_context, tmp233);
    }
    if (catch346__label.is_used()) {
      compiler::CodeAssemblerLabel catch346_skip(&ca_);
      ca_.Goto(&catch346_skip);
      ca_.Bind(&catch346__label, &tmp347);
      ca_.Goto(&block201, phi_bb198_16, phi_bb198_17, phi_bb198_18, phi_bb198_26, phi_bb198_28, phi_bb198_29, phi_bb198_30, phi_bb198_33, phi_bb198_34, phi_bb198_35, phi_bb198_36, phi_bb198_38, phi_bb198_41, phi_bb198_42, phi_bb198_41, phi_bb198_42);
      ca_.Bind(&catch346_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch349__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch349__label);
    tmp348 = Bitcast_WasmCodePointer_float32_0(state_, TNode<Float32T>{tmp345});
    }
    if (catch349__label.is_used()) {
      compiler::CodeAssemblerLabel catch349_skip(&ca_);
      ca_.Goto(&catch349_skip);
      ca_.Bind(&catch349__label, &tmp350);
      ca_.Goto(&block202, phi_bb198_16, phi_bb198_17, phi_bb198_18, phi_bb198_26, phi_bb198_28, phi_bb198_29, phi_bb198_30, phi_bb198_33, phi_bb198_34, phi_bb198_35, phi_bb198_36, phi_bb198_38, phi_bb198_41, phi_bb198_42, phi_bb198_41, phi_bb198_42);
      ca_.Bind(&catch349_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch352__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch352__label);
    tmp351 = Convert_intptr_WasmCodePointer_0(state_, TNode<Uint32T>{tmp348});
    }
    if (catch352__label.is_used()) {
      compiler::CodeAssemblerLabel catch352_skip(&ca_);
      ca_.Goto(&catch352_skip);
      ca_.Bind(&catch352__label, &tmp353);
      ca_.Goto(&block203, phi_bb198_16, phi_bb198_17, phi_bb198_18, phi_bb198_26, phi_bb198_28, phi_bb198_29, phi_bb198_30, phi_bb198_33, phi_bb198_34, phi_bb198_35, phi_bb198_36, phi_bb198_38, phi_bb198_41, phi_bb198_42, phi_bb198_41, phi_bb198_42);
      ca_.Bind(&catch352_skip);
    }
    CodeStubAssembler(state_).StoreReference<IntPtrT>(CodeStubAssembler::Reference{phi_bb198_41, phi_bb198_42}, tmp351);
    ca_.Goto(&block199, phi_bb198_16, phi_bb198_17, phi_bb198_18, phi_bb198_26, phi_bb198_28, phi_bb198_29, phi_bb198_30, phi_bb198_33, phi_bb198_34, phi_bb198_35, phi_bb198_36, phi_bb198_38, phi_bb198_41, phi_bb198_42);
  }

  TNode<JSAny> phi_bb201_16;
  TNode<IntPtrT> phi_bb201_17;
  TNode<BoolT> phi_bb201_18;
  TNode<IntPtrT> phi_bb201_26;
  TNode<IntPtrT> phi_bb201_28;
  TNode<IntPtrT> phi_bb201_29;
  TNode<IntPtrT> phi_bb201_30;
  TNode<IntPtrT> phi_bb201_33;
  TNode<BoolT> phi_bb201_34;
  TNode<BoolT> phi_bb201_35;
  TNode<Union<FixedArray, Smi>> phi_bb201_36;
  TNode<Int32T> phi_bb201_38;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb201_41;
  TNode<IntPtrT> phi_bb201_42;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb201_43;
  TNode<IntPtrT> phi_bb201_44;
  TNode<Union<Hole, JSMessageObject>> tmp354;
  if (block201.is_used()) {
    ca_.Bind(&block201, &phi_bb201_16, &phi_bb201_17, &phi_bb201_18, &phi_bb201_26, &phi_bb201_28, &phi_bb201_29, &phi_bb201_30, &phi_bb201_33, &phi_bb201_34, &phi_bb201_35, &phi_bb201_36, &phi_bb201_38, &phi_bb201_41, &phi_bb201_42, &phi_bb201_43, &phi_bb201_44);
    tmp354 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb201_16, phi_bb201_17, phi_bb201_18, tmp347, tmp354);
  }

  TNode<JSAny> phi_bb202_16;
  TNode<IntPtrT> phi_bb202_17;
  TNode<BoolT> phi_bb202_18;
  TNode<IntPtrT> phi_bb202_26;
  TNode<IntPtrT> phi_bb202_28;
  TNode<IntPtrT> phi_bb202_29;
  TNode<IntPtrT> phi_bb202_30;
  TNode<IntPtrT> phi_bb202_33;
  TNode<BoolT> phi_bb202_34;
  TNode<BoolT> phi_bb202_35;
  TNode<Union<FixedArray, Smi>> phi_bb202_36;
  TNode<Int32T> phi_bb202_38;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb202_41;
  TNode<IntPtrT> phi_bb202_42;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb202_43;
  TNode<IntPtrT> phi_bb202_44;
  TNode<Union<Hole, JSMessageObject>> tmp355;
  if (block202.is_used()) {
    ca_.Bind(&block202, &phi_bb202_16, &phi_bb202_17, &phi_bb202_18, &phi_bb202_26, &phi_bb202_28, &phi_bb202_29, &phi_bb202_30, &phi_bb202_33, &phi_bb202_34, &phi_bb202_35, &phi_bb202_36, &phi_bb202_38, &phi_bb202_41, &phi_bb202_42, &phi_bb202_43, &phi_bb202_44);
    tmp355 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb202_16, phi_bb202_17, phi_bb202_18, tmp350, tmp355);
  }

  TNode<JSAny> phi_bb203_16;
  TNode<IntPtrT> phi_bb203_17;
  TNode<BoolT> phi_bb203_18;
  TNode<IntPtrT> phi_bb203_26;
  TNode<IntPtrT> phi_bb203_28;
  TNode<IntPtrT> phi_bb203_29;
  TNode<IntPtrT> phi_bb203_30;
  TNode<IntPtrT> phi_bb203_33;
  TNode<BoolT> phi_bb203_34;
  TNode<BoolT> phi_bb203_35;
  TNode<Union<FixedArray, Smi>> phi_bb203_36;
  TNode<Int32T> phi_bb203_38;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb203_41;
  TNode<IntPtrT> phi_bb203_42;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb203_43;
  TNode<IntPtrT> phi_bb203_44;
  TNode<Union<Hole, JSMessageObject>> tmp356;
  if (block203.is_used()) {
    ca_.Bind(&block203, &phi_bb203_16, &phi_bb203_17, &phi_bb203_18, &phi_bb203_26, &phi_bb203_28, &phi_bb203_29, &phi_bb203_30, &phi_bb203_33, &phi_bb203_34, &phi_bb203_35, &phi_bb203_36, &phi_bb203_38, &phi_bb203_41, &phi_bb203_42, &phi_bb203_43, &phi_bb203_44);
    tmp356 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb203_16, phi_bb203_17, phi_bb203_18, tmp353, tmp356);
  }

  TNode<JSAny> phi_bb199_16;
  TNode<IntPtrT> phi_bb199_17;
  TNode<BoolT> phi_bb199_18;
  TNode<IntPtrT> phi_bb199_26;
  TNode<IntPtrT> phi_bb199_28;
  TNode<IntPtrT> phi_bb199_29;
  TNode<IntPtrT> phi_bb199_30;
  TNode<IntPtrT> phi_bb199_33;
  TNode<BoolT> phi_bb199_34;
  TNode<BoolT> phi_bb199_35;
  TNode<Union<FixedArray, Smi>> phi_bb199_36;
  TNode<Int32T> phi_bb199_38;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb199_41;
  TNode<IntPtrT> phi_bb199_42;
  if (block199.is_used()) {
    ca_.Bind(&block199, &phi_bb199_16, &phi_bb199_17, &phi_bb199_18, &phi_bb199_26, &phi_bb199_28, &phi_bb199_29, &phi_bb199_30, &phi_bb199_33, &phi_bb199_34, &phi_bb199_35, &phi_bb199_36, &phi_bb199_38, &phi_bb199_41, &phi_bb199_42);
    ca_.Goto(&block187, phi_bb199_16, phi_bb199_17, phi_bb199_18, phi_bb199_26, tmp318, phi_bb199_28, phi_bb199_29, phi_bb199_30, phi_bb199_33, phi_bb199_34, phi_bb199_35, phi_bb199_36, phi_bb199_38);
  }

  TNode<JSAny> phi_bb184_16;
  TNode<IntPtrT> phi_bb184_17;
  TNode<BoolT> phi_bb184_18;
  TNode<IntPtrT> phi_bb184_26;
  TNode<IntPtrT> phi_bb184_27;
  TNode<IntPtrT> phi_bb184_28;
  TNode<IntPtrT> phi_bb184_29;
  TNode<IntPtrT> phi_bb184_30;
  TNode<IntPtrT> phi_bb184_33;
  TNode<BoolT> phi_bb184_34;
  TNode<BoolT> phi_bb184_35;
  TNode<Union<FixedArray, Smi>> phi_bb184_36;
  TNode<Int32T> phi_bb184_38;
  TNode<Int32T> tmp357;
      TNode<JSAny> tmp359;
  TNode<BoolT> tmp360;
      TNode<JSAny> tmp362;
  if (block184.is_used()) {
    ca_.Bind(&block184, &phi_bb184_16, &phi_bb184_17, &phi_bb184_18, &phi_bb184_26, &phi_bb184_27, &phi_bb184_28, &phi_bb184_29, &phi_bb184_30, &phi_bb184_33, &phi_bb184_34, &phi_bb184_35, &phi_bb184_36, &phi_bb184_38);
    compiler::CodeAssemblerExceptionHandlerLabel catch358__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch358__label);
    tmp357 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmF64.raw_bit_field());
    }
    if (catch358__label.is_used()) {
      compiler::CodeAssemblerLabel catch358_skip(&ca_);
      ca_.Goto(&catch358_skip);
      ca_.Bind(&catch358__label, &tmp359);
      ca_.Goto(&block206, phi_bb184_16, phi_bb184_17, phi_bb184_18, phi_bb184_26, phi_bb184_27, phi_bb184_28, phi_bb184_29, phi_bb184_30, phi_bb184_33, phi_bb184_34, phi_bb184_35, phi_bb184_36, phi_bb184_38);
      ca_.Bind(&catch358_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch361__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch361__label);
    tmp360 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp249}, TNode<Int32T>{tmp357});
    }
    if (catch361__label.is_used()) {
      compiler::CodeAssemblerLabel catch361_skip(&ca_);
      ca_.Goto(&catch361_skip);
      ca_.Bind(&catch361__label, &tmp362);
      ca_.Goto(&block207, phi_bb184_16, phi_bb184_17, phi_bb184_18, phi_bb184_26, phi_bb184_27, phi_bb184_28, phi_bb184_29, phi_bb184_30, phi_bb184_33, phi_bb184_34, phi_bb184_35, phi_bb184_36, phi_bb184_38);
      ca_.Bind(&catch361_skip);
    }
    ca_.Branch(tmp360, &block204, std::vector<compiler::Node*>{phi_bb184_16, phi_bb184_17, phi_bb184_18, phi_bb184_26, phi_bb184_27, phi_bb184_28, phi_bb184_29, phi_bb184_30, phi_bb184_33, phi_bb184_34, phi_bb184_35, phi_bb184_36, phi_bb184_38}, &block205, std::vector<compiler::Node*>{phi_bb184_16, phi_bb184_17, phi_bb184_18, phi_bb184_26, phi_bb184_27, phi_bb184_28, phi_bb184_29, phi_bb184_30, phi_bb184_33, phi_bb184_34, phi_bb184_35, phi_bb184_36, phi_bb184_38});
  }

  TNode<JSAny> phi_bb206_16;
  TNode<IntPtrT> phi_bb206_17;
  TNode<BoolT> phi_bb206_18;
  TNode<IntPtrT> phi_bb206_26;
  TNode<IntPtrT> phi_bb206_27;
  TNode<IntPtrT> phi_bb206_28;
  TNode<IntPtrT> phi_bb206_29;
  TNode<IntPtrT> phi_bb206_30;
  TNode<IntPtrT> phi_bb206_33;
  TNode<BoolT> phi_bb206_34;
  TNode<BoolT> phi_bb206_35;
  TNode<Union<FixedArray, Smi>> phi_bb206_36;
  TNode<Int32T> phi_bb206_38;
  TNode<Union<Hole, JSMessageObject>> tmp363;
  if (block206.is_used()) {
    ca_.Bind(&block206, &phi_bb206_16, &phi_bb206_17, &phi_bb206_18, &phi_bb206_26, &phi_bb206_27, &phi_bb206_28, &phi_bb206_29, &phi_bb206_30, &phi_bb206_33, &phi_bb206_34, &phi_bb206_35, &phi_bb206_36, &phi_bb206_38);
    tmp363 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb206_16, phi_bb206_17, phi_bb206_18, tmp359, tmp363);
  }

  TNode<JSAny> phi_bb207_16;
  TNode<IntPtrT> phi_bb207_17;
  TNode<BoolT> phi_bb207_18;
  TNode<IntPtrT> phi_bb207_26;
  TNode<IntPtrT> phi_bb207_27;
  TNode<IntPtrT> phi_bb207_28;
  TNode<IntPtrT> phi_bb207_29;
  TNode<IntPtrT> phi_bb207_30;
  TNode<IntPtrT> phi_bb207_33;
  TNode<BoolT> phi_bb207_34;
  TNode<BoolT> phi_bb207_35;
  TNode<Union<FixedArray, Smi>> phi_bb207_36;
  TNode<Int32T> phi_bb207_38;
  TNode<Union<Hole, JSMessageObject>> tmp364;
  if (block207.is_used()) {
    ca_.Bind(&block207, &phi_bb207_16, &phi_bb207_17, &phi_bb207_18, &phi_bb207_26, &phi_bb207_27, &phi_bb207_28, &phi_bb207_29, &phi_bb207_30, &phi_bb207_33, &phi_bb207_34, &phi_bb207_35, &phi_bb207_36, &phi_bb207_38);
    tmp364 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb207_16, phi_bb207_17, phi_bb207_18, tmp362, tmp364);
  }

  TNode<JSAny> phi_bb204_16;
  TNode<IntPtrT> phi_bb204_17;
  TNode<BoolT> phi_bb204_18;
  TNode<IntPtrT> phi_bb204_26;
  TNode<IntPtrT> phi_bb204_27;
  TNode<IntPtrT> phi_bb204_28;
  TNode<IntPtrT> phi_bb204_29;
  TNode<IntPtrT> phi_bb204_30;
  TNode<IntPtrT> phi_bb204_33;
  TNode<BoolT> phi_bb204_34;
  TNode<BoolT> phi_bb204_35;
  TNode<Union<FixedArray, Smi>> phi_bb204_36;
  TNode<Int32T> phi_bb204_38;
  TNode<IntPtrT> tmp365;
  TNode<IntPtrT> tmp366;
  TNode<IntPtrT> tmp367;
  TNode<BoolT> tmp368;
  if (block204.is_used()) {
    ca_.Bind(&block204, &phi_bb204_16, &phi_bb204_17, &phi_bb204_18, &phi_bb204_26, &phi_bb204_27, &phi_bb204_28, &phi_bb204_29, &phi_bb204_30, &phi_bb204_33, &phi_bb204_34, &phi_bb204_35, &phi_bb204_36, &phi_bb204_38);
    tmp365 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp366 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{phi_bb204_27}, TNode<IntPtrT>{tmp365});
    tmp367 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp368 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{phi_bb204_27}, TNode<IntPtrT>{tmp367});
    ca_.Branch(tmp368, &block210, std::vector<compiler::Node*>{phi_bb204_16, phi_bb204_17, phi_bb204_18, phi_bb204_26, phi_bb204_28, phi_bb204_29, phi_bb204_30, phi_bb204_33, phi_bb204_34, phi_bb204_35, phi_bb204_36, phi_bb204_38}, &block211, std::vector<compiler::Node*>{phi_bb204_16, phi_bb204_17, phi_bb204_18, phi_bb204_26, phi_bb204_28, phi_bb204_29, phi_bb204_30, phi_bb204_33, phi_bb204_34, phi_bb204_35, phi_bb204_36, phi_bb204_38});
  }

  TNode<JSAny> phi_bb210_16;
  TNode<IntPtrT> phi_bb210_17;
  TNode<BoolT> phi_bb210_18;
  TNode<IntPtrT> phi_bb210_26;
  TNode<IntPtrT> phi_bb210_28;
  TNode<IntPtrT> phi_bb210_29;
  TNode<IntPtrT> phi_bb210_30;
  TNode<IntPtrT> phi_bb210_33;
  TNode<BoolT> phi_bb210_34;
  TNode<BoolT> phi_bb210_35;
  TNode<Union<FixedArray, Smi>> phi_bb210_36;
  TNode<Int32T> phi_bb210_38;
  TNode<Union<HeapObject, TaggedIndex>> tmp369;
  TNode<IntPtrT> tmp370;
  TNode<IntPtrT> tmp371;
  TNode<IntPtrT> tmp372;
  if (block210.is_used()) {
    ca_.Bind(&block210, &phi_bb210_16, &phi_bb210_17, &phi_bb210_18, &phi_bb210_26, &phi_bb210_28, &phi_bb210_29, &phi_bb210_30, &phi_bb210_33, &phi_bb210_34, &phi_bb210_35, &phi_bb210_36, &phi_bb210_38);
    std::tie(tmp369, tmp370) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp197}, TNode<IntPtrT>{phi_bb210_29}).Flatten();
    tmp371 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_float64_0(state_)));
    tmp372 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb210_29}, TNode<IntPtrT>{tmp371});
    ca_.Goto(&block209, phi_bb210_16, phi_bb210_17, phi_bb210_18, phi_bb210_26, phi_bb210_28, tmp372, phi_bb210_30, phi_bb210_33, phi_bb210_34, phi_bb210_35, phi_bb210_36, phi_bb210_38, tmp369, tmp370);
  }

  TNode<JSAny> phi_bb211_16;
  TNode<IntPtrT> phi_bb211_17;
  TNode<BoolT> phi_bb211_18;
  TNode<IntPtrT> phi_bb211_26;
  TNode<IntPtrT> phi_bb211_28;
  TNode<IntPtrT> phi_bb211_29;
  TNode<IntPtrT> phi_bb211_30;
  TNode<IntPtrT> phi_bb211_33;
  TNode<BoolT> phi_bb211_34;
  TNode<BoolT> phi_bb211_35;
  TNode<Union<FixedArray, Smi>> phi_bb211_36;
  TNode<Int32T> phi_bb211_38;
  if (block211.is_used()) {
    ca_.Bind(&block211, &phi_bb211_16, &phi_bb211_17, &phi_bb211_18, &phi_bb211_26, &phi_bb211_28, &phi_bb211_29, &phi_bb211_30, &phi_bb211_33, &phi_bb211_34, &phi_bb211_35, &phi_bb211_36, &phi_bb211_38);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block212, phi_bb211_16, phi_bb211_17, phi_bb211_18, phi_bb211_26, phi_bb211_28, phi_bb211_29, phi_bb211_30, phi_bb211_33, phi_bb211_34, phi_bb211_35, phi_bb211_36, phi_bb211_38);
    } else {
      ca_.Goto(&block213, phi_bb211_16, phi_bb211_17, phi_bb211_18, phi_bb211_26, phi_bb211_28, phi_bb211_29, phi_bb211_30, phi_bb211_33, phi_bb211_34, phi_bb211_35, phi_bb211_36, phi_bb211_38);
    }
  }

  TNode<JSAny> phi_bb212_16;
  TNode<IntPtrT> phi_bb212_17;
  TNode<BoolT> phi_bb212_18;
  TNode<IntPtrT> phi_bb212_26;
  TNode<IntPtrT> phi_bb212_28;
  TNode<IntPtrT> phi_bb212_29;
  TNode<IntPtrT> phi_bb212_30;
  TNode<IntPtrT> phi_bb212_33;
  TNode<BoolT> phi_bb212_34;
  TNode<BoolT> phi_bb212_35;
  TNode<Union<FixedArray, Smi>> phi_bb212_36;
  TNode<Int32T> phi_bb212_38;
  if (block212.is_used()) {
    ca_.Bind(&block212, &phi_bb212_16, &phi_bb212_17, &phi_bb212_18, &phi_bb212_26, &phi_bb212_28, &phi_bb212_29, &phi_bb212_30, &phi_bb212_33, &phi_bb212_34, &phi_bb212_35, &phi_bb212_36, &phi_bb212_38);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block216, phi_bb212_16, phi_bb212_17, phi_bb212_18, phi_bb212_26, phi_bb212_28, phi_bb212_29, phi_bb212_30, phi_bb212_33, phi_bb212_34, phi_bb212_35, phi_bb212_36, phi_bb212_38);
    } else {
      ca_.Goto(&block217, phi_bb212_16, phi_bb212_17, phi_bb212_18, phi_bb212_26, phi_bb212_28, phi_bb212_29, phi_bb212_30, phi_bb212_33, phi_bb212_34, phi_bb212_35, phi_bb212_36, phi_bb212_38);
    }
  }

  TNode<JSAny> phi_bb216_16;
  TNode<IntPtrT> phi_bb216_17;
  TNode<BoolT> phi_bb216_18;
  TNode<IntPtrT> phi_bb216_26;
  TNode<IntPtrT> phi_bb216_28;
  TNode<IntPtrT> phi_bb216_29;
  TNode<IntPtrT> phi_bb216_30;
  TNode<IntPtrT> phi_bb216_33;
  TNode<BoolT> phi_bb216_34;
  TNode<BoolT> phi_bb216_35;
  TNode<Union<FixedArray, Smi>> phi_bb216_36;
  TNode<Int32T> phi_bb216_38;
  TNode<Union<HeapObject, TaggedIndex>> tmp373;
  TNode<IntPtrT> tmp374;
  TNode<IntPtrT> tmp375;
  TNode<IntPtrT> tmp376;
  if (block216.is_used()) {
    ca_.Bind(&block216, &phi_bb216_16, &phi_bb216_17, &phi_bb216_18, &phi_bb216_26, &phi_bb216_28, &phi_bb216_29, &phi_bb216_30, &phi_bb216_33, &phi_bb216_34, &phi_bb216_35, &phi_bb216_36, &phi_bb216_38);
    std::tie(tmp373, tmp374) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp197}, TNode<IntPtrT>{phi_bb216_30}).Flatten();
    tmp375 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp376 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb216_30}, TNode<IntPtrT>{tmp375});
    ca_.Goto(&block215, phi_bb216_16, phi_bb216_17, phi_bb216_18, phi_bb216_26, phi_bb216_28, phi_bb216_29, tmp376, phi_bb216_33, phi_bb216_34, phi_bb216_35, phi_bb216_36, phi_bb216_38, tmp373, tmp374);
  }

  TNode<JSAny> phi_bb217_16;
  TNode<IntPtrT> phi_bb217_17;
  TNode<BoolT> phi_bb217_18;
  TNode<IntPtrT> phi_bb217_26;
  TNode<IntPtrT> phi_bb217_28;
  TNode<IntPtrT> phi_bb217_29;
  TNode<IntPtrT> phi_bb217_30;
  TNode<IntPtrT> phi_bb217_33;
  TNode<BoolT> phi_bb217_34;
  TNode<BoolT> phi_bb217_35;
  TNode<Union<FixedArray, Smi>> phi_bb217_36;
  TNode<Int32T> phi_bb217_38;
  TNode<IntPtrT> tmp377;
  TNode<BoolT> tmp378;
  if (block217.is_used()) {
    ca_.Bind(&block217, &phi_bb217_16, &phi_bb217_17, &phi_bb217_18, &phi_bb217_26, &phi_bb217_28, &phi_bb217_29, &phi_bb217_30, &phi_bb217_33, &phi_bb217_34, &phi_bb217_35, &phi_bb217_36, &phi_bb217_38);
    tmp377 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp378 = CodeStubAssembler(state_).WordNotEqual(TNode<IntPtrT>{phi_bb217_33}, TNode<IntPtrT>{tmp377});
    ca_.Branch(tmp378, &block219, std::vector<compiler::Node*>{phi_bb217_16, phi_bb217_17, phi_bb217_18, phi_bb217_26, phi_bb217_28, phi_bb217_29, phi_bb217_30, phi_bb217_33, phi_bb217_34, phi_bb217_35, phi_bb217_36, phi_bb217_38}, &block220, std::vector<compiler::Node*>{phi_bb217_16, phi_bb217_17, phi_bb217_18, phi_bb217_26, phi_bb217_28, phi_bb217_29, phi_bb217_30, phi_bb217_33, phi_bb217_34, phi_bb217_35, phi_bb217_36, phi_bb217_38});
  }

  TNode<JSAny> phi_bb219_16;
  TNode<IntPtrT> phi_bb219_17;
  TNode<BoolT> phi_bb219_18;
  TNode<IntPtrT> phi_bb219_26;
  TNode<IntPtrT> phi_bb219_28;
  TNode<IntPtrT> phi_bb219_29;
  TNode<IntPtrT> phi_bb219_30;
  TNode<IntPtrT> phi_bb219_33;
  TNode<BoolT> phi_bb219_34;
  TNode<BoolT> phi_bb219_35;
  TNode<Union<FixedArray, Smi>> phi_bb219_36;
  TNode<Int32T> phi_bb219_38;
  TNode<Union<HeapObject, TaggedIndex>> tmp379;
  TNode<IntPtrT> tmp380;
  TNode<IntPtrT> tmp381;
  TNode<BoolT> tmp382;
  if (block219.is_used()) {
    ca_.Bind(&block219, &phi_bb219_16, &phi_bb219_17, &phi_bb219_18, &phi_bb219_26, &phi_bb219_28, &phi_bb219_29, &phi_bb219_30, &phi_bb219_33, &phi_bb219_34, &phi_bb219_35, &phi_bb219_36, &phi_bb219_38);
    std::tie(tmp379, tmp380) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp197}, TNode<IntPtrT>{phi_bb219_33}).Flatten();
    tmp381 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp382 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block215, phi_bb219_16, phi_bb219_17, phi_bb219_18, phi_bb219_26, phi_bb219_28, phi_bb219_29, phi_bb219_30, tmp381, tmp382, phi_bb219_35, phi_bb219_36, phi_bb219_38, tmp379, tmp380);
  }

  TNode<JSAny> phi_bb220_16;
  TNode<IntPtrT> phi_bb220_17;
  TNode<BoolT> phi_bb220_18;
  TNode<IntPtrT> phi_bb220_26;
  TNode<IntPtrT> phi_bb220_28;
  TNode<IntPtrT> phi_bb220_29;
  TNode<IntPtrT> phi_bb220_30;
  TNode<IntPtrT> phi_bb220_33;
  TNode<BoolT> phi_bb220_34;
  TNode<BoolT> phi_bb220_35;
  TNode<Union<FixedArray, Smi>> phi_bb220_36;
  TNode<Int32T> phi_bb220_38;
  TNode<Union<HeapObject, TaggedIndex>> tmp383;
  TNode<IntPtrT> tmp384;
  TNode<IntPtrT> tmp385;
  TNode<IntPtrT> tmp386;
  TNode<IntPtrT> tmp387;
  TNode<IntPtrT> tmp388;
  TNode<BoolT> tmp389;
  if (block220.is_used()) {
    ca_.Bind(&block220, &phi_bb220_16, &phi_bb220_17, &phi_bb220_18, &phi_bb220_26, &phi_bb220_28, &phi_bb220_29, &phi_bb220_30, &phi_bb220_33, &phi_bb220_34, &phi_bb220_35, &phi_bb220_36, &phi_bb220_38);
    std::tie(tmp383, tmp384) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp197}, TNode<IntPtrT>{phi_bb220_30}).Flatten();
    tmp385 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp386 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb220_30}, TNode<IntPtrT>{tmp385});
    tmp387 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp388 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp386}, TNode<IntPtrT>{tmp387});
    tmp389 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block215, phi_bb220_16, phi_bb220_17, phi_bb220_18, phi_bb220_26, phi_bb220_28, phi_bb220_29, tmp388, tmp386, tmp389, phi_bb220_35, phi_bb220_36, phi_bb220_38, tmp383, tmp384);
  }

  TNode<JSAny> phi_bb215_16;
  TNode<IntPtrT> phi_bb215_17;
  TNode<BoolT> phi_bb215_18;
  TNode<IntPtrT> phi_bb215_26;
  TNode<IntPtrT> phi_bb215_28;
  TNode<IntPtrT> phi_bb215_29;
  TNode<IntPtrT> phi_bb215_30;
  TNode<IntPtrT> phi_bb215_33;
  TNode<BoolT> phi_bb215_34;
  TNode<BoolT> phi_bb215_35;
  TNode<Union<FixedArray, Smi>> phi_bb215_36;
  TNode<Int32T> phi_bb215_38;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb215_41;
  TNode<IntPtrT> phi_bb215_42;
  if (block215.is_used()) {
    ca_.Bind(&block215, &phi_bb215_16, &phi_bb215_17, &phi_bb215_18, &phi_bb215_26, &phi_bb215_28, &phi_bb215_29, &phi_bb215_30, &phi_bb215_33, &phi_bb215_34, &phi_bb215_35, &phi_bb215_36, &phi_bb215_38, &phi_bb215_41, &phi_bb215_42);
    ca_.Goto(&block209, phi_bb215_16, phi_bb215_17, phi_bb215_18, phi_bb215_26, phi_bb215_28, phi_bb215_29, phi_bb215_30, phi_bb215_33, phi_bb215_34, phi_bb215_35, phi_bb215_36, phi_bb215_38, phi_bb215_41, phi_bb215_42);
  }

  TNode<JSAny> phi_bb213_16;
  TNode<IntPtrT> phi_bb213_17;
  TNode<BoolT> phi_bb213_18;
  TNode<IntPtrT> phi_bb213_26;
  TNode<IntPtrT> phi_bb213_28;
  TNode<IntPtrT> phi_bb213_29;
  TNode<IntPtrT> phi_bb213_30;
  TNode<IntPtrT> phi_bb213_33;
  TNode<BoolT> phi_bb213_34;
  TNode<BoolT> phi_bb213_35;
  TNode<Union<FixedArray, Smi>> phi_bb213_36;
  TNode<Int32T> phi_bb213_38;
  TNode<Union<HeapObject, TaggedIndex>> tmp390;
  TNode<IntPtrT> tmp391;
  TNode<IntPtrT> tmp392;
  TNode<IntPtrT> tmp393;
  TNode<BoolT> tmp394;
  if (block213.is_used()) {
    ca_.Bind(&block213, &phi_bb213_16, &phi_bb213_17, &phi_bb213_18, &phi_bb213_26, &phi_bb213_28, &phi_bb213_29, &phi_bb213_30, &phi_bb213_33, &phi_bb213_34, &phi_bb213_35, &phi_bb213_36, &phi_bb213_38);
    std::tie(tmp390, tmp391) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp197}, TNode<IntPtrT>{phi_bb213_30}).Flatten();
    tmp392 = FromConstexpr_intptr_constexpr_int31_0(state_, (CodeStubAssembler(state_).ConstexprInt31Mul((FromConstexpr_constexpr_int31_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull))), (SizeOf_intptr_0(state_)))));
    tmp393 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb213_30}, TNode<IntPtrT>{tmp392});
    tmp394 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block209, phi_bb213_16, phi_bb213_17, phi_bb213_18, phi_bb213_26, phi_bb213_28, phi_bb213_29, tmp393, phi_bb213_33, tmp394, phi_bb213_35, phi_bb213_36, phi_bb213_38, tmp390, tmp391);
  }

  TNode<JSAny> phi_bb209_16;
  TNode<IntPtrT> phi_bb209_17;
  TNode<BoolT> phi_bb209_18;
  TNode<IntPtrT> phi_bb209_26;
  TNode<IntPtrT> phi_bb209_28;
  TNode<IntPtrT> phi_bb209_29;
  TNode<IntPtrT> phi_bb209_30;
  TNode<IntPtrT> phi_bb209_33;
  TNode<BoolT> phi_bb209_34;
  TNode<BoolT> phi_bb209_35;
  TNode<Union<FixedArray, Smi>> phi_bb209_36;
  TNode<Int32T> phi_bb209_38;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb209_41;
  TNode<IntPtrT> phi_bb209_42;
  TNode<Union<HeapObject, TaggedIndex>> tmp395;
  TNode<IntPtrT> tmp396;
      TNode<JSAny> tmp398;
  TNode<Float64T> tmp399;
      TNode<JSAny> tmp401;
  TNode<Float64T> tmp402;
      TNode<JSAny> tmp404;
  if (block209.is_used()) {
    ca_.Bind(&block209, &phi_bb209_16, &phi_bb209_17, &phi_bb209_18, &phi_bb209_26, &phi_bb209_28, &phi_bb209_29, &phi_bb209_30, &phi_bb209_33, &phi_bb209_34, &phi_bb209_35, &phi_bb209_36, &phi_bb209_38, &phi_bb209_41, &phi_bb209_42);
    compiler::CodeAssemblerExceptionHandlerLabel catch397__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch397__label);
    std::tie(tmp395, tmp396) = RefCast_float64_0(state_, TorqueStructReference_intptr_0{TNode<Union<HeapObject, TaggedIndex>>{phi_bb209_41}, TNode<IntPtrT>{phi_bb209_42}, TorqueStructUnsafe_0{}}).Flatten();
    }
    if (catch397__label.is_used()) {
      compiler::CodeAssemblerLabel catch397_skip(&ca_);
      ca_.Goto(&catch397_skip);
      ca_.Bind(&catch397__label, &tmp398);
      ca_.Goto(&block221, phi_bb209_16, phi_bb209_17, phi_bb209_18, phi_bb209_26, phi_bb209_28, phi_bb209_29, phi_bb209_30, phi_bb209_33, phi_bb209_34, phi_bb209_35, phi_bb209_36, phi_bb209_38, phi_bb209_41, phi_bb209_42, phi_bb209_41, phi_bb209_42);
      ca_.Bind(&catch397_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch400__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch400__label);
    tmp399 = CodeStubAssembler(state_).ChangeTaggedToFloat64(TNode<Context>{p_context}, TNode<JSAny>{tmp233});
    }
    if (catch400__label.is_used()) {
      compiler::CodeAssemblerLabel catch400_skip(&ca_);
      ca_.Goto(&catch400_skip);
      ca_.Bind(&catch400__label, &tmp401);
      ca_.Goto(&block222, phi_bb209_16, phi_bb209_17, phi_bb209_18, phi_bb209_26, phi_bb209_28, phi_bb209_29, phi_bb209_30, phi_bb209_33, phi_bb209_34, phi_bb209_35, phi_bb209_36, phi_bb209_38, phi_bb209_41, phi_bb209_42);
      ca_.Bind(&catch400_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch403__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch403__label);
    tmp402 = CodeStubAssembler(state_).Float64SilenceNaN(TNode<Float64T>{tmp399});
    }
    if (catch403__label.is_used()) {
      compiler::CodeAssemblerLabel catch403_skip(&ca_);
      ca_.Goto(&catch403_skip);
      ca_.Bind(&catch403__label, &tmp404);
      ca_.Goto(&block223, phi_bb209_16, phi_bb209_17, phi_bb209_18, phi_bb209_26, phi_bb209_28, phi_bb209_29, phi_bb209_30, phi_bb209_33, phi_bb209_34, phi_bb209_35, phi_bb209_36, phi_bb209_38, phi_bb209_41, phi_bb209_42);
      ca_.Bind(&catch403_skip);
    }
    CodeStubAssembler(state_).StoreReference<Float64T>(CodeStubAssembler::Reference{tmp395, tmp396}, tmp402);
    ca_.Goto(&block208, phi_bb209_16, phi_bb209_17, phi_bb209_18, phi_bb209_26, tmp366, phi_bb209_28, phi_bb209_29, phi_bb209_30, phi_bb209_33, phi_bb209_34, phi_bb209_35, phi_bb209_36, phi_bb209_38);
  }

  TNode<JSAny> phi_bb221_16;
  TNode<IntPtrT> phi_bb221_17;
  TNode<BoolT> phi_bb221_18;
  TNode<IntPtrT> phi_bb221_26;
  TNode<IntPtrT> phi_bb221_28;
  TNode<IntPtrT> phi_bb221_29;
  TNode<IntPtrT> phi_bb221_30;
  TNode<IntPtrT> phi_bb221_33;
  TNode<BoolT> phi_bb221_34;
  TNode<BoolT> phi_bb221_35;
  TNode<Union<FixedArray, Smi>> phi_bb221_36;
  TNode<Int32T> phi_bb221_38;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb221_41;
  TNode<IntPtrT> phi_bb221_42;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb221_43;
  TNode<IntPtrT> phi_bb221_44;
  TNode<Union<Hole, JSMessageObject>> tmp405;
  if (block221.is_used()) {
    ca_.Bind(&block221, &phi_bb221_16, &phi_bb221_17, &phi_bb221_18, &phi_bb221_26, &phi_bb221_28, &phi_bb221_29, &phi_bb221_30, &phi_bb221_33, &phi_bb221_34, &phi_bb221_35, &phi_bb221_36, &phi_bb221_38, &phi_bb221_41, &phi_bb221_42, &phi_bb221_43, &phi_bb221_44);
    tmp405 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb221_16, phi_bb221_17, phi_bb221_18, tmp398, tmp405);
  }

  TNode<JSAny> phi_bb222_16;
  TNode<IntPtrT> phi_bb222_17;
  TNode<BoolT> phi_bb222_18;
  TNode<IntPtrT> phi_bb222_26;
  TNode<IntPtrT> phi_bb222_28;
  TNode<IntPtrT> phi_bb222_29;
  TNode<IntPtrT> phi_bb222_30;
  TNode<IntPtrT> phi_bb222_33;
  TNode<BoolT> phi_bb222_34;
  TNode<BoolT> phi_bb222_35;
  TNode<Union<FixedArray, Smi>> phi_bb222_36;
  TNode<Int32T> phi_bb222_38;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb222_41;
  TNode<IntPtrT> phi_bb222_42;
  TNode<Union<Hole, JSMessageObject>> tmp406;
  if (block222.is_used()) {
    ca_.Bind(&block222, &phi_bb222_16, &phi_bb222_17, &phi_bb222_18, &phi_bb222_26, &phi_bb222_28, &phi_bb222_29, &phi_bb222_30, &phi_bb222_33, &phi_bb222_34, &phi_bb222_35, &phi_bb222_36, &phi_bb222_38, &phi_bb222_41, &phi_bb222_42);
    tmp406 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb222_16, phi_bb222_17, phi_bb222_18, tmp401, tmp406);
  }

  TNode<JSAny> phi_bb223_16;
  TNode<IntPtrT> phi_bb223_17;
  TNode<BoolT> phi_bb223_18;
  TNode<IntPtrT> phi_bb223_26;
  TNode<IntPtrT> phi_bb223_28;
  TNode<IntPtrT> phi_bb223_29;
  TNode<IntPtrT> phi_bb223_30;
  TNode<IntPtrT> phi_bb223_33;
  TNode<BoolT> phi_bb223_34;
  TNode<BoolT> phi_bb223_35;
  TNode<Union<FixedArray, Smi>> phi_bb223_36;
  TNode<Int32T> phi_bb223_38;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb223_41;
  TNode<IntPtrT> phi_bb223_42;
  TNode<Union<Hole, JSMessageObject>> tmp407;
  if (block223.is_used()) {
    ca_.Bind(&block223, &phi_bb223_16, &phi_bb223_17, &phi_bb223_18, &phi_bb223_26, &phi_bb223_28, &phi_bb223_29, &phi_bb223_30, &phi_bb223_33, &phi_bb223_34, &phi_bb223_35, &phi_bb223_36, &phi_bb223_38, &phi_bb223_41, &phi_bb223_42);
    tmp407 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb223_16, phi_bb223_17, phi_bb223_18, tmp404, tmp407);
  }

  TNode<JSAny> phi_bb205_16;
  TNode<IntPtrT> phi_bb205_17;
  TNode<BoolT> phi_bb205_18;
  TNode<IntPtrT> phi_bb205_26;
  TNode<IntPtrT> phi_bb205_27;
  TNode<IntPtrT> phi_bb205_28;
  TNode<IntPtrT> phi_bb205_29;
  TNode<IntPtrT> phi_bb205_30;
  TNode<IntPtrT> phi_bb205_33;
  TNode<BoolT> phi_bb205_34;
  TNode<BoolT> phi_bb205_35;
  TNode<Union<FixedArray, Smi>> phi_bb205_36;
  TNode<Int32T> phi_bb205_38;
  TNode<Int32T> tmp408;
      TNode<JSAny> tmp410;
  TNode<BoolT> tmp411;
      TNode<JSAny> tmp413;
  if (block205.is_used()) {
    ca_.Bind(&block205, &phi_bb205_16, &phi_bb205_17, &phi_bb205_18, &phi_bb205_26, &phi_bb205_27, &phi_bb205_28, &phi_bb205_29, &phi_bb205_30, &phi_bb205_33, &phi_bb205_34, &phi_bb205_35, &phi_bb205_36, &phi_bb205_38);
    compiler::CodeAssemblerExceptionHandlerLabel catch409__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch409__label);
    tmp408 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmI64.raw_bit_field());
    }
    if (catch409__label.is_used()) {
      compiler::CodeAssemblerLabel catch409_skip(&ca_);
      ca_.Goto(&catch409_skip);
      ca_.Bind(&catch409__label, &tmp410);
      ca_.Goto(&block226, phi_bb205_16, phi_bb205_17, phi_bb205_18, phi_bb205_26, phi_bb205_27, phi_bb205_28, phi_bb205_29, phi_bb205_30, phi_bb205_33, phi_bb205_34, phi_bb205_35, phi_bb205_36, phi_bb205_38);
      ca_.Bind(&catch409_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch412__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch412__label);
    tmp411 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp249}, TNode<Int32T>{tmp408});
    }
    if (catch412__label.is_used()) {
      compiler::CodeAssemblerLabel catch412_skip(&ca_);
      ca_.Goto(&catch412_skip);
      ca_.Bind(&catch412__label, &tmp413);
      ca_.Goto(&block227, phi_bb205_16, phi_bb205_17, phi_bb205_18, phi_bb205_26, phi_bb205_27, phi_bb205_28, phi_bb205_29, phi_bb205_30, phi_bb205_33, phi_bb205_34, phi_bb205_35, phi_bb205_36, phi_bb205_38);
      ca_.Bind(&catch412_skip);
    }
    ca_.Branch(tmp411, &block224, std::vector<compiler::Node*>{phi_bb205_16, phi_bb205_17, phi_bb205_18, phi_bb205_26, phi_bb205_27, phi_bb205_28, phi_bb205_29, phi_bb205_30, phi_bb205_33, phi_bb205_34, phi_bb205_35, phi_bb205_36, phi_bb205_38}, &block225, std::vector<compiler::Node*>{phi_bb205_16, phi_bb205_17, phi_bb205_18, phi_bb205_26, phi_bb205_27, phi_bb205_28, phi_bb205_29, phi_bb205_30, phi_bb205_33, phi_bb205_34, phi_bb205_35, phi_bb205_36, phi_bb205_38});
  }

  TNode<JSAny> phi_bb226_16;
  TNode<IntPtrT> phi_bb226_17;
  TNode<BoolT> phi_bb226_18;
  TNode<IntPtrT> phi_bb226_26;
  TNode<IntPtrT> phi_bb226_27;
  TNode<IntPtrT> phi_bb226_28;
  TNode<IntPtrT> phi_bb226_29;
  TNode<IntPtrT> phi_bb226_30;
  TNode<IntPtrT> phi_bb226_33;
  TNode<BoolT> phi_bb226_34;
  TNode<BoolT> phi_bb226_35;
  TNode<Union<FixedArray, Smi>> phi_bb226_36;
  TNode<Int32T> phi_bb226_38;
  TNode<Union<Hole, JSMessageObject>> tmp414;
  if (block226.is_used()) {
    ca_.Bind(&block226, &phi_bb226_16, &phi_bb226_17, &phi_bb226_18, &phi_bb226_26, &phi_bb226_27, &phi_bb226_28, &phi_bb226_29, &phi_bb226_30, &phi_bb226_33, &phi_bb226_34, &phi_bb226_35, &phi_bb226_36, &phi_bb226_38);
    tmp414 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb226_16, phi_bb226_17, phi_bb226_18, tmp410, tmp414);
  }

  TNode<JSAny> phi_bb227_16;
  TNode<IntPtrT> phi_bb227_17;
  TNode<BoolT> phi_bb227_18;
  TNode<IntPtrT> phi_bb227_26;
  TNode<IntPtrT> phi_bb227_27;
  TNode<IntPtrT> phi_bb227_28;
  TNode<IntPtrT> phi_bb227_29;
  TNode<IntPtrT> phi_bb227_30;
  TNode<IntPtrT> phi_bb227_33;
  TNode<BoolT> phi_bb227_34;
  TNode<BoolT> phi_bb227_35;
  TNode<Union<FixedArray, Smi>> phi_bb227_36;
  TNode<Int32T> phi_bb227_38;
  TNode<Union<Hole, JSMessageObject>> tmp415;
  if (block227.is_used()) {
    ca_.Bind(&block227, &phi_bb227_16, &phi_bb227_17, &phi_bb227_18, &phi_bb227_26, &phi_bb227_27, &phi_bb227_28, &phi_bb227_29, &phi_bb227_30, &phi_bb227_33, &phi_bb227_34, &phi_bb227_35, &phi_bb227_36, &phi_bb227_38);
    tmp415 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb227_16, phi_bb227_17, phi_bb227_18, tmp413, tmp415);
  }

  TNode<JSAny> phi_bb224_16;
  TNode<IntPtrT> phi_bb224_17;
  TNode<BoolT> phi_bb224_18;
  TNode<IntPtrT> phi_bb224_26;
  TNode<IntPtrT> phi_bb224_27;
  TNode<IntPtrT> phi_bb224_28;
  TNode<IntPtrT> phi_bb224_29;
  TNode<IntPtrT> phi_bb224_30;
  TNode<IntPtrT> phi_bb224_33;
  TNode<BoolT> phi_bb224_34;
  TNode<BoolT> phi_bb224_35;
  TNode<Union<FixedArray, Smi>> phi_bb224_36;
  TNode<Int32T> phi_bb224_38;
  if (block224.is_used()) {
    ca_.Bind(&block224, &phi_bb224_16, &phi_bb224_17, &phi_bb224_18, &phi_bb224_26, &phi_bb224_27, &phi_bb224_28, &phi_bb224_29, &phi_bb224_30, &phi_bb224_33, &phi_bb224_34, &phi_bb224_35, &phi_bb224_36, &phi_bb224_38);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block229, phi_bb224_16, phi_bb224_17, phi_bb224_18, phi_bb224_26, phi_bb224_27, phi_bb224_28, phi_bb224_29, phi_bb224_30, phi_bb224_33, phi_bb224_34, phi_bb224_35, phi_bb224_36, phi_bb224_38);
    } else {
      ca_.Goto(&block230, phi_bb224_16, phi_bb224_17, phi_bb224_18, phi_bb224_26, phi_bb224_27, phi_bb224_28, phi_bb224_29, phi_bb224_30, phi_bb224_33, phi_bb224_34, phi_bb224_35, phi_bb224_36, phi_bb224_38);
    }
  }

  TNode<JSAny> phi_bb229_16;
  TNode<IntPtrT> phi_bb229_17;
  TNode<BoolT> phi_bb229_18;
  TNode<IntPtrT> phi_bb229_26;
  TNode<IntPtrT> phi_bb229_27;
  TNode<IntPtrT> phi_bb229_28;
  TNode<IntPtrT> phi_bb229_29;
  TNode<IntPtrT> phi_bb229_30;
  TNode<IntPtrT> phi_bb229_33;
  TNode<BoolT> phi_bb229_34;
  TNode<BoolT> phi_bb229_35;
  TNode<Union<FixedArray, Smi>> phi_bb229_36;
  TNode<Int32T> phi_bb229_38;
  TNode<IntPtrT> tmp416;
  TNode<IntPtrT> tmp417;
  TNode<IntPtrT> tmp418;
  TNode<BoolT> tmp419;
  if (block229.is_used()) {
    ca_.Bind(&block229, &phi_bb229_16, &phi_bb229_17, &phi_bb229_18, &phi_bb229_26, &phi_bb229_27, &phi_bb229_28, &phi_bb229_29, &phi_bb229_30, &phi_bb229_33, &phi_bb229_34, &phi_bb229_35, &phi_bb229_36, &phi_bb229_38);
    tmp416 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp417 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{phi_bb229_26}, TNode<IntPtrT>{tmp416});
    tmp418 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp419 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{phi_bb229_26}, TNode<IntPtrT>{tmp418});
    ca_.Branch(tmp419, &block233, std::vector<compiler::Node*>{phi_bb229_16, phi_bb229_17, phi_bb229_18, phi_bb229_27, phi_bb229_28, phi_bb229_29, phi_bb229_30, phi_bb229_33, phi_bb229_34, phi_bb229_35, phi_bb229_36, phi_bb229_38}, &block234, std::vector<compiler::Node*>{phi_bb229_16, phi_bb229_17, phi_bb229_18, phi_bb229_27, phi_bb229_28, phi_bb229_29, phi_bb229_30, phi_bb229_33, phi_bb229_34, phi_bb229_35, phi_bb229_36, phi_bb229_38});
  }

  TNode<JSAny> phi_bb233_16;
  TNode<IntPtrT> phi_bb233_17;
  TNode<BoolT> phi_bb233_18;
  TNode<IntPtrT> phi_bb233_27;
  TNode<IntPtrT> phi_bb233_28;
  TNode<IntPtrT> phi_bb233_29;
  TNode<IntPtrT> phi_bb233_30;
  TNode<IntPtrT> phi_bb233_33;
  TNode<BoolT> phi_bb233_34;
  TNode<BoolT> phi_bb233_35;
  TNode<Union<FixedArray, Smi>> phi_bb233_36;
  TNode<Int32T> phi_bb233_38;
  TNode<Union<HeapObject, TaggedIndex>> tmp420;
  TNode<IntPtrT> tmp421;
  TNode<IntPtrT> tmp422;
  TNode<IntPtrT> tmp423;
  if (block233.is_used()) {
    ca_.Bind(&block233, &phi_bb233_16, &phi_bb233_17, &phi_bb233_18, &phi_bb233_27, &phi_bb233_28, &phi_bb233_29, &phi_bb233_30, &phi_bb233_33, &phi_bb233_34, &phi_bb233_35, &phi_bb233_36, &phi_bb233_38);
    std::tie(tmp420, tmp421) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp197}, TNode<IntPtrT>{phi_bb233_28}).Flatten();
    tmp422 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp423 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb233_28}, TNode<IntPtrT>{tmp422});
    ca_.Goto(&block232, phi_bb233_16, phi_bb233_17, phi_bb233_18, phi_bb233_27, tmp423, phi_bb233_29, phi_bb233_30, phi_bb233_33, phi_bb233_34, phi_bb233_35, phi_bb233_36, phi_bb233_38, tmp420, tmp421);
  }

  TNode<JSAny> phi_bb234_16;
  TNode<IntPtrT> phi_bb234_17;
  TNode<BoolT> phi_bb234_18;
  TNode<IntPtrT> phi_bb234_27;
  TNode<IntPtrT> phi_bb234_28;
  TNode<IntPtrT> phi_bb234_29;
  TNode<IntPtrT> phi_bb234_30;
  TNode<IntPtrT> phi_bb234_33;
  TNode<BoolT> phi_bb234_34;
  TNode<BoolT> phi_bb234_35;
  TNode<Union<FixedArray, Smi>> phi_bb234_36;
  TNode<Int32T> phi_bb234_38;
  if (block234.is_used()) {
    ca_.Bind(&block234, &phi_bb234_16, &phi_bb234_17, &phi_bb234_18, &phi_bb234_27, &phi_bb234_28, &phi_bb234_29, &phi_bb234_30, &phi_bb234_33, &phi_bb234_34, &phi_bb234_35, &phi_bb234_36, &phi_bb234_38);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block236, phi_bb234_16, phi_bb234_17, phi_bb234_18, phi_bb234_27, phi_bb234_28, phi_bb234_29, phi_bb234_30, phi_bb234_33, phi_bb234_34, phi_bb234_35, phi_bb234_36, phi_bb234_38);
    } else {
      ca_.Goto(&block237, phi_bb234_16, phi_bb234_17, phi_bb234_18, phi_bb234_27, phi_bb234_28, phi_bb234_29, phi_bb234_30, phi_bb234_33, phi_bb234_34, phi_bb234_35, phi_bb234_36, phi_bb234_38);
    }
  }

  TNode<JSAny> phi_bb236_16;
  TNode<IntPtrT> phi_bb236_17;
  TNode<BoolT> phi_bb236_18;
  TNode<IntPtrT> phi_bb236_27;
  TNode<IntPtrT> phi_bb236_28;
  TNode<IntPtrT> phi_bb236_29;
  TNode<IntPtrT> phi_bb236_30;
  TNode<IntPtrT> phi_bb236_33;
  TNode<BoolT> phi_bb236_34;
  TNode<BoolT> phi_bb236_35;
  TNode<Union<FixedArray, Smi>> phi_bb236_36;
  TNode<Int32T> phi_bb236_38;
  TNode<Union<HeapObject, TaggedIndex>> tmp424;
  TNode<IntPtrT> tmp425;
  TNode<IntPtrT> tmp426;
  TNode<IntPtrT> tmp427;
  if (block236.is_used()) {
    ca_.Bind(&block236, &phi_bb236_16, &phi_bb236_17, &phi_bb236_18, &phi_bb236_27, &phi_bb236_28, &phi_bb236_29, &phi_bb236_30, &phi_bb236_33, &phi_bb236_34, &phi_bb236_35, &phi_bb236_36, &phi_bb236_38);
    std::tie(tmp424, tmp425) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp197}, TNode<IntPtrT>{phi_bb236_30}).Flatten();
    tmp426 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp427 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb236_30}, TNode<IntPtrT>{tmp426});
    ca_.Goto(&block235, phi_bb236_16, phi_bb236_17, phi_bb236_18, phi_bb236_27, phi_bb236_28, phi_bb236_29, tmp427, phi_bb236_33, phi_bb236_34, phi_bb236_35, phi_bb236_36, phi_bb236_38, tmp424, tmp425);
  }

  TNode<JSAny> phi_bb237_16;
  TNode<IntPtrT> phi_bb237_17;
  TNode<BoolT> phi_bb237_18;
  TNode<IntPtrT> phi_bb237_27;
  TNode<IntPtrT> phi_bb237_28;
  TNode<IntPtrT> phi_bb237_29;
  TNode<IntPtrT> phi_bb237_30;
  TNode<IntPtrT> phi_bb237_33;
  TNode<BoolT> phi_bb237_34;
  TNode<BoolT> phi_bb237_35;
  TNode<Union<FixedArray, Smi>> phi_bb237_36;
  TNode<Int32T> phi_bb237_38;
  TNode<IntPtrT> tmp428;
  TNode<BoolT> tmp429;
  if (block237.is_used()) {
    ca_.Bind(&block237, &phi_bb237_16, &phi_bb237_17, &phi_bb237_18, &phi_bb237_27, &phi_bb237_28, &phi_bb237_29, &phi_bb237_30, &phi_bb237_33, &phi_bb237_34, &phi_bb237_35, &phi_bb237_36, &phi_bb237_38);
    tmp428 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp429 = CodeStubAssembler(state_).WordNotEqual(TNode<IntPtrT>{phi_bb237_33}, TNode<IntPtrT>{tmp428});
    ca_.Branch(tmp429, &block239, std::vector<compiler::Node*>{phi_bb237_16, phi_bb237_17, phi_bb237_18, phi_bb237_27, phi_bb237_28, phi_bb237_29, phi_bb237_30, phi_bb237_33, phi_bb237_34, phi_bb237_35, phi_bb237_36, phi_bb237_38}, &block240, std::vector<compiler::Node*>{phi_bb237_16, phi_bb237_17, phi_bb237_18, phi_bb237_27, phi_bb237_28, phi_bb237_29, phi_bb237_30, phi_bb237_33, phi_bb237_34, phi_bb237_35, phi_bb237_36, phi_bb237_38});
  }

  TNode<JSAny> phi_bb239_16;
  TNode<IntPtrT> phi_bb239_17;
  TNode<BoolT> phi_bb239_18;
  TNode<IntPtrT> phi_bb239_27;
  TNode<IntPtrT> phi_bb239_28;
  TNode<IntPtrT> phi_bb239_29;
  TNode<IntPtrT> phi_bb239_30;
  TNode<IntPtrT> phi_bb239_33;
  TNode<BoolT> phi_bb239_34;
  TNode<BoolT> phi_bb239_35;
  TNode<Union<FixedArray, Smi>> phi_bb239_36;
  TNode<Int32T> phi_bb239_38;
  TNode<Union<HeapObject, TaggedIndex>> tmp430;
  TNode<IntPtrT> tmp431;
  TNode<IntPtrT> tmp432;
  TNode<BoolT> tmp433;
  if (block239.is_used()) {
    ca_.Bind(&block239, &phi_bb239_16, &phi_bb239_17, &phi_bb239_18, &phi_bb239_27, &phi_bb239_28, &phi_bb239_29, &phi_bb239_30, &phi_bb239_33, &phi_bb239_34, &phi_bb239_35, &phi_bb239_36, &phi_bb239_38);
    std::tie(tmp430, tmp431) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp197}, TNode<IntPtrT>{phi_bb239_33}).Flatten();
    tmp432 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp433 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block235, phi_bb239_16, phi_bb239_17, phi_bb239_18, phi_bb239_27, phi_bb239_28, phi_bb239_29, phi_bb239_30, tmp432, tmp433, phi_bb239_35, phi_bb239_36, phi_bb239_38, tmp430, tmp431);
  }

  TNode<JSAny> phi_bb240_16;
  TNode<IntPtrT> phi_bb240_17;
  TNode<BoolT> phi_bb240_18;
  TNode<IntPtrT> phi_bb240_27;
  TNode<IntPtrT> phi_bb240_28;
  TNode<IntPtrT> phi_bb240_29;
  TNode<IntPtrT> phi_bb240_30;
  TNode<IntPtrT> phi_bb240_33;
  TNode<BoolT> phi_bb240_34;
  TNode<BoolT> phi_bb240_35;
  TNode<Union<FixedArray, Smi>> phi_bb240_36;
  TNode<Int32T> phi_bb240_38;
  TNode<Union<HeapObject, TaggedIndex>> tmp434;
  TNode<IntPtrT> tmp435;
  TNode<IntPtrT> tmp436;
  TNode<IntPtrT> tmp437;
  TNode<IntPtrT> tmp438;
  TNode<IntPtrT> tmp439;
  TNode<BoolT> tmp440;
  if (block240.is_used()) {
    ca_.Bind(&block240, &phi_bb240_16, &phi_bb240_17, &phi_bb240_18, &phi_bb240_27, &phi_bb240_28, &phi_bb240_29, &phi_bb240_30, &phi_bb240_33, &phi_bb240_34, &phi_bb240_35, &phi_bb240_36, &phi_bb240_38);
    std::tie(tmp434, tmp435) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp197}, TNode<IntPtrT>{phi_bb240_30}).Flatten();
    tmp436 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp437 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb240_30}, TNode<IntPtrT>{tmp436});
    tmp438 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp439 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp437}, TNode<IntPtrT>{tmp438});
    tmp440 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block235, phi_bb240_16, phi_bb240_17, phi_bb240_18, phi_bb240_27, phi_bb240_28, phi_bb240_29, tmp439, tmp437, tmp440, phi_bb240_35, phi_bb240_36, phi_bb240_38, tmp434, tmp435);
  }

  TNode<JSAny> phi_bb235_16;
  TNode<IntPtrT> phi_bb235_17;
  TNode<BoolT> phi_bb235_18;
  TNode<IntPtrT> phi_bb235_27;
  TNode<IntPtrT> phi_bb235_28;
  TNode<IntPtrT> phi_bb235_29;
  TNode<IntPtrT> phi_bb235_30;
  TNode<IntPtrT> phi_bb235_33;
  TNode<BoolT> phi_bb235_34;
  TNode<BoolT> phi_bb235_35;
  TNode<Union<FixedArray, Smi>> phi_bb235_36;
  TNode<Int32T> phi_bb235_38;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb235_41;
  TNode<IntPtrT> phi_bb235_42;
  if (block235.is_used()) {
    ca_.Bind(&block235, &phi_bb235_16, &phi_bb235_17, &phi_bb235_18, &phi_bb235_27, &phi_bb235_28, &phi_bb235_29, &phi_bb235_30, &phi_bb235_33, &phi_bb235_34, &phi_bb235_35, &phi_bb235_36, &phi_bb235_38, &phi_bb235_41, &phi_bb235_42);
    ca_.Goto(&block232, phi_bb235_16, phi_bb235_17, phi_bb235_18, phi_bb235_27, phi_bb235_28, phi_bb235_29, phi_bb235_30, phi_bb235_33, phi_bb235_34, phi_bb235_35, phi_bb235_36, phi_bb235_38, phi_bb235_41, phi_bb235_42);
  }

  TNode<JSAny> phi_bb232_16;
  TNode<IntPtrT> phi_bb232_17;
  TNode<BoolT> phi_bb232_18;
  TNode<IntPtrT> phi_bb232_27;
  TNode<IntPtrT> phi_bb232_28;
  TNode<IntPtrT> phi_bb232_29;
  TNode<IntPtrT> phi_bb232_30;
  TNode<IntPtrT> phi_bb232_33;
  TNode<BoolT> phi_bb232_34;
  TNode<BoolT> phi_bb232_35;
  TNode<Union<FixedArray, Smi>> phi_bb232_36;
  TNode<Int32T> phi_bb232_38;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb232_41;
  TNode<IntPtrT> phi_bb232_42;
  TNode<IntPtrT> tmp441;
      TNode<JSAny> tmp443;
  if (block232.is_used()) {
    ca_.Bind(&block232, &phi_bb232_16, &phi_bb232_17, &phi_bb232_18, &phi_bb232_27, &phi_bb232_28, &phi_bb232_29, &phi_bb232_30, &phi_bb232_33, &phi_bb232_34, &phi_bb232_35, &phi_bb232_36, &phi_bb232_38, &phi_bb232_41, &phi_bb232_42);
    compiler::CodeAssemblerExceptionHandlerLabel catch442__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch442__label);
    tmp441 = TruncateBigIntToI64_0(state_, TNode<Context>{p_context}, TNode<JSAny>{tmp233});
    }
    if (catch442__label.is_used()) {
      compiler::CodeAssemblerLabel catch442_skip(&ca_);
      ca_.Goto(&catch442_skip);
      ca_.Bind(&catch442__label, &tmp443);
      ca_.Goto(&block241, phi_bb232_16, phi_bb232_17, phi_bb232_18, phi_bb232_27, phi_bb232_28, phi_bb232_29, phi_bb232_30, phi_bb232_33, phi_bb232_34, phi_bb232_35, phi_bb232_36, phi_bb232_38, phi_bb232_41, phi_bb232_42);
      ca_.Bind(&catch442_skip);
    }
    CodeStubAssembler(state_).StoreReference<IntPtrT>(CodeStubAssembler::Reference{phi_bb232_41, phi_bb232_42}, tmp441);
    ca_.Goto(&block231, phi_bb232_16, phi_bb232_17, phi_bb232_18, tmp417, phi_bb232_27, phi_bb232_28, phi_bb232_29, phi_bb232_30, phi_bb232_33, phi_bb232_34, phi_bb232_35, phi_bb232_36, phi_bb232_38);
  }

  TNode<JSAny> phi_bb241_16;
  TNode<IntPtrT> phi_bb241_17;
  TNode<BoolT> phi_bb241_18;
  TNode<IntPtrT> phi_bb241_27;
  TNode<IntPtrT> phi_bb241_28;
  TNode<IntPtrT> phi_bb241_29;
  TNode<IntPtrT> phi_bb241_30;
  TNode<IntPtrT> phi_bb241_33;
  TNode<BoolT> phi_bb241_34;
  TNode<BoolT> phi_bb241_35;
  TNode<Union<FixedArray, Smi>> phi_bb241_36;
  TNode<Int32T> phi_bb241_38;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb241_41;
  TNode<IntPtrT> phi_bb241_42;
  TNode<Union<Hole, JSMessageObject>> tmp444;
  if (block241.is_used()) {
    ca_.Bind(&block241, &phi_bb241_16, &phi_bb241_17, &phi_bb241_18, &phi_bb241_27, &phi_bb241_28, &phi_bb241_29, &phi_bb241_30, &phi_bb241_33, &phi_bb241_34, &phi_bb241_35, &phi_bb241_36, &phi_bb241_38, &phi_bb241_41, &phi_bb241_42);
    tmp444 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb241_16, phi_bb241_17, phi_bb241_18, tmp443, tmp444);
  }

  TNode<JSAny> phi_bb230_16;
  TNode<IntPtrT> phi_bb230_17;
  TNode<BoolT> phi_bb230_18;
  TNode<IntPtrT> phi_bb230_26;
  TNode<IntPtrT> phi_bb230_27;
  TNode<IntPtrT> phi_bb230_28;
  TNode<IntPtrT> phi_bb230_29;
  TNode<IntPtrT> phi_bb230_30;
  TNode<IntPtrT> phi_bb230_33;
  TNode<BoolT> phi_bb230_34;
  TNode<BoolT> phi_bb230_35;
  TNode<Union<FixedArray, Smi>> phi_bb230_36;
  TNode<Int32T> phi_bb230_38;
  TNode<IntPtrT> tmp445;
  TNode<IntPtrT> tmp446;
  TNode<IntPtrT> tmp447;
  TNode<BoolT> tmp448;
  if (block230.is_used()) {
    ca_.Bind(&block230, &phi_bb230_16, &phi_bb230_17, &phi_bb230_18, &phi_bb230_26, &phi_bb230_27, &phi_bb230_28, &phi_bb230_29, &phi_bb230_30, &phi_bb230_33, &phi_bb230_34, &phi_bb230_35, &phi_bb230_36, &phi_bb230_38);
    tmp445 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp446 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{phi_bb230_26}, TNode<IntPtrT>{tmp445});
    tmp447 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp448 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{phi_bb230_26}, TNode<IntPtrT>{tmp447});
    ca_.Branch(tmp448, &block243, std::vector<compiler::Node*>{phi_bb230_16, phi_bb230_17, phi_bb230_18, phi_bb230_27, phi_bb230_28, phi_bb230_29, phi_bb230_30, phi_bb230_33, phi_bb230_34, phi_bb230_35, phi_bb230_36, phi_bb230_38}, &block244, std::vector<compiler::Node*>{phi_bb230_16, phi_bb230_17, phi_bb230_18, phi_bb230_27, phi_bb230_28, phi_bb230_29, phi_bb230_30, phi_bb230_33, phi_bb230_34, phi_bb230_35, phi_bb230_36, phi_bb230_38});
  }

  TNode<JSAny> phi_bb243_16;
  TNode<IntPtrT> phi_bb243_17;
  TNode<BoolT> phi_bb243_18;
  TNode<IntPtrT> phi_bb243_27;
  TNode<IntPtrT> phi_bb243_28;
  TNode<IntPtrT> phi_bb243_29;
  TNode<IntPtrT> phi_bb243_30;
  TNode<IntPtrT> phi_bb243_33;
  TNode<BoolT> phi_bb243_34;
  TNode<BoolT> phi_bb243_35;
  TNode<Union<FixedArray, Smi>> phi_bb243_36;
  TNode<Int32T> phi_bb243_38;
  TNode<Union<HeapObject, TaggedIndex>> tmp449;
  TNode<IntPtrT> tmp450;
  TNode<IntPtrT> tmp451;
  TNode<IntPtrT> tmp452;
  if (block243.is_used()) {
    ca_.Bind(&block243, &phi_bb243_16, &phi_bb243_17, &phi_bb243_18, &phi_bb243_27, &phi_bb243_28, &phi_bb243_29, &phi_bb243_30, &phi_bb243_33, &phi_bb243_34, &phi_bb243_35, &phi_bb243_36, &phi_bb243_38);
    std::tie(tmp449, tmp450) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp197}, TNode<IntPtrT>{phi_bb243_28}).Flatten();
    tmp451 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp452 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb243_28}, TNode<IntPtrT>{tmp451});
    ca_.Goto(&block242, phi_bb243_16, phi_bb243_17, phi_bb243_18, phi_bb243_27, tmp452, phi_bb243_29, phi_bb243_30, phi_bb243_33, phi_bb243_34, phi_bb243_35, phi_bb243_36, phi_bb243_38, tmp449, tmp450);
  }

  TNode<JSAny> phi_bb244_16;
  TNode<IntPtrT> phi_bb244_17;
  TNode<BoolT> phi_bb244_18;
  TNode<IntPtrT> phi_bb244_27;
  TNode<IntPtrT> phi_bb244_28;
  TNode<IntPtrT> phi_bb244_29;
  TNode<IntPtrT> phi_bb244_30;
  TNode<IntPtrT> phi_bb244_33;
  TNode<BoolT> phi_bb244_34;
  TNode<BoolT> phi_bb244_35;
  TNode<Union<FixedArray, Smi>> phi_bb244_36;
  TNode<Int32T> phi_bb244_38;
  if (block244.is_used()) {
    ca_.Bind(&block244, &phi_bb244_16, &phi_bb244_17, &phi_bb244_18, &phi_bb244_27, &phi_bb244_28, &phi_bb244_29, &phi_bb244_30, &phi_bb244_33, &phi_bb244_34, &phi_bb244_35, &phi_bb244_36, &phi_bb244_38);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block246, phi_bb244_16, phi_bb244_17, phi_bb244_18, phi_bb244_27, phi_bb244_28, phi_bb244_29, phi_bb244_30, phi_bb244_33, phi_bb244_34, phi_bb244_35, phi_bb244_36, phi_bb244_38);
    } else {
      ca_.Goto(&block247, phi_bb244_16, phi_bb244_17, phi_bb244_18, phi_bb244_27, phi_bb244_28, phi_bb244_29, phi_bb244_30, phi_bb244_33, phi_bb244_34, phi_bb244_35, phi_bb244_36, phi_bb244_38);
    }
  }

  TNode<JSAny> phi_bb246_16;
  TNode<IntPtrT> phi_bb246_17;
  TNode<BoolT> phi_bb246_18;
  TNode<IntPtrT> phi_bb246_27;
  TNode<IntPtrT> phi_bb246_28;
  TNode<IntPtrT> phi_bb246_29;
  TNode<IntPtrT> phi_bb246_30;
  TNode<IntPtrT> phi_bb246_33;
  TNode<BoolT> phi_bb246_34;
  TNode<BoolT> phi_bb246_35;
  TNode<Union<FixedArray, Smi>> phi_bb246_36;
  TNode<Int32T> phi_bb246_38;
  TNode<Union<HeapObject, TaggedIndex>> tmp453;
  TNode<IntPtrT> tmp454;
  TNode<IntPtrT> tmp455;
  TNode<IntPtrT> tmp456;
  if (block246.is_used()) {
    ca_.Bind(&block246, &phi_bb246_16, &phi_bb246_17, &phi_bb246_18, &phi_bb246_27, &phi_bb246_28, &phi_bb246_29, &phi_bb246_30, &phi_bb246_33, &phi_bb246_34, &phi_bb246_35, &phi_bb246_36, &phi_bb246_38);
    std::tie(tmp453, tmp454) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp197}, TNode<IntPtrT>{phi_bb246_30}).Flatten();
    tmp455 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp456 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb246_30}, TNode<IntPtrT>{tmp455});
    ca_.Goto(&block245, phi_bb246_16, phi_bb246_17, phi_bb246_18, phi_bb246_27, phi_bb246_28, phi_bb246_29, tmp456, phi_bb246_33, phi_bb246_34, phi_bb246_35, phi_bb246_36, phi_bb246_38, tmp453, tmp454);
  }

  TNode<JSAny> phi_bb247_16;
  TNode<IntPtrT> phi_bb247_17;
  TNode<BoolT> phi_bb247_18;
  TNode<IntPtrT> phi_bb247_27;
  TNode<IntPtrT> phi_bb247_28;
  TNode<IntPtrT> phi_bb247_29;
  TNode<IntPtrT> phi_bb247_30;
  TNode<IntPtrT> phi_bb247_33;
  TNode<BoolT> phi_bb247_34;
  TNode<BoolT> phi_bb247_35;
  TNode<Union<FixedArray, Smi>> phi_bb247_36;
  TNode<Int32T> phi_bb247_38;
  TNode<IntPtrT> tmp457;
  TNode<BoolT> tmp458;
  if (block247.is_used()) {
    ca_.Bind(&block247, &phi_bb247_16, &phi_bb247_17, &phi_bb247_18, &phi_bb247_27, &phi_bb247_28, &phi_bb247_29, &phi_bb247_30, &phi_bb247_33, &phi_bb247_34, &phi_bb247_35, &phi_bb247_36, &phi_bb247_38);
    tmp457 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp458 = CodeStubAssembler(state_).WordNotEqual(TNode<IntPtrT>{phi_bb247_33}, TNode<IntPtrT>{tmp457});
    ca_.Branch(tmp458, &block249, std::vector<compiler::Node*>{phi_bb247_16, phi_bb247_17, phi_bb247_18, phi_bb247_27, phi_bb247_28, phi_bb247_29, phi_bb247_30, phi_bb247_33, phi_bb247_34, phi_bb247_35, phi_bb247_36, phi_bb247_38}, &block250, std::vector<compiler::Node*>{phi_bb247_16, phi_bb247_17, phi_bb247_18, phi_bb247_27, phi_bb247_28, phi_bb247_29, phi_bb247_30, phi_bb247_33, phi_bb247_34, phi_bb247_35, phi_bb247_36, phi_bb247_38});
  }

  TNode<JSAny> phi_bb249_16;
  TNode<IntPtrT> phi_bb249_17;
  TNode<BoolT> phi_bb249_18;
  TNode<IntPtrT> phi_bb249_27;
  TNode<IntPtrT> phi_bb249_28;
  TNode<IntPtrT> phi_bb249_29;
  TNode<IntPtrT> phi_bb249_30;
  TNode<IntPtrT> phi_bb249_33;
  TNode<BoolT> phi_bb249_34;
  TNode<BoolT> phi_bb249_35;
  TNode<Union<FixedArray, Smi>> phi_bb249_36;
  TNode<Int32T> phi_bb249_38;
  TNode<Union<HeapObject, TaggedIndex>> tmp459;
  TNode<IntPtrT> tmp460;
  TNode<IntPtrT> tmp461;
  TNode<BoolT> tmp462;
  if (block249.is_used()) {
    ca_.Bind(&block249, &phi_bb249_16, &phi_bb249_17, &phi_bb249_18, &phi_bb249_27, &phi_bb249_28, &phi_bb249_29, &phi_bb249_30, &phi_bb249_33, &phi_bb249_34, &phi_bb249_35, &phi_bb249_36, &phi_bb249_38);
    std::tie(tmp459, tmp460) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp197}, TNode<IntPtrT>{phi_bb249_33}).Flatten();
    tmp461 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp462 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block245, phi_bb249_16, phi_bb249_17, phi_bb249_18, phi_bb249_27, phi_bb249_28, phi_bb249_29, phi_bb249_30, tmp461, tmp462, phi_bb249_35, phi_bb249_36, phi_bb249_38, tmp459, tmp460);
  }

  TNode<JSAny> phi_bb250_16;
  TNode<IntPtrT> phi_bb250_17;
  TNode<BoolT> phi_bb250_18;
  TNode<IntPtrT> phi_bb250_27;
  TNode<IntPtrT> phi_bb250_28;
  TNode<IntPtrT> phi_bb250_29;
  TNode<IntPtrT> phi_bb250_30;
  TNode<IntPtrT> phi_bb250_33;
  TNode<BoolT> phi_bb250_34;
  TNode<BoolT> phi_bb250_35;
  TNode<Union<FixedArray, Smi>> phi_bb250_36;
  TNode<Int32T> phi_bb250_38;
  TNode<Union<HeapObject, TaggedIndex>> tmp463;
  TNode<IntPtrT> tmp464;
  TNode<IntPtrT> tmp465;
  TNode<IntPtrT> tmp466;
  TNode<IntPtrT> tmp467;
  TNode<IntPtrT> tmp468;
  TNode<BoolT> tmp469;
  if (block250.is_used()) {
    ca_.Bind(&block250, &phi_bb250_16, &phi_bb250_17, &phi_bb250_18, &phi_bb250_27, &phi_bb250_28, &phi_bb250_29, &phi_bb250_30, &phi_bb250_33, &phi_bb250_34, &phi_bb250_35, &phi_bb250_36, &phi_bb250_38);
    std::tie(tmp463, tmp464) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp197}, TNode<IntPtrT>{phi_bb250_30}).Flatten();
    tmp465 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp466 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb250_30}, TNode<IntPtrT>{tmp465});
    tmp467 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp468 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp466}, TNode<IntPtrT>{tmp467});
    tmp469 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block245, phi_bb250_16, phi_bb250_17, phi_bb250_18, phi_bb250_27, phi_bb250_28, phi_bb250_29, tmp468, tmp466, tmp469, phi_bb250_35, phi_bb250_36, phi_bb250_38, tmp463, tmp464);
  }

  TNode<JSAny> phi_bb245_16;
  TNode<IntPtrT> phi_bb245_17;
  TNode<BoolT> phi_bb245_18;
  TNode<IntPtrT> phi_bb245_27;
  TNode<IntPtrT> phi_bb245_28;
  TNode<IntPtrT> phi_bb245_29;
  TNode<IntPtrT> phi_bb245_30;
  TNode<IntPtrT> phi_bb245_33;
  TNode<BoolT> phi_bb245_34;
  TNode<BoolT> phi_bb245_35;
  TNode<Union<FixedArray, Smi>> phi_bb245_36;
  TNode<Int32T> phi_bb245_38;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb245_41;
  TNode<IntPtrT> phi_bb245_42;
  if (block245.is_used()) {
    ca_.Bind(&block245, &phi_bb245_16, &phi_bb245_17, &phi_bb245_18, &phi_bb245_27, &phi_bb245_28, &phi_bb245_29, &phi_bb245_30, &phi_bb245_33, &phi_bb245_34, &phi_bb245_35, &phi_bb245_36, &phi_bb245_38, &phi_bb245_41, &phi_bb245_42);
    ca_.Goto(&block242, phi_bb245_16, phi_bb245_17, phi_bb245_18, phi_bb245_27, phi_bb245_28, phi_bb245_29, phi_bb245_30, phi_bb245_33, phi_bb245_34, phi_bb245_35, phi_bb245_36, phi_bb245_38, phi_bb245_41, phi_bb245_42);
  }

  TNode<JSAny> phi_bb242_16;
  TNode<IntPtrT> phi_bb242_17;
  TNode<BoolT> phi_bb242_18;
  TNode<IntPtrT> phi_bb242_27;
  TNode<IntPtrT> phi_bb242_28;
  TNode<IntPtrT> phi_bb242_29;
  TNode<IntPtrT> phi_bb242_30;
  TNode<IntPtrT> phi_bb242_33;
  TNode<BoolT> phi_bb242_34;
  TNode<BoolT> phi_bb242_35;
  TNode<Union<FixedArray, Smi>> phi_bb242_36;
  TNode<Int32T> phi_bb242_38;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb242_41;
  TNode<IntPtrT> phi_bb242_42;
  TNode<IntPtrT> tmp470;
  TNode<IntPtrT> tmp471;
  TNode<IntPtrT> tmp472;
  TNode<BoolT> tmp473;
  if (block242.is_used()) {
    ca_.Bind(&block242, &phi_bb242_16, &phi_bb242_17, &phi_bb242_18, &phi_bb242_27, &phi_bb242_28, &phi_bb242_29, &phi_bb242_30, &phi_bb242_33, &phi_bb242_34, &phi_bb242_35, &phi_bb242_36, &phi_bb242_38, &phi_bb242_41, &phi_bb242_42);
    tmp470 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp471 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{tmp446}, TNode<IntPtrT>{tmp470});
    tmp472 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp473 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp446}, TNode<IntPtrT>{tmp472});
    ca_.Branch(tmp473, &block252, std::vector<compiler::Node*>{phi_bb242_16, phi_bb242_17, phi_bb242_18, phi_bb242_27, phi_bb242_28, phi_bb242_29, phi_bb242_30, phi_bb242_33, phi_bb242_34, phi_bb242_35, phi_bb242_36, phi_bb242_38, phi_bb242_41, phi_bb242_42}, &block253, std::vector<compiler::Node*>{phi_bb242_16, phi_bb242_17, phi_bb242_18, phi_bb242_27, phi_bb242_28, phi_bb242_29, phi_bb242_30, phi_bb242_33, phi_bb242_34, phi_bb242_35, phi_bb242_36, phi_bb242_38, phi_bb242_41, phi_bb242_42});
  }

  TNode<JSAny> phi_bb252_16;
  TNode<IntPtrT> phi_bb252_17;
  TNode<BoolT> phi_bb252_18;
  TNode<IntPtrT> phi_bb252_27;
  TNode<IntPtrT> phi_bb252_28;
  TNode<IntPtrT> phi_bb252_29;
  TNode<IntPtrT> phi_bb252_30;
  TNode<IntPtrT> phi_bb252_33;
  TNode<BoolT> phi_bb252_34;
  TNode<BoolT> phi_bb252_35;
  TNode<Union<FixedArray, Smi>> phi_bb252_36;
  TNode<Int32T> phi_bb252_38;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb252_41;
  TNode<IntPtrT> phi_bb252_42;
  TNode<Union<HeapObject, TaggedIndex>> tmp474;
  TNode<IntPtrT> tmp475;
  TNode<IntPtrT> tmp476;
  TNode<IntPtrT> tmp477;
  if (block252.is_used()) {
    ca_.Bind(&block252, &phi_bb252_16, &phi_bb252_17, &phi_bb252_18, &phi_bb252_27, &phi_bb252_28, &phi_bb252_29, &phi_bb252_30, &phi_bb252_33, &phi_bb252_34, &phi_bb252_35, &phi_bb252_36, &phi_bb252_38, &phi_bb252_41, &phi_bb252_42);
    std::tie(tmp474, tmp475) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp197}, TNode<IntPtrT>{phi_bb252_28}).Flatten();
    tmp476 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp477 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb252_28}, TNode<IntPtrT>{tmp476});
    ca_.Goto(&block251, phi_bb252_16, phi_bb252_17, phi_bb252_18, phi_bb252_27, tmp477, phi_bb252_29, phi_bb252_30, phi_bb252_33, phi_bb252_34, phi_bb252_35, phi_bb252_36, phi_bb252_38, phi_bb252_41, phi_bb252_42, tmp474, tmp475);
  }

  TNode<JSAny> phi_bb253_16;
  TNode<IntPtrT> phi_bb253_17;
  TNode<BoolT> phi_bb253_18;
  TNode<IntPtrT> phi_bb253_27;
  TNode<IntPtrT> phi_bb253_28;
  TNode<IntPtrT> phi_bb253_29;
  TNode<IntPtrT> phi_bb253_30;
  TNode<IntPtrT> phi_bb253_33;
  TNode<BoolT> phi_bb253_34;
  TNode<BoolT> phi_bb253_35;
  TNode<Union<FixedArray, Smi>> phi_bb253_36;
  TNode<Int32T> phi_bb253_38;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb253_41;
  TNode<IntPtrT> phi_bb253_42;
  if (block253.is_used()) {
    ca_.Bind(&block253, &phi_bb253_16, &phi_bb253_17, &phi_bb253_18, &phi_bb253_27, &phi_bb253_28, &phi_bb253_29, &phi_bb253_30, &phi_bb253_33, &phi_bb253_34, &phi_bb253_35, &phi_bb253_36, &phi_bb253_38, &phi_bb253_41, &phi_bb253_42);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block255, phi_bb253_16, phi_bb253_17, phi_bb253_18, phi_bb253_27, phi_bb253_28, phi_bb253_29, phi_bb253_30, phi_bb253_33, phi_bb253_34, phi_bb253_35, phi_bb253_36, phi_bb253_38, phi_bb253_41, phi_bb253_42);
    } else {
      ca_.Goto(&block256, phi_bb253_16, phi_bb253_17, phi_bb253_18, phi_bb253_27, phi_bb253_28, phi_bb253_29, phi_bb253_30, phi_bb253_33, phi_bb253_34, phi_bb253_35, phi_bb253_36, phi_bb253_38, phi_bb253_41, phi_bb253_42);
    }
  }

  TNode<JSAny> phi_bb255_16;
  TNode<IntPtrT> phi_bb255_17;
  TNode<BoolT> phi_bb255_18;
  TNode<IntPtrT> phi_bb255_27;
  TNode<IntPtrT> phi_bb255_28;
  TNode<IntPtrT> phi_bb255_29;
  TNode<IntPtrT> phi_bb255_30;
  TNode<IntPtrT> phi_bb255_33;
  TNode<BoolT> phi_bb255_34;
  TNode<BoolT> phi_bb255_35;
  TNode<Union<FixedArray, Smi>> phi_bb255_36;
  TNode<Int32T> phi_bb255_38;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb255_41;
  TNode<IntPtrT> phi_bb255_42;
  TNode<Union<HeapObject, TaggedIndex>> tmp478;
  TNode<IntPtrT> tmp479;
  TNode<IntPtrT> tmp480;
  TNode<IntPtrT> tmp481;
  if (block255.is_used()) {
    ca_.Bind(&block255, &phi_bb255_16, &phi_bb255_17, &phi_bb255_18, &phi_bb255_27, &phi_bb255_28, &phi_bb255_29, &phi_bb255_30, &phi_bb255_33, &phi_bb255_34, &phi_bb255_35, &phi_bb255_36, &phi_bb255_38, &phi_bb255_41, &phi_bb255_42);
    std::tie(tmp478, tmp479) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp197}, TNode<IntPtrT>{phi_bb255_30}).Flatten();
    tmp480 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp481 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb255_30}, TNode<IntPtrT>{tmp480});
    ca_.Goto(&block254, phi_bb255_16, phi_bb255_17, phi_bb255_18, phi_bb255_27, phi_bb255_28, phi_bb255_29, tmp481, phi_bb255_33, phi_bb255_34, phi_bb255_35, phi_bb255_36, phi_bb255_38, phi_bb255_41, phi_bb255_42, tmp478, tmp479);
  }

  TNode<JSAny> phi_bb256_16;
  TNode<IntPtrT> phi_bb256_17;
  TNode<BoolT> phi_bb256_18;
  TNode<IntPtrT> phi_bb256_27;
  TNode<IntPtrT> phi_bb256_28;
  TNode<IntPtrT> phi_bb256_29;
  TNode<IntPtrT> phi_bb256_30;
  TNode<IntPtrT> phi_bb256_33;
  TNode<BoolT> phi_bb256_34;
  TNode<BoolT> phi_bb256_35;
  TNode<Union<FixedArray, Smi>> phi_bb256_36;
  TNode<Int32T> phi_bb256_38;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb256_41;
  TNode<IntPtrT> phi_bb256_42;
  TNode<IntPtrT> tmp482;
  TNode<BoolT> tmp483;
  if (block256.is_used()) {
    ca_.Bind(&block256, &phi_bb256_16, &phi_bb256_17, &phi_bb256_18, &phi_bb256_27, &phi_bb256_28, &phi_bb256_29, &phi_bb256_30, &phi_bb256_33, &phi_bb256_34, &phi_bb256_35, &phi_bb256_36, &phi_bb256_38, &phi_bb256_41, &phi_bb256_42);
    tmp482 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp483 = CodeStubAssembler(state_).WordNotEqual(TNode<IntPtrT>{phi_bb256_33}, TNode<IntPtrT>{tmp482});
    ca_.Branch(tmp483, &block258, std::vector<compiler::Node*>{phi_bb256_16, phi_bb256_17, phi_bb256_18, phi_bb256_27, phi_bb256_28, phi_bb256_29, phi_bb256_30, phi_bb256_33, phi_bb256_34, phi_bb256_35, phi_bb256_36, phi_bb256_38, phi_bb256_41, phi_bb256_42}, &block259, std::vector<compiler::Node*>{phi_bb256_16, phi_bb256_17, phi_bb256_18, phi_bb256_27, phi_bb256_28, phi_bb256_29, phi_bb256_30, phi_bb256_33, phi_bb256_34, phi_bb256_35, phi_bb256_36, phi_bb256_38, phi_bb256_41, phi_bb256_42});
  }

  TNode<JSAny> phi_bb258_16;
  TNode<IntPtrT> phi_bb258_17;
  TNode<BoolT> phi_bb258_18;
  TNode<IntPtrT> phi_bb258_27;
  TNode<IntPtrT> phi_bb258_28;
  TNode<IntPtrT> phi_bb258_29;
  TNode<IntPtrT> phi_bb258_30;
  TNode<IntPtrT> phi_bb258_33;
  TNode<BoolT> phi_bb258_34;
  TNode<BoolT> phi_bb258_35;
  TNode<Union<FixedArray, Smi>> phi_bb258_36;
  TNode<Int32T> phi_bb258_38;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb258_41;
  TNode<IntPtrT> phi_bb258_42;
  TNode<Union<HeapObject, TaggedIndex>> tmp484;
  TNode<IntPtrT> tmp485;
  TNode<IntPtrT> tmp486;
  TNode<BoolT> tmp487;
  if (block258.is_used()) {
    ca_.Bind(&block258, &phi_bb258_16, &phi_bb258_17, &phi_bb258_18, &phi_bb258_27, &phi_bb258_28, &phi_bb258_29, &phi_bb258_30, &phi_bb258_33, &phi_bb258_34, &phi_bb258_35, &phi_bb258_36, &phi_bb258_38, &phi_bb258_41, &phi_bb258_42);
    std::tie(tmp484, tmp485) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp197}, TNode<IntPtrT>{phi_bb258_33}).Flatten();
    tmp486 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp487 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block254, phi_bb258_16, phi_bb258_17, phi_bb258_18, phi_bb258_27, phi_bb258_28, phi_bb258_29, phi_bb258_30, tmp486, tmp487, phi_bb258_35, phi_bb258_36, phi_bb258_38, phi_bb258_41, phi_bb258_42, tmp484, tmp485);
  }

  TNode<JSAny> phi_bb259_16;
  TNode<IntPtrT> phi_bb259_17;
  TNode<BoolT> phi_bb259_18;
  TNode<IntPtrT> phi_bb259_27;
  TNode<IntPtrT> phi_bb259_28;
  TNode<IntPtrT> phi_bb259_29;
  TNode<IntPtrT> phi_bb259_30;
  TNode<IntPtrT> phi_bb259_33;
  TNode<BoolT> phi_bb259_34;
  TNode<BoolT> phi_bb259_35;
  TNode<Union<FixedArray, Smi>> phi_bb259_36;
  TNode<Int32T> phi_bb259_38;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb259_41;
  TNode<IntPtrT> phi_bb259_42;
  TNode<Union<HeapObject, TaggedIndex>> tmp488;
  TNode<IntPtrT> tmp489;
  TNode<IntPtrT> tmp490;
  TNode<IntPtrT> tmp491;
  TNode<IntPtrT> tmp492;
  TNode<IntPtrT> tmp493;
  TNode<BoolT> tmp494;
  if (block259.is_used()) {
    ca_.Bind(&block259, &phi_bb259_16, &phi_bb259_17, &phi_bb259_18, &phi_bb259_27, &phi_bb259_28, &phi_bb259_29, &phi_bb259_30, &phi_bb259_33, &phi_bb259_34, &phi_bb259_35, &phi_bb259_36, &phi_bb259_38, &phi_bb259_41, &phi_bb259_42);
    std::tie(tmp488, tmp489) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp197}, TNode<IntPtrT>{phi_bb259_30}).Flatten();
    tmp490 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp491 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb259_30}, TNode<IntPtrT>{tmp490});
    tmp492 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp493 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp491}, TNode<IntPtrT>{tmp492});
    tmp494 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block254, phi_bb259_16, phi_bb259_17, phi_bb259_18, phi_bb259_27, phi_bb259_28, phi_bb259_29, tmp493, tmp491, tmp494, phi_bb259_35, phi_bb259_36, phi_bb259_38, phi_bb259_41, phi_bb259_42, tmp488, tmp489);
  }

  TNode<JSAny> phi_bb254_16;
  TNode<IntPtrT> phi_bb254_17;
  TNode<BoolT> phi_bb254_18;
  TNode<IntPtrT> phi_bb254_27;
  TNode<IntPtrT> phi_bb254_28;
  TNode<IntPtrT> phi_bb254_29;
  TNode<IntPtrT> phi_bb254_30;
  TNode<IntPtrT> phi_bb254_33;
  TNode<BoolT> phi_bb254_34;
  TNode<BoolT> phi_bb254_35;
  TNode<Union<FixedArray, Smi>> phi_bb254_36;
  TNode<Int32T> phi_bb254_38;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb254_41;
  TNode<IntPtrT> phi_bb254_42;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb254_43;
  TNode<IntPtrT> phi_bb254_44;
  if (block254.is_used()) {
    ca_.Bind(&block254, &phi_bb254_16, &phi_bb254_17, &phi_bb254_18, &phi_bb254_27, &phi_bb254_28, &phi_bb254_29, &phi_bb254_30, &phi_bb254_33, &phi_bb254_34, &phi_bb254_35, &phi_bb254_36, &phi_bb254_38, &phi_bb254_41, &phi_bb254_42, &phi_bb254_43, &phi_bb254_44);
    ca_.Goto(&block251, phi_bb254_16, phi_bb254_17, phi_bb254_18, phi_bb254_27, phi_bb254_28, phi_bb254_29, phi_bb254_30, phi_bb254_33, phi_bb254_34, phi_bb254_35, phi_bb254_36, phi_bb254_38, phi_bb254_41, phi_bb254_42, phi_bb254_43, phi_bb254_44);
  }

  TNode<JSAny> phi_bb251_16;
  TNode<IntPtrT> phi_bb251_17;
  TNode<BoolT> phi_bb251_18;
  TNode<IntPtrT> phi_bb251_27;
  TNode<IntPtrT> phi_bb251_28;
  TNode<IntPtrT> phi_bb251_29;
  TNode<IntPtrT> phi_bb251_30;
  TNode<IntPtrT> phi_bb251_33;
  TNode<BoolT> phi_bb251_34;
  TNode<BoolT> phi_bb251_35;
  TNode<Union<FixedArray, Smi>> phi_bb251_36;
  TNode<Int32T> phi_bb251_38;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb251_41;
  TNode<IntPtrT> phi_bb251_42;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb251_43;
  TNode<IntPtrT> phi_bb251_44;
  TNode<BigInt> tmp495;
      TNode<JSAny> tmp497;
  TNode<UintPtrT> tmp498;
  TNode<UintPtrT> tmp499;
      TNode<JSAny> tmp501;
  TNode<IntPtrT> tmp502;
      TNode<JSAny> tmp504;
  TNode<IntPtrT> tmp505;
      TNode<JSAny> tmp507;
  if (block251.is_used()) {
    ca_.Bind(&block251, &phi_bb251_16, &phi_bb251_17, &phi_bb251_18, &phi_bb251_27, &phi_bb251_28, &phi_bb251_29, &phi_bb251_30, &phi_bb251_33, &phi_bb251_34, &phi_bb251_35, &phi_bb251_36, &phi_bb251_38, &phi_bb251_41, &phi_bb251_42, &phi_bb251_43, &phi_bb251_44);
    compiler::CodeAssemblerExceptionHandlerLabel catch496__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch496__label);
    tmp495 = CodeStubAssembler(state_).ToBigInt(TNode<Context>{p_context}, TNode<JSAny>{tmp233});
    }
    if (catch496__label.is_used()) {
      compiler::CodeAssemblerLabel catch496_skip(&ca_);
      ca_.Goto(&catch496_skip);
      ca_.Bind(&catch496__label, &tmp497);
      ca_.Goto(&block260, phi_bb251_16, phi_bb251_17, phi_bb251_18, phi_bb251_27, phi_bb251_28, phi_bb251_29, phi_bb251_30, phi_bb251_33, phi_bb251_34, phi_bb251_35, phi_bb251_36, phi_bb251_38, phi_bb251_41, phi_bb251_42, phi_bb251_43, phi_bb251_44);
      ca_.Bind(&catch496_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch500__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch500__label);
    std::tie(tmp498, tmp499) = CodeStubAssembler(state_).BigIntToRawBytes(TNode<BigInt>{tmp495}).Flatten();
    }
    if (catch500__label.is_used()) {
      compiler::CodeAssemblerLabel catch500_skip(&ca_);
      ca_.Goto(&catch500_skip);
      ca_.Bind(&catch500__label, &tmp501);
      ca_.Goto(&block261, phi_bb251_16, phi_bb251_17, phi_bb251_18, phi_bb251_27, phi_bb251_28, phi_bb251_29, phi_bb251_30, phi_bb251_33, phi_bb251_34, phi_bb251_35, phi_bb251_36, phi_bb251_38, phi_bb251_41, phi_bb251_42, phi_bb251_43, phi_bb251_44);
      ca_.Bind(&catch500_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch503__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch503__label);
    tmp502 = CodeStubAssembler(state_).Signed(TNode<UintPtrT>{tmp498});
    }
    if (catch503__label.is_used()) {
      compiler::CodeAssemblerLabel catch503_skip(&ca_);
      ca_.Goto(&catch503_skip);
      ca_.Bind(&catch503__label, &tmp504);
      ca_.Goto(&block262, phi_bb251_16, phi_bb251_17, phi_bb251_18, phi_bb251_27, phi_bb251_28, phi_bb251_29, phi_bb251_30, phi_bb251_33, phi_bb251_34, phi_bb251_35, phi_bb251_36, phi_bb251_38, phi_bb251_41, phi_bb251_42, phi_bb251_43, phi_bb251_44, phi_bb251_41, phi_bb251_42);
      ca_.Bind(&catch503_skip);
    }
    CodeStubAssembler(state_).StoreReference<IntPtrT>(CodeStubAssembler::Reference{phi_bb251_41, phi_bb251_42}, tmp502);
    compiler::CodeAssemblerExceptionHandlerLabel catch506__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch506__label);
    tmp505 = CodeStubAssembler(state_).Signed(TNode<UintPtrT>{tmp499});
    }
    if (catch506__label.is_used()) {
      compiler::CodeAssemblerLabel catch506_skip(&ca_);
      ca_.Goto(&catch506_skip);
      ca_.Bind(&catch506__label, &tmp507);
      ca_.Goto(&block263, phi_bb251_16, phi_bb251_17, phi_bb251_18, phi_bb251_27, phi_bb251_28, phi_bb251_29, phi_bb251_30, phi_bb251_33, phi_bb251_34, phi_bb251_35, phi_bb251_36, phi_bb251_38, phi_bb251_41, phi_bb251_42, phi_bb251_43, phi_bb251_44, phi_bb251_43, phi_bb251_44);
      ca_.Bind(&catch506_skip);
    }
    CodeStubAssembler(state_).StoreReference<IntPtrT>(CodeStubAssembler::Reference{phi_bb251_43, phi_bb251_44}, tmp505);
    ca_.Goto(&block231, phi_bb251_16, phi_bb251_17, phi_bb251_18, tmp471, phi_bb251_27, phi_bb251_28, phi_bb251_29, phi_bb251_30, phi_bb251_33, phi_bb251_34, phi_bb251_35, phi_bb251_36, phi_bb251_38);
  }

  TNode<JSAny> phi_bb260_16;
  TNode<IntPtrT> phi_bb260_17;
  TNode<BoolT> phi_bb260_18;
  TNode<IntPtrT> phi_bb260_27;
  TNode<IntPtrT> phi_bb260_28;
  TNode<IntPtrT> phi_bb260_29;
  TNode<IntPtrT> phi_bb260_30;
  TNode<IntPtrT> phi_bb260_33;
  TNode<BoolT> phi_bb260_34;
  TNode<BoolT> phi_bb260_35;
  TNode<Union<FixedArray, Smi>> phi_bb260_36;
  TNode<Int32T> phi_bb260_38;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb260_41;
  TNode<IntPtrT> phi_bb260_42;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb260_43;
  TNode<IntPtrT> phi_bb260_44;
  TNode<Union<Hole, JSMessageObject>> tmp508;
  if (block260.is_used()) {
    ca_.Bind(&block260, &phi_bb260_16, &phi_bb260_17, &phi_bb260_18, &phi_bb260_27, &phi_bb260_28, &phi_bb260_29, &phi_bb260_30, &phi_bb260_33, &phi_bb260_34, &phi_bb260_35, &phi_bb260_36, &phi_bb260_38, &phi_bb260_41, &phi_bb260_42, &phi_bb260_43, &phi_bb260_44);
    tmp508 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb260_16, phi_bb260_17, phi_bb260_18, tmp497, tmp508);
  }

  TNode<JSAny> phi_bb261_16;
  TNode<IntPtrT> phi_bb261_17;
  TNode<BoolT> phi_bb261_18;
  TNode<IntPtrT> phi_bb261_27;
  TNode<IntPtrT> phi_bb261_28;
  TNode<IntPtrT> phi_bb261_29;
  TNode<IntPtrT> phi_bb261_30;
  TNode<IntPtrT> phi_bb261_33;
  TNode<BoolT> phi_bb261_34;
  TNode<BoolT> phi_bb261_35;
  TNode<Union<FixedArray, Smi>> phi_bb261_36;
  TNode<Int32T> phi_bb261_38;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb261_41;
  TNode<IntPtrT> phi_bb261_42;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb261_43;
  TNode<IntPtrT> phi_bb261_44;
  TNode<Union<Hole, JSMessageObject>> tmp509;
  if (block261.is_used()) {
    ca_.Bind(&block261, &phi_bb261_16, &phi_bb261_17, &phi_bb261_18, &phi_bb261_27, &phi_bb261_28, &phi_bb261_29, &phi_bb261_30, &phi_bb261_33, &phi_bb261_34, &phi_bb261_35, &phi_bb261_36, &phi_bb261_38, &phi_bb261_41, &phi_bb261_42, &phi_bb261_43, &phi_bb261_44);
    tmp509 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb261_16, phi_bb261_17, phi_bb261_18, tmp501, tmp509);
  }

  TNode<JSAny> phi_bb262_16;
  TNode<IntPtrT> phi_bb262_17;
  TNode<BoolT> phi_bb262_18;
  TNode<IntPtrT> phi_bb262_27;
  TNode<IntPtrT> phi_bb262_28;
  TNode<IntPtrT> phi_bb262_29;
  TNode<IntPtrT> phi_bb262_30;
  TNode<IntPtrT> phi_bb262_33;
  TNode<BoolT> phi_bb262_34;
  TNode<BoolT> phi_bb262_35;
  TNode<Union<FixedArray, Smi>> phi_bb262_36;
  TNode<Int32T> phi_bb262_38;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb262_41;
  TNode<IntPtrT> phi_bb262_42;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb262_43;
  TNode<IntPtrT> phi_bb262_44;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb262_48;
  TNode<IntPtrT> phi_bb262_49;
  TNode<Union<Hole, JSMessageObject>> tmp510;
  if (block262.is_used()) {
    ca_.Bind(&block262, &phi_bb262_16, &phi_bb262_17, &phi_bb262_18, &phi_bb262_27, &phi_bb262_28, &phi_bb262_29, &phi_bb262_30, &phi_bb262_33, &phi_bb262_34, &phi_bb262_35, &phi_bb262_36, &phi_bb262_38, &phi_bb262_41, &phi_bb262_42, &phi_bb262_43, &phi_bb262_44, &phi_bb262_48, &phi_bb262_49);
    tmp510 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb262_16, phi_bb262_17, phi_bb262_18, tmp504, tmp510);
  }

  TNode<JSAny> phi_bb263_16;
  TNode<IntPtrT> phi_bb263_17;
  TNode<BoolT> phi_bb263_18;
  TNode<IntPtrT> phi_bb263_27;
  TNode<IntPtrT> phi_bb263_28;
  TNode<IntPtrT> phi_bb263_29;
  TNode<IntPtrT> phi_bb263_30;
  TNode<IntPtrT> phi_bb263_33;
  TNode<BoolT> phi_bb263_34;
  TNode<BoolT> phi_bb263_35;
  TNode<Union<FixedArray, Smi>> phi_bb263_36;
  TNode<Int32T> phi_bb263_38;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb263_41;
  TNode<IntPtrT> phi_bb263_42;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb263_43;
  TNode<IntPtrT> phi_bb263_44;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb263_48;
  TNode<IntPtrT> phi_bb263_49;
  TNode<Union<Hole, JSMessageObject>> tmp511;
  if (block263.is_used()) {
    ca_.Bind(&block263, &phi_bb263_16, &phi_bb263_17, &phi_bb263_18, &phi_bb263_27, &phi_bb263_28, &phi_bb263_29, &phi_bb263_30, &phi_bb263_33, &phi_bb263_34, &phi_bb263_35, &phi_bb263_36, &phi_bb263_38, &phi_bb263_41, &phi_bb263_42, &phi_bb263_43, &phi_bb263_44, &phi_bb263_48, &phi_bb263_49);
    tmp511 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb263_16, phi_bb263_17, phi_bb263_18, tmp507, tmp511);
  }

  TNode<JSAny> phi_bb231_16;
  TNode<IntPtrT> phi_bb231_17;
  TNode<BoolT> phi_bb231_18;
  TNode<IntPtrT> phi_bb231_26;
  TNode<IntPtrT> phi_bb231_27;
  TNode<IntPtrT> phi_bb231_28;
  TNode<IntPtrT> phi_bb231_29;
  TNode<IntPtrT> phi_bb231_30;
  TNode<IntPtrT> phi_bb231_33;
  TNode<BoolT> phi_bb231_34;
  TNode<BoolT> phi_bb231_35;
  TNode<Union<FixedArray, Smi>> phi_bb231_36;
  TNode<Int32T> phi_bb231_38;
  if (block231.is_used()) {
    ca_.Bind(&block231, &phi_bb231_16, &phi_bb231_17, &phi_bb231_18, &phi_bb231_26, &phi_bb231_27, &phi_bb231_28, &phi_bb231_29, &phi_bb231_30, &phi_bb231_33, &phi_bb231_34, &phi_bb231_35, &phi_bb231_36, &phi_bb231_38);
    ca_.Goto(&block228, phi_bb231_16, phi_bb231_17, phi_bb231_18, phi_bb231_26, phi_bb231_27, phi_bb231_28, phi_bb231_29, phi_bb231_30, phi_bb231_33, phi_bb231_34, phi_bb231_35, phi_bb231_36, phi_bb231_38);
  }

  TNode<JSAny> phi_bb225_16;
  TNode<IntPtrT> phi_bb225_17;
  TNode<BoolT> phi_bb225_18;
  TNode<IntPtrT> phi_bb225_26;
  TNode<IntPtrT> phi_bb225_27;
  TNode<IntPtrT> phi_bb225_28;
  TNode<IntPtrT> phi_bb225_29;
  TNode<IntPtrT> phi_bb225_30;
  TNode<IntPtrT> phi_bb225_33;
  TNode<BoolT> phi_bb225_34;
  TNode<BoolT> phi_bb225_35;
  TNode<Union<FixedArray, Smi>> phi_bb225_36;
  TNode<Int32T> phi_bb225_38;
  TNode<Int32T> tmp512;
      TNode<JSAny> tmp514;
  TNode<Int32T> tmp515;
      TNode<JSAny> tmp517;
  TNode<Int32T> tmp518;
      TNode<JSAny> tmp520;
  TNode<BoolT> tmp521;
      TNode<JSAny> tmp523;
  if (block225.is_used()) {
    ca_.Bind(&block225, &phi_bb225_16, &phi_bb225_17, &phi_bb225_18, &phi_bb225_26, &phi_bb225_27, &phi_bb225_28, &phi_bb225_29, &phi_bb225_30, &phi_bb225_33, &phi_bb225_34, &phi_bb225_35, &phi_bb225_36, &phi_bb225_38);
    compiler::CodeAssemblerExceptionHandlerLabel catch513__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch513__label);
    tmp512 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmValueKindBitsMask);
    }
    if (catch513__label.is_used()) {
      compiler::CodeAssemblerLabel catch513_skip(&ca_);
      ca_.Goto(&catch513_skip);
      ca_.Bind(&catch513__label, &tmp514);
      ca_.Goto(&block264, phi_bb225_16, phi_bb225_17, phi_bb225_18, phi_bb225_26, phi_bb225_27, phi_bb225_28, phi_bb225_29, phi_bb225_30, phi_bb225_33, phi_bb225_34, phi_bb225_35, phi_bb225_36, phi_bb225_38);
      ca_.Bind(&catch513_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch516__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch516__label);
    tmp515 = CodeStubAssembler(state_).Word32And(TNode<Int32T>{tmp249}, TNode<Int32T>{tmp512});
    }
    if (catch516__label.is_used()) {
      compiler::CodeAssemblerLabel catch516_skip(&ca_);
      ca_.Goto(&catch516_skip);
      ca_.Bind(&catch516__label, &tmp517);
      ca_.Goto(&block265, phi_bb225_16, phi_bb225_17, phi_bb225_18, phi_bb225_26, phi_bb225_27, phi_bb225_28, phi_bb225_29, phi_bb225_30, phi_bb225_33, phi_bb225_34, phi_bb225_35, phi_bb225_36, phi_bb225_38);
      ca_.Bind(&catch516_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch519__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch519__label);
    tmp518 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::ValueKind::kRef);
    }
    if (catch519__label.is_used()) {
      compiler::CodeAssemblerLabel catch519_skip(&ca_);
      ca_.Goto(&catch519_skip);
      ca_.Bind(&catch519__label, &tmp520);
      ca_.Goto(&block268, phi_bb225_16, phi_bb225_17, phi_bb225_18, phi_bb225_26, phi_bb225_27, phi_bb225_28, phi_bb225_29, phi_bb225_30, phi_bb225_33, phi_bb225_34, phi_bb225_35, phi_bb225_36, phi_bb225_38);
      ca_.Bind(&catch519_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch522__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch522__label);
    tmp521 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp515}, TNode<Int32T>{tmp518});
    }
    if (catch522__label.is_used()) {
      compiler::CodeAssemblerLabel catch522_skip(&ca_);
      ca_.Goto(&catch522_skip);
      ca_.Bind(&catch522__label, &tmp523);
      ca_.Goto(&block269, phi_bb225_16, phi_bb225_17, phi_bb225_18, phi_bb225_26, phi_bb225_27, phi_bb225_28, phi_bb225_29, phi_bb225_30, phi_bb225_33, phi_bb225_34, phi_bb225_35, phi_bb225_36, phi_bb225_38);
      ca_.Bind(&catch522_skip);
    }
    ca_.Branch(tmp521, &block270, std::vector<compiler::Node*>{phi_bb225_16, phi_bb225_17, phi_bb225_18, phi_bb225_26, phi_bb225_27, phi_bb225_28, phi_bb225_29, phi_bb225_30, phi_bb225_33, phi_bb225_34, phi_bb225_35, phi_bb225_36, phi_bb225_38}, &block271, std::vector<compiler::Node*>{phi_bb225_16, phi_bb225_17, phi_bb225_18, phi_bb225_26, phi_bb225_27, phi_bb225_28, phi_bb225_29, phi_bb225_30, phi_bb225_33, phi_bb225_34, phi_bb225_35, phi_bb225_36, phi_bb225_38});
  }

  TNode<JSAny> phi_bb264_16;
  TNode<IntPtrT> phi_bb264_17;
  TNode<BoolT> phi_bb264_18;
  TNode<IntPtrT> phi_bb264_26;
  TNode<IntPtrT> phi_bb264_27;
  TNode<IntPtrT> phi_bb264_28;
  TNode<IntPtrT> phi_bb264_29;
  TNode<IntPtrT> phi_bb264_30;
  TNode<IntPtrT> phi_bb264_33;
  TNode<BoolT> phi_bb264_34;
  TNode<BoolT> phi_bb264_35;
  TNode<Union<FixedArray, Smi>> phi_bb264_36;
  TNode<Int32T> phi_bb264_38;
  TNode<Union<Hole, JSMessageObject>> tmp524;
  if (block264.is_used()) {
    ca_.Bind(&block264, &phi_bb264_16, &phi_bb264_17, &phi_bb264_18, &phi_bb264_26, &phi_bb264_27, &phi_bb264_28, &phi_bb264_29, &phi_bb264_30, &phi_bb264_33, &phi_bb264_34, &phi_bb264_35, &phi_bb264_36, &phi_bb264_38);
    tmp524 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb264_16, phi_bb264_17, phi_bb264_18, tmp514, tmp524);
  }

  TNode<JSAny> phi_bb265_16;
  TNode<IntPtrT> phi_bb265_17;
  TNode<BoolT> phi_bb265_18;
  TNode<IntPtrT> phi_bb265_26;
  TNode<IntPtrT> phi_bb265_27;
  TNode<IntPtrT> phi_bb265_28;
  TNode<IntPtrT> phi_bb265_29;
  TNode<IntPtrT> phi_bb265_30;
  TNode<IntPtrT> phi_bb265_33;
  TNode<BoolT> phi_bb265_34;
  TNode<BoolT> phi_bb265_35;
  TNode<Union<FixedArray, Smi>> phi_bb265_36;
  TNode<Int32T> phi_bb265_38;
  TNode<Union<Hole, JSMessageObject>> tmp525;
  if (block265.is_used()) {
    ca_.Bind(&block265, &phi_bb265_16, &phi_bb265_17, &phi_bb265_18, &phi_bb265_26, &phi_bb265_27, &phi_bb265_28, &phi_bb265_29, &phi_bb265_30, &phi_bb265_33, &phi_bb265_34, &phi_bb265_35, &phi_bb265_36, &phi_bb265_38);
    tmp525 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb265_16, phi_bb265_17, phi_bb265_18, tmp517, tmp525);
  }

  TNode<JSAny> phi_bb268_16;
  TNode<IntPtrT> phi_bb268_17;
  TNode<BoolT> phi_bb268_18;
  TNode<IntPtrT> phi_bb268_26;
  TNode<IntPtrT> phi_bb268_27;
  TNode<IntPtrT> phi_bb268_28;
  TNode<IntPtrT> phi_bb268_29;
  TNode<IntPtrT> phi_bb268_30;
  TNode<IntPtrT> phi_bb268_33;
  TNode<BoolT> phi_bb268_34;
  TNode<BoolT> phi_bb268_35;
  TNode<Union<FixedArray, Smi>> phi_bb268_36;
  TNode<Int32T> phi_bb268_38;
  TNode<Union<Hole, JSMessageObject>> tmp526;
  if (block268.is_used()) {
    ca_.Bind(&block268, &phi_bb268_16, &phi_bb268_17, &phi_bb268_18, &phi_bb268_26, &phi_bb268_27, &phi_bb268_28, &phi_bb268_29, &phi_bb268_30, &phi_bb268_33, &phi_bb268_34, &phi_bb268_35, &phi_bb268_36, &phi_bb268_38);
    tmp526 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb268_16, phi_bb268_17, phi_bb268_18, tmp520, tmp526);
  }

  TNode<JSAny> phi_bb269_16;
  TNode<IntPtrT> phi_bb269_17;
  TNode<BoolT> phi_bb269_18;
  TNode<IntPtrT> phi_bb269_26;
  TNode<IntPtrT> phi_bb269_27;
  TNode<IntPtrT> phi_bb269_28;
  TNode<IntPtrT> phi_bb269_29;
  TNode<IntPtrT> phi_bb269_30;
  TNode<IntPtrT> phi_bb269_33;
  TNode<BoolT> phi_bb269_34;
  TNode<BoolT> phi_bb269_35;
  TNode<Union<FixedArray, Smi>> phi_bb269_36;
  TNode<Int32T> phi_bb269_38;
  TNode<Union<Hole, JSMessageObject>> tmp527;
  if (block269.is_used()) {
    ca_.Bind(&block269, &phi_bb269_16, &phi_bb269_17, &phi_bb269_18, &phi_bb269_26, &phi_bb269_27, &phi_bb269_28, &phi_bb269_29, &phi_bb269_30, &phi_bb269_33, &phi_bb269_34, &phi_bb269_35, &phi_bb269_36, &phi_bb269_38);
    tmp527 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb269_16, phi_bb269_17, phi_bb269_18, tmp523, tmp527);
  }

  TNode<JSAny> phi_bb270_16;
  TNode<IntPtrT> phi_bb270_17;
  TNode<BoolT> phi_bb270_18;
  TNode<IntPtrT> phi_bb270_26;
  TNode<IntPtrT> phi_bb270_27;
  TNode<IntPtrT> phi_bb270_28;
  TNode<IntPtrT> phi_bb270_29;
  TNode<IntPtrT> phi_bb270_30;
  TNode<IntPtrT> phi_bb270_33;
  TNode<BoolT> phi_bb270_34;
  TNode<BoolT> phi_bb270_35;
  TNode<Union<FixedArray, Smi>> phi_bb270_36;
  TNode<Int32T> phi_bb270_38;
  TNode<BoolT> tmp528;
      TNode<JSAny> tmp530;
  if (block270.is_used()) {
    ca_.Bind(&block270, &phi_bb270_16, &phi_bb270_17, &phi_bb270_18, &phi_bb270_26, &phi_bb270_27, &phi_bb270_28, &phi_bb270_29, &phi_bb270_30, &phi_bb270_33, &phi_bb270_34, &phi_bb270_35, &phi_bb270_36, &phi_bb270_38);
    compiler::CodeAssemblerExceptionHandlerLabel catch529__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch529__label);
    tmp528 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    }
    if (catch529__label.is_used()) {
      compiler::CodeAssemblerLabel catch529_skip(&ca_);
      ca_.Goto(&catch529_skip);
      ca_.Bind(&catch529__label, &tmp530);
      ca_.Goto(&block273, phi_bb270_16, phi_bb270_17, phi_bb270_18, phi_bb270_26, phi_bb270_27, phi_bb270_28, phi_bb270_29, phi_bb270_30, phi_bb270_33, phi_bb270_34, phi_bb270_35, phi_bb270_36, phi_bb270_38);
      ca_.Bind(&catch529_skip);
    }
    ca_.Goto(&block272, phi_bb270_16, phi_bb270_17, phi_bb270_18, phi_bb270_26, phi_bb270_27, phi_bb270_28, phi_bb270_29, phi_bb270_30, phi_bb270_33, phi_bb270_34, phi_bb270_35, phi_bb270_36, phi_bb270_38, tmp528);
  }

  TNode<JSAny> phi_bb273_16;
  TNode<IntPtrT> phi_bb273_17;
  TNode<BoolT> phi_bb273_18;
  TNode<IntPtrT> phi_bb273_26;
  TNode<IntPtrT> phi_bb273_27;
  TNode<IntPtrT> phi_bb273_28;
  TNode<IntPtrT> phi_bb273_29;
  TNode<IntPtrT> phi_bb273_30;
  TNode<IntPtrT> phi_bb273_33;
  TNode<BoolT> phi_bb273_34;
  TNode<BoolT> phi_bb273_35;
  TNode<Union<FixedArray, Smi>> phi_bb273_36;
  TNode<Int32T> phi_bb273_38;
  TNode<Union<Hole, JSMessageObject>> tmp531;
  if (block273.is_used()) {
    ca_.Bind(&block273, &phi_bb273_16, &phi_bb273_17, &phi_bb273_18, &phi_bb273_26, &phi_bb273_27, &phi_bb273_28, &phi_bb273_29, &phi_bb273_30, &phi_bb273_33, &phi_bb273_34, &phi_bb273_35, &phi_bb273_36, &phi_bb273_38);
    tmp531 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb273_16, phi_bb273_17, phi_bb273_18, tmp530, tmp531);
  }

  TNode<JSAny> phi_bb271_16;
  TNode<IntPtrT> phi_bb271_17;
  TNode<BoolT> phi_bb271_18;
  TNode<IntPtrT> phi_bb271_26;
  TNode<IntPtrT> phi_bb271_27;
  TNode<IntPtrT> phi_bb271_28;
  TNode<IntPtrT> phi_bb271_29;
  TNode<IntPtrT> phi_bb271_30;
  TNode<IntPtrT> phi_bb271_33;
  TNode<BoolT> phi_bb271_34;
  TNode<BoolT> phi_bb271_35;
  TNode<Union<FixedArray, Smi>> phi_bb271_36;
  TNode<Int32T> phi_bb271_38;
  TNode<Int32T> tmp532;
      TNode<JSAny> tmp534;
  TNode<BoolT> tmp535;
      TNode<JSAny> tmp537;
  if (block271.is_used()) {
    ca_.Bind(&block271, &phi_bb271_16, &phi_bb271_17, &phi_bb271_18, &phi_bb271_26, &phi_bb271_27, &phi_bb271_28, &phi_bb271_29, &phi_bb271_30, &phi_bb271_33, &phi_bb271_34, &phi_bb271_35, &phi_bb271_36, &phi_bb271_38);
    compiler::CodeAssemblerExceptionHandlerLabel catch533__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch533__label);
    tmp532 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::ValueKind::kRefNull);
    }
    if (catch533__label.is_used()) {
      compiler::CodeAssemblerLabel catch533_skip(&ca_);
      ca_.Goto(&catch533_skip);
      ca_.Bind(&catch533__label, &tmp534);
      ca_.Goto(&block274, phi_bb271_16, phi_bb271_17, phi_bb271_18, phi_bb271_26, phi_bb271_27, phi_bb271_28, phi_bb271_29, phi_bb271_30, phi_bb271_33, phi_bb271_34, phi_bb271_35, phi_bb271_36, phi_bb271_38);
      ca_.Bind(&catch533_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch536__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch536__label);
    tmp535 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp515}, TNode<Int32T>{tmp532});
    }
    if (catch536__label.is_used()) {
      compiler::CodeAssemblerLabel catch536_skip(&ca_);
      ca_.Goto(&catch536_skip);
      ca_.Bind(&catch536__label, &tmp537);
      ca_.Goto(&block275, phi_bb271_16, phi_bb271_17, phi_bb271_18, phi_bb271_26, phi_bb271_27, phi_bb271_28, phi_bb271_29, phi_bb271_30, phi_bb271_33, phi_bb271_34, phi_bb271_35, phi_bb271_36, phi_bb271_38);
      ca_.Bind(&catch536_skip);
    }
    ca_.Goto(&block272, phi_bb271_16, phi_bb271_17, phi_bb271_18, phi_bb271_26, phi_bb271_27, phi_bb271_28, phi_bb271_29, phi_bb271_30, phi_bb271_33, phi_bb271_34, phi_bb271_35, phi_bb271_36, phi_bb271_38, tmp535);
  }

  TNode<JSAny> phi_bb274_16;
  TNode<IntPtrT> phi_bb274_17;
  TNode<BoolT> phi_bb274_18;
  TNode<IntPtrT> phi_bb274_26;
  TNode<IntPtrT> phi_bb274_27;
  TNode<IntPtrT> phi_bb274_28;
  TNode<IntPtrT> phi_bb274_29;
  TNode<IntPtrT> phi_bb274_30;
  TNode<IntPtrT> phi_bb274_33;
  TNode<BoolT> phi_bb274_34;
  TNode<BoolT> phi_bb274_35;
  TNode<Union<FixedArray, Smi>> phi_bb274_36;
  TNode<Int32T> phi_bb274_38;
  TNode<Union<Hole, JSMessageObject>> tmp538;
  if (block274.is_used()) {
    ca_.Bind(&block274, &phi_bb274_16, &phi_bb274_17, &phi_bb274_18, &phi_bb274_26, &phi_bb274_27, &phi_bb274_28, &phi_bb274_29, &phi_bb274_30, &phi_bb274_33, &phi_bb274_34, &phi_bb274_35, &phi_bb274_36, &phi_bb274_38);
    tmp538 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb274_16, phi_bb274_17, phi_bb274_18, tmp534, tmp538);
  }

  TNode<JSAny> phi_bb275_16;
  TNode<IntPtrT> phi_bb275_17;
  TNode<BoolT> phi_bb275_18;
  TNode<IntPtrT> phi_bb275_26;
  TNode<IntPtrT> phi_bb275_27;
  TNode<IntPtrT> phi_bb275_28;
  TNode<IntPtrT> phi_bb275_29;
  TNode<IntPtrT> phi_bb275_30;
  TNode<IntPtrT> phi_bb275_33;
  TNode<BoolT> phi_bb275_34;
  TNode<BoolT> phi_bb275_35;
  TNode<Union<FixedArray, Smi>> phi_bb275_36;
  TNode<Int32T> phi_bb275_38;
  TNode<Union<Hole, JSMessageObject>> tmp539;
  if (block275.is_used()) {
    ca_.Bind(&block275, &phi_bb275_16, &phi_bb275_17, &phi_bb275_18, &phi_bb275_26, &phi_bb275_27, &phi_bb275_28, &phi_bb275_29, &phi_bb275_30, &phi_bb275_33, &phi_bb275_34, &phi_bb275_35, &phi_bb275_36, &phi_bb275_38);
    tmp539 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb275_16, phi_bb275_17, phi_bb275_18, tmp537, tmp539);
  }

  TNode<JSAny> phi_bb272_16;
  TNode<IntPtrT> phi_bb272_17;
  TNode<BoolT> phi_bb272_18;
  TNode<IntPtrT> phi_bb272_26;
  TNode<IntPtrT> phi_bb272_27;
  TNode<IntPtrT> phi_bb272_28;
  TNode<IntPtrT> phi_bb272_29;
  TNode<IntPtrT> phi_bb272_30;
  TNode<IntPtrT> phi_bb272_33;
  TNode<BoolT> phi_bb272_34;
  TNode<BoolT> phi_bb272_35;
  TNode<Union<FixedArray, Smi>> phi_bb272_36;
  TNode<Int32T> phi_bb272_38;
  TNode<BoolT> phi_bb272_43;
  if (block272.is_used()) {
    ca_.Bind(&block272, &phi_bb272_16, &phi_bb272_17, &phi_bb272_18, &phi_bb272_26, &phi_bb272_27, &phi_bb272_28, &phi_bb272_29, &phi_bb272_30, &phi_bb272_33, &phi_bb272_34, &phi_bb272_35, &phi_bb272_36, &phi_bb272_38, &phi_bb272_43);
    ca_.Branch(phi_bb272_43, &block266, std::vector<compiler::Node*>{phi_bb272_16, phi_bb272_17, phi_bb272_18, phi_bb272_26, phi_bb272_27, phi_bb272_28, phi_bb272_29, phi_bb272_30, phi_bb272_33, phi_bb272_34, phi_bb272_35, phi_bb272_36, phi_bb272_38}, &block267, std::vector<compiler::Node*>{phi_bb272_16, phi_bb272_17, phi_bb272_18, phi_bb272_26, phi_bb272_27, phi_bb272_28, phi_bb272_29, phi_bb272_30, phi_bb272_33, phi_bb272_34, phi_bb272_35, phi_bb272_36, phi_bb272_38});
  }

  TNode<JSAny> phi_bb267_16;
  TNode<IntPtrT> phi_bb267_17;
  TNode<BoolT> phi_bb267_18;
  TNode<IntPtrT> phi_bb267_26;
  TNode<IntPtrT> phi_bb267_27;
  TNode<IntPtrT> phi_bb267_28;
  TNode<IntPtrT> phi_bb267_29;
  TNode<IntPtrT> phi_bb267_30;
  TNode<IntPtrT> phi_bb267_33;
  TNode<BoolT> phi_bb267_34;
  TNode<BoolT> phi_bb267_35;
  TNode<Union<FixedArray, Smi>> phi_bb267_36;
  TNode<Int32T> phi_bb267_38;
  if (block267.is_used()) {
    ca_.Bind(&block267, &phi_bb267_16, &phi_bb267_17, &phi_bb267_18, &phi_bb267_26, &phi_bb267_27, &phi_bb267_28, &phi_bb267_29, &phi_bb267_30, &phi_bb267_33, &phi_bb267_34, &phi_bb267_35, &phi_bb267_36, &phi_bb267_38);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/js-to-wasm.tq", 711});
      CodeStubAssembler(state_).FailAssert("Torque assert 'paramKind == ValueKind::kRef || paramKind == ValueKind::kRefNull' failed", pos_stack);
    }
  }

  TNode<JSAny> phi_bb266_16;
  TNode<IntPtrT> phi_bb266_17;
  TNode<BoolT> phi_bb266_18;
  TNode<IntPtrT> phi_bb266_26;
  TNode<IntPtrT> phi_bb266_27;
  TNode<IntPtrT> phi_bb266_28;
  TNode<IntPtrT> phi_bb266_29;
  TNode<IntPtrT> phi_bb266_30;
  TNode<IntPtrT> phi_bb266_33;
  TNode<BoolT> phi_bb266_34;
  TNode<BoolT> phi_bb266_35;
  TNode<Union<FixedArray, Smi>> phi_bb266_36;
  TNode<Int32T> phi_bb266_38;
  TNode<BoolT> tmp540;
      TNode<JSAny> tmp542;
  TNode<BoolT> tmp543;
      TNode<JSAny> tmp545;
  if (block266.is_used()) {
    ca_.Bind(&block266, &phi_bb266_16, &phi_bb266_17, &phi_bb266_18, &phi_bb266_26, &phi_bb266_27, &phi_bb266_28, &phi_bb266_29, &phi_bb266_30, &phi_bb266_33, &phi_bb266_34, &phi_bb266_35, &phi_bb266_36, &phi_bb266_38);
    compiler::CodeAssemblerExceptionHandlerLabel catch541__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch541__label);
    tmp540 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    }
    if (catch541__label.is_used()) {
      compiler::CodeAssemblerLabel catch541_skip(&ca_);
      ca_.Goto(&catch541_skip);
      ca_.Bind(&catch541__label, &tmp542);
      ca_.Goto(&block276, phi_bb266_16, phi_bb266_17, phi_bb266_18, phi_bb266_26, phi_bb266_27, phi_bb266_28, phi_bb266_29, phi_bb266_30, phi_bb266_33, phi_bb266_34, phi_bb266_35, phi_bb266_36, phi_bb266_38);
      ca_.Bind(&catch541_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch544__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch544__label);
    tmp543 = CodeStubAssembler(state_).TaggedIsSmi(TNode<Object>{phi_bb266_36});
    }
    if (catch544__label.is_used()) {
      compiler::CodeAssemblerLabel catch544_skip(&ca_);
      ca_.Goto(&catch544_skip);
      ca_.Bind(&catch544__label, &tmp545);
      ca_.Goto(&block279, phi_bb266_16, phi_bb266_17, phi_bb266_18, phi_bb266_26, phi_bb266_27, phi_bb266_28, phi_bb266_29, phi_bb266_30, phi_bb266_33, phi_bb266_34, phi_bb266_36, phi_bb266_38, phi_bb266_36);
      ca_.Bind(&catch544_skip);
    }
    ca_.Branch(tmp543, &block277, std::vector<compiler::Node*>{phi_bb266_16, phi_bb266_17, phi_bb266_18, phi_bb266_26, phi_bb266_27, phi_bb266_28, phi_bb266_29, phi_bb266_30, phi_bb266_33, phi_bb266_34, phi_bb266_36, phi_bb266_38}, &block278, std::vector<compiler::Node*>{phi_bb266_16, phi_bb266_17, phi_bb266_18, phi_bb266_26, phi_bb266_27, phi_bb266_28, phi_bb266_29, phi_bb266_30, phi_bb266_33, phi_bb266_34, phi_bb266_36, phi_bb266_38});
  }

  TNode<JSAny> phi_bb276_16;
  TNode<IntPtrT> phi_bb276_17;
  TNode<BoolT> phi_bb276_18;
  TNode<IntPtrT> phi_bb276_26;
  TNode<IntPtrT> phi_bb276_27;
  TNode<IntPtrT> phi_bb276_28;
  TNode<IntPtrT> phi_bb276_29;
  TNode<IntPtrT> phi_bb276_30;
  TNode<IntPtrT> phi_bb276_33;
  TNode<BoolT> phi_bb276_34;
  TNode<BoolT> phi_bb276_35;
  TNode<Union<FixedArray, Smi>> phi_bb276_36;
  TNode<Int32T> phi_bb276_38;
  TNode<Union<Hole, JSMessageObject>> tmp546;
  if (block276.is_used()) {
    ca_.Bind(&block276, &phi_bb276_16, &phi_bb276_17, &phi_bb276_18, &phi_bb276_26, &phi_bb276_27, &phi_bb276_28, &phi_bb276_29, &phi_bb276_30, &phi_bb276_33, &phi_bb276_34, &phi_bb276_35, &phi_bb276_36, &phi_bb276_38);
    tmp546 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb276_16, phi_bb276_17, phi_bb276_18, tmp542, tmp546);
  }

  TNode<JSAny> phi_bb279_16;
  TNode<IntPtrT> phi_bb279_17;
  TNode<BoolT> phi_bb279_18;
  TNode<IntPtrT> phi_bb279_26;
  TNode<IntPtrT> phi_bb279_27;
  TNode<IntPtrT> phi_bb279_28;
  TNode<IntPtrT> phi_bb279_29;
  TNode<IntPtrT> phi_bb279_30;
  TNode<IntPtrT> phi_bb279_33;
  TNode<BoolT> phi_bb279_34;
  TNode<Union<FixedArray, Smi>> phi_bb279_36;
  TNode<Int32T> phi_bb279_38;
  TNode<Union<FixedArray, Smi>> phi_bb279_42;
  TNode<Union<Hole, JSMessageObject>> tmp547;
  if (block279.is_used()) {
    ca_.Bind(&block279, &phi_bb279_16, &phi_bb279_17, &phi_bb279_18, &phi_bb279_26, &phi_bb279_27, &phi_bb279_28, &phi_bb279_29, &phi_bb279_30, &phi_bb279_33, &phi_bb279_34, &phi_bb279_36, &phi_bb279_38, &phi_bb279_42);
    tmp547 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb279_16, phi_bb279_17, phi_bb279_18, tmp545, tmp547);
  }

  TNode<JSAny> phi_bb277_16;
  TNode<IntPtrT> phi_bb277_17;
  TNode<BoolT> phi_bb277_18;
  TNode<IntPtrT> phi_bb277_26;
  TNode<IntPtrT> phi_bb277_27;
  TNode<IntPtrT> phi_bb277_28;
  TNode<IntPtrT> phi_bb277_29;
  TNode<IntPtrT> phi_bb277_30;
  TNode<IntPtrT> phi_bb277_33;
  TNode<BoolT> phi_bb277_34;
  TNode<Union<FixedArray, Smi>> phi_bb277_36;
  TNode<Int32T> phi_bb277_38;
  TNode<IntPtrT> tmp548;
      TNode<JSAny> tmp550;
  TNode<FixedArray> tmp551;
      TNode<JSAny> tmp553;
  if (block277.is_used()) {
    ca_.Bind(&block277, &phi_bb277_16, &phi_bb277_17, &phi_bb277_18, &phi_bb277_26, &phi_bb277_27, &phi_bb277_28, &phi_bb277_29, &phi_bb277_30, &phi_bb277_33, &phi_bb277_34, &phi_bb277_36, &phi_bb277_38);
    compiler::CodeAssemblerExceptionHandlerLabel catch549__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch549__label);
    tmp548 = Convert_intptr_int32_0(state_, TNode<Int32T>{tmp25});
    }
    if (catch549__label.is_used()) {
      compiler::CodeAssemblerLabel catch549_skip(&ca_);
      ca_.Goto(&catch549_skip);
      ca_.Bind(&catch549__label, &tmp550);
      ca_.Goto(&block280, phi_bb277_16, phi_bb277_17, phi_bb277_18, phi_bb277_26, phi_bb277_27, phi_bb277_28, phi_bb277_29, phi_bb277_30, phi_bb277_33, phi_bb277_34, phi_bb277_36, phi_bb277_38);
      ca_.Bind(&catch549_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch552__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch552__label);
    tmp551 = ca_.CallBuiltin<FixedArray>(Builtin::kWasmAllocateZeroedFixedArray, TNode<Object>(), tmp548);
    }
    if (catch552__label.is_used()) {
      compiler::CodeAssemblerLabel catch552_skip(&ca_);
      ca_.Goto(&catch552_skip);
      ca_.Bind(&catch552__label, &tmp553);
      ca_.Goto(&block281, phi_bb277_16, phi_bb277_17, phi_bb277_18, phi_bb277_26, phi_bb277_27, phi_bb277_28, phi_bb277_29, phi_bb277_30, phi_bb277_33, phi_bb277_34, phi_bb277_36, phi_bb277_38);
      ca_.Bind(&catch552_skip);
    }
    ca_.Goto(&block278, phi_bb277_16, phi_bb277_17, phi_bb277_18, phi_bb277_26, phi_bb277_27, phi_bb277_28, phi_bb277_29, phi_bb277_30, phi_bb277_33, phi_bb277_34, tmp551, phi_bb277_38);
  }

  TNode<JSAny> phi_bb280_16;
  TNode<IntPtrT> phi_bb280_17;
  TNode<BoolT> phi_bb280_18;
  TNode<IntPtrT> phi_bb280_26;
  TNode<IntPtrT> phi_bb280_27;
  TNode<IntPtrT> phi_bb280_28;
  TNode<IntPtrT> phi_bb280_29;
  TNode<IntPtrT> phi_bb280_30;
  TNode<IntPtrT> phi_bb280_33;
  TNode<BoolT> phi_bb280_34;
  TNode<Union<FixedArray, Smi>> phi_bb280_36;
  TNode<Int32T> phi_bb280_38;
  TNode<Union<Hole, JSMessageObject>> tmp554;
  if (block280.is_used()) {
    ca_.Bind(&block280, &phi_bb280_16, &phi_bb280_17, &phi_bb280_18, &phi_bb280_26, &phi_bb280_27, &phi_bb280_28, &phi_bb280_29, &phi_bb280_30, &phi_bb280_33, &phi_bb280_34, &phi_bb280_36, &phi_bb280_38);
    tmp554 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb280_16, phi_bb280_17, phi_bb280_18, tmp550, tmp554);
  }

  TNode<JSAny> phi_bb281_16;
  TNode<IntPtrT> phi_bb281_17;
  TNode<BoolT> phi_bb281_18;
  TNode<IntPtrT> phi_bb281_26;
  TNode<IntPtrT> phi_bb281_27;
  TNode<IntPtrT> phi_bb281_28;
  TNode<IntPtrT> phi_bb281_29;
  TNode<IntPtrT> phi_bb281_30;
  TNode<IntPtrT> phi_bb281_33;
  TNode<BoolT> phi_bb281_34;
  TNode<Union<FixedArray, Smi>> phi_bb281_36;
  TNode<Int32T> phi_bb281_38;
  TNode<Union<Hole, JSMessageObject>> tmp555;
  if (block281.is_used()) {
    ca_.Bind(&block281, &phi_bb281_16, &phi_bb281_17, &phi_bb281_18, &phi_bb281_26, &phi_bb281_27, &phi_bb281_28, &phi_bb281_29, &phi_bb281_30, &phi_bb281_33, &phi_bb281_34, &phi_bb281_36, &phi_bb281_38);
    tmp555 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb281_16, phi_bb281_17, phi_bb281_18, tmp553, tmp555);
  }

  TNode<JSAny> phi_bb278_16;
  TNode<IntPtrT> phi_bb278_17;
  TNode<BoolT> phi_bb278_18;
  TNode<IntPtrT> phi_bb278_26;
  TNode<IntPtrT> phi_bb278_27;
  TNode<IntPtrT> phi_bb278_28;
  TNode<IntPtrT> phi_bb278_29;
  TNode<IntPtrT> phi_bb278_30;
  TNode<IntPtrT> phi_bb278_33;
  TNode<BoolT> phi_bb278_34;
  TNode<Union<FixedArray, Smi>> phi_bb278_36;
  TNode<Int32T> phi_bb278_38;
  TNode<FixedArray> tmp556;
      TNode<JSAny> tmp558;
  TNode<Union<HeapObject, TaggedIndex>> tmp559;
  TNode<IntPtrT> tmp560;
  TNode<IntPtrT> tmp561;
      TNode<JSAny> tmp563;
  TNode<IntPtrT> tmp564;
      TNode<JSAny> tmp566;
  TNode<UintPtrT> tmp567;
  TNode<UintPtrT> tmp568;
  TNode<BoolT> tmp569;
  if (block278.is_used()) {
    ca_.Bind(&block278, &phi_bb278_16, &phi_bb278_17, &phi_bb278_18, &phi_bb278_26, &phi_bb278_27, &phi_bb278_28, &phi_bb278_29, &phi_bb278_30, &phi_bb278_33, &phi_bb278_34, &phi_bb278_36, &phi_bb278_38);
    compiler::CodeAssemblerExceptionHandlerLabel catch557__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch557__label);
    tmp556 = UnsafeCast_FixedArray_0(state_, TNode<Context>{p_context}, TNode<Object>{phi_bb278_36});
    }
    if (catch557__label.is_used()) {
      compiler::CodeAssemblerLabel catch557_skip(&ca_);
      ca_.Goto(&catch557_skip);
      ca_.Bind(&catch557__label, &tmp558);
      ca_.Goto(&block282, phi_bb278_16, phi_bb278_17, phi_bb278_18, phi_bb278_26, phi_bb278_27, phi_bb278_28, phi_bb278_29, phi_bb278_30, phi_bb278_33, phi_bb278_34, phi_bb278_38);
      ca_.Bind(&catch557_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch562__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch562__label);
    std::tie(tmp559, tmp560, tmp561) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{tmp556}).Flatten();
    }
    if (catch562__label.is_used()) {
      compiler::CodeAssemblerLabel catch562_skip(&ca_);
      ca_.Goto(&catch562_skip);
      ca_.Bind(&catch562__label, &tmp563);
      ca_.Goto(&block283, phi_bb278_16, phi_bb278_17, phi_bb278_18, phi_bb278_26, phi_bb278_27, phi_bb278_28, phi_bb278_29, phi_bb278_30, phi_bb278_33, phi_bb278_34, phi_bb278_38);
      ca_.Bind(&catch562_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch565__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch565__label);
    tmp564 = Convert_intptr_int32_0(state_, TNode<Int32T>{phi_bb278_38});
    }
    if (catch565__label.is_used()) {
      compiler::CodeAssemblerLabel catch565_skip(&ca_);
      ca_.Goto(&catch565_skip);
      ca_.Bind(&catch565__label, &tmp566);
      ca_.Goto(&block284, phi_bb278_16, phi_bb278_17, phi_bb278_18, phi_bb278_26, phi_bb278_27, phi_bb278_28, phi_bb278_29, phi_bb278_30, phi_bb278_33, phi_bb278_34, phi_bb278_38, phi_bb278_38);
      ca_.Bind(&catch565_skip);
    }
    tmp567 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp564});
    tmp568 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp561});
    tmp569 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp567}, TNode<UintPtrT>{tmp568});
    ca_.Branch(tmp569, &block289, std::vector<compiler::Node*>{phi_bb278_16, phi_bb278_17, phi_bb278_18, phi_bb278_26, phi_bb278_27, phi_bb278_28, phi_bb278_29, phi_bb278_30, phi_bb278_33, phi_bb278_34, phi_bb278_38}, &block290, std::vector<compiler::Node*>{phi_bb278_16, phi_bb278_17, phi_bb278_18, phi_bb278_26, phi_bb278_27, phi_bb278_28, phi_bb278_29, phi_bb278_30, phi_bb278_33, phi_bb278_34, phi_bb278_38});
  }

  TNode<JSAny> phi_bb282_16;
  TNode<IntPtrT> phi_bb282_17;
  TNode<BoolT> phi_bb282_18;
  TNode<IntPtrT> phi_bb282_26;
  TNode<IntPtrT> phi_bb282_27;
  TNode<IntPtrT> phi_bb282_28;
  TNode<IntPtrT> phi_bb282_29;
  TNode<IntPtrT> phi_bb282_30;
  TNode<IntPtrT> phi_bb282_33;
  TNode<BoolT> phi_bb282_34;
  TNode<Int32T> phi_bb282_38;
  TNode<Union<Hole, JSMessageObject>> tmp570;
  if (block282.is_used()) {
    ca_.Bind(&block282, &phi_bb282_16, &phi_bb282_17, &phi_bb282_18, &phi_bb282_26, &phi_bb282_27, &phi_bb282_28, &phi_bb282_29, &phi_bb282_30, &phi_bb282_33, &phi_bb282_34, &phi_bb282_38);
    tmp570 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb282_16, phi_bb282_17, phi_bb282_18, tmp558, tmp570);
  }

  TNode<JSAny> phi_bb283_16;
  TNode<IntPtrT> phi_bb283_17;
  TNode<BoolT> phi_bb283_18;
  TNode<IntPtrT> phi_bb283_26;
  TNode<IntPtrT> phi_bb283_27;
  TNode<IntPtrT> phi_bb283_28;
  TNode<IntPtrT> phi_bb283_29;
  TNode<IntPtrT> phi_bb283_30;
  TNode<IntPtrT> phi_bb283_33;
  TNode<BoolT> phi_bb283_34;
  TNode<Int32T> phi_bb283_38;
  TNode<Union<Hole, JSMessageObject>> tmp571;
  if (block283.is_used()) {
    ca_.Bind(&block283, &phi_bb283_16, &phi_bb283_17, &phi_bb283_18, &phi_bb283_26, &phi_bb283_27, &phi_bb283_28, &phi_bb283_29, &phi_bb283_30, &phi_bb283_33, &phi_bb283_34, &phi_bb283_38);
    tmp571 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb283_16, phi_bb283_17, phi_bb283_18, tmp563, tmp571);
  }

  TNode<JSAny> phi_bb284_16;
  TNode<IntPtrT> phi_bb284_17;
  TNode<BoolT> phi_bb284_18;
  TNode<IntPtrT> phi_bb284_26;
  TNode<IntPtrT> phi_bb284_27;
  TNode<IntPtrT> phi_bb284_28;
  TNode<IntPtrT> phi_bb284_29;
  TNode<IntPtrT> phi_bb284_30;
  TNode<IntPtrT> phi_bb284_33;
  TNode<BoolT> phi_bb284_34;
  TNode<Int32T> phi_bb284_38;
  TNode<Int32T> phi_bb284_47;
  TNode<Union<Hole, JSMessageObject>> tmp572;
  if (block284.is_used()) {
    ca_.Bind(&block284, &phi_bb284_16, &phi_bb284_17, &phi_bb284_18, &phi_bb284_26, &phi_bb284_27, &phi_bb284_28, &phi_bb284_29, &phi_bb284_30, &phi_bb284_33, &phi_bb284_34, &phi_bb284_38, &phi_bb284_47);
    tmp572 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb284_16, phi_bb284_17, phi_bb284_18, tmp566, tmp572);
  }

  TNode<JSAny> phi_bb289_16;
  TNode<IntPtrT> phi_bb289_17;
  TNode<BoolT> phi_bb289_18;
  TNode<IntPtrT> phi_bb289_26;
  TNode<IntPtrT> phi_bb289_27;
  TNode<IntPtrT> phi_bb289_28;
  TNode<IntPtrT> phi_bb289_29;
  TNode<IntPtrT> phi_bb289_30;
  TNode<IntPtrT> phi_bb289_33;
  TNode<BoolT> phi_bb289_34;
  TNode<Int32T> phi_bb289_38;
  TNode<IntPtrT> tmp573;
  TNode<IntPtrT> tmp574;
  TNode<Union<HeapObject, TaggedIndex>> tmp575;
  TNode<IntPtrT> tmp576;
  TNode<Object> tmp577;
      TNode<JSAny> tmp579;
  if (block289.is_used()) {
    ca_.Bind(&block289, &phi_bb289_16, &phi_bb289_17, &phi_bb289_18, &phi_bb289_26, &phi_bb289_27, &phi_bb289_28, &phi_bb289_29, &phi_bb289_30, &phi_bb289_33, &phi_bb289_34, &phi_bb289_38);
    tmp573 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{tmp564});
    tmp574 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp560}, TNode<IntPtrT>{tmp573});
    std::tie(tmp575, tmp576) = NewReference_Object_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp559}, TNode<IntPtrT>{tmp574}).Flatten();
    compiler::CodeAssemblerExceptionHandlerLabel catch578__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch578__label);
    tmp577 = JSToWasmObject_0(state_, TNode<NativeContext>{p_context}, TNode<Int32T>{tmp249}, TNode<JSAny>{tmp233});
    }
    if (catch578__label.is_used()) {
      compiler::CodeAssemblerLabel catch578_skip(&ca_);
      ca_.Goto(&catch578_skip);
      ca_.Bind(&catch578__label, &tmp579);
      ca_.Goto(&block293, phi_bb289_16, phi_bb289_17, phi_bb289_18, phi_bb289_26, phi_bb289_27, phi_bb289_28, phi_bb289_29, phi_bb289_30, phi_bb289_33, phi_bb289_34, phi_bb289_38);
      ca_.Bind(&catch578_skip);
    }
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp575, tmp576}, tmp577);
    ca_.Goto(&block228, phi_bb289_16, phi_bb289_17, phi_bb289_18, phi_bb289_26, phi_bb289_27, phi_bb289_28, phi_bb289_29, phi_bb289_30, phi_bb289_33, phi_bb289_34, tmp540, phi_bb278_36, phi_bb289_38);
  }

  TNode<JSAny> phi_bb290_16;
  TNode<IntPtrT> phi_bb290_17;
  TNode<BoolT> phi_bb290_18;
  TNode<IntPtrT> phi_bb290_26;
  TNode<IntPtrT> phi_bb290_27;
  TNode<IntPtrT> phi_bb290_28;
  TNode<IntPtrT> phi_bb290_29;
  TNode<IntPtrT> phi_bb290_30;
  TNode<IntPtrT> phi_bb290_33;
  TNode<BoolT> phi_bb290_34;
  TNode<Int32T> phi_bb290_38;
  if (block290.is_used()) {
    ca_.Bind(&block290, &phi_bb290_16, &phi_bb290_17, &phi_bb290_18, &phi_bb290_26, &phi_bb290_27, &phi_bb290_28, &phi_bb290_29, &phi_bb290_30, &phi_bb290_33, &phi_bb290_34, &phi_bb290_38);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<JSAny> phi_bb293_16;
  TNode<IntPtrT> phi_bb293_17;
  TNode<BoolT> phi_bb293_18;
  TNode<IntPtrT> phi_bb293_26;
  TNode<IntPtrT> phi_bb293_27;
  TNode<IntPtrT> phi_bb293_28;
  TNode<IntPtrT> phi_bb293_29;
  TNode<IntPtrT> phi_bb293_30;
  TNode<IntPtrT> phi_bb293_33;
  TNode<BoolT> phi_bb293_34;
  TNode<Int32T> phi_bb293_38;
  TNode<Union<Hole, JSMessageObject>> tmp580;
  if (block293.is_used()) {
    ca_.Bind(&block293, &phi_bb293_16, &phi_bb293_17, &phi_bb293_18, &phi_bb293_26, &phi_bb293_27, &phi_bb293_28, &phi_bb293_29, &phi_bb293_30, &phi_bb293_33, &phi_bb293_34, &phi_bb293_38);
    tmp580 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb293_16, phi_bb293_17, phi_bb293_18, tmp579, tmp580);
  }

  TNode<JSAny> phi_bb228_16;
  TNode<IntPtrT> phi_bb228_17;
  TNode<BoolT> phi_bb228_18;
  TNode<IntPtrT> phi_bb228_26;
  TNode<IntPtrT> phi_bb228_27;
  TNode<IntPtrT> phi_bb228_28;
  TNode<IntPtrT> phi_bb228_29;
  TNode<IntPtrT> phi_bb228_30;
  TNode<IntPtrT> phi_bb228_33;
  TNode<BoolT> phi_bb228_34;
  TNode<BoolT> phi_bb228_35;
  TNode<Union<FixedArray, Smi>> phi_bb228_36;
  TNode<Int32T> phi_bb228_38;
  if (block228.is_used()) {
    ca_.Bind(&block228, &phi_bb228_16, &phi_bb228_17, &phi_bb228_18, &phi_bb228_26, &phi_bb228_27, &phi_bb228_28, &phi_bb228_29, &phi_bb228_30, &phi_bb228_33, &phi_bb228_34, &phi_bb228_35, &phi_bb228_36, &phi_bb228_38);
    ca_.Goto(&block208, phi_bb228_16, phi_bb228_17, phi_bb228_18, phi_bb228_26, phi_bb228_27, phi_bb228_28, phi_bb228_29, phi_bb228_30, phi_bb228_33, phi_bb228_34, phi_bb228_35, phi_bb228_36, phi_bb228_38);
  }

  TNode<JSAny> phi_bb208_16;
  TNode<IntPtrT> phi_bb208_17;
  TNode<BoolT> phi_bb208_18;
  TNode<IntPtrT> phi_bb208_26;
  TNode<IntPtrT> phi_bb208_27;
  TNode<IntPtrT> phi_bb208_28;
  TNode<IntPtrT> phi_bb208_29;
  TNode<IntPtrT> phi_bb208_30;
  TNode<IntPtrT> phi_bb208_33;
  TNode<BoolT> phi_bb208_34;
  TNode<BoolT> phi_bb208_35;
  TNode<Union<FixedArray, Smi>> phi_bb208_36;
  TNode<Int32T> phi_bb208_38;
  if (block208.is_used()) {
    ca_.Bind(&block208, &phi_bb208_16, &phi_bb208_17, &phi_bb208_18, &phi_bb208_26, &phi_bb208_27, &phi_bb208_28, &phi_bb208_29, &phi_bb208_30, &phi_bb208_33, &phi_bb208_34, &phi_bb208_35, &phi_bb208_36, &phi_bb208_38);
    ca_.Goto(&block187, phi_bb208_16, phi_bb208_17, phi_bb208_18, phi_bb208_26, phi_bb208_27, phi_bb208_28, phi_bb208_29, phi_bb208_30, phi_bb208_33, phi_bb208_34, phi_bb208_35, phi_bb208_36, phi_bb208_38);
  }

  TNode<JSAny> phi_bb187_16;
  TNode<IntPtrT> phi_bb187_17;
  TNode<BoolT> phi_bb187_18;
  TNode<IntPtrT> phi_bb187_26;
  TNode<IntPtrT> phi_bb187_27;
  TNode<IntPtrT> phi_bb187_28;
  TNode<IntPtrT> phi_bb187_29;
  TNode<IntPtrT> phi_bb187_30;
  TNode<IntPtrT> phi_bb187_33;
  TNode<BoolT> phi_bb187_34;
  TNode<BoolT> phi_bb187_35;
  TNode<Union<FixedArray, Smi>> phi_bb187_36;
  TNode<Int32T> phi_bb187_38;
  if (block187.is_used()) {
    ca_.Bind(&block187, &phi_bb187_16, &phi_bb187_17, &phi_bb187_18, &phi_bb187_26, &phi_bb187_27, &phi_bb187_28, &phi_bb187_29, &phi_bb187_30, &phi_bb187_33, &phi_bb187_34, &phi_bb187_35, &phi_bb187_36, &phi_bb187_38);
    ca_.Goto(&block164, phi_bb187_16, phi_bb187_17, phi_bb187_18, phi_bb187_26, phi_bb187_27, phi_bb187_28, phi_bb187_29, phi_bb187_30, phi_bb187_33, phi_bb187_34, phi_bb187_35, phi_bb187_36, phi_bb187_38);
  }

  TNode<JSAny> phi_bb164_16;
  TNode<IntPtrT> phi_bb164_17;
  TNode<BoolT> phi_bb164_18;
  TNode<IntPtrT> phi_bb164_26;
  TNode<IntPtrT> phi_bb164_27;
  TNode<IntPtrT> phi_bb164_28;
  TNode<IntPtrT> phi_bb164_29;
  TNode<IntPtrT> phi_bb164_30;
  TNode<IntPtrT> phi_bb164_33;
  TNode<BoolT> phi_bb164_34;
  TNode<BoolT> phi_bb164_35;
  TNode<Union<FixedArray, Smi>> phi_bb164_36;
  TNode<Int32T> phi_bb164_38;
  TNode<Int32T> tmp581;
      TNode<JSAny> tmp583;
  TNode<Int32T> tmp584;
      TNode<JSAny> tmp586;
  if (block164.is_used()) {
    ca_.Bind(&block164, &phi_bb164_16, &phi_bb164_17, &phi_bb164_18, &phi_bb164_26, &phi_bb164_27, &phi_bb164_28, &phi_bb164_29, &phi_bb164_30, &phi_bb164_33, &phi_bb164_34, &phi_bb164_35, &phi_bb164_36, &phi_bb164_38);
    compiler::CodeAssemblerExceptionHandlerLabel catch582__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch582__label);
    tmp581 = FromConstexpr_int32_constexpr_int31_0(state_, 1);
    }
    if (catch582__label.is_used()) {
      compiler::CodeAssemblerLabel catch582_skip(&ca_);
      ca_.Goto(&catch582_skip);
      ca_.Bind(&catch582__label, &tmp583);
      ca_.Goto(&block294, phi_bb164_16, phi_bb164_17, phi_bb164_18, phi_bb164_26, phi_bb164_27, phi_bb164_28, phi_bb164_29, phi_bb164_30, phi_bb164_33, phi_bb164_34, phi_bb164_35, phi_bb164_36, phi_bb164_38, phi_bb164_38, phi_bb164_38);
      ca_.Bind(&catch582_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch585__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch585__label);
    tmp584 = CodeStubAssembler(state_).Int32Add(TNode<Int32T>{phi_bb164_38}, TNode<Int32T>{tmp581});
    }
    if (catch585__label.is_used()) {
      compiler::CodeAssemblerLabel catch585_skip(&ca_);
      ca_.Goto(&catch585_skip);
      ca_.Bind(&catch585__label, &tmp586);
      ca_.Goto(&block295, phi_bb164_16, phi_bb164_17, phi_bb164_18, phi_bb164_26, phi_bb164_27, phi_bb164_28, phi_bb164_29, phi_bb164_30, phi_bb164_33, phi_bb164_34, phi_bb164_35, phi_bb164_36, phi_bb164_38, phi_bb164_38);
      ca_.Bind(&catch585_skip);
    }
    ca_.Goto(&block151, phi_bb164_16, phi_bb164_17, phi_bb164_18, phi_bb164_26, phi_bb164_27, phi_bb164_28, phi_bb164_29, phi_bb164_30, phi_bb164_33, phi_bb164_34, phi_bb164_35, phi_bb164_36, tmp239, tmp584);
  }

  TNode<JSAny> phi_bb294_16;
  TNode<IntPtrT> phi_bb294_17;
  TNode<BoolT> phi_bb294_18;
  TNode<IntPtrT> phi_bb294_26;
  TNode<IntPtrT> phi_bb294_27;
  TNode<IntPtrT> phi_bb294_28;
  TNode<IntPtrT> phi_bb294_29;
  TNode<IntPtrT> phi_bb294_30;
  TNode<IntPtrT> phi_bb294_33;
  TNode<BoolT> phi_bb294_34;
  TNode<BoolT> phi_bb294_35;
  TNode<Union<FixedArray, Smi>> phi_bb294_36;
  TNode<Int32T> phi_bb294_38;
  TNode<Int32T> phi_bb294_39;
  TNode<Int32T> phi_bb294_40;
  TNode<Union<Hole, JSMessageObject>> tmp587;
  if (block294.is_used()) {
    ca_.Bind(&block294, &phi_bb294_16, &phi_bb294_17, &phi_bb294_18, &phi_bb294_26, &phi_bb294_27, &phi_bb294_28, &phi_bb294_29, &phi_bb294_30, &phi_bb294_33, &phi_bb294_34, &phi_bb294_35, &phi_bb294_36, &phi_bb294_38, &phi_bb294_39, &phi_bb294_40);
    tmp587 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb294_16, phi_bb294_17, phi_bb294_18, tmp583, tmp587);
  }

  TNode<JSAny> phi_bb295_16;
  TNode<IntPtrT> phi_bb295_17;
  TNode<BoolT> phi_bb295_18;
  TNode<IntPtrT> phi_bb295_26;
  TNode<IntPtrT> phi_bb295_27;
  TNode<IntPtrT> phi_bb295_28;
  TNode<IntPtrT> phi_bb295_29;
  TNode<IntPtrT> phi_bb295_30;
  TNode<IntPtrT> phi_bb295_33;
  TNode<BoolT> phi_bb295_34;
  TNode<BoolT> phi_bb295_35;
  TNode<Union<FixedArray, Smi>> phi_bb295_36;
  TNode<Int32T> phi_bb295_38;
  TNode<Int32T> phi_bb295_39;
  TNode<Union<Hole, JSMessageObject>> tmp588;
  if (block295.is_used()) {
    ca_.Bind(&block295, &phi_bb295_16, &phi_bb295_17, &phi_bb295_18, &phi_bb295_26, &phi_bb295_27, &phi_bb295_28, &phi_bb295_29, &phi_bb295_30, &phi_bb295_33, &phi_bb295_34, &phi_bb295_35, &phi_bb295_36, &phi_bb295_38, &phi_bb295_39);
    tmp588 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb295_16, phi_bb295_17, phi_bb295_18, tmp586, tmp588);
  }

  TNode<JSAny> phi_bb150_16;
  TNode<IntPtrT> phi_bb150_17;
  TNode<BoolT> phi_bb150_18;
  TNode<IntPtrT> phi_bb150_26;
  TNode<IntPtrT> phi_bb150_27;
  TNode<IntPtrT> phi_bb150_28;
  TNode<IntPtrT> phi_bb150_29;
  TNode<IntPtrT> phi_bb150_30;
  TNode<IntPtrT> phi_bb150_33;
  TNode<BoolT> phi_bb150_34;
  TNode<BoolT> phi_bb150_35;
  TNode<Union<FixedArray, Smi>> phi_bb150_36;
  TNode<Int32T> phi_bb150_37;
  TNode<Int32T> phi_bb150_38;
  TNode<Undefined> tmp589;
  if (block150.is_used()) {
    ca_.Bind(&block150, &phi_bb150_16, &phi_bb150_17, &phi_bb150_18, &phi_bb150_26, &phi_bb150_27, &phi_bb150_28, &phi_bb150_29, &phi_bb150_30, &phi_bb150_33, &phi_bb150_34, &phi_bb150_35, &phi_bb150_36, &phi_bb150_37, &phi_bb150_38);
    tmp589 = Undefined_0(state_);
    if ((((CodeStubAssembler(state_).ConstexprInt32Equal(p_promise, wasm::Promise::kPromise)) || (CodeStubAssembler(state_).ConstexprInt32Equal(p_promise, wasm::Promise::kStressSwitch))))) {
      ca_.Goto(&block296, phi_bb150_16, phi_bb150_17, phi_bb150_18, phi_bb150_26, phi_bb150_27, phi_bb150_28, phi_bb150_29, phi_bb150_30, phi_bb150_33, phi_bb150_34, phi_bb150_35, phi_bb150_36, phi_bb150_37);
    } else {
      ca_.Goto(&block297, phi_bb150_16, phi_bb150_17, phi_bb150_18, phi_bb150_26, phi_bb150_27, phi_bb150_28, phi_bb150_29, phi_bb150_30, phi_bb150_33, phi_bb150_34, phi_bb150_35, phi_bb150_36, phi_bb150_37);
    }
  }

  TNode<JSAny> phi_bb296_16;
  TNode<IntPtrT> phi_bb296_17;
  TNode<BoolT> phi_bb296_18;
  TNode<IntPtrT> phi_bb296_26;
  TNode<IntPtrT> phi_bb296_27;
  TNode<IntPtrT> phi_bb296_28;
  TNode<IntPtrT> phi_bb296_29;
  TNode<IntPtrT> phi_bb296_30;
  TNode<IntPtrT> phi_bb296_33;
  TNode<BoolT> phi_bb296_34;
  TNode<BoolT> phi_bb296_35;
  TNode<Union<FixedArray, Smi>> phi_bb296_36;
  TNode<Int32T> phi_bb296_37;
  TNode<JSAny> tmp590;
      TNode<JSAny> tmp592;
  TNode<BoolT> tmp593;
      TNode<JSAny> tmp595;
  if (block296.is_used()) {
    ca_.Bind(&block296, &phi_bb296_16, &phi_bb296_17, &phi_bb296_18, &phi_bb296_26, &phi_bb296_27, &phi_bb296_28, &phi_bb296_29, &phi_bb296_30, &phi_bb296_33, &phi_bb296_34, &phi_bb296_35, &phi_bb296_36, &phi_bb296_37);
    compiler::CodeAssemblerExceptionHandlerLabel catch591__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch591__label);
    tmp590 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kWasmAllocateSuspender, p_context)); 
    }
    if (catch591__label.is_used()) {
      compiler::CodeAssemblerLabel catch591_skip(&ca_);
      ca_.Goto(&catch591_skip);
      ca_.Bind(&catch591__label, &tmp592);
      ca_.Goto(&block299, phi_bb296_16, phi_bb296_17, phi_bb296_18, phi_bb296_26, phi_bb296_27, phi_bb296_28, phi_bb296_29, phi_bb296_30, phi_bb296_33, phi_bb296_34, phi_bb296_35, phi_bb296_36, phi_bb296_37);
      ca_.Bind(&catch591_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch594__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch594__label);
    tmp593 = FromConstexpr_bool_constexpr_bool_0(state_, (CodeStubAssembler(state_).ConstexprInt32Equal(p_promise, wasm::Promise::kStressSwitch)));
    }
    if (catch594__label.is_used()) {
      compiler::CodeAssemblerLabel catch594_skip(&ca_);
      ca_.Goto(&catch594_skip);
      ca_.Bind(&catch594__label, &tmp595);
      ca_.Goto(&block302, phi_bb296_16, phi_bb296_17, phi_bb296_18, phi_bb296_26, phi_bb296_27, phi_bb296_28, phi_bb296_29, phi_bb296_30, phi_bb296_33, phi_bb296_34, phi_bb296_35, phi_bb296_36, phi_bb296_37);
      ca_.Bind(&catch594_skip);
    }
    ca_.Branch(tmp593, &block300, std::vector<compiler::Node*>{phi_bb296_16, phi_bb296_17, phi_bb296_18, phi_bb296_26, phi_bb296_27, phi_bb296_28, phi_bb296_29, phi_bb296_30, phi_bb296_33, phi_bb296_34, phi_bb296_35, phi_bb296_36, phi_bb296_37}, &block301, std::vector<compiler::Node*>{phi_bb296_16, phi_bb296_17, phi_bb296_18, phi_bb296_26, phi_bb296_27, phi_bb296_28, phi_bb296_29, phi_bb296_30, phi_bb296_33, phi_bb296_34, phi_bb296_35, phi_bb296_36, phi_bb296_37});
  }

  TNode<JSAny> phi_bb299_16;
  TNode<IntPtrT> phi_bb299_17;
  TNode<BoolT> phi_bb299_18;
  TNode<IntPtrT> phi_bb299_26;
  TNode<IntPtrT> phi_bb299_27;
  TNode<IntPtrT> phi_bb299_28;
  TNode<IntPtrT> phi_bb299_29;
  TNode<IntPtrT> phi_bb299_30;
  TNode<IntPtrT> phi_bb299_33;
  TNode<BoolT> phi_bb299_34;
  TNode<BoolT> phi_bb299_35;
  TNode<Union<FixedArray, Smi>> phi_bb299_36;
  TNode<Int32T> phi_bb299_37;
  TNode<Union<Hole, JSMessageObject>> tmp596;
  if (block299.is_used()) {
    ca_.Bind(&block299, &phi_bb299_16, &phi_bb299_17, &phi_bb299_18, &phi_bb299_26, &phi_bb299_27, &phi_bb299_28, &phi_bb299_29, &phi_bb299_30, &phi_bb299_33, &phi_bb299_34, &phi_bb299_35, &phi_bb299_36, &phi_bb299_37);
    tmp596 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb299_16, phi_bb299_17, phi_bb299_18, tmp592, tmp596);
  }

  TNode<JSAny> phi_bb302_16;
  TNode<IntPtrT> phi_bb302_17;
  TNode<BoolT> phi_bb302_18;
  TNode<IntPtrT> phi_bb302_26;
  TNode<IntPtrT> phi_bb302_27;
  TNode<IntPtrT> phi_bb302_28;
  TNode<IntPtrT> phi_bb302_29;
  TNode<IntPtrT> phi_bb302_30;
  TNode<IntPtrT> phi_bb302_33;
  TNode<BoolT> phi_bb302_34;
  TNode<BoolT> phi_bb302_35;
  TNode<Union<FixedArray, Smi>> phi_bb302_36;
  TNode<Int32T> phi_bb302_37;
  TNode<Union<Hole, JSMessageObject>> tmp597;
  if (block302.is_used()) {
    ca_.Bind(&block302, &phi_bb302_16, &phi_bb302_17, &phi_bb302_18, &phi_bb302_26, &phi_bb302_27, &phi_bb302_28, &phi_bb302_29, &phi_bb302_30, &phi_bb302_33, &phi_bb302_34, &phi_bb302_35, &phi_bb302_36, &phi_bb302_37);
    tmp597 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb302_16, phi_bb302_17, phi_bb302_18, tmp595, tmp597);
  }

  TNode<JSAny> phi_bb300_16;
  TNode<IntPtrT> phi_bb300_17;
  TNode<BoolT> phi_bb300_18;
  TNode<IntPtrT> phi_bb300_26;
  TNode<IntPtrT> phi_bb300_27;
  TNode<IntPtrT> phi_bb300_28;
  TNode<IntPtrT> phi_bb300_29;
  TNode<IntPtrT> phi_bb300_30;
  TNode<IntPtrT> phi_bb300_33;
  TNode<BoolT> phi_bb300_34;
  TNode<BoolT> phi_bb300_35;
  TNode<Union<FixedArray, Smi>> phi_bb300_36;
  TNode<Int32T> phi_bb300_37;
  TNode<WasmSuspenderObject> tmp598;
      TNode<JSAny> tmp600;
  TNode<IntPtrT> tmp601;
      TNode<JSAny> tmp603;
  TNode<Undefined> tmp604;
  if (block300.is_used()) {
    ca_.Bind(&block300, &phi_bb300_16, &phi_bb300_17, &phi_bb300_18, &phi_bb300_26, &phi_bb300_27, &phi_bb300_28, &phi_bb300_29, &phi_bb300_30, &phi_bb300_33, &phi_bb300_34, &phi_bb300_35, &phi_bb300_36, &phi_bb300_37);
    compiler::CodeAssemblerExceptionHandlerLabel catch599__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch599__label);
    tmp598 = UnsafeCast_WasmSuspenderObject_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp590});
    }
    if (catch599__label.is_used()) {
      compiler::CodeAssemblerLabel catch599_skip(&ca_);
      ca_.Goto(&catch599_skip);
      ca_.Bind(&catch599__label, &tmp600);
      ca_.Goto(&block303, phi_bb300_16, phi_bb300_17, phi_bb300_18, phi_bb300_26, phi_bb300_27, phi_bb300_28, phi_bb300_29, phi_bb300_30, phi_bb300_33, phi_bb300_34, phi_bb300_35, phi_bb300_36, phi_bb300_37);
      ca_.Bind(&catch599_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch602__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch602__label);
    tmp601 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    }
    if (catch602__label.is_used()) {
      compiler::CodeAssemblerLabel catch602_skip(&ca_);
      ca_.Goto(&catch602_skip);
      ca_.Bind(&catch602__label, &tmp603);
      ca_.Goto(&block304, phi_bb300_16, phi_bb300_17, phi_bb300_18, phi_bb300_26, phi_bb300_27, phi_bb300_28, phi_bb300_29, phi_bb300_30, phi_bb300_33, phi_bb300_34, phi_bb300_35, phi_bb300_36, phi_bb300_37);
      ca_.Bind(&catch602_skip);
    }
    tmp604 = Undefined_0(state_);
    CodeStubAssembler(state_).StoreReference<Union<JSObject, Undefined>>(CodeStubAssembler::Reference{tmp598, tmp601}, tmp604);
    ca_.Goto(&block301, phi_bb300_16, phi_bb300_17, phi_bb300_18, phi_bb300_26, phi_bb300_27, phi_bb300_28, phi_bb300_29, phi_bb300_30, phi_bb300_33, phi_bb300_34, phi_bb300_35, phi_bb300_36, phi_bb300_37);
  }

  TNode<JSAny> phi_bb303_16;
  TNode<IntPtrT> phi_bb303_17;
  TNode<BoolT> phi_bb303_18;
  TNode<IntPtrT> phi_bb303_26;
  TNode<IntPtrT> phi_bb303_27;
  TNode<IntPtrT> phi_bb303_28;
  TNode<IntPtrT> phi_bb303_29;
  TNode<IntPtrT> phi_bb303_30;
  TNode<IntPtrT> phi_bb303_33;
  TNode<BoolT> phi_bb303_34;
  TNode<BoolT> phi_bb303_35;
  TNode<Union<FixedArray, Smi>> phi_bb303_36;
  TNode<Int32T> phi_bb303_37;
  TNode<Union<Hole, JSMessageObject>> tmp605;
  if (block303.is_used()) {
    ca_.Bind(&block303, &phi_bb303_16, &phi_bb303_17, &phi_bb303_18, &phi_bb303_26, &phi_bb303_27, &phi_bb303_28, &phi_bb303_29, &phi_bb303_30, &phi_bb303_33, &phi_bb303_34, &phi_bb303_35, &phi_bb303_36, &phi_bb303_37);
    tmp605 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb303_16, phi_bb303_17, phi_bb303_18, tmp600, tmp605);
  }

  TNode<JSAny> phi_bb304_16;
  TNode<IntPtrT> phi_bb304_17;
  TNode<BoolT> phi_bb304_18;
  TNode<IntPtrT> phi_bb304_26;
  TNode<IntPtrT> phi_bb304_27;
  TNode<IntPtrT> phi_bb304_28;
  TNode<IntPtrT> phi_bb304_29;
  TNode<IntPtrT> phi_bb304_30;
  TNode<IntPtrT> phi_bb304_33;
  TNode<BoolT> phi_bb304_34;
  TNode<BoolT> phi_bb304_35;
  TNode<Union<FixedArray, Smi>> phi_bb304_36;
  TNode<Int32T> phi_bb304_37;
  TNode<Union<Hole, JSMessageObject>> tmp606;
  if (block304.is_used()) {
    ca_.Bind(&block304, &phi_bb304_16, &phi_bb304_17, &phi_bb304_18, &phi_bb304_26, &phi_bb304_27, &phi_bb304_28, &phi_bb304_29, &phi_bb304_30, &phi_bb304_33, &phi_bb304_34, &phi_bb304_35, &phi_bb304_36, &phi_bb304_37);
    tmp606 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb304_16, phi_bb304_17, phi_bb304_18, tmp603, tmp606);
  }

  TNode<JSAny> phi_bb301_16;
  TNode<IntPtrT> phi_bb301_17;
  TNode<BoolT> phi_bb301_18;
  TNode<IntPtrT> phi_bb301_26;
  TNode<IntPtrT> phi_bb301_27;
  TNode<IntPtrT> phi_bb301_28;
  TNode<IntPtrT> phi_bb301_29;
  TNode<IntPtrT> phi_bb301_30;
  TNode<IntPtrT> phi_bb301_33;
  TNode<BoolT> phi_bb301_34;
  TNode<BoolT> phi_bb301_35;
  TNode<Union<FixedArray, Smi>> phi_bb301_36;
  TNode<Int32T> phi_bb301_37;
  if (block301.is_used()) {
    ca_.Bind(&block301, &phi_bb301_16, &phi_bb301_17, &phi_bb301_18, &phi_bb301_26, &phi_bb301_27, &phi_bb301_28, &phi_bb301_29, &phi_bb301_30, &phi_bb301_33, &phi_bb301_34, &phi_bb301_35, &phi_bb301_36, &phi_bb301_37);
    ca_.Goto(&block298, phi_bb301_16, phi_bb301_17, phi_bb301_18, phi_bb301_26, phi_bb301_27, phi_bb301_28, phi_bb301_29, phi_bb301_30, phi_bb301_33, phi_bb301_34, phi_bb301_35, phi_bb301_36, phi_bb301_37, tmp590);
  }

  TNode<JSAny> phi_bb297_16;
  TNode<IntPtrT> phi_bb297_17;
  TNode<BoolT> phi_bb297_18;
  TNode<IntPtrT> phi_bb297_26;
  TNode<IntPtrT> phi_bb297_27;
  TNode<IntPtrT> phi_bb297_28;
  TNode<IntPtrT> phi_bb297_29;
  TNode<IntPtrT> phi_bb297_30;
  TNode<IntPtrT> phi_bb297_33;
  TNode<BoolT> phi_bb297_34;
  TNode<BoolT> phi_bb297_35;
  TNode<Union<FixedArray, Smi>> phi_bb297_36;
  TNode<Int32T> phi_bb297_37;
  if (block297.is_used()) {
    ca_.Bind(&block297, &phi_bb297_16, &phi_bb297_17, &phi_bb297_18, &phi_bb297_26, &phi_bb297_27, &phi_bb297_28, &phi_bb297_29, &phi_bb297_30, &phi_bb297_33, &phi_bb297_34, &phi_bb297_35, &phi_bb297_36, &phi_bb297_37);
    ca_.Goto(&block298, phi_bb297_16, phi_bb297_17, phi_bb297_18, phi_bb297_26, phi_bb297_27, phi_bb297_28, phi_bb297_29, phi_bb297_30, phi_bb297_33, phi_bb297_34, phi_bb297_35, phi_bb297_36, phi_bb297_37, tmp589);
  }

  TNode<JSAny> phi_bb298_16;
  TNode<IntPtrT> phi_bb298_17;
  TNode<BoolT> phi_bb298_18;
  TNode<IntPtrT> phi_bb298_26;
  TNode<IntPtrT> phi_bb298_27;
  TNode<IntPtrT> phi_bb298_28;
  TNode<IntPtrT> phi_bb298_29;
  TNode<IntPtrT> phi_bb298_30;
  TNode<IntPtrT> phi_bb298_33;
  TNode<BoolT> phi_bb298_34;
  TNode<BoolT> phi_bb298_35;
  TNode<Union<FixedArray, Smi>> phi_bb298_36;
  TNode<Int32T> phi_bb298_37;
  TNode<JSAny> phi_bb298_38;
  if (block298.is_used()) {
    ca_.Bind(&block298, &phi_bb298_16, &phi_bb298_17, &phi_bb298_18, &phi_bb298_26, &phi_bb298_27, &phi_bb298_28, &phi_bb298_29, &phi_bb298_30, &phi_bb298_33, &phi_bb298_34, &phi_bb298_35, &phi_bb298_36, &phi_bb298_37, &phi_bb298_38);
    ca_.Branch(phi_bb298_35, &block305, std::vector<compiler::Node*>{phi_bb298_16, phi_bb298_17, phi_bb298_18, phi_bb298_26, phi_bb298_27, phi_bb298_28, phi_bb298_29, phi_bb298_30, phi_bb298_33, phi_bb298_34, phi_bb298_35, phi_bb298_36, phi_bb298_37}, &block306, std::vector<compiler::Node*>{phi_bb298_16, phi_bb298_17, phi_bb298_18, phi_bb298_26, phi_bb298_27, phi_bb298_28, phi_bb298_29, phi_bb298_30, phi_bb298_33, phi_bb298_34, phi_bb298_35, phi_bb298_36, phi_bb298_37});
  }

  TNode<JSAny> phi_bb305_16;
  TNode<IntPtrT> phi_bb305_17;
  TNode<BoolT> phi_bb305_18;
  TNode<IntPtrT> phi_bb305_26;
  TNode<IntPtrT> phi_bb305_27;
  TNode<IntPtrT> phi_bb305_28;
  TNode<IntPtrT> phi_bb305_29;
  TNode<IntPtrT> phi_bb305_30;
  TNode<IntPtrT> phi_bb305_33;
  TNode<BoolT> phi_bb305_34;
  TNode<BoolT> phi_bb305_35;
  TNode<Union<FixedArray, Smi>> phi_bb305_36;
  TNode<Int32T> phi_bb305_37;
  TNode<Int32T> tmp607;
      TNode<JSAny> tmp609;
  TNode<Int32T> tmp610;
      TNode<JSAny> tmp612;
  TNode<BoolT> tmp613;
  if (block305.is_used()) {
    ca_.Bind(&block305, &phi_bb305_16, &phi_bb305_17, &phi_bb305_18, &phi_bb305_26, &phi_bb305_27, &phi_bb305_28, &phi_bb305_29, &phi_bb305_30, &phi_bb305_33, &phi_bb305_34, &phi_bb305_35, &phi_bb305_36, &phi_bb305_37);
    compiler::CodeAssemblerExceptionHandlerLabel catch608__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch608__label);
    tmp607 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    }
    if (catch608__label.is_used()) {
      compiler::CodeAssemblerLabel catch608_skip(&ca_);
      ca_.Goto(&catch608_skip);
      ca_.Bind(&catch608__label, &tmp609);
      ca_.Goto(&block307, phi_bb305_16, phi_bb305_17, phi_bb305_18, phi_bb305_26, phi_bb305_27, phi_bb305_28, phi_bb305_29, phi_bb305_30, phi_bb305_33, phi_bb305_34, phi_bb305_35, phi_bb305_36, phi_bb305_37);
      ca_.Bind(&catch608_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch611__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch611__label);
    tmp610 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    }
    if (catch611__label.is_used()) {
      compiler::CodeAssemblerLabel catch611_skip(&ca_);
      ca_.Goto(&catch611_skip);
      ca_.Bind(&catch611__label, &tmp612);
      ca_.Goto(&block308, phi_bb305_16, phi_bb305_17, phi_bb305_18, phi_bb305_26, phi_bb305_27, phi_bb305_28, phi_bb305_29, phi_bb305_30, phi_bb305_33, phi_bb305_34, phi_bb305_35, phi_bb305_36, phi_bb305_37);
      ca_.Bind(&catch611_skip);
    }
    tmp613 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{phi_bb305_34});
    ca_.Branch(tmp613, &block310, std::vector<compiler::Node*>{phi_bb305_16, phi_bb305_17, phi_bb305_18, phi_bb305_26, phi_bb305_27, phi_bb305_28, phi_bb305_29, phi_bb305_30, phi_bb305_33, phi_bb305_34, phi_bb305_35, phi_bb305_36, phi_bb305_37}, &block311, std::vector<compiler::Node*>{phi_bb305_16, phi_bb305_17, phi_bb305_18, phi_bb305_26, phi_bb305_27, phi_bb305_28, phi_bb305_29, phi_bb305_30, phi_bb305_33, phi_bb305_34, phi_bb305_35, phi_bb305_36, phi_bb305_37});
  }

  TNode<JSAny> phi_bb307_16;
  TNode<IntPtrT> phi_bb307_17;
  TNode<BoolT> phi_bb307_18;
  TNode<IntPtrT> phi_bb307_26;
  TNode<IntPtrT> phi_bb307_27;
  TNode<IntPtrT> phi_bb307_28;
  TNode<IntPtrT> phi_bb307_29;
  TNode<IntPtrT> phi_bb307_30;
  TNode<IntPtrT> phi_bb307_33;
  TNode<BoolT> phi_bb307_34;
  TNode<BoolT> phi_bb307_35;
  TNode<Union<FixedArray, Smi>> phi_bb307_36;
  TNode<Int32T> phi_bb307_37;
  TNode<Union<Hole, JSMessageObject>> tmp614;
  if (block307.is_used()) {
    ca_.Bind(&block307, &phi_bb307_16, &phi_bb307_17, &phi_bb307_18, &phi_bb307_26, &phi_bb307_27, &phi_bb307_28, &phi_bb307_29, &phi_bb307_30, &phi_bb307_33, &phi_bb307_34, &phi_bb307_35, &phi_bb307_36, &phi_bb307_37);
    tmp614 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb307_16, phi_bb307_17, phi_bb307_18, tmp609, tmp614);
  }

  TNode<JSAny> phi_bb308_16;
  TNode<IntPtrT> phi_bb308_17;
  TNode<BoolT> phi_bb308_18;
  TNode<IntPtrT> phi_bb308_26;
  TNode<IntPtrT> phi_bb308_27;
  TNode<IntPtrT> phi_bb308_28;
  TNode<IntPtrT> phi_bb308_29;
  TNode<IntPtrT> phi_bb308_30;
  TNode<IntPtrT> phi_bb308_33;
  TNode<BoolT> phi_bb308_34;
  TNode<BoolT> phi_bb308_35;
  TNode<Union<FixedArray, Smi>> phi_bb308_36;
  TNode<Int32T> phi_bb308_37;
  TNode<Union<Hole, JSMessageObject>> tmp615;
  if (block308.is_used()) {
    ca_.Bind(&block308, &phi_bb308_16, &phi_bb308_17, &phi_bb308_18, &phi_bb308_26, &phi_bb308_27, &phi_bb308_28, &phi_bb308_29, &phi_bb308_30, &phi_bb308_33, &phi_bb308_34, &phi_bb308_35, &phi_bb308_36, &phi_bb308_37);
    tmp615 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb308_16, phi_bb308_17, phi_bb308_18, tmp612, tmp615);
  }

  TNode<JSAny> phi_bb310_16;
  TNode<IntPtrT> phi_bb310_17;
  TNode<BoolT> phi_bb310_18;
  TNode<IntPtrT> phi_bb310_26;
  TNode<IntPtrT> phi_bb310_27;
  TNode<IntPtrT> phi_bb310_28;
  TNode<IntPtrT> phi_bb310_29;
  TNode<IntPtrT> phi_bb310_30;
  TNode<IntPtrT> phi_bb310_33;
  TNode<BoolT> phi_bb310_34;
  TNode<BoolT> phi_bb310_35;
  TNode<Union<FixedArray, Smi>> phi_bb310_36;
  TNode<Int32T> phi_bb310_37;
  TNode<IntPtrT> tmp616;
  if (block310.is_used()) {
    ca_.Bind(&block310, &phi_bb310_16, &phi_bb310_17, &phi_bb310_18, &phi_bb310_26, &phi_bb310_27, &phi_bb310_28, &phi_bb310_29, &phi_bb310_30, &phi_bb310_33, &phi_bb310_34, &phi_bb310_35, &phi_bb310_36, &phi_bb310_37);
    tmp616 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.Goto(&block311, phi_bb310_16, phi_bb310_17, phi_bb310_18, phi_bb310_26, phi_bb310_27, phi_bb310_28, phi_bb310_29, phi_bb310_30, tmp616, phi_bb310_34, phi_bb310_35, phi_bb310_36, phi_bb310_37);
  }

  TNode<JSAny> phi_bb311_16;
  TNode<IntPtrT> phi_bb311_17;
  TNode<BoolT> phi_bb311_18;
  TNode<IntPtrT> phi_bb311_26;
  TNode<IntPtrT> phi_bb311_27;
  TNode<IntPtrT> phi_bb311_28;
  TNode<IntPtrT> phi_bb311_29;
  TNode<IntPtrT> phi_bb311_30;
  TNode<IntPtrT> phi_bb311_33;
  TNode<BoolT> phi_bb311_34;
  TNode<BoolT> phi_bb311_35;
  TNode<Union<FixedArray, Smi>> phi_bb311_36;
  TNode<Int32T> phi_bb311_37;
  if (block311.is_used()) {
    ca_.Bind(&block311, &phi_bb311_16, &phi_bb311_17, &phi_bb311_18, &phi_bb311_26, &phi_bb311_27, &phi_bb311_28, &phi_bb311_29, &phi_bb311_30, &phi_bb311_33, &phi_bb311_34, &phi_bb311_35, &phi_bb311_36, &phi_bb311_37);
    ca_.Goto(&block314, phi_bb311_16, phi_bb311_17, phi_bb311_18, phi_bb311_26, phi_bb311_27, phi_bb311_28, phi_bb311_29, phi_bb311_30, phi_bb311_33, phi_bb311_34, phi_bb311_35, phi_bb311_36, phi_bb311_37, tmp607, tmp610);
  }

  TNode<JSAny> phi_bb314_16;
  TNode<IntPtrT> phi_bb314_17;
  TNode<BoolT> phi_bb314_18;
  TNode<IntPtrT> phi_bb314_26;
  TNode<IntPtrT> phi_bb314_27;
  TNode<IntPtrT> phi_bb314_28;
  TNode<IntPtrT> phi_bb314_29;
  TNode<IntPtrT> phi_bb314_30;
  TNode<IntPtrT> phi_bb314_33;
  TNode<BoolT> phi_bb314_34;
  TNode<BoolT> phi_bb314_35;
  TNode<Union<FixedArray, Smi>> phi_bb314_36;
  TNode<Int32T> phi_bb314_37;
  TNode<Int32T> phi_bb314_39;
  TNode<Int32T> phi_bb314_40;
  TNode<BoolT> tmp617;
      TNode<JSAny> tmp619;
  if (block314.is_used()) {
    ca_.Bind(&block314, &phi_bb314_16, &phi_bb314_17, &phi_bb314_18, &phi_bb314_26, &phi_bb314_27, &phi_bb314_28, &phi_bb314_29, &phi_bb314_30, &phi_bb314_33, &phi_bb314_34, &phi_bb314_35, &phi_bb314_36, &phi_bb314_37, &phi_bb314_39, &phi_bb314_40);
    compiler::CodeAssemblerExceptionHandlerLabel catch618__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch618__label);
    tmp617 = CodeStubAssembler(state_).Int32LessThan(TNode<Int32T>{phi_bb314_39}, TNode<Int32T>{tmp25});
    }
    if (catch618__label.is_used()) {
      compiler::CodeAssemblerLabel catch618_skip(&ca_);
      ca_.Goto(&catch618_skip);
      ca_.Bind(&catch618__label, &tmp619);
      ca_.Goto(&block315, phi_bb314_16, phi_bb314_17, phi_bb314_18, phi_bb314_26, phi_bb314_27, phi_bb314_28, phi_bb314_29, phi_bb314_30, phi_bb314_33, phi_bb314_34, phi_bb314_35, phi_bb314_36, phi_bb314_37, phi_bb314_39, phi_bb314_40, phi_bb314_39);
      ca_.Bind(&catch618_skip);
    }
    ca_.Branch(tmp617, &block312, std::vector<compiler::Node*>{phi_bb314_16, phi_bb314_17, phi_bb314_18, phi_bb314_26, phi_bb314_27, phi_bb314_28, phi_bb314_29, phi_bb314_30, phi_bb314_33, phi_bb314_34, phi_bb314_35, phi_bb314_36, phi_bb314_37, phi_bb314_39, phi_bb314_40}, &block313, std::vector<compiler::Node*>{phi_bb314_16, phi_bb314_17, phi_bb314_18, phi_bb314_26, phi_bb314_27, phi_bb314_28, phi_bb314_29, phi_bb314_30, phi_bb314_33, phi_bb314_34, phi_bb314_35, phi_bb314_36, phi_bb314_37, phi_bb314_39, phi_bb314_40});
  }

  TNode<JSAny> phi_bb315_16;
  TNode<IntPtrT> phi_bb315_17;
  TNode<BoolT> phi_bb315_18;
  TNode<IntPtrT> phi_bb315_26;
  TNode<IntPtrT> phi_bb315_27;
  TNode<IntPtrT> phi_bb315_28;
  TNode<IntPtrT> phi_bb315_29;
  TNode<IntPtrT> phi_bb315_30;
  TNode<IntPtrT> phi_bb315_33;
  TNode<BoolT> phi_bb315_34;
  TNode<BoolT> phi_bb315_35;
  TNode<Union<FixedArray, Smi>> phi_bb315_36;
  TNode<Int32T> phi_bb315_37;
  TNode<Int32T> phi_bb315_39;
  TNode<Int32T> phi_bb315_40;
  TNode<Int32T> phi_bb315_41;
  TNode<Union<Hole, JSMessageObject>> tmp620;
  if (block315.is_used()) {
    ca_.Bind(&block315, &phi_bb315_16, &phi_bb315_17, &phi_bb315_18, &phi_bb315_26, &phi_bb315_27, &phi_bb315_28, &phi_bb315_29, &phi_bb315_30, &phi_bb315_33, &phi_bb315_34, &phi_bb315_35, &phi_bb315_36, &phi_bb315_37, &phi_bb315_39, &phi_bb315_40, &phi_bb315_41);
    tmp620 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb315_16, phi_bb315_17, phi_bb315_18, tmp619, tmp620);
  }

  TNode<JSAny> phi_bb312_16;
  TNode<IntPtrT> phi_bb312_17;
  TNode<BoolT> phi_bb312_18;
  TNode<IntPtrT> phi_bb312_26;
  TNode<IntPtrT> phi_bb312_27;
  TNode<IntPtrT> phi_bb312_28;
  TNode<IntPtrT> phi_bb312_29;
  TNode<IntPtrT> phi_bb312_30;
  TNode<IntPtrT> phi_bb312_33;
  TNode<BoolT> phi_bb312_34;
  TNode<BoolT> phi_bb312_35;
  TNode<Union<FixedArray, Smi>> phi_bb312_36;
  TNode<Int32T> phi_bb312_37;
  TNode<Int32T> phi_bb312_39;
  TNode<Int32T> phi_bb312_40;
  TNode<IntPtrT> tmp621;
      TNode<JSAny> tmp623;
  TNode<IntPtrT> tmp624;
  TNode<IntPtrT> tmp625;
  TNode<Union<HeapObject, TaggedIndex>> tmp626;
  TNode<IntPtrT> tmp627;
  TNode<Int32T> tmp628;
  TNode<Int32T> tmp629;
      TNode<JSAny> tmp631;
  TNode<Int32T> tmp632;
      TNode<JSAny> tmp634;
  TNode<Int32T> tmp635;
      TNode<JSAny> tmp637;
  TNode<BoolT> tmp638;
      TNode<JSAny> tmp640;
  if (block312.is_used()) {
    ca_.Bind(&block312, &phi_bb312_16, &phi_bb312_17, &phi_bb312_18, &phi_bb312_26, &phi_bb312_27, &phi_bb312_28, &phi_bb312_29, &phi_bb312_30, &phi_bb312_33, &phi_bb312_34, &phi_bb312_35, &phi_bb312_36, &phi_bb312_37, &phi_bb312_39, &phi_bb312_40);
    compiler::CodeAssemblerExceptionHandlerLabel catch622__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch622__label);
    tmp621 = Convert_intptr_int32_0(state_, TNode<Int32T>{phi_bb312_39});
    }
    if (catch622__label.is_used()) {
      compiler::CodeAssemblerLabel catch622_skip(&ca_);
      ca_.Goto(&catch622_skip);
      ca_.Bind(&catch622__label, &tmp623);
      ca_.Goto(&block316, phi_bb312_16, phi_bb312_17, phi_bb312_18, phi_bb312_26, phi_bb312_27, phi_bb312_28, phi_bb312_29, phi_bb312_30, phi_bb312_33, phi_bb312_34, phi_bb312_35, phi_bb312_36, phi_bb312_37, phi_bb312_39, phi_bb312_40, phi_bb312_39);
      ca_.Bind(&catch622_skip);
    }
    tmp624 = TimesSizeOf_int32_0(state_, TNode<IntPtrT>{tmp621});
    tmp625 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp176}, TNode<IntPtrT>{tmp624});
    std::tie(tmp626, tmp627) = NewReference_int32_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp175}, TNode<IntPtrT>{tmp625}).Flatten();
    tmp628 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{tmp626, tmp627});
    compiler::CodeAssemblerExceptionHandlerLabel catch630__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch630__label);
    tmp629 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmValueKindBitsMask);
    }
    if (catch630__label.is_used()) {
      compiler::CodeAssemblerLabel catch630_skip(&ca_);
      ca_.Goto(&catch630_skip);
      ca_.Bind(&catch630__label, &tmp631);
      ca_.Goto(&block318, phi_bb312_16, phi_bb312_17, phi_bb312_18, phi_bb312_26, phi_bb312_27, phi_bb312_28, phi_bb312_29, phi_bb312_30, phi_bb312_33, phi_bb312_34, phi_bb312_35, phi_bb312_36, phi_bb312_37, phi_bb312_39, phi_bb312_40);
      ca_.Bind(&catch630_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch633__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch633__label);
    tmp632 = CodeStubAssembler(state_).Word32And(TNode<Int32T>{tmp628}, TNode<Int32T>{tmp629});
    }
    if (catch633__label.is_used()) {
      compiler::CodeAssemblerLabel catch633_skip(&ca_);
      ca_.Goto(&catch633_skip);
      ca_.Bind(&catch633__label, &tmp634);
      ca_.Goto(&block319, phi_bb312_16, phi_bb312_17, phi_bb312_18, phi_bb312_26, phi_bb312_27, phi_bb312_28, phi_bb312_29, phi_bb312_30, phi_bb312_33, phi_bb312_34, phi_bb312_35, phi_bb312_36, phi_bb312_37, phi_bb312_39, phi_bb312_40);
      ca_.Bind(&catch633_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch636__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch636__label);
    tmp635 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::ValueKind::kRef);
    }
    if (catch636__label.is_used()) {
      compiler::CodeAssemblerLabel catch636_skip(&ca_);
      ca_.Goto(&catch636_skip);
      ca_.Bind(&catch636__label, &tmp637);
      ca_.Goto(&block322, phi_bb312_16, phi_bb312_17, phi_bb312_18, phi_bb312_26, phi_bb312_27, phi_bb312_28, phi_bb312_29, phi_bb312_30, phi_bb312_33, phi_bb312_34, phi_bb312_35, phi_bb312_36, phi_bb312_37, phi_bb312_39, phi_bb312_40);
      ca_.Bind(&catch636_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch639__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch639__label);
    tmp638 = CodeStubAssembler(state_).Word32NotEqual(TNode<Int32T>{tmp632}, TNode<Int32T>{tmp635});
    }
    if (catch639__label.is_used()) {
      compiler::CodeAssemblerLabel catch639_skip(&ca_);
      ca_.Goto(&catch639_skip);
      ca_.Bind(&catch639__label, &tmp640);
      ca_.Goto(&block323, phi_bb312_16, phi_bb312_17, phi_bb312_18, phi_bb312_26, phi_bb312_27, phi_bb312_28, phi_bb312_29, phi_bb312_30, phi_bb312_33, phi_bb312_34, phi_bb312_35, phi_bb312_36, phi_bb312_37, phi_bb312_39, phi_bb312_40);
      ca_.Bind(&catch639_skip);
    }
    ca_.Branch(tmp638, &block324, std::vector<compiler::Node*>{phi_bb312_16, phi_bb312_17, phi_bb312_18, phi_bb312_26, phi_bb312_27, phi_bb312_28, phi_bb312_29, phi_bb312_30, phi_bb312_33, phi_bb312_34, phi_bb312_35, phi_bb312_36, phi_bb312_37, phi_bb312_39, phi_bb312_40}, &block325, std::vector<compiler::Node*>{phi_bb312_16, phi_bb312_17, phi_bb312_18, phi_bb312_26, phi_bb312_27, phi_bb312_28, phi_bb312_29, phi_bb312_30, phi_bb312_33, phi_bb312_34, phi_bb312_35, phi_bb312_36, phi_bb312_37, phi_bb312_39, phi_bb312_40});
  }

  TNode<JSAny> phi_bb316_16;
  TNode<IntPtrT> phi_bb316_17;
  TNode<BoolT> phi_bb316_18;
  TNode<IntPtrT> phi_bb316_26;
  TNode<IntPtrT> phi_bb316_27;
  TNode<IntPtrT> phi_bb316_28;
  TNode<IntPtrT> phi_bb316_29;
  TNode<IntPtrT> phi_bb316_30;
  TNode<IntPtrT> phi_bb316_33;
  TNode<BoolT> phi_bb316_34;
  TNode<BoolT> phi_bb316_35;
  TNode<Union<FixedArray, Smi>> phi_bb316_36;
  TNode<Int32T> phi_bb316_37;
  TNode<Int32T> phi_bb316_39;
  TNode<Int32T> phi_bb316_40;
  TNode<Int32T> phi_bb316_44;
  TNode<Union<Hole, JSMessageObject>> tmp641;
  if (block316.is_used()) {
    ca_.Bind(&block316, &phi_bb316_16, &phi_bb316_17, &phi_bb316_18, &phi_bb316_26, &phi_bb316_27, &phi_bb316_28, &phi_bb316_29, &phi_bb316_30, &phi_bb316_33, &phi_bb316_34, &phi_bb316_35, &phi_bb316_36, &phi_bb316_37, &phi_bb316_39, &phi_bb316_40, &phi_bb316_44);
    tmp641 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb316_16, phi_bb316_17, phi_bb316_18, tmp623, tmp641);
  }

  TNode<JSAny> phi_bb318_16;
  TNode<IntPtrT> phi_bb318_17;
  TNode<BoolT> phi_bb318_18;
  TNode<IntPtrT> phi_bb318_26;
  TNode<IntPtrT> phi_bb318_27;
  TNode<IntPtrT> phi_bb318_28;
  TNode<IntPtrT> phi_bb318_29;
  TNode<IntPtrT> phi_bb318_30;
  TNode<IntPtrT> phi_bb318_33;
  TNode<BoolT> phi_bb318_34;
  TNode<BoolT> phi_bb318_35;
  TNode<Union<FixedArray, Smi>> phi_bb318_36;
  TNode<Int32T> phi_bb318_37;
  TNode<Int32T> phi_bb318_39;
  TNode<Int32T> phi_bb318_40;
  TNode<Union<Hole, JSMessageObject>> tmp642;
  if (block318.is_used()) {
    ca_.Bind(&block318, &phi_bb318_16, &phi_bb318_17, &phi_bb318_18, &phi_bb318_26, &phi_bb318_27, &phi_bb318_28, &phi_bb318_29, &phi_bb318_30, &phi_bb318_33, &phi_bb318_34, &phi_bb318_35, &phi_bb318_36, &phi_bb318_37, &phi_bb318_39, &phi_bb318_40);
    tmp642 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb318_16, phi_bb318_17, phi_bb318_18, tmp631, tmp642);
  }

  TNode<JSAny> phi_bb319_16;
  TNode<IntPtrT> phi_bb319_17;
  TNode<BoolT> phi_bb319_18;
  TNode<IntPtrT> phi_bb319_26;
  TNode<IntPtrT> phi_bb319_27;
  TNode<IntPtrT> phi_bb319_28;
  TNode<IntPtrT> phi_bb319_29;
  TNode<IntPtrT> phi_bb319_30;
  TNode<IntPtrT> phi_bb319_33;
  TNode<BoolT> phi_bb319_34;
  TNode<BoolT> phi_bb319_35;
  TNode<Union<FixedArray, Smi>> phi_bb319_36;
  TNode<Int32T> phi_bb319_37;
  TNode<Int32T> phi_bb319_39;
  TNode<Int32T> phi_bb319_40;
  TNode<Union<Hole, JSMessageObject>> tmp643;
  if (block319.is_used()) {
    ca_.Bind(&block319, &phi_bb319_16, &phi_bb319_17, &phi_bb319_18, &phi_bb319_26, &phi_bb319_27, &phi_bb319_28, &phi_bb319_29, &phi_bb319_30, &phi_bb319_33, &phi_bb319_34, &phi_bb319_35, &phi_bb319_36, &phi_bb319_37, &phi_bb319_39, &phi_bb319_40);
    tmp643 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb319_16, phi_bb319_17, phi_bb319_18, tmp634, tmp643);
  }

  TNode<JSAny> phi_bb322_16;
  TNode<IntPtrT> phi_bb322_17;
  TNode<BoolT> phi_bb322_18;
  TNode<IntPtrT> phi_bb322_26;
  TNode<IntPtrT> phi_bb322_27;
  TNode<IntPtrT> phi_bb322_28;
  TNode<IntPtrT> phi_bb322_29;
  TNode<IntPtrT> phi_bb322_30;
  TNode<IntPtrT> phi_bb322_33;
  TNode<BoolT> phi_bb322_34;
  TNode<BoolT> phi_bb322_35;
  TNode<Union<FixedArray, Smi>> phi_bb322_36;
  TNode<Int32T> phi_bb322_37;
  TNode<Int32T> phi_bb322_39;
  TNode<Int32T> phi_bb322_40;
  TNode<Union<Hole, JSMessageObject>> tmp644;
  if (block322.is_used()) {
    ca_.Bind(&block322, &phi_bb322_16, &phi_bb322_17, &phi_bb322_18, &phi_bb322_26, &phi_bb322_27, &phi_bb322_28, &phi_bb322_29, &phi_bb322_30, &phi_bb322_33, &phi_bb322_34, &phi_bb322_35, &phi_bb322_36, &phi_bb322_37, &phi_bb322_39, &phi_bb322_40);
    tmp644 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb322_16, phi_bb322_17, phi_bb322_18, tmp637, tmp644);
  }

  TNode<JSAny> phi_bb323_16;
  TNode<IntPtrT> phi_bb323_17;
  TNode<BoolT> phi_bb323_18;
  TNode<IntPtrT> phi_bb323_26;
  TNode<IntPtrT> phi_bb323_27;
  TNode<IntPtrT> phi_bb323_28;
  TNode<IntPtrT> phi_bb323_29;
  TNode<IntPtrT> phi_bb323_30;
  TNode<IntPtrT> phi_bb323_33;
  TNode<BoolT> phi_bb323_34;
  TNode<BoolT> phi_bb323_35;
  TNode<Union<FixedArray, Smi>> phi_bb323_36;
  TNode<Int32T> phi_bb323_37;
  TNode<Int32T> phi_bb323_39;
  TNode<Int32T> phi_bb323_40;
  TNode<Union<Hole, JSMessageObject>> tmp645;
  if (block323.is_used()) {
    ca_.Bind(&block323, &phi_bb323_16, &phi_bb323_17, &phi_bb323_18, &phi_bb323_26, &phi_bb323_27, &phi_bb323_28, &phi_bb323_29, &phi_bb323_30, &phi_bb323_33, &phi_bb323_34, &phi_bb323_35, &phi_bb323_36, &phi_bb323_37, &phi_bb323_39, &phi_bb323_40);
    tmp645 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb323_16, phi_bb323_17, phi_bb323_18, tmp640, tmp645);
  }

  TNode<JSAny> phi_bb324_16;
  TNode<IntPtrT> phi_bb324_17;
  TNode<BoolT> phi_bb324_18;
  TNode<IntPtrT> phi_bb324_26;
  TNode<IntPtrT> phi_bb324_27;
  TNode<IntPtrT> phi_bb324_28;
  TNode<IntPtrT> phi_bb324_29;
  TNode<IntPtrT> phi_bb324_30;
  TNode<IntPtrT> phi_bb324_33;
  TNode<BoolT> phi_bb324_34;
  TNode<BoolT> phi_bb324_35;
  TNode<Union<FixedArray, Smi>> phi_bb324_36;
  TNode<Int32T> phi_bb324_37;
  TNode<Int32T> phi_bb324_39;
  TNode<Int32T> phi_bb324_40;
  TNode<Int32T> tmp646;
      TNode<JSAny> tmp648;
  TNode<BoolT> tmp649;
      TNode<JSAny> tmp651;
  if (block324.is_used()) {
    ca_.Bind(&block324, &phi_bb324_16, &phi_bb324_17, &phi_bb324_18, &phi_bb324_26, &phi_bb324_27, &phi_bb324_28, &phi_bb324_29, &phi_bb324_30, &phi_bb324_33, &phi_bb324_34, &phi_bb324_35, &phi_bb324_36, &phi_bb324_37, &phi_bb324_39, &phi_bb324_40);
    compiler::CodeAssemblerExceptionHandlerLabel catch647__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch647__label);
    tmp646 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::ValueKind::kRefNull);
    }
    if (catch647__label.is_used()) {
      compiler::CodeAssemblerLabel catch647_skip(&ca_);
      ca_.Goto(&catch647_skip);
      ca_.Bind(&catch647__label, &tmp648);
      ca_.Goto(&block327, phi_bb324_16, phi_bb324_17, phi_bb324_18, phi_bb324_26, phi_bb324_27, phi_bb324_28, phi_bb324_29, phi_bb324_30, phi_bb324_33, phi_bb324_34, phi_bb324_35, phi_bb324_36, phi_bb324_37, phi_bb324_39, phi_bb324_40);
      ca_.Bind(&catch647_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch650__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch650__label);
    tmp649 = CodeStubAssembler(state_).Word32NotEqual(TNode<Int32T>{tmp632}, TNode<Int32T>{tmp646});
    }
    if (catch650__label.is_used()) {
      compiler::CodeAssemblerLabel catch650_skip(&ca_);
      ca_.Goto(&catch650_skip);
      ca_.Bind(&catch650__label, &tmp651);
      ca_.Goto(&block328, phi_bb324_16, phi_bb324_17, phi_bb324_18, phi_bb324_26, phi_bb324_27, phi_bb324_28, phi_bb324_29, phi_bb324_30, phi_bb324_33, phi_bb324_34, phi_bb324_35, phi_bb324_36, phi_bb324_37, phi_bb324_39, phi_bb324_40);
      ca_.Bind(&catch650_skip);
    }
    ca_.Goto(&block326, phi_bb324_16, phi_bb324_17, phi_bb324_18, phi_bb324_26, phi_bb324_27, phi_bb324_28, phi_bb324_29, phi_bb324_30, phi_bb324_33, phi_bb324_34, phi_bb324_35, phi_bb324_36, phi_bb324_37, phi_bb324_39, phi_bb324_40, tmp649);
  }

  TNode<JSAny> phi_bb327_16;
  TNode<IntPtrT> phi_bb327_17;
  TNode<BoolT> phi_bb327_18;
  TNode<IntPtrT> phi_bb327_26;
  TNode<IntPtrT> phi_bb327_27;
  TNode<IntPtrT> phi_bb327_28;
  TNode<IntPtrT> phi_bb327_29;
  TNode<IntPtrT> phi_bb327_30;
  TNode<IntPtrT> phi_bb327_33;
  TNode<BoolT> phi_bb327_34;
  TNode<BoolT> phi_bb327_35;
  TNode<Union<FixedArray, Smi>> phi_bb327_36;
  TNode<Int32T> phi_bb327_37;
  TNode<Int32T> phi_bb327_39;
  TNode<Int32T> phi_bb327_40;
  TNode<Union<Hole, JSMessageObject>> tmp652;
  if (block327.is_used()) {
    ca_.Bind(&block327, &phi_bb327_16, &phi_bb327_17, &phi_bb327_18, &phi_bb327_26, &phi_bb327_27, &phi_bb327_28, &phi_bb327_29, &phi_bb327_30, &phi_bb327_33, &phi_bb327_34, &phi_bb327_35, &phi_bb327_36, &phi_bb327_37, &phi_bb327_39, &phi_bb327_40);
    tmp652 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb327_16, phi_bb327_17, phi_bb327_18, tmp648, tmp652);
  }

  TNode<JSAny> phi_bb328_16;
  TNode<IntPtrT> phi_bb328_17;
  TNode<BoolT> phi_bb328_18;
  TNode<IntPtrT> phi_bb328_26;
  TNode<IntPtrT> phi_bb328_27;
  TNode<IntPtrT> phi_bb328_28;
  TNode<IntPtrT> phi_bb328_29;
  TNode<IntPtrT> phi_bb328_30;
  TNode<IntPtrT> phi_bb328_33;
  TNode<BoolT> phi_bb328_34;
  TNode<BoolT> phi_bb328_35;
  TNode<Union<FixedArray, Smi>> phi_bb328_36;
  TNode<Int32T> phi_bb328_37;
  TNode<Int32T> phi_bb328_39;
  TNode<Int32T> phi_bb328_40;
  TNode<Union<Hole, JSMessageObject>> tmp653;
  if (block328.is_used()) {
    ca_.Bind(&block328, &phi_bb328_16, &phi_bb328_17, &phi_bb328_18, &phi_bb328_26, &phi_bb328_27, &phi_bb328_28, &phi_bb328_29, &phi_bb328_30, &phi_bb328_33, &phi_bb328_34, &phi_bb328_35, &phi_bb328_36, &phi_bb328_37, &phi_bb328_39, &phi_bb328_40);
    tmp653 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb328_16, phi_bb328_17, phi_bb328_18, tmp651, tmp653);
  }

  TNode<JSAny> phi_bb325_16;
  TNode<IntPtrT> phi_bb325_17;
  TNode<BoolT> phi_bb325_18;
  TNode<IntPtrT> phi_bb325_26;
  TNode<IntPtrT> phi_bb325_27;
  TNode<IntPtrT> phi_bb325_28;
  TNode<IntPtrT> phi_bb325_29;
  TNode<IntPtrT> phi_bb325_30;
  TNode<IntPtrT> phi_bb325_33;
  TNode<BoolT> phi_bb325_34;
  TNode<BoolT> phi_bb325_35;
  TNode<Union<FixedArray, Smi>> phi_bb325_36;
  TNode<Int32T> phi_bb325_37;
  TNode<Int32T> phi_bb325_39;
  TNode<Int32T> phi_bb325_40;
  TNode<BoolT> tmp654;
      TNode<JSAny> tmp656;
  if (block325.is_used()) {
    ca_.Bind(&block325, &phi_bb325_16, &phi_bb325_17, &phi_bb325_18, &phi_bb325_26, &phi_bb325_27, &phi_bb325_28, &phi_bb325_29, &phi_bb325_30, &phi_bb325_33, &phi_bb325_34, &phi_bb325_35, &phi_bb325_36, &phi_bb325_37, &phi_bb325_39, &phi_bb325_40);
    compiler::CodeAssemblerExceptionHandlerLabel catch655__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch655__label);
    tmp654 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    }
    if (catch655__label.is_used()) {
      compiler::CodeAssemblerLabel catch655_skip(&ca_);
      ca_.Goto(&catch655_skip);
      ca_.Bind(&catch655__label, &tmp656);
      ca_.Goto(&block329, phi_bb325_16, phi_bb325_17, phi_bb325_18, phi_bb325_26, phi_bb325_27, phi_bb325_28, phi_bb325_29, phi_bb325_30, phi_bb325_33, phi_bb325_34, phi_bb325_35, phi_bb325_36, phi_bb325_37, phi_bb325_39, phi_bb325_40);
      ca_.Bind(&catch655_skip);
    }
    ca_.Goto(&block326, phi_bb325_16, phi_bb325_17, phi_bb325_18, phi_bb325_26, phi_bb325_27, phi_bb325_28, phi_bb325_29, phi_bb325_30, phi_bb325_33, phi_bb325_34, phi_bb325_35, phi_bb325_36, phi_bb325_37, phi_bb325_39, phi_bb325_40, tmp654);
  }

  TNode<JSAny> phi_bb329_16;
  TNode<IntPtrT> phi_bb329_17;
  TNode<BoolT> phi_bb329_18;
  TNode<IntPtrT> phi_bb329_26;
  TNode<IntPtrT> phi_bb329_27;
  TNode<IntPtrT> phi_bb329_28;
  TNode<IntPtrT> phi_bb329_29;
  TNode<IntPtrT> phi_bb329_30;
  TNode<IntPtrT> phi_bb329_33;
  TNode<BoolT> phi_bb329_34;
  TNode<BoolT> phi_bb329_35;
  TNode<Union<FixedArray, Smi>> phi_bb329_36;
  TNode<Int32T> phi_bb329_37;
  TNode<Int32T> phi_bb329_39;
  TNode<Int32T> phi_bb329_40;
  TNode<Union<Hole, JSMessageObject>> tmp657;
  if (block329.is_used()) {
    ca_.Bind(&block329, &phi_bb329_16, &phi_bb329_17, &phi_bb329_18, &phi_bb329_26, &phi_bb329_27, &phi_bb329_28, &phi_bb329_29, &phi_bb329_30, &phi_bb329_33, &phi_bb329_34, &phi_bb329_35, &phi_bb329_36, &phi_bb329_37, &phi_bb329_39, &phi_bb329_40);
    tmp657 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb329_16, phi_bb329_17, phi_bb329_18, tmp656, tmp657);
  }

  TNode<JSAny> phi_bb326_16;
  TNode<IntPtrT> phi_bb326_17;
  TNode<BoolT> phi_bb326_18;
  TNode<IntPtrT> phi_bb326_26;
  TNode<IntPtrT> phi_bb326_27;
  TNode<IntPtrT> phi_bb326_28;
  TNode<IntPtrT> phi_bb326_29;
  TNode<IntPtrT> phi_bb326_30;
  TNode<IntPtrT> phi_bb326_33;
  TNode<BoolT> phi_bb326_34;
  TNode<BoolT> phi_bb326_35;
  TNode<Union<FixedArray, Smi>> phi_bb326_36;
  TNode<Int32T> phi_bb326_37;
  TNode<Int32T> phi_bb326_39;
  TNode<Int32T> phi_bb326_40;
  TNode<BoolT> phi_bb326_44;
  if (block326.is_used()) {
    ca_.Bind(&block326, &phi_bb326_16, &phi_bb326_17, &phi_bb326_18, &phi_bb326_26, &phi_bb326_27, &phi_bb326_28, &phi_bb326_29, &phi_bb326_30, &phi_bb326_33, &phi_bb326_34, &phi_bb326_35, &phi_bb326_36, &phi_bb326_37, &phi_bb326_39, &phi_bb326_40, &phi_bb326_44);
    ca_.Branch(phi_bb326_44, &block320, std::vector<compiler::Node*>{phi_bb326_16, phi_bb326_17, phi_bb326_18, phi_bb326_26, phi_bb326_27, phi_bb326_28, phi_bb326_29, phi_bb326_30, phi_bb326_33, phi_bb326_34, phi_bb326_35, phi_bb326_36, phi_bb326_37, phi_bb326_39, phi_bb326_40}, &block321, std::vector<compiler::Node*>{phi_bb326_16, phi_bb326_17, phi_bb326_18, phi_bb326_26, phi_bb326_27, phi_bb326_28, phi_bb326_29, phi_bb326_30, phi_bb326_33, phi_bb326_34, phi_bb326_35, phi_bb326_36, phi_bb326_37, phi_bb326_39, phi_bb326_40});
  }

  TNode<JSAny> phi_bb320_16;
  TNode<IntPtrT> phi_bb320_17;
  TNode<BoolT> phi_bb320_18;
  TNode<IntPtrT> phi_bb320_26;
  TNode<IntPtrT> phi_bb320_27;
  TNode<IntPtrT> phi_bb320_28;
  TNode<IntPtrT> phi_bb320_29;
  TNode<IntPtrT> phi_bb320_30;
  TNode<IntPtrT> phi_bb320_33;
  TNode<BoolT> phi_bb320_34;
  TNode<BoolT> phi_bb320_35;
  TNode<Union<FixedArray, Smi>> phi_bb320_36;
  TNode<Int32T> phi_bb320_37;
  TNode<Int32T> phi_bb320_39;
  TNode<Int32T> phi_bb320_40;
  TNode<Int32T> tmp658;
      TNode<JSAny> tmp660;
  TNode<Int32T> tmp661;
      TNode<JSAny> tmp663;
  TNode<Int32T> tmp664;
      TNode<JSAny> tmp666;
  TNode<Int32T> tmp667;
      TNode<JSAny> tmp669;
  if (block320.is_used()) {
    ca_.Bind(&block320, &phi_bb320_16, &phi_bb320_17, &phi_bb320_18, &phi_bb320_26, &phi_bb320_27, &phi_bb320_28, &phi_bb320_29, &phi_bb320_30, &phi_bb320_33, &phi_bb320_34, &phi_bb320_35, &phi_bb320_36, &phi_bb320_37, &phi_bb320_39, &phi_bb320_40);
    compiler::CodeAssemblerExceptionHandlerLabel catch659__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch659__label);
    tmp658 = FromConstexpr_int32_constexpr_int31_0(state_, 1);
    }
    if (catch659__label.is_used()) {
      compiler::CodeAssemblerLabel catch659_skip(&ca_);
      ca_.Goto(&catch659_skip);
      ca_.Bind(&catch659__label, &tmp660);
      ca_.Goto(&block330, phi_bb320_16, phi_bb320_17, phi_bb320_18, phi_bb320_26, phi_bb320_27, phi_bb320_28, phi_bb320_29, phi_bb320_30, phi_bb320_33, phi_bb320_34, phi_bb320_35, phi_bb320_36, phi_bb320_37, phi_bb320_39, phi_bb320_40, phi_bb320_39, phi_bb320_39);
      ca_.Bind(&catch659_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch662__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch662__label);
    tmp661 = CodeStubAssembler(state_).Int32Add(TNode<Int32T>{phi_bb320_39}, TNode<Int32T>{tmp658});
    }
    if (catch662__label.is_used()) {
      compiler::CodeAssemblerLabel catch662_skip(&ca_);
      ca_.Goto(&catch662_skip);
      ca_.Bind(&catch662__label, &tmp663);
      ca_.Goto(&block331, phi_bb320_16, phi_bb320_17, phi_bb320_18, phi_bb320_26, phi_bb320_27, phi_bb320_28, phi_bb320_29, phi_bb320_30, phi_bb320_33, phi_bb320_34, phi_bb320_35, phi_bb320_36, phi_bb320_37, phi_bb320_39, phi_bb320_40, phi_bb320_39);
      ca_.Bind(&catch662_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch665__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch665__label);
    tmp664 = FromConstexpr_int32_constexpr_int31_0(state_, 1);
    }
    if (catch665__label.is_used()) {
      compiler::CodeAssemblerLabel catch665_skip(&ca_);
      ca_.Goto(&catch665_skip);
      ca_.Bind(&catch665__label, &tmp666);
      ca_.Goto(&block332, phi_bb320_16, phi_bb320_17, phi_bb320_18, phi_bb320_26, phi_bb320_27, phi_bb320_28, phi_bb320_29, phi_bb320_30, phi_bb320_33, phi_bb320_34, phi_bb320_35, phi_bb320_36, phi_bb320_37, phi_bb320_40, phi_bb320_40, phi_bb320_40);
      ca_.Bind(&catch665_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch668__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch668__label);
    tmp667 = CodeStubAssembler(state_).Int32Add(TNode<Int32T>{phi_bb320_40}, TNode<Int32T>{tmp664});
    }
    if (catch668__label.is_used()) {
      compiler::CodeAssemblerLabel catch668_skip(&ca_);
      ca_.Goto(&catch668_skip);
      ca_.Bind(&catch668__label, &tmp669);
      ca_.Goto(&block333, phi_bb320_16, phi_bb320_17, phi_bb320_18, phi_bb320_26, phi_bb320_27, phi_bb320_28, phi_bb320_29, phi_bb320_30, phi_bb320_33, phi_bb320_34, phi_bb320_35, phi_bb320_36, phi_bb320_37, phi_bb320_40, phi_bb320_40);
      ca_.Bind(&catch668_skip);
    }
    ca_.Goto(&block314, phi_bb320_16, phi_bb320_17, phi_bb320_18, phi_bb320_26, phi_bb320_27, phi_bb320_28, phi_bb320_29, phi_bb320_30, phi_bb320_33, phi_bb320_34, phi_bb320_35, phi_bb320_36, phi_bb320_37, tmp661, tmp667);
  }

  TNode<JSAny> phi_bb330_16;
  TNode<IntPtrT> phi_bb330_17;
  TNode<BoolT> phi_bb330_18;
  TNode<IntPtrT> phi_bb330_26;
  TNode<IntPtrT> phi_bb330_27;
  TNode<IntPtrT> phi_bb330_28;
  TNode<IntPtrT> phi_bb330_29;
  TNode<IntPtrT> phi_bb330_30;
  TNode<IntPtrT> phi_bb330_33;
  TNode<BoolT> phi_bb330_34;
  TNode<BoolT> phi_bb330_35;
  TNode<Union<FixedArray, Smi>> phi_bb330_36;
  TNode<Int32T> phi_bb330_37;
  TNode<Int32T> phi_bb330_39;
  TNode<Int32T> phi_bb330_40;
  TNode<Int32T> phi_bb330_43;
  TNode<Int32T> phi_bb330_44;
  TNode<Union<Hole, JSMessageObject>> tmp670;
  if (block330.is_used()) {
    ca_.Bind(&block330, &phi_bb330_16, &phi_bb330_17, &phi_bb330_18, &phi_bb330_26, &phi_bb330_27, &phi_bb330_28, &phi_bb330_29, &phi_bb330_30, &phi_bb330_33, &phi_bb330_34, &phi_bb330_35, &phi_bb330_36, &phi_bb330_37, &phi_bb330_39, &phi_bb330_40, &phi_bb330_43, &phi_bb330_44);
    tmp670 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb330_16, phi_bb330_17, phi_bb330_18, tmp660, tmp670);
  }

  TNode<JSAny> phi_bb331_16;
  TNode<IntPtrT> phi_bb331_17;
  TNode<BoolT> phi_bb331_18;
  TNode<IntPtrT> phi_bb331_26;
  TNode<IntPtrT> phi_bb331_27;
  TNode<IntPtrT> phi_bb331_28;
  TNode<IntPtrT> phi_bb331_29;
  TNode<IntPtrT> phi_bb331_30;
  TNode<IntPtrT> phi_bb331_33;
  TNode<BoolT> phi_bb331_34;
  TNode<BoolT> phi_bb331_35;
  TNode<Union<FixedArray, Smi>> phi_bb331_36;
  TNode<Int32T> phi_bb331_37;
  TNode<Int32T> phi_bb331_39;
  TNode<Int32T> phi_bb331_40;
  TNode<Int32T> phi_bb331_43;
  TNode<Union<Hole, JSMessageObject>> tmp671;
  if (block331.is_used()) {
    ca_.Bind(&block331, &phi_bb331_16, &phi_bb331_17, &phi_bb331_18, &phi_bb331_26, &phi_bb331_27, &phi_bb331_28, &phi_bb331_29, &phi_bb331_30, &phi_bb331_33, &phi_bb331_34, &phi_bb331_35, &phi_bb331_36, &phi_bb331_37, &phi_bb331_39, &phi_bb331_40, &phi_bb331_43);
    tmp671 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb331_16, phi_bb331_17, phi_bb331_18, tmp663, tmp671);
  }

  TNode<JSAny> phi_bb332_16;
  TNode<IntPtrT> phi_bb332_17;
  TNode<BoolT> phi_bb332_18;
  TNode<IntPtrT> phi_bb332_26;
  TNode<IntPtrT> phi_bb332_27;
  TNode<IntPtrT> phi_bb332_28;
  TNode<IntPtrT> phi_bb332_29;
  TNode<IntPtrT> phi_bb332_30;
  TNode<IntPtrT> phi_bb332_33;
  TNode<BoolT> phi_bb332_34;
  TNode<BoolT> phi_bb332_35;
  TNode<Union<FixedArray, Smi>> phi_bb332_36;
  TNode<Int32T> phi_bb332_37;
  TNode<Int32T> phi_bb332_40;
  TNode<Int32T> phi_bb332_43;
  TNode<Int32T> phi_bb332_44;
  TNode<Union<Hole, JSMessageObject>> tmp672;
  if (block332.is_used()) {
    ca_.Bind(&block332, &phi_bb332_16, &phi_bb332_17, &phi_bb332_18, &phi_bb332_26, &phi_bb332_27, &phi_bb332_28, &phi_bb332_29, &phi_bb332_30, &phi_bb332_33, &phi_bb332_34, &phi_bb332_35, &phi_bb332_36, &phi_bb332_37, &phi_bb332_40, &phi_bb332_43, &phi_bb332_44);
    tmp672 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb332_16, phi_bb332_17, phi_bb332_18, tmp666, tmp672);
  }

  TNode<JSAny> phi_bb333_16;
  TNode<IntPtrT> phi_bb333_17;
  TNode<BoolT> phi_bb333_18;
  TNode<IntPtrT> phi_bb333_26;
  TNode<IntPtrT> phi_bb333_27;
  TNode<IntPtrT> phi_bb333_28;
  TNode<IntPtrT> phi_bb333_29;
  TNode<IntPtrT> phi_bb333_30;
  TNode<IntPtrT> phi_bb333_33;
  TNode<BoolT> phi_bb333_34;
  TNode<BoolT> phi_bb333_35;
  TNode<Union<FixedArray, Smi>> phi_bb333_36;
  TNode<Int32T> phi_bb333_37;
  TNode<Int32T> phi_bb333_40;
  TNode<Int32T> phi_bb333_43;
  TNode<Union<Hole, JSMessageObject>> tmp673;
  if (block333.is_used()) {
    ca_.Bind(&block333, &phi_bb333_16, &phi_bb333_17, &phi_bb333_18, &phi_bb333_26, &phi_bb333_27, &phi_bb333_28, &phi_bb333_29, &phi_bb333_30, &phi_bb333_33, &phi_bb333_34, &phi_bb333_35, &phi_bb333_36, &phi_bb333_37, &phi_bb333_40, &phi_bb333_43);
    tmp673 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb333_16, phi_bb333_17, phi_bb333_18, tmp669, tmp673);
  }

  TNode<JSAny> phi_bb321_16;
  TNode<IntPtrT> phi_bb321_17;
  TNode<BoolT> phi_bb321_18;
  TNode<IntPtrT> phi_bb321_26;
  TNode<IntPtrT> phi_bb321_27;
  TNode<IntPtrT> phi_bb321_28;
  TNode<IntPtrT> phi_bb321_29;
  TNode<IntPtrT> phi_bb321_30;
  TNode<IntPtrT> phi_bb321_33;
  TNode<BoolT> phi_bb321_34;
  TNode<BoolT> phi_bb321_35;
  TNode<Union<FixedArray, Smi>> phi_bb321_36;
  TNode<Int32T> phi_bb321_37;
  TNode<Int32T> phi_bb321_39;
  TNode<Int32T> phi_bb321_40;
  TNode<FixedArray> tmp674;
      TNode<JSAny> tmp676;
  TNode<Union<HeapObject, TaggedIndex>> tmp677;
  TNode<IntPtrT> tmp678;
  TNode<IntPtrT> tmp679;
      TNode<JSAny> tmp681;
  TNode<Int32T> tmp682;
      TNode<JSAny> tmp684;
  TNode<Int32T> tmp685;
      TNode<JSAny> tmp687;
  TNode<IntPtrT> tmp688;
      TNode<JSAny> tmp690;
  TNode<UintPtrT> tmp691;
  TNode<UintPtrT> tmp692;
  TNode<BoolT> tmp693;
  if (block321.is_used()) {
    ca_.Bind(&block321, &phi_bb321_16, &phi_bb321_17, &phi_bb321_18, &phi_bb321_26, &phi_bb321_27, &phi_bb321_28, &phi_bb321_29, &phi_bb321_30, &phi_bb321_33, &phi_bb321_34, &phi_bb321_35, &phi_bb321_36, &phi_bb321_37, &phi_bb321_39, &phi_bb321_40);
    compiler::CodeAssemblerExceptionHandlerLabel catch675__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch675__label);
    tmp674 = UnsafeCast_FixedArray_0(state_, TNode<Context>{p_context}, TNode<Object>{phi_bb321_36});
    }
    if (catch675__label.is_used()) {
      compiler::CodeAssemblerLabel catch675_skip(&ca_);
      ca_.Goto(&catch675_skip);
      ca_.Bind(&catch675__label, &tmp676);
      ca_.Goto(&block334, phi_bb321_16, phi_bb321_17, phi_bb321_18, phi_bb321_26, phi_bb321_27, phi_bb321_28, phi_bb321_29, phi_bb321_30, phi_bb321_33, phi_bb321_34, phi_bb321_35, phi_bb321_36, phi_bb321_37, phi_bb321_39, phi_bb321_40, phi_bb321_36);
      ca_.Bind(&catch675_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch680__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch680__label);
    std::tie(tmp677, tmp678, tmp679) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{tmp674}).Flatten();
    }
    if (catch680__label.is_used()) {
      compiler::CodeAssemblerLabel catch680_skip(&ca_);
      ca_.Goto(&catch680_skip);
      ca_.Bind(&catch680__label, &tmp681);
      ca_.Goto(&block335, phi_bb321_16, phi_bb321_17, phi_bb321_18, phi_bb321_26, phi_bb321_27, phi_bb321_28, phi_bb321_29, phi_bb321_30, phi_bb321_33, phi_bb321_34, phi_bb321_35, phi_bb321_36, phi_bb321_37, phi_bb321_39, phi_bb321_40);
      ca_.Bind(&catch680_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch683__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch683__label);
    tmp682 = FromConstexpr_int32_constexpr_int31_0(state_, 1);
    }
    if (catch683__label.is_used()) {
      compiler::CodeAssemblerLabel catch683_skip(&ca_);
      ca_.Goto(&catch683_skip);
      ca_.Bind(&catch683__label, &tmp684);
      ca_.Goto(&block336, phi_bb321_16, phi_bb321_17, phi_bb321_18, phi_bb321_26, phi_bb321_27, phi_bb321_28, phi_bb321_29, phi_bb321_30, phi_bb321_33, phi_bb321_34, phi_bb321_35, phi_bb321_36, phi_bb321_37, phi_bb321_39, phi_bb321_40, phi_bb321_40, phi_bb321_40);
      ca_.Bind(&catch683_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch686__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch686__label);
    tmp685 = CodeStubAssembler(state_).Int32Add(TNode<Int32T>{phi_bb321_40}, TNode<Int32T>{tmp682});
    }
    if (catch686__label.is_used()) {
      compiler::CodeAssemblerLabel catch686_skip(&ca_);
      ca_.Goto(&catch686_skip);
      ca_.Bind(&catch686__label, &tmp687);
      ca_.Goto(&block337, phi_bb321_16, phi_bb321_17, phi_bb321_18, phi_bb321_26, phi_bb321_27, phi_bb321_28, phi_bb321_29, phi_bb321_30, phi_bb321_33, phi_bb321_34, phi_bb321_35, phi_bb321_36, phi_bb321_37, phi_bb321_39, phi_bb321_40, phi_bb321_40);
      ca_.Bind(&catch686_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch689__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch689__label);
    tmp688 = Convert_intptr_int32_0(state_, TNode<Int32T>{phi_bb321_40});
    }
    if (catch689__label.is_used()) {
      compiler::CodeAssemblerLabel catch689_skip(&ca_);
      ca_.Goto(&catch689_skip);
      ca_.Bind(&catch689__label, &tmp690);
      ca_.Goto(&block338, phi_bb321_16, phi_bb321_17, phi_bb321_18, phi_bb321_26, phi_bb321_27, phi_bb321_28, phi_bb321_29, phi_bb321_30, phi_bb321_33, phi_bb321_34, phi_bb321_35, phi_bb321_36, phi_bb321_37, phi_bb321_39, phi_bb321_40);
      ca_.Bind(&catch689_skip);
    }
    tmp691 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp688});
    tmp692 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp679});
    tmp693 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp691}, TNode<UintPtrT>{tmp692});
    ca_.Branch(tmp693, &block343, std::vector<compiler::Node*>{phi_bb321_16, phi_bb321_17, phi_bb321_18, phi_bb321_26, phi_bb321_27, phi_bb321_28, phi_bb321_29, phi_bb321_30, phi_bb321_33, phi_bb321_34, phi_bb321_35, phi_bb321_36, phi_bb321_37, phi_bb321_39}, &block344, std::vector<compiler::Node*>{phi_bb321_16, phi_bb321_17, phi_bb321_18, phi_bb321_26, phi_bb321_27, phi_bb321_28, phi_bb321_29, phi_bb321_30, phi_bb321_33, phi_bb321_34, phi_bb321_35, phi_bb321_36, phi_bb321_37, phi_bb321_39});
  }

  TNode<JSAny> phi_bb334_16;
  TNode<IntPtrT> phi_bb334_17;
  TNode<BoolT> phi_bb334_18;
  TNode<IntPtrT> phi_bb334_26;
  TNode<IntPtrT> phi_bb334_27;
  TNode<IntPtrT> phi_bb334_28;
  TNode<IntPtrT> phi_bb334_29;
  TNode<IntPtrT> phi_bb334_30;
  TNode<IntPtrT> phi_bb334_33;
  TNode<BoolT> phi_bb334_34;
  TNode<BoolT> phi_bb334_35;
  TNode<Union<FixedArray, Smi>> phi_bb334_36;
  TNode<Int32T> phi_bb334_37;
  TNode<Int32T> phi_bb334_39;
  TNode<Int32T> phi_bb334_40;
  TNode<Union<FixedArray, Smi>> phi_bb334_43;
  TNode<Union<Hole, JSMessageObject>> tmp694;
  if (block334.is_used()) {
    ca_.Bind(&block334, &phi_bb334_16, &phi_bb334_17, &phi_bb334_18, &phi_bb334_26, &phi_bb334_27, &phi_bb334_28, &phi_bb334_29, &phi_bb334_30, &phi_bb334_33, &phi_bb334_34, &phi_bb334_35, &phi_bb334_36, &phi_bb334_37, &phi_bb334_39, &phi_bb334_40, &phi_bb334_43);
    tmp694 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb334_16, phi_bb334_17, phi_bb334_18, tmp676, tmp694);
  }

  TNode<JSAny> phi_bb335_16;
  TNode<IntPtrT> phi_bb335_17;
  TNode<BoolT> phi_bb335_18;
  TNode<IntPtrT> phi_bb335_26;
  TNode<IntPtrT> phi_bb335_27;
  TNode<IntPtrT> phi_bb335_28;
  TNode<IntPtrT> phi_bb335_29;
  TNode<IntPtrT> phi_bb335_30;
  TNode<IntPtrT> phi_bb335_33;
  TNode<BoolT> phi_bb335_34;
  TNode<BoolT> phi_bb335_35;
  TNode<Union<FixedArray, Smi>> phi_bb335_36;
  TNode<Int32T> phi_bb335_37;
  TNode<Int32T> phi_bb335_39;
  TNode<Int32T> phi_bb335_40;
  TNode<Union<Hole, JSMessageObject>> tmp695;
  if (block335.is_used()) {
    ca_.Bind(&block335, &phi_bb335_16, &phi_bb335_17, &phi_bb335_18, &phi_bb335_26, &phi_bb335_27, &phi_bb335_28, &phi_bb335_29, &phi_bb335_30, &phi_bb335_33, &phi_bb335_34, &phi_bb335_35, &phi_bb335_36, &phi_bb335_37, &phi_bb335_39, &phi_bb335_40);
    tmp695 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb335_16, phi_bb335_17, phi_bb335_18, tmp681, tmp695);
  }

  TNode<JSAny> phi_bb336_16;
  TNode<IntPtrT> phi_bb336_17;
  TNode<BoolT> phi_bb336_18;
  TNode<IntPtrT> phi_bb336_26;
  TNode<IntPtrT> phi_bb336_27;
  TNode<IntPtrT> phi_bb336_28;
  TNode<IntPtrT> phi_bb336_29;
  TNode<IntPtrT> phi_bb336_30;
  TNode<IntPtrT> phi_bb336_33;
  TNode<BoolT> phi_bb336_34;
  TNode<BoolT> phi_bb336_35;
  TNode<Union<FixedArray, Smi>> phi_bb336_36;
  TNode<Int32T> phi_bb336_37;
  TNode<Int32T> phi_bb336_39;
  TNode<Int32T> phi_bb336_40;
  TNode<Int32T> phi_bb336_48;
  TNode<Int32T> phi_bb336_49;
  TNode<Union<Hole, JSMessageObject>> tmp696;
  if (block336.is_used()) {
    ca_.Bind(&block336, &phi_bb336_16, &phi_bb336_17, &phi_bb336_18, &phi_bb336_26, &phi_bb336_27, &phi_bb336_28, &phi_bb336_29, &phi_bb336_30, &phi_bb336_33, &phi_bb336_34, &phi_bb336_35, &phi_bb336_36, &phi_bb336_37, &phi_bb336_39, &phi_bb336_40, &phi_bb336_48, &phi_bb336_49);
    tmp696 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb336_16, phi_bb336_17, phi_bb336_18, tmp684, tmp696);
  }

  TNode<JSAny> phi_bb337_16;
  TNode<IntPtrT> phi_bb337_17;
  TNode<BoolT> phi_bb337_18;
  TNode<IntPtrT> phi_bb337_26;
  TNode<IntPtrT> phi_bb337_27;
  TNode<IntPtrT> phi_bb337_28;
  TNode<IntPtrT> phi_bb337_29;
  TNode<IntPtrT> phi_bb337_30;
  TNode<IntPtrT> phi_bb337_33;
  TNode<BoolT> phi_bb337_34;
  TNode<BoolT> phi_bb337_35;
  TNode<Union<FixedArray, Smi>> phi_bb337_36;
  TNode<Int32T> phi_bb337_37;
  TNode<Int32T> phi_bb337_39;
  TNode<Int32T> phi_bb337_40;
  TNode<Int32T> phi_bb337_48;
  TNode<Union<Hole, JSMessageObject>> tmp697;
  if (block337.is_used()) {
    ca_.Bind(&block337, &phi_bb337_16, &phi_bb337_17, &phi_bb337_18, &phi_bb337_26, &phi_bb337_27, &phi_bb337_28, &phi_bb337_29, &phi_bb337_30, &phi_bb337_33, &phi_bb337_34, &phi_bb337_35, &phi_bb337_36, &phi_bb337_37, &phi_bb337_39, &phi_bb337_40, &phi_bb337_48);
    tmp697 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb337_16, phi_bb337_17, phi_bb337_18, tmp687, tmp697);
  }

  TNode<JSAny> phi_bb338_16;
  TNode<IntPtrT> phi_bb338_17;
  TNode<BoolT> phi_bb338_18;
  TNode<IntPtrT> phi_bb338_26;
  TNode<IntPtrT> phi_bb338_27;
  TNode<IntPtrT> phi_bb338_28;
  TNode<IntPtrT> phi_bb338_29;
  TNode<IntPtrT> phi_bb338_30;
  TNode<IntPtrT> phi_bb338_33;
  TNode<BoolT> phi_bb338_34;
  TNode<BoolT> phi_bb338_35;
  TNode<Union<FixedArray, Smi>> phi_bb338_36;
  TNode<Int32T> phi_bb338_37;
  TNode<Int32T> phi_bb338_39;
  TNode<Int32T> phi_bb338_48;
  TNode<Union<Hole, JSMessageObject>> tmp698;
  if (block338.is_used()) {
    ca_.Bind(&block338, &phi_bb338_16, &phi_bb338_17, &phi_bb338_18, &phi_bb338_26, &phi_bb338_27, &phi_bb338_28, &phi_bb338_29, &phi_bb338_30, &phi_bb338_33, &phi_bb338_34, &phi_bb338_35, &phi_bb338_36, &phi_bb338_37, &phi_bb338_39, &phi_bb338_48);
    tmp698 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb338_16, phi_bb338_17, phi_bb338_18, tmp690, tmp698);
  }

  TNode<JSAny> phi_bb343_16;
  TNode<IntPtrT> phi_bb343_17;
  TNode<BoolT> phi_bb343_18;
  TNode<IntPtrT> phi_bb343_26;
  TNode<IntPtrT> phi_bb343_27;
  TNode<IntPtrT> phi_bb343_28;
  TNode<IntPtrT> phi_bb343_29;
  TNode<IntPtrT> phi_bb343_30;
  TNode<IntPtrT> phi_bb343_33;
  TNode<BoolT> phi_bb343_34;
  TNode<BoolT> phi_bb343_35;
  TNode<Union<FixedArray, Smi>> phi_bb343_36;
  TNode<Int32T> phi_bb343_37;
  TNode<Int32T> phi_bb343_39;
  TNode<IntPtrT> tmp699;
  TNode<IntPtrT> tmp700;
  TNode<Union<HeapObject, TaggedIndex>> tmp701;
  TNode<IntPtrT> tmp702;
  TNode<Object> tmp703;
  TNode<IntPtrT> tmp704;
  TNode<IntPtrT> tmp705;
  TNode<IntPtrT> tmp706;
  TNode<BoolT> tmp707;
  if (block343.is_used()) {
    ca_.Bind(&block343, &phi_bb343_16, &phi_bb343_17, &phi_bb343_18, &phi_bb343_26, &phi_bb343_27, &phi_bb343_28, &phi_bb343_29, &phi_bb343_30, &phi_bb343_33, &phi_bb343_34, &phi_bb343_35, &phi_bb343_36, &phi_bb343_37, &phi_bb343_39);
    tmp699 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{tmp688});
    tmp700 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp678}, TNode<IntPtrT>{tmp699});
    std::tie(tmp701, tmp702) = NewReference_Object_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp677}, TNode<IntPtrT>{tmp700}).Flatten();
    tmp703 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp701, tmp702});
    tmp704 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp705 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{phi_bb343_26}, TNode<IntPtrT>{tmp704});
    tmp706 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp707 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{phi_bb343_26}, TNode<IntPtrT>{tmp706});
    ca_.Branch(tmp707, &block348, std::vector<compiler::Node*>{phi_bb343_16, phi_bb343_17, phi_bb343_18, phi_bb343_27, phi_bb343_28, phi_bb343_29, phi_bb343_30, phi_bb343_33, phi_bb343_34, phi_bb343_35, phi_bb343_36, phi_bb343_37, phi_bb343_39}, &block349, std::vector<compiler::Node*>{phi_bb343_16, phi_bb343_17, phi_bb343_18, phi_bb343_27, phi_bb343_28, phi_bb343_29, phi_bb343_30, phi_bb343_33, phi_bb343_34, phi_bb343_35, phi_bb343_36, phi_bb343_37, phi_bb343_39});
  }

  TNode<JSAny> phi_bb344_16;
  TNode<IntPtrT> phi_bb344_17;
  TNode<BoolT> phi_bb344_18;
  TNode<IntPtrT> phi_bb344_26;
  TNode<IntPtrT> phi_bb344_27;
  TNode<IntPtrT> phi_bb344_28;
  TNode<IntPtrT> phi_bb344_29;
  TNode<IntPtrT> phi_bb344_30;
  TNode<IntPtrT> phi_bb344_33;
  TNode<BoolT> phi_bb344_34;
  TNode<BoolT> phi_bb344_35;
  TNode<Union<FixedArray, Smi>> phi_bb344_36;
  TNode<Int32T> phi_bb344_37;
  TNode<Int32T> phi_bb344_39;
  if (block344.is_used()) {
    ca_.Bind(&block344, &phi_bb344_16, &phi_bb344_17, &phi_bb344_18, &phi_bb344_26, &phi_bb344_27, &phi_bb344_28, &phi_bb344_29, &phi_bb344_30, &phi_bb344_33, &phi_bb344_34, &phi_bb344_35, &phi_bb344_36, &phi_bb344_37, &phi_bb344_39);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<JSAny> phi_bb348_16;
  TNode<IntPtrT> phi_bb348_17;
  TNode<BoolT> phi_bb348_18;
  TNode<IntPtrT> phi_bb348_27;
  TNode<IntPtrT> phi_bb348_28;
  TNode<IntPtrT> phi_bb348_29;
  TNode<IntPtrT> phi_bb348_30;
  TNode<IntPtrT> phi_bb348_33;
  TNode<BoolT> phi_bb348_34;
  TNode<BoolT> phi_bb348_35;
  TNode<Union<FixedArray, Smi>> phi_bb348_36;
  TNode<Int32T> phi_bb348_37;
  TNode<Int32T> phi_bb348_39;
  TNode<Union<HeapObject, TaggedIndex>> tmp708;
  TNode<IntPtrT> tmp709;
  TNode<IntPtrT> tmp710;
  TNode<IntPtrT> tmp711;
  if (block348.is_used()) {
    ca_.Bind(&block348, &phi_bb348_16, &phi_bb348_17, &phi_bb348_18, &phi_bb348_27, &phi_bb348_28, &phi_bb348_29, &phi_bb348_30, &phi_bb348_33, &phi_bb348_34, &phi_bb348_35, &phi_bb348_36, &phi_bb348_37, &phi_bb348_39);
    std::tie(tmp708, tmp709) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp197}, TNode<IntPtrT>{phi_bb348_28}).Flatten();
    tmp710 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp711 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb348_28}, TNode<IntPtrT>{tmp710});
    ca_.Goto(&block347, phi_bb348_16, phi_bb348_17, phi_bb348_18, phi_bb348_27, tmp711, phi_bb348_29, phi_bb348_30, phi_bb348_33, phi_bb348_34, phi_bb348_35, phi_bb348_36, phi_bb348_37, phi_bb348_39, tmp708, tmp709);
  }

  TNode<JSAny> phi_bb349_16;
  TNode<IntPtrT> phi_bb349_17;
  TNode<BoolT> phi_bb349_18;
  TNode<IntPtrT> phi_bb349_27;
  TNode<IntPtrT> phi_bb349_28;
  TNode<IntPtrT> phi_bb349_29;
  TNode<IntPtrT> phi_bb349_30;
  TNode<IntPtrT> phi_bb349_33;
  TNode<BoolT> phi_bb349_34;
  TNode<BoolT> phi_bb349_35;
  TNode<Union<FixedArray, Smi>> phi_bb349_36;
  TNode<Int32T> phi_bb349_37;
  TNode<Int32T> phi_bb349_39;
  if (block349.is_used()) {
    ca_.Bind(&block349, &phi_bb349_16, &phi_bb349_17, &phi_bb349_18, &phi_bb349_27, &phi_bb349_28, &phi_bb349_29, &phi_bb349_30, &phi_bb349_33, &phi_bb349_34, &phi_bb349_35, &phi_bb349_36, &phi_bb349_37, &phi_bb349_39);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block351, phi_bb349_16, phi_bb349_17, phi_bb349_18, phi_bb349_27, phi_bb349_28, phi_bb349_29, phi_bb349_30, phi_bb349_33, phi_bb349_34, phi_bb349_35, phi_bb349_36, phi_bb349_37, phi_bb349_39);
    } else {
      ca_.Goto(&block352, phi_bb349_16, phi_bb349_17, phi_bb349_18, phi_bb349_27, phi_bb349_28, phi_bb349_29, phi_bb349_30, phi_bb349_33, phi_bb349_34, phi_bb349_35, phi_bb349_36, phi_bb349_37, phi_bb349_39);
    }
  }

  TNode<JSAny> phi_bb351_16;
  TNode<IntPtrT> phi_bb351_17;
  TNode<BoolT> phi_bb351_18;
  TNode<IntPtrT> phi_bb351_27;
  TNode<IntPtrT> phi_bb351_28;
  TNode<IntPtrT> phi_bb351_29;
  TNode<IntPtrT> phi_bb351_30;
  TNode<IntPtrT> phi_bb351_33;
  TNode<BoolT> phi_bb351_34;
  TNode<BoolT> phi_bb351_35;
  TNode<Union<FixedArray, Smi>> phi_bb351_36;
  TNode<Int32T> phi_bb351_37;
  TNode<Int32T> phi_bb351_39;
  TNode<Union<HeapObject, TaggedIndex>> tmp712;
  TNode<IntPtrT> tmp713;
  TNode<IntPtrT> tmp714;
  TNode<IntPtrT> tmp715;
  if (block351.is_used()) {
    ca_.Bind(&block351, &phi_bb351_16, &phi_bb351_17, &phi_bb351_18, &phi_bb351_27, &phi_bb351_28, &phi_bb351_29, &phi_bb351_30, &phi_bb351_33, &phi_bb351_34, &phi_bb351_35, &phi_bb351_36, &phi_bb351_37, &phi_bb351_39);
    std::tie(tmp712, tmp713) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp197}, TNode<IntPtrT>{phi_bb351_30}).Flatten();
    tmp714 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp715 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb351_30}, TNode<IntPtrT>{tmp714});
    ca_.Goto(&block350, phi_bb351_16, phi_bb351_17, phi_bb351_18, phi_bb351_27, phi_bb351_28, phi_bb351_29, tmp715, phi_bb351_33, phi_bb351_34, phi_bb351_35, phi_bb351_36, phi_bb351_37, phi_bb351_39, tmp712, tmp713);
  }

  TNode<JSAny> phi_bb352_16;
  TNode<IntPtrT> phi_bb352_17;
  TNode<BoolT> phi_bb352_18;
  TNode<IntPtrT> phi_bb352_27;
  TNode<IntPtrT> phi_bb352_28;
  TNode<IntPtrT> phi_bb352_29;
  TNode<IntPtrT> phi_bb352_30;
  TNode<IntPtrT> phi_bb352_33;
  TNode<BoolT> phi_bb352_34;
  TNode<BoolT> phi_bb352_35;
  TNode<Union<FixedArray, Smi>> phi_bb352_36;
  TNode<Int32T> phi_bb352_37;
  TNode<Int32T> phi_bb352_39;
  TNode<IntPtrT> tmp716;
  TNode<BoolT> tmp717;
  if (block352.is_used()) {
    ca_.Bind(&block352, &phi_bb352_16, &phi_bb352_17, &phi_bb352_18, &phi_bb352_27, &phi_bb352_28, &phi_bb352_29, &phi_bb352_30, &phi_bb352_33, &phi_bb352_34, &phi_bb352_35, &phi_bb352_36, &phi_bb352_37, &phi_bb352_39);
    tmp716 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp717 = CodeStubAssembler(state_).WordNotEqual(TNode<IntPtrT>{phi_bb352_33}, TNode<IntPtrT>{tmp716});
    ca_.Branch(tmp717, &block354, std::vector<compiler::Node*>{phi_bb352_16, phi_bb352_17, phi_bb352_18, phi_bb352_27, phi_bb352_28, phi_bb352_29, phi_bb352_30, phi_bb352_33, phi_bb352_34, phi_bb352_35, phi_bb352_36, phi_bb352_37, phi_bb352_39}, &block355, std::vector<compiler::Node*>{phi_bb352_16, phi_bb352_17, phi_bb352_18, phi_bb352_27, phi_bb352_28, phi_bb352_29, phi_bb352_30, phi_bb352_33, phi_bb352_34, phi_bb352_35, phi_bb352_36, phi_bb352_37, phi_bb352_39});
  }

  TNode<JSAny> phi_bb354_16;
  TNode<IntPtrT> phi_bb354_17;
  TNode<BoolT> phi_bb354_18;
  TNode<IntPtrT> phi_bb354_27;
  TNode<IntPtrT> phi_bb354_28;
  TNode<IntPtrT> phi_bb354_29;
  TNode<IntPtrT> phi_bb354_30;
  TNode<IntPtrT> phi_bb354_33;
  TNode<BoolT> phi_bb354_34;
  TNode<BoolT> phi_bb354_35;
  TNode<Union<FixedArray, Smi>> phi_bb354_36;
  TNode<Int32T> phi_bb354_37;
  TNode<Int32T> phi_bb354_39;
  TNode<Union<HeapObject, TaggedIndex>> tmp718;
  TNode<IntPtrT> tmp719;
  TNode<IntPtrT> tmp720;
  TNode<BoolT> tmp721;
  if (block354.is_used()) {
    ca_.Bind(&block354, &phi_bb354_16, &phi_bb354_17, &phi_bb354_18, &phi_bb354_27, &phi_bb354_28, &phi_bb354_29, &phi_bb354_30, &phi_bb354_33, &phi_bb354_34, &phi_bb354_35, &phi_bb354_36, &phi_bb354_37, &phi_bb354_39);
    std::tie(tmp718, tmp719) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp197}, TNode<IntPtrT>{phi_bb354_33}).Flatten();
    tmp720 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp721 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block350, phi_bb354_16, phi_bb354_17, phi_bb354_18, phi_bb354_27, phi_bb354_28, phi_bb354_29, phi_bb354_30, tmp720, tmp721, phi_bb354_35, phi_bb354_36, phi_bb354_37, phi_bb354_39, tmp718, tmp719);
  }

  TNode<JSAny> phi_bb355_16;
  TNode<IntPtrT> phi_bb355_17;
  TNode<BoolT> phi_bb355_18;
  TNode<IntPtrT> phi_bb355_27;
  TNode<IntPtrT> phi_bb355_28;
  TNode<IntPtrT> phi_bb355_29;
  TNode<IntPtrT> phi_bb355_30;
  TNode<IntPtrT> phi_bb355_33;
  TNode<BoolT> phi_bb355_34;
  TNode<BoolT> phi_bb355_35;
  TNode<Union<FixedArray, Smi>> phi_bb355_36;
  TNode<Int32T> phi_bb355_37;
  TNode<Int32T> phi_bb355_39;
  TNode<Union<HeapObject, TaggedIndex>> tmp722;
  TNode<IntPtrT> tmp723;
  TNode<IntPtrT> tmp724;
  TNode<IntPtrT> tmp725;
  TNode<IntPtrT> tmp726;
  TNode<IntPtrT> tmp727;
  TNode<BoolT> tmp728;
  if (block355.is_used()) {
    ca_.Bind(&block355, &phi_bb355_16, &phi_bb355_17, &phi_bb355_18, &phi_bb355_27, &phi_bb355_28, &phi_bb355_29, &phi_bb355_30, &phi_bb355_33, &phi_bb355_34, &phi_bb355_35, &phi_bb355_36, &phi_bb355_37, &phi_bb355_39);
    std::tie(tmp722, tmp723) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp197}, TNode<IntPtrT>{phi_bb355_30}).Flatten();
    tmp724 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp725 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb355_30}, TNode<IntPtrT>{tmp724});
    tmp726 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp727 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp725}, TNode<IntPtrT>{tmp726});
    tmp728 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block350, phi_bb355_16, phi_bb355_17, phi_bb355_18, phi_bb355_27, phi_bb355_28, phi_bb355_29, tmp727, tmp725, tmp728, phi_bb355_35, phi_bb355_36, phi_bb355_37, phi_bb355_39, tmp722, tmp723);
  }

  TNode<JSAny> phi_bb350_16;
  TNode<IntPtrT> phi_bb350_17;
  TNode<BoolT> phi_bb350_18;
  TNode<IntPtrT> phi_bb350_27;
  TNode<IntPtrT> phi_bb350_28;
  TNode<IntPtrT> phi_bb350_29;
  TNode<IntPtrT> phi_bb350_30;
  TNode<IntPtrT> phi_bb350_33;
  TNode<BoolT> phi_bb350_34;
  TNode<BoolT> phi_bb350_35;
  TNode<Union<FixedArray, Smi>> phi_bb350_36;
  TNode<Int32T> phi_bb350_37;
  TNode<Int32T> phi_bb350_39;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb350_44;
  TNode<IntPtrT> phi_bb350_45;
  if (block350.is_used()) {
    ca_.Bind(&block350, &phi_bb350_16, &phi_bb350_17, &phi_bb350_18, &phi_bb350_27, &phi_bb350_28, &phi_bb350_29, &phi_bb350_30, &phi_bb350_33, &phi_bb350_34, &phi_bb350_35, &phi_bb350_36, &phi_bb350_37, &phi_bb350_39, &phi_bb350_44, &phi_bb350_45);
    ca_.Goto(&block347, phi_bb350_16, phi_bb350_17, phi_bb350_18, phi_bb350_27, phi_bb350_28, phi_bb350_29, phi_bb350_30, phi_bb350_33, phi_bb350_34, phi_bb350_35, phi_bb350_36, phi_bb350_37, phi_bb350_39, phi_bb350_44, phi_bb350_45);
  }

  TNode<JSAny> phi_bb347_16;
  TNode<IntPtrT> phi_bb347_17;
  TNode<BoolT> phi_bb347_18;
  TNode<IntPtrT> phi_bb347_27;
  TNode<IntPtrT> phi_bb347_28;
  TNode<IntPtrT> phi_bb347_29;
  TNode<IntPtrT> phi_bb347_30;
  TNode<IntPtrT> phi_bb347_33;
  TNode<BoolT> phi_bb347_34;
  TNode<BoolT> phi_bb347_35;
  TNode<Union<FixedArray, Smi>> phi_bb347_36;
  TNode<Int32T> phi_bb347_37;
  TNode<Int32T> phi_bb347_39;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb347_44;
  TNode<IntPtrT> phi_bb347_45;
  TNode<IntPtrT> tmp729;
      TNode<JSAny> tmp731;
  TNode<Int32T> tmp732;
      TNode<JSAny> tmp734;
  TNode<Int32T> tmp735;
      TNode<JSAny> tmp737;
  if (block347.is_used()) {
    ca_.Bind(&block347, &phi_bb347_16, &phi_bb347_17, &phi_bb347_18, &phi_bb347_27, &phi_bb347_28, &phi_bb347_29, &phi_bb347_30, &phi_bb347_33, &phi_bb347_34, &phi_bb347_35, &phi_bb347_36, &phi_bb347_37, &phi_bb347_39, &phi_bb347_44, &phi_bb347_45);
    compiler::CodeAssemblerExceptionHandlerLabel catch730__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch730__label);
    tmp729 = CodeStubAssembler(state_).BitcastTaggedToWord(TNode<Object>{tmp703});
    }
    if (catch730__label.is_used()) {
      compiler::CodeAssemblerLabel catch730_skip(&ca_);
      ca_.Goto(&catch730_skip);
      ca_.Bind(&catch730__label, &tmp731);
      ca_.Goto(&block356, phi_bb347_16, phi_bb347_17, phi_bb347_18, phi_bb347_27, phi_bb347_28, phi_bb347_29, phi_bb347_30, phi_bb347_33, phi_bb347_34, phi_bb347_35, phi_bb347_36, phi_bb347_37, phi_bb347_39, phi_bb347_44, phi_bb347_45, phi_bb347_44, phi_bb347_45);
      ca_.Bind(&catch730_skip);
    }
    CodeStubAssembler(state_).StoreReference<IntPtrT>(CodeStubAssembler::Reference{phi_bb347_44, phi_bb347_45}, tmp729);
    compiler::CodeAssemblerExceptionHandlerLabel catch733__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch733__label);
    tmp732 = FromConstexpr_int32_constexpr_int31_0(state_, 1);
    }
    if (catch733__label.is_used()) {
      compiler::CodeAssemblerLabel catch733_skip(&ca_);
      ca_.Goto(&catch733_skip);
      ca_.Bind(&catch733__label, &tmp734);
      ca_.Goto(&block357, phi_bb347_16, phi_bb347_17, phi_bb347_18, phi_bb347_27, phi_bb347_28, phi_bb347_29, phi_bb347_30, phi_bb347_33, phi_bb347_34, phi_bb347_35, phi_bb347_36, phi_bb347_37, phi_bb347_39, phi_bb347_44, phi_bb347_45, phi_bb347_39, phi_bb347_39);
      ca_.Bind(&catch733_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch736__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch736__label);
    tmp735 = CodeStubAssembler(state_).Int32Add(TNode<Int32T>{phi_bb347_39}, TNode<Int32T>{tmp732});
    }
    if (catch736__label.is_used()) {
      compiler::CodeAssemblerLabel catch736_skip(&ca_);
      ca_.Goto(&catch736_skip);
      ca_.Bind(&catch736__label, &tmp737);
      ca_.Goto(&block358, phi_bb347_16, phi_bb347_17, phi_bb347_18, phi_bb347_27, phi_bb347_28, phi_bb347_29, phi_bb347_30, phi_bb347_33, phi_bb347_34, phi_bb347_35, phi_bb347_36, phi_bb347_37, phi_bb347_39, phi_bb347_44, phi_bb347_45, phi_bb347_39);
      ca_.Bind(&catch736_skip);
    }
    ca_.Goto(&block314, phi_bb347_16, phi_bb347_17, phi_bb347_18, tmp705, phi_bb347_27, phi_bb347_28, phi_bb347_29, phi_bb347_30, phi_bb347_33, phi_bb347_34, phi_bb347_35, phi_bb347_36, phi_bb347_37, tmp735, tmp685);
  }

  TNode<JSAny> phi_bb356_16;
  TNode<IntPtrT> phi_bb356_17;
  TNode<BoolT> phi_bb356_18;
  TNode<IntPtrT> phi_bb356_27;
  TNode<IntPtrT> phi_bb356_28;
  TNode<IntPtrT> phi_bb356_29;
  TNode<IntPtrT> phi_bb356_30;
  TNode<IntPtrT> phi_bb356_33;
  TNode<BoolT> phi_bb356_34;
  TNode<BoolT> phi_bb356_35;
  TNode<Union<FixedArray, Smi>> phi_bb356_36;
  TNode<Int32T> phi_bb356_37;
  TNode<Int32T> phi_bb356_39;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb356_44;
  TNode<IntPtrT> phi_bb356_45;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb356_46;
  TNode<IntPtrT> phi_bb356_47;
  TNode<Union<Hole, JSMessageObject>> tmp738;
  if (block356.is_used()) {
    ca_.Bind(&block356, &phi_bb356_16, &phi_bb356_17, &phi_bb356_18, &phi_bb356_27, &phi_bb356_28, &phi_bb356_29, &phi_bb356_30, &phi_bb356_33, &phi_bb356_34, &phi_bb356_35, &phi_bb356_36, &phi_bb356_37, &phi_bb356_39, &phi_bb356_44, &phi_bb356_45, &phi_bb356_46, &phi_bb356_47);
    tmp738 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb356_16, phi_bb356_17, phi_bb356_18, tmp731, tmp738);
  }

  TNode<JSAny> phi_bb357_16;
  TNode<IntPtrT> phi_bb357_17;
  TNode<BoolT> phi_bb357_18;
  TNode<IntPtrT> phi_bb357_27;
  TNode<IntPtrT> phi_bb357_28;
  TNode<IntPtrT> phi_bb357_29;
  TNode<IntPtrT> phi_bb357_30;
  TNode<IntPtrT> phi_bb357_33;
  TNode<BoolT> phi_bb357_34;
  TNode<BoolT> phi_bb357_35;
  TNode<Union<FixedArray, Smi>> phi_bb357_36;
  TNode<Int32T> phi_bb357_37;
  TNode<Int32T> phi_bb357_39;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb357_44;
  TNode<IntPtrT> phi_bb357_45;
  TNode<Int32T> phi_bb357_46;
  TNode<Int32T> phi_bb357_47;
  TNode<Union<Hole, JSMessageObject>> tmp739;
  if (block357.is_used()) {
    ca_.Bind(&block357, &phi_bb357_16, &phi_bb357_17, &phi_bb357_18, &phi_bb357_27, &phi_bb357_28, &phi_bb357_29, &phi_bb357_30, &phi_bb357_33, &phi_bb357_34, &phi_bb357_35, &phi_bb357_36, &phi_bb357_37, &phi_bb357_39, &phi_bb357_44, &phi_bb357_45, &phi_bb357_46, &phi_bb357_47);
    tmp739 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb357_16, phi_bb357_17, phi_bb357_18, tmp734, tmp739);
  }

  TNode<JSAny> phi_bb358_16;
  TNode<IntPtrT> phi_bb358_17;
  TNode<BoolT> phi_bb358_18;
  TNode<IntPtrT> phi_bb358_27;
  TNode<IntPtrT> phi_bb358_28;
  TNode<IntPtrT> phi_bb358_29;
  TNode<IntPtrT> phi_bb358_30;
  TNode<IntPtrT> phi_bb358_33;
  TNode<BoolT> phi_bb358_34;
  TNode<BoolT> phi_bb358_35;
  TNode<Union<FixedArray, Smi>> phi_bb358_36;
  TNode<Int32T> phi_bb358_37;
  TNode<Int32T> phi_bb358_39;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb358_44;
  TNode<IntPtrT> phi_bb358_45;
  TNode<Int32T> phi_bb358_46;
  TNode<Union<Hole, JSMessageObject>> tmp740;
  if (block358.is_used()) {
    ca_.Bind(&block358, &phi_bb358_16, &phi_bb358_17, &phi_bb358_18, &phi_bb358_27, &phi_bb358_28, &phi_bb358_29, &phi_bb358_30, &phi_bb358_33, &phi_bb358_34, &phi_bb358_35, &phi_bb358_36, &phi_bb358_37, &phi_bb358_39, &phi_bb358_44, &phi_bb358_45, &phi_bb358_46);
    tmp740 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb358_16, phi_bb358_17, phi_bb358_18, tmp737, tmp740);
  }

  TNode<JSAny> phi_bb313_16;
  TNode<IntPtrT> phi_bb313_17;
  TNode<BoolT> phi_bb313_18;
  TNode<IntPtrT> phi_bb313_26;
  TNode<IntPtrT> phi_bb313_27;
  TNode<IntPtrT> phi_bb313_28;
  TNode<IntPtrT> phi_bb313_29;
  TNode<IntPtrT> phi_bb313_30;
  TNode<IntPtrT> phi_bb313_33;
  TNode<BoolT> phi_bb313_34;
  TNode<BoolT> phi_bb313_35;
  TNode<Union<FixedArray, Smi>> phi_bb313_36;
  TNode<Int32T> phi_bb313_37;
  TNode<Int32T> phi_bb313_39;
  TNode<Int32T> phi_bb313_40;
  if (block313.is_used()) {
    ca_.Bind(&block313, &phi_bb313_16, &phi_bb313_17, &phi_bb313_18, &phi_bb313_26, &phi_bb313_27, &phi_bb313_28, &phi_bb313_29, &phi_bb313_30, &phi_bb313_33, &phi_bb313_34, &phi_bb313_35, &phi_bb313_36, &phi_bb313_37, &phi_bb313_39, &phi_bb313_40);
    ca_.Goto(&block306, phi_bb313_16, phi_bb313_17, phi_bb313_18, phi_bb313_26, phi_bb313_27, phi_bb313_28, phi_bb313_29, phi_bb313_30, phi_bb313_33, phi_bb313_34, phi_bb313_35, phi_bb313_36, phi_bb313_37);
  }

  TNode<JSAny> phi_bb306_16;
  TNode<IntPtrT> phi_bb306_17;
  TNode<BoolT> phi_bb306_18;
  TNode<IntPtrT> phi_bb306_26;
  TNode<IntPtrT> phi_bb306_27;
  TNode<IntPtrT> phi_bb306_28;
  TNode<IntPtrT> phi_bb306_29;
  TNode<IntPtrT> phi_bb306_30;
  TNode<IntPtrT> phi_bb306_33;
  TNode<BoolT> phi_bb306_34;
  TNode<BoolT> phi_bb306_35;
  TNode<Union<FixedArray, Smi>> phi_bb306_36;
  TNode<Int32T> phi_bb306_37;
  TNode<RawPtrT> tmp741;
  TNode<RawPtrT> tmp742;
  if (block306.is_used()) {
    ca_.Bind(&block306, &phi_bb306_16, &phi_bb306_17, &phi_bb306_18, &phi_bb306_26, &phi_bb306_27, &phi_bb306_28, &phi_bb306_29, &phi_bb306_30, &phi_bb306_33, &phi_bb306_34, &phi_bb306_35, &phi_bb306_36, &phi_bb306_37);
    tmp741 = CodeStubAssembler(state_).GCUnsafeReferenceToRawPtr(TNode<Union<HeapObject, TaggedIndex>>{phi_bb133_22}, TNode<IntPtrT>{phi_bb133_23});
    tmp742 = (TNode<RawPtrT>{tmp741});
    ca_.Branch(phi_bb306_34, &block361, std::vector<compiler::Node*>{phi_bb306_16, phi_bb306_17, phi_bb306_18, phi_bb306_26, phi_bb306_27, phi_bb306_28, phi_bb306_29, phi_bb306_30, phi_bb306_33, phi_bb306_34, phi_bb306_35, phi_bb306_36, phi_bb306_37, phi_bb306_30}, &block362, std::vector<compiler::Node*>{phi_bb306_16, phi_bb306_17, phi_bb306_18, phi_bb306_26, phi_bb306_27, phi_bb306_28, phi_bb306_29, phi_bb306_30, phi_bb306_33, phi_bb306_34, phi_bb306_35, phi_bb306_36, phi_bb306_37, phi_bb306_30});
  }

  TNode<JSAny> phi_bb361_16;
  TNode<IntPtrT> phi_bb361_17;
  TNode<BoolT> phi_bb361_18;
  TNode<IntPtrT> phi_bb361_26;
  TNode<IntPtrT> phi_bb361_27;
  TNode<IntPtrT> phi_bb361_28;
  TNode<IntPtrT> phi_bb361_29;
  TNode<IntPtrT> phi_bb361_30;
  TNode<IntPtrT> phi_bb361_33;
  TNode<BoolT> phi_bb361_34;
  TNode<BoolT> phi_bb361_35;
  TNode<Union<FixedArray, Smi>> phi_bb361_36;
  TNode<Int32T> phi_bb361_37;
  TNode<IntPtrT> phi_bb361_40;
  TNode<IntPtrT> tmp743;
  TNode<IntPtrT> tmp744;
  if (block361.is_used()) {
    ca_.Bind(&block361, &phi_bb361_16, &phi_bb361_17, &phi_bb361_18, &phi_bb361_26, &phi_bb361_27, &phi_bb361_28, &phi_bb361_29, &phi_bb361_30, &phi_bb361_33, &phi_bb361_34, &phi_bb361_35, &phi_bb361_36, &phi_bb361_37, &phi_bb361_40);
    tmp743 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp744 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{phi_bb361_40}, TNode<IntPtrT>{tmp743});
    ca_.Goto(&block362, phi_bb361_16, phi_bb361_17, phi_bb361_18, phi_bb361_26, phi_bb361_27, phi_bb361_28, phi_bb361_29, phi_bb361_30, phi_bb361_33, phi_bb361_34, phi_bb361_35, phi_bb361_36, phi_bb361_37, tmp744);
  }

  TNode<JSAny> phi_bb362_16;
  TNode<IntPtrT> phi_bb362_17;
  TNode<BoolT> phi_bb362_18;
  TNode<IntPtrT> phi_bb362_26;
  TNode<IntPtrT> phi_bb362_27;
  TNode<IntPtrT> phi_bb362_28;
  TNode<IntPtrT> phi_bb362_29;
  TNode<IntPtrT> phi_bb362_30;
  TNode<IntPtrT> phi_bb362_33;
  TNode<BoolT> phi_bb362_34;
  TNode<BoolT> phi_bb362_35;
  TNode<Union<FixedArray, Smi>> phi_bb362_36;
  TNode<Int32T> phi_bb362_37;
  TNode<IntPtrT> phi_bb362_40;
  TNode<RawPtrT> tmp745;
  TNode<IntPtrT> tmp746;
  TNode<BoolT> tmp747;
  if (block362.is_used()) {
    ca_.Bind(&block362, &phi_bb362_16, &phi_bb362_17, &phi_bb362_18, &phi_bb362_26, &phi_bb362_27, &phi_bb362_28, &phi_bb362_29, &phi_bb362_30, &phi_bb362_33, &phi_bb362_34, &phi_bb362_35, &phi_bb362_36, &phi_bb362_37, &phi_bb362_40);
    tmp745 = CodeStubAssembler(state_).GCUnsafeReferenceToRawPtr(TNode<Union<HeapObject, TaggedIndex>>{tmp197}, TNode<IntPtrT>{phi_bb362_40});
    tmp746 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp747 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp204}, TNode<IntPtrT>{tmp746});
    ca_.Branch(tmp747, &block366, std::vector<compiler::Node*>{phi_bb362_16, phi_bb362_17, phi_bb362_18, phi_bb362_26, phi_bb362_27, phi_bb362_28, phi_bb362_29, phi_bb362_30, phi_bb362_33, phi_bb362_34, phi_bb362_35, phi_bb362_36, phi_bb362_37}, &block367, std::vector<compiler::Node*>{phi_bb362_16, phi_bb362_17, phi_bb362_18, phi_bb362_26, phi_bb362_27, phi_bb362_28, phi_bb362_29, phi_bb362_30, phi_bb362_33, phi_bb362_34, phi_bb362_35, phi_bb362_36, phi_bb362_37});
  }

  TNode<JSAny> phi_bb366_16;
  TNode<IntPtrT> phi_bb366_17;
  TNode<BoolT> phi_bb366_18;
  TNode<IntPtrT> phi_bb366_26;
  TNode<IntPtrT> phi_bb366_27;
  TNode<IntPtrT> phi_bb366_28;
  TNode<IntPtrT> phi_bb366_29;
  TNode<IntPtrT> phi_bb366_30;
  TNode<IntPtrT> phi_bb366_33;
  TNode<BoolT> phi_bb366_34;
  TNode<BoolT> phi_bb366_35;
  TNode<Union<FixedArray, Smi>> phi_bb366_36;
  TNode<Int32T> phi_bb366_37;
  TNode<BoolT> tmp748;
  if (block366.is_used()) {
    ca_.Bind(&block366, &phi_bb366_16, &phi_bb366_17, &phi_bb366_18, &phi_bb366_26, &phi_bb366_27, &phi_bb366_28, &phi_bb366_29, &phi_bb366_30, &phi_bb366_33, &phi_bb366_34, &phi_bb366_35, &phi_bb366_36, &phi_bb366_37);
    tmp748 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block368, phi_bb366_16, phi_bb366_17, phi_bb366_18, phi_bb366_26, phi_bb366_27, phi_bb366_28, phi_bb366_29, phi_bb366_30, phi_bb366_33, phi_bb366_34, phi_bb366_35, phi_bb366_36, phi_bb366_37, tmp748);
  }

  TNode<JSAny> phi_bb367_16;
  TNode<IntPtrT> phi_bb367_17;
  TNode<BoolT> phi_bb367_18;
  TNode<IntPtrT> phi_bb367_26;
  TNode<IntPtrT> phi_bb367_27;
  TNode<IntPtrT> phi_bb367_28;
  TNode<IntPtrT> phi_bb367_29;
  TNode<IntPtrT> phi_bb367_30;
  TNode<IntPtrT> phi_bb367_33;
  TNode<BoolT> phi_bb367_34;
  TNode<BoolT> phi_bb367_35;
  TNode<Union<FixedArray, Smi>> phi_bb367_36;
  TNode<Int32T> phi_bb367_37;
  TNode<BoolT> tmp749;
  if (block367.is_used()) {
    ca_.Bind(&block367, &phi_bb367_16, &phi_bb367_17, &phi_bb367_18, &phi_bb367_26, &phi_bb367_27, &phi_bb367_28, &phi_bb367_29, &phi_bb367_30, &phi_bb367_33, &phi_bb367_34, &phi_bb367_35, &phi_bb367_36, &phi_bb367_37);
    tmp749 = CodeStubAssembler(state_).IntPtrLessThanOrEqual(TNode<IntPtrT>{phi_bb367_30}, TNode<IntPtrT>{tmp204});
    ca_.Goto(&block368, phi_bb367_16, phi_bb367_17, phi_bb367_18, phi_bb367_26, phi_bb367_27, phi_bb367_28, phi_bb367_29, phi_bb367_30, phi_bb367_33, phi_bb367_34, phi_bb367_35, phi_bb367_36, phi_bb367_37, tmp749);
  }

  TNode<JSAny> phi_bb368_16;
  TNode<IntPtrT> phi_bb368_17;
  TNode<BoolT> phi_bb368_18;
  TNode<IntPtrT> phi_bb368_26;
  TNode<IntPtrT> phi_bb368_27;
  TNode<IntPtrT> phi_bb368_28;
  TNode<IntPtrT> phi_bb368_29;
  TNode<IntPtrT> phi_bb368_30;
  TNode<IntPtrT> phi_bb368_33;
  TNode<BoolT> phi_bb368_34;
  TNode<BoolT> phi_bb368_35;
  TNode<Union<FixedArray, Smi>> phi_bb368_36;
  TNode<Int32T> phi_bb368_37;
  TNode<BoolT> phi_bb368_42;
  if (block368.is_used()) {
    ca_.Bind(&block368, &phi_bb368_16, &phi_bb368_17, &phi_bb368_18, &phi_bb368_26, &phi_bb368_27, &phi_bb368_28, &phi_bb368_29, &phi_bb368_30, &phi_bb368_33, &phi_bb368_34, &phi_bb368_35, &phi_bb368_36, &phi_bb368_37, &phi_bb368_42);
    ca_.Branch(phi_bb368_42, &block364, std::vector<compiler::Node*>{phi_bb368_16, phi_bb368_17, phi_bb368_18, phi_bb368_26, phi_bb368_27, phi_bb368_28, phi_bb368_29, phi_bb368_30, phi_bb368_33, phi_bb368_34, phi_bb368_35, phi_bb368_36, phi_bb368_37}, &block365, std::vector<compiler::Node*>{phi_bb368_16, phi_bb368_17, phi_bb368_18, phi_bb368_26, phi_bb368_27, phi_bb368_28, phi_bb368_29, phi_bb368_30, phi_bb368_33, phi_bb368_34, phi_bb368_35, phi_bb368_36, phi_bb368_37});
  }

  TNode<JSAny> phi_bb365_16;
  TNode<IntPtrT> phi_bb365_17;
  TNode<BoolT> phi_bb365_18;
  TNode<IntPtrT> phi_bb365_26;
  TNode<IntPtrT> phi_bb365_27;
  TNode<IntPtrT> phi_bb365_28;
  TNode<IntPtrT> phi_bb365_29;
  TNode<IntPtrT> phi_bb365_30;
  TNode<IntPtrT> phi_bb365_33;
  TNode<BoolT> phi_bb365_34;
  TNode<BoolT> phi_bb365_35;
  TNode<Union<FixedArray, Smi>> phi_bb365_36;
  TNode<Int32T> phi_bb365_37;
  if (block365.is_used()) {
    ca_.Bind(&block365, &phi_bb365_16, &phi_bb365_17, &phi_bb365_18, &phi_bb365_26, &phi_bb365_27, &phi_bb365_28, &phi_bb365_29, &phi_bb365_30, &phi_bb365_33, &phi_bb365_34, &phi_bb365_35, &phi_bb365_36, &phi_bb365_37);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/js-to-wasm.tq", 379});
      CodeStubAssembler(state_).FailAssert("Torque assert 'this.paramBufferEnd == 0 || this.nextStack <= this.paramBufferEnd' failed", pos_stack);
    }
  }

  TNode<JSAny> phi_bb364_16;
  TNode<IntPtrT> phi_bb364_17;
  TNode<BoolT> phi_bb364_18;
  TNode<IntPtrT> phi_bb364_26;
  TNode<IntPtrT> phi_bb364_27;
  TNode<IntPtrT> phi_bb364_28;
  TNode<IntPtrT> phi_bb364_29;
  TNode<IntPtrT> phi_bb364_30;
  TNode<IntPtrT> phi_bb364_33;
  TNode<BoolT> phi_bb364_34;
  TNode<BoolT> phi_bb364_35;
  TNode<Union<FixedArray, Smi>> phi_bb364_36;
  TNode<Int32T> phi_bb364_37;
  TNode<WasmInternalFunction> tmp750;
      TNode<JSAny> tmp752;
  TNode<IntPtrT> tmp753;
      TNode<JSAny> tmp755;
  TNode<Uint32T> tmp756;
  TNode<RawPtrT> tmp757;
      TNode<JSAny> tmp759;
  TNode<RawPtrT> tmp760;
  TNode<IntPtrT> tmp761;
      TNode<JSAny> tmp763;
  TNode<Union<HeapObject, TaggedIndex>> tmp764;
  TNode<IntPtrT> tmp765;
      TNode<JSAny> tmp767;
  TNode<IntPtrT> tmp768;
      TNode<JSAny> tmp770;
  TNode<Union<HeapObject, TaggedIndex>> tmp771;
  TNode<IntPtrT> tmp772;
      TNode<JSAny> tmp774;
  TNode<IntPtrT> tmp775;
      TNode<JSAny> tmp777;
  TNode<Union<HeapObject, TaggedIndex>> tmp778;
  TNode<IntPtrT> tmp779;
      TNode<JSAny> tmp781;
  TNode<IntPtrT> tmp782;
      TNode<JSAny> tmp784;
  TNode<Union<HeapObject, TaggedIndex>> tmp785;
  TNode<IntPtrT> tmp786;
      TNode<JSAny> tmp788;
  TNode<IntPtrT> tmp789;
      TNode<JSAny> tmp791;
  TNode<Union<HeapObject, TaggedIndex>> tmp792;
  TNode<IntPtrT> tmp793;
      TNode<JSAny> tmp795;
  TNode<IntPtrT> tmp796;
      TNode<JSAny> tmp798;
  TNode<Union<HeapObject, TaggedIndex>> tmp799;
  TNode<IntPtrT> tmp800;
      TNode<JSAny> tmp802;
  TNode<IntPtrT> tmp803;
      TNode<JSAny> tmp805;
  TNode<Union<HeapObject, TaggedIndex>> tmp806;
  TNode<IntPtrT> tmp807;
      TNode<JSAny> tmp809;
  if (block364.is_used()) {
    ca_.Bind(&block364, &phi_bb364_16, &phi_bb364_17, &phi_bb364_18, &phi_bb364_26, &phi_bb364_27, &phi_bb364_28, &phi_bb364_29, &phi_bb364_30, &phi_bb364_33, &phi_bb364_34, &phi_bb364_35, &phi_bb364_36, &phi_bb364_37);
    compiler::CodeAssemblerExceptionHandlerLabel catch751__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch751__label);
    tmp750 = CodeStubAssembler(state_).LoadWasmInternalFunctionFromFunctionData(TNode<WasmFunctionData>{tmp2});
    }
    if (catch751__label.is_used()) {
      compiler::CodeAssemblerLabel catch751_skip(&ca_);
      ca_.Goto(&catch751_skip);
      ca_.Bind(&catch751__label, &tmp752);
      ca_.Goto(&block369, phi_bb364_16, phi_bb364_17, phi_bb364_18, phi_bb364_26, phi_bb364_27, phi_bb364_28, phi_bb364_29, phi_bb364_30, phi_bb364_33, phi_bb364_34, phi_bb364_35, phi_bb364_36, phi_bb364_37);
      ca_.Bind(&catch751_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch754__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch754__label);
    tmp753 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
    }
    if (catch754__label.is_used()) {
      compiler::CodeAssemblerLabel catch754_skip(&ca_);
      ca_.Goto(&catch754_skip);
      ca_.Bind(&catch754__label, &tmp755);
      ca_.Goto(&block370, phi_bb364_16, phi_bb364_17, phi_bb364_18, phi_bb364_26, phi_bb364_27, phi_bb364_28, phi_bb364_29, phi_bb364_30, phi_bb364_33, phi_bb364_34, phi_bb364_35, phi_bb364_36, phi_bb364_37);
      ca_.Bind(&catch754_skip);
    }
    tmp756 = CodeStubAssembler(state_).LoadReference<Uint32T>(CodeStubAssembler::Reference{tmp750, tmp753});
    compiler::CodeAssemblerExceptionHandlerLabel catch758__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch758__label);
    tmp757 = CodeStubAssembler(state_).StackSlotPtr(JSToWasmWrapperFrameConstants::kWrapperBufferSize, (SizeOf_intptr_0(state_)));
    }
    if (catch758__label.is_used()) {
      compiler::CodeAssemblerLabel catch758_skip(&ca_);
      ca_.Goto(&catch758_skip);
      ca_.Bind(&catch758__label, &tmp759);
      ca_.Goto(&block371, phi_bb364_16, phi_bb364_17, phi_bb364_18, phi_bb364_26, phi_bb364_27, phi_bb364_28, phi_bb364_29, phi_bb364_30, phi_bb364_33, phi_bb364_34, phi_bb364_35, phi_bb364_36, phi_bb364_37);
      ca_.Bind(&catch758_skip);
    }
    tmp760 = (TNode<RawPtrT>{tmp757});
    compiler::CodeAssemblerExceptionHandlerLabel catch762__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch762__label);
    tmp761 = FromConstexpr_intptr_constexpr_intptr_0(state_, JSToWasmWrapperFrameConstants::kWrapperBufferReturnCount);
    }
    if (catch762__label.is_used()) {
      compiler::CodeAssemblerLabel catch762_skip(&ca_);
      ca_.Goto(&catch762_skip);
      ca_.Bind(&catch762__label, &tmp763);
      ca_.Goto(&block372, phi_bb364_16, phi_bb364_17, phi_bb364_18, phi_bb364_26, phi_bb364_27, phi_bb364_28, phi_bb364_29, phi_bb364_30, phi_bb364_33, phi_bb364_34, phi_bb364_35, phi_bb364_36, phi_bb364_37);
      ca_.Bind(&catch762_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch766__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch766__label);
    std::tie(tmp764, tmp765) = GetRefAt_int32_RawPtr_intptr_0(state_, TNode<RawPtrT>{tmp760}, TNode<IntPtrT>{tmp761}).Flatten();
    }
    if (catch766__label.is_used()) {
      compiler::CodeAssemblerLabel catch766_skip(&ca_);
      ca_.Goto(&catch766_skip);
      ca_.Bind(&catch766__label, &tmp767);
      ca_.Goto(&block373, phi_bb364_16, phi_bb364_17, phi_bb364_18, phi_bb364_26, phi_bb364_27, phi_bb364_28, phi_bb364_29, phi_bb364_30, phi_bb364_33, phi_bb364_34, phi_bb364_35, phi_bb364_36, phi_bb364_37);
      ca_.Bind(&catch766_skip);
    }
    CodeStubAssembler(state_).StoreReference<Int32T>(CodeStubAssembler::Reference{tmp764, tmp765}, tmp30);
    compiler::CodeAssemblerExceptionHandlerLabel catch769__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch769__label);
    tmp768 = FromConstexpr_intptr_constexpr_intptr_0(state_, JSToWasmWrapperFrameConstants::kWrapperBufferRefReturnCount);
    }
    if (catch769__label.is_used()) {
      compiler::CodeAssemblerLabel catch769_skip(&ca_);
      ca_.Goto(&catch769_skip);
      ca_.Bind(&catch769__label, &tmp770);
      ca_.Goto(&block374, phi_bb364_16, phi_bb364_17, phi_bb364_18, phi_bb364_26, phi_bb364_27, phi_bb364_28, phi_bb364_29, phi_bb364_30, phi_bb364_33, phi_bb364_34, phi_bb364_35, phi_bb364_36, phi_bb364_37);
      ca_.Bind(&catch769_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch773__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch773__label);
    std::tie(tmp771, tmp772) = GetRefAt_bool_RawPtr_intptr_0(state_, TNode<RawPtrT>{tmp760}, TNode<IntPtrT>{tmp768}).Flatten();
    }
    if (catch773__label.is_used()) {
      compiler::CodeAssemblerLabel catch773_skip(&ca_);
      ca_.Goto(&catch773_skip);
      ca_.Bind(&catch773__label, &tmp774);
      ca_.Goto(&block375, phi_bb364_16, phi_bb364_17, phi_bb364_18, phi_bb364_26, phi_bb364_27, phi_bb364_28, phi_bb364_29, phi_bb364_30, phi_bb364_33, phi_bb364_34, phi_bb364_35, phi_bb364_36, phi_bb364_37);
      ca_.Bind(&catch773_skip);
    }
    CodeStubAssembler(state_).StoreReference<BoolT>(CodeStubAssembler::Reference{tmp771, tmp772}, phi_bb364_18);
    compiler::CodeAssemblerExceptionHandlerLabel catch776__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch776__label);
    tmp775 = FromConstexpr_intptr_constexpr_intptr_0(state_, JSToWasmWrapperFrameConstants::kWrapperBufferSigRepresentationArray);
    }
    if (catch776__label.is_used()) {
      compiler::CodeAssemblerLabel catch776_skip(&ca_);
      ca_.Goto(&catch776_skip);
      ca_.Bind(&catch776__label, &tmp777);
      ca_.Goto(&block376, phi_bb364_16, phi_bb364_17, phi_bb364_18, phi_bb364_26, phi_bb364_27, phi_bb364_28, phi_bb364_29, phi_bb364_30, phi_bb364_33, phi_bb364_34, phi_bb364_35, phi_bb364_36, phi_bb364_37);
      ca_.Bind(&catch776_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch780__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch780__label);
    std::tie(tmp778, tmp779) = GetRefAt_RawPtr_RawPtr_intptr_0(state_, TNode<RawPtrT>{tmp760}, TNode<IntPtrT>{tmp775}).Flatten();
    }
    if (catch780__label.is_used()) {
      compiler::CodeAssemblerLabel catch780_skip(&ca_);
      ca_.Goto(&catch780_skip);
      ca_.Bind(&catch780__label, &tmp781);
      ca_.Goto(&block377, phi_bb364_16, phi_bb364_17, phi_bb364_18, phi_bb364_26, phi_bb364_27, phi_bb364_28, phi_bb364_29, phi_bb364_30, phi_bb364_33, phi_bb364_34, phi_bb364_35, phi_bb364_36, phi_bb364_37);
      ca_.Bind(&catch780_skip);
    }
    CodeStubAssembler(state_).StoreReference<RawPtrT>(CodeStubAssembler::Reference{tmp778, tmp779}, tmp34);
    compiler::CodeAssemblerExceptionHandlerLabel catch783__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch783__label);
    tmp782 = FromConstexpr_intptr_constexpr_intptr_0(state_, JSToWasmWrapperFrameConstants::kWrapperBufferStackReturnBufferSize);
    }
    if (catch783__label.is_used()) {
      compiler::CodeAssemblerLabel catch783_skip(&ca_);
      ca_.Goto(&catch783_skip);
      ca_.Bind(&catch783__label, &tmp784);
      ca_.Goto(&block378, phi_bb364_16, phi_bb364_17, phi_bb364_18, phi_bb364_26, phi_bb364_27, phi_bb364_28, phi_bb364_29, phi_bb364_30, phi_bb364_33, phi_bb364_34, phi_bb364_35, phi_bb364_36, phi_bb364_37);
      ca_.Bind(&catch783_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch787__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch787__label);
    std::tie(tmp785, tmp786) = GetRefAt_intptr_RawPtr_intptr_0(state_, TNode<RawPtrT>{tmp760}, TNode<IntPtrT>{tmp782}).Flatten();
    }
    if (catch787__label.is_used()) {
      compiler::CodeAssemblerLabel catch787_skip(&ca_);
      ca_.Goto(&catch787_skip);
      ca_.Bind(&catch787__label, &tmp788);
      ca_.Goto(&block379, phi_bb364_16, phi_bb364_17, phi_bb364_18, phi_bb364_26, phi_bb364_27, phi_bb364_28, phi_bb364_29, phi_bb364_30, phi_bb364_33, phi_bb364_34, phi_bb364_35, phi_bb364_36, phi_bb364_37);
      ca_.Bind(&catch787_skip);
    }
    CodeStubAssembler(state_).StoreReference<IntPtrT>(CodeStubAssembler::Reference{tmp785, tmp786}, phi_bb364_17);
    compiler::CodeAssemblerExceptionHandlerLabel catch790__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch790__label);
    tmp789 = FromConstexpr_intptr_constexpr_intptr_0(state_, JSToWasmWrapperFrameConstants::kWrapperBufferCallTarget);
    }
    if (catch790__label.is_used()) {
      compiler::CodeAssemblerLabel catch790_skip(&ca_);
      ca_.Goto(&catch790_skip);
      ca_.Bind(&catch790__label, &tmp791);
      ca_.Goto(&block380, phi_bb364_16, phi_bb364_17, phi_bb364_18, phi_bb364_26, phi_bb364_27, phi_bb364_28, phi_bb364_29, phi_bb364_30, phi_bb364_33, phi_bb364_34, phi_bb364_35, phi_bb364_36, phi_bb364_37);
      ca_.Bind(&catch790_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch794__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch794__label);
    std::tie(tmp792, tmp793) = GetRefAt_WasmCodePointer_RawPtr_intptr_0(state_, TNode<RawPtrT>{tmp760}, TNode<IntPtrT>{tmp789}).Flatten();
    }
    if (catch794__label.is_used()) {
      compiler::CodeAssemblerLabel catch794_skip(&ca_);
      ca_.Goto(&catch794_skip);
      ca_.Bind(&catch794__label, &tmp795);
      ca_.Goto(&block381, phi_bb364_16, phi_bb364_17, phi_bb364_18, phi_bb364_26, phi_bb364_27, phi_bb364_28, phi_bb364_29, phi_bb364_30, phi_bb364_33, phi_bb364_34, phi_bb364_35, phi_bb364_36, phi_bb364_37);
      ca_.Bind(&catch794_skip);
    }
    CodeStubAssembler(state_).StoreReference<Uint32T>(CodeStubAssembler::Reference{tmp792, tmp793}, tmp756);
    compiler::CodeAssemblerExceptionHandlerLabel catch797__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch797__label);
    tmp796 = FromConstexpr_intptr_constexpr_intptr_0(state_, JSToWasmWrapperFrameConstants::kWrapperBufferParamStart);
    }
    if (catch797__label.is_used()) {
      compiler::CodeAssemblerLabel catch797_skip(&ca_);
      ca_.Goto(&catch797_skip);
      ca_.Bind(&catch797__label, &tmp798);
      ca_.Goto(&block382, phi_bb364_16, phi_bb364_17, phi_bb364_18, phi_bb364_26, phi_bb364_27, phi_bb364_28, phi_bb364_29, phi_bb364_30, phi_bb364_33, phi_bb364_34, phi_bb364_35, phi_bb364_36, phi_bb364_37);
      ca_.Bind(&catch797_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch801__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch801__label);
    std::tie(tmp799, tmp800) = GetRefAt_RawPtr_intptr_RawPtr_intptr_0(state_, TNode<RawPtrT>{tmp760}, TNode<IntPtrT>{tmp796}).Flatten();
    }
    if (catch801__label.is_used()) {
      compiler::CodeAssemblerLabel catch801_skip(&ca_);
      ca_.Goto(&catch801_skip);
      ca_.Bind(&catch801__label, &tmp802);
      ca_.Goto(&block383, phi_bb364_16, phi_bb364_17, phi_bb364_18, phi_bb364_26, phi_bb364_27, phi_bb364_28, phi_bb364_29, phi_bb364_30, phi_bb364_33, phi_bb364_34, phi_bb364_35, phi_bb364_36, phi_bb364_37);
      ca_.Bind(&catch801_skip);
    }
    CodeStubAssembler(state_).StoreReference<RawPtrT>(CodeStubAssembler::Reference{tmp799, tmp800}, tmp742);
    compiler::CodeAssemblerExceptionHandlerLabel catch804__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch804__label);
    tmp803 = FromConstexpr_intptr_constexpr_intptr_0(state_, JSToWasmWrapperFrameConstants::kWrapperBufferParamEnd);
    }
    if (catch804__label.is_used()) {
      compiler::CodeAssemblerLabel catch804_skip(&ca_);
      ca_.Goto(&catch804_skip);
      ca_.Bind(&catch804__label, &tmp805);
      ca_.Goto(&block384, phi_bb364_16, phi_bb364_17, phi_bb364_18, phi_bb364_26, phi_bb364_27, phi_bb364_28, phi_bb364_29, phi_bb364_30, phi_bb364_33, phi_bb364_34, phi_bb364_35, phi_bb364_36, phi_bb364_37);
      ca_.Bind(&catch804_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch808__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch808__label);
    std::tie(tmp806, tmp807) = GetRefAt_RawPtr_RawPtr_intptr_0(state_, TNode<RawPtrT>{tmp760}, TNode<IntPtrT>{tmp803}).Flatten();
    }
    if (catch808__label.is_used()) {
      compiler::CodeAssemblerLabel catch808_skip(&ca_);
      ca_.Goto(&catch808_skip);
      ca_.Bind(&catch808__label, &tmp809);
      ca_.Goto(&block385, phi_bb364_16, phi_bb364_17, phi_bb364_18, phi_bb364_26, phi_bb364_27, phi_bb364_28, phi_bb364_29, phi_bb364_30, phi_bb364_33, phi_bb364_34, phi_bb364_35, phi_bb364_36, phi_bb364_37);
      ca_.Bind(&catch808_skip);
    }
    CodeStubAssembler(state_).StoreReference<RawPtrT>(CodeStubAssembler::Reference{tmp806, tmp807}, tmp745);
    if (((CodeStubAssembler(state_).ConstexprInt32Equal(p_promise, wasm::Promise::kPromise)))) {
      ca_.Goto(&block386, phi_bb364_16, phi_bb364_17, phi_bb364_18, phi_bb364_26, phi_bb364_27, phi_bb364_28, phi_bb364_29, phi_bb364_30, phi_bb364_33, phi_bb364_34, phi_bb364_35, phi_bb364_36, phi_bb364_37);
    } else {
      ca_.Goto(&block387, phi_bb364_16, phi_bb364_17, phi_bb364_18, phi_bb364_26, phi_bb364_27, phi_bb364_28, phi_bb364_29, phi_bb364_30, phi_bb364_33, phi_bb364_34, phi_bb364_35, phi_bb364_36, phi_bb364_37);
    }
  }

  TNode<JSAny> phi_bb369_16;
  TNode<IntPtrT> phi_bb369_17;
  TNode<BoolT> phi_bb369_18;
  TNode<IntPtrT> phi_bb369_26;
  TNode<IntPtrT> phi_bb369_27;
  TNode<IntPtrT> phi_bb369_28;
  TNode<IntPtrT> phi_bb369_29;
  TNode<IntPtrT> phi_bb369_30;
  TNode<IntPtrT> phi_bb369_33;
  TNode<BoolT> phi_bb369_34;
  TNode<BoolT> phi_bb369_35;
  TNode<Union<FixedArray, Smi>> phi_bb369_36;
  TNode<Int32T> phi_bb369_37;
  TNode<Union<Hole, JSMessageObject>> tmp810;
  if (block369.is_used()) {
    ca_.Bind(&block369, &phi_bb369_16, &phi_bb369_17, &phi_bb369_18, &phi_bb369_26, &phi_bb369_27, &phi_bb369_28, &phi_bb369_29, &phi_bb369_30, &phi_bb369_33, &phi_bb369_34, &phi_bb369_35, &phi_bb369_36, &phi_bb369_37);
    tmp810 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb369_16, phi_bb369_17, phi_bb369_18, tmp752, tmp810);
  }

  TNode<JSAny> phi_bb370_16;
  TNode<IntPtrT> phi_bb370_17;
  TNode<BoolT> phi_bb370_18;
  TNode<IntPtrT> phi_bb370_26;
  TNode<IntPtrT> phi_bb370_27;
  TNode<IntPtrT> phi_bb370_28;
  TNode<IntPtrT> phi_bb370_29;
  TNode<IntPtrT> phi_bb370_30;
  TNode<IntPtrT> phi_bb370_33;
  TNode<BoolT> phi_bb370_34;
  TNode<BoolT> phi_bb370_35;
  TNode<Union<FixedArray, Smi>> phi_bb370_36;
  TNode<Int32T> phi_bb370_37;
  TNode<Union<Hole, JSMessageObject>> tmp811;
  if (block370.is_used()) {
    ca_.Bind(&block370, &phi_bb370_16, &phi_bb370_17, &phi_bb370_18, &phi_bb370_26, &phi_bb370_27, &phi_bb370_28, &phi_bb370_29, &phi_bb370_30, &phi_bb370_33, &phi_bb370_34, &phi_bb370_35, &phi_bb370_36, &phi_bb370_37);
    tmp811 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb370_16, phi_bb370_17, phi_bb370_18, tmp755, tmp811);
  }

  TNode<JSAny> phi_bb371_16;
  TNode<IntPtrT> phi_bb371_17;
  TNode<BoolT> phi_bb371_18;
  TNode<IntPtrT> phi_bb371_26;
  TNode<IntPtrT> phi_bb371_27;
  TNode<IntPtrT> phi_bb371_28;
  TNode<IntPtrT> phi_bb371_29;
  TNode<IntPtrT> phi_bb371_30;
  TNode<IntPtrT> phi_bb371_33;
  TNode<BoolT> phi_bb371_34;
  TNode<BoolT> phi_bb371_35;
  TNode<Union<FixedArray, Smi>> phi_bb371_36;
  TNode<Int32T> phi_bb371_37;
  TNode<Union<Hole, JSMessageObject>> tmp812;
  if (block371.is_used()) {
    ca_.Bind(&block371, &phi_bb371_16, &phi_bb371_17, &phi_bb371_18, &phi_bb371_26, &phi_bb371_27, &phi_bb371_28, &phi_bb371_29, &phi_bb371_30, &phi_bb371_33, &phi_bb371_34, &phi_bb371_35, &phi_bb371_36, &phi_bb371_37);
    tmp812 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb371_16, phi_bb371_17, phi_bb371_18, tmp759, tmp812);
  }

  TNode<JSAny> phi_bb372_16;
  TNode<IntPtrT> phi_bb372_17;
  TNode<BoolT> phi_bb372_18;
  TNode<IntPtrT> phi_bb372_26;
  TNode<IntPtrT> phi_bb372_27;
  TNode<IntPtrT> phi_bb372_28;
  TNode<IntPtrT> phi_bb372_29;
  TNode<IntPtrT> phi_bb372_30;
  TNode<IntPtrT> phi_bb372_33;
  TNode<BoolT> phi_bb372_34;
  TNode<BoolT> phi_bb372_35;
  TNode<Union<FixedArray, Smi>> phi_bb372_36;
  TNode<Int32T> phi_bb372_37;
  TNode<Union<Hole, JSMessageObject>> tmp813;
  if (block372.is_used()) {
    ca_.Bind(&block372, &phi_bb372_16, &phi_bb372_17, &phi_bb372_18, &phi_bb372_26, &phi_bb372_27, &phi_bb372_28, &phi_bb372_29, &phi_bb372_30, &phi_bb372_33, &phi_bb372_34, &phi_bb372_35, &phi_bb372_36, &phi_bb372_37);
    tmp813 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb372_16, phi_bb372_17, phi_bb372_18, tmp763, tmp813);
  }

  TNode<JSAny> phi_bb373_16;
  TNode<IntPtrT> phi_bb373_17;
  TNode<BoolT> phi_bb373_18;
  TNode<IntPtrT> phi_bb373_26;
  TNode<IntPtrT> phi_bb373_27;
  TNode<IntPtrT> phi_bb373_28;
  TNode<IntPtrT> phi_bb373_29;
  TNode<IntPtrT> phi_bb373_30;
  TNode<IntPtrT> phi_bb373_33;
  TNode<BoolT> phi_bb373_34;
  TNode<BoolT> phi_bb373_35;
  TNode<Union<FixedArray, Smi>> phi_bb373_36;
  TNode<Int32T> phi_bb373_37;
  TNode<Union<Hole, JSMessageObject>> tmp814;
  if (block373.is_used()) {
    ca_.Bind(&block373, &phi_bb373_16, &phi_bb373_17, &phi_bb373_18, &phi_bb373_26, &phi_bb373_27, &phi_bb373_28, &phi_bb373_29, &phi_bb373_30, &phi_bb373_33, &phi_bb373_34, &phi_bb373_35, &phi_bb373_36, &phi_bb373_37);
    tmp814 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb373_16, phi_bb373_17, phi_bb373_18, tmp767, tmp814);
  }

  TNode<JSAny> phi_bb374_16;
  TNode<IntPtrT> phi_bb374_17;
  TNode<BoolT> phi_bb374_18;
  TNode<IntPtrT> phi_bb374_26;
  TNode<IntPtrT> phi_bb374_27;
  TNode<IntPtrT> phi_bb374_28;
  TNode<IntPtrT> phi_bb374_29;
  TNode<IntPtrT> phi_bb374_30;
  TNode<IntPtrT> phi_bb374_33;
  TNode<BoolT> phi_bb374_34;
  TNode<BoolT> phi_bb374_35;
  TNode<Union<FixedArray, Smi>> phi_bb374_36;
  TNode<Int32T> phi_bb374_37;
  TNode<Union<Hole, JSMessageObject>> tmp815;
  if (block374.is_used()) {
    ca_.Bind(&block374, &phi_bb374_16, &phi_bb374_17, &phi_bb374_18, &phi_bb374_26, &phi_bb374_27, &phi_bb374_28, &phi_bb374_29, &phi_bb374_30, &phi_bb374_33, &phi_bb374_34, &phi_bb374_35, &phi_bb374_36, &phi_bb374_37);
    tmp815 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb374_16, phi_bb374_17, phi_bb374_18, tmp770, tmp815);
  }

  TNode<JSAny> phi_bb375_16;
  TNode<IntPtrT> phi_bb375_17;
  TNode<BoolT> phi_bb375_18;
  TNode<IntPtrT> phi_bb375_26;
  TNode<IntPtrT> phi_bb375_27;
  TNode<IntPtrT> phi_bb375_28;
  TNode<IntPtrT> phi_bb375_29;
  TNode<IntPtrT> phi_bb375_30;
  TNode<IntPtrT> phi_bb375_33;
  TNode<BoolT> phi_bb375_34;
  TNode<BoolT> phi_bb375_35;
  TNode<Union<FixedArray, Smi>> phi_bb375_36;
  TNode<Int32T> phi_bb375_37;
  TNode<Union<Hole, JSMessageObject>> tmp816;
  if (block375.is_used()) {
    ca_.Bind(&block375, &phi_bb375_16, &phi_bb375_17, &phi_bb375_18, &phi_bb375_26, &phi_bb375_27, &phi_bb375_28, &phi_bb375_29, &phi_bb375_30, &phi_bb375_33, &phi_bb375_34, &phi_bb375_35, &phi_bb375_36, &phi_bb375_37);
    tmp816 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb375_16, phi_bb375_17, phi_bb375_18, tmp774, tmp816);
  }

  TNode<JSAny> phi_bb376_16;
  TNode<IntPtrT> phi_bb376_17;
  TNode<BoolT> phi_bb376_18;
  TNode<IntPtrT> phi_bb376_26;
  TNode<IntPtrT> phi_bb376_27;
  TNode<IntPtrT> phi_bb376_28;
  TNode<IntPtrT> phi_bb376_29;
  TNode<IntPtrT> phi_bb376_30;
  TNode<IntPtrT> phi_bb376_33;
  TNode<BoolT> phi_bb376_34;
  TNode<BoolT> phi_bb376_35;
  TNode<Union<FixedArray, Smi>> phi_bb376_36;
  TNode<Int32T> phi_bb376_37;
  TNode<Union<Hole, JSMessageObject>> tmp817;
  if (block376.is_used()) {
    ca_.Bind(&block376, &phi_bb376_16, &phi_bb376_17, &phi_bb376_18, &phi_bb376_26, &phi_bb376_27, &phi_bb376_28, &phi_bb376_29, &phi_bb376_30, &phi_bb376_33, &phi_bb376_34, &phi_bb376_35, &phi_bb376_36, &phi_bb376_37);
    tmp817 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb376_16, phi_bb376_17, phi_bb376_18, tmp777, tmp817);
  }

  TNode<JSAny> phi_bb377_16;
  TNode<IntPtrT> phi_bb377_17;
  TNode<BoolT> phi_bb377_18;
  TNode<IntPtrT> phi_bb377_26;
  TNode<IntPtrT> phi_bb377_27;
  TNode<IntPtrT> phi_bb377_28;
  TNode<IntPtrT> phi_bb377_29;
  TNode<IntPtrT> phi_bb377_30;
  TNode<IntPtrT> phi_bb377_33;
  TNode<BoolT> phi_bb377_34;
  TNode<BoolT> phi_bb377_35;
  TNode<Union<FixedArray, Smi>> phi_bb377_36;
  TNode<Int32T> phi_bb377_37;
  TNode<Union<Hole, JSMessageObject>> tmp818;
  if (block377.is_used()) {
    ca_.Bind(&block377, &phi_bb377_16, &phi_bb377_17, &phi_bb377_18, &phi_bb377_26, &phi_bb377_27, &phi_bb377_28, &phi_bb377_29, &phi_bb377_30, &phi_bb377_33, &phi_bb377_34, &phi_bb377_35, &phi_bb377_36, &phi_bb377_37);
    tmp818 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb377_16, phi_bb377_17, phi_bb377_18, tmp781, tmp818);
  }

  TNode<JSAny> phi_bb378_16;
  TNode<IntPtrT> phi_bb378_17;
  TNode<BoolT> phi_bb378_18;
  TNode<IntPtrT> phi_bb378_26;
  TNode<IntPtrT> phi_bb378_27;
  TNode<IntPtrT> phi_bb378_28;
  TNode<IntPtrT> phi_bb378_29;
  TNode<IntPtrT> phi_bb378_30;
  TNode<IntPtrT> phi_bb378_33;
  TNode<BoolT> phi_bb378_34;
  TNode<BoolT> phi_bb378_35;
  TNode<Union<FixedArray, Smi>> phi_bb378_36;
  TNode<Int32T> phi_bb378_37;
  TNode<Union<Hole, JSMessageObject>> tmp819;
  if (block378.is_used()) {
    ca_.Bind(&block378, &phi_bb378_16, &phi_bb378_17, &phi_bb378_18, &phi_bb378_26, &phi_bb378_27, &phi_bb378_28, &phi_bb378_29, &phi_bb378_30, &phi_bb378_33, &phi_bb378_34, &phi_bb378_35, &phi_bb378_36, &phi_bb378_37);
    tmp819 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb378_16, phi_bb378_17, phi_bb378_18, tmp784, tmp819);
  }

  TNode<JSAny> phi_bb379_16;
  TNode<IntPtrT> phi_bb379_17;
  TNode<BoolT> phi_bb379_18;
  TNode<IntPtrT> phi_bb379_26;
  TNode<IntPtrT> phi_bb379_27;
  TNode<IntPtrT> phi_bb379_28;
  TNode<IntPtrT> phi_bb379_29;
  TNode<IntPtrT> phi_bb379_30;
  TNode<IntPtrT> phi_bb379_33;
  TNode<BoolT> phi_bb379_34;
  TNode<BoolT> phi_bb379_35;
  TNode<Union<FixedArray, Smi>> phi_bb379_36;
  TNode<Int32T> phi_bb379_37;
  TNode<Union<Hole, JSMessageObject>> tmp820;
  if (block379.is_used()) {
    ca_.Bind(&block379, &phi_bb379_16, &phi_bb379_17, &phi_bb379_18, &phi_bb379_26, &phi_bb379_27, &phi_bb379_28, &phi_bb379_29, &phi_bb379_30, &phi_bb379_33, &phi_bb379_34, &phi_bb379_35, &phi_bb379_36, &phi_bb379_37);
    tmp820 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb379_16, phi_bb379_17, phi_bb379_18, tmp788, tmp820);
  }

  TNode<JSAny> phi_bb380_16;
  TNode<IntPtrT> phi_bb380_17;
  TNode<BoolT> phi_bb380_18;
  TNode<IntPtrT> phi_bb380_26;
  TNode<IntPtrT> phi_bb380_27;
  TNode<IntPtrT> phi_bb380_28;
  TNode<IntPtrT> phi_bb380_29;
  TNode<IntPtrT> phi_bb380_30;
  TNode<IntPtrT> phi_bb380_33;
  TNode<BoolT> phi_bb380_34;
  TNode<BoolT> phi_bb380_35;
  TNode<Union<FixedArray, Smi>> phi_bb380_36;
  TNode<Int32T> phi_bb380_37;
  TNode<Union<Hole, JSMessageObject>> tmp821;
  if (block380.is_used()) {
    ca_.Bind(&block380, &phi_bb380_16, &phi_bb380_17, &phi_bb380_18, &phi_bb380_26, &phi_bb380_27, &phi_bb380_28, &phi_bb380_29, &phi_bb380_30, &phi_bb380_33, &phi_bb380_34, &phi_bb380_35, &phi_bb380_36, &phi_bb380_37);
    tmp821 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb380_16, phi_bb380_17, phi_bb380_18, tmp791, tmp821);
  }

  TNode<JSAny> phi_bb381_16;
  TNode<IntPtrT> phi_bb381_17;
  TNode<BoolT> phi_bb381_18;
  TNode<IntPtrT> phi_bb381_26;
  TNode<IntPtrT> phi_bb381_27;
  TNode<IntPtrT> phi_bb381_28;
  TNode<IntPtrT> phi_bb381_29;
  TNode<IntPtrT> phi_bb381_30;
  TNode<IntPtrT> phi_bb381_33;
  TNode<BoolT> phi_bb381_34;
  TNode<BoolT> phi_bb381_35;
  TNode<Union<FixedArray, Smi>> phi_bb381_36;
  TNode<Int32T> phi_bb381_37;
  TNode<Union<Hole, JSMessageObject>> tmp822;
  if (block381.is_used()) {
    ca_.Bind(&block381, &phi_bb381_16, &phi_bb381_17, &phi_bb381_18, &phi_bb381_26, &phi_bb381_27, &phi_bb381_28, &phi_bb381_29, &phi_bb381_30, &phi_bb381_33, &phi_bb381_34, &phi_bb381_35, &phi_bb381_36, &phi_bb381_37);
    tmp822 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb381_16, phi_bb381_17, phi_bb381_18, tmp795, tmp822);
  }

  TNode<JSAny> phi_bb382_16;
  TNode<IntPtrT> phi_bb382_17;
  TNode<BoolT> phi_bb382_18;
  TNode<IntPtrT> phi_bb382_26;
  TNode<IntPtrT> phi_bb382_27;
  TNode<IntPtrT> phi_bb382_28;
  TNode<IntPtrT> phi_bb382_29;
  TNode<IntPtrT> phi_bb382_30;
  TNode<IntPtrT> phi_bb382_33;
  TNode<BoolT> phi_bb382_34;
  TNode<BoolT> phi_bb382_35;
  TNode<Union<FixedArray, Smi>> phi_bb382_36;
  TNode<Int32T> phi_bb382_37;
  TNode<Union<Hole, JSMessageObject>> tmp823;
  if (block382.is_used()) {
    ca_.Bind(&block382, &phi_bb382_16, &phi_bb382_17, &phi_bb382_18, &phi_bb382_26, &phi_bb382_27, &phi_bb382_28, &phi_bb382_29, &phi_bb382_30, &phi_bb382_33, &phi_bb382_34, &phi_bb382_35, &phi_bb382_36, &phi_bb382_37);
    tmp823 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb382_16, phi_bb382_17, phi_bb382_18, tmp798, tmp823);
  }

  TNode<JSAny> phi_bb383_16;
  TNode<IntPtrT> phi_bb383_17;
  TNode<BoolT> phi_bb383_18;
  TNode<IntPtrT> phi_bb383_26;
  TNode<IntPtrT> phi_bb383_27;
  TNode<IntPtrT> phi_bb383_28;
  TNode<IntPtrT> phi_bb383_29;
  TNode<IntPtrT> phi_bb383_30;
  TNode<IntPtrT> phi_bb383_33;
  TNode<BoolT> phi_bb383_34;
  TNode<BoolT> phi_bb383_35;
  TNode<Union<FixedArray, Smi>> phi_bb383_36;
  TNode<Int32T> phi_bb383_37;
  TNode<Union<Hole, JSMessageObject>> tmp824;
  if (block383.is_used()) {
    ca_.Bind(&block383, &phi_bb383_16, &phi_bb383_17, &phi_bb383_18, &phi_bb383_26, &phi_bb383_27, &phi_bb383_28, &phi_bb383_29, &phi_bb383_30, &phi_bb383_33, &phi_bb383_34, &phi_bb383_35, &phi_bb383_36, &phi_bb383_37);
    tmp824 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb383_16, phi_bb383_17, phi_bb383_18, tmp802, tmp824);
  }

  TNode<JSAny> phi_bb384_16;
  TNode<IntPtrT> phi_bb384_17;
  TNode<BoolT> phi_bb384_18;
  TNode<IntPtrT> phi_bb384_26;
  TNode<IntPtrT> phi_bb384_27;
  TNode<IntPtrT> phi_bb384_28;
  TNode<IntPtrT> phi_bb384_29;
  TNode<IntPtrT> phi_bb384_30;
  TNode<IntPtrT> phi_bb384_33;
  TNode<BoolT> phi_bb384_34;
  TNode<BoolT> phi_bb384_35;
  TNode<Union<FixedArray, Smi>> phi_bb384_36;
  TNode<Int32T> phi_bb384_37;
  TNode<Union<Hole, JSMessageObject>> tmp825;
  if (block384.is_used()) {
    ca_.Bind(&block384, &phi_bb384_16, &phi_bb384_17, &phi_bb384_18, &phi_bb384_26, &phi_bb384_27, &phi_bb384_28, &phi_bb384_29, &phi_bb384_30, &phi_bb384_33, &phi_bb384_34, &phi_bb384_35, &phi_bb384_36, &phi_bb384_37);
    tmp825 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb384_16, phi_bb384_17, phi_bb384_18, tmp805, tmp825);
  }

  TNode<JSAny> phi_bb385_16;
  TNode<IntPtrT> phi_bb385_17;
  TNode<BoolT> phi_bb385_18;
  TNode<IntPtrT> phi_bb385_26;
  TNode<IntPtrT> phi_bb385_27;
  TNode<IntPtrT> phi_bb385_28;
  TNode<IntPtrT> phi_bb385_29;
  TNode<IntPtrT> phi_bb385_30;
  TNode<IntPtrT> phi_bb385_33;
  TNode<BoolT> phi_bb385_34;
  TNode<BoolT> phi_bb385_35;
  TNode<Union<FixedArray, Smi>> phi_bb385_36;
  TNode<Int32T> phi_bb385_37;
  TNode<Union<Hole, JSMessageObject>> tmp826;
  if (block385.is_used()) {
    ca_.Bind(&block385, &phi_bb385_16, &phi_bb385_17, &phi_bb385_18, &phi_bb385_26, &phi_bb385_27, &phi_bb385_28, &phi_bb385_29, &phi_bb385_30, &phi_bb385_33, &phi_bb385_34, &phi_bb385_35, &phi_bb385_36, &phi_bb385_37);
    tmp826 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb385_16, phi_bb385_17, phi_bb385_18, tmp809, tmp826);
  }

  TNode<JSAny> phi_bb386_16;
  TNode<IntPtrT> phi_bb386_17;
  TNode<BoolT> phi_bb386_18;
  TNode<IntPtrT> phi_bb386_26;
  TNode<IntPtrT> phi_bb386_27;
  TNode<IntPtrT> phi_bb386_28;
  TNode<IntPtrT> phi_bb386_29;
  TNode<IntPtrT> phi_bb386_30;
  TNode<IntPtrT> phi_bb386_33;
  TNode<BoolT> phi_bb386_34;
  TNode<BoolT> phi_bb386_35;
  TNode<Union<FixedArray, Smi>> phi_bb386_36;
  TNode<Int32T> phi_bb386_37;
  TNode<JSAny> tmp827;
      TNode<JSAny> tmp829;
  if (block386.is_used()) {
    ca_.Bind(&block386, &phi_bb386_16, &phi_bb386_17, &phi_bb386_18, &phi_bb386_26, &phi_bb386_27, &phi_bb386_28, &phi_bb386_29, &phi_bb386_30, &phi_bb386_33, &phi_bb386_34, &phi_bb386_35, &phi_bb386_36, &phi_bb386_37);
    compiler::CodeAssemblerExceptionHandlerLabel catch828__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch828__label);
    tmp827 = ca_.CallBuiltin<JSAny>(Builtin::kWasmReturnPromiseOnSuspendAsm, TNode<Object>(), tmp760, tmp20, phi_bb386_16);
    }
    if (catch828__label.is_used()) {
      compiler::CodeAssemblerLabel catch828_skip(&ca_);
      ca_.Goto(&catch828_skip);
      ca_.Bind(&catch828__label, &tmp829);
      ca_.Goto(&block389, phi_bb386_16, phi_bb386_17, phi_bb386_18, phi_bb386_26, phi_bb386_27, phi_bb386_28, phi_bb386_29, phi_bb386_30, phi_bb386_33, phi_bb386_34, phi_bb386_35, phi_bb386_36, phi_bb386_37, phi_bb386_16);
      ca_.Bind(&catch828_skip);
    }
    ca_.Goto(&block388, phi_bb386_16, phi_bb386_17, phi_bb386_18, phi_bb386_26, phi_bb386_27, phi_bb386_28, phi_bb386_29, phi_bb386_30, phi_bb386_33, phi_bb386_34, phi_bb386_35, phi_bb386_36, phi_bb386_37, tmp827);
  }

  TNode<JSAny> phi_bb389_16;
  TNode<IntPtrT> phi_bb389_17;
  TNode<BoolT> phi_bb389_18;
  TNode<IntPtrT> phi_bb389_26;
  TNode<IntPtrT> phi_bb389_27;
  TNode<IntPtrT> phi_bb389_28;
  TNode<IntPtrT> phi_bb389_29;
  TNode<IntPtrT> phi_bb389_30;
  TNode<IntPtrT> phi_bb389_33;
  TNode<BoolT> phi_bb389_34;
  TNode<BoolT> phi_bb389_35;
  TNode<Union<FixedArray, Smi>> phi_bb389_36;
  TNode<Int32T> phi_bb389_37;
  TNode<JSAny> phi_bb389_46;
  TNode<Union<Hole, JSMessageObject>> tmp830;
  if (block389.is_used()) {
    ca_.Bind(&block389, &phi_bb389_16, &phi_bb389_17, &phi_bb389_18, &phi_bb389_26, &phi_bb389_27, &phi_bb389_28, &phi_bb389_29, &phi_bb389_30, &phi_bb389_33, &phi_bb389_34, &phi_bb389_35, &phi_bb389_36, &phi_bb389_37, &phi_bb389_46);
    tmp830 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb389_16, phi_bb389_17, phi_bb389_18, tmp829, tmp830);
  }

  TNode<JSAny> phi_bb387_16;
  TNode<IntPtrT> phi_bb387_17;
  TNode<BoolT> phi_bb387_18;
  TNode<IntPtrT> phi_bb387_26;
  TNode<IntPtrT> phi_bb387_27;
  TNode<IntPtrT> phi_bb387_28;
  TNode<IntPtrT> phi_bb387_29;
  TNode<IntPtrT> phi_bb387_30;
  TNode<IntPtrT> phi_bb387_33;
  TNode<BoolT> phi_bb387_34;
  TNode<BoolT> phi_bb387_35;
  TNode<Union<FixedArray, Smi>> phi_bb387_36;
  TNode<Int32T> phi_bb387_37;
  TNode<BoolT> tmp831;
      TNode<JSAny> tmp833;
  if (block387.is_used()) {
    ca_.Bind(&block387, &phi_bb387_16, &phi_bb387_17, &phi_bb387_18, &phi_bb387_26, &phi_bb387_27, &phi_bb387_28, &phi_bb387_29, &phi_bb387_30, &phi_bb387_33, &phi_bb387_34, &phi_bb387_35, &phi_bb387_36, &phi_bb387_37);
    compiler::CodeAssemblerExceptionHandlerLabel catch832__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch832__label);
    tmp831 = FromConstexpr_bool_constexpr_bool_0(state_, (CodeStubAssembler(state_).ConstexprInt32Equal(p_promise, wasm::Promise::kNoPromise)));
    }
    if (catch832__label.is_used()) {
      compiler::CodeAssemblerLabel catch832_skip(&ca_);
      ca_.Goto(&catch832_skip);
      ca_.Bind(&catch832__label, &tmp833);
      ca_.Goto(&block392, phi_bb387_16, phi_bb387_17, phi_bb387_18, phi_bb387_26, phi_bb387_27, phi_bb387_28, phi_bb387_29, phi_bb387_30, phi_bb387_33, phi_bb387_34, phi_bb387_35, phi_bb387_36, phi_bb387_37);
      ca_.Bind(&catch832_skip);
    }
    ca_.Branch(tmp831, &block390, std::vector<compiler::Node*>{phi_bb387_16, phi_bb387_17, phi_bb387_18, phi_bb387_26, phi_bb387_27, phi_bb387_28, phi_bb387_29, phi_bb387_30, phi_bb387_33, phi_bb387_34, phi_bb387_35, phi_bb387_36, phi_bb387_37}, &block391, std::vector<compiler::Node*>{phi_bb387_16, phi_bb387_17, phi_bb387_18, phi_bb387_26, phi_bb387_27, phi_bb387_28, phi_bb387_29, phi_bb387_30, phi_bb387_33, phi_bb387_34, phi_bb387_35, phi_bb387_36, phi_bb387_37});
  }

  TNode<JSAny> phi_bb392_16;
  TNode<IntPtrT> phi_bb392_17;
  TNode<BoolT> phi_bb392_18;
  TNode<IntPtrT> phi_bb392_26;
  TNode<IntPtrT> phi_bb392_27;
  TNode<IntPtrT> phi_bb392_28;
  TNode<IntPtrT> phi_bb392_29;
  TNode<IntPtrT> phi_bb392_30;
  TNode<IntPtrT> phi_bb392_33;
  TNode<BoolT> phi_bb392_34;
  TNode<BoolT> phi_bb392_35;
  TNode<Union<FixedArray, Smi>> phi_bb392_36;
  TNode<Int32T> phi_bb392_37;
  TNode<Union<Hole, JSMessageObject>> tmp834;
  if (block392.is_used()) {
    ca_.Bind(&block392, &phi_bb392_16, &phi_bb392_17, &phi_bb392_18, &phi_bb392_26, &phi_bb392_27, &phi_bb392_28, &phi_bb392_29, &phi_bb392_30, &phi_bb392_33, &phi_bb392_34, &phi_bb392_35, &phi_bb392_36, &phi_bb392_37);
    tmp834 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb392_16, phi_bb392_17, phi_bb392_18, tmp833, tmp834);
  }

  TNode<JSAny> phi_bb390_16;
  TNode<IntPtrT> phi_bb390_17;
  TNode<BoolT> phi_bb390_18;
  TNode<IntPtrT> phi_bb390_26;
  TNode<IntPtrT> phi_bb390_27;
  TNode<IntPtrT> phi_bb390_28;
  TNode<IntPtrT> phi_bb390_29;
  TNode<IntPtrT> phi_bb390_30;
  TNode<IntPtrT> phi_bb390_33;
  TNode<BoolT> phi_bb390_34;
  TNode<BoolT> phi_bb390_35;
  TNode<Union<FixedArray, Smi>> phi_bb390_36;
  TNode<Int32T> phi_bb390_37;
  TNode<JSAny> tmp835;
      TNode<JSAny> tmp837;
  if (block390.is_used()) {
    ca_.Bind(&block390, &phi_bb390_16, &phi_bb390_17, &phi_bb390_18, &phi_bb390_26, &phi_bb390_27, &phi_bb390_28, &phi_bb390_29, &phi_bb390_30, &phi_bb390_33, &phi_bb390_34, &phi_bb390_35, &phi_bb390_36, &phi_bb390_37);
    compiler::CodeAssemblerExceptionHandlerLabel catch836__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch836__label);
    tmp835 = ca_.CallBuiltin<JSAny>(Builtin::kJSToWasmWrapperAsm, TNode<Object>(), tmp760, tmp20, phi_bb390_16);
    }
    if (catch836__label.is_used()) {
      compiler::CodeAssemblerLabel catch836_skip(&ca_);
      ca_.Goto(&catch836_skip);
      ca_.Bind(&catch836__label, &tmp837);
      ca_.Goto(&block394, phi_bb390_16, phi_bb390_17, phi_bb390_18, phi_bb390_26, phi_bb390_27, phi_bb390_28, phi_bb390_29, phi_bb390_30, phi_bb390_33, phi_bb390_34, phi_bb390_35, phi_bb390_36, phi_bb390_37, phi_bb390_16);
      ca_.Bind(&catch836_skip);
    }
    ca_.Goto(&block393, phi_bb390_16, phi_bb390_17, phi_bb390_18, phi_bb390_26, phi_bb390_27, phi_bb390_28, phi_bb390_29, phi_bb390_30, phi_bb390_33, phi_bb390_34, phi_bb390_35, phi_bb390_36, phi_bb390_37, tmp835);
  }

  TNode<JSAny> phi_bb394_16;
  TNode<IntPtrT> phi_bb394_17;
  TNode<BoolT> phi_bb394_18;
  TNode<IntPtrT> phi_bb394_26;
  TNode<IntPtrT> phi_bb394_27;
  TNode<IntPtrT> phi_bb394_28;
  TNode<IntPtrT> phi_bb394_29;
  TNode<IntPtrT> phi_bb394_30;
  TNode<IntPtrT> phi_bb394_33;
  TNode<BoolT> phi_bb394_34;
  TNode<BoolT> phi_bb394_35;
  TNode<Union<FixedArray, Smi>> phi_bb394_36;
  TNode<Int32T> phi_bb394_37;
  TNode<JSAny> phi_bb394_46;
  TNode<Union<Hole, JSMessageObject>> tmp838;
  if (block394.is_used()) {
    ca_.Bind(&block394, &phi_bb394_16, &phi_bb394_17, &phi_bb394_18, &phi_bb394_26, &phi_bb394_27, &phi_bb394_28, &phi_bb394_29, &phi_bb394_30, &phi_bb394_33, &phi_bb394_34, &phi_bb394_35, &phi_bb394_36, &phi_bb394_37, &phi_bb394_46);
    tmp838 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb394_16, phi_bb394_17, phi_bb394_18, tmp837, tmp838);
  }

  TNode<JSAny> phi_bb391_16;
  TNode<IntPtrT> phi_bb391_17;
  TNode<BoolT> phi_bb391_18;
  TNode<IntPtrT> phi_bb391_26;
  TNode<IntPtrT> phi_bb391_27;
  TNode<IntPtrT> phi_bb391_28;
  TNode<IntPtrT> phi_bb391_29;
  TNode<IntPtrT> phi_bb391_30;
  TNode<IntPtrT> phi_bb391_33;
  TNode<BoolT> phi_bb391_34;
  TNode<BoolT> phi_bb391_35;
  TNode<Union<FixedArray, Smi>> phi_bb391_36;
  TNode<Int32T> phi_bb391_37;
  TNode<BoolT> tmp839;
      TNode<JSAny> tmp841;
  if (block391.is_used()) {
    ca_.Bind(&block391, &phi_bb391_16, &phi_bb391_17, &phi_bb391_18, &phi_bb391_26, &phi_bb391_27, &phi_bb391_28, &phi_bb391_29, &phi_bb391_30, &phi_bb391_33, &phi_bb391_34, &phi_bb391_35, &phi_bb391_36, &phi_bb391_37);
    compiler::CodeAssemblerExceptionHandlerLabel catch840__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch840__label);
    tmp839 = FromConstexpr_bool_constexpr_bool_0(state_, (CodeStubAssembler(state_).ConstexprInt32Equal(p_promise, wasm::Promise::kStressSwitch)));
    }
    if (catch840__label.is_used()) {
      compiler::CodeAssemblerLabel catch840_skip(&ca_);
      ca_.Goto(&catch840_skip);
      ca_.Bind(&catch840__label, &tmp841);
      ca_.Goto(&block397, phi_bb391_16, phi_bb391_17, phi_bb391_18, phi_bb391_26, phi_bb391_27, phi_bb391_28, phi_bb391_29, phi_bb391_30, phi_bb391_33, phi_bb391_34, phi_bb391_35, phi_bb391_36, phi_bb391_37);
      ca_.Bind(&catch840_skip);
    }
    ca_.Branch(tmp839, &block395, std::vector<compiler::Node*>{phi_bb391_16, phi_bb391_17, phi_bb391_18, phi_bb391_26, phi_bb391_27, phi_bb391_28, phi_bb391_29, phi_bb391_30, phi_bb391_33, phi_bb391_34, phi_bb391_35, phi_bb391_36, phi_bb391_37}, &block396, std::vector<compiler::Node*>{phi_bb391_16, phi_bb391_17, phi_bb391_18, phi_bb391_26, phi_bb391_27, phi_bb391_28, phi_bb391_29, phi_bb391_30, phi_bb391_33, phi_bb391_34, phi_bb391_35, phi_bb391_36, phi_bb391_37});
  }

  TNode<JSAny> phi_bb397_16;
  TNode<IntPtrT> phi_bb397_17;
  TNode<BoolT> phi_bb397_18;
  TNode<IntPtrT> phi_bb397_26;
  TNode<IntPtrT> phi_bb397_27;
  TNode<IntPtrT> phi_bb397_28;
  TNode<IntPtrT> phi_bb397_29;
  TNode<IntPtrT> phi_bb397_30;
  TNode<IntPtrT> phi_bb397_33;
  TNode<BoolT> phi_bb397_34;
  TNode<BoolT> phi_bb397_35;
  TNode<Union<FixedArray, Smi>> phi_bb397_36;
  TNode<Int32T> phi_bb397_37;
  TNode<Union<Hole, JSMessageObject>> tmp842;
  if (block397.is_used()) {
    ca_.Bind(&block397, &phi_bb397_16, &phi_bb397_17, &phi_bb397_18, &phi_bb397_26, &phi_bb397_27, &phi_bb397_28, &phi_bb397_29, &phi_bb397_30, &phi_bb397_33, &phi_bb397_34, &phi_bb397_35, &phi_bb397_36, &phi_bb397_37);
    tmp842 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb397_16, phi_bb397_17, phi_bb397_18, tmp841, tmp842);
  }

  TNode<JSAny> phi_bb395_16;
  TNode<IntPtrT> phi_bb395_17;
  TNode<BoolT> phi_bb395_18;
  TNode<IntPtrT> phi_bb395_26;
  TNode<IntPtrT> phi_bb395_27;
  TNode<IntPtrT> phi_bb395_28;
  TNode<IntPtrT> phi_bb395_29;
  TNode<IntPtrT> phi_bb395_30;
  TNode<IntPtrT> phi_bb395_33;
  TNode<BoolT> phi_bb395_34;
  TNode<BoolT> phi_bb395_35;
  TNode<Union<FixedArray, Smi>> phi_bb395_36;
  TNode<Int32T> phi_bb395_37;
  TNode<JSAny> tmp843;
      TNode<JSAny> tmp845;
  if (block395.is_used()) {
    ca_.Bind(&block395, &phi_bb395_16, &phi_bb395_17, &phi_bb395_18, &phi_bb395_26, &phi_bb395_27, &phi_bb395_28, &phi_bb395_29, &phi_bb395_30, &phi_bb395_33, &phi_bb395_34, &phi_bb395_35, &phi_bb395_36, &phi_bb395_37);
    compiler::CodeAssemblerExceptionHandlerLabel catch844__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch844__label);
    tmp843 = ca_.CallBuiltin<JSAny>(Builtin::kJSToWasmStressSwitchStacksAsm, TNode<Object>(), tmp760, tmp20, phi_bb395_16);
    }
    if (catch844__label.is_used()) {
      compiler::CodeAssemblerLabel catch844_skip(&ca_);
      ca_.Goto(&catch844_skip);
      ca_.Bind(&catch844__label, &tmp845);
      ca_.Goto(&block399, phi_bb395_16, phi_bb395_17, phi_bb395_18, phi_bb395_26, phi_bb395_27, phi_bb395_28, phi_bb395_29, phi_bb395_30, phi_bb395_33, phi_bb395_34, phi_bb395_35, phi_bb395_36, phi_bb395_37, phi_bb395_16);
      ca_.Bind(&catch844_skip);
    }
    ca_.Goto(&block393, phi_bb395_16, phi_bb395_17, phi_bb395_18, phi_bb395_26, phi_bb395_27, phi_bb395_28, phi_bb395_29, phi_bb395_30, phi_bb395_33, phi_bb395_34, phi_bb395_35, phi_bb395_36, phi_bb395_37, tmp843);
  }

  TNode<JSAny> phi_bb399_16;
  TNode<IntPtrT> phi_bb399_17;
  TNode<BoolT> phi_bb399_18;
  TNode<IntPtrT> phi_bb399_26;
  TNode<IntPtrT> phi_bb399_27;
  TNode<IntPtrT> phi_bb399_28;
  TNode<IntPtrT> phi_bb399_29;
  TNode<IntPtrT> phi_bb399_30;
  TNode<IntPtrT> phi_bb399_33;
  TNode<BoolT> phi_bb399_34;
  TNode<BoolT> phi_bb399_35;
  TNode<Union<FixedArray, Smi>> phi_bb399_36;
  TNode<Int32T> phi_bb399_37;
  TNode<JSAny> phi_bb399_46;
  TNode<Union<Hole, JSMessageObject>> tmp846;
  if (block399.is_used()) {
    ca_.Bind(&block399, &phi_bb399_16, &phi_bb399_17, &phi_bb399_18, &phi_bb399_26, &phi_bb399_27, &phi_bb399_28, &phi_bb399_29, &phi_bb399_30, &phi_bb399_33, &phi_bb399_34, &phi_bb399_35, &phi_bb399_36, &phi_bb399_37, &phi_bb399_46);
    tmp846 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb399_16, phi_bb399_17, phi_bb399_18, tmp845, tmp846);
  }

  TNode<JSAny> phi_bb396_16;
  TNode<IntPtrT> phi_bb396_17;
  TNode<BoolT> phi_bb396_18;
  TNode<IntPtrT> phi_bb396_26;
  TNode<IntPtrT> phi_bb396_27;
  TNode<IntPtrT> phi_bb396_28;
  TNode<IntPtrT> phi_bb396_29;
  TNode<IntPtrT> phi_bb396_30;
  TNode<IntPtrT> phi_bb396_33;
  TNode<BoolT> phi_bb396_34;
  TNode<BoolT> phi_bb396_35;
  TNode<Union<FixedArray, Smi>> phi_bb396_36;
  TNode<Int32T> phi_bb396_37;
  if (block396.is_used()) {
    ca_.Bind(&block396, &phi_bb396_16, &phi_bb396_17, &phi_bb396_18, &phi_bb396_26, &phi_bb396_27, &phi_bb396_28, &phi_bb396_29, &phi_bb396_30, &phi_bb396_33, &phi_bb396_34, &phi_bb396_35, &phi_bb396_36, &phi_bb396_37);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<JSAny> phi_bb393_16;
  TNode<IntPtrT> phi_bb393_17;
  TNode<BoolT> phi_bb393_18;
  TNode<IntPtrT> phi_bb393_26;
  TNode<IntPtrT> phi_bb393_27;
  TNode<IntPtrT> phi_bb393_28;
  TNode<IntPtrT> phi_bb393_29;
  TNode<IntPtrT> phi_bb393_30;
  TNode<IntPtrT> phi_bb393_33;
  TNode<BoolT> phi_bb393_34;
  TNode<BoolT> phi_bb393_35;
  TNode<Union<FixedArray, Smi>> phi_bb393_36;
  TNode<Int32T> phi_bb393_37;
  TNode<JSAny> phi_bb393_43;
  if (block393.is_used()) {
    ca_.Bind(&block393, &phi_bb393_16, &phi_bb393_17, &phi_bb393_18, &phi_bb393_26, &phi_bb393_27, &phi_bb393_28, &phi_bb393_29, &phi_bb393_30, &phi_bb393_33, &phi_bb393_34, &phi_bb393_35, &phi_bb393_36, &phi_bb393_37, &phi_bb393_43);
    ca_.Goto(&block388, phi_bb393_16, phi_bb393_17, phi_bb393_18, phi_bb393_26, phi_bb393_27, phi_bb393_28, phi_bb393_29, phi_bb393_30, phi_bb393_33, phi_bb393_34, phi_bb393_35, phi_bb393_36, phi_bb393_37, phi_bb393_43);
  }

  TNode<JSAny> phi_bb388_16;
  TNode<IntPtrT> phi_bb388_17;
  TNode<BoolT> phi_bb388_18;
  TNode<IntPtrT> phi_bb388_26;
  TNode<IntPtrT> phi_bb388_27;
  TNode<IntPtrT> phi_bb388_28;
  TNode<IntPtrT> phi_bb388_29;
  TNode<IntPtrT> phi_bb388_30;
  TNode<IntPtrT> phi_bb388_33;
  TNode<BoolT> phi_bb388_34;
  TNode<BoolT> phi_bb388_35;
  TNode<Union<FixedArray, Smi>> phi_bb388_36;
  TNode<Int32T> phi_bb388_37;
  TNode<JSAny> phi_bb388_43;
  TNode<Int32T> tmp847;
      TNode<JSAny> tmp849;
  TNode<BoolT> tmp850;
      TNode<JSAny> tmp852;
  if (block388.is_used()) {
    ca_.Bind(&block388, &phi_bb388_16, &phi_bb388_17, &phi_bb388_18, &phi_bb388_26, &phi_bb388_27, &phi_bb388_28, &phi_bb388_29, &phi_bb388_30, &phi_bb388_33, &phi_bb388_34, &phi_bb388_35, &phi_bb388_36, &phi_bb388_37, &phi_bb388_43);
    compiler::CodeAssemblerExceptionHandlerLabel catch848__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch848__label);
    tmp847 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0xaull));
    }
    if (catch848__label.is_used()) {
      compiler::CodeAssemblerLabel catch848_skip(&ca_);
      ca_.Goto(&catch848_skip);
      ca_.Bind(&catch848__label, &tmp849);
      ca_.Goto(&block402, phi_bb388_16, phi_bb388_17, phi_bb388_18, phi_bb388_26, phi_bb388_27, phi_bb388_28, phi_bb388_29, phi_bb388_30, phi_bb388_33, phi_bb388_34, phi_bb388_35, phi_bb388_36, phi_bb388_37, phi_bb388_43);
      ca_.Bind(&catch848_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch851__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch851__label);
    tmp850 = CodeStubAssembler(state_).Int32GreaterThan(TNode<Int32T>{tmp25}, TNode<Int32T>{tmp847});
    }
    if (catch851__label.is_used()) {
      compiler::CodeAssemblerLabel catch851_skip(&ca_);
      ca_.Goto(&catch851_skip);
      ca_.Bind(&catch851__label, &tmp852);
      ca_.Goto(&block403, phi_bb388_16, phi_bb388_17, phi_bb388_18, phi_bb388_26, phi_bb388_27, phi_bb388_28, phi_bb388_29, phi_bb388_30, phi_bb388_33, phi_bb388_34, phi_bb388_35, phi_bb388_36, phi_bb388_37, phi_bb388_43);
      ca_.Bind(&catch851_skip);
    }
    ca_.Branch(tmp850, &block400, std::vector<compiler::Node*>{phi_bb388_16, phi_bb388_17, phi_bb388_18, phi_bb388_26, phi_bb388_27, phi_bb388_28, phi_bb388_29, phi_bb388_30, phi_bb388_33, phi_bb388_34, phi_bb388_35, phi_bb388_36, phi_bb388_37, phi_bb388_43}, &block401, std::vector<compiler::Node*>{phi_bb388_16, phi_bb388_17, phi_bb388_18, phi_bb388_26, phi_bb388_27, phi_bb388_28, phi_bb388_29, phi_bb388_30, phi_bb388_33, phi_bb388_34, phi_bb388_35, phi_bb388_36, phi_bb388_37, phi_bb388_43});
  }

  TNode<JSAny> phi_bb402_16;
  TNode<IntPtrT> phi_bb402_17;
  TNode<BoolT> phi_bb402_18;
  TNode<IntPtrT> phi_bb402_26;
  TNode<IntPtrT> phi_bb402_27;
  TNode<IntPtrT> phi_bb402_28;
  TNode<IntPtrT> phi_bb402_29;
  TNode<IntPtrT> phi_bb402_30;
  TNode<IntPtrT> phi_bb402_33;
  TNode<BoolT> phi_bb402_34;
  TNode<BoolT> phi_bb402_35;
  TNode<Union<FixedArray, Smi>> phi_bb402_36;
  TNode<Int32T> phi_bb402_37;
  TNode<JSAny> phi_bb402_43;
  TNode<Union<Hole, JSMessageObject>> tmp853;
  if (block402.is_used()) {
    ca_.Bind(&block402, &phi_bb402_16, &phi_bb402_17, &phi_bb402_18, &phi_bb402_26, &phi_bb402_27, &phi_bb402_28, &phi_bb402_29, &phi_bb402_30, &phi_bb402_33, &phi_bb402_34, &phi_bb402_35, &phi_bb402_36, &phi_bb402_37, &phi_bb402_43);
    tmp853 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb402_16, phi_bb402_17, phi_bb402_18, tmp849, tmp853);
  }

  TNode<JSAny> phi_bb403_16;
  TNode<IntPtrT> phi_bb403_17;
  TNode<BoolT> phi_bb403_18;
  TNode<IntPtrT> phi_bb403_26;
  TNode<IntPtrT> phi_bb403_27;
  TNode<IntPtrT> phi_bb403_28;
  TNode<IntPtrT> phi_bb403_29;
  TNode<IntPtrT> phi_bb403_30;
  TNode<IntPtrT> phi_bb403_33;
  TNode<BoolT> phi_bb403_34;
  TNode<BoolT> phi_bb403_35;
  TNode<Union<FixedArray, Smi>> phi_bb403_36;
  TNode<Int32T> phi_bb403_37;
  TNode<JSAny> phi_bb403_43;
  TNode<Union<Hole, JSMessageObject>> tmp854;
  if (block403.is_used()) {
    ca_.Bind(&block403, &phi_bb403_16, &phi_bb403_17, &phi_bb403_18, &phi_bb403_26, &phi_bb403_27, &phi_bb403_28, &phi_bb403_29, &phi_bb403_30, &phi_bb403_33, &phi_bb403_34, &phi_bb403_35, &phi_bb403_36, &phi_bb403_37, &phi_bb403_43);
    tmp854 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb403_16, phi_bb403_17, phi_bb403_18, tmp852, tmp854);
  }

  TNode<JSAny> phi_bb400_16;
  TNode<IntPtrT> phi_bb400_17;
  TNode<BoolT> phi_bb400_18;
  TNode<IntPtrT> phi_bb400_26;
  TNode<IntPtrT> phi_bb400_27;
  TNode<IntPtrT> phi_bb400_28;
  TNode<IntPtrT> phi_bb400_29;
  TNode<IntPtrT> phi_bb400_30;
  TNode<IntPtrT> phi_bb400_33;
  TNode<BoolT> phi_bb400_34;
  TNode<BoolT> phi_bb400_35;
  TNode<Union<FixedArray, Smi>> phi_bb400_36;
  TNode<Int32T> phi_bb400_37;
  TNode<JSAny> phi_bb400_43;
  TNode<RawPtrT> tmp855;
  TNode<RawPtrT> tmp856;
      TNode<JSAny> tmp858;
  if (block400.is_used()) {
    ca_.Bind(&block400, &phi_bb400_16, &phi_bb400_17, &phi_bb400_18, &phi_bb400_26, &phi_bb400_27, &phi_bb400_28, &phi_bb400_29, &phi_bb400_30, &phi_bb400_33, &phi_bb400_34, &phi_bb400_35, &phi_bb400_36, &phi_bb400_37, &phi_bb400_43);
    tmp855 = CodeStubAssembler(state_).GCUnsafeReferenceToRawPtr(TNode<Union<HeapObject, TaggedIndex>>{phi_bb133_22}, TNode<IntPtrT>{phi_bb133_23});
    tmp856 = (TNode<RawPtrT>{tmp855});
    compiler::CodeAssemblerExceptionHandlerLabel catch857__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch857__label);
    CodeStubAssembler(state_).DeallocateBuffer(TNode<RawPtrT>{tmp856});
    }
    if (catch857__label.is_used()) {
      compiler::CodeAssemblerLabel catch857_skip(&ca_);
      ca_.Goto(&catch857_skip);
      ca_.Bind(&catch857__label, &tmp858);
      ca_.Goto(&block405, phi_bb400_16, phi_bb400_17, phi_bb400_18, phi_bb400_26, phi_bb400_27, phi_bb400_28, phi_bb400_29, phi_bb400_30, phi_bb400_33, phi_bb400_34, phi_bb400_35, phi_bb400_36, phi_bb400_37, phi_bb400_43);
      ca_.Bind(&catch857_skip);
    }
    ca_.Goto(&block401, phi_bb400_16, phi_bb400_17, phi_bb400_18, phi_bb400_26, phi_bb400_27, phi_bb400_28, phi_bb400_29, phi_bb400_30, phi_bb400_33, phi_bb400_34, phi_bb400_35, phi_bb400_36, phi_bb400_37, phi_bb400_43);
  }

  TNode<JSAny> phi_bb405_16;
  TNode<IntPtrT> phi_bb405_17;
  TNode<BoolT> phi_bb405_18;
  TNode<IntPtrT> phi_bb405_26;
  TNode<IntPtrT> phi_bb405_27;
  TNode<IntPtrT> phi_bb405_28;
  TNode<IntPtrT> phi_bb405_29;
  TNode<IntPtrT> phi_bb405_30;
  TNode<IntPtrT> phi_bb405_33;
  TNode<BoolT> phi_bb405_34;
  TNode<BoolT> phi_bb405_35;
  TNode<Union<FixedArray, Smi>> phi_bb405_36;
  TNode<Int32T> phi_bb405_37;
  TNode<JSAny> phi_bb405_43;
  TNode<Union<Hole, JSMessageObject>> tmp859;
  if (block405.is_used()) {
    ca_.Bind(&block405, &phi_bb405_16, &phi_bb405_17, &phi_bb405_18, &phi_bb405_26, &phi_bb405_27, &phi_bb405_28, &phi_bb405_29, &phi_bb405_30, &phi_bb405_33, &phi_bb405_34, &phi_bb405_35, &phi_bb405_36, &phi_bb405_37, &phi_bb405_43);
    tmp859 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block143, phi_bb405_16, phi_bb405_17, phi_bb405_18, tmp858, tmp859);
  }

  TNode<JSAny> phi_bb401_16;
  TNode<IntPtrT> phi_bb401_17;
  TNode<BoolT> phi_bb401_18;
  TNode<IntPtrT> phi_bb401_26;
  TNode<IntPtrT> phi_bb401_27;
  TNode<IntPtrT> phi_bb401_28;
  TNode<IntPtrT> phi_bb401_29;
  TNode<IntPtrT> phi_bb401_30;
  TNode<IntPtrT> phi_bb401_33;
  TNode<BoolT> phi_bb401_34;
  TNode<BoolT> phi_bb401_35;
  TNode<Union<FixedArray, Smi>> phi_bb401_36;
  TNode<Int32T> phi_bb401_37;
  TNode<JSAny> phi_bb401_43;
  if (block401.is_used()) {
    ca_.Bind(&block401, &phi_bb401_16, &phi_bb401_17, &phi_bb401_18, &phi_bb401_26, &phi_bb401_27, &phi_bb401_28, &phi_bb401_29, &phi_bb401_30, &phi_bb401_33, &phi_bb401_34, &phi_bb401_35, &phi_bb401_36, &phi_bb401_37, &phi_bb401_43);
    ca_.Goto(&block409, phi_bb401_43);
  }

  TNode<JSAny> phi_bb143_16;
  TNode<IntPtrT> phi_bb143_17;
  TNode<BoolT> phi_bb143_18;
  TNode<JSAny> phi_bb143_25;
  TNode<Union<Hole, JSMessageObject>> phi_bb143_26;
  TNode<Int32T> tmp860;
  TNode<BoolT> tmp861;
  if (block143.is_used()) {
    ca_.Bind(&block143, &phi_bb143_16, &phi_bb143_17, &phi_bb143_18, &phi_bb143_25, &phi_bb143_26);
    tmp860 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0xaull));
    tmp861 = CodeStubAssembler(state_).Int32GreaterThan(TNode<Int32T>{tmp25}, TNode<Int32T>{tmp860});
    ca_.Branch(tmp861, &block406, std::vector<compiler::Node*>{phi_bb143_16, phi_bb143_17, phi_bb143_18}, &block407, std::vector<compiler::Node*>{phi_bb143_16, phi_bb143_17, phi_bb143_18});
  }

  TNode<JSAny> phi_bb406_16;
  TNode<IntPtrT> phi_bb406_17;
  TNode<BoolT> phi_bb406_18;
  TNode<RawPtrT> tmp862;
  TNode<RawPtrT> tmp863;
  if (block406.is_used()) {
    ca_.Bind(&block406, &phi_bb406_16, &phi_bb406_17, &phi_bb406_18);
    tmp862 = CodeStubAssembler(state_).GCUnsafeReferenceToRawPtr(TNode<Union<HeapObject, TaggedIndex>>{phi_bb133_22}, TNode<IntPtrT>{phi_bb133_23});
    tmp863 = (TNode<RawPtrT>{tmp862});
    CodeStubAssembler(state_).DeallocateBuffer(TNode<RawPtrT>{tmp863});
    ca_.Goto(&block407, phi_bb406_16, phi_bb406_17, phi_bb406_18);
  }

  TNode<JSAny> phi_bb407_16;
  TNode<IntPtrT> phi_bb407_17;
  TNode<BoolT> phi_bb407_18;
  if (block407.is_used()) {
    ca_.Bind(&block407, &phi_bb407_16, &phi_bb407_17, &phi_bb407_18);
    CodeStubAssembler(state_).CallRuntime(Runtime::kReThrowWithMessage, p_context, phi_bb143_25, phi_bb143_26);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<JSAny> phi_bb409_7;
    ca_.Bind(&block409, &phi_bb409_7);
  return TNode<JSAny>{phi_bb409_7};
}

TF_BUILTIN(JSToWasmWrapper, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Word32T> argc = UncheckedParameter<Word32T>(Descriptor::kJSActualArgumentsCount);
  TNode<IntPtrT> arguments_length(ChangeInt32ToIntPtr(UncheckedCast<Int32T>(argc)));
  TNode<RawPtrT> arguments_frame = UncheckedCast<RawPtrT>(LoadFramePointer());
  TorqueStructArguments torque_arguments(GetFrameArguments(arguments_frame, arguments_length, FrameArgumentsArgcType::kCountIncludesReceiver));
  CodeStubArguments arguments(this, torque_arguments);
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<JSAny> parameter1 = arguments.GetReceiver();
  USE(parameter1);
  TNode<JSFunction> parameter2 = UncheckedParameter<JSFunction>(Descriptor::kJSTarget);
  USE(parameter2);
  TNode<JSDispatchHandleT> parameter3 = UncheckedParameter<JSDispatchHandleT>(Descriptor::kJSDispatchHandle);
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSAny> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    CodeStubAssembler(state_).SetSupportsDynamicParameterCount(TNode<JSFunction>{parameter2}, TNode<JSDispatchHandleT>{parameter3});
    tmp0 = JSToWasmWrapperHelper_0(state_, TNode<NativeContext>{parameter0}, TNode<JSAny>{parameter1}, TNode<JSFunction>{parameter2}, TorqueStructArguments{TNode<RawPtrT>{torque_arguments.frame}, TNode<RawPtrT>{torque_arguments.base}, TNode<IntPtrT>{torque_arguments.length}, TNode<IntPtrT>{torque_arguments.actual_count}}, wasm::Promise::kNoPromise);
    arguments.PopAndReturn(tmp0);
  }
}

TF_BUILTIN(WasmPromising, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Word32T> argc = UncheckedParameter<Word32T>(Descriptor::kJSActualArgumentsCount);
  TNode<IntPtrT> arguments_length(ChangeInt32ToIntPtr(UncheckedCast<Int32T>(argc)));
  TNode<RawPtrT> arguments_frame = UncheckedCast<RawPtrT>(LoadFramePointer());
  TorqueStructArguments torque_arguments(GetFrameArguments(arguments_frame, arguments_length, FrameArgumentsArgcType::kCountIncludesReceiver));
  CodeStubArguments arguments(this, torque_arguments);
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<JSAny> parameter1 = arguments.GetReceiver();
  USE(parameter1);
  TNode<JSFunction> parameter2 = UncheckedParameter<JSFunction>(Descriptor::kJSTarget);
  USE(parameter2);
  TNode<JSDispatchHandleT> parameter3 = UncheckedParameter<JSDispatchHandleT>(Descriptor::kJSDispatchHandle);
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSAny> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    CodeStubAssembler(state_).SetSupportsDynamicParameterCount(TNode<JSFunction>{parameter2}, TNode<JSDispatchHandleT>{parameter3});
    tmp0 = JSToWasmWrapperHelper_0(state_, TNode<NativeContext>{parameter0}, TNode<JSAny>{parameter1}, TNode<JSFunction>{parameter2}, TorqueStructArguments{TNode<RawPtrT>{torque_arguments.frame}, TNode<RawPtrT>{torque_arguments.base}, TNode<IntPtrT>{torque_arguments.length}, TNode<IntPtrT>{torque_arguments.actual_count}}, wasm::Promise::kPromise);
    arguments.PopAndReturn(tmp0);
  }
}

TF_BUILTIN(WasmStressSwitch, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Word32T> argc = UncheckedParameter<Word32T>(Descriptor::kJSActualArgumentsCount);
  TNode<IntPtrT> arguments_length(ChangeInt32ToIntPtr(UncheckedCast<Int32T>(argc)));
  TNode<RawPtrT> arguments_frame = UncheckedCast<RawPtrT>(LoadFramePointer());
  TorqueStructArguments torque_arguments(GetFrameArguments(arguments_frame, arguments_length, FrameArgumentsArgcType::kCountIncludesReceiver));
  CodeStubArguments arguments(this, torque_arguments);
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<JSAny> parameter1 = arguments.GetReceiver();
  USE(parameter1);
  TNode<JSFunction> parameter2 = UncheckedParameter<JSFunction>(Descriptor::kJSTarget);
  USE(parameter2);
  TNode<JSDispatchHandleT> parameter3 = UncheckedParameter<JSDispatchHandleT>(Descriptor::kJSDispatchHandle);
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSAny> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    CodeStubAssembler(state_).SetSupportsDynamicParameterCount(TNode<JSFunction>{parameter2}, TNode<JSDispatchHandleT>{parameter3});
    tmp0 = JSToWasmWrapperHelper_0(state_, TNode<NativeContext>{parameter0}, TNode<JSAny>{parameter1}, TNode<JSFunction>{parameter2}, TorqueStructArguments{TNode<RawPtrT>{torque_arguments.frame}, TNode<RawPtrT>{torque_arguments.base}, TNode<IntPtrT>{torque_arguments.length}, TNode<IntPtrT>{torque_arguments.actual_count}}, wasm::Promise::kStressSwitch);
    arguments.PopAndReturn(tmp0);
  }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=852&c=1
TNode<JSAny> WasmToJSObject_0(compiler::CodeAssemblerState* state_, TNode<NativeContext> p_context, TNode<Object> p_value, TNode<Int32T> p_retType) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block41(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block40(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block44(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block45(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block46(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block47(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block48(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block49(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block50(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block51(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block52(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block42(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block43(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block53(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block54(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block57(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block58(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block59(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block60(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block61(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block62(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block63(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block64(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block65(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block66(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block67(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block68(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block69(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block70(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block71(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block55(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block56(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny> block72(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Int32T> tmp1;
  TNode<Int32T> tmp2;
  TNode<Int32T> tmp3;
  TNode<Int32T> tmp4;
  TNode<Int32T> tmp5;
  TNode<Int32T> tmp6;
  TNode<BoolT> tmp7;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmValueKindBitsMask);
    tmp1 = CodeStubAssembler(state_).Word32And(TNode<Int32T>{p_retType}, TNode<Int32T>{tmp0});
    tmp2 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::ValueType::kKindBits);
    tmp3 = CodeStubAssembler(state_).Word32Sar(TNode<Int32T>{p_retType}, TNode<Int32T>{tmp2});
    tmp4 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmHeapTypeBitsMask);
    tmp5 = CodeStubAssembler(state_).Word32And(TNode<Int32T>{tmp3}, TNode<Int32T>{tmp4});
    tmp6 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::ValueKind::kRef);
    tmp7 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp1}, TNode<Int32T>{tmp6});
    ca_.Branch(tmp7, &block2, std::vector<compiler::Node*>{}, &block3, std::vector<compiler::Node*>{});
  }

  TNode<Int32T> tmp8;
  TNode<BoolT> tmp9;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp8 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::HeapType::Representation::kEq);
    tmp9 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp5}, TNode<Int32T>{tmp8});
    ca_.Branch(tmp9, &block7, std::vector<compiler::Node*>{}, &block8, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp10;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    tmp10 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block9, tmp10);
  }

  TNode<Int32T> tmp11;
  TNode<BoolT> tmp12;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    tmp11 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::HeapType::Representation::kI31);
    tmp12 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp5}, TNode<Int32T>{tmp11});
    ca_.Goto(&block9, tmp12);
  }

  TNode<BoolT> phi_bb9_6;
  if (block9.is_used()) {
    ca_.Bind(&block9, &phi_bb9_6);
    ca_.Branch(phi_bb9_6, &block10, std::vector<compiler::Node*>{}, &block11, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp13;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    tmp13 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block12, tmp13);
  }

  TNode<Int32T> tmp14;
  TNode<BoolT> tmp15;
  if (block11.is_used()) {
    ca_.Bind(&block11);
    tmp14 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::HeapType::Representation::kStruct);
    tmp15 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp5}, TNode<Int32T>{tmp14});
    ca_.Goto(&block12, tmp15);
  }

  TNode<BoolT> phi_bb12_6;
  if (block12.is_used()) {
    ca_.Bind(&block12, &phi_bb12_6);
    ca_.Branch(phi_bb12_6, &block13, std::vector<compiler::Node*>{}, &block14, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp16;
  if (block13.is_used()) {
    ca_.Bind(&block13);
    tmp16 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block15, tmp16);
  }

  TNode<Int32T> tmp17;
  TNode<BoolT> tmp18;
  if (block14.is_used()) {
    ca_.Bind(&block14);
    tmp17 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::HeapType::Representation::kArray);
    tmp18 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp5}, TNode<Int32T>{tmp17});
    ca_.Goto(&block15, tmp18);
  }

  TNode<BoolT> phi_bb15_6;
  if (block15.is_used()) {
    ca_.Bind(&block15, &phi_bb15_6);
    ca_.Branch(phi_bb15_6, &block16, std::vector<compiler::Node*>{}, &block17, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp19;
  if (block16.is_used()) {
    ca_.Bind(&block16);
    tmp19 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block18, tmp19);
  }

  TNode<Int32T> tmp20;
  TNode<BoolT> tmp21;
  if (block17.is_used()) {
    ca_.Bind(&block17);
    tmp20 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::HeapType::Representation::kAny);
    tmp21 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp5}, TNode<Int32T>{tmp20});
    ca_.Goto(&block18, tmp21);
  }

  TNode<BoolT> phi_bb18_6;
  if (block18.is_used()) {
    ca_.Bind(&block18, &phi_bb18_6);
    ca_.Branch(phi_bb18_6, &block19, std::vector<compiler::Node*>{}, &block20, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp22;
  if (block19.is_used()) {
    ca_.Bind(&block19);
    tmp22 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block21, tmp22);
  }

  TNode<Int32T> tmp23;
  TNode<BoolT> tmp24;
  if (block20.is_used()) {
    ca_.Bind(&block20);
    tmp23 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::HeapType::Representation::kExtern);
    tmp24 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp5}, TNode<Int32T>{tmp23});
    ca_.Goto(&block21, tmp24);
  }

  TNode<BoolT> phi_bb21_6;
  if (block21.is_used()) {
    ca_.Bind(&block21, &phi_bb21_6);
    ca_.Branch(phi_bb21_6, &block22, std::vector<compiler::Node*>{}, &block23, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp25;
  if (block22.is_used()) {
    ca_.Bind(&block22);
    tmp25 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block24, tmp25);
  }

  TNode<Int32T> tmp26;
  TNode<BoolT> tmp27;
  if (block23.is_used()) {
    ca_.Bind(&block23);
    tmp26 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::HeapType::Representation::kString);
    tmp27 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp5}, TNode<Int32T>{tmp26});
    ca_.Goto(&block24, tmp27);
  }

  TNode<BoolT> phi_bb24_6;
  if (block24.is_used()) {
    ca_.Bind(&block24, &phi_bb24_6);
    ca_.Branch(phi_bb24_6, &block25, std::vector<compiler::Node*>{}, &block26, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp28;
  if (block25.is_used()) {
    ca_.Bind(&block25);
    tmp28 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block27, tmp28);
  }

  TNode<Int32T> tmp29;
  TNode<BoolT> tmp30;
  if (block26.is_used()) {
    ca_.Bind(&block26);
    tmp29 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::HeapType::Representation::kNone);
    tmp30 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp5}, TNode<Int32T>{tmp29});
    ca_.Goto(&block27, tmp30);
  }

  TNode<BoolT> phi_bb27_6;
  if (block27.is_used()) {
    ca_.Bind(&block27, &phi_bb27_6);
    ca_.Branch(phi_bb27_6, &block28, std::vector<compiler::Node*>{}, &block29, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp31;
  if (block28.is_used()) {
    ca_.Bind(&block28);
    tmp31 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block30, tmp31);
  }

  TNode<Int32T> tmp32;
  TNode<BoolT> tmp33;
  if (block29.is_used()) {
    ca_.Bind(&block29);
    tmp32 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::HeapType::Representation::kNoFunc);
    tmp33 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp5}, TNode<Int32T>{tmp32});
    ca_.Goto(&block30, tmp33);
  }

  TNode<BoolT> phi_bb30_6;
  if (block30.is_used()) {
    ca_.Bind(&block30, &phi_bb30_6);
    ca_.Branch(phi_bb30_6, &block31, std::vector<compiler::Node*>{}, &block32, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp34;
  if (block31.is_used()) {
    ca_.Bind(&block31);
    tmp34 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block33, tmp34);
  }

  TNode<Int32T> tmp35;
  TNode<BoolT> tmp36;
  if (block32.is_used()) {
    ca_.Bind(&block32);
    tmp35 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::HeapType::Representation::kNoExtern);
    tmp36 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp5}, TNode<Int32T>{tmp35});
    ca_.Goto(&block33, tmp36);
  }

  TNode<BoolT> phi_bb33_6;
  if (block33.is_used()) {
    ca_.Bind(&block33, &phi_bb33_6);
    ca_.Branch(phi_bb33_6, &block34, std::vector<compiler::Node*>{}, &block35, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp37;
  if (block34.is_used()) {
    ca_.Bind(&block34);
    tmp37 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block36, tmp37);
  }

  TNode<Int32T> tmp38;
  TNode<BoolT> tmp39;
  if (block35.is_used()) {
    ca_.Bind(&block35);
    tmp38 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::HeapType::Representation::kExn);
    tmp39 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp5}, TNode<Int32T>{tmp38});
    ca_.Goto(&block36, tmp39);
  }

  TNode<BoolT> phi_bb36_6;
  if (block36.is_used()) {
    ca_.Bind(&block36, &phi_bb36_6);
    ca_.Branch(phi_bb36_6, &block37, std::vector<compiler::Node*>{}, &block38, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp40;
  if (block37.is_used()) {
    ca_.Bind(&block37);
    tmp40 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block39, tmp40);
  }

  TNode<Int32T> tmp41;
  TNode<BoolT> tmp42;
  if (block38.is_used()) {
    ca_.Bind(&block38);
    tmp41 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::HeapType::Representation::kNoExn);
    tmp42 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp5}, TNode<Int32T>{tmp41});
    ca_.Goto(&block39, tmp42);
  }

  TNode<BoolT> phi_bb39_6;
  if (block39.is_used()) {
    ca_.Bind(&block39, &phi_bb39_6);
    ca_.Branch(phi_bb39_6, &block5, std::vector<compiler::Node*>{}, &block6, std::vector<compiler::Node*>{});
  }

  TNode<JSAny> tmp43;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp43 = UnsafeCast_JSAny_0(state_, TNode<Context>{p_context}, TNode<Object>{p_value});
    ca_.Goto(&block1, tmp43);
  }

  TNode<JSAny> tmp44;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp44 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kWasmGenericWasmToJSObject, p_context, p_value)); 
    ca_.Goto(&block1, tmp44);
  }

  TNode<Int32T> tmp45;
  TNode<BoolT> tmp46;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp45 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::ValueKind::kRefNull);
    tmp46 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp1}, TNode<Int32T>{tmp45});
    ca_.Branch(tmp46, &block40, std::vector<compiler::Node*>{}, &block41, std::vector<compiler::Node*>{});
  }

  if (block41.is_used()) {
    ca_.Bind(&block41);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/js-to-wasm.tq", 871});
      CodeStubAssembler(state_).FailAssert("Torque assert 'paramKind == ValueKind::kRefNull' failed", pos_stack);
    }
  }

  TNode<Int32T> tmp47;
  TNode<BoolT> tmp48;
  if (block40.is_used()) {
    ca_.Bind(&block40);
    tmp47 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::HeapType::Representation::kExtern);
    tmp48 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp5}, TNode<Int32T>{tmp47});
    ca_.Branch(tmp48, &block44, std::vector<compiler::Node*>{}, &block45, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp49;
  if (block44.is_used()) {
    ca_.Bind(&block44);
    tmp49 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block46, tmp49);
  }

  TNode<Int32T> tmp50;
  TNode<BoolT> tmp51;
  if (block45.is_used()) {
    ca_.Bind(&block45);
    tmp50 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::HeapType::Representation::kNoExtern);
    tmp51 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp5}, TNode<Int32T>{tmp50});
    ca_.Goto(&block46, tmp51);
  }

  TNode<BoolT> phi_bb46_6;
  if (block46.is_used()) {
    ca_.Bind(&block46, &phi_bb46_6);
    ca_.Branch(phi_bb46_6, &block47, std::vector<compiler::Node*>{}, &block48, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp52;
  if (block47.is_used()) {
    ca_.Bind(&block47);
    tmp52 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block49, tmp52);
  }

  TNode<Int32T> tmp53;
  TNode<BoolT> tmp54;
  if (block48.is_used()) {
    ca_.Bind(&block48);
    tmp53 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::HeapType::Representation::kExn);
    tmp54 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp5}, TNode<Int32T>{tmp53});
    ca_.Goto(&block49, tmp54);
  }

  TNode<BoolT> phi_bb49_6;
  if (block49.is_used()) {
    ca_.Bind(&block49, &phi_bb49_6);
    ca_.Branch(phi_bb49_6, &block50, std::vector<compiler::Node*>{}, &block51, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp55;
  if (block50.is_used()) {
    ca_.Bind(&block50);
    tmp55 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block52, tmp55);
  }

  TNode<Int32T> tmp56;
  TNode<BoolT> tmp57;
  if (block51.is_used()) {
    ca_.Bind(&block51);
    tmp56 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::HeapType::Representation::kNoExn);
    tmp57 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp5}, TNode<Int32T>{tmp56});
    ca_.Goto(&block52, tmp57);
  }

  TNode<BoolT> phi_bb52_6;
  if (block52.is_used()) {
    ca_.Bind(&block52, &phi_bb52_6);
    ca_.Branch(phi_bb52_6, &block42, std::vector<compiler::Node*>{}, &block43, std::vector<compiler::Node*>{});
  }

  TNode<JSAny> tmp58;
  if (block42.is_used()) {
    ca_.Bind(&block42);
    tmp58 = UnsafeCast_JSAny_0(state_, TNode<Context>{p_context}, TNode<Object>{p_value});
    ca_.Goto(&block1, tmp58);
  }

  TNode<WasmNull> tmp59;
  TNode<BoolT> tmp60;
  if (block43.is_used()) {
    ca_.Bind(&block43);
    tmp59 = kWasmNull_0(state_);
    tmp60 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{p_value}, TNode<Union<Context, FixedArrayBase, FunctionTemplateInfo, Hole, JSReceiver, Map, Oddball, String, Symbol, WasmFuncRef, WasmNull, WeakCell>>{tmp59});
    ca_.Branch(tmp60, &block53, std::vector<compiler::Node*>{}, &block54, std::vector<compiler::Node*>{});
  }

  TNode<Null> tmp61;
  if (block53.is_used()) {
    ca_.Bind(&block53);
    tmp61 = Null_0(state_);
    ca_.Goto(&block1, tmp61);
  }

  TNode<Int32T> tmp62;
  TNode<BoolT> tmp63;
  if (block54.is_used()) {
    ca_.Bind(&block54);
    tmp62 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::HeapType::Representation::kEq);
    tmp63 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp5}, TNode<Int32T>{tmp62});
    ca_.Branch(tmp63, &block57, std::vector<compiler::Node*>{}, &block58, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp64;
  if (block57.is_used()) {
    ca_.Bind(&block57);
    tmp64 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block59, tmp64);
  }

  TNode<Int32T> tmp65;
  TNode<BoolT> tmp66;
  if (block58.is_used()) {
    ca_.Bind(&block58);
    tmp65 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::HeapType::Representation::kStruct);
    tmp66 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp5}, TNode<Int32T>{tmp65});
    ca_.Goto(&block59, tmp66);
  }

  TNode<BoolT> phi_bb59_6;
  if (block59.is_used()) {
    ca_.Bind(&block59, &phi_bb59_6);
    ca_.Branch(phi_bb59_6, &block60, std::vector<compiler::Node*>{}, &block61, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp67;
  if (block60.is_used()) {
    ca_.Bind(&block60);
    tmp67 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block62, tmp67);
  }

  TNode<Int32T> tmp68;
  TNode<BoolT> tmp69;
  if (block61.is_used()) {
    ca_.Bind(&block61);
    tmp68 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::HeapType::Representation::kArray);
    tmp69 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp5}, TNode<Int32T>{tmp68});
    ca_.Goto(&block62, tmp69);
  }

  TNode<BoolT> phi_bb62_6;
  if (block62.is_used()) {
    ca_.Bind(&block62, &phi_bb62_6);
    ca_.Branch(phi_bb62_6, &block63, std::vector<compiler::Node*>{}, &block64, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp70;
  if (block63.is_used()) {
    ca_.Bind(&block63);
    tmp70 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block65, tmp70);
  }

  TNode<Int32T> tmp71;
  TNode<BoolT> tmp72;
  if (block64.is_used()) {
    ca_.Bind(&block64);
    tmp71 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::HeapType::Representation::kString);
    tmp72 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp5}, TNode<Int32T>{tmp71});
    ca_.Goto(&block65, tmp72);
  }

  TNode<BoolT> phi_bb65_6;
  if (block65.is_used()) {
    ca_.Bind(&block65, &phi_bb65_6);
    ca_.Branch(phi_bb65_6, &block66, std::vector<compiler::Node*>{}, &block67, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp73;
  if (block66.is_used()) {
    ca_.Bind(&block66);
    tmp73 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block68, tmp73);
  }

  TNode<Int32T> tmp74;
  TNode<BoolT> tmp75;
  if (block67.is_used()) {
    ca_.Bind(&block67);
    tmp74 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::HeapType::Representation::kI31);
    tmp75 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp5}, TNode<Int32T>{tmp74});
    ca_.Goto(&block68, tmp75);
  }

  TNode<BoolT> phi_bb68_6;
  if (block68.is_used()) {
    ca_.Bind(&block68, &phi_bb68_6);
    ca_.Branch(phi_bb68_6, &block69, std::vector<compiler::Node*>{}, &block70, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp76;
  if (block69.is_used()) {
    ca_.Bind(&block69);
    tmp76 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block71, tmp76);
  }

  TNode<Int32T> tmp77;
  TNode<BoolT> tmp78;
  if (block70.is_used()) {
    ca_.Bind(&block70);
    tmp77 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::HeapType::Representation::kAny);
    tmp78 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp5}, TNode<Int32T>{tmp77});
    ca_.Goto(&block71, tmp78);
  }

  TNode<BoolT> phi_bb71_6;
  if (block71.is_used()) {
    ca_.Bind(&block71, &phi_bb71_6);
    ca_.Branch(phi_bb71_6, &block55, std::vector<compiler::Node*>{}, &block56, std::vector<compiler::Node*>{});
  }

  TNode<JSAny> tmp79;
  if (block55.is_used()) {
    ca_.Bind(&block55);
    tmp79 = UnsafeCast_JSAny_0(state_, TNode<Context>{p_context}, TNode<Object>{p_value});
    ca_.Goto(&block1, tmp79);
  }

  TNode<JSAny> tmp80;
  if (block56.is_used()) {
    ca_.Bind(&block56);
    tmp80 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kWasmGenericWasmToJSObject, p_context, p_value)); 
    ca_.Goto(&block1, tmp80);
  }

  TNode<JSAny> phi_bb1_3;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_3);
    ca_.Goto(&block72, phi_bb1_3);
  }

  TNode<JSAny> phi_bb72_3;
    ca_.Bind(&block72, &phi_bb72_3);
  return TNode<JSAny>{phi_bb72_3};
}

TF_BUILTIN(JSToWasmHandleReturns, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kJsContext);
  USE(parameter0);
  TNode<JSArray> parameter1 = UncheckedParameter<JSArray>(Descriptor::kResultArray);
  USE(parameter1);
  TNode<RawPtrT> parameter2 = UncheckedParameter<RawPtrT>(Descriptor::kWrapperBuffer);
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block30(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block47(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block51(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block49(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block54(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block58(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block59(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block61(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block62(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block64(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block65(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT> block60(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT> block57(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block55(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block66(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block70(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block71(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block73(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block74(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block76(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block77(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT> block72(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT> block69(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block67(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block78(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block82(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block83(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block85(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block86(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block88(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block89(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT> block84(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT> block81(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block90(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block94(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block95(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block97(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block98(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block100(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block101(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT> block96(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT> block93(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block91(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block92(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block79(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block102(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block105(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block106(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block107(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block111(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block112(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block114(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block115(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT> block110(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block108(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT> block104(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block103(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block80(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block68(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block56(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block50(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT> block117(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT> block118(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block121(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block119(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block126(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block127(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, BoolT> block128(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block124(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block130(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block131(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block133(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block134(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block136(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block137(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT> block132(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT> block129(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block142(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block143(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block125(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block120(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT> block48(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT> block149(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT> block150(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT> block151(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT> block148(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT> block147(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block154(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block152(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block157(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block161(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block162(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block164(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block165(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block167(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block168(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT> block163(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT> block160(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT> block169(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT> block170(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT, Int32T> block171(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block176(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block177(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block158(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block180(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block184(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block185(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block187(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block188(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block190(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block191(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT> block186(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT> block183(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT> block192(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT> block195(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT> block196(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT, Float32T> block198(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT> block193(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT> block199(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT> block202(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT> block203(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT, Float32T> block205(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT> block200(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT, Float32T> block201(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT, Float32T> block194(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block210(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block211(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block181(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block214(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block217(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block221(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block222(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block224(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block225(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block227(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block228(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT> block223(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT> block220(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block233(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block234(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block218(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block238(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block239(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block241(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block242(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block244(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block245(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT> block240(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT> block237(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT> block247(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT> block248(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT> block250(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT> block251(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT> block253(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT> block254(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT> block249(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT> block246(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block259(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block260(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block219(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block215(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block263(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block267(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block268(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block269(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block273(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block274(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block276(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block277(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT> block272(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block270(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT> block266(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block282(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Union<HeapObject, TaggedIndex>, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block283(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block264(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block288(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block289(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, BoolT> block290(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block287(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block286(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block295(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block296(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block303(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block304(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block265(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block216(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block182(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block159(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block153(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT> block310(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT> block311(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT> block312(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT> block309(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT> block308(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Union<HeapObject, TaggedIndex>> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Int32T> tmp3;
  TNode<Int32T> tmp4;
  TNode<BoolT> tmp5;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_intptr_0(state_, JSToWasmWrapperFrameConstants::kWrapperBufferReturnCount);
    std::tie(tmp1, tmp2) = GetRefAt_int32_RawPtr_intptr_0(state_, TNode<RawPtrT>{parameter2}, TNode<IntPtrT>{tmp0}).Flatten();
    tmp3 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{tmp1, tmp2});
    tmp4 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp5 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp3}, TNode<Int32T>{tmp4});
    ca_.Branch(tmp5, &block1, std::vector<compiler::Node*>{}, &block2, std::vector<compiler::Node*>{});
  }

  TNode<Undefined> tmp6;
  if (block1.is_used()) {
    ca_.Bind(&block1);
    tmp6 = Undefined_0(state_);
    CodeStubAssembler(state_).Return(tmp6);
  }

  TNode<Int32T> tmp7;
  TNode<BoolT> tmp8;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp7 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp8 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp3}, TNode<Int32T>{tmp7});
    ca_.Branch(tmp8, &block3, std::vector<compiler::Node*>{}, &block4, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp9;
  TNode<Union<HeapObject, TaggedIndex>> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<RawPtrT> tmp12;
  TNode<IntPtrT> tmp13;
  TNode<Union<HeapObject, TaggedIndex>> tmp14;
  TNode<IntPtrT> tmp15;
  TNode<Int32T> tmp16;
  TNode<Int32T> tmp17;
  TNode<BoolT> tmp18;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp9 = FromConstexpr_intptr_constexpr_intptr_0(state_, JSToWasmWrapperFrameConstants::kWrapperBufferSigRepresentationArray);
    std::tie(tmp10, tmp11) = GetRefAt_RawPtr_RawPtr_intptr_0(state_, TNode<RawPtrT>{parameter2}, TNode<IntPtrT>{tmp9}).Flatten();
    tmp12 = CodeStubAssembler(state_).LoadReference<RawPtrT>(CodeStubAssembler::Reference{tmp10, tmp11});
    tmp13 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    std::tie(tmp14, tmp15) = GetRefAt_int32_RawPtr_0(state_, TNode<RawPtrT>{tmp12}, TNode<IntPtrT>{tmp13}).Flatten();
    tmp16 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{tmp14, tmp15});
    tmp17 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmI32.raw_bit_field());
    tmp18 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp16}, TNode<Int32T>{tmp17});
    ca_.Branch(tmp18, &block5, std::vector<compiler::Node*>{}, &block6, std::vector<compiler::Node*>{});
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    if ((wasm::kIsBigEndian)) {
      ca_.Goto(&block8);
    } else {
      ca_.Goto(&block9);
    }
  }

  TNode<IntPtrT> tmp19;
  TNode<Union<HeapObject, TaggedIndex>> tmp20;
  TNode<IntPtrT> tmp21;
  TNode<Int64T> tmp22;
  TNode<Int32T> tmp23;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    tmp19 = FromConstexpr_intptr_constexpr_intptr_0(state_, JSToWasmWrapperFrameConstants::kWrapperBufferGPReturnRegister1);
    std::tie(tmp20, tmp21) = GetRefAt_int64_RawPtr_intptr_0(state_, TNode<RawPtrT>{parameter2}, TNode<IntPtrT>{tmp19}).Flatten();
    tmp22 = CodeStubAssembler(state_).LoadReference<Int64T>(CodeStubAssembler::Reference{tmp20, tmp21});
    tmp23 = CodeStubAssembler(state_).TruncateInt64ToInt32(TNode<Int64T>{tmp22});
    ca_.Goto(&block10, tmp23);
  }

  TNode<IntPtrT> tmp24;
  TNode<Union<HeapObject, TaggedIndex>> tmp25;
  TNode<IntPtrT> tmp26;
  TNode<Int32T> tmp27;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    tmp24 = FromConstexpr_intptr_constexpr_intptr_0(state_, JSToWasmWrapperFrameConstants::kWrapperBufferGPReturnRegister1);
    std::tie(tmp25, tmp26) = GetRefAt_int32_RawPtr_intptr_0(state_, TNode<RawPtrT>{parameter2}, TNode<IntPtrT>{tmp24}).Flatten();
    tmp27 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{tmp25, tmp26});
    ca_.Goto(&block10, tmp27);
  }

  TNode<Int32T> phi_bb10_6;
  TNode<Number> tmp28;
  if (block10.is_used()) {
    ca_.Bind(&block10, &phi_bb10_6);
    tmp28 = Convert_Number_int32_0(state_, TNode<Int32T>{phi_bb10_6});
    CodeStubAssembler(state_).Return(tmp28);
  }

  TNode<Int32T> tmp29;
  TNode<BoolT> tmp30;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp29 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmF32.raw_bit_field());
    tmp30 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp16}, TNode<Int32T>{tmp29});
    ca_.Branch(tmp30, &block11, std::vector<compiler::Node*>{}, &block12, std::vector<compiler::Node*>{});
  }

  if (block11.is_used()) {
    ca_.Bind(&block11);
    if ((wasm::kIsFpAlwaysDouble)) {
      ca_.Goto(&block14);
    } else {
      ca_.Goto(&block15);
    }
  }

  TNode<IntPtrT> tmp31;
  TNode<Union<HeapObject, TaggedIndex>> tmp32;
  TNode<IntPtrT> tmp33;
  TNode<Float64T> tmp34;
  TNode<Float32T> tmp35;
  TNode<Number> tmp36;
  if (block14.is_used()) {
    ca_.Bind(&block14);
    tmp31 = FromConstexpr_intptr_constexpr_intptr_0(state_, JSToWasmWrapperFrameConstants::kWrapperBufferFPReturnRegister1);
    std::tie(tmp32, tmp33) = GetRefAt_float64_RawPtr_intptr_0(state_, TNode<RawPtrT>{parameter2}, TNode<IntPtrT>{tmp31}).Flatten();
    tmp34 = CodeStubAssembler(state_).LoadReference<Float64T>(CodeStubAssembler::Reference{tmp32, tmp33});
    tmp35 = CodeStubAssembler(state_).TruncateFloat64ToFloat32(TNode<Float64T>{tmp34});
    tmp36 = Convert_Number_float32_0(state_, TNode<Float32T>{tmp35});
    CodeStubAssembler(state_).Return(tmp36);
  }

  if (block15.is_used()) {
    ca_.Bind(&block15);
    if ((wasm::kIsBigEndianOnSim)) {
      ca_.Goto(&block17);
    } else {
      ca_.Goto(&block18);
    }
  }

  TNode<IntPtrT> tmp37;
  TNode<Union<HeapObject, TaggedIndex>> tmp38;
  TNode<IntPtrT> tmp39;
  TNode<Int64T> tmp40;
  TNode<Int64T> tmp41;
  TNode<Int64T> tmp42;
  TNode<Int32T> tmp43;
  TNode<Float32T> tmp44;
  TNode<Number> tmp45;
  if (block17.is_used()) {
    ca_.Bind(&block17);
    tmp37 = FromConstexpr_intptr_constexpr_intptr_0(state_, JSToWasmWrapperFrameConstants::kWrapperBufferFPReturnRegister1);
    std::tie(tmp38, tmp39) = GetRefAt_int64_RawPtr_intptr_0(state_, TNode<RawPtrT>{parameter2}, TNode<IntPtrT>{tmp37}).Flatten();
    tmp40 = CodeStubAssembler(state_).LoadReference<Int64T>(CodeStubAssembler::Reference{tmp38, tmp39});
    tmp41 = FromConstexpr_int64_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x20ull));
    tmp42 = CodeStubAssembler(state_).Word64Sar(TNode<Int64T>{tmp40}, TNode<Int64T>{tmp41});
    tmp43 = CodeStubAssembler(state_).TruncateInt64ToInt32(TNode<Int64T>{tmp42});
    tmp44 = CodeStubAssembler(state_).BitcastInt32ToFloat32(TNode<Int32T>{tmp43});
    tmp45 = Convert_Number_float32_0(state_, TNode<Float32T>{tmp44});
    CodeStubAssembler(state_).Return(tmp45);
  }

  TNode<IntPtrT> tmp46;
  TNode<Union<HeapObject, TaggedIndex>> tmp47;
  TNode<IntPtrT> tmp48;
  TNode<Float32T> tmp49;
  TNode<Number> tmp50;
  if (block18.is_used()) {
    ca_.Bind(&block18);
    tmp46 = FromConstexpr_intptr_constexpr_intptr_0(state_, JSToWasmWrapperFrameConstants::kWrapperBufferFPReturnRegister1);
    std::tie(tmp47, tmp48) = GetRefAt_float32_RawPtr_intptr_0(state_, TNode<RawPtrT>{parameter2}, TNode<IntPtrT>{tmp46}).Flatten();
    tmp49 = CodeStubAssembler(state_).LoadReference<Float32T>(CodeStubAssembler::Reference{tmp47, tmp48});
    tmp50 = Convert_Number_float32_0(state_, TNode<Float32T>{tmp49});
    CodeStubAssembler(state_).Return(tmp50);
  }

  TNode<Int32T> tmp51;
  TNode<BoolT> tmp52;
  if (block12.is_used()) {
    ca_.Bind(&block12);
    tmp51 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmF64.raw_bit_field());
    tmp52 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp16}, TNode<Int32T>{tmp51});
    ca_.Branch(tmp52, &block20, std::vector<compiler::Node*>{}, &block21, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp53;
  TNode<Union<HeapObject, TaggedIndex>> tmp54;
  TNode<IntPtrT> tmp55;
  TNode<Float64T> tmp56;
  TNode<Number> tmp57;
  if (block20.is_used()) {
    ca_.Bind(&block20);
    tmp53 = FromConstexpr_intptr_constexpr_intptr_0(state_, JSToWasmWrapperFrameConstants::kWrapperBufferFPReturnRegister1);
    std::tie(tmp54, tmp55) = GetRefAt_float64_RawPtr_intptr_0(state_, TNode<RawPtrT>{parameter2}, TNode<IntPtrT>{tmp53}).Flatten();
    tmp56 = CodeStubAssembler(state_).LoadReference<Float64T>(CodeStubAssembler::Reference{tmp54, tmp55});
    tmp57 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp56});
    CodeStubAssembler(state_).Return(tmp57);
  }

  TNode<Int32T> tmp58;
  TNode<BoolT> tmp59;
  if (block21.is_used()) {
    ca_.Bind(&block21);
    tmp58 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmI64.raw_bit_field());
    tmp59 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp16}, TNode<Int32T>{tmp58});
    ca_.Branch(tmp59, &block23, std::vector<compiler::Node*>{}, &block24, std::vector<compiler::Node*>{});
  }

  if (block23.is_used()) {
    ca_.Bind(&block23);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block26);
    } else {
      ca_.Goto(&block27);
    }
  }

  TNode<IntPtrT> tmp60;
  TNode<Union<HeapObject, TaggedIndex>> tmp61;
  TNode<IntPtrT> tmp62;
  TNode<IntPtrT> tmp63;
  TNode<BigInt> tmp64;
  if (block26.is_used()) {
    ca_.Bind(&block26);
    tmp60 = FromConstexpr_intptr_constexpr_intptr_0(state_, JSToWasmWrapperFrameConstants::kWrapperBufferGPReturnRegister1);
    std::tie(tmp61, tmp62) = GetRefAt_intptr_RawPtr_intptr_0(state_, TNode<RawPtrT>{parameter2}, TNode<IntPtrT>{tmp60}).Flatten();
    tmp63 = CodeStubAssembler(state_).LoadReference<IntPtrT>(CodeStubAssembler::Reference{tmp61, tmp62});
    tmp64 = ca_.CallBuiltin<BigInt>(Builtin::kI64ToBigInt, TNode<Object>(), tmp63);
    CodeStubAssembler(state_).Return(tmp64);
  }

  TNode<IntPtrT> tmp65;
  TNode<Union<HeapObject, TaggedIndex>> tmp66;
  TNode<IntPtrT> tmp67;
  TNode<IntPtrT> tmp68;
  TNode<IntPtrT> tmp69;
  TNode<Union<HeapObject, TaggedIndex>> tmp70;
  TNode<IntPtrT> tmp71;
  TNode<IntPtrT> tmp72;
  TNode<BigInt> tmp73;
  if (block27.is_used()) {
    ca_.Bind(&block27);
    tmp65 = FromConstexpr_intptr_constexpr_intptr_0(state_, JSToWasmWrapperFrameConstants::kWrapperBufferGPReturnRegister1);
    std::tie(tmp66, tmp67) = GetRefAt_intptr_RawPtr_intptr_0(state_, TNode<RawPtrT>{parameter2}, TNode<IntPtrT>{tmp65}).Flatten();
    tmp68 = CodeStubAssembler(state_).LoadReference<IntPtrT>(CodeStubAssembler::Reference{tmp66, tmp67});
    tmp69 = FromConstexpr_intptr_constexpr_intptr_0(state_, JSToWasmWrapperFrameConstants::kWrapperBufferGPReturnRegister2);
    std::tie(tmp70, tmp71) = GetRefAt_intptr_RawPtr_intptr_0(state_, TNode<RawPtrT>{parameter2}, TNode<IntPtrT>{tmp69}).Flatten();
    tmp72 = CodeStubAssembler(state_).LoadReference<IntPtrT>(CodeStubAssembler::Reference{tmp70, tmp71});
    tmp73 = ca_.CallBuiltin<BigInt>(Builtin::kI32PairToBigInt, TNode<Object>(), tmp68, tmp72);
    CodeStubAssembler(state_).Return(tmp73);
  }

  TNode<Int32T> tmp74;
  TNode<Int32T> tmp75;
  TNode<Int32T> tmp76;
  TNode<BoolT> tmp77;
  if (block24.is_used()) {
    ca_.Bind(&block24);
    tmp74 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmValueKindBitsMask);
    tmp75 = CodeStubAssembler(state_).Word32And(TNode<Int32T>{tmp16}, TNode<Int32T>{tmp74});
    tmp76 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::ValueKind::kRef);
    tmp77 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp75}, TNode<Int32T>{tmp76});
    ca_.Branch(tmp77, &block31, std::vector<compiler::Node*>{}, &block32, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp78;
  if (block31.is_used()) {
    ca_.Bind(&block31);
    tmp78 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block33, tmp78);
  }

  TNode<Int32T> tmp79;
  TNode<BoolT> tmp80;
  if (block32.is_used()) {
    ca_.Bind(&block32);
    tmp79 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::ValueKind::kRefNull);
    tmp80 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp75}, TNode<Int32T>{tmp79});
    ca_.Goto(&block33, tmp80);
  }

  TNode<BoolT> phi_bb33_8;
  if (block33.is_used()) {
    ca_.Bind(&block33, &phi_bb33_8);
    ca_.Branch(phi_bb33_8, &block29, std::vector<compiler::Node*>{}, &block30, std::vector<compiler::Node*>{});
  }

  if (block30.is_used()) {
    ca_.Bind(&block30);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/js-to-wasm.tq", 947});
      CodeStubAssembler(state_).FailAssert("Torque assert 'retKind == ValueKind::kRef || retKind == ValueKind::kRefNull' failed", pos_stack);
    }
  }

  TNode<IntPtrT> tmp81;
  TNode<RawPtrT> tmp82;
  TNode<RawPtrT> tmp83;
  TNode<IntPtrT> tmp84;
  TNode<Union<HeapObject, TaggedIndex>> tmp85;
  TNode<IntPtrT> tmp86;
  TNode<UintPtrT> tmp87;
  TNode<Object> tmp88;
  TNode<JSAny> tmp89;
  if (block29.is_used()) {
    ca_.Bind(&block29);
    tmp81 = FromConstexpr_intptr_constexpr_intptr_0(state_, JSToWasmWrapperFrameConstants::kWrapperBufferGPReturnRegister1);
    tmp82 = CodeStubAssembler(state_).RawPtrAdd(TNode<RawPtrT>{parameter2}, TNode<IntPtrT>{tmp81});
    tmp83 = (TNode<RawPtrT>{tmp82});
    tmp84 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    std::tie(tmp85, tmp86) = GetRefAt_uintptr_RawPtr_uintptr_0(state_, TNode<RawPtrT>{tmp83}, TNode<IntPtrT>{tmp84}).Flatten();
    tmp87 = CodeStubAssembler(state_).LoadReference<UintPtrT>(CodeStubAssembler::Reference{tmp85, tmp86});
    tmp88 = CodeStubAssembler(state_).BitcastWordToTagged(TNode<UintPtrT>{tmp87});
    tmp89 = WasmToJSObject_0(state_, TNode<NativeContext>{parameter0}, TNode<Object>{tmp88}, TNode<Int32T>{tmp16});
    CodeStubAssembler(state_).Return(tmp89);
  }

  TNode<IntPtrT> tmp90;
  TNode<FixedArrayBase> tmp91;
  TNode<FixedArray> tmp92;
  TNode<IntPtrT> tmp93;
  TNode<Union<HeapObject, TaggedIndex>> tmp94;
  TNode<IntPtrT> tmp95;
  TNode<RawPtrT> tmp96;
  TNode<IntPtrT> tmp97;
  TNode<RawPtrT> tmp98;
  TNode<IntPtrT> tmp99;
  TNode<RawPtrT> tmp100;
  TNode<Union<HeapObject, TaggedIndex>> tmp101;
  TNode<IntPtrT> tmp102;
  TNode<IntPtrT> tmp103;
  TNode<IntPtrT> tmp104;
  TNode<IntPtrT> tmp105;
  TNode<IntPtrT> tmp106;
  TNode<IntPtrT> tmp107;
  TNode<IntPtrT> tmp108;
  TNode<IntPtrT> tmp109;
  TNode<BoolT> tmp110;
  TNode<IntPtrT> tmp111;
  TNode<Union<HeapObject, TaggedIndex>> tmp112;
  TNode<IntPtrT> tmp113;
  TNode<RawPtrT> tmp114;
  TNode<RawPtrT> tmp115;
  TNode<IntPtrT> tmp116;
  TNode<Union<HeapObject, TaggedIndex>> tmp117;
  TNode<IntPtrT> tmp118;
  TNode<IntPtrT> tmp119;
  TNode<IntPtrT> tmp120;
  TNode<Union<HeapObject, TaggedIndex>> tmp121;
  TNode<IntPtrT> tmp122;
  TNode<BoolT> tmp123;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp90 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp91 = CodeStubAssembler(state_).LoadReference<FixedArrayBase>(CodeStubAssembler::Reference{parameter1, tmp90});
    tmp92 = TORQUE_CAST(TNode<Object>{tmp91});
    tmp93 = FromConstexpr_intptr_constexpr_intptr_0(state_, JSToWasmWrapperFrameConstants::kWrapperBufferStackReturnBufferStart);
    std::tie(tmp94, tmp95) = GetRefAt_RawPtr_RawPtr_intptr_0(state_, TNode<RawPtrT>{parameter2}, TNode<IntPtrT>{tmp93}).Flatten();
    tmp96 = CodeStubAssembler(state_).LoadReference<RawPtrT>(CodeStubAssembler::Reference{tmp94, tmp95});
    tmp97 = FromConstexpr_intptr_constexpr_intptr_0(state_, JSToWasmWrapperFrameConstants::kWrapperBufferGPReturnRegister1);
    tmp98 = CodeStubAssembler(state_).RawPtrAdd(TNode<RawPtrT>{parameter2}, TNode<IntPtrT>{tmp97});
    tmp99 = FromConstexpr_intptr_constexpr_intptr_0(state_, JSToWasmWrapperFrameConstants::kWrapperBufferFPReturnRegister1);
    tmp100 = CodeStubAssembler(state_).RawPtrAdd(TNode<RawPtrT>{parameter2}, TNode<IntPtrT>{tmp99});
    std::tie(tmp101, tmp102, tmp103, tmp104, tmp105, tmp106, tmp107, tmp108, tmp109, tmp110) = LocationAllocatorForReturns_0(state_, TNode<RawPtrT>{tmp98}, TNode<RawPtrT>{tmp100}, TNode<RawPtrT>{tmp96}).Flatten();
    tmp111 = FromConstexpr_intptr_constexpr_intptr_0(state_, JSToWasmWrapperFrameConstants::kWrapperBufferSigRepresentationArray);
    std::tie(tmp112, tmp113) = GetRefAt_RawPtr_RawPtr_intptr_0(state_, TNode<RawPtrT>{parameter2}, TNode<IntPtrT>{tmp111}).Flatten();
    tmp114 = CodeStubAssembler(state_).LoadReference<RawPtrT>(CodeStubAssembler::Reference{tmp112, tmp113});
    tmp115 = (TNode<RawPtrT>{tmp114});
    tmp116 = Convert_intptr_int32_0(state_, TNode<Int32T>{tmp3});
    std::tie(tmp117, tmp118, tmp119) = NewOffHeapConstSlice_int32_0(state_, TNode<RawPtrT>{tmp115}, TNode<IntPtrT>{tmp116}).Flatten();
    tmp120 = FromConstexpr_intptr_constexpr_intptr_0(state_, JSToWasmWrapperFrameConstants::kWrapperBufferRefReturnCount);
    std::tie(tmp121, tmp122) = GetRefAt_bool_RawPtr_intptr_0(state_, TNode<RawPtrT>{parameter2}, TNode<IntPtrT>{tmp120}).Flatten();
    tmp123 = CodeStubAssembler(state_).LoadReference<BoolT>(CodeStubAssembler::Reference{tmp121, tmp122});
    ca_.Branch(tmp123, &block47, std::vector<compiler::Node*>{}, &block48, std::vector<compiler::Node*>{tmp102, tmp103, tmp104, tmp105, tmp106, tmp109, tmp110});
  }

  TNode<IntPtrT> tmp124;
  if (block47.is_used()) {
    ca_.Bind(&block47);
    tmp124 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.Goto(&block51, tmp102, tmp103, tmp104, tmp105, tmp106, tmp109, tmp110, tmp124);
  }

  TNode<IntPtrT> phi_bb51_7;
  TNode<IntPtrT> phi_bb51_8;
  TNode<IntPtrT> phi_bb51_9;
  TNode<IntPtrT> phi_bb51_10;
  TNode<IntPtrT> phi_bb51_11;
  TNode<IntPtrT> phi_bb51_14;
  TNode<BoolT> phi_bb51_15;
  TNode<IntPtrT> phi_bb51_21;
  TNode<IntPtrT> tmp125;
  TNode<BoolT> tmp126;
  if (block51.is_used()) {
    ca_.Bind(&block51, &phi_bb51_7, &phi_bb51_8, &phi_bb51_9, &phi_bb51_10, &phi_bb51_11, &phi_bb51_14, &phi_bb51_15, &phi_bb51_21);
    tmp125 = Convert_intptr_int32_0(state_, TNode<Int32T>{tmp3});
    tmp126 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{phi_bb51_21}, TNode<IntPtrT>{tmp125});
    ca_.Branch(tmp126, &block49, std::vector<compiler::Node*>{phi_bb51_7, phi_bb51_8, phi_bb51_9, phi_bb51_10, phi_bb51_11, phi_bb51_14, phi_bb51_15, phi_bb51_21}, &block50, std::vector<compiler::Node*>{phi_bb51_7, phi_bb51_8, phi_bb51_9, phi_bb51_10, phi_bb51_11, phi_bb51_14, phi_bb51_15, phi_bb51_21});
  }

  TNode<IntPtrT> phi_bb49_7;
  TNode<IntPtrT> phi_bb49_8;
  TNode<IntPtrT> phi_bb49_9;
  TNode<IntPtrT> phi_bb49_10;
  TNode<IntPtrT> phi_bb49_11;
  TNode<IntPtrT> phi_bb49_14;
  TNode<BoolT> phi_bb49_15;
  TNode<IntPtrT> phi_bb49_21;
  TNode<IntPtrT> tmp127;
  TNode<IntPtrT> tmp128;
  TNode<Union<HeapObject, TaggedIndex>> tmp129;
  TNode<IntPtrT> tmp130;
  TNode<Int32T> tmp131;
  TNode<Int32T> tmp132;
  TNode<BoolT> tmp133;
  if (block49.is_used()) {
    ca_.Bind(&block49, &phi_bb49_7, &phi_bb49_8, &phi_bb49_9, &phi_bb49_10, &phi_bb49_11, &phi_bb49_14, &phi_bb49_15, &phi_bb49_21);
    tmp127 = TimesSizeOf_int32_0(state_, TNode<IntPtrT>{phi_bb49_21});
    tmp128 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp118}, TNode<IntPtrT>{tmp127});
    std::tie(tmp129, tmp130) = NewReference_int32_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp117}, TNode<IntPtrT>{tmp128}).Flatten();
    tmp131 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{tmp129, tmp130});
    tmp132 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmI32.raw_bit_field());
    tmp133 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp131}, TNode<Int32T>{tmp132});
    ca_.Branch(tmp133, &block54, std::vector<compiler::Node*>{phi_bb49_7, phi_bb49_8, phi_bb49_9, phi_bb49_10, phi_bb49_11, phi_bb49_14, phi_bb49_15, phi_bb49_21}, &block55, std::vector<compiler::Node*>{phi_bb49_7, phi_bb49_8, phi_bb49_9, phi_bb49_10, phi_bb49_11, phi_bb49_14, phi_bb49_15, phi_bb49_21});
  }

  TNode<IntPtrT> phi_bb54_7;
  TNode<IntPtrT> phi_bb54_8;
  TNode<IntPtrT> phi_bb54_9;
  TNode<IntPtrT> phi_bb54_10;
  TNode<IntPtrT> phi_bb54_11;
  TNode<IntPtrT> phi_bb54_14;
  TNode<BoolT> phi_bb54_15;
  TNode<IntPtrT> phi_bb54_21;
  TNode<IntPtrT> tmp134;
  TNode<IntPtrT> tmp135;
  TNode<IntPtrT> tmp136;
  TNode<BoolT> tmp137;
  if (block54.is_used()) {
    ca_.Bind(&block54, &phi_bb54_7, &phi_bb54_8, &phi_bb54_9, &phi_bb54_10, &phi_bb54_11, &phi_bb54_14, &phi_bb54_15, &phi_bb54_21);
    tmp134 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp135 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{phi_bb54_7}, TNode<IntPtrT>{tmp134});
    tmp136 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp137 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{phi_bb54_7}, TNode<IntPtrT>{tmp136});
    ca_.Branch(tmp137, &block58, std::vector<compiler::Node*>{phi_bb54_8, phi_bb54_9, phi_bb54_10, phi_bb54_11, phi_bb54_14, phi_bb54_15, phi_bb54_21}, &block59, std::vector<compiler::Node*>{phi_bb54_8, phi_bb54_9, phi_bb54_10, phi_bb54_11, phi_bb54_14, phi_bb54_15, phi_bb54_21});
  }

  TNode<IntPtrT> phi_bb58_8;
  TNode<IntPtrT> phi_bb58_9;
  TNode<IntPtrT> phi_bb58_10;
  TNode<IntPtrT> phi_bb58_11;
  TNode<IntPtrT> phi_bb58_14;
  TNode<BoolT> phi_bb58_15;
  TNode<IntPtrT> phi_bb58_21;
  TNode<Union<HeapObject, TaggedIndex>> tmp138;
  TNode<IntPtrT> tmp139;
  TNode<IntPtrT> tmp140;
  TNode<IntPtrT> tmp141;
  if (block58.is_used()) {
    ca_.Bind(&block58, &phi_bb58_8, &phi_bb58_9, &phi_bb58_10, &phi_bb58_11, &phi_bb58_14, &phi_bb58_15, &phi_bb58_21);
    std::tie(tmp138, tmp139) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp101}, TNode<IntPtrT>{phi_bb58_9}).Flatten();
    tmp140 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp141 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb58_9}, TNode<IntPtrT>{tmp140});
    ca_.Goto(&block57, phi_bb58_8, tmp141, phi_bb58_10, phi_bb58_11, phi_bb58_14, phi_bb58_15, phi_bb58_21, tmp138, tmp139);
  }

  TNode<IntPtrT> phi_bb59_8;
  TNode<IntPtrT> phi_bb59_9;
  TNode<IntPtrT> phi_bb59_10;
  TNode<IntPtrT> phi_bb59_11;
  TNode<IntPtrT> phi_bb59_14;
  TNode<BoolT> phi_bb59_15;
  TNode<IntPtrT> phi_bb59_21;
  if (block59.is_used()) {
    ca_.Bind(&block59, &phi_bb59_8, &phi_bb59_9, &phi_bb59_10, &phi_bb59_11, &phi_bb59_14, &phi_bb59_15, &phi_bb59_21);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block61, phi_bb59_8, phi_bb59_9, phi_bb59_10, phi_bb59_11, phi_bb59_14, phi_bb59_15, phi_bb59_21);
    } else {
      ca_.Goto(&block62, phi_bb59_8, phi_bb59_9, phi_bb59_10, phi_bb59_11, phi_bb59_14, phi_bb59_15, phi_bb59_21);
    }
  }

  TNode<IntPtrT> phi_bb61_8;
  TNode<IntPtrT> phi_bb61_9;
  TNode<IntPtrT> phi_bb61_10;
  TNode<IntPtrT> phi_bb61_11;
  TNode<IntPtrT> phi_bb61_14;
  TNode<BoolT> phi_bb61_15;
  TNode<IntPtrT> phi_bb61_21;
  TNode<Union<HeapObject, TaggedIndex>> tmp142;
  TNode<IntPtrT> tmp143;
  TNode<IntPtrT> tmp144;
  TNode<IntPtrT> tmp145;
  if (block61.is_used()) {
    ca_.Bind(&block61, &phi_bb61_8, &phi_bb61_9, &phi_bb61_10, &phi_bb61_11, &phi_bb61_14, &phi_bb61_15, &phi_bb61_21);
    std::tie(tmp142, tmp143) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp101}, TNode<IntPtrT>{phi_bb61_11}).Flatten();
    tmp144 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp145 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb61_11}, TNode<IntPtrT>{tmp144});
    ca_.Goto(&block60, phi_bb61_8, phi_bb61_9, phi_bb61_10, tmp145, phi_bb61_14, phi_bb61_15, phi_bb61_21, tmp142, tmp143);
  }

  TNode<IntPtrT> phi_bb62_8;
  TNode<IntPtrT> phi_bb62_9;
  TNode<IntPtrT> phi_bb62_10;
  TNode<IntPtrT> phi_bb62_11;
  TNode<IntPtrT> phi_bb62_14;
  TNode<BoolT> phi_bb62_15;
  TNode<IntPtrT> phi_bb62_21;
  TNode<IntPtrT> tmp146;
  TNode<BoolT> tmp147;
  if (block62.is_used()) {
    ca_.Bind(&block62, &phi_bb62_8, &phi_bb62_9, &phi_bb62_10, &phi_bb62_11, &phi_bb62_14, &phi_bb62_15, &phi_bb62_21);
    tmp146 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp147 = CodeStubAssembler(state_).WordNotEqual(TNode<IntPtrT>{phi_bb62_14}, TNode<IntPtrT>{tmp146});
    ca_.Branch(tmp147, &block64, std::vector<compiler::Node*>{phi_bb62_8, phi_bb62_9, phi_bb62_10, phi_bb62_11, phi_bb62_14, phi_bb62_15, phi_bb62_21}, &block65, std::vector<compiler::Node*>{phi_bb62_8, phi_bb62_9, phi_bb62_10, phi_bb62_11, phi_bb62_14, phi_bb62_15, phi_bb62_21});
  }

  TNode<IntPtrT> phi_bb64_8;
  TNode<IntPtrT> phi_bb64_9;
  TNode<IntPtrT> phi_bb64_10;
  TNode<IntPtrT> phi_bb64_11;
  TNode<IntPtrT> phi_bb64_14;
  TNode<BoolT> phi_bb64_15;
  TNode<IntPtrT> phi_bb64_21;
  TNode<Union<HeapObject, TaggedIndex>> tmp148;
  TNode<IntPtrT> tmp149;
  TNode<IntPtrT> tmp150;
  TNode<BoolT> tmp151;
  if (block64.is_used()) {
    ca_.Bind(&block64, &phi_bb64_8, &phi_bb64_9, &phi_bb64_10, &phi_bb64_11, &phi_bb64_14, &phi_bb64_15, &phi_bb64_21);
    std::tie(tmp148, tmp149) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp101}, TNode<IntPtrT>{phi_bb64_14}).Flatten();
    tmp150 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp151 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block60, phi_bb64_8, phi_bb64_9, phi_bb64_10, phi_bb64_11, tmp150, tmp151, phi_bb64_21, tmp148, tmp149);
  }

  TNode<IntPtrT> phi_bb65_8;
  TNode<IntPtrT> phi_bb65_9;
  TNode<IntPtrT> phi_bb65_10;
  TNode<IntPtrT> phi_bb65_11;
  TNode<IntPtrT> phi_bb65_14;
  TNode<BoolT> phi_bb65_15;
  TNode<IntPtrT> phi_bb65_21;
  TNode<Union<HeapObject, TaggedIndex>> tmp152;
  TNode<IntPtrT> tmp153;
  TNode<IntPtrT> tmp154;
  TNode<IntPtrT> tmp155;
  TNode<IntPtrT> tmp156;
  TNode<IntPtrT> tmp157;
  TNode<BoolT> tmp158;
  if (block65.is_used()) {
    ca_.Bind(&block65, &phi_bb65_8, &phi_bb65_9, &phi_bb65_10, &phi_bb65_11, &phi_bb65_14, &phi_bb65_15, &phi_bb65_21);
    std::tie(tmp152, tmp153) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp101}, TNode<IntPtrT>{phi_bb65_11}).Flatten();
    tmp154 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp155 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb65_11}, TNode<IntPtrT>{tmp154});
    tmp156 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp157 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp155}, TNode<IntPtrT>{tmp156});
    tmp158 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block60, phi_bb65_8, phi_bb65_9, phi_bb65_10, tmp157, tmp155, tmp158, phi_bb65_21, tmp152, tmp153);
  }

  TNode<IntPtrT> phi_bb60_8;
  TNode<IntPtrT> phi_bb60_9;
  TNode<IntPtrT> phi_bb60_10;
  TNode<IntPtrT> phi_bb60_11;
  TNode<IntPtrT> phi_bb60_14;
  TNode<BoolT> phi_bb60_15;
  TNode<IntPtrT> phi_bb60_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb60_23;
  TNode<IntPtrT> phi_bb60_24;
  if (block60.is_used()) {
    ca_.Bind(&block60, &phi_bb60_8, &phi_bb60_9, &phi_bb60_10, &phi_bb60_11, &phi_bb60_14, &phi_bb60_15, &phi_bb60_21, &phi_bb60_23, &phi_bb60_24);
    ca_.Goto(&block57, phi_bb60_8, phi_bb60_9, phi_bb60_10, phi_bb60_11, phi_bb60_14, phi_bb60_15, phi_bb60_21, phi_bb60_23, phi_bb60_24);
  }

  TNode<IntPtrT> phi_bb57_8;
  TNode<IntPtrT> phi_bb57_9;
  TNode<IntPtrT> phi_bb57_10;
  TNode<IntPtrT> phi_bb57_11;
  TNode<IntPtrT> phi_bb57_14;
  TNode<BoolT> phi_bb57_15;
  TNode<IntPtrT> phi_bb57_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb57_23;
  TNode<IntPtrT> phi_bb57_24;
  if (block57.is_used()) {
    ca_.Bind(&block57, &phi_bb57_8, &phi_bb57_9, &phi_bb57_10, &phi_bb57_11, &phi_bb57_14, &phi_bb57_15, &phi_bb57_21, &phi_bb57_23, &phi_bb57_24);
    ca_.Goto(&block56, tmp135, phi_bb57_8, phi_bb57_9, phi_bb57_10, phi_bb57_11, phi_bb57_14, phi_bb57_15, phi_bb57_21);
  }

  TNode<IntPtrT> phi_bb55_7;
  TNode<IntPtrT> phi_bb55_8;
  TNode<IntPtrT> phi_bb55_9;
  TNode<IntPtrT> phi_bb55_10;
  TNode<IntPtrT> phi_bb55_11;
  TNode<IntPtrT> phi_bb55_14;
  TNode<BoolT> phi_bb55_15;
  TNode<IntPtrT> phi_bb55_21;
  TNode<Int32T> tmp159;
  TNode<BoolT> tmp160;
  if (block55.is_used()) {
    ca_.Bind(&block55, &phi_bb55_7, &phi_bb55_8, &phi_bb55_9, &phi_bb55_10, &phi_bb55_11, &phi_bb55_14, &phi_bb55_15, &phi_bb55_21);
    tmp159 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmF32.raw_bit_field());
    tmp160 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp131}, TNode<Int32T>{tmp159});
    ca_.Branch(tmp160, &block66, std::vector<compiler::Node*>{phi_bb55_7, phi_bb55_8, phi_bb55_9, phi_bb55_10, phi_bb55_11, phi_bb55_14, phi_bb55_15, phi_bb55_21}, &block67, std::vector<compiler::Node*>{phi_bb55_7, phi_bb55_8, phi_bb55_9, phi_bb55_10, phi_bb55_11, phi_bb55_14, phi_bb55_15, phi_bb55_21});
  }

  TNode<IntPtrT> phi_bb66_7;
  TNode<IntPtrT> phi_bb66_8;
  TNode<IntPtrT> phi_bb66_9;
  TNode<IntPtrT> phi_bb66_10;
  TNode<IntPtrT> phi_bb66_11;
  TNode<IntPtrT> phi_bb66_14;
  TNode<BoolT> phi_bb66_15;
  TNode<IntPtrT> phi_bb66_21;
  TNode<IntPtrT> tmp161;
  TNode<IntPtrT> tmp162;
  TNode<IntPtrT> tmp163;
  TNode<BoolT> tmp164;
  if (block66.is_used()) {
    ca_.Bind(&block66, &phi_bb66_7, &phi_bb66_8, &phi_bb66_9, &phi_bb66_10, &phi_bb66_11, &phi_bb66_14, &phi_bb66_15, &phi_bb66_21);
    tmp161 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp162 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{phi_bb66_8}, TNode<IntPtrT>{tmp161});
    tmp163 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp164 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{phi_bb66_8}, TNode<IntPtrT>{tmp163});
    ca_.Branch(tmp164, &block70, std::vector<compiler::Node*>{phi_bb66_7, phi_bb66_9, phi_bb66_10, phi_bb66_11, phi_bb66_14, phi_bb66_15, phi_bb66_21}, &block71, std::vector<compiler::Node*>{phi_bb66_7, phi_bb66_9, phi_bb66_10, phi_bb66_11, phi_bb66_14, phi_bb66_15, phi_bb66_21});
  }

  TNode<IntPtrT> phi_bb70_7;
  TNode<IntPtrT> phi_bb70_9;
  TNode<IntPtrT> phi_bb70_10;
  TNode<IntPtrT> phi_bb70_11;
  TNode<IntPtrT> phi_bb70_14;
  TNode<BoolT> phi_bb70_15;
  TNode<IntPtrT> phi_bb70_21;
  TNode<Union<HeapObject, TaggedIndex>> tmp165;
  TNode<IntPtrT> tmp166;
  TNode<IntPtrT> tmp167;
  TNode<IntPtrT> tmp168;
  if (block70.is_used()) {
    ca_.Bind(&block70, &phi_bb70_7, &phi_bb70_9, &phi_bb70_10, &phi_bb70_11, &phi_bb70_14, &phi_bb70_15, &phi_bb70_21);
    std::tie(tmp165, tmp166) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp101}, TNode<IntPtrT>{phi_bb70_10}).Flatten();
    tmp167 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_float64_0(state_)));
    tmp168 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb70_10}, TNode<IntPtrT>{tmp167});
    ca_.Goto(&block69, phi_bb70_7, phi_bb70_9, tmp168, phi_bb70_11, phi_bb70_14, phi_bb70_15, phi_bb70_21, tmp165, tmp166);
  }

  TNode<IntPtrT> phi_bb71_7;
  TNode<IntPtrT> phi_bb71_9;
  TNode<IntPtrT> phi_bb71_10;
  TNode<IntPtrT> phi_bb71_11;
  TNode<IntPtrT> phi_bb71_14;
  TNode<BoolT> phi_bb71_15;
  TNode<IntPtrT> phi_bb71_21;
  if (block71.is_used()) {
    ca_.Bind(&block71, &phi_bb71_7, &phi_bb71_9, &phi_bb71_10, &phi_bb71_11, &phi_bb71_14, &phi_bb71_15, &phi_bb71_21);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block73, phi_bb71_7, phi_bb71_9, phi_bb71_10, phi_bb71_11, phi_bb71_14, phi_bb71_15, phi_bb71_21);
    } else {
      ca_.Goto(&block74, phi_bb71_7, phi_bb71_9, phi_bb71_10, phi_bb71_11, phi_bb71_14, phi_bb71_15, phi_bb71_21);
    }
  }

  TNode<IntPtrT> phi_bb73_7;
  TNode<IntPtrT> phi_bb73_9;
  TNode<IntPtrT> phi_bb73_10;
  TNode<IntPtrT> phi_bb73_11;
  TNode<IntPtrT> phi_bb73_14;
  TNode<BoolT> phi_bb73_15;
  TNode<IntPtrT> phi_bb73_21;
  TNode<Union<HeapObject, TaggedIndex>> tmp169;
  TNode<IntPtrT> tmp170;
  TNode<IntPtrT> tmp171;
  TNode<IntPtrT> tmp172;
  if (block73.is_used()) {
    ca_.Bind(&block73, &phi_bb73_7, &phi_bb73_9, &phi_bb73_10, &phi_bb73_11, &phi_bb73_14, &phi_bb73_15, &phi_bb73_21);
    std::tie(tmp169, tmp170) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp101}, TNode<IntPtrT>{phi_bb73_11}).Flatten();
    tmp171 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp172 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb73_11}, TNode<IntPtrT>{tmp171});
    ca_.Goto(&block72, phi_bb73_7, phi_bb73_9, phi_bb73_10, tmp172, phi_bb73_14, phi_bb73_15, phi_bb73_21, tmp169, tmp170);
  }

  TNode<IntPtrT> phi_bb74_7;
  TNode<IntPtrT> phi_bb74_9;
  TNode<IntPtrT> phi_bb74_10;
  TNode<IntPtrT> phi_bb74_11;
  TNode<IntPtrT> phi_bb74_14;
  TNode<BoolT> phi_bb74_15;
  TNode<IntPtrT> phi_bb74_21;
  TNode<IntPtrT> tmp173;
  TNode<BoolT> tmp174;
  if (block74.is_used()) {
    ca_.Bind(&block74, &phi_bb74_7, &phi_bb74_9, &phi_bb74_10, &phi_bb74_11, &phi_bb74_14, &phi_bb74_15, &phi_bb74_21);
    tmp173 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp174 = CodeStubAssembler(state_).WordNotEqual(TNode<IntPtrT>{phi_bb74_14}, TNode<IntPtrT>{tmp173});
    ca_.Branch(tmp174, &block76, std::vector<compiler::Node*>{phi_bb74_7, phi_bb74_9, phi_bb74_10, phi_bb74_11, phi_bb74_14, phi_bb74_15, phi_bb74_21}, &block77, std::vector<compiler::Node*>{phi_bb74_7, phi_bb74_9, phi_bb74_10, phi_bb74_11, phi_bb74_14, phi_bb74_15, phi_bb74_21});
  }

  TNode<IntPtrT> phi_bb76_7;
  TNode<IntPtrT> phi_bb76_9;
  TNode<IntPtrT> phi_bb76_10;
  TNode<IntPtrT> phi_bb76_11;
  TNode<IntPtrT> phi_bb76_14;
  TNode<BoolT> phi_bb76_15;
  TNode<IntPtrT> phi_bb76_21;
  TNode<Union<HeapObject, TaggedIndex>> tmp175;
  TNode<IntPtrT> tmp176;
  TNode<IntPtrT> tmp177;
  TNode<BoolT> tmp178;
  if (block76.is_used()) {
    ca_.Bind(&block76, &phi_bb76_7, &phi_bb76_9, &phi_bb76_10, &phi_bb76_11, &phi_bb76_14, &phi_bb76_15, &phi_bb76_21);
    std::tie(tmp175, tmp176) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp101}, TNode<IntPtrT>{phi_bb76_14}).Flatten();
    tmp177 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp178 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block72, phi_bb76_7, phi_bb76_9, phi_bb76_10, phi_bb76_11, tmp177, tmp178, phi_bb76_21, tmp175, tmp176);
  }

  TNode<IntPtrT> phi_bb77_7;
  TNode<IntPtrT> phi_bb77_9;
  TNode<IntPtrT> phi_bb77_10;
  TNode<IntPtrT> phi_bb77_11;
  TNode<IntPtrT> phi_bb77_14;
  TNode<BoolT> phi_bb77_15;
  TNode<IntPtrT> phi_bb77_21;
  TNode<Union<HeapObject, TaggedIndex>> tmp179;
  TNode<IntPtrT> tmp180;
  TNode<IntPtrT> tmp181;
  TNode<IntPtrT> tmp182;
  TNode<IntPtrT> tmp183;
  TNode<IntPtrT> tmp184;
  TNode<BoolT> tmp185;
  if (block77.is_used()) {
    ca_.Bind(&block77, &phi_bb77_7, &phi_bb77_9, &phi_bb77_10, &phi_bb77_11, &phi_bb77_14, &phi_bb77_15, &phi_bb77_21);
    std::tie(tmp179, tmp180) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp101}, TNode<IntPtrT>{phi_bb77_11}).Flatten();
    tmp181 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp182 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb77_11}, TNode<IntPtrT>{tmp181});
    tmp183 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp184 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp182}, TNode<IntPtrT>{tmp183});
    tmp185 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block72, phi_bb77_7, phi_bb77_9, phi_bb77_10, tmp184, tmp182, tmp185, phi_bb77_21, tmp179, tmp180);
  }

  TNode<IntPtrT> phi_bb72_7;
  TNode<IntPtrT> phi_bb72_9;
  TNode<IntPtrT> phi_bb72_10;
  TNode<IntPtrT> phi_bb72_11;
  TNode<IntPtrT> phi_bb72_14;
  TNode<BoolT> phi_bb72_15;
  TNode<IntPtrT> phi_bb72_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb72_23;
  TNode<IntPtrT> phi_bb72_24;
  if (block72.is_used()) {
    ca_.Bind(&block72, &phi_bb72_7, &phi_bb72_9, &phi_bb72_10, &phi_bb72_11, &phi_bb72_14, &phi_bb72_15, &phi_bb72_21, &phi_bb72_23, &phi_bb72_24);
    ca_.Goto(&block69, phi_bb72_7, phi_bb72_9, phi_bb72_10, phi_bb72_11, phi_bb72_14, phi_bb72_15, phi_bb72_21, phi_bb72_23, phi_bb72_24);
  }

  TNode<IntPtrT> phi_bb69_7;
  TNode<IntPtrT> phi_bb69_9;
  TNode<IntPtrT> phi_bb69_10;
  TNode<IntPtrT> phi_bb69_11;
  TNode<IntPtrT> phi_bb69_14;
  TNode<BoolT> phi_bb69_15;
  TNode<IntPtrT> phi_bb69_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb69_23;
  TNode<IntPtrT> phi_bb69_24;
  if (block69.is_used()) {
    ca_.Bind(&block69, &phi_bb69_7, &phi_bb69_9, &phi_bb69_10, &phi_bb69_11, &phi_bb69_14, &phi_bb69_15, &phi_bb69_21, &phi_bb69_23, &phi_bb69_24);
    ca_.Goto(&block68, phi_bb69_7, tmp162, phi_bb69_9, phi_bb69_10, phi_bb69_11, phi_bb69_14, phi_bb69_15, phi_bb69_21);
  }

  TNode<IntPtrT> phi_bb67_7;
  TNode<IntPtrT> phi_bb67_8;
  TNode<IntPtrT> phi_bb67_9;
  TNode<IntPtrT> phi_bb67_10;
  TNode<IntPtrT> phi_bb67_11;
  TNode<IntPtrT> phi_bb67_14;
  TNode<BoolT> phi_bb67_15;
  TNode<IntPtrT> phi_bb67_21;
  TNode<Int32T> tmp186;
  TNode<BoolT> tmp187;
  if (block67.is_used()) {
    ca_.Bind(&block67, &phi_bb67_7, &phi_bb67_8, &phi_bb67_9, &phi_bb67_10, &phi_bb67_11, &phi_bb67_14, &phi_bb67_15, &phi_bb67_21);
    tmp186 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmI64.raw_bit_field());
    tmp187 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp131}, TNode<Int32T>{tmp186});
    ca_.Branch(tmp187, &block78, std::vector<compiler::Node*>{phi_bb67_7, phi_bb67_8, phi_bb67_9, phi_bb67_10, phi_bb67_11, phi_bb67_14, phi_bb67_15, phi_bb67_21}, &block79, std::vector<compiler::Node*>{phi_bb67_7, phi_bb67_8, phi_bb67_9, phi_bb67_10, phi_bb67_11, phi_bb67_14, phi_bb67_15, phi_bb67_21});
  }

  TNode<IntPtrT> phi_bb78_7;
  TNode<IntPtrT> phi_bb78_8;
  TNode<IntPtrT> phi_bb78_9;
  TNode<IntPtrT> phi_bb78_10;
  TNode<IntPtrT> phi_bb78_11;
  TNode<IntPtrT> phi_bb78_14;
  TNode<BoolT> phi_bb78_15;
  TNode<IntPtrT> phi_bb78_21;
  TNode<IntPtrT> tmp188;
  TNode<IntPtrT> tmp189;
  TNode<IntPtrT> tmp190;
  TNode<BoolT> tmp191;
  if (block78.is_used()) {
    ca_.Bind(&block78, &phi_bb78_7, &phi_bb78_8, &phi_bb78_9, &phi_bb78_10, &phi_bb78_11, &phi_bb78_14, &phi_bb78_15, &phi_bb78_21);
    tmp188 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp189 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{phi_bb78_7}, TNode<IntPtrT>{tmp188});
    tmp190 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp191 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{phi_bb78_7}, TNode<IntPtrT>{tmp190});
    ca_.Branch(tmp191, &block82, std::vector<compiler::Node*>{phi_bb78_8, phi_bb78_9, phi_bb78_10, phi_bb78_11, phi_bb78_14, phi_bb78_15, phi_bb78_21}, &block83, std::vector<compiler::Node*>{phi_bb78_8, phi_bb78_9, phi_bb78_10, phi_bb78_11, phi_bb78_14, phi_bb78_15, phi_bb78_21});
  }

  TNode<IntPtrT> phi_bb82_8;
  TNode<IntPtrT> phi_bb82_9;
  TNode<IntPtrT> phi_bb82_10;
  TNode<IntPtrT> phi_bb82_11;
  TNode<IntPtrT> phi_bb82_14;
  TNode<BoolT> phi_bb82_15;
  TNode<IntPtrT> phi_bb82_21;
  TNode<Union<HeapObject, TaggedIndex>> tmp192;
  TNode<IntPtrT> tmp193;
  TNode<IntPtrT> tmp194;
  TNode<IntPtrT> tmp195;
  if (block82.is_used()) {
    ca_.Bind(&block82, &phi_bb82_8, &phi_bb82_9, &phi_bb82_10, &phi_bb82_11, &phi_bb82_14, &phi_bb82_15, &phi_bb82_21);
    std::tie(tmp192, tmp193) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp101}, TNode<IntPtrT>{phi_bb82_9}).Flatten();
    tmp194 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp195 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb82_9}, TNode<IntPtrT>{tmp194});
    ca_.Goto(&block81, phi_bb82_8, tmp195, phi_bb82_10, phi_bb82_11, phi_bb82_14, phi_bb82_15, phi_bb82_21, tmp192, tmp193);
  }

  TNode<IntPtrT> phi_bb83_8;
  TNode<IntPtrT> phi_bb83_9;
  TNode<IntPtrT> phi_bb83_10;
  TNode<IntPtrT> phi_bb83_11;
  TNode<IntPtrT> phi_bb83_14;
  TNode<BoolT> phi_bb83_15;
  TNode<IntPtrT> phi_bb83_21;
  if (block83.is_used()) {
    ca_.Bind(&block83, &phi_bb83_8, &phi_bb83_9, &phi_bb83_10, &phi_bb83_11, &phi_bb83_14, &phi_bb83_15, &phi_bb83_21);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block85, phi_bb83_8, phi_bb83_9, phi_bb83_10, phi_bb83_11, phi_bb83_14, phi_bb83_15, phi_bb83_21);
    } else {
      ca_.Goto(&block86, phi_bb83_8, phi_bb83_9, phi_bb83_10, phi_bb83_11, phi_bb83_14, phi_bb83_15, phi_bb83_21);
    }
  }

  TNode<IntPtrT> phi_bb85_8;
  TNode<IntPtrT> phi_bb85_9;
  TNode<IntPtrT> phi_bb85_10;
  TNode<IntPtrT> phi_bb85_11;
  TNode<IntPtrT> phi_bb85_14;
  TNode<BoolT> phi_bb85_15;
  TNode<IntPtrT> phi_bb85_21;
  TNode<Union<HeapObject, TaggedIndex>> tmp196;
  TNode<IntPtrT> tmp197;
  TNode<IntPtrT> tmp198;
  TNode<IntPtrT> tmp199;
  if (block85.is_used()) {
    ca_.Bind(&block85, &phi_bb85_8, &phi_bb85_9, &phi_bb85_10, &phi_bb85_11, &phi_bb85_14, &phi_bb85_15, &phi_bb85_21);
    std::tie(tmp196, tmp197) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp101}, TNode<IntPtrT>{phi_bb85_11}).Flatten();
    tmp198 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp199 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb85_11}, TNode<IntPtrT>{tmp198});
    ca_.Goto(&block84, phi_bb85_8, phi_bb85_9, phi_bb85_10, tmp199, phi_bb85_14, phi_bb85_15, phi_bb85_21, tmp196, tmp197);
  }

  TNode<IntPtrT> phi_bb86_8;
  TNode<IntPtrT> phi_bb86_9;
  TNode<IntPtrT> phi_bb86_10;
  TNode<IntPtrT> phi_bb86_11;
  TNode<IntPtrT> phi_bb86_14;
  TNode<BoolT> phi_bb86_15;
  TNode<IntPtrT> phi_bb86_21;
  TNode<IntPtrT> tmp200;
  TNode<BoolT> tmp201;
  if (block86.is_used()) {
    ca_.Bind(&block86, &phi_bb86_8, &phi_bb86_9, &phi_bb86_10, &phi_bb86_11, &phi_bb86_14, &phi_bb86_15, &phi_bb86_21);
    tmp200 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp201 = CodeStubAssembler(state_).WordNotEqual(TNode<IntPtrT>{phi_bb86_14}, TNode<IntPtrT>{tmp200});
    ca_.Branch(tmp201, &block88, std::vector<compiler::Node*>{phi_bb86_8, phi_bb86_9, phi_bb86_10, phi_bb86_11, phi_bb86_14, phi_bb86_15, phi_bb86_21}, &block89, std::vector<compiler::Node*>{phi_bb86_8, phi_bb86_9, phi_bb86_10, phi_bb86_11, phi_bb86_14, phi_bb86_15, phi_bb86_21});
  }

  TNode<IntPtrT> phi_bb88_8;
  TNode<IntPtrT> phi_bb88_9;
  TNode<IntPtrT> phi_bb88_10;
  TNode<IntPtrT> phi_bb88_11;
  TNode<IntPtrT> phi_bb88_14;
  TNode<BoolT> phi_bb88_15;
  TNode<IntPtrT> phi_bb88_21;
  TNode<Union<HeapObject, TaggedIndex>> tmp202;
  TNode<IntPtrT> tmp203;
  TNode<IntPtrT> tmp204;
  TNode<BoolT> tmp205;
  if (block88.is_used()) {
    ca_.Bind(&block88, &phi_bb88_8, &phi_bb88_9, &phi_bb88_10, &phi_bb88_11, &phi_bb88_14, &phi_bb88_15, &phi_bb88_21);
    std::tie(tmp202, tmp203) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp101}, TNode<IntPtrT>{phi_bb88_14}).Flatten();
    tmp204 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp205 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block84, phi_bb88_8, phi_bb88_9, phi_bb88_10, phi_bb88_11, tmp204, tmp205, phi_bb88_21, tmp202, tmp203);
  }

  TNode<IntPtrT> phi_bb89_8;
  TNode<IntPtrT> phi_bb89_9;
  TNode<IntPtrT> phi_bb89_10;
  TNode<IntPtrT> phi_bb89_11;
  TNode<IntPtrT> phi_bb89_14;
  TNode<BoolT> phi_bb89_15;
  TNode<IntPtrT> phi_bb89_21;
  TNode<Union<HeapObject, TaggedIndex>> tmp206;
  TNode<IntPtrT> tmp207;
  TNode<IntPtrT> tmp208;
  TNode<IntPtrT> tmp209;
  TNode<IntPtrT> tmp210;
  TNode<IntPtrT> tmp211;
  TNode<BoolT> tmp212;
  if (block89.is_used()) {
    ca_.Bind(&block89, &phi_bb89_8, &phi_bb89_9, &phi_bb89_10, &phi_bb89_11, &phi_bb89_14, &phi_bb89_15, &phi_bb89_21);
    std::tie(tmp206, tmp207) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp101}, TNode<IntPtrT>{phi_bb89_11}).Flatten();
    tmp208 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp209 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb89_11}, TNode<IntPtrT>{tmp208});
    tmp210 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp211 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp209}, TNode<IntPtrT>{tmp210});
    tmp212 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block84, phi_bb89_8, phi_bb89_9, phi_bb89_10, tmp211, tmp209, tmp212, phi_bb89_21, tmp206, tmp207);
  }

  TNode<IntPtrT> phi_bb84_8;
  TNode<IntPtrT> phi_bb84_9;
  TNode<IntPtrT> phi_bb84_10;
  TNode<IntPtrT> phi_bb84_11;
  TNode<IntPtrT> phi_bb84_14;
  TNode<BoolT> phi_bb84_15;
  TNode<IntPtrT> phi_bb84_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb84_23;
  TNode<IntPtrT> phi_bb84_24;
  if (block84.is_used()) {
    ca_.Bind(&block84, &phi_bb84_8, &phi_bb84_9, &phi_bb84_10, &phi_bb84_11, &phi_bb84_14, &phi_bb84_15, &phi_bb84_21, &phi_bb84_23, &phi_bb84_24);
    ca_.Goto(&block81, phi_bb84_8, phi_bb84_9, phi_bb84_10, phi_bb84_11, phi_bb84_14, phi_bb84_15, phi_bb84_21, phi_bb84_23, phi_bb84_24);
  }

  TNode<IntPtrT> phi_bb81_8;
  TNode<IntPtrT> phi_bb81_9;
  TNode<IntPtrT> phi_bb81_10;
  TNode<IntPtrT> phi_bb81_11;
  TNode<IntPtrT> phi_bb81_14;
  TNode<BoolT> phi_bb81_15;
  TNode<IntPtrT> phi_bb81_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb81_23;
  TNode<IntPtrT> phi_bb81_24;
  if (block81.is_used()) {
    ca_.Bind(&block81, &phi_bb81_8, &phi_bb81_9, &phi_bb81_10, &phi_bb81_11, &phi_bb81_14, &phi_bb81_15, &phi_bb81_21, &phi_bb81_23, &phi_bb81_24);
    if (((CodeStubAssembler(state_).ConstexprBoolNot((CodeStubAssembler(state_).Is64()))))) {
      ca_.Goto(&block90, phi_bb81_8, phi_bb81_9, phi_bb81_10, phi_bb81_11, phi_bb81_14, phi_bb81_15, phi_bb81_21);
    } else {
      ca_.Goto(&block91, phi_bb81_8, phi_bb81_9, phi_bb81_10, phi_bb81_11, phi_bb81_14, phi_bb81_15, phi_bb81_21);
    }
  }

  TNode<IntPtrT> phi_bb90_8;
  TNode<IntPtrT> phi_bb90_9;
  TNode<IntPtrT> phi_bb90_10;
  TNode<IntPtrT> phi_bb90_11;
  TNode<IntPtrT> phi_bb90_14;
  TNode<BoolT> phi_bb90_15;
  TNode<IntPtrT> phi_bb90_21;
  TNode<IntPtrT> tmp213;
  TNode<IntPtrT> tmp214;
  TNode<IntPtrT> tmp215;
  TNode<BoolT> tmp216;
  if (block90.is_used()) {
    ca_.Bind(&block90, &phi_bb90_8, &phi_bb90_9, &phi_bb90_10, &phi_bb90_11, &phi_bb90_14, &phi_bb90_15, &phi_bb90_21);
    tmp213 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp214 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{tmp189}, TNode<IntPtrT>{tmp213});
    tmp215 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp216 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp189}, TNode<IntPtrT>{tmp215});
    ca_.Branch(tmp216, &block94, std::vector<compiler::Node*>{phi_bb90_8, phi_bb90_9, phi_bb90_10, phi_bb90_11, phi_bb90_14, phi_bb90_15, phi_bb90_21}, &block95, std::vector<compiler::Node*>{phi_bb90_8, phi_bb90_9, phi_bb90_10, phi_bb90_11, phi_bb90_14, phi_bb90_15, phi_bb90_21});
  }

  TNode<IntPtrT> phi_bb94_8;
  TNode<IntPtrT> phi_bb94_9;
  TNode<IntPtrT> phi_bb94_10;
  TNode<IntPtrT> phi_bb94_11;
  TNode<IntPtrT> phi_bb94_14;
  TNode<BoolT> phi_bb94_15;
  TNode<IntPtrT> phi_bb94_21;
  TNode<Union<HeapObject, TaggedIndex>> tmp217;
  TNode<IntPtrT> tmp218;
  TNode<IntPtrT> tmp219;
  TNode<IntPtrT> tmp220;
  if (block94.is_used()) {
    ca_.Bind(&block94, &phi_bb94_8, &phi_bb94_9, &phi_bb94_10, &phi_bb94_11, &phi_bb94_14, &phi_bb94_15, &phi_bb94_21);
    std::tie(tmp217, tmp218) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp101}, TNode<IntPtrT>{phi_bb94_9}).Flatten();
    tmp219 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp220 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb94_9}, TNode<IntPtrT>{tmp219});
    ca_.Goto(&block93, phi_bb94_8, tmp220, phi_bb94_10, phi_bb94_11, phi_bb94_14, phi_bb94_15, phi_bb94_21, tmp217, tmp218);
  }

  TNode<IntPtrT> phi_bb95_8;
  TNode<IntPtrT> phi_bb95_9;
  TNode<IntPtrT> phi_bb95_10;
  TNode<IntPtrT> phi_bb95_11;
  TNode<IntPtrT> phi_bb95_14;
  TNode<BoolT> phi_bb95_15;
  TNode<IntPtrT> phi_bb95_21;
  if (block95.is_used()) {
    ca_.Bind(&block95, &phi_bb95_8, &phi_bb95_9, &phi_bb95_10, &phi_bb95_11, &phi_bb95_14, &phi_bb95_15, &phi_bb95_21);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block97, phi_bb95_8, phi_bb95_9, phi_bb95_10, phi_bb95_11, phi_bb95_14, phi_bb95_15, phi_bb95_21);
    } else {
      ca_.Goto(&block98, phi_bb95_8, phi_bb95_9, phi_bb95_10, phi_bb95_11, phi_bb95_14, phi_bb95_15, phi_bb95_21);
    }
  }

  TNode<IntPtrT> phi_bb97_8;
  TNode<IntPtrT> phi_bb97_9;
  TNode<IntPtrT> phi_bb97_10;
  TNode<IntPtrT> phi_bb97_11;
  TNode<IntPtrT> phi_bb97_14;
  TNode<BoolT> phi_bb97_15;
  TNode<IntPtrT> phi_bb97_21;
  TNode<Union<HeapObject, TaggedIndex>> tmp221;
  TNode<IntPtrT> tmp222;
  TNode<IntPtrT> tmp223;
  TNode<IntPtrT> tmp224;
  if (block97.is_used()) {
    ca_.Bind(&block97, &phi_bb97_8, &phi_bb97_9, &phi_bb97_10, &phi_bb97_11, &phi_bb97_14, &phi_bb97_15, &phi_bb97_21);
    std::tie(tmp221, tmp222) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp101}, TNode<IntPtrT>{phi_bb97_11}).Flatten();
    tmp223 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp224 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb97_11}, TNode<IntPtrT>{tmp223});
    ca_.Goto(&block96, phi_bb97_8, phi_bb97_9, phi_bb97_10, tmp224, phi_bb97_14, phi_bb97_15, phi_bb97_21, tmp221, tmp222);
  }

  TNode<IntPtrT> phi_bb98_8;
  TNode<IntPtrT> phi_bb98_9;
  TNode<IntPtrT> phi_bb98_10;
  TNode<IntPtrT> phi_bb98_11;
  TNode<IntPtrT> phi_bb98_14;
  TNode<BoolT> phi_bb98_15;
  TNode<IntPtrT> phi_bb98_21;
  TNode<IntPtrT> tmp225;
  TNode<BoolT> tmp226;
  if (block98.is_used()) {
    ca_.Bind(&block98, &phi_bb98_8, &phi_bb98_9, &phi_bb98_10, &phi_bb98_11, &phi_bb98_14, &phi_bb98_15, &phi_bb98_21);
    tmp225 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp226 = CodeStubAssembler(state_).WordNotEqual(TNode<IntPtrT>{phi_bb98_14}, TNode<IntPtrT>{tmp225});
    ca_.Branch(tmp226, &block100, std::vector<compiler::Node*>{phi_bb98_8, phi_bb98_9, phi_bb98_10, phi_bb98_11, phi_bb98_14, phi_bb98_15, phi_bb98_21}, &block101, std::vector<compiler::Node*>{phi_bb98_8, phi_bb98_9, phi_bb98_10, phi_bb98_11, phi_bb98_14, phi_bb98_15, phi_bb98_21});
  }

  TNode<IntPtrT> phi_bb100_8;
  TNode<IntPtrT> phi_bb100_9;
  TNode<IntPtrT> phi_bb100_10;
  TNode<IntPtrT> phi_bb100_11;
  TNode<IntPtrT> phi_bb100_14;
  TNode<BoolT> phi_bb100_15;
  TNode<IntPtrT> phi_bb100_21;
  TNode<Union<HeapObject, TaggedIndex>> tmp227;
  TNode<IntPtrT> tmp228;
  TNode<IntPtrT> tmp229;
  TNode<BoolT> tmp230;
  if (block100.is_used()) {
    ca_.Bind(&block100, &phi_bb100_8, &phi_bb100_9, &phi_bb100_10, &phi_bb100_11, &phi_bb100_14, &phi_bb100_15, &phi_bb100_21);
    std::tie(tmp227, tmp228) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp101}, TNode<IntPtrT>{phi_bb100_14}).Flatten();
    tmp229 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp230 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block96, phi_bb100_8, phi_bb100_9, phi_bb100_10, phi_bb100_11, tmp229, tmp230, phi_bb100_21, tmp227, tmp228);
  }

  TNode<IntPtrT> phi_bb101_8;
  TNode<IntPtrT> phi_bb101_9;
  TNode<IntPtrT> phi_bb101_10;
  TNode<IntPtrT> phi_bb101_11;
  TNode<IntPtrT> phi_bb101_14;
  TNode<BoolT> phi_bb101_15;
  TNode<IntPtrT> phi_bb101_21;
  TNode<Union<HeapObject, TaggedIndex>> tmp231;
  TNode<IntPtrT> tmp232;
  TNode<IntPtrT> tmp233;
  TNode<IntPtrT> tmp234;
  TNode<IntPtrT> tmp235;
  TNode<IntPtrT> tmp236;
  TNode<BoolT> tmp237;
  if (block101.is_used()) {
    ca_.Bind(&block101, &phi_bb101_8, &phi_bb101_9, &phi_bb101_10, &phi_bb101_11, &phi_bb101_14, &phi_bb101_15, &phi_bb101_21);
    std::tie(tmp231, tmp232) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp101}, TNode<IntPtrT>{phi_bb101_11}).Flatten();
    tmp233 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp234 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb101_11}, TNode<IntPtrT>{tmp233});
    tmp235 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp236 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp234}, TNode<IntPtrT>{tmp235});
    tmp237 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block96, phi_bb101_8, phi_bb101_9, phi_bb101_10, tmp236, tmp234, tmp237, phi_bb101_21, tmp231, tmp232);
  }

  TNode<IntPtrT> phi_bb96_8;
  TNode<IntPtrT> phi_bb96_9;
  TNode<IntPtrT> phi_bb96_10;
  TNode<IntPtrT> phi_bb96_11;
  TNode<IntPtrT> phi_bb96_14;
  TNode<BoolT> phi_bb96_15;
  TNode<IntPtrT> phi_bb96_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb96_23;
  TNode<IntPtrT> phi_bb96_24;
  if (block96.is_used()) {
    ca_.Bind(&block96, &phi_bb96_8, &phi_bb96_9, &phi_bb96_10, &phi_bb96_11, &phi_bb96_14, &phi_bb96_15, &phi_bb96_21, &phi_bb96_23, &phi_bb96_24);
    ca_.Goto(&block93, phi_bb96_8, phi_bb96_9, phi_bb96_10, phi_bb96_11, phi_bb96_14, phi_bb96_15, phi_bb96_21, phi_bb96_23, phi_bb96_24);
  }

  TNode<IntPtrT> phi_bb93_8;
  TNode<IntPtrT> phi_bb93_9;
  TNode<IntPtrT> phi_bb93_10;
  TNode<IntPtrT> phi_bb93_11;
  TNode<IntPtrT> phi_bb93_14;
  TNode<BoolT> phi_bb93_15;
  TNode<IntPtrT> phi_bb93_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb93_23;
  TNode<IntPtrT> phi_bb93_24;
  if (block93.is_used()) {
    ca_.Bind(&block93, &phi_bb93_8, &phi_bb93_9, &phi_bb93_10, &phi_bb93_11, &phi_bb93_14, &phi_bb93_15, &phi_bb93_21, &phi_bb93_23, &phi_bb93_24);
    ca_.Goto(&block92, tmp214, phi_bb93_8, phi_bb93_9, phi_bb93_10, phi_bb93_11, phi_bb93_14, phi_bb93_15, phi_bb93_21);
  }

  TNode<IntPtrT> phi_bb91_8;
  TNode<IntPtrT> phi_bb91_9;
  TNode<IntPtrT> phi_bb91_10;
  TNode<IntPtrT> phi_bb91_11;
  TNode<IntPtrT> phi_bb91_14;
  TNode<BoolT> phi_bb91_15;
  TNode<IntPtrT> phi_bb91_21;
  if (block91.is_used()) {
    ca_.Bind(&block91, &phi_bb91_8, &phi_bb91_9, &phi_bb91_10, &phi_bb91_11, &phi_bb91_14, &phi_bb91_15, &phi_bb91_21);
    ca_.Goto(&block92, tmp189, phi_bb91_8, phi_bb91_9, phi_bb91_10, phi_bb91_11, phi_bb91_14, phi_bb91_15, phi_bb91_21);
  }

  TNode<IntPtrT> phi_bb92_7;
  TNode<IntPtrT> phi_bb92_8;
  TNode<IntPtrT> phi_bb92_9;
  TNode<IntPtrT> phi_bb92_10;
  TNode<IntPtrT> phi_bb92_11;
  TNode<IntPtrT> phi_bb92_14;
  TNode<BoolT> phi_bb92_15;
  TNode<IntPtrT> phi_bb92_21;
  if (block92.is_used()) {
    ca_.Bind(&block92, &phi_bb92_7, &phi_bb92_8, &phi_bb92_9, &phi_bb92_10, &phi_bb92_11, &phi_bb92_14, &phi_bb92_15, &phi_bb92_21);
    ca_.Goto(&block80, phi_bb92_7, phi_bb92_8, phi_bb92_9, phi_bb92_10, phi_bb92_11, phi_bb92_14, phi_bb92_15, phi_bb92_21);
  }

  TNode<IntPtrT> phi_bb79_7;
  TNode<IntPtrT> phi_bb79_8;
  TNode<IntPtrT> phi_bb79_9;
  TNode<IntPtrT> phi_bb79_10;
  TNode<IntPtrT> phi_bb79_11;
  TNode<IntPtrT> phi_bb79_14;
  TNode<BoolT> phi_bb79_15;
  TNode<IntPtrT> phi_bb79_21;
  TNode<Int32T> tmp238;
  TNode<BoolT> tmp239;
  if (block79.is_used()) {
    ca_.Bind(&block79, &phi_bb79_7, &phi_bb79_8, &phi_bb79_9, &phi_bb79_10, &phi_bb79_11, &phi_bb79_14, &phi_bb79_15, &phi_bb79_21);
    tmp238 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmF64.raw_bit_field());
    tmp239 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp131}, TNode<Int32T>{tmp238});
    ca_.Branch(tmp239, &block102, std::vector<compiler::Node*>{phi_bb79_7, phi_bb79_8, phi_bb79_9, phi_bb79_10, phi_bb79_11, phi_bb79_14, phi_bb79_15, phi_bb79_21}, &block103, std::vector<compiler::Node*>{phi_bb79_7, phi_bb79_8, phi_bb79_9, phi_bb79_10, phi_bb79_11, phi_bb79_14, phi_bb79_15, phi_bb79_21});
  }

  TNode<IntPtrT> phi_bb102_7;
  TNode<IntPtrT> phi_bb102_8;
  TNode<IntPtrT> phi_bb102_9;
  TNode<IntPtrT> phi_bb102_10;
  TNode<IntPtrT> phi_bb102_11;
  TNode<IntPtrT> phi_bb102_14;
  TNode<BoolT> phi_bb102_15;
  TNode<IntPtrT> phi_bb102_21;
  TNode<IntPtrT> tmp240;
  TNode<IntPtrT> tmp241;
  TNode<IntPtrT> tmp242;
  TNode<BoolT> tmp243;
  if (block102.is_used()) {
    ca_.Bind(&block102, &phi_bb102_7, &phi_bb102_8, &phi_bb102_9, &phi_bb102_10, &phi_bb102_11, &phi_bb102_14, &phi_bb102_15, &phi_bb102_21);
    tmp240 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp241 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{phi_bb102_8}, TNode<IntPtrT>{tmp240});
    tmp242 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp243 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{phi_bb102_8}, TNode<IntPtrT>{tmp242});
    ca_.Branch(tmp243, &block105, std::vector<compiler::Node*>{phi_bb102_7, phi_bb102_9, phi_bb102_10, phi_bb102_11, phi_bb102_14, phi_bb102_15, phi_bb102_21}, &block106, std::vector<compiler::Node*>{phi_bb102_7, phi_bb102_9, phi_bb102_10, phi_bb102_11, phi_bb102_14, phi_bb102_15, phi_bb102_21});
  }

  TNode<IntPtrT> phi_bb105_7;
  TNode<IntPtrT> phi_bb105_9;
  TNode<IntPtrT> phi_bb105_10;
  TNode<IntPtrT> phi_bb105_11;
  TNode<IntPtrT> phi_bb105_14;
  TNode<BoolT> phi_bb105_15;
  TNode<IntPtrT> phi_bb105_21;
  TNode<Union<HeapObject, TaggedIndex>> tmp244;
  TNode<IntPtrT> tmp245;
  TNode<IntPtrT> tmp246;
  TNode<IntPtrT> tmp247;
  if (block105.is_used()) {
    ca_.Bind(&block105, &phi_bb105_7, &phi_bb105_9, &phi_bb105_10, &phi_bb105_11, &phi_bb105_14, &phi_bb105_15, &phi_bb105_21);
    std::tie(tmp244, tmp245) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp101}, TNode<IntPtrT>{phi_bb105_10}).Flatten();
    tmp246 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_float64_0(state_)));
    tmp247 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb105_10}, TNode<IntPtrT>{tmp246});
    ca_.Goto(&block104, phi_bb105_7, phi_bb105_9, tmp247, phi_bb105_11, phi_bb105_14, phi_bb105_15, phi_bb105_21, tmp244, tmp245);
  }

  TNode<IntPtrT> phi_bb106_7;
  TNode<IntPtrT> phi_bb106_9;
  TNode<IntPtrT> phi_bb106_10;
  TNode<IntPtrT> phi_bb106_11;
  TNode<IntPtrT> phi_bb106_14;
  TNode<BoolT> phi_bb106_15;
  TNode<IntPtrT> phi_bb106_21;
  if (block106.is_used()) {
    ca_.Bind(&block106, &phi_bb106_7, &phi_bb106_9, &phi_bb106_10, &phi_bb106_11, &phi_bb106_14, &phi_bb106_15, &phi_bb106_21);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block107, phi_bb106_7, phi_bb106_9, phi_bb106_10, phi_bb106_11, phi_bb106_14, phi_bb106_15, phi_bb106_21);
    } else {
      ca_.Goto(&block108, phi_bb106_7, phi_bb106_9, phi_bb106_10, phi_bb106_11, phi_bb106_14, phi_bb106_15, phi_bb106_21);
    }
  }

  TNode<IntPtrT> phi_bb107_7;
  TNode<IntPtrT> phi_bb107_9;
  TNode<IntPtrT> phi_bb107_10;
  TNode<IntPtrT> phi_bb107_11;
  TNode<IntPtrT> phi_bb107_14;
  TNode<BoolT> phi_bb107_15;
  TNode<IntPtrT> phi_bb107_21;
  if (block107.is_used()) {
    ca_.Bind(&block107, &phi_bb107_7, &phi_bb107_9, &phi_bb107_10, &phi_bb107_11, &phi_bb107_14, &phi_bb107_15, &phi_bb107_21);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block111, phi_bb107_7, phi_bb107_9, phi_bb107_10, phi_bb107_11, phi_bb107_14, phi_bb107_15, phi_bb107_21);
    } else {
      ca_.Goto(&block112, phi_bb107_7, phi_bb107_9, phi_bb107_10, phi_bb107_11, phi_bb107_14, phi_bb107_15, phi_bb107_21);
    }
  }

  TNode<IntPtrT> phi_bb111_7;
  TNode<IntPtrT> phi_bb111_9;
  TNode<IntPtrT> phi_bb111_10;
  TNode<IntPtrT> phi_bb111_11;
  TNode<IntPtrT> phi_bb111_14;
  TNode<BoolT> phi_bb111_15;
  TNode<IntPtrT> phi_bb111_21;
  TNode<Union<HeapObject, TaggedIndex>> tmp248;
  TNode<IntPtrT> tmp249;
  TNode<IntPtrT> tmp250;
  TNode<IntPtrT> tmp251;
  if (block111.is_used()) {
    ca_.Bind(&block111, &phi_bb111_7, &phi_bb111_9, &phi_bb111_10, &phi_bb111_11, &phi_bb111_14, &phi_bb111_15, &phi_bb111_21);
    std::tie(tmp248, tmp249) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp101}, TNode<IntPtrT>{phi_bb111_11}).Flatten();
    tmp250 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp251 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb111_11}, TNode<IntPtrT>{tmp250});
    ca_.Goto(&block110, phi_bb111_7, phi_bb111_9, phi_bb111_10, tmp251, phi_bb111_14, phi_bb111_15, phi_bb111_21, tmp248, tmp249);
  }

  TNode<IntPtrT> phi_bb112_7;
  TNode<IntPtrT> phi_bb112_9;
  TNode<IntPtrT> phi_bb112_10;
  TNode<IntPtrT> phi_bb112_11;
  TNode<IntPtrT> phi_bb112_14;
  TNode<BoolT> phi_bb112_15;
  TNode<IntPtrT> phi_bb112_21;
  TNode<IntPtrT> tmp252;
  TNode<BoolT> tmp253;
  if (block112.is_used()) {
    ca_.Bind(&block112, &phi_bb112_7, &phi_bb112_9, &phi_bb112_10, &phi_bb112_11, &phi_bb112_14, &phi_bb112_15, &phi_bb112_21);
    tmp252 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp253 = CodeStubAssembler(state_).WordNotEqual(TNode<IntPtrT>{phi_bb112_14}, TNode<IntPtrT>{tmp252});
    ca_.Branch(tmp253, &block114, std::vector<compiler::Node*>{phi_bb112_7, phi_bb112_9, phi_bb112_10, phi_bb112_11, phi_bb112_14, phi_bb112_15, phi_bb112_21}, &block115, std::vector<compiler::Node*>{phi_bb112_7, phi_bb112_9, phi_bb112_10, phi_bb112_11, phi_bb112_14, phi_bb112_15, phi_bb112_21});
  }

  TNode<IntPtrT> phi_bb114_7;
  TNode<IntPtrT> phi_bb114_9;
  TNode<IntPtrT> phi_bb114_10;
  TNode<IntPtrT> phi_bb114_11;
  TNode<IntPtrT> phi_bb114_14;
  TNode<BoolT> phi_bb114_15;
  TNode<IntPtrT> phi_bb114_21;
  TNode<Union<HeapObject, TaggedIndex>> tmp254;
  TNode<IntPtrT> tmp255;
  TNode<IntPtrT> tmp256;
  TNode<BoolT> tmp257;
  if (block114.is_used()) {
    ca_.Bind(&block114, &phi_bb114_7, &phi_bb114_9, &phi_bb114_10, &phi_bb114_11, &phi_bb114_14, &phi_bb114_15, &phi_bb114_21);
    std::tie(tmp254, tmp255) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp101}, TNode<IntPtrT>{phi_bb114_14}).Flatten();
    tmp256 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp257 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block110, phi_bb114_7, phi_bb114_9, phi_bb114_10, phi_bb114_11, tmp256, tmp257, phi_bb114_21, tmp254, tmp255);
  }

  TNode<IntPtrT> phi_bb115_7;
  TNode<IntPtrT> phi_bb115_9;
  TNode<IntPtrT> phi_bb115_10;
  TNode<IntPtrT> phi_bb115_11;
  TNode<IntPtrT> phi_bb115_14;
  TNode<BoolT> phi_bb115_15;
  TNode<IntPtrT> phi_bb115_21;
  TNode<Union<HeapObject, TaggedIndex>> tmp258;
  TNode<IntPtrT> tmp259;
  TNode<IntPtrT> tmp260;
  TNode<IntPtrT> tmp261;
  TNode<IntPtrT> tmp262;
  TNode<IntPtrT> tmp263;
  TNode<BoolT> tmp264;
  if (block115.is_used()) {
    ca_.Bind(&block115, &phi_bb115_7, &phi_bb115_9, &phi_bb115_10, &phi_bb115_11, &phi_bb115_14, &phi_bb115_15, &phi_bb115_21);
    std::tie(tmp258, tmp259) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp101}, TNode<IntPtrT>{phi_bb115_11}).Flatten();
    tmp260 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp261 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb115_11}, TNode<IntPtrT>{tmp260});
    tmp262 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp263 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp261}, TNode<IntPtrT>{tmp262});
    tmp264 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block110, phi_bb115_7, phi_bb115_9, phi_bb115_10, tmp263, tmp261, tmp264, phi_bb115_21, tmp258, tmp259);
  }

  TNode<IntPtrT> phi_bb110_7;
  TNode<IntPtrT> phi_bb110_9;
  TNode<IntPtrT> phi_bb110_10;
  TNode<IntPtrT> phi_bb110_11;
  TNode<IntPtrT> phi_bb110_14;
  TNode<BoolT> phi_bb110_15;
  TNode<IntPtrT> phi_bb110_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb110_23;
  TNode<IntPtrT> phi_bb110_24;
  if (block110.is_used()) {
    ca_.Bind(&block110, &phi_bb110_7, &phi_bb110_9, &phi_bb110_10, &phi_bb110_11, &phi_bb110_14, &phi_bb110_15, &phi_bb110_21, &phi_bb110_23, &phi_bb110_24);
    ca_.Goto(&block104, phi_bb110_7, phi_bb110_9, phi_bb110_10, phi_bb110_11, phi_bb110_14, phi_bb110_15, phi_bb110_21, phi_bb110_23, phi_bb110_24);
  }

  TNode<IntPtrT> phi_bb108_7;
  TNode<IntPtrT> phi_bb108_9;
  TNode<IntPtrT> phi_bb108_10;
  TNode<IntPtrT> phi_bb108_11;
  TNode<IntPtrT> phi_bb108_14;
  TNode<BoolT> phi_bb108_15;
  TNode<IntPtrT> phi_bb108_21;
  TNode<Union<HeapObject, TaggedIndex>> tmp265;
  TNode<IntPtrT> tmp266;
  TNode<IntPtrT> tmp267;
  TNode<IntPtrT> tmp268;
  TNode<BoolT> tmp269;
  if (block108.is_used()) {
    ca_.Bind(&block108, &phi_bb108_7, &phi_bb108_9, &phi_bb108_10, &phi_bb108_11, &phi_bb108_14, &phi_bb108_15, &phi_bb108_21);
    std::tie(tmp265, tmp266) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp101}, TNode<IntPtrT>{phi_bb108_11}).Flatten();
    tmp267 = FromConstexpr_intptr_constexpr_int31_0(state_, (CodeStubAssembler(state_).ConstexprInt31Mul((FromConstexpr_constexpr_int31_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull))), (SizeOf_intptr_0(state_)))));
    tmp268 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb108_11}, TNode<IntPtrT>{tmp267});
    tmp269 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block104, phi_bb108_7, phi_bb108_9, phi_bb108_10, tmp268, phi_bb108_14, tmp269, phi_bb108_21, tmp265, tmp266);
  }

  TNode<IntPtrT> phi_bb104_7;
  TNode<IntPtrT> phi_bb104_9;
  TNode<IntPtrT> phi_bb104_10;
  TNode<IntPtrT> phi_bb104_11;
  TNode<IntPtrT> phi_bb104_14;
  TNode<BoolT> phi_bb104_15;
  TNode<IntPtrT> phi_bb104_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb104_23;
  TNode<IntPtrT> phi_bb104_24;
  if (block104.is_used()) {
    ca_.Bind(&block104, &phi_bb104_7, &phi_bb104_9, &phi_bb104_10, &phi_bb104_11, &phi_bb104_14, &phi_bb104_15, &phi_bb104_21, &phi_bb104_23, &phi_bb104_24);
    ca_.Goto(&block103, phi_bb104_7, tmp241, phi_bb104_9, phi_bb104_10, phi_bb104_11, phi_bb104_14, phi_bb104_15, phi_bb104_21);
  }

  TNode<IntPtrT> phi_bb103_7;
  TNode<IntPtrT> phi_bb103_8;
  TNode<IntPtrT> phi_bb103_9;
  TNode<IntPtrT> phi_bb103_10;
  TNode<IntPtrT> phi_bb103_11;
  TNode<IntPtrT> phi_bb103_14;
  TNode<BoolT> phi_bb103_15;
  TNode<IntPtrT> phi_bb103_21;
  if (block103.is_used()) {
    ca_.Bind(&block103, &phi_bb103_7, &phi_bb103_8, &phi_bb103_9, &phi_bb103_10, &phi_bb103_11, &phi_bb103_14, &phi_bb103_15, &phi_bb103_21);
    ca_.Goto(&block80, phi_bb103_7, phi_bb103_8, phi_bb103_9, phi_bb103_10, phi_bb103_11, phi_bb103_14, phi_bb103_15, phi_bb103_21);
  }

  TNode<IntPtrT> phi_bb80_7;
  TNode<IntPtrT> phi_bb80_8;
  TNode<IntPtrT> phi_bb80_9;
  TNode<IntPtrT> phi_bb80_10;
  TNode<IntPtrT> phi_bb80_11;
  TNode<IntPtrT> phi_bb80_14;
  TNode<BoolT> phi_bb80_15;
  TNode<IntPtrT> phi_bb80_21;
  if (block80.is_used()) {
    ca_.Bind(&block80, &phi_bb80_7, &phi_bb80_8, &phi_bb80_9, &phi_bb80_10, &phi_bb80_11, &phi_bb80_14, &phi_bb80_15, &phi_bb80_21);
    ca_.Goto(&block68, phi_bb80_7, phi_bb80_8, phi_bb80_9, phi_bb80_10, phi_bb80_11, phi_bb80_14, phi_bb80_15, phi_bb80_21);
  }

  TNode<IntPtrT> phi_bb68_7;
  TNode<IntPtrT> phi_bb68_8;
  TNode<IntPtrT> phi_bb68_9;
  TNode<IntPtrT> phi_bb68_10;
  TNode<IntPtrT> phi_bb68_11;
  TNode<IntPtrT> phi_bb68_14;
  TNode<BoolT> phi_bb68_15;
  TNode<IntPtrT> phi_bb68_21;
  if (block68.is_used()) {
    ca_.Bind(&block68, &phi_bb68_7, &phi_bb68_8, &phi_bb68_9, &phi_bb68_10, &phi_bb68_11, &phi_bb68_14, &phi_bb68_15, &phi_bb68_21);
    ca_.Goto(&block56, phi_bb68_7, phi_bb68_8, phi_bb68_9, phi_bb68_10, phi_bb68_11, phi_bb68_14, phi_bb68_15, phi_bb68_21);
  }

  TNode<IntPtrT> phi_bb56_7;
  TNode<IntPtrT> phi_bb56_8;
  TNode<IntPtrT> phi_bb56_9;
  TNode<IntPtrT> phi_bb56_10;
  TNode<IntPtrT> phi_bb56_11;
  TNode<IntPtrT> phi_bb56_14;
  TNode<BoolT> phi_bb56_15;
  TNode<IntPtrT> phi_bb56_21;
  TNode<IntPtrT> tmp270;
  TNode<IntPtrT> tmp271;
  if (block56.is_used()) {
    ca_.Bind(&block56, &phi_bb56_7, &phi_bb56_8, &phi_bb56_9, &phi_bb56_10, &phi_bb56_11, &phi_bb56_14, &phi_bb56_15, &phi_bb56_21);
    tmp270 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp271 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb56_21}, TNode<IntPtrT>{tmp270});
    ca_.Goto(&block51, phi_bb56_7, phi_bb56_8, phi_bb56_9, phi_bb56_10, phi_bb56_11, phi_bb56_14, phi_bb56_15, tmp271);
  }

  TNode<IntPtrT> phi_bb50_7;
  TNode<IntPtrT> phi_bb50_8;
  TNode<IntPtrT> phi_bb50_9;
  TNode<IntPtrT> phi_bb50_10;
  TNode<IntPtrT> phi_bb50_11;
  TNode<IntPtrT> phi_bb50_14;
  TNode<BoolT> phi_bb50_15;
  TNode<IntPtrT> phi_bb50_21;
  TNode<BoolT> tmp272;
  if (block50.is_used()) {
    ca_.Bind(&block50, &phi_bb50_7, &phi_bb50_8, &phi_bb50_9, &phi_bb50_10, &phi_bb50_11, &phi_bb50_14, &phi_bb50_15, &phi_bb50_21);
    tmp272 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{phi_bb50_15});
    ca_.Branch(tmp272, &block117, std::vector<compiler::Node*>{phi_bb50_7, phi_bb50_8, phi_bb50_9, phi_bb50_10, phi_bb50_11, phi_bb50_14, phi_bb50_15}, &block118, std::vector<compiler::Node*>{phi_bb50_7, phi_bb50_8, phi_bb50_9, phi_bb50_10, phi_bb50_11, phi_bb50_14, phi_bb50_15});
  }

  TNode<IntPtrT> phi_bb117_7;
  TNode<IntPtrT> phi_bb117_8;
  TNode<IntPtrT> phi_bb117_9;
  TNode<IntPtrT> phi_bb117_10;
  TNode<IntPtrT> phi_bb117_11;
  TNode<IntPtrT> phi_bb117_14;
  TNode<BoolT> phi_bb117_15;
  TNode<IntPtrT> tmp273;
  if (block117.is_used()) {
    ca_.Bind(&block117, &phi_bb117_7, &phi_bb117_8, &phi_bb117_9, &phi_bb117_10, &phi_bb117_11, &phi_bb117_14, &phi_bb117_15);
    tmp273 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.Goto(&block118, phi_bb117_7, phi_bb117_8, phi_bb117_9, phi_bb117_10, phi_bb117_11, tmp273, phi_bb117_15);
  }

  TNode<IntPtrT> phi_bb118_7;
  TNode<IntPtrT> phi_bb118_8;
  TNode<IntPtrT> phi_bb118_9;
  TNode<IntPtrT> phi_bb118_10;
  TNode<IntPtrT> phi_bb118_11;
  TNode<IntPtrT> phi_bb118_14;
  TNode<BoolT> phi_bb118_15;
  TNode<IntPtrT> tmp274;
  if (block118.is_used()) {
    ca_.Bind(&block118, &phi_bb118_7, &phi_bb118_8, &phi_bb118_9, &phi_bb118_10, &phi_bb118_11, &phi_bb118_14, &phi_bb118_15);
    tmp274 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.Goto(&block121, phi_bb118_7, phi_bb118_8, phi_bb118_9, phi_bb118_10, phi_bb118_11, phi_bb118_14, phi_bb118_15, tmp274);
  }

  TNode<IntPtrT> phi_bb121_7;
  TNode<IntPtrT> phi_bb121_8;
  TNode<IntPtrT> phi_bb121_9;
  TNode<IntPtrT> phi_bb121_10;
  TNode<IntPtrT> phi_bb121_11;
  TNode<IntPtrT> phi_bb121_14;
  TNode<BoolT> phi_bb121_15;
  TNode<IntPtrT> phi_bb121_21;
  TNode<IntPtrT> tmp275;
  TNode<BoolT> tmp276;
  if (block121.is_used()) {
    ca_.Bind(&block121, &phi_bb121_7, &phi_bb121_8, &phi_bb121_9, &phi_bb121_10, &phi_bb121_11, &phi_bb121_14, &phi_bb121_15, &phi_bb121_21);
    tmp275 = Convert_intptr_int32_0(state_, TNode<Int32T>{tmp3});
    tmp276 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{phi_bb121_21}, TNode<IntPtrT>{tmp275});
    ca_.Branch(tmp276, &block119, std::vector<compiler::Node*>{phi_bb121_7, phi_bb121_8, phi_bb121_9, phi_bb121_10, phi_bb121_11, phi_bb121_14, phi_bb121_15, phi_bb121_21}, &block120, std::vector<compiler::Node*>{phi_bb121_7, phi_bb121_8, phi_bb121_9, phi_bb121_10, phi_bb121_11, phi_bb121_14, phi_bb121_15, phi_bb121_21});
  }

  TNode<IntPtrT> phi_bb119_7;
  TNode<IntPtrT> phi_bb119_8;
  TNode<IntPtrT> phi_bb119_9;
  TNode<IntPtrT> phi_bb119_10;
  TNode<IntPtrT> phi_bb119_11;
  TNode<IntPtrT> phi_bb119_14;
  TNode<BoolT> phi_bb119_15;
  TNode<IntPtrT> phi_bb119_21;
  TNode<IntPtrT> tmp277;
  TNode<IntPtrT> tmp278;
  TNode<Union<HeapObject, TaggedIndex>> tmp279;
  TNode<IntPtrT> tmp280;
  TNode<Int32T> tmp281;
  TNode<Int32T> tmp282;
  TNode<Int32T> tmp283;
  TNode<Int32T> tmp284;
  TNode<BoolT> tmp285;
  if (block119.is_used()) {
    ca_.Bind(&block119, &phi_bb119_7, &phi_bb119_8, &phi_bb119_9, &phi_bb119_10, &phi_bb119_11, &phi_bb119_14, &phi_bb119_15, &phi_bb119_21);
    tmp277 = TimesSizeOf_int32_0(state_, TNode<IntPtrT>{phi_bb119_21});
    tmp278 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp118}, TNode<IntPtrT>{tmp277});
    std::tie(tmp279, tmp280) = NewReference_int32_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp117}, TNode<IntPtrT>{tmp278}).Flatten();
    tmp281 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{tmp279, tmp280});
    tmp282 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmValueKindBitsMask);
    tmp283 = CodeStubAssembler(state_).Word32And(TNode<Int32T>{tmp281}, TNode<Int32T>{tmp282});
    tmp284 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::ValueKind::kRef);
    tmp285 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp283}, TNode<Int32T>{tmp284});
    ca_.Branch(tmp285, &block126, std::vector<compiler::Node*>{phi_bb119_7, phi_bb119_8, phi_bb119_9, phi_bb119_10, phi_bb119_11, phi_bb119_14, phi_bb119_15, phi_bb119_21}, &block127, std::vector<compiler::Node*>{phi_bb119_7, phi_bb119_8, phi_bb119_9, phi_bb119_10, phi_bb119_11, phi_bb119_14, phi_bb119_15, phi_bb119_21});
  }

  TNode<IntPtrT> phi_bb126_7;
  TNode<IntPtrT> phi_bb126_8;
  TNode<IntPtrT> phi_bb126_9;
  TNode<IntPtrT> phi_bb126_10;
  TNode<IntPtrT> phi_bb126_11;
  TNode<IntPtrT> phi_bb126_14;
  TNode<BoolT> phi_bb126_15;
  TNode<IntPtrT> phi_bb126_21;
  TNode<BoolT> tmp286;
  if (block126.is_used()) {
    ca_.Bind(&block126, &phi_bb126_7, &phi_bb126_8, &phi_bb126_9, &phi_bb126_10, &phi_bb126_11, &phi_bb126_14, &phi_bb126_15, &phi_bb126_21);
    tmp286 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block128, phi_bb126_7, phi_bb126_8, phi_bb126_9, phi_bb126_10, phi_bb126_11, phi_bb126_14, phi_bb126_15, phi_bb126_21, tmp286);
  }

  TNode<IntPtrT> phi_bb127_7;
  TNode<IntPtrT> phi_bb127_8;
  TNode<IntPtrT> phi_bb127_9;
  TNode<IntPtrT> phi_bb127_10;
  TNode<IntPtrT> phi_bb127_11;
  TNode<IntPtrT> phi_bb127_14;
  TNode<BoolT> phi_bb127_15;
  TNode<IntPtrT> phi_bb127_21;
  TNode<Int32T> tmp287;
  TNode<BoolT> tmp288;
  if (block127.is_used()) {
    ca_.Bind(&block127, &phi_bb127_7, &phi_bb127_8, &phi_bb127_9, &phi_bb127_10, &phi_bb127_11, &phi_bb127_14, &phi_bb127_15, &phi_bb127_21);
    tmp287 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::ValueKind::kRefNull);
    tmp288 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp283}, TNode<Int32T>{tmp287});
    ca_.Goto(&block128, phi_bb127_7, phi_bb127_8, phi_bb127_9, phi_bb127_10, phi_bb127_11, phi_bb127_14, phi_bb127_15, phi_bb127_21, tmp288);
  }

  TNode<IntPtrT> phi_bb128_7;
  TNode<IntPtrT> phi_bb128_8;
  TNode<IntPtrT> phi_bb128_9;
  TNode<IntPtrT> phi_bb128_10;
  TNode<IntPtrT> phi_bb128_11;
  TNode<IntPtrT> phi_bb128_14;
  TNode<BoolT> phi_bb128_15;
  TNode<IntPtrT> phi_bb128_21;
  TNode<BoolT> phi_bb128_25;
  if (block128.is_used()) {
    ca_.Bind(&block128, &phi_bb128_7, &phi_bb128_8, &phi_bb128_9, &phi_bb128_10, &phi_bb128_11, &phi_bb128_14, &phi_bb128_15, &phi_bb128_21, &phi_bb128_25);
    ca_.Branch(phi_bb128_25, &block124, std::vector<compiler::Node*>{phi_bb128_7, phi_bb128_8, phi_bb128_9, phi_bb128_10, phi_bb128_11, phi_bb128_14, phi_bb128_15, phi_bb128_21}, &block125, std::vector<compiler::Node*>{phi_bb128_7, phi_bb128_8, phi_bb128_9, phi_bb128_10, phi_bb128_11, phi_bb128_14, phi_bb128_15, phi_bb128_21});
  }

  TNode<IntPtrT> phi_bb124_7;
  TNode<IntPtrT> phi_bb124_8;
  TNode<IntPtrT> phi_bb124_9;
  TNode<IntPtrT> phi_bb124_10;
  TNode<IntPtrT> phi_bb124_11;
  TNode<IntPtrT> phi_bb124_14;
  TNode<BoolT> phi_bb124_15;
  TNode<IntPtrT> phi_bb124_21;
  TNode<IntPtrT> tmp289;
  TNode<IntPtrT> tmp290;
  TNode<IntPtrT> tmp291;
  TNode<BoolT> tmp292;
  if (block124.is_used()) {
    ca_.Bind(&block124, &phi_bb124_7, &phi_bb124_8, &phi_bb124_9, &phi_bb124_10, &phi_bb124_11, &phi_bb124_14, &phi_bb124_15, &phi_bb124_21);
    tmp289 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp290 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{phi_bb124_7}, TNode<IntPtrT>{tmp289});
    tmp291 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp292 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{phi_bb124_7}, TNode<IntPtrT>{tmp291});
    ca_.Branch(tmp292, &block130, std::vector<compiler::Node*>{phi_bb124_8, phi_bb124_9, phi_bb124_10, phi_bb124_11, phi_bb124_14, phi_bb124_15, phi_bb124_21}, &block131, std::vector<compiler::Node*>{phi_bb124_8, phi_bb124_9, phi_bb124_10, phi_bb124_11, phi_bb124_14, phi_bb124_15, phi_bb124_21});
  }

  TNode<IntPtrT> phi_bb130_8;
  TNode<IntPtrT> phi_bb130_9;
  TNode<IntPtrT> phi_bb130_10;
  TNode<IntPtrT> phi_bb130_11;
  TNode<IntPtrT> phi_bb130_14;
  TNode<BoolT> phi_bb130_15;
  TNode<IntPtrT> phi_bb130_21;
  TNode<Union<HeapObject, TaggedIndex>> tmp293;
  TNode<IntPtrT> tmp294;
  TNode<IntPtrT> tmp295;
  TNode<IntPtrT> tmp296;
  if (block130.is_used()) {
    ca_.Bind(&block130, &phi_bb130_8, &phi_bb130_9, &phi_bb130_10, &phi_bb130_11, &phi_bb130_14, &phi_bb130_15, &phi_bb130_21);
    std::tie(tmp293, tmp294) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp101}, TNode<IntPtrT>{phi_bb130_9}).Flatten();
    tmp295 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp296 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb130_9}, TNode<IntPtrT>{tmp295});
    ca_.Goto(&block129, phi_bb130_8, tmp296, phi_bb130_10, phi_bb130_11, phi_bb130_14, phi_bb130_15, phi_bb130_21, tmp293, tmp294);
  }

  TNode<IntPtrT> phi_bb131_8;
  TNode<IntPtrT> phi_bb131_9;
  TNode<IntPtrT> phi_bb131_10;
  TNode<IntPtrT> phi_bb131_11;
  TNode<IntPtrT> phi_bb131_14;
  TNode<BoolT> phi_bb131_15;
  TNode<IntPtrT> phi_bb131_21;
  if (block131.is_used()) {
    ca_.Bind(&block131, &phi_bb131_8, &phi_bb131_9, &phi_bb131_10, &phi_bb131_11, &phi_bb131_14, &phi_bb131_15, &phi_bb131_21);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block133, phi_bb131_8, phi_bb131_9, phi_bb131_10, phi_bb131_11, phi_bb131_14, phi_bb131_15, phi_bb131_21);
    } else {
      ca_.Goto(&block134, phi_bb131_8, phi_bb131_9, phi_bb131_10, phi_bb131_11, phi_bb131_14, phi_bb131_15, phi_bb131_21);
    }
  }

  TNode<IntPtrT> phi_bb133_8;
  TNode<IntPtrT> phi_bb133_9;
  TNode<IntPtrT> phi_bb133_10;
  TNode<IntPtrT> phi_bb133_11;
  TNode<IntPtrT> phi_bb133_14;
  TNode<BoolT> phi_bb133_15;
  TNode<IntPtrT> phi_bb133_21;
  TNode<Union<HeapObject, TaggedIndex>> tmp297;
  TNode<IntPtrT> tmp298;
  TNode<IntPtrT> tmp299;
  TNode<IntPtrT> tmp300;
  if (block133.is_used()) {
    ca_.Bind(&block133, &phi_bb133_8, &phi_bb133_9, &phi_bb133_10, &phi_bb133_11, &phi_bb133_14, &phi_bb133_15, &phi_bb133_21);
    std::tie(tmp297, tmp298) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp101}, TNode<IntPtrT>{phi_bb133_11}).Flatten();
    tmp299 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp300 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb133_11}, TNode<IntPtrT>{tmp299});
    ca_.Goto(&block132, phi_bb133_8, phi_bb133_9, phi_bb133_10, tmp300, phi_bb133_14, phi_bb133_15, phi_bb133_21, tmp297, tmp298);
  }

  TNode<IntPtrT> phi_bb134_8;
  TNode<IntPtrT> phi_bb134_9;
  TNode<IntPtrT> phi_bb134_10;
  TNode<IntPtrT> phi_bb134_11;
  TNode<IntPtrT> phi_bb134_14;
  TNode<BoolT> phi_bb134_15;
  TNode<IntPtrT> phi_bb134_21;
  TNode<IntPtrT> tmp301;
  TNode<BoolT> tmp302;
  if (block134.is_used()) {
    ca_.Bind(&block134, &phi_bb134_8, &phi_bb134_9, &phi_bb134_10, &phi_bb134_11, &phi_bb134_14, &phi_bb134_15, &phi_bb134_21);
    tmp301 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp302 = CodeStubAssembler(state_).WordNotEqual(TNode<IntPtrT>{phi_bb134_14}, TNode<IntPtrT>{tmp301});
    ca_.Branch(tmp302, &block136, std::vector<compiler::Node*>{phi_bb134_8, phi_bb134_9, phi_bb134_10, phi_bb134_11, phi_bb134_14, phi_bb134_15, phi_bb134_21}, &block137, std::vector<compiler::Node*>{phi_bb134_8, phi_bb134_9, phi_bb134_10, phi_bb134_11, phi_bb134_14, phi_bb134_15, phi_bb134_21});
  }

  TNode<IntPtrT> phi_bb136_8;
  TNode<IntPtrT> phi_bb136_9;
  TNode<IntPtrT> phi_bb136_10;
  TNode<IntPtrT> phi_bb136_11;
  TNode<IntPtrT> phi_bb136_14;
  TNode<BoolT> phi_bb136_15;
  TNode<IntPtrT> phi_bb136_21;
  TNode<Union<HeapObject, TaggedIndex>> tmp303;
  TNode<IntPtrT> tmp304;
  TNode<IntPtrT> tmp305;
  TNode<BoolT> tmp306;
  if (block136.is_used()) {
    ca_.Bind(&block136, &phi_bb136_8, &phi_bb136_9, &phi_bb136_10, &phi_bb136_11, &phi_bb136_14, &phi_bb136_15, &phi_bb136_21);
    std::tie(tmp303, tmp304) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp101}, TNode<IntPtrT>{phi_bb136_14}).Flatten();
    tmp305 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp306 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block132, phi_bb136_8, phi_bb136_9, phi_bb136_10, phi_bb136_11, tmp305, tmp306, phi_bb136_21, tmp303, tmp304);
  }

  TNode<IntPtrT> phi_bb137_8;
  TNode<IntPtrT> phi_bb137_9;
  TNode<IntPtrT> phi_bb137_10;
  TNode<IntPtrT> phi_bb137_11;
  TNode<IntPtrT> phi_bb137_14;
  TNode<BoolT> phi_bb137_15;
  TNode<IntPtrT> phi_bb137_21;
  TNode<Union<HeapObject, TaggedIndex>> tmp307;
  TNode<IntPtrT> tmp308;
  TNode<IntPtrT> tmp309;
  TNode<IntPtrT> tmp310;
  TNode<IntPtrT> tmp311;
  TNode<IntPtrT> tmp312;
  TNode<BoolT> tmp313;
  if (block137.is_used()) {
    ca_.Bind(&block137, &phi_bb137_8, &phi_bb137_9, &phi_bb137_10, &phi_bb137_11, &phi_bb137_14, &phi_bb137_15, &phi_bb137_21);
    std::tie(tmp307, tmp308) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp101}, TNode<IntPtrT>{phi_bb137_11}).Flatten();
    tmp309 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp310 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb137_11}, TNode<IntPtrT>{tmp309});
    tmp311 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp312 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp310}, TNode<IntPtrT>{tmp311});
    tmp313 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block132, phi_bb137_8, phi_bb137_9, phi_bb137_10, tmp312, tmp310, tmp313, phi_bb137_21, tmp307, tmp308);
  }

  TNode<IntPtrT> phi_bb132_8;
  TNode<IntPtrT> phi_bb132_9;
  TNode<IntPtrT> phi_bb132_10;
  TNode<IntPtrT> phi_bb132_11;
  TNode<IntPtrT> phi_bb132_14;
  TNode<BoolT> phi_bb132_15;
  TNode<IntPtrT> phi_bb132_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb132_24;
  TNode<IntPtrT> phi_bb132_25;
  if (block132.is_used()) {
    ca_.Bind(&block132, &phi_bb132_8, &phi_bb132_9, &phi_bb132_10, &phi_bb132_11, &phi_bb132_14, &phi_bb132_15, &phi_bb132_21, &phi_bb132_24, &phi_bb132_25);
    ca_.Goto(&block129, phi_bb132_8, phi_bb132_9, phi_bb132_10, phi_bb132_11, phi_bb132_14, phi_bb132_15, phi_bb132_21, phi_bb132_24, phi_bb132_25);
  }

  TNode<IntPtrT> phi_bb129_8;
  TNode<IntPtrT> phi_bb129_9;
  TNode<IntPtrT> phi_bb129_10;
  TNode<IntPtrT> phi_bb129_11;
  TNode<IntPtrT> phi_bb129_14;
  TNode<BoolT> phi_bb129_15;
  TNode<IntPtrT> phi_bb129_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb129_24;
  TNode<IntPtrT> phi_bb129_25;
  TNode<IntPtrT> tmp314;
  TNode<Object> tmp315;
  TNode<Union<HeapObject, TaggedIndex>> tmp316;
  TNode<IntPtrT> tmp317;
  TNode<IntPtrT> tmp318;
  TNode<UintPtrT> tmp319;
  TNode<UintPtrT> tmp320;
  TNode<BoolT> tmp321;
  if (block129.is_used()) {
    ca_.Bind(&block129, &phi_bb129_8, &phi_bb129_9, &phi_bb129_10, &phi_bb129_11, &phi_bb129_14, &phi_bb129_15, &phi_bb129_21, &phi_bb129_24, &phi_bb129_25);
    tmp314 = CodeStubAssembler(state_).LoadReference<IntPtrT>(CodeStubAssembler::Reference{phi_bb129_24, phi_bb129_25});
    tmp315 = CodeStubAssembler(state_).BitcastWordToTagged(TNode<IntPtrT>{tmp314});
    std::tie(tmp316, tmp317, tmp318) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{tmp92}).Flatten();
    tmp319 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{phi_bb129_21});
    tmp320 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp318});
    tmp321 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp319}, TNode<UintPtrT>{tmp320});
    ca_.Branch(tmp321, &block142, std::vector<compiler::Node*>{phi_bb129_8, phi_bb129_9, phi_bb129_10, phi_bb129_11, phi_bb129_14, phi_bb129_15, phi_bb129_21, phi_bb129_24, phi_bb129_25, phi_bb129_21, phi_bb129_21, phi_bb129_21, phi_bb129_21}, &block143, std::vector<compiler::Node*>{phi_bb129_8, phi_bb129_9, phi_bb129_10, phi_bb129_11, phi_bb129_14, phi_bb129_15, phi_bb129_21, phi_bb129_24, phi_bb129_25, phi_bb129_21, phi_bb129_21, phi_bb129_21, phi_bb129_21});
  }

  TNode<IntPtrT> phi_bb142_8;
  TNode<IntPtrT> phi_bb142_9;
  TNode<IntPtrT> phi_bb142_10;
  TNode<IntPtrT> phi_bb142_11;
  TNode<IntPtrT> phi_bb142_14;
  TNode<BoolT> phi_bb142_15;
  TNode<IntPtrT> phi_bb142_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb142_24;
  TNode<IntPtrT> phi_bb142_25;
  TNode<IntPtrT> phi_bb142_32;
  TNode<IntPtrT> phi_bb142_33;
  TNode<IntPtrT> phi_bb142_37;
  TNode<IntPtrT> phi_bb142_38;
  TNode<IntPtrT> tmp322;
  TNode<IntPtrT> tmp323;
  TNode<Union<HeapObject, TaggedIndex>> tmp324;
  TNode<IntPtrT> tmp325;
  if (block142.is_used()) {
    ca_.Bind(&block142, &phi_bb142_8, &phi_bb142_9, &phi_bb142_10, &phi_bb142_11, &phi_bb142_14, &phi_bb142_15, &phi_bb142_21, &phi_bb142_24, &phi_bb142_25, &phi_bb142_32, &phi_bb142_33, &phi_bb142_37, &phi_bb142_38);
    tmp322 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{phi_bb142_38});
    tmp323 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp317}, TNode<IntPtrT>{tmp322});
    std::tie(tmp324, tmp325) = NewReference_Object_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp316}, TNode<IntPtrT>{tmp323}).Flatten();
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp324, tmp325}, tmp315);
    ca_.Goto(&block125, tmp290, phi_bb142_8, phi_bb142_9, phi_bb142_10, phi_bb142_11, phi_bb142_14, phi_bb142_15, phi_bb142_21);
  }

  TNode<IntPtrT> phi_bb143_8;
  TNode<IntPtrT> phi_bb143_9;
  TNode<IntPtrT> phi_bb143_10;
  TNode<IntPtrT> phi_bb143_11;
  TNode<IntPtrT> phi_bb143_14;
  TNode<BoolT> phi_bb143_15;
  TNode<IntPtrT> phi_bb143_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb143_24;
  TNode<IntPtrT> phi_bb143_25;
  TNode<IntPtrT> phi_bb143_32;
  TNode<IntPtrT> phi_bb143_33;
  TNode<IntPtrT> phi_bb143_37;
  TNode<IntPtrT> phi_bb143_38;
  if (block143.is_used()) {
    ca_.Bind(&block143, &phi_bb143_8, &phi_bb143_9, &phi_bb143_10, &phi_bb143_11, &phi_bb143_14, &phi_bb143_15, &phi_bb143_21, &phi_bb143_24, &phi_bb143_25, &phi_bb143_32, &phi_bb143_33, &phi_bb143_37, &phi_bb143_38);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> phi_bb125_7;
  TNode<IntPtrT> phi_bb125_8;
  TNode<IntPtrT> phi_bb125_9;
  TNode<IntPtrT> phi_bb125_10;
  TNode<IntPtrT> phi_bb125_11;
  TNode<IntPtrT> phi_bb125_14;
  TNode<BoolT> phi_bb125_15;
  TNode<IntPtrT> phi_bb125_21;
  TNode<IntPtrT> tmp326;
  TNode<IntPtrT> tmp327;
  if (block125.is_used()) {
    ca_.Bind(&block125, &phi_bb125_7, &phi_bb125_8, &phi_bb125_9, &phi_bb125_10, &phi_bb125_11, &phi_bb125_14, &phi_bb125_15, &phi_bb125_21);
    tmp326 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp327 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb125_21}, TNode<IntPtrT>{tmp326});
    ca_.Goto(&block121, phi_bb125_7, phi_bb125_8, phi_bb125_9, phi_bb125_10, phi_bb125_11, phi_bb125_14, phi_bb125_15, tmp327);
  }

  TNode<IntPtrT> phi_bb120_7;
  TNode<IntPtrT> phi_bb120_8;
  TNode<IntPtrT> phi_bb120_9;
  TNode<IntPtrT> phi_bb120_10;
  TNode<IntPtrT> phi_bb120_11;
  TNode<IntPtrT> phi_bb120_14;
  TNode<BoolT> phi_bb120_15;
  TNode<IntPtrT> phi_bb120_21;
  if (block120.is_used()) {
    ca_.Bind(&block120, &phi_bb120_7, &phi_bb120_8, &phi_bb120_9, &phi_bb120_10, &phi_bb120_11, &phi_bb120_14, &phi_bb120_15, &phi_bb120_21);
    ca_.Goto(&block48, phi_bb120_7, phi_bb120_8, phi_bb120_9, phi_bb120_10, phi_bb120_11, phi_bb120_14, phi_bb120_15);
  }

  TNode<IntPtrT> phi_bb48_7;
  TNode<IntPtrT> phi_bb48_8;
  TNode<IntPtrT> phi_bb48_9;
  TNode<IntPtrT> phi_bb48_10;
  TNode<IntPtrT> phi_bb48_11;
  TNode<IntPtrT> phi_bb48_14;
  TNode<BoolT> phi_bb48_15;
  TNode<IntPtrT> tmp328;
  TNode<BoolT> tmp329;
  if (block48.is_used()) {
    ca_.Bind(&block48, &phi_bb48_7, &phi_bb48_8, &phi_bb48_9, &phi_bb48_10, &phi_bb48_11, &phi_bb48_14, &phi_bb48_15);
    tmp328 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp329 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp108}, TNode<IntPtrT>{tmp328});
    ca_.Branch(tmp329, &block149, std::vector<compiler::Node*>{phi_bb48_7, phi_bb48_8, phi_bb48_9, phi_bb48_10, phi_bb48_11, phi_bb48_14, phi_bb48_15}, &block150, std::vector<compiler::Node*>{phi_bb48_7, phi_bb48_8, phi_bb48_9, phi_bb48_10, phi_bb48_11, phi_bb48_14, phi_bb48_15});
  }

  TNode<IntPtrT> phi_bb149_7;
  TNode<IntPtrT> phi_bb149_8;
  TNode<IntPtrT> phi_bb149_9;
  TNode<IntPtrT> phi_bb149_10;
  TNode<IntPtrT> phi_bb149_11;
  TNode<IntPtrT> phi_bb149_14;
  TNode<BoolT> phi_bb149_15;
  TNode<BoolT> tmp330;
  if (block149.is_used()) {
    ca_.Bind(&block149, &phi_bb149_7, &phi_bb149_8, &phi_bb149_9, &phi_bb149_10, &phi_bb149_11, &phi_bb149_14, &phi_bb149_15);
    tmp330 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block151, phi_bb149_7, phi_bb149_8, phi_bb149_9, phi_bb149_10, phi_bb149_11, phi_bb149_14, phi_bb149_15, tmp330);
  }

  TNode<IntPtrT> phi_bb150_7;
  TNode<IntPtrT> phi_bb150_8;
  TNode<IntPtrT> phi_bb150_9;
  TNode<IntPtrT> phi_bb150_10;
  TNode<IntPtrT> phi_bb150_11;
  TNode<IntPtrT> phi_bb150_14;
  TNode<BoolT> phi_bb150_15;
  TNode<BoolT> tmp331;
  if (block150.is_used()) {
    ca_.Bind(&block150, &phi_bb150_7, &phi_bb150_8, &phi_bb150_9, &phi_bb150_10, &phi_bb150_11, &phi_bb150_14, &phi_bb150_15);
    tmp331 = CodeStubAssembler(state_).IntPtrLessThanOrEqual(TNode<IntPtrT>{phi_bb150_11}, TNode<IntPtrT>{tmp108});
    ca_.Goto(&block151, phi_bb150_7, phi_bb150_8, phi_bb150_9, phi_bb150_10, phi_bb150_11, phi_bb150_14, phi_bb150_15, tmp331);
  }

  TNode<IntPtrT> phi_bb151_7;
  TNode<IntPtrT> phi_bb151_8;
  TNode<IntPtrT> phi_bb151_9;
  TNode<IntPtrT> phi_bb151_10;
  TNode<IntPtrT> phi_bb151_11;
  TNode<IntPtrT> phi_bb151_14;
  TNode<BoolT> phi_bb151_15;
  TNode<BoolT> phi_bb151_22;
  if (block151.is_used()) {
    ca_.Bind(&block151, &phi_bb151_7, &phi_bb151_8, &phi_bb151_9, &phi_bb151_10, &phi_bb151_11, &phi_bb151_14, &phi_bb151_15, &phi_bb151_22);
    ca_.Branch(phi_bb151_22, &block147, std::vector<compiler::Node*>{phi_bb151_7, phi_bb151_8, phi_bb151_9, phi_bb151_10, phi_bb151_11, phi_bb151_14, phi_bb151_15}, &block148, std::vector<compiler::Node*>{phi_bb151_7, phi_bb151_8, phi_bb151_9, phi_bb151_10, phi_bb151_11, phi_bb151_14, phi_bb151_15});
  }

  TNode<IntPtrT> phi_bb148_7;
  TNode<IntPtrT> phi_bb148_8;
  TNode<IntPtrT> phi_bb148_9;
  TNode<IntPtrT> phi_bb148_10;
  TNode<IntPtrT> phi_bb148_11;
  TNode<IntPtrT> phi_bb148_14;
  TNode<BoolT> phi_bb148_15;
  if (block148.is_used()) {
    ca_.Bind(&block148, &phi_bb148_7, &phi_bb148_8, &phi_bb148_9, &phi_bb148_10, &phi_bb148_11, &phi_bb148_14, &phi_bb148_15);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/js-to-wasm.tq", 379});
      CodeStubAssembler(state_).FailAssert("Torque assert 'this.paramBufferEnd == 0 || this.nextStack <= this.paramBufferEnd' failed", pos_stack);
    }
  }

  TNode<IntPtrT> phi_bb147_7;
  TNode<IntPtrT> phi_bb147_8;
  TNode<IntPtrT> phi_bb147_9;
  TNode<IntPtrT> phi_bb147_10;
  TNode<IntPtrT> phi_bb147_11;
  TNode<IntPtrT> phi_bb147_14;
  TNode<BoolT> phi_bb147_15;
  TNode<IntPtrT> tmp332;
  TNode<RawPtrT> tmp333;
  TNode<IntPtrT> tmp334;
  TNode<RawPtrT> tmp335;
  TNode<Union<HeapObject, TaggedIndex>> tmp336;
  TNode<IntPtrT> tmp337;
  TNode<IntPtrT> tmp338;
  TNode<IntPtrT> tmp339;
  TNode<IntPtrT> tmp340;
  TNode<IntPtrT> tmp341;
  TNode<IntPtrT> tmp342;
  TNode<IntPtrT> tmp343;
  TNode<IntPtrT> tmp344;
  TNode<BoolT> tmp345;
  TNode<IntPtrT> tmp346;
  if (block147.is_used()) {
    ca_.Bind(&block147, &phi_bb147_7, &phi_bb147_8, &phi_bb147_9, &phi_bb147_10, &phi_bb147_11, &phi_bb147_14, &phi_bb147_15);
    tmp332 = FromConstexpr_intptr_constexpr_intptr_0(state_, JSToWasmWrapperFrameConstants::kWrapperBufferGPReturnRegister1);
    tmp333 = CodeStubAssembler(state_).RawPtrAdd(TNode<RawPtrT>{parameter2}, TNode<IntPtrT>{tmp332});
    tmp334 = FromConstexpr_intptr_constexpr_intptr_0(state_, JSToWasmWrapperFrameConstants::kWrapperBufferFPReturnRegister1);
    tmp335 = CodeStubAssembler(state_).RawPtrAdd(TNode<RawPtrT>{parameter2}, TNode<IntPtrT>{tmp334});
    std::tie(tmp336, tmp337, tmp338, tmp339, tmp340, tmp341, tmp342, tmp343, tmp344, tmp345) = LocationAllocatorForReturns_0(state_, TNode<RawPtrT>{tmp333}, TNode<RawPtrT>{tmp335}, TNode<RawPtrT>{tmp96}).Flatten();
    tmp346 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.Goto(&block154, tmp337, tmp338, tmp339, tmp340, tmp341, tmp344, tmp345, tmp346);
  }

  TNode<IntPtrT> phi_bb154_7;
  TNode<IntPtrT> phi_bb154_8;
  TNode<IntPtrT> phi_bb154_9;
  TNode<IntPtrT> phi_bb154_10;
  TNode<IntPtrT> phi_bb154_11;
  TNode<IntPtrT> phi_bb154_14;
  TNode<BoolT> phi_bb154_15;
  TNode<IntPtrT> phi_bb154_21;
  TNode<IntPtrT> tmp347;
  TNode<BoolT> tmp348;
  if (block154.is_used()) {
    ca_.Bind(&block154, &phi_bb154_7, &phi_bb154_8, &phi_bb154_9, &phi_bb154_10, &phi_bb154_11, &phi_bb154_14, &phi_bb154_15, &phi_bb154_21);
    tmp347 = Convert_intptr_int32_0(state_, TNode<Int32T>{tmp3});
    tmp348 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{phi_bb154_21}, TNode<IntPtrT>{tmp347});
    ca_.Branch(tmp348, &block152, std::vector<compiler::Node*>{phi_bb154_7, phi_bb154_8, phi_bb154_9, phi_bb154_10, phi_bb154_11, phi_bb154_14, phi_bb154_15, phi_bb154_21}, &block153, std::vector<compiler::Node*>{phi_bb154_7, phi_bb154_8, phi_bb154_9, phi_bb154_10, phi_bb154_11, phi_bb154_14, phi_bb154_15, phi_bb154_21});
  }

  TNode<IntPtrT> phi_bb152_7;
  TNode<IntPtrT> phi_bb152_8;
  TNode<IntPtrT> phi_bb152_9;
  TNode<IntPtrT> phi_bb152_10;
  TNode<IntPtrT> phi_bb152_11;
  TNode<IntPtrT> phi_bb152_14;
  TNode<BoolT> phi_bb152_15;
  TNode<IntPtrT> phi_bb152_21;
  TNode<IntPtrT> tmp349;
  TNode<IntPtrT> tmp350;
  TNode<Union<HeapObject, TaggedIndex>> tmp351;
  TNode<IntPtrT> tmp352;
  TNode<Int32T> tmp353;
  TNode<Int32T> tmp354;
  TNode<BoolT> tmp355;
  if (block152.is_used()) {
    ca_.Bind(&block152, &phi_bb152_7, &phi_bb152_8, &phi_bb152_9, &phi_bb152_10, &phi_bb152_11, &phi_bb152_14, &phi_bb152_15, &phi_bb152_21);
    tmp349 = TimesSizeOf_int32_0(state_, TNode<IntPtrT>{phi_bb152_21});
    tmp350 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp118}, TNode<IntPtrT>{tmp349});
    std::tie(tmp351, tmp352) = NewReference_int32_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp117}, TNode<IntPtrT>{tmp350}).Flatten();
    tmp353 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{tmp351, tmp352});
    tmp354 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmI32.raw_bit_field());
    tmp355 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp353}, TNode<Int32T>{tmp354});
    ca_.Branch(tmp355, &block157, std::vector<compiler::Node*>{phi_bb152_7, phi_bb152_8, phi_bb152_9, phi_bb152_10, phi_bb152_11, phi_bb152_14, phi_bb152_15, phi_bb152_21}, &block158, std::vector<compiler::Node*>{phi_bb152_7, phi_bb152_8, phi_bb152_9, phi_bb152_10, phi_bb152_11, phi_bb152_14, phi_bb152_15, phi_bb152_21});
  }

  TNode<IntPtrT> phi_bb157_7;
  TNode<IntPtrT> phi_bb157_8;
  TNode<IntPtrT> phi_bb157_9;
  TNode<IntPtrT> phi_bb157_10;
  TNode<IntPtrT> phi_bb157_11;
  TNode<IntPtrT> phi_bb157_14;
  TNode<BoolT> phi_bb157_15;
  TNode<IntPtrT> phi_bb157_21;
  TNode<IntPtrT> tmp356;
  TNode<IntPtrT> tmp357;
  TNode<IntPtrT> tmp358;
  TNode<BoolT> tmp359;
  if (block157.is_used()) {
    ca_.Bind(&block157, &phi_bb157_7, &phi_bb157_8, &phi_bb157_9, &phi_bb157_10, &phi_bb157_11, &phi_bb157_14, &phi_bb157_15, &phi_bb157_21);
    tmp356 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp357 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{phi_bb157_7}, TNode<IntPtrT>{tmp356});
    tmp358 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp359 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{phi_bb157_7}, TNode<IntPtrT>{tmp358});
    ca_.Branch(tmp359, &block161, std::vector<compiler::Node*>{phi_bb157_8, phi_bb157_9, phi_bb157_10, phi_bb157_11, phi_bb157_14, phi_bb157_15, phi_bb157_21}, &block162, std::vector<compiler::Node*>{phi_bb157_8, phi_bb157_9, phi_bb157_10, phi_bb157_11, phi_bb157_14, phi_bb157_15, phi_bb157_21});
  }

  TNode<IntPtrT> phi_bb161_8;
  TNode<IntPtrT> phi_bb161_9;
  TNode<IntPtrT> phi_bb161_10;
  TNode<IntPtrT> phi_bb161_11;
  TNode<IntPtrT> phi_bb161_14;
  TNode<BoolT> phi_bb161_15;
  TNode<IntPtrT> phi_bb161_21;
  TNode<Union<HeapObject, TaggedIndex>> tmp360;
  TNode<IntPtrT> tmp361;
  TNode<IntPtrT> tmp362;
  TNode<IntPtrT> tmp363;
  if (block161.is_used()) {
    ca_.Bind(&block161, &phi_bb161_8, &phi_bb161_9, &phi_bb161_10, &phi_bb161_11, &phi_bb161_14, &phi_bb161_15, &phi_bb161_21);
    std::tie(tmp360, tmp361) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp336}, TNode<IntPtrT>{phi_bb161_9}).Flatten();
    tmp362 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp363 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb161_9}, TNode<IntPtrT>{tmp362});
    ca_.Goto(&block160, phi_bb161_8, tmp363, phi_bb161_10, phi_bb161_11, phi_bb161_14, phi_bb161_15, phi_bb161_21, tmp360, tmp361);
  }

  TNode<IntPtrT> phi_bb162_8;
  TNode<IntPtrT> phi_bb162_9;
  TNode<IntPtrT> phi_bb162_10;
  TNode<IntPtrT> phi_bb162_11;
  TNode<IntPtrT> phi_bb162_14;
  TNode<BoolT> phi_bb162_15;
  TNode<IntPtrT> phi_bb162_21;
  if (block162.is_used()) {
    ca_.Bind(&block162, &phi_bb162_8, &phi_bb162_9, &phi_bb162_10, &phi_bb162_11, &phi_bb162_14, &phi_bb162_15, &phi_bb162_21);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block164, phi_bb162_8, phi_bb162_9, phi_bb162_10, phi_bb162_11, phi_bb162_14, phi_bb162_15, phi_bb162_21);
    } else {
      ca_.Goto(&block165, phi_bb162_8, phi_bb162_9, phi_bb162_10, phi_bb162_11, phi_bb162_14, phi_bb162_15, phi_bb162_21);
    }
  }

  TNode<IntPtrT> phi_bb164_8;
  TNode<IntPtrT> phi_bb164_9;
  TNode<IntPtrT> phi_bb164_10;
  TNode<IntPtrT> phi_bb164_11;
  TNode<IntPtrT> phi_bb164_14;
  TNode<BoolT> phi_bb164_15;
  TNode<IntPtrT> phi_bb164_21;
  TNode<Union<HeapObject, TaggedIndex>> tmp364;
  TNode<IntPtrT> tmp365;
  TNode<IntPtrT> tmp366;
  TNode<IntPtrT> tmp367;
  if (block164.is_used()) {
    ca_.Bind(&block164, &phi_bb164_8, &phi_bb164_9, &phi_bb164_10, &phi_bb164_11, &phi_bb164_14, &phi_bb164_15, &phi_bb164_21);
    std::tie(tmp364, tmp365) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp336}, TNode<IntPtrT>{phi_bb164_11}).Flatten();
    tmp366 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp367 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb164_11}, TNode<IntPtrT>{tmp366});
    ca_.Goto(&block163, phi_bb164_8, phi_bb164_9, phi_bb164_10, tmp367, phi_bb164_14, phi_bb164_15, phi_bb164_21, tmp364, tmp365);
  }

  TNode<IntPtrT> phi_bb165_8;
  TNode<IntPtrT> phi_bb165_9;
  TNode<IntPtrT> phi_bb165_10;
  TNode<IntPtrT> phi_bb165_11;
  TNode<IntPtrT> phi_bb165_14;
  TNode<BoolT> phi_bb165_15;
  TNode<IntPtrT> phi_bb165_21;
  TNode<IntPtrT> tmp368;
  TNode<BoolT> tmp369;
  if (block165.is_used()) {
    ca_.Bind(&block165, &phi_bb165_8, &phi_bb165_9, &phi_bb165_10, &phi_bb165_11, &phi_bb165_14, &phi_bb165_15, &phi_bb165_21);
    tmp368 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp369 = CodeStubAssembler(state_).WordNotEqual(TNode<IntPtrT>{phi_bb165_14}, TNode<IntPtrT>{tmp368});
    ca_.Branch(tmp369, &block167, std::vector<compiler::Node*>{phi_bb165_8, phi_bb165_9, phi_bb165_10, phi_bb165_11, phi_bb165_14, phi_bb165_15, phi_bb165_21}, &block168, std::vector<compiler::Node*>{phi_bb165_8, phi_bb165_9, phi_bb165_10, phi_bb165_11, phi_bb165_14, phi_bb165_15, phi_bb165_21});
  }

  TNode<IntPtrT> phi_bb167_8;
  TNode<IntPtrT> phi_bb167_9;
  TNode<IntPtrT> phi_bb167_10;
  TNode<IntPtrT> phi_bb167_11;
  TNode<IntPtrT> phi_bb167_14;
  TNode<BoolT> phi_bb167_15;
  TNode<IntPtrT> phi_bb167_21;
  TNode<Union<HeapObject, TaggedIndex>> tmp370;
  TNode<IntPtrT> tmp371;
  TNode<IntPtrT> tmp372;
  TNode<BoolT> tmp373;
  if (block167.is_used()) {
    ca_.Bind(&block167, &phi_bb167_8, &phi_bb167_9, &phi_bb167_10, &phi_bb167_11, &phi_bb167_14, &phi_bb167_15, &phi_bb167_21);
    std::tie(tmp370, tmp371) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp336}, TNode<IntPtrT>{phi_bb167_14}).Flatten();
    tmp372 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp373 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block163, phi_bb167_8, phi_bb167_9, phi_bb167_10, phi_bb167_11, tmp372, tmp373, phi_bb167_21, tmp370, tmp371);
  }

  TNode<IntPtrT> phi_bb168_8;
  TNode<IntPtrT> phi_bb168_9;
  TNode<IntPtrT> phi_bb168_10;
  TNode<IntPtrT> phi_bb168_11;
  TNode<IntPtrT> phi_bb168_14;
  TNode<BoolT> phi_bb168_15;
  TNode<IntPtrT> phi_bb168_21;
  TNode<Union<HeapObject, TaggedIndex>> tmp374;
  TNode<IntPtrT> tmp375;
  TNode<IntPtrT> tmp376;
  TNode<IntPtrT> tmp377;
  TNode<IntPtrT> tmp378;
  TNode<IntPtrT> tmp379;
  TNode<BoolT> tmp380;
  if (block168.is_used()) {
    ca_.Bind(&block168, &phi_bb168_8, &phi_bb168_9, &phi_bb168_10, &phi_bb168_11, &phi_bb168_14, &phi_bb168_15, &phi_bb168_21);
    std::tie(tmp374, tmp375) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp336}, TNode<IntPtrT>{phi_bb168_11}).Flatten();
    tmp376 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp377 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb168_11}, TNode<IntPtrT>{tmp376});
    tmp378 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp379 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp377}, TNode<IntPtrT>{tmp378});
    tmp380 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block163, phi_bb168_8, phi_bb168_9, phi_bb168_10, tmp379, tmp377, tmp380, phi_bb168_21, tmp374, tmp375);
  }

  TNode<IntPtrT> phi_bb163_8;
  TNode<IntPtrT> phi_bb163_9;
  TNode<IntPtrT> phi_bb163_10;
  TNode<IntPtrT> phi_bb163_11;
  TNode<IntPtrT> phi_bb163_14;
  TNode<BoolT> phi_bb163_15;
  TNode<IntPtrT> phi_bb163_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb163_23;
  TNode<IntPtrT> phi_bb163_24;
  if (block163.is_used()) {
    ca_.Bind(&block163, &phi_bb163_8, &phi_bb163_9, &phi_bb163_10, &phi_bb163_11, &phi_bb163_14, &phi_bb163_15, &phi_bb163_21, &phi_bb163_23, &phi_bb163_24);
    ca_.Goto(&block160, phi_bb163_8, phi_bb163_9, phi_bb163_10, phi_bb163_11, phi_bb163_14, phi_bb163_15, phi_bb163_21, phi_bb163_23, phi_bb163_24);
  }

  TNode<IntPtrT> phi_bb160_8;
  TNode<IntPtrT> phi_bb160_9;
  TNode<IntPtrT> phi_bb160_10;
  TNode<IntPtrT> phi_bb160_11;
  TNode<IntPtrT> phi_bb160_14;
  TNode<BoolT> phi_bb160_15;
  TNode<IntPtrT> phi_bb160_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb160_23;
  TNode<IntPtrT> phi_bb160_24;
  if (block160.is_used()) {
    ca_.Bind(&block160, &phi_bb160_8, &phi_bb160_9, &phi_bb160_10, &phi_bb160_11, &phi_bb160_14, &phi_bb160_15, &phi_bb160_21, &phi_bb160_23, &phi_bb160_24);
    if ((wasm::kIsBigEndian)) {
      ca_.Goto(&block169, phi_bb160_8, phi_bb160_9, phi_bb160_10, phi_bb160_11, phi_bb160_14, phi_bb160_15, phi_bb160_21, phi_bb160_23, phi_bb160_24);
    } else {
      ca_.Goto(&block170, phi_bb160_8, phi_bb160_9, phi_bb160_10, phi_bb160_11, phi_bb160_14, phi_bb160_15, phi_bb160_21, phi_bb160_23, phi_bb160_24);
    }
  }

  TNode<IntPtrT> phi_bb169_8;
  TNode<IntPtrT> phi_bb169_9;
  TNode<IntPtrT> phi_bb169_10;
  TNode<IntPtrT> phi_bb169_11;
  TNode<IntPtrT> phi_bb169_14;
  TNode<BoolT> phi_bb169_15;
  TNode<IntPtrT> phi_bb169_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb169_23;
  TNode<IntPtrT> phi_bb169_24;
  TNode<Union<HeapObject, TaggedIndex>> tmp381;
  TNode<IntPtrT> tmp382;
  TNode<Int64T> tmp383;
  TNode<Int32T> tmp384;
  if (block169.is_used()) {
    ca_.Bind(&block169, &phi_bb169_8, &phi_bb169_9, &phi_bb169_10, &phi_bb169_11, &phi_bb169_14, &phi_bb169_15, &phi_bb169_21, &phi_bb169_23, &phi_bb169_24);
    std::tie(tmp381, tmp382) = RefCast_int64_0(state_, TorqueStructReference_intptr_0{TNode<Union<HeapObject, TaggedIndex>>{phi_bb169_23}, TNode<IntPtrT>{phi_bb169_24}, TorqueStructUnsafe_0{}}).Flatten();
    tmp383 = CodeStubAssembler(state_).LoadReference<Int64T>(CodeStubAssembler::Reference{tmp381, tmp382});
    tmp384 = CodeStubAssembler(state_).TruncateInt64ToInt32(TNode<Int64T>{tmp383});
    ca_.Goto(&block171, phi_bb169_8, phi_bb169_9, phi_bb169_10, phi_bb169_11, phi_bb169_14, phi_bb169_15, phi_bb169_21, phi_bb169_23, phi_bb169_24, tmp384);
  }

  TNode<IntPtrT> phi_bb170_8;
  TNode<IntPtrT> phi_bb170_9;
  TNode<IntPtrT> phi_bb170_10;
  TNode<IntPtrT> phi_bb170_11;
  TNode<IntPtrT> phi_bb170_14;
  TNode<BoolT> phi_bb170_15;
  TNode<IntPtrT> phi_bb170_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb170_23;
  TNode<IntPtrT> phi_bb170_24;
  TNode<Union<HeapObject, TaggedIndex>> tmp385;
  TNode<IntPtrT> tmp386;
  TNode<Int32T> tmp387;
  if (block170.is_used()) {
    ca_.Bind(&block170, &phi_bb170_8, &phi_bb170_9, &phi_bb170_10, &phi_bb170_11, &phi_bb170_14, &phi_bb170_15, &phi_bb170_21, &phi_bb170_23, &phi_bb170_24);
    std::tie(tmp385, tmp386) = RefCast_int32_0(state_, TorqueStructReference_intptr_0{TNode<Union<HeapObject, TaggedIndex>>{phi_bb170_23}, TNode<IntPtrT>{phi_bb170_24}, TorqueStructUnsafe_0{}}).Flatten();
    tmp387 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{tmp385, tmp386});
    ca_.Goto(&block171, phi_bb170_8, phi_bb170_9, phi_bb170_10, phi_bb170_11, phi_bb170_14, phi_bb170_15, phi_bb170_21, phi_bb170_23, phi_bb170_24, tmp387);
  }

  TNode<IntPtrT> phi_bb171_8;
  TNode<IntPtrT> phi_bb171_9;
  TNode<IntPtrT> phi_bb171_10;
  TNode<IntPtrT> phi_bb171_11;
  TNode<IntPtrT> phi_bb171_14;
  TNode<BoolT> phi_bb171_15;
  TNode<IntPtrT> phi_bb171_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb171_23;
  TNode<IntPtrT> phi_bb171_24;
  TNode<Int32T> phi_bb171_25;
  TNode<Union<HeapObject, TaggedIndex>> tmp388;
  TNode<IntPtrT> tmp389;
  TNode<IntPtrT> tmp390;
  TNode<UintPtrT> tmp391;
  TNode<UintPtrT> tmp392;
  TNode<BoolT> tmp393;
  if (block171.is_used()) {
    ca_.Bind(&block171, &phi_bb171_8, &phi_bb171_9, &phi_bb171_10, &phi_bb171_11, &phi_bb171_14, &phi_bb171_15, &phi_bb171_21, &phi_bb171_23, &phi_bb171_24, &phi_bb171_25);
    std::tie(tmp388, tmp389, tmp390) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{tmp92}).Flatten();
    tmp391 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{phi_bb171_21});
    tmp392 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp390});
    tmp393 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp391}, TNode<UintPtrT>{tmp392});
    ca_.Branch(tmp393, &block176, std::vector<compiler::Node*>{phi_bb171_8, phi_bb171_9, phi_bb171_10, phi_bb171_11, phi_bb171_14, phi_bb171_15, phi_bb171_21, phi_bb171_23, phi_bb171_24, phi_bb171_21, phi_bb171_21, phi_bb171_21, phi_bb171_21}, &block177, std::vector<compiler::Node*>{phi_bb171_8, phi_bb171_9, phi_bb171_10, phi_bb171_11, phi_bb171_14, phi_bb171_15, phi_bb171_21, phi_bb171_23, phi_bb171_24, phi_bb171_21, phi_bb171_21, phi_bb171_21, phi_bb171_21});
  }

  TNode<IntPtrT> phi_bb176_8;
  TNode<IntPtrT> phi_bb176_9;
  TNode<IntPtrT> phi_bb176_10;
  TNode<IntPtrT> phi_bb176_11;
  TNode<IntPtrT> phi_bb176_14;
  TNode<BoolT> phi_bb176_15;
  TNode<IntPtrT> phi_bb176_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb176_23;
  TNode<IntPtrT> phi_bb176_24;
  TNode<IntPtrT> phi_bb176_30;
  TNode<IntPtrT> phi_bb176_31;
  TNode<IntPtrT> phi_bb176_35;
  TNode<IntPtrT> phi_bb176_36;
  TNode<IntPtrT> tmp394;
  TNode<IntPtrT> tmp395;
  TNode<Union<HeapObject, TaggedIndex>> tmp396;
  TNode<IntPtrT> tmp397;
  TNode<Number> tmp398;
  if (block176.is_used()) {
    ca_.Bind(&block176, &phi_bb176_8, &phi_bb176_9, &phi_bb176_10, &phi_bb176_11, &phi_bb176_14, &phi_bb176_15, &phi_bb176_21, &phi_bb176_23, &phi_bb176_24, &phi_bb176_30, &phi_bb176_31, &phi_bb176_35, &phi_bb176_36);
    tmp394 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{phi_bb176_36});
    tmp395 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp389}, TNode<IntPtrT>{tmp394});
    std::tie(tmp396, tmp397) = NewReference_Object_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp388}, TNode<IntPtrT>{tmp395}).Flatten();
    tmp398 = Convert_Number_int32_0(state_, TNode<Int32T>{phi_bb171_25});
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp396, tmp397}, tmp398);
    ca_.Goto(&block159, tmp357, phi_bb176_8, phi_bb176_9, phi_bb176_10, phi_bb176_11, phi_bb176_14, phi_bb176_15, phi_bb176_21);
  }

  TNode<IntPtrT> phi_bb177_8;
  TNode<IntPtrT> phi_bb177_9;
  TNode<IntPtrT> phi_bb177_10;
  TNode<IntPtrT> phi_bb177_11;
  TNode<IntPtrT> phi_bb177_14;
  TNode<BoolT> phi_bb177_15;
  TNode<IntPtrT> phi_bb177_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb177_23;
  TNode<IntPtrT> phi_bb177_24;
  TNode<IntPtrT> phi_bb177_30;
  TNode<IntPtrT> phi_bb177_31;
  TNode<IntPtrT> phi_bb177_35;
  TNode<IntPtrT> phi_bb177_36;
  if (block177.is_used()) {
    ca_.Bind(&block177, &phi_bb177_8, &phi_bb177_9, &phi_bb177_10, &phi_bb177_11, &phi_bb177_14, &phi_bb177_15, &phi_bb177_21, &phi_bb177_23, &phi_bb177_24, &phi_bb177_30, &phi_bb177_31, &phi_bb177_35, &phi_bb177_36);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> phi_bb158_7;
  TNode<IntPtrT> phi_bb158_8;
  TNode<IntPtrT> phi_bb158_9;
  TNode<IntPtrT> phi_bb158_10;
  TNode<IntPtrT> phi_bb158_11;
  TNode<IntPtrT> phi_bb158_14;
  TNode<BoolT> phi_bb158_15;
  TNode<IntPtrT> phi_bb158_21;
  TNode<Int32T> tmp399;
  TNode<BoolT> tmp400;
  if (block158.is_used()) {
    ca_.Bind(&block158, &phi_bb158_7, &phi_bb158_8, &phi_bb158_9, &phi_bb158_10, &phi_bb158_11, &phi_bb158_14, &phi_bb158_15, &phi_bb158_21);
    tmp399 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmF32.raw_bit_field());
    tmp400 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp353}, TNode<Int32T>{tmp399});
    ca_.Branch(tmp400, &block180, std::vector<compiler::Node*>{phi_bb158_7, phi_bb158_8, phi_bb158_9, phi_bb158_10, phi_bb158_11, phi_bb158_14, phi_bb158_15, phi_bb158_21}, &block181, std::vector<compiler::Node*>{phi_bb158_7, phi_bb158_8, phi_bb158_9, phi_bb158_10, phi_bb158_11, phi_bb158_14, phi_bb158_15, phi_bb158_21});
  }

  TNode<IntPtrT> phi_bb180_7;
  TNode<IntPtrT> phi_bb180_8;
  TNode<IntPtrT> phi_bb180_9;
  TNode<IntPtrT> phi_bb180_10;
  TNode<IntPtrT> phi_bb180_11;
  TNode<IntPtrT> phi_bb180_14;
  TNode<BoolT> phi_bb180_15;
  TNode<IntPtrT> phi_bb180_21;
  TNode<IntPtrT> tmp401;
  TNode<IntPtrT> tmp402;
  TNode<IntPtrT> tmp403;
  TNode<BoolT> tmp404;
  if (block180.is_used()) {
    ca_.Bind(&block180, &phi_bb180_7, &phi_bb180_8, &phi_bb180_9, &phi_bb180_10, &phi_bb180_11, &phi_bb180_14, &phi_bb180_15, &phi_bb180_21);
    tmp401 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp402 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{phi_bb180_8}, TNode<IntPtrT>{tmp401});
    tmp403 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp404 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{phi_bb180_8}, TNode<IntPtrT>{tmp403});
    ca_.Branch(tmp404, &block184, std::vector<compiler::Node*>{phi_bb180_7, phi_bb180_9, phi_bb180_10, phi_bb180_11, phi_bb180_14, phi_bb180_15, phi_bb180_21}, &block185, std::vector<compiler::Node*>{phi_bb180_7, phi_bb180_9, phi_bb180_10, phi_bb180_11, phi_bb180_14, phi_bb180_15, phi_bb180_21});
  }

  TNode<IntPtrT> phi_bb184_7;
  TNode<IntPtrT> phi_bb184_9;
  TNode<IntPtrT> phi_bb184_10;
  TNode<IntPtrT> phi_bb184_11;
  TNode<IntPtrT> phi_bb184_14;
  TNode<BoolT> phi_bb184_15;
  TNode<IntPtrT> phi_bb184_21;
  TNode<Union<HeapObject, TaggedIndex>> tmp405;
  TNode<IntPtrT> tmp406;
  TNode<IntPtrT> tmp407;
  TNode<IntPtrT> tmp408;
  if (block184.is_used()) {
    ca_.Bind(&block184, &phi_bb184_7, &phi_bb184_9, &phi_bb184_10, &phi_bb184_11, &phi_bb184_14, &phi_bb184_15, &phi_bb184_21);
    std::tie(tmp405, tmp406) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp336}, TNode<IntPtrT>{phi_bb184_10}).Flatten();
    tmp407 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_float64_0(state_)));
    tmp408 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb184_10}, TNode<IntPtrT>{tmp407});
    ca_.Goto(&block183, phi_bb184_7, phi_bb184_9, tmp408, phi_bb184_11, phi_bb184_14, phi_bb184_15, phi_bb184_21, tmp405, tmp406);
  }

  TNode<IntPtrT> phi_bb185_7;
  TNode<IntPtrT> phi_bb185_9;
  TNode<IntPtrT> phi_bb185_10;
  TNode<IntPtrT> phi_bb185_11;
  TNode<IntPtrT> phi_bb185_14;
  TNode<BoolT> phi_bb185_15;
  TNode<IntPtrT> phi_bb185_21;
  if (block185.is_used()) {
    ca_.Bind(&block185, &phi_bb185_7, &phi_bb185_9, &phi_bb185_10, &phi_bb185_11, &phi_bb185_14, &phi_bb185_15, &phi_bb185_21);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block187, phi_bb185_7, phi_bb185_9, phi_bb185_10, phi_bb185_11, phi_bb185_14, phi_bb185_15, phi_bb185_21);
    } else {
      ca_.Goto(&block188, phi_bb185_7, phi_bb185_9, phi_bb185_10, phi_bb185_11, phi_bb185_14, phi_bb185_15, phi_bb185_21);
    }
  }

  TNode<IntPtrT> phi_bb187_7;
  TNode<IntPtrT> phi_bb187_9;
  TNode<IntPtrT> phi_bb187_10;
  TNode<IntPtrT> phi_bb187_11;
  TNode<IntPtrT> phi_bb187_14;
  TNode<BoolT> phi_bb187_15;
  TNode<IntPtrT> phi_bb187_21;
  TNode<Union<HeapObject, TaggedIndex>> tmp409;
  TNode<IntPtrT> tmp410;
  TNode<IntPtrT> tmp411;
  TNode<IntPtrT> tmp412;
  if (block187.is_used()) {
    ca_.Bind(&block187, &phi_bb187_7, &phi_bb187_9, &phi_bb187_10, &phi_bb187_11, &phi_bb187_14, &phi_bb187_15, &phi_bb187_21);
    std::tie(tmp409, tmp410) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp336}, TNode<IntPtrT>{phi_bb187_11}).Flatten();
    tmp411 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp412 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb187_11}, TNode<IntPtrT>{tmp411});
    ca_.Goto(&block186, phi_bb187_7, phi_bb187_9, phi_bb187_10, tmp412, phi_bb187_14, phi_bb187_15, phi_bb187_21, tmp409, tmp410);
  }

  TNode<IntPtrT> phi_bb188_7;
  TNode<IntPtrT> phi_bb188_9;
  TNode<IntPtrT> phi_bb188_10;
  TNode<IntPtrT> phi_bb188_11;
  TNode<IntPtrT> phi_bb188_14;
  TNode<BoolT> phi_bb188_15;
  TNode<IntPtrT> phi_bb188_21;
  TNode<IntPtrT> tmp413;
  TNode<BoolT> tmp414;
  if (block188.is_used()) {
    ca_.Bind(&block188, &phi_bb188_7, &phi_bb188_9, &phi_bb188_10, &phi_bb188_11, &phi_bb188_14, &phi_bb188_15, &phi_bb188_21);
    tmp413 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp414 = CodeStubAssembler(state_).WordNotEqual(TNode<IntPtrT>{phi_bb188_14}, TNode<IntPtrT>{tmp413});
    ca_.Branch(tmp414, &block190, std::vector<compiler::Node*>{phi_bb188_7, phi_bb188_9, phi_bb188_10, phi_bb188_11, phi_bb188_14, phi_bb188_15, phi_bb188_21}, &block191, std::vector<compiler::Node*>{phi_bb188_7, phi_bb188_9, phi_bb188_10, phi_bb188_11, phi_bb188_14, phi_bb188_15, phi_bb188_21});
  }

  TNode<IntPtrT> phi_bb190_7;
  TNode<IntPtrT> phi_bb190_9;
  TNode<IntPtrT> phi_bb190_10;
  TNode<IntPtrT> phi_bb190_11;
  TNode<IntPtrT> phi_bb190_14;
  TNode<BoolT> phi_bb190_15;
  TNode<IntPtrT> phi_bb190_21;
  TNode<Union<HeapObject, TaggedIndex>> tmp415;
  TNode<IntPtrT> tmp416;
  TNode<IntPtrT> tmp417;
  TNode<BoolT> tmp418;
  if (block190.is_used()) {
    ca_.Bind(&block190, &phi_bb190_7, &phi_bb190_9, &phi_bb190_10, &phi_bb190_11, &phi_bb190_14, &phi_bb190_15, &phi_bb190_21);
    std::tie(tmp415, tmp416) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp336}, TNode<IntPtrT>{phi_bb190_14}).Flatten();
    tmp417 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp418 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block186, phi_bb190_7, phi_bb190_9, phi_bb190_10, phi_bb190_11, tmp417, tmp418, phi_bb190_21, tmp415, tmp416);
  }

  TNode<IntPtrT> phi_bb191_7;
  TNode<IntPtrT> phi_bb191_9;
  TNode<IntPtrT> phi_bb191_10;
  TNode<IntPtrT> phi_bb191_11;
  TNode<IntPtrT> phi_bb191_14;
  TNode<BoolT> phi_bb191_15;
  TNode<IntPtrT> phi_bb191_21;
  TNode<Union<HeapObject, TaggedIndex>> tmp419;
  TNode<IntPtrT> tmp420;
  TNode<IntPtrT> tmp421;
  TNode<IntPtrT> tmp422;
  TNode<IntPtrT> tmp423;
  TNode<IntPtrT> tmp424;
  TNode<BoolT> tmp425;
  if (block191.is_used()) {
    ca_.Bind(&block191, &phi_bb191_7, &phi_bb191_9, &phi_bb191_10, &phi_bb191_11, &phi_bb191_14, &phi_bb191_15, &phi_bb191_21);
    std::tie(tmp419, tmp420) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp336}, TNode<IntPtrT>{phi_bb191_11}).Flatten();
    tmp421 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp422 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb191_11}, TNode<IntPtrT>{tmp421});
    tmp423 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp424 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp422}, TNode<IntPtrT>{tmp423});
    tmp425 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block186, phi_bb191_7, phi_bb191_9, phi_bb191_10, tmp424, tmp422, tmp425, phi_bb191_21, tmp419, tmp420);
  }

  TNode<IntPtrT> phi_bb186_7;
  TNode<IntPtrT> phi_bb186_9;
  TNode<IntPtrT> phi_bb186_10;
  TNode<IntPtrT> phi_bb186_11;
  TNode<IntPtrT> phi_bb186_14;
  TNode<BoolT> phi_bb186_15;
  TNode<IntPtrT> phi_bb186_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb186_23;
  TNode<IntPtrT> phi_bb186_24;
  if (block186.is_used()) {
    ca_.Bind(&block186, &phi_bb186_7, &phi_bb186_9, &phi_bb186_10, &phi_bb186_11, &phi_bb186_14, &phi_bb186_15, &phi_bb186_21, &phi_bb186_23, &phi_bb186_24);
    ca_.Goto(&block183, phi_bb186_7, phi_bb186_9, phi_bb186_10, phi_bb186_11, phi_bb186_14, phi_bb186_15, phi_bb186_21, phi_bb186_23, phi_bb186_24);
  }

  TNode<IntPtrT> phi_bb183_7;
  TNode<IntPtrT> phi_bb183_9;
  TNode<IntPtrT> phi_bb183_10;
  TNode<IntPtrT> phi_bb183_11;
  TNode<IntPtrT> phi_bb183_14;
  TNode<BoolT> phi_bb183_15;
  TNode<IntPtrT> phi_bb183_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb183_23;
  TNode<IntPtrT> phi_bb183_24;
  if (block183.is_used()) {
    ca_.Bind(&block183, &phi_bb183_7, &phi_bb183_9, &phi_bb183_10, &phi_bb183_11, &phi_bb183_14, &phi_bb183_15, &phi_bb183_21, &phi_bb183_23, &phi_bb183_24);
    if ((wasm::kIsFpAlwaysDouble)) {
      ca_.Goto(&block192, phi_bb183_7, phi_bb183_9, phi_bb183_10, phi_bb183_11, phi_bb183_14, phi_bb183_15, phi_bb183_21, phi_bb183_23, phi_bb183_24);
    } else {
      ca_.Goto(&block193, phi_bb183_7, phi_bb183_9, phi_bb183_10, phi_bb183_11, phi_bb183_14, phi_bb183_15, phi_bb183_21, phi_bb183_23, phi_bb183_24);
    }
  }

  TNode<IntPtrT> phi_bb192_7;
  TNode<IntPtrT> phi_bb192_9;
  TNode<IntPtrT> phi_bb192_10;
  TNode<IntPtrT> phi_bb192_11;
  TNode<IntPtrT> phi_bb192_14;
  TNode<BoolT> phi_bb192_15;
  TNode<IntPtrT> phi_bb192_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb192_23;
  TNode<IntPtrT> phi_bb192_24;
  TNode<IntPtrT> tmp426;
  TNode<BoolT> tmp427;
  if (block192.is_used()) {
    ca_.Bind(&block192, &phi_bb192_7, &phi_bb192_9, &phi_bb192_10, &phi_bb192_11, &phi_bb192_14, &phi_bb192_15, &phi_bb192_21, &phi_bb192_23, &phi_bb192_24);
    tmp426 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp427 = CodeStubAssembler(state_).IntPtrGreaterThanOrEqual(TNode<IntPtrT>{tmp402}, TNode<IntPtrT>{tmp426});
    ca_.Branch(tmp427, &block195, std::vector<compiler::Node*>{phi_bb192_7, phi_bb192_9, phi_bb192_10, phi_bb192_11, phi_bb192_14, phi_bb192_15, phi_bb192_21, phi_bb192_23, phi_bb192_24}, &block196, std::vector<compiler::Node*>{phi_bb192_7, phi_bb192_9, phi_bb192_10, phi_bb192_11, phi_bb192_14, phi_bb192_15, phi_bb192_21, phi_bb192_23, phi_bb192_24});
  }

  TNode<IntPtrT> phi_bb195_7;
  TNode<IntPtrT> phi_bb195_9;
  TNode<IntPtrT> phi_bb195_10;
  TNode<IntPtrT> phi_bb195_11;
  TNode<IntPtrT> phi_bb195_14;
  TNode<BoolT> phi_bb195_15;
  TNode<IntPtrT> phi_bb195_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb195_23;
  TNode<IntPtrT> phi_bb195_24;
  TNode<Union<HeapObject, TaggedIndex>> tmp428;
  TNode<IntPtrT> tmp429;
  TNode<Float64T> tmp430;
  TNode<Float32T> tmp431;
  if (block195.is_used()) {
    ca_.Bind(&block195, &phi_bb195_7, &phi_bb195_9, &phi_bb195_10, &phi_bb195_11, &phi_bb195_14, &phi_bb195_15, &phi_bb195_21, &phi_bb195_23, &phi_bb195_24);
    std::tie(tmp428, tmp429) = RefCast_float64_0(state_, TorqueStructReference_intptr_0{TNode<Union<HeapObject, TaggedIndex>>{phi_bb195_23}, TNode<IntPtrT>{phi_bb195_24}, TorqueStructUnsafe_0{}}).Flatten();
    tmp430 = CodeStubAssembler(state_).LoadReference<Float64T>(CodeStubAssembler::Reference{tmp428, tmp429});
    tmp431 = CodeStubAssembler(state_).TruncateFloat64ToFloat32(TNode<Float64T>{tmp430});
    ca_.Goto(&block198, phi_bb195_7, phi_bb195_9, phi_bb195_10, phi_bb195_11, phi_bb195_14, phi_bb195_15, phi_bb195_21, phi_bb195_23, phi_bb195_24, tmp431);
  }

  TNode<IntPtrT> phi_bb196_7;
  TNode<IntPtrT> phi_bb196_9;
  TNode<IntPtrT> phi_bb196_10;
  TNode<IntPtrT> phi_bb196_11;
  TNode<IntPtrT> phi_bb196_14;
  TNode<BoolT> phi_bb196_15;
  TNode<IntPtrT> phi_bb196_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb196_23;
  TNode<IntPtrT> phi_bb196_24;
  TNode<Union<HeapObject, TaggedIndex>> tmp432;
  TNode<IntPtrT> tmp433;
  TNode<Float32T> tmp434;
  if (block196.is_used()) {
    ca_.Bind(&block196, &phi_bb196_7, &phi_bb196_9, &phi_bb196_10, &phi_bb196_11, &phi_bb196_14, &phi_bb196_15, &phi_bb196_21, &phi_bb196_23, &phi_bb196_24);
    std::tie(tmp432, tmp433) = RefCast_float32_0(state_, TorqueStructReference_intptr_0{TNode<Union<HeapObject, TaggedIndex>>{phi_bb196_23}, TNode<IntPtrT>{phi_bb196_24}, TorqueStructUnsafe_0{}}).Flatten();
    tmp434 = CodeStubAssembler(state_).LoadReference<Float32T>(CodeStubAssembler::Reference{tmp432, tmp433});
    ca_.Goto(&block198, phi_bb196_7, phi_bb196_9, phi_bb196_10, phi_bb196_11, phi_bb196_14, phi_bb196_15, phi_bb196_21, phi_bb196_23, phi_bb196_24, tmp434);
  }

  TNode<IntPtrT> phi_bb198_7;
  TNode<IntPtrT> phi_bb198_9;
  TNode<IntPtrT> phi_bb198_10;
  TNode<IntPtrT> phi_bb198_11;
  TNode<IntPtrT> phi_bb198_14;
  TNode<BoolT> phi_bb198_15;
  TNode<IntPtrT> phi_bb198_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb198_23;
  TNode<IntPtrT> phi_bb198_24;
  TNode<Float32T> phi_bb198_25;
  if (block198.is_used()) {
    ca_.Bind(&block198, &phi_bb198_7, &phi_bb198_9, &phi_bb198_10, &phi_bb198_11, &phi_bb198_14, &phi_bb198_15, &phi_bb198_21, &phi_bb198_23, &phi_bb198_24, &phi_bb198_25);
    ca_.Goto(&block194, phi_bb198_7, phi_bb198_9, phi_bb198_10, phi_bb198_11, phi_bb198_14, phi_bb198_15, phi_bb198_21, phi_bb198_23, phi_bb198_24, phi_bb198_25);
  }

  TNode<IntPtrT> phi_bb193_7;
  TNode<IntPtrT> phi_bb193_9;
  TNode<IntPtrT> phi_bb193_10;
  TNode<IntPtrT> phi_bb193_11;
  TNode<IntPtrT> phi_bb193_14;
  TNode<BoolT> phi_bb193_15;
  TNode<IntPtrT> phi_bb193_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb193_23;
  TNode<IntPtrT> phi_bb193_24;
  if (block193.is_used()) {
    ca_.Bind(&block193, &phi_bb193_7, &phi_bb193_9, &phi_bb193_10, &phi_bb193_11, &phi_bb193_14, &phi_bb193_15, &phi_bb193_21, &phi_bb193_23, &phi_bb193_24);
    if ((wasm::kIsBigEndianOnSim)) {
      ca_.Goto(&block199, phi_bb193_7, phi_bb193_9, phi_bb193_10, phi_bb193_11, phi_bb193_14, phi_bb193_15, phi_bb193_21, phi_bb193_23, phi_bb193_24);
    } else {
      ca_.Goto(&block200, phi_bb193_7, phi_bb193_9, phi_bb193_10, phi_bb193_11, phi_bb193_14, phi_bb193_15, phi_bb193_21, phi_bb193_23, phi_bb193_24);
    }
  }

  TNode<IntPtrT> phi_bb199_7;
  TNode<IntPtrT> phi_bb199_9;
  TNode<IntPtrT> phi_bb199_10;
  TNode<IntPtrT> phi_bb199_11;
  TNode<IntPtrT> phi_bb199_14;
  TNode<BoolT> phi_bb199_15;
  TNode<IntPtrT> phi_bb199_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb199_23;
  TNode<IntPtrT> phi_bb199_24;
  TNode<IntPtrT> tmp435;
  TNode<BoolT> tmp436;
  if (block199.is_used()) {
    ca_.Bind(&block199, &phi_bb199_7, &phi_bb199_9, &phi_bb199_10, &phi_bb199_11, &phi_bb199_14, &phi_bb199_15, &phi_bb199_21, &phi_bb199_23, &phi_bb199_24);
    tmp435 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp436 = CodeStubAssembler(state_).IntPtrGreaterThanOrEqual(TNode<IntPtrT>{tmp402}, TNode<IntPtrT>{tmp435});
    ca_.Branch(tmp436, &block202, std::vector<compiler::Node*>{phi_bb199_7, phi_bb199_9, phi_bb199_10, phi_bb199_11, phi_bb199_14, phi_bb199_15, phi_bb199_21, phi_bb199_23, phi_bb199_24}, &block203, std::vector<compiler::Node*>{phi_bb199_7, phi_bb199_9, phi_bb199_10, phi_bb199_11, phi_bb199_14, phi_bb199_15, phi_bb199_21, phi_bb199_23, phi_bb199_24});
  }

  TNode<IntPtrT> phi_bb202_7;
  TNode<IntPtrT> phi_bb202_9;
  TNode<IntPtrT> phi_bb202_10;
  TNode<IntPtrT> phi_bb202_11;
  TNode<IntPtrT> phi_bb202_14;
  TNode<BoolT> phi_bb202_15;
  TNode<IntPtrT> phi_bb202_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb202_23;
  TNode<IntPtrT> phi_bb202_24;
  TNode<Union<HeapObject, TaggedIndex>> tmp437;
  TNode<IntPtrT> tmp438;
  TNode<Int64T> tmp439;
  TNode<Int64T> tmp440;
  TNode<Int64T> tmp441;
  TNode<Int32T> tmp442;
  TNode<Float32T> tmp443;
  if (block202.is_used()) {
    ca_.Bind(&block202, &phi_bb202_7, &phi_bb202_9, &phi_bb202_10, &phi_bb202_11, &phi_bb202_14, &phi_bb202_15, &phi_bb202_21, &phi_bb202_23, &phi_bb202_24);
    std::tie(tmp437, tmp438) = RefCast_int64_0(state_, TorqueStructReference_intptr_0{TNode<Union<HeapObject, TaggedIndex>>{phi_bb202_23}, TNode<IntPtrT>{phi_bb202_24}, TorqueStructUnsafe_0{}}).Flatten();
    tmp439 = CodeStubAssembler(state_).LoadReference<Int64T>(CodeStubAssembler::Reference{tmp437, tmp438});
    tmp440 = FromConstexpr_int64_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x20ull));
    tmp441 = CodeStubAssembler(state_).Word64Sar(TNode<Int64T>{tmp439}, TNode<Int64T>{tmp440});
    tmp442 = CodeStubAssembler(state_).TruncateInt64ToInt32(TNode<Int64T>{tmp441});
    tmp443 = CodeStubAssembler(state_).BitcastInt32ToFloat32(TNode<Int32T>{tmp442});
    ca_.Goto(&block205, phi_bb202_7, phi_bb202_9, phi_bb202_10, phi_bb202_11, phi_bb202_14, phi_bb202_15, phi_bb202_21, phi_bb202_23, phi_bb202_24, tmp443);
  }

  TNode<IntPtrT> phi_bb203_7;
  TNode<IntPtrT> phi_bb203_9;
  TNode<IntPtrT> phi_bb203_10;
  TNode<IntPtrT> phi_bb203_11;
  TNode<IntPtrT> phi_bb203_14;
  TNode<BoolT> phi_bb203_15;
  TNode<IntPtrT> phi_bb203_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb203_23;
  TNode<IntPtrT> phi_bb203_24;
  TNode<Union<HeapObject, TaggedIndex>> tmp444;
  TNode<IntPtrT> tmp445;
  TNode<Float32T> tmp446;
  if (block203.is_used()) {
    ca_.Bind(&block203, &phi_bb203_7, &phi_bb203_9, &phi_bb203_10, &phi_bb203_11, &phi_bb203_14, &phi_bb203_15, &phi_bb203_21, &phi_bb203_23, &phi_bb203_24);
    std::tie(tmp444, tmp445) = RefCast_float32_0(state_, TorqueStructReference_intptr_0{TNode<Union<HeapObject, TaggedIndex>>{phi_bb203_23}, TNode<IntPtrT>{phi_bb203_24}, TorqueStructUnsafe_0{}}).Flatten();
    tmp446 = CodeStubAssembler(state_).LoadReference<Float32T>(CodeStubAssembler::Reference{tmp444, tmp445});
    ca_.Goto(&block205, phi_bb203_7, phi_bb203_9, phi_bb203_10, phi_bb203_11, phi_bb203_14, phi_bb203_15, phi_bb203_21, phi_bb203_23, phi_bb203_24, tmp446);
  }

  TNode<IntPtrT> phi_bb205_7;
  TNode<IntPtrT> phi_bb205_9;
  TNode<IntPtrT> phi_bb205_10;
  TNode<IntPtrT> phi_bb205_11;
  TNode<IntPtrT> phi_bb205_14;
  TNode<BoolT> phi_bb205_15;
  TNode<IntPtrT> phi_bb205_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb205_23;
  TNode<IntPtrT> phi_bb205_24;
  TNode<Float32T> phi_bb205_25;
  if (block205.is_used()) {
    ca_.Bind(&block205, &phi_bb205_7, &phi_bb205_9, &phi_bb205_10, &phi_bb205_11, &phi_bb205_14, &phi_bb205_15, &phi_bb205_21, &phi_bb205_23, &phi_bb205_24, &phi_bb205_25);
    ca_.Goto(&block201, phi_bb205_7, phi_bb205_9, phi_bb205_10, phi_bb205_11, phi_bb205_14, phi_bb205_15, phi_bb205_21, phi_bb205_23, phi_bb205_24, phi_bb205_25);
  }

  TNode<IntPtrT> phi_bb200_7;
  TNode<IntPtrT> phi_bb200_9;
  TNode<IntPtrT> phi_bb200_10;
  TNode<IntPtrT> phi_bb200_11;
  TNode<IntPtrT> phi_bb200_14;
  TNode<BoolT> phi_bb200_15;
  TNode<IntPtrT> phi_bb200_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb200_23;
  TNode<IntPtrT> phi_bb200_24;
  TNode<Union<HeapObject, TaggedIndex>> tmp447;
  TNode<IntPtrT> tmp448;
  TNode<Float32T> tmp449;
  if (block200.is_used()) {
    ca_.Bind(&block200, &phi_bb200_7, &phi_bb200_9, &phi_bb200_10, &phi_bb200_11, &phi_bb200_14, &phi_bb200_15, &phi_bb200_21, &phi_bb200_23, &phi_bb200_24);
    std::tie(tmp447, tmp448) = RefCast_float32_0(state_, TorqueStructReference_intptr_0{TNode<Union<HeapObject, TaggedIndex>>{phi_bb200_23}, TNode<IntPtrT>{phi_bb200_24}, TorqueStructUnsafe_0{}}).Flatten();
    tmp449 = CodeStubAssembler(state_).LoadReference<Float32T>(CodeStubAssembler::Reference{tmp447, tmp448});
    ca_.Goto(&block201, phi_bb200_7, phi_bb200_9, phi_bb200_10, phi_bb200_11, phi_bb200_14, phi_bb200_15, phi_bb200_21, phi_bb200_23, phi_bb200_24, tmp449);
  }

  TNode<IntPtrT> phi_bb201_7;
  TNode<IntPtrT> phi_bb201_9;
  TNode<IntPtrT> phi_bb201_10;
  TNode<IntPtrT> phi_bb201_11;
  TNode<IntPtrT> phi_bb201_14;
  TNode<BoolT> phi_bb201_15;
  TNode<IntPtrT> phi_bb201_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb201_23;
  TNode<IntPtrT> phi_bb201_24;
  TNode<Float32T> phi_bb201_25;
  if (block201.is_used()) {
    ca_.Bind(&block201, &phi_bb201_7, &phi_bb201_9, &phi_bb201_10, &phi_bb201_11, &phi_bb201_14, &phi_bb201_15, &phi_bb201_21, &phi_bb201_23, &phi_bb201_24, &phi_bb201_25);
    ca_.Goto(&block194, phi_bb201_7, phi_bb201_9, phi_bb201_10, phi_bb201_11, phi_bb201_14, phi_bb201_15, phi_bb201_21, phi_bb201_23, phi_bb201_24, phi_bb201_25);
  }

  TNode<IntPtrT> phi_bb194_7;
  TNode<IntPtrT> phi_bb194_9;
  TNode<IntPtrT> phi_bb194_10;
  TNode<IntPtrT> phi_bb194_11;
  TNode<IntPtrT> phi_bb194_14;
  TNode<BoolT> phi_bb194_15;
  TNode<IntPtrT> phi_bb194_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb194_23;
  TNode<IntPtrT> phi_bb194_24;
  TNode<Float32T> phi_bb194_25;
  TNode<Union<HeapObject, TaggedIndex>> tmp450;
  TNode<IntPtrT> tmp451;
  TNode<IntPtrT> tmp452;
  TNode<UintPtrT> tmp453;
  TNode<UintPtrT> tmp454;
  TNode<BoolT> tmp455;
  if (block194.is_used()) {
    ca_.Bind(&block194, &phi_bb194_7, &phi_bb194_9, &phi_bb194_10, &phi_bb194_11, &phi_bb194_14, &phi_bb194_15, &phi_bb194_21, &phi_bb194_23, &phi_bb194_24, &phi_bb194_25);
    std::tie(tmp450, tmp451, tmp452) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{tmp92}).Flatten();
    tmp453 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{phi_bb194_21});
    tmp454 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp452});
    tmp455 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp453}, TNode<UintPtrT>{tmp454});
    ca_.Branch(tmp455, &block210, std::vector<compiler::Node*>{phi_bb194_7, phi_bb194_9, phi_bb194_10, phi_bb194_11, phi_bb194_14, phi_bb194_15, phi_bb194_21, phi_bb194_23, phi_bb194_24, phi_bb194_21, phi_bb194_21, phi_bb194_21, phi_bb194_21}, &block211, std::vector<compiler::Node*>{phi_bb194_7, phi_bb194_9, phi_bb194_10, phi_bb194_11, phi_bb194_14, phi_bb194_15, phi_bb194_21, phi_bb194_23, phi_bb194_24, phi_bb194_21, phi_bb194_21, phi_bb194_21, phi_bb194_21});
  }

  TNode<IntPtrT> phi_bb210_7;
  TNode<IntPtrT> phi_bb210_9;
  TNode<IntPtrT> phi_bb210_10;
  TNode<IntPtrT> phi_bb210_11;
  TNode<IntPtrT> phi_bb210_14;
  TNode<BoolT> phi_bb210_15;
  TNode<IntPtrT> phi_bb210_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb210_23;
  TNode<IntPtrT> phi_bb210_24;
  TNode<IntPtrT> phi_bb210_30;
  TNode<IntPtrT> phi_bb210_31;
  TNode<IntPtrT> phi_bb210_35;
  TNode<IntPtrT> phi_bb210_36;
  TNode<IntPtrT> tmp456;
  TNode<IntPtrT> tmp457;
  TNode<Union<HeapObject, TaggedIndex>> tmp458;
  TNode<IntPtrT> tmp459;
  TNode<Number> tmp460;
  if (block210.is_used()) {
    ca_.Bind(&block210, &phi_bb210_7, &phi_bb210_9, &phi_bb210_10, &phi_bb210_11, &phi_bb210_14, &phi_bb210_15, &phi_bb210_21, &phi_bb210_23, &phi_bb210_24, &phi_bb210_30, &phi_bb210_31, &phi_bb210_35, &phi_bb210_36);
    tmp456 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{phi_bb210_36});
    tmp457 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp451}, TNode<IntPtrT>{tmp456});
    std::tie(tmp458, tmp459) = NewReference_Object_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp450}, TNode<IntPtrT>{tmp457}).Flatten();
    tmp460 = Convert_Number_float32_0(state_, TNode<Float32T>{phi_bb194_25});
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp458, tmp459}, tmp460);
    ca_.Goto(&block182, phi_bb210_7, tmp402, phi_bb210_9, phi_bb210_10, phi_bb210_11, phi_bb210_14, phi_bb210_15, phi_bb210_21);
  }

  TNode<IntPtrT> phi_bb211_7;
  TNode<IntPtrT> phi_bb211_9;
  TNode<IntPtrT> phi_bb211_10;
  TNode<IntPtrT> phi_bb211_11;
  TNode<IntPtrT> phi_bb211_14;
  TNode<BoolT> phi_bb211_15;
  TNode<IntPtrT> phi_bb211_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb211_23;
  TNode<IntPtrT> phi_bb211_24;
  TNode<IntPtrT> phi_bb211_30;
  TNode<IntPtrT> phi_bb211_31;
  TNode<IntPtrT> phi_bb211_35;
  TNode<IntPtrT> phi_bb211_36;
  if (block211.is_used()) {
    ca_.Bind(&block211, &phi_bb211_7, &phi_bb211_9, &phi_bb211_10, &phi_bb211_11, &phi_bb211_14, &phi_bb211_15, &phi_bb211_21, &phi_bb211_23, &phi_bb211_24, &phi_bb211_30, &phi_bb211_31, &phi_bb211_35, &phi_bb211_36);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> phi_bb181_7;
  TNode<IntPtrT> phi_bb181_8;
  TNode<IntPtrT> phi_bb181_9;
  TNode<IntPtrT> phi_bb181_10;
  TNode<IntPtrT> phi_bb181_11;
  TNode<IntPtrT> phi_bb181_14;
  TNode<BoolT> phi_bb181_15;
  TNode<IntPtrT> phi_bb181_21;
  TNode<Int32T> tmp461;
  TNode<BoolT> tmp462;
  if (block181.is_used()) {
    ca_.Bind(&block181, &phi_bb181_7, &phi_bb181_8, &phi_bb181_9, &phi_bb181_10, &phi_bb181_11, &phi_bb181_14, &phi_bb181_15, &phi_bb181_21);
    tmp461 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmI64.raw_bit_field());
    tmp462 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp353}, TNode<Int32T>{tmp461});
    ca_.Branch(tmp462, &block214, std::vector<compiler::Node*>{phi_bb181_7, phi_bb181_8, phi_bb181_9, phi_bb181_10, phi_bb181_11, phi_bb181_14, phi_bb181_15, phi_bb181_21}, &block215, std::vector<compiler::Node*>{phi_bb181_7, phi_bb181_8, phi_bb181_9, phi_bb181_10, phi_bb181_11, phi_bb181_14, phi_bb181_15, phi_bb181_21});
  }

  TNode<IntPtrT> phi_bb214_7;
  TNode<IntPtrT> phi_bb214_8;
  TNode<IntPtrT> phi_bb214_9;
  TNode<IntPtrT> phi_bb214_10;
  TNode<IntPtrT> phi_bb214_11;
  TNode<IntPtrT> phi_bb214_14;
  TNode<BoolT> phi_bb214_15;
  TNode<IntPtrT> phi_bb214_21;
  if (block214.is_used()) {
    ca_.Bind(&block214, &phi_bb214_7, &phi_bb214_8, &phi_bb214_9, &phi_bb214_10, &phi_bb214_11, &phi_bb214_14, &phi_bb214_15, &phi_bb214_21);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block217, phi_bb214_7, phi_bb214_8, phi_bb214_9, phi_bb214_10, phi_bb214_11, phi_bb214_14, phi_bb214_15, phi_bb214_21);
    } else {
      ca_.Goto(&block218, phi_bb214_7, phi_bb214_8, phi_bb214_9, phi_bb214_10, phi_bb214_11, phi_bb214_14, phi_bb214_15, phi_bb214_21);
    }
  }

  TNode<IntPtrT> phi_bb217_7;
  TNode<IntPtrT> phi_bb217_8;
  TNode<IntPtrT> phi_bb217_9;
  TNode<IntPtrT> phi_bb217_10;
  TNode<IntPtrT> phi_bb217_11;
  TNode<IntPtrT> phi_bb217_14;
  TNode<BoolT> phi_bb217_15;
  TNode<IntPtrT> phi_bb217_21;
  TNode<IntPtrT> tmp463;
  TNode<IntPtrT> tmp464;
  TNode<IntPtrT> tmp465;
  TNode<BoolT> tmp466;
  if (block217.is_used()) {
    ca_.Bind(&block217, &phi_bb217_7, &phi_bb217_8, &phi_bb217_9, &phi_bb217_10, &phi_bb217_11, &phi_bb217_14, &phi_bb217_15, &phi_bb217_21);
    tmp463 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp464 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{phi_bb217_7}, TNode<IntPtrT>{tmp463});
    tmp465 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp466 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{phi_bb217_7}, TNode<IntPtrT>{tmp465});
    ca_.Branch(tmp466, &block221, std::vector<compiler::Node*>{phi_bb217_8, phi_bb217_9, phi_bb217_10, phi_bb217_11, phi_bb217_14, phi_bb217_15, phi_bb217_21}, &block222, std::vector<compiler::Node*>{phi_bb217_8, phi_bb217_9, phi_bb217_10, phi_bb217_11, phi_bb217_14, phi_bb217_15, phi_bb217_21});
  }

  TNode<IntPtrT> phi_bb221_8;
  TNode<IntPtrT> phi_bb221_9;
  TNode<IntPtrT> phi_bb221_10;
  TNode<IntPtrT> phi_bb221_11;
  TNode<IntPtrT> phi_bb221_14;
  TNode<BoolT> phi_bb221_15;
  TNode<IntPtrT> phi_bb221_21;
  TNode<Union<HeapObject, TaggedIndex>> tmp467;
  TNode<IntPtrT> tmp468;
  TNode<IntPtrT> tmp469;
  TNode<IntPtrT> tmp470;
  if (block221.is_used()) {
    ca_.Bind(&block221, &phi_bb221_8, &phi_bb221_9, &phi_bb221_10, &phi_bb221_11, &phi_bb221_14, &phi_bb221_15, &phi_bb221_21);
    std::tie(tmp467, tmp468) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp336}, TNode<IntPtrT>{phi_bb221_9}).Flatten();
    tmp469 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp470 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb221_9}, TNode<IntPtrT>{tmp469});
    ca_.Goto(&block220, phi_bb221_8, tmp470, phi_bb221_10, phi_bb221_11, phi_bb221_14, phi_bb221_15, phi_bb221_21, tmp467, tmp468);
  }

  TNode<IntPtrT> phi_bb222_8;
  TNode<IntPtrT> phi_bb222_9;
  TNode<IntPtrT> phi_bb222_10;
  TNode<IntPtrT> phi_bb222_11;
  TNode<IntPtrT> phi_bb222_14;
  TNode<BoolT> phi_bb222_15;
  TNode<IntPtrT> phi_bb222_21;
  if (block222.is_used()) {
    ca_.Bind(&block222, &phi_bb222_8, &phi_bb222_9, &phi_bb222_10, &phi_bb222_11, &phi_bb222_14, &phi_bb222_15, &phi_bb222_21);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block224, phi_bb222_8, phi_bb222_9, phi_bb222_10, phi_bb222_11, phi_bb222_14, phi_bb222_15, phi_bb222_21);
    } else {
      ca_.Goto(&block225, phi_bb222_8, phi_bb222_9, phi_bb222_10, phi_bb222_11, phi_bb222_14, phi_bb222_15, phi_bb222_21);
    }
  }

  TNode<IntPtrT> phi_bb224_8;
  TNode<IntPtrT> phi_bb224_9;
  TNode<IntPtrT> phi_bb224_10;
  TNode<IntPtrT> phi_bb224_11;
  TNode<IntPtrT> phi_bb224_14;
  TNode<BoolT> phi_bb224_15;
  TNode<IntPtrT> phi_bb224_21;
  TNode<Union<HeapObject, TaggedIndex>> tmp471;
  TNode<IntPtrT> tmp472;
  TNode<IntPtrT> tmp473;
  TNode<IntPtrT> tmp474;
  if (block224.is_used()) {
    ca_.Bind(&block224, &phi_bb224_8, &phi_bb224_9, &phi_bb224_10, &phi_bb224_11, &phi_bb224_14, &phi_bb224_15, &phi_bb224_21);
    std::tie(tmp471, tmp472) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp336}, TNode<IntPtrT>{phi_bb224_11}).Flatten();
    tmp473 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp474 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb224_11}, TNode<IntPtrT>{tmp473});
    ca_.Goto(&block223, phi_bb224_8, phi_bb224_9, phi_bb224_10, tmp474, phi_bb224_14, phi_bb224_15, phi_bb224_21, tmp471, tmp472);
  }

  TNode<IntPtrT> phi_bb225_8;
  TNode<IntPtrT> phi_bb225_9;
  TNode<IntPtrT> phi_bb225_10;
  TNode<IntPtrT> phi_bb225_11;
  TNode<IntPtrT> phi_bb225_14;
  TNode<BoolT> phi_bb225_15;
  TNode<IntPtrT> phi_bb225_21;
  TNode<IntPtrT> tmp475;
  TNode<BoolT> tmp476;
  if (block225.is_used()) {
    ca_.Bind(&block225, &phi_bb225_8, &phi_bb225_9, &phi_bb225_10, &phi_bb225_11, &phi_bb225_14, &phi_bb225_15, &phi_bb225_21);
    tmp475 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp476 = CodeStubAssembler(state_).WordNotEqual(TNode<IntPtrT>{phi_bb225_14}, TNode<IntPtrT>{tmp475});
    ca_.Branch(tmp476, &block227, std::vector<compiler::Node*>{phi_bb225_8, phi_bb225_9, phi_bb225_10, phi_bb225_11, phi_bb225_14, phi_bb225_15, phi_bb225_21}, &block228, std::vector<compiler::Node*>{phi_bb225_8, phi_bb225_9, phi_bb225_10, phi_bb225_11, phi_bb225_14, phi_bb225_15, phi_bb225_21});
  }

  TNode<IntPtrT> phi_bb227_8;
  TNode<IntPtrT> phi_bb227_9;
  TNode<IntPtrT> phi_bb227_10;
  TNode<IntPtrT> phi_bb227_11;
  TNode<IntPtrT> phi_bb227_14;
  TNode<BoolT> phi_bb227_15;
  TNode<IntPtrT> phi_bb227_21;
  TNode<Union<HeapObject, TaggedIndex>> tmp477;
  TNode<IntPtrT> tmp478;
  TNode<IntPtrT> tmp479;
  TNode<BoolT> tmp480;
  if (block227.is_used()) {
    ca_.Bind(&block227, &phi_bb227_8, &phi_bb227_9, &phi_bb227_10, &phi_bb227_11, &phi_bb227_14, &phi_bb227_15, &phi_bb227_21);
    std::tie(tmp477, tmp478) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp336}, TNode<IntPtrT>{phi_bb227_14}).Flatten();
    tmp479 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp480 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block223, phi_bb227_8, phi_bb227_9, phi_bb227_10, phi_bb227_11, tmp479, tmp480, phi_bb227_21, tmp477, tmp478);
  }

  TNode<IntPtrT> phi_bb228_8;
  TNode<IntPtrT> phi_bb228_9;
  TNode<IntPtrT> phi_bb228_10;
  TNode<IntPtrT> phi_bb228_11;
  TNode<IntPtrT> phi_bb228_14;
  TNode<BoolT> phi_bb228_15;
  TNode<IntPtrT> phi_bb228_21;
  TNode<Union<HeapObject, TaggedIndex>> tmp481;
  TNode<IntPtrT> tmp482;
  TNode<IntPtrT> tmp483;
  TNode<IntPtrT> tmp484;
  TNode<IntPtrT> tmp485;
  TNode<IntPtrT> tmp486;
  TNode<BoolT> tmp487;
  if (block228.is_used()) {
    ca_.Bind(&block228, &phi_bb228_8, &phi_bb228_9, &phi_bb228_10, &phi_bb228_11, &phi_bb228_14, &phi_bb228_15, &phi_bb228_21);
    std::tie(tmp481, tmp482) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp336}, TNode<IntPtrT>{phi_bb228_11}).Flatten();
    tmp483 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp484 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb228_11}, TNode<IntPtrT>{tmp483});
    tmp485 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp486 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp484}, TNode<IntPtrT>{tmp485});
    tmp487 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block223, phi_bb228_8, phi_bb228_9, phi_bb228_10, tmp486, tmp484, tmp487, phi_bb228_21, tmp481, tmp482);
  }

  TNode<IntPtrT> phi_bb223_8;
  TNode<IntPtrT> phi_bb223_9;
  TNode<IntPtrT> phi_bb223_10;
  TNode<IntPtrT> phi_bb223_11;
  TNode<IntPtrT> phi_bb223_14;
  TNode<BoolT> phi_bb223_15;
  TNode<IntPtrT> phi_bb223_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb223_23;
  TNode<IntPtrT> phi_bb223_24;
  if (block223.is_used()) {
    ca_.Bind(&block223, &phi_bb223_8, &phi_bb223_9, &phi_bb223_10, &phi_bb223_11, &phi_bb223_14, &phi_bb223_15, &phi_bb223_21, &phi_bb223_23, &phi_bb223_24);
    ca_.Goto(&block220, phi_bb223_8, phi_bb223_9, phi_bb223_10, phi_bb223_11, phi_bb223_14, phi_bb223_15, phi_bb223_21, phi_bb223_23, phi_bb223_24);
  }

  TNode<IntPtrT> phi_bb220_8;
  TNode<IntPtrT> phi_bb220_9;
  TNode<IntPtrT> phi_bb220_10;
  TNode<IntPtrT> phi_bb220_11;
  TNode<IntPtrT> phi_bb220_14;
  TNode<BoolT> phi_bb220_15;
  TNode<IntPtrT> phi_bb220_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb220_23;
  TNode<IntPtrT> phi_bb220_24;
  TNode<IntPtrT> tmp488;
  TNode<Union<HeapObject, TaggedIndex>> tmp489;
  TNode<IntPtrT> tmp490;
  TNode<IntPtrT> tmp491;
  TNode<UintPtrT> tmp492;
  TNode<UintPtrT> tmp493;
  TNode<BoolT> tmp494;
  if (block220.is_used()) {
    ca_.Bind(&block220, &phi_bb220_8, &phi_bb220_9, &phi_bb220_10, &phi_bb220_11, &phi_bb220_14, &phi_bb220_15, &phi_bb220_21, &phi_bb220_23, &phi_bb220_24);
    tmp488 = CodeStubAssembler(state_).LoadReference<IntPtrT>(CodeStubAssembler::Reference{phi_bb220_23, phi_bb220_24});
    std::tie(tmp489, tmp490, tmp491) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{tmp92}).Flatten();
    tmp492 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{phi_bb220_21});
    tmp493 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp491});
    tmp494 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp492}, TNode<UintPtrT>{tmp493});
    ca_.Branch(tmp494, &block233, std::vector<compiler::Node*>{phi_bb220_8, phi_bb220_9, phi_bb220_10, phi_bb220_11, phi_bb220_14, phi_bb220_15, phi_bb220_21, phi_bb220_23, phi_bb220_24, phi_bb220_21, phi_bb220_21, phi_bb220_21, phi_bb220_21}, &block234, std::vector<compiler::Node*>{phi_bb220_8, phi_bb220_9, phi_bb220_10, phi_bb220_11, phi_bb220_14, phi_bb220_15, phi_bb220_21, phi_bb220_23, phi_bb220_24, phi_bb220_21, phi_bb220_21, phi_bb220_21, phi_bb220_21});
  }

  TNode<IntPtrT> phi_bb233_8;
  TNode<IntPtrT> phi_bb233_9;
  TNode<IntPtrT> phi_bb233_10;
  TNode<IntPtrT> phi_bb233_11;
  TNode<IntPtrT> phi_bb233_14;
  TNode<BoolT> phi_bb233_15;
  TNode<IntPtrT> phi_bb233_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb233_23;
  TNode<IntPtrT> phi_bb233_24;
  TNode<IntPtrT> phi_bb233_30;
  TNode<IntPtrT> phi_bb233_31;
  TNode<IntPtrT> phi_bb233_35;
  TNode<IntPtrT> phi_bb233_36;
  TNode<IntPtrT> tmp495;
  TNode<IntPtrT> tmp496;
  TNode<Union<HeapObject, TaggedIndex>> tmp497;
  TNode<IntPtrT> tmp498;
  TNode<BigInt> tmp499;
  if (block233.is_used()) {
    ca_.Bind(&block233, &phi_bb233_8, &phi_bb233_9, &phi_bb233_10, &phi_bb233_11, &phi_bb233_14, &phi_bb233_15, &phi_bb233_21, &phi_bb233_23, &phi_bb233_24, &phi_bb233_30, &phi_bb233_31, &phi_bb233_35, &phi_bb233_36);
    tmp495 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{phi_bb233_36});
    tmp496 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp490}, TNode<IntPtrT>{tmp495});
    std::tie(tmp497, tmp498) = NewReference_Object_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp489}, TNode<IntPtrT>{tmp496}).Flatten();
    tmp499 = ca_.CallBuiltin<BigInt>(Builtin::kI64ToBigInt, TNode<Object>(), tmp488);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp497, tmp498}, tmp499);
    ca_.Goto(&block219, tmp464, phi_bb233_8, phi_bb233_9, phi_bb233_10, phi_bb233_11, phi_bb233_14, phi_bb233_15, phi_bb233_21);
  }

  TNode<IntPtrT> phi_bb234_8;
  TNode<IntPtrT> phi_bb234_9;
  TNode<IntPtrT> phi_bb234_10;
  TNode<IntPtrT> phi_bb234_11;
  TNode<IntPtrT> phi_bb234_14;
  TNode<BoolT> phi_bb234_15;
  TNode<IntPtrT> phi_bb234_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb234_23;
  TNode<IntPtrT> phi_bb234_24;
  TNode<IntPtrT> phi_bb234_30;
  TNode<IntPtrT> phi_bb234_31;
  TNode<IntPtrT> phi_bb234_35;
  TNode<IntPtrT> phi_bb234_36;
  if (block234.is_used()) {
    ca_.Bind(&block234, &phi_bb234_8, &phi_bb234_9, &phi_bb234_10, &phi_bb234_11, &phi_bb234_14, &phi_bb234_15, &phi_bb234_21, &phi_bb234_23, &phi_bb234_24, &phi_bb234_30, &phi_bb234_31, &phi_bb234_35, &phi_bb234_36);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> phi_bb218_7;
  TNode<IntPtrT> phi_bb218_8;
  TNode<IntPtrT> phi_bb218_9;
  TNode<IntPtrT> phi_bb218_10;
  TNode<IntPtrT> phi_bb218_11;
  TNode<IntPtrT> phi_bb218_14;
  TNode<BoolT> phi_bb218_15;
  TNode<IntPtrT> phi_bb218_21;
  TNode<IntPtrT> tmp500;
  TNode<IntPtrT> tmp501;
  TNode<IntPtrT> tmp502;
  TNode<BoolT> tmp503;
  if (block218.is_used()) {
    ca_.Bind(&block218, &phi_bb218_7, &phi_bb218_8, &phi_bb218_9, &phi_bb218_10, &phi_bb218_11, &phi_bb218_14, &phi_bb218_15, &phi_bb218_21);
    tmp500 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp501 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{phi_bb218_7}, TNode<IntPtrT>{tmp500});
    tmp502 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp503 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{phi_bb218_7}, TNode<IntPtrT>{tmp502});
    ca_.Branch(tmp503, &block238, std::vector<compiler::Node*>{phi_bb218_8, phi_bb218_9, phi_bb218_10, phi_bb218_11, phi_bb218_14, phi_bb218_15, phi_bb218_21}, &block239, std::vector<compiler::Node*>{phi_bb218_8, phi_bb218_9, phi_bb218_10, phi_bb218_11, phi_bb218_14, phi_bb218_15, phi_bb218_21});
  }

  TNode<IntPtrT> phi_bb238_8;
  TNode<IntPtrT> phi_bb238_9;
  TNode<IntPtrT> phi_bb238_10;
  TNode<IntPtrT> phi_bb238_11;
  TNode<IntPtrT> phi_bb238_14;
  TNode<BoolT> phi_bb238_15;
  TNode<IntPtrT> phi_bb238_21;
  TNode<Union<HeapObject, TaggedIndex>> tmp504;
  TNode<IntPtrT> tmp505;
  TNode<IntPtrT> tmp506;
  TNode<IntPtrT> tmp507;
  if (block238.is_used()) {
    ca_.Bind(&block238, &phi_bb238_8, &phi_bb238_9, &phi_bb238_10, &phi_bb238_11, &phi_bb238_14, &phi_bb238_15, &phi_bb238_21);
    std::tie(tmp504, tmp505) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp336}, TNode<IntPtrT>{phi_bb238_9}).Flatten();
    tmp506 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp507 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb238_9}, TNode<IntPtrT>{tmp506});
    ca_.Goto(&block237, phi_bb238_8, tmp507, phi_bb238_10, phi_bb238_11, phi_bb238_14, phi_bb238_15, phi_bb238_21, tmp504, tmp505);
  }

  TNode<IntPtrT> phi_bb239_8;
  TNode<IntPtrT> phi_bb239_9;
  TNode<IntPtrT> phi_bb239_10;
  TNode<IntPtrT> phi_bb239_11;
  TNode<IntPtrT> phi_bb239_14;
  TNode<BoolT> phi_bb239_15;
  TNode<IntPtrT> phi_bb239_21;
  if (block239.is_used()) {
    ca_.Bind(&block239, &phi_bb239_8, &phi_bb239_9, &phi_bb239_10, &phi_bb239_11, &phi_bb239_14, &phi_bb239_15, &phi_bb239_21);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block241, phi_bb239_8, phi_bb239_9, phi_bb239_10, phi_bb239_11, phi_bb239_14, phi_bb239_15, phi_bb239_21);
    } else {
      ca_.Goto(&block242, phi_bb239_8, phi_bb239_9, phi_bb239_10, phi_bb239_11, phi_bb239_14, phi_bb239_15, phi_bb239_21);
    }
  }

  TNode<IntPtrT> phi_bb241_8;
  TNode<IntPtrT> phi_bb241_9;
  TNode<IntPtrT> phi_bb241_10;
  TNode<IntPtrT> phi_bb241_11;
  TNode<IntPtrT> phi_bb241_14;
  TNode<BoolT> phi_bb241_15;
  TNode<IntPtrT> phi_bb241_21;
  TNode<Union<HeapObject, TaggedIndex>> tmp508;
  TNode<IntPtrT> tmp509;
  TNode<IntPtrT> tmp510;
  TNode<IntPtrT> tmp511;
  if (block241.is_used()) {
    ca_.Bind(&block241, &phi_bb241_8, &phi_bb241_9, &phi_bb241_10, &phi_bb241_11, &phi_bb241_14, &phi_bb241_15, &phi_bb241_21);
    std::tie(tmp508, tmp509) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp336}, TNode<IntPtrT>{phi_bb241_11}).Flatten();
    tmp510 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp511 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb241_11}, TNode<IntPtrT>{tmp510});
    ca_.Goto(&block240, phi_bb241_8, phi_bb241_9, phi_bb241_10, tmp511, phi_bb241_14, phi_bb241_15, phi_bb241_21, tmp508, tmp509);
  }

  TNode<IntPtrT> phi_bb242_8;
  TNode<IntPtrT> phi_bb242_9;
  TNode<IntPtrT> phi_bb242_10;
  TNode<IntPtrT> phi_bb242_11;
  TNode<IntPtrT> phi_bb242_14;
  TNode<BoolT> phi_bb242_15;
  TNode<IntPtrT> phi_bb242_21;
  TNode<IntPtrT> tmp512;
  TNode<BoolT> tmp513;
  if (block242.is_used()) {
    ca_.Bind(&block242, &phi_bb242_8, &phi_bb242_9, &phi_bb242_10, &phi_bb242_11, &phi_bb242_14, &phi_bb242_15, &phi_bb242_21);
    tmp512 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp513 = CodeStubAssembler(state_).WordNotEqual(TNode<IntPtrT>{phi_bb242_14}, TNode<IntPtrT>{tmp512});
    ca_.Branch(tmp513, &block244, std::vector<compiler::Node*>{phi_bb242_8, phi_bb242_9, phi_bb242_10, phi_bb242_11, phi_bb242_14, phi_bb242_15, phi_bb242_21}, &block245, std::vector<compiler::Node*>{phi_bb242_8, phi_bb242_9, phi_bb242_10, phi_bb242_11, phi_bb242_14, phi_bb242_15, phi_bb242_21});
  }

  TNode<IntPtrT> phi_bb244_8;
  TNode<IntPtrT> phi_bb244_9;
  TNode<IntPtrT> phi_bb244_10;
  TNode<IntPtrT> phi_bb244_11;
  TNode<IntPtrT> phi_bb244_14;
  TNode<BoolT> phi_bb244_15;
  TNode<IntPtrT> phi_bb244_21;
  TNode<Union<HeapObject, TaggedIndex>> tmp514;
  TNode<IntPtrT> tmp515;
  TNode<IntPtrT> tmp516;
  TNode<BoolT> tmp517;
  if (block244.is_used()) {
    ca_.Bind(&block244, &phi_bb244_8, &phi_bb244_9, &phi_bb244_10, &phi_bb244_11, &phi_bb244_14, &phi_bb244_15, &phi_bb244_21);
    std::tie(tmp514, tmp515) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp336}, TNode<IntPtrT>{phi_bb244_14}).Flatten();
    tmp516 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp517 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block240, phi_bb244_8, phi_bb244_9, phi_bb244_10, phi_bb244_11, tmp516, tmp517, phi_bb244_21, tmp514, tmp515);
  }

  TNode<IntPtrT> phi_bb245_8;
  TNode<IntPtrT> phi_bb245_9;
  TNode<IntPtrT> phi_bb245_10;
  TNode<IntPtrT> phi_bb245_11;
  TNode<IntPtrT> phi_bb245_14;
  TNode<BoolT> phi_bb245_15;
  TNode<IntPtrT> phi_bb245_21;
  TNode<Union<HeapObject, TaggedIndex>> tmp518;
  TNode<IntPtrT> tmp519;
  TNode<IntPtrT> tmp520;
  TNode<IntPtrT> tmp521;
  TNode<IntPtrT> tmp522;
  TNode<IntPtrT> tmp523;
  TNode<BoolT> tmp524;
  if (block245.is_used()) {
    ca_.Bind(&block245, &phi_bb245_8, &phi_bb245_9, &phi_bb245_10, &phi_bb245_11, &phi_bb245_14, &phi_bb245_15, &phi_bb245_21);
    std::tie(tmp518, tmp519) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp336}, TNode<IntPtrT>{phi_bb245_11}).Flatten();
    tmp520 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp521 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb245_11}, TNode<IntPtrT>{tmp520});
    tmp522 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp523 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp521}, TNode<IntPtrT>{tmp522});
    tmp524 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block240, phi_bb245_8, phi_bb245_9, phi_bb245_10, tmp523, tmp521, tmp524, phi_bb245_21, tmp518, tmp519);
  }

  TNode<IntPtrT> phi_bb240_8;
  TNode<IntPtrT> phi_bb240_9;
  TNode<IntPtrT> phi_bb240_10;
  TNode<IntPtrT> phi_bb240_11;
  TNode<IntPtrT> phi_bb240_14;
  TNode<BoolT> phi_bb240_15;
  TNode<IntPtrT> phi_bb240_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb240_23;
  TNode<IntPtrT> phi_bb240_24;
  if (block240.is_used()) {
    ca_.Bind(&block240, &phi_bb240_8, &phi_bb240_9, &phi_bb240_10, &phi_bb240_11, &phi_bb240_14, &phi_bb240_15, &phi_bb240_21, &phi_bb240_23, &phi_bb240_24);
    ca_.Goto(&block237, phi_bb240_8, phi_bb240_9, phi_bb240_10, phi_bb240_11, phi_bb240_14, phi_bb240_15, phi_bb240_21, phi_bb240_23, phi_bb240_24);
  }

  TNode<IntPtrT> phi_bb237_8;
  TNode<IntPtrT> phi_bb237_9;
  TNode<IntPtrT> phi_bb237_10;
  TNode<IntPtrT> phi_bb237_11;
  TNode<IntPtrT> phi_bb237_14;
  TNode<BoolT> phi_bb237_15;
  TNode<IntPtrT> phi_bb237_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb237_23;
  TNode<IntPtrT> phi_bb237_24;
  TNode<IntPtrT> tmp525;
  TNode<IntPtrT> tmp526;
  TNode<IntPtrT> tmp527;
  TNode<BoolT> tmp528;
  if (block237.is_used()) {
    ca_.Bind(&block237, &phi_bb237_8, &phi_bb237_9, &phi_bb237_10, &phi_bb237_11, &phi_bb237_14, &phi_bb237_15, &phi_bb237_21, &phi_bb237_23, &phi_bb237_24);
    tmp525 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp526 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{tmp501}, TNode<IntPtrT>{tmp525});
    tmp527 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp528 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp501}, TNode<IntPtrT>{tmp527});
    ca_.Branch(tmp528, &block247, std::vector<compiler::Node*>{phi_bb237_8, phi_bb237_9, phi_bb237_10, phi_bb237_11, phi_bb237_14, phi_bb237_15, phi_bb237_21, phi_bb237_23, phi_bb237_24}, &block248, std::vector<compiler::Node*>{phi_bb237_8, phi_bb237_9, phi_bb237_10, phi_bb237_11, phi_bb237_14, phi_bb237_15, phi_bb237_21, phi_bb237_23, phi_bb237_24});
  }

  TNode<IntPtrT> phi_bb247_8;
  TNode<IntPtrT> phi_bb247_9;
  TNode<IntPtrT> phi_bb247_10;
  TNode<IntPtrT> phi_bb247_11;
  TNode<IntPtrT> phi_bb247_14;
  TNode<BoolT> phi_bb247_15;
  TNode<IntPtrT> phi_bb247_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb247_23;
  TNode<IntPtrT> phi_bb247_24;
  TNode<Union<HeapObject, TaggedIndex>> tmp529;
  TNode<IntPtrT> tmp530;
  TNode<IntPtrT> tmp531;
  TNode<IntPtrT> tmp532;
  if (block247.is_used()) {
    ca_.Bind(&block247, &phi_bb247_8, &phi_bb247_9, &phi_bb247_10, &phi_bb247_11, &phi_bb247_14, &phi_bb247_15, &phi_bb247_21, &phi_bb247_23, &phi_bb247_24);
    std::tie(tmp529, tmp530) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp336}, TNode<IntPtrT>{phi_bb247_9}).Flatten();
    tmp531 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp532 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb247_9}, TNode<IntPtrT>{tmp531});
    ca_.Goto(&block246, phi_bb247_8, tmp532, phi_bb247_10, phi_bb247_11, phi_bb247_14, phi_bb247_15, phi_bb247_21, phi_bb247_23, phi_bb247_24, tmp529, tmp530);
  }

  TNode<IntPtrT> phi_bb248_8;
  TNode<IntPtrT> phi_bb248_9;
  TNode<IntPtrT> phi_bb248_10;
  TNode<IntPtrT> phi_bb248_11;
  TNode<IntPtrT> phi_bb248_14;
  TNode<BoolT> phi_bb248_15;
  TNode<IntPtrT> phi_bb248_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb248_23;
  TNode<IntPtrT> phi_bb248_24;
  if (block248.is_used()) {
    ca_.Bind(&block248, &phi_bb248_8, &phi_bb248_9, &phi_bb248_10, &phi_bb248_11, &phi_bb248_14, &phi_bb248_15, &phi_bb248_21, &phi_bb248_23, &phi_bb248_24);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block250, phi_bb248_8, phi_bb248_9, phi_bb248_10, phi_bb248_11, phi_bb248_14, phi_bb248_15, phi_bb248_21, phi_bb248_23, phi_bb248_24);
    } else {
      ca_.Goto(&block251, phi_bb248_8, phi_bb248_9, phi_bb248_10, phi_bb248_11, phi_bb248_14, phi_bb248_15, phi_bb248_21, phi_bb248_23, phi_bb248_24);
    }
  }

  TNode<IntPtrT> phi_bb250_8;
  TNode<IntPtrT> phi_bb250_9;
  TNode<IntPtrT> phi_bb250_10;
  TNode<IntPtrT> phi_bb250_11;
  TNode<IntPtrT> phi_bb250_14;
  TNode<BoolT> phi_bb250_15;
  TNode<IntPtrT> phi_bb250_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb250_23;
  TNode<IntPtrT> phi_bb250_24;
  TNode<Union<HeapObject, TaggedIndex>> tmp533;
  TNode<IntPtrT> tmp534;
  TNode<IntPtrT> tmp535;
  TNode<IntPtrT> tmp536;
  if (block250.is_used()) {
    ca_.Bind(&block250, &phi_bb250_8, &phi_bb250_9, &phi_bb250_10, &phi_bb250_11, &phi_bb250_14, &phi_bb250_15, &phi_bb250_21, &phi_bb250_23, &phi_bb250_24);
    std::tie(tmp533, tmp534) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp336}, TNode<IntPtrT>{phi_bb250_11}).Flatten();
    tmp535 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp536 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb250_11}, TNode<IntPtrT>{tmp535});
    ca_.Goto(&block249, phi_bb250_8, phi_bb250_9, phi_bb250_10, tmp536, phi_bb250_14, phi_bb250_15, phi_bb250_21, phi_bb250_23, phi_bb250_24, tmp533, tmp534);
  }

  TNode<IntPtrT> phi_bb251_8;
  TNode<IntPtrT> phi_bb251_9;
  TNode<IntPtrT> phi_bb251_10;
  TNode<IntPtrT> phi_bb251_11;
  TNode<IntPtrT> phi_bb251_14;
  TNode<BoolT> phi_bb251_15;
  TNode<IntPtrT> phi_bb251_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb251_23;
  TNode<IntPtrT> phi_bb251_24;
  TNode<IntPtrT> tmp537;
  TNode<BoolT> tmp538;
  if (block251.is_used()) {
    ca_.Bind(&block251, &phi_bb251_8, &phi_bb251_9, &phi_bb251_10, &phi_bb251_11, &phi_bb251_14, &phi_bb251_15, &phi_bb251_21, &phi_bb251_23, &phi_bb251_24);
    tmp537 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp538 = CodeStubAssembler(state_).WordNotEqual(TNode<IntPtrT>{phi_bb251_14}, TNode<IntPtrT>{tmp537});
    ca_.Branch(tmp538, &block253, std::vector<compiler::Node*>{phi_bb251_8, phi_bb251_9, phi_bb251_10, phi_bb251_11, phi_bb251_14, phi_bb251_15, phi_bb251_21, phi_bb251_23, phi_bb251_24}, &block254, std::vector<compiler::Node*>{phi_bb251_8, phi_bb251_9, phi_bb251_10, phi_bb251_11, phi_bb251_14, phi_bb251_15, phi_bb251_21, phi_bb251_23, phi_bb251_24});
  }

  TNode<IntPtrT> phi_bb253_8;
  TNode<IntPtrT> phi_bb253_9;
  TNode<IntPtrT> phi_bb253_10;
  TNode<IntPtrT> phi_bb253_11;
  TNode<IntPtrT> phi_bb253_14;
  TNode<BoolT> phi_bb253_15;
  TNode<IntPtrT> phi_bb253_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb253_23;
  TNode<IntPtrT> phi_bb253_24;
  TNode<Union<HeapObject, TaggedIndex>> tmp539;
  TNode<IntPtrT> tmp540;
  TNode<IntPtrT> tmp541;
  TNode<BoolT> tmp542;
  if (block253.is_used()) {
    ca_.Bind(&block253, &phi_bb253_8, &phi_bb253_9, &phi_bb253_10, &phi_bb253_11, &phi_bb253_14, &phi_bb253_15, &phi_bb253_21, &phi_bb253_23, &phi_bb253_24);
    std::tie(tmp539, tmp540) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp336}, TNode<IntPtrT>{phi_bb253_14}).Flatten();
    tmp541 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp542 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block249, phi_bb253_8, phi_bb253_9, phi_bb253_10, phi_bb253_11, tmp541, tmp542, phi_bb253_21, phi_bb253_23, phi_bb253_24, tmp539, tmp540);
  }

  TNode<IntPtrT> phi_bb254_8;
  TNode<IntPtrT> phi_bb254_9;
  TNode<IntPtrT> phi_bb254_10;
  TNode<IntPtrT> phi_bb254_11;
  TNode<IntPtrT> phi_bb254_14;
  TNode<BoolT> phi_bb254_15;
  TNode<IntPtrT> phi_bb254_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb254_23;
  TNode<IntPtrT> phi_bb254_24;
  TNode<Union<HeapObject, TaggedIndex>> tmp543;
  TNode<IntPtrT> tmp544;
  TNode<IntPtrT> tmp545;
  TNode<IntPtrT> tmp546;
  TNode<IntPtrT> tmp547;
  TNode<IntPtrT> tmp548;
  TNode<BoolT> tmp549;
  if (block254.is_used()) {
    ca_.Bind(&block254, &phi_bb254_8, &phi_bb254_9, &phi_bb254_10, &phi_bb254_11, &phi_bb254_14, &phi_bb254_15, &phi_bb254_21, &phi_bb254_23, &phi_bb254_24);
    std::tie(tmp543, tmp544) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp336}, TNode<IntPtrT>{phi_bb254_11}).Flatten();
    tmp545 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp546 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb254_11}, TNode<IntPtrT>{tmp545});
    tmp547 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp548 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp546}, TNode<IntPtrT>{tmp547});
    tmp549 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block249, phi_bb254_8, phi_bb254_9, phi_bb254_10, tmp548, tmp546, tmp549, phi_bb254_21, phi_bb254_23, phi_bb254_24, tmp543, tmp544);
  }

  TNode<IntPtrT> phi_bb249_8;
  TNode<IntPtrT> phi_bb249_9;
  TNode<IntPtrT> phi_bb249_10;
  TNode<IntPtrT> phi_bb249_11;
  TNode<IntPtrT> phi_bb249_14;
  TNode<BoolT> phi_bb249_15;
  TNode<IntPtrT> phi_bb249_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb249_23;
  TNode<IntPtrT> phi_bb249_24;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb249_25;
  TNode<IntPtrT> phi_bb249_26;
  if (block249.is_used()) {
    ca_.Bind(&block249, &phi_bb249_8, &phi_bb249_9, &phi_bb249_10, &phi_bb249_11, &phi_bb249_14, &phi_bb249_15, &phi_bb249_21, &phi_bb249_23, &phi_bb249_24, &phi_bb249_25, &phi_bb249_26);
    ca_.Goto(&block246, phi_bb249_8, phi_bb249_9, phi_bb249_10, phi_bb249_11, phi_bb249_14, phi_bb249_15, phi_bb249_21, phi_bb249_23, phi_bb249_24, phi_bb249_25, phi_bb249_26);
  }

  TNode<IntPtrT> phi_bb246_8;
  TNode<IntPtrT> phi_bb246_9;
  TNode<IntPtrT> phi_bb246_10;
  TNode<IntPtrT> phi_bb246_11;
  TNode<IntPtrT> phi_bb246_14;
  TNode<BoolT> phi_bb246_15;
  TNode<IntPtrT> phi_bb246_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb246_23;
  TNode<IntPtrT> phi_bb246_24;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb246_25;
  TNode<IntPtrT> phi_bb246_26;
  TNode<IntPtrT> tmp550;
  TNode<IntPtrT> tmp551;
  TNode<Union<HeapObject, TaggedIndex>> tmp552;
  TNode<IntPtrT> tmp553;
  TNode<IntPtrT> tmp554;
  TNode<UintPtrT> tmp555;
  TNode<UintPtrT> tmp556;
  TNode<BoolT> tmp557;
  if (block246.is_used()) {
    ca_.Bind(&block246, &phi_bb246_8, &phi_bb246_9, &phi_bb246_10, &phi_bb246_11, &phi_bb246_14, &phi_bb246_15, &phi_bb246_21, &phi_bb246_23, &phi_bb246_24, &phi_bb246_25, &phi_bb246_26);
    tmp550 = CodeStubAssembler(state_).LoadReference<IntPtrT>(CodeStubAssembler::Reference{phi_bb246_23, phi_bb246_24});
    tmp551 = CodeStubAssembler(state_).LoadReference<IntPtrT>(CodeStubAssembler::Reference{phi_bb246_25, phi_bb246_26});
    std::tie(tmp552, tmp553, tmp554) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{tmp92}).Flatten();
    tmp555 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{phi_bb246_21});
    tmp556 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp554});
    tmp557 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp555}, TNode<UintPtrT>{tmp556});
    ca_.Branch(tmp557, &block259, std::vector<compiler::Node*>{phi_bb246_8, phi_bb246_9, phi_bb246_10, phi_bb246_11, phi_bb246_14, phi_bb246_15, phi_bb246_21, phi_bb246_23, phi_bb246_24, phi_bb246_25, phi_bb246_26, phi_bb246_21, phi_bb246_21, phi_bb246_21, phi_bb246_21}, &block260, std::vector<compiler::Node*>{phi_bb246_8, phi_bb246_9, phi_bb246_10, phi_bb246_11, phi_bb246_14, phi_bb246_15, phi_bb246_21, phi_bb246_23, phi_bb246_24, phi_bb246_25, phi_bb246_26, phi_bb246_21, phi_bb246_21, phi_bb246_21, phi_bb246_21});
  }

  TNode<IntPtrT> phi_bb259_8;
  TNode<IntPtrT> phi_bb259_9;
  TNode<IntPtrT> phi_bb259_10;
  TNode<IntPtrT> phi_bb259_11;
  TNode<IntPtrT> phi_bb259_14;
  TNode<BoolT> phi_bb259_15;
  TNode<IntPtrT> phi_bb259_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb259_23;
  TNode<IntPtrT> phi_bb259_24;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb259_25;
  TNode<IntPtrT> phi_bb259_26;
  TNode<IntPtrT> phi_bb259_33;
  TNode<IntPtrT> phi_bb259_34;
  TNode<IntPtrT> phi_bb259_38;
  TNode<IntPtrT> phi_bb259_39;
  TNode<IntPtrT> tmp558;
  TNode<IntPtrT> tmp559;
  TNode<Union<HeapObject, TaggedIndex>> tmp560;
  TNode<IntPtrT> tmp561;
  TNode<BigInt> tmp562;
  if (block259.is_used()) {
    ca_.Bind(&block259, &phi_bb259_8, &phi_bb259_9, &phi_bb259_10, &phi_bb259_11, &phi_bb259_14, &phi_bb259_15, &phi_bb259_21, &phi_bb259_23, &phi_bb259_24, &phi_bb259_25, &phi_bb259_26, &phi_bb259_33, &phi_bb259_34, &phi_bb259_38, &phi_bb259_39);
    tmp558 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{phi_bb259_39});
    tmp559 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp553}, TNode<IntPtrT>{tmp558});
    std::tie(tmp560, tmp561) = NewReference_Object_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp552}, TNode<IntPtrT>{tmp559}).Flatten();
    tmp562 = ca_.CallBuiltin<BigInt>(Builtin::kI32PairToBigInt, TNode<Object>(), tmp550, tmp551);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp560, tmp561}, tmp562);
    ca_.Goto(&block219, tmp526, phi_bb259_8, phi_bb259_9, phi_bb259_10, phi_bb259_11, phi_bb259_14, phi_bb259_15, phi_bb259_21);
  }

  TNode<IntPtrT> phi_bb260_8;
  TNode<IntPtrT> phi_bb260_9;
  TNode<IntPtrT> phi_bb260_10;
  TNode<IntPtrT> phi_bb260_11;
  TNode<IntPtrT> phi_bb260_14;
  TNode<BoolT> phi_bb260_15;
  TNode<IntPtrT> phi_bb260_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb260_23;
  TNode<IntPtrT> phi_bb260_24;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb260_25;
  TNode<IntPtrT> phi_bb260_26;
  TNode<IntPtrT> phi_bb260_33;
  TNode<IntPtrT> phi_bb260_34;
  TNode<IntPtrT> phi_bb260_38;
  TNode<IntPtrT> phi_bb260_39;
  if (block260.is_used()) {
    ca_.Bind(&block260, &phi_bb260_8, &phi_bb260_9, &phi_bb260_10, &phi_bb260_11, &phi_bb260_14, &phi_bb260_15, &phi_bb260_21, &phi_bb260_23, &phi_bb260_24, &phi_bb260_25, &phi_bb260_26, &phi_bb260_33, &phi_bb260_34, &phi_bb260_38, &phi_bb260_39);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> phi_bb219_7;
  TNode<IntPtrT> phi_bb219_8;
  TNode<IntPtrT> phi_bb219_9;
  TNode<IntPtrT> phi_bb219_10;
  TNode<IntPtrT> phi_bb219_11;
  TNode<IntPtrT> phi_bb219_14;
  TNode<BoolT> phi_bb219_15;
  TNode<IntPtrT> phi_bb219_21;
  if (block219.is_used()) {
    ca_.Bind(&block219, &phi_bb219_7, &phi_bb219_8, &phi_bb219_9, &phi_bb219_10, &phi_bb219_11, &phi_bb219_14, &phi_bb219_15, &phi_bb219_21);
    ca_.Goto(&block216, phi_bb219_7, phi_bb219_8, phi_bb219_9, phi_bb219_10, phi_bb219_11, phi_bb219_14, phi_bb219_15, phi_bb219_21);
  }

  TNode<IntPtrT> phi_bb215_7;
  TNode<IntPtrT> phi_bb215_8;
  TNode<IntPtrT> phi_bb215_9;
  TNode<IntPtrT> phi_bb215_10;
  TNode<IntPtrT> phi_bb215_11;
  TNode<IntPtrT> phi_bb215_14;
  TNode<BoolT> phi_bb215_15;
  TNode<IntPtrT> phi_bb215_21;
  TNode<Int32T> tmp563;
  TNode<BoolT> tmp564;
  if (block215.is_used()) {
    ca_.Bind(&block215, &phi_bb215_7, &phi_bb215_8, &phi_bb215_9, &phi_bb215_10, &phi_bb215_11, &phi_bb215_14, &phi_bb215_15, &phi_bb215_21);
    tmp563 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmF64.raw_bit_field());
    tmp564 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp353}, TNode<Int32T>{tmp563});
    ca_.Branch(tmp564, &block263, std::vector<compiler::Node*>{phi_bb215_7, phi_bb215_8, phi_bb215_9, phi_bb215_10, phi_bb215_11, phi_bb215_14, phi_bb215_15, phi_bb215_21}, &block264, std::vector<compiler::Node*>{phi_bb215_7, phi_bb215_8, phi_bb215_9, phi_bb215_10, phi_bb215_11, phi_bb215_14, phi_bb215_15, phi_bb215_21});
  }

  TNode<IntPtrT> phi_bb263_7;
  TNode<IntPtrT> phi_bb263_8;
  TNode<IntPtrT> phi_bb263_9;
  TNode<IntPtrT> phi_bb263_10;
  TNode<IntPtrT> phi_bb263_11;
  TNode<IntPtrT> phi_bb263_14;
  TNode<BoolT> phi_bb263_15;
  TNode<IntPtrT> phi_bb263_21;
  TNode<IntPtrT> tmp565;
  TNode<IntPtrT> tmp566;
  TNode<IntPtrT> tmp567;
  TNode<BoolT> tmp568;
  if (block263.is_used()) {
    ca_.Bind(&block263, &phi_bb263_7, &phi_bb263_8, &phi_bb263_9, &phi_bb263_10, &phi_bb263_11, &phi_bb263_14, &phi_bb263_15, &phi_bb263_21);
    tmp565 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp566 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{phi_bb263_8}, TNode<IntPtrT>{tmp565});
    tmp567 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp568 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{phi_bb263_8}, TNode<IntPtrT>{tmp567});
    ca_.Branch(tmp568, &block267, std::vector<compiler::Node*>{phi_bb263_7, phi_bb263_9, phi_bb263_10, phi_bb263_11, phi_bb263_14, phi_bb263_15, phi_bb263_21}, &block268, std::vector<compiler::Node*>{phi_bb263_7, phi_bb263_9, phi_bb263_10, phi_bb263_11, phi_bb263_14, phi_bb263_15, phi_bb263_21});
  }

  TNode<IntPtrT> phi_bb267_7;
  TNode<IntPtrT> phi_bb267_9;
  TNode<IntPtrT> phi_bb267_10;
  TNode<IntPtrT> phi_bb267_11;
  TNode<IntPtrT> phi_bb267_14;
  TNode<BoolT> phi_bb267_15;
  TNode<IntPtrT> phi_bb267_21;
  TNode<Union<HeapObject, TaggedIndex>> tmp569;
  TNode<IntPtrT> tmp570;
  TNode<IntPtrT> tmp571;
  TNode<IntPtrT> tmp572;
  if (block267.is_used()) {
    ca_.Bind(&block267, &phi_bb267_7, &phi_bb267_9, &phi_bb267_10, &phi_bb267_11, &phi_bb267_14, &phi_bb267_15, &phi_bb267_21);
    std::tie(tmp569, tmp570) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp336}, TNode<IntPtrT>{phi_bb267_10}).Flatten();
    tmp571 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_float64_0(state_)));
    tmp572 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb267_10}, TNode<IntPtrT>{tmp571});
    ca_.Goto(&block266, phi_bb267_7, phi_bb267_9, tmp572, phi_bb267_11, phi_bb267_14, phi_bb267_15, phi_bb267_21, tmp569, tmp570);
  }

  TNode<IntPtrT> phi_bb268_7;
  TNode<IntPtrT> phi_bb268_9;
  TNode<IntPtrT> phi_bb268_10;
  TNode<IntPtrT> phi_bb268_11;
  TNode<IntPtrT> phi_bb268_14;
  TNode<BoolT> phi_bb268_15;
  TNode<IntPtrT> phi_bb268_21;
  if (block268.is_used()) {
    ca_.Bind(&block268, &phi_bb268_7, &phi_bb268_9, &phi_bb268_10, &phi_bb268_11, &phi_bb268_14, &phi_bb268_15, &phi_bb268_21);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block269, phi_bb268_7, phi_bb268_9, phi_bb268_10, phi_bb268_11, phi_bb268_14, phi_bb268_15, phi_bb268_21);
    } else {
      ca_.Goto(&block270, phi_bb268_7, phi_bb268_9, phi_bb268_10, phi_bb268_11, phi_bb268_14, phi_bb268_15, phi_bb268_21);
    }
  }

  TNode<IntPtrT> phi_bb269_7;
  TNode<IntPtrT> phi_bb269_9;
  TNode<IntPtrT> phi_bb269_10;
  TNode<IntPtrT> phi_bb269_11;
  TNode<IntPtrT> phi_bb269_14;
  TNode<BoolT> phi_bb269_15;
  TNode<IntPtrT> phi_bb269_21;
  if (block269.is_used()) {
    ca_.Bind(&block269, &phi_bb269_7, &phi_bb269_9, &phi_bb269_10, &phi_bb269_11, &phi_bb269_14, &phi_bb269_15, &phi_bb269_21);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block273, phi_bb269_7, phi_bb269_9, phi_bb269_10, phi_bb269_11, phi_bb269_14, phi_bb269_15, phi_bb269_21);
    } else {
      ca_.Goto(&block274, phi_bb269_7, phi_bb269_9, phi_bb269_10, phi_bb269_11, phi_bb269_14, phi_bb269_15, phi_bb269_21);
    }
  }

  TNode<IntPtrT> phi_bb273_7;
  TNode<IntPtrT> phi_bb273_9;
  TNode<IntPtrT> phi_bb273_10;
  TNode<IntPtrT> phi_bb273_11;
  TNode<IntPtrT> phi_bb273_14;
  TNode<BoolT> phi_bb273_15;
  TNode<IntPtrT> phi_bb273_21;
  TNode<Union<HeapObject, TaggedIndex>> tmp573;
  TNode<IntPtrT> tmp574;
  TNode<IntPtrT> tmp575;
  TNode<IntPtrT> tmp576;
  if (block273.is_used()) {
    ca_.Bind(&block273, &phi_bb273_7, &phi_bb273_9, &phi_bb273_10, &phi_bb273_11, &phi_bb273_14, &phi_bb273_15, &phi_bb273_21);
    std::tie(tmp573, tmp574) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp336}, TNode<IntPtrT>{phi_bb273_11}).Flatten();
    tmp575 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp576 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb273_11}, TNode<IntPtrT>{tmp575});
    ca_.Goto(&block272, phi_bb273_7, phi_bb273_9, phi_bb273_10, tmp576, phi_bb273_14, phi_bb273_15, phi_bb273_21, tmp573, tmp574);
  }

  TNode<IntPtrT> phi_bb274_7;
  TNode<IntPtrT> phi_bb274_9;
  TNode<IntPtrT> phi_bb274_10;
  TNode<IntPtrT> phi_bb274_11;
  TNode<IntPtrT> phi_bb274_14;
  TNode<BoolT> phi_bb274_15;
  TNode<IntPtrT> phi_bb274_21;
  TNode<IntPtrT> tmp577;
  TNode<BoolT> tmp578;
  if (block274.is_used()) {
    ca_.Bind(&block274, &phi_bb274_7, &phi_bb274_9, &phi_bb274_10, &phi_bb274_11, &phi_bb274_14, &phi_bb274_15, &phi_bb274_21);
    tmp577 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp578 = CodeStubAssembler(state_).WordNotEqual(TNode<IntPtrT>{phi_bb274_14}, TNode<IntPtrT>{tmp577});
    ca_.Branch(tmp578, &block276, std::vector<compiler::Node*>{phi_bb274_7, phi_bb274_9, phi_bb274_10, phi_bb274_11, phi_bb274_14, phi_bb274_15, phi_bb274_21}, &block277, std::vector<compiler::Node*>{phi_bb274_7, phi_bb274_9, phi_bb274_10, phi_bb274_11, phi_bb274_14, phi_bb274_15, phi_bb274_21});
  }

  TNode<IntPtrT> phi_bb276_7;
  TNode<IntPtrT> phi_bb276_9;
  TNode<IntPtrT> phi_bb276_10;
  TNode<IntPtrT> phi_bb276_11;
  TNode<IntPtrT> phi_bb276_14;
  TNode<BoolT> phi_bb276_15;
  TNode<IntPtrT> phi_bb276_21;
  TNode<Union<HeapObject, TaggedIndex>> tmp579;
  TNode<IntPtrT> tmp580;
  TNode<IntPtrT> tmp581;
  TNode<BoolT> tmp582;
  if (block276.is_used()) {
    ca_.Bind(&block276, &phi_bb276_7, &phi_bb276_9, &phi_bb276_10, &phi_bb276_11, &phi_bb276_14, &phi_bb276_15, &phi_bb276_21);
    std::tie(tmp579, tmp580) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp336}, TNode<IntPtrT>{phi_bb276_14}).Flatten();
    tmp581 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp582 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block272, phi_bb276_7, phi_bb276_9, phi_bb276_10, phi_bb276_11, tmp581, tmp582, phi_bb276_21, tmp579, tmp580);
  }

  TNode<IntPtrT> phi_bb277_7;
  TNode<IntPtrT> phi_bb277_9;
  TNode<IntPtrT> phi_bb277_10;
  TNode<IntPtrT> phi_bb277_11;
  TNode<IntPtrT> phi_bb277_14;
  TNode<BoolT> phi_bb277_15;
  TNode<IntPtrT> phi_bb277_21;
  TNode<Union<HeapObject, TaggedIndex>> tmp583;
  TNode<IntPtrT> tmp584;
  TNode<IntPtrT> tmp585;
  TNode<IntPtrT> tmp586;
  TNode<IntPtrT> tmp587;
  TNode<IntPtrT> tmp588;
  TNode<BoolT> tmp589;
  if (block277.is_used()) {
    ca_.Bind(&block277, &phi_bb277_7, &phi_bb277_9, &phi_bb277_10, &phi_bb277_11, &phi_bb277_14, &phi_bb277_15, &phi_bb277_21);
    std::tie(tmp583, tmp584) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp336}, TNode<IntPtrT>{phi_bb277_11}).Flatten();
    tmp585 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp586 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb277_11}, TNode<IntPtrT>{tmp585});
    tmp587 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp588 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp586}, TNode<IntPtrT>{tmp587});
    tmp589 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block272, phi_bb277_7, phi_bb277_9, phi_bb277_10, tmp588, tmp586, tmp589, phi_bb277_21, tmp583, tmp584);
  }

  TNode<IntPtrT> phi_bb272_7;
  TNode<IntPtrT> phi_bb272_9;
  TNode<IntPtrT> phi_bb272_10;
  TNode<IntPtrT> phi_bb272_11;
  TNode<IntPtrT> phi_bb272_14;
  TNode<BoolT> phi_bb272_15;
  TNode<IntPtrT> phi_bb272_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb272_23;
  TNode<IntPtrT> phi_bb272_24;
  if (block272.is_used()) {
    ca_.Bind(&block272, &phi_bb272_7, &phi_bb272_9, &phi_bb272_10, &phi_bb272_11, &phi_bb272_14, &phi_bb272_15, &phi_bb272_21, &phi_bb272_23, &phi_bb272_24);
    ca_.Goto(&block266, phi_bb272_7, phi_bb272_9, phi_bb272_10, phi_bb272_11, phi_bb272_14, phi_bb272_15, phi_bb272_21, phi_bb272_23, phi_bb272_24);
  }

  TNode<IntPtrT> phi_bb270_7;
  TNode<IntPtrT> phi_bb270_9;
  TNode<IntPtrT> phi_bb270_10;
  TNode<IntPtrT> phi_bb270_11;
  TNode<IntPtrT> phi_bb270_14;
  TNode<BoolT> phi_bb270_15;
  TNode<IntPtrT> phi_bb270_21;
  TNode<Union<HeapObject, TaggedIndex>> tmp590;
  TNode<IntPtrT> tmp591;
  TNode<IntPtrT> tmp592;
  TNode<IntPtrT> tmp593;
  TNode<BoolT> tmp594;
  if (block270.is_used()) {
    ca_.Bind(&block270, &phi_bb270_7, &phi_bb270_9, &phi_bb270_10, &phi_bb270_11, &phi_bb270_14, &phi_bb270_15, &phi_bb270_21);
    std::tie(tmp590, tmp591) = NewReference_intptr_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp336}, TNode<IntPtrT>{phi_bb270_11}).Flatten();
    tmp592 = FromConstexpr_intptr_constexpr_int31_0(state_, (CodeStubAssembler(state_).ConstexprInt31Mul((FromConstexpr_constexpr_int31_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull))), (SizeOf_intptr_0(state_)))));
    tmp593 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb270_11}, TNode<IntPtrT>{tmp592});
    tmp594 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block266, phi_bb270_7, phi_bb270_9, phi_bb270_10, tmp593, phi_bb270_14, tmp594, phi_bb270_21, tmp590, tmp591);
  }

  TNode<IntPtrT> phi_bb266_7;
  TNode<IntPtrT> phi_bb266_9;
  TNode<IntPtrT> phi_bb266_10;
  TNode<IntPtrT> phi_bb266_11;
  TNode<IntPtrT> phi_bb266_14;
  TNode<BoolT> phi_bb266_15;
  TNode<IntPtrT> phi_bb266_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb266_23;
  TNode<IntPtrT> phi_bb266_24;
  TNode<Union<HeapObject, TaggedIndex>> tmp595;
  TNode<IntPtrT> tmp596;
  TNode<Float64T> tmp597;
  TNode<Union<HeapObject, TaggedIndex>> tmp598;
  TNode<IntPtrT> tmp599;
  TNode<IntPtrT> tmp600;
  TNode<UintPtrT> tmp601;
  TNode<UintPtrT> tmp602;
  TNode<BoolT> tmp603;
  if (block266.is_used()) {
    ca_.Bind(&block266, &phi_bb266_7, &phi_bb266_9, &phi_bb266_10, &phi_bb266_11, &phi_bb266_14, &phi_bb266_15, &phi_bb266_21, &phi_bb266_23, &phi_bb266_24);
    std::tie(tmp595, tmp596) = RefCast_float64_0(state_, TorqueStructReference_intptr_0{TNode<Union<HeapObject, TaggedIndex>>{phi_bb266_23}, TNode<IntPtrT>{phi_bb266_24}, TorqueStructUnsafe_0{}}).Flatten();
    tmp597 = CodeStubAssembler(state_).LoadReference<Float64T>(CodeStubAssembler::Reference{tmp595, tmp596});
    std::tie(tmp598, tmp599, tmp600) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{tmp92}).Flatten();
    tmp601 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{phi_bb266_21});
    tmp602 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp600});
    tmp603 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp601}, TNode<UintPtrT>{tmp602});
    ca_.Branch(tmp603, &block282, std::vector<compiler::Node*>{phi_bb266_7, phi_bb266_9, phi_bb266_10, phi_bb266_11, phi_bb266_14, phi_bb266_15, phi_bb266_21, phi_bb266_23, phi_bb266_24, phi_bb266_21, phi_bb266_21, phi_bb266_21, phi_bb266_21}, &block283, std::vector<compiler::Node*>{phi_bb266_7, phi_bb266_9, phi_bb266_10, phi_bb266_11, phi_bb266_14, phi_bb266_15, phi_bb266_21, phi_bb266_23, phi_bb266_24, phi_bb266_21, phi_bb266_21, phi_bb266_21, phi_bb266_21});
  }

  TNode<IntPtrT> phi_bb282_7;
  TNode<IntPtrT> phi_bb282_9;
  TNode<IntPtrT> phi_bb282_10;
  TNode<IntPtrT> phi_bb282_11;
  TNode<IntPtrT> phi_bb282_14;
  TNode<BoolT> phi_bb282_15;
  TNode<IntPtrT> phi_bb282_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb282_23;
  TNode<IntPtrT> phi_bb282_24;
  TNode<IntPtrT> phi_bb282_30;
  TNode<IntPtrT> phi_bb282_31;
  TNode<IntPtrT> phi_bb282_35;
  TNode<IntPtrT> phi_bb282_36;
  TNode<IntPtrT> tmp604;
  TNode<IntPtrT> tmp605;
  TNode<Union<HeapObject, TaggedIndex>> tmp606;
  TNode<IntPtrT> tmp607;
  TNode<Number> tmp608;
  if (block282.is_used()) {
    ca_.Bind(&block282, &phi_bb282_7, &phi_bb282_9, &phi_bb282_10, &phi_bb282_11, &phi_bb282_14, &phi_bb282_15, &phi_bb282_21, &phi_bb282_23, &phi_bb282_24, &phi_bb282_30, &phi_bb282_31, &phi_bb282_35, &phi_bb282_36);
    tmp604 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{phi_bb282_36});
    tmp605 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp599}, TNode<IntPtrT>{tmp604});
    std::tie(tmp606, tmp607) = NewReference_Object_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp598}, TNode<IntPtrT>{tmp605}).Flatten();
    tmp608 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp597});
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp606, tmp607}, tmp608);
    ca_.Goto(&block265, phi_bb282_7, tmp566, phi_bb282_9, phi_bb282_10, phi_bb282_11, phi_bb282_14, phi_bb282_15, phi_bb282_21);
  }

  TNode<IntPtrT> phi_bb283_7;
  TNode<IntPtrT> phi_bb283_9;
  TNode<IntPtrT> phi_bb283_10;
  TNode<IntPtrT> phi_bb283_11;
  TNode<IntPtrT> phi_bb283_14;
  TNode<BoolT> phi_bb283_15;
  TNode<IntPtrT> phi_bb283_21;
  TNode<Union<HeapObject, TaggedIndex>> phi_bb283_23;
  TNode<IntPtrT> phi_bb283_24;
  TNode<IntPtrT> phi_bb283_30;
  TNode<IntPtrT> phi_bb283_31;
  TNode<IntPtrT> phi_bb283_35;
  TNode<IntPtrT> phi_bb283_36;
  if (block283.is_used()) {
    ca_.Bind(&block283, &phi_bb283_7, &phi_bb283_9, &phi_bb283_10, &phi_bb283_11, &phi_bb283_14, &phi_bb283_15, &phi_bb283_21, &phi_bb283_23, &phi_bb283_24, &phi_bb283_30, &phi_bb283_31, &phi_bb283_35, &phi_bb283_36);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> phi_bb264_7;
  TNode<IntPtrT> phi_bb264_8;
  TNode<IntPtrT> phi_bb264_9;
  TNode<IntPtrT> phi_bb264_10;
  TNode<IntPtrT> phi_bb264_11;
  TNode<IntPtrT> phi_bb264_14;
  TNode<BoolT> phi_bb264_15;
  TNode<IntPtrT> phi_bb264_21;
  TNode<Int32T> tmp609;
  TNode<Int32T> tmp610;
  TNode<Int32T> tmp611;
  TNode<BoolT> tmp612;
  if (block264.is_used()) {
    ca_.Bind(&block264, &phi_bb264_7, &phi_bb264_8, &phi_bb264_9, &phi_bb264_10, &phi_bb264_11, &phi_bb264_14, &phi_bb264_15, &phi_bb264_21);
    tmp609 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmValueKindBitsMask);
    tmp610 = CodeStubAssembler(state_).Word32And(TNode<Int32T>{tmp353}, TNode<Int32T>{tmp609});
    tmp611 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::ValueKind::kRef);
    tmp612 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp610}, TNode<Int32T>{tmp611});
    ca_.Branch(tmp612, &block288, std::vector<compiler::Node*>{phi_bb264_7, phi_bb264_8, phi_bb264_9, phi_bb264_10, phi_bb264_11, phi_bb264_14, phi_bb264_15, phi_bb264_21}, &block289, std::vector<compiler::Node*>{phi_bb264_7, phi_bb264_8, phi_bb264_9, phi_bb264_10, phi_bb264_11, phi_bb264_14, phi_bb264_15, phi_bb264_21});
  }

  TNode<IntPtrT> phi_bb288_7;
  TNode<IntPtrT> phi_bb288_8;
  TNode<IntPtrT> phi_bb288_9;
  TNode<IntPtrT> phi_bb288_10;
  TNode<IntPtrT> phi_bb288_11;
  TNode<IntPtrT> phi_bb288_14;
  TNode<BoolT> phi_bb288_15;
  TNode<IntPtrT> phi_bb288_21;
  TNode<BoolT> tmp613;
  if (block288.is_used()) {
    ca_.Bind(&block288, &phi_bb288_7, &phi_bb288_8, &phi_bb288_9, &phi_bb288_10, &phi_bb288_11, &phi_bb288_14, &phi_bb288_15, &phi_bb288_21);
    tmp613 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block290, phi_bb288_7, phi_bb288_8, phi_bb288_9, phi_bb288_10, phi_bb288_11, phi_bb288_14, phi_bb288_15, phi_bb288_21, tmp613);
  }

  TNode<IntPtrT> phi_bb289_7;
  TNode<IntPtrT> phi_bb289_8;
  TNode<IntPtrT> phi_bb289_9;
  TNode<IntPtrT> phi_bb289_10;
  TNode<IntPtrT> phi_bb289_11;
  TNode<IntPtrT> phi_bb289_14;
  TNode<BoolT> phi_bb289_15;
  TNode<IntPtrT> phi_bb289_21;
  TNode<Int32T> tmp614;
  TNode<BoolT> tmp615;
  if (block289.is_used()) {
    ca_.Bind(&block289, &phi_bb289_7, &phi_bb289_8, &phi_bb289_9, &phi_bb289_10, &phi_bb289_11, &phi_bb289_14, &phi_bb289_15, &phi_bb289_21);
    tmp614 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::ValueKind::kRefNull);
    tmp615 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp610}, TNode<Int32T>{tmp614});
    ca_.Goto(&block290, phi_bb289_7, phi_bb289_8, phi_bb289_9, phi_bb289_10, phi_bb289_11, phi_bb289_14, phi_bb289_15, phi_bb289_21, tmp615);
  }

  TNode<IntPtrT> phi_bb290_7;
  TNode<IntPtrT> phi_bb290_8;
  TNode<IntPtrT> phi_bb290_9;
  TNode<IntPtrT> phi_bb290_10;
  TNode<IntPtrT> phi_bb290_11;
  TNode<IntPtrT> phi_bb290_14;
  TNode<BoolT> phi_bb290_15;
  TNode<IntPtrT> phi_bb290_21;
  TNode<BoolT> phi_bb290_25;
  if (block290.is_used()) {
    ca_.Bind(&block290, &phi_bb290_7, &phi_bb290_8, &phi_bb290_9, &phi_bb290_10, &phi_bb290_11, &phi_bb290_14, &phi_bb290_15, &phi_bb290_21, &phi_bb290_25);
    ca_.Branch(phi_bb290_25, &block286, std::vector<compiler::Node*>{phi_bb290_7, phi_bb290_8, phi_bb290_9, phi_bb290_10, phi_bb290_11, phi_bb290_14, phi_bb290_15, phi_bb290_21}, &block287, std::vector<compiler::Node*>{phi_bb290_7, phi_bb290_8, phi_bb290_9, phi_bb290_10, phi_bb290_11, phi_bb290_14, phi_bb290_15, phi_bb290_21});
  }

  TNode<IntPtrT> phi_bb287_7;
  TNode<IntPtrT> phi_bb287_8;
  TNode<IntPtrT> phi_bb287_9;
  TNode<IntPtrT> phi_bb287_10;
  TNode<IntPtrT> phi_bb287_11;
  TNode<IntPtrT> phi_bb287_14;
  TNode<BoolT> phi_bb287_15;
  TNode<IntPtrT> phi_bb287_21;
  if (block287.is_used()) {
    ca_.Bind(&block287, &phi_bb287_7, &phi_bb287_8, &phi_bb287_9, &phi_bb287_10, &phi_bb287_11, &phi_bb287_14, &phi_bb287_15, &phi_bb287_21);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/js-to-wasm.tq", 1065});
      CodeStubAssembler(state_).FailAssert("Torque assert 'retKind == ValueKind::kRef || retKind == ValueKind::kRefNull' failed", pos_stack);
    }
  }

  TNode<IntPtrT> phi_bb286_7;
  TNode<IntPtrT> phi_bb286_8;
  TNode<IntPtrT> phi_bb286_9;
  TNode<IntPtrT> phi_bb286_10;
  TNode<IntPtrT> phi_bb286_11;
  TNode<IntPtrT> phi_bb286_14;
  TNode<BoolT> phi_bb286_15;
  TNode<IntPtrT> phi_bb286_21;
  TNode<Union<HeapObject, TaggedIndex>> tmp616;
  TNode<IntPtrT> tmp617;
  TNode<IntPtrT> tmp618;
  TNode<UintPtrT> tmp619;
  TNode<UintPtrT> tmp620;
  TNode<BoolT> tmp621;
  if (block286.is_used()) {
    ca_.Bind(&block286, &phi_bb286_7, &phi_bb286_8, &phi_bb286_9, &phi_bb286_10, &phi_bb286_11, &phi_bb286_14, &phi_bb286_15, &phi_bb286_21);
    std::tie(tmp616, tmp617, tmp618) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{tmp92}).Flatten();
    tmp619 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{phi_bb286_21});
    tmp620 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp618});
    tmp621 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp619}, TNode<UintPtrT>{tmp620});
    ca_.Branch(tmp621, &block295, std::vector<compiler::Node*>{phi_bb286_7, phi_bb286_8, phi_bb286_9, phi_bb286_10, phi_bb286_11, phi_bb286_14, phi_bb286_15, phi_bb286_21, phi_bb286_21, phi_bb286_21, phi_bb286_21, phi_bb286_21}, &block296, std::vector<compiler::Node*>{phi_bb286_7, phi_bb286_8, phi_bb286_9, phi_bb286_10, phi_bb286_11, phi_bb286_14, phi_bb286_15, phi_bb286_21, phi_bb286_21, phi_bb286_21, phi_bb286_21, phi_bb286_21});
  }

  TNode<IntPtrT> phi_bb295_7;
  TNode<IntPtrT> phi_bb295_8;
  TNode<IntPtrT> phi_bb295_9;
  TNode<IntPtrT> phi_bb295_10;
  TNode<IntPtrT> phi_bb295_11;
  TNode<IntPtrT> phi_bb295_14;
  TNode<BoolT> phi_bb295_15;
  TNode<IntPtrT> phi_bb295_21;
  TNode<IntPtrT> phi_bb295_28;
  TNode<IntPtrT> phi_bb295_29;
  TNode<IntPtrT> phi_bb295_33;
  TNode<IntPtrT> phi_bb295_34;
  TNode<IntPtrT> tmp622;
  TNode<IntPtrT> tmp623;
  TNode<Union<HeapObject, TaggedIndex>> tmp624;
  TNode<IntPtrT> tmp625;
  TNode<Object> tmp626;
  TNode<Union<HeapObject, TaggedIndex>> tmp627;
  TNode<IntPtrT> tmp628;
  TNode<IntPtrT> tmp629;
  TNode<UintPtrT> tmp630;
  TNode<UintPtrT> tmp631;
  TNode<BoolT> tmp632;
  if (block295.is_used()) {
    ca_.Bind(&block295, &phi_bb295_7, &phi_bb295_8, &phi_bb295_9, &phi_bb295_10, &phi_bb295_11, &phi_bb295_14, &phi_bb295_15, &phi_bb295_21, &phi_bb295_28, &phi_bb295_29, &phi_bb295_33, &phi_bb295_34);
    tmp622 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{phi_bb295_34});
    tmp623 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp617}, TNode<IntPtrT>{tmp622});
    std::tie(tmp624, tmp625) = NewReference_Object_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp616}, TNode<IntPtrT>{tmp623}).Flatten();
    tmp626 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp624, tmp625});
    std::tie(tmp627, tmp628, tmp629) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{tmp92}).Flatten();
    tmp630 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{phi_bb295_21});
    tmp631 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp629});
    tmp632 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp630}, TNode<UintPtrT>{tmp631});
    ca_.Branch(tmp632, &block303, std::vector<compiler::Node*>{phi_bb295_7, phi_bb295_8, phi_bb295_9, phi_bb295_10, phi_bb295_11, phi_bb295_14, phi_bb295_15, phi_bb295_21, phi_bb295_21, phi_bb295_21, phi_bb295_21, phi_bb295_21}, &block304, std::vector<compiler::Node*>{phi_bb295_7, phi_bb295_8, phi_bb295_9, phi_bb295_10, phi_bb295_11, phi_bb295_14, phi_bb295_15, phi_bb295_21, phi_bb295_21, phi_bb295_21, phi_bb295_21, phi_bb295_21});
  }

  TNode<IntPtrT> phi_bb296_7;
  TNode<IntPtrT> phi_bb296_8;
  TNode<IntPtrT> phi_bb296_9;
  TNode<IntPtrT> phi_bb296_10;
  TNode<IntPtrT> phi_bb296_11;
  TNode<IntPtrT> phi_bb296_14;
  TNode<BoolT> phi_bb296_15;
  TNode<IntPtrT> phi_bb296_21;
  TNode<IntPtrT> phi_bb296_28;
  TNode<IntPtrT> phi_bb296_29;
  TNode<IntPtrT> phi_bb296_33;
  TNode<IntPtrT> phi_bb296_34;
  if (block296.is_used()) {
    ca_.Bind(&block296, &phi_bb296_7, &phi_bb296_8, &phi_bb296_9, &phi_bb296_10, &phi_bb296_11, &phi_bb296_14, &phi_bb296_15, &phi_bb296_21, &phi_bb296_28, &phi_bb296_29, &phi_bb296_33, &phi_bb296_34);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> phi_bb303_7;
  TNode<IntPtrT> phi_bb303_8;
  TNode<IntPtrT> phi_bb303_9;
  TNode<IntPtrT> phi_bb303_10;
  TNode<IntPtrT> phi_bb303_11;
  TNode<IntPtrT> phi_bb303_14;
  TNode<BoolT> phi_bb303_15;
  TNode<IntPtrT> phi_bb303_21;
  TNode<IntPtrT> phi_bb303_29;
  TNode<IntPtrT> phi_bb303_30;
  TNode<IntPtrT> phi_bb303_34;
  TNode<IntPtrT> phi_bb303_35;
  TNode<IntPtrT> tmp633;
  TNode<IntPtrT> tmp634;
  TNode<Union<HeapObject, TaggedIndex>> tmp635;
  TNode<IntPtrT> tmp636;
  TNode<JSAny> tmp637;
  if (block303.is_used()) {
    ca_.Bind(&block303, &phi_bb303_7, &phi_bb303_8, &phi_bb303_9, &phi_bb303_10, &phi_bb303_11, &phi_bb303_14, &phi_bb303_15, &phi_bb303_21, &phi_bb303_29, &phi_bb303_30, &phi_bb303_34, &phi_bb303_35);
    tmp633 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{phi_bb303_35});
    tmp634 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp628}, TNode<IntPtrT>{tmp633});
    std::tie(tmp635, tmp636) = NewReference_Object_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp627}, TNode<IntPtrT>{tmp634}).Flatten();
    tmp637 = WasmToJSObject_0(state_, TNode<NativeContext>{parameter0}, TNode<Object>{tmp626}, TNode<Int32T>{tmp353});
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp635, tmp636}, tmp637);
    ca_.Goto(&block265, phi_bb303_7, phi_bb303_8, phi_bb303_9, phi_bb303_10, phi_bb303_11, phi_bb303_14, phi_bb303_15, phi_bb303_21);
  }

  TNode<IntPtrT> phi_bb304_7;
  TNode<IntPtrT> phi_bb304_8;
  TNode<IntPtrT> phi_bb304_9;
  TNode<IntPtrT> phi_bb304_10;
  TNode<IntPtrT> phi_bb304_11;
  TNode<IntPtrT> phi_bb304_14;
  TNode<BoolT> phi_bb304_15;
  TNode<IntPtrT> phi_bb304_21;
  TNode<IntPtrT> phi_bb304_29;
  TNode<IntPtrT> phi_bb304_30;
  TNode<IntPtrT> phi_bb304_34;
  TNode<IntPtrT> phi_bb304_35;
  if (block304.is_used()) {
    ca_.Bind(&block304, &phi_bb304_7, &phi_bb304_8, &phi_bb304_9, &phi_bb304_10, &phi_bb304_11, &phi_bb304_14, &phi_bb304_15, &phi_bb304_21, &phi_bb304_29, &phi_bb304_30, &phi_bb304_34, &phi_bb304_35);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> phi_bb265_7;
  TNode<IntPtrT> phi_bb265_8;
  TNode<IntPtrT> phi_bb265_9;
  TNode<IntPtrT> phi_bb265_10;
  TNode<IntPtrT> phi_bb265_11;
  TNode<IntPtrT> phi_bb265_14;
  TNode<BoolT> phi_bb265_15;
  TNode<IntPtrT> phi_bb265_21;
  if (block265.is_used()) {
    ca_.Bind(&block265, &phi_bb265_7, &phi_bb265_8, &phi_bb265_9, &phi_bb265_10, &phi_bb265_11, &phi_bb265_14, &phi_bb265_15, &phi_bb265_21);
    ca_.Goto(&block216, phi_bb265_7, phi_bb265_8, phi_bb265_9, phi_bb265_10, phi_bb265_11, phi_bb265_14, phi_bb265_15, phi_bb265_21);
  }

  TNode<IntPtrT> phi_bb216_7;
  TNode<IntPtrT> phi_bb216_8;
  TNode<IntPtrT> phi_bb216_9;
  TNode<IntPtrT> phi_bb216_10;
  TNode<IntPtrT> phi_bb216_11;
  TNode<IntPtrT> phi_bb216_14;
  TNode<BoolT> phi_bb216_15;
  TNode<IntPtrT> phi_bb216_21;
  if (block216.is_used()) {
    ca_.Bind(&block216, &phi_bb216_7, &phi_bb216_8, &phi_bb216_9, &phi_bb216_10, &phi_bb216_11, &phi_bb216_14, &phi_bb216_15, &phi_bb216_21);
    ca_.Goto(&block182, phi_bb216_7, phi_bb216_8, phi_bb216_9, phi_bb216_10, phi_bb216_11, phi_bb216_14, phi_bb216_15, phi_bb216_21);
  }

  TNode<IntPtrT> phi_bb182_7;
  TNode<IntPtrT> phi_bb182_8;
  TNode<IntPtrT> phi_bb182_9;
  TNode<IntPtrT> phi_bb182_10;
  TNode<IntPtrT> phi_bb182_11;
  TNode<IntPtrT> phi_bb182_14;
  TNode<BoolT> phi_bb182_15;
  TNode<IntPtrT> phi_bb182_21;
  if (block182.is_used()) {
    ca_.Bind(&block182, &phi_bb182_7, &phi_bb182_8, &phi_bb182_9, &phi_bb182_10, &phi_bb182_11, &phi_bb182_14, &phi_bb182_15, &phi_bb182_21);
    ca_.Goto(&block159, phi_bb182_7, phi_bb182_8, phi_bb182_9, phi_bb182_10, phi_bb182_11, phi_bb182_14, phi_bb182_15, phi_bb182_21);
  }

  TNode<IntPtrT> phi_bb159_7;
  TNode<IntPtrT> phi_bb159_8;
  TNode<IntPtrT> phi_bb159_9;
  TNode<IntPtrT> phi_bb159_10;
  TNode<IntPtrT> phi_bb159_11;
  TNode<IntPtrT> phi_bb159_14;
  TNode<BoolT> phi_bb159_15;
  TNode<IntPtrT> phi_bb159_21;
  TNode<IntPtrT> tmp638;
  TNode<IntPtrT> tmp639;
  if (block159.is_used()) {
    ca_.Bind(&block159, &phi_bb159_7, &phi_bb159_8, &phi_bb159_9, &phi_bb159_10, &phi_bb159_11, &phi_bb159_14, &phi_bb159_15, &phi_bb159_21);
    tmp638 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp639 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb159_21}, TNode<IntPtrT>{tmp638});
    ca_.Goto(&block154, phi_bb159_7, phi_bb159_8, phi_bb159_9, phi_bb159_10, phi_bb159_11, phi_bb159_14, phi_bb159_15, tmp639);
  }

  TNode<IntPtrT> phi_bb153_7;
  TNode<IntPtrT> phi_bb153_8;
  TNode<IntPtrT> phi_bb153_9;
  TNode<IntPtrT> phi_bb153_10;
  TNode<IntPtrT> phi_bb153_11;
  TNode<IntPtrT> phi_bb153_14;
  TNode<BoolT> phi_bb153_15;
  TNode<IntPtrT> phi_bb153_21;
  TNode<IntPtrT> tmp640;
  TNode<BoolT> tmp641;
  if (block153.is_used()) {
    ca_.Bind(&block153, &phi_bb153_7, &phi_bb153_8, &phi_bb153_9, &phi_bb153_10, &phi_bb153_11, &phi_bb153_14, &phi_bb153_15, &phi_bb153_21);
    tmp640 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp641 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp343}, TNode<IntPtrT>{tmp640});
    ca_.Branch(tmp641, &block310, std::vector<compiler::Node*>{phi_bb153_7, phi_bb153_8, phi_bb153_9, phi_bb153_10, phi_bb153_11, phi_bb153_14, phi_bb153_15}, &block311, std::vector<compiler::Node*>{phi_bb153_7, phi_bb153_8, phi_bb153_9, phi_bb153_10, phi_bb153_11, phi_bb153_14, phi_bb153_15});
  }

  TNode<IntPtrT> phi_bb310_7;
  TNode<IntPtrT> phi_bb310_8;
  TNode<IntPtrT> phi_bb310_9;
  TNode<IntPtrT> phi_bb310_10;
  TNode<IntPtrT> phi_bb310_11;
  TNode<IntPtrT> phi_bb310_14;
  TNode<BoolT> phi_bb310_15;
  TNode<BoolT> tmp642;
  if (block310.is_used()) {
    ca_.Bind(&block310, &phi_bb310_7, &phi_bb310_8, &phi_bb310_9, &phi_bb310_10, &phi_bb310_11, &phi_bb310_14, &phi_bb310_15);
    tmp642 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block312, phi_bb310_7, phi_bb310_8, phi_bb310_9, phi_bb310_10, phi_bb310_11, phi_bb310_14, phi_bb310_15, tmp642);
  }

  TNode<IntPtrT> phi_bb311_7;
  TNode<IntPtrT> phi_bb311_8;
  TNode<IntPtrT> phi_bb311_9;
  TNode<IntPtrT> phi_bb311_10;
  TNode<IntPtrT> phi_bb311_11;
  TNode<IntPtrT> phi_bb311_14;
  TNode<BoolT> phi_bb311_15;
  TNode<BoolT> tmp643;
  if (block311.is_used()) {
    ca_.Bind(&block311, &phi_bb311_7, &phi_bb311_8, &phi_bb311_9, &phi_bb311_10, &phi_bb311_11, &phi_bb311_14, &phi_bb311_15);
    tmp643 = CodeStubAssembler(state_).IntPtrLessThanOrEqual(TNode<IntPtrT>{phi_bb311_11}, TNode<IntPtrT>{tmp343});
    ca_.Goto(&block312, phi_bb311_7, phi_bb311_8, phi_bb311_9, phi_bb311_10, phi_bb311_11, phi_bb311_14, phi_bb311_15, tmp643);
  }

  TNode<IntPtrT> phi_bb312_7;
  TNode<IntPtrT> phi_bb312_8;
  TNode<IntPtrT> phi_bb312_9;
  TNode<IntPtrT> phi_bb312_10;
  TNode<IntPtrT> phi_bb312_11;
  TNode<IntPtrT> phi_bb312_14;
  TNode<BoolT> phi_bb312_15;
  TNode<BoolT> phi_bb312_22;
  if (block312.is_used()) {
    ca_.Bind(&block312, &phi_bb312_7, &phi_bb312_8, &phi_bb312_9, &phi_bb312_10, &phi_bb312_11, &phi_bb312_14, &phi_bb312_15, &phi_bb312_22);
    ca_.Branch(phi_bb312_22, &block308, std::vector<compiler::Node*>{phi_bb312_7, phi_bb312_8, phi_bb312_9, phi_bb312_10, phi_bb312_11, phi_bb312_14, phi_bb312_15}, &block309, std::vector<compiler::Node*>{phi_bb312_7, phi_bb312_8, phi_bb312_9, phi_bb312_10, phi_bb312_11, phi_bb312_14, phi_bb312_15});
  }

  TNode<IntPtrT> phi_bb309_7;
  TNode<IntPtrT> phi_bb309_8;
  TNode<IntPtrT> phi_bb309_9;
  TNode<IntPtrT> phi_bb309_10;
  TNode<IntPtrT> phi_bb309_11;
  TNode<IntPtrT> phi_bb309_14;
  TNode<BoolT> phi_bb309_15;
  if (block309.is_used()) {
    ca_.Bind(&block309, &phi_bb309_7, &phi_bb309_8, &phi_bb309_9, &phi_bb309_10, &phi_bb309_11, &phi_bb309_14, &phi_bb309_15);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/js-to-wasm.tq", 379});
      CodeStubAssembler(state_).FailAssert("Torque assert 'this.paramBufferEnd == 0 || this.nextStack <= this.paramBufferEnd' failed", pos_stack);
    }
  }

  TNode<IntPtrT> phi_bb308_7;
  TNode<IntPtrT> phi_bb308_8;
  TNode<IntPtrT> phi_bb308_9;
  TNode<IntPtrT> phi_bb308_10;
  TNode<IntPtrT> phi_bb308_11;
  TNode<IntPtrT> phi_bb308_14;
  TNode<BoolT> phi_bb308_15;
  if (block308.is_used()) {
    ca_.Bind(&block308, &phi_bb308_7, &phi_bb308_8, &phi_bb308_9, &phi_bb308_10, &phi_bb308_11, &phi_bb308_14, &phi_bb308_15);
    CodeStubAssembler(state_).Return(parameter1);
  }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=420&c=32
int31_t SizeOf_float64_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return kDoubleSize;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=487&c=8
TorqueStructReference_float64_0 RefCast_float64_0(compiler::CodeAssemblerState* state_, TorqueStructReference_intptr_0 p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Union<HeapObject, TaggedIndex>> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    std::tie(tmp0, tmp1) = NewReference_float64_0(state_, TNode<Union<HeapObject, TaggedIndex>>{p_i.object}, TNode<IntPtrT>{p_i.offset}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReference_float64_0{TNode<Union<HeapObject, TaggedIndex>>{tmp0}, TNode<IntPtrT>{tmp1}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=490&c=8
TorqueStructReference_float32_0 RefCast_float32_0(compiler::CodeAssemblerState* state_, TorqueStructReference_intptr_0 p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Union<HeapObject, TaggedIndex>> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    std::tie(tmp0, tmp1) = NewReference_float32_0(state_, TNode<Union<HeapObject, TaggedIndex>>{p_i.object}, TNode<IntPtrT>{p_i.offset}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReference_float32_0{TNode<Union<HeapObject, TaggedIndex>>{tmp0}, TNode<IntPtrT>{tmp1}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=526&c=30
TorqueStructReference_intptr_0 GetRefAt_intptr_RawFunctionSigPtr_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_base, TNode<IntPtrT> p_offset) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<RawPtrT> tmp0;
  TNode<RawPtrT> tmp1;
  TNode<Union<HeapObject, TaggedIndex>> tmp2;
  TNode<IntPtrT> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).RawPtrAdd(TNode<RawPtrT>{p_base}, TNode<IntPtrT>{p_offset});
    tmp1 = (TNode<RawPtrT>{tmp0});
    std::tie(tmp2, tmp3) = NewOffHeapReference_intptr_0(state_, TNode<RawPtrT>{tmp1}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReference_intptr_0{TNode<Union<HeapObject, TaggedIndex>>{tmp2}, TNode<IntPtrT>{tmp3}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=531&c=17
TorqueStructReference_RawPtr_0 GetRefAt_RawPtr_RawFunctionSigPtr_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_base, TNode<IntPtrT> p_offset) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<RawPtrT> tmp0;
  TNode<RawPtrT> tmp1;
  TNode<Union<HeapObject, TaggedIndex>> tmp2;
  TNode<IntPtrT> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).RawPtrAdd(TNode<RawPtrT>{p_base}, TNode<IntPtrT>{p_offset});
    tmp1 = (TNode<RawPtrT>{tmp0});
    std::tie(tmp2, tmp3) = NewOffHeapReference_RawPtr_0(state_, TNode<RawPtrT>{tmp1}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReference_RawPtr_0{TNode<Union<HeapObject, TaggedIndex>>{tmp2}, TNode<IntPtrT>{tmp3}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=308&c=22
TorqueStructReference_intptr_0 NewReference_intptr_0(compiler::CodeAssemblerState* state_, TNode<Union<HeapObject, TaggedIndex>> p_object, TNode<IntPtrT> p_offset) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Union<HeapObject, TaggedIndex>> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    std::tie(tmp0, tmp1) = (TorqueStructReference_intptr_0{TNode<Union<HeapObject, TaggedIndex>>{p_object}, TNode<IntPtrT>{p_offset}, TorqueStructUnsafe_0{}}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReference_intptr_0{TNode<Union<HeapObject, TaggedIndex>>{tmp0}, TNode<IntPtrT>{tmp1}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=736&c=9
TNode<WasmSuspenderObject> UnsafeCast_WasmSuspenderObject_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<WasmSuspenderObject> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = TORQUE_CAST(TNode<Object>{p_o});
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
  return TNode<WasmSuspenderObject>{tmp0};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=778&c=6
TorqueStructReference_int32_0 GetRefAt_int32_RawPtr_intptr_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_base, TNode<IntPtrT> p_offset) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<RawPtrT> tmp0;
  TNode<RawPtrT> tmp1;
  TNode<Union<HeapObject, TaggedIndex>> tmp2;
  TNode<IntPtrT> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).RawPtrAdd(TNode<RawPtrT>{p_base}, TNode<IntPtrT>{p_offset});
    tmp1 = (TNode<RawPtrT>{tmp0});
    std::tie(tmp2, tmp3) = NewOffHeapReference_int32_0(state_, TNode<RawPtrT>{tmp1}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReference_int32_0{TNode<Union<HeapObject, TaggedIndex>>{tmp2}, TNode<IntPtrT>{tmp3}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=779&c=6
TorqueStructReference_bool_0 GetRefAt_bool_RawPtr_intptr_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_base, TNode<IntPtrT> p_offset) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<RawPtrT> tmp0;
  TNode<RawPtrT> tmp1;
  TNode<Union<HeapObject, TaggedIndex>> tmp2;
  TNode<IntPtrT> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).RawPtrAdd(TNode<RawPtrT>{p_base}, TNode<IntPtrT>{p_offset});
    tmp1 = (TNode<RawPtrT>{tmp0});
    std::tie(tmp2, tmp3) = NewOffHeapReference_bool_0(state_, TNode<RawPtrT>{tmp1}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReference_bool_0{TNode<Union<HeapObject, TaggedIndex>>{tmp2}, TNode<IntPtrT>{tmp3}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=781&c=6
TorqueStructReference_RawPtr_0 GetRefAt_RawPtr_RawPtr_intptr_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_base, TNode<IntPtrT> p_offset) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<RawPtrT> tmp0;
  TNode<RawPtrT> tmp1;
  TNode<Union<HeapObject, TaggedIndex>> tmp2;
  TNode<IntPtrT> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).RawPtrAdd(TNode<RawPtrT>{p_base}, TNode<IntPtrT>{p_offset});
    tmp1 = (TNode<RawPtrT>{tmp0});
    std::tie(tmp2, tmp3) = NewOffHeapReference_RawPtr_0(state_, TNode<RawPtrT>{tmp1}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReference_RawPtr_0{TNode<Union<HeapObject, TaggedIndex>>{tmp2}, TNode<IntPtrT>{tmp3}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=783&c=6
TorqueStructReference_intptr_0 GetRefAt_intptr_RawPtr_intptr_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_base, TNode<IntPtrT> p_offset) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<RawPtrT> tmp0;
  TNode<RawPtrT> tmp1;
  TNode<Union<HeapObject, TaggedIndex>> tmp2;
  TNode<IntPtrT> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).RawPtrAdd(TNode<RawPtrT>{p_base}, TNode<IntPtrT>{p_offset});
    tmp1 = (TNode<RawPtrT>{tmp0});
    std::tie(tmp2, tmp3) = NewOffHeapReference_intptr_0(state_, TNode<RawPtrT>{tmp1}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReference_intptr_0{TNode<Union<HeapObject, TaggedIndex>>{tmp2}, TNode<IntPtrT>{tmp3}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=785&c=6
TorqueStructReference_WasmCodePointer_0 GetRefAt_WasmCodePointer_RawPtr_intptr_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_base, TNode<IntPtrT> p_offset) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<RawPtrT> tmp0;
  TNode<RawPtrT> tmp1;
  TNode<Union<HeapObject, TaggedIndex>> tmp2;
  TNode<IntPtrT> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).RawPtrAdd(TNode<RawPtrT>{p_base}, TNode<IntPtrT>{p_offset});
    tmp1 = (TNode<RawPtrT>{tmp0});
    std::tie(tmp2, tmp3) = NewOffHeapReference_WasmCodePointer_0(state_, TNode<RawPtrT>{tmp1}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReference_WasmCodePointer_0{TNode<Union<HeapObject, TaggedIndex>>{tmp2}, TNode<IntPtrT>{tmp3}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=787&c=6
TorqueStructReference_RawPtr_intptr_0 GetRefAt_RawPtr_intptr_RawPtr_intptr_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_base, TNode<IntPtrT> p_offset) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<RawPtrT> tmp0;
  TNode<RawPtrT> tmp1;
  TNode<Union<HeapObject, TaggedIndex>> tmp2;
  TNode<IntPtrT> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).RawPtrAdd(TNode<RawPtrT>{p_base}, TNode<IntPtrT>{p_offset});
    tmp1 = (TNode<RawPtrT>{tmp0});
    std::tie(tmp2, tmp3) = NewOffHeapReference_RawPtr_intptr_0(state_, TNode<RawPtrT>{tmp1}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReference_RawPtr_intptr_0{TNode<Union<HeapObject, TaggedIndex>>{tmp2}, TNode<IntPtrT>{tmp3}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=903&c=22
TorqueStructReference_int32_0 GetRefAt_int32_RawPtr_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_base, TNode<IntPtrT> p_offset) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<RawPtrT> tmp0;
  TNode<RawPtrT> tmp1;
  TNode<Union<HeapObject, TaggedIndex>> tmp2;
  TNode<IntPtrT> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).RawPtrAdd(TNode<RawPtrT>{p_base}, TNode<IntPtrT>{p_offset});
    tmp1 = (TNode<RawPtrT>{tmp0});
    std::tie(tmp2, tmp3) = NewOffHeapReference_int32_0(state_, TNode<RawPtrT>{tmp1}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReference_int32_0{TNode<Union<HeapObject, TaggedIndex>>{tmp2}, TNode<IntPtrT>{tmp3}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=907&c=37
TorqueStructReference_int64_0 GetRefAt_int64_RawPtr_intptr_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_base, TNode<IntPtrT> p_offset) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<RawPtrT> tmp0;
  TNode<RawPtrT> tmp1;
  TNode<Union<HeapObject, TaggedIndex>> tmp2;
  TNode<IntPtrT> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).RawPtrAdd(TNode<RawPtrT>{p_base}, TNode<IntPtrT>{p_offset});
    tmp1 = (TNode<RawPtrT>{tmp0});
    std::tie(tmp2, tmp3) = NewOffHeapReference_int64_0(state_, TNode<RawPtrT>{tmp1}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReference_int64_0{TNode<Union<HeapObject, TaggedIndex>>{tmp2}, TNode<IntPtrT>{tmp3}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=916&c=58
TorqueStructReference_float64_0 GetRefAt_float64_RawPtr_intptr_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_base, TNode<IntPtrT> p_offset) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<RawPtrT> tmp0;
  TNode<RawPtrT> tmp1;
  TNode<Union<HeapObject, TaggedIndex>> tmp2;
  TNode<IntPtrT> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).RawPtrAdd(TNode<RawPtrT>{p_base}, TNode<IntPtrT>{p_offset});
    tmp1 = (TNode<RawPtrT>{tmp0});
    std::tie(tmp2, tmp3) = NewOffHeapReference_float64_0(state_, TNode<RawPtrT>{tmp1}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReference_float64_0{TNode<Union<HeapObject, TaggedIndex>>{tmp2}, TNode<IntPtrT>{tmp3}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=926&c=13
TorqueStructReference_float32_0 GetRefAt_float32_RawPtr_intptr_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_base, TNode<IntPtrT> p_offset) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<RawPtrT> tmp0;
  TNode<RawPtrT> tmp1;
  TNode<Union<HeapObject, TaggedIndex>> tmp2;
  TNode<IntPtrT> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).RawPtrAdd(TNode<RawPtrT>{p_base}, TNode<IntPtrT>{p_offset});
    tmp1 = (TNode<RawPtrT>{tmp0});
    std::tie(tmp2, tmp3) = NewOffHeapReference_float32_0(state_, TNode<RawPtrT>{tmp1}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReference_float32_0{TNode<Union<HeapObject, TaggedIndex>>{tmp2}, TNode<IntPtrT>{tmp3}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=950&c=23
TorqueStructReference_uintptr_0 GetRefAt_uintptr_RawPtr_uintptr_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_base, TNode<IntPtrT> p_offset) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<RawPtrT> tmp0;
  TNode<RawPtrT> tmp1;
  TNode<Union<HeapObject, TaggedIndex>> tmp2;
  TNode<IntPtrT> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).RawPtrAdd(TNode<RawPtrT>{p_base}, TNode<IntPtrT>{p_offset});
    tmp1 = (TNode<RawPtrT>{tmp0});
    std::tie(tmp2, tmp3) = NewOffHeapReference_uintptr_0(state_, TNode<RawPtrT>{tmp1}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReference_uintptr_0{TNode<Union<HeapObject, TaggedIndex>>{tmp2}, TNode<IntPtrT>{tmp3}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=1022&c=37
TorqueStructReference_int64_0 RefCast_int64_0(compiler::CodeAssemblerState* state_, TorqueStructReference_intptr_0 p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Union<HeapObject, TaggedIndex>> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    std::tie(tmp0, tmp1) = NewReference_int64_0(state_, TNode<Union<HeapObject, TaggedIndex>>{p_i.object}, TNode<IntPtrT>{p_i.offset}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReference_int64_0{TNode<Union<HeapObject, TaggedIndex>>{tmp0}, TNode<IntPtrT>{tmp1}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=1024&c=16
TorqueStructReference_int32_0 RefCast_int32_0(compiler::CodeAssemblerState* state_, TorqueStructReference_intptr_0 p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Union<HeapObject, TaggedIndex>> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    std::tie(tmp0, tmp1) = NewReference_int32_0(state_, TNode<Union<HeapObject, TaggedIndex>>{p_i.object}, TNode<IntPtrT>{p_i.offset}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReference_int32_0{TNode<Union<HeapObject, TaggedIndex>>{tmp0}, TNode<IntPtrT>{tmp1}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=155&c=10
TorqueStructReference_float32_0 NewReference_float32_0(compiler::CodeAssemblerState* state_, TNode<Union<HeapObject, TaggedIndex>> p_object, TNode<IntPtrT> p_offset) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Union<HeapObject, TaggedIndex>> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    std::tie(tmp0, tmp1) = (TorqueStructReference_float32_0{TNode<Union<HeapObject, TaggedIndex>>{p_object}, TNode<IntPtrT>{p_offset}, TorqueStructUnsafe_0{}}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReference_float32_0{TNode<Union<HeapObject, TaggedIndex>>{tmp0}, TNode<IntPtrT>{tmp1}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=155&c=10
TorqueStructReference_int64_0 NewReference_int64_0(compiler::CodeAssemblerState* state_, TNode<Union<HeapObject, TaggedIndex>> p_object, TNode<IntPtrT> p_offset) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Union<HeapObject, TaggedIndex>> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    std::tie(tmp0, tmp1) = (TorqueStructReference_int64_0{TNode<Union<HeapObject, TaggedIndex>>{p_object}, TNode<IntPtrT>{p_offset}, TorqueStructUnsafe_0{}}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReference_int64_0{TNode<Union<HeapObject, TaggedIndex>>{tmp0}, TNode<IntPtrT>{tmp1}, TorqueStructUnsafe_0{}};
}

} // namespace internal
} // namespace v8
