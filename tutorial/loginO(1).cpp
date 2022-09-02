int logg(long long x)
{
    return 64 - __builtin_clzll(x) - 1;
}