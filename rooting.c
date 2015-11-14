int Rooting(int x)
{
	if(a < 0)
		printf('Error !');
	else
	{
		a = x/2;
		b = (a + x/a)/2;
		while(fabs(a - b) >= 1e-6)
		{
			a = b;
			b = (a + x/a)/2;
		}
	}
}