; for testing: disp/8fw 0x403028
;              disp $xmm1.v2_double
;              disp $xmm2.v2_double
;              disp $xmm3.v2_double

%include "io64.inc"

section .data
vector_len dw 3
scalar_A dq 2.0
vector_X dq 1.0, 2.0, 3.0
vector_Y dq 11.0, 12.0, 13.0
vector_Z dq 0.0, 0.0, 0.0

section .text
global main
main:
    mov rbp, rsp; for correct debugging
    ;write your code here
    mov rcx, [vector_len] ; loop n times (vector length)
    lea rsi, [scalar_A] ; get addr of scalar A
    lea rdi, [vector_X] ; get addr of vector X 
    lea rdx, [vector_Y] ; get addr of vector X 
    lea rbx, [vector_Z] ; store result of vector scaling here
    
    movsd xmm1, [rsi]
    
    L1:
        movsd xmm2, [rdi]
        movsd xmm3, [rdx]
        mulsd xmm2, xmm1     ; scale X[i] by A 
        addsd xmm3, xmm2     ; add Y to result
        movsd [rbx], xmm3    ; store result to Z[i]
        
        add rdi, 8
        add rdx, 8
        add rbx, 8
        
        DEC RCX
        CMP rcx, 0
        je exit
        jmp L1
        
    exit:
    xor rax, rax
    ret