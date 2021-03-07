/*
 * Copyright (C) 2018 Koen Zandberg <koen@bergzand.net>
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

#include "log.h"
#include "xtimer.h"
#include "lvgl.h"
#include "controller.h"
#include "hal.h"
#include "bleman.h"
#include "storage.h"

#include "shell.h"
#include "msg.h"

#define MAIN_QUEUE_SIZE     (8)
static msg_t _main_msg_queue[MAIN_QUEUE_SIZE];

int lvgl_thread_create(void);

int main(void)
{
    storage_init();
    msg_init_queue(_main_msg_queue, MAIN_QUEUE_SIZE);
    LOG_DEBUG("Starting PineTime application TETS");
    lv_init();

    hal_init();
    lvgl_thread_create();
    bleman_thread_create();

    controller_thread_create();
    /* start shell */
    puts("All up, running the shell now");
    char line_buf[SHELL_DEFAULT_BUFSIZE];
    shell_run(NULL, line_buf, SHELL_DEFAULT_BUFSIZE);

    return 0;
}
