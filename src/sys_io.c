#include "errno.h"
#include <sys/stat.h>
#include "headfile.h"


ssize_t _write(int file,const void *ptr, size_t len)
{
	(void)file;
	const uint8_t *current = (const uint8_t*)ptr;

    //for (size_t i=0;i<len;i++)
        //UART1_putbuf(current[i]);
    Uart_Send(UART1,(uint8_t *)current,len);

	return len;
}

/**/
int _close(int fd)
{
    return -1;
}

int _fstat(int file, struct stat *st)
{
    return -1;
}

int _isatty(int file)
{
    return -1;
}

off_t _lseek(int file, off_t ptr, int dir)
{
    return -1;
}

ssize_t _read(int file, void *ptr, size_t len)
{
    return -1;
}







