void jump_start(void *init, void *exit_func, void *entry)
{
	register long esp __asm__("esp") = (long) init;
	register long edx __asm__("edx") = (long) exit_func;

	__asm__ __volatile__(
		"jmp *%0\n"
		:
		: "r" (entry), "r" (esp), "r" (edx)
		:
	);
}

