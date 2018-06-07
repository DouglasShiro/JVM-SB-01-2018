#include <stdio.h>
#include <stdlib.h>
#include "reader.h"
#include "exibidor.h"

int main(int argc, char* argv[]) {
    
    ClassFile *fp_class_info;

    fp_class_info = classFileRead("double_aritmetica.class");
    
    classFileExib(fp_class_info);
    
    return 0;
}
