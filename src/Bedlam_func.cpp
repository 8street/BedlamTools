
#include <cstring>
#include "Bedlam_func.h"

//00401E39
void draw_IMG_in_buffer(int32_t image_number, int16_t transparent, int32_t x_pos, int32_t y_pos, uint8_t* buffer, uint8_t* bin_ptr)
{

    int img_header;
    int img_x_pos;
    int img_y_pos;
    int img_x_size;
    int img_height;
    int img_height1;
    int img_x_size1;
    int transparent1;
    uint8_t* v6; // esi
    int v7; // eax
    uint8_t* v8; // esi
    int v9; // eax
    uint8_t* v10; // esi
    uint8_t* v12; // esi
    uint8_t* v13; // esi
    uint8_t* v14; // edi
    int v16; // ebx
    bool v17; // zf
    int v18; // ecx
    int i; // ecx
    int v20; // ecx
    int v21; // ecx
    int v22; // ecx
    int v23; // ecx
    uint8_t* v25; // [esp-8h] [ebp-8h]
    uint8_t* v26; // [esp-8h] [ebp-8h]
    char v27; // [esp-8h] [ebp-8h]
    int v28; // [esp-8h] [ebp-8h]
    unsigned int v29; // [esp-4h] [ebp-4h]
    unsigned int v30; // [esp-4h] [ebp-4h]
    uint8_t* v31; // [esp-4h] [ebp-4h]
    uint8_t* v32; // [esp-4h] [ebp-4h]

    transparent1 = transparent;
    v6 = &bin_ptr[4 * image_number + 2 + *(uint32_t*)&bin_ptr[4 * image_number + 2]];
    v7 = *(unsigned __int16*)v6;
    v8 = v6 + 2;
    img_header = v7;
    if (bittest(v7, 1u))
    {
        v9 = *(unsigned __int16*)v8;
        v10 = v8 + 2;
        x_pos += v9;
        y_pos += *(unsigned __int16*)v10;
        v8 = v10 + 2;
    }
    img_y_pos = x_pos;
    img_x_pos = y_pos;
    img_height1 = *(uint16_t*)v8;
    if (*(uint16_t*)v8)
    {
        img_x_size = *(unsigned __int16*)v8;
        v12 = v8 + 2;
        img_height1 = *(unsigned __int16*)v12;
        if (*(uint16_t*)v12)
        {
            v13 = v12 + 2;
            img_height = img_height1;
            v14 = &buffer[640 * img_y_pos + img_x_pos];
            img_x_size1 = img_x_size;
            v16 = img_height1;
            img_height1 = (unsigned __int16)img_header;
            if (bittest(img_height1, 0))
            {
                if (transparent1)
                {
                    do
                    {
                        v31 = v14;
                        do
                        {
                            while (1)
                            {
                                v18 = *(unsigned __int16*)v13;
                                v13 += 2;
                                if (!bittest(v18, 0xFu))
                                    break;
                                img_height1 = v18 & 0xFFF;
                                v14 += img_height1;
                                if (bittest(v18, 0xEu))
                                    goto LABEL_28;
                            }
                            img_height1 = v18;
                            v27 = v18;
                            for (i = (unsigned __int16)(v18 & 0xFFF) >> 1; i; --i)
                            {
                                *(uint16_t*)v14 = *(uint16_t*)v13;
                                v13 += 2;
                                v14 += 2;
                            }
                            if ((v27 & 1) != 0)
                                *v14++ = *v13++;
                        } while (!bittest(img_height1, 0xEu));
                    LABEL_28:
                        v14 = v31 + 640;
                        --v16;
                    } while (v16);
                }
                else
                {
                    do
                    {
                        v32 = v14;
                        do
                        {
                            while (1)
                            {
                                v20 = *(unsigned __int16*)v13;
                                v13 += 2;
                                if (bittest(v20, 0xFu))
                                    break;
                                img_height1 = v20;
                                v21 = v20 & 0xFFF;
                                memcpy(v14, v13, v21);
                                v13 += v21;
                                v14 += v21;
                                if (bittest(img_height1, 0xEu))
                                    goto LABEL_37;
                            }
                            v28 = v20;
                            v22 = v20 & 0xFFF;
                            img_height1 = 0;
                            do
                            {
                                *v14++ = 0;
                                --v22;
                            } while (v22);
                            v23 = v28;
                        } while (!bittest(v23, 0xEu));
                    LABEL_37:
                        v14 = v32 + 640;
                        --v16;
                    } while (v16);
                }
            }
            else
            {
                v17 = transparent1 == 0;
                if (transparent1)
                {
                    do
                    {
                        v29 = img_x_size1;
                        v25 = v14;
                        do
                        {
                            img_height1 = *v13++;
                            if ((uint8_t)img_height1)
                                *v14 = img_height1;
                            ++v14;
                            --img_x_size1;
                        } while (img_x_size1);
                        v14 = v25 + 640;
                        img_x_size1 = v29;
                        --v16;
                    } while (v16);
                }
                else
                {
                    do
                    {
                        v30 = img_x_size1;
                        v26 = v14;
                        do
                        {
                            memcpy(v14, v13, img_x_size1);
                            v13 += img_x_size1;
                            v14 += img_x_size1;
                            img_x_size1 = 0;
                        } while (!v17);
                        v14 = v26 + 640;
                        img_x_size1 = v30;
                        v17 = --v16 == 0;
                    } while (v16);
                }
            }
        }
    }
}

//no present
bool bittest(int32_t value, int32_t bit)
{
    return value & (1 << bit);
}