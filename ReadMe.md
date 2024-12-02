## Running the Program

1. Open the directory.
2. Compile and link the program using the following commands:

```bash
nasm -f win64 daxpy_asm.asm
gcc -c daxpy_c.c -o daxpy_c.obj -m64
gcc -c c_main.c -o c_main.obj -m64
gcc c_main.obj daxpy_c.obj daxpy_asm.obj -o daxpy_mp.exe -m64
daxpy_mp.exe

```

## Analysis of C and x86-64 Assembly Kernels
This project aims to compare the execution times of a DAXPY implementation in both C and x86-64 assembly language. Execution times were recorded 30 times for each implementation, using three vector lengths (2^20, 2^24, and 2^28).

Across all three vector lengths, it is observed that the x86-64 assembly implementation consistently outperformed its C counterpart:
- For 2^20: Assembly was 49.21% faster, with an average execution time of 0.001033s compared to C's 0.002033s.
- For 2^24: Assembly was 50.00% faster, having an average execution time of 0.017267s versus C's 0.034533s.
- For 2^28: Assembly was 51.23% faster, averaging 0.273733s compared to C's 0.561167s.

These results highlight the efficiency of low-level assembly optimizations through its direct access to CPU registers and reduced instruction overhead compared to the higher-level C implementation.


## Screenshots 

![Alt Text](screenshot.png)

## Execution times of both programs

Execution # 1
Vector Length: 2, 20
C file execution time: 0.003000
ASM file execution time: 0.001000

Execution # 2
Vector Length: 2, 20
C file execution time: 0.002000
ASM file execution time: 0.001000

Execution # 3
Vector Length: 2, 20
C file execution time: 0.002000
ASM file execution time: 0.001000

Execution # 4
Vector Length: 2, 20
C file execution time: 0.002000
ASM file execution time: 0.001000

Execution # 5
Vector Length: 2, 20
C file execution time: 0.002000
ASM file execution time: 0.001000

Execution # 6
Vector Length: 2, 20
C file execution time: 0.002000
ASM file execution time: 0.001000

Execution # 7
Vector Length: 2, 20
C file execution time: 0.002000
ASM file execution time: 0.001000

Execution # 8
Vector Length: 2, 20
C file execution time: 0.003000
ASM file execution time: 0.001000

Execution # 9
Vector Length: 2, 20
C file execution time: 0.002000
ASM file execution time: 0.001000

Execution # 10
Vector Length: 2, 20
C file execution time: 0.001000
ASM file execution time: 0.001000

Execution # 11
Vector Length: 2, 20
C file execution time: 0.002000
ASM file execution time: 0.001000

Execution # 12
Vector Length: 2, 20
C file execution time: 0.002000
ASM file execution time: 0.001000

Execution # 13
Vector Length: 2, 20
C file execution time: 0.003000
ASM file execution time: 0.001000

Execution # 14
Vector Length: 2, 20
C file execution time: 0.002000
ASM file execution time: 0.001000

Execution # 15
Vector Length: 2, 20
C file execution time: 0.002000
ASM file execution time: 0.001000

Execution # 16
Vector Length: 2, 20
C file execution time: 0.002000
ASM file execution time: 0.001000

Execution # 17
Vector Length: 2, 20
C file execution time: 0.002000
ASM file execution time: 0.001000

Execution # 18
Vector Length: 2, 20
C file execution time: 0.002000
ASM file execution time: 0.001000

Execution # 19
Vector Length: 2, 20
C file execution time: 0.002000
ASM file execution time: 0.001000

Execution # 20
Vector Length: 2, 20
C file execution time: 0.002000
ASM file execution time: 0.001000

Execution # 21
Vector Length: 2, 20
C file execution time: 0.002000
ASM file execution time: 0.001000

Execution # 22
Vector Length: 2, 20
C file execution time: 0.001000
ASM file execution time: 0.001000

Execution # 23
Vector Length: 2, 20
C file execution time: 0.002000
ASM file execution time: 0.001000

