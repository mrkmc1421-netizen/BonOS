/* BonOS Kernelware C - Brain Off Mode */

void kmain() {
    const char* msg = "BonOS Kernelware Activated";
    char* vid = (char*)0xB8000;

    for (int i = 0; msg[i] != 0; i++) {
        vid[i*2] = msg[i];
        vid[i*2+1] = 0x0F;
    }

    while (1) { }
}