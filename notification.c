/* BonOS Notifications 🔔 */
/* Brain OFF Mode */

#define VID ((char*)0xB8000)
#define WIDTH 80

void clear_notif() {
    int row = 0;
    int off = row * WIDTH * 2;

    for (int i = 0; i < WIDTH; i++) {
        VID[off + i*2] = ' ';
        VID[off + i*2+1] = 0x1E;
    }
}

void show_notif(const char* msg) {
    clear_notif();

    int off = 0 * WIDTH * 2;
    const char* bell = "🔔 ";

    int i = 0;
    for (; bell[i]; i++) {
        VID[off + i*2] = bell[i];
        VID[off + i*2+1] = 0x0F;
    }

    int j = 0;
    for (; msg[j]; j++) {
        VID[off + (i+j)*2] = msg[j];
        VID[off + (i+j)*2+1] = 0x0F;
    }
}

void notif_storage() {
    show_notif("Storage updated!");
}

void notif_upgrade() {
    show_notif("Upgrade purchased!");
}

void notif_battery() {
    show_notif("Battery low!");
}

void notif_gobocash() {
    show_notif("GoboCash +$1 added!");
}

void kmain() {
    // Draw your appbar first
    // draw_appbar();

    // Example notifications:
    notif_storage();
    // notif_upgrade();
    // notif_battery();
    // notif_gobocash();

    while (1) { }
}