Execution # 24
Vector Length: 2, 20
C file execution time: 0.002000
ASM file execution time: 0.001000

Execution # 25
Vector Length: 2, 20
C file execution time: 0.002000
ASM file execution time: 0.002000

Execution # 26
Vector Length: 2, 20
C file execution time: 0.002000
ASM file execution time: 0.001000

Execution # 27
Vector Length: 2, 20
C file execution time: 0.002000
ASM file execution time: 0.001000

Execution # 28
Vector Length: 2, 20
C file execution time: 0.002000
ASM file execution time: 0.001000

Execution # 29
Vector Length: 2, 20
C file execution time: 0.002000
ASM file execution time: 0.001000

Execution # 30
Vector Length: 2, 20
C file execution time: 0.002000
ASM file execution time: 0.001000

Execution # 1
Vector Length: 2, 24
C file execution time: 0.037000
ASM file execution time: 0.018000

Execution # 2
Vector Length: 2, 24
C file execution time: 0.037000
ASM file execution time: 0.018000

Execution # 3
Vector Length: 2, 24
C file execution time: 0.036000
ASM file execution time: 0.017000

Execution # 4
Vector Length: 2, 24
C file execution time: 0.034000
ASM file execution time: 0.018000

Execution # 5
Vector Length: 2, 24
C file execution time: 0.034000
ASM file execution time: 0.017000

Execution # 6
Vector Length: 2, 24
C file execution time: 0.035000
ASM file execution time: 0.018000

Execution # 7
Vector Length: 2, 24
C file execution time: 0.034000
ASM file execution time: 0.017000

Execution # 8
Vector Length: 2, 24
C file execution time: 0.034000
ASM file execution time: 0.016000

Execution # 9
Vector Length: 2, 24
C file execution time: 0.031000
ASM file execution time: 0.016000

Execution # 10
Vector Length: 2, 24
C file execution time: 0.036000
ASM file execution time: 0.019000

Execution # 11
Vector Length: 2, 24
C file execution time: 0.036000
ASM file execution time: 0.016000

Execution # 12
Vector Length: 2, 24
C file execution time: 0.034000
ASM file execution time: 0.018000

Execution # 13
Vector Length: 2, 24
C file execution time: 0.032000
ASM file execution time: 0.018000

Execution # 14
Vector Length: 2, 24
C file execution time: 0.033000
ASM file execution time: 0.016000

Execution # 15
Vector Length: 2, 24
C file execution time: 0.036000
ASM file execution time: 0.019000

Execution # 16
Vector Length: 2, 24
C file execution time: 0.037000
ASM file execution time: 0.020000

Execution # 17
Vector Length: 2, 24
C file execution time: 0.033000
ASM file execution time: 0.017000

Execution # 18
Vector Length: 2, 24
C file execution time: 0.035000
ASM file execution time: 0.017000

Execution # 19
Vector Length: 2, 24
C file execution time: 0.034000
ASM file execution time: 0.017000

Execution # 20
Vector Length: 2, 24
C file execution time: 0.031000
ASM file execution time: 0.018000

Execution # 21
Vector Length: 2, 24
C file execution time: 0.033000
ASM file execution time: 0.017000

Execution # 22
Vector Length: 2, 24
C file execution time: 0.036000
ASM file execution time: 0.018000

Execution # 23
Vector Length: 2, 24
C file execution time: 0.035000
ASM file execution time: 0.016000

Execution # 24
Vector Length: 2, 24
C file execution time: 0.036000
ASM file execution time: 0.017000

Execution # 25
Vector Length: 2, 24
C file execution time: 0.036000
ASM file execution time: 0.017000

Execution # 26
Vector Length: 2, 24
C file execution time: 0.034000
ASM file execution time: 0.017000

Execution # 27
Vector Length: 2, 24
C file execution time: 0.033000
ASM file execution time: 0.016000

Execution # 28
Vector Length: 2, 24
C file execution time: 0.033000
ASM file execution time: 0.016000

