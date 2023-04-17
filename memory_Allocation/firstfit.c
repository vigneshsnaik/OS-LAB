#include "memprocesses.h"

void allocate(int np, Process *p, int nb, Block *b)
{
    for (int i = 0; i < np; i++)
    {
        for (int j = 0; j < nb; j++)
        {
            if (b[j].mem_size > 0)
                if (p[i].req_mem < b[j].mem_size)
                {
                    p[i].allocated = true;
                    b[j].mem_size -= p[i].req_mem;
                    p[i].block = b[j].blockid;
                    break;
                }
        }
    }
}
