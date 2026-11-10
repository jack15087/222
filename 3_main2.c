//202610211332
//张裕晟
#include <stdio.h>

struct Window {
    int buffer[3];
    int count;
};


struct Window push_data(struct Window win, int val)
{
    win.buffer[win.count % 3] = val;
    win.count += 1;
    return win;
}


int get_average(struct Window win)
{
    int sum = 0;
    if (win.count < 3)
    {
        for (int i = 0; i < win.count; i++)
        {
            sum += win.buffer[i];
        }
        return sum / win.count;
    }
    else
    {
        sum = win.buffer[0] + win.buffer[1] + win.buffer[2];
        return sum / 3;
    }
}

int main(void)
{
    struct Window win;
    win.count = 0;
    for (int i = 0; i < 3; i++)
    {
        win.buffer[i] = 0;
    }

    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        int v;
        scanf("%d", &v);
        win = push_data(win, v);
        int avg = get_average(win);
        if (i > 0)
            printf(" ");
        printf("%d", avg);
    }
    printf("\n");
    return 0;
}
