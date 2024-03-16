

bool UCV(int i)
{
    if (i <= n)
    {
        return (!visited[i] && load < cap);
    }
    else
    {
        return (!visited[i] && visited[i - n]);
    }
}