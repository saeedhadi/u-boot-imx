/*
 * Copyright (C) 2010-2011 Freescale Semiconductor, Inc.
 *
 * Configuration settings for the Boundary Devices Nitrogen6X
 * and Freescale i.MX6Q Sabre Lite boards.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#define CONFIG_MX6
#define CONFIG_DISPLAY_CPUINFO
#define CONFIG_DISPLAY_BOARDINFO

#define CONFIG_MACH_TYPE	4843

#include <asm/arch/imx-regs.h>
#include <asm/imx-common/gpio.h>
#include <asm/sizes.h>

#define CONFIG_CMDLINE_TAG
#define CONFIG_SETUP_MEMORY_TAGS
#define CONFIG_INITRD_TAG
#define CONFIG_REVISION_TAG

/* Size of malloc() pool */
#define CONFIG_SYS_MALLOC_LEN		(10 * SZ_1M)

#define CONFIG_BOARD_EARLY_INIT_F
#define CONFIG_MXC_GPIO

#define CONFIG_CMD_FUSE
#define CONFIG_MXC_OCOTP

#define CONFIG_MXC_UART
#define CONFIG_MXC_UART_BASE	       UART1_BASE

#define CONFIG_CMD_SF
#define CONFIG_SPI_FLASH
#define CONFIG_SPI_FLASH_STMICRO
#define CONFIG_MXC_SPI

/* I2C Configs */
#define CONFIG_CMD_I2C
#define CONFIG_I2C_MULTI_BUS
#define CONFIG_I2C_MXC
#define CONFIG_SYS_I2C_SPEED		100000

#define CONFIG_CMD_BBDETECT
#define CONFIG_BB_S0		IMX_GPIO_NR(1, 2)
#define CONFIG_BB_S1		IMX_GPIO_NR(2, 24)
#define CONFIG_BB_S2		IMX_GPIO_NR(2, 26)
#define CONFIG_BB_IN		IMX_GPIO_NR(2, 25)
#define CONFIG_BB_USDLY		1000

/* OCOTP Configs */
#define CONFIG_CMD_IMXOTP
#define CONFIG_IMX_OTP
#define IMX_OTP_BASE				OCOTP_BASE_ADDR
#define IMX_OTP_ADDR_MAX			0x7F
#define IMX_OTP_DATA_ERROR_VAL		0xBADABADA
#define IMX_OTPWRITE_ENABLED
#define CONFIG_RANDOM_MACADDR

/* MMC Configs */
#define CONFIG_FSL_ESDHC
#define CONFIG_FSL_USDHC
#define CONFIG_SYS_FSL_ESDHC_ADDR      0
#define CONFIG_SYS_FSL_USDHC_NUM       2

#define CONFIG_MMC
#define CONFIG_CMD_MMC
#define CONFIG_GENERIC_MMC
#define CONFIG_BOUNCE_BUFFER
#define CONFIG_CMD_EXT2
#define CONFIG_CMD_EXT4
#define CONFIG_CMD_FS_GENERIC
#define CONFIG_CMD_GPIO
#define CONFIG_CMD_FAT
#define CONFIG_DOS_PARTITION


#define CONFIG_BOARD_SPECIFIC_LED
#define CONFIG_STATUS_LED
#define CONFIG_CMD_LED

#define CONFIG_RED_LED                  IMX_GPIO_NR(1, 2)
#define CONFIG_GREEN_LED                IMX_GPIO_NR(2, 24)
#define STATUS_LED_RED                  0
#define STATUS_LED_GREEN                1

#define STATUS_LED_BIT                  STATUS_LED_RED
#define STATUS_LED_STATE                STATUS_LED_ON
#define STATUS_LED_PERIOD               (CONFIG_SYS_HZ / 2)

#define STATUS_LED_BIT1                 STATUS_LED_GREEN
#define STATUS_LED_STATE1               STATUS_LED_ON
#define STATUS_LED_PERIOD1              (CONFIG_SYS_HZ / 2)

#ifdef CONFIG_MX6Q
#define CONFIG_CMD_SATA
#endif

#ifdef CONFIG_CMD_SATA
#define CONFIG_DWC_AHSATA
#define CONFIG_SYS_SATA_MAX_DEVICE	1
#define CONFIG_DWC_AHSATA_PORT_ID	0
#define CONFIG_DWC_AHSATA_BASE_ADDR	SATA_ARB_BASE_ADDR
#define CONFIG_LBA48
#define CONFIG_LIBATA
#endif

#define CONFIG_CMD_PING
#define CONFIG_CMD_DHCP
#define CONFIG_CMD_MII
#define CONFIG_CMD_NET
#define CONFIG_FEC_MXC
#define CONFIG_NET_RETRY_COUNT     20
#define CONFIG_MII
#define IMX_FEC_BASE			ENET_BASE_ADDR
#define CONFIG_FEC_XCV_TYPE		RGMII
#define CONFIG_ETHPRIME			"FEC"
#define CONFIG_FEC_MXC_PHYADDR		7
#define CONFIG_PHYLIB
#define CONFIG_PHY_MICREL
#define CONFIG_PHY_MICREL_KSZ9021

