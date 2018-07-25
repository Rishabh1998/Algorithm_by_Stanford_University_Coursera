// Author : Nishant Panwar
#include<bits/stdc++.h>
using namespace std;
long long inv(int* arr, int len);
long long inv(int* arr, int* out, int* buf, int begin, int end);
long long inv(int* arr, int len)
{
    int* out = new int[len];
    int* buf = new int[len];
    long long result = inv(arr, out, buf, 0, len);
    delete[] out;
    delete[] buf;
    return result;
}
long long inv(int* arr, int* out, int* buf, int begin, int end)
{
    if (end - begin == 1)
    {
        out[begin] = arr[begin];
        return 0;
    }
    else
    {
        assert(end - begin > 1);
        int mid = (begin + end) / 2;
        long long inv1 = inv(arr, buf, out, begin, mid);
        long long inv2 = inv(arr, buf, out, mid, end);
        int i = begin;
        int j = mid;
        int k = begin;
        long long inv3 = 0;
        while ((i < mid) || (j < end))
        {
            if (i < mid && j < end)
            {
                if (buf[i] < buf[j])
                {
                    out[k++] = buf[i++];
                }
                else
                {
                    assert(buf[i] > buf[j]);
                    inv3 += mid - i;
                    out[k++] = buf[j++];
                }
            }
            else if (i < mid)
            {
                out[k++] = buf[i++];
            }
            else
            {
                assert(j < end);
                out[k++] = buf[j++];
            }
        }
        return inv1 + inv2 + inv3;
    }
}
int main(void)
{
    ifstream fin("integerArray.txt");
    const int size = 100000;
    int data[size];
    for (int i = 0; i < size; i++)
    {
        fin >> data[i];
    }
    fin.close();
    cout << inv(data, size) << endl;
    return 0;
}
