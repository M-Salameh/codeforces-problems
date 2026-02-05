
ll inf = 1e7+5;
vector<bool>is_Prime(inf , true);

void find_primes()
{
    for (ll i=2 ; i<inf ; i++)
    {
        if (is_Prime[i])
        {
            for (ll j=2 ; j<=inf/i ; j++)
            {
                if(is_Prime[j*i])
                {
                    is_Prime[j*i]=false;
                }
            }
        }
    }
}
