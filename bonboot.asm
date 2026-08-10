; ================================
; BonOS Bootloader (512 bytes)
; ================================

BITS 16
ORG 0x7C00

start:
    cli
    xor ax, ax
    mov ds, ax
    mov es, ax

    ; Print message
    mov si, msg
print_loop:
    lodsb
    or al, al
    jz done_print
    mov ah, 0x0E
    int 0x10
    jmp print_loop

done_print:

    ; Load kernel (sector 2 → memory 0x1000)
    mov bx, 0x1000
    mov ah, 0x02
    mov al, 1
    mov ch, 0
    mov cl, 2
    mov dh, 0
    mov dl, [BOOT_DRIVE]
    int 0x13

    ; Jump to kernel
    jmp 0x0000:0x1000

msg:
    db "BonOS Booting...", 0

BOOT_DRIVE:
    db 0

times 510-($-$$) db 0
dw 0xAA55