section .text
bits 64
default rel
global daxpy_sasm
daxpy_sasm:
    
    movsd xmm1, [rdx]
    
    push rbp
    mov rbp, rsp
    add rbp, 8
    
    mov r10, [rbp+40]
    
    L1:
        movsd xmm2, [r8]     ; xmm2 <- vectorX
        movsd xmm3, [r9]     ; xmm3 <- vectorY
        mulsd xmm2, xmm1     ; scale X[i] by A 
        addsd xmm3, xmm2     ; add Y to result
        movsd [r10], xmm3    ; store result to Z[i]
        
        add r8, 8
        add r9, 8
        add r10, 8
        
        DEC RCX
        JNZ L1
        
      xor rax, rax
        
      pop rbp
      ret