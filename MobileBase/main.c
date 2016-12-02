#include "stm32f4xx.h"
#include <stdio.h>

USART_InitTypeDef USART_InitStructure;
GPIO_InitTypeDef GPIO_InitStructure;

void USART_Configuration(unsigned int BaudRate);
void SendUSART(USART_TypeDef* USARTx,uint16_t ch);
int GetUSART(USART_TypeDef* USARTx);
static void Delay(__IO uint32_t nTime);  

static __IO uint32_t TimingDelay;
/* Private function prototypes -----------------------------------------------*/
#ifdef __GNUC__
  /* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
     set to 'Yes') calls __io_putchar() */
  #define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
  #define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
  #define GETCHAR_PROTOTYPE int fgetc(FILE *f)
#endif /* __GNUC__ */

void Delay(__IO uint32_t nTime){ 
  TimingDelay = nTime;
  while(TimingDelay != 0);
}

void TimingDelay_Decrement(void){
  if (TimingDelay != 0){ 
    TimingDelay--;
  }
}

int main(void){  
	SysTick_Config(SystemCoreClock / 1000);

  USART_Configuration(115200);	
  printf(" Test hello world\r");
  while(1){
		printf(" abc\r");
		Delay(2000);
  }
}

void USART_Configuration(unsigned int BaudRate){
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE); 
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
  
  /* Configure USART Tx as alternate function  */
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  /* Configure USART Rx as alternate function  */
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
  
  USART_InitStructure.USART_BaudRate = BaudRate;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
  USART_Init(USART1, &USART_InitStructure);
  
  GPIO_PinAFConfig(GPIOB,GPIO_PinSource6,GPIO_AF_USART1); 
  GPIO_PinAFConfig(GPIOB,GPIO_PinSource7,GPIO_AF_USART1); 
  
  USART_Cmd(USART1, ENABLE);  
}

void SendUSART(USART_TypeDef* USARTx,uint16_t ch){
  USART_SendData(USARTx, (uint8_t) ch);
  /* Loop until the end of transmission */
  while (USART_GetFlagStatus(USARTx, USART_IT_TXE) == RESET)
  {}
}

int GetUSART(USART_TypeDef* USARTx){
  while (USART_GetFlagStatus(USARTx, USART_IT_RXNE) == RESET)
  {}
  return USART_ReceiveData(USARTx);
}

/**
  * @brief  Retargets the C library printf function to the USART.
  * @param  None
  * @retval None
  */
GETCHAR_PROTOTYPE{
  return GetUSART(USART1);
}

PUTCHAR_PROTOTYPE{
  /* Place your implementation of fputc here */
  /* e.g. write a character to the USART */
  USART_SendData(USART1, (uint8_t) ch);

  /* Loop until the end of transmission */
  while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET)
  {}

  return ch;
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif
