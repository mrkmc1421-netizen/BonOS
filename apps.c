/* BonOS App Bar + Storage, Upgrade, Battery, GoboCash */
/* Brain OFF 📴 */

#define VID ((char*)0xB8000)
#define WIDTH 80

int storage_open = 0;
int upgrade_open = 0;
int battery_open = 0;
int gobocash_open = 0;

void draw_appbar() {
    int row = 23;
    int offset = row * WIDTH * 2;

    for (int i = 0; i < WIDTH; i++) {
        VID[offset + i*2] = ' ';
        VID[offset + i*2+1] = 0x1F;
    }

    const char* a1 = "[📂 Storage]";
    const char* a2 = "[💸 Upgrade]";
    const char* a3 = "[🔋 Battery]";
    const char* a4 = "[🤑 GoboCash]";

    int x = 2;
    for (int i = 0; a1[i]; i++) { VID[offset + (x+i)*2] = a1[i]; VID[offset + (x+i)*2+1] = 0x1E; }
    x += 14;
    for (int i = 0; a2[i]; i++) { VID[offset + (x+i)*2] = a2[i]; VID[offset + (x+i)*2+1] = 0x1E; }
    x += 14;
    for (int i = 0; a3[i]; i++) { VID[offset + (x+i)*2] = a3[i]; VID[offset + (x+i)*2+1] = 0x1E; }
    x += 14;
    for (int i = 0; a4[i]; i++) { VID[offset + (x+i)*2] = a4[i]; VID[offset + (x+i)*2+1] = 0x1E; }
}

void clear_window() {
    for (int r = 5; r < 20; r++) {
        int off = r * WIDTH * 2;
        for (int c = 0; c < WIDTH; c++) {
            VID[off + c*2] = ' ';
            VID[off + c*2+1] = 0x07;
        }
    }
}

void show_storage() {
    clear_window();
    const char* msg = "Storage 📂: 2GB used / 8GB total";
    int off = 6 * WIDTH * 2;
    for (int i = 0; msg[i]; i++) {
        VID[off + i*2] = msg[i];
        VID[off + i*2+1] = 0x0F;
    }
}

void show_upgrade() {
    clear_window();
    const char* msg = "Upgrade Storage 💸: +8GB for $5";
    int off = 6 * WIDTH * 2;
    for (int i = 0; msg[i]; i++) {
        VID[off + i*2] = msg[i];
        VID[off + i*2+1] = 0x0F;
    }
}

void show_battery() {
    clear_window();
    const char* msg = "Battery 🔋: 87%";
    int off = 6 * WIDTH * 2;
    for (int i = 0; msg[i]; i++) {
        VID[off + i*2] = msg[i];
        VID[off + i*2+1] = 0x0F;
    }
}

void show_gobocash() {
    clear_window();
    const char* msg = "GoboCash 🤑: +$1.00 added!";
    int off = 6 * WIDTH * 2;
    for (int i = 0; msg[i]; i++) {
        VID[off + i*2] = msg[i];
        VID[off + i*2+1] = 0x0F;
    }
}

void handle_click(int x, int y) {
    if (y != 23) return;

    if (x >= 2 && x <= 14) show_storage();
    if (x >= 16 && x <= 28) show_upgrade();
    if (x >= 30 && x <= 42) show_battery();
    if (x >= 44 && x <= 58) show_gobocash();
}

void kmain() {
    draw_appbar();
    while (1) { }
}