/* USB Configs */ 
#define CONFIG_CMD_USB
#define CONFIG_CMD_FAT
#define CONFIG_USB_EHCI
#define CONFIG_USB_EHCI_MX6
#define CONFIG_USB_STORAGE
#define CONFIG_USB_HOST_ETHER
#define CONFIG_USB_ETHER_ASIX
#define CONFIG_USB_ETHER_SMSC95XX
#define CONFIG_MXC_USB_PORT	1
#define CONFIG_MXC_USB_PORTSC	(PORT_PTS_UTMI | PORT_PTS_PTW)
#define CONFIG_MXC_USB_FLAGS	0 

/* Miscellaneous commands */
#define CONFIG_CMD_BMODE
#define CONFIG_CMD_SETEXPR

/* allow to overwrite serial and ethaddr */
#define CONFIG_ENV_OVERWRITE
#define CONFIG_CONS_INDEX	       1
#define CONFIG_BAUDRATE			       115200

/* Command definition */
#include <config_cmd_default.h>

#undef CONFIG_CMD_IMLS

#define CONFIG_BOOTDELAY	       1
#define CONFIG_PREBOOT                 ""
#define CONFIG_LOADADDR			       0x12000000
#define CONFIG_SYS_TEXT_BASE	       0x17800000
#define CONFIG_MISC_INIT_R

#ifdef CONFIG_CMD_SATA
#define CONFIG_DRIVE_SATA "sata "
#else
#define CONFIG_DRIVE_SATA
#endif

#ifdef CONFIG_CMD_MMC
#define CONFIG_DRIVE_MMC "mmc "
#else
#define CONFIG_DRIVE_MMC
#endif

#define CONFIG_DRIVE_TYPES CONFIG_DRIVE_SATA CONFIG_DRIVE_MMC

#define CONFIG_NFS_TIMEOUT 10000UL

#define CONFIG_EXTRA_ENV_SETTINGS \
	"uimage=/boot/uImage\0" \
	"ip_dyn=yes\0" \
	"initrd_high=0xffffffff\0" \
	"fdtaddr=0x18000000\0" \
	"fdt_high=0xffffffff\0" \
	"sdboot=echo Booting from the SD card ...; " \
		"bbdetect; " \
		"if load mmc 0:1 ${fdtaddr} /boot/ts4900-${baseboard}.dtb; " \
			"then echo $baseboard detected; " \
		"else " \
			"echo Booting default device tree; " \
			"load mmc 0:1 ${fdtaddr} /boot/ts4900-default.dtb; " \
		"fi; " \
		"load mmc 0:1 ${loadaddr} ${uimage}; " \
		"setenv bootargs 'console=ttymxc0,115200 debug root=/dev/mmcblk0p1 " \
			" rootwait rw init=/sbin/init'; " \
		"bootm ${loadaddr} - ${fdtaddr}; \0" \
	"emmcboot=echo Booting from the eMMC ...; " \
		"bbdetect; " \
		"if load mmc 1:1 ${fdtaddr} /boot/ts4900-${baseboard}.dtb; " \
			"then echo $baseboard detected; " \
		"else " \
			"echo Booting default device tree; " \
			"load mmc 1:1 ${fdtaddr} /boot/ts4900-default.dtb; " \
		"fi; " \
		"load mmc 1:1 ${loadaddr} ${uimage}; " \
		"setenv bootargs 'console=ttymxc0,115200 debug root=/dev/mmcblk0p1 " \
			" rootwait rw init=/sbin/init'; " \
		"bootm ${loadaddr} - ${fdtaddr}; \0" \
	"usbprod=usb start; " \
		"if usb storage; " \
			"then echo Checking USB storage for updates; " \
			"if load usb 0:1 ${loadaddr} /u-boot.imx; " \
				"then echo updating u-boot. ; " \
				"sf probe; " \
				"sf erase 0 0x50000; " \
				"sf write ${loadaddr} 0x400 $filesize; " \
			"fi; " \
			"if load usb 0:1 ${loadaddr} /tsinit; " \
				"then source ${loadaddr}; " \
			"fi; " \
		"fi; \0" \
	"nfsboot=echo Booting from NFS ...; " \
		"setenv serverip 192.168.0.11 ; " \
		"setenv autoload no ; " \
		"setenv nfsroot /u/x/ts4900/rootfs/ ;" \
		"dhcp ; " \
		"bbdetect; " \
		"nfs ${loadaddr} ${serverip}:${nfsroot}/boot/uImage; " \
		"if nfs ${fdtaddr} ${serverip}:${nfsroot}/boot/ts4900-${baseboard}.dtb; " \
		"then echo $baseboard detected; " \
		"else " \
			"echo Booting default device tree; " \
			"load nfs ${fdtaddr} ${serverip}:${nfsroot}/boot/ts4900-default.dtb; " \
		"fi; " \
		"setenv bootargs 'console=ttymxc0,115200 debug root=/dev/nfs " \
			"ip=dhcp nfsroot=${serverip}:${nfsroot} rootwait rw init=/sbin/init'; " \
		"bootm ${loadaddr} - ${fdtaddr}; \0" \
	"prod=echo Starting Production ...; " \
		"setenv serverip 192.168.0.11; " \
		"setenv autoload no; " \
		"dhcp; " \
		"nfs 0x12000000 192.168.0.11:/u/x/ts4900/ts4900-production.uboot; " \
		"source 0x12000000;\0"

