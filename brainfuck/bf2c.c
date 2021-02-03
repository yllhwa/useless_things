#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fp;
    fp = fopen("output.c", "w");
    //头
    fputs("#include <stdio.h>\n", fp);
    fputs("#include <stdlib.h>\n", fp);
    fputs("int main()\n{\n", fp);
    //数据空间和数据指针
    fputs("int data[1000]={0};\n", fp);
    fputs("int data_p=0;\n", fp);

    printf("please input the code:\n");
    char cmd;
    while ((cmd = getchar()) != '\n')
    {
        if (cmd == '>')
        {
            fputs("data_p++;\n", fp);
        }
        else if (cmd == '<')
        {
            fputs("data_p--;\n", fp);
        }
        else if (cmd == '+')
        {
            fputs("data[data_p]++;\n", fp);
        }
        else if (cmd == '-')
        {
            fputs("data[data_p]--;\n", fp);
        }
        else if (cmd == '.')
        {
            fputs("putchar(data[data_p]);\n", fp);
        }
        else if (cmd == ',')
        {
            fputs("data[data_p]=getchar();\n", fp);
        }
        else if (cmd == '[')
        {
            fputs("while(data[data_p])\n{\n", fp);
        }
        else if (cmd == ']')
        {
            fputs("}\n", fp);
        }
    }
    fputs("system(\"pause\");", fp);
    fputs("return 0;\n}\n", fp);
    fclose(fp);
    system("gcc output.c -o output.exe");
    return 0;
}