Execution # 29
Vector Length: 2, 24
C file execution time: 0.036000
ASM file execution time: 0.017000

Execution # 30
Vector Length: 2, 24
C file execution time: 0.035000
ASM file execution time: 0.017000

Execution # 1
Vector Length: 2, 28
C file execution time: 0.593000
ASM file execution time: 0.259000

Execution # 2
Vector Length: 2, 28
C file execution time: 0.603000
ASM file execution time: 0.273000

Execution # 3
Vector Length: 2, 28
C file execution time: 0.590000
ASM file execution time: 0.294000

Execution # 4
Vector Length: 2, 28
C file execution time: 0.585000
ASM file execution time: 0.277000

Execution # 5
Vector Length: 2, 28
C file execution time: 0.593000
ASM file execution time: 0.277000

Execution # 6
Vector Length: 2, 28
C file execution time: 0.580000
ASM file execution time: 0.286000

Execution # 7
Vector Length: 2, 28
C file execution time: 0.577000
ASM file execution time: 0.276000

Execution # 8
Vector Length: 2, 28
C file execution time: 0.588000
ASM file execution time: 0.282000

Execution # 9
Vector Length: 2, 28
C file execution time: 0.571000
ASM file execution time: 0.277000

Execution # 10
Vector Length: 2, 28
C file execution time: 0.626000
ASM file execution time: 0.275000

Execution # 11
Vector Length: 2, 28
C file execution time: 0.533000
ASM file execution time: 0.271000

Execution # 12
Vector Length: 2, 28
C file execution time: 0.563000
ASM file execution time: 0.273000

Execution # 13
Vector Length: 2, 28
C file execution time: 0.561000
ASM file execution time: 0.282000

Execution # 14
Vector Length: 2, 28
C file execution time: 0.572000
ASM file execution time: 0.269000

Execution # 15
Vector Length: 2, 28
C file execution time: 0.527000
ASM file execution time: 0.273000

Execution # 16
Vector Length: 2, 28
C file execution time: 0.552000
ASM file execution time: 0.286000

Execution # 17
Vector Length: 2, 28
C file execution time: 0.546000
ASM file execution time: 0.273000

Execution # 18
Vector Length: 2, 28
C file execution time: 0.521000
ASM file execution time: 0.255000

Execution # 19
Vector Length: 2, 28
C file execution time: 0.528000
ASM file execution time: 0.268000

Execution # 20
Vector Length: 2, 28
C file execution time: 0.546000
ASM file execution time: 0.269000

Execution # 21
Vector Length: 2, 28
C file execution time: 0.528000
ASM file execution time: 0.262000

Execution # 22
Vector Length: 2, 28
C file execution time: 0.574000
ASM file execution time: 0.272000

Execution # 23
Vector Length: 2, 28
C file execution time: 0.544000
ASM file execution time: 0.276000

Execution # 24
Vector Length: 2, 28
C file execution time: 0.570000
ASM file execution time: 0.263000

Execution # 25
Vector Length: 2, 28
C file execution time: 0.554000
ASM file execution time: 0.275000

Execution # 26
Vector Length: 2, 28
C file execution time: 0.539000
ASM file execution time: 0.275000

Execution # 27
Vector Length: 2, 28
C file execution time: 0.553000
ASM file execution time: 0.277000

Execution # 28
Vector Length: 2, 28
C file execution time: 0.541000
ASM file execution time: 0.274000

Execution # 29
Vector Length: 2, 28
C file execution time: 0.545000
ASM file execution time: 0.279000

Execution # 30
Vector Length: 2, 28
C file execution time: 0.532000
ASM file execution time: 0.264000

Average for last 30 executions:
C file average execution time: 0.002033 seconds
ASM file average execution time: 0.001033 seconds

Average for last 30 executions:
C file average execution time: 0.034533 seconds
ASM file average execution time: 0.017267 seconds

Average for last 30 executions:
C file average execution time: 0.561167 seconds
ASM file average execution time: 0.273733 seconds

