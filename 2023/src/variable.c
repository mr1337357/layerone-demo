#include "basic_functions.h"

variable variables[50];

void variable_init()
{
    int i;
    for(i=0;i<50;i++)
    {
        variables[i].name[0] = 0;
    }
}

void variable_create(__eds__ uint8_t *name,int32_t value)
{
    int i;
    int j;
    for(i=0;i<50;i++)
    {
        if(variables[i].name[0] == 0)
        {
            break;
        }
        for(j=0;j<10;j++)
        {
            if(name[j] == 0 || name[j] == ' ')
            {
                return;
            }
            if(variables[i].name[j] != name[j])
            {
                break;
            }
        }
    }
    for(j=0;j<10;j++)
    {
        if(name[j] == 0 || name[j] == ' ')
        {
            variables[i].name[j] = 0;
            break;
        }
        variables[i].name[j] = name[j];
    }
    variables[i].value = value;
}

int32_t *variable_get(__eds__ uint8_t *name)
{
    int i;
    int j;
    for(i=0;i<50;i++)
    {
        for(j=0;j<10;j++)
        {
            if(name[j] == 0 || name[j] == ' ')
            {
                return &variables[i].value;
            }
            if(variables[i].name[j] != name[j])
            {
                break;
            }
        }
    }
    return 0;
}

void variable_dump()
{
    int i;
    for(i=0;i<50;i++)
    {
        if(variables[i].name[0] != 0)
        {
            fprintf(stdout,"%s %ld\n",variables[i].name,variables[i].value);
        }
    }
}