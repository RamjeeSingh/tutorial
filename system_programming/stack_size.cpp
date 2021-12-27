void MyFunc( void );

void *pFnBottom = (void *)MyFunc;
void *pFnTop;
unsigned int uiStackUsage;

void MyFunc( void )
{
    __asm__ ( mov pFnTop, esp );
    uiStackUsage = (unsigned int)(pFnTop - pFnBottom);
}

int main() {


}
