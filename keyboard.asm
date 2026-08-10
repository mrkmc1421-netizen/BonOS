; BonOS Universal Keyboard Driver
; Brain OFF Mode

BITS 32

KBD_PORT equ 0x60
PIC_CMD  equ 0x20

kbd_irq:
    pusha

    ; Read scan code
    in al, KBD_PORT

    ; Print scan code to screen (debug)
    mov edi, 0xB8000
    mov [edi], al
    mov byte [edi+1], 0x0A

    ; Send End Of Interrupt to PIC
    mov al, 0x20
    out PIC_CMD, al

    popa
    iretd

kbd_init:
    ; Nothing fancy needed, PS/2 keyboards work instantly
    ret