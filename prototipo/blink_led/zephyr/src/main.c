#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

#define LED0_NODE DT_ALIAS(my_led0)

static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);

int main(void) {
    int ret;

    if (!gpio_is_ready_dt(&led)) {
        printk("GPIO is not ready");
        return 0;
    }

    ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_LOW);
    if (ret < 0) {
        printk("Error configuring GPIO");
        return 0;
    }

    while(1) {
        gpio_pin_set_dt(&led, 1);
        k_msleep(1000);
        gpio_pin_set_dt(&led, 0);
        k_msleep(1000);
    }

    return 0;
}