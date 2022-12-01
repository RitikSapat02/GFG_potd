class Solution
{
public:
    // This function wants you to modify the given input
    // array and no need to return anything
    // arr: input array
    // n: size of array
    // Function to rearrange  the array elements alternately.
    void rearrange(long long *arr, int n)
    {

        long long maxele = arr[n - 1] + 1, start = 0, end = n - 1;

        for (long long i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                arr[i] += (arr[end--] % maxele) * maxele;
            }
            else
            {
                arr[i] += (arr[start++] % maxele) * maxele;
            }
        }
        for (long long i = 0; i < n; i++)
        {
            arr[i] /= maxele;
        }
    }
};