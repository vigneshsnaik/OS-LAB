#include "memprocesses.h"

void sort(int nb, Block *b)
{
    for (int i = 0; i < nb - 1; i++)
        for (int j = 0; j < nb - i - 1; j++)
            if (b[j].mem_size < b[j + 1].mem_size)
            {
                Block temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
}
void allocate(int np, Process *p, int nb, Block *b)
{
    sort(nb, b);

    for (int i = 0; i < np; i++)
    {
        for (int j = 0; j < nb; j++)
        {
            if (b[j].mem_size > 0)
                if (p[i].req_mem <= b[j].mem_size)
                {
                    p[i].allocated = true;
                    b[j].mem_size -= p[i].req_mem;
                    p[i].block = b[j].blockid;
                    sort(nb, b);

                    break;
                }
        }
    }
}
