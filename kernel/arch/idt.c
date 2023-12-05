/**
 * idt.c
 * Инициализация обработчика прерываний
 *
 * Настройка обработчика прерываний и системных исключений
 *
 */

#include "idt.h"
#include <arch.h>
#include <fb.h>
#include <stdbool.h>
#include <stdint.h>
#include <tool.h>

static struct idt_ptr idt_ptr;
static idt_entry_t idt[256];

void exception_handler(struct frame state) {
	asm volatile("cli");
	LOG("\nПОЛУЧЕНО ИСКЛЮЧЕНИЕ: %s\n", exception_names[state.int_number]);

	uintptr_t rsp = state.rsp;

	const uintptr_t stack_bottom = rsp & ~((uintptr_t)4096 - 1);
	const uintptr_t stack_top = stack_bottom + 4096;

	LOG("  RAX=%x  RBX=%x\n"
	    "  RCX=%x  RDX=%x\n"
	    "  RSI=%x  RDI=%x\n"
	    "  RBP=%x  RSP=%x\n"
	    "  R08=%x  R09=%x\n"
	    "  R10=%x  R11=%x\n"
	    "  R12=%x  R13=%x\n"
	    "  R14=%x  R15=%x\n"
	    "  RIP=%x  RFLAGS=%x\n"
	    "  CS=%x   SS=%x\n"
	    "  ERR=%x  INT=%u",
	    state.rax, state.rbx, state.rcx, state.rdx, state.rsi, state.rdi,
	    state.rbp, state.rsp, state.r8, state.r9, state.r10, state.r11,
	    state.r12, state.r13, state.r14, state.r15, state.rip, state.rflags,
	    state.cs, state.ss, state.err, state.int_number);
	LOG("stack_top = %x\n", stack_top);

	asm volatile("hlt");
}

void idt_set_gate(uint8_t num, interrupt_handler_t handler, uint16_t selector,
                  uint8_t flags) {
	uintptr_t base = (uintptr_t)handler;
	idt[num].base_low = (base & 0xFFFF);
	idt[num].base_mid = (base >> 16) & 0xFFFF;
	idt[num].base_high = (base >> 32) & 0xFFFFFFFF;
	idt[num].selector = selector;
	idt[num].zero = 0;
	idt[num].pad = 0;
	idt[num].flags = flags | 0; // 0x60 для режима пользователя (RING3)
}

static void idt_load( ) {
	asm volatile("lidt %0" : : "m"(idt_ptr));
}

void idt_set_int(uint8_t vector, void *int_handler, char *name) {
	idt_set_gate(&idt[vector], 0x08, (uintptr_t)int_handler, 0x8E);
	idt_load( );
}

void idt_init( ) {
	asm volatile("cli");
	asm volatile("lidt %0" : : "m"(idt_ptr));
	LOG("IDT инициализирован 0x%x\n", 0x08);
}