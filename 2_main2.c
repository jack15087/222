//202610211332
//张裕晟
#include <stdio.h>

struct Sensor {
    int temp;
    int humi;
    int valid;
};

struct Sensor pack_sensor(int t, int h)
{
    struct Sensor s;
    s.temp = t;
    s.humi = h;

    if (t >= -20 && t <= 50 && h >= 0 && h <= 100)
    {
        s.valid = 1;
    }
    else
    {
        s.valid = 0;
    }
    return s;
}

int main(void)
{
    int t, h;
    scanf("%d %d", &t, &h);

    struct Sensor data = pack_sensor(t, h);

    if (data.valid == 1)
    {
        printf("TEMP=%d HUMI=%d\n", data.temp, data.humi);
    }
    else
    {
        printf("ERROR: Out of Range\n");
    }

    return 0;
}
