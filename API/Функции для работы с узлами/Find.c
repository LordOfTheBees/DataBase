#include "stdafx.h"


void way(NODE * beginf)
{
	char* ways;
	char* buf;
	int len = 0;
	len = strlen(beginf->NodeName) + 1;
	ways = (char*)malloc(len);
	buf = (char*)malloc(len);
	memset(ways, 0, len);
	strcat(ways, ".");
	strcat(ways, beginf->NodeName);
	strcpy(buf, ways);
	printf("%s\n", buf);
	beginf = beginf->UpNode;

	while (beginf != NULL)
	{
		len = len + strlen(beginf->NodeName) + 1;
		ways = (char*)realloc(ways,len);
		memset(ways, 0, len);
		if (beginf->UpNode != NULL)
			strcat(ways, ".");
		strcat(ways, beginf->NodeName);
		strcat(ways, buf);
		buf = (char*)realloc(buf,len);
		strcpy(buf, ways);
		beginf = beginf->UpNode;
	}
	printf("%s\n", ways);
	free(ways);
	free(buf);
}

NODE* find_node(char* findname, NODE* beginf)//Ïîèñê ôàéëîâ ñ ïîìîùüþ ðåêóðñèè
{
	NODE* buf = NULL;
	//char YN[2];
	//strcat(YN, "Y");
	if (strcmp(beginf->NodeName, findname) == 0)//Èä¸ò ñðàâíåíèå
	{
		//way(beginf);
		//printf("    Continue searching? Y/N: ");
		//scanf("%s", YN);
		//if (strcmp(YN, "N") == 0)
		//{
		//	memset(YN, 0, 2);
		//	return(beginf);
		//}
		return(beginf);
	}
	beginf = beginf->DownNode;
	if (beginf != NULL)
		while (beginf != NULL)//Ïðîõîäèìñÿ ïî êàæäîìó áðàòó(NextNode)
		{
			buf = findnode(findname, beginf);
			if (buf != NULL)//Òðåáóåòñÿ, äëÿ âîçâàðàòà çíà÷åíèÿ ïðè îòêàçå äàëüíåéøåãî ïîèñêà
				return(buf);
			beginf = beginf->NextNode;
		}

	return(NULL);
}