#define CONFIG_BOOTCOMMAND \
	"run usbprod; " \
	"if test ${jpsdboot} = 'on' ; " \
		"then run sdboot; " \
		"else run emmcboot; " \
	"fi;"

/* Miscellaneous configurable options */
#define CONFIG_SYS_LONGHELP
#define CONFIG_SYS_HUSH_PARSER
#define CONFIG_SYS_PROMPT	       "U-Boot > "
#define CONFIG_AUTO_COMPLETE
#define CONFIG_SYS_CBSIZE	       1024
#define CONFIG_HW_WATCHDOG
#define CONFIG_IMX_WATCHDOG

/* Print Buffer Size */
#define CONFIG_SYS_PBSIZE (CONFIG_SYS_CBSIZE + sizeof(CONFIG_SYS_PROMPT) + 16)
#define CONFIG_SYS_MAXARGS	       16
#define CONFIG_SYS_BARGSIZE CONFIG_SYS_CBSIZE

#define CONFIG_SYS_MEMTEST_START       0x10000000
#define CONFIG_SYS_MEMTEST_END	       0x10010000
#define CONFIG_SYS_MEMTEST_SCRATCH     0x10800000
#define CONFIG_CMD_MEMTEST

#define CONFIG_SYS_LOAD_ADDR	       CONFIG_LOADADDR
#define CONFIG_SYS_HZ		           1000

#define CONFIG_CMDLINE_EDITING

/* Physical Memory Map */
#define CONFIG_NR_DRAM_BANKS	       1
#define PHYS_SDRAM		       MMDC0_ARB_BASE_ADDR

#define CONFIG_SYS_SDRAM_BASE	       PHYS_SDRAM
#define CONFIG_SYS_INIT_RAM_ADDR       IRAM_BASE_ADDR
#define CONFIG_SYS_INIT_RAM_SIZE       IRAM_SIZE

#define CONFIG_SYS_INIT_SP_OFFSET \
	(CONFIG_SYS_INIT_RAM_SIZE - GENERATED_GBL_DATA_SIZE)
#define CONFIG_SYS_INIT_SP_ADDR \
	(CONFIG_SYS_INIT_RAM_ADDR + CONFIG_SYS_INIT_SP_OFFSET)

/* FLASH and environment organization */
#define CONFIG_SYS_NO_FLASH

/* 
 * 8MB SPI Flash
 * 0-0x3ff 				Padding				
 * 0x400-0x9FFFF		U-Boot 				Requires ~300KB in current build
 * 0x100000-0x101FFF	U-Boot environment  8KB, can be bigger, but has to be loaded every boot
 * 0x102000-0x1FFFFF	Reserved
 * 0x200000-0x2FFFFF	FDT
 * 0x300000-0x7FFFFF	Available
 */

#define CONFIG_ENV_SIZE			(8 * 1024)
#define CONFIG_ENV_IS_IN_SPI_FLASH
#define CONFIG_ENV_OFFSET		0x100000
#define CONFIG_ENV_SECT_SIZE	(4 * 1024)
#define CONFIG_SF_DEFAULT_BUS  0
#define CONFIG_SF_DEFAULT_CS   (0|(IMX_GPIO_NR(3, 19)<<8))
#define CONFIG_SF_DEFAULT_SPEED 15000000
#define CONFIG_SF_DEFAULT_MODE (SPI_MODE_0)
#define CONFIG_ENV_SPI_BUS		CONFIG_SF_DEFAULT_BUS
#define CONFIG_ENV_SPI_CS		CONFIG_SF_DEFAULT_CS
#define CONFIG_ENV_SPI_MODE		CONFIG_SF_DEFAULT_MODE
#define CONFIG_ENV_SPI_MAX_HZ	CONFIG_SF_DEFAULT_SPEED

#define CONFIG_OF_LIBFDT
#define CONFIG_CMD_BOOTZ

#ifndef CONFIG_SYS_DCACHE_OFF
#define CONFIG_CMD_CACHE
#endif

#define CONFIG_CMD_TIME
#define CONFIG_SYS_ALT_MEMTEST

#define CONFIG_CMD_BOOTZ
#define CONFIG_SUPPORT_RAW_INITRD
#define CONFIG_CMD_FS_GENERIC

#endif	       /* __CONFIG_H */