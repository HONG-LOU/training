#include <stdio.h>
#define MAX 512
int main()
{
	char c,s1[MAX],s2[MAX];
	int i,j;
	i = j = 0;
	gets(s1);
	while(s1[i] != '\0'){
		s2[j++] = s1[i];
		if(s1[i+1] == '-' && s1[i] < s1[i+2]){
			for(c = s1[i]+1; c < s1[i+2]; c++)
				s2[j++] = c;
			i = i+2;
		}
		else i++;
	}
	s2[j] = '\0';
	puts(s2);
	return 0;
}

