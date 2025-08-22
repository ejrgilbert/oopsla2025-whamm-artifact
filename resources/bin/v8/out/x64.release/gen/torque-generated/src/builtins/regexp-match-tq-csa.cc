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
#include "torque-generated/src/builtins/regexp-match-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/boolean-tq-csa.h"
#include "torque-generated/src/builtins/cast-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/growable-fixed-array-tq-csa.h"
#include "torque-generated/src/builtins/number-tq-csa.h"
#include "torque-generated/src/builtins/regexp-exec-tq-csa.h"
#include "torque-generated/src/builtins/regexp-match-all-tq-csa.h"
#include "torque-generated/src/builtins/regexp-match-tq-csa.h"
#include "torque-generated/src/builtins/regexp-tq-csa.h"
#include "torque-generated/src/builtins/torque-internal-tq-csa.h"
#include "torque-generated/src/objects/fixed-array-tq-csa.h"
#include "torque-generated/src/objects/js-array-tq-csa.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/regexp-match.tq?l=31&c=1
TNode<JSAny> RegExpPrototypeMatchBody_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_regexp, TNode<String> p_string, bool p_isFastPath) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT> block40(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT> block41(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, Union<JSArray, Null>> block42(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT> block64(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT> block65(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT> block83(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT> block84(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block87(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block88(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSAny> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block89(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    if ((p_isFastPath)) {
      ca_.Goto(&block2);
    } else {
      ca_.Goto(&block3);
    }
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.Goto(&block4);
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.Goto(&block4);
  }

  TNode<BoolT> tmp0;
  TNode<BoolT> tmp1;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp0 = RegExpBuiltinsAssembler(state_).FlagGetter(TNode<Context>{p_context}, TNode<JSAny>{p_regexp}, JSRegExp::Flag::kGlobal, p_isFastPath);
    tmp1 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp0});
    ca_.Branch(tmp1, &block9, std::vector<compiler::Node*>{}, &block10, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp2;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    tmp2 = FromConstexpr_bool_constexpr_bool_0(state_, p_isFastPath);
    ca_.Branch(tmp2, &block11, std::vector<compiler::Node*>{}, &block12, std::vector<compiler::Node*>{});
  }

  TNode<JSAny> tmp3;
  if (block11.is_used()) {
    ca_.Bind(&block11);
    tmp3 = RegExpPrototypeExecBodyFast_0(state_, TNode<Context>{p_context}, TNode<JSReceiver>{p_regexp}, TNode<String>{p_string});
    ca_.Goto(&block13, tmp3);
  }

  TNode<JSAny> tmp4;
  if (block12.is_used()) {
    ca_.Bind(&block12);
    tmp4 = RegExpExec_0(state_, TNode<Context>{p_context}, TNode<JSReceiver>{p_regexp}, TNode<String>{p_string});
    ca_.Goto(&block13, tmp4);
  }

  TNode<JSAny> phi_bb13_4;
  if (block13.is_used()) {
    ca_.Bind(&block13, &phi_bb13_4);
    ca_.Goto(&block1, phi_bb13_4);
  }

  if (block10.is_used()) {
    ca_.Bind(&block10);
    if ((p_isFastPath)) {
      ca_.Goto(&block19);
    } else {
      ca_.Goto(&block20);
    }
  }

  TNode<JSRegExp> tmp5;
  TNode<TrustedObject> tmp6;
  TNode<RegExpData> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<Smi> tmp9;
  TNode<Number> tmp10;
  TNode<BoolT> tmp11;
  if (block19.is_used()) {
    ca_.Bind(&block19);
    tmp5 = UnsafeCast_JSRegExp_0(state_, TNode<Context>{p_context}, TNode<Object>{p_regexp});
    tmp6 = CodeStubAssembler(state_).LoadTrustedPointerFromObject(TNode<HeapObject>{tmp5}, JSRegExp::kDataOffset, kRegExpDataIndirectPointerTag);
    tmp7 = UnsafeCast_RegExpData_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp6});
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp9 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp7, tmp8});
    tmp10 = FromConstexpr_Number_constexpr_WasmCodePointer_0(state_, static_cast<uint8_t>(RegExpData::Type::ATOM));
    tmp11 = IsNumberEqual_0(state_, TNode<Number>{tmp9}, TNode<Number>{tmp10});
    ca_.Branch(tmp11, &block22, std::vector<compiler::Node*>{}, &block23, std::vector<compiler::Node*>{});
  }

  TNode<JSAny> tmp12;
  if (block22.is_used()) {
    ca_.Bind(&block22);
    tmp12 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kRegExpMatchGlobalAtom, p_context, tmp5, p_string, tmp7)); 
    ca_.Goto(&block1, tmp12);
  }

  TNode<JSAny> tmp13;
  if (block23.is_used()) {
    ca_.Bind(&block23);
    tmp13 = RegExpBuiltinsAssembler(state_).RegExpMatchGlobal(TNode<Context>{p_context}, TNode<JSRegExp>{tmp5}, TNode<String>{p_string}, TNode<RegExpData>{tmp7});
    ca_.Goto(&block1, tmp13);
  }

  TNode<BoolT> tmp14;
  if (block20.is_used()) {
    ca_.Bind(&block20);
    tmp14 = RegExpBuiltinsAssembler(state_).FlagGetter(TNode<Context>{p_context}, TNode<JSAny>{p_regexp}, JSRegExp::Flag::kUnicode, p_isFastPath);
    ca_.Branch(tmp14, &block28, std::vector<compiler::Node*>{}, &block29, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp15;
  if (block28.is_used()) {
    ca_.Bind(&block28);
    tmp15 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block30, tmp15);
  }

  TNode<BoolT> tmp16;
  if (block29.is_used()) {
    ca_.Bind(&block29);
    tmp16 = RegExpBuiltinsAssembler(state_).FlagGetter(TNode<Context>{p_context}, TNode<JSAny>{p_regexp}, JSRegExp::Flag::kUnicodeSets, p_isFastPath);
    ca_.Goto(&block30, tmp16);
  }

  TNode<BoolT> phi_bb30_5;
  TNode<Number> tmp17;
  TNode<FixedArray> tmp18;
  TNode<IntPtrT> tmp19;
  TNode<IntPtrT> tmp20;
  if (block30.is_used()) {
    ca_.Bind(&block30, &phi_bb30_5);
    tmp17 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    StoreLastIndex_0(state_, TNode<Context>{p_context}, TNode<JSAny>{p_regexp}, TNode<Number>{tmp17}, p_isFastPath);
    std::tie(tmp18, tmp19, tmp20) = NewGrowableFixedArray_0(state_).Flatten();
    ca_.Goto(&block33, tmp18, tmp19, tmp20);
  }

  TNode<FixedArray> phi_bb33_5;
  TNode<IntPtrT> phi_bb33_6;
  TNode<IntPtrT> phi_bb33_7;
  TNode<BoolT> tmp21;
  if (block33.is_used()) {
    ca_.Bind(&block33, &phi_bb33_5, &phi_bb33_6, &phi_bb33_7);
    tmp21 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp21, &block31, std::vector<compiler::Node*>{phi_bb33_5, phi_bb33_6, phi_bb33_7}, &block32, std::vector<compiler::Node*>{phi_bb33_5, phi_bb33_6, phi_bb33_7});
  }

  TNode<FixedArray> phi_bb31_5;
  TNode<IntPtrT> phi_bb31_6;
  TNode<IntPtrT> phi_bb31_7;
  TNode<String> tmp22;
  TNode<JSAny> tmp23;
  TNode<Null> tmp24;
  TNode<BoolT> tmp25;
  if (block31.is_used()) {
    ca_.Bind(&block31, &phi_bb31_5, &phi_bb31_6, &phi_bb31_7);
    tmp22 = CodeStubAssembler(state_).EmptyStringConstant();
    tmp23 = RegExpExec_0(state_, TNode<Context>{p_context}, TNode<JSReceiver>{p_regexp}, TNode<String>{p_string});
    tmp24 = Null_0(state_);
    tmp25 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp23}, TNode<Union<Context, FixedArrayBase, FunctionTemplateInfo, Hole, JSReceiver, Map, Oddball, String, Symbol, WasmFuncRef, WasmNull, WeakCell>>{tmp24});
    ca_.Branch(tmp25, &block38, std::vector<compiler::Node*>{phi_bb31_5, phi_bb31_6, phi_bb31_7}, &block39, std::vector<compiler::Node*>{phi_bb31_5, phi_bb31_6, phi_bb31_7});
  }

  TNode<FixedArray> phi_bb38_5;
  TNode<IntPtrT> phi_bb38_6;
  TNode<IntPtrT> phi_bb38_7;
  TNode<IntPtrT> tmp26;
  TNode<BoolT> tmp27;
  if (block38.is_used()) {
    ca_.Bind(&block38, &phi_bb38_5, &phi_bb38_6, &phi_bb38_7);
    tmp26 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp27 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{phi_bb38_7}, TNode<IntPtrT>{tmp26});
    ca_.Branch(tmp27, &block40, std::vector<compiler::Node*>{phi_bb38_5, phi_bb38_6, phi_bb38_7}, &block41, std::vector<compiler::Node*>{phi_bb38_5, phi_bb38_6, phi_bb38_7});
  }

  TNode<FixedArray> phi_bb39_5;
  TNode<IntPtrT> phi_bb39_6;
  TNode<IntPtrT> phi_bb39_7;
  TNode<Smi> tmp28;
  TNode<JSAny> tmp29;
  TNode<String> tmp30;
  TNode<BoolT> tmp31;
  if (block39.is_used()) {
    ca_.Bind(&block39, &phi_bb39_5, &phi_bb39_6, &phi_bb39_7);
    tmp28 = SmiConstant_0(state_, IntegerLiteral(false, 0x0ull));
    tmp29 = CodeStubAssembler(state_).GetProperty(TNode<Context>{p_context}, TNode<JSAny>{tmp23}, TNode<JSAny>{tmp28});
    tmp30 = CodeStubAssembler(state_).ToString_Inline(TNode<Context>{p_context}, TNode<JSAny>{tmp29});
    tmp31 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{phi_bb39_6}, TNode<IntPtrT>{phi_bb39_7});
    ca_.Branch(tmp31, &block64, std::vector<compiler::Node*>{phi_bb39_5, phi_bb39_6, phi_bb39_7}, &block65, std::vector<compiler::Node*>{phi_bb39_5, phi_bb39_6, phi_bb39_7});
  }

  TNode<FixedArray> phi_bb40_5;
  TNode<IntPtrT> phi_bb40_6;
  TNode<IntPtrT> phi_bb40_7;
  TNode<Null> tmp32;
  if (block40.is_used()) {
    ca_.Bind(&block40, &phi_bb40_5, &phi_bb40_6, &phi_bb40_7);
    tmp32 = Null_0(state_);
    ca_.Goto(&block42, phi_bb40_5, phi_bb40_6, phi_bb40_7, tmp32);
  }

  TNode<FixedArray> phi_bb41_5;
  TNode<IntPtrT> phi_bb41_6;
  TNode<IntPtrT> phi_bb41_7;
  TNode<NativeContext> tmp33;
  TNode<Map> tmp34;
  TNode<IntPtrT> tmp35;
  TNode<Hole> tmp36;
  TNode<FixedArray> tmp37;
  TNode<Smi> tmp38;
  TNode<JSArray> tmp39;
  if (block41.is_used()) {
    ca_.Bind(&block41, &phi_bb41_5, &phi_bb41_6, &phi_bb41_7);
    tmp33 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{p_context});
    tmp34 = CodeStubAssembler(state_).LoadJSArrayElementsMap(ElementsKind::PACKED_ELEMENTS, TNode<NativeContext>{tmp33});
    tmp35 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp36 = TheHole_0(state_);
    tmp37 = ExtractFixedArray_0(state_, TNode<FixedArray>{phi_bb41_5}, TNode<IntPtrT>{tmp35}, TNode<IntPtrT>{phi_bb41_7}, TNode<IntPtrT>{phi_bb41_7}, TNode<Hole>{tmp36});
    tmp38 = Convert_Smi_intptr_0(state_, TNode<IntPtrT>{phi_bb41_7});
    tmp39 = CodeStubAssembler(state_).AllocateJSArray(TNode<Map>{tmp34}, TNode<FixedArrayBase>{tmp37}, TNode<Smi>{tmp38});
    ca_.Goto(&block42, phi_bb41_5, phi_bb41_6, phi_bb41_7, tmp39);
  }

  TNode<FixedArray> phi_bb42_5;
  TNode<IntPtrT> phi_bb42_6;
  TNode<IntPtrT> phi_bb42_7;
  TNode<Union<JSArray, Null>> phi_bb42_9;
  if (block42.is_used()) {
    ca_.Bind(&block42, &phi_bb42_5, &phi_bb42_6, &phi_bb42_7, &phi_bb42_9);
    ca_.Goto(&block1, phi_bb42_9);
  }

  TNode<FixedArray> phi_bb64_5;
  TNode<IntPtrT> phi_bb64_6;
  TNode<IntPtrT> phi_bb64_7;
  TNode<IntPtrT> tmp40;
  TNode<IntPtrT> tmp41;
  TNode<IntPtrT> tmp42;
  TNode<IntPtrT> tmp43;
  TNode<IntPtrT> tmp44;
  TNode<IntPtrT> tmp45;
  TNode<Hole> tmp46;
  TNode<FixedArray> tmp47;
  if (block64.is_used()) {
    ca_.Bind(&block64, &phi_bb64_5, &phi_bb64_6, &phi_bb64_7);
    tmp40 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp41 = CodeStubAssembler(state_).WordSar(TNode<IntPtrT>{phi_bb64_6}, TNode<IntPtrT>{tmp40});
    tmp42 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb64_6}, TNode<IntPtrT>{tmp41});
    tmp43 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x10ull));
    tmp44 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp42}, TNode<IntPtrT>{tmp43});
    tmp45 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp46 = TheHole_0(state_);
    tmp47 = ExtractFixedArray_0(state_, TNode<FixedArray>{phi_bb64_5}, TNode<IntPtrT>{tmp45}, TNode<IntPtrT>{phi_bb64_7}, TNode<IntPtrT>{tmp44}, TNode<Hole>{tmp46});
    ca_.Goto(&block65, tmp47, tmp44, phi_bb64_7);
  }

  TNode<FixedArray> phi_bb65_5;
  TNode<IntPtrT> phi_bb65_6;
  TNode<IntPtrT> phi_bb65_7;
  TNode<Union<HeapObject, TaggedIndex>> tmp48;
  TNode<IntPtrT> tmp49;
  TNode<IntPtrT> tmp50;
  TNode<IntPtrT> tmp51;
  TNode<IntPtrT> tmp52;
  TNode<UintPtrT> tmp53;
  TNode<UintPtrT> tmp54;
  TNode<BoolT> tmp55;
  if (block65.is_used()) {
    ca_.Bind(&block65, &phi_bb65_5, &phi_bb65_6, &phi_bb65_7);
    std::tie(tmp48, tmp49, tmp50) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{phi_bb65_5}).Flatten();
    tmp51 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp52 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb65_7}, TNode<IntPtrT>{tmp51});
    tmp53 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{phi_bb65_7});
    tmp54 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp50});
    tmp55 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp53}, TNode<UintPtrT>{tmp54});
    ca_.Branch(tmp55, &block83, std::vector<compiler::Node*>{phi_bb65_7, phi_bb65_7, phi_bb65_7, phi_bb65_7}, &block84, std::vector<compiler::Node*>{phi_bb65_7, phi_bb65_7, phi_bb65_7, phi_bb65_7});
  }

  TNode<IntPtrT> phi_bb83_15;
  TNode<IntPtrT> phi_bb83_16;
  TNode<IntPtrT> phi_bb83_20;
  TNode<IntPtrT> phi_bb83_21;
  TNode<IntPtrT> tmp56;
  TNode<IntPtrT> tmp57;
  TNode<Union<HeapObject, TaggedIndex>> tmp58;
  TNode<IntPtrT> tmp59;
  TNode<Smi> tmp60;
  TNode<Smi> tmp61;
  TNode<BoolT> tmp62;
  if (block83.is_used()) {
    ca_.Bind(&block83, &phi_bb83_15, &phi_bb83_16, &phi_bb83_20, &phi_bb83_21);
    tmp56 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{phi_bb83_21});
    tmp57 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp49}, TNode<IntPtrT>{tmp56});
    std::tie(tmp58, tmp59) = NewReference_Object_0(state_, TNode<Union<HeapObject, TaggedIndex>>{tmp48}, TNode<IntPtrT>{tmp57}).Flatten();
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp58, tmp59}, tmp30);
    tmp60 = CodeStubAssembler(state_).LoadStringLengthAsSmi(TNode<String>{tmp30});
    tmp61 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp62 = CodeStubAssembler(state_).SmiNotEqual(TNode<Smi>{tmp60}, TNode<Smi>{tmp61});
    ca_.Branch(tmp62, &block87, std::vector<compiler::Node*>{}, &block88, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> phi_bb84_15;
  TNode<IntPtrT> phi_bb84_16;
  TNode<IntPtrT> phi_bb84_20;
  TNode<IntPtrT> phi_bb84_21;
  if (block84.is_used()) {
    ca_.Bind(&block84, &phi_bb84_15, &phi_bb84_16, &phi_bb84_20, &phi_bb84_21);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block87.is_used()) {
    ca_.Bind(&block87);
    ca_.Goto(&block33, phi_bb65_5, phi_bb65_6, tmp52);
  }

  TNode<JSAny> tmp63;
  TNode<Number> tmp64;
  TNode<Number> tmp65;
  TNode<Number> tmp66;
  if (block88.is_used()) {
    ca_.Bind(&block88);
    tmp63 = LoadLastIndex_0(state_, TNode<Context>{p_context}, TNode<JSAny>{p_regexp}, p_isFastPath);
    tmp64 = CodeStubAssembler(state_).ToLength_Inline(TNode<Context>{p_context}, TNode<JSAny>{tmp63});
    tmp65 = UnsafeCast_Number_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp64});
    tmp66 = RegExpBuiltinsAssembler(state_).AdvanceStringIndex(TNode<String>{p_string}, TNode<Number>{tmp65}, TNode<BoolT>{phi_bb30_5}, p_isFastPath);
    StoreLastIndex_0(state_, TNode<Context>{p_context}, TNode<JSAny>{p_regexp}, TNode<Number>{tmp66}, p_isFastPath);
    ca_.Goto(&block33, phi_bb65_5, phi_bb65_6, tmp52);
  }

  TNode<FixedArray> phi_bb32_5;
  TNode<IntPtrT> phi_bb32_6;
  TNode<IntPtrT> phi_bb32_7;
  if (block32.is_used()) {
    ca_.Bind(&block32, &phi_bb32_5, &phi_bb32_6, &phi_bb32_7);
    VerifiedUnreachable_0(state_);
  }

  TNode<JSAny> phi_bb1_3;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_3);
    ca_.Goto(&block89);
  }

    ca_.Bind(&block89);
  return TNode<JSAny>{phi_bb1_3};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/regexp-match.tq?l=104&c=1
