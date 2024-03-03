; ==============================================================================
; ### mcds.asm
; Minha implementação da solução aproximada do problema Minimum Connected
; Dominating Set
; By: anachan01h
; ==============================================================================

section .text
global mcds

; mcds(u64 n, bool *graph, bool *covered, bool *cds) -> u64
mcds:
    mov r8, rdx
    ; rdi: n
    ; rsi: *graph
    ; r8: *covered
    ; rcx: *cds

    sub rsp, 16
    ; rsp: vertex
    ; rsp + 8: neighbors
    mov qword [rsp], 0
    mov qword [rsp + 8], 0

    ; Find a vertex with maximum neighbors
    xor r9, r9                  ; r9: v <- 0
mcds_loop01:
    xor r11, r11                ; r11: u <- 0
    xor r10, r10                ; r10: m <- 0
mcds_loop02:
    mov rax, r9                 ; rax <- v
    mul rdi                     ; rax <- v * n
    add rax, r11                ; rax <- v * n + u
    cmp byte [rsi + rax], 1     ; (v, u) not in graph?
    jne mcds_loop02_next
    inc r10                     ; m++
mcds_loop02_next:
    inc r11                     ; u++
    cmp r11, rdi                ; u < n?
    jb mcds_loop02
    cmp [rsp + 8], r10          ; neighbors >= m?
    jae mcds_loop01_next
    mov [rsp], r9               ; vertex <- v
    mov [rsp + 8], r10          ; neighbors <- m
mcds_loop01_next:
    inc r9                      ; v++
    cmp r9, rdi                 ; v < n?
    jb mcds_loop01

    mov r9, [rsp]               ; r9 <- vertex
    or byte [r8 + r9], 0x01     ; vertex in covered
mcds_loop1:
    mov qword [rsp], 0          ; vertex <- 0
    mov qword [rsp + 8], 0      ; vizinhos <- 0
    xor r9, r9                  ; r9: v <- 0
mcds_select:
    cmp byte [r8 + r9], 1       ; v not in covered?
    jne mcds_select_next
    cmp byte [rcx + r9], 1      ; v in cds?
    je mcds_select_next
    xor r11, r11                ; r11: u <- 0
    xor r10, r10                ; r10: m <- 0
mcds_vizinhos:
    cmp byte [r8 + r11], 1      ; u in covered?
    je mcds_vizinhos_next
    mov rax, r9                 ; rax <- v
    mul rdi                     ; rax <- v * n
    add rax, r11                ; rax <- v * n + u
    cmp byte [rsi + rax], 1     ; (v, u) not in graph?
    jne mcds_vizinhos_next
    inc r10                     ; m++
mcds_vizinhos_next:
    inc r11                     ; u++
    cmp r11, rdi                ; u < n?
    jb mcds_vizinhos
    cmp [rsp + 8], r10          ; neighbors >= m?
    jae mcds_select_next
    mov [rsp], r9               ; vertex <- v
    mov [rsp + 8], r10          ; neighbors <- m
mcds_select_next:
    inc r9                      ; v++
    cmp r9, rdi                 ; v < n?
    jb mcds_select

    mov r9, [rsp]               ; r9 <- vertex
    or byte [rcx + r9], 0x01    ; vertex in cds
    xor r11, r11                ; r11: u <- 0
mcds_loop2:
    cmp byte [r8 + r11], 1      ; u in covered?
    je mcds_loop2_next
    mov rax, r9                 ; rax <- vertex
    mul rdi                     ; rax <- vertex * n
    add rax, r11                ; rax <- vertex * n + u
    cmp byte [rsi + rax], 1     ; (vertex, u) not in graph?
    jne mcds_loop2_next
    or byte [r8 + r11], 0x01    ; u in covered
mcds_loop2_next:
    inc r11                     ; u++
    cmp r11, rdi                ; u < n?
    jb mcds_loop2

    xor r11, r11                ; r11: u <- 0
mcds_loop3:
    cmp byte [r8 + r11], 1      ; u not in covered?
    jne mcds_loop1
    inc r11                     ; u++
    cmp r11, rdi                ; u < n?
    jb mcds_loop3

    xor r11, r11                ; r11: u <- 0
    xor rax, rax                ; rax: m <- 0
mcds_loop4:
    cmp byte [rcx + r11], 1     ; u not in cds
    jne mcds_loop4_next
    inc rax                     ; m++
mcds_loop4_next:
    inc r11                     ; u++
    cmp r11, rdi                ; u < n?
    jb mcds_loop4

    add rsp, 16
    ret

_exit:
    mov rax, 0x3C
    mov rdi, [r8 + 1]
    syscall
