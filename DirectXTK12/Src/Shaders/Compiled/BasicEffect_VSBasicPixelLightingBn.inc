#if 0
;
; Input signature:
;
; Name                 Index   Mask Register SysValue  Format   Used
; -------------------- ----- ------ -------- -------- ------- ------
; SV_Position              0   xyzw        0     NONE   float   xyzw
; NORMAL                   0   xyz         1     NONE   float   xyz 
;
;
; Output signature:
;
; Name                 Index   Mask Register SysValue  Format   Used
; -------------------- ----- ------ -------- -------- ------- ------
; TEXCOORD                 0   xyzw        0     NONE   float   xyzw
; TEXCOORD                 1   xyz         1     NONE   float   xyz 
; COLOR                    0   xyzw        2     NONE   float   xyzw
; SV_Position              0   xyzw        3      POS   float   xyzw
;
; shader debug name: Compiled\BasicEffect_VSBasicPixelLightingBn.pdb
; shader hash: e0b50e3a90182eed91de99e8f355c8ca
;
; Pipeline Runtime Information: 
;
; Vertex Shader
; OutputPositionPresent=1
;
;
; Input signature:
;
; Name                 Index             InterpMode DynIdx
; -------------------- ----- ---------------------- ------
; SV_Position              0                              
; NORMAL                   0                              
;
; Output signature:
;
; Name                 Index             InterpMode DynIdx
; -------------------- ----- ---------------------- ------
; TEXCOORD                 0                 linear       
; TEXCOORD                 1                 linear       
; COLOR                    0                 linear       
; SV_Position              0          noperspective       
;
; Buffer Definitions:
;
; cbuffer 
; {
;
;   [416 x i8] (type annotation not present)
;
; }
;
;
; Resource Bindings:
;
; Name                                 Type  Format         Dim      ID      HLSL Bind  Count
; ------------------------------ ---------- ------- ----------- ------- -------------- ------
;                                   cbuffer      NA          NA     CB0            cb0     1
;
;
; ViewId state:
;
; Number of inputs: 7, outputs: 16
; Outputs dependent on ViewId: {  }
; Inputs contributing to computation of Outputs:
;   output 0 depends on inputs: { 0, 1, 2, 3 }
;   output 1 depends on inputs: { 0, 1, 2, 3 }
;   output 2 depends on inputs: { 0, 1, 2, 3 }
;   output 3 depends on inputs: { 0, 1, 2, 3 }
;   output 4 depends on inputs: { 4, 5, 6 }
;   output 5 depends on inputs: { 4, 5, 6 }
;   output 6 depends on inputs: { 4, 5, 6 }
;   output 12 depends on inputs: { 0, 1, 2, 3 }
;   output 13 depends on inputs: { 0, 1, 2, 3 }
;   output 14 depends on inputs: { 0, 1, 2, 3 }
;   output 15 depends on inputs: { 0, 1, 2, 3 }
;
target datalayout = "e-m:e-p:32:32-i1:32-i8:32-i16:32-i32:32-i64:64-f16:32-f32:32-f64:64-n8:16:32:64"
target triple = "dxil-ms-dx"

%dx.types.Handle = type { i8* }
%dx.types.CBufRet.f32 = type { float, float, float, float }
%dx.alignment.legacy.Parameters = type { <4 x float>, <3 x float>, <3 x float>, float, [3 x <3 x float>], [3 x <3 x float>], [3 x <3 x float>], <3 x float>, <3 x float>, <4 x float>, [4 x <4 x float>], [3 x <3 x float>], [4 x <4 x float>] }