TNode<JSAny> FastRegExpPrototypeMatchBody_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSRegExp> p_receiver, TNode<String> p_string) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSAny> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = RegExpPrototypeMatchBody_0(state_, TNode<Context>{p_context}, TNode<JSReceiver>{p_receiver}, TNode<String>{p_string}, true);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<JSAny>{tmp0};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/regexp-match.tq?l=109&c=1
TNode<JSAny> SlowRegExpPrototypeMatchBody_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_receiver, TNode<String> p_string) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSAny> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = RegExpPrototypeMatchBody_0(state_, TNode<Context>{p_context}, TNode<JSReceiver>{p_receiver}, TNode<String>{p_string}, false);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<JSAny>{tmp0};
}

TF_BUILTIN(RegExpMatchFast, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
  USE(parameter0);
  TNode<JSRegExp> parameter1 = UncheckedParameter<JSRegExp>(Descriptor::kReceiver);
  USE(parameter1);
  TNode<String> parameter2 = UncheckedParameter<String>(Descriptor::kString);
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSAny> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FastRegExpPrototypeMatchBody_0(state_, TNode<Context>{parameter0}, TNode<JSRegExp>{parameter1}, TNode<String>{parameter2});
    CodeStubAssembler(state_).Return(tmp0);
  }
}

