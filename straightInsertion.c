void straightInsertion(Record a[], int length)
{
	int j;
	for(int i = 2; i < length; i++)
	{
		a[0] = a[i];
		j = i - 1;
		while(a[0].key < a[j].key)
		{
			a[j+1] = a[j];
			j = j-1;
		}
		a[j+1] = a[0]
	}
}