define void @VSBasicPixelLightingBn() {
  %1 = call %dx.types.Handle @dx.op.createHandle(i32 57, i8 2, i32 0, i32 0, i1 false)  ; CreateHandle(resourceClass,rangeId,index,nonUniformIndex)
  %2 = call float @dx.op.loadInput.f32(i32 4, i32 1, i32 0, i8 0, i32 undef)  ; LoadInput(inputSigId,rowIndex,colIndex,gsVertexAxis)
  %3 = call float @dx.op.loadInput.f32(i32 4, i32 1, i32 0, i8 1, i32 undef)  ; LoadInput(inputSigId,rowIndex,colIndex,gsVertexAxis)
  %4 = call float @dx.op.loadInput.f32(i32 4, i32 1, i32 0, i8 2, i32 undef)  ; LoadInput(inputSigId,rowIndex,colIndex,gsVertexAxis)
  %5 = call float @dx.op.loadInput.f32(i32 4, i32 0, i32 0, i8 0, i32 undef)  ; LoadInput(inputSigId,rowIndex,colIndex,gsVertexAxis)
  %6 = call float @dx.op.loadInput.f32(i32 4, i32 0, i32 0, i8 1, i32 undef)  ; LoadInput(inputSigId,rowIndex,colIndex,gsVertexAxis)
  %7 = call float @dx.op.loadInput.f32(i32 4, i32 0, i32 0, i8 2, i32 undef)  ; LoadInput(inputSigId,rowIndex,colIndex,gsVertexAxis)
  %8 = call float @dx.op.loadInput.f32(i32 4, i32 0, i32 0, i8 3, i32 undef)  ; LoadInput(inputSigId,rowIndex,colIndex,gsVertexAxis)
  %9 = fmul fast float %2, 2.000000e+00
  %10 = fmul fast float %3, 2.000000e+00
  %11 = fmul fast float %4, 2.000000e+00
  %12 = fadd fast float %9, -1.000000e+00
  %13 = fadd fast float %10, -1.000000e+00
  %14 = fadd fast float %11, -1.000000e+00
  %15 = call %dx.types.CBufRet.f32 @dx.op.cbufferLoadLegacy.f32(i32 59, %dx.types.Handle %1, i32 22)  ; CBufferLoadLegacy(handle,regIndex)
  %16 = extractvalue %dx.types.CBufRet.f32 %15, 0
  %17 = extractvalue %dx.types.CBufRet.f32 %15, 1
  %18 = extractvalue %dx.types.CBufRet.f32 %15, 2
  %19 = extractvalue %dx.types.CBufRet.f32 %15, 3
  %20 = call %dx.types.CBufRet.f32 @dx.op.cbufferLoadLegacy.f32(i32 59, %dx.types.Handle %1, i32 23)  ; CBufferLoadLegacy(handle,regIndex)
  %21 = extractvalue %dx.types.CBufRet.f32 %20, 0
  %22 = extractvalue %dx.types.CBufRet.f32 %20, 1
  %23 = extractvalue %dx.types.CBufRet.f32 %20, 2
  %24 = extractvalue %dx.types.CBufRet.f32 %20, 3
  %25 = call %dx.types.CBufRet.f32 @dx.op.cbufferLoadLegacy.f32(i32 59, %dx.types.Handle %1, i32 24)  ; CBufferLoadLegacy(handle,regIndex)
  %26 = extractvalue %dx.types.CBufRet.f32 %25, 0
  %27 = extractvalue %dx.types.CBufRet.f32 %25, 1
  %28 = extractvalue %dx.types.CBufRet.f32 %25, 2
  %29 = extractvalue %dx.types.CBufRet.f32 %25, 3
  %30 = call %dx.types.CBufRet.f32 @dx.op.cbufferLoadLegacy.f32(i32 59, %dx.types.Handle %1, i32 25)  ; CBufferLoadLegacy(handle,regIndex)
  %31 = extractvalue %dx.types.CBufRet.f32 %30, 0
  %32 = extractvalue %dx.types.CBufRet.f32 %30, 1
  %33 = extractvalue %dx.types.CBufRet.f32 %30, 2
  %34 = extractvalue %dx.types.CBufRet.f32 %30, 3
  %35 = fmul fast float %16, %5
  %36 = call float @dx.op.tertiary.f32(i32 46, float %6, float %17, float %35)  ; FMad(a,b,c)
  %37 = call float @dx.op.tertiary.f32(i32 46, float %7, float %18, float %36)  ; FMad(a,b,c)
  %38 = call float @dx.op.tertiary.f32(i32 46, float %8, float %19, float %37)  ; FMad(a,b,c)
  %39 = fmul fast float %21, %5
  %40 = call float @dx.op.tertiary.f32(i32 46, float %6, float %22, float %39)  ; FMad(a,b,c)
  %41 = call float @dx.op.tertiary.f32(i32 46, float %7, float %23, float %40)  ; FMad(a,b,c)
  %42 = call float @dx.op.tertiary.f32(i32 46, float %8, float %24, float %41)  ; FMad(a,b,c)
  %43 = fmul fast float %26, %5
  %44 = call float @dx.op.tertiary.f32(i32 46, float %6, float %27, float %43)  ; FMad(a,b,c)
  %45 = call float @dx.op.tertiary.f32(i32 46, float %7, float %28, float %44)  ; FMad(a,b,c)
  %46 = call float @dx.op.tertiary.f32(i32 46, float %8, float %29, float %45)  ; FMad(a,b,c)
  %47 = fmul fast float %31, %5
  %48 = call float @dx.op.tertiary.f32(i32 46, float %6, float %32, float %47)  ; FMad(a,b,c)
  %49 = call float @dx.op.tertiary.f32(i32 46, float %7, float %33, float %48)  ; FMad(a,b,c)
  %50 = call float @dx.op.tertiary.f32(i32 46, float %8, float %34, float %49)  ; FMad(a,b,c)
  %51 = call %dx.types.CBufRet.f32 @dx.op.cbufferLoadLegacy.f32(i32 59, %dx.types.Handle %1, i32 15)  ; CBufferLoadLegacy(handle,regIndex)
  %52 = extractvalue %dx.types.CBufRet.f32 %51, 0
  %53 = extractvalue %dx.types.CBufRet.f32 %51, 1
  %54 = extractvalue %dx.types.CBufRet.f32 %51, 2
  %55 = extractvalue %dx.types.CBufRet.f32 %51, 3
  %56 = call %dx.types.CBufRet.f32 @dx.op.cbufferLoadLegacy.f32(i32 59, %dx.types.Handle %1, i32 16)  ; CBufferLoadLegacy(handle,regIndex)
  %57 = extractvalue %dx.types.CBufRet.f32 %56, 0
  %58 = extractvalue %dx.types.CBufRet.f32 %56, 1
  %59 = extractvalue %dx.types.CBufRet.f32 %56, 2
  %60 = extractvalue %dx.types.CBufRet.f32 %56, 3
  %61 = call %dx.types.CBufRet.f32 @dx.op.cbufferLoadLegacy.f32(i32 59, %dx.types.Handle %1, i32 17)  ; CBufferLoadLegacy(handle,regIndex)
  %62 = extractvalue %dx.types.CBufRet.f32 %61, 0
  %63 = extractvalue %dx.types.CBufRet.f32 %61, 1
  %64 = extractvalue %dx.types.CBufRet.f32 %61, 2
  %65 = extractvalue %dx.types.CBufRet.f32 %61, 3
  %66 = fmul fast float %52, %5
  %67 = call float @dx.op.tertiary.f32(i32 46, float %6, float %53, float %66)  ; FMad(a,b,c)
  %68 = call float @dx.op.tertiary.f32(i32 46, float %7, float %54, float %67)  ; FMad(a,b,c)
  %69 = call float @dx.op.tertiary.f32(i32 46, float %8, float %55, float %68)  ; FMad(a,b,c)
  %70 = fmul fast float %57, %5
  %71 = call float @dx.op.tertiary.f32(i32 46, float %6, float %58, float %70)  ; FMad(a,b,c)
  %72 = call float @dx.op.tertiary.f32(i32 46, float %7, float %59, float %71)  ; FMad(a,b,c)
  %73 = call float @dx.op.tertiary.f32(i32 46, float %8, float %60, float %72)  ; FMad(a,b,c)
  %74 = fmul fast float %62, %5
  %75 = call float @dx.op.tertiary.f32(i32 46, float %6, float %63, float %74)  ; FMad(a,b,c)
  %76 = call float @dx.op.tertiary.f32(i32 46, float %7, float %64, float %75)  ; FMad(a,b,c)
  %77 = call float @dx.op.tertiary.f32(i32 46, float %8, float %65, float %76)  ; FMad(a,b,c)
  %78 = call %dx.types.CBufRet.f32 @dx.op.cbufferLoadLegacy.f32(i32 59, %dx.types.Handle %1, i32 19)  ; CBufferLoadLegacy(handle,regIndex)
  %79 = extractvalue %dx.types.CBufRet.f32 %78, 0
  %80 = extractvalue %dx.types.CBufRet.f32 %78, 1
  %81 = extractvalue %dx.types.CBufRet.f32 %78, 2
  %82 = call %dx.types.CBufRet.f32 @dx.op.cbufferLoadLegacy.f32(i32 59, %dx.types.Handle %1, i32 20)  ; CBufferLoadLegacy(handle,regIndex)
  %83 = extractvalue %dx.types.CBufRet.f32 %82, 0
  %84 = extractvalue %dx.types.CBufRet.f32 %82, 1
  %85 = extractvalue %dx.types.CBufRet.f32 %82, 2
  %86 = call %dx.types.CBufRet.f32 @dx.op.cbufferLoadLegacy.f32(i32 59, %dx.types.Handle %1, i32 21)  ; CBufferLoadLegacy(handle,regIndex)
  %87 = extractvalue %dx.types.CBufRet.f32 %86, 0
  %88 = extractvalue %dx.types.CBufRet.f32 %86, 1
  %89 = extractvalue %dx.types.CBufRet.f32 %86, 2
  %90 = fmul fast float %79, %12
  %91 = call float @dx.op.tertiary.f32(i32 46, float %13, float %80, float %90)  ; FMad(a,b,c)
  %92 = call float @dx.op.tertiary.f32(i32 46, float %14, float %81, float %91)  ; FMad(a,b,c)
  %93 = fmul fast float %83, %12
  %94 = call float @dx.op.tertiary.f32(i32 46, float %13, float %84, float %93)  ; FMad(a,b,c)
  %95 = call float @dx.op.tertiary.f32(i32 46, float %14, float %85, float %94)  ; FMad(a,b,c)
  %96 = fmul fast float %87, %12
  %97 = call float @dx.op.tertiary.f32(i32 46, float %13, float %88, float %96)  ; FMad(a,b,c)
  %98 = call float @dx.op.tertiary.f32(i32 46, float %14, float %89, float %97)  ; FMad(a,b,c)
  %99 = call float @dx.op.dot3.f32(i32 55, float %92, float %95, float %98, float %92, float %95, float %98)  ; Dot3(ax,ay,az,bx,by,bz)
  %100 = call float @dx.op.unary.f32(i32 25, float %99)  ; Rsqrt(value)
  %101 = fmul fast float %100, %92
  %102 = fmul fast float %100, %95
  %103 = fmul fast float %100, %98
  %104 = call %dx.types.CBufRet.f32 @dx.op.cbufferLoadLegacy.f32(i32 59, %dx.types.Handle %1, i32 14)  ; CBufferLoadLegacy(handle,regIndex)
  %105 = extractvalue %dx.types.CBufRet.f32 %104, 0
  %106 = extractvalue %dx.types.CBufRet.f32 %104, 1
  %107 = extractvalue %dx.types.CBufRet.f32 %104, 2
  %108 = extractvalue %dx.types.CBufRet.f32 %104, 3
  %109 = call float @dx.op.dot4.f32(i32 56, float %5, float %6, float %7, float %8, float %105, float %106, float %107, float %108)  ; Dot4(ax,ay,az,aw,bx,by,bz,bw)
  %110 = call float @dx.op.unary.f32(i32 7, float %109)  ; Saturate(value)
  call void @dx.op.storeOutput.f32(i32 5, i32 3, i32 0, i8 0, float %38)  ; StoreOutput(outputSigId,rowIndex,colIndex,value)
  call void @dx.op.storeOutput.f32(i32 5, i32 3, i32 0, i8 1, float %42)  ; StoreOutput(outputSigId,rowIndex,colIndex,value)
  call void @dx.op.storeOutput.f32(i32 5, i32 3, i32 0, i8 2, float %46)  ; StoreOutput(outputSigId,rowIndex,colIndex,value)
  call void @dx.op.storeOutput.f32(i32 5, i32 3, i32 0, i8 3, float %50)  ; StoreOutput(outputSigId,rowIndex,colIndex,value)
  call void @dx.op.storeOutput.f32(i32 5, i32 0, i32 0, i8 0, float %69)  ; StoreOutput(outputSigId,rowIndex,colIndex,value)
  call void @dx.op.storeOutput.f32(i32 5, i32 0, i32 0, i8 1, float %73)  ; StoreOutput(outputSigId,rowIndex,colIndex,value)
  call void @dx.op.storeOutput.f32(i32 5, i32 0, i32 0, i8 2, float %77)  ; StoreOutput(outputSigId,rowIndex,colIndex,value)
  call void @dx.op.storeOutput.f32(i32 5, i32 0, i32 0, i8 3, float %110)  ; StoreOutput(outputSigId,rowIndex,colIndex,value)
  call void @dx.op.storeOutput.f32(i32 5, i32 1, i32 0, i8 0, float %101)  ; StoreOutput(outputSigId,rowIndex,colIndex,value)
  call void @dx.op.storeOutput.f32(i32 5, i32 1, i32 0, i8 1, float %102)  ; StoreOutput(outputSigId,rowIndex,colIndex,value)
  call void @dx.op.storeOutput.f32(i32 5, i32 1, i32 0, i8 2, float %103)  ; StoreOutput(outputSigId,rowIndex,colIndex,value)
  %111 = call %dx.types.CBufRet.f32 @dx.op.cbufferLoadLegacy.f32(i32 59, %dx.types.Handle %1, i32 0)  ; CBufferLoadLegacy(handle,regIndex)
  %112 = extractvalue %dx.types.CBufRet.f32 %111, 3
  call void @dx.op.storeOutput.f32(i32 5, i32 2, i32 0, i8 0, float 1.000000e+00)  ; StoreOutput(outputSigId,rowIndex,colIndex,value)
  call void @dx.op.storeOutput.f32(i32 5, i32 2, i32 0, i8 1, float 1.000000e+00)  ; StoreOutput(outputSigId,rowIndex,colIndex,value)
  call void @dx.op.storeOutput.f32(i32 5, i32 2, i32 0, i8 2, float 1.000000e+00)  ; StoreOutput(outputSigId,rowIndex,colIndex,value)
  call void @dx.op.storeOutput.f32(i32 5, i32 2, i32 0, i8 3, float %112)  ; StoreOutput(outputSigId,rowIndex,colIndex,value)
  ret void
}