TF_BUILTIN(RegExpPrototypeMatch, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<JSAny> parameter1 = UncheckedParameter<JSAny>(Descriptor::kReceiver);
  USE(parameter1);
  TNode<JSAny> parameter2 = UncheckedParameter<JSAny>(Descriptor::kString);
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSReceiver> tmp0;
  TNode<String> tmp1;
  TNode<JSRegExp> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    CodeStubAssembler(state_).ThrowIfNotJSReceiver(TNode<Context>{parameter0}, TNode<JSAny>{parameter1}, MessageTemplate::kIncompatibleMethodReceiver, "RegExp.prototype.@@match");
    tmp0 = UnsafeCast_JSReceiver_0(state_, TNode<Context>{parameter0}, TNode<Object>{parameter1});
    tmp1 = CodeStubAssembler(state_).ToString_Inline(TNode<Context>{parameter0}, TNode<JSAny>{parameter2});
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_FastJSRegExp_0(state_, TNode<Context>{parameter0}, TNode<HeapObject>{tmp0}, &label3);
    ca_.Goto(&block3);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block4);
    }
  }

  TNode<JSAny> tmp4;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp4 = SlowRegExpPrototypeMatchBody_0(state_, TNode<Context>{parameter0}, TNode<JSReceiver>{tmp0}, TNode<String>{tmp1});
    CodeStubAssembler(state_).Return(tmp4);
  }

  TNode<JSAny> tmp5;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp5 = ca_.CallBuiltin<JSAny>(Builtin::kRegExpMatchFast, parameter0, tmp2, tmp1);
    CodeStubAssembler(state_).Return(tmp5);
  }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/regexp-match.tq?l=35&c=12
TNode<BoolT> Is_FastJSRegExp_JSReceiver_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSRegExp> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_FastJSRegExp_0(state_, TNode<Context>{p_context}, TNode<HeapObject>{p_o}, &label1);
    ca_.Goto(&block4);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block5);
    }
  }

  TNode<BoolT> tmp2;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp2 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp2);
  }

  TNode<BoolT> tmp3;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp3 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp3);
  }

  TNode<BoolT> phi_bb1_2;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_2);
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
  return TNode<BoolT>{phi_bb1_2};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/regexp-match.tq?l=51&c=9
TNode<RegExpData> UnsafeCast_RegExpData_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<RegExpData> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = TORQUE_CAST(TNode<Object>{p_o});
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
  return TNode<RegExpData>{tmp0};
}

} // namespace internal
} // namespace v8
