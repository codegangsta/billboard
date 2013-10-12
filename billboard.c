#include <stdio.h>
#include "termbox/termbox.h"

static void draw() {
    tb_clear();
    tb_change_cell(0, 0, 'A', 0, 1);
    tb_present();
}

int main(int argc, char * argv[]) {
    int ret = tb_init();
    if(ret) {
        fprintf(stderr, "tb_init() failed with error code %d\n", ret);
        return 1;
    }

    draw();

    // event loop
    struct tb_event event;
    while(tb_poll_event(&event)) {
        switch(event.type) {
            case TB_EVENT_KEY:
                if(event.key == TB_KEY_ESC){
                    goto done;
                }
                break;
            case TB_EVENT_RESIZE:
                break;
        }
    }

done:
    tb_shutdown();
    return 0;
}