; Function Attrs: nounwind readnone
declare float @dx.op.loadInput.f32(i32, i32, i32, i8, i32) #0

; Function Attrs: nounwind
declare void @dx.op.storeOutput.f32(i32, i32, i32, i8, float) #1

; Function Attrs: nounwind readonly
declare %dx.types.CBufRet.f32 @dx.op.cbufferLoadLegacy.f32(i32, %dx.types.Handle, i32) #2

; Function Attrs: nounwind readnone
declare float @dx.op.dot3.f32(i32, float, float, float, float, float, float) #0

; Function Attrs: nounwind readnone
declare float @dx.op.unary.f32(i32, float) #0

; Function Attrs: nounwind readnone
declare float @dx.op.dot4.f32(i32, float, float, float, float, float, float, float, float) #0

; Function Attrs: nounwind readnone
declare float @dx.op.tertiary.f32(i32, float, float, float) #0

; Function Attrs: nounwind readonly
declare %dx.types.Handle @dx.op.createHandle(i32, i8, i32, i32, i1) #2

attributes #0 = { nounwind readnone }
attributes #1 = { nounwind }
attributes #2 = { nounwind readonly }

!llvm.ident = !{!0}
!dx.version = !{!1}
!dx.valver = !{!2}
!dx.shaderModel = !{!3}
!dx.resources = !{!4}
!dx.viewIdState = !{!7}
!dx.entryPoints = !{!8}

!0 = !{!"dxc 1.2"}
!1 = !{i32 1, i32 0}
!2 = !{i32 1, i32 5}
!3 = !{!"vs", i32 6, i32 0}
!4 = !{null, null, !5, null}
!5 = !{!6}
!6 = !{i32 0, %dx.alignment.legacy.Parameters* undef, !"", i32 0, i32 0, i32 1, i32 416, null}
!7 = !{[9 x i32] [i32 7, i32 16, i32 61455, i32 61455, i32 61455, i32 61455, i32 112, i32 112, i32 112]}
!8 = !{void ()* @VSBasicPixelLightingBn, !"VSBasicPixelLightingBn", !9, !4, null}
!9 = !{!10, !16, null}
!10 = !{!11, !14}
!11 = !{i32 0, !"SV_Position", i8 9, i8 0, !12, i8 0, i32 1, i8 4, i32 0, i8 0, !13}
!12 = !{i32 0}
!13 = !{i32 3, i32 15}
!14 = !{i32 1, !"NORMAL", i8 9, i8 0, !12, i8 0, i32 1, i8 3, i32 1, i8 0, !15}
!15 = !{i32 3, i32 7}
!16 = !{!17, !18, !20, !21}
!17 = !{i32 0, !"TEXCOORD", i8 9, i8 0, !12, i8 2, i32 1, i8 4, i32 0, i8 0, !13}
!18 = !{i32 1, !"TEXCOORD", i8 9, i8 0, !19, i8 2, i32 1, i8 3, i32 1, i8 0, !15}
!19 = !{i32 1}
!20 = !{i32 2, !"COLOR", i8 9, i8 0, !12, i8 2, i32 1, i8 4, i32 2, i8 0, !13}
!21 = !{i32 3, !"SV_Position", i8 9, i8 3, !12, i8 4, i32 1, i8 4, i32 3, i8 0, !13}

#endif

