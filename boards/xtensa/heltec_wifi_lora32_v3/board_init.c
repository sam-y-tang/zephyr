/*
 * Copyright (c) 2021 Instituto de Pesquisas Eldorado (eldorado.org.br)
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>

#define VEXT_PIN  DT_GPIO_PIN(DT_NODELABEL(vext), gpios)
//#define OLED_RST  DT_GPIO_PIN(DT_NODELABEL(oledrst), gpios)

//#define LORA_NSS  DT_GPIO_PIN(DT_NODELABEL(loranss), gpios)
//#define LORA_RESET  DT_GPIO_PIN(DT_NODELABEL(lorareset), gpios)

static int board_heltec_wifi_lora32_v3_init(const struct device *dev)
{
	ARG_UNUSED(dev);
	const struct device *gpio;

	gpio = DEVICE_DT_GET(DT_NODELABEL(gpio0));
	if (!device_is_ready(gpio)) {
		return -ENODEV;
	}

	/* turns external VCC on  */
	gpio_pin_configure(gpio, VEXT_PIN, GPIO_OUTPUT);
	gpio_pin_set_raw(gpio, VEXT_PIN, 0);
	
	
	//gpio_pin_configure(gpio, OLED_RST, GPIO_OUTPUT);
	//gpio_pin_set_raw(gpio, OLED_RST, 1);	
		

	return 0;
}

SYS_INIT(board_heltec_wifi_lora32_v3_init, PRE_KERNEL_2, CONFIG_GPIO_INIT_PRIORITY);
