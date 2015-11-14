int QD(record r[], int left, int right)
{
	x = r[left];
	low = left; high = right;

	while(low < high)
	{
		while(low < high && r[high].key >= x.key)  //find one less than x
		{
			high--;
		}
		if(low < high)  //replace the base with found one
		{
			r[low] = r[high];
			low++;
		}
		while(low < high && r[low].key <= x.key)  //find one bigger than x
		{
			low++;
		}
		if(low <high)  //change
		{
			r[high] = r[low];
			high--;
		}
		r[low] = x;
		return low
	}
}
void QS(record r[], int left, int right)
{
	int i, j;
	if(left < right)
	{
		i = QD(r, left, right);
		QS(r, left, i - 1);
		QS(r, i +1, right);
	}
}