float sinf(float);
float cosf(float);

void func_00195538(float *arg0, float arg1) {
    float s;

    s = sinf(arg1);
    ((int *)arg0)[1] = 0;
    arg0[0] = s;
    arg0[2] = cosf(arg1);
    arg0[3] = 1.0f;
}
