#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_TEMPLATES_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_TEMPLATES_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=5&c=1
TNode<TemplateInfo> Cast_TemplateInfo_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=13&c=1
TNode<FunctionTemplateRareData> Cast_FunctionTemplateRareData_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=44&c=1
TNode<FunctionTemplateInfo> Cast_FunctionTemplateInfo_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=104&c=1
TNode<ObjectTemplateInfo> Cast_ObjectTemplateInfo_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=110&c=1
TNode<DictionaryTemplateInfo> Cast_DictionaryTemplateInfo_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=7&c=3
TNode<Smi> LoadTemplateInfoSerialNumber_0(compiler::CodeAssemblerState* state_, TNode<TemplateInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=7&c=3
void StoreTemplateInfoSerialNumber_0(compiler::CodeAssemblerState* state_, TNode<TemplateInfo> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=8&c=3
TNode<Smi> LoadTemplateInfoNumberOfProperties_0(compiler::CodeAssemblerState* state_, TNode<TemplateInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=8&c=3
void StoreTemplateInfoNumberOfProperties_0(compiler::CodeAssemblerState* state_, TNode<TemplateInfo> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=9&c=3
TNode<Union<ArrayList, Undefined>> LoadTemplateInfoPropertyList_0(compiler::CodeAssemblerState* state_, TNode<TemplateInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=9&c=3
void StoreTemplateInfoPropertyList_0(compiler::CodeAssemblerState* state_, TNode<TemplateInfo> p_o, TNode<Union<ArrayList, Undefined>> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=10&c=3
TNode<Union<ArrayList, Undefined>> LoadTemplateInfoPropertyAccessors_0(compiler::CodeAssemblerState* state_, TNode<TemplateInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=10&c=3
void StoreTemplateInfoPropertyAccessors_0(compiler::CodeAssemblerState* state_, TNode<TemplateInfo> p_o, TNode<Union<ArrayList, Undefined>> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=46&c=3
TNode<Union<String, Undefined>> LoadFunctionTemplateInfoClassName_0(compiler::CodeAssemblerState* state_, TNode<FunctionTemplateInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=46&c=3
void StoreFunctionTemplateInfoClassName_0(compiler::CodeAssemblerState* state_, TNode<FunctionTemplateInfo> p_o, TNode<Union<String, Undefined>> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=50&c=3
TNode<Union<String, Undefined>> LoadFunctionTemplateInfoInterfaceName_0(compiler::CodeAssemblerState* state_, TNode<FunctionTemplateInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=50&c=3
void StoreFunctionTemplateInfoInterfaceName_0(compiler::CodeAssemblerState* state_, TNode<FunctionTemplateInfo> p_o, TNode<Union<String, Undefined>> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=55&c=3
TNode<Union<FunctionTemplateInfo, Undefined>> LoadFunctionTemplateInfoSignature_0(compiler::CodeAssemblerState* state_, TNode<FunctionTemplateInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=55&c=3
void StoreFunctionTemplateInfoSignature_0(compiler::CodeAssemblerState* state_, TNode<FunctionTemplateInfo> p_o, TNode<Union<FunctionTemplateInfo, Undefined>> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=61&c=3
TNode<Union<FunctionTemplateRareData, Undefined>> LoadFunctionTemplateInfoRareData_0(compiler::CodeAssemblerState* state_, TNode<FunctionTemplateInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=61&c=3
void StoreFunctionTemplateInfoRareData_0(compiler::CodeAssemblerState* state_, TNode<FunctionTemplateInfo> p_o, TNode<Union<FunctionTemplateRareData, Undefined>> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=62&c=3
TNode<Union<SharedFunctionInfo, Undefined>> LoadFunctionTemplateInfoSharedFunctionInfo_0(compiler::CodeAssemblerState* state_, TNode<FunctionTemplateInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=62&c=3
void StoreFunctionTemplateInfoSharedFunctionInfo_0(compiler::CodeAssemblerState* state_, TNode<FunctionTemplateInfo> p_o, TNode<Union<SharedFunctionInfo, Undefined>> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=66&c=3
TNode<Object> LoadFunctionTemplateInfoCachedPropertyName_0(compiler::CodeAssemblerState* state_, TNode<FunctionTemplateInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=66&c=3
void StoreFunctionTemplateInfoCachedPropertyName_0(compiler::CodeAssemblerState* state_, TNode<FunctionTemplateInfo> p_o, TNode<Object> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=73&c=36
TNode<Object> LoadFunctionTemplateInfoCallbackData_0(compiler::CodeAssemblerState* state_, TNode<FunctionTemplateInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=73&c=36
void StoreFunctionTemplateInfoCallbackData_0(compiler::CodeAssemblerState* state_, TNode<FunctionTemplateInfo> p_o, TNode<Object> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=76&c=3
TNode<Uint32T> LoadFunctionTemplateInfoFlag_0(compiler::CodeAssemblerState* state_, TNode<FunctionTemplateInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=76&c=3
void StoreFunctionTemplateInfoFlag_0(compiler::CodeAssemblerState* state_, TNode<FunctionTemplateInfo> p_o, TNode<Uint32T> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=78&c=3
TNode<Int16T> LoadFunctionTemplateInfoLength_0(compiler::CodeAssemblerState* state_, TNode<FunctionTemplateInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=78&c=3
void StoreFunctionTemplateInfoLength_0(compiler::CodeAssemblerState* state_, TNode<FunctionTemplateInfo> p_o, TNode<Int16T> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=81&c=3
TNode<Uint16T> LoadFunctionTemplateInfoInstanceType_0(compiler::CodeAssemblerState* state_, TNode<FunctionTemplateInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=81&c=3
void StoreFunctionTemplateInfoInstanceType_0(compiler::CodeAssemblerState* state_, TNode<FunctionTemplateInfo> p_o, TNode<Uint16T> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=86&c=3
TNode<Uint32T> LoadFunctionTemplateInfoExceptionContext_0(compiler::CodeAssemblerState* state_, TNode<FunctionTemplateInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=86&c=3
void StoreFunctionTemplateInfoExceptionContext_0(compiler::CodeAssemblerState* state_, TNode<FunctionTemplateInfo> p_o, TNode<Uint32T> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=95&c=3
TNode<ExternalPointerT> LoadFunctionTemplateInfoMaybeRedirectedCallback_0(compiler::CodeAssemblerState* state_, TNode<FunctionTemplateInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=95&c=3
void StoreFunctionTemplateInfoMaybeRedirectedCallback_0(compiler::CodeAssemblerState* state_, TNode<FunctionTemplateInfo> p_o, TNode<ExternalPointerT> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=15&c=3
TNode<Union<ObjectTemplateInfo, Undefined>> LoadFunctionTemplateRareDataPrototypeTemplate_0(compiler::CodeAssemblerState* state_, TNode<FunctionTemplateRareData> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=15&c=3
void StoreFunctionTemplateRareDataPrototypeTemplate_0(compiler::CodeAssemblerState* state_, TNode<FunctionTemplateRareData> p_o, TNode<Union<ObjectTemplateInfo, Undefined>> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=16&c=3
TNode<Union<FunctionTemplateInfo, Undefined>> LoadFunctionTemplateRareDataPrototypeProviderTemplate_0(compiler::CodeAssemblerState* state_, TNode<FunctionTemplateRareData> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=16&c=3
void StoreFunctionTemplateRareDataPrototypeProviderTemplate_0(compiler::CodeAssemblerState* state_, TNode<FunctionTemplateRareData> p_o, TNode<Union<FunctionTemplateInfo, Undefined>> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=17&c=3
TNode<Union<FunctionTemplateInfo, Undefined>> LoadFunctionTemplateRareDataParentTemplate_0(compiler::CodeAssemblerState* state_, TNode<FunctionTemplateRareData> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=17&c=3
void StoreFunctionTemplateRareDataParentTemplate_0(compiler::CodeAssemblerState* state_, TNode<FunctionTemplateRareData> p_o, TNode<Union<FunctionTemplateInfo, Undefined>> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=18&c=3
TNode<Union<InterceptorInfo, Undefined>> LoadFunctionTemplateRareDataNamedPropertyHandler_0(compiler::CodeAssemblerState* state_, TNode<FunctionTemplateRareData> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=18&c=3
void StoreFunctionTemplateRareDataNamedPropertyHandler_0(compiler::CodeAssemblerState* state_, TNode<FunctionTemplateRareData> p_o, TNode<Union<InterceptorInfo, Undefined>> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=19&c=3
TNode<Union<InterceptorInfo, Undefined>> LoadFunctionTemplateRareDataIndexedPropertyHandler_0(compiler::CodeAssemblerState* state_, TNode<FunctionTemplateRareData> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=19&c=3
void StoreFunctionTemplateRareDataIndexedPropertyHandler_0(compiler::CodeAssemblerState* state_, TNode<FunctionTemplateRareData> p_o, TNode<Union<InterceptorInfo, Undefined>> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=20&c=3
TNode<Union<ObjectTemplateInfo, Undefined>> LoadFunctionTemplateRareDataInstanceTemplate_0(compiler::CodeAssemblerState* state_, TNode<FunctionTemplateRareData> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=20&c=3
void StoreFunctionTemplateRareDataInstanceTemplate_0(compiler::CodeAssemblerState* state_, TNode<FunctionTemplateRareData> p_o, TNode<Union<ObjectTemplateInfo, Undefined>> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=21&c=3
TNode<Union<FunctionTemplateInfo, Undefined>> LoadFunctionTemplateRareDataInstanceCallHandler_0(compiler::CodeAssemblerState* state_, TNode<FunctionTemplateRareData> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=21&c=3
void StoreFunctionTemplateRareDataInstanceCallHandler_0(compiler::CodeAssemblerState* state_, TNode<FunctionTemplateRareData> p_o, TNode<Union<FunctionTemplateInfo, Undefined>> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=22&c=3
TNode<Union<AccessCheckInfo, Undefined>> LoadFunctionTemplateRareDataAccessCheckInfo_0(compiler::CodeAssemblerState* state_, TNode<FunctionTemplateRareData> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=22&c=3
void StoreFunctionTemplateRareDataAccessCheckInfo_0(compiler::CodeAssemblerState* state_, TNode<FunctionTemplateRareData> p_o, TNode<Union<AccessCheckInfo, Undefined>> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=23&c=3
TNode<FixedArray> LoadFunctionTemplateRareDataCFunctionOverloads_0(compiler::CodeAssemblerState* state_, TNode<FunctionTemplateRareData> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=23&c=3
void StoreFunctionTemplateRareDataCFunctionOverloads_0(compiler::CodeAssemblerState* state_, TNode<FunctionTemplateRareData> p_o, TNode<FixedArray> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=106&c=3
TNode<Union<FunctionTemplateInfo, Undefined>> LoadObjectTemplateInfoConstructor_0(compiler::CodeAssemblerState* state_, TNode<ObjectTemplateInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=106&c=3
void StoreObjectTemplateInfoConstructor_0(compiler::CodeAssemblerState* state_, TNode<ObjectTemplateInfo> p_o, TNode<Union<FunctionTemplateInfo, Undefined>> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=107&c=3
TNode<Smi> LoadObjectTemplateInfoData_0(compiler::CodeAssemblerState* state_, TNode<ObjectTemplateInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=107&c=3
void StoreObjectTemplateInfoData_0(compiler::CodeAssemblerState* state_, TNode<ObjectTemplateInfo> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=112&c=3
TNode<FixedArray> LoadDictionaryTemplateInfoPropertyNames_0(compiler::CodeAssemblerState* state_, TNode<DictionaryTemplateInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=112&c=3
void StoreDictionaryTemplateInfoPropertyNames_0(compiler::CodeAssemblerState* state_, TNode<DictionaryTemplateInfo> p_o, TNode<FixedArray> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=113&c=3
TNode<Smi> LoadDictionaryTemplateInfoSerialNumber_0(compiler::CodeAssemblerState* state_, TNode<DictionaryTemplateInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=113&c=3
void StoreDictionaryTemplateInfoSerialNumber_0(compiler::CodeAssemblerState* state_, TNode<DictionaryTemplateInfo> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=5&c=1
TNode<TemplateInfo> DownCastForTorqueClass_TemplateInfo_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=13&c=1
TNode<FunctionTemplateRareData> DownCastForTorqueClass_FunctionTemplateRareData_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=44&c=1
TNode<FunctionTemplateInfo> DownCastForTorqueClass_FunctionTemplateInfo_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=104&c=1
TNode<ObjectTemplateInfo> DownCastForTorqueClass_ObjectTemplateInfo_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=110&c=1
TNode<DictionaryTemplateInfo> DownCastForTorqueClass_DictionaryTemplateInfo_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_TEMPLATES_TQ_CSA_H_
