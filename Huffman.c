#include<stdio.h>

typedef struct{
	int weight;
	int parent;
	int left;
	int right;
}HuffmanTree;

typedef char* HuffmanCode;

void CreateTree(HuffmanTree *ht, int n, int *w)//ht is a HuffmanTree array pointer, n is the lenght of w
{
	int i, m = 2 * n - 1;
	int bt1, bt2;
	if (n <= 1) return 0;

	//init the data given
	for (i = 1; i <= n; ++i)
	{
		ht[i].weight = w[i - 1];
		ht[i].parent = 0;
		ht[i].left = 0;
		ht[i].right = 0;
	}

	//init others in the array
	for (; i <= m; ++i)
	{
		ht[i].weight = 0;
		ht[i].parent = 0;
		ht[i].left = 0;
		ht[i].right = 0;
	}
	//create the tree
	for (i = n + 1; i <= m; ++i)
	{
		SelectNode(ht, n - 1, &bt1, &bt2); //form node 1 to node i-1 choose two node that parent == 0 with minimum eright
		ht[bt1].parent = i;
		ht[bt2].parent = i;
		ht[i].left = bt1;
		ht[i].right = bt2;
		ht[i].weight = ht[bt1].weight + ht[bt2].weight;
	}
}

void SelectNode(HuffmanTree *ht, int n, int *bt1, int *bt2)
{
	HuffmanTree *ht1, *ht2, *t;
	int i;
	ht1 = ht2 = NULL;
	for (i = 1; i <= n; ++i)
	{
		if (!ht[i].parent)//parent should be 0
		{
			if (ht1 == NULL)
			{
				ht1 = ht + i;
				continue;
			}
			if (ht2 == NULL)
			{
				ht2 = ht + i;
				if (ht1->weight > ht2->weight)
				{
					t = ht2;
					ht2 = ht1;
					ht1 = t;
				}
				continue;
			}
			if (ht1 && ht2)
			{
				if (ht[i].weight <= ht1->weight)
				{
					ht2 = ht1;
					ht1 = ht + i;
				}
				else if (ht[i].weight < ht2->weight)
				{
					ht2 = ht + i;
				}
			}
		}
	}
	if (ht1 > ht2)
	{
		*bt2 = ht1 - ht;
		*bt1 = ht2 - ht;
	}
	else{
		*bt1 = ht1 - ht;
		*bt2 = ht2 - ht;
	}
}