
#include <errno.h>
#include <sys/stat.h>
#include <sys/times.h>
#include <sys/unistd.h>
//#include <stm32f10x.h>

extern uint32_t __get_MSP ( void );

#define STDOUT_USART USART1
#define STDERR_USART USART1
#define STDIN_USART USART1


#ifdef __cplusplus
extern "C" {
#endif
// errno
#undef errno
extern int errno;

/*
 * Переменные среды - пустой список.
 */
char * __env[1] = { 0 };
char ** environ = __env;

int _write ( int file, char * ptr, int len );

// exit - экстренный выход. В качестве выхода - зацикливаемся.
void _exit ( int status ) {
  while ( 1 );
}

// close - закрытие файла - возвращаем ошибку
int _close ( int file ) {

  return -1;
}
/*
 * execve - передача управления новому процессу - процессов нет -> возвращаем ошибку.
 */
int _execve ( char * name, char ** argv, char ** env ) {
  errno = ENOMEM;
  return -1;
}

/*
 * fork = создание нового процесса
 */
int _fork() {
  errno = EAGAIN;
  return -1;
}

/*
 * fstat - состояние открытого файла
 */
int _fstat ( int file, struct stat * st ) {
  st->st_mode = S_IFCHR;
  return 0;
}

/*
 * getpid - получить ID текущего процесса
 */

int _getpid() {
  return 1;
}

/*
 * isatty - является ли файл терминалом.
 */
int _isatty ( int file ) {
  switch ( file ) {
    case STDOUT_FILENO:
    case STDERR_FILENO:
    case STDIN_FILENO:
      return 1;

    default:
      //errno = ENOTTY;
      errno = EBADF;
      return 0;
  }
}

/*
 * kill - послать сигнал процессу
 */
int _kill ( int pid, int sig ) {
  errno = EINVAL;
  return ( -1 );
}

/*
 * link - устанвить новое имя для существующего файла.
 */

int _link ( char * old, char * new ) {
  errno = EMLINK;
  return -1;
}

/*
 * lseek - установить позицию в файле
 */
int _lseek ( int file, int ptr, int dir ) {
  return 0;
}

/*
 * sbrk - увеличить размер области данных, использутся для malloc
 */
caddr_t _sbrk ( int incr ) {
  extern char _Heap_Begin;
  extern char _Heap_Limit;

  static char * current_heap_end;
  char * current_block_address;

  if ( current_heap_end == 0 ) {
    current_heap_end = &_Heap_Begin;
  }

  current_block_address = current_heap_end;
  incr = ( incr + 3 ) & ( ~3 );

  if ( current_heap_end + incr > &_Heap_Limit ) {
#if 0
    extern void abort ( void );
    _write ( 1, "_sbrk: Heap and stack collision\n", 32 );
    abort();
#else
    errno = ENOMEM;
    return ( caddr_t ) - 1;
#endif
  }

  current_heap_end += incr;
  return ( caddr_t ) current_block_address;

}

/*
 * read - чтение из файла, у нас пока для чтения есть только stdin
 */

int _read ( int file, char * ptr, int len ) {
  int n;
  int num = 0;

  switch ( file ) {
//     case STDIN_FILENO:
//       for (n = 0; n < len; n++)
//       {
//         while (USART_GetFlagStatus(STDIN_USART, USART_FLAG_RXNE) == RESET);
//         char c = (char) (USART_ReceiveData(STDIN_USART) & (uint16_t) 0x01FF);
//         *ptr++ = c;
//         num++;
//       }
//               break;
    default:
      errno = EBADF;
      return -1;
  }

  return num;
}

/*
 * stat - состояние открытого файла.
 */

int _stat ( const char * filepath, struct stat * st ) {
  st->st_mode = S_IFCHR;
  return 0;
}

/*
 * times - временная информация о процессе (сколько тиков: системных, процессорных и т.д.)
 */

clock_t _times ( struct tms * buf ) {
  return -1;
}

/*
 * unlink - удалить имя файла.
 */
int _unlink ( char * name ) {
  errno = ENOENT;
  return -1;
}

/*
 * wait - ожидания дочерних процессов
 */
int _wait ( int * status ) {
  errno = ECHILD;
  return -1;
}

/*
 * write - запись в файл - у нас есть только stderr/stdout
 */
int _write ( int file, char * ptr, int len ) {
  int n;

  switch ( file ) {
//     case STDOUT_FILENO: /*stdout*/
//       for (n = 0; n < len; n++)
//       {
//         while (USART_GetFlagStatus(STDOUT_USART, USART_FLAG_TC) == RESET);
//         USART_SendData(STDOUT_USART, (uint8_t) * ptr++);
//       }
//               break;
//     case STDERR_FILENO: /* stderr */
//       for (n = 0; n < len; n++)
//       {
//         while (USART_GetFlagStatus(STDERR_USART, USART_FLAG_TC) == RESET);
//         USART_SendData(STDERR_USART, (uint8_t) * ptr++);
//       }
//               break;
    default:
      errno = EBADF;
      return -1;
  }

  return len;
}




#ifdef __cplusplus
}
#endif
