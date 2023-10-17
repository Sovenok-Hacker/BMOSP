#include <arch.h>
#include <cpu.h>
#include <fb.h>
#include <limine.h>
#include <mem.h>
#include <mod.h>
#include <tool.h>
#include <version.h>

extern "C" void main( );

// Точка входа
extern "C" void _start( ) {
	asm volatile("cli");

	fb::init( );
	arch::init( );
	cpu::init( );
	mem::init( );
	fb::printf("\t\t\t\t *** Базовая Модульная Платформа Операционных Систем "
	           "версии %u.%u.%u ***\n",
	           VERSION_MAJOR, VERSION_MINOR, VERSION_BUILD);
	fb::printf("\t\t\t\t *** Дата сборки: %s %s ***\n", __DATE__, __TIME__);
	mod::init( );
	fb::printf("Пауза...\n");
	pause( );
	main( );
	for (;;) { asm volatile("hlt"); }
}