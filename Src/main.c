#include <stdint.h>

typedef struct
{
	volatile uint32_t MODER;	/* offset: 0*00 */
	volatile uint32_t OTYPER;	/* offset: 0*04 */
	volatile uint32_t OSPEEDR;	/* offset: 0*08 */
	volatile uint32_t PUPDR;	/* offset: 0*0C */
	volatile uint32_t IDR;		/* offset: 0*10 */
	volatile uint32_t ODR;		/* offset: 0*14 */
	volatile uint32_t BSSR;		/* offset: 0*18 */
	volatile uint32_t LCKR;		/* offset: 0*1C */
	volatile uint32_t AFRL;		/* offset: 0*20 */
	volatile uint32_t AFRH;		/* offset: 0*24 */
	volatile uint32_t BRR;		/* offset: 0*28 */
} GPIO_TypeDef;

typedef struct
{
	volatile uint32_t DUMMY[5];
	volatile uint32_t AHBENR; /* offset: 0x14*/
} RCC_TypeDef;

/* Base address definitions */
#define RCC_BASE	0x40021000
#define GPIOA_BASE	0x48000000

/* Peripheral pointer definitions */
#define RCC			((RCC_TypeDef*) RCC_BASE)
#define GPIOA 		((GPIO_TypeDef*)GPIOA_BASE)

/* Bit mask for enabling GPIOA (bit 0) */
#define GPIOEN		(1U << 17)

/* Bit mask for GPIOA pin 5 */
#define PIN5		(1U << 5)
#define LED_PIN PIN5

int main(void)
{
	/* Enable clock access to GPIOA */
	RCC->AHBENR |= GPIOEN;
	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &= ~(1U<<11);

	while(1)
	{
	 /* Set PA5(LED_PIN) high */
	 GPIOA->ODR ^= LED_PIN;

	 /* simple delay*/
	 for(int i=0; i<1000000;i++);

	}
}













