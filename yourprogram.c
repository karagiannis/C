#include <unistd.h>

int main()
{
  if(getpid()%100 == 0 ) {
    char* ptr = 1;
    *ptr = 1;
  }
  return 0;
}
