#include <stdint.h>

#define NO_NAME "Не задано название"

struct frame {
	uint64_t rbp;
	uint64_t rbx;
	uint64_t r15;
	uint64_t r14;
	uint64_t r13;
	uint64_t r12;
	uint64_t r11;
	uint64_t r10;
	uint64_t r9;
	uint64_t r8;
	uint64_t rax;
	uint64_t rcx;
	uint64_t rdx;
	uint64_t rsi;
	uint64_t rdi;
	uint64_t int_number;
	uint64_t err;
	uint64_t rip;
	uint64_t cs;
	uint64_t rflags;
	uint64_t rsp;
	uint64_t ss;
} __attribute__((packed));

typedef void (*exception_handler_t)(void);
typedef void (*interrupt_handler_t)(void);

typedef struct {
	uint16_t base_low;
	uint16_t selector;

	uint8_t zero;
	uint8_t flags;

	uint16_t base_mid;
	uint32_t base_high;
	uint32_t pad;
} __attribute__((packed)) idt_entry_t;

struct idt_ptr {
	uint16_t limit;
	uint64_t base;
} __attribute__((packed));

typedef void (*int_entry_t)(void);
extern int_entry_t isr_stubs[];

static const char *exception_names[] = { "Деление на ноль",
	                                     "Отладка",
	                                     "NMI",
	                                     "Точка останова",
	                                     "Переполнение",
	                                     "Выход за границы",
	                                     "Недопустимая операция",
	                                     "Устройство недоступно",
	                                     "Двойное исключение",
	                                     NO_NAME,
	                                     "Недопустимый TSS",
	                                     "Сегмент не присутствует",
	                                     "Ошибка сегмента стека",
	                                     "Общая защитная ошибка",
	                                     "Ошибка страницы",
	                                     NO_NAME,
	                                     "x87 исключение",
	                                     "Проверка выравнивания",
	                                     "Ошибка машины",
	                                     "SIMD исключение",
	                                     "Ошибка виртуализации",
	                                     NO_NAME,
	                                     NO_NAME,
	                                     NO_NAME,
	                                     NO_NAME,
	                                     NO_NAME,
	                                     NO_NAME,
	                                     NO_NAME,
	                                     NO_NAME,
	                                     "Ошибка безопасности" };
extern struct regs *_isr0(struct regs *);
extern struct regs *_isr1(struct regs *);
extern struct regs *_isr2(struct regs *);
extern struct regs *_isr3(struct regs *);
extern struct regs *_isr4(struct regs *);
extern struct regs *_isr5(struct regs *);
extern struct regs *_isr6(struct regs *);
extern struct regs *_isr7(struct regs *);
extern struct regs *_isr8(struct regs *);
extern struct regs *_isr9(struct regs *);
extern struct regs *_isr10(struct regs *);
extern struct regs *_isr11(struct regs *);
extern struct regs *_isr12(struct regs *);
extern struct regs *_isr13(struct regs *);
extern struct regs *_isr14(struct regs *);
extern struct regs *_isr15(struct regs *);
extern struct regs *_isr16(struct regs *);
extern struct regs *_isr17(struct regs *);
extern struct regs *_isr18(struct regs *);
extern struct regs *_isr19(struct regs *);
extern struct regs *_isr20(struct regs *);
extern struct regs *_isr21(struct regs *);
extern struct regs *_isr22(struct regs *);
extern struct regs *_isr23(struct regs *);
extern struct regs *_isr24(struct regs *);
extern struct regs *_isr25(struct regs *);
extern struct regs *_isr26(struct regs *);
extern struct regs *_isr27(struct regs *);
extern struct regs *_isr28(struct regs *);
extern struct regs *_isr29(struct regs *);
extern struct regs *_isr30(struct regs *);
extern struct regs *_isr31(struct regs *);
extern struct regs *_irq0(struct regs *);
extern struct regs *_irq1(struct regs *);
extern struct regs *_irq2(struct regs *);
extern struct regs *_irq3(struct regs *);
extern struct regs *_irq4(struct regs *);
extern struct regs *_irq5(struct regs *);
extern struct regs *_irq6(struct regs *);
extern struct regs *_irq7(struct regs *);
extern struct regs *_irq8(struct regs *);
extern struct regs *_irq9(struct regs *);
extern struct regs *_irq10(struct regs *);
extern struct regs *_irq11(struct regs *);
extern struct regs *_irq12(struct regs *);
extern struct regs *_irq13(struct regs *);
extern struct regs *_irq14(struct regs *);
extern struct regs *_irq15(struct regs *);
extern struct regs *_isr123(struct regs *);