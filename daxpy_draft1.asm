; for testing: disp/8fw 0x403028
;              disp $xmm1.v2_double
;              disp $xmm2.v2_double
;              disp $xmm3.v2_double
; NOT YET SURE IF WORKING WITH C CODE

section .text
bits 64
default rel
global daxpy_sasm
daxpy_sasm:
    ; rcx <- n
    ; rdx <- scalar_A
    ; r8 <-  vector_X
    ; r9 <-  vector_Y
    ; rsp+32 <- vector_Z
    
    mov rbp, rsp; for correct debugging
    movsd xmm1, [rdx] ; xmm1 <- scalarA
    mov rsi, 8
    
    L1:
        movsd xmm2, [r8] ; xmm2 <- vectorX
        movsd xmm3, [r9] ; xmm1 <- vectorY
        mulsd xmm2, xmm1     ; scale X[i] by A 
        addsd xmm3, xmm2     ; add Y to result
        movsd [rsp+rsi], xmm3    ; store result to Z[i]
        
        add r8, 8
        add r9, 8
        add rsi, 8
        
        DEC RCX
        CMP rcx, 0
        je exit
        jmp L1
        
    exit:
    xor rax, rax
    ret