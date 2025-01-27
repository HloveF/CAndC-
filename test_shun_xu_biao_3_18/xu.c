#include"shun.h"


/*！！！！！！！！！！！！！！！！！！！！！！！兜兵晒糞�屐�！！！！！！！！！！！！！！！！！！！！！*/
void SeqListInit(SL* ps)
{
	(*ps).a = NULL;
	(*ps).size = (*ps).capacity = 0;
}



/*！！！！！！！！！！！！！！！！！！！！！！制否痕方糞�屐�！！！！！！！！！！！！！！！！！！！！！*/
void SeqListCheckCapacity(SL* ps)
{
	if ((ps->size) == (ps->capacity))
	{
		int newcapacity = (ps->capacity) == 0 ? 4 : (ps->capacity) * 2;
		//SLDataType峺議頁窃侏��箭泌int宸乂
		SLDataType* tmp = (SLDataType*)realloc((ps->a), (sizeof(SLDataType) * newcapacity));
		if (tmp == NULL)
		{
			printf("払移��\n");
			exit(-1);//嶮峭痕方
		}
		(ps->a) = tmp;
		(ps->capacity) = newcapacity;
	}
}



/*！！！！！！！！！！！！！！！！！！！！！！！！遊峨糞�屐�！！！！！！！！！！！！！！！！！！！！！*/
void SeqListPushFront(SL* ps, SLDataType x)
{
	//殊臥頁倦俶勣奐否
	SeqListCheckCapacity(ps);

	//制否頼撹岻朔蝕兵轍強
	int end = (ps->size) - 1;
	for (;end >= 0;end--)
	{
		ps->a[end + 1] = ps->a[end];
	}
	(ps->a[0]) = x;
	(ps->size)++;
}



/*！！！！！！！！！！！！！！！！！！！！！！！！硫峨糞�屐�！！！！！！！！！！！！！！！！！！！！！*/
void SeqListPushBack(SL* ps, SLDataType x)
{
	//殊臥頁倦俶勣奐否
	SeqListCheckCapacity(ps);

	//腎寂怎校岻朔��祥辛參慧方序肇阻
	(ps->a[ps->size]) = x;
	(ps->size)++;
}



/*！！！！！！！！！！！！！！！！！！！！！！遊評痕方糞�屐�！！！！！！！！！！！！！！！！！！！！！*/
void SeqListPopFront(SL* ps)
{
	int i = 0;
	for (i = 0;i < ((ps->size) - 1);i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	assert((ps->size) > 0);
	(ps->size)--;
}



/*！！！！！！！！！！！！！！！！！！！！！！硫評痕方糞�屐�！！！！！！！！！！！！！！！！！！！！！*/
void SeqListPopBack(SL* ps)
{
	//if ((ps->size) > 0)
	//{
	//	//(ps->a[ps->size]) = 0;
	//	(ps->size)--;
	//}
	assert((ps->size) > 0);
	(ps->size)--;
}



/*！！！！！！！！！！！！！！！！！！！！！孀x圷殆痕方糞�屐�！！！！！！！！！！！！！！！！！！！！*/
int SeqListFind(SL* ps, SLDataType x)
{
	int i = 0;
	while (i < (ps->size))
	{
		if (ps->a[i] == x)
		{
			return i;
		}
		i++;
	}
	return -1;
}



/*！！！！！！！！！！！！！！！！！！！！峨秘x欺pos和炎痕方糞�屐�！！！！！！！！！！！！！！！！！！*/
void SeqListInsert(SL* ps, int pos, SLDataType x)
{
	if (pos > (ps->size) || pos < 0)
	{
		printf("和炎危列��峨秘払移��\n");
		return;
	}
	SeqListCheckCapacity(ps);
	int i = 0;
	int j = 0;
	int arr[100] = { 0 };
	while (i <= (ps->size))
	{
		if (i == pos)
		{
			arr[i] = x;
			i++;
		}
		else
		{
			arr[i] = (ps->a[j]);
			j++;
			i++;
		}
	}
	for (i = 0;i <= (ps->size);i++)
	{
		(ps->a[i]) = arr[i];
	}
	(ps->size)++;
}



/*！！！！！！！！！！！！！！！！！！！！評茅pos和炎方痕方糞�屐�！！！！！！！！！！！！！！！！！！*/
void SeqListErase(SL* ps, int pos)
{
	int arr[9999] = { 0 };
	int i = 0;//arr
	int j = 0;//ps.a
	for (i = 0;i < (ps->size);i++)
	{
		if (j == pos)
		{
			j++;
			i--;
		}
		else
		{
			arr[i] = (ps->a[j]);
			j++;
		}
	}
	for (i = 0;i < ((ps->size) - 1);i++)
	{
		(ps->a[i]) = arr[i];
	}
	(ps->size)--;
}



/*！！！！！！！！！！！！！！！！！！！！！！嬉咫痕方糞�屐�！！！！！！！！！！！！！！！！！！！！！*/
SeqListprint(SL* ps)
{
	for (int i = 0;i < ps->size;i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}



/*！！！！！！！！！！！！！！！！！！！！！！��支痕方糞�屐�！！！！！！！！！！！！！！！！！！！！！*/
void SeqListDestory(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}