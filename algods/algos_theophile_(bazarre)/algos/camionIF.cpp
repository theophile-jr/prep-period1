#include <stdio.h>
#include <string.h>

int main()
{
    int size_camion = 0;
    int num_students = 0;
    if (scanf("%d", &size_camion) != 1) return 0;
    if (scanf("%d", &num_students) != 1) return 0;

    int camion_pack_3if[size_camion + 1];
    int camion_pack_4if[size_camion + 1];

    int if3weights[num_students];
    int if4weights[num_students];
    int size_if3weights = 0;
    int size_if4_weights = 0;

    for (int i = 0; i < num_students; i++)
    {
        int tmp_class = 0;
        int tmp_weight = 0;
        if (scanf("%d %d", &tmp_weight, &tmp_class) != 2) return 0;
        if (tmp_class == 3)
        {
            if3weights[size_if3weights++] = tmp_weight;
        }
        else
        {
            if4weights[size_if4_weights++] = tmp_weight;
        }
    }

    /* initialize DP arrays to 0, set base case dp[0] = 1 */
    for (int i = 0; i <= size_camion; ++i) {
        camion_pack_3if[i] = 0;
        camion_pack_4if[i] = 0;
    }
    camion_pack_3if[0] = 1;
    camion_pack_4if[0] = 1;

    /* 0/1 subset-sum: weights-first, capacity backward */
    for (int weight_index = 0; weight_index < size_if3weights; weight_index++)
    {
        int w = if3weights[weight_index];
        if (w > size_camion) continue;
        for (int capa_index = size_camion; capa_index >= w; capa_index--)
        {
            if (camion_pack_3if[capa_index - w] == 1)
                camion_pack_3if[capa_index] = 1;
        }
    }

    for (int weight_index = 0; weight_index < size_if4_weights; weight_index++)
    {
        int w = if4weights[weight_index];
        if (w > size_camion) continue;
        for (int capa_index = size_camion; capa_index >= w; capa_index--)
        {
            if (camion_pack_4if[capa_index - w] == 1)
                camion_pack_4if[capa_index] = 1;
        }
    }

    /* find best reachable sum for each class */
    int last_found_3if = 0;
    int last_found_4if = 0;
    for (int i = 1; i <= size_camion; i++)
    {
        if (camion_pack_3if[i] == 1)
            last_found_3if = i;
        if (camion_pack_4if[i] == 1)
            last_found_4if = i;
    }

    if (last_found_3if > last_found_4if) {
        printf("%d\r\n", 3);
    } else if (last_found_4if > last_found_3if) {
        printf("%d\r\n", 4);
    } else {
        printf("3 4\r\n");
    }

    return 0;
}
    