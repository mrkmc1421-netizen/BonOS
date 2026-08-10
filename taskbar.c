/* BonOS Minimal Taskbar + Chatbot Button (Not simplified) */

#define VID ((char*)0xB8000)
#define WIDTH 80

int chatbot_open = 0;

void draw_taskbar() {
    int row = 24; // bottom row
    int offset = row * WIDTH * 2;

    for (int i = 0; i < WIDTH; i++) {
        VID[offset + i*2] = ' ';
        VID[offset + i*2 + 1] = 0x1F; // blue background
    }

    // Draw "Chatbot" button
    const char* btn = "[ Chatbot ]";
    for (int i = 0; btn[i] != 0; i++) {
        VID[offset + (2 + i)*2] = btn[i];
        VID[offset + (2 + i)*2 + 1] = 0x1E;
    }
}

void draw_chatbot_window() {
    if (!chatbot_open) return;

    const char* msg = "Chatbot: Hello Kenny!";
    int offset = 20 * WIDTH * 2;

    for (int i = 0; msg[i] != 0; i++) {
        VID[offset + i*2] = msg[i];
        VID[offset + i*2 + 1] = 0x0F;
    }
}

void handle_click(int x, int y) {
    // If click is on the Chatbot button area
    if (y == 24 && x >= 2 && x <= 12) {
        chatbot_open = !chatbot_open;
        draw_chatbot_window();
    }
}

void kmain() {
    draw_taskbar();
    while (1) { }
}