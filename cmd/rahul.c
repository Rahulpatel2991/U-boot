/*
 * Copyright 2000-2009
 * Wolfgang Denk, DENX Software Engineering, wd@denx.de.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <command.h>

#define OMAP_GPIO_DIR_OUT       0
#define OMAP_GPIO_DIR_IN        1
#define OMAP_GPIO_OE        0x134
#include "/home/jay/adeptchips/u-boot/arch/arc/include/asm/io.h"

//#define BASE  0x4804c000
struct gpio_bank {
        /* TODO(sjg@chromium.org): Can we use a struct here? */
        void *base;     /* address of registers in physical memory */
};

static int _get_gpio_direction(const struct gpio_bank *bank, int gpio)
{
        void *reg = bank->base;
        u32 v;

        reg += OMAP_GPIO_OE;

        v = __raw_readl(reg);

        if (v & (1 << gpio))
                return OMAP_GPIO_DIR_IN;
        else
                return OMAP_GPIO_DIR_OUT;
}

static int do_task(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	if(argc!=4)
	{
		printf("USAGE:- rahul gpio get/set value/direction");
		return 0;
	}

	if((argv[2][0]=='G' || argv[2][0]=='g') && (argv[3][0]== 'D' || argv[3][0]=='d'))
	{

		printf("direction =%d\n,",_get_gpio_direction((unsigned int *)0x4804c000,48));		
	}
	printf("WOW I am using commnad............................\n");
}


U_BOOT_CMD(
	rahul,	CONFIG_SYS_MAXARGS,	3,	do_task,
	"echo args to console",
	"[args..]\n"
	"    - echo args to console; \\c suppresses newline"
);
