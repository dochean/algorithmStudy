void merge(record fin[], int start, int mid, int end, record fout[])
{
	int i = start, j = mid + 1, k = start;  //k is used for traversing

	while((i <= mid) && (j <= end))  //merge half
	{
		if(fin[i] <= fin[j])  //the small part
		{
			fout[k] = fin[i];
			i++;
		}
		else
		{
			fout[k] = fin[j];
			j++;
		}
		k++;
	}
	while(i <= mid)  //the rest
	{
		fout[k] = fin[i];
		k++; i++;
	}
	while(j <= end)  //the rest
	{
		fout[k] = fin[j];
		k++; j++
	}
}
void MergeSort(record fin[], int low, int high, record fout[])
{
	record *r = (record*)malloc(sizeof(record)*(high - low +1));
	if(low == high)
		fout[low] = fin[low];
	else
	{
		mid = (low + high)/2;
		MergeSort(fin, low, mid, r);
		MergeSort(fin, mid+1, high, r);
		merge(r, low, mid, high, fout);
	}
	free(r);
}