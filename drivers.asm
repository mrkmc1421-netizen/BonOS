; BonOS ASM Driver Template
; Brain OFF Mode

BITS 32

; ============================
; I/O PORT READ
; ============================
io_read8:
    mov dx, [esp+4]
    in al, dx
    ret

io_read16:
    mov dx, [esp+4]
    in ax, dx
    ret

io_read32:
    mov dx, [esp+4]
    in eax, dx
    ret

; ============================
; I/O PORT WRITE
; ============================
io_write8:
    mov dx, [esp+4]
    mov al, [esp+8]
    out dx, al
    ret

io_write16:
    mov dx, [esp+4]
    mov ax, [esp+8]
    out dx, ax
    ret

io_write32:
    mov dx, [esp+4]
    mov eax, [esp+8]
    out dx, eax
    ret

; ============================
; BASIC DRIVER INIT
; ============================
driver_init:
    ; Example: ping device at port 0x60
    mov dx, 0x60
    in al, dx

    ; Store result somewhere
    mov [0xB8000], al
    mov byte [0xB8001], 0x0F

    ret

; ============================
; IRQ HANDLER TEMPLATE
; ============================
irq_handler:
    pusha

    ; Example: read from device port
    mov dx, 0x60
    in al, dx

    ; Print to screen
    mov edi, 0xB8000
    mov [edi], al
    mov byte [edi+1], 0x0E

    popa
    iretd