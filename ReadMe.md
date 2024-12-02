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


## Screenshots 

![Alt Text](screenshot.png)

## Execution times of both programs


Vector Length: 2, 20
C file execution time: 0.002000
ASM file execution time: 0.001000

Vector Length: 2, 20
C file execution time: 0.003000
ASM file execution time: 0.001000

Vector Length: 2, 20
C file execution time: 0.002000
ASM file execution time: 0.001000

Vector Length: 2, 20
C file execution time: 0.001000
ASM file execution time: 0.001000

Vector Length: 2, 20
C file execution time: 0.003000
ASM file execution time: 0.000000

Vector Length: 2, 20
C file execution time: 0.003000
ASM file execution time: 0.001000

Vector Length: 2, 20
C file execution time: 0.003000
ASM file execution time: 0.001000

Vector Length: 2, 20
C file execution time: 0.002000
ASM file execution time: 0.001000

Vector Length: 2, 24
C file execution time: 0.039000
ASM file execution time: 0.017000

Vector Length: 2, 24
C file execution time: 0.037000
ASM file execution time: 0.016000

Vector Length: 2, 24
C file execution time: 0.036000
ASM file execution time: 0.017000

Vector Length: 2, 24
C file execution time: 0.038000
ASM file execution time: 0.018000

Vector Length: 2, 24
C file execution time: 0.035000
ASM file execution time: 0.017000

Vector Length: 2, 24
C file execution time: 0.038000
ASM file execution time: 0.017000

Vector Length: 2, 24
C file execution time: 0.034000
ASM file execution time: 0.018000

Vector Length: 2, 24
C file execution time: 0.036000
ASM file execution time: 0.017000

Vector Length: 2, 24
C file execution time: 0.044000
ASM file execution time: 0.017000

Vector Length: 2, 28
C file execution time: 0.803000
ASM file execution time: 0.565000

Vector Length: 2, 28
C file execution time: 0.567000
ASM file execution time: 0.270000

Vector Length: 2, 28
C file execution time: 0.556000
ASM file execution time: 0.262000

Vector Length: 2, 28
C file execution time: 0.559000
ASM file execution time: 0.269000

Vector Length: 2, 28
C file execution time: 0.580000
ASM file execution time: 0.261000

Vector Length: 2, 28
C file execution time: 0.551000
ASM file execution time: 0.262000

Vector Length: 2, 28
C file execution time: 0.547000
ASM file execution time: 0.264000

Vector Length: 2, 28
C file execution time: 0.585000
ASM file execution time: 0.268000

Vector Length: 2, 27
C file execution time: 0.274000
ASM file execution time: 0.135000

Vector Length: 2, 27
C file execution time: 0.269000
ASM file execution time: 0.130000

Vector Length: 2, 27
C file execution time: 0.279000
ASM file execution time: 0.130000

Vector Length: 2, 27
C file execution time: 0.289000
ASM file execution time: 0.132000

Vector Length: 2, 27
C file execution time: 0.269000
ASM file execution time: 0.131000

Vector Length: 2, 27
C file execution time: 0.291000
ASM file execution time: 0.149000

