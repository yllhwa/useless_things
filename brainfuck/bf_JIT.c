#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CMDLEN 5
#define CODELEN 1000
#define DATALEN 1000

int get_cmd(char *cmd);
void deal_cmd(char *cmd);
void help();
void code();

/**
 * @name: get_cmd()
 * @func: 读取输入
 * @param: 存放指令的字符数组
 * @return: 是否读取成功
*/
int get_cmd(char *cmd)
{

    int i;
    for (i = 0; i < CMDLEN; i++)
    {
        if ((cmd[i] = getchar()) == '\n')
        {
            cmd[i] = '\0';
            return 1;
        }
    }
    return 0;
}

/**
 * @name: deal_cmd()
 * @func: 处理输入的指令
 * @param: 存放指令的字符数组
*/
void deal_cmd(char *cmd)
{
    if (strcmp(cmd, "help") == 0)
    {
        help();
    }
    else if (strcmp(cmd, "exit") == 0)
    {
        exit(0);
    }
    else if (strcmp(cmd, "code") == 0)
    {
        code();
    }
    else
    {
        printf("no command named \"%s\"!\n", cmd);
    }
}

/**
 * @name: help()
 * @func: 输出帮助信息
*/
void help()
{
    printf("use \"code\" to get in code mode\n");
    printf("use \"exit\" to exit\n");
}

/**
 * @name: code()
 * @func: 读取bf代码并解释
*/
void code()
{
    printf("You are now at code mode!\n");
    printf("Use ctrl+Z to go back\n");
    char current_cmd;
    char _code[CODELEN];
    int _data[CODELEN] = {0};
    int data_p = 0;
    while (1)
    {
        printf("@");
        if (!gets(_code))
        {
            break;
        }
        int code_p = 0;
        while (_code[code_p])
        {
            if (data_p >= DATALEN || data_p < 0)
            {
                printf("Access to illegal memory!\n");
                break;
            }
            if (_code[code_p] == '>')
            {
                data_p++;
            }
            else if (_code[code_p] == '<')
            {
                data_p--;
            }
            else if (_code[code_p] == '+')
            {
                _data[data_p]++;
            }
            else if (_code[code_p] == '-')
            {
                _data[data_p]--;
            }
            else if (_code[code_p] == '.')
            {
                putchar(_data[data_p]);
            }
            else if (_code[code_p] == ',')
            {
                _data[data_p] = getchar();
            }
            else if (_code[code_p] == '[')
            {
                int left_count = 0;
                int right_count = 0;
                if (_data[data_p] == 0)
                {
                    while (1)
                    {
                        code_p++;
                        if (_code[code_p] == '[')
                        {
                            left_count++;
                        }
                        else if (_code[code_p] == ']')
                        {
                            if (left_count == right_count)
                            {
                                break;
                            }
                            else
                            {
                                right_count++;
                            }
                        }
                    }
                }
            }
            else if (_code[code_p] == ']')
            {
                int left_count = 0;
                int right_count = 0;
                if (_data[data_p])
                {
                    while (1)
                    {
                        code_p--;
                        if (_code[code_p] == ']')
                        {
                            right_count++;
                        }
                        else if (_code[code_p] == '[')
                        {
                            if (left_count == right_count)
                            {
                                break;
                            }
                            else
                            {
                                left_count++;
                            }
                        }
                    }
                }
            }
            code_p++;
        }
        putchar('\n');
    }
}

int main()
{
    char cmd[CMDLEN];
    printf("Brainfuck interpreter 0.1.0\n");
    printf("Type \"help\" for more information.\n");
    while (1)
    {
        printf(">>>");
        if (get_cmd(cmd))
        {
            deal_cmd(cmd);
        }
        else
        {
            printf("command is to long\n");
            while (getchar() != '\n')
            {
                continue;
            }
        }
    }
    return 0;
}