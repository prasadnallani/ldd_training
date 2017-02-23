#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
 .name = KBUILD_MODNAME,
 .init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
 .exit = cleanup_module,
#endif
 .arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x1d963aaa, "module_layout" },
	{ 0x37a0cba, "kfree" },
	{ 0x7dff883, "class_destroy" },
	{ 0xf45c161b, "device_destroy" },
	{ 0x1c2cbbe7, "kmem_cache_alloc_trace" },
	{ 0x57a93b08, "kmalloc_caches" },
	{ 0xe023ab03, "device_create" },
	{ 0x6fc72d15, "__class_create" },
	{ 0xd1593722, "cdev_del" },
	{ 0x5f3f4ae3, "cdev_add" },
	{ 0x6230642e, "cdev_init" },
	{ 0x7485e15e, "unregister_chrdev_region" },
	{ 0xb8d2fa68, "cdev_alloc" },
	{ 0x29537c9e, "alloc_chrdev_region" },
	{ 0x2f287f0d, "copy_to_user" },
	{ 0xb65b26e0, "up" },
	{ 0xf9a482f9, "msleep" },
	{ 0x362ef408, "_copy_from_user" },
	{ 0xad185894, "down_interruptible" },
	{ 0x641f2b1d, "module_refcount" },
	{ 0xdd456354, "current_task" },
	{ 0x50eedeb8, "printk" },
	{ 0xb4390f9a, "mcount" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "B1D2FBC641796A5C9D2305D");