const unsigned char BasicEffect_VSBasicPixelLightingBn[] = {
  0x44, 0x58, 0x42, 0x43, 0xa5, 0xca, 0x7d, 0x7d, 0xd2, 0x02, 0xec, 0x0d,
  0x7e, 0x8c, 0xe3, 0x7c, 0x88, 0x6f, 0xc9, 0xdb, 0x01, 0x00, 0x00, 0x00,
  0xf7, 0x0d, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00,
  0x50, 0x00, 0x00, 0x00, 0xb3, 0x00, 0x00, 0x00, 0x67, 0x01, 0x00, 0x00,
  0x6f, 0x02, 0x00, 0x00, 0xa7, 0x02, 0x00, 0x00, 0xe3, 0x02, 0x00, 0x00,
  0xff, 0x02, 0x00, 0x00, 0x53, 0x46, 0x49, 0x30, 0x08, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0x53, 0x47, 0x31,
  0x5b, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x48, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x54, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x07, 0x07, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x53, 0x56, 0x5f, 0x50, 0x6f, 0x73, 0x69, 0x74,
  0x69, 0x6f, 0x6e, 0x00, 0x4e, 0x4f, 0x52, 0x4d, 0x41, 0x4c, 0x00, 0x4f,
  0x53, 0x47, 0x31, 0xac, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x08,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x91, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x07,
  0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9a,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
  0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03,
  0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x54,
  0x45, 0x58, 0x43, 0x4f, 0x4f, 0x52, 0x44, 0x00, 0x54, 0x45, 0x58, 0x43,
  0x4f, 0x4f, 0x52, 0x44, 0x00, 0x43, 0x4f, 0x4c, 0x4f, 0x52, 0x00, 0x53,
  0x56, 0x5f, 0x50, 0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x00, 0x50,
  0x53, 0x56, 0x30, 0x00, 0x01, 0x00, 0x00, 0x24, 0x00, 0x00, 0x00, 0x01,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x01,
  0x00, 0x00, 0x00, 0x02, 0x04, 0x00, 0x02, 0x04, 0x00, 0x00, 0x00, 0x01,
  0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2c,
  0x00, 0x00, 0x00, 0x00, 0x53, 0x56, 0x5f, 0x50, 0x6f, 0x73, 0x69, 0x74,
  0x69, 0x6f, 0x6e, 0x00, 0x4e, 0x4f, 0x52, 0x4d, 0x41, 0x4c, 0x00, 0x54,
  0x45, 0x58, 0x43, 0x4f, 0x4f, 0x52, 0x44, 0x00, 0x54, 0x45, 0x58, 0x43,
  0x4f, 0x4f, 0x52, 0x44, 0x00, 0x43, 0x4f, 0x4c, 0x4f, 0x52, 0x00, 0x02,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x10,
  0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x00, 0x44, 0x00, 0x03, 0x00, 0x00, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x01, 0x01, 0x43, 0x00, 0x03, 0x00, 0x00, 0x00, 0x14,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x44, 0x00, 0x03,
  0x02, 0x00, 0x00, 0x1d, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01,
  0x01, 0x43, 0x00, 0x03, 0x02, 0x00, 0x00, 0x26, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x01, 0x02, 0x44, 0x00, 0x03, 0x02, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x44, 0x03, 0x03,
  0x04, 0x00, 0x00, 0x0f, 0xf0, 0x00, 0x00, 0x0f, 0xf0, 0x00, 0x00, 0x0f,
  0xf0, 0x00, 0x00, 0x0f, 0xf0, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70,
  0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x52,
  0x54, 0x53, 0x30, 0x30, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01,
  0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30,
  0x00, 0x00, 0x00, 0x1d, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0x4c, 0x44, 0x4e, 0x34,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 0x00, 0x43, 0x6f, 0x6d, 0x70, 0x69,
  0x6c, 0x65, 0x64, 0x5c, 0x42, 0x61, 0x73, 0x69, 0x63, 0x45, 0x66, 0x66,
  0x65, 0x63, 0x74, 0x5f, 0x56, 0x53, 0x42, 0x61, 0x73, 0x69, 0x63, 0x50,
  0x69, 0x78, 0x65, 0x6c, 0x4c, 0x69, 0x67, 0x68, 0x74, 0x69, 0x6e, 0x67,
  0x42, 0x6e, 0x2e, 0x70, 0x64, 0x62, 0x00, 0x48, 0x41, 0x53, 0x48, 0x14,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xb5, 0x0e, 0x3a, 0x90,
  0x18, 0x2e, 0xed, 0x91, 0xde, 0x99, 0xe8, 0xf3, 0x55, 0xc8, 0xca, 0x44,
  0x58, 0x49, 0x4c, 0xf0, 0x0a, 0x00, 0x00, 0x60, 0x00, 0x01, 0x00, 0xbc,
  0x02, 0x00, 0x00, 0x44, 0x58, 0x49, 0x4c, 0x00, 0x01, 0x00, 0x00, 0x10,
  0x00, 0x00, 0x00, 0xd8, 0x0a, 0x00, 0x00, 0x42, 0x43, 0xc0, 0xde, 0x21,
  0x0c, 0x00, 0x00, 0xb3, 0x02, 0x00, 0x00, 0x0b, 0x82, 0x20, 0x00, 0x02,
  0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x07, 0x81, 0x23, 0x91, 0x41,
  0xc8, 0x04, 0x49, 0x06, 0x10, 0x32, 0x39, 0x92, 0x01, 0x84, 0x0c, 0x25,
  0x05, 0x08, 0x19, 0x1e, 0x04, 0x8b, 0x62, 0x80, 0x18, 0x45, 0x02, 0x42,
  0x92, 0x0b, 0x42, 0xc4, 0x10, 0x32, 0x14, 0x38, 0x08, 0x18, 0x4b, 0x0a,
  0x32, 0x62, 0x88, 0x48, 0x90, 0x14, 0x20, 0x43, 0x46, 0x88, 0xa5, 0x00,
  0x19, 0x32, 0x42, 0xe4, 0x48, 0x0e, 0x90, 0x11, 0x23, 0xc4, 0x50, 0x41,
  0x51, 0x81, 0x8c, 0xe1, 0x83, 0xe5, 0x8a, 0x04, 0x31, 0x46, 0x06, 0x51,
  0x18, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x1b, 0x8c, 0xe0, 0xff, 0xff,
  0xff, 0xff, 0x07, 0x40, 0x02, 0xa8, 0x0d, 0x84, 0xf0, 0xff, 0xff, 0xff,
  0xff, 0x03, 0x20, 0x6d, 0x30, 0x86, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x00,
  0x09, 0xa8, 0x00, 0x49, 0x18, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x13,
  0x82, 0x60, 0x42, 0x20, 0x4c, 0x08, 0x06, 0x00, 0x00, 0x00, 0x00, 0x89,
  0x20, 0x00, 0x00, 0x31, 0x00, 0x00, 0x00, 0x32, 0x22, 0x88, 0x09, 0x20,
  0x64, 0x85, 0x04, 0x13, 0x23, 0xa4, 0x84, 0x04, 0x13, 0x23, 0xe3, 0x84,
  0xa1, 0x90, 0x14, 0x12, 0x4c, 0x8c, 0x8c, 0x0b, 0x84, 0xc4, 0x4c, 0x10,
  0x88, 0xc1, 0x08, 0x40, 0x09, 0x00, 0x0a, 0x66, 0x00, 0xe6, 0x08, 0xc0,
  0x60, 0x8e, 0x00, 0x29, 0xc6, 0x40, 0x10, 0x44, 0x41, 0x90, 0x51, 0x0c,
  0x80, 0x20, 0x88, 0x62, 0x20, 0xe4, 0xa8, 0xe1, 0xf2, 0x27, 0xec, 0x21,
  0x24, 0x9f, 0xdb, 0xa8, 0x62, 0x25, 0x26, 0xbf, 0xb8, 0x6d, 0x44, 0x0c,
  0xc3, 0x30, 0x50, 0x71, 0xcf, 0x70, 0xf9, 0x13, 0xf6, 0x10, 0x92, 0x1f,
  0x02, 0xcd, 0xb0, 0x10, 0x28, 0x58, 0x0a, 0xa1, 0x10, 0x0c, 0x41, 0x4d,
  0x41, 0x06, 0x62, 0x18, 0x86, 0x61, 0x18, 0xe8, 0x29, 0xc3, 0x40, 0x0c,
  0x14, 0x15, 0x65, 0x20, 0x86, 0x61, 0x18, 0x86, 0x61, 0x18, 0x68, 0x2a,
  0xc5, 0x40, 0x0c, 0xc3, 0x40, 0xd5, 0x1c, 0x41, 0x50, 0x0c, 0x86, 0x28,
  0x08, 0xe2, 0x22, 0x6c, 0x20, 0x60, 0x18, 0x81, 0x18, 0x86, 0x11, 0x86,
  0x21, 0x07, 0xb8, 0x24, 0xd8, 0xce, 0x1b, 0x2e, 0x1f, 0x58, 0x10, 0xa3,
  0x61, 0x88, 0x66, 0xf2, 0x17, 0xc2, 0x00, 0x04, 0xcc, 0x4f, 0x81, 0x08,
  0x60, 0x88, 0x89, 0x88, 0x24, 0xd4, 0x6c, 0x1c, 0x37, 0x74, 0x5d, 0xc7,
  0x71, 0x9b, 0xd7, 0x79, 0xf4, 0x65, 0x02, 0x01, 0x00, 0x00, 0x00, 0x13,
  0x14, 0x72, 0xc0, 0x87, 0x74, 0x60, 0x87, 0x36, 0x68, 0x87, 0x79, 0x68,
  0x03, 0x72, 0xc0, 0x87, 0x0d, 0xaf, 0x50, 0x0e, 0x6d, 0xd0, 0x0e, 0x7a,
  0x50, 0x0e, 0x6d, 0x00, 0x0f, 0x7a, 0x30, 0x07, 0x72, 0xa0, 0x07, 0x73,
  0x20, 0x07, 0x6d, 0x90, 0x0e, 0x71, 0xa0, 0x07, 0x73, 0x20, 0x07, 0x6d,
  0x90, 0x0e, 0x78, 0xa0, 0x07, 0x73, 0x20, 0x07, 0x6d, 0x90, 0x0e, 0x71,
  0x60, 0x07, 0x7a, 0x30, 0x07, 0x72, 0xd0, 0x06, 0xe9, 0x30, 0x07, 0x72,
  0xa0, 0x07, 0x73, 0x20, 0x07, 0x6d, 0x90, 0x0e, 0x76, 0x40, 0x07, 0x7a,
  0x60, 0x07, 0x74, 0xd0, 0x06, 0xe6, 0x10, 0x07, 0x76, 0xa0, 0x07, 0x73,
  0x20, 0x07, 0x6d, 0x60, 0x0e, 0x73, 0x20, 0x07, 0x7a, 0x30, 0x07, 0x72,
  0xd0, 0x06, 0xe6, 0x60, 0x07, 0x74, 0xa0, 0x07, 0x76, 0x40, 0x07, 0x6d,
  0xe0, 0x0e, 0x78, 0xa0, 0x07, 0x71, 0x60, 0x07, 0x7a, 0x30, 0x07, 0x72,
  0xa0, 0x07, 0x76, 0x40, 0x07, 0x43, 0x9e, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x86, 0x3c, 0x06, 0x10, 0x00, 0x01,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x79, 0x10, 0x20, 0x00,
  0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0xf2, 0x34, 0x40,
  0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0xe4, 0x79,
  0x80, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0xc8,
  0x13, 0x01, 0x01, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0,
  0x90, 0x67, 0x02, 0x02, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x80, 0x21, 0x4f, 0x05, 0x04, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x43, 0x1e, 0x0c, 0x08, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0xb2, 0x40, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x32,
  0x1e, 0x98, 0x14, 0x19, 0x11, 0x4c, 0x90, 0x8c, 0x09, 0x26, 0x47, 0xc6,
  0x04, 0x43, 0x22, 0x4a, 0x60, 0x04, 0xa0, 0x14, 0x8a, 0xa1, 0x80, 0x0d,
  0xca, 0xa0, 0x3c, 0xca, 0xa1, 0x08, 0xa8, 0x28, 0x89, 0x11, 0x80, 0x42,
  0x28, 0x83, 0x22, 0x20, 0x70, 0x06, 0x80, 0xc2, 0xb1, 0x92, 0x03, 0x7a,
  0x41, 0x3e, 0x78, 0x41, 0x3e, 0x78, 0x41, 0x3e, 0x78, 0x41, 0x3e, 0x80,
  0x07, 0x78, 0x80, 0x07, 0x00, 0x00, 0x00, 0x79, 0x18, 0x00, 0x00, 0x60,
  0x00, 0x00, 0x00, 0x1a, 0x03, 0x4c, 0x90, 0x46, 0x02, 0x13, 0xc4, 0x83,
  0x0c, 0x6f, 0x0c, 0x24, 0xc6, 0x45, 0x66, 0x43, 0x10, 0x4c, 0x10, 0x88,
  0x64, 0x82, 0x40, 0x28, 0x1b, 0x84, 0x81, 0x98, 0x20, 0x10, 0xcb, 0x06,
  0x61, 0x30, 0x28, 0xd8, 0xcd, 0x4d, 0x10, 0x08, 0x66, 0xc3, 0x80, 0x24,
  0xc4, 0x04, 0x01, 0x0c, 0x2e, 0x02, 0x13, 0x04, 0xa2, 0xd9, 0x80, 0x10,
  0x0b, 0x43, 0x10, 0x43, 0x03, 0x6c, 0x08, 0x9c, 0x0d, 0x04, 0x00, 0x3c,
  0xc0, 0x04, 0x21, 0x0c, 0xb0, 0x0d, 0x41, 0x34, 0x41, 0x10, 0x00, 0x5a,
  0x56, 0x53, 0x42, 0x61, 0x73, 0x69, 0x63, 0x50, 0x69, 0x78, 0x65, 0x6c,
  0x4c, 0x69, 0x67, 0x68, 0x74, 0x69, 0x6e, 0x67, 0x42, 0x6e, 0x5c, 0xa6,
  0xac, 0xbe, 0xa0, 0xde, 0xe6, 0xd2, 0xe8, 0xd2, 0xde, 0xdc, 0x26, 0x08,
  0x85, 0x34, 0x41, 0x28, 0xa6, 0x0d, 0x01, 0x31, 0x41, 0x28, 0xa8, 0x09,
  0x02, 0xe1, 0x4c, 0x10, 0x88, 0x67, 0x83, 0xa0, 0x6d, 0x1b, 0x16, 0xa2,
  0xb2, 0x2e, 0xec, 0x1a, 0x32, 0xe2, 0xe2, 0x68, 0x38, 0x3d, 0x49, 0x35,
  0x05, 0x31, 0x4d, 0x10, 0x8a, 0x6a, 0x82, 0x40, 0x40, 0x1b, 0x04, 0x0d,
  0x0c, 0x36, 0x2c, 0x83, 0x67, 0x5d, 0xd8, 0x35, 0x7c, 0xc3, 0x15, 0x06,
  0x1b, 0x84, 0x4e, 0x0c, 0x88, 0x50, 0x15, 0x61, 0x0d, 0x3d, 0x3d, 0x49,
  0x11, 0x4d, 0x10, 0x0a, 0x6b, 0xc3, 0x42, 0x90, 0x81, 0x75, 0x61, 0x65,
  0x30, 0x64, 0xc4, 0xc5, 0x6d, 0x08, 0x86, 0x0d, 0xcb, 0x40, 0x06, 0xd6,
  0x75, 0x06, 0x65, 0x30, 0x7c, 0xc3, 0x15, 0x06, 0x13, 0x04, 0x22, 0x62,
  0x31, 0xf4, 0xc4, 0xf4, 0x24, 0xb5, 0x61, 0x49, 0x03, 0x35, 0xb0, 0x2e,
  0xac, 0x0c, 0x86, 0x2c, 0x0d, 0x2e, 0x6e, 0xc3, 0xa2, 0x55, 0xd6, 0x87,
  0x65, 0x43, 0xa6, 0x5d, 0xdc, 0x06, 0xc2, 0x0c, 0xd0, 0x60, 0x0d, 0xd8,
  0x60, 0xc3, 0x30, 0x06, 0x6d, 0x00, 0x6c, 0x28, 0x26, 0xca, 0x0d, 0x20,
  0xa0, 0x0a, 0x1b, 0x9b, 0x5d, 0x9b, 0x4b, 0x1a, 0x59, 0x99, 0x1b, 0xdd,
  0x94, 0x20, 0xa8, 0x42, 0x86, 0xe7, 0x62, 0x57, 0x26, 0x37, 0x97, 0xf6,
  0xe6, 0x36, 0x25, 0x20, 0x9a, 0x90, 0xe1, 0xb9, 0xd8, 0x85, 0xb1, 0xd9,
  0x95, 0xc9, 0x4d, 0x09, 0x8c, 0x3a, 0x64, 0x78, 0x2e, 0x73, 0x68, 0x61,
  0x64, 0x65, 0x72, 0x4d, 0x6f, 0x64, 0x65, 0x6c, 0x53, 0x82, 0xa4, 0x0c,
  0x19, 0x9e, 0x8b, 0x5c, 0xd9, 0xdc, 0x5b, 0x9d, 0xdc, 0x58, 0xd9, 0xdc,
  0x94, 0xe0, 0xa9, 0x43, 0x86, 0xe7, 0x62, 0x97, 0x56, 0x76, 0x97, 0x44,
  0x36, 0x45, 0x17, 0x46, 0x57, 0x36, 0x25, 0x88, 0xea, 0x90, 0xe1, 0xb9,
  0x94, 0xb9, 0xd1, 0xc9, 0xe5, 0x41, 0xbd, 0xa5, 0xb9, 0xd1, 0xcd, 0x4d,
  0x09, 0xdc, 0x00, 0x79, 0x18, 0x00, 0x00, 0x4c, 0x00, 0x00, 0x00, 0x33,
  0x08, 0x80, 0x1c, 0xc4, 0xe1, 0x1c, 0x66, 0x14, 0x01, 0x3d, 0x88, 0x43,
  0x38, 0x84, 0xc3, 0x8c, 0x42, 0x80, 0x07, 0x79, 0x78, 0x07, 0x73, 0x98,
  0x71, 0x0c, 0xe6, 0x00, 0x0f, 0xed, 0x10, 0x0e, 0xf4, 0x80, 0x0e, 0x33,
  0x0c, 0x42, 0x1e, 0xc2, 0xc1, 0x1d, 0xce, 0xa1, 0x1c, 0x66, 0x30, 0x05,
  0x3d, 0x88, 0x43, 0x38, 0x84, 0x83, 0x1b, 0xcc, 0x03, 0x3d, 0xc8, 0x43,
  0x3d, 0x8c, 0x03, 0x3d, 0xcc, 0x78, 0x8c, 0x74, 0x70, 0x07, 0x7b, 0x08,
  0x07, 0x79, 0x48, 0x87, 0x70, 0x70, 0x07, 0x7a, 0x70, 0x03, 0x76, 0x78,
  0x87, 0x70, 0x20, 0x87, 0x19, 0xcc, 0x11, 0x0e, 0xec, 0x90, 0x0e, 0xe1,
  0x30, 0x0f, 0x6e, 0x30, 0x0f, 0xe3, 0xf0, 0x0e, 0xf0, 0x50, 0x0e, 0x33,
  0x10, 0xc4, 0x1d, 0xde, 0x21, 0x1c, 0xd8, 0x21, 0x1d, 0xc2, 0x61, 0x1e,
  0x66, 0x30, 0x89, 0x3b, 0xbc, 0x83, 0x3b, 0xd0, 0x43, 0x39, 0xb4, 0x03,
  0x3c, 0xbc, 0x83, 0x3c, 0x84, 0x03, 0x3b, 0xcc, 0xf0, 0x14, 0x76, 0x60,
  0x07, 0x7b, 0x68, 0x07, 0x37, 0x68, 0x87, 0x72, 0x68, 0x07, 0x37, 0x80,
  0x87, 0x70, 0x90, 0x87, 0x70, 0x60, 0x07, 0x76, 0x28, 0x07, 0x76, 0xf8,
  0x05, 0x76, 0x78, 0x87, 0x77, 0x80, 0x87, 0x5f, 0x08, 0x87, 0x71, 0x18,
  0x87, 0x72, 0x98, 0x87, 0x79, 0x98, 0x81, 0x2c, 0xee, 0xf0, 0x0e, 0xee,
  0xe0, 0x0e, 0xf5, 0xc0, 0x0e, 0xec, 0x30, 0x03, 0x62, 0xc8, 0xa1, 0x1c,
  0xe4, 0xa1, 0x1c, 0xcc, 0xa1, 0x1c, 0xe4, 0xa1, 0x1c, 0xdc, 0x61, 0x1c,
  0xca, 0x21, 0x1c, 0xc4, 0x81, 0x1d, 0xca, 0x61, 0x06, 0xd6, 0x90, 0x43,
  0x39, 0xc8, 0x43, 0x39, 0x98, 0x43, 0x39, 0xc8, 0x43, 0x39, 0xb8, 0xc3,
  0x38, 0x94, 0x43, 0x38, 0x88, 0x03, 0x3b, 0x94, 0xc3, 0x2f, 0xbc, 0x83,
  0x3c, 0xfc, 0x82, 0x3b, 0xd4, 0x03, 0x3b, 0xb0, 0xc3, 0x8c, 0xcc, 0x21,
  0x07, 0x7c, 0x70, 0x03, 0x74, 0x60, 0x07, 0x37, 0x90, 0x87, 0x72, 0x98,
  0x87, 0x77, 0xa8, 0x07, 0x79, 0x18, 0x87, 0x72, 0x70, 0x83, 0x70, 0xa0,
  0x07, 0x7a, 0x90, 0x87, 0x74, 0x10, 0x87, 0x7a, 0xa0, 0x87, 0x72, 0x00,
  0x00, 0x00, 0x00, 0x71, 0x20, 0x00, 0x00, 0x25, 0x00, 0x00, 0x00, 0x06,
  0x60, 0xbd, 0xec, 0x06, 0x48, 0x88, 0x90, 0x22, 0x17, 0xb1, 0x94, 0x88,
  0x71, 0x4c, 0x48, 0x63, 0x6c, 0x8d, 0x0d, 0x6c, 0xc3, 0xe5, 0x3b, 0x8f,
  0x2f, 0x04, 0x54, 0x51, 0x10, 0x51, 0xe9, 0x00, 0x43, 0x49, 0x18, 0x80,
  0x80, 0xf9, 0xc5, 0x6d, 0x1b, 0x82, 0x34, 0x5c, 0xbe, 0xf3, 0xf8, 0x42,
  0x44, 0x00, 0x13, 0x11, 0x02, 0xcd, 0xb0, 0x10, 0x46, 0xe0, 0x0c, 0x97,
  0xef, 0x3c, 0xfe, 0xe0, 0x4c, 0xb7, 0x5f, 0xdc, 0xb6, 0x19, 0x38, 0xc3,
  0xe5, 0x3b, 0x8f, 0x3f, 0x38, 0x13, 0xee, 0x17, 0xb7, 0x6d, 0x01, 0xd3,
  0x70, 0xf9, 0xce, 0xe3, 0x2f, 0x0e, 0x30, 0x88, 0xcd, 0x43, 0x4d, 0x7e,
  0x71, 0xdb, 0x26, 0x50, 0x0d, 0x97, 0xef, 0x3c, 0xbe, 0x34, 0x39, 0x11,
  0x81, 0x52, 0xd3, 0x43, 0x4d, 0x7e, 0x71, 0xdb, 0x76, 0x20, 0x0d, 0x97,
  0xef, 0x3c, 0xfe, 0x44, 0x44, 0x13, 0x02, 0x44, 0x98, 0x5f, 0xdc, 0xb6,
  0x15, 0x3c, 0xc3, 0xe5, 0x3b, 0x8f, 0x4f, 0x35, 0x40, 0x84, 0xf9, 0xc5,
  0x6d, 0x03, 0x00, 0x61, 0x20, 0x00, 0x00, 0x2e, 0x01, 0x00, 0x00, 0x13,
  0x04, 0x41, 0x2c, 0x10, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x74,
  0x8d, 0x00, 0x50, 0x51, 0x02, 0x44, 0x14, 0x5c, 0x71, 0x95, 0x5d, 0x21,
  0xcc, 0x00, 0x94, 0x4c, 0xc9, 0x15, 0x4b, 0xb9, 0x14, 0x4c, 0x81, 0x94,
  0x48, 0x99, 0x14, 0x4a, 0xa9, 0x94, 0x5b, 0x71, 0xd0, 0x30, 0x46, 0x00,
  0x82, 0x20, 0x88, 0x7f, 0x63, 0x04, 0x20, 0x08, 0x82, 0xf8, 0x2f, 0x8c,
  0x11, 0x80, 0x20, 0x08, 0x82, 0x60, 0x00, 0x23, 0x06, 0x09, 0x00, 0x82,
  0x60, 0x80, 0x9d, 0x81, 0x93, 0x95, 0x41, 0x19, 0x58, 0x23, 0x06, 0x09,
  0x00, 0x82, 0x60, 0x60, 0xbc, 0x81, 0x74, 0x06, 0x66, 0xd0, 0x45, 0x23,
  0x06, 0x09, 0x00, 0x82, 0x60, 0x60, 0xc0, 0xc1, 0x84, 0x06, 0x67, 0x70,
  0x49, 0x23, 0x06, 0x09, 0x00, 0x82, 0x60, 0x60, 0xc4, 0x01, 0x95, 0x06,
  0x68, 0xc0, 0x4d, 0x23, 0x06, 0x09, 0x00, 0x82, 0x60, 0x60, 0xc8, 0x41,
  0x95, 0x06, 0x69, 0x00, 0x06, 0xd4, 0x88, 0x41, 0x02, 0x80, 0x20, 0x18,
  0x18, 0x73, 0x60, 0xa9, 0x81, 0x1a, 0x68, 0xd5, 0x88, 0x41, 0x02, 0x80,
  0x20, 0x18, 0x18, 0x74, 0x70, 0xad, 0xc1, 0x1a, 0x7c, 0xd6, 0x88, 0x41,
  0x02, 0x80, 0x20, 0x18, 0x18, 0x75, 0x80, 0xb1, 0x01, 0x1b, 0x84, 0xc1,
  0x65, 0x47, 0x22, 0x1f, 0x3b, 0x14, 0xf9, 0xd8, 0xb1, 0xc8, 0xc7, 0x86,
  0x06, 0x3e, 0x36, 0x38, 0xf0, 0xb1, 0xe1, 0x81, 0xcf, 0x88, 0xc1, 0x01,
  0x80, 0x20, 0x18, 0x34, 0x7a, 0x00, 0x06, 0xce, 0x36, 0x9a, 0x10, 0x00,
  0xa3, 0x09, 0x42, 0x30, 0x9a, 0x30, 0x08, 0xa3, 0x09, 0xc4, 0x30, 0x62,
  0x70, 0x00, 0x20, 0x08, 0x06, 0xcd, 0x1f, 0x94, 0xc1, 0xf4, 0x8d, 0x26,
  0x04, 0xc0, 0x68, 0x82, 0x10, 0x8c, 0x26, 0x0c, 0xc2, 0x68, 0x02, 0x31,
  0x8c, 0x18, 0x1c, 0x00, 0x08, 0x82, 0x41, 0x43, 0x0a, 0x6a, 0x80, 0x8d,
  0xc1, 0x68, 0x42, 0x00, 0x8c, 0x26, 0x08, 0xc1, 0x68, 0xc2, 0x20, 0x8c,
  0x26, 0x10, 0xc3, 0x88, 0xc1, 0x01, 0x80, 0x20, 0x18, 0x34, 0xa9, 0xf0,
  0x06, 0x1d, 0x1b, 0x8c, 0x26, 0x04, 0xc0, 0x68, 0x82, 0x10, 0x8c, 0x26,
  0x0c, 0xc2, 0x68, 0x02, 0x31, 0xd8, 0xe4, 0xc9, 0x67, 0xc4, 0x00, 0x01,
  0x40, 0x10, 0x0c, 0xaa, 0x55, 0xb0, 0x03, 0x6f, 0x0a, 0x46, 0x0c, 0x10,
  0x00, 0x04, 0xc1, 0xa0, 0x62, 0x85, 0x3b, 0xf0, 0xa6, 0x60, 0xc4, 0x00,
  0x01, 0x40, 0x10, 0x0c, 0xaa, 0x56, 0xc0, 0x03, 0x6f, 0x0a, 0x4c, 0x12,
  0x03, 0xf9, 0x8c, 0x18, 0x20, 0x00, 0x08, 0x82, 0x41, 0xf5, 0x0a, 0x7a,
  0x20, 0x06, 0x52, 0x30, 0x62, 0x80, 0x00, 0x20, 0x08, 0x06, 0x15, 0x2c,
  0xec, 0x81, 0x18, 0x48, 0xc1, 0x88, 0x01, 0x02, 0x80, 0x20, 0x18, 0x54,
  0xb1, 0xc0, 0x07, 0x62, 0x20, 0x05, 0x16, 0x99, 0x81, 0x7c, 0x46, 0x0c,
  0x10, 0x00, 0x04, 0xc1, 0xa0, 0x9a, 0x05, 0x3f, 0x30, 0x83, 0x28, 0x18,
  0x31, 0x40, 0x00, 0x10, 0x04, 0x83, 0x8a, 0x16, 0xfe, 0xc0, 0x0c, 0xa2,
  0x60, 0xc4, 0x00, 0x01, 0x40, 0x10, 0x0c, 0xaa, 0x5a, 0x00, 0x05, 0x33,
  0x88, 0x02, 0x83, 0xd4, 0x40, 0x3e, 0x23, 0x06, 0x08, 0x00, 0x82, 0x60,
  0x50, 0xdd, 0x82, 0x28, 0xa8, 0x01, 0x14, 0x8c, 0x18, 0x20, 0x00, 0x08,
  0x82, 0x41, 0x85, 0x0b, 0xa3, 0xa0, 0x06, 0x50, 0x30, 0x62, 0x80, 0x00,
  0x20, 0x08, 0x06, 0x55, 0x2e, 0x90, 0x82, 0x1a, 0x40, 0xc1, 0x88, 0xc1,
  0x01, 0x80, 0x20, 0x18, 0x34, 0xbe, 0x40, 0x0a, 0x72, 0x20, 0x0b, 0xa3,
  0x09, 0x01, 0x30, 0x9a, 0x20, 0x04, 0xa3, 0x09, 0x83, 0x30, 0x9a, 0x40,
  0x0c, 0x23, 0x06, 0x07, 0x00, 0x82, 0x60, 0xd0, 0x8c, 0x43, 0x2a, 0xdc,
  0x41, 0x28, 0x8c, 0x26, 0x04, 0xc0, 0x68, 0x82, 0x10, 0x8c, 0x26, 0x0c,
  0xc2, 0x68, 0x02, 0x31, 0x8c, 0x18, 0x1c, 0x00, 0x08, 0x82, 0x41, 0x83,
  0x0e, 0xae, 0xc0, 0x07, 0xa5, 0x30, 0x9a, 0x10, 0x00, 0xa3, 0x09, 0x42,
  0x30, 0x9a, 0x30, 0x08, 0xa3, 0x09, 0xc4, 0x60, 0x4e, 0x1f, 0xc8, 0x67,
  0xc4, 0x00, 0x01, 0x40, 0x10, 0x0c, 0x2a, 0x75, 0xa8, 0x85, 0x3e, 0x70,
  0x82, 0x11, 0x03, 0x04, 0x00, 0x41, 0x30, 0xa8, 0xd6, 0xc1, 0x16, 0xfa,
  0xc0, 0x09, 0x46, 0x0c, 0x10, 0x00, 0x04, 0xc1, 0xa0, 0x62, 0x87, 0x5b,
  0xe8, 0x03, 0x27, 0xb0, 0x26, 0x14, 0xe4, 0x33, 0x62, 0x80, 0x00, 0x20,
  0x08, 0x06, 0x95, 0x3b, 0xe4, 0x42, 0x28, 0x34, 0xc1, 0x88, 0x01, 0x02,
  0x80, 0x20, 0x18, 0x54, 0xef, 0xa0, 0x0b, 0xa1, 0xd0, 0x04, 0x23, 0x06,
  0x08, 0x00, 0x82, 0x60, 0x50, 0xc1, 0xc3, 0x2e, 0x84, 0x42, 0x13, 0x18,
  0x53, 0x0a, 0xf2, 0x19, 0x31, 0x40, 0x00, 0x10, 0x04, 0x83, 0x4a, 0x1e,
  0x7a, 0xa1, 0x14, 0x98, 0x60, 0xc4, 0x00, 0x01, 0x40, 0x10, 0x0c, 0xaa,
  0x79, 0xf0, 0x85, 0x52, 0x60, 0x82, 0x11, 0x03, 0x04, 0x00, 0x41, 0x30,
  0xa8, 0xe8, 0xe1, 0x17, 0x4a, 0x81, 0x09, 0x46, 0x0c, 0x0e, 0x00, 0x04,
  0xc1, 0xa0, 0xc9, 0x87, 0x5f, 0x68, 0x85, 0x5a, 0x18, 0x4d, 0x08, 0x80,
  0xd1, 0x04, 0x21, 0x18, 0x4d, 0x18, 0x84, 0x11, 0x83, 0x03, 0x00, 0x41,
  0x30, 0x68, 0xfa, 0x61, 0x1c, 0x62, 0x01, 0x17, 0x46, 0x13, 0x02, 0x60,
  0x34, 0x41, 0x08, 0x46, 0x13, 0x06, 0x61, 0xc4, 0xe0, 0x00, 0x40, 0x10,
  0x0c, 0x9a, 0x90, 0x38, 0x87, 0x5a, 0xd8, 0x85, 0xd1, 0x84, 0x00, 0x18,
  0x4d, 0x10, 0x82, 0xd1, 0x84, 0x41, 0xb0, 0xc5, 0x15, 0xe4, 0x33, 0x62,
  0x80, 0x00, 0x20, 0x08, 0x06, 0x95, 0x48, 0xb4, 0x83, 0x2b, 0x2c, 0xc1,
  0x88, 0x01, 0x02, 0x80, 0x20, 0x18, 0x54, 0x23, 0xe1, 0x0e, 0xae, 0xb0,
  0x04, 0xa6, 0xc4, 0x82, 0x7c, 0x46, 0x0c, 0x10, 0x00, 0x04, 0xc1, 0xa0,
  0x2a, 0x09, 0x78, 0x88, 0x05, 0x25, 0x18, 0x31, 0x40, 0x00, 0x10, 0x04,
  0x83, 0xca, 0x24, 0xe2, 0x21, 0x16, 0x94, 0xc0, 0x12, 0x5a, 0x90, 0xcf,
  0x88, 0x01, 0x02, 0x80, 0x20, 0x18, 0x54, 0x28, 0x31, 0x0f, 0xb4, 0x90,
  0x04, 0x23, 0x06, 0x08, 0x00, 0x82, 0x60, 0x50, 0xa5, 0x04, 0x3d, 0xd0,
  0x42, 0x12, 0x8c, 0x18, 0x2c, 0x00, 0x08, 0x82, 0xc1, 0xd3, 0x12, 0xe7,
  0x70, 0x10, 0xc1, 0x41, 0x04, 0x23, 0x06, 0x06, 0x00, 0x82, 0x60, 0x10,
  0xb5, 0x84, 0x3c, 0x04, 0x16, 0x24, 0xf2, 0x31, 0xe1, 0x90, 0x8f, 0x0d,
  0x85, 0x7c, 0x46, 0x0c, 0x0e, 0x00, 0x04, 0xc1, 0xa0, 0x99, 0x89, 0x7c,
  0x38, 0x87, 0x75, 0x18, 0x4d, 0x08, 0x80, 0xd1, 0x04, 0x21, 0x18, 0x4d,
  0x18, 0x84, 0xd1, 0x04, 0x62, 0x18, 0x31, 0x68, 0x00, 0x10, 0x04, 0x83,
  0xa9, 0x26, 0x40, 0x02, 0x1d, 0xce, 0xc1, 0x1c, 0xca, 0x81, 0x18, 0x84,
  0x60, 0xc4, 0xc0, 0x00, 0x40, 0x10, 0x0c, 0xa2, 0x9b, 0x60, 0x89, 0x60,
  0xc4, 0x20, 0x01, 0x40, 0x10, 0x0c, 0x90, 0x9d, 0x90, 0x89, 0x97, 0x98,
  0x09, 0x95, 0x48, 0x85, 0x11, 0x83, 0x04, 0x00, 0x41, 0x30, 0x40, 0x76,
  0x42, 0x26, 0x5e, 0x62, 0x26, 0x46, 0xa2, 0x14, 0x46, 0x0c, 0x12, 0x00,
  0x04, 0xc1, 0x00, 0xd9, 0x09, 0x99, 0x78, 0x89, 0x99, 0x38, 0x89, 0x50,
  0x18, 0x31, 0x48, 0x00, 0x10, 0x04, 0x03, 0x64, 0x27, 0x64, 0xe2, 0x25,
  0x66, 0x02, 0x25, 0xfa, 0x60, 0xc4, 0x20, 0x01, 0x40, 0x10, 0x0c, 0x90,
  0x9d, 0x90, 0x89, 0x99, 0x98, 0x09, 0x95, 0x50, 0x83, 0x11, 0x83, 0x04,
  0x00, 0x41, 0x30, 0x40, 0x76, 0x42, 0x26, 0x66, 0x62, 0x26, 0x46, 0xc2,
  0x0c, 0x46, 0x0c, 0x12, 0x00, 0x04, 0xc1, 0x00, 0xd9, 0x09, 0x99, 0x98,
  0x89, 0x99, 0x38, 0x09, 0x31, 0x18, 0x31, 0x48, 0x00, 0x10, 0x04, 0x03,
  0x64, 0x27, 0x64, 0x62, 0x26, 0x66, 0x02, 0x25, 0x82, 0x11, 0x83, 0x04,
  0x00, 0x41, 0x30, 0x40, 0x76, 0x42, 0x26, 0x68, 0x62, 0x26, 0x54, 0x42,
  0x19, 0x31, 0x48, 0x00, 0x10, 0x04, 0x03, 0x64, 0x27, 0x64, 0x82, 0x26,
  0x66, 0x62, 0x24, 0x92, 0x11, 0x83, 0x04, 0x00, 0x41, 0x30, 0x40, 0x76,
  0x42, 0x26, 0x68, 0x62, 0x26, 0x4e, 0x02, 0x19, 0x31, 0x38, 0x00, 0x10,
  0x04, 0x83, 0x46, 0x27, 0x40, 0xc2, 0x1d, 0x66, 0x62, 0x34, 0x21, 0x18,
  0x46, 0x0c, 0x12, 0x00, 0x04, 0xc1, 0x00, 0xe9, 0x09, 0x9a, 0x70, 0x89,
  0x9a, 0x60, 0x89, 0x79, 0x18, 0x31, 0x48, 0x00, 0x10, 0x04, 0x03, 0xa4,
  0x27, 0x68, 0xc2, 0x25, 0x6a, 0xa2, 0x24, 0xe6, 0x61, 0xc4, 0x20, 0x01,
  0x40, 0x10, 0x0c, 0x90, 0x9e, 0xa0, 0x09, 0x97, 0xa8, 0x89, 0x94, 0x98,
  0x87, 0x11, 0x83, 0x04, 0x00, 0x41, 0x30, 0x40, 0x7a, 0x82, 0x26, 0x5c,
  0xa2, 0x26, 0x54, 0x22, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
