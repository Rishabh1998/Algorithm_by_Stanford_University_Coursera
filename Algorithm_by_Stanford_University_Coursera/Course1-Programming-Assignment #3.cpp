// Author : Nishant Panwar
#include<bits/stdc++.h>
using namespace std;

void QuickSort(int* data, int l, int r, long long& C_Count, int p_No)
{
    if (r <= l)
    {
        return;
    }
    C_Count += (r - l);

    if (p_No == 2)
    {
        swap(data[l], data[r]);
    }
    else if (p_No == 3)
    {
        int three[3];
        int index[3];
        index[0] = l;
        index[1] = r;
        index[2] = (l + r)/2;
        for (int i = 0; i < 3; i++)
        {
            three[i] = data[index[i]];
        }
        for (int p = 0; p < 3; p++)
        {
            for (int q = p + 1; q < 3; q++)
            {
                if (three[p] > three[q])
                {
                    swap(three[p], three[q]);
                    swap(index[p], index[q]);
                }
            }
        }
        swap(data[l], data[index[1]]);
    }
    int p = data[l];
    int i = l + 1;
    for (int j = l + 1; j <= r; j++)
    {
        if (data[j] < p)
        {
            swap(data[j], data[i]);
            i++;
        }
    }
    swap(data[l], data[i - 1]);
    QuickSort(data, l, i - 2, C_Count, p_No);
    QuickSort(data, i, r, C_Count, p_No);
}

int main()
{
    ifstream fin("QuickSort.txt");
    const int size = 10000;
    int source[size];
    int data[size];
    for (int i = 0; i < size; i++)
    {
        fin >> source[i];
    }
    fin.close();
    for (int p_No = 1; p_No <= 3; p_No++)
    {
        for (int i = 0; i < size; i++)
        {
            data[i] = source[i];
        }
        long long C_Count = 0;
        QuickSort(data, 0, size - 1, C_Count, p_No);
        cout << C_Count << endl;
    }
}
