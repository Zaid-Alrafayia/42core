#include "ft_printf.h"

int	main(void)
{
	ft_printf("printf  : char:%c \nstring:%s \nptr:%p \ndec:%d \nint:%i\nunsigned:%u \nhex_lower:%x \nhex_upper:%X \npercent: %%\n", 'a', "hello my name is zaid", (void *)0xDEADBEEF,-12345, 12345, 4294967295u, 305441741u, /* 0x1234ABCD */ 305441741u);
	return (0);
}
