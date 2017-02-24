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
	{ 0x8e49f4de, "module_layout" },
	{ 0x33723412, "dma_pool_destroy" },
	{ 0x34e0218, "dma_pool_free" },
	{ 0x7824f24, "dma_pool_alloc" },
	{ 0x1dffd862, "dma_pool_create" },
	{ 0xd916ef76, "dma_ops" },
	{ 0xbb458f82, "x86_dma_fallback_dev" },
	{ 0xea147363, "printk" },
	{ 0xb4390f9a, "mcount" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "E69AD221BC4F7C6A942B7B5");
