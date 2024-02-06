; ==============================================================================
; ### mochila_pd.asm
; Minha implementação da solução do Problema da Mochila.
; By: anachan01h
; ==============================================================================

section .text
global mochila_pd

; mochila_pd(u64 n, u64 max_w, u64 *w, u64 *v, u64 *table) -> u64
mochila_pd:
    mov r9, rdx
    ;; rdi: n
    ;; rsi: max_w
    ;; r9: *w
    ;; rcx: *v
    ;; r8: *table
    mov r10, 0                      ; r10: j <- 0 (vai até max_w)
_loop1:
    mov qword [r8 + r10 * 8], 0     ; table[0,j] <- 0
    mov r11, 1                      ; r11: i <- 1 (vai até n)
_loop2:
    mov rax, r11                    ; rax <- i
    dec rax                         ; rax <- i - 1
    mov rdx, rsi                    ; rdx <- max_w
    inc rdx                         ; rdx <- max_w + 1
    mul rdx                         ; rax <- (i - 1) * (max_w + 1)
    add rax, r10                    ; rax <- (i - 1) * (max_w + 1) + j
    mov rax, [r8 + rax * 8]         ; rax <- table[i - 1, j]
    cmp r10, [r9 + r11 * 8 - 8]     ; se j < w[i - 1]
    jb _next

    push rax
    mov rax, r11                    ; rax <- i
    dec rax                         ; rax <- i - 1
    mov rdx, rsi                    ; rdx <- max_w
    inc rdx                         ; rdx <- max_w + 1
    mul rdx                         ; rax <- (i - 1) * (max_w + 1)
    add rax, r10                    ; rax <- (i - 1) * (max_w + 1) + j
    sub rax, [r9 + r11 * 8 - 8]     ; rax <- (i - 1) * (max_w + 1) + j - w[i - 1]
    mov rax, [r8 + rax * 8]         ; rax <- table[i - 1, j - w[i - 1]]
    add rax, [rcx + r11 * 8 - 8]    ; rax <- table[i - 1, j - w[i - 1]] + v[i - 1]
    pop rdx
    cmp rax, rdx                    ; se table[i - 1, j] < table[i - 1, j - w[i - 1]] + v[i - 1]
    cmovb rax, rdx

_next:
    push rax
    mov rax, r11                    ; rax <- i
    mov rdx, rsi                    ; rdx <- max_w
    inc rdx                         ; rdx <- max_w + 1
    mul rdx                         ; rax <- i * (max_w + 1)
    add rax, r10                    ; rax <- i * (max_w + 1) + j
    pop rdx
    mov [r8 + rax * 8], rdx         ; table[i, j] <- rdx

    inc r11                         ; incrementa i
    cmp r11, rdi                    ; se i <= n
    jbe _loop2

    inc r10                         ; incrementa j
    cmp r10, rsi                    ; se j <= max_w
    jbe _loop1

    mov rax, rdi                    ; rax <- n
    inc rax                         ; rax <- n + 1
    mov rdx, rsi                    ; rdx <- max_w
    inc rdx                         ; rdx <- max_w + 1
    mul rdx                         ; rax <- (n + 1) * (max_w + 1)
    dec rax                         ; rax <- (n + 1) * (max_w + 1) - 1
    mov rax, [r8 + rax * 8]         ; rax <- table[n + 1, max_w + 1]
